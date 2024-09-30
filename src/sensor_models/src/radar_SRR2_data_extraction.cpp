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

#include <can_msgs/Frame.h>

#include <delphi_srr_msgs/SrrDebug3.h>
#include <delphi_srr_msgs/SrrDebug4.h>
#include <delphi_srr_msgs/SrrDebug5.h>
#include <delphi_srr_msgs/SrrFeatureAlert.h>
#include <delphi_srr_msgs/SrrFeatureSwVersion.h>
#include <delphi_srr_msgs/SrrStatus1.h>
#include <delphi_srr_msgs/SrrStatus2.h>
#include <delphi_srr_msgs/SrrStatus3.h>
#include <delphi_srr_msgs/SrrStatus4.h>
#include <delphi_srr_msgs/SrrStatus5.h>
#include <delphi_srr_msgs/SrrTrack.h>

#include <radar_msgs/RadarDetectionArray.h>

#include <visualization_msgs/Marker.h>

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport extractedObstacle;

can_msgs::Frame can_tx;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport reportObstacle;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool obstacleReceived = false;
void obstacleDataCallback(const project_s_msgs::ObstacleReport::ConstPtr& ObstacleArray)
{
	extractedObstacle = *ObstacleArray;

	obstacleReceived = true;
}

bool can_tx_Received = false;
void cantxCallback(const can_msgs::Frame::ConstPtr& buffer)
{
	can_tx = *buffer;

	can_tx_Received = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "radar_SRR2_data_extraction");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher pub_obstacles = n.advertise<project_s_msgs::ObstacleReport>(std::string("/radar_SRR2_data_extraction"), 1);	

	ros::Publisher pub_can_rx = n.advertise<can_msgs::Frame>(std::string("/can_rx"), 1);

	ros::Publisher pub_srr_debug3             = n.advertise<delphi_srr_msgs::SrrDebug3>          (std::string("/parsed_tx/srr_debug3"),             1);
	ros::Publisher pub_srr_debug4             = n.advertise<delphi_srr_msgs::SrrDebug4>          (std::string("/parsed_tx/srr_debug4"),             1);
	ros::Publisher pub_srr_debug5             = n.advertise<delphi_srr_msgs::SrrDebug5>          (std::string("/parsed_tx/srr_debug5"),             1);
	ros::Publisher pub_srr_feature_alert      = n.advertise<delphi_srr_msgs::SrrFeatureAlert>    (std::string("/parsed_tx/srr_feature_alert"),      1);
	ros::Publisher pub_srr_feature_sw_version = n.advertise<delphi_srr_msgs::SrrFeatureSwVersion>(std::string("/parsed_tx/srr_feature_sw_version"), 1);
	ros::Publisher pub_srr_status1            = n.advertise<delphi_srr_msgs::SrrStatus1>         (std::string("/parsed_tx/srr_status1"),            1);
	ros::Publisher pub_srr_status2            = n.advertise<delphi_srr_msgs::SrrStatus2>         (std::string("/parsed_tx/srr_status2"),            1);
	ros::Publisher pub_srr_status3            = n.advertise<delphi_srr_msgs::SrrStatus3>         (std::string("/parsed_tx/srr_status3"),            1);
	ros::Publisher pub_srr_status4            = n.advertise<delphi_srr_msgs::SrrStatus4>         (std::string("/parsed_tx/srr_status4"),            1);
	ros::Publisher pub_srr_status5            = n.advertise<delphi_srr_msgs::SrrStatus5>         (std::string("/parsed_tx/srr_status5"),            1);
	ros::Publisher pub_srr_track              = n.advertise<delphi_srr_msgs::SrrTrack>           (std::string("/parsed_tx/srr_track"),              1);

	ros::Publisher pub_detections = n.advertise<radar_msgs::RadarDetectionArray>(std::string("/as_tx/detections"), 1);

	ros::Publisher pub_radar_markers = n.advertise<visualization_msgs::Marker>(std::string("/as_tx/radar_markers"), 1);

	// Subscriber
	ros::Subscriber subData = n.subscribe(std::string("/radar_SRR2_obstacle"), 1, obstacleDataCallback);

	ros::Subscriber sub_can_tx = n.subscribe(std::string("/can_tx"), 1, cantxCallback);

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

		loop_rate.sleep();
	}

	return 0;
}
