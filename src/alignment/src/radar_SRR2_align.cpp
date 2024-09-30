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

can_msgs::Frame can_rx;

delphi_srr_msgs::SrrDebug3 srr_debug3;
delphi_srr_msgs::SrrDebug4 srr_debug4;
delphi_srr_msgs::SrrDebug5 srr_debug5;
delphi_srr_msgs::SrrFeatureAlert srr_feature_alert;
delphi_srr_msgs::SrrFeatureSwVersion srr_feature_sw_version;
delphi_srr_msgs::SrrStatus1 srr_status1;
delphi_srr_msgs::SrrStatus2 srr_status2;
delphi_srr_msgs::SrrStatus3 srr_status3;
delphi_srr_msgs::SrrStatus4 srr_status4;
delphi_srr_msgs::SrrStatus5 srr_status5;
delphi_srr_msgs::SrrTrack srr_track;

radar_msgs::RadarDetectionArray detections;

visualization_msgs::Marker radar_markers;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleAlignmentReport reportObstacle;


//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool received = false;
void obstacleDataCallback(const project_s_msgs::ObstacleReport::ConstPtr& genericSmartData)
{
	extractedObstacle = *genericSmartData;

	received = true;
}

void canrxCallback(const can_msgs::Frame::ConstPtr& buffer)
{
	can_rx = *buffer;
}

void srrdebug3Callback(const delphi_srr_msgs::SrrDebug3::ConstPtr& buffer)
{
	srr_debug3 = *buffer;
}

void srrdebug4Callback(const delphi_srr_msgs::SrrDebug4::ConstPtr& buffer)
{
	srr_debug4 = *buffer;
}

void srrdebug5Callback(const delphi_srr_msgs::SrrDebug5::ConstPtr& buffer)
{
	srr_debug5 = *buffer;
}

void srrfeaturealertCallback(const delphi_srr_msgs::SrrFeatureAlert::ConstPtr& buffer)
{
	srr_feature_alert = *buffer;
}

void srrfeatureswversionCallback(const delphi_srr_msgs::SrrFeatureSwVersion::ConstPtr& buffer)
{
	srr_feature_sw_version = *buffer;
}

void srrstatus1Callback(const delphi_srr_msgs::SrrStatus1::ConstPtr& buffer)
{
	srr_status1 = *buffer;
}

void srrstatus2Callback(const delphi_srr_msgs::SrrStatus2::ConstPtr& buffer)
{
	srr_status2 = *buffer;
}

void srrstatus3Callback(const delphi_srr_msgs::SrrStatus3::ConstPtr& buffer)
{
	srr_status3 = *buffer;
}

void srrstatus4Callback(const delphi_srr_msgs::SrrStatus4::ConstPtr& buffer)
{
	srr_status4 = *buffer;
}

void srrstatus5Callback(const delphi_srr_msgs::SrrStatus5::ConstPtr& buffer)
{
	srr_status5 = *buffer;
}

void srrtrackCallback(const delphi_srr_msgs::SrrTrack::ConstPtr& buffer)
{
	srr_track = *buffer;
}

void detectionsCallback(const radar_msgs::RadarDetectionArray::ConstPtr& buffer)
{
	detections = *buffer;
}

void radarmarkersCallback(const visualization_msgs::Marker::ConstPtr& buffer)
{
	radar_markers = *buffer;
}

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
// Server parameters
geometry_msgs::Point offset;

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

	ros::init(argc, argv, std::string("radar_SRR2_align"));

	ros::NodeHandle n;

	// Subscriber global reference obstacle data  
	ros::Subscriber subData = n.subscribe(std::string("/radar_SRR2_data_extraction"), 1, obstacleDataCallback);

	ros::Subscriber sub_can_rx = n.subscribe(std::string("/can_rx"), 1, canrxCallback);

	ros::Subscriber sub_srr_debug3             = n.subscribe(std::string("/parsed_tx/srr_debug3")            , 1, srrdebug3Callback);
	ros::Subscriber sub_srr_debug4             = n.subscribe(std::string("/parsed_tx/srr_debug4")            , 1, srrdebug4Callback);
	ros::Subscriber sub_srr_debug5             = n.subscribe(std::string("/parsed_tx/srr_debug5")            , 1, srrdebug5Callback);
	ros::Subscriber sub_srr_feature_alert      = n.subscribe(std::string("/parsed_tx/srr_feature_alert")     , 1, srrfeaturealertCallback);
	ros::Subscriber sub_srr_feature_sw_version = n.subscribe(std::string("/parsed_tx/srr_feature_sw_version"), 1, srrfeatureswversionCallback);
	ros::Subscriber sub_srr_status1            = n.subscribe(std::string("/parsed_tx/srr_status1")           , 1, srrstatus1Callback);
	ros::Subscriber sub_srr_status2            = n.subscribe(std::string("/parsed_tx/srr_status2")           , 1, srrstatus2Callback);
	ros::Subscriber sub_srr_status3            = n.subscribe(std::string("/parsed_tx/srr_status3")           , 1, srrstatus3Callback);
	ros::Subscriber sub_srr_status4            = n.subscribe(std::string("/parsed_tx/srr_status4")           , 1, srrstatus4Callback);
	ros::Subscriber sub_srr_status5            = n.subscribe(std::string("/parsed_tx/srr_status5")           , 1, srrstatus5Callback);
	ros::Subscriber sub_srr_track              = n.subscribe(std::string("/parsed_tx/srr_track")             , 1, srrtrackCallback);

	ros::Subscriber sub_detections = n.subscribe(std::string("/as_tx/detections"), 1, detectionsCallback);

	ros::Subscriber sub_radar_markers = n.subscribe(std::string("/as_tx/radar_markers"), 1, radarmarkersCallback);

	// Raport publisher with relative positions for the objects with the car
	ros::Publisher pubRaport = n.advertise<project_s_msgs::ObstacleAlignmentReport>(std::string("/radar_SRR2_obstacles_align_data"), 1);

	ros::Rate loop_rate(1000);

	if (n.hasParam("/ESR_2_5/offset_x"))
		n.getParam("/ESR_2_5/offset_x", offset.x);
	if (n.hasParam("/ESR_2_5/offset_y"))
		n.getParam("/ESR_2_5/offset_y", offset.y);
	if (n.hasParam("/ESR_2_5/offset_z"))
		n.getParam("/ESR_2_5/offset_z", offset.z);

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
