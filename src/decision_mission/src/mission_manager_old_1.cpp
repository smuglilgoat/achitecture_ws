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
#include <math.h>
#include <cmath>

#include "std_msgs/UInt32.h"
#include "std_msgs/Bool.h"
#include "project_s_msgs/MissionManagerModem.h"
#include "project_s_msgs/toMissionServer.h"
#include "project_s_msgs/fromMissionServer.h"
#include "project_s_msgs/ElectronicHorizonArray.h"
#include "project_s_msgs/RoadModel.h"

#include "ros/ros.h"

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
std_msgs::UInt32 circuit_manager;
std_msgs::Bool saut_indice;
project_s_msgs::MissionManagerModem mission_manager_modem;
project_s_msgs::fromMissionServer fromMissionServer;
project_s_msgs::ElectronicHorizonArray electronicHorizonArray, electronic_Horizon_Array;
project_s_msgs::RoadModel roadModel_EH;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
std_msgs::Bool mission_manager_reset;
std_msgs::UInt32 mission_manager_nbr;
std_msgs::UInt32 mission_manager_status;
/*
#define MISSION_STOP		0
#define MISSION_SQUARE		1
#define MISSION_EIGHT		2
*/
/*
#define STARTING_VEHICLE		0
#define WAITING_FOR_MISSION		1
#define SHUTDOWN			2
#define NAVIGATION_TO_DESTINATION	3
*/
#define	ID_CAR		1

project_s_msgs::toMissionServer toMissionServer;
std_msgs::UInt8 circuit_choice;

//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedCircuitManager = false;
void circuitManagerCallback(const std_msgs::UInt32::ConstPtr& msg)
{
	circuit_manager = *msg;

	receivedCircuitManager = true;
}

bool receivedEndMission = false;
void endMissionCallback(const std_msgs::Bool::ConstPtr& msg)
{
	saut_indice = *msg;

	receivedEndMission = true;
}


bool receivedMissionManagerModem = false;
void MissionManagerModemCallback(const project_s_msgs::MissionManagerModem::ConstPtr& msg)
{
	mission_manager_modem = *msg;

	receivedMissionManagerModem = true;
}

bool receivedfromMissionServer = false;
void fromMissionServerCallback(const project_s_msgs::fromMissionServer::ConstPtr& msg)
{
	fromMissionServer = *msg;

	receivedfromMissionServer = true;
}

bool electronicHorizonArrayReceived = false;
void electronicHorizonArrayCallback(const project_s_msgs::ElectronicHorizonArray::ConstPtr& buffer)
{
	electronic_Horizon_Array = *buffer;

	electronicHorizonArrayReceived = true;
}

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("circuit_manager"));

	ros::NodeHandle n;

	ros::Publisher pub_mission_manager_reset = n.advertise<std_msgs::Bool>("/mission_manager_reset", 1);
	ros::Publisher pub_mission_manager_nbr = n.advertise<std_msgs::UInt32>("/mission_manager_nbr", 1);
	ros::Publisher pub_mission_manager_state = n.advertise<std_msgs::UInt32>("/mission_manager_state", 1);
	ros::Publisher pub_to_Mission_Server = n.advertise<project_s_msgs::toMissionServer>("/toMissionServer", 1);
	ros::Publisher pub_circuit_choice = n.advertise<std_msgs::UInt8>(std::string("/circuit_choice"), 1);

	ros::Subscriber sub_circuit_manager = n.subscribe(std::string("/circuit_manager_cmd"), 1, circuitManagerCallback);
	ros::Subscriber sub_end_mission = n.subscribe(std::string("/end_of_mission"), 1, endMissionCallback);
	ros::Subscriber sub_mission_manager_modem = n.subscribe(std::string("/mission_manager_modem"), 1, MissionManagerModemCallback);
	ros::Subscriber sub_from_Mission_Server = n.subscribe(std::string("/fromMissionServer"), 1, fromMissionServerCallback);

	ros::Rate loop_rate(25);

