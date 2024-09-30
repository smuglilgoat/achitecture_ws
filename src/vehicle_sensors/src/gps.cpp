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

#include <dbw_mkz_msgs/SteeringReport.h>
#include <sensor_msgs/Imu.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include "std_msgs/Bool.h"

// Buffers
dbw_mkz_msgs::SteeringReport steering_report = dbw_mkz_msgs::SteeringReport();
sensor_msgs::Imu             IMU_report      = sensor_msgs::Imu();
nav_msgs::Odometry           odom_gps        = nav_msgs::Odometry();
std_msgs::Bool               mission_management;

// Callback functions for receiving topics
bool receivedSteeringReport = false;
void steeringReportCallback(const dbw_mkz_msgs::SteeringReport::ConstPtr& msg)
{
	steering_report = *msg;

	receivedSteeringReport = true;
}

bool receivedIMU = false;
void IMUCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
	IMU_report = *msg;

	receivedIMU = true;
}

bool receivedMissionManagement = false;
void missionManagementCallback(const std_msgs::Bool::ConstPtr& msg)
{
	mission_management = *msg;

	receivedMissionManagement = true;
}

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("GPS"));

	ros::NodeHandle n;

	ros::Publisher pub_odom = n.advertise<nav_msgs::Odometry>("/odom_gps", 1);

	ros::Subscriber sub_steering_report    = n.subscribe(std::string("/steering_report"), 1, steeringReportCallback);
	ros::Subscriber sub_IMU_report         = n.subscribe(std::string("/imu/data_raw"), 1, IMUCallback);
	ros::Subscriber sub_mission_management = n.subscribe(std::string("/mission_manager_reset"), 1, missionManagementCallback);

	ros::Rate loop_rate(100);	

	ros::Time current_time, last_time;
	last_time = ros::Time::now();

	// coordonnées du véhicule + placement initiale
	double x = 0.0;
	double y = 0.0;
	double th = 0.0;

	while(n.ok())
	{
		ros::spinOnce();

		current_time = ros::Time::now();
		double dt = (current_time - last_time).toSec();
		last_time = current_time;

		if (receivedSteeringReport)
		{
			receivedSteeringReport = false;
		}

		if (receivedIMU)
		{
			receivedIMU = false;
		}

		if (receivedMissionManagement)
		{
			receivedMissionManagement = false;
		}

		double delta_x = steering_report.speed * cos(th) * dt;
		double delta_y = steering_report.speed * sin(th) * dt;
		x += delta_x;
		y += delta_y;

		double delta_th = IMU_report.angular_velocity.z * dt;
		th += delta_th;

		if(mission_management.data){
			mission_management.data = false;

			odom_gps.pose.pose.position.x = 0;
			odom_gps.pose.pose.position.y = 0;
			geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(0);
			odom_gps.pose.pose.orientation = odom_quat;
			odom_gps.twist.twist.linear.x = steering_report.speed;
		}
		else{
			odom_gps.pose.pose.position.x = x;
			odom_gps.pose.pose.position.y = y;
			geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);
			odom_gps.pose.pose.orientation = odom_quat;
			odom_gps.twist.twist.linear.x = steering_report.speed;
		}

		pub_odom.publish(odom_gps);

		loop_rate.sleep();		
	}

	return 0;
}
