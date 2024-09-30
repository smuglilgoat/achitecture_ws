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
#include <derived_object_msgs/ObjectWithCovarianceArray.h>
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

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport extractedObstacle;

can_msgs::Frame can_tx;

delphi_esr_msgs::EsrVehicle1 vehicle1_msgs;
delphi_esr_msgs::EsrVehicle2 vehicle2_msgs;
delphi_esr_msgs::EsrVehicle3 vehicle3_msgs;
delphi_esr_msgs::EsrVehicle4 vehicle4_msgs;
delphi_esr_msgs::EsrVehicle5 vehicle5_msgs;

geometry_msgs::TwistStamped vehicle_motion;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport reportObstacle;

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
derived_object_msgs::ObjectWithCovarianceArray objects;
radar_msgs::RadarStatus radar_status;
radar_msgs::RadarErrorStatus radar_error_status;
radar_msgs::RadarTrackArray radar_tracks;
visualization_msgs::Marker radar_markers;

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

void vehicle1Callback(const delphi_esr_msgs::EsrVehicle1::ConstPtr& buffer)
{
	vehicle1_msgs = *buffer;
}

void vehicle2Callback(const delphi_esr_msgs::EsrVehicle2::ConstPtr& buffer)
{
	vehicle2_msgs = *buffer;
}

void vehicle3Callback(const delphi_esr_msgs::EsrVehicle3::ConstPtr& buffer)
{
	vehicle3_msgs = *buffer;
}

void vehicle4Callback(const delphi_esr_msgs::EsrVehicle4::ConstPtr& buffer)
{
	vehicle4_msgs = *buffer;
}

void vehicle5Callback(const delphi_esr_msgs::EsrVehicle5::ConstPtr& buffer)
{
	vehicle5_msgs = *buffer;
}

void vehiclemotionCallback(const geometry_msgs::TwistStamped::ConstPtr& buffer)
{
	vehicle_motion = *buffer;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "radar_ESR_data_extraction");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher pub_obstacles = n.advertise<project_s_msgs::ObstacleReport>(std::string("/radar_ESR_data_extraction"), 1);

	ros::Publisher pub_can_rx = n.advertise<can_msgs::Frame>(std::string("/can_rx"), 1);

	ros::Publisher pub_radarstatus1 = n.advertise<delphi_esr_msgs::EsrStatus1>(std::string("/parsed_tx/radarstatus1"), 1);
	ros::Publisher pub_radarstatus2 = n.advertise<delphi_esr_msgs::EsrStatus2>(std::string("/parsed_tx/radarstatus2"), 1);
	ros::Publisher pub_radarstatus3 = n.advertise<delphi_esr_msgs::EsrStatus3>(std::string("/parsed_tx/radarstatus3"), 1);
	ros::Publisher pub_radarstatus4 = n.advertise<delphi_esr_msgs::EsrStatus4>(std::string("/parsed_tx/radarstatus4"), 1);
	ros::Publisher pub_radarstatus5 = n.advertise<delphi_esr_msgs::EsrStatus5>(std::string("/parsed_tx/radarstatus5"), 1);
	ros::Publisher pub_radarstatus6 = n.advertise<delphi_esr_msgs::EsrStatus6>(std::string("/parsed_tx/radarstatus6"), 1);
	ros::Publisher pub_radarstatus7 = n.advertise<delphi_esr_msgs::EsrStatus7>(std::string("/parsed_tx/radarstatus7"), 1);
	ros::Publisher pub_radarstatus8 = n.advertise<delphi_esr_msgs::EsrStatus8>(std::string("/parsed_tx/radarstatus8"), 1);
	ros::Publisher pub_radarstatus9 = n.advertise<delphi_esr_msgs::EsrStatus9>(std::string("/parsed_tx/radarstatus9"), 1);

	ros::Publisher pub_radarvalid1 = n.advertise<delphi_esr_msgs::EsrValid1>(std::string("/parsed_tx/radarvalid1"), 1);
	ros::Publisher pub_radarvalid2 = n.advertise<delphi_esr_msgs::EsrValid2>(std::string("/parsed_tx/radarvalid2"), 1);
	ros::Publisher pub_radartrack = n.advertise<delphi_esr_msgs::EsrTrack>(std::string("/parsed_tx/radartrack"), 1);
	ros::Publisher pub_trackmotionpower = n.advertise<delphi_esr_msgs::EsrTrackMotionPower>(std::string("/parsed_tx/trackmotionpower"), 1);
