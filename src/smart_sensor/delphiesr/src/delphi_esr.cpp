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
#include "ros/ros.h"
#include <tf/transform_broadcaster.h>
#include "visualization_msgs/Marker.h"

//message_project_s
#include<message_project_s/ObstacleAlignmentReport_1.h>
#include<message_project_s/ObstacleAlignment_1.h>

//Delphi_ESR
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
#include <radar_msgs/RadarStatus.h>
#include <radar_msgs/RadarErrorStatus.h>
#include <radar_msgs/RadarTrackArray.h>
#include <visualization_msgs/Marker.h>
#include <derived_object_msgs/ObjectWithCovarianceArray.h>

// Offsets 

geometry_msgs::Point offset_esr;
geometry_msgs::Point euler_esr;

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------

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
derived_object_msgs::ObjectWithCovarianceArray objects;
radar_msgs::RadarStatus radar_status;
radar_msgs::RadarErrorStatus radar_error_status;
radar_msgs::RadarTrackArray radar_tracks;
visualization_msgs::Marker radar_markers;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------

message_project_s::ObstacleAlignmentReport_1 localAlignmentReport_esr;
message_project_s::ObstacleAlignment_1 tempObstacleAlignment_esr;


//-------------------------------------------------------------------------------------------------
// local CallBack
//-------------------------------------------------------------------------------------------------


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

void objectsDataCallback(const derived_object_msgs::ObjectWithCovarianceArray::ConstPtr& buffer)
{
	objects = *buffer;
}

void radarstatusDataCallback(const radar_msgs::RadarStatus::ConstPtr& buffer)
{
	radar_status = *buffer;
}

void radarerrorstatuDataCallback(const radar_msgs::RadarErrorStatus::ConstPtr& buffer)
{
	radar_error_status = *buffer;
}

bool received_radar_tracks=false;
void radartracksDataCallback(const radar_msgs::RadarTrackArray::ConstPtr& buffer)
{
	radar_tracks = *buffer;
        received_radar_tracks=true;
        
}

void radarmarkersDataCallback(const visualization_msgs::Marker::ConstPtr& buffer)
{
	radar_markers = *buffer;
}


//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	
	ros::init(argc, argv, std::string("delphi_esr_node"));

	ros::NodeHandle n;
   
//-------------------------------------------------------------------------------------------------
// Subscribers
//-------------------------------------------------------------------------------------------------
     
	ros::Subscriber sub_can_rx = n.subscribe(std::string("/esr_1/can_rx"), 1, canrxDataCallback);
	ros::Subscriber sub_radarstatus1 = n.subscribe(std::string("/esr_1/parsed_tx/radarstatus1"), 1, radarstatus1DataCallback);
	ros::Subscriber sub_radarstatus2 = n.subscribe(std::string("/esr_1/parsed_tx/radarstatus2"), 1, radarstatus2DataCallback);
	ros::Subscriber sub_radarstatus3 = n.subscribe(std::string("/esr_1/parsed_tx/radarstatus3"), 1, radarstatus3DataCallback);
	ros::Subscriber sub_radarstatus4 = n.subscribe(std::string("/esr_1/parsed_tx/radarstatus4"), 1, radarstatus4DataCallback);
	ros::Subscriber sub_radarstatus5 = n.subscribe(std::string("/esr_1/parsed_tx/radarstatus5"), 1, radarstatus5DataCallback);
	ros::Subscriber sub_radarstatus6 = n.subscribe(std::string("/esr_1/parsed_tx/radarstatus6"), 1, radarstatus6DataCallback);
	ros::Subscriber sub_radarstatus7 = n.subscribe(std::string("/esr_1/parsed_tx/radarstatus7"), 1, radarstatus7DataCallback);
	ros::Subscriber sub_radarstatus8 = n.subscribe(std::string("/esr_1/parsed_tx/radarstatus8"), 1, radarstatus8DataCallback);
	ros::Subscriber sub_radarstatus9 = n.subscribe(std::string("/esr_1/parsed_tx/radarstatus9"), 1, radarstatus9DataCallback);
	ros::Subscriber sub_radarvalid1  = n.subscribe(std::string("/esr_1/parsed_tx/radarvalid1"), 1, radarvalid1DataCallback);
	ros::Subscriber sub_radarvalid2  = n.subscribe(std::string("/esr_1/parsed_tx/radarvalid2"), 1, radarvalid2DataCallback);
	ros::Subscriber sub_radartrack   = n.subscribe(std::string("/esr_1/parsed_tx/radartrack"), 1, radartrackDataCallback);
	ros::Subscriber sub_trackmotionpower = n.subscribe(std::string("/esr_1/parsed_tx/trackmotionpower"), 1, trackmotionpowerDataCallback);
	ros::Subscriber sub_objects = n.subscribe(std::string("/esr_1/as_tx/objects"), 1, objectsDataCallback);
	ros::Subscriber sub_radar_status = n.subscribe(std::string("/esr_1/as_tx/radar_status"), 1, radarstatusDataCallback);
	ros::Subscriber sub_radar_error_status = n.subscribe(std::string("/esr_1/as_tx/radar_error_status"), 1, radarerrorstatuDataCallback);
	ros::Subscriber sub_radar_tracks = n.subscribe(std::string("/esr_1/as_tx/radar_tracks"), 1, radartracksDataCallback);
	ros::Subscriber sub_radar_markers = n.subscribe(std::string("/esr_1/as_tx/radar_markers"), 1, radarmarkersDataCallback); 	 

