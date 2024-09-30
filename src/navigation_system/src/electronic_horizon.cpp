#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <time.h> 
#include <sys/timeb.h>
#include <sys/time.h>  
#include <sstream>
#include <ros/callback_queue.h>
#include <iostream>
#include <string>
#include <vector>

#include "ros/ros.h"

#include "std_msgs/Bool.h"
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include "project_s_msgs/Line.h"
#include "project_s_msgs/ElectronicHorizonArray.h"
#include "project_s_msgs/ElectronicHorizonReport.h"
#include <mobileye_560_660_msgs/Tsr.h>
#include "project_s_msgs/GenericSmartData.h"
#include "project_s_msgs/RouteLine.h"
#include "project_s_msgs/EgoDistanceCurviligne.h"

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::Line electronicHorizon;
project_s_msgs::ElectronicHorizonArray  electronic_Horizon_data;
project_s_msgs::ElectronicHorizonReport electronic_Horizon_Report;

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::Line Circuit;
nav_msgs::Odometry odom_gps;
std_msgs::Bool               mission_management;
project_s_msgs::EgoDistanceCurviligne Distance_Curviligne_Ego;
project_s_msgs::RouteLine globalRouteLine;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedNavigationManager = false;
void navigationManagerCallback(const project_s_msgs::Line::ConstPtr& msg)
{
	Circuit = *msg;

	receivedNavigationManager = true;
}

bool receivedOdomGPS = false;
void odomGPSCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
	odom_gps = *msg;

	receivedOdomGPS = true;
}

bool received_Distance_Curviligne_Ego = false;
void Distance_Curviligne_Ego_Callback(const project_s_msgs::EgoDistanceCurviligne::ConstPtr& buffer)
{
	Distance_Curviligne_Ego = *buffer;

	received_Distance_Curviligne_Ego = true;
}

/*
bool receivedMissionManagement = false;
void missionManagementCallback(const std_msgs::Bool::ConstPtr& msg)
{
	mission_management = *msg;

	receivedMissionManagement = true;
}
*/

bool received_route_line = false;
void routeLineDataCallback(const project_s_msgs::RouteLine::ConstPtr& buffer)
{
	globalRouteLine = *buffer;

	received_route_line = true;
}

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
double produit_scalaire(geometry_msgs::Point V1, geometry_msgs::Point V2){
	double p_scalaire;
	p_scalaire = V1.x * V2.x + V1.y * V2.y;
	return p_scalaire;
}

double distance_euclidienne(geometry_msgs::Point P1, geometry_msgs::Point P2){
	double distance;
	distance = std::sqrt(std::pow((P1.x - P2.x),2) + std::pow((P1.y - P2.y),2));
	return distance;
}

geometry_msgs::Point computeRelativePosition(geometry_msgs::Point point, nav_msgs::Odometry odom)
{	// calculs de la position dans le repère du lidar sensor,
	// à partir de la position dans le repère absolu
	geometry_msgs::Point p;
	double theta = tf::getYaw(odom.pose.pose.orientation);

	p.x =  (point.x - odom.pose.pose.position.x) * cos(theta) + (point.y - odom.pose.pose.position.y) * sin(theta);
	p.y = -(point.x - odom.pose.pose.position.x) * sin(theta) + (point.y - odom.pose.pose.position.y) * cos(theta);
	p.z =  (point.z - odom.pose.pose.position.z);

	return p;
}

uint indice_position=0;
uint indice_horizon=5;
std_msgs::Bool saut_indice;

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("electronic_horizon"));

	ros::NodeHandle n;

ros::Publisher pub_electronic_horizon_data = n.advertise<project_s_msgs::ElectronicHorizonReport>(std::string("/electronic_horizon_data"), 1);
	ros::Publisher pub_electronic_horizon = n.advertise<project_s_msgs::Line>(std::string("/electronic_horizon"), 1);
	ros::Publisher pub_saut_indice = n.advertise<std_msgs::Bool>(std::string("/end_of_mission"), 1);

	ros::Subscriber sub_navigation_manager = n.subscribe(std::string("/navigation_manager"), 1, navigationManagerCallback);
	ros::Subscriber sub_odom_gps = n.subscribe(std::string("/odom_gps"), 1, odomGPSCallback);