//	ros::Publisher pub_objects = n.advertise<perception_msgs::ObjectWithCovarianceArray>(std::string("/as_tx/objects"), 1);
	ros::Publisher pub_objects = n.advertise<derived_object_msgs::ObjectWithCovarianceArray>(std::string("/as_tx/objects"), 1);
	ros::Publisher pub_radar_status = n.advertise<radar_msgs::RadarStatus>(std::string("/as_tx/radar_status"), 1);
	ros::Publisher pub_radar_error_status = n.advertise<radar_msgs::RadarErrorStatus>(std::string("/as_tx/radar_error_status"), 1);
	ros::Publisher pub_radar_tracks = n.advertise<radar_msgs::RadarTrackArray>(std::string("/as_tx/radar_tracks"), 1);
	ros::Publisher pub_radar_markers = n.advertise<visualization_msgs::Marker>(std::string("/as_tx/radar_markers"), 1);

	// Subscriber
	ros::Subscriber subData = n.subscribe(std::string("/radar_ESR_obstacle"), 1, obstacleDataCallback);

	ros::Subscriber sub_can_tx = n.subscribe(std::string("/can_tx"), 1, cantxCallback);

	ros::Subscriber sub_vehicle1 = n.subscribe(std::string("/parsed_rx/vehicle1_msgs"), 1, vehicle1Callback);
	ros::Subscriber sub_vehicle2 = n.subscribe(std::string("/parsed_rx/vehicle2_msgs"), 1, vehicle2Callback);
	ros::Subscriber sub_vehicle3 = n.subscribe(std::string("/parsed_rx/vehicle3_msgs"), 1, vehicle3Callback);
	ros::Subscriber sub_vehicle4 = n.subscribe(std::string("/parsed_rx/vehicle4_msgs"), 1, vehicle4Callback);
	ros::Subscriber sub_vehicle5 = n.subscribe(std::string("/parsed_rx/vehicle5_msgs"), 1, vehicle5Callback);

	ros::Subscriber sub_vehicle_motion = n.subscribe(std::string("/as_rx/vehicle_motion"), 1, vehiclemotionCallback);

	ros::Rate loop_rate(1000);

  	while(n.ok())
	{
		ros::spinOnce();

		if(obstacleReceived)
		{
			obstacleReceived = false;

			reportObstacle = extractedObstacle;

			pub_obstacles.publish(reportObstacle);

			pub_can_rx.publish(can_rx);

			pub_radarstatus1.publish(radarstatus1);
			pub_radarstatus2.publish(radarstatus2);
			pub_radarstatus3.publish(radarstatus3);
			pub_radarstatus4.publish(radarstatus4);
			pub_radarstatus5.publish(radarstatus5);
			pub_radarstatus6.publish(radarstatus6);
			pub_radarstatus7.publish(radarstatus7);
			pub_radarstatus8.publish(radarstatus8);
			pub_radarstatus9.publish(radarstatus9);

			pub_radarvalid1.publish(radarvalid1);
			pub_radarvalid2.publish(radarvalid2);
			pub_radartrack.publish(radartrack);
			pub_trackmotionpower.publish(trackmotionpower);
			pub_objects.publish(objects);
			pub_radar_status.publish(radar_status);
			pub_radar_error_status.publish(radar_error_status);
			pub_radar_tracks.publish(radar_tracks);
			pub_radar_markers.publish(radar_markers);
		}

		loop_rate.sleep();
	}

	return 0;
}
