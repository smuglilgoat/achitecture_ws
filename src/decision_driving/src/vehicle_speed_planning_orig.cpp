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
#include "std_msgs/Float64.h"
#include "std_msgs/UInt32.h"
#include "project_s_msgs/EgoDataReport.h"
#include "project_s_msgs/RoadModel.h"

//#include <boost/bind.hpp>
#include <dynamic_reconfigure/server.h>
#include <decision_driving/SpeedConfig.h>
 
//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::EgoDataReport ego_data_report;
project_s_msgs::RoadModel roadModel;

#define	OFFSET_NULL		9999.0

std_msgs::UInt32 circuit_manager;
#define MISSION_STOP		0
#define MISSION_SQUARE		1
#define MISSION_EIGHT		2

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
std_msgs::Float64 Speed;
float SPEED_DEFAULT_VALUE;
//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------
struct speedLimitStruct{
float offset;
#define	OFFSET_NULL		9999.0
float speed;
//#define	SPEED_DEFAULT_VALUE		6
};

struct speedLimitStruct speedLimit[project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE], speedLateralConfort[project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE], speedEnveloppe[project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE];

#define DELTA_T			0.1					// 100ms
float SpeedConsigne[project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE];	// tableau de la consigne de vitesse sur DELTA_T * SPEED_LIMIT_ARRAY_SIZE

std_msgs::UInt32 mission_manager_status;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedEgoDataReport = false;
void egoDataCallback(const project_s_msgs::EgoDataReport::ConstPtr& buffer)
{
	ego_data_report = *buffer;

	receivedEgoDataReport = true;
}

bool roadModelReceived = false;
void road_model_EH_Callback(const project_s_msgs::RoadModel::ConstPtr& buffer)
{
	roadModel = *buffer;

	roadModelReceived = true;
}

bool receivedCircuitManager = false;
void circuit_manager_Callback(const std_msgs::UInt32::ConstPtr& msg)
{
	circuit_manager = *msg;

	receivedCircuitManager = true;
}



void config_callback(decision_driving::SpeedConfig &config, uint32_t level) {
  //ROS_INFO("Reconfigure speed_default_value: %f ",config.speed_default_value);
  SPEED_DEFAULT_VALUE=config.speed_default_value;
}


