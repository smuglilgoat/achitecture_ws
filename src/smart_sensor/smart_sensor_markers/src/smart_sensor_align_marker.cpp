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
#include <std_msgs/String.h>
#include "ros/ros.h"
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include "nav_msgs/Odometry.h"
#include <tf/transform_broadcaster.h>
#include "message_project_s/ObstacleAlignmentReport_1.h"

//-------------------------------------------------------------------------------------------------
// Mobileye Callbacks - Alignment Data
//-------------------------------------------------------------------------------------------------

message_project_s::ObstacleAlignmentReport_1 ME_obstacles_alignment;

bool received_ME_obstacles_alignment = false;
void ME_obstacles_alignment_Callback(const message_project_s::ObstacleAlignmentReport_1::ConstPtr& msg)
{
	ME_obstacles_alignment = *msg;

	received_ME_obstacles_alignment = true;
}

//-------------------------------------------------------------------------------------------------
// IBEO LIDAR Callbacks - Alignment Data
//-------------------------------------------------------------------------------------------------

message_project_s::ObstacleAlignmentReport_1 lidar_obstacles_alignment;

bool received_lidar_obstacles_alignment = false;
void lidar_obstacles_alignment_Callback(const message_project_s::ObstacleAlignmentReport_1::ConstPtr& msg)
{
	lidar_obstacles_alignment = *msg;

	received_lidar_obstacles_alignment = true;
}

//-------------------------------------------------------------------------------------------------
// ESR Callbacks - Alignment Data
//-------------------------------------------------------------------------------------------------

message_project_s::ObstacleAlignmentReport_1 ESR_obstacles_alignment;

