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

#include <can_msgs/Frame.h>

#include <delphi_esr_msgs/EsrStatus1.h>
#include <delphi_esr_msgs/EsrStatus2.h>
#include <delphi_esr_msgs/EsrStatus3.h>
#include <delphi_esr_msgs/EsrStatus4.h>
#include <delphi_esr_msgs/EsrStatus5.h>
#include <delphi_esr_msgs/EsrStatus6.h>
#include <delphi_esr_msgs/EsrStatus7.h>
#include <delphi_esr_msgs/EsrStatus8.h>
#include <delphi_esr_msgs/EsrStatus9.h>

#include <delphi_esr_msgs/EsrValid1.h>
#include <delphi_esr_msgs/EsrValid2.h>
#include <delphi_esr_msgs/EsrTrack.h>
#include <delphi_esr_msgs/EsrTrackMotionPower.h>
//#include <perception_msgs/ObjectWithCovarianceArray.h>
#include <radar_msgs/RadarStatus.h>
#include <radar_msgs/RadarErrorStatus.h>
#include <radar_msgs/RadarTrackArray.h>
#include <visualization_msgs/Marker.h>

#include <delphi_esr_msgs/EsrVehicle1.h>
#include <delphi_esr_msgs/EsrVehicle2.h>
#include <delphi_esr_msgs/EsrVehicle3.h>
#include <delphi_esr_msgs/EsrVehicle4.h>
#include <delphi_esr_msgs/EsrVehicle5.h>
#include <geometry_msgs/TwistStamped.h>

// Server parameters
geometry_msgs::Point offset;

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport extractedObstacle;

can_msgs::Frame can_rx;

delphi_esr_msgs::EsrStatus1 radarstatus1;
delphi_esr_msgs::EsrStatus2 radarstatus2;
delphi_esr_msgs::EsrStatus3 radarstatus3;
delphi_esr_msgs::EsrStatus4 radarstatus4;
delphi_esr_msgs::EsrStatus5 radarstatus5;
delphi_esr_msgs::EsrStatus6 radarstatus6;
delphi_esr_msgs::EsrStatus7 radarstatus7;
delphi_esr_msgs::EsrStatus8 radarstatus8;
delphi_esr_msgs::EsrStatus9 radarstatus9;

delphi_esr_msgs::EsrValid1 radarvalid1;
delphi_esr_msgs::EsrValid2 radarvalid2;
delphi_esr_msgs::EsrTrack radartrack;
delphi_esr_msgs::EsrTrackMotionPower trackmotionpower;
//perception_msgs::ObjectWithCovarianceArray objects;
radar_msgs::RadarStatus radar_status;
radar_msgs::RadarErrorStatus radar_error_status;
radar_msgs::RadarTrackArray radar_tracks;
visualization_msgs::Marker radar_markers;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleAlignmentReport reportObstacle;

//-------------------------------------------------------------------------------------------------
// local CallBack
//-------------------------------------------------------------------------------------------------
bool received = false;
void obstacleDataCallback(const project_s_msgs::ObstacleReport::ConstPtr& genericSmartData)
{
	extractedObstacle = *genericSmartData;

	received = true;
}

bool received_can_rx = false;
void canrxDataCallback(const can_msgs::Frame::ConstPtr& buffer)
{
	can_rx = *buffer;

	received_can_rx = true;
}

void radarstatus1DataCallback(const delphi_esr_msgs::EsrStatus1::ConstPtr& buffer)
{
	radarstatus1 = *buffer;
}

void radarstatus2DataCallback(const delphi_esr_msgs::EsrStatus2::ConstPtr& buffer)
{
	radarstatus2 = *buffer;
}

void radarstatus3DataCallback(const delphi_esr_msgs::EsrStatus3::ConstPtr& buffer)
{
	radarstatus3 = *buffer;
}

void radarstatus4DataCallback(const delphi_esr_msgs::EsrStatus4::ConstPtr& buffer)
{
	radarstatus4 = *buffer;
}

void radarstatus5DataCallback(const delphi_esr_msgs::EsrStatus5::ConstPtr& buffer)
{
	radarstatus5 = *buffer;
}

void radarstatus6DataCallback(const delphi_esr_msgs::EsrStatus6::ConstPtr& buffer)
{
	radarstatus6 = *buffer;
}

void radarstatus7DataCallback(const delphi_esr_msgs::EsrStatus7::ConstPtr& buffer)
{
	radarstatus7 = *buffer;
}

void radarstatus8DataCallback(const delphi_esr_msgs::EsrStatus8::ConstPtr& buffer)
{
	radarstatus8 = *buffer;
}

void radarstatus9DataCallback(const delphi_esr_msgs::EsrStatus9::ConstPtr& buffer)
{
	radarstatus9 = *buffer;
}

