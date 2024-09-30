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



// added by Abbas
#include "project_s_msgs/Trajectory.h"
//


#ifdef PROJECT_S_SIMULATION
#include "project_s_msgs/Tableau_Circuit.h"
#endif


//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------
struct speedLimitStruct{
float offset;
#define	OFFSET_NULL		9999.0
float speed;
#define	SPEED_NULL		20.0
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

// added by Abbas
project_s_msgs::Trajectory trajectory_GPS;
bool read_EH = false;
bool objetPresent = false;
double vehOffset = 0.0;
uint i_veh;
//



//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::RoadModel roadModel, roadModelTrajBased;
project_s_msgs::RoadModel roadModel_lines;
project_s_msgs::RoadModel roadModel_EH;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
void obstaclesFusionCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& buffer)
{
	obstacleFusion = *buffer;
}

bool lanesFusionReceived = false;
void lanesFusionCallback(const project_s_msgs::LaneFusion::ConstPtr& laneFusion)
{
	lane = *laneFusion;

	lanesFusionReceived = true;
}

bool linesUpdateReceived = false;
void linesUpdateCallback(const project_s_msgs::LaneFusion::ConstPtr& buffer)
{
	lines_update = *buffer;

	linesUpdateReceived = true;
}

void ehPositionCallback(const project_s_msgs::ehPosition::ConstPtr& ehPosition)
{
	position = *ehPosition;
}

void ehSegmentCallback(const project_s_msgs::ehSegment::ConstPtr& ehSegment)
{
	segment = *ehSegment;
}

void ehStubCallback(const project_s_msgs::ehStub::ConstPtr& ehStub)
{
	stub = *ehStub;
}

bool electronicHorizonReceived = false;
void ehCallback(const project_s_msgs::Line::ConstPtr& msg)
{
	electronicHorizon = *msg;

	electronicHorizonReceived = true;
}

//bool electronicHorizonReceived = false;
void electronicHorizonCallback(const project_s_msgs::ElectronicHorizonReport::ConstPtr& buffer)
{
	electronic_Horizon_Report = *buffer;

	electronicHorizonReceived = true;
}

bool electronicHorizonArrayReceived = false;
void electronicHorizonArrayCallback(const project_s_msgs::ElectronicHorizonArray::ConstPtr& buffer)
{
	electronic_Horizon_Array = *buffer;

	electronicHorizonArrayReceived = true;
}

bool finemapmatchingReceived = false;
void fineMapMatchingCallback(const project_s_msgs::FineMapMatching::ConstPtr& buffer)
{
	fine_map_matching = *buffer;

	finemapmatchingReceived = true;
}

bool receivedEgoDataReport = false;
void egoDataCallback(const project_s_msgs::EgoDataReport::ConstPtr& buffer)
{
	ego_data_report = *buffer;

	receivedEgoDataReport = true;
}

#include "project_s_msgs/LaneSynchronizedReport.h"
project_s_msgs::LaneSynchronizedReport lines_synchronization;
bool linesSynchronizationReceived = false;
void linesSynchronizationDataCallback(const project_s_msgs::LaneSynchronizedReport::ConstPtr& buffer)
{
	lines_synchronization = *buffer;

	linesSynchronizationReceived = true;
}

bool received_Distance_Curviligne_Ego = false;
void Distance_Curviligne_Ego_Callback(const project_s_msgs::EgoDistanceCurviligne::ConstPtr& buffer)
{
	Distance_Curviligne_Ego = *buffer;

	received_Distance_Curviligne_Ego = true;
}

bool received_route_line = false;
void routeLineDataCallback(const project_s_msgs::RouteLine::ConstPtr& buffer)
{
	globalRouteLine = *buffer;

	received_route_line = true;
}

bool receivedRoutePlanning = false;
void routePlanningCallback(const project_s_msgs::RoutePlanning::ConstPtr& msg)
{
	Route_Planning_data = *msg;

	receivedRoutePlanning = true;
}


// added by Abbas
bool receivedTrajectory_GPS = false;
void trajectoryCallback(const project_s_msgs::Trajectory::ConstPtr& buffer)
{
	trajectory_GPS = *buffer;

	receivedTrajectory_GPS = true;
}
//


//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
#define LATITUDE_ORIGIN		+48.7965	// centré sur le parking de Segula@Trappes
#define LONGITUDE_ORIGIN	+ 1.9872
#define RAYON_TERRE		6371000.0
#define X_ORIGIN		0.0
#define Y_ORIGIN		0.0

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

geometry_msgs::Point Convertion_Coord_Geo_vers_Carto_(double phi, double lambda)// phi    = latitude,  en degré
{										// lambda = longitude, en degré
	geometry_msgs::Point Coord_Carto;

	Coord_Carto.x = ((double)rho_de_phi(0.0)                 - (double)rho_de_phi(phi/180.0*M_PI) * cos(n_constante*lambda                   /180.0*M_PI));	// latitude croissant vers le nord.
	Coord_Carto.y = (                                       - (double)rho_de_phi(phi/180.0*M_PI) * sin(n_constante*lambda                   /180.0*M_PI));	// longitude croissant vers l'ouest.

	return Coord_Carto;
}