//	mission_manager_status.data = MISSION_STOP;
//	mission_manager_status.data = STARTING_VEHICLE;
toMissionServer.state = project_s_msgs::toMissionServer::UNAVAILABLE;

	bool vehicle_ready = false;
	bool shutdown_request = false;
	bool mission_act = false;

	while(n.ok())
	{
		ros::spinOnce();

		if(electronicHorizonArrayReceived)
		{
			electronicHorizonArrayReceived = false;

			roadModel_EH.header = electronic_Horizon_Array.header;
			roadModel_EH.electronicHorizon = electronic_Horizon_Array.PathsArray[0];
		}
/*
		switch(mission_manager_status.data)
		{
		case MISSION_STOP :
		case MISSION_EIGHT :
		case MISSION_SQUARE :
			if(receivedEndMission)
			{
				receivedEndMission = false;

				mission_manager_status.data = MISSION_STOP;

				mission_manager_nbr.data = MISSION_STOP;
				mission_manager_reset.data = true;

				pub_mission_manager_nbr.publish(mission_manager_status);
				pub_mission_manager_reset.publish(mission_manager_reset);

			}
			else if(receivedCircuitManager)
			{
				receivedCircuitManager = false;

				mission_manager_status.data = circuit_manager.data;

				mission_manager_nbr.data = circuit_manager.data;
				mission_manager_reset.data = true;

				pub_mission_manager_nbr.publish(mission_manager_status);
				pub_mission_manager_reset.publish(mission_manager_reset);

			}
			break;

		default :
			mission_manager_status.data = MISSION_STOP;

			mission_manager_nbr.data = MISSION_STOP;
			mission_manager_reset.data = true;

			pub_mission_manager_nbr.publish(mission_manager_status);
			pub_mission_manager_reset.publish(mission_manager_reset);
			break;
		}
*/
/*		switch(mission_manager_status.data)
		{
		case STARTING_VEHICLE :
			if(vehicle_ready){
				mission_manager_status.data = WAITING_FOR_MISSION;
			}
			break;

		case WAITING_FOR_MISSION :
			if(shutdown_request){
				mission_manager_status.data = SHUTDOWN;
			}

			if(mission_act){
				mission_manager_status.data = NAVIGATION_TO_DESTINATION;
			}
			break;

		case SHUTDOWN :
			break;

		case NAVIGATION_TO_DESTINATION :
			if(!mission_act){
				mission_manager_status.data = WAITING_FOR_MISSION;
			}
			break;

		default :
			mission_manager_status.data = STARTING_VEHICLE;
			break;
		}

		pub_mission_manager_state.publish(mission_manager_status);
*/


		toMissionServer.url = "";	//reset par défaut
		
/*
std::string str;
str = std::to_string(10);
toMissionServer.lat = str;

strcpy(str, fromMissionServer.lat);
double d_buffer;
d_buffer = std::stod(str);
*/


ros::Time current_time = ros::Time::now();
		switch(toMissionServer.state)
		{
		case project_s_msgs::toMissionServer::UNAVAILABLE :
			if(vehicle_ready){
				toMissionServer.state = project_s_msgs::toMissionServer::WAITING;
			}
			break;

		case project_s_msgs::toMissionServer::WAITING :
			// requête de POST
			toMissionServer.url = "http://labcar.digital-segula.fr/post/update?";
			toMissionServer.idCar = ID_CAR;
			//toMissionServer.state = à jour;
			toMissionServer.lat = std::to_string(roadModel_EH.electronicHorizon.ehPosition.latitude);
			toMissionServer.lng = std::to_string(roadModel_EH.electronicHorizon.ehPosition.longitude);

			// requête de GET
			toMissionServer.url = "http://labcar.digital-segula.fr/get/search";

			// parse new JSON answer
			mission_act = false;
			if(!fromMissionServer.err){
				if(fromMissionServer.msg == "A new mission found"){
					if(fromMissionServer.mission != 0){
						mission_act = true;
						circuit_choice.data = fromMissionServer.mission;
						pub_circuit_choice.publish(circuit_choice);
					}
				}
			}

			if(shutdown_request){
				toMissionServer.state = project_s_msgs::toMissionServer::ENDING;
			}

			if(mission_act){
				toMissionServer.state = project_s_msgs::toMissionServer::NAVIGATING;
			}
			break;

		case project_s_msgs::toMissionServer::ENDING :
			// requête de POST
			toMissionServer.url = "http://labcar.digital-segula.fr/post/update?";
			toMissionServer.idCar = ID_CAR;
			//toMissionServer.state = à jour;
			toMissionServer.lat = std::to_string(roadModel_EH.electronicHorizon.ehPosition.latitude);
			toMissionServer.lng = std::to_string(roadModel_EH.electronicHorizon.ehPosition.longitude);

			break;

		case project_s_msgs::toMissionServer::NAVIGATING :
			// requête de POST
			toMissionServer.url = "http://labcar.digital-segula.fr/post/update?";
			toMissionServer.idCar = ID_CAR;
			//toMissionServer.state = à jour;
			toMissionServer.header.stamp = current_time;
			toMissionServer.lat = std::to_string(roadModel_EH.electronicHorizon.ehPosition.latitude);
			toMissionServer.lng = std::to_string(roadModel_EH.electronicHorizon.ehPosition.longitude);

			if(!mission_act){
				toMissionServer.state = project_s_msgs::toMissionServer::WAITING;
			}
			break;

		default :
			toMissionServer.state = project_s_msgs::toMissionServer::UNAVAILABLE;
			break;
		}

		pub_to_Mission_Server.publish(toMissionServer);

		loop_rate.sleep();
	}

	return 0;
}
