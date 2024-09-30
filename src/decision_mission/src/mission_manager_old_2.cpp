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
#include <dbw_mkz_msgs/GearCmd.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>
#include "ros/ros.h"
#include <novatel_gps_msgs/Inspva.h>
//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
std_msgs::UInt32 circuit_manager;
std_msgs::Bool saut_indice;
std_msgs::String fms_debug_msg;
std_msgs::String debug_msg;
std_msgs::Empty empty_msg;
dbw_mkz_msgs::GearCmd gear_cmd;
std_msgs::UInt32 circuit_manager_cmd;
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
#define	CIRCUIT_STOP	0
#define	CIRCUIT_GO		1

#define LOOPRATE		25
#define TOSERVERDELAY	(5*LOOPRATE)
#define ENDING_TO_WAITING_DELAY	(5*LOOPRATE)	// 5 seconds
#define	ID_CAR			1

project_s_msgs::toMissionServer toMissionServer;
std_msgs::UInt8 circuit_choice;
novatel_gps_msgs::Inspva inspva; 
//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------

bool received_inspva = false;
void InspvaDataCallback(const novatel_gps_msgs::Inspva::ConstPtr& buffer)
{
	inspva = *buffer;
	received_inspva = true;
}


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
	
	// Debug messages
	ros::Publisher pub_mission_manager_debug = n.advertise<std_msgs::String>("/mission_manager_debug", 1);


	ros::Publisher pub_mission_manager_reset = n.advertise<std_msgs::Bool>("/mission_manager_reset", 1);
	ros::Publisher pub_mission_manager_nbr = n.advertise<std_msgs::UInt32>("/mission_manager_nbr", 1);
	ros::Publisher pub_mission_manager_state = n.advertise<std_msgs::UInt32>("/mission_manager_state", 1);
	ros::Publisher pub_to_Mission_Server = n.advertise<project_s_msgs::toMissionServer>("/toMissionServer", 1);

	ros::Publisher pub_disable_dbw = n.advertise<std_msgs::Empty>(std::string("/disable"), 1);	
	ros::Publisher pub_enable_dbw = n.advertise<std_msgs::Empty>(std::string("/enable"), 1);
	ros::Publisher pub_gear_cmd = n.advertise<dbw_mkz_msgs::GearCmd>(std::string("/gear_cmd"), 1);	
	ros::Publisher pub_circuit_manager_cmd = n.advertise<std_msgs::UInt32>(std::string("/circuit_manager_cmd"), 1);
	ros::Publisher pub_circuit_choice = n.advertise<std_msgs::UInt8>(std::string("/circuit_choice"), 1);

	ros::Subscriber sub_inspva = n.subscribe(std::string("/inspva"), 1, InspvaDataCallback);

	ros::Subscriber sub_electronic_horizon_array = n.subscribe(std::string("/electronic_horizon_array_data"), 1, electronicHorizonArrayCallback);
	ros::Subscriber sub_circuit_manager = n.subscribe(std::string("/circuit_manager_cmd"), 1, circuitManagerCallback);
	ros::Subscriber sub_end_mission = n.subscribe(std::string("/end_of_mission"), 1, endMissionCallback);
	ros::Subscriber sub_mission_manager_modem = n.subscribe(std::string("/mission_manager_modem"), 1, MissionManagerModemCallback);
	ros::Subscriber sub_from_Mission_Server = n.subscribe(std::string("/fromMissionServer"), 1, fromMissionServerCallback);

	ros::Rate loop_rate(LOOPRATE);

//	mission_manager_status.data = MISSION_STOP;
//	mission_manager_status.data = STARTING_VEHICLE;
	toMissionServer.state = project_s_msgs::toMissionServer::UNAVAILABLE;

	bool modemConnected = false;
