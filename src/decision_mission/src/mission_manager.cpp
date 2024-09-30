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

//#define SIMULE
//#define	SIMUL_MISSION

#include "std_msgs/UInt8.h"
#include "std_msgs/UInt32.h"
#include "std_msgs/Bool.h"
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>
#include "project_s_msgs/toMissionServer.h"
#include "project_s_msgs/fromMissionServer.h"
#ifndef SIMULE
	#include "project_s_msgs/MissionManagerModem.h"
	#include "project_s_msgs/ElectronicHorizonArray.h"
	#include "project_s_msgs/RoadModel.h"
	#include <dbw_mkz_msgs/GearCmd.h>
	#include <novatel_gps_msgs/Inspva.h>
	#include "project_s_msgs/EgoDataReport.h"
	#include "project_s_msgs/RoutePlanning.h"
#endif
#include "ros/ros.h"

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
std_msgs::UInt32 circuit_manager;
std_msgs::Bool saut_indice;
std_msgs::String fms_debug_msg;
std_msgs::String debug_msg;
project_s_msgs::fromMissionServer fromMissionServer;
#ifndef SIMULE
	project_s_msgs::MissionManagerModem mission_manager_modem;
	project_s_msgs::ElectronicHorizonArray electronic_Horizon_Array;
	project_s_msgs::RoadModel roadModel_EH;
	novatel_gps_msgs::Inspva inspva;
	project_s_msgs::EgoDataReport ego_data_report;
	project_s_msgs::RoutePlanning Route_Planning_data;
#else
	project_s_msgs::point_GPS;
	std_msgs::String gear_cmd_debug;
#endif

//-------------------------------------------------------------------------------------------------
// local define
//-------------------------------------------------------------------------------------------------

/*
#define MISSION_STOP					0
#define MISSION_SQUARE					1
#define MISSION_EIGHT					2
*/
/*
#define STARTING_VEHICLE				0
#define WAITING_FOR_MISSION				1
#define SHUTDOWN						2
#define NAVIGATION_TO_DESTINATION		3
*/
#define	CIRCUIT_STOP					0
#define	CIRCUIT_GO						1

#define LOOPRATE						25		// 1 second
#define TOSERVERDELAY					(5*LOOPRATE)
#define ENDING_TO_WAITING_DELAY_LONG	(30*LOOPRATE)	// 30 seconds
#define ENDING_TO_WAITING_DELAY			(5*LOOPRATE)	// 5 seconds
#define	ID_CAR							1
#define DEBUG_NAVIGATING_TO_END_DELAY	(15*LOOPRATE)	// 15 seconds
#define START_OF_NAVIGATING_TO_GO_DELAY	(10*LOOPRATE)	// 10 seconds

#define DBW_DISABLE						0
#define DBW_ENABLE						1

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
std_msgs::Bool mission_manager_reset;
std_msgs::UInt32 mission_manager_nbr;
//std_msgs::UInt32 mission_manager_status;
project_s_msgs::toMissionServer toMissionServer;

std_msgs::UInt8 circuit_choice;
std_msgs::Empty empty_msg;
int cmd_dbw = DBW_DISABLE;   // false
#ifndef SIMULE
dbw_mkz_msgs::GearCmd gear_cmd;
#endif
std_msgs::UInt32 circuit_manager_cmd;

//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------

ros::Time current_time, last_time;
double dt;
bool pub_enable;

std::string str;

bool bEndOfMission;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------

bool receivedfromMissionServer = false;
void fromMissionServerCallback(const project_s_msgs::fromMissionServer::ConstPtr& msg)
{
	fromMissionServer = *msg;

	receivedfromMissionServer = true;
}

#ifndef SIMULE
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

bool electronicHorizonArrayReceived = false;
void electronicHorizonArrayCallback(const project_s_msgs::ElectronicHorizonArray::ConstPtr& buffer)
{
	electronic_Horizon_Array = *buffer;

	electronicHorizonArrayReceived = true;
}

bool received_inspva = false;
void InspvaDataCallback(const novatel_gps_msgs::Inspva::ConstPtr& buffer)
{
	inspva = *buffer;
	received_inspva = true;
}

bool receivedEgoDataReport = false;
void egoDataCallback(const project_s_msgs::EgoDataReport::ConstPtr& buffer)
{
	ego_data_report = *buffer;

	receivedEgoDataReport = true;
}

