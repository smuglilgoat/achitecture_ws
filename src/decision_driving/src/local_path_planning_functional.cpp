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

#include <ros/ros.h>
#include "std_msgs/UInt32.h"

#include "project_s_msgs/Configurations.h"
#include "project_s_msgs/Trajectory.h"
#include "project_s_msgs/LaneAlignment.h"
#include "project_s_msgs/LaneFusion.h"
#include "project_s_msgs/RoadModel.h"
#include "project_s_msgs/RouteLine.h"
#include "project_s_msgs/ObstacleFusionReport.h"
#include "project_s_msgs/TargetSelection.h"
#include "project_s_msgs/EgoDataReport.h"

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::RoadModel roadModel;
project_s_msgs::ObstacleFusionReport obstacleFusion, obstacleAssignment;
project_s_msgs::TargetSelection targetSelection;
std_msgs::UInt32 mission_manager;
project_s_msgs::Trajectory trajectory_generation;
project_s_msgs::RoadModel roadModel_EH;
std_msgs::Float64 Speed;	// à enlever une fois que l'on se sera servi uniquement de EgoData
project_s_msgs::EgoDataReport ego_data_report;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::Trajectory trajectory, trajectory_GPS;
geometry_msgs::Twist cmd_vel;
project_s_msgs::Trajectory trajectory_clothoide_virage, trajectory_clothoide, trajectory_clothoide_reference;

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
#define	K_ref	0.001
#define ds_ref	(sqrt(2/K_ref)*sqrt(M_PI/4.0)/25.0)
		// theta = PI/4 sur 25 points

void clothoide_reference(void){
	float t;
	float theta=0;
	float Xn = 0, Yn = 0;

	float dt = ds_ref*sqrt(K_ref/2.0);

	for(int i=0;i<25;i++){
		t = i * dt;
		theta += dt*((2*(t-0))+dt);
		Xn += ds_ref*cos(theta);
		Yn += ds_ref*sin(theta);
		trajectory_clothoide_reference.trajectoryLine.segment[i].position.x = Xn + 0.0;	// +3.0 correspond à la longueur de la voiture
		trajectory_clothoide_reference.trajectoryLine.segment[i].position.y = Yn;
		trajectory_clothoide_reference.trajectoryLine.segment[i].angle.data = theta;
	}

	for(int i=25;i<75;i++){
		t = i * dt;
		theta -= dt*((2*(t-50*dt))+dt);
		Xn += ds_ref*cos(theta);
		Yn += ds_ref*sin(theta);
		trajectory_clothoide_reference.trajectoryLine.segment[i].position.x = Xn + 0.0;
		trajectory_clothoide_reference.trajectoryLine.segment[i].position.y = Yn;
		trajectory_clothoide_reference.trajectoryLine.segment[i].angle.data = theta;
	}

	for(int i=75;i<100;i++){
		t = i * dt;
		theta += dt*((2*(t-100*dt))+dt);
		Xn += ds_ref*cos(theta);
		Yn += ds_ref*sin(theta);
		trajectory_clothoide_reference.trajectoryLine.segment[i].position.x = Xn + 0.0;
		trajectory_clothoide_reference.trajectoryLine.segment[i].position.y = Yn;
		trajectory_clothoide_reference.trajectoryLine.segment[i].angle.data = theta;
	}
}

//-------------------------------------------------------------------------------------------------
float R_confort = 493;
float Y2_voulu = 2.5;
float K;
void define_K(void){
	for(int i=0;i<100;i++){
		
	}
K = 0.0199;
}

//-------------------------------------------------------------------------------------------------
//#define	K	0.0142
//int nbr_point = 12;	// doit être <= 25
//#define	K	0.0199
int nbr_point = 12;	// doit être <= 25