// Compute relative position
geometry_msgs::Point computeRelativePosition(geometry_msgs::Point ptRef, float theta, geometry_msgs::Point ptFixe)
{	// calculs de la position dans le repère de l'ego,
	// à partir de la position dans le repère absolu.
	geometry_msgs::Point p;

	double c = cos(theta);
	double s = sin(theta);

	p.x =  (ptFixe.x - ptRef.x) * c + (ptFixe.y - ptRef.y) * s;
	p.y = -(ptFixe.x - ptRef.x) * s + (ptFixe.y - ptRef.y) * c;
	p.z =  0;
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

	ros::Subscriber subObs            = n.subscribe(std::string("/obstacles_assignment_data"),        1, obstaclesFusionCallback);
	ros::Subscriber subLanes          = n.subscribe(std::string("/lanes_fusion_data"),                1, lanesFusionCallback);
	ros::Subscriber sub_lines_update  = n.subscribe(std::string("/lines_update_data"),                1, linesUpdateCallback);
	ros::Subscriber subEHPos          = n.subscribe(std::string("/electronic_horizon_position_data"), 1, ehPositionCallback);
	ros::Subscriber subEHSeg          = n.subscribe(std::string("/electronic_horizon_segment_data"),  1, ehSegmentCallback);
	ros::Subscriber subEHStub         = n.subscribe(std::string("/electronic_horizon_stub_data"),     1, ehStubCallback);
	ros::Subscriber subEH             = n.subscribe(std::string("/electronic_horizon"),               1, ehCallback);
	ros::Subscriber sub_electronic_horizon 		= n.subscribe(std::string("/electronic_horizon_data"),	1, electronicHorizonCallback);
	ros::Subscriber sub_electronic_horizon_array	= n.subscribe(std::string("/electronic_horizon_array_data"),	1, electronicHorizonArrayCallback);
	ros::Subscriber sub_fine_map_matching  		= n.subscribe(std::string("/fine_map_matching_data"),	1, fineMapMatchingCallback);
	ros::Subscriber subEgoData			= n.subscribe(std::string("/ego_data"),			1, egoDataCallback);
	ros::Subscriber sub_lines_synchronization	= n.subscribe(std::string("/lines_synchronization_data"),1,linesSynchronizationDataCallback); 
	ros::Subscriber sub_Distance_Curviligne_Ego 	= n.subscribe(std::string("/Distance_Curviligne_Ego"), 	1, Distance_Curviligne_Ego_Callback);
	ros::Subscriber sub_route_lines 		= n.subscribe(std::string("/line_data"),		1, routeLineDataCallback);
	ros::Subscriber subRoutePlanning		= n.subscribe(std::string("/route_planning_data"),	1, routePlanningCallback);

	// added by Abbas
	ros::Subscriber trajectory_GPS_sub	= n.subscribe(std::string("/trajectory_GPS_generation_data"),        1, trajectoryCallback);
	//

	ros::Publisher pub 			= n.advertise<project_s_msgs::RoadModel>(std::string("/road_model_data"),	1);
	ros::Publisher pub_road_model_line 	= n.advertise<project_s_msgs::RoadModel>(std::string("/road_model_lines_data"), 1);
	ros::Publisher pub_road_model_EH	= n.advertise<project_s_msgs::RoadModel>(std::string("/road_model_EH_data"),	1);

	Init_Convertion_Coord_Geo_vers_Carto();

	int i_prec, i_actuel;

	bool depart_time_out = false;
	ros::Time current_time, last_time;
	last_time = ros::Time::now();

	ros::Rate loop_rate(100);

	while(n.ok())
	{
		ros::spinOnce();

		//----------
		if(receivedRoutePlanning)
		{
			receivedRoutePlanning = false;
		}


		//----------
		if(electronicHorizonArrayReceived)
		{
			electronicHorizonArrayReceived = false;
			#ifdef PROJECT_S_VEHICLE
			// code avec trajectory venant de l'EH
			roadModel = project_s_msgs::RoadModel();
			roadModel.header.stamp = electronic_Horizon_Array.header.stamp;

			// conversion trajectory : GPS -> locale
			geometry_msgs::Point ptRef;
			ptRef = Convertion_Coord_Geo_vers_Carto_(electronic_Horizon_Array.PathsArray[0].ehPosition.latitude,
							electronic_Horizon_Array.PathsArray[0].ehPosition.longitude);

			uint j=0;
			for(uint i=0; i<Route_Planning_data.NBRE_POINT_TABLEAU_GPS; i++)
			{
				if((Route_Planning_data.Tableau_circuit_GPS[i].offset > electronic_Horizon_Array.PathsArray[0].ehPosition.offset.data) && (j < project_s_msgs::Line::SEGMENT_REPORT_SIZE))
				{
					roadModel.roadLine[3].segment[j].latitude = Route_Planning_data.Tableau_circuit_GPS[i].latitude;	// coord GPS
					roadModel.roadLine[3].segment[j].longitude = Route_Planning_data.Tableau_circuit_GPS[i].longitude;
					roadModel.roadLine[3].segment[j].offset = Route_Planning_data.Tableau_circuit_GPS[i].offset;

					geometry_msgs::Point ptFixe;
					ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel.roadLine[3].segment[j].latitude, roadModel.roadLine[3].segment[j].longitude);

					// coord Ref Ego
					roadModel.roadLine[3].segment[j].position = computeRelativePosition(ptRef, -electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data/180.0*M_PI, ptFixe);
					roadModel.roadLine[3].segment[j].offset -= electronic_Horizon_Array.PathsArray[0].ehPosition.offset.data;

					j++;
				}
			}

			roadModel.roadLine[3].QtySegment.data = j;
		
			// added by Abbas
			if(read_EH == false){
				roadModelTrajBased = roadModel;
			}
			objetPresent = false;
			double latDist[roadModelTrajBased.roadLine[3].QtySegment.data];
			for(uint i=0; i<roadModelTrajBased.roadLine[3].QtySegment.data; i++)
			{
				if(vehOffset >= roadModel.roadLine[3].segment[i].offset)
				{
					i_veh = i;
				}
			}
			for(uint i=i_veh; i<roadModelTrajBased.roadLine[3].QtySegment.data; i++)
			{
					latDist[i] = 0;
			}
			if(receivedTrajectory_GPS)
			{
				for(uint i=i_veh; i<roadModelTrajBased.roadLine[3].QtySegment.data; i++)
				{
					latDist[i] =trajectory_GPS.trajectoryLine.segment[i].position.y - roadModelTrajBased.roadLine[3].segment[i].position.y;
					roadModelTrajBased.roadLine[3].segment[i].position.y += latDist[i];
					if (roadModelTrajBased.roadLine[3].segment[i].position.y != roadModel.roadLine[3].segment[i].position.y)
					objetPresent = true;	
				}
			}
					
			if(objetPresent)
			pub.publish(roadModelTrajBased);
			else
			pub.publish(roadModel);
			//

				// pub.publish(roadModel);
			#endif

			#ifdef SIMULATION_CIRCUIT_GPS
			roadModel_EH.header = electronic_Horizon_Array.header;
			roadModel_EH.electronicHorizon = electronic_Horizon_Array.PathsArray[0];

			// conversion line : GPS -> locale
			ptRef = Convertion_Coord_Geo_vers_Carto_(roadModel_EH.electronicHorizon.ehPosition.latitude, roadModel_EH.electronicHorizon.ehPosition.longitude);

			for(uint i = 0; i < roadModel_EH.electronicHorizon.QtyLineCoordGeo.data; i++)
			{
				for(uint m = 0; m < roadModel_EH.electronicHorizon.ehLineCoordGeo[i].NbrSpotCoordGeo.data; m++)
				{
					geometry_msgs::Point ptFixe;
					ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel_EH.electronicHorizon.ehLineCoordGeo[i].ehSpotCoordGeo[m].latitude,
										  roadModel_EH.electronicHorizon.ehLineCoordGeo[i].ehSpotCoordGeo[m].longitude);

					// coord Ref Ego
					#ifdef PROJECT_S_VEHICLE
						roadModel_EH.roadLine[i].segment[m].position = computeRelativePosition(ptRef, -roadModel_EH.electronicHorizon.ehPosition.cap.data/(float)180.0*(float)M_PI, ptFixe);
					#endif

					#ifdef PROJECT_S_SIMULATION
						roadModel_EH.roadLine[i].segment[m].position = computeRelativePosition(ptRef, roadModel_EH.electronicHorizon.ehPosition.cap.data, ptFixe);
					#endif

					roadModel_EH.roadLine[i].segment[m].offset   = roadModel_EH.electronicHorizon.ehLineCoordGeo[i].ehSpotCoordGeo[m].offset.data
										     - roadModel_EH.electronicHorizon.ehPosition.offset.data;
				}

				roadModel_EH.roadLine[i].QtySegment.data = roadModel_EH.electronicHorizon.ehLineCoordGeo[i].NbrSpotCoordGeo.data;
			}

			roadModel_EH.nbrLine = roadModel_EH.electronicHorizon.QtyLineCoordGeo;

			// conversion line ME droite : GPS -> locale
			{
				for(uint m = 0; m < roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].NbrSpotCoordGeo.data; m++){
					geometry_msgs::Point ptFixe;
					ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].ehSpotCoordGeo[m].latitude,
										roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].ehSpotCoordGeo[m].longitude);

					// coord Ref Ego
					roadModel_EH.roadLine[4].segment[m].position = computeRelativePosition(ptRef, -roadModel_EH.electronicHorizon.ehPosition.cap.data/(float)180.0*(float)M_PI, ptFixe);
					roadModel_EH.roadLine[4].segment[m].offset   = roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].ehSpotCoordGeo[m].offset.data
											- roadModel_EH.electronicHorizon.ehPosition.offset.data;
				}

				roadModel_EH.roadLine[4].QtySegment.data = roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].NbrSpotCoordGeo.data;
			}

			// added by Abbas

			if(receivedTrajectory_GPS)
			{
				for(uint m = 0; m < roadModel_EH.roadLine[4].QtySegment.data; m++)
				{	
					for(uint i=i_veh; i<roadModelTrajBased.roadLine[3].QtySegment.data-1; i++)
					{
						if(roadModelTrajBased.roadLine[3].segment[i].offset <= roadModel_EH.roadLine[4].segment[m].offset 
							&& roadModel_EH.roadLine[4].segment[m].offset <= roadModelTrajBased.roadLine[3].segment[i+1].offset)
						{
							roadModel_EH.roadLine[4].segment[m].position.y += latDist[i];
						}
					}
				}
			}
			//

			// conversion line ME gauche : GPS -> locale
			{
				for(uint m = 0; m < roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].NbrSpotCoordGeo.data; m++){
					geometry_msgs::Point ptFixe;
					ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].ehSpotCoordGeo[m].latitude,
										roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].ehSpotCoordGeo[m].longitude);

					// coord Ref Ego
					roadModel_EH.roadLine[5].segment[m].position = computeRelativePosition(ptRef, -roadModel_EH.electronicHorizon.ehPosition.cap.data/(float)180.0*(float)M_PI, ptFixe);
					roadModel_EH.roadLine[5].segment[m].offset   = roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].ehSpotCoordGeo[m].offset.data
											- roadModel_EH.electronicHorizon.ehPosition.offset.data;
				}

				roadModel_EH.roadLine[5].QtySegment.data = roadModel_EH.electronicHorizon.ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].NbrSpotCoordGeo.data;
			}

			// added by Abbas
				if(receivedTrajectory_GPS)
				{
					for(uint m = 0; m < roadModel_EH.roadLine[5].QtySegment.data; m++)
					{	
						for(uint i=i_veh; i<roadModelTrajBased.roadLine[3].QtySegment.data-1; i++)
						{
							if(roadModelTrajBased.roadLine[3].segment[i].offset <= roadModel_EH.roadLine[5].segment[m].offset 
								&& roadModel_EH.roadLine[5].segment[m].offset <= roadModelTrajBased.roadLine[3].segment[i+1].offset)
							{
								roadModel_EH.roadLine[5].segment[m].position.y += latDist[i];
							}
						}
					}
				}
				vehOffset = roadModel_EH.electronicHorizon.ehPosition.offset.data;
				receivedTrajectory_GPS = false;
				read_EH = true;
			//

			// conversion amer : GPS -> locale
			for(uint i = 0; i < roadModel_EH.electronicHorizon.NbrSpotTrafficSign.data; i++)
			{
				geometry_msgs::Point ptFixe;
				ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel_EH.electronicHorizon.ehSpotTrafficSign[i].latitude,
									  roadModel_EH.electronicHorizon.ehSpotTrafficSign[i].longitude);

				// coord Ref Ego
				#ifdef PROJECT_S_VEHICLE
								roadModel_EH.amer[i] = computeRelativePosition(ptRef, -roadModel_EH.electronicHorizon.ehPosition.cap.data/(float)180.0*(float)M_PI, ptFixe);
				#endif
				#ifdef PROJECT_S_SIMULATION
								roadModel_EH.amer[i] = computeRelativePosition(ptRef, roadModel_EH.electronicHorizon.ehPosition.cap.data, ptFixe);
				#endif
			}

			roadModel_EH.nbrAmer = roadModel_EH.electronicHorizon.NbrSpotTrafficSign;

			// plannification des tableaux d'évolution de la vitesse limite
			//----------
			// -> speedLimit
			i_actuel = 0;
			for(int i = 0; i < roadModel_EH.electronicHorizon.NbrSegment.data; i++){	// hyp : roadModel_EH.electronicHorizon.ehSegment[] classé par ordre croissant d'offset
				if(roadModel_EH.electronicHorizon.ehPosition.offset.data >= roadModel_EH.electronicHorizon.ehSegment[i].offset.data)	// garde le dernier Segment antérieur à la position
					i_actuel = i;
			}

			int index = 0;

			for(int i = i_actuel; i < roadModel_EH.electronicHorizon.NbrSegment.data; i++){
				float delta_offset;
				delta_offset = roadModel_EH.electronicHorizon.ehSegment[i].offset.data - roadModel_EH.electronicHorizon.ehPosition.offset.data;
				if(delta_offset < 0)
					delta_offset = 0;

				if(index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
					speedLimit[index].offset = delta_offset;
					speedLimit[index].speed  = roadModel_EH.electronicHorizon.ehSegment[i].effectiveSpeedLimit.data;
					speedLimit[index].speed /= 3.6;		// conversion km/h --> m/s
					index++;
				}
			}

			// on complete le tableau avec des valeurs NULL
			for(; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
				speedLimit[index].offset = OFFSET_NULL;
				speedLimit[index].speed  = 20;
			}

			// MODIF REDEMARRAGE DU STOP
			if((speedLimit[1].offset != OFFSET_NULL) && (speedLimit[1].speed == 0)) depart_time_out = false;
			if((speedLimit[0].offset != OFFSET_NULL) && (speedLimit[0].speed == 0)){
				current_time = ros::Time::now();
				if(!depart_time_out) last_time = current_time;
				if(!depart_time_out && (ego_data_report.EgoData[0].velocity.linear.x == 0))
					// time_out s'incrémente
					depart_time_out = true;
				float delta_tempo = (current_time - last_time).toSec();

				if(delta_tempo > 2.0)
					if(speedLimit[1].offset != OFFSET_NULL)
						speedLimit[0].speed  = speedLimit[1].speed;
			}

			// FIN MODIF

			//----------
			// -> speedLateralConfort
			//roadModel_EH.electronicHorizon.NbrSpotCurvature.data = 0;

			//----------
			// -> speedLimit_trafficSign 
			index = 0; 

			// on complete le tableau avec des valeurs NULL
			for(; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++)
			{
				speedLimit_trafficSign[index].offset = OFFSET_NULL;
				speedLimit_trafficSign[index].speed  = 0;
			}

			//----------
			// -> collision avoidance
			index = 0;

			speedCollisionAvoidance[index].offset = OFFSET_NULL;
			speedCollisionAvoidance[index].speed  = 0;
			index++;

			// arret devant obstacle
			bool ArretObstacle = false;
			for(int i=0; i < roadModel_EH.electronicHorizon.QtySegmentAO.data; i++)
			{
				if(  (roadModel_EH.electronicHorizon.ehSegmentAO[i].offset_debut.data <= roadModel_EH.electronicHorizon.ehPosition.offset.data)
				&&(roadModel_EH.electronicHorizon.ehSegmentAO[i].offset_fin.data   >= roadModel_EH.electronicHorizon.ehPosition.offset.data))
					ArretObstacle = true;
			}
			// FORCAGE
			//ArretObstacle = true;

			// evitement d'obstacle 
			bool EvitementObstacle = false;
			for(int i=0; i < roadModel_EH.electronicHorizon.QtySegmentEO.data; i++)
			{
				if(  (roadModel_EH.electronicHorizon.ehSegmentEO[i].offset_debut.data <= roadModel_EH.electronicHorizon.ehPosition.offset.data)
				&&(roadModel_EH.electronicHorizon.ehSegmentEO[i].offset_fin.data   >= roadModel_EH.electronicHorizon.ehPosition.offset.data))
					EvitementObstacle = true;
			}


			// FORCAGE
			//EvitementObstacle = false;

			//#define	ZONE_DETECTION_OBSTACLE_CURVILIGNE	20
			#define	DISTANCE_ARRET				20
			#define DEBUT_CHANGEMENT_VOIE		30.0
			float LONGUEUR_VEHICULE =    		5.0 ;
									
			#define	VITESSE_DETOURNEMENT_OBSTACLE	2	// m/s   // evitement d'obstacle

			float coefficient_de_frottement = 0.7;
			if(ArretObstacle)
			{
				float delta_offset, Distance_darret_obligatoire, Vitesse_instantanee;
				for(int id = 0; id < obstacleFusion.QtyObstacles.data; id++)
				{

					delta_offset = -LONGUEUR_VEHICULE + std::sqrt(std::pow(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.x,2)
								+ std::pow(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.y,2));
					Vitesse_instantanee	= ego_data_report.EgoData[0].velocity.linear.x;  
					Distance_darret_obligatoire=  std::pow(Vitesse_instantanee,2)/(2*coefficient_de_frottement*9.81); //gravité g=9.81 
					
					
					if(   (   ((obstacleFusion.ObstacleFusion[id].distanceCurviligne > 0) && (obstacleFusion.ObstacleFusion[id].distanceCurviligne < 50))
						// cas particulier : bouclage fin/début circuit
						|| (roadModel_EH.electronicHorizon.ehPosition.offset.data > roadModel.roadLine[3].segment[Route_Planning_data.NBRE_POINT_CIRCUIT_GPS-1].offset - 20.0))
					// && (delta_offset < ZONE_DETECTION_OBSTACLE_CURVILIGNE)
					&& (delta_offset <  3*Distance_darret_obligatoire + DEBUT_CHANGEMENT_VOIE)
					//&& (obstacleFusion.ObstacleFusion[id].NbrOccupiedLane == 1)
					&& (objetPresent == true || obstacleFusion.ObstacleFusion[id].NbrOccupiedLane == 1) 
					
					&& (   (obstacleFusion.ObstacleFusion[id].existenceState.data == project_s_msgs::ObstacleFusion::CURRENT_TRACK)
						|| (obstacleFusion.ObstacleFusion[id].existenceState.data == project_s_msgs::ObstacleFusion::POST_TRACK)))
					{
						if(EvitementObstacle)
						{
							if(index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE && obstacleFusion.ObstacleFusion[id].obstaclePosition.position.y < 0)
							{  //-1.5){

								// si l'obstacle est placé à + de 1,5m à droite de l'ego,
								// on laisse une vitesse non nulle pour dépasser l'obstacle.

								/*
								if(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.y < -1.5)
								speedCollisionAvoidance[index].speed  = VITESSE_DETOURNEMENT_OBSTACLE;
								*/
								if(delta_offset < DEBUT_CHANGEMENT_VOIE && delta_offset > 1.5*Distance_darret_obligatoire) 
								{ 								
									speedCollisionAvoidance[0].offset = 0;
									speedCollisionAvoidance[0].speed  = VITESSE_DETOURNEMENT_OBSTACLE;
									index=1;
								}
								else if ( delta_offset > DEBUT_CHANGEMENT_VOIE )
								{
									speedCollisionAvoidance[index].offset = delta_offset - DEBUT_CHANGEMENT_VOIE;
									speedCollisionAvoidance[index].speed  = 2;
									index++;
								}
							}
						}

							/*
						if(index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
							speedCollisionAvoidance[index].offset = delta_offset - DISTANCE_ARRET;
							speedCollisionAvoidance[index].speed  = 0;
							index++;

							// evitement d'obstacle
							#define	VITESSE_DETOURNEMENT_OBSTACLE	2	// m/s

							// si l'obstacle est placé à + de 1,5m à droite de l'ego,
							// on laisse une vitesse non nulle pour dépasser l'obstacle.
							if(EvitementObstacle)
							if(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.y < -1.5)
							speedCollisionAvoidance[index].speed  = VITESSE_DETOURNEMENT_OBSTACLE;
						}
								*/
								
						if(index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
						{
													
							//if(delta_offset < 4.5*Distance_darret_obligatoire){  
							if(delta_offset < 7){
								speedCollisionAvoidance[0].offset = 0;
								speedCollisionAvoidance[0].speed  = 0;
								index=1;
							}	
							else if (delta_offset > 7)
							{
								speedCollisionAvoidance[index].offset = delta_offset - 7;
								speedCollisionAvoidance[index].speed  = 0;
								index++;
					

								/*  not  clear enought why he repeated this twice!!
							// evitement d'obstacle
							if(EvitementObstacle)
							if(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.y < -1.5)
							speedCollisionAvoidance[0].speed  = VITESSE_DETOURNEMENT_OBSTACLE;
							*/
							
							}

						}
					}
				}
			}

			// on complete le tableau avec des valeurs NULL
			for(; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++)
			{
				// désactivation arrêt devant  obstacles
				//for(index = 0; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
				speedCollisionAvoidance[index].offset = OFFSET_NULL;
				speedCollisionAvoidance[index].speed  = 0;
			}

			//----------
			// -> speedEnveloppe
			// test de la consigne la plus basse
			int i_speedEnveloppe = 0;
			int i_speedLimit = 0;
			int i_speedLimit_trafficSign = 0;
			int i_speedCollisionAvoidance = 0;

			float offset_speedEnveloppe, speed_speedEnveloppe;

			// premier enregistrement de speedEnveloppe
			{
				// recherche de l'offset le + proche
				offset_speedEnveloppe = 0;

				// recherche de la vitesse la + basse
				speed_speedEnveloppe = speedLimit[0].speed;		// hyp : speedLimit[0] toujours renseigné
				if((speed_speedEnveloppe > speedLimit_trafficSign[0].speed) && (speedLimit_trafficSign[0].offset == 0)){
					speed_speedEnveloppe = speedLimit_trafficSign[0].speed;
				}
				if((speed_speedEnveloppe > speedCollisionAvoidance[0].speed)&& (speedCollisionAvoidance[0].offset == 0)){
					speed_speedEnveloppe = speedCollisionAvoidance[0].speed;
				}

				// enregistrement dans tableau
				roadModel_EH.speedEnveloppe[i_speedEnveloppe].offset.data = offset_speedEnveloppe;
				roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data  = speed_speedEnveloppe;
			}

			// enregistrements suivants de speedEnveloppe
			do{
				// recherche de l'offset le + proche
				uint origine_speedEnveloppe = 0x00;
				#define	ORIGINE_LIMITATION		0x01
				#define	ORIGINE_LIMITATION_TRAFFIC_SIGN	0x04
				#define	ORIGINE_COLLISION_AVOIDANCE	0x08

				offset_speedEnveloppe = OFFSET_NULL;
				if(i_speedLimit+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
					if((offset_speedEnveloppe > speedLimit[i_speedLimit+1].offset)   && (speedLimit[i_speedLimit+1].offset != OFFSET_NULL))
					{
						origine_speedEnveloppe = ORIGINE_LIMITATION;
						offset_speedEnveloppe  = speedLimit[i_speedLimit+1].offset;
					}
				}

				if(i_speedLimit_trafficSign+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					if((offset_speedEnveloppe > speedLimit_trafficSign[i_speedLimit_trafficSign+1].offset) && (speedLimit_trafficSign[i_speedLimit_trafficSign+1].offset != OFFSET_NULL))
					{
						origine_speedEnveloppe = ORIGINE_LIMITATION_TRAFFIC_SIGN;
						offset_speedEnveloppe  = speedLimit_trafficSign[i_speedLimit_trafficSign+1].offset;
					}
				}

				if(i_speedCollisionAvoidance+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					if((offset_speedEnveloppe > speedCollisionAvoidance[i_speedCollisionAvoidance+1].offset) && (speedCollisionAvoidance[i_speedCollisionAvoidance+1].offset != OFFSET_NULL))
					{
						origine_speedEnveloppe = ORIGINE_COLLISION_AVOIDANCE;
						offset_speedEnveloppe  = speedCollisionAvoidance[i_speedCollisionAvoidance+1].offset;
					}
				}

				// test du cas : plusieurs offsets egaux
				if(i_speedLimit+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					if((offset_speedEnveloppe >= speedLimit[i_speedLimit+1].offset)   && (speedLimit[i_speedLimit+1].offset != OFFSET_NULL))
						origine_speedEnveloppe |= ORIGINE_LIMITATION;
				}

				if(i_speedLimit_trafficSign+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					if((offset_speedEnveloppe >= speedLimit_trafficSign[i_speedLimit_trafficSign+1].offset) && (speedLimit_trafficSign[i_speedLimit_trafficSign+1].offset != OFFSET_NULL))
						origine_speedEnveloppe |= ORIGINE_LIMITATION_TRAFFIC_SIGN;
				}

				if(i_speedCollisionAvoidance+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE)
				{
					if((offset_speedEnveloppe >= speedCollisionAvoidance[i_speedCollisionAvoidance+1].offset)&&(speedCollisionAvoidance[i_speedCollisionAvoidance+1].offset != OFFSET_NULL))
						origine_speedEnveloppe |= ORIGINE_COLLISION_AVOIDANCE;
				}

				// màj de(s) l'indice(s) qui donne l'offset le + proche
				if(origine_speedEnveloppe & ORIGINE_LIMITATION)              i_speedLimit++;
				if(origine_speedEnveloppe & ORIGINE_LIMITATION_TRAFFIC_SIGN) i_speedLimit_trafficSign++;
				if(origine_speedEnveloppe & ORIGINE_COLLISION_AVOIDANCE)     i_speedCollisionAvoidance++;

				// recherche de la vitesse la + basse
				if(offset_speedEnveloppe != OFFSET_NULL)
				{
					speed_speedEnveloppe  = SPEED_NULL;
					if((speed_speedEnveloppe > speedLimit[i_speedLimit].speed)   && (speedLimit[i_speedLimit].offset != OFFSET_NULL))
					{
						speed_speedEnveloppe = speedLimit[i_speedLimit].speed;
					}

					if((speed_speedEnveloppe > speedLimit_trafficSign[i_speedLimit_trafficSign].speed) && (speedLimit_trafficSign[i_speedLimit_trafficSign].offset != OFFSET_NULL))
					{
						speed_speedEnveloppe = speedLimit_trafficSign[i_speedLimit_trafficSign].speed;
					}

					if((speed_speedEnveloppe > speedCollisionAvoidance[i_speedCollisionAvoidance].speed)&&(speedCollisionAvoidance[i_speedCollisionAvoidance].offset != OFFSET_NULL))
					{
						speed_speedEnveloppe = speedCollisionAvoidance[i_speedCollisionAvoidance].speed;
					}

					// test si changement de vitesse (+ ou -) par rapport au dernier enregistrement dans tableau
					if(speed_speedEnveloppe != roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data)
					{
						i_speedEnveloppe++;
						roadModel_EH.speedEnveloppe[i_speedEnveloppe].offset.data = offset_speedEnveloppe;
						roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data  = speed_speedEnveloppe;
					}
				}
				else
				{
					i_speedEnveloppe++;
					roadModel_EH.speedEnveloppe[i_speedEnveloppe].offset.data = OFFSET_NULL;
					roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data  = 0;
				}
			}while(i_speedEnveloppe < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE-1);	// on complete (éventuellement) le tableau avec des valeurs NULL

			// POUR TEST
			//for(index = 0; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
			//	roadModel_EH.speedEnveloppe[index].offset.data = speedLimit[index].offset;
			//	roadModel_EH.speedEnveloppe[index].speed.data  = speedLimit[index].speed;
			//}

			// publish
			pub_road_model_EH.publish(roadModel_EH);
			#endif
		}

		//----------
		//if(lanesFusionReceived)
		{
			lanesFusionReceived = false;
			#ifdef PROJECT_S_SIMULATION
			//if((Distance_Curviligne_Ego.header.stamp).toSec() > (roadModel.header.stamp).toSec())
			{
				// code avec trajectory venant des sensors
				roadModel = project_s_msgs::RoadModel();
				roadModel.header.stamp = Distance_Curviligne_Ego.header.stamp;
				roadModel.id = lane.id;
				roadModel.odom = lane.odom;

				roadModel.nbrLine = lane.QtyLine;
				for(int i = 0; i < 3; i++)	// lane est un tableau			5 lignes
				{				// mais on se limite pour l'instant à	3 lignes
					roadModel.roadLine[i] = lane.line[i];
				}

				// code avec trajectory venant de GPS
				uint j=0;
				/*for(uint i=0; i<250; i++){								// *1.05 pour tenir compte de la dérive de Distance_Curviligne_Ego.distance
					if(globalRouteLine.line[3].segment[i].offset > Distance_Curviligne_Ego.distance.data*1.05){
						if(j<50){
							roadModel.roadLine[3].segment[j] = globalRouteLine.line[3].segment[i];							// coord Ref absolu + GPS

							geometry_msgs::Point ptRef;
							ptRef = Convertion_Coord_Geo_vers_Carto_(Distance_Curviligne_Ego.latitude.data, Distance_Curviligne_Ego.longitude.data);

							geometry_msgs::Point ptFixe;
							ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel.roadLine[3].segment[j].latitude, roadModel.roadLine[3].segment[j].longitude);

							roadModel.roadLine[3].segment[j].position = computeRelativePosition(ptRef, Distance_Curviligne_Ego.cap.data, ptFixe);	// coord Ref Ego + GPS
							roadModel.roadLine[3].segment[j].offset -= Distance_Curviligne_Ego.distance.data*1.05;					// *1.05 ...

							j++;
						}
					}
				}*/
				/*
				// code pour prendre quelques points GPS
				uint i=0;				
				while(i<250){
					if(globalRouteLine.line[3].segment[i].offset > Distance_Curviligne_Ego.distance.data*1.05){
						if(j<50){
							roadModel.roadLine[3].segment[j] = globalRouteLine.line[3].segment[i];							// coord Ref absolu + GPS

							geometry_msgs::Point ptRef;
							ptRef = Convertion_Coord_Geo_vers_Carto_(Distance_Curviligne_Ego.latitude.data, Distance_Curviligne_Ego.longitude.data);

							geometry_msgs::Point ptFixe;
							ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel.roadLine[3].segment[j].latitude, roadModel.roadLine[3].segment[j].longitude);

							roadModel.roadLine[3].segment[j].position = computeRelativePosition(ptRef, Distance_Curviligne_Ego.cap.data, ptFixe);	// coord Ref Ego + GPS
							roadModel.roadLine[3].segment[j].offset -= Distance_Curviligne_Ego.distance.data*1.05;					// *1.05 ...

							j++;
						}
					}
					if(i==205-1) i=250;	// on sort
					if(i==195) i=205-1;
					if(i==157) i=195;
					if(i==147) i=157;
					if(i==110) i=147;
					if(i==60)  i=110;
					if(i==50)  i=60;
					if(i==0)   i=50;
				}
				*/
				// code pour prendre les points GPS venant Tableau_Circuit.h
				for(uint i=0; i<NBRE_POINT_TABLEAU_GPS; i++)
				{
					if(Tableau_circuit_GPS[i].offset > Distance_Curviligne_Ego.distance.data)
					{
						roadModel.roadLine[3].segment[j].latitude = Tableau_circuit_GPS[i].latitude;	// coord GPS
						roadModel.roadLine[3].segment[j].longitude = Tableau_circuit_GPS[i].longitude;
						roadModel.roadLine[3].segment[j].offset = Tableau_circuit_GPS[i].offset;

						geometry_msgs::Point ptRef;
						ptRef = Convertion_Coord_Geo_vers_Carto_(Distance_Curviligne_Ego.latitude, Distance_Curviligne_Ego.longitude);

						geometry_msgs::Point ptFixe;
						ptFixe = Convertion_Coord_Geo_vers_Carto_(roadModel.roadLine[3].segment[j].latitude, roadModel.roadLine[3].segment[j].longitude);

						roadModel.roadLine[3].segment[j].position = computeRelativePosition(ptRef, Distance_Curviligne_Ego.cap.data, ptFixe);// coord Ref Ego
						roadModel.roadLine[3].segment[j].offset -= Distance_Curviligne_Ego.distance.data;

						j++;
					}
				}

				roadModel.roadLine[3].QtySegment.data = j;

				pub.publish(roadModel);
			}
			#endif
		}

		//----------
		if(received_Distance_Curviligne_Ego)
		{
			received_Distance_Curviligne_Ego = false;
		}

		//----------
		if(linesUpdateReceived)
		{
			linesUpdateReceived = false;

			#ifdef PROJECT_S_SIMULATION
			roadModel_lines = project_s_msgs::RoadModel();
			roadModel_lines.id = lines_update.id;
			roadModel_lines.odom = lines_update.odom;

			roadModel_lines.nbrLine = lines_update.QtyLine;
			for(int i = 0; i < 5; i++)	// roadModel_lines est un tableau 5 lignes
			{
				roadModel_lines.roadLine[i] = lines_update.line[i];
			}

			pub_road_model_line.publish(roadModel_lines);

			/*
			roadModel = project_s_msgs::RoadModel();
			roadModel.id = lines_update.id;
			roadModel.odom = lines_update.odom;

			roadModel.nbrLine = lines_update.QtyLine;
			for(int i = 0; i < 5; i++)	// roadModel_lines est un tableau 5 lignes
			{
				roadModel.roadLine[i] = lines_update.line[i];
			}

			pub.publish(roadModel);
			*/
			/*
			roadModel = project_s_msgs::RoadModel();
			roadModel.id = lines_synchronization.laneAlignement.id;
			roadModel.odom = lines_synchronization.laneAlignement.odom;

			roadModel.nbrLine = lines_synchronization.laneAlignement.QtyLine;
			for(int i = 0; i < 5; i++)	// roadModel_lines est un tableau 5 lignes
			{
				roadModel.roadLine[i] = lines_synchronization.laneAlignement.line[i];
			}

			pub.publish(roadModel);
			*/
			#endif
		}

		//----------
		if(finemapmatchingReceived)
		{
			//finemapmatchingReceived = false;
		}

		//----------
		if((electronicHorizonReceived) || (finemapmatchingReceived))
		{
			electronicHorizonReceived = false;
			finemapmatchingReceived = false;

			#ifdef PROJECT_S_SIMULATION
			#ifdef SIMULATION_CIRCUIT_LINE

			//electronicHorizonArray = electronic_Horizon_Report.ElectronicHorizonArray[0];
			electronicHorizonArray = fine_map_matching.electronicHorizonArray;

			double dt = (electronicHorizonArray.header.stamp - fine_map_matching.header.stamp).toSec();

			roadModel_EH.header.stamp = electronicHorizonArray.header.stamp;

			int indexMPP = electronicHorizonArray.indexMPP.data;
			roadModel_EH.electronicHorizon = electronicHorizonArray.PathsArray[indexMPP];

			//-----
			// correction curviligne
			project_s_msgs::ehSpotCoordGeo SpotCoordGeo_ego;
			SpotCoordGeo_ego.offset.data = roadModel_EH.electronicHorizon.ehPosition.offset.data;

			SpotCoordGeo_ego.offset.data += fine_map_matching.dX.data;

			// recherche d'un encadrement de la position de l'égo par 2 pts de ligne droite, et 2 pts de ligne gauche
			project_s_msgs::ehSpotCoordGeo SpotCoordGeo_right_align;
			for(int i = 0; i < roadModel_EH.electronicHorizon.NbrSpotCoordGeoRight.data-1; i++)
			{
				project_s_msgs::ehSpotCoordGeo SpotCoordGeo_right_1, SpotCoordGeo_right_2;
				SpotCoordGeo_right_1 = roadModel_EH.electronicHorizon.ehSpotCoordGeoRight[i];
				SpotCoordGeo_right_2 = roadModel_EH.electronicHorizon.ehSpotCoordGeoRight[i+1];

				if((SpotCoordGeo_right_1.offset.data <= SpotCoordGeo_ego.offset.data) && (SpotCoordGeo_ego.offset.data <= SpotCoordGeo_right_2.offset.data))
				{
					SpotCoordGeo_right_align.offset = SpotCoordGeo_ego.offset;

					SpotCoordGeo_right_align.latitude  = SpotCoordGeo_right_2.latitude        - SpotCoordGeo_right_1.latitude;
					SpotCoordGeo_right_align.latitude /= SpotCoordGeo_right_2.offset.data     - SpotCoordGeo_right_1.offset.data;
					SpotCoordGeo_right_align.latitude *= SpotCoordGeo_right_align.offset.data - SpotCoordGeo_right_1.offset.data;
					SpotCoordGeo_right_align.latitude += SpotCoordGeo_right_1.latitude;

					SpotCoordGeo_right_align.longitude  = SpotCoordGeo_right_2.longitude       - SpotCoordGeo_right_1.longitude;
					SpotCoordGeo_right_align.longitude /= SpotCoordGeo_right_2.offset.data     - SpotCoordGeo_right_1.offset.data;
					SpotCoordGeo_right_align.longitude *= SpotCoordGeo_right_align.offset.data - SpotCoordGeo_right_1.offset.data;
					SpotCoordGeo_right_align.longitude += SpotCoordGeo_right_1.longitude;
				}
			}

			project_s_msgs::ehSpotCoordGeo SpotCoordGeo_left_align;
			for(int i = 0; i < roadModel_EH.electronicHorizon.NbrSpotCoordGeoLeft.data-1; i++)
			{
				project_s_msgs::ehSpotCoordGeo SpotCoordGeo_left_1, SpotCoordGeo_left_2;
				SpotCoordGeo_left_1 = roadModel_EH.electronicHorizon.ehSpotCoordGeoLeft[i];
				SpotCoordGeo_left_2 = roadModel_EH.electronicHorizon.ehSpotCoordGeoLeft[i+1];

				if((SpotCoordGeo_left_1.offset.data <= SpotCoordGeo_ego.offset.data) && (SpotCoordGeo_ego.offset.data <= SpotCoordGeo_left_2.offset.data))
				{
					SpotCoordGeo_left_align.offset = SpotCoordGeo_ego.offset;

					SpotCoordGeo_left_align.latitude  = SpotCoordGeo_left_2.latitude        - SpotCoordGeo_left_1.latitude;
					SpotCoordGeo_left_align.latitude /= SpotCoordGeo_left_2.offset.data     - SpotCoordGeo_left_1.offset.data;
					SpotCoordGeo_left_align.latitude *= SpotCoordGeo_left_align.offset.data - SpotCoordGeo_left_1.offset.data;
					SpotCoordGeo_left_align.latitude += SpotCoordGeo_left_1.latitude;

					SpotCoordGeo_left_align.longitude  = SpotCoordGeo_left_2.longitude       - SpotCoordGeo_left_1.longitude;
					SpotCoordGeo_left_align.longitude /= SpotCoordGeo_left_2.offset.data     - SpotCoordGeo_left_1.offset.data;
					SpotCoordGeo_left_align.longitude *= SpotCoordGeo_left_align.offset.data - SpotCoordGeo_left_1.offset.data;
					SpotCoordGeo_left_align.longitude += SpotCoordGeo_left_1.longitude;
				}
			}

			// milieu du segment
			SpotCoordGeo_ego.latitude  = (SpotCoordGeo_right_align.latitude  + SpotCoordGeo_left_align.latitude) /2.0;
			SpotCoordGeo_ego.longitude = (SpotCoordGeo_right_align.longitude + SpotCoordGeo_left_align.longitude)/2.0;

			// correction latérale
			// calcul de l'arc de cercle entre 2 points de coordonnées géographiques
			double dY_align;
			dY_align  = cos((SpotCoordGeo_right_align.longitude - SpotCoordGeo_left_align.longitude)/180.0*M_PI);
			dY_align *= cos(SpotCoordGeo_right_align.latitude/180.0*M_PI) * cos(SpotCoordGeo_left_align.latitude/180.0*M_PI);
			dY_align += sin(SpotCoordGeo_right_align.latitude/180.0*M_PI) * sin(SpotCoordGeo_left_align.latitude/180.0*M_PI);
			dY_align  = acos(dY_align);
			dY_align *= RAYON_TERRE;

			// règle de 3 pour calculer le delta_latitude & delta_longitude correspondant au fine_map_matching.dy
			project_s_msgs::ehSpotCoordGeo delta_CoordGeo;
			delta_CoordGeo.latitude  = SpotCoordGeo_right_align.latitude - SpotCoordGeo_left_align.latitude;
			delta_CoordGeo.latitude /= dY_align;
			delta_CoordGeo.latitude *= fine_map_matching.dY.data;

			delta_CoordGeo.longitude  = SpotCoordGeo_right_align.longitude - SpotCoordGeo_left_align.longitude;
			delta_CoordGeo.longitude /= dY_align;
			delta_CoordGeo.longitude *= fine_map_matching.dY.data;

			// correction
			SpotCoordGeo_ego.latitude  += delta_CoordGeo.latitude;
			SpotCoordGeo_ego.longitude += delta_CoordGeo.longitude;

			// calcul du cap de la voie par rapport au Nord
			// en se basant sur le delta_latitude & delta_longitude (cotés oposé et adjacent du triangle rectangle)
			double delta_latitude, delta_longitude;
			/* A REVOIR 		delta_longitude  = cos((SpotCoordGeo_right_align.longitude - SpotCoordGeo_left_align.longitude)/180.0*M_PI);
			delta_longitude *= pow(cos(SpotCoordGeo_right_align.latitude/180.0*M_PI), 2);
			delta_longitude += pow(sin(SpotCoordGeo_right_align.latitude/180.0*M_PI), 2);
			delta_longitude  = acos(delta_longitude);
			delta_longitude *= RAYON_TERRE;*/

			delta_longitude  = SpotCoordGeo_right_align.longitude/180.0*M_PI * RAYON_TERRE;
			delta_longitude -= SpotCoordGeo_left_align.longitude/ 180.0*M_PI * RAYON_TERRE;
			delta_longitude *= cos(LATITUDE_ORIGIN/180.0*M_PI);

			delta_latitude  = (SpotCoordGeo_right_align.latitude - SpotCoordGeo_left_align.latitude)/180.0*M_PI;
			delta_latitude *= RAYON_TERRE;

			double SpotCoordGeo_ego_Cap;
			if(delta_longitude != 0)
			{
				SpotCoordGeo_ego_Cap = +atan(delta_latitude/delta_longitude);

				if(delta_longitude < 0){
					if(delta_latitude >= 0)
						SpotCoordGeo_ego_Cap += M_PI;
					if(delta_latitude < 0)
						SpotCoordGeo_ego_Cap -= M_PI;
				}
			}
			else
			{
				if(delta_latitude > 0)
					SpotCoordGeo_ego_Cap = +M_PI/2.0;
				else if(delta_latitude < 0)
					SpotCoordGeo_ego_Cap = -M_PI/2.0;
				else
					SpotCoordGeo_ego_Cap = 0;	// indéterminé dans le cas delta_longitude = 0 & delta_latitude = 0
			}

			// correction
			SpotCoordGeo_ego_Cap += fine_map_matching.dCap.data;

			//-----
			// conversion des coordonnées géographiques -> cartographiques
			// ego véhicule
			geometry_msgs::Point ptRef;
			ptRef = Convertion_Coord_Geo_vers_Carto(SpotCoordGeo_ego.latitude, SpotCoordGeo_ego.longitude);

			// position & cap réel de l'égo
			roadModel_EH.odom = electronicHorizonArray.odom;
			/*
			// pour un alignement parfait, soit on force l'odom aux calculs de road model
			roadModel_EH.odom.pose.pose.position = ptRef;
			roadModel_EH.odom.pose.pose.orientation = tf::createQuaternionMsgFromYaw(SpotCoordGeo_ego_Cap);
			*/
			// soit on force les calculs à l'odom de l'EH
			//ptRef = roadModel_EH.odom.pose.pose.position;
			//SpotCoordGeo_ego_Cap = tf::getYaw(roadModel_EH.odom.pose.pose.orientation);

			// Recherche de l'ego data le mieux synchronisé
			project_s_msgs::EgoData ego_data;

			double tempsREF = (roadModel_EH.odom.header.stamp).toSec();
			uint iMIN = 0;
			double dtMIN = fabs((ego_data_report.EgoData[iMIN].stamp).toSec() - tempsREF);
			ego_data = ego_data_report.EgoData[iMIN];

			for(uint i = 0; i < project_s_msgs::EgoDataReport::NBR_MAX_EGO_DATA; i++)
			{
				double dt = fabs((ego_data_report.EgoData[i].stamp).toSec() - tempsREF);
				if(dt < dtMIN)
				{
					dtMIN = dt;
					iMIN = i;
					ego_data = ego_data_report.EgoData[iMIN];
				}
			}

			SpotCoordGeo_ego_Cap = ego_data.cap;

			//-----
			// Lignes de l'EH
			geometry_msgs::Point ptFixe;
			float distance_Spot_Ego;
			int indice_segment = 0;

			// ligne de droite
			for(int i = 0; i < roadModel_EH.electronicHorizon.NbrSpotCoordGeoRight.data; i++)
			{
				distance_Spot_Ego = roadModel_EH.electronicHorizon.ehSpotCoordGeoRight[i].offset.data - roadModel_EH.electronicHorizon.ehPosition.offset.data;
				if((-15.0 <= distance_Spot_Ego) && (distance_Spot_Ego <= +30.0))
				{
					ptFixe = Convertion_Coord_Geo_vers_Carto(roadModel_EH.electronicHorizon.ehSpotCoordGeoRight[i].latitude, \
										 roadModel_EH.electronicHorizon.ehSpotCoordGeoRight[i].longitude);

					// convertion dans le repère de l'égo
					geometry_msgs::Point ptMobile = computeRelativePosition(ptRef, SpotCoordGeo_ego_Cap, ptFixe);
					roadModel_EH.roadLine[0].segment[indice_segment].position    = ptMobile;
					roadModel_EH.roadLine[0].segment[indice_segment].length.data = distance_Spot_Ego;
					if(indice_segment == 0)
						// angle de la tangente de la line par rapport à l'orientation de l'ego
						roadModel_EH.roadLine[0].segment[indice_segment].angle.data = 0;
					else
					{
						roadModel_EH.roadLine[0].segment[indice_segment].angle.data  = atan((ptMobile.y - roadModel_EH.roadLine[0].segment[indice_segment-1].position.y) \
														   /(ptMobile.x - roadModel_EH.roadLine[0].segment[indice_segment-1].position.x));
						if((ptMobile.x - roadModel_EH.roadLine[0].segment[indice_segment-1].position.x) < 0)
							roadModel_EH.roadLine[0].segment[indice_segment].angle.data += M_PI;
					}

					indice_segment++;
				}
			}

			roadModel_EH.roadLine[0].QtySegment.data = indice_segment;

			// ligne de gauche
			indice_segment = 0;
			for(int i = 0; i < roadModel_EH.electronicHorizon.NbrSpotCoordGeoLeft.data; i++)
			{
				distance_Spot_Ego = roadModel_EH.electronicHorizon.ehSpotCoordGeoLeft[i].offset.data - roadModel_EH.electronicHorizon.ehPosition.offset.data;
				if((-15.0 <= distance_Spot_Ego) && (distance_Spot_Ego <= +30.0))
				{
					ptFixe = Convertion_Coord_Geo_vers_Carto(roadModel_EH.electronicHorizon.ehSpotCoordGeoLeft[i].latitude, \
										 roadModel_EH.electronicHorizon.ehSpotCoordGeoLeft[i].longitude);

					// convertion dans le repère de l'égo
					geometry_msgs::Point ptMobile = computeRelativePosition(ptRef, SpotCoordGeo_ego_Cap, ptFixe);
					roadModel_EH.roadLine[1].segment[indice_segment].position    = ptMobile;
					roadModel_EH.roadLine[1].segment[indice_segment].length.data = distance_Spot_Ego;
					if(indice_segment == 0)
						// angle de la tangente de la line par rapport à l'orientation de l'ego
						roadModel_EH.roadLine[1].segment[indice_segment].angle.data = 0;
					else{
						roadModel_EH.roadLine[1].segment[indice_segment].angle.data  = atan((ptMobile.y - roadModel_EH.roadLine[1].segment[indice_segment-1].position.y) \
														   /(ptMobile.x - roadModel_EH.roadLine[1].segment[indice_segment-1].position.x));
						if((ptMobile.x - roadModel_EH.roadLine[1].segment[indice_segment-1].position.x) < 0)
							roadModel_EH.roadLine[1].segment[indice_segment].angle.data += M_PI;
						}

					indice_segment++;
				}
			}

			roadModel_EH.roadLine[1].QtySegment.data = indice_segment;

			//-----
			// plannification des tableaux d'évolution de la vitesse limite
			// -> speedLimit
			for(int i = 0; i < roadModel_EH.electronicHorizon.NbrSegment.data; i++){	// hyp : roadModel_EH.electronicHorizon.ehSegment[] classé par ordre croissant d'offset
				if(roadModel_EH.electronicHorizon.ehPosition.offset.data >= roadModel_EH.electronicHorizon.ehSegment[i].offset.data)	// garde le dernier Segment antérieur à la position
					i_actuel = i;
			}

			int index = 0;

			for(int i = i_actuel; i < roadModel_EH.electronicHorizon.NbrSegment.data; i++, index++){
				float delta_offset;
				delta_offset = roadModel_EH.electronicHorizon.ehSegment[i].offset.data - roadModel_EH.electronicHorizon.ehPosition.offset.data;
				if(delta_offset < 0)
					delta_offset = 0;

				speedLimit[index].offset = delta_offset;
				speedLimit[index].speed  = roadModel_EH.electronicHorizon.ehSegment[i].effectiveSpeedLimit.data;	
			}

			// ajout vitesse nulle à la fin du trajet plannifié
			{
			int i = roadModel_EH.electronicHorizon.NbrSegment.data - 1;
			if((i >= 0) && (indexMPP == 1)){
			float delta_offset;
			delta_offset = roadModel_EH.electronicHorizon.ehSegment[i].offset.data - roadModel_EH.electronicHorizon.ehPosition.offset.data - 5;
			if(delta_offset < 0){ delta_offset = 0; index=0;}
			speedLimit[index].offset = delta_offset;
			speedLimit[index].speed  = 0;	
			index++;
			}
			}


			// on complete le tableau avec des valeurs NULL
			for(; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
				speedLimit[index].offset = OFFSET_NULL;
				speedLimit[index].speed  = 0;
			}

			// -> speedLimit_trafficSign 
			index = 0;

			// on garde le tableau avec les limitations antérieures
			for(int id = 0; id < obstacleFusion.QtyObstacles.data; id++){
				if(   (obstacleFusion.ObstacleFusion[id].obstacleClass == project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN)
				   && (obstacleFusion.ObstacleFusion[id].obstaclePosition.position.x < 10.0)){
					float delta_offset;
					delta_offset = obstacleFusion.ObstacleFusion[id].obstaclePosition.position.x;
					if(delta_offset < 0){
						delta_offset = 0;
						index = 0;
					}
					else{
						delta_offset = std::sqrt(std::pow(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.x,2)
								       + std::pow(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.y,2));
						if(speedLimit_trafficSign[0].offset == OFFSET_NULL) index = 0;
						else index++;
					}
					speedLimit_trafficSign[index].offset = delta_offset;

					switch(obstacleFusion.ObstacleFusion[id].vision_only_sign_type){
					case mobileye_560_660_msgs::Tsr::SIGN_TYPE_REGULAR_50 :
						speedLimit_trafficSign[index].speed = 3;
						break;
					case mobileye_560_660_msgs::Tsr::SIGN_TYPE_REGULAR_90 :
						speedLimit_trafficSign[index].speed = 7;
						break;
					}
				}
			}
				for(index += 1; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
					speedLimit_trafficSign[index].offset = OFFSET_NULL;	// on efface la limitation du panneau precedente.
					speedLimit_trafficSign[index].speed  = 0;
				}

			if(i_actuel == 0){							// dans le cas du premier segment,
				for(index = 0; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
					speedLimit_trafficSign[index].offset = OFFSET_NULL;	// on efface la limitation du panneau precedente.
					speedLimit_trafficSign[index].speed  = 0;
				}
			}
			/*

			// -> speedLateralConfort
			#define	ACCELERATION_LATERALE_MAX	+2.0	// m/s2

			for(int i = 0; i < roadModel_EH.electronicHorizon.NbrSpotCurvature.data; i++){	// hyp : roadModel_EH.electronicHorizon.ehSpotCurvature[] classé par ordre croissant d'offset
				if(roadModel_EH.electronicHorizon.ehPosition.offset.data >= roadModel_EH.electronicHorizon.ehSpotCurvature[i].offset.data) // garde le dernier Spot antérieur à la position
					i_actuel = i;
			}

			index = 0;

			for(int i = i_actuel; i < roadModel_EH.electronicHorizon.NbrSpotCurvature.data; i++){
				float delta_offset;
				delta_offset = roadModel_EH.electronicHorizon.ehSpotCurvature[i].offset.data - roadModel_EH.electronicHorizon.ehPosition.offset.data;
				if(delta_offset < 0)
					delta_offset = 0;

				float Curvature;
				Curvature = roadModel_EH.electronicHorizon.ehSpotCurvature[i].Value_0.data;
				if(Curvature != 0){
					speedLateralConfort[index].offset = delta_offset;
					speedLateralConfort[index].speed  = sqrt(ACCELERATION_LATERALE_MAX/Curvature);
					index++;
				}
				else{
					speedLateralConfort[index].offset = delta_offset;
					speedLateralConfort[index].speed  = SPEED_NULL;
					index++;
				}
			}
			// on complete le tableau avec des valeurs NULL
			for(; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
			//			for(index = 0; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
				speedLateralConfort[index].offset = OFFSET_NULL;
				speedLateralConfort[index].speed  = 0;
			}
			*/
			// -> collision avoidance
			/*		
				for(int i = 0; i < roadModel_EH.electronicHorizon.NbrSegment.data; i++){	// hyp : roadModel_EH.electronicHorizon.ehSegment[] classé par ordre croissant d'offset
				if(roadModel_EH.electronicHorizon.ehPosition.offset.data >= roadModel_EH.electronicHorizon.ehSegment[i].offset.data)	// garde le dernier Segment antérieur à la position
					i_actuel = i;
			}*/

			index = 0;

			speedCollisionAvoidance[index].offset = OFFSET_NULL;
			speedCollisionAvoidance[index].speed  = 0;
			index++;
			/* A REMETTRE ???

			for(int id = 0; id < obstacleFusion.QtyObstacles.data; id++){
				float delta_offset;
				delta_offset = std::sqrt(std::pow(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.x,2)
						       + std::pow(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.y,2));
				//delta_offset = obstacleFusion.ObstacleFusion[id].obstaclePosition.position.x;
				if(   (delta_offset < 20.0)
				   && (abs(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.y) <  0.5)){
					speedCollisionAvoidance[index].offset = delta_offset - 5;
					speedCollisionAvoidance[index].speed  = 0;
					index++;

					if(obstacleFusion.ObstacleFusion[id].obstaclePosition.position.x < 5){
						delta_offset = 0;

						speedCollisionAvoidance[0].offset = delta_offset;
						speedCollisionAvoidance[0].speed  = 0;
						index=1;
					}
				}
			}*/
			// on complete le tableau avec des valeurs NULL
			for(; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
				speedCollisionAvoidance[index].offset = OFFSET_NULL;
				speedCollisionAvoidance[index].speed  = 0;
			}

			// -> speedEnveloppe
			// test de la consigne la plus basse
			int i_speedEnveloppe = 0;
			int i_speedLimit = 0;
			int i_speedLimit_trafficSign = 0;
			/*			int i_speedLateralConfort = 0;*/
			int i_speedCollisionAvoidance = 0;

			float offset_speedEnveloppe, speed_speedEnveloppe;

			// premier enregistrement de speedEnveloppe
			{
				// recherche de l'offset le + proche
				offset_speedEnveloppe = 0;

				// recherche de la vitesse la + basse
				speed_speedEnveloppe = speedLimit[0].speed;		// hyp : speedLimit[0] toujours renseigné
				/*				if((speed_speedEnveloppe > speedLateralConfort[0].speed)    && (speedLateralConfort[0].offset == 0)){
					speed_speedEnveloppe = speedLateralConfort[0].speed;
				}*/
				if((speed_speedEnveloppe > speedLimit_trafficSign[0].speed) && (speedLimit_trafficSign[0].offset == 0)){
					speed_speedEnveloppe = speedLimit_trafficSign[0].speed;
				}
				if((speed_speedEnveloppe > speedCollisionAvoidance[0].speed)&& (speedCollisionAvoidance[0].offset == 0)){
					speed_speedEnveloppe = speedCollisionAvoidance[0].speed;
				}

				// enregistrement dans tableau
				roadModel_EH.speedEnveloppe[i_speedEnveloppe].offset.data = offset_speedEnveloppe;
				roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data  = speed_speedEnveloppe;
			}

			// enregistrements suivants de speedEnveloppe
			do{
				// recherche de l'offset le + proche
				uint origine_speedEnveloppe = 0x00;
				#define	ORIGINE_LIMITATION		0x01
				/*				#define	ORIGINE_LATERAL_CONFORT		0x02*/
				#define	ORIGINE_LIMITATION_TRAFFIC_SIGN	0x04
				#define	ORIGINE_COLLISION_AVOIDANCE	0x08

				offset_speedEnveloppe = OFFSET_NULL;
				if(i_speedLimit+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe > speedLimit[i_speedLimit+1].offset)                         && (speedLimit[i_speedLimit+1].offset != OFFSET_NULL)){
					origine_speedEnveloppe = ORIGINE_LIMITATION;
					offset_speedEnveloppe  = speedLimit[i_speedLimit+1].offset;
				}}
				/*				if(i_speedLateralConfort+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe > speedLateralConfort[i_speedLateralConfort+1].offset)       && (speedLateralConfort[i_speedLateralConfort+1].offset != OFFSET_NULL)){
					origine_speedEnveloppe = ORIGINE_LATERAL_CONFORT;
					offset_speedEnveloppe  = speedLateralConfort[i_speedLateralConfort+1].offset;
				}}*/
				if(i_speedLimit_trafficSign+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe > speedLimit_trafficSign[i_speedLimit_trafficSign+1].offset) && (speedLimit_trafficSign[i_speedLimit_trafficSign+1].offset != OFFSET_NULL)){
					origine_speedEnveloppe = ORIGINE_LIMITATION_TRAFFIC_SIGN;
					offset_speedEnveloppe  = speedLimit_trafficSign[i_speedLimit_trafficSign+1].offset;
				}}
				if(i_speedCollisionAvoidance+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe > speedCollisionAvoidance[i_speedCollisionAvoidance+1].offset) && (speedCollisionAvoidance[i_speedCollisionAvoidance+1].offset != OFFSET_NULL)){
					origine_speedEnveloppe = ORIGINE_COLLISION_AVOIDANCE;
					offset_speedEnveloppe  = speedCollisionAvoidance[i_speedCollisionAvoidance+1].offset;
				}}
				// test du cas : plusieurs offsets egaux
				if(i_speedLimit+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe >= speedLimit[i_speedLimit+1].offset)                         && (speedLimit[i_speedLimit+1].offset != OFFSET_NULL))
					origine_speedEnveloppe |= ORIGINE_LIMITATION;}
				/*				if(i_speedLateralConfort+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe >= speedLateralConfort[i_speedLateralConfort+1].offset)       && (speedLateralConfort[i_speedLateralConfort+1].offset != OFFSET_NULL))
					origine_speedEnveloppe |= ORIGINE_LATERAL_CONFORT;}*/
				if(i_speedLimit_trafficSign+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe >= speedLimit_trafficSign[i_speedLimit_trafficSign+1].offset) && (speedLimit_trafficSign[i_speedLimit_trafficSign+1].offset != OFFSET_NULL))
					origine_speedEnveloppe |= ORIGINE_LIMITATION_TRAFFIC_SIGN;}
				if(i_speedCollisionAvoidance+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe >= speedCollisionAvoidance[i_speedCollisionAvoidance+1].offset)&&(speedCollisionAvoidance[i_speedCollisionAvoidance+1].offset != OFFSET_NULL))
					origine_speedEnveloppe |= ORIGINE_COLLISION_AVOIDANCE;}

				// màj de(s) l'indice(s) qui donne l'offset le + proche
				if(origine_speedEnveloppe & ORIGINE_LIMITATION)              i_speedLimit++;
				/*				if(origine_speedEnveloppe & ORIGINE_LATERAL_CONFORT)         i_speedLateralConfort++;*/
				if(origine_speedEnveloppe & ORIGINE_LIMITATION_TRAFFIC_SIGN) i_speedLimit_trafficSign++;
				if(origine_speedEnveloppe & ORIGINE_COLLISION_AVOIDANCE)     i_speedCollisionAvoidance++;

				// recherche de la vitesse la + basse
				if(offset_speedEnveloppe != OFFSET_NULL){
					speed_speedEnveloppe  = SPEED_NULL;
					if((speed_speedEnveloppe > speedLimit[i_speedLimit].speed)                         && (speedLimit[i_speedLimit].offset != OFFSET_NULL)){
						speed_speedEnveloppe = speedLimit[i_speedLimit].speed;
					}
					/*					if((speed_speedEnveloppe > speedLateralConfort[i_speedLateralConfort].speed)       && (speedLateralConfort[i_speedLateralConfort].offset != OFFSET_NULL)){
						speed_speedEnveloppe = speedLateralConfort[i_speedLateralConfort].speed;
					}*/
					if((speed_speedEnveloppe > speedLimit_trafficSign[i_speedLimit_trafficSign].speed) && (speedLimit_trafficSign[i_speedLimit_trafficSign].offset != OFFSET_NULL)){
						speed_speedEnveloppe = speedLimit_trafficSign[i_speedLimit_trafficSign].speed;
					}
					if((speed_speedEnveloppe > speedCollisionAvoidance[i_speedCollisionAvoidance].speed)&&(speedCollisionAvoidance[i_speedCollisionAvoidance].offset != OFFSET_NULL)){
						speed_speedEnveloppe = speedCollisionAvoidance[i_speedCollisionAvoidance].speed;
					}

					// test si changement de vitesse (+ ou -) par rapport au dernier enregistrement dans tableau
					if(speed_speedEnveloppe != roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data)
					{
						i_speedEnveloppe++;
						roadModel_EH.speedEnveloppe[i_speedEnveloppe].offset.data = offset_speedEnveloppe;
						roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data  = speed_speedEnveloppe;
					}
				}
				else{
					i_speedEnveloppe++;
					roadModel_EH.speedEnveloppe[i_speedEnveloppe].offset.data = OFFSET_NULL;
					roadModel_EH.speedEnveloppe[i_speedEnveloppe].speed.data  = 0;
				}
			}while(i_speedEnveloppe < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE-1);	// on complete (éventuellement) le tableau avec des valeurs NULL

			//-----
			pub_road_model_EH.publish(roadModel_EH);
			#endif
			#endif
		}

		loop_rate.sleep();
	}

	return 0;
}
