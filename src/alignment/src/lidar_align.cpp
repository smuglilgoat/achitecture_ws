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

#include "ros/ros.h"
#include <tf/transform_broadcaster.h>

#include "project_s_msgs/ObstacleReport.h"
#include "project_s_msgs/ObstacleAlignmentReport.h"

#include "network_interface/TCPFrame.h"
#include "sensor_msgs/PointCloud2.h"
#include "visualization_msgs/MarkerArray.h"
#include "visualization_msgs/Marker.h"

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
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleAlignmentReport reportObstacle;

// Server parameters
geometry_msgs::Point offset;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool received = false;
void obstacleDataCallback(const project_s_msgs::ObstacleReport::ConstPtr& genericSmartData)
{
	extractedObstacle = *genericSmartData;

	received = true;
}

void tcptxDataCallback(const network_interface::TCPFrame::ConstPtr& buffer)
{
	tcp_tx = *buffer;
}

void pointcloudDataCallback(const sensor_msgs::PointCloud2::ConstPtr& buffer)
{
	point_cloud = *buffer;
}

void objectsDataCallback(const visualization_msgs::MarkerArray::ConstPtr& buffer)
{
	objects = *buffer;
}

void objectcontourpointsDataCallback(const visualization_msgs::Marker::ConstPtr& buffer)
{
	object_contour_points = *buffer;
}

void scandata2205DataCallback(const ibeo_msgs::ScanData2205::ConstPtr& buffer)
{
	scan_data_2205 = *buffer;
}

void objectdata2225DataCallback(const ibeo_msgs::ObjectData2225::ConstPtr& buffer)
{
	object_data_2225 = *buffer;
}

void objectdata2280DataCallback(const ibeo_msgs::ObjectData2280::ConstPtr& buffer)
{
	object_data_2280 = *buffer;
}

void cameraimageDataCallback(const ibeo_msgs::CameraImage::ConstPtr& buffer)
{
	camera_image = *buffer;
}

void hostvehiclestate2806DataCallback(const ibeo_msgs::HostVehicleState2806::ConstPtr& buffer)
{
	host_vehicle_state_2806 = *buffer;
}

void hostvehiclestate2807DataCallback(const ibeo_msgs::HostVehicleState2807::ConstPtr& buffer)
{
	host_vehicle_state_2807 = *buffer;
}

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
// alignement spatial
geometry_msgs::Point obstacleAlignment(geometry_msgs::Point point, geometry_msgs::Point off_)
{
	geometry_msgs::Point p;
	p.x = point.x + off_.x; // add the camera's position to ego reference and the ego reference position relative to the center of the car
	p.y = point.y + off_.y;
	p.z = point.z + off_.z;

	return p;
}