//	bool vehicle_ready = false;
	bool vehicle_ready = true;
	bool bGetSearch = false;
	bool shutdown_request = false;
	bool mission_act = false;
	bool pubToMissionServer = false;
	unsigned int loopCnt = 0;
	unsigned int endingToWaitingCnt = 0;


	while(n.ok())
	{
		ros::spinOnce();

/*		// Récupération de la position lat/lng
		if(electronicHorizonArrayReceived)
		{
			electronicHorizonArrayReceived = false;

			roadModel_EH.header = electronic_Horizon_Array.header;
			roadModel_EH.electronicHorizon = electronic_Horizon_Array.PathsArray[0];
		}
*/
		if(received_inspva)
		{
			received_inspva = false;

			toMissionServer.lat = std::to_string(inspva.latitude);
			toMissionServer.lng = std::to_string(inspva.longitude);
			
		}
		
		ros::Time current_time = ros::Time::now();

		fms_debug_msg.data = "";
		if(receivedfromMissionServer) {
			// Calcul de la longeur
			// Partie Header
			int pubHeaderLength = sizeof(fromMissionServer.header.seq)
					    + sizeof(fromMissionServer.header.stamp)
					    + fromMissionServer.header.frame_id.length() + 4;
			int pubDataLength = sizeof(fromMissionServer.mode)
					   + sizeof(fromMissionServer.err)
					   + sizeof(fromMissionServer.mission)
					   + sizeof(fromMissionServer.idUser)
					   + sizeof(fromMissionServer.errCode)
					   + sizeof(fromMissionServer.idCar)
					   + sizeof(fromMissionServer.stateCmd);
			int pubStringLength = fromMissionServer.msg.length() + 4
					     + fromMissionServer.lat.length() + 4
					     + fromMissionServer.lng.length() + 4
					     + fromMissionServer.url.length() + 4
					     + fromMissionServer.data.length() + 4;
			fms_debug_msg.data = "receive(fromMissionServer)[" + std::to_string(fromMissionServer.header.seq)
				+ "] Frame_id='" + fromMissionServer.header.frame_id
				+ "' Header=" + std::to_string(pubHeaderLength)
				+ " Data=" + std::to_string(pubDataLength)
				+ " String=" + std::to_string(pubStringLength)
				+ "-> " + std::to_string(pubHeaderLength + pubDataLength + pubStringLength);
			pub_mission_manager_debug.publish(fms_debug_msg);
		}


		switch(toMissionServer.state)
		{
		case project_s_msgs::toMissionServer::UNAVAILABLE :
			if(receivedfromMissionServer) {
				switch (fromMissionServer.mode) {
					case project_s_msgs::fromMissionServer::ARDUINOMODE:
						if (fromMissionServer.msg.find("DISCONNECTED") != std::string::npos) {
							modemConnected = false;
							debug_msg.data = "State UNAVAILABLE: Arduino Modem DISCONNECTED";
							pub_mission_manager_debug.publish(debug_msg);
						}
						else if(fromMissionServer.msg.find("CONNECTED") != std::string::npos) {
							modemConnected = true;
							debug_msg.data = "State UNAVAILABLE: Arduino Modem CONNECTED";
							pub_mission_manager_debug.publish(debug_msg);
						}
						break;

					default:
						modemConnected = false;
						break;
				}
			}
			if(vehicle_ready){
				if(modemConnected) {
					toMissionServer.state = project_s_msgs::toMissionServer::WAITING;
					loopCnt = 0;
					debug_msg.data = "State UNAVAILABLE: Vehicule Ready, Modem CONNECTED -> goto state WAITING";
					pub_mission_manager_debug.publish(debug_msg);
				}
				else if(!loopCnt) {
					toMissionServer.mode = project_s_msgs::toMissionServer::ARDUINOMODE;
					toMissionServer.idCar = ID_CAR;
					toMissionServer.lat = ""; 
					toMissionServer.lng = "";
					toMissionServer.url = ""; 
					toMissionServer.data = "";
					pubToMissionServer = true;
					loopCnt = TOSERVERDELAY;
					debug_msg.data = "State UNAVAILABLE: Vehicule Ready, Arduino Modem DISCONNECTED -> get modem status";
					pub_mission_manager_debug.publish(debug_msg);
				}
			}
			break;

		case project_s_msgs::toMissionServer::WAITING :
			// Gestion des messages fromMissionServer
			if(receivedfromMissionServer) {
				switch (toMissionServer.mode) {
					case project_s_msgs::toMissionServer::ARDUINOMODE:
						if (fromMissionServer.msg.find("DISCONNECTED") != std::string::npos) {
							modemConnected = false;
							toMissionServer.mode = project_s_msgs::toMissionServer::UNAVAILABLE;
							debug_msg.data = "State WAITING: Arduino Modem DISCONNECTED -> goto state UNAVAILABLE";
							pub_mission_manager_debug.publish(debug_msg);

						}
						else if(fromMissionServer.msg.find("CONNECTED") != std::string::npos) {
							modemConnected = true;
							debug_msg.data = "State WAITING: Arduino Modem CONNECTED";
							pub_mission_manager_debug.publish(debug_msg);
						}
						else {
							modemConnected = false;
							toMissionServer.mode = project_s_msgs::toMissionServer::UNAVAILABLE;
							debug_msg.data = "State WAITING: Arduino Modem ??? -> goto state UNAVAILABLE";
							pub_mission_manager_debug.publish(debug_msg);
						}
						break;

					case project_s_msgs::toMissionServer::BYFIELDMODE:
						if(fromMissionServer.err) {
							mission_act = false;
							debug_msg.data = "State WAITING: Reception BYFIELDMODE error";
							pub_mission_manager_debug.publish(debug_msg);
						}
						else {
							if(fromMissionServer.msg == "A new mission found.") {
								if(fromMissionServer.mission != 0){
									mission_act = true;
									circuit_choice.data = fromMissionServer.mission;
									debug_msg.data = "State WAITING: 'A new mission found.' [" + std::to_string(circuit_choice.data) + "]-> mission_act = true";
									pub_mission_manager_debug.publish(debug_msg);
								}
								else {
									mission_act = false;
									debug_msg.data = "State WAITING: 'A new mission found.' [0]-> mission_act = false";
									pub_mission_manager_debug.publish(debug_msg);
								}
								
							}
							debug_msg.data = "State WAITING: receive NAVIGATING -> Goto NAVIGATING and Start";
							switch (fromMissionServer.stateCmd) {
								case project_s_msgs::fromMissionServer::NAVIGATE:
									debug_msg.data = "State WAITING: receive NAVIGATE -> Goto NAVIGATING and Start";
								case project_s_msgs::fromMissionServer::NAVIGATING:
									if (mission_act) {
										toMissionServer.state = project_s_msgs::toMissionServer::NAVIGATING;
										pub_mission_manager_debug.publish(debug_msg);
										// Sélection du circuit
										pub_circuit_choice.publish(circuit_choice);
										// Active le Drive-by-Wire
										pub_enable_dbw.publish(empty_msg);
										// Sélectionne la vitesse 'Drive'
										gear_cmd.cmd.gear = dbw_mkz_msgs::Gear::DRIVE;
										pub_gear_cmd.publish(gear_cmd);
										// Démarre le mode autonome
										//circuit_manager_cmd.data = CIRCUIT_GO;
  										//pub_circuit_manager_cmd.publish(circuit_manager_cmd);
									}
									break;

								case project_s_msgs::fromMissionServer::UNAVAILABLE:
									debug_msg.data = "State WAITING: receive UNAVAILABLE.";
									pub_mission_manager_debug.publish(debug_msg);
									break;

								case project_s_msgs::fromMissionServer::WAITING:
									debug_msg.data = "State WAITING: receive WAITING.";
									pub_mission_manager_debug.publish(debug_msg);
									break;

								default:
									debug_msg.data = "State WAITING: receive (" + std::to_string(fromMissionServer.stateCmd) + ") -> default";
									pub_mission_manager_debug.publish(debug_msg);
									break;
							}
						}
						break;
					
					case project_s_msgs::toMissionServer::TRANSPARENTMODE:
						debug_msg.data = "State WAITING: TRANSPARENTMODE - Not yet implemented";
						pub_mission_manager_debug.publish(debug_msg);
						// JSON Parsing, tnot yet implemented
						break;
					
					default:
						debug_msg.data = "State WAITING: Default - Not yet implemented -> modemConnected = false";
						pub_mission_manager_debug.publish(debug_msg);
						modemConnected = false;
						break;
				}
				receivedfromMissionServer = false;
				loopCnt = TOSERVERDELAY;
			}

			// Partie Emission du message toMissionServer en état WAITING
			if(!loopCnt) {
				// requête de POST par champs en mode BYFIELD
				toMissionServer.mode = project_s_msgs::toMissionServer::BYFIELDMODE;
/*
				// requête de POST en mode TRANSPARENTMODE
				toMissionServer.mode = project_s_msgs::toMissionServer::TRANSPARENTMODE;
				bGetSearch = (bGetSearch) ? false : true;
				if(bGetSearch) {
					// requête de GET
					toMissionServer.url = "http://labcar.digital-segula.fr/get/search";
				}
				else {
					// Requête de POST
					toMissionServer.url = "http://labcar.digital-segula.fr/post/update?";
				}
*/
				/*toMissionServer.lat = std::to_string(roadModel_EH.electronicHorizon.ehPosition.latitude);
				toMissionServer.lng = std::to_string(roadModel_EH.electronicHorizon.ehPosition.longitude);
				*/

				toMissionServer.lat = std::to_string(inspva.latitude);
				toMissionServer.lng = std::to_string(inspva.longitude);

				toMissionServer.idCar = ID_CAR;
				pubToMissionServer = true;
				loopCnt = TOSERVERDELAY;

				debug_msg.data = "State WAITING: Emission BYFIELDMODE Lat/Lng & idCar " + std::to_string(toMissionServer.idCar) + ": " + toMissionServer.lat + "/" + toMissionServer.lng;
				pub_mission_manager_debug.publish(debug_msg);
			}
			break;

		case project_s_msgs::toMissionServer::NAVIGATING:
			if(receivedfromMissionServer) {
				switch (fromMissionServer.mode) {
					case project_s_msgs::fromMissionServer::ARDUINOMODE:
						if (fromMissionServer.msg.find("DISCONNECTED") != std::string::npos) {
							modemConnected = false;
							debug_msg.data = "State NAVIGATING: Arduino Modem DISCONNECTED -> modemConnected = false";
							pub_mission_manager_debug.publish(debug_msg);
						}
						else if(fromMissionServer.msg.find("CONNECTED") != std::string::npos) {
							modemConnected = true;
							debug_msg.data = "State NAVIGATING: Arduino Modem CONNECTED -> modemConnected = true";
							pub_mission_manager_debug.publish(debug_msg);
						}
						else {
							modemConnected = false;
							debug_msg.data = "State NAVIGATING: Arduino Modem ??? -> modemConnected = false";
							pub_mission_manager_debug.publish(debug_msg);
						}
						break;

					case project_s_msgs::toMissionServer::BYFIELDMODE:
						if(!fromMissionServer.err) {
							debug_msg.data = "";
							switch (fromMissionServer.stateCmd) {
								case project_s_msgs::fromMissionServer::ENDOFNAV:
									debug_msg.data = "State NAVIGATING: Receive ENDOFNAV";
								case project_s_msgs::fromMissionServer::ENDING:
									if (debug_msg.data == "")
										debug_msg.data = "State NAVIGATING: Receive ENDING";
								case project_s_msgs::fromMissionServer::WAITING:
									if (debug_msg.data == "")
										debug_msg.data = "State NAVIGATING: Receive WAITING";
									debug_msg.data += " -> Goto ENDING & Stop";
									pub_mission_manager_debug.publish(debug_msg);
									circuit_manager_cmd.data = CIRCUIT_STOP;
  									pub_circuit_manager_cmd.publish(circuit_manager_cmd);
									toMissionServer.state = project_s_msgs::toMissionServer::ENDING;
									endingToWaitingCnt = ENDING_TO_WAITING_DELAY;
									break;

								default:
									break;
							}
						}

					case project_s_msgs::toMissionServer::TRANSPARENTMODE:
						debug_msg.data = "State NAVIGATING: TRANSPARENTMODE - Not yet implemented";
						pub_mission_manager_debug.publish(debug_msg);
						// JSON Parsing, tnot yet implemented
						break;
					
					default:
						debug_msg.data = "State NAVIGATING: Default - Not yet implemented";
						pub_mission_manager_debug.publish(debug_msg);
						break;
				}
				receivedfromMissionServer = false;
				loopCnt = TOSERVERDELAY;
			}

			// Partie Emission du message toMissionServer en état NAVIGATING
			if(!loopCnt) {
				// requête de POST par champs en mode BYFIELD
				toMissionServer.mode = project_s_msgs::toMissionServer::BYFIELDMODE;
/*
				// requête de POST en mode TRANSPARENTMODE
				toMissionServer.mode = project_s_msgs::toMissionServer::TRANSPARENTMODE;
				toMissionServer.url = "http://labcar.digital-segula.fr/post/update?";
*/
				/*toMissionServer.lat = std::to_string(roadModel_EH.electronicHorizon.ehPosition.latitude);
				toMissionServer.lng = std::to_string(roadModel_EH.electronicHorizon.ehPosition.longitude);
				*/

				toMissionServer.lat = std::to_string(inspva.latitude);
				toMissionServer.lng = std::to_string(inspva.longitude);
				toMissionServer.idCar = ID_CAR;
				pubToMissionServer = true;
				loopCnt = TOSERVERDELAY;
			}

			if(!mission_act){
				toMissionServer.state = project_s_msgs::toMissionServer::WAITING;
				debug_msg.data = "State NAVIGATING: (!mission_act) Emission BYFIELDMODE Lat/Lng & idCar " + std::to_string(toMissionServer.idCar) + ": " + toMissionServer.lat + "/" + toMissionServer.lng;
			}
			else {
				debug_msg.data = "State NAVIGATING: (mission_act) Emission BYFIELDMODE Lat/Lng & idCar " + std::to_string(toMissionServer.idCar) + ": " + toMissionServer.lat + "/" + toMissionServer.lng;
			}
			pub_mission_manager_debug.publish(debug_msg);
			break;

		case project_s_msgs::toMissionServer::ENDING:
			// Gestion des messages fromMissionServer
			if(receivedfromMissionServer) {
				receivedfromMissionServer = false;
				loopCnt = TOSERVERDELAY;
				switch (toMissionServer.mode) {
					case project_s_msgs::toMissionServer::ARDUINOMODE:
						if (fromMissionServer.msg.find("DISCONNECTED") != std::string::npos) {
							modemConnected = false;
							toMissionServer.mode = project_s_msgs::toMissionServer::UNAVAILABLE;
							debug_msg.data = "State ENDING: Arduino Modem DISCONNECTED -> goto state UNAVAILABLE";
							pub_mission_manager_debug.publish(debug_msg);
						}
						else if(fromMissionServer.msg.find("CONNECTED") != std::string::npos) {
							modemConnected = true;
							debug_msg.data = "State ENDING: Arduino Modem CONNECTED -> modemConnected = true";
							pub_mission_manager_debug.publish(debug_msg);
						}
						else {
							modemConnected = false;
							toMissionServer.mode = project_s_msgs::toMissionServer::UNAVAILABLE;
							debug_msg.data = "State ENDING: Arduino Modem ??? -> goto state UNAVAILABLE, modemConnected = false";
							pub_mission_manager_debug.publish(debug_msg);
						}
						break;

					case project_s_msgs::toMissionServer::BYFIELDMODE:
						if(fromMissionServer.err) {
							mission_act = false;
							debug_msg.data = "State ENDING: Receive Error";
						}
						else {
							debug_msg.data = "State ENDING: Receive stateCmd -> no treatment";
							switch (fromMissionServer.stateCmd) {
								default:
									break;
							}
						}
						pub_mission_manager_debug.publish(debug_msg);
						break;

					case project_s_msgs::toMissionServer::TRANSPARENTMODE:
						debug_msg.data = "State ENDING: TRANSPARENTMODE - Not yet implemented";
						pub_mission_manager_debug.publish(debug_msg);
						// JSON Parsing, tnot yet implemented
						break;
					
					default:
						debug_msg.data = "State ENDING: Default - Not yet implemented";
						pub_mission_manager_debug.publish(debug_msg);
						break;
				}
				receivedfromMissionServer = false;
				loopCnt = TOSERVERDELAY;
			}

			// Partie Emission du message toMissionServer en état WAITING
			if(!loopCnt) {
				// requête de POST par champs en mode BYFIELD
				toMissionServer.mode = project_s_msgs::toMissionServer::BYFIELDMODE;
/*
				// requête de POST en mode TRANSPARENTMODE
				toMissionServer.mode = project_s_msgs::toMissionServer::TRANSPARENTMODE;
				bGetSearch = false;
				toMissionServer.url = "http://labcar.digital-segula.fr/post/update?";
				}
*/
				toMissionServer.idCar = ID_CAR;
				/*toMissionServer.lat = std::to_string(roadModel_EH.electronicHorizon.ehPosition.latitude);
				toMissionServer.lng = std::to_string(roadModel_EH.electronicHorizon.ehPosition.longitude);
				*/

				toMissionServer.lat = std::to_string(inspva.latitude);
				toMissionServer.lng = std::to_string(inspva.longitude);

				pubToMissionServer = true;
				loopCnt = TOSERVERDELAY;
				debug_msg.data = "State ENDING: Emission BYFIELDMODE Lat/Lng & idCar " + std::to_string(toMissionServer.idCar) + ": " + toMissionServer.lat + "/" + toMissionServer.lng;
				pub_mission_manager_debug.publish(debug_msg);
			}
			break;

		default :
			toMissionServer.state = project_s_msgs::toMissionServer::UNAVAILABLE;
			modemConnected = false;
			debug_msg.data = "State ENDING: Default -> Goto state UNAVAILABLE & modemConnected = false";
			pub_mission_manager_debug.publish(debug_msg);
			break;
		}

		if(pubToMissionServer) {
			toMissionServer.header.stamp = current_time;
			// Calcul de la longeur
			{
				// Partie Header
				int pubHeaderLength = sizeof(toMissionServer.header.seq)
						    + sizeof(toMissionServer.header.stamp)
						    + toMissionServer.header.frame_id.length() + 4;
				int pubDataLength = sizeof(toMissionServer.idCar)
						   + sizeof(toMissionServer.state)
						   + sizeof(toMissionServer.mode);
				int pubStringLength = toMissionServer.lat.length() + 4
						     + toMissionServer.lng.length() + 4
						     + toMissionServer.url.length() + 4
						     + toMissionServer.data.length() + 4;
				debug_msg.data = "publish(toMissionServer): Frame_id='" + toMissionServer.header.frame_id
					+ "' Header=" + std::to_string(pubHeaderLength)
					+ " Data=" + std::to_string(pubDataLength)
					+ " String=" + std::to_string(pubStringLength)
					+ "-> " + std::to_string(pubHeaderLength + pubDataLength + pubStringLength);
				pub_mission_manager_debug.publish(debug_msg);
			}
			pub_to_Mission_Server.publish(toMissionServer);
			pubToMissionServer = false;
		}

		if(loopCnt) {
			loopCnt--;
		}
		if(endingToWaitingCnt) {
			endingToWaitingCnt--;
		}
		loop_rate.sleep();
	}

	return 0;
}
