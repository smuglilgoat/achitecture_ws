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

#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include "nav_msgs/Odometry.h"
#include <tf/transform_broadcaster.h>

#include "project_s_msgs/RouteLine.h"
#include "project_s_msgs/RoadModel.h"

project_s_msgs::RouteLine globalRouteLine ;
project_s_msgs::RoadModel roadModel_EH;
project_s_msgs::RoutePlanning rp;

//#define LATITUDE_ORIGIN	+48.80
//#define LONGITUDE_ORIGIN	+01.98
#define LATITUDE_ORIGIN		+48.7965
#define LONGITUDE_ORIGIN	+ 1.9872
#define RAYON_TERRE		6371000.0
#define X_ORIGIN		0.0
#define Y_ORIGIN		0.0

nav_msgs::Odometry odom_EH;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool received_rp = false;
void rpCallback(const project_s_msgs::RoutePlanning::ConstPtr& buffer)
{
	rp = *buffer;

	received_rp = true;
}

bool received_route_line = false;
void routeLineDataCallback(const project_s_msgs::RouteLine::ConstPtr& buffer)
{
	globalRouteLine = *buffer;

	received_route_line = true;
}

bool received_road_model = false;
void roadModelDataCallback(const project_s_msgs::RoadModel::ConstPtr& buffer)
{
	roadModel_EH = *buffer;
	odom_EH = roadModel_EH.odom;

	received_road_model = true;
}

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
double e_exentricite;
double n_constante;
double rho_0;

void Init_Convertion_Coord_Geo_vers_Carto(void)
{
	double a_demi_grand_axe = RAYON_TERRE; //6378137;
	double f_aplatissement = 1/298.257222101;
	double b_demi_petit_axe;
	b_demi_petit_axe = a_demi_grand_axe * (1 - f_aplatissement);
	//double e_exentricite;
	e_exentricite = sqrt((pow(a_demi_grand_axe,2) - pow(b_demi_petit_axe,2)) / pow(a_demi_grand_axe,2));
	double phi_1 = 44.0/180.0*M_PI;
	double phi_2 = 49.0/180.0*M_PI;

	//calcul de n_constante
	double n_denominateur;

	n_denominateur  = tan(phi_2/2.0 + M_PI/4.0);
	n_denominateur *= pow(1 + e_exentricite*sin(phi_1), e_exentricite/2.0);
	n_denominateur *= pow(1 - e_exentricite*sin(phi_2), e_exentricite/2.0);

	n_constante     = tan(phi_1/2.0 + M_PI/4.0);
	n_constante    *= pow(1 - e_exentricite*sin(phi_1), e_exentricite/2.0);
	n_constante    *= pow(1 + e_exentricite*sin(phi_2), e_exentricite/2.0);

	n_denominateur  = log(n_constante / n_denominateur);

	n_constante  = log(cos(phi_2)/cos(phi_1));
	n_constante += 0.5 * log(1 - pow(e_exentricite*sin(phi_1), 2)) / (1 - pow(e_exentricite*sin(phi_2), 2));

	n_constante /= n_denominateur;

	// calcul de rho_0
	rho_0  = pow((1 - e_exentricite*sin(phi_1)) / (1 + e_exentricite*sin(phi_1)), e_exentricite/2.0);
	rho_0 *= tan(phi_1/2.0 + M_PI/4.0);
	rho_0  = pow(rho_0, n_constante);
	rho_0 *= a_demi_grand_axe*cos(phi_1);
	rho_0 /= n_constante*sqrt(1 - pow(e_exentricite*sin(phi_1), 2));
}

double rho_de_phi(double phi)	// phi en radian
{
	double rho;

	rho  = pow((1 + e_exentricite*sin(phi)) / (1 - e_exentricite*sin(phi)), e_exentricite/2.0);
	rho /= tan(phi/2.0 + M_PI/4.0);
	rho  = pow(rho, n_constante);
	rho *= rho_0;

	return rho;		// rho en mètre
}

