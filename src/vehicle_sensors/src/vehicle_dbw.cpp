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
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include "ros/ros.h"
#include <tf/transform_broadcaster.h>
#include "visualization_msgs/Marker.h"
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TwistStamped.h>
#include <sensor_msgs/Imu.h>

//project_s_msgs
#include<project_s_msgs/EgoData.h>
#include<project_s_msgs/EgoDataReport.h>

//DBW
#include <can_msgs/Frame.h>
#include <dbw_mkz_msgs/AmbientLight.h>
#include <dbw_mkz_msgs/BrakeCmd.h>
#include <dbw_mkz_msgs/BrakeInfoReport.h>
#include <dbw_mkz_msgs/BrakeReport.h>
//#include <dbw_mkz_msgs/DriverAssistReport.h>
#include <dbw_mkz_msgs/FuelLevelReport.h>
#include <dbw_mkz_msgs/Gear.h>
#include <dbw_mkz_msgs/GearCmd.h>
#include <dbw_mkz_msgs/GearReject.h>
#include <dbw_mkz_msgs/HillStartAssist.h>
#include <dbw_mkz_msgs/Misc1Report.h>
#include <dbw_mkz_msgs/ParkingBrake.h>
#include <dbw_mkz_msgs/SteeringCmd.h>
#include <dbw_mkz_msgs/SteeringReport.h>
#include <dbw_mkz_msgs/SurroundReport.h>
#include <dbw_mkz_msgs/ThrottleCmd.h>
#include <dbw_mkz_msgs/ThrottleInfoReport.h>
#include <dbw_mkz_msgs/ThrottleReport.h>
#include <dbw_mkz_msgs/TirePressureReport.h>
#include <dbw_mkz_msgs/TurnSignal.h>
#include <dbw_mkz_msgs/TurnSignalCmd.h>
#include <dbw_mkz_msgs/TwistCmd.h>
#include <dbw_mkz_msgs/WatchdogCounter.h>
#include <dbw_mkz_msgs/WheelPositionReport.h>
#include <dbw_mkz_msgs/WheelSpeedReport.h>
#include <dbw_mkz_msgs/Wiper.h>

//NOVATEL

#include <novatel_gps_msgs/Gpgga.h>
#include <novatel_gps_msgs/Gpgsa.h>
#include <novatel_gps_msgs/Gpgsv.h>
#include <novatel_gps_msgs/Gprmc.h>
#include <novatel_gps_msgs/Inscov.h>
#include <novatel_gps_msgs/Inspva.h>
#include <novatel_gps_msgs/Inspvax.h>
#include <novatel_gps_msgs/Insstdev.h>
#include <novatel_gps_msgs/NovatelCorrectedImuData.h>
#include <novatel_gps_msgs/NovatelExtendedSolutionStatus.h>
#include <novatel_gps_msgs/NovatelMessageHeader.h>
#include <novatel_gps_msgs/NovatelPosition.h>
#include <novatel_gps_msgs/NovatelReceiverStatus.h>
#include <novatel_gps_msgs/NovatelSignalMask.h>
#include <novatel_gps_msgs/NovatelUtmPosition.h>
#include <novatel_gps_msgs/NovatelVelocity.h>
#include <novatel_gps_msgs/Range.h>
#include <novatel_gps_msgs/RangeInformation.h>
#include <novatel_gps_msgs/Satellite.h>
#include <novatel_gps_msgs/Time.h>
#include <novatel_gps_msgs/Trackstat.h>
#include <novatel_gps_msgs/TrackstatChannel.h>


//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
dbw_mkz_msgs::SteeringReport steering_report;
sensor_msgs::Imu imu_data;
novatel_gps_msgs::Inspva inspva; 


//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------

project_s_msgs::EgoData vehicle_egodata;
project_s_msgs::EgoDataReport vehicle_egodatareport ;



//-------------------------------------------------------------------------------------------------
// local CallBack
//-------------------------------------------------------------------------------------------------

bool received_inspva = false;
void InspvaDataCallback(const novatel_gps_msgs::Inspva::ConstPtr& buffer)
{
	inspva = *buffer;
	received_inspva = true;
}

bool received_steering_report=false;
void SteeringReportCallback(const dbw_mkz_msgs::SteeringReport::ConstPtr& buffer)
{
	steering_report = *buffer;
        received_steering_report=true;
        
}

bool received_imu_data_raw=false;
void ImuDataRawCallback(const sensor_msgs::Imu::ConstPtr& buffer)
{
	imu_data = *buffer;
        received_imu_data_raw=true;
        
}


//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	
	ros::init(argc, argv, std::string("vehicle_ego_data_report"));

	ros::NodeHandle n;

   
//-------------------------------------------------------------------------------------------------
// Subscribers
//-------------------------------------------------------------------------------------------------
     
	ros::Subscriber sub_inspva = n.subscribe(std::string("/inspva"), 1, InspvaDataCallback);
	ros::Subscriber sub_steeringreport = n.subscribe(std::string("/steering_report"), 1, SteeringReportCallback);	 
	ros::Subscriber sub_imudataraw = n.subscribe(std::string("/imu/data_raw"), 1, ImuDataRawCallback);	


//-------------------------------------------------------------------------------------------------
// Publisher
//-------------------------------------------------------------------------------------------------

	ros::Publisher pub_vehicle_egodatareport = n.advertise<project_s_msgs::EgoDataReport>(std::string("/ego_data"), 1);
	
	ros::Rate loop_rate(20);
        int i = 0;
	int siz=project_s_msgs::EgoDataReport::NBR_MAX_EGO_DATA;

        while(n.ok())
	
	{
		ros::spinOnce();

		if(received_steering_report && received_inspva && ImuDataRawCallback)

		{
			

			for (int k = i; k >= 1; k--)
			{
					vehicle_egodatareport.EgoData[k] =  vehicle_egodatareport.EgoData[k - 1];
			}

			//Stamp - For the report
			vehicle_egodatareport.header.stamp = steering_report.header.stamp ;
			
			//Stamp - From Steering Report
			vehicle_egodatareport.EgoData[0].stamp =  steering_report.header.stamp;
   			
			//Velocity
			vehicle_egodatareport.EgoData[0].velocity.linear.x =  steering_report.speed;

			//Velocity-Angular
			vehicle_egodatareport.EgoData[0].velocity.angular.x =  imu_data.angular_velocity.x;
			
			vehicle_egodatareport.EgoData[0].velocity.angular.y =  imu_data.angular_velocity.y;
		
			vehicle_egodatareport.EgoData[0].velocity.angular.z =  imu_data.angular_velocity.z;

			//Acceleration			
			vehicle_egodatareport.EgoData[0].acceleration.linear.x =  imu_data.linear_acceleration.x;
			
			vehicle_egodatareport.EgoData[0].acceleration.linear.y =  imu_data.linear_acceleration.y;
			
			vehicle_egodatareport.EgoData[0].acceleration.linear.z =  imu_data.linear_acceleration.z;
			
			//Novatel - Latitude, Longitude and Cap
			vehicle_egodatareport.EgoData[0].latitude =  inspva.latitude;
			
			vehicle_egodatareport.EgoData[0].longitude =  inspva.longitude;
			
			vehicle_egodatareport.EgoData[0].cap =  inspva.azimuth;


			if (i < siz-1)
			{			
				i++;
			}
				

			//PUBLISH
				
			pub_vehicle_egodatareport.publish(vehicle_egodatareport);

			
			received_inspva=false;
			received_steering_report=false;
			received_imu_data_raw=false;

	      	}
				
	loop_rate.sleep();

   	}

    return 0;

}

