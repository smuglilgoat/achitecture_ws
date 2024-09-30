#include <ros/ros.h>

#include "project_s_msgs/VehicleGuidance.h"

#include "project_s_msgs/Actuators.h"
#include "dbw_mkz_msgs/SteeringCmd.h"
#include "dbw_mkz_msgs/GearCmd.h"
#include "dbw_mkz_msgs/ThrottleCmd.h"
#include "dbw_mkz_msgs/BrakeCmd.h"

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::Actuators actuators;

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::VehicleGuidance vehicleGuidance;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool received = false;
void vehicleGuidanceCallback(const project_s_msgs::VehicleGuidance::ConstPtr& buffer)
{
	vehicleGuidance = *buffer;

	received = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "actuators");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher actuators_pub = n.advertise<project_s_msgs::Actuators>("/actuators_data", 1);

	ros::Publisher pub_steering_cmd = n.advertise<dbw_mkz_msgs::SteeringCmd>("/actuators_steering_cmd", 1);
	ros::Publisher pub_gear_cmd     = n.advertise<dbw_mkz_msgs::GearCmd>    ("/actuators_gear_cmd"    , 1);
	ros::Publisher pub_throttle_cmd = n.advertise<dbw_mkz_msgs::ThrottleCmd>("/actuators_throttle_cmd", 1);
	ros::Publisher pub_brake_cmd    = n.advertise<dbw_mkz_msgs::BrakeCmd>   ("/actuators_brake_cmd"   , 1);

	// Subscriber 
	ros::Subscriber vehicleGuidance_sub = n.subscribe(std::string("/vehicle_guidance_data"), 1, vehicleGuidanceCallback);

	ros::Rate r(25);

	ros::Time current_time, last_time;
	last_time = ros::Time::now();
	std_msgs::Float32 steeringAngle_old;
	steeringAngle_old.data = 0;

  	while(n.ok())
	{
		ros::spinOnce();

		current_time  = ros::Time::now();

		if(received)
		{
			received = false;

			actuators.header = vehicleGuidance.header;

			// MàJ de l'OUTPUT data
			// passage directement de vehicleGuidance en attendant un traitement
			if(vehicleGuidance.driveBrakingTorque.data >= 0)
			{
				actuators.Accelerator.data = vehicleGuidance.driveBrakingTorque.data;
				actuators.brakePressure.data = 0;
			}
			else
			{
				actuators.Accelerator.data = 0;
				actuators.brakePressure.data = - vehicleGuidance.driveBrakingTorque.data;
			}

			actuators.steeringAngle.data = vehicleGuidance.steeringWheelAngle.data;

			// lissage de steeringAngle au 1er ordre
			std_msgs::Float32 dt;
			dt.data = (current_time - last_time).toSec();
			last_time = current_time;
			double K = exp(-dt.data/0.1); 

			actuators.steeringAngle.data  = (1.0-K)*actuators.steeringAngle.data;
			actuators.steeringAngle.data +=      K *          steeringAngle_old.data;
			steeringAngle_old.data = actuators.steeringAngle.data;

			//publish the message
			actuators_pub.publish(actuators);

/*			dbw_mkz_msgs::SteeringCmd SteeringCmd;
			SteeringCmd.steering_wheel_angle_cmd = actuators.steeringAngle.data;
			pub_steering_cmd.publish(SteeringCmd);

			dbw_mkz_msgs::GearCmd gearCommand = dbw_mkz_msgs::GearCmd();
			gearCommand.cmd.gear = dbw_mkz_msgs::Gear::DRIVE;
			gearCommand.clear = true;
			pub_gear_cmd.publish(gearCommand);

			dbw_mkz_msgs::ThrottleCmd throttleCommand = dbw_mkz_msgs::ThrottleCmd();
			throttleCommand.pedal_cmd_type = dbw_mkz_msgs::ThrottleCmd::CMD_PERCENT;
			throttleCommand.pedal_cmd = 0.1;
			pub_throttle_cmd.publish(throttleCommand);

			dbw_mkz_msgs::BrakeCmd brakeCommand = dbw_mkz_msgs::BrakeCmd();
			brakeCommand.pedal_cmd_type = dbw_mkz_msgs::BrakeCmd::CMD_TORQUE;
			brakeCommand.pedal_cmd = 100;
			pub_brake_cmd.publish(brakeCommand);
*/
		}

		r.sleep();
	}

	return 0;
}