//-------------------------------------------------------------------------------------------------
// Publisher
//-------------------------------------------------------------------------------------------------

	ros::Publisher pubAlignedReport = n.advertise<message_project_s::ObstacleAlignmentReport_1>(std::string("/radar_ESR_obstacles_align_data"), 1);


//-------------------------------------------------------------------------------------------------
// Time Alignment
//-------------------------------------------------------------------------------------------------
	
	// It is the time shift between the sensor clock and ROS clock which we need to estimate in order to successfully implement TIME ALIGNMENT
	ros::Duration clk_offset_mean;

	// Latency is the duration between time at which environment is sampled by the sensor and the time at which processed data (derived from raw data sample) is received on the ROS machine. It is measured physically and set into the software. Ex: here its 0.001 
	ros::Duration Latency(0.001);

	// Intialize "begin" with the current ROS time which is required to compute the cycle_time
	ros::Time begin;
	begin = ros::Time::now();

	ros::Rate loop_rate(1000);

//-------------------------------------------------------------------------------------------------
// Spatial Alignment Offsets
//-------------------------------------------------------------------------------------------------

	if (n.hasParam("/ESR_2_5/offset_x"))
		n.getParam("/ESR_2_5/offset_x", offset_esr.x);
	if (n.hasParam("/ESR_2_5/offset_y"))
		n.getParam("/ESR_2_5/offset_y", offset_esr.y);
	if (n.hasParam("/ESR_2_5/offset_z"))
		n.getParam("/ESR_2_5/offset_z", offset_esr.z);

	if (n.hasParam("/ESR_2_5/yaw"))
		n.getParam("/ESR_2_5/yaw", euler_esr.x);
	if (n.hasParam("/ESR_2_5/pitch"))
		n.getParam("/ESR_2_5/pitch", euler_esr.y);
	if (n.hasParam("/ESR_2_5/roll"))
		n.getParam("/ESR_2_5/roll", euler_esr.z);

//-------------------------------------------------------------------------------------------------
//Declaration for Variance calculation 
//-------------------------------------------------------------------------------------------------

	double pos_x, pos_y; 
	double range, bearing, Er, Et, sigma_pos_x, sigma_pos_y, sigma_vel_x, sigma_vel_y, variance_pos_x, variance_pos_y, variance_vel_x, variance_vel_y ;
	const double PI = 3.141592653589793;

