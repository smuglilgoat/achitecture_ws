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
#include <sensor_msgs/Range.h>

//DBW
#include <can_msgs/Frame.h>
#include <dbw_mkz_msgs/AmbientLight.h>
#include <dbw_mkz_msgs/BrakeCmd.h>
#include <dbw_mkz_msgs/BrakeInfoReport.h>
#include <dbw_mkz_msgs/BrakeReport.h>
#include <dbw_mkz_msgs/FuelLevelReport.h>
#include <dbw_mkz_msgs/Gear.h>
#include <dbw_mkz_msgs/GearCmd.h>
#include <dbw_mkz_msgs/GearReject.h>
#include <dbw_mkz_msgs/GearReport.h>
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

//message_project_s
//#include<message_project_s/sonarreport.h>

//#include <sound_play/sound_play.h>
#include <unistd.h>

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
dbw_mkz_msgs::SurroundReport surround_report;
dbw_mkz_msgs::GearReport gear_report;
//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
//message_project_s::sonarreport sonar_data_report;
sensor_msgs::Range sonar_data;


//-------------------------------------------------------------------------------------------------
// local CallBack
//-------------------------------------------------------------------------------------------------

bool received_gear_report=false;
void GearReportCallback(const dbw_mkz_msgs::GearReport::ConstPtr& buffer)
{
	gear_report = *buffer;
        received_gear_report=true;
        
}


bool received_surround_report=false;
void SurroundReportCallback(const dbw_mkz_msgs::SurroundReport::ConstPtr& buffer)
{
	surround_report = *buffer;
        received_surround_report=true;
        
}
//test
void sleepok(float t, ros::NodeHandle &n)
{
	if (n.ok())
	usleep(t*1000000);
}


//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{	
	ros::init(argc, argv, std::string("sonar_data"));

	ros::NodeHandle n;

//-------------------------------------------------------------------------------------------------
// Subscribers
//-------------------------------------------------------------------------------------------------
	ros::Subscriber sub_surroundreport = n.subscribe(std::string("/surround_report"), 1, SurroundReportCallback);	 	
	ros::Subscriber sub_gearreport     = n.subscribe(std::string("/gear_report"), 1, GearReportCallback);
//-------------------------------------------------------------------------------------------------
// Publisher
//-------------------------------------------------------------------------------------------------
ros::Publisher pub_surroundreport_rearleftcorner = n.advertise<sensor_msgs::Range>(std::string("/sonar_data_rearleftcorner"), 1);
ros::Publisher pub_surroundreport_rearleftcenter = n.advertise<sensor_msgs::Range>(std::string("/sonar_data_rearleftcenter"), 1);
ros::Publisher pub_surroundreport_rearrightcenter = n.advertise<sensor_msgs::Range>(std::string("/sonar_data_rearrightcenter"), 1);
ros::Publisher pub_surroundreport_rearrightcorner = n.advertise<sensor_msgs::Range>(std::string("/sonar_data_rearrightcorner"), 1);

	ros::Rate loop_rate(10);