bool receivedRoutePlanning = false;
void routePlanningCallback(const project_s_msgs::RoutePlanning::ConstPtr& msg)
{
	Route_Planning_data = *msg;

	receivedRoutePlanning = true;
}
#endif

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("circuit_manager"));

	ros::NodeHandle n;
	
	// Debug messages
	ros::Publisher pub_mission_manager_debug = n.advertise<std_msgs::String>("/mission_manager_debug", 1);

	// Publisher
	ros::Publisher pub_mission_manager_reset = n.advertise<std_msgs::Bool>("/mission_manager_reset", 1);
	ros::Publisher pub_mission_manager_nbr = n.advertise<std_msgs::UInt32>("/mission_manager_nbr", 1);
	ros::Publisher pub_mission_manager_state = n.advertise<std_msgs::UInt32>("/mission_manager_state", 1);
	ros::Publisher pub_to_Mission_Server = n.advertise<project_s_msgs::toMissionServer>("/toMissionServer", 1);

	ros::Publisher pub_disable_dbw = n.advertise<std_msgs::Empty>(std::string("/disable"), 1);	
	ros::Publisher pub_enable_dbw = n.advertise<std_msgs::Empty>(std::string("/enable"), 1);
#ifndef SIMULE
	ros::Publisher pub_gear_cmd = n.advertise<dbw_mkz_msgs::GearCmd>(std::string("/gear_cmd"), 1);
#else
	ros::Publisher pub_gear_cmd_debug = n.advertise<std_msgs::String>("/gear_cmd_debug", 1);
#endif
	ros::Publisher pub_circuit_manager_cmd = n.advertise<std_msgs::UInt32>(std::string("/circuit_manager_cmd"), 1);
	ros::Publisher pub_circuit_choice = n.advertise<std_msgs::UInt8>(std::string("/circuit_choice"), 1);

	// Subscriber

#ifndef SIMULE
	ros::Subscriber sub_electronic_horizon_array = n.subscribe(std::string("/electronic_horizon_array_data"), 1, electronicHorizonArrayCallback);
	ros::Subscriber sub_circuit_manager = n.subscribe(std::string("/circuit_manager_cmd"), 1, circuitManagerCallback);
	ros::Subscriber sub_end_mission = n.subscribe(std::string("/end_of_mission"), 1, endMissionCallback);
	ros::Subscriber sub_mission_manager_modem = n.subscribe(std::string("/mission_manager_modem"), 1, MissionManagerModemCallback);
	ros::Subscriber sub_inspva = n.subscribe(std::string("/inspva"), 1, InspvaDataCallback);
	ros::Subscriber subEgoData = n.subscribe(std::string("/ego_data"), 1, egoDataCallback);
	ros::Subscriber subRoutePlanning = n.subscribe(std::string("/route_planning_data"), 1, routePlanningCallback);
#endif
	ros::Subscriber sub_from_Mission_Server = n.subscribe(std::string("/fromMissionServer"), 1, fromMissionServerCallback);

	ros::Rate loop_rate(LOOPRATE);

#ifndef SIMULE
//	mission_manager_status.data = MISSION_STOP;
//	mission_manager_status.data = STARTING_VEHICLE;
#endif
	toMissionServer.state = project_s_msgs::toMissionServer::UNAVAILABLE;

	bool modemConnected = false;
#ifndef SIMULE
	bool vehicle_ready = true;
#else
	bool vehicle_ready = true;