bool received_ESR_obstacles_alignment = false;
void ESR_obstacles_alignment_Callback(const message_project_s::ObstacleAlignmentReport_1::ConstPtr& msg)
{
	ESR_obstacles_alignment = *msg;

	received_ESR_obstacles_alignment = true;
}

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{ 

	ros::init(argc, argv, std::string("smart_sensor_align_marker"));

	ros::NodeHandle n;

//------------------------------------------- MobilEye ---------------------------------------------------------------
	// Markers---Mobileye 
	visualization_msgs::Marker ME_obstacles_align_Marker;

	//Mobileye - obstacle Filtering data
	ros::Subscriber sub_ME_obstacles_align = n.subscribe(std::string("/camera_me_obstacles_align_data"), 1, ME_obstacles_alignment_Callback);
	ros::Publisher pub_ME_obstacles_align = n.advertise<visualization_msgs::Marker>(std::string("/camera_me_obstacles_align_data_marker"), 1);
	
//------------------------------------------- IBEO ---------------------------------------------------------------
	// Markers---IBEO LIDAR
	visualization_msgs::Marker lidar_obstacles_align_Marker;

	//IBEO - Filtering Data
	ros::Subscriber sub_lidar_obstacles_align = n.subscribe(std::string("/lidar_obstacles_align_data"), 1, lidar_obstacles_alignment_Callback);
	ros::Publisher pub_lidar_obstacles_align = n.advertise<visualization_msgs::Marker>(std::string("/lidar_obstacles_align_data_markers"), 1);

//---------------------------------------------------------------------------------------------------------------

//------------------------------------------- Delphi-ESR ----------------------------------------------------------
	// Markers---ESR 
	visualization_msgs::Marker ESR_obstacles_align_Marker;

        //ESR - Filtering data
	ros::Subscriber sub_ESR_obstacles_align = n.subscribe(std::string("/radar_ESR_obstacles_align_data"), 1, ESR_obstacles_alignment_Callback);
	ros::Publisher pub_ESR_obstacles_align = n.advertise<visualization_msgs::Marker>(std::string("/radar_ESR_obstacles_align_data_markers"), 1);

//---------------------------------------------------------------------------------------------------------------

	ros::Duration blink_of_an_eye(0.1); 

	ros::Rate loop_rate(100);

	while(n.ok())
	{
		ros::spinOnce();
//-------------------------------------------------------------------------------------------------
// Marker - Mobileye  - Obstacle Alignment Data
//-------------------------------------------------------------------------------------------------

		if (received_ME_obstacles_alignment)
		{
			received_ME_obstacles_alignment = false;

			ME_obstacles_align_Marker = visualization_msgs::Marker();
			ME_obstacles_align_Marker.header.frame_id = "/base_link";
			ME_obstacles_align_Marker.header.stamp = ros::Time::now();
			ME_obstacles_align_Marker.lifetime = ros::Duration(0.2);
			ME_obstacles_align_Marker.id = 310;
			ME_obstacles_align_Marker.ns = "smart_sensor";
			ME_obstacles_align_Marker.type = visualization_msgs::Marker::CUBE_LIST;
			ME_obstacles_align_Marker.scale.x = 0.2;
			ME_obstacles_align_Marker.scale.y = 0.2;
			ME_obstacles_align_Marker.scale.z = 0.7;
			ME_obstacles_align_Marker.color.r = 1.0f;
			ME_obstacles_align_Marker.color.g = 1.0f;
			ME_obstacles_align_Marker.color.b = 1.0f;
			ME_obstacles_align_Marker.color.a = 1.0;
			ME_obstacles_align_Marker.action = visualization_msgs::Marker::MODIFY;
			ME_obstacles_align_Marker.pose.orientation.w = 1;

			for (int i = 0; i < ME_obstacles_alignment.QtyObstacles.data; i++)
			{
				ME_obstacles_align_Marker.points.push_back(ME_obstacles_alignment.ObstacleAlignement_1[i].obstaclePosition.position);	
				std::cerr<<"ID: "<< ME_obstacles_alignment.ObstacleAlignement_1[i].id;
				std::cerr<<" stamp: "<< ME_obstacles_alignment.ObstacleAlignement_1[i].header.stamp<<std::endl;			
		
			}
			std::cerr<<"-------------------------"<<std::endl;
				pub_ME_obstacles_align.publish(ME_obstacles_align_Marker);
		}
			
//-------------------------------------------------------------------------------------------------
// Marker - IBEO LIDAR - Obstacle Alignment Data
//-------------------------------------------------------------------------------------------------
			
		if (received_lidar_obstacles_alignment)
			{
			received_lidar_obstacles_alignment = false;

			lidar_obstacles_align_Marker = visualization_msgs::Marker();
			lidar_obstacles_align_Marker.header.frame_id = "/base_link";
			lidar_obstacles_align_Marker.header.stamp = ros::Time::now();
			lidar_obstacles_align_Marker.lifetime = ros::Duration();
			lidar_obstacles_align_Marker.id = 320;
			lidar_obstacles_align_Marker.ns = "smart_sensor";
			lidar_obstacles_align_Marker.type = visualization_msgs::Marker::CUBE_LIST;
			lidar_obstacles_align_Marker.scale.x = 0.2;
			lidar_obstacles_align_Marker.scale.y = 0.2;
			lidar_obstacles_align_Marker.scale.z = 0.7;
			lidar_obstacles_align_Marker.color.r = 1.0f;
			lidar_obstacles_align_Marker.color.g = 0.0f;
			lidar_obstacles_align_Marker.color.b = 0.0f;
			lidar_obstacles_align_Marker.color.a = 1.0;
			lidar_obstacles_align_Marker.action = visualization_msgs::Marker::MODIFY;
			lidar_obstacles_align_Marker.pose.orientation.w = 1;

			for (int i = 0; i < lidar_obstacles_alignment.QtyObstacles.data; i++)
			{
				lidar_obstacles_align_Marker.points.push_back(lidar_obstacles_alignment.ObstacleAlignement_1[i].obstaclePosition.position);
			}
			pub_lidar_obstacles_align.publish(lidar_obstacles_align_Marker);
		}

//-------------------------------------------------------------------------------------------------
// Marker - Delphi ESR  - Obstacle Alignment Data
//-------------------------------------------------------------------------------------------------

		if (received_ESR_obstacles_alignment)

		{
			received_ESR_obstacles_alignment = false;
	
			ESR_obstacles_align_Marker = visualization_msgs::Marker();

			ESR_obstacles_align_Marker.header.frame_id = "/base_link";
			ESR_obstacles_align_Marker.header.stamp = ros::Time::now();
			ESR_obstacles_align_Marker.lifetime = ros::Duration();
			ESR_obstacles_align_Marker.id = 330;
			ESR_obstacles_align_Marker.ns = "smart_sensor";
			ESR_obstacles_align_Marker.type = visualization_msgs::Marker::CUBE_LIST;
			ESR_obstacles_align_Marker.scale.x = 0.2;
			ESR_obstacles_align_Marker.scale.y = 0.2;
			ESR_obstacles_align_Marker.scale.z = 0.7;
			ESR_obstacles_align_Marker.color.r = 1.0f;
			ESR_obstacles_align_Marker.color.g = 1.0f;
			ESR_obstacles_align_Marker.color.b = 0.0f;
			ESR_obstacles_align_Marker.color.a = 1.0;
			ESR_obstacles_align_Marker.action = visualization_msgs::Marker::MODIFY;
			ESR_obstacles_align_Marker.pose.orientation.w = 1;

			for (int i = 0; i < ESR_obstacles_alignment.QtyObstacles.data; i++)
			{
				ESR_obstacles_align_Marker.points.push_back(ESR_obstacles_alignment.ObstacleAlignement_1[i].obstaclePosition.position);
			}
			pub_ESR_obstacles_align.publish(ESR_obstacles_align_Marker);
		}
		loop_rate.sleep();
	}
	return 0;	
}
