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
#include <tf/transform_broadcaster.h>

#include "ros/ros.h"

#include "project_s_msgs/Configurations.h"
#include "project_s_msgs/ObstacleFusionReport.h"
#include "project_s_msgs/LaneFusion.h"
#include "project_s_msgs/RoadModel.h"
#include "project_s_msgs/ehPosition.h"
#include "project_s_msgs/ehSegment.h"
#include "project_s_msgs/ehStub.h"
#include "project_s_msgs/ElectronicHorizonArray.h"
#include "project_s_msgs/ElectronicHorizonReport.h"
#include "project_s_msgs/FineMapMatching.h"
#include "project_s_msgs/EgoDataReport.h"
#include "project_s_msgs/GenericSmartData.h"
#include <mobileye_560_660_msgs/Tsr.h>
#include "project_s_msgs/EgoDistanceCurviligne.h"
#include "project_s_msgs/RouteLine.h"
#include "project_s_msgs/RoutePlanning.h"



//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------
struct speedLimitStruct
{
	float offset;
#define OFFSET_NULL 9999.0
	float speed;
#define SPEED_NULL 10.0
};

struct speedLimitStruct speedLimit[project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE], /*speedLateralConfort[project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE],*/ speedLimit_trafficSign[project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE], speedCollisionAvoidance[project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE];

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport obstacleFusion;
project_s_msgs::LaneFusion lane;
project_s_msgs::LaneFusion lines_update;
project_s_msgs::ehPosition position;
project_s_msgs::ehSegment segment;
project_s_msgs::ehStub stub;
project_s_msgs::Line electronicHorizon;
project_s_msgs::ElectronicHorizonArray electronicHorizonArray, electronic_Horizon_Array;
project_s_msgs::ElectronicHorizonReport electronic_Horizon_Report;
project_s_msgs::FineMapMatching fine_map_matching;
project_s_msgs::EgoDataReport ego_data_report;
project_s_msgs::EgoDistanceCurviligne Distance_Curviligne_Ego;
project_s_msgs::RouteLine globalRouteLine;
project_s_msgs::RoutePlanning Route_Planning_data;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::RoadModel roadModel;
project_s_msgs::RoadModel roadModel_lines;
project_s_msgs::RoadModel roadModel_EH;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
void obstaclesFusionCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr &buffer)
{
	obstacleFusion = *buffer;
}

bool lanesFusionReceived = false;
void lanesFusionCallback(const project_s_msgs::LaneFusion::ConstPtr &laneFusion)
{
	lane = *laneFusion;

	lanesFusionReceived = true;
}

bool linesUpdateReceived = false;
void linesUpdateCallback(const project_s_msgs::LaneFusion::ConstPtr &buffer)
{
	lines_update = *buffer;

	linesUpdateReceived = true;
}

void ehPositionCallback(const project_s_msgs::ehPosition::ConstPtr &ehPosition)
{
	position = *ehPosition;
}

void ehSegmentCallback(const project_s_msgs::ehSegment::ConstPtr &ehSegment)
{
	segment = *ehSegment;
}

void ehStubCallback(const project_s_msgs::ehStub::ConstPtr &ehStub)
{
	stub = *ehStub;
}

bool electronicHorizonReceived = false;
void ehCallback(const project_s_msgs::Line::ConstPtr &msg)
{
	electronicHorizon = *msg;

	electronicHorizonReceived = true;
}

//bool electronicHorizonReceived = false;
void electronicHorizonCallback(const project_s_msgs::ElectronicHorizonReport::ConstPtr &buffer)
{
	electronic_Horizon_Report = *buffer;

	electronicHorizonReceived = true;
}

bool electronicHorizonArrayReceived = false;
void electronicHorizonArrayCallback(const project_s_msgs::ElectronicHorizonArray::ConstPtr &buffer)
{
	electronic_Horizon_Array = *buffer;

	electronicHorizonArrayReceived = true;
}

bool finemapmatchingReceived = false;
void fineMapMatchingCallback(const project_s_msgs::FineMapMatching::ConstPtr &buffer)
{
	fine_map_matching = *buffer;

	finemapmatchingReceived = true;
}

bool receivedEgoDataReport = false;
void egoDataCallback(const project_s_msgs::EgoDataReport::ConstPtr &buffer)
{
	ego_data_report = *buffer;

	receivedEgoDataReport = true;
}

