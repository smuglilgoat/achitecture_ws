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

#include "project_s_msgs/GenericSmartData.h"
#include "project_s_msgs/ObstacleReport.h"

project_s_msgs::ObstacleReport extractedObstacles;

bool received = false;

void obstacleCallback(const project_s_msgs::ObstacleReport::ConstPtr& genericSmartDataArray)
{
	extractedObstacles = *genericSmartDataArray;

	received = true;
}

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("obstacles_markers"));

	ros::NodeHandle n;

	ros::Publisher pubMarker = n.advertise<visualization_msgs::Marker>(std::string("/obstacles_markers"), 10);	// affichage jusqu'à 10 objets

	ros::Subscriber subObstacles = n.subscribe(std::string("/obstacles"), 1, obstacleCallback);

	visualization_msgs::Marker marker;

	ros::Duration blink_of_an_eye(0.01); 

	ros::Rate loop_rate(1000);

	while(n.ok())
	{
		ros::spinOnce();

		if (received)
		{
			received = false;

			marker = visualization_msgs::Marker();

			for(int i = 0; i < 10; i++)
			{
				marker.header.frame_id = "/odom";
				marker.header.stamp = ros::Time::now();
				marker.type = visualization_msgs::Marker::CUBE;
				marker.ns = "obstacles";
				marker.id = 10 + i;

				marker.scale = extractedObstacles.GenericSmartData[i].obstacleDimensions; 

				marker.color.r = 0.5f;
				marker.color.g = 0.5f;
				marker.color.b = 0.5f;
				marker.color.a = 0.5;
				marker.lifetime = ros::Duration();

				marker.pose = extractedObstacles.GenericSmartData[i].obstaclePosition;	// pose & orientation

				if(extractedObstacles.GenericSmartData[i].id.data != 0)
					pubMarker.publish(marker);
				// Rem : pas possible d'utiliser marker.points.push_back() car marker.scale change à chaque obstacles
			}
		}

		loop_rate.sleep();
	}

	return 0;
}