#endif
	bool bGetSearch = false;
	bool shutdown_request = false;
	bool mission_act = false;
	bool pubToMissionServer = false;
	unsigned int loopCnt = 0;
	unsigned int endingToWaitingCnt = 0;
	unsigned int StartOfNavigatingToGoCnt = 0;			// Delay from start of NAVIGATING to GO sending
	unsigned int NavigatingToEndMissionCnt = 0;
	float pos_offset = 0.0;
	float delta_offset = 0.0;
	float abs_offset = 0.0;
	float vitesse_effective = 0.0;
	
	last_time = ros::Time::now();
	pub_enable = true;

	while(n.ok())
	{
		ros::spinOnce();
		//debug_msg.data = "spinOnce()";
		//pub_mission_manager_debug.publish(debug_msg);
		
		// Récupération de la position lat/lng
#ifndef SIMULE
		if(electronicHorizonArrayReceived)
		{
			debug_msg.data = "electronicHorizonArrayReceived";
			pub_mission_manager_debug.publish(debug_msg);
			electronicHorizonArrayReceived = false;

			roadModel_EH.header = electronic_Horizon_Array.header;
			roadModel_EH.electronicHorizon = electronic_Horizon_Array.PathsArray[0];
		}		
		if(received_inspva)
		{
		//	debug_msg.data = "received_inspva";
		//	pub_mission_manager_debug.publish(debug_msg);
			received_inspva = false;

			toMissionServer.lat = std::to_string(inspva.latitude);
			toMissionServer.lng = std::to_string(inspva.longitude);
			
		}
		if(receivedRoutePlanning)
		{
			debug_msg.data = "receivedRoutePlanning";
			pub_mission_manager_debug.publish(debug_msg);
			receivedRoutePlanning = false;
		}

#endif
		ros::Time current_time = ros::Time::now();

		fms_debug_msg.data = "";
		debug_msg.data = "";
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
			fms_debug_msg.data += "receive(fromMissionServer)[" + std::to_string(fromMissionServer.header.seq)
				+ "] Frame_id='" + fromMissionServer.header.frame_id
				+ "' Header=" + std::to_string(pubHeaderLength)
				+ " Data=" + std::to_string(pubDataLength)
				+ " String=" + std::to_string(pubStringLength)
				+ "-> " + std::to_string(pubHeaderLength + pubDataLength + pubStringLength)
				+ "\n";
				
			debug_msg.data += "RcvMsg: State_" + std::to_string(toMissionServer.state)
				+ "mode_" + std::to_string(fromMissionServer.mode)
				+ "\n";
			//pub_mission_manager_debug.publish(fms_debug_msg);
/*			switch (fromMissionServer.mode) {
			case project_s_msgs::fromMissionServer::BYFIELDMODE:
			case project_s_msgs::fromMissionServer::TRANSPARENTMODE:
				pubToMissionServer = true;
				break;
			default:
				pubToMissionServer = pubToMissionServer;
				break;
			}
*/
		}

		//debug_msg.data = "";
		switch(toMissionServer.state)
		{
		case project_s_msgs::toMissionServer::UNAVAILABLE :
			// màj des data topics
			circuit_choice.data = 0;
			cmd_dbw = DBW_DISABLE;   // false
			gear_cmd.cmd.gear = dbw_mkz_msgs::Gear::NEUTRAL;
			circuit_manager_cmd.data = CIRCUIT_STOP;

			// Check if Arduino is connected
			if(receivedfromMissionServer) {
				switch (fromMissionServer.mode) {
					case project_s_msgs::fromMissionServer::ARDUINOMODE:
						if (fromMissionServer.msg.find("DISCONNECTED") != std::string::npos) {
							modemConnected = false;
							debug_msg.data += "State UNAVAILABLE: Arduino Modem DISCONNECTED\n";
							//pub_mission_manager_debug.publish(debug_msg);
						}
						else if(fromMissionServer.msg.find("CONNECTED") != std::string::npos) {
							modemConnected = true;
							debug_msg.data += "State UNAVAILABLE: Arduino Modem CONNECTED\n";
							//pub_mission_manager_debug.publish(debug_msg);
						}
						else {
							modemConnected = false; 
						}
						break;

					default:
						//modemConnected = false; 
						break;
				}
			}
			
			// Main treatment
			if(vehicle_ready){
				if(modemConnected) {
					toMissionServer.state = project_s_msgs::toMissionServer::WAITING;
					//pubToMissionServer = true;
					loopCnt = 0;
					debug_msg.data = "State UNAVAILABLE: Vehicule Ready, Modem CONNECTED -> goto state WAITING\n";
					pubToMissionServer = true;
					//pub_mission_manager_debug.publish(debug_msg);
				}
				else if(!loopCnt) {
					toMissionServer.mode = project_s_msgs::toMissionServer::ARDUINOMODE;
					toMissionServer.idCar = ID_CAR;
					str = std::to_string(ego_data_report.EgoData[0].latitude);
//str = std::to_string(48.0);
					toMissionServer.lat = str;
					str = std::to_string(ego_data_report.EgoData[0].longitude);
//str = std::to_string(5.0);
					toMissionServer.lng = str;
					toMissionServer.url = ""; 
					toMissionServer.data = "";
					//pubToMissionServer = true;
					loopCnt = TOSERVERDELAY;
					debug_msg.data += "State UNAVAILABLE: Vehicule Ready, Arduino Modem DISCONNECTED -> get modem status\n";
					//pub_mission_manager_debug.publish(debug_msg);
				}
			}
			break;

		case project_s_msgs::toMissionServer::WAITING :
		/*   ======================================== */
			// màj des data topics
			//circuit_choice.data = màj par la suite
			cmd_dbw = DBW_DISABLE;   // false
			gear_cmd.cmd.gear = dbw_mkz_msgs::Gear::NEUTRAL;
			circuit_manager_cmd.data = CIRCUIT_STOP;

			// Gestion des messages fromMissionServer
			if(receivedfromMissionServer) {
				switch (toMissionServer.mode) {
					case project_s_msgs::toMissionServer::ARDUINOMODE:
						debug_msg.data += "[ARDUINOMODE] ";
						if (fromMissionServer.msg.find("DISCONNECTED") != std::string::npos) {
							modemConnected = false;
							toMissionServer.mode = project_s_msgs::toMissionServer::UNAVAILABLE;
							debug_msg.data += "State WAITING: Arduino Modem DISCONNECTED -> goto state UNAVAILABLE\n";
							//pub_mission_manager_debug.publish(debug_msg);

						}
						else if(fromMissionServer.msg.find("CONNECTED") != std::string::npos) {
							modemConnected = true;
							debug_msg.data += "State WAITING: Arduino Modem CONNECTED\n";
							//pub_mission_manager_debug.publish(debug_msg);
						}
						else {
							//modemConnected = false;
							//toMissionServer.mode = project_s_msgs::toMissionServer::UNAVAILABLE;
							//debug_msg.data += "State WAITING: Arduino Modem ??? -> goto state UNAVAILABLE\n";
							//pub_mission_manager_debug.publish(debug_msg);
						}
						break;

					case project_s_msgs::toMissionServer::BYFIELDMODE:
						debug_msg.data += "[BYFIELDMODE] ";
						if(fromMissionServer.err) {
							mission_act = false;
							debug_msg.data += "State WAITING: Reception BYFIELDMODE error\n";
							//pub_mission_manager_debug.publish(debug_msg);
						}
						else {
							if(fromMissionServer.msg == "A new mission found.") {
								if(fromMissionServer.mission != 0){
									mission_act = true;
									circuit_choice.data = fromMissionServer.mission;
									debug_msg.data += "State WAITING: 'A new mission found.' [" + std::to_string(circuit_choice.data) + "]-> mission_act = true\n";
									//pub_mission_manager_debug.publish(debug_msg);
								}
								else {
									mission_act = false;
									debug_msg.data = "State WAITING: 'A new mission found.' [0]-> mission_act = false\\n";
									//pub_mission_manager_debug.publish(debug_msg);
								}
								
							}
							else {
								debug_msg.data = "State WAITING: receive msg 'No mission found.\\n";
							}

							switch (fromMissionServer.stateCmd) {
								case project_s_msgs::fromMissionServer::NAVIGATE:
								case project_s_msgs::fromMissionServer::NAVIGATING:
									if (fromMissionServer.stateCmd == project_s_msgs::fromMissionServer::NAVIGATE)
										debug_msg.data += "State WAITING: receive NAVIGATE -> Goto NAVIGATING and Start\\n";
									else
										debug_msg.data += "State WAITING: receive NAVIGATING -> Goto NAVIGATING and Start\\n";
	
									if (mission_act) {
										toMissionServer.state = project_s_msgs::toMissionServer::NAVIGATING;
										bEndOfMission = false;
#ifndef SIMUL_MISSION
										StartOfNavigatingToGoCnt = START_OF_NAVIGATING_TO_GO_DELAY;
#else
										StartOfNavigatingToGoCnt = 0;
#endif										
										//pub_mission_manager_debug.publish(debug_msg);

										// forcer l'envoi topics sans attendre la tempo 1s
										pub_enable = true;
										// Sélection du circuit
										//circuit_choice.data = xxx	déjà fait
										// Active le Drive-by-Wire
										cmd_dbw = DBW_ENABLE;
										// Sélectionne la vitesse 'Drive'
#ifndef SIMULE
										gear_cmd.cmd.gear = dbw_mkz_msgs::Gear::DRIVE;
#endif
										debug_msg.data += "gear_cmd.cmd.gear = dbw_mkz_msgs::Gear::DRIVE\n";
										//pub_mission_manager_debug.publish(debug_msg);										

										// Démarre le mode autonome
#ifndef SIMULE
										circuit_manager_cmd.data = CIRCUIT_STOP;
#ifndef SIMUL_MISSION
										debug_msg.data += "circuit_manager_cmd.data = CIRCUIT_GO (after delay)\n";
#else
										NavigatingToEndMissionCnt = DEBUG_NAVIGATING_TO_END_DELAY;
										debug_msg.data += "circuit_manager_cmd.data = CIRCUIT_GO (simul)\n";
#endif
#endif
										//pub_mission_manager_debug.publish(debug_msg);										
									}
									break;

								case project_s_msgs::fromMissionServer::UNAVAILABLE:
									debug_msg.data += "State WAITING: receive UNAVAILABLE\n";
									//pub_mission_manager_debug.publish(debug_msg);
									break;

								case project_s_msgs::fromMissionServer::WAITING:
									debug_msg.data += "State WAITING: receive WAITING\n";
									//pub_mission_manager_debug.publish(debug_msg);
									break;

								default:
									debug_msg.data += "State WAITING: receive (" + std::to_string(fromMissionServer.stateCmd) + ") -> default\n";
									//pub_mission_manager_debug.publish(debug_msg);
									break;
							}
						}
						pubToMissionServer = true;
						break;
					
					case project_s_msgs::toMissionServer::TRANSPARENTMODE:
						debug_msg.data += "State WAITING: TRANSPARENTMODE - Not yet implemented\n";
						pubToMissionServer = true;
						//pub_mission_manager_debug.publish(debug_msg);
						// JSON Parsing, tnot yet implemented
						break;
					
					default:
						debug_msg.data += "State WAITING: Default - Not yet implemented -> modemConnected = false\n";
						pubToMissionServer = true;
						//pub_mission_manager_debug.publish(debug_msg);
						modemConnected = false;
						break;
				}
				receivedfromMissionServer = false;
				loopCnt = TOSERVERDELAY;
			}	// End of if(receivedfromMissionServer)

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
#ifndef SIMULE
				toMissionServer.lat = std::to_string(inspva.latitude);
				toMissionServer.lng = std::to_string(inspva.longitude);
#else
				toMissionServer.lat = std::to_string(inspva.latitude);
				toMissionServer.lng = std::to_string(inspva.longitude);
#endif
				toMissionServer.idCar = ID_CAR;
				//pubToMissionServer = true;
				loopCnt = TOSERVERDELAY;

				debug_msg.data += "State WAITING: Emission BYFIELDMODE Lat/Lng & idCar " + std::to_string(toMissionServer.idCar) + ": " + toMissionServer.lat + "/" + toMissionServer.lng + "\n";
				//pub_mission_manager_debug.publish(debug_msg);
			}	// End of WAITING
			break;

		case project_s_msgs::toMissionServer::NAVIGATING:
			// test de fin de mission
			
			vitesse_effective = sqrt(pow(ego_data_report.EgoData[0].velocity.linear.x,2)
						+ pow(ego_data_report.EgoData[0].velocity.linear.y,2));

			pos_offset = roadModel_EH.electronicHorizon.ehPosition.offset.data;
			if(Route_Planning_data.NBRE_POINT_TABLEAU_GPS > 0) {
				delta_offset = pos_offset - Route_Planning_data.Tableau_circuit_GPS[Route_Planning_data.NBRE_POINT_TABLEAU_GPS-1].offset;
				bEndOfMission = false;
				abs_offset = fabs(delta_offset);
				if((abs_offset < 5.0) && (vitesse_effective < 0.1))
					bEndOfMission = true;
			}
			else {
				delta_offset = 0.0;
				abs_offset = 0.0;
				bEndOfMission = false;
			}


			// FIN

			// màj des data topics
			//circuit_choice.data = déjà màj
			cmd_dbw = DBW_ENABLE;   // true
			gear_cmd.cmd.gear = dbw_mkz_msgs::Gear::DRIVE;