#include "project_s_msgs/LaneSynchronizedReport.h"
project_s_msgs::LaneSynchronizedReport lines_synchronization;
bool linesSynchronizationReceived = false;
void linesSynchronizationDataCallback(const project_s_msgs::LaneSynchronizedReport::ConstPtr &buffer)
{
	lines_synchronization = *buffer;

	linesSynchronizationReceived = true;
}

bool received_Distance_Curviligne_Ego = false;
void Distance_Curviligne_Ego_Callback(const project_s_msgs::EgoDistanceCurviligne::ConstPtr &buffer)
{
	Distance_Curviligne_Ego = *buffer;

	received_Distance_Curviligne_Ego = true;
}

bool received_route_line = false;
void routeLineDataCallback(const project_s_msgs::RouteLine::ConstPtr &buffer)
{
	globalRouteLine = *buffer;

	received_route_line = true;
}

bool receivedRoutePlanning = false;
void routePlanningCallback(const project_s_msgs::RoutePlanning::ConstPtr &msg)
{
	Route_Planning_data = *msg;

	receivedRoutePlanning = true;
}

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
#define LATITUDE_ORIGIN +48.7965 // centré sur le parking de Segula@Trappes
#define LONGITUDE_ORIGIN +1.9872
#define RAYON_TERRE 6371000.0
#define X_ORIGIN 0.0
#define Y_ORIGIN 0.0

double e_exentricite;
double n_constante;
double rho_0;

void Init_Convertion_Coord_Geo_vers_Carto(void)
{
	double a_demi_grand_axe = RAYON_TERRE; //6378137;
	double f_aplatissement = 1 / 298.257222101;
	double b_demi_petit_axe;
	b_demi_petit_axe = a_demi_grand_axe * (1 - f_aplatissement);
	//double e_exentricite;
	e_exentricite = sqrt((pow(a_demi_grand_axe, 2) - pow(b_demi_petit_axe, 2)) / pow(a_demi_grand_axe, 2));
	double phi_1 = 44.0 / 180.0 * M_PI;
	double phi_2 = 49.0 / 180.0 * M_PI;

	//calcul de n_constante
	double n_denominateur;

	n_denominateur = tan(phi_2 / 2.0 + M_PI / 4.0);
	n_denominateur *= pow(1 + e_exentricite * sin(phi_1), e_exentricite / 2.0);
	n_denominateur *= pow(1 - e_exentricite * sin(phi_2), e_exentricite / 2.0);

	n_constante = tan(phi_1 / 2.0 + M_PI / 4.0);
	n_constante *= pow(1 - e_exentricite * sin(phi_1), e_exentricite / 2.0);
	n_constante *= pow(1 + e_exentricite * sin(phi_2), e_exentricite / 2.0);

	n_denominateur = log(n_constante / n_denominateur);

	n_constante = log(cos(phi_2) / cos(phi_1));
	n_constante += 0.5 * log(1 - pow(e_exentricite * sin(phi_1), 2)) / (1 - pow(e_exentricite * sin(phi_2), 2));

	n_constante /= n_denominateur;

	// calcul de rho_0
	rho_0 = pow((1 - e_exentricite * sin(phi_1)) / (1 + e_exentricite * sin(phi_1)), e_exentricite / 2.0);
	rho_0 *= tan(phi_1 / 2.0 + M_PI / 4.0);
	rho_0 = pow(rho_0, n_constante);
	rho_0 *= a_demi_grand_axe * cos(phi_1);
	rho_0 /= n_constante * sqrt(1 - pow(e_exentricite * sin(phi_1), 2));
}

double rho_de_phi(double phi) // phi en radian
{
	double rho;

	rho = pow((1 + e_exentricite * sin(phi)) / (1 - e_exentricite * sin(phi)), e_exentricite / 2.0);
	rho /= tan(phi / 2.0 + M_PI / 4.0);
	rho = pow(rho, n_constante);
	rho *= rho_0;

	return rho; // rho en mètre
}

geometry_msgs::Point Convertion_Coord_Geo_vers_Carto(double phi, double lambda) // phi    = latitude,  en degré
{																				// lambda = longitude, en degré
	geometry_msgs::Point Coord_Carto;

	Coord_Carto.x = rho_de_phi(LATITUDE_ORIGIN / 180.0 * M_PI) - rho_de_phi(phi / 180.0 * M_PI) * cos(n_constante * (lambda - LONGITUDE_ORIGIN) / 180.0 * M_PI); // latitude croissant vers le nord.
	Coord_Carto.y = -rho_de_phi(phi / 180.0 * M_PI) * sin(n_constante * (lambda - LONGITUDE_ORIGIN) / 180.0 * M_PI);											 // longitude croissant vers l'est,
																																								 // alors que l'on veut Y croissant vers l'ouest.
	Coord_Carto.x += X_ORIGIN;
	Coord_Carto.y += Y_ORIGIN; // -Y_ORIGIN ???

	return Coord_Carto;
}