//	ros::Subscriber sub_mission_management = n.subscribe(std::string("/mission_manager_reset"), 1, missionManagementCallback);
	ros::Subscriber sub_Distance_Curviligne_Ego = n.subscribe(std::string("/Distance_Curviligne_Ego"), 1, Distance_Curviligne_Ego_Callback);
ros::Subscriber sub_route_lines = n.subscribe("/line_data", 1, routeLineDataCallback);

	geometry_msgs::Point vecteur_unitaire;

	saut_indice.data = false;

	ros::Rate loop_rate(10);

	while(n.ok())
	{
		ros::spinOnce();
/*
		if (receivedMissionManagement)
		{
			receivedMissionManagement = false;

indice_position=0;
indice_horizon=5;
saut_indice.data = false;
		}
*/
		if(receivedNavigationManager){
			//receivedNavigationManager = false;
		}

		if(receivedOdomGPS & receivedNavigationManager){
			receivedOdomGPS = false;

			double th = tf::getYaw(odom_gps.pose.pose.orientation);
			vecteur_unitaire.x = cos(th);
			vecteur_unitaire.y = sin(th);

			// MàJ indice_position (= map matching)
			geometry_msgs::Point vecteur_relatif;
			vecteur_relatif.x = Circuit.segment[indice_position].position.x - odom_gps.pose.pose.position.x;
			vecteur_relatif.y = Circuit.segment[indice_position].position.y - odom_gps.pose.pose.position.y;

			while(produit_scalaire(vecteur_relatif, vecteur_unitaire) <= double(0.0)){
				indice_position++;
				if(indice_position >= Circuit.lineClass.data){	// Circuit.lineClass.data contient le nbre de points du circuit
					indice_position = 0;
					pub_saut_indice.publish(saut_indice);
					saut_indice.data = false;
				}

				vecteur_relatif.x = Circuit.segment[indice_position].position.x - odom_gps.pose.pose.position.x;
				vecteur_relatif.y = Circuit.segment[indice_position].position.y - odom_gps.pose.pose.position.y;
			} 
//ROS_ERROR("indice_position : %i" ,indice_position);

			// MàJ indice_horizon
float distance;
			while((distance = distance_euclidienne(Circuit.segment[indice_horizon].position, odom_gps.pose.pose.position)) < 18){
				indice_horizon++;
//ROS_ERROR("distance : %f" ,distance);
//ROS_ERROR("indice_horizon : %i" ,indice_horizon);
//ROS_ERROR("circuit.x : %f" ,Circuit.segment[indice_horizon].position.x);
//ROS_ERROR("circuit.y : %f" ,Circuit.segment[indice_horizon].position.y);
//ROS_ERROR("odom.x : %f" ,odom_gps.pose.pose.position.x);
//ROS_ERROR("odom.y : %f" ,odom_gps.pose.pose.position.y);


				if(indice_horizon >= Circuit.lineClass.data){
					indice_horizon = 0;
					saut_indice.data = true;
				}
			}
//ROS_ERROR("indice_horizon : %i" ,indice_horizon);

			// MàJ Horizon
			electronicHorizon = project_s_msgs::Line();
			if(!saut_indice.data)
			{
				for (uint i=indice_position; i<=indice_horizon; i++){
					electronicHorizon.segment[i-indice_position].position = computeRelativePosition(Circuit.segment[i].position, odom_gps);
				}
			}
			else{
				uint j = 0;
				for (uint i=indice_position; i<=Circuit.lineClass.data; i++){
					electronicHorizon.segment[j].position = computeRelativePosition(Circuit.segment[i].position, odom_gps);
					j++;
				}
				for (uint i=0; i<=indice_horizon; i++){
					electronicHorizon.segment[j].position = computeRelativePosition(Circuit.segment[i].position, odom_gps);
					j++;
				}
			}

			pub_electronic_horizon.publish(electronicHorizon);
		}

		//----------
		if(received_Distance_Curviligne_Ego){
			received_Distance_Curviligne_Ego = false;

			electronic_Horizon_data.header.stamp = Distance_Curviligne_Ego.odom.header.stamp;
			electronic_Horizon_data.odom         = Distance_Curviligne_Ego.odom;

			electronic_Horizon_data.NbrPath.data = 2;

#define LARGEUR_VOIE		3.50
#define RAYON_1			20.0
#define LONGUEUR_LIGNE_1	20.0
#define RAYON_2			5.0
#define LONGUEUR_LIGNE_2	17.0
float offset, offset_path_1;
			{
			// Génération de la Position de l'égo dans le Path d'index 0 (jusqu'à la fin de la 1ère ligne droite)
			electronic_Horizon_data.PathsArray[0].indexPath.data = 0;
			electronic_Horizon_data.PathsArray[0].ehPosition.offset.data = Distance_Curviligne_Ego.distance.data;

			// Génération des Spot_Traffic_Sign
			electronic_Horizon_data.PathsArray[0].NbrSpotTrafficSign.data = 3;

			offset =  (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI/2.0;
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[0].offset.data = offset;
			//electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[0].offset.data += 10;	// décalage du panneau de 10m,
													// ce qui va induire que le panneau ne sera pas associé,
													// ainsi on aura un panneau de GT qui n'est pas dans l'EH,
													// & on place un panneau dans l'EH qui ne sera pas vu en GT.
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[0].Sign_Type = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_PLOT;

			offset += (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI/2.0;
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[1].offset.data = offset;
			//electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[1].offset.data += 2.0;// décalage du panneau 1m derrière,
													// ce qui va induire que le panneau sera toujours associé,
													// mais que le véhicule sera en avance par rapport à l'EH.
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[1].Sign_Type = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN;
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[1].Value = mobileye_560_660_msgs::Tsr::SIGN_TYPE_REGULAR_90;

			offset += LONGUEUR_LIGNE_1;
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[2].offset.data = offset;
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[2].Sign_Type = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN;
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[2].Value = mobileye_560_660_msgs::Tsr::SIGN_TYPE_REGULAR_50;

			offset_path_1 = offset;

			/*offset += (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI;
			offset += (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76;
			offset += LONGUEUR_LIGNE_2;
			offset += (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI*0.76;
			offset += 6.6;
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[3].offset.data = offset;
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[3].Sign_Type = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN;
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[3].Value = mobileye_560_660_msgs::Tsr::SIGN_TYPE_REGULAR_90;

			offset += 10.0;
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[4].offset.data = offset;
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[4].Sign_Type = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_PLOT;*/
			}

			{
			// Génération de la Position de l'égo dans le Path d'index 1 (à partir de la chicane)
			electronic_Horizon_data.PathsArray[1].indexPath.data = 1;
			electronic_Horizon_data.PathsArray[1].ehPosition.offset.data = Distance_Curviligne_Ego.distance.data - offset_path_1;

			// Génération des Spot_Traffic_Sign
			electronic_Horizon_data.PathsArray[1].NbrSpotTrafficSign.data = 2;

			offset  = (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI;
			offset += (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76;
			offset += LONGUEUR_LIGNE_2;
			offset += (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI*0.76;
			offset += 6.6;
			electronic_Horizon_data.PathsArray[1].ehSpotTrafficSign[0].offset.data = offset;
			//electronic_Horizon_data.PathsArray[1].ehSpotTrafficSign[0].offset.data += 2.0;
			electronic_Horizon_data.PathsArray[1].ehSpotTrafficSign[0].Sign_Type = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN;
			electronic_Horizon_data.PathsArray[1].ehSpotTrafficSign[0].Value = mobileye_560_660_msgs::Tsr::SIGN_TYPE_REGULAR_90;

			offset += 10.0;
			electronic_Horizon_data.PathsArray[1].ehSpotTrafficSign[1].offset.data = offset;
			//electronic_Horizon_data.PathsArray[1].ehSpotTrafficSign[1].offset.data += 2.0;
			electronic_Horizon_data.PathsArray[1].ehSpotTrafficSign[1].Sign_Type = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_PLOT;
			}

			electronic_Horizon_data.indexMPP.data = 0;
			if(Distance_Curviligne_Ego.distance.data > offset_path_1)
				electronic_Horizon_data.indexMPP.data = 1;

			// décalage des buffers
			// indice 0 -> NBR_MAX_EH : du plus récent -> au plus ancien
			#define NBR_MAX_EH	5	// en concordance avec ElectronicHorizonReport.msg
			for(int i = NBR_MAX_EH-1; i > 0; i--)
				electronic_Horizon_Report.ElectronicHorizonArray[i] = electronic_Horizon_Report.ElectronicHorizonArray[i-1];
			electronic_Horizon_Report.ElectronicHorizonArray[0] = electronic_Horizon_data;

			pub_electronic_horizon_data.publish(electronic_Horizon_Report);
		}

		//----------
		if(received_route_line)
		{
			received_route_line = false;

			// Génération de Spot_Coordonnées_Géométriques dans le Path d'index 0
			uint indexSpot = 0;
			for(uint j = 0; j < 60; j+=1){
				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoRight[indexSpot].offset.data = globalRouteLine.line[0].segment[j].offset;
				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoRight[indexSpot].latitude    = globalRouteLine.line[0].segment[j].latitude;	// line[0] est la ligne de droite
				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoRight[indexSpot].longitude   = globalRouteLine.line[0].segment[j].longitude;

				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoLeft[indexSpot].offset.data = globalRouteLine.line[1].segment[j].offset;
				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoLeft[indexSpot].latitude    = globalRouteLine.line[1].segment[j].latitude;	// line[1] est la ligne du milieu
				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoLeft[indexSpot].longitude   = globalRouteLine.line[1].segment[j].longitude;

				indexSpot++;
			}
			for(uint j = 60; j < 150; j+=1){	// débordement de path 0 sur path 1
				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoRight[indexSpot].offset.data = globalRouteLine.line[0].segment[j].offset;
				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoRight[indexSpot].latitude    = globalRouteLine.line[0].segment[j].latitude;	// line[0] est la ligne de droite
				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoRight[indexSpot].longitude   = globalRouteLine.line[0].segment[j].longitude;

				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoLeft[indexSpot].offset.data = globalRouteLine.line[1].segment[j].offset;
				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoLeft[indexSpot].latitude    = globalRouteLine.line[1].segment[j].latitude;	// line[1] est la ligne du milieu
				electronic_Horizon_data.PathsArray[0].ehSpotCoordGeoLeft[indexSpot].longitude   = globalRouteLine.line[1].segment[j].longitude;

				indexSpot++;
			}
			electronic_Horizon_data.PathsArray[0].NbrSpotCoordGeoRight.data = indexSpot;
			electronic_Horizon_data.PathsArray[0].NbrSpotCoordGeoLeft.data  = indexSpot;

			// Génération de Spot_Segment (principaux attributs) dans le Path d'index 0
			indexSpot = 0;
			electronic_Horizon_data.PathsArray[0].ehSegment[indexSpot].offset.data              = 0;
			electronic_Horizon_data.PathsArray[0].ehSegment[indexSpot].effectiveSpeedLimit.data = 5.0;
			indexSpot++;

			electronic_Horizon_data.PathsArray[0].ehSegment[indexSpot].offset.data              = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI;
			electronic_Horizon_data.PathsArray[0].ehSegment[indexSpot].effectiveSpeedLimit.data = 8.0;
			indexSpot++;

			// débordement de path 0 sur path 1
			electronic_Horizon_data.PathsArray[0].ehSegment[indexSpot].offset.data              = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI + LONGUEUR_LIGNE_1;
			electronic_Horizon_data.PathsArray[0].ehSegment[indexSpot].effectiveSpeedLimit.data = 3.0;
			indexSpot++;

			electronic_Horizon_data.PathsArray[0].NbrSegment.data = indexSpot;

// Génération de Spot_Curvature dans le Path d'index 0
indexSpot = 0;
electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].offset.data     = 0;
electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].Value_0.data    = 1/(RAYON_1 + LARGEUR_VOIE/2.0);
electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].Distance_1.data =   (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI;
electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].Value_1.data    = 1/(RAYON_1 + LARGEUR_VOIE/2.0);
indexSpot++;

electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].offset.data     = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI;;
electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].Value_0.data    = 0;
electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].Distance_1.data = LONGUEUR_LIGNE_1;
electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].Value_1.data    = 0;
indexSpot++;

