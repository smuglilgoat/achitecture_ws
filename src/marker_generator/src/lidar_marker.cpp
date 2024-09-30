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

#include "visualization_msgs/Marker.h"
#include "nav_msgs/Odometry.h"
#include <tf/transform_broadcaster.h>

#include "project_s_msgs/ObstacleAlignmentReport.h"

project_s_msgs::ObstacleAlignmentReport extractedObstaclesAlign;
nav_msgs::Odometry odom;

bool received = false;
void obstacleAlignCallback(const project_s_msgs::ObstacleAlignmentReport::ConstPtr& ObstacleAlignementArray)
{
	extractedObstaclesAlign = *ObstacleAlignementArray;
	odom = extractedObstaclesAlign.odom;

	received = true;
}

geometry_msgs::Point computeGlobalPosition(geometry_msgs::Point point)
{	// calculs de la position dans le repère absolu,
	// à partir de la position dans le repère de l'égo (position déjà alignée)
	geometry_msgs::Point p;
	double theta = tf::getYaw(odom.pose.pose.orientation);

	p.x = odom.pose.pose.position.x + (point.x * cos(theta) - point.y * sin(theta));
	p.y = odom.pose.pose.position.y + (point.x * sin(theta) + point.y * cos(theta));
	p.z = odom.pose.pose.position.z +  point.z;

	return p;
}

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("obstacles_markers_lidar"));

	ros::NodeHandle n;

	ros::Publisher pub_obstacle_rel = n.advertise<visualization_msgs::Marker>(std::string("/lidar_relative_obstacle_markers"), 1);
	ros::Publisher pub_obstacle_abs = n.advertise<visualization_msgs::Marker>(std::string("/lidar_absolu_obstacle_markers"), 1);

	ros::Subscriber subObstaclesAlign = n.subscribe(std::string("/lidar_obstacles_align_data"), 1, obstacleAlignCallback);

	visualization_msgs::Marker relativeObstacleMarker, absoluObstacleMarker;

	ros::Duration blink_of_an_eye(0.01); 

	ros::Rate loop_rate(25);

	while(n.ok())
	{
		ros::spinOnce();

		if (received)
		{
			received = false;

			// Markers pour le repère relatif
			relativeObstacleMarker = visualization_msgs::Marker();

			relativeObstacleMarker.header.frame_id = "/base_link";
			relativeObstacleMarker.header.stamp = ros::Time::now();
			relativeObstacleMarker.lifetime = ros::Duration();
			relativeObstacleMarker.id = 321;
			relativeObstacleMarker.ns = "Obstacles";
			relativeObstacleMarker.type = visualization_msgs::Marker::SPHERE_LIST;
			relativeObstacleMarker.scale.x = 0.8;
			relativeObstacleMarker.scale.y = 0.8;
			relativeObstacleMarker.scale.z = 0.8;
			relativeObstacleMarker.color.r = 0.0f;
			relativeObstacleMarker.color.g = 1.0f;
			relativeObstacleMarker.color.b = 0.0f;
			relativeObstacleMarker.color.a = 1.0;
			relativeObstacleMarker.action = visualization_msgs::Marker::MODIFY;
			relativeObstacleMarker.pose.orientation.w = 1;

			// Markers pour le repère absolu
			absoluObstacleMarker = visualization_msgs::Marker();

			absoluObstacleMarker.header.frame_id = "/odom";
			absoluObstacleMarker.header.stamp = ros::Time::now();
			absoluObstacleMarker.lifetime = ros::Duration();
			absoluObstacleMarker.id = 322;
			absoluObstacleMarker.ns = "Obstacles";
			absoluObstacleMarker.type = visualization_msgs::Marker::CUBE_LIST;
			absoluObstacleMarker.scale.x = 0.8;
			absoluObstacleMarker.scale.y = 0.8;
			absoluObstacleMarker.scale.z = 0.8;
			absoluObstacleMarker.color.r = 0.0f;
			absoluObstacleMarker.color.g = 1.0f;
			absoluObstacleMarker.color.b = 0.0f;
			absoluObstacleMarker.color.a = 1.0;
			absoluObstacleMarker.action = visualization_msgs::Marker::MODIFY;
			absoluObstacleMarker.pose.orientation.w = 1;

			for (int i = 0; i < extractedObstaclesAlign.QtyObstacles.data; i++)
			{
				relativeObstacleMarker.points.push_back(extractedObstaclesAlign.ObstacleAlignement[i].obstaclePosition.position);
				absoluObstacleMarker.points.push_back(computeGlobalPosition(extractedObstaclesAlign.ObstacleAlignement[i].obstaclePosition.position));
			}

			pub_obstacle_rel.publish(relativeObstacleMarker);
			pub_obstacle_abs.publish(absoluObstacleMarker);
		}

		loop_rate.sleep();
	}

	return 0;
}
