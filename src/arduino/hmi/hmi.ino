//#include <iostream.h>

#include <ros.h>
#include <std_msgs/UInt32.h>
#include <std_msgs/UInt8.h>
#include <project_s_msgs/MissionManagerModem.h>
#include <project_s_msgs/toMissionServer.h>
#include <dbw_mkz_msgs/GearCmd.h>
//#include <string>
#include <std_msgs/Empty.h>
#include <tf/tf.h>

ros::NodeHandle  nh;

std_msgs::Empty empty_msg;
ros::Publisher pub_disable_dbw("disable", &empty_msg);
ros::Publisher pub_enable_dbw ("enable" , &empty_msg);
dbw_mkz_msgs::GearCmd gear_cmd;
ros::Publisher pub_gear_cmd("gear_cmd", &gear_cmd);
std_msgs::UInt32 circuit_manager_cmd;
ros::Publisher pub_circuit_manager_cmd("circuit_manager_cmd", &circuit_manager_cmd);
std_msgs::UInt8 circuit_choice;
ros::Publisher pub_circuit_choice("circuit_choice", &circuit_choice);

project_s_msgs::MissionManagerModem mission_manager_cmd;

void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.advertise(pub_circuit_choice);
  nh.advertise(pub_disable_dbw);
  nh.advertise(pub_enable_dbw);
  nh.advertise(pub_gear_cmd);
  nh.advertise(pub_circuit_manager_cmd);
}

void loop() {
  // put your main code here, to run repeatedly:

  // juste pour vérifier l'accès à MissionManagerModem.msg
  mission_manager_cmd.request = 0;

  // juste pour vérifier l'accès à toMissionServer.msg
  project_s_msgs::toMissionServer toMissionServer;
  toMissionServer.lat = "48.00";
//-----
  // gestion du choix de circuit
  int n_circuit = 10;
  //if (nh.hasParam("/n_circuit"))
  //nh.getParam("/n_circuit", &n_circuit);  // ATTENTION getParam() ne récupère que : int | float | *char
                                          //                                        (mais pas de char)
  if(n_circuit != 0){
    circuit_choice.data = n_circuit;
    pub_circuit_choice.publish(&circuit_choice);
  }

//-----
  // gestion de la commande de enable/disable dbw_mkz
  int cmd_dbw = 0;   // false
  //nh.getParam("/cmd_dbw", &cmd_dbw, 1);

  if(cmd_dbw == 0)
    pub_disable_dbw.publish(&empty_msg);
  else
    pub_enable_dbw.publish(&empty_msg);

//-----
  // gestion de la commande de Gear
  int cmd_gear = 0;   // NONE
//  nh.getParam("/cmd_gear", &cmd_gear);

  gear_cmd.cmd.gear = cmd_gear;
  pub_gear_cmd.publish(&gear_cmd);

//-----
  // gestion de la commande GO pour mode autonome
  int cmd_circuit = 0;
//  nh.getParam("/cmd_circuit", &cmd_circuit);

  circuit_manager_cmd.data = cmd_circuit;
  pub_circuit_manager_cmd.publish(&circuit_manager_cmd);

  nh.spinOnce();
  delay(1000);
}