#ifndef SIMUL_MISSION
			// Send GO when StartOfNavigatingToGoCnt reach 0
			circuit_manager_cmd.data = (StartOfNavigatingToGoCnt) ? CIRCUIT_STOP : CIRCUIT_GO;
#else
			circuit_manager_cmd.data = CIRCUIT_STOP;	// Simul mission
#endif
			if(receivedfromMissionServer) {
				switch (fromMissionServer.mode) {
					case project_s_msgs::fromMissionServer::ARDUINOMODE:
						if (fromMissionServer.msg.find("DISCONNECTED") != std::string::npos) {
							modemConnected = false;
							debug_msg.data += "State NAVIGATING: Arduino Modem DISCONNECTED -> modemConnected = false\n";
							//pub_mission_manager_debug.publish(debug_msg);
						}
						else if(fromMissionServer.msg.find("CONNECTED") != std::string::npos) {
							modemConnected = true;
							debug_msg.data += "State NAVIGATING: Arduino Modem CONNECTED -> modemConnected = true\n";
							pubToMissionServer = true;
							//pub_mission_manager_debug.publish(debug_msg);
						}
						else {
							modemConnected = false;
							debug_msg.data += "State NAVIGATING: Arduino Modem ??? -> modemConnected = false\n";
							//pub_mission_manager_debug.publish(debug_msg);
						}
						break;

					case project_s_msgs::toMissionServer::BYFIELDMODE:
						if(!fromMissionServer.err) {
							//debug_msg.data = "";
							bool bEnd = false;
							switch (fromMissionServer.stateCmd) {
								case project_s_msgs::fromMissionServer::ENDOFNAV:
									debug_msg.data += "State NAVIGATING: Receive ENDOFNAV";
									bEnd = true;
								case project_s_msgs::fromMissionServer::ENDING:
									if (!bEnd)
										debug_msg.data += "State NAVIGATING: Receive ENDING";
									bEnd = true;
								case project_s_msgs::fromMissionServer::WAITING:
									if (!bEnd)
										debug_msg.data += "State NAVIGATING: Receive WAITING";
									bEnd = true;
									debug_msg.data += " -> Goto ENDING & Stop\n";
									//pub_mission_manager_debug.publish(debug_msg);

									// forcer l'envoi topics sans attendre la tempo 1s
									pub_enable = true;
#ifndef SIMULE
									circuit_manager_cmd.data = CIRCUIT_STOP;
#endif
									if(bEndOfMission) {
										debug_msg.data = "circuit_manager_cmd.data = CIRCUIT_STOP (End Of Mission)\n";
									}
									else {
										debug_msg.data = "circuit_manager_cmd.data = CIRCUIT_STOP (During Mission)\n";
									}

									//pub_mission_manager_debug.publish(debug_msg);										

									toMissionServer.state = project_s_msgs::toMissionServer::ENDING;
									endingToWaitingCnt = (bEndOfMission) ?
										ENDING_TO_WAITING_DELAY :
										ENDING_TO_WAITING_DELAY_LONG;

									break;

								default:
									break;
							}
						}
						pubToMissionServer = true;
						break;

					case project_s_msgs::toMissionServer::TRANSPARENTMODE:
						debug_msg.data += "State NAVIGATING: TRANSPARENTMODE - Not yet implemented\n";
						pubToMissionServer = true;
						//pub_mission_manager_debug.publish(debug_msg);
						// JSON Parsing, tnot yet implemented
						break;
					
					default:
						debug_msg.data += "State NAVIGATING: Default - Not yet implemented\n";
						pubToMissionServer = true;
						//pub_mission_manager_debug.publish(debug_msg);
						break;
				}
				receivedfromMissionServer = false;
				loopCnt = TOSERVERDELAY;
			}	// End of if(receivedfromMissionServer)
