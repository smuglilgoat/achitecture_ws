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
#include "project_s_msgs/RouteLine.h"
#include "project_s_msgs/LaneAlignment.h"

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport extractedObstacle;
project_s_msgs::RouteLine      extractedLine;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport reportObstacle;
project_s_msgs::RouteLine      reportLine;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool obstacleReceived = false;
void obstacleDataCallback(const project_s_msgs::ObstacleReport::ConstPtr& ObstacleArray)
{
	extractedObstacle = *ObstacleArray;

	obstacleReceived = true;
}

bool routeLineReceived = false;
void linesDataCallback(const project_s_msgs::RouteLine::ConstPtr& routeLine)
{
	extractedLine = *routeLine;

	routeLineReceived = true;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "camera_sekonix_image_processing");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher pub_obstacles   = n.advertise<project_s_msgs::ObstacleReport>(std::string("/camera_sekonix_image_processing_obstacle"), 1);	
	ros::Publisher pub_route_lines = n.advertise<project_s_msgs::RouteLine>     (std::string("/camera_sekonix_image_processing_route_lines"), 1);

	// Subscriber
	ros::Subscriber subData  = n.subscribe(std::string("/camera_sekonix_obstacle"),    1, obstacleDataCallback);
	ros::Subscriber subLines = n.subscribe(std::string("/camera_sekonix_route_lines"), 1, linesDataCallback);

	ros::Rate loop_rate(1000);

  	while(n.ok())
	{
		ros::spinOnce();

		if(obstacleReceived)
		{
			obstacleReceived = false;

			reportObstacle = extractedObstacle;

			pub_obstacles.publish(reportObstacle);
		}

		if(routeLineReceived)
		{
			routeLineReceived = false;

			reportLine = extractedLine;

			pub_route_lines.publish(reportLine);
		}

		loop_rate.sleep();
	}

	return 0;
}