void clothoide(void){
	trajectory_clothoide = project_s_msgs::Trajectory();
	//trajectory_clothoide = trajectory_clothoide_reference;

	for(int i=0;i<=nbr_point;i++){
		trajectory_clothoide.trajectoryLine.segment[i].position.x = trajectory_clothoide_reference.trajectoryLine.segment[i].position.x/sqrt(K/K_ref);
		trajectory_clothoide.trajectoryLine.segment[i].position.y = trajectory_clothoide_reference.trajectoryLine.segment[i].position.y/sqrt(K/K_ref);
		trajectory_clothoide.trajectoryLine.segment[i].angle      = trajectory_clothoide_reference.trajectoryLine.segment[i].angle;
	}

	for(int i=nbr_point+1;i<=2*nbr_point;i++){
		float X, Y;
		X  =       trajectory_clothoide.trajectoryLine.segment[nbr_point].position.x;
		X +=      (trajectory_clothoide.trajectoryLine.segment[2*nbr_point-i].position.x-trajectory_clothoide.trajectoryLine.segment[nbr_point].position.x) \
			 *(-pow(cos(trajectory_clothoide.trajectoryLine.segment[nbr_point].angle.data),2)+pow(sin(trajectory_clothoide.trajectoryLine.segment[nbr_point].angle.data),2));
		X += -2.0*(trajectory_clothoide.trajectoryLine.segment[2*nbr_point-i].position.y-trajectory_clothoide.trajectoryLine.segment[nbr_point].position.y) \
			 *sin(trajectory_clothoide.trajectoryLine.segment[nbr_point].angle.data)*cos(trajectory_clothoide.trajectoryLine.segment[nbr_point].angle.data);
		trajectory_clothoide.trajectoryLine.segment[i].position.x = X;

		Y  =       trajectory_clothoide.trajectoryLine.segment[nbr_point].position.y;
		Y += -2.0*(trajectory_clothoide.trajectoryLine.segment[2*nbr_point-i].position.x-trajectory_clothoide.trajectoryLine.segment[nbr_point].position.x) \
			 *sin(trajectory_clothoide.trajectoryLine.segment[nbr_point].angle.data)*cos(trajectory_clothoide.trajectoryLine.segment[nbr_point].angle.data);
		Y +=      (trajectory_clothoide.trajectoryLine.segment[2*nbr_point-i].position.y-trajectory_clothoide.trajectoryLine.segment[nbr_point].position.y) \
			 *(-pow(sin(trajectory_clothoide.trajectoryLine.segment[nbr_point].angle.data),2)+pow(cos(trajectory_clothoide.trajectoryLine.segment[nbr_point].angle.data),2));
		trajectory_clothoide.trajectoryLine.segment[i].position.y = Y;

		trajectory_clothoide.trajectoryLine.segment[i].angle.data = trajectory_clothoide.trajectoryLine.segment[i-1].angle.data \
                                                         		  + trajectory_clothoide.trajectoryLine.segment[(2*nbr_point)-i+1].angle.data \
									  - trajectory_clothoide.trajectoryLine.segment[(2*nbr_point)-i].angle.data;
	}

	for(int i=2*nbr_point+1;i<4*nbr_point;i++){
		trajectory_clothoide.trajectoryLine.segment[i].position.x = 2.0*trajectory_clothoide.trajectoryLine.segment[2*nbr_point].position.x \
									    -   trajectory_clothoide.trajectoryLine.segment[4*nbr_point-i].position.x;
		trajectory_clothoide.trajectoryLine.segment[i].position.y = 2.0*trajectory_clothoide.trajectoryLine.segment[2*nbr_point].position.y \
									    -   trajectory_clothoide.trajectoryLine.segment[4*nbr_point-i].position.y;

		trajectory_clothoide.trajectoryLine.segment[i].angle      = trajectory_clothoide_reference.trajectoryLine.segment[(4*nbr_point)-i+1].angle;
	}

	// on se sert de length pour enregistrer l'abscisse curviligne
	trajectory_clothoide.trajectoryLine.segment[0].length.data = sqrt(pow(trajectory_clothoide.trajectoryLine.segment[0].position.x,2) \
									+ pow(trajectory_clothoide.trajectoryLine.segment[0].position.y,2));
	for(int i=1;i<4*nbr_point;i++){
		trajectory_clothoide.trajectoryLine.segment[i].length       = trajectory_clothoide.trajectoryLine.segment[i-1].length;
		trajectory_clothoide.trajectoryLine.segment[i].length.data += sqrt(pow((trajectory_clothoide.trajectoryLine.segment[i].position.x \
										       -trajectory_clothoide.trajectoryLine.segment[i-1].position.x),2) \
										 + pow((trajectory_clothoide.trajectoryLine.segment[i].position.y \
										       -trajectory_clothoide.trajectoryLine.segment[i-1].position.y),2));
	}
}

//-------------------------------------------------------------------------------------------------
void clothoide_virage(void){
	float s_virage     = trajectory_clothoide.trajectoryLine.segment[4*nbr_point-1].length.data;
	float theta_virage = s_virage/(20+3.5/2);

	trajectory_clothoide_virage = project_s_msgs::Trajectory();
/*	for(int i=0;i<4*nbr_point;i++){

		// calculs du virage circulaire
		trajectory_clothoide_virage.trajectoryLine.segment[i].position.x = (cos(i*theta_virage/(4*nbr_point) + M_PI*3.0/2.0)    ) * (20+3.5/2);
		trajectory_clothoide_virage.trajectoryLine.segment[i].position.y = (sin(i*theta_virage/(4*nbr_point) + M_PI*3.0/2.0) + 1) * (20+3.5/2);
		trajectory_clothoide_virage.trajectoryLine.segment[i].angle.data = i*theta_virage/(4*nbr_point);

		// association de la clothoide
		trajectory_clothoide_virage.trajectoryLine.segment[i].position.x -= trajectory_clothoide.trajectoryLine.segment[i].position.y \
										    *sin(trajectory_clothoide_virage.trajectoryLine.segment[i].angle.data);
		trajectory_clothoide_virage.trajectoryLine.segment[i].position.y += trajectory_clothoide.trajectoryLine.segment[i].position.y \
										    *cos(trajectory_clothoide_virage.trajectoryLine.segment[i].angle.data);
	}*/

	for(int i=0;i<trajectory_generation.trajectoryLine.QtySegment.data;i++){	// trajectory_generation sur 9 points
		trajectory_clothoide_virage.trajectoryLine.segment[i] = trajectory_generation.trajectoryLine.segment[i];
		trajectory_clothoide_virage.trajectoryLine.segment[i].angle.data = i/10*M_PI/4;

		// association de la clothoide
		trajectory_clothoide_virage.trajectoryLine.segment[i].position.x -= trajectory_clothoide.trajectoryLine.segment[i*5].position.y \
										    *sin(trajectory_clothoide_virage.trajectoryLine.segment[i].angle.data);
		trajectory_clothoide_virage.trajectoryLine.segment[i].position.y += trajectory_clothoide.trajectoryLine.segment[i*5].position.y \
										    *cos(trajectory_clothoide_virage.trajectoryLine.segment[i].angle.data);
	}
}

