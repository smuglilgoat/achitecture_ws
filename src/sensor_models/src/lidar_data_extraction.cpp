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

#include "project_s_msgs/ObstacleReport.h"
#include "project_s_msgs/ObstacleAlignmentReport.h"

#include <network_interface/TCPFrame.h>
#include <sensor_msgs/PointCloud2.h>
#include <visualization_msgs/MarkerArray.h>
#include <visualization_msgs/Marker.h>
/*
#include <ibeo_msgs/ScanData2205.h>
#include <ibeo_msgs/ScanData2208.h>
#include <ibeo_msgs/ObjectData2270.h>
#include <ibeo_msgs/ObjectData2271.h>
#include <ibeo_msgs/HostVehicleState2805.h>
*/
#include <ibeo_msgs/ScanData2205.h>
#include <ibeo_msgs/ObjectData2225.h>
#include <ibeo_msgs/ObjectData2280.h>
#include <ibeo_msgs/CameraImage.h>
#include <ibeo_msgs/HostVehicleState2806.h>
#include <ibeo_msgs/HostVehicleState2807.h>

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport extractedObstacle;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport reportObstacle;

network_interface::TCPFrame tcp_tx;
sensor_msgs::PointCloud2 point_cloud;
visualization_msgs::MarkerArray objects;
visualization_msgs::Marker object_contour_points;

ibeo_msgs::ScanData2205 scan_data_2205;
ibeo_msgs::ObjectData2225 object_data_2225;
ibeo_msgs::ObjectData2280 object_data_2280;
ibeo_msgs::CameraImage camera_image;
ibeo_msgs::HostVehicleState2806 host_vehicle_state_2806;
ibeo_msgs::HostVehicleState2807 host_vehicle_state_2807;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool obstacleReceived = false;
void obstacleDataCallback(const project_s_msgs::ObstacleReport::ConstPtr& ObstacleArray)
{
	extractedObstacle = *ObstacleArray;

	obstacleReceived = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "lidar_data_extraction");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher pub_obstacles = n.advertise<project_s_msgs::ObstacleReport>(std::string("/lidar_data_extraction"), 1);	

	ros::Publisher pub_tcp_tx                = n.advertise<network_interface::TCPFrame>    (std::string("/tcp_tx")                     , 1);
	ros::Publisher pub_point_cloud           = n.advertise<sensor_msgs::PointCloud2>       (std::string("/as_tx/point_cloud")          , 1);
	ros::Publisher pub_object_contour_points = n.advertise<visualization_msgs::Marker>     (std::string("/as_tx/object_contour_points"), 1);
	ros::Publisher pub_objects               = n.advertise<visualization_msgs::MarkerArray>(std::string("/as_tx/objects_lidar")        , 1);// topic renommé en "objects_lidar",
																		// car "objects" existe déjà camera_me_data_extraction.cpp

	ros::Publisher pub_scan_data_2205          = n.advertise<ibeo_msgs::ScanData2205>        (std::string("/parsed_tx/scan_data_2205")         , 1);
	ros::Publisher pub_object_data_2225        = n.advertise<ibeo_msgs::ObjectData2225>      (std::string("/parsed_tx/object_data_2225")       , 1);
	ros::Publisher pub_object_data_2280        = n.advertise<ibeo_msgs::ObjectData2280>      (std::string("/parsed_tx/object_data_2280")       , 1);
	ros::Publisher pub_camera_image            = n.advertise<ibeo_msgs::CameraImage>         (std::string("/parsed_tx/camera_image")           , 1);
	ros::Publisher pub_host_vehicle_state_2806 = n.advertise<ibeo_msgs::HostVehicleState2806>(std::string("/parsed_tx/host_vehicle_state_2806"), 1);
	ros::Publisher pub_host_vehicle_state_2807 = n.advertise<ibeo_msgs::HostVehicleState2807>(std::string("/parsed_tx/host_vehicle_state_2807"), 1);

	// Subscriber
	ros::Subscriber subData = n.subscribe(std::string("/lidar_obstacle"), 1, obstacleDataCallback);

	ros::Rate loop_rate(1000);

  	while(n.ok())
	{
		ros::spinOnce();

		if(obstacleReceived)
		{
			obstacleReceived = false;

			reportObstacle = extractedObstacle;

			pub_obstacles.publish(reportObstacle);

			pub_tcp_tx.publish(tcp_tx);
			pub_point_cloud.publish(point_cloud);
			pub_objects.publish(objects);
			pub_object_contour_points.publish(object_contour_points);

			pub_scan_data_2205.publish(scan_data_2205);
			pub_object_data_2225.publish(object_data_2225);
			pub_object_data_2280.publish(object_data_2280);
			pub_camera_image.publish(camera_image);
			pub_host_vehicle_state_2806.publish(host_vehicle_state_2806);
			pub_host_vehicle_state_2807.publish(host_vehicle_state_2807);
		}

		loop_rate.sleep();
	}

	return 0;
}