void radarvalid1DataCallback(const delphi_esr_msgs::EsrValid1::ConstPtr& buffer)
{
	radarvalid1 = *buffer;
}

void radarvalid2DataCallback(const delphi_esr_msgs::EsrValid2::ConstPtr& buffer)
{
	radarvalid2 = *buffer;
}

void radartrackDataCallback(const delphi_esr_msgs::EsrTrack::ConstPtr& buffer)
{
	radartrack = *buffer;
}

void trackmotionpowerDataCallback(const delphi_esr_msgs::EsrTrackMotionPower::ConstPtr& buffer)
{
	trackmotionpower = *buffer;
}

//void objectsDataCallback(const perception_msgs::ObjectWithCovarianceArray::ConstPtr& buffer)
//{
//	objects = *buffer;
//}

void radarstatusDataCallback(const radar_msgs::RadarStatus::ConstPtr& buffer)
{
	radar_status = *buffer;
}

void radarerrorstatuDataCallback(const radar_msgs::RadarErrorStatus::ConstPtr& buffer)
{
	radar_error_status = *buffer;
}

void radartracksDataCallback(const radar_msgs::RadarTrackArray::ConstPtr& buffer)
{
	radar_tracks = *buffer;
}

void radarmarkersDataCallback(const visualization_msgs::Marker::ConstPtr& buffer)
{
	radar_markers = *buffer;
}

//-------------------------------------------------------------------------------------------------
// local functions
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

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("radar_ESR_align"));

	ros::NodeHandle n;

	// Subscriber global reference obstacle data  
	ros::Subscriber subData = n.subscribe(std::string("/radar_ESR_data_extraction"), 1, obstacleDataCallback);

	ros::Subscriber sub_radarstatus1 = n.subscribe(std::string("/parsed_tx/radarstatus1"), 1, radarstatus1DataCallback);
	ros::Subscriber sub_radarstatus2 = n.subscribe(std::string("/parsed_tx/radarstatus2"), 1, radarstatus2DataCallback);
	ros::Subscriber sub_radarstatus3 = n.subscribe(std::string("/parsed_tx/radarstatus3"), 1, radarstatus3DataCallback);
	ros::Subscriber sub_radarstatus4 = n.subscribe(std::string("/parsed_tx/radarstatus4"), 1, radarstatus4DataCallback);
	ros::Subscriber sub_radarstatus5 = n.subscribe(std::string("/parsed_tx/radarstatus5"), 1, radarstatus5DataCallback);
	ros::Subscriber sub_radarstatus6 = n.subscribe(std::string("/parsed_tx/radarstatus6"), 1, radarstatus6DataCallback);
	ros::Subscriber sub_radarstatus7 = n.subscribe(std::string("/parsed_tx/radarstatus7"), 1, radarstatus7DataCallback);
	ros::Subscriber sub_radarstatus8 = n.subscribe(std::string("/parsed_tx/radarstatus8"), 1, radarstatus8DataCallback);
	ros::Subscriber sub_radarstatus9 = n.subscribe(std::string("/parsed_tx/radarstatus9"), 1, radarstatus9DataCallback);

	ros::Subscriber sub_radarvalid1        = n.subscribe(std::string("/parsed_tx/radarvalid1"),      1, radarvalid1DataCallback);
	ros::Subscriber sub_radarvalid2        = n.subscribe(std::string("/parsed_tx/radarvalid2"),      1, radarvalid2DataCallback);
	ros::Subscriber sub_radartrack         = n.subscribe(std::string("/parsed_tx/radartrack"),       1, radartrackDataCallback);
	ros::Subscriber sub_trackmotionpower   = n.subscribe(std::string("/parsed_tx/trackmotionpower"), 1, trackmotionpowerDataCallback);
	//ros::Subscriber sub_objects          = n.subscribe(std::string("/as_tx/objects"),              1, objectsDataCallback);
	ros::Subscriber sub_radar_status       = n.subscribe(std::string("/as_tx/radar_status"),         1, radarstatusDataCallback);
	ros::Subscriber sub_radar_error_status = n.subscribe(std::string("/as_tx/radar_error_status"),   1, radarerrorstatuDataCallback);
	ros::Subscriber sub_radar_tracks       = n.subscribe(std::string("/as_tx/radar_tracks"),         1, radartracksDataCallback);
	ros::Subscriber sub_radar_markers      = n.subscribe(std::string("/as_tx/radar_markers"),        1, radarmarkersDataCallback);

	// Raport publisher with relative positions for the objects with the car
	ros::Publisher pubRaport = n.advertise<project_s_msgs::ObstacleAlignmentReport>(std::string("/radar_ESR_obstacles_align_data"), 1);

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
			}

			pubRaport.publish(reportObstacle);
		}
		
		loop_rate.sleep();
	}

	return 0;
}