//-------------------------------------------------------------------------------------------------
void clothoide_virage_EH(void){
	project_s_msgs::Trajectory trajectory;
	trajectory.odom = roadModel_EH.odom;

	// calculs de la trajectoire en se basant sur la ligne droite de l'EH
	int QtySegment = 0;
	for(int i=0;i<roadModel_EH.roadLine[0].QtySegment.data;i++){
		if(roadModel_EH.roadLine[0].segment[i].length.data > 0){
			trajectory.trajectoryLine.segment[QtySegment]             = roadModel_EH.roadLine[0].segment[i];
			trajectory.trajectoryLine.segment[QtySegment].position.x -= 3.5/2.0 *sin(trajectory.trajectoryLine.segment[QtySegment].angle.data);
			trajectory.trajectoryLine.segment[QtySegment].position.y += 3.5/2.0 *cos(trajectory.trajectoryLine.segment[QtySegment].angle.data);
			QtySegment++;
		}

	}
	trajectory.trajectoryLine.QtySegment.data = QtySegment;

	trajectory_clothoide_virage = project_s_msgs::Trajectory();
	trajectory_clothoide_virage.odom = trajectory.odom;

	// ajout de la clothoide sur la portion en commun
	QtySegment = 0;
	for(int i=0;i<trajectory.trajectoryLine.QtySegment.data;i++){
		// recherche du point de clothoide le + proche
		int jj;
		for(int j=0;j<4*nbr_point;j++){
			if(trajectory_clothoide.trajectoryLine.segment[j].length.data < trajectory.trajectoryLine.segment[i].length.data)
				jj = j;
		}

		trajectory_clothoide_virage.trajectoryLine.segment[QtySegment] = trajectory.trajectoryLine.segment[i];
		QtySegment++;

		// association de la clothoide
		trajectory_clothoide_virage.trajectoryLine.segment[i].position.x -= trajectory_clothoide.trajectoryLine.segment[jj].position.y \
										    *sin(trajectory_clothoide_virage.trajectoryLine.segment[i].angle.data);
		trajectory_clothoide_virage.trajectoryLine.segment[i].position.y += trajectory_clothoide.trajectoryLine.segment[jj].position.y \
										    *cos(trajectory_clothoide_virage.trajectoryLine.segment[i].angle.data);

	}
	trajectory_clothoide_virage.trajectoryLine.QtySegment.data = QtySegment;
}

//-------------------------------------------------------------------------------------------------
float barycentre(float data1, float C1, float data2, float C2){
	float moyenne;
	moyenne  = (data1 * C1) + (data2 * C2);
	moyenne /= (C1 + C2);
	return moyenne;
}

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool roadModelReceived = false;
void roadModelCallback(const project_s_msgs::RoadModel::ConstPtr& ptrRoadModel)
{
  roadModel = *ptrRoadModel;

  roadModelReceived = true;
}

void obstacles_fusion_Callback(const project_s_msgs::ObstacleFusionReport::ConstPtr& ptrObstacleFusion)
{
	obstacleFusion = *ptrObstacleFusion;
//	received = true;
}

void obstacles_assignment_Callback(const project_s_msgs::ObstacleFusionReport::ConstPtr& ptrObstacleFusion)
{
	obstacleAssignment = *ptrObstacleFusion;
//	received = true;
}

void targetSelectionCallback(const project_s_msgs::TargetSelection::ConstPtr& ptrTargetSelection)
{
	targetSelection = *ptrTargetSelection;
//	received = true;
}

// Callback functions for receiving topics
bool receivedMissionManager = false;
void missionManagerCallback(const std_msgs::UInt32::ConstPtr& msg)
{
	mission_manager = *msg;

	receivedMissionManager = true;
}

/*bool received_trajectory_generation = false;
void trajectory_generation_Callback(const project_s_msgs::Trajectory::ConstPtr& buffer)
{
	trajectory_generation = *buffer;

	received_trajectory_generation = true;
}*/