// débordement de path 0 sur path 1
electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].offset.data     = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI + LONGUEUR_LIGNE_1;
electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].Value_0.data    = 1/(RAYON_2 + LARGEUR_VOIE/2.0);
electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].Distance_1.data =   (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI;
electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexSpot].Value_1.data    = 1/(RAYON_2 + LARGEUR_VOIE/2.0);
indexSpot++;

electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data = indexSpot;

			// Génération de Spot_Coordonnées_Géométriques dans le Path d'index 1
			float offset_path_1 = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI + LONGUEUR_LIGNE_1;
			float offset_path_2 = (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI + LONGUEUR_LIGNE_1 + (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76 \
					    + LONGUEUR_LIGNE_2 + (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI*0.76 + 26.6;

			indexSpot = 0;
			for(uint j = 60; j < 206; j+=1){
				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoRight[indexSpot].offset.data = globalRouteLine.line[0].segment[j].offset - offset_path_1;
				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoRight[indexSpot].latitude    = globalRouteLine.line[0].segment[j].latitude;
				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoRight[indexSpot].longitude   = globalRouteLine.line[0].segment[j].longitude;

				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoLeft[indexSpot].offset.data = globalRouteLine.line[1].segment[j].offset - offset_path_1;
				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoLeft[indexSpot].latitude    = globalRouteLine.line[1].segment[j].latitude;
				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoLeft[indexSpot].longitude   = globalRouteLine.line[1].segment[j].longitude;

				indexSpot++;
			}
			for(uint j = 0; j < 50; j+=1){		// débordement de path 1 sur path 0
				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoRight[indexSpot].offset.data = globalRouteLine.line[0].segment[j].offset + offset_path_2 - offset_path_1;
				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoRight[indexSpot].latitude    = globalRouteLine.line[0].segment[j].latitude;
				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoRight[indexSpot].longitude   = globalRouteLine.line[0].segment[j].longitude;

				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoLeft[indexSpot].offset.data = globalRouteLine.line[1].segment[j].offset + offset_path_2 - offset_path_1;
				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoLeft[indexSpot].latitude    = globalRouteLine.line[1].segment[j].latitude;
				electronic_Horizon_data.PathsArray[1].ehSpotCoordGeoLeft[indexSpot].longitude   = globalRouteLine.line[1].segment[j].longitude;

				indexSpot++;
			}
			electronic_Horizon_data.PathsArray[1].NbrSpotCoordGeoRight.data = indexSpot;
			electronic_Horizon_data.PathsArray[1].NbrSpotCoordGeoLeft.data  = indexSpot;

			// Génération de Spot_Segment (principaux attributs) dans le Path d'index 1
			indexSpot = 0;
			electronic_Horizon_data.PathsArray[1].ehSegment[indexSpot].offset.data              = 0;
			electronic_Horizon_data.PathsArray[1].ehSegment[indexSpot].effectiveSpeedLimit.data = 3.0;
			indexSpot++;

			electronic_Horizon_data.PathsArray[1].ehSegment[indexSpot].offset.data              = (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76;
			electronic_Horizon_data.PathsArray[1].ehSegment[indexSpot].effectiveSpeedLimit.data = 8.0;
			indexSpot++;

			electronic_Horizon_data.PathsArray[1].ehSegment[indexSpot].offset.data              = (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76 \
					    								    + LONGUEUR_LIGNE_2;
			electronic_Horizon_data.PathsArray[1].ehSegment[indexSpot].effectiveSpeedLimit.data = 3.0;
			indexSpot++;

			electronic_Horizon_data.PathsArray[1].ehSegment[indexSpot].offset.data              = (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76 \
					    								    + LONGUEUR_LIGNE_2 + (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI*0.76;
			electronic_Horizon_data.PathsArray[1].ehSegment[indexSpot].effectiveSpeedLimit.data = 8.0;
			indexSpot++;

			// débordement de path 1 sur path 1
			electronic_Horizon_data.PathsArray[1].ehSegment[indexSpot].offset.data		    = (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76 \
					    								    + LONGUEUR_LIGNE_2 + (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI*0.76 + 26.6;
			electronic_Horizon_data.PathsArray[1].ehSegment[indexSpot].effectiveSpeedLimit.data = 5.0;
			indexSpot++;

			electronic_Horizon_data.PathsArray[1].NbrSegment.data = indexSpot;

// Génération de Spot_Curvature dans le Path d'index 1
indexSpot = 0;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].offset.data     = 0;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_0.data    = 1/(RAYON_2 + LARGEUR_VOIE/2.0);
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Distance_1.data =   (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_1.data    = 1/(RAYON_2 + LARGEUR_VOIE/2.0);
indexSpot++;

electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].offset.data     = (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_0.data    = 1/(RAYON_2 - LARGEUR_VOIE/2.0);
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Distance_1.data =   (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_1.data    = 1/(RAYON_2 - LARGEUR_VOIE/2.0);
indexSpot++;

electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].offset.data     = (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_0.data    = 0;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Distance_1.data = LONGUEUR_LIGNE_2;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_1.data    = 0;
indexSpot++;

electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].offset.data     = (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76 + LONGUEUR_LIGNE_2;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_0.data    = 1/(RAYON_2 + LARGEUR_VOIE/2.0);
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Distance_1.data =   (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI*0.76;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_1.data    = 1/(RAYON_2 + LARGEUR_VOIE/2.0);
indexSpot++;

electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].offset.data     = (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76 + LONGUEUR_LIGNE_2 
										 + (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI*0.76;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_0.data    = 0;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Distance_1.data = 26.6;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_1.data    = 0;
indexSpot++;

// débordement de path 1 sur path 0
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].offset.data     = (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI + (RAYON_2 - LARGEUR_VOIE/2.0)*M_PI*0.76 + LONGUEUR_LIGNE_2 
										 + (RAYON_2 + LARGEUR_VOIE/2.0)*M_PI*0.76 + 26.6;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_0.data    = 1/(RAYON_1 + LARGEUR_VOIE/2.0);
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Distance_1.data =   (RAYON_1 + LARGEUR_VOIE/2.0)*M_PI;
electronic_Horizon_data.PathsArray[1].ehSpotCurvature[indexSpot].Value_1.data    = 1/(RAYON_1 + LARGEUR_VOIE/2.0);
indexSpot++;

electronic_Horizon_data.PathsArray[1].NbrSpotCurvature.data = indexSpot;

			// publication à la réception de Distance_Curviligne_Ego
		}

		loop_rate.sleep();		
	}

	return 0;
}