#ifdef SIMUL_MISSION
			else if(!NavigatingToEndMissionCnt)
			{
				bEndOfMission = true;
				debug_msg.data += "State NAVIGATING: End Of Mission (simul)";
				debug_msg.data += " -> Goto ENDING & Stop\n";
				//pub_mission_manager_debug.publish(debug_msg);

				// forcer l'envoi topics sans attendre la tempo 1s
				pub_enable = true;
#ifndef SIMULE
				circuit_manager_cmd.data = CIRCUIT_STOP;
#endif
				if(bEndOfMission) {
					debug_msg.data += "circuit_manager_cmd.data = CIRCUIT_STOP (End Of Mission)\n";
				}
				else {
					debug_msg.data += "circuit_manager_cmd.data = CIRCUIT_STOP (During Mission)\n";
				}

				//pub_mission_manager_debug.publish(debug_msg);										

				toMissionServer.state = project_s_msgs::toMissionServer::ENDING;
				endingToWaitingCnt = (bEndOfMission) ?
					ENDING_TO_WAITING_DELAY :
					ENDING_TO_WAITING_DELAY_LONG;
			}
#endif
			else {
				if (bEndOfMission) {
					toMissionServer.state = project_s_msgs::toMissionServer::ENDING;
					endingToWaitingCnt = ENDING_TO_WAITING_DELAY;
					debug_msg.data += "NAVIGATING: EndOfMission -> ENDING\n";
				}
				else {
				//	debug_msg.data += "NAVIGATING: loop..\n";
				}
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
				//pubToMissionServer = true;
				loopCnt = TOSERVERDELAY;
			}

			if(!mission_act){
				toMissionServer.state = project_s_msgs::toMissionServer::WAITING;
				debug_msg.data += "State NAVIGATING: (!mission_act) Emission BYFIELDMODE Lat/Lng & idCar " + std::to_string(toMissionServer.idCar) + ": " + toMissionServer.lat + "/" + toMissionServer.lng + " -> goto WAITING\n";
			}
			else {
				debug_msg.data += "State NAVIGATING: (" + std::to_string(fromMissionServer.mission)
					+ ") Emission(" + std::to_string(toMissionServer.header.seq)
					+ ") BYFIELDMODE Lat/Lng & idCar " + std::to_string(toMissionServer.idCar)
					+ ": " + toMissionServer.lat + "/" + toMissionServer.lng
					+ " pda_offset=" + std::to_string(pos_offset) + "|" + std::to_string(delta_offset) + "|" + std::to_string(abs_offset)
					+ " vit=" + std::to_string(vitesse_effective)
					+ "EoM=" +  ((bEndOfMission) ? "1" : "0") + "\n";
			}
			//pub_mission_manager_debug.publish(debug_msg);
			break;

		case project_s_msgs::toMissionServer::ENDING:
			// màj des data topics
			//circuit_choice.data = déjà màj
			cmd_dbw = DBW_ENABLE;   // true
			//gear_cmd.cmd.gear = dbw_mkz_msgs::Gear::NEUTRAL;
			//circuit_manager_cmd.data = CIRCUIT_STOP;

			// Gestion des messages fromMissionServer
			if(receivedfromMissionServer) {
				receivedfromMissionServer = false;
				loopCnt = TOSERVERDELAY;
				switch (toMissionServer.mode) {
					case project_s_msgs::toMissionServer::ARDUINOMODE:
						if (fromMissionServer.msg.find("DISCONNECTED") != std::string::npos) {
							modemConnected = false;
							toMissionServer.mode = project_s_msgs::toMissionServer::UNAVAILABLE;
							debug_msg.data += "State ENDING: Arduino Modem DISCONNECTED -> goto state UNAVAILABLE\n";
							//pub_mission_manager_debug.publish(debug_msg);
						}
						else if(fromMissionServer.msg.find("CONNECTED") != std::string::npos) {
							modemConnected = true;
							debug_msg.data += "State ENDING: Arduino Modem CONNECTED -> modemConnected = true\n";
							//pub_mission_manager_debug.publish(debug_msg);
						}
						else {
							modemConnected = false;
							toMissionServer.mode = project_s_msgs::toMissionServer::UNAVAILABLE;
							debug_msg.data += "State ENDING: Arduino Modem ??? -> goto state UNAVAILABLE, modemConnected = false\n";
							//pub_mission_manager_debug.publish(debug_msg);
						}
						break;

					case project_s_msgs::toMissionServer::BYFIELDMODE:
						if(fromMissionServer.err) {
							mission_act = false;
							debug_msg.data += "State ENDING: Receive Error\n";
						}
						else {
							debug_msg.data += "State ENDING: Receive stateCmd -> no treatment\n";
							switch (fromMissionServer.stateCmd) {
								default:
									break;
							}
						}
						pubToMissionServer = true;
						//pub_mission_manager_debug.publish(debug_msg);
						break;

					case project_s_msgs::toMissionServer::TRANSPARENTMODE:
						debug_msg.data += "State ENDING: TRANSPARENTMODE - Not yet implemented\n";
						pubToMissionServer = true;
						//pub_mission_manager_debug.publish(debug_msg);
						// JSON Parsing, tnot yet implemented
						break;
					
					default:
						debug_msg.data += "State ENDING: Default - Not yet implemented\n";
						pubToMissionServer = true;
						//pub_mission_manager_debug.publish(debug_msg);
						break;
				}	// End of switch (toMissionServer.mode)
				receivedfromMissionServer = false;
				loopCnt = TOSERVERDELAY;
			}	// End of if(receivedfromMissionServer)

			if (!endingToWaitingCnt) {
				// End of Ending-to-Waiting timeout
				toMissionServer.state = project_s_msgs::toMissionServer::WAITING;
				circuit_choice.data = 0;
				cmd_dbw = DBW_DISABLE;
				gear_cmd.cmd.gear = dbw_mkz_msgs::Gear::NEUTRAL;
				circuit_manager_cmd.data = CIRCUIT_STOP;
				pub_enable = true;
			}
			else {
			//	debug_msg.data += "ENDING: loop..\n";
			}

			// Partie Emission du message toMissionServer en état ENDING
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

				//pubToMissionServer = true;
				loopCnt = TOSERVERDELAY;
				debug_msg.data += "State ENDING: Emission BYFIELDMODE Lat/Lng & idCar " + std::to_string(toMissionServer.idCar) + ": " + toMissionServer.lat + "/" + toMissionServer.lng + "\n";
				//pub_mission_manager_debug.publish(debug_msg);
			}
			break;

		default :
			toMissionServer.state = project_s_msgs::toMissionServer::UNAVAILABLE;
			modemConnected = false;
			debug_msg.data += "State ENDING: Default -> Goto state UNAVAILABLE & modemConnected = false\n";
			//pub_mission_manager_debug.publish(debug_msg);
			break;
		}	// End of switch(toMissionServer.state)

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
				debug_msg.data += "publish(toMissionServer): Frame_id='" + toMissionServer.header.frame_id
					+ "' Header=" + std::to_string(pubHeaderLength)
					+ " Data=" + std::to_string(pubDataLength)
					+ " String=" + std::to_string(pubStringLength)
					+ "-> " + std::to_string(pubHeaderLength + pubDataLength + pubStringLength);
				//pub_mission_manager_debug.publish(debug_msg);
			}
			pub_to_Mission_Server.publish(toMissionServer);
			pubToMissionServer = false;
		}

		if(loopCnt) {
			loopCnt--;
		}
		if(endingToWaitingCnt) {
			if(bEndOfMission) {
				endingToWaitingCnt--;
			}
		}
		if(StartOfNavigatingToGoCnt)
			StartOfNavigatingToGoCnt--;
			