bool received_road_model = false;
void roadModelDataCallback(const project_s_msgs::RoadModel::ConstPtr& buffer)
{
	roadModel_EH = *buffer;
//	odom_EH = roadModel_EH.odom;

	received_road_model = true;
}

void Vehicle_Speed_Planning_Callback(const std_msgs::Float64::ConstPtr& buffer)
{
	Speed = *buffer;
}

bool receivedEgoDataReport = false;
void egoDataCallback(const project_s_msgs::EgoDataReport::ConstPtr& buffer)
{
	ego_data_report = *buffer;

	receivedEgoDataReport = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "local_path_planning");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher trajectory_pub = n.advertise<project_s_msgs::Trajectory>("/trajectory_generation_data", 1);
	ros::Publisher trajectory_GPS_pub = n.advertise<project_s_msgs::Trajectory>("/trajectory_GPS_generation_data", 1);
	ros::Publisher cmd_vel_pub    = n.advertise<geometry_msgs::Twist>("/trajectory_generation_vel", 1);
	ros::Publisher pub_trajectory_generation_clothoide    = n.advertise<project_s_msgs::Trajectory>("/trajectory_generation_clothoide", 1);

	// Subscriber 
	ros::Subscriber roadmodel_sub = n.subscribe(std::string("/road_model_data"), 1, roadModelCallback);
	ros::Subscriber sub_road_model_EH = n.subscribe("/road_model_EH_data", 1, roadModelDataCallback);
	ros::Subscriber sub_viewed_obstacle = n.subscribe(std::string("/global_tracks_update_data"), 1, obstacles_fusion_Callback);
	ros::Subscriber sub_obstacles_assignment = n.subscribe(std::string("/obstacles_assignment_data"), 1, obstacles_assignment_Callback);
	ros::Subscriber target_selection_sub = n.subscribe(std::string("/target_selection_data"), 1, targetSelectionCallback);
	ros::Subscriber sub_mission_manager = n.subscribe(std::string("/mission_manager_nbr"), 1, missionManagerCallback);
	ros::Subscriber sub_vehicle_speed_planning = n.subscribe(std::string("/vehicle_speed_planning"), 1, Vehicle_Speed_Planning_Callback);
	ros::Subscriber subEgoData = n.subscribe(std::string("/ego_data"), 1, egoDataCallback);

	ros::Rate loop_rate(25);

	clothoide_reference();

  	while(n.ok())
	{
		ros::spinOnce();

		if(receivedMissionManager)
		{
			receivedMissionManager = false;

			if(mission_manager.data == 0){
				cmd_vel.linear.x  = 0;
			}
			else{
				cmd_vel.linear.x  = 3;
			}

			cmd_vel_pub.publish(cmd_vel);
		}

		if(roadModelReceived)
		{
			roadModelReceived = false;

			trajectory        = project_s_msgs::Trajectory();
			trajectory.header = roadModel.header;
			trajectory.id     = roadModel.id;
			trajectory.odom   = roadModel.odom;

/*#ifndef PROJECT_S_SIMULATION
			geometry_msgs::Point p;
			double distance;
			uint i = 0;
			do{
				p = roadModel.roadLine[0].segment[i].position;
				distance = std::sqrt(std::pow(roadModel.roadLine[0].segment[i].position.x,2) + std::pow(roadModel.roadLine[0].segment[i].position.y,2));
				i++;
			}while(distance < 6);

			trajectory.setpointPosition.position = p;
#endif*/

#ifdef PROJECT_S_SIMULATION

			bool FirstSetPoint = true;
			uint QtySegment = 0;

			roadModel.roadLine[0].QtySegment.data = 200;
			for(uint i=0; i<roadModel.roadLine[0].QtySegment.data-1; i++)
			{
				float Xm, Ym;
				float Xn, Yn, N;
				Xn = Yn = 0;		// consigne à 0 par défaut

				// consigne en prenant compte de la ligne de droite
				if(  ((roadModel.roadLine[0].segment[i].position.x   > 0) && (roadModel.roadLine[0].segment[i].position.y   != 0))	// roadLine[0] ligne de droite
   				   &&((roadModel.roadLine[0].segment[i+1].position.x > 0) && (roadModel.roadLine[0].segment[i+1].position.y != 0)))
				{
					// calcul du milieu segment	
					//float Xm, Ym;
					Xm  = roadModel.roadLine[0].segment[i].position.x + roadModel.roadLine[0].segment[i+1].position.x;
					Xm /= 2.0;
					Ym  = roadModel.roadLine[0].segment[i].position.y + roadModel.roadLine[0].segment[i+1].position.y;
					Ym /= 2.0;

					// calcul du vecteur normal
					//float Xn, Yn, N;
					Xn  = roadModel.roadLine[0].segment[i+1].position.x - roadModel.roadLine[0].segment[i].position.x;		
					Yn  = roadModel.roadLine[0].segment[i+1].position.y - roadModel.roadLine[0].segment[i].position.y;	
					N = Xn;				// on se sert de N comme buffer		
					// N = sqrt(Xn*Xn + Yn*Yn);	// sera fait plus loin

					Xn = -Yn;		
					Yn = N;				// N contient Xn
					N = sqrt(Xn*Xn + Yn*Yn);
					Xn /= N;
					Yn /= N;

					// calcul du milieu voie
					Xn = Xm + 3.50/2*Xn;		// largeur de voie constante à 3,50m
					//Yn = Ym + 3.50/2*Yn;
					if(Yn > 0.5)			// test pour "platrer" un bug de simu
						Yn = Ym + 3.50/2*Yn;
					else
						Yn = Ym + 3.50/2*1.0;
				}	

				// consigne en prenant compte de la ligne du milieu (ligne de gauche de notre voie)
				float Xn2, Yn2;
				Xn2 = Yn2 = 0;		// consigne à 0 par défaut

				if(  ((roadModel.roadLine[1].segment[i].position.x   > 0) && (roadModel.roadLine[1].segment[i].position.y   != 0))	// roadLine[1] ligne du milieu
   				   &&((roadModel.roadLine[1].segment[i+1].position.x > 0) && (roadModel.roadLine[1].segment[i+1].position.y != 0)))
				{
					// calcul du milieu segment	
					Xm  = roadModel.roadLine[1].segment[i].position.x + roadModel.roadLine[1].segment[i+1].position.x;
					Xm /= 2.0;
					Ym  = roadModel.roadLine[1].segment[i].position.y + roadModel.roadLine[1].segment[i+1].position.y;
					Ym /= 2.0;

					// calcul du vecteur normal
					Xn2  = roadModel.roadLine[1].segment[i+1].position.x - roadModel.roadLine[1].segment[i].position.x;		
					Yn2  = roadModel.roadLine[1].segment[i+1].position.y - roadModel.roadLine[1].segment[i].position.y;	
					N = Xn2;			// on se sert de N comme buffer		
					// N = sqrt(Xn2*Xn2 + Yn2*Yn2);	// sera fait plus loin

					Xn2 = -Yn2;		
					Yn2 = N;			// N contient Xn
					N = sqrt(Xn2*Xn2 + Yn2*Yn2);
					Xn2 /= N;
					Yn2 /= N;

					// calcul du milieu voie
					Xn2 = Xm - 3.50/2*Xn2;		// largeur de voie constante à 3,50m	// -Xn car ligne du milieu (à gauche)
					Yn2 = Ym - 3.50/2*Yn2;	
				}

//				// moyenne des 2 consignes provenant ligne de droite et ligne de gauche
//				if((Xn == 0) && (Yn == 0))
//				{
//					Xn = Xn2;
//					Yn = Yn2;
//				}
//				if((Xn2 == 0) && (Yn2 == 0))
//				{
//					Xn2 = Xn;
//					Yn2 = Yn;
//				}
//				Xn = (Xn + Xn2)/2;
//				Yn = (Yn + Yn2)/2;

				// on prend en priorité la consige provenant de la ligne de droite, sinon la consigne provenant de la ligne du milieu
				if(   ((Xn  == 0) && (Yn  == 0))
				   && ((Xn2 != 0) || (Yn2 != 0)))
				{
					Xn = Xn2;
					Yn = Yn2;
				}
				//else
				//{
				//	Xn = Xn;
				//	Yn = Yn;
				//}

				// pub du point
				geometry_msgs::Point p;
				if((Xn != 0) || (Yn != 0))
				{
					// prise en compte del'obstacle
					for(int k = 0; k < obstacleFusion.QtyObstacles.data; k++)
					{
						double deltaX, deltaY;
						deltaX = obstacleFusion.ObstacleFusion[k].obstaclePosition.position.x - Xn;
						deltaY = obstacleFusion.ObstacleFusion[k].obstaclePosition.position.y - Yn;

//						if(obstacleFusion.ObstacleFusion[k].id.data != 0)
						{
							if(sqrt((deltaX)*(deltaX) + (deltaY)*(deltaY)) < 3.0)
							{	// si obstacle suffisamment proche,
								// on traite le changement de trajectoire
								if((deltaY > 0.0) && (deltaY < +5.0))
								{
//									Yn += -1;
//									Yn += -3.50;
								}
								if((deltaY < 0.0) && (deltaY > -5.0))
								{
//									Yn += +1;
//									Yn += +3.50;
								}
							}
						}
					}

					p.x = Xn;
					p.y = Yn;

//					// enregistrement du 1er point de la consigne de trajectoire
//					if(FirstSetPoint)
//					{
//						FirstSetPoint = false;
//
//						trajectory.setpointPosition.position = p;
//					}

					QtySegment++;
				}

				trajectory.trajectoryLine.segment[i].position = p;
				trajectory.trajectoryLine.segment[i].offset = std::sqrt(  std::pow(trajectory.trajectoryLine.segment[i].position.x,2)
										        + std::pow(trajectory.trajectoryLine.segment[i].position.y,2));
				trajectory.trajectoryLine.QtySegment.data = QtySegment;
			}

			// calcul du setpoint à xx secondes devant l'égo-véhicule
			FirstSetPoint = true;
			#define TEMPS_DEPLACEMENT	1.5					// 1s
			float t_i, t_i_1=0;
			for(uint i=0; i<trajectory.trajectoryLine.QtySegment.data; i++){
				t_i = trajectory.trajectoryLine.segment[i].offset / Speed.data;	// / 3.0 m/s
				if((FirstSetPoint) && (t_i > TEMPS_DEPLACEMENT)){
					FirstSetPoint = false;

					if((i == 0) || (t_i == t_i_1)){
						trajectory.setpointPosition.position = trajectory.trajectoryLine.segment[i].position;
					}
					else{
						float C1, C2;
						C2  = t_i - TEMPS_DEPLACEMENT;
						C2 /= (t_i - t_i_1);
						C1 = 1.0 - C2;

						trajectory.setpointPosition.position.x =  barycentre(trajectory.trajectoryLine.segment[i]  .position.x, C1,	// C1
                                                                       				     trajectory.trajectoryLine.segment[i-1].position.x, C2);	// C2
						trajectory.setpointPosition.position.y =  barycentre(trajectory.trajectoryLine.segment[i]  .position.y, C1,
                                                                     				     trajectory.trajectoryLine.segment[i-1].position.y, C2);
					}
				}

				t_i_1 = t_i;
			}

			// setpoint par défaut
			if(FirstSetPoint){
				FirstSetPoint = false;
				if(trajectory.trajectoryLine.QtySegment.data > 0)
					trajectory.setpointPosition.position = trajectory.trajectoryLine.segment[trajectory.trajectoryLine.QtySegment.data-1].position;
				else
					trajectory.setpointPosition.position = trajectory.trajectoryLine.segment[0].position;
					//trajectory.setpointPosition = geometry_msgs::Pose();
			}

			// code avec trajectory venant de GPS
			//if((roadModel.header.stamp).toSec() > (trajectory_GPS.header.stamp).toSec())
			{
				trajectory_GPS        = project_s_msgs::Trajectory();
				trajectory_GPS.header = roadModel.header;
				trajectory_GPS.id     = roadModel.id;
				trajectory_GPS.odom   = roadModel.odom;

				for(uint i=0; i<roadModel.roadLine[3].QtySegment.data; i++){
					trajectory_GPS.trajectoryLine.segment[i] = roadModel.roadLine[3].segment[i];
				}
				trajectory_GPS.trajectoryLine.QtySegment.data = roadModel.roadLine[3].QtySegment.data;
			}

			// calcul du setpoint à xx secondes devant l'égo-véhicule
			FirstSetPoint = true;
			t_i_1=0;
			for(uint i=0; i<trajectory_GPS.trajectoryLine.QtySegment.data; i++){
				t_i = trajectory_GPS.trajectoryLine.segment[i].offset / Speed.data;	// / 3.0 m/s
				if((FirstSetPoint) && (t_i > TEMPS_DEPLACEMENT)){
					FirstSetPoint = false;

					if((i == 0) || (t_i == t_i_1)){
						trajectory_GPS.setpointPosition.position = trajectory_GPS.trajectoryLine.segment[i].position;
					}
					else{
						float C1, C2;
						C2  = t_i - TEMPS_DEPLACEMENT;
						C2 /= (t_i - t_i_1);
						C1 = 1.0 - C2;

						trajectory_GPS.setpointPosition.position.x =  barycentre(trajectory_GPS.trajectoryLine.segment[i]  .position.x, C1,	// C1
                                                                       				         trajectory_GPS.trajectoryLine.segment[i-1].position.x, C2);	// C2
						trajectory_GPS.setpointPosition.position.y =  barycentre(trajectory_GPS.trajectoryLine.segment[i]  .position.y, C1,
                                                                     				         trajectory_GPS.trajectoryLine.segment[i-1].position.y, C2);
					}
				}

				t_i_1 = t_i;
			}

			// setpoint par défaut
			if(FirstSetPoint){
				FirstSetPoint = false;
				if(trajectory_GPS.trajectoryLine.QtySegment.data > 0)
					trajectory_GPS.setpointPosition.position = trajectory_GPS.trajectoryLine.segment[trajectory_GPS.trajectoryLine.QtySegment.data-1].position;
				else
					trajectory_GPS.setpointPosition.position = trajectory_GPS.trajectoryLine.segment[0].position;
					//trajectory_GPS.setpointPosition = geometry_msgs::Pose();
			}

			// fin

			//publish the message
			trajectory_pub.publish(trajectory);
			trajectory_GPS_pub.publish(trajectory_GPS);
#endif

#ifdef PROJECT_S_VEHICLE
			// code avec trajectory venant de GPS
			//if((roadModel.header.stamp).toSec() > (trajectory_GPS.header.stamp).toSec())
			{
				trajectory_GPS        = project_s_msgs::Trajectory();
				trajectory_GPS.header = roadModel.header;
				trajectory_GPS.id     = roadModel.id;
				trajectory_GPS.odom   = roadModel.odom;

				for(uint i=0; i<roadModel.roadLine[3].QtySegment.data; i++){
					trajectory_GPS.trajectoryLine.segment[i] = roadModel.roadLine[3].segment[i];
				}
				trajectory_GPS.trajectoryLine.QtySegment.data = roadModel.roadLine[3].QtySegment.data;
			}

//---------- evitement d'obstacle

for(int k = 0; k < obstacleAssignment.QtyObstacles.data; k++)
{	// pour chaque obstacle assigné dans la voie
if(  (obstacleAssignment.ObstacleFusion[k].NbrOccupiedLane == 1) 
  && (obstacleAssignment.ObstacleFusion[k].distanceCurviligne > 0) && (obstacleAssignment.ObstacleFusion[k].distanceCurviligne < 20)){

	// recherche du point trajectory le + proche de l'obstacle assigné dans la voie
	double deltaX=0;
	double deltaY=0;
	uint i_pt = 0;

	for(uint i=0; i<trajectory_GPS.trajectoryLine.QtySegment.data; i++){
		// position centrale
		double d_X = obstacleAssignment.ObstacleFusion[k].obstaclePosition.position.x - trajectory_GPS.trajectoryLine.segment[i].position.x;
		double d_Y = obstacleAssignment.ObstacleFusion[k].obstaclePosition.position.y - trajectory_GPS.trajectoryLine.segment[i].position.y;

		if((abs(d_X) < abs(deltaX)) || (deltaX == 0))
		{
			deltaX = d_X;
			deltaY = d_Y;
			i_pt = i;
		}
	}

	// cas d'évitement d'obstacle systématiquement par la gauche, si le coin gauche est à droite de la voie
	for(uint i=0; i<trajectory_GPS.trajectoryLine.QtySegment.data; i++){
		double d_X = trajectory_GPS.trajectoryLine.segment[i].position.x - trajectory_GPS.trajectoryLine.segment[i_pt].position.x;
		double d_Y = trajectory_GPS.trajectoryLine.segment[i].position.y - trajectory_GPS.trajectoryLine.segment[i_pt].position.y;

		// on traite le changement de trajectoire :
		// - si l'obstacle est à droite de la trajectoire initiale,
		// - pour les points 10m avant et après l'obstacle,
		// - pour les points devant le véhicule jusqu'à 20m
		if((deltaY < 0) && (abs(d_X) < 10) && (trajectory_GPS.trajectoryLine.segment[i].offset < 20))
		{
			trajectory_GPS.trajectoryLine.segment[i].position.y += 1.5 /*+ deltaY*/; // revient à obstacleCorner[].y + 1,5m
		}
	}
}
}

/*
for(int k = 0; k < obstacleAssignment.QtyObstacles.data; k++)
{
if(obstacleAssignment.ObstacleFusion[k].NbrOccupiedLane == 1){
	double deltaX=0;
	double deltaY=0;

	for(int c = 0; c < 4; c++){
		double d_X = obstacleAssignment.ObstacleFusion[k].obstacleCorner[c].x - trajectory_GPS.trajectoryLine.segment[i].position.x;
		double d_Y = obstacleAssignment.ObstacleFusion[k].obstacleCorner[c].y - trajectory_GPS.trajectoryLine.segment[i].position.y;

		// selection du coin le + proche en X
		if((abs(d_X) < abs(deltaX)) || (deltaX == 0)) deltaX = d_X;
		// et                le + près dans la trajectoire en Y
		if((abs(d_Y) < abs(deltaY)) || (deltaY == 0)) deltaY = d_Y;
	}

	if(   (sqrt(pow(deltaX,2) + pow(deltaY,2)) < 5.0)
	   && (deltaX > 0))
	{	// si obstacle suffisamment proche,
		// on traite le changement de trajectoire
		if((deltaY > 0.0) && (deltaY < +5.0))
		{
			trajectory_GPS.trajectoryLine.segment[i].position.y += -3.5;
		}
		if((deltaY < 0.0) && (deltaY > -5.0))
		{
			trajectory_GPS.trajectoryLine.segment[i].position.y += +3.5;
		}
	}

// cas d'évitement d'obstacle systématiquement par la gauche, si le coin gauche est à droite de la voie
	double deltaX=0;
	double deltaY=0;

	for(int c = 0; c < 4; c++){
		double d_X = obstacleAssignment.ObstacleFusion[k].obstacleCorner[c].x - trajectory_GPS.trajectoryLine.segment[i].position.x;
		double d_Y = obstacleAssignment.ObstacleFusion[k].obstacleCorner[c].y - trajectory_GPS.trajectoryLine.segment[i].position.y;

		// selection du coin le + à gauche en Y
		if((d_Y > deltaY) || (deltaY == 0)){
			deltaX = d_X;
			deltaY = d_Y;
		}
	}

// position centrale

		double d_X = obstacleAssignment.ObstacleFusion[k].obstaclePosition.position.x - trajectory_GPS.trajectoryLine.segment[i].position.x;
		double d_Y = obstacleAssignment.ObstacleFusion[k].obstaclePosition.position.y - trajectory_GPS.trajectoryLine.segment[i].position.y;

			deltaX = d_X;
			deltaY = d_Y;

	if((abs(deltaX) < 10) && (deltaY < 0))
	{	// si le coin est à droite de la voie,
		// on traite le changement de trajectoire
		trajectory_GPS.trajectoryLine.segment[i].position.y += 1.5 + deltaY; // revient à obstacleCorner[].y + 1,5m
	}

}
}*/
//---------- FIN


			// calcul du setpoint à xx secondes devant l'égo-véhicule
			bool FirstSetPoint = true;
			#define TEMPS_DEPLACEMENT	3					// 3s
			double speed = sqrt(pow(ego_data_report.EgoData[0].velocity.linear.x,2)+pow(ego_data_report.EgoData[0].velocity.linear.y,2));

			float t_i, t_i_1=0;
			for(uint i=0; i<trajectory_GPS.trajectoryLine.QtySegment.data; i++){
				if(speed >= 1.0){
//				if(speed != 0)
					t_i = trajectory_GPS.trajectoryLine.segment[i].offset / speed;
				}
				else{
					// si speed trop faible, on va viser entre les points [2] et [1]
					t_i   = TEMPS_DEPLACEMENT + 0.5;
					t_i_1 = TEMPS_DEPLACEMENT - 0.5;
				}

				if(i == 0) t_i_1 = t_i;

				if((FirstSetPoint) && (t_i > TEMPS_DEPLACEMENT)){
					FirstSetPoint = false;

					if((i == 0) || (t_i == t_i_1)){
int j = trajectory_GPS.trajectoryLine.QtySegment.data;
if (j > 5) j = 5;
						trajectory_GPS.setpointPosition.position = trajectory_GPS.trajectoryLine.segment[j-1].position;	// [4] a affiner
/*						float C1, C2;
						C2  = 0.5;
						C1 = 1.0 - C2;

						trajectory_GPS.setpointPosition.position.x =  barycentre(trajectory_GPS.trajectoryLine.segment[4]  .position.x, C1,	// C1
                                                                       				         trajectory_GPS.trajectoryLine.segment[3].position.x, C2);	// C2
						trajectory_GPS.setpointPosition.position.y =  barycentre(trajectory_GPS.trajectoryLine.segment[4]  .position.y, C1,
                                                                     				         trajectory_GPS.trajectoryLine.segment[3].position.y, C2);*/
					}
					else{
						float C1, C2;
						C2  = t_i - TEMPS_DEPLACEMENT;
						C2 /= (t_i - t_i_1);
						C1 = 1.0 - C2;

						trajectory_GPS.setpointPosition.position.x =  barycentre(trajectory_GPS.trajectoryLine.segment[i]  .position.x, C1,	// C1
                                                                       				         trajectory_GPS.trajectoryLine.segment[i-1].position.x, C2);	// C2
						trajectory_GPS.setpointPosition.position.y =  barycentre(trajectory_GPS.trajectoryLine.segment[i]  .position.y, C1,
                                                                     				         trajectory_GPS.trajectoryLine.segment[i-1].position.y, C2);
					}

/*					if((i == 0) || (t_i == t_i_1))
						i = 2;	// [2] a affiner

					float C1, C2;
					C2  = t_i - TEMPS_DEPLACEMENT;
					C2 /= (t_i - t_i_1);
					C1 = 1.0 - C2;

					trajectory_GPS.setpointPosition.position.x =  barycentre(trajectory_GPS.trajectoryLine.segment[i]  .position.x, C1,	// C1
                                                                       				 trajectory_GPS.trajectoryLine.segment[i-1].position.x, C2);	// C2
					trajectory_GPS.setpointPosition.position.y =  barycentre(trajectory_GPS.trajectoryLine.segment[i]  .position.y, C1,
                                                                     				 trajectory_GPS.trajectoryLine.segment[i-1].position.y, C2);*/
				}

				t_i_1 = t_i;
			}

			//publish the message
			trajectory_GPS_pub.publish(trajectory_GPS);
#endif

		}

		/*if(received_trajectory_generation)
		{
			received_trajectory_generation = false;

			define_K();

			clothoide();
			//pub_trajectory_generation_clothoide.publish(trajectory_clothoide);

			clothoide_virage();
			//pub_trajectory_generation_clothoide.publish(trajectory_clothoide_virage);
		}*/

		if(received_road_model)
		{
			received_road_model = false;

			define_K();

			clothoide();

			clothoide_virage_EH();

			pub_trajectory_generation_clothoide.publish(trajectory_clothoide_virage);
		}

		if(receivedEgoDataReport){
			receivedEgoDataReport = false;
		}

		loop_rate.sleep();
	}

	return 0;
}