//-------------------------------------------------------------------------------------------------

        while(n.ok())
	
	{
		ros::spinOnce();


		if(received_radar_tracks)

		{

			// Initialize "current_time" with the current ROS machine time.Receive_time or time of data reception by ROS node
			ros::Time current_time = ros::Time::now();

			// Gives the cycle time 
			double cycle_time = (current_time - begin).toSec(); 

			//clk_offset represent the time_shift_raw: time_shift_raw = Receive_Time(ROS) - Sensor Timestamp - latency - Jitter
			double clk_offset  = (current_time - radar_tracks.header.stamp - Latency).toSec();

			// Implement 1st order low-pass filter (Exponential Filter / Smoothing). Gain K = Exp (-cycle_time/Time_constant). 
			double K = exp(-cycle_time/0.100);

			// Filter state output at time step (Ti) is given as: State(Ti) = K * State(Ti - 1) + (1 - K) * Input (Ti)
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_mean.toSec();

			// Here we obtain the time shift between the sensor and ROS clock
			clk_offset_mean = ros::Duration(clk_offset);

			// Final Aligned Timestamp 
			radar_tracks.header.stamp += clk_offset_mean;

			localAlignmentReport_esr.header=radar_tracks.header;

			std::cout<<"QTYObstacles Delphi-ESR: "<<radar_tracks.tracks.size()<<std::endl;

			//QTYObstacles
			localAlignmentReport_esr.QtyObstacles.data = radar_tracks.tracks.size();

			localAlignmentReport_esr.ObstacleAlignement_1.clear();

			           
             		for(int tidx=0;tidx<radar_tracks.tracks.size();tidx++)
              
              		{
	       			//std::cout<<radar_tracks.tracks[tidx].track_id<<"  ";
	   
			       	// fill obstacleAlignment.msg

			       	//Header
			       	tempObstacleAlignment_esr.header=radar_tracks.header;

			       	//Track ID
			       	tempObstacleAlignment_esr.id.data=radar_tracks.tracks[tidx].track_id;
				std::cout<<"ID : "<<radar_tracks.tracks[tidx].track_id<<std::endl;

			       	//---- Position-X and Y ------- 
				pos_x = (radar_tracks.tracks[tidx].track_shape.points[0].x);
				pos_y = (((radar_tracks.tracks[tidx].track_shape.points[0].y + radar_tracks.tracks[tidx].track_shape.points[1].y)/2)); 

				//Aligned position in report - add offset
			       	tempObstacleAlignment_esr.obstaclePosition.position.x = pos_x + offset_esr.x;
			       	tempObstacleAlignment_esr.obstaclePosition.position.y = pos_y + offset_esr.y;


//-----------------------------------------
				// Obstacle Center for Corner Computation
				tempObstacleAlignment_esr.obstacleBodyCenter.position.x = pos_x + offset_esr.x;
		       		tempObstacleAlignment_esr.obstacleBodyCenter.position.y = pos_y + offset_esr.y;
//-----------------------------------------

				//range and bearing calculation for std. dev.				
				
				range = sqrt(pow(pos_x,2) + pow(pos_y,2));

				std::cout<<"pos_x: "<<pos_x<<std::endl;
				std::cout<<"pos_y: "<<pos_y<<std::endl;
				std::cout<<"range: "<<range<<std::endl;
 
				bearing = atan(pos_y/pos_x); 
				std::cout<<"bearing: "<<bearing<<std::endl;

				if(range <= 25)
				{
				  Er = 0.25;
				}
				else 
				{
				  Er = 0.5;	
				}

				if(range <= 10)
				{
				  Et = 2*(PI/180);
				}

				else if(range>10 && range<25)
				{
				  Et = 1*(PI/180);
				}

				else if(range >= 25)
				{
				  Et = 0.5*(PI/180);;
				}


				std::cout<<"Er: "<<Er<<std::endl;
				std::cout<<"Et: "<<Et<<std::endl;

				//Computing the Standard Deviation - Position - X and Y
				sigma_pos_x = (1.0/3.0)*(fabs(cos(bearing))*Er + range*fabs(sin(bearing))*Et);

				sigma_pos_y = (1.0/3.0)*(fabs(sin(bearing))*Er + range*fabs(cos(bearing))*Et);

				//variance position
				variance_pos_x = pow(sigma_pos_x, 2);
				variance_pos_y = pow(sigma_pos_y, 2);

				//Computing the Standard Deviation - Velocity - X and Y
				sigma_vel_x = 0.05;
				sigma_vel_y = 15;

				//variance velocity
				variance_vel_x = pow(sigma_vel_x, 2);
				variance_vel_y = pow(sigma_vel_y, 2);

				std::cout<<"sigma_vel_x: "<<sigma_vel_x<<std::endl;
				std::cout<<"sigma_vel_y: "<<sigma_vel_y<<std::endl;
				std::cout<<"---------------------------------------"<<std::endl;

			       	//Velocity-X and Y 
			       	tempObstacleAlignment_esr.obstacleVelocity.linear.x=radar_tracks.tracks[tidx].linear_velocity.x;
			       	tempObstacleAlignment_esr.obstacleVelocity.linear.y=radar_tracks.tracks[tidx].linear_velocity.y;

			       	//Acceleration-X
			       	tempObstacleAlignment_esr.obstacleAcceleration.linear.x=radar_tracks.tracks[tidx].linear_acceleration.x;



				//Position Variance - X and Y 
			       	tempObstacleAlignment_esr.obstaclePoseVariance.position.x = variance_pos_x;
			       	tempObstacleAlignment_esr.obstaclePoseVariance.position.y = variance_pos_y;


				//Relative Velocity Variance - X and Y
				tempObstacleAlignment_esr.obstacleRelativeVelocityVariance.linear.x = variance_vel_x;
				tempObstacleAlignment_esr.obstacleRelativeVelocityVariance.linear.y = variance_vel_y;



//-------------------------------------------------------------------------------------------------
// Info Unavailable 
//-------------------------------------------------------------------------------------------------

				//Relative Velocity-X 

				/*tempObstacleAlignment_esr.obstacleRelativeVelocity.linear.x = tempObstacleAlignment_esr.obstacleRelativeVelocity_linear_Unknown;
				tempObstacleAlignment_esr.obstacleRelativeVelocity.linear.y = tempObstacleAlignment_esr.obstacleRelativeVelocity_linear_Unknown;
				tempObstacleAlignment_esr.obstacleRelativeVelocity.linear.z = tempObstacleAlignment_esr.obstacleRelativeVelocity_linear_Unknown;
				tempObstacleAlignment_esr.obstacleRelativeVelocity.angular.x = tempObstacleAlignment_esr.obstacleRelativeVelocity_angular_Unknown;
				tempObstacleAlignment_esr.obstacleRelativeVelocity.angular.y = tempObstacleAlignment_esr.obstacleRelativeVelocity_angular_Unknown;
				tempObstacleAlignment_esr.obstacleRelativeVelocity.angular.z = tempObstacleAlignment_esr.obstacleRelativeVelocity_angular_Unknown;*/


				//Obstacle Dimension-Length and Width (meter)
				tempObstacleAlignment_esr.obstacleDimensions.x = tempObstacleAlignment_esr.obstacleDimensions_Unknown;
				tempObstacleAlignment_esr.obstacleDimensions.y = tempObstacleAlignment_esr.obstacleDimensions_Unknown;
				tempObstacleAlignment_esr.obstacleDimensions.z = tempObstacleAlignment_esr.obstacleDimensions_Unknown;

				//Blinker Status 
				tempObstacleAlignment_esr.blinkerInfo = tempObstacleAlignment_esr.blinkerInfo_Unknown;

				//Cut_in_and_out
				tempObstacleAlignment_esr.cutInAndOut = tempObstacleAlignment_esr.cutInAndOut_Unknown;

				//Obstacle Classification
				tempObstacleAlignment_esr.obstacleType  = tempObstacleAlignment_esr.obstacleType_Unknown;

				//Obstacle Status
				tempObstacleAlignment_esr.obstacleStatus  = tempObstacleAlignment_esr.obstacleStatus_Unknown;

				//Obstacle Brake Lights
				tempObstacleAlignment_esr.obstacleBrakeLights  = tempObstacleAlignment_esr.obstacleBrakeLights_Unknown;

				//Closest in Path Vehicle
				tempObstacleAlignment_esr.cipvFlag  = tempObstacleAlignment_esr.cipvFlag_Unknown;

				//Obstacle Replaced
				tempObstacleAlignment_esr.obstacleReplaced  = tempObstacleAlignment_esr.obstacleReplaced_Unknown;

				//Obstacle Valid
				tempObstacleAlignment_esr.obstacleValid  = tempObstacleAlignment_esr.obstacleValid_Unknown;

				//Obstacle Age
				tempObstacleAlignment_esr.obstacleAge  = tempObstacleAlignment_esr.obstacleAge_Unknown;

				//Obstacle Lane
				tempObstacleAlignment_esr.obstacleLane  = tempObstacleAlignment_esr.obstacleLane_Unknown;

				//Obstacle Angle 
				tempObstacleAlignment_esr.obstacleAngle  = tempObstacleAlignment_esr.obstacleAngle_Unknown;

				//Obstacle Angle Variance 
				tempObstacleAlignment_esr.obstacleAngleVariance = tempObstacleAlignment_esr.obstacleAngleVariance_Unknown;

				//Obstacle Angle Rate 
				tempObstacleAlignment_esr.obstacleAngleRate  = tempObstacleAlignment_esr.obstacleAngleRate_Unknown;

				//Obstacle Scale Change (pix/sec)
				tempObstacleAlignment_esr.obstacleScaleChange  = tempObstacleAlignment_esr.obstacleScaleChange_Unknown;

				//Traffic Sign Recognition (TSR) sign type   
				tempObstacleAlignment_esr.visionOnlySignType = tempObstacleAlignment_esr.visionOnlySignType_Unknown;

				//Supplementary sign type - rain, snow, arrow etc.
				tempObstacleAlignment_esr.visionOnlySupplementarySignType = tempObstacleAlignment_esr.visionOnlySupplementarySignType_Unknown;

				//Sign Position
				tempObstacleAlignment_esr.signPosition.x= tempObstacleAlignment_esr.signPosition_Unknown;
				tempObstacleAlignment_esr.signPosition.y= tempObstacleAlignment_esr.signPosition_Unknown;
				tempObstacleAlignment_esr.signPosition.z= tempObstacleAlignment_esr.signPosition_Unknown;

				//Filter
				tempObstacleAlignment_esr.filterType = tempObstacleAlignment_esr.filterType_Unknown;

/*				//Position Variance - X and Y 
			       	tempObstacleAlignment_esr.obstaclePoseVariance.position.x = tempObstacleAlignment_esr.obstaclePoseVariance_position_Unknown;
			       	tempObstacleAlignment_esr.obstaclePoseVariance.position.y = tempObstacleAlignment_esr.obstaclePoseVariance_position_Unknown;
				tempObstacleAlignment_esr.obstaclePoseVariance.position.z = tempObstacleAlignment_esr.obstaclePoseVariance_position_Unknown;

				tempObstacleAlignment_esr.obstaclePoseVariance.orientation.x = tempObstacleAlignment_esr.obstaclePoseVariance_orientation_Unknown;
				tempObstacleAlignment_esr.obstaclePoseVariance.orientation.y = tempObstacleAlignment_esr.obstaclePoseVariance_orientation_Unknown;
				tempObstacleAlignment_esr.obstaclePoseVariance.orientation.z = tempObstacleAlignment_esr.obstaclePoseVariance_orientation_Unknown;
				tempObstacleAlignment_esr.obstaclePoseVariance.orientation.w = tempObstacleAlignment_esr.obstaclePoseVariance_orientation_Unknown;

*/

				//Absolute Velocity Variance - X and Y
				tempObstacleAlignment_esr.obstacleVelocityVariance.linear.x = tempObstacleAlignment_esr.obstacleVelocityVariance_linear_Unknown;
				tempObstacleAlignment_esr.obstacleVelocityVariance.linear.y = tempObstacleAlignment_esr.obstacleVelocityVariance_linear_Unknown;
				tempObstacleAlignment_esr.obstacleVelocityVariance.linear.z = tempObstacleAlignment_esr.obstacleVelocityVariance_linear_Unknown;

				tempObstacleAlignment_esr.obstacleVelocityVariance.angular.x = tempObstacleAlignment_esr.obstacleVelocityVariance_angular_Unknown;
				tempObstacleAlignment_esr.obstacleVelocityVariance.angular.y = tempObstacleAlignment_esr.obstacleVelocityVariance_angular_Unknown;
				tempObstacleAlignment_esr.obstacleVelocityVariance.angular.z = tempObstacleAlignment_esr.obstacleVelocityVariance_angular_Unknown;

/*				//Relative Velocity Variance - X and Y
				tempObstacleAlignment_esr.obstacleRelativeVelocityVariance.linear.x = tempObstacleAlignment_esr.obstacleRelativeVelocityVariance_linear_Unknown;
				tempObstacleAlignment_esr.obstacleRelativeVelocityVariance.linear.y = tempObstacleAlignment_esr.obstacleRelativeVelocityVariance_linear_Unknown;
				tempObstacleAlignment_esr.obstacleRelativeVelocityVariance.linear.z = tempObstacleAlignment_esr.obstacleRelativeVelocityVariance_linear_Unknown;

				tempObstacleAlignment_esr.obstacleRelativeVelocityVariance.angular.x = tempObstacleAlignment_esr.obstacleRelativeVelocityVariance_angular_Unknown;
				tempObstacleAlignment_esr.obstacleRelativeVelocityVariance.angular.y = tempObstacleAlignment_esr.obstacleRelativeVelocityVariance_angular_Unknown;
				tempObstacleAlignment_esr.obstacleRelativeVelocityVariance.angular.z = tempObstacleAlignment_esr.obstacleRelativeVelocityVariance_angular_Unknown;

*/

				//Classification probability
			       	tempObstacleAlignment_esr.classificationProbability = tempObstacleAlignment_esr.classificationProbability_Unknown;

				//Ground Height
			       	tempObstacleAlignment_esr.groundHeight.data = tempObstacleAlignment_esr.groundHeight_Unknown;

				//Date Acquisition
			       	tempObstacleAlignment_esr.dateAcquisition.data = tempObstacleAlignment_esr.dateAcquisition_Unknown;
			       

			       	localAlignmentReport_esr.ObstacleAlignement_1.push_back(tempObstacleAlignment_esr);

			}

			std::cout<<std::endl;

			// Publish final aligned data topic
			pubAlignedReport.publish(localAlignmentReport_esr);
			received_radar_tracks=false;

      	}

	loop_rate.sleep();

   }

    return 0;

}