//	sound_play::SoundClient sc;

	const char *str2 = "/home/dev/Documents/Beep/beep-02.wav";
	const char *strrev = "/home/dev/Documents/Beep/rev.wav";
	const char *strdrive = "/home/dev/Documents/Beep/drive.wav";

	float range_RL_center, range_RL_corner, range_RR_center, range_RR_corner; 
 
        while(n.ok())
	
	{
		ros::spinOnce();

		if(received_surround_report)

		{
			std::cout<<"Sonar Data Available:   ";

			for (int i = 7; i < 11; i++)
			{
				std::cout<<surround_report.sonar[i]<<"  ";
			
				// SONAR REAR LEFT CORNER = 7
				if(i == 7)
				{

					sonar_data.header.frame_id = "/sonar_rearleftcorner";

					sonar_data.radiation_type = sensor_msgs::Range::ULTRASOUND;

					sonar_data.field_of_view = 5;

					sonar_data.min_range = 0.2;

					sonar_data.max_range = 2.39;

					sonar_data.range = surround_report.sonar[7];

					range_RL_corner = sonar_data.range;

					pub_surroundreport_rearleftcorner.publish(sonar_data);
				}

				// SONAR REAR LEFT CENTER = 8
				else if(i == 8)
				{

					sonar_data.header.frame_id = "/sonar_rearleftcenter";

					sonar_data.radiation_type = sensor_msgs::Range::ULTRASOUND;

					sonar_data.field_of_view = 5;

					sonar_data.min_range = 0.2;

					sonar_data.max_range = 2.39;

					sonar_data.range = surround_report.sonar[8];

					range_RL_center = sonar_data.range;

					pub_surroundreport_rearleftcenter.publish(sonar_data);

				}

				// SONAR REAR RIGHT CENTER = 9
				else if(i == 9)
				{

					sonar_data.header.frame_id = "/sonar_rearrightcenter";

					sonar_data.radiation_type = sensor_msgs::Range::ULTRASOUND;

					sonar_data.field_of_view = 5;

					sonar_data.min_range = 0.2;

					sonar_data.max_range = 2.39;

					sonar_data.range = surround_report.sonar[9];

					range_RR_center = sonar_data.range;

					pub_surroundreport_rearrightcenter.publish(sonar_data);

				}

				// SONAR REAR RIGHT CORNER = 10
				else if(i == 10)
				{

					sonar_data.header.frame_id = "/sonar_rearrightcorner";

					sonar_data.radiation_type = sensor_msgs::Range::ULTRASOUND;

					sonar_data.field_of_view = 5;

					sonar_data.min_range = 0.2;

					sonar_data.max_range = 2.39;

					range_RR_corner = sonar_data.range;

					sonar_data.range = surround_report.sonar[10];


					pub_surroundreport_rearrightcorner.publish(sonar_data);

				}
					
			}
			std::cout<<std::endl;
/*
			// If Reverse Gear
			if(received_gear_report)

			{
				if(gear_report.cmd.gear == 2)
				{
					sc.startWave(strrev);
					sleepok(2, n);
					sc.stopWave(strrev);
				}
				else if(gear_report.cmd.gear == 4)
				{
					sc.startWave(strdrive);
					sleepok(2, n);
					sc.stopWave(strdrive);
				}
				received_gear_report=false; 
			}
		

if((gear_report.state.gear == 2) && ((range_RL_center <= 0.4) || (range_RL_corner <= 0.4) || (range_RR_center <= 0.4) || (range_RR_corner <= 0.4)))
{
	//case: Obstacle Close 
	sc.startWave(str2);
	sleepok(0.2, n);
	sc.stopWave(str2);
}

else if((gear_report.state.gear == 2) && ((range_RL_center > 0.4 && range_RL_center <= 1) || (range_RL_corner > 0.4 && range_RL_corner <= 1) || (range_RR_center > 0.4 && range_RR_center <= 1) ||  (range_RR_corner > 0.4 && range_RR_corner <= 1)))
{
	//case: Obstacle Close 
	sc.startWave(str2);
	sleepok(0.5, n);
	sc.stopWave(str2);
}

else if((gear_report.state.gear == 2) && (range_RL_center >= 2.0 && range_RL_corner >= 2.0 && range_RR_center >= 2.0 && range_RR_corner >= 2.0))
{
	//case: Obstacle Far
	sc.startWave(str2);
	sleepok(1.5, n);
	sc.stopWave(str2);
}

else if(gear_report.state.gear == 2)
{
	//case: Obstacle Intermediate
	sc.startWave(str2);
	sleepok(1, n);
	sc.stopWave(str2);
}

*/				
		received_surround_report=false; 
			
	      	}
				
	loop_rate.sleep();

   	}

    return 0;

}