geometry_msgs::Point Convertion_Coord_Geo_vers_Carto(double phi, double lambda)	// phi    = latitude,  en degré
{										// lambda = longitude, en degré
	geometry_msgs::Point Coord_Carto;

	Coord_Carto.x = rho_de_phi(LATITUDE_ORIGIN/180.0*M_PI) - rho_de_phi(phi/180.0*M_PI) * cos(n_constante*(lambda-LONGITUDE_ORIGIN)/180.0*M_PI);	// latitude croissant vers le nord.
	Coord_Carto.y =                                        - rho_de_phi(phi/180.0*M_PI) * sin(n_constante*(lambda-LONGITUDE_ORIGIN)/180.0*M_PI);	// longitude croissant vers l'est,
																			// alors que l'on veut Y croissant vers l'ouest.
	Coord_Carto.x += X_ORIGIN;
	Coord_Carto.y += Y_ORIGIN;	// -Y_ORIGIN ???

	return Coord_Carto;
}

geometry_msgs::Point computeGlobalPosition(geometry_msgs::Point point, nav_msgs::Odometry odom)
{	// calculs de la position dans le repère absolu,
	// à partir de la position dans le repère de l'égo (position déjà alignée)
	geometry_msgs::Point p;
	double theta = tf::getYaw(odom.pose.pose.orientation);

	p.x = odom.pose.pose.position.x + (point.x * cos(theta) - point.y * sin(theta));
	p.y = odom.pose.pose.position.y + (point.x * sin(theta) + point.y * cos(theta));
	p.z = odom.pose.pose.position.z +  point.z;

	return p;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("electronic_horizon_markers"));

	ros::NodeHandle n;

	ros::Subscriber sub_route_lines = n.subscribe("/line_data", 1, routeLineDataCallback);
	ros::Publisher  pub_route_lines = n.advertise<visualization_msgs::MarkerArray>("/line_data_marker", 1);
	visualization_msgs::MarkerArray Lines_Array;

	ros::Subscriber sub_road_model_EH = n.subscribe("/road_model_EH_data", 1, roadModelDataCallback);
	ros::Publisher  pub_road_model_EH_marker        = n.advertise<visualization_msgs::MarkerArray>("/road_model_EH_marker", 1);
	ros::Publisher  pub_road_model_absolu_EH_marker = n.advertise<visualization_msgs::MarkerArray>("/road_model_absolu_EH_marker", 1);
	visualization_msgs::MarkerArray Lines_EH_Array, Lines_absolu_EH_Array;

	Init_Convertion_Coord_Geo_vers_Carto();

	ros::Duration blink_of_an_eye(0.01); 

	ros::Rate loop_rate(25);

	while(n.ok())
	{
		ros::spinOnce();

		if(received_route_line)
		{
			received_route_line = false;

			Lines_Array           = visualization_msgs::MarkerArray();

			/*for(int i = 0; i < 4; i++){
				visualization_msgs::Marker marker;
				marker.header.frame_id = "/odom";
				marker.header.stamp = ros::Time::now();
				marker.lifetime = ros::Duration();
				marker.id = 500+i;
				marker.ns = "Electronic_Horizon";
				marker.type = visualization_msgs::Marker::CUBE_LIST;
				marker.scale.x = 0.3;
				marker.scale.y = 0.3;
				marker.scale.z = 0.3;
				marker.color.r = 1.0f;
				marker.color.g = 0.0f;
				marker.color.b = 0.0f;
				marker.color.a = 1.0;
				marker.action = visualization_msgs::Marker::MODIFY;
				marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

				for(uint j = 0; j < 250-1; j++){
					geometry_msgs::Point p;

					//p.x = + (globalRouteLine.line[i].segment[j].latitude  - LATITUDE_ORIGIN)  / 180.0 * M_PI * RAYON_TERRE;
					//p.y = - (globalRouteLine.line[i].segment[j].longitude - LONGITUDE_ORIGIN) / 180.0 * M_PI * RAYON_TERRE * cos(LATITUDE_ORIGIN/180.0*M_PI);

					p = Convertion_Coord_Geo_vers_Carto(globalRouteLine.line[i].segment[j].latitude, globalRouteLine.line[i].segment[j].longitude);

					marker.points.push_back(p);
				}

				Lines_Array.markers.push_back(marker);
			}*/

			for(int i = 3; i < 4; i++){
				visualization_msgs::Marker marker;
				marker.header.frame_id = "/base_link";
				marker.header.stamp = ros::Time::now();
				marker.lifetime = ros::Duration();
				marker.id = 500+i;
				marker.ns = "Electronic_Horizon";
				marker.type = visualization_msgs::Marker::CUBE_LIST;
				marker.scale.x = 0.3;
				marker.scale.y = 0.3;
				marker.scale.z = 0.3;
				marker.color.r = 1.0f;
				marker.color.g = 0.0f;
				marker.color.b = 0.0f;
				marker.color.a = 1.0;
				marker.action = visualization_msgs::Marker::MODIFY;
				marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

				for(uint j = 0; j < globalRouteLine.line[i].QtySegment.data; j++){
					geometry_msgs::Point p;

					p = Convertion_Coord_Geo_vers_Carto(globalRouteLine.line[i].segment[j].latitude, globalRouteLine.line[i].segment[j].longitude);

					marker.points.push_back(p);
				}

				Lines_Array.markers.push_back(marker);
			}

			pub_route_lines.publish(Lines_Array);
		}

		if(received_road_model)
		{
			received_road_model = false;

			Lines_EH_Array = visualization_msgs::MarkerArray();
			Lines_absolu_EH_Array = visualization_msgs::MarkerArray();

			{	// ligne de droite
				// Markers pour le repère relatif
				visualization_msgs::Marker marker;
				marker.header.frame_id = "/base_link";
				marker.header.stamp = ros::Time::now();
				marker.lifetime = ros::Duration(0.2);
				marker.id = 510;
				marker.ns = "Electronic_Horizon";
				marker.type = visualization_msgs::Marker::SPHERE_LIST;
				marker.scale.x = 0.3;
				marker.scale.y = 0.3;
				marker.scale.z = 0.3;
				marker.color.r = 1.0f;
				marker.color.g = 0.0f;
				marker.color.b = 0.0f;
				marker.color.a = 1.0;
				marker.action = visualization_msgs::Marker::MODIFY;
				marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

				// Markers pour le repère absolu
				visualization_msgs::Marker absoluRoadModelMarker;
				absoluRoadModelMarker.header.frame_id = "/odom";
				absoluRoadModelMarker.header.stamp = ros::Time::now();
				absoluRoadModelMarker.lifetime = ros::Duration(0.2);
				absoluRoadModelMarker.id = 511;
				absoluRoadModelMarker.ns = "Electronic_Horizon";
				absoluRoadModelMarker.type = visualization_msgs::Marker::CUBE_LIST;
				absoluRoadModelMarker.scale.x = 0.3;
				absoluRoadModelMarker.scale.y = 0.3;
				absoluRoadModelMarker.scale.z = 0.3;
				absoluRoadModelMarker.color.r = 1.0f;
				absoluRoadModelMarker.color.g = 0.0f;
				absoluRoadModelMarker.color.b = 0.0f;
				absoluRoadModelMarker.color.a = 1.0;
				absoluRoadModelMarker.action = visualization_msgs::Marker::MODIFY;
				absoluRoadModelMarker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

/*				for(uint j = 0; j < roadModel_EH.roadLine[0].QtySegment.data; j++){
					geometry_msgs::Point p;

					p = roadModel_EH.roadLine[0].segment[j].position;

					marker.points.push_back(p);
					absoluRoadModelMarker.points.push_back(computeGlobalPosition(p, odom_EH));
				}*/


				for(uint j = 0; j < roadModel_EH.electronicHorizon.ehLineCoordGeo[0].NbrSpotCoordGeo.data; j++){
					marker.points.push_back(roadModel_EH.roadLine[0].segment[j].position);

					geometry_msgs::Point p;
					p = Convertion_Coord_Geo_vers_Carto(roadModel_EH.electronicHorizon.ehLineCoordGeo[0].ehSpotCoordGeo[j].latitude,
									    roadModel_EH.electronicHorizon.ehLineCoordGeo[0].ehSpotCoordGeo[j].longitude);

					absoluRoadModelMarker.points.push_back(p);
				}

				Lines_EH_Array.markers.push_back(marker);
				Lines_absolu_EH_Array.markers.push_back(absoluRoadModelMarker);
			}

			{	// ligne de gauche
				// Markers pour le repère relatif
				visualization_msgs::Marker marker;
				marker.header.frame_id = "/base_link";
				marker.header.stamp = ros::Time::now();
				marker.lifetime = ros::Duration(0.2);
				marker.id = 512;
				marker.ns = "Electronic_Horizon";
				marker.type = visualization_msgs::Marker::SPHERE_LIST;
				marker.scale.x = 0.3;
				marker.scale.y = 0.3;
				marker.scale.z = 0.3;
				marker.color.r = 1.0f;
				marker.color.g = 0.0f;
				marker.color.b = 0.0f;
				marker.color.a = 1.0;
				marker.action = visualization_msgs::Marker::MODIFY;
				marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

				// Markers pour le repère absolu
				visualization_msgs::Marker absoluRoadModelMarker;
				absoluRoadModelMarker.header.frame_id = "/odom";
				absoluRoadModelMarker.header.stamp = ros::Time::now();
				absoluRoadModelMarker.lifetime = ros::Duration(0.2);
				absoluRoadModelMarker.id = 513;
				absoluRoadModelMarker.ns = "Electronic_Horizon";
				absoluRoadModelMarker.type = visualization_msgs::Marker::CUBE_LIST;
				absoluRoadModelMarker.scale.x = 0.3;
				absoluRoadModelMarker.scale.y = 0.3;
				absoluRoadModelMarker.scale.z = 0.3;
				absoluRoadModelMarker.color.r = 1.0f;
				absoluRoadModelMarker.color.g = 0.0f;
				absoluRoadModelMarker.color.b = 0.0f;
				absoluRoadModelMarker.color.a = 1.0;
				absoluRoadModelMarker.action = visualization_msgs::Marker::MODIFY;
				absoluRoadModelMarker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

/*				for(uint j = 0; j < roadModel_EH.roadLine[1].QtySegment.data; j++){
					geometry_msgs::Point p;

					p = roadModel_EH.roadLine[1].segment[j].position;

					marker.points.push_back(p);
					absoluRoadModelMarker.points.push_back(computeGlobalPosition(p, odom_EH));
				}*/

				for(uint j = 0; j < roadModel_EH.electronicHorizon.ehLineCoordGeo[1].NbrSpotCoordGeo.data; j++){
					marker.points.push_back(roadModel_EH.roadLine[1].segment[j].position);

					geometry_msgs::Point p;
					p = Convertion_Coord_Geo_vers_Carto(roadModel_EH.electronicHorizon.ehLineCoordGeo[1].ehSpotCoordGeo[j].latitude,
									    roadModel_EH.electronicHorizon.ehLineCoordGeo[1].ehSpotCoordGeo[j].longitude);

					absoluRoadModelMarker.points.push_back(p);
				}

				Lines_EH_Array.markers.push_back(marker);
				Lines_absolu_EH_Array.markers.push_back(absoluRoadModelMarker);
			}

			{	// AMERs
				visualization_msgs::Marker AmerMarker;
				AmerMarker.header.frame_id = "/base_link";
				AmerMarker.header.stamp = ros::Time::now();
				AmerMarker.lifetime = ros::Duration(0.2);
				AmerMarker.id = 515;
				AmerMarker.ns = "Electronic_Horizon";
				AmerMarker.type = visualization_msgs::Marker::CUBE_LIST;
				AmerMarker.scale.x = 0.5;
				AmerMarker.scale.y = 0.5;
				AmerMarker.scale.z = 0.5;
				AmerMarker.color.r = 1.0f;
				AmerMarker.color.g = 0.0f;
				AmerMarker.color.b = 0.0f;
				AmerMarker.color.a = 1.0;
				AmerMarker.action = visualization_msgs::Marker::MODIFY;
				AmerMarker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

				for(uint j = 0; j < roadModel_EH.nbrAmer.data; j++){
					AmerMarker.points.push_back(roadModel_EH.amer[j]);
				}

				Lines_EH_Array.markers.push_back(AmerMarker);
			}




//NEWS -----
			{	// ME ligne de droite
				// Markers pour le repère absolu
				visualization_msgs::Marker absoluRoadModelMarker;
				absoluRoadModelMarker.header.frame_id = "/odom";
				absoluRoadModelMarker.header.stamp = ros::Time::now();
				absoluRoadModelMarker.lifetime = ros::Duration(0.2);
				absoluRoadModelMarker.id = 516;
				absoluRoadModelMarker.ns = "Electronic_Horizon";
				absoluRoadModelMarker.type = visualization_msgs::Marker::CUBE_LIST;
				absoluRoadModelMarker.scale.x = 0.3;
				absoluRoadModelMarker.scale.y = 0.3;
				absoluRoadModelMarker.scale.z = 0.3;
				absoluRoadModelMarker.color.r = 1.0f;
				absoluRoadModelMarker.color.g = 1.0f;
				absoluRoadModelMarker.color.b = 1.0f;
				absoluRoadModelMarker.color.a = 1.0;
				absoluRoadModelMarker.action = visualization_msgs::Marker::MODIFY;
				absoluRoadModelMarker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

				for(uint j = 0; j < roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].NbrSpotCoordGeo.data; j++){
					geometry_msgs::Point p;
					p = Convertion_Coord_Geo_vers_Carto(roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].ehSpotCoordGeo[j].latitude,
									    roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].ehSpotCoordGeo[j].longitude);

					absoluRoadModelMarker.points.push_back(p);
				}

				Lines_absolu_EH_Array.markers.push_back(absoluRoadModelMarker);
			}

			{	// ME ligne de gauche
				// Markers pour le repère absolu
				visualization_msgs::Marker absoluRoadModelMarker;
				absoluRoadModelMarker.header.frame_id = "/odom";
				absoluRoadModelMarker.header.stamp = ros::Time::now();
				absoluRoadModelMarker.lifetime = ros::Duration(0.2);
				absoluRoadModelMarker.id = 517;
				absoluRoadModelMarker.ns = "Electronic_Horizon";
				absoluRoadModelMarker.type = visualization_msgs::Marker::CUBE_LIST;
				absoluRoadModelMarker.scale.x = 0.3;
				absoluRoadModelMarker.scale.y = 0.3;
				absoluRoadModelMarker.scale.z = 0.3;
				absoluRoadModelMarker.color.r = 1.0f;
				absoluRoadModelMarker.color.g = 1.0f;
				absoluRoadModelMarker.color.b = 1.0f;
				absoluRoadModelMarker.color.a = 1.0;
				absoluRoadModelMarker.action = visualization_msgs::Marker::MODIFY;
				absoluRoadModelMarker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

				for(uint j = 0; j < roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].NbrSpotCoordGeo.data; j++){
					geometry_msgs::Point p;
					p = Convertion_Coord_Geo_vers_Carto(roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].ehSpotCoordGeo[j].latitude,
									    roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].ehSpotCoordGeo[j].longitude);

					absoluRoadModelMarker.points.push_back(p);
				}

				Lines_absolu_EH_Array.markers.push_back(absoluRoadModelMarker);
			}

// FIN -----

			pub_road_model_EH_marker.publish(Lines_EH_Array);
			pub_road_model_absolu_EH_marker.publish(Lines_absolu_EH_Array);

		}

		loop_rate.sleep();
	}

	return 0;

