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

#include "project_s_msgs/Trajectory.h"
#include "project_s_msgs/Configurations.h"

project_s_msgs::Trajectory extractedTrajectory, trajectory_generation_clothoide, trajectory_GPS;
nav_msgs::Odometry odom, odom_trajectory_generation_clothoide;

bool received = false;
void trajectoryCallback(const project_s_msgs::Trajectory::ConstPtr& trajectory)
{
	extractedTrajectory = *trajectory;
	odom = extractedTrajectory.odom;

	received = true;
}

bool received_trajectory_GPS = false;
void trajectoryGPSCallback(const project_s_msgs::Trajectory::ConstPtr& buffer)
{
	trajectory_GPS = *buffer;
//	odom = trajectory_GPS.odom;

	received_trajectory_GPS = true;
}

bool received_trajectory_generation_clothoide = false;
void trajectorygenerationclothoideCallback(const project_s_msgs::Trajectory::ConstPtr& trajectory)
{
	trajectory_generation_clothoide = *trajectory;
	odom_trajectory_generation_clothoide = trajectory_generation_clothoide.odom;

	received_trajectory_generation_clothoide = true;
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

geometry_msgs::Point _computeGlobalPosition(geometry_msgs::Point point)
{	// calculs de la position dans le repère absolu,
	// à partir de la position dans le repère de l'égo (position déjà alignée)
	geometry_msgs::Point p;
	double theta = tf::getYaw(odom_trajectory_generation_clothoide.pose.pose.orientation);

	p.x = odom_trajectory_generation_clothoide.pose.pose.position.x + (point.x * cos(theta) - point.y * sin(theta));
	p.y = odom_trajectory_generation_clothoide.pose.pose.position.y + (point.x * sin(theta) + point.y * cos(theta));
	p.z = odom_trajectory_generation_clothoide.pose.pose.position.z +  point.z;

	return p;
}

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("trajectory_markers"));

	ros::NodeHandle n;

	ros::Publisher pub_trajectory_rel = n.advertise<visualization_msgs::Marker>(std::string("/trajectory_relative_markers"), 1);
	ros::Publisher pub_trajectory_abs = n.advertise<visualization_msgs::Marker>(std::string("/trajectory_absolu_markers"), 1);
	ros::Publisher pub_set_point_abs = n.advertise<visualization_msgs::Marker>(std::string("/set_point_absolu_markers"), 1);
	ros::Publisher pub_trajectory_GPS_abs = n.advertise<visualization_msgs::Marker>(std::string("/trajectory_GPS_absolu_markers"), 1);
	ros::Publisher pub_trajectory_generation_clothoide_rel = n.advertise<visualization_msgs::Marker>(std::string("/trajectory_generation_clothoide_relative_markers"), 1);
	ros::Publisher pub_trajectory_generation_clothoide_abs = n.advertise<visualization_msgs::Marker>(std::string("/trajectory_generation_clothoide_absolu_markers"), 1);

	ros::Subscriber subTrajectory = n.subscribe(std::string("/trajectory_generation_data"), 1, trajectoryCallback);
	ros::Subscriber subTrajectoryGPS = n.subscribe(std::string("/trajectory_GPS_generation_data"), 1, trajectoryGPSCallback);
	ros::Subscriber sub_trajectory_generation_clothoide = n.subscribe(std::string("/trajectory_generation_clothoide"), 1, trajectorygenerationclothoideCallback);

	visualization_msgs::Marker relativeTrajectoryMarker, absoluTrajectoryMarker, absoluSetPointMarker, absoluTrajectoryGPSMarker, absoluSetPointGPSMarker;
	visualization_msgs::Marker relativeTrajectoryClothoideMarker, absoluTrajectoryClothoideMarker;

	ros::Duration blink_of_an_eye(0.01); 

	ros::Rate loop_rate(25);

	while(n.ok())
	{
		ros::spinOnce();

		if (received)
		{
			received = false;

			// Markers pour le repère relatif
			relativeTrajectoryMarker = visualization_msgs::Marker();

			relativeTrajectoryMarker.header.frame_id = "/base_link";
			relativeTrajectoryMarker.header.stamp = ros::Time::now();
			relativeTrajectoryMarker.lifetime = ros::Duration();
			relativeTrajectoryMarker.id = 321;
			relativeTrajectoryMarker.ns = "trajectory";
			relativeTrajectoryMarker.type = visualization_msgs::Marker::SPHERE_LIST;
			relativeTrajectoryMarker.scale.x = 0.3;
			relativeTrajectoryMarker.scale.y = 0.3;
			relativeTrajectoryMarker.scale.z = 0.3;
			relativeTrajectoryMarker.color.r = 1.0f;
			relativeTrajectoryMarker.color.g = 1.0f;
			relativeTrajectoryMarker.color.b = 0.0f;
			relativeTrajectoryMarker.color.a = 1.0;
			relativeTrajectoryMarker.action = visualization_msgs::Marker::MODIFY;
			relativeTrajectoryMarker.pose.orientation.w = 1;

			// Markers pour le repère absolu
			absoluTrajectoryMarker = visualization_msgs::Marker();

			absoluTrajectoryMarker.header.frame_id = "/odom";
			absoluTrajectoryMarker.header.stamp = ros::Time::now();
			absoluTrajectoryMarker.lifetime = ros::Duration();
			absoluTrajectoryMarker.id = 322;
			absoluTrajectoryMarker.ns = "trajectory";
			absoluTrajectoryMarker.type = visualization_msgs::Marker::CUBE_LIST;
			absoluTrajectoryMarker.scale.x = 0.3;
			absoluTrajectoryMarker.scale.y = 0.3;
			absoluTrajectoryMarker.scale.z = 0.3;
			absoluTrajectoryMarker.color.r = 1.0f;
			absoluTrajectoryMarker.color.g = 1.0f;
			absoluTrajectoryMarker.color.b = 0.0f;
			absoluTrajectoryMarker.color.a = 1.0;
			absoluTrajectoryMarker.action = visualization_msgs::Marker::MODIFY;
			absoluTrajectoryMarker.pose.orientation.w = 1;

			absoluSetPointMarker = visualization_msgs::Marker();

			absoluSetPointMarker.header.frame_id = "/odom";
			absoluSetPointMarker.header.stamp = ros::Time::now();
			absoluSetPointMarker.lifetime = ros::Duration();
			absoluSetPointMarker.id = 323;
			absoluSetPointMarker.ns = "trajectory";
			absoluSetPointMarker.type = visualization_msgs::Marker::CUBE_LIST;
			absoluSetPointMarker.scale.x = 0.5;
			absoluSetPointMarker.scale.y = 0.5;
			absoluSetPointMarker.scale.z = 0.5;
			absoluSetPointMarker.color.r = 1.0f;
			absoluSetPointMarker.color.g = 1.0f;
			absoluSetPointMarker.color.b = 0.0f;
			absoluSetPointMarker.color.a = 1.0;
			absoluSetPointMarker.action = visualization_msgs::Marker::MODIFY;
			absoluSetPointMarker.pose.orientation.w = 1;

			for (int i = 0; i < extractedTrajectory.trajectoryLine.QtySegment.data; i++)
			{
				relativeTrajectoryMarker.points.push_back(extractedTrajectory.trajectoryLine.segment[i].position);
				absoluTrajectoryMarker.points.push_back(computeGlobalPosition(extractedTrajectory.trajectoryLine.segment[i].position));
			}

			absoluSetPointMarker.points.push_back(computeGlobalPosition(extractedTrajectory.setpointPosition.position));

#ifdef SIMULATION_CIRCUIT_LINE
			pub_trajectory_rel.publish(relativeTrajectoryMarker);
			pub_trajectory_abs.publish(absoluTrajectoryMarker);
			pub_set_point_abs.publish(absoluSetPointMarker);
#endif
		}

		if(received_trajectory_GPS)
		{
			received_trajectory_GPS = false;

			// Markers pour le repère absolu
			absoluTrajectoryGPSMarker = visualization_msgs::Marker();


			// attention : le nom de la variable commence par absoluXXX mais c'est un affichage en relatif
			//absoluTrajectoryGPSMarker.header.frame_id = "/odom";
			absoluTrajectoryGPSMarker.header.frame_id = "/base_link";
			absoluTrajectoryGPSMarker.header.stamp = ros::Time::now();
			absoluTrajectoryGPSMarker.lifetime = ros::Duration();
			absoluTrajectoryGPSMarker.id = 326;
			absoluTrajectoryGPSMarker.ns = "trajectory";
			absoluTrajectoryGPSMarker.type = visualization_msgs::Marker::CUBE_LIST;
			absoluTrajectoryGPSMarker.scale.x = 0.3;
			absoluTrajectoryGPSMarker.scale.y = 0.3;
			absoluTrajectoryGPSMarker.scale.z = 0.3;
			absoluTrajectoryGPSMarker.color.r = 1.0f;
			absoluTrajectoryGPSMarker.color.g = 1.0f;
			absoluTrajectoryGPSMarker.color.b = 0.0f;
			absoluTrajectoryGPSMarker.color.a = 1.0;
			absoluTrajectoryGPSMarker.action = visualization_msgs::Marker::MODIFY;
			absoluTrajectoryGPSMarker.pose.orientation.w = 1;

			absoluSetPointGPSMarker = visualization_msgs::Marker();

			absoluSetPointGPSMarker.header.frame_id = "/base_link";
			absoluSetPointGPSMarker.header.stamp = ros::Time::now();
			absoluSetPointGPSMarker.lifetime = ros::Duration();
			absoluSetPointGPSMarker.id = 323;
			absoluSetPointGPSMarker.ns = "trajectory";
			absoluSetPointGPSMarker.type = visualization_msgs::Marker::CUBE_LIST;
			absoluSetPointGPSMarker.scale.x = 0.5;
			absoluSetPointGPSMarker.scale.y = 0.5;
			absoluSetPointGPSMarker.scale.z = 0.5;
			absoluSetPointGPSMarker.color.r = 1.0f;
			absoluSetPointGPSMarker.color.g = 1.0f;
			absoluSetPointGPSMarker.color.b = 0.0f;
			absoluSetPointGPSMarker.color.a = 1.0;
			absoluSetPointGPSMarker.action = visualization_msgs::Marker::MODIFY;
			absoluSetPointGPSMarker.pose.orientation.w = 1;

			for (int i = 0; i < trajectory_GPS.trajectoryLine.QtySegment.data; i++)
			{
				//absoluTrajectoryGPSMarker.points.push_back(computeGlobalPosition(trajectory_GPS.trajectoryLine.segment[i].position));
				absoluTrajectoryGPSMarker.points.push_back(trajectory_GPS.trajectoryLine.segment[i].position);
			}

			pub_trajectory_GPS_abs.publish(absoluTrajectoryGPSMarker);

			absoluSetPointGPSMarker.points.push_back(trajectory_GPS.setpointPosition.position);
#ifdef SIMULATION_CIRCUIT_GPS
			pub_set_point_abs.publish(absoluSetPointGPSMarker);
#endif
		}

		if(received_trajectory_generation_clothoide)
		{
			received_trajectory_generation_clothoide = false;

			// Markers pour le repère relatif
			relativeTrajectoryClothoideMarker = visualization_msgs::Marker();

			relativeTrajectoryClothoideMarker.header.frame_id = "/base_link";
			relativeTrajectoryClothoideMarker.header.stamp = ros::Time::now();
			relativeTrajectoryClothoideMarker.lifetime = ros::Duration();
			relativeTrajectoryClothoideMarker.id = 324;
			relativeTrajectoryClothoideMarker.ns = "trajectory";
			relativeTrajectoryClothoideMarker.type = visualization_msgs::Marker::SPHERE_LIST;
			relativeTrajectoryClothoideMarker.scale.x = 0.3;
			relativeTrajectoryClothoideMarker.scale.y = 0.3;
			relativeTrajectoryClothoideMarker.scale.z = 0.3;
			relativeTrajectoryClothoideMarker.color.r = 1.0f;
			relativeTrajectoryClothoideMarker.color.g = 1.0f;
			relativeTrajectoryClothoideMarker.color.b = 0.0f;
			relativeTrajectoryClothoideMarker.color.a = 1.0;
			relativeTrajectoryClothoideMarker.action = visualization_msgs::Marker::MODIFY;
			relativeTrajectoryClothoideMarker.pose.orientation.w = 1;

			// Markers pour le repère absolu
			absoluTrajectoryClothoideMarker = visualization_msgs::Marker();

			absoluTrajectoryClothoideMarker.header.frame_id = "/odom";
			absoluTrajectoryClothoideMarker.header.stamp = ros::Time::now();
			absoluTrajectoryMarker.lifetime = ros::Duration();
			absoluTrajectoryClothoideMarker.id = 325;
			absoluTrajectoryClothoideMarker.ns = "trajectory";
			absoluTrajectoryClothoideMarker.type = visualization_msgs::Marker::CUBE_LIST;
			absoluTrajectoryClothoideMarker.scale.x = 0.3;
			absoluTrajectoryClothoideMarker.scale.y = 0.3;
			absoluTrajectoryClothoideMarker.scale.z = 0.3;
			absoluTrajectoryClothoideMarker.color.r = 1.0f;
			absoluTrajectoryClothoideMarker.color.g = 1.0f;
			absoluTrajectoryClothoideMarker.color.b = 0.0f;
			absoluTrajectoryClothoideMarker.color.a = 1.0;
			absoluTrajectoryClothoideMarker.action = visualization_msgs::Marker::MODIFY;
			absoluTrajectoryClothoideMarker.pose.orientation.w = 1;

			//for (int i = 0; i < 100; i++)
			for (int i = 0; i < trajectory_generation_clothoide.trajectoryLine.QtySegment.data; i++)
			{
				if(trajectory_generation_clothoide.trajectoryLine.segment[i].position.x != 0 || trajectory_generation_clothoide.trajectoryLine.segment[i].position.y != 0)
				{
					relativeTrajectoryClothoideMarker.points.push_back(trajectory_generation_clothoide.trajectoryLine.segment[i].position);
					absoluTrajectoryClothoideMarker.points.push_back(_computeGlobalPosition(trajectory_generation_clothoide.trajectoryLine.segment[i].position));
				}
			}

			pub_trajectory_generation_clothoide_rel.publish(relativeTrajectoryClothoideMarker);
			pub_trajectory_generation_clothoide_abs.publish(absoluTrajectoryClothoideMarker);
		}

		loop_rate.sleep();
	}

	return 0;
}