// synchronisation temporelle
geometry_msgs::Pose obstacleSynchronisation(geometry_msgs::Pose pose, geometry_msgs::Twist twist, double dt)
{
	geometry_msgs::Pose p;
	p.position.x = pose.position.x + twist.linear.x*dt;
	p.position.y = pose.position.y + twist.linear.y*dt;
	p.position.z = pose.position.z + twist.linear.z*dt;

	return p;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("lidar_align"));

	ros::NodeHandle n;

	// Subscriber global reference obstacle data  
	ros::Subscriber subData = n.subscribe(std::string("/lidar_data_extraction"), 1, obstacleDataCallback);

	ros::Subscriber sub_tcp_tx                = n.subscribe(std::string("/tcp_tx")                     , 1, tcptxDataCallback);
	ros::Subscriber sub_point_cloud           = n.subscribe(std::string("/as_tx/point_cloud")          , 1, pointcloudDataCallback);
	ros::Subscriber sub_objects               = n.subscribe(std::string("/as_tx/objects_lidar")        , 1, objectsDataCallback);
	ros::Subscriber sub_object_contour_points = n.subscribe(std::string("/as_tx/object_contour_points"), 1, objectcontourpointsDataCallback);

	ros::Subscriber sub_scan_data_2205          = n.subscribe(std::string("/parsed_tx/scan_data_2205")         , 1, scandata2205DataCallback);
	ros::Subscriber sub_object_data_2225        = n.subscribe(std::string("/parsed_tx/object_data_2225")       , 1, objectdata2225DataCallback);
	ros::Subscriber sub_object_data_2280        = n.subscribe(std::string("/parsed_tx/object_data_2280")       , 1, objectdata2280DataCallback);
	ros::Subscriber sub_camera_image            = n.subscribe(std::string("/parsed_tx/camera_image")           , 1, cameraimageDataCallback);
	ros::Subscriber sub_host_vehicle_state_2806 = n.subscribe(std::string("/parsed_tx/host_vehicle_state_2806"), 1, hostvehiclestate2806DataCallback);
	ros::Subscriber sub_host_vehicle_state_2807 = n.subscribe(std::string("/parsed_tx/host_vehicle_state_2807"), 1, hostvehiclestate2807DataCallback);

	// Raport publisher with relative positions for the objects with the car
	ros::Publisher pubRaport = n.advertise<project_s_msgs::ObstacleAlignmentReport>(std::string("/lidar_obstacles_align_data"), 1);

	ros::Rate loop_rate(1000);

	if (n.hasParam("/lidar/offset_x"))
		n.getParam("/lidar/offset_x", offset.x);
	if (n.hasParam("/lidar/offset_y"))
		n.getParam("/lidar/offset_y", offset.y);
	if (n.hasParam("/lidar/offset_z"))
		n.getParam("/lidar/offset_z", offset.z);

	geometry_msgs::Point egoRelativePosition;
	geometry_msgs::Pose  egoRelativePose;

	//double dt;

	while(n.ok())
	{
		ros::spinOnce();

		if (received)
		{
			received = false;

			reportObstacle              = project_s_msgs::ObstacleAlignmentReport();
			reportObstacle.header       = extractedObstacle.header;
			reportObstacle.id           = extractedObstacle.id;
			reportObstacle.odom         = extractedObstacle.odom;
			reportObstacle.QtyObstacles = extractedObstacle.QtySmartData;

			for(int i = 0; i < extractedObstacle.QtySmartData.data; i++)
			{
				reportObstacle.ObstacleAlignement[i].header                   = extractedObstacle.GenericSmartData[i].header;
				reportObstacle.ObstacleAlignement[i].id                       = extractedObstacle.GenericSmartData[i].id;
				reportObstacle.ObstacleAlignement[i].obstaclePosition         = extractedObstacle.GenericSmartData[i].obstaclePosition;
				reportObstacle.ObstacleAlignement[i].obstaclePoseVariance     = extractedObstacle.GenericSmartData[i].obstaclePoseVariance;
				reportObstacle.ObstacleAlignement[i].obstacleVelocity         = extractedObstacle.GenericSmartData[i].obstacleVelocity;
				reportObstacle.ObstacleAlignement[i].obstacleVelocityVariance = extractedObstacle.GenericSmartData[i].obstacleVelocityVariance;
				reportObstacle.ObstacleAlignement[i].obstacleAcceleration     = extractedObstacle.GenericSmartData[i].obstacleAcceleration;
				reportObstacle.ObstacleAlignement[i].obstacleDimensions       = extractedObstacle.GenericSmartData[i].obstacleDimensions;

				// alignement spatial
				egoRelativePosition = obstacleAlignment(reportObstacle.ObstacleAlignement[i].obstaclePosition.position, offset);
				reportObstacle.ObstacleAlignement[i].obstaclePosition.position = egoRelativePosition;

				// synchro temporelle
				//dt = 0;
				//egoRelativePose = obstacleSynchronisation(reportObstacle.ObstacleAlignement[i].obstaclePosition, reportObstacle.ObstacleAlignement[i].obstacleVelocity, dt);
				//reportObstacle.ObstacleAlignement[i].obstaclePosition = egoRelativePose;
			}

			pubRaport.publish(reportObstacle);
		}
		
		loop_rate.sleep();
	}

	return 0;
}
