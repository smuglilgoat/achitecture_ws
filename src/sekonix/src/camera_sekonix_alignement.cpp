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

#include "visualization_msgs/Marker.h"
#include "project_s_msgs/ObstacleReport.h"
#include "project_s_msgs/ObstacleAlignmentReport.h"
#include "project_s_msgs/RouteLine.h"
#include "project_s_msgs/LaneAlignment.h"

project_s_msgs::ObstacleReport extractedObstacle;
project_s_msgs::ObstacleAlignmentReport reportObstacle;
project_s_msgs::RouteLine extractedLine;
project_s_msgs::LaneAlignment laneAlignReport;


// Server parameters
geometry_msgs::Point offset;

bool received = false;
void obstacleDataCallback(const project_s_msgs::ObstacleReport::ConstPtr& ObstacleArray)
{
	extractedObstacle = *ObstacleArray;

	received = true;
}

bool routeLineReceived = false;
void linesDataCallback(const project_s_msgs::RouteLine::ConstPtr& routeLine)
{
	extractedLine = *routeLine;

	routeLineReceived = true;
}

// alignement spatial
geometry_msgs::Point obstacleAlignment(geometry_msgs::Point point, geometry_msgs::Point off_)
{
	geometry_msgs::Point p;
	p.x = point.x + off_.x; // add the camera's position to ego reference and the ego reference position relative to the center of the car
	p.y = point.y + off_.y;
	p.z = point.z + off_.z;

	return p;
}

// alignement spatial
geometry_msgs::Point lineAlignment(geometry_msgs::Point point, geometry_msgs::Point off_)
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

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("camera_sekonix_alignement"));

	ros::NodeHandle n;

	// Subscriber global reference obstacle data  
	ros::Subscriber subData  = n.subscribe(std::string("/camera_sekonix_data_extraction_obstacle"),     1, obstacleDataCallback);
	ros::Subscriber subLines = n.subscribe(std::string("/camera_sekonix_data_extraction_route_lines"), 1, linesDataCallback);

	// Raport publisher with relative positions for the objects with the car
	ros::Publisher pubRaport    = n.advertise<project_s_msgs::ObstacleAlignmentReport>(std::string("/camera_sekonix_obstacles_align_data"), 1);
	ros::Publisher pubLaneAlign = n.advertise<project_s_msgs::LaneAlignment>          (std::string("/camera_sekonix_route_alignment_data"), 1);

	ros::Rate loop_rate(1000);

	if (n.hasParam("/mobil_eye/offset_x"))
		n.getParam("/mobil_eye/offset_x", offset.x);
	if (n.hasParam("/mobil_eye/offset_y"))
		n.getParam("/mobil_eye/offset_y", offset.y);
	if (n.hasParam("/mobil_eye/offset_z"))
		n.getParam("/mobil_eye/offset_z", offset.z);

	geometry_msgs::Point egoRelativePosition;

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
			}

			pubRaport.publish(reportObstacle);
		}

		// Transform intro ego relative position from camera relative position so just add the positions of the camera 
		// for the momend embedded in the code, but they should be added by a config/database file
		if(routeLineReceived)
		{
			routeLineReceived = false;

			laneAlignReport        = project_s_msgs::LaneAlignment();
			laneAlignReport.header = extractedLine.header;
			laneAlignReport.id     = extractedLine.id;
			laneAlignReport.odom   = extractedLine.odom;

			for(int i = 0; i < 3; i++)	// extractedLine est un tableau		5 lignes de 250 segments
			{				// mais on se limite pour l'instant à	3 lignes de  10 segments
				for(int j = 0; j < 10; j++)
				{
					if((extractedLine.line[i].segment[j].position.x != 0) || (extractedLine.line[i].segment[j].position.y != 0))
					{
						laneAlignReport.line[i].segment[j].position = extractedLine.line[i].segment[j].position;
						laneAlignReport.line[i].segment[j].Velocity = extractedLine.line[i].segment[j].Velocity;

						// alignement spatial
						egoRelativePosition = lineAlignment(extractedLine.line[i].segment[j].position, offset);
						laneAlignReport.line[i].segment[j].position = egoRelativePosition;
					}
				}
			}

			pubLaneAlign.publish(laneAlignReport);
		}

		loop_rate.sleep();
	}

	return 0;
}