geometry_msgs::Point Convertion_Coord_Geo_vers_Carto_(double phi, double lambda) // phi    = latitude,  en degré
{																				 // lambda = longitude, en degré
	geometry_msgs::Point Coord_Carto;

	Coord_Carto.x = ((double)rho_de_phi(0.0) - (double)rho_de_phi(phi / 180.0 * M_PI) * cos(n_constante * lambda / 180.0 * M_PI)); // latitude croissant vers le nord.
	Coord_Carto.y = (-(double)rho_de_phi(phi / 180.0 * M_PI) * sin(n_constante * lambda / 180.0 * M_PI));						   // longitude croissant vers l'ouest.

	return Coord_Carto;
}

// Compute relative position
geometry_msgs::Point computeRelativePosition(geometry_msgs::Point ptRef, float theta, geometry_msgs::Point ptFixe)
{ // calculs de la position dans le repère de l'ego,
	// à partir de la position dans le repère absolu.
	geometry_msgs::Point p;

	double c = cos(theta);
	double s = sin(theta);

	p.x = (ptFixe.x - ptRef.x) * c + (ptFixe.y - ptRef.y) * s;
	p.y = -(ptFixe.x - ptRef.x) * s + (ptFixe.y - ptRef.y) * c;
	p.z = 0;
	return p;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("road_model"));

	ros::NodeHandle n;

	ros::Subscriber subObs = n.subscribe(std::string("/obstacles_assignment_data"), 1, obstaclesFusionCallback);
	ros::Subscriber subLanes = n.subscribe(std::string("/lanes_fusion_data"), 1, lanesFusionCallback);
	ros::Subscriber sub_lines_update = n.subscribe(std::string("/lines_update_data"), 1, linesUpdateCallback);
	ros::Subscriber subEHPos = n.subscribe(std::string("/electronic_horizon_position_data"), 1, ehPositionCallback);
	ros::Subscriber subEHSeg = n.subscribe(std::string("/electronic_horizon_segment_data"), 1, ehSegmentCallback);
	ros::Subscriber subEHStub = n.subscribe(std::string("/electronic_horizon_stub_data"), 1, ehStubCallback);
	ros::Subscriber subEH = n.subscribe(std::string("/electronic_horizon"), 1, ehCallback);
	ros::Subscriber sub_electronic_horizon = n.subscribe(std::string("/electronic_horizon_data"), 1, electronicHorizonCallback);  
	ros::Subscriber sub_electronic_horizon_array = n.subscribe(std::string("/electronic_horizon_array_data"), 1, electronicHorizonArrayCallback);
	ros::Subscriber sub_fine_map_matching = n.subscribe(std::string("/fine_map_matching_data"), 1, fineMapMatchingCallback);
	ros::Subscriber subEgoData = n.subscribe(std::string("/ego_data"), 1, egoDataCallback);
	ros::Subscriber sub_lines_synchronization = n.subscribe(std::string("/lines_synchronization_data"), 1, linesSynchronizationDataCallback);
	ros::Subscriber sub_Distance_Curviligne_Ego = n.subscribe(std::string("/Distance_Curviligne_Ego"), 1, Distance_Curviligne_Ego_Callback);
	ros::Subscriber sub_route_lines = n.subscribe(std::string("/line_data"), 1, routeLineDataCallback);
	ros::Subscriber subRoutePlanning = n.subscribe(std::string("/route_planning_data"), 1, routePlanningCallback);

	ros::Publisher pub = n.advertise<project_s_msgs::RoadModel>(std::string("/road_model_data"), 1);
	ros::Publisher pub_road_model_line = n.advertise<project_s_msgs::RoadModel>(std::string("/road_model_lines_data"), 1);
	ros::Publisher pub_road_model_EH = n.advertise<project_s_msgs::RoadModel>(std::string("/road_model_EH_dataa"), 1);

	Init_Convertion_Coord_Geo_vers_Carto();

	int i_prec, i_actuel;

	bool depart_time_out = false;
	ros::Time current_time, last_time;
	last_time = ros::Time::now();

	ros::Rate loop_rate(100);

	while (n.ok())
	{
		ros::spinOnce();

		//----------
		if (receivedRoutePlanning)
		{
			receivedRoutePlanning = false;
		}

		//----------
		if (electronicHorizonArrayReceived)
		{
			electronicHorizonArrayReceived = false;
 			// code avec trajectory venant de l'EH
			roadModel = project_s_msgs::RoadModel();
			roadModel.header.stamp = electronic_Horizon_Array.header.stamp;

			// conversion trajectory : GPS -> locale
			geometry_msgs::Point ptRef;
			ptRef = Convertion_Coord_Geo_vers_Carto_(electronic_Horizon_Array.PathsArray[0].ehPosition.latitude,
													 electronic_Horizon_Array.PathsArray[0].ehPosition.longitude);

			uint j = 0;
			for (uint i = 0; i < Route_Planning_data.NBRE_POINT_TABLEAU_GPS; i++)
			{
				if ((Route_Planning_data.Tableau_circuit_GPS[i].offset > electronic_Horizon_Array.PathsArray[0].ehPosition.offset.data) && (j < project_s_msgs::Line::SEGMENT_REPORT_SIZE))
				{
					roadModel.roadLine[3].segment[j].latitude = Route_Planning_data.Tableau_circuit_GPS[i].latitude; // coord GPS
					roadModel.roadLine[3].segment[j].longitude = Route_Planning_data.Tableau_circuit_GPS[i].longitude;
					roadModel.roadLine[3].segment[j].offset = Route_Planning_data.Tableau_circuit_GPS[i].offset;

					geometry_msgs::Point ptFixe;
					ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel.roadLine[3].segment[j].latitude, roadModel.roadLine[3].segment[j].longitude);

					// coord Ref Ego
					roadModel.roadLine[3].segment[j].position = computeRelativePosition(ptRef, -electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data / 180.0 * M_PI, ptFixe);
					roadModel.roadLine[3].segment[j].offset -= electronic_Horizon_Array.PathsArray[0].ehPosition.offset.data;

					j++;
				}
			}

			roadModel.roadLine[3].QtySegment.data = j;

			pub.publish(roadModel);
 
 			roadModel_EH.header = electronic_Horizon_Array.header;
			roadModel_EH.electronicHorizon = electronic_Horizon_Array.PathsArray[0];

			// conversion line : GPS -> locale
			ptRef = Convertion_Coord_Geo_vers_Carto_(roadModel_EH.electronicHorizon.ehPosition.latitude, roadModel_EH.electronicHorizon.ehPosition.longitude);

			for (uint i = 0; i < roadModel_EH.electronicHorizon.QtyLineCoordGeo.data; i++)
			{
				for (uint m = 0; m < roadModel_EH.electronicHorizon.ehLineCoordGeo[i].NbrSpotCoordGeo.data; m++)
				{
					geometry_msgs::Point ptFixe;
					ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel_EH.electronicHorizon.ehLineCoordGeo[i].ehSpotCoordGeo[m].latitude,
															  roadModel_EH.electronicHorizon.ehLineCoordGeo[i].ehSpotCoordGeo[m].longitude);

					// coord Ref Ego
 					roadModel_EH.roadLine[i].segment[m].position = computeRelativePosition(ptRef, -roadModel_EH.electronicHorizon.ehPosition.cap.data / (float)180.0 * (float)M_PI, ptFixe);
 
					roadModel_EH.roadLine[i].segment[m].offset = roadModel_EH.electronicHorizon.ehLineCoordGeo[i].ehSpotCoordGeo[m].offset.data - roadModel_EH.electronicHorizon.ehPosition.offset.data;
				}

				roadModel_EH.roadLine[i].QtySegment.data = roadModel_EH.electronicHorizon.ehLineCoordGeo[i].NbrSpotCoordGeo.data;
			}

			roadModel_EH.nbrLine = roadModel_EH.electronicHorizon.QtyLineCoordGeo;

			// conversion line ME droite : GPS -> locale
			{
				for (uint m = 0; m < roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].NbrSpotCoordGeo.data; m++)
				{
					geometry_msgs::Point ptFixe;
					ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].ehSpotCoordGeo[m].latitude,
															  roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].ehSpotCoordGeo[m].longitude);

					// coord Ref Ego
					roadModel_EH.roadLine[4].segment[m].position = computeRelativePosition(ptRef, -roadModel_EH.electronicHorizon.ehPosition.cap.data / (float)180.0 * (float)M_PI, ptFixe);
					roadModel_EH.roadLine[4].segment[m].offset = roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].ehSpotCoordGeo[m].offset.data - roadModel_EH.electronicHorizon.ehPosition.offset.data;
				}

				roadModel_EH.roadLine[4].QtySegment.data = roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].NbrSpotCoordGeo.data;
			}

			// conversion line ME gauche : GPS -> locale
			{
				for (uint m = 0; m < roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].NbrSpotCoordGeo.data; m++)
				{
					geometry_msgs::Point ptFixe;
					ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].ehSpotCoordGeo[m].latitude,
															  roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].ehSpotCoordGeo[m].longitude);

					// coord Ref Ego
					roadModel_EH.roadLine[5].segment[m].position = computeRelativePosition(ptRef, -roadModel_EH.electronicHorizon.ehPosition.cap.data / (float)180.0 * (float)M_PI, ptFixe);
					roadModel_EH.roadLine[5].segment[m].offset = roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].ehSpotCoordGeo[m].offset.data - roadModel_EH.electronicHorizon.ehPosition.offset.data;
				}

				roadModel_EH.roadLine[5].QtySegment.data = roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].NbrSpotCoordGeo.data;
			}

			// conversion amer : GPS -> locale
			for (uint i = 0; i < roadModel_EH.electronicHorizon.NbrSpotTrafficSign.data; i++)
			{
				geometry_msgs::Point ptFixe;
				ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel_EH.electronicHorizon.ehSpotTrafficSign[i].latitude,
														  roadModel_EH.electronicHorizon.ehSpotTrafficSign[i].longitude);

				// coord Ref Ego
 				roadModel_EH.amer[i] = computeRelativePosition(ptRef, -roadModel_EH.electronicHorizon.ehPosition.cap.data / (float)180.0 * (float)M_PI, ptFixe);
 
			}

			roadModel_EH.nbrAmer = roadModel_EH.electronicHorizon.NbrSpotTrafficSign;

			// plannification des tableaux d'évolution de la vitesse limite
			//----------
			// -> speedLimit   // effectiveSpeedLimit
			i_actuel = 0;
			for (int i = 0; i < roadModel_EH.electronicHorizon.NbrSegment.data; i++)
			{																														  // hyp : roadModel_EH.electronicHorizon.ehSegment[] classé par ordre croissant d'offset
				if (roadModel_EH.electronicHorizon.ehPosition.offset.data >= roadModel_EH.electronicHorizon.ehSegment[i].offset.data) // garde le dernier Segment antérieur à la position
					i_actuel = i;
			}

			int index = 0;

			for (int i = i_actuel; i < roadModel_EH.electronicHorizon.NbrSegment.data; i++)
			{
				float delta_offset;
				delta_offset = roadModel_EH.electronicHorizon.ehSegment[i].offset.data - roadModel_EH.electronicHorizon.ehPosition.offset.data;
				if (delta_offset < 0)
					delta_offset = 0;

				if (index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					speedLimit[index].offset = delta_offset;
					speedLimit[index].speed = roadModel_EH.electronicHorizon.ehSegment[i].effectiveSpeedLimit.data;
					speedLimit[index].speed /= 3.6; // conversion km/h --> m/s
					printf("index %i speedLimit  %f  \n",index,speedLimit[index].speed);

					index++;
				}
			}

			// on complete le tableau avec des valeurs NULL
			for (; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++)
			{
				speedLimit[index].offset = OFFSET_NULL;
				speedLimit[index].speed = 0;
			}

			// MODIF REDEMARRAGE DU STOP
			if ((speedLimit[1].offset != OFFSET_NULL) && (speedLimit[1].speed == 0))
				depart_time_out = false;
			if ((speedLimit[0].offset != OFFSET_NULL) && (speedLimit[0].speed == 0))
			{
				current_time = ros::Time::now();
				if (!depart_time_out)
					last_time = current_time;
				if (!depart_time_out && (ego_data_report.EgoData[0].velocity.linear.x == 0))
					// time_out s'incrémente
					depart_time_out = true;
				float delta_tempo = (current_time - last_time).toSec();

				if (delta_tempo > 2.0)
					if (speedLimit[1].offset != OFFSET_NULL)
						speedLimit[0].speed = speedLimit[1].speed;
			}
			// FIN MODIF

			//----------
			// -> speedLateralConfort
			//roadModel_EH.electronicHorizon.NbrSpotCurvature.data = 0;

			/*

			//----------
			// -> speedLimit_trafficSign
			index = 0;

			// on complete le tableau avec des valeurs NULL
			for (; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++)
			{
				speedLimit_trafficSign[index].offset = OFFSET_NULL;
				speedLimit_trafficSign[index].speed = 0;
			}

			*/

			//----------
			// -> collision avoidance
			index = 0;

			speedCollisionAvoidance[index].offset = OFFSET_NULL;
			speedCollisionAvoidance[index].speed = 0;
			index++;

			// arret devant obstacle
			bool ArretObstacle = false;
			for (int i = 0; i < roadModel_EH.electronicHorizon.QtySegmentAO.data; i++)
			{
				if ((roadModel_EH.electronicHorizon.ehSegmentAO[i].offset_debut.data <= roadModel_EH.electronicHorizon.ehPosition.offset.data) 
				&& (roadModel_EH.electronicHorizon.ehSegmentAO[i].offset_fin.data >= roadModel_EH.electronicHorizon.ehPosition.offset.data))
					ArretObstacle = true;
			}
			// FORCAGE
			//ArretObstacle = true;

			// evitement d'obstacle
			bool EvitementObstacle = false;
			for (int i = 0; i < roadModel_EH.electronicHorizon.QtySegmentEO.data; i++)
			{
				if ((roadModel_EH.electronicHorizon.ehSegmentEO[i].offset_debut.data <= roadModel_EH.electronicHorizon.ehPosition.offset.data) 
				&& (roadModel_EH.electronicHorizon.ehSegmentEO[i].offset_fin.data >= roadModel_EH.electronicHorizon.ehPosition.offset.data))
					EvitementObstacle = true;
			}
			// FORCAGE
			//EvitementObstacle = false;

			#define ZONE_DETECTION_OBSTACLE_CURVILIGNE 20
			#define DISTANCE_ARRET 10
			float coefficient_de_frottement=0.8;
			float Distance_darret= ego_data_report.EgoData[0].velocity.linear.x/(0.5*coefficient_de_frottement*9.81); //gravité g=9.81 
			if (ArretObstacle)
			{
				for (int id = 0; id < obstacleFusion.QtyObstacles.data; id++)
				{
					float delta_offset;
					delta_offset = std::sqrt(std::pow(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.x, 2) + std::pow(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.y, 2));
					//delta_offset = obstacleFusion.ObstacleFusion[id].distanceCurviligne;

					// Added obstacleFusion.ObstacleFusion[id].distanceCurviligne =offset roadLine
					if ((((obstacleFusion.ObstacleFusion[id].distanceCurviligne > 0) && (obstacleFusion.ObstacleFusion[id].distanceCurviligne < 50))
						 // cas particulier : bouclage fin/début circuit
						 || (roadModel_EH.electronicHorizon.ehPosition.offset.data > roadModel.roadLine[3].segment[Route_Planning_data.NBRE_POINT_CIRCUIT_GPS - 1].offset - 20.0)) &&
						(delta_offset < Distance_darret+ZONE_DETECTION_OBSTACLE_CURVILIGNE) && (obstacleFusion.ObstacleFusion[id].NbrOccupiedLane == 1) 
						&& ((obstacleFusion.ObstacleFusion[id].existenceState.data == project_s_msgs::ObstacleFusion::CURRENT_TRACK)
						 || (obstacleFusion.ObstacleFusion[id].existenceState.data == project_s_msgs::ObstacleFusion::POST_TRACK)))
					{
						if (index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
						{
							// ego_data_report.EgoData[0].velocity.linear.x
							speedCollisionAvoidance[index].offset = delta_offset - DISTANCE_ARRET;
							speedCollisionAvoidance[index].speed = 0;
							index++;

							// evitement d'obstacle
							#define VITESSE_DETOURNEMENT_OBSTACLE 2 // m/s

							// si l'obstacle est placé à + de 1,5m à droite de l'ego,
							// on laisse une vitesse non nulle pour dépasser l'obstacle.
							if (EvitementObstacle)
								if (obstacleFusion.ObstacleFusion[id].obstaclePosition.position.y < -1.5)
									speedCollisionAvoidance[index].speed = VITESSE_DETOURNEMENT_OBSTACLE;
						}

						if (delta_offset < DISTANCE_ARRET)
						{
							speedCollisionAvoidance[0].offset = 0;
							speedCollisionAvoidance[0].speed = 0;
							index = 1;

							// evitement d'obstacle
							if (EvitementObstacle)
								if (obstacleFusion.ObstacleFusion[id].obstaclePosition.position.y < -1.5)
									speedCollisionAvoidance[0].speed = VITESSE_DETOURNEMENT_OBSTACLE;
						}
					}
				}
			}

			// on complete le tableau avec des valeurs NULL
			for (; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++)
			{
				// désactivation arrêt devant  obstacles
				//for(index = 0; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
				speedCollisionAvoidance[index].offset = OFFSET_NULL;
				speedCollisionAvoidance[index].speed = 0;
			}

			//----------
			// -> speedEnveloppe
			// test de la consigne la plus basse
			int i_speedEnveloppe = 0;
			int i_speedLimit = 0;
			// int i_speedLimit_trafficSign = 0;
			int i_speedCollisionAvoidance = 0;

			float offset_speedEnveloppe, speed_speedEnveloppe;

			// premier enregistrement de speedEnveloppe
			{
				// recherche de l'offset le + proche
				offset_speedEnveloppe = 0;

				// recherche de la vitesse la + basse
				speed_speedEnveloppe = speedLimit[0].speed; // hyp : speedLimit[0] toujours renseigné
			
			/*
				if ((speed_speedEnveloppe > speedLimit_trafficSign[0].speed) && (speedLimit_trafficSign[0].offset == 0))
				{
					speed_speedEnveloppe = speedLimit_trafficSign[0].speed;
				}

			*/	
				if ((speed_speedEnveloppe > speedCollisionAvoidance[0].speed) && (speedCollisionAvoidance[0].offset == 0))
				{
					speed_speedEnveloppe = speedCollisionAvoidance[0].speed;
				}

				// enregistrement dans tableau
				roadModel_EH.speedEnveloppe[i_speedEnveloppe].offset.data = offset_speedEnveloppe;
				roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data = speed_speedEnveloppe;

			}

			// enregistrements suivants de speedEnveloppe
			do
			{
				// recherche de l'offset le + proche
				uint origine_speedEnveloppe = 0x00;
				#define ORIGINE_LIMITATION 0x01
				#define ORIGINE_LIMITATION_TRAFFIC_SIGN 0x04
				#define ORIGINE_COLLISION_AVOIDANCE 0x08

				offset_speedEnveloppe = OFFSET_NULL;
				if (i_speedLimit + 1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					if ((offset_speedEnveloppe > speedLimit[i_speedLimit + 1].offset) && (speedLimit[i_speedLimit + 1].offset != OFFSET_NULL))
					{
						origine_speedEnveloppe = ORIGINE_LIMITATION;
						offset_speedEnveloppe = speedLimit[i_speedLimit + 1].offset;
					}
				}

				/*
				if (i_speedLimit_trafficSign + 1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					if ((offset_speedEnveloppe > speedLimit_trafficSign[i_speedLimit_trafficSign + 1].offset) && (speedLimit_trafficSign[i_speedLimit_trafficSign + 1].offset != OFFSET_NULL))
					{
						origine_speedEnveloppe = ORIGINE_LIMITATION_TRAFFIC_SIGN;
						offset_speedEnveloppe = speedLimit_trafficSign[i_speedLimit_trafficSign + 1].offset;
					}
				}
				*/
				if (i_speedCollisionAvoidance + 1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					if ((offset_speedEnveloppe > speedCollisionAvoidance[i_speedCollisionAvoidance + 1].offset) && (speedCollisionAvoidance[i_speedCollisionAvoidance + 1].offset != OFFSET_NULL))
					{
						origine_speedEnveloppe = ORIGINE_COLLISION_AVOIDANCE;
						offset_speedEnveloppe = speedCollisionAvoidance[i_speedCollisionAvoidance + 1].offset;
					}
				}
				// test du cas : plusieurs offsets egaux
				if (i_speedLimit + 1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					if ((offset_speedEnveloppe >= speedLimit[i_speedLimit + 1].offset) && (speedLimit[i_speedLimit + 1].offset != OFFSET_NULL))
						origine_speedEnveloppe |= ORIGINE_LIMITATION;
				}

				/*
				if (i_speedLimit_trafficSign + 1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					if ((offset_speedEnveloppe >= speedLimit_trafficSign[i_speedLimit_trafficSign + 1].offset) && (speedLimit_trafficSign[i_speedLimit_trafficSign + 1].offset != OFFSET_NULL))
						origine_speedEnveloppe |= ORIGINE_LIMITATION_TRAFFIC_SIGN;
				}
				*/

				if (i_speedCollisionAvoidance + 1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					if ((offset_speedEnveloppe >= speedCollisionAvoidance[i_speedCollisionAvoidance + 1].offset) && (speedCollisionAvoidance[i_speedCollisionAvoidance + 1].offset != OFFSET_NULL))
						origine_speedEnveloppe |= ORIGINE_COLLISION_AVOIDANCE;
				}

				// màj de(s) l'indice(s) qui donne l'offset le + proche
				if (origine_speedEnveloppe & ORIGINE_LIMITATION)
					i_speedLimit++;
				/*	
				if (origine_speedEnveloppe & ORIGINE_LIMITATION_TRAFFIC_SIGN)
					i_speedLimit_trafficSign++;
				*/

				if (origine_speedEnveloppe & ORIGINE_COLLISION_AVOIDANCE)
					i_speedCollisionAvoidance++;

				// recherche de la vitesse la + basse
				if (offset_speedEnveloppe != OFFSET_NULL)
				{
					//speed_speedEnveloppe = SPEED_NULL;
				//	if ((speed_speedEnveloppe > speedLimit[i_speedLimit].speed) && (speedLimit[i_speedLimit].offset != OFFSET_NULL))
					if  (speedLimit[i_speedLimit].offset != OFFSET_NULL)
					{
						speed_speedEnveloppe = speedLimit[i_speedLimit].speed;
						//printf("i_speedLimit %i speedLimit  %f  \n",i_speedLimit,speed_speedEnveloppe);

					}

					/*
					if ((speed_speedEnveloppe > speedLimit_trafficSign[i_speedLimit_trafficSign].speed) && (speedLimit_trafficSign[i_speedLimit_trafficSign].offset != OFFSET_NULL))
					{
						speed_speedEnveloppe = speedLimit_trafficSign[i_speedLimit_trafficSign].speed;
					}
					*/

					if ((speed_speedEnveloppe > speedCollisionAvoidance[i_speedCollisionAvoidance].speed) && (speedCollisionAvoidance[i_speedCollisionAvoidance].offset != OFFSET_NULL))
					{
						speed_speedEnveloppe = speedCollisionAvoidance[i_speedCollisionAvoidance].speed;
					}

					// test si changement de vitesse (+ ou -) par rapport au dernier enregistrement dans tableau
					if (speed_speedEnveloppe != roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data)
					{
						i_speedEnveloppe++;
						roadModel_EH.speedEnveloppe[i_speedEnveloppe].offset.data = offset_speedEnveloppe;
						roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data = speed_speedEnveloppe;

						printf("i_speedEnveloppe %i speedEnveloppe_Final  %f  \n",i_speedEnveloppe,speed_speedEnveloppe);

					}
				}
				else
				{
					i_speedEnveloppe++;
					roadModel_EH.speedEnveloppe[i_speedEnveloppe].offset.data = OFFSET_NULL;
					roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data = 0;
				}
			} while (i_speedEnveloppe < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE - 1); // on complete (éventuellement) le tableau avec des valeurs NULL

			// POUR TEST
			//for(index = 0; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
			//	roadModel_EH.speedEnveloppe[index].offset.data = speedLimit[index].offset;
			//	roadModel_EH.speedEnveloppe[index].speed.data  = speedLimit[index].speed;
			//}

			// publish
		
		printf("roadModel_EH.speedEnveloppe[0]  %f \n",roadModel_EH.speedEnveloppe[0].speed.data);

			pub_road_model_EH.publish(roadModel_EH);
 		}

		//----------
		//if(lanesFusionReceived)
		{
			lanesFusionReceived = false;

		}

		//----------
		if (received_Distance_Curviligne_Ego)
		{
			received_Distance_Curviligne_Ego = false;
		}

		//----------
		if (linesUpdateReceived)
		{
			linesUpdateReceived = false;

		}

		//----------
		if (finemapmatchingReceived)
		{
			//finemapmatchingReceived = false;
		}

		//----------
		if ((electronicHorizonReceived) || (finemapmatchingReceived))
		{
			electronicHorizonReceived = false;
			finemapmatchingReceived = false;


		}

		loop_rate.sleep();
	}

	return 0;
}