//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "vehicle_speed_planning");

	ros::NodeHandle n;


	dynamic_reconfigure::Server<decision_driving::SpeedConfig> server;
  	dynamic_reconfigure::Server<decision_driving::SpeedConfig>::CallbackType f;



	// Publisher
	ros::Publisher pub_vehicle_speed_planning = n.advertise<std_msgs::Float64>(std::string("/vehicle_speed_planning"), 1);

	//Speed.data = 1.0;		// vitesse initiale, unité = m/s

	// Subscriber 
	ros::Subscriber subEgoData        = n.subscribe(std::string("/ego_data"),           1, egoDataCallback);
	ros::Subscriber sub_road_model_EH = n.subscribe(std::string("/road_model_EH_data"), 1, road_model_EH_Callback);
	ros::Subscriber sub_circuit_manager = n.subscribe(std::string("/circuit_manager_cmd"), 1, circuit_manager_Callback);

	ros::Rate loop_rate(25);

	ros::Time current_time, last_time;
	last_time = ros::Time::now();

	mission_manager_status.data = MISSION_STOP;

  	while(n.ok())
	{
		ros::spinOnce();

		f = boost::bind(&config_callback, _1, _2);
  		server.setCallback(f);
		//printf("SPEED_DEFAULT_VALUE  %f  \n",SPEED_DEFAULT_VALUE);

		//----------
		switch(mission_manager_status.data)
		{
		case MISSION_STOP :
		case MISSION_EIGHT :
		case MISSION_SQUARE :
			if(receivedCircuitManager)
			{
				receivedCircuitManager = false;

				mission_manager_status.data = circuit_manager.data;
			}
			break;

		default :
			mission_manager_status.data = MISSION_STOP;    
			break;
		}

		//----------
		if(roadModelReceived)
		{
			roadModelReceived = false;

			//-----
			if(mission_manager_status.data == MISSION_STOP){     // Original

				roadModel.speedEnveloppe[0].offset.data = OFFSET_NULL;
				roadModel.speedEnveloppe[0].speed.data  = 0;
			}

			//-----
			// Recherche de l'ego data le mieux synchronisé
			project_s_msgs::EgoData ego_data;

			double tempsREF = (roadModel.odom.header.stamp).toSec();
			uint iMIN = 0;
			double dtMIN = fabs((ego_data_report.EgoData[iMIN].stamp).toSec() - tempsREF);
			ego_data = ego_data_report.EgoData[iMIN];

			for(uint i = 0; i < project_s_msgs::EgoDataReport::NBR_MAX_EGO_DATA; i++){
				double dt = fabs((ego_data_report.EgoData[i].stamp).toSec() - tempsREF);
				if(dt < dtMIN){
					dtMIN = dt;
					iMIN = i;
					ego_data = ego_data_report.EgoData[iMIN];
				}
			}

			//-----
			// -> speedLateralConfort
			#define	ACCELERATION_LATERALE_MAX	+0.5	// m/s2

			int i_actuel;

			for(int i = 0; i < roadModel.electronicHorizon.NbrSpotCurvature.data; i++){	// hyp : roadModel.electronicHorizon.ehSpotCurvature[] classé par ordre croissant d'offset
				if(roadModel.electronicHorizon.ehPosition.offset.data >= roadModel.electronicHorizon.ehSpotCurvature[i].offset.data) // garde le dernier Spot antérieur à la position
					i_actuel = i;
			}

			int index = 0;

			for(int i = i_actuel; i < roadModel.electronicHorizon.NbrSpotCurvature.data; i++){
				float delta_offset;
				delta_offset = roadModel.electronicHorizon.ehSpotCurvature[i].offset.data - roadModel.electronicHorizon.ehPosition.offset.data;
				//printf("ehPosition.offset  %f   \n",roadModel.electronicHorizon.ehPosition.offset.data);
				//printf("speedLateralConfort.offset  %f   \n",delta_offset);

				if(delta_offset < 0)
					delta_offset = 0;
				//printf("ehPostion %f \n",roadModel.electronicHorizon.ehPosition.offset.data);
				float Curvature;
				Curvature = roadModel.electronicHorizon.ehSpotCurvature[i].Value_0.data;
				if(Curvature != 0){
					if(index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
						speedLateralConfort[index].offset = delta_offset;
						speedLateralConfort[index].speed  = sqrt(ACCELERATION_LATERALE_MAX/fabs(Curvature));
						index++;
					}
				}
				else{
					if(index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
						speedLateralConfort[index].offset = delta_offset;
						speedLateralConfort[index].speed  = SPEED_DEFAULT_VALUE;
						index++;
					}
				}

			
			}
			// on complete le tableau avec des valeurs NULL
			for(; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
				// POUR TEST
				//			for(index = 0; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
				// FIN
				speedLateralConfort[index].offset = OFFSET_NULL;
				speedLateralConfort[index].speed  = 0;
			}

			// -> speedLimit

			for(index = 0; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
				speedLimit[index].offset = roadModel.speedEnveloppe[index].offset.data;
				speedLimit[index].speed  = roadModel.speedEnveloppe[index].speed.data;
				//printf("speedLimit.offset  %f data : %f  \n",speedLimit[index].offset,speedLimit[index].speed);

			}

			// POUR TEST
			//for(index = 1; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
			//	speedLimit[index].offset = OFFSET_NULL;
			//	speedLimit[index].speed  = 0;
			//}
			// FIN


			// test de la consigne la plus basse
			// -> speedEnveloppe
			int i_speedEnveloppe = 0;
			int i_speedLimit = 0;
			int i_speedLateralConfort = 0;

			float offset_speedEnveloppe, speed_speedEnveloppe;

			// premier enregistrement de speedEnveloppe
			{
				// recherche de l'offset le + proche
				offset_speedEnveloppe = 0;

				// recherche de la vitesse la + basse
				speed_speedEnveloppe = speedLimit[0].speed;		// hyp : speedLimit[0] toujours renseigné
				if((speed_speedEnveloppe > speedLateralConfort[0].speed) && (speedLateralConfort[0].offset == 0)){
					speed_speedEnveloppe = speedLateralConfort[0].speed;
				}

				// enregistrement dans tableau
				speedEnveloppe[i_speedEnveloppe].offset = offset_speedEnveloppe;
				speedEnveloppe[i_speedEnveloppe].speed  = speed_speedEnveloppe;
			}

			// enregistrements suivants de speedEnveloppe
			do{
				// recherche de l'offset le + proche
				uint origine_speedEnveloppe = 0x00;
				#define	ORIGINE_LIMITATION		0x01
				#define	ORIGINE_LATERAL_CONFORT		0x02

				offset_speedEnveloppe = OFFSET_NULL;
				if(i_speedLimit+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe > speedLimit[i_speedLimit+1].offset)				&& (speedLimit[i_speedLimit+1].offset != OFFSET_NULL)){
					origine_speedEnveloppe = ORIGINE_LIMITATION;
					offset_speedEnveloppe  = speedLimit[i_speedLimit+1].offset;
				}}
				if(i_speedLateralConfort+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe > speedLateralConfort[i_speedLateralConfort+1].offset)	&& (speedLateralConfort[i_speedLateralConfort+1].offset != OFFSET_NULL)){
					origine_speedEnveloppe = ORIGINE_LATERAL_CONFORT;
					offset_speedEnveloppe  = speedLateralConfort[i_speedLateralConfort+1].offset;
				}}
				
				// test du cas : plusieurs offsets egaux
				if(i_speedLimit+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe >= speedLimit[i_speedLimit+1].offset)				&& (speedLimit[i_speedLimit+1].offset != OFFSET_NULL))
					origine_speedEnveloppe |= ORIGINE_LIMITATION;}
				if(i_speedLateralConfort+1 < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE){
				if((offset_speedEnveloppe >= speedLateralConfort[i_speedLateralConfort+1].offset)	&& (speedLateralConfort[i_speedLateralConfort+1].offset != OFFSET_NULL))
					origine_speedEnveloppe |= ORIGINE_LATERAL_CONFORT;}

				// màj de(s) l'indice(s) qui donne l'offset le + proche
				if(origine_speedEnveloppe & ORIGINE_LIMITATION)              i_speedLimit++;
				if(origine_speedEnveloppe & ORIGINE_LATERAL_CONFORT)         i_speedLateralConfort++;

				// recherche de la vitesse la + basse
				if(offset_speedEnveloppe != OFFSET_NULL){
					speed_speedEnveloppe  = SPEED_DEFAULT_VALUE;
					if((speed_speedEnveloppe > speedLimit[i_speedLimit].speed)			&& (speedLimit[i_speedLimit].offset != OFFSET_NULL)){
					//if (speedLimit[i_speedLimit].offset != OFFSET_NULL){
						speed_speedEnveloppe = speedLimit[i_speedLimit].speed;
						//printf(" speedEnveloppe %f  \n", speed_speedEnveloppe);
					}


					if((speed_speedEnveloppe > speedLateralConfort[i_speedLateralConfort].speed)	&& (speedLateralConfort[i_speedLateralConfort].offset != OFFSET_NULL)){
						speed_speedEnveloppe = speedLateralConfort[i_speedLateralConfort].speed;
						//printf(" speedLateralConfort %f  \n", speed_speedEnveloppe);


					}

					// test si changement de vitesse (+ ou -) par rapport au dernier enregistrement dans tableau
					if(speed_speedEnveloppe != speedEnveloppe[i_speedEnveloppe].speed)
					{
						i_speedEnveloppe++;
						speedEnveloppe[i_speedEnveloppe].offset = offset_speedEnveloppe;
						speedEnveloppe[i_speedEnveloppe].speed  = speed_speedEnveloppe;
					//	printf(" Offset %f speedEnveloppe_Final  %f  \n",offset_speedEnveloppe,speed_speedEnveloppe);
					}
				}
				else{
					i_speedEnveloppe++;
					speedEnveloppe[i_speedEnveloppe].offset = OFFSET_NULL;
					speedEnveloppe[i_speedEnveloppe].speed  = 0;
				}
			}while(i_speedEnveloppe < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE-1);	// on complete le tableau avec des valeurs NULL

			// POUR TEST
			//for(index = 0; index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; index++){
			//	speedEnveloppe[index] = speedLimit[index];
			//}


			//-----
			// filtrage de la vitesse
			current_time = ros::Time::now();
			double dt = (current_time - last_time).toSec();
			last_time = current_time;

			float speed_limitation;
			#define	ACCELERATION_MAX	+1.0     //+0.5	// m/s2		(rappel : 0-100km/h en 10s correspond a une acceleration de 2,777m/s2)
			#define	DECELERATION_MAX	+0.5   //  +0.5	// m/s2		signe +, on gère le signe negatif dans le code

			float acceleration_limitation;
			#define	JERK_MAX	  +3.0	// +10.0	// m/s3		soit une accéleration max de 1m/s2 en DELTA_T = 0.1s

			#define CONSTANTE_TEMPS		1	// s		constante de temps du filtrage de 1er ordre de la consigne de vitesse
								//		(rappel : 64% d'amplitude pour t=Cste, soit par ex. 5m/s*0.64/1s = 3.2m/s2 pour Cste=1s)

			// plannification temporelle du tableau d'évolution de la vitesse limite
			float speed_forward_buffer[project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE], speed_reward_buffer[project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE];

			index = 0;

			for(int i = 0; i < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE-1; i++){
				int delta_nbr = 0;

				float delta_offset;

				if(speedEnveloppe[i+1].offset != OFFSET_NULL)
					delta_offset = speedEnveloppe[i+1].offset - speedEnveloppe[i].offset;
				else
					delta_offset = 0;

				float velocity = std::sqrt(std::pow(ego_data.velocity.linear.x,2) + std::pow(ego_data.velocity.linear.y,2));

				if((velocity != 0) && (delta_offset != 0)){
					float delta_temps;
					delta_temps = delta_offset / velocity;

					delta_nbr = (int)((float)delta_temps/(float)DELTA_T);
					//if(delta_nbr == 0) delta_nbr = SPEED_ARRAY_SIZE;
				}
				else{
					delta_nbr = project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE;
				}
				while((index < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE) && (delta_nbr > 0) ){ 
					speed_reward_buffer[index] = speedEnveloppe[i].speed;	// consigne théorique
 					speed_forward_buffer[index] = speedEnveloppe[i].speed;	
					index++;
					delta_nbr--;
				//	printf("index %i  speed_forward_buffer %f \n",index,float (speed_forward_buffer[index]));
				}

			}


			// filtrage sens chrono
			speed_forward_buffer[0] = Speed.data;	// consigne effective precedente

			for(int i = 1; i < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; i++){
				// limitation en acceleration
				speed_limitation = speed_forward_buffer[i-1] + ACCELERATION_MAX*DELTA_T;
				if(speed_forward_buffer[i] > speed_limitation)
					speed_forward_buffer[i] = speed_limitation;
			}

			// filtrage sens anti-chrono
			//speed_reward_buffer[project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE-1] = inchangé

			for(int i = project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE-2; i > 0; i--){
				// limitation en deceleration
				speed_limitation = speed_reward_buffer[i+1] + DECELERATION_MAX*DELTA_T;
				if(speed_reward_buffer[i] > speed_limitation)
					speed_reward_buffer[i] = speed_limitation;
			}

			// recuperation de la consigne la plus basse
			SpeedConsigne[0] = speed_forward_buffer[0];
			for(int i = 1; i < project_s_msgs::RoadModel::SPEED_LIMIT_ARRAY_SIZE; i++){
				SpeedConsigne[i] = speed_forward_buffer[i];
				if(speed_reward_buffer[i] < speed_forward_buffer[i])
					SpeedConsigne[i] = speed_reward_buffer[i];
			//	printf("SpeedConsigne[i]  %f  \n",SpeedConsigne[i]);


				/*	 // limitation en jerk
				acceleration_limitation = SpeedConsigne[i-1] + JERK_MAX*DELTA_T*DELTA_T;
				if(SpeedConsigne[i] > acceleration_limitation)
					SpeedConsigne[i] = acceleration_limitation;z

				acceleration_limitation = SpeedConsigne[i-1] - JERK_MAX*DELTA_T*DELTA_T;
				if(acceleration_limitation < 0) acceleration_limitation = 0;
				if(SpeedConsigne[i] < acceleration_limitation)
					SpeedConsigne[i] = acceleration_limitation;*/

			}
			
			//printf(" SpeedConsigne[0] %f \n", SpeedConsigne[0] );

			//printf(" SpeedConsigne[1] %f \n", SpeedConsigne[1] );

			Speed.data = SpeedConsigne[1];

			// printf("*****Speed.data 1  %f  \n",SpeedConsigne[1]);

		}

		//----------
		pub_vehicle_speed_planning.publish(Speed);

		// POUR AFFICHAGE
		std_msgs::Float64 buffer;
		//buffer.data = roadModel.speedEnveloppe[0].speed.data;
		buffer.data = speedEnveloppe[0].speed;

		//ROS_ERROR("Consigne : %f   Speed : %f", buffer.data, Speed.data);
		//ROS_ERROR("Consigne : %f", buffer.data);

		loop_rate.sleep();
	}

	return 0;
}