#ifdef SIMUL_MISSION
		if(NavigatingToEndMissionCnt) {
			NavigatingToEndMissionCnt--;
		}
#endif

		if(debug_msg.data != "")
			pub_mission_manager_debug.publish(debug_msg); // debug topic publish
		loop_rate.sleep();

		// gestion de l'envoi périodique des topics
		current_time = ros::Time::now();
		if((dt = (current_time - last_time).toSec()) >= 1.0)
			pub_enable = true;

		if(pub_enable){
			pub_enable = false;
			last_time = current_time;

			// envoi des topics
			debug_msg.data += "topic publish";
			if(circuit_choice.data != 0) {
				debug_msg.data += " pub_circuit_choice\n";
				pub_circuit_choice.publish(circuit_choice);
			}
			if(cmd_dbw == DBW_DISABLE) {
				debug_msg.data += " pub_disable_dbw\n";
				pub_disable_dbw.publish(empty_msg);
			}
			else {
				debug_msg.data += " pub_enable_dbw\n";
				pub_enable_dbw.publish(empty_msg);
			}
			debug_msg.data += " pub_gear_cmd";
			pub_gear_cmd.publish(gear_cmd);
			debug_msg.data += "|pub_circuit_manager_cmd\n";
			pub_circuit_manager_cmd.publish(circuit_manager_cmd);
		}	// End of if(pub_enable)

	}	// End of while(n.ok())

	return 0;
}
