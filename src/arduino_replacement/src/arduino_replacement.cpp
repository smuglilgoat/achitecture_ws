#include "ros/ros.h"

#include <std_msgs/UInt32.h>
#include <std_msgs/UInt8.h>
#include <project_s_msgs/MissionManagerModem.h>
#include <dbw_mkz_msgs/GearCmd.h>
#include <std_msgs/Empty.h>

std_msgs::Empty empty_msg;
dbw_mkz_msgs::GearCmd gear_cmd;
std_msgs::UInt32 circuit_manager_cmd;
std_msgs::UInt8 circuit_choice;

int cmd_dbw_previous = -1;

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("arduino_replacement"));

	ros::NodeHandle n;

	// Raport publisher with relative positions for the objects
	ros::Publisher pub_disable_dbw = n.advertise<std_msgs::Empty>(std::string("/disable"), 1);	
	ros::Publisher pub_enable_dbw = n.advertise<std_msgs::Empty>(std::string("/enable"), 1);
	ros::Publisher pub_gear_cmd = n.advertise<dbw_mkz_msgs::GearCmd>(std::string("/gear_cmd"), 1);	
	ros::Publisher pub_circuit_manager_cmd = n.advertise<std_msgs::UInt32>(std::string("/circuit_manager_cmd"), 1);
	ros::Publisher pub_circuit_choice = n.advertise<std_msgs::UInt8>(std::string("/circuit_choice"), 1);

	ros::Rate loop_rate(1);

	while(n.ok())
	{
		ros::spinOnce();

//-----
  // gestion du choix de circuit
  int n_circuit = 0;
  if (n.hasParam("/n_circuit"))
    n.getParam("/n_circuit", n_circuit);

  if(n_circuit != 0){
    circuit_choice.data = n_circuit;
    pub_circuit_choice.publish(circuit_choice);
  }

//-----
  // gestion de la commande de enable/disable dbw_mkz
  int cmd_dbw = 0;   // false
  if (n.hasParam("/cmd_dbw"))
    n.getParam("/cmd_dbw", cmd_dbw);

  if(cmd_dbw != cmd_dbw_previous){
    if(cmd_dbw == 0)
      pub_disable_dbw.publish(empty_msg);
    else
      pub_enable_dbw.publish(empty_msg);
  }

  cmd_dbw_previous = cmd_dbw;

//-----
  // gestion de la commande de Gear
  int cmd_gear = 0;   // NONE
  if (n.hasParam("/cmd_gear"))
    n.getParam("/cmd_gear", cmd_gear);

  gear_cmd.cmd.gear = cmd_gear;
  pub_gear_cmd.publish(gear_cmd);

//-----
  // gestion de la commande GO pour mode autonome
  int cmd_circuit = 0;
  if (n.hasParam("/cmd_circuit"))
    n.getParam("/cmd_circuit", cmd_circuit);

  circuit_manager_cmd.data = cmd_circuit;
  pub_circuit_manager_cmd.publish(circuit_manager_cmd);

		loop_rate.sleep();		
	}

	return 0;
}
