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

//Delphi_SRR_RF
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

can_msgs::Frame can_tx;
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
radar_msgs::RadarDetectionArray detections_rf;
visualization_msgs::Marker radar_markers;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------

message_project_s::ObstacleAlignmentReport_1 localAlignmentReport_srrrf;
message_project_s::ObstacleAlignment_1 tempObstacleAlignment_srrrf;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------

bool received_can_tx = false;
void cantxCallback(const can_msgs::Frame::ConstPtr& buffer)
{
	can_tx = *buffer;
        received_can_tx = true;
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

bool received_detections_rf=false;
void detectionsRFCallback(const radar_msgs::RadarDetectionArray::ConstPtr& buffer)
{
	detections_rf = *buffer;
        received_detections_rf=true;
}

void radarmarkersCallback(const visualization_msgs::Marker::ConstPtr& buffer)
{
	radar_markers = *buffer;
}


//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{ 

	ros::init(argc, argv, std::string("DelphiSRR_RF_node"));

	ros::NodeHandle n;

//-------------------------------------------------------------------------------------------------
// Subscribers
//-------------------------------------------------------------------------------------------------

	ros::Subscriber sub_can_tx = n.subscribe(std::string("/front_srr/can_tx"), 1, cantxCallback);
	ros::Subscriber sub_srr_debug3 = n.subscribe(std::string("/front_srr/front_right_srr/parsed_tx/srr_debug3") , 1, srrdebug3Callback);
	ros::Subscriber sub_srr_debug4 = n.subscribe(std::string("/front_srr/front_right_srr/parsed_tx/srr_debug4") , 1, srrdebug4Callback);
	ros::Subscriber sub_srr_debug5 = n.subscribe(std::string("/front_srr/front_right_srr/parsed_tx/srr_debug5") , 1, srrdebug5Callback);
	ros::Subscriber sub_srr_feature_alert = n.subscribe(std::string("/front_srr/front_right_srr/parsed_tx/srr_feature_alert") , 1, srrfeaturealertCallback);
	ros::Subscriber sub_srr_feature_sw_version = n.subscribe(std::string("/front_srr/front_right_srr/parsed_tx/srr_feature_sw_version"), 1, srrfeatureswversionCallback);
	ros::Subscriber sub_srr_status1 = n.subscribe(std::string("/front_srr/front_right_srr/parsed_tx/srr_status1") , 1, srrstatus1Callback);
	ros::Subscriber sub_srr_status2 = n.subscribe(std::string("/front_srr/front_right_srr/parsed_tx/srr_status2") , 1, srrstatus2Callback);
	ros::Subscriber sub_srr_status3 = n.subscribe(std::string("/front_srr/front_right_srr/parsed_tx/srr_status3") , 1, srrstatus3Callback);
	ros::Subscriber sub_srr_status4 = n.subscribe(std::string("/front_srr/front_right_srr/parsed_tx/srr_status4") , 1, srrstatus4Callback);
	ros::Subscriber sub_srr_status5 = n.subscribe(std::string("/front_srr/front_right_srr/parsed_tx/srr_status5") , 1, srrstatus5Callback);
	ros::Subscriber sub_srr_track   = n.subscribe(std::string("/front_srr/front_right_srr/parsed_tx/srr_track") , 1, srrtrackCallback);
	ros::Subscriber sub_detections_rf = n.subscribe(std::string("/front_srr/front_right_srr/as_tx/detections"), 1, detectionsRFCallback);
	ros::Subscriber sub_radar_markers = n.subscribe(std::string("/front_srr/front_right_srr/as_tx/radar_markers"), 1, radarmarkersCallback);


//-------------------------------------------------------------------------------------------------
// Publishers
//------------------------------------------------------------------------------------------------- 
	ros::Publisher pubAlignedReport = n.advertise<message_project_s::ObstacleAlignmentReport_1>(std::string("/DelphiSRR_RightFront_ObstacleAlignmentReport"), 1);     
	


	// It is the time shift between the sensor clock and ROS clock which we need to estimate in order to successfully implement TIME ALIGNMENT.
	ros::Duration clk_offset_mean;

	// Latency is the duration between time at which environment is sampled by the sensor and the time at which processed data (derived from raw data sample) is received on the ROS machine. It is measured physically and set into the software. Ex: here its 0.001 
	ros::Duration Latency(0.001);

	// Intialize "begin" with the current ROS time which is needed to compute the cycle_time
	ros::Time begin;
	begin = ros::Time::now(); 


	ros::Rate loop_rate(1000);
	

	while(n.ok())

	{
              
		ros::spinOnce();
		

		if(received_detections_rf)

                {
                    
			// Initialize "current_time" with the current ROS machine time. It is actually the Receive_time or time of data reception by ROS node
			ros::Time current_time = ros::Time::now();

			// Gives the cycle time 
			double cycle_time = (current_time - begin).toSec(); 

			// Here the clk_offset represent the time_shift_raw which is given as: time_shift_raw = Receive_Time(ROS) - Sensor Timestamp - latency - Jitter
			double clk_offset  = (current_time - detections_rf.header.stamp - Latency).toSec();

			// Implement 1st order low-pass filter (Exponential Filter / Smoothing). Gain K = Exp (-cycle_time/Time_constant). Time_constant is supposed to be big enough so that the filtered jitter tends to zero. As time_constant approaches 0, K goes to zero, so there is no-filtering and the output equals the new input. As the time_constant gets very large, K approaches to 1, so that the new input is almost ignored - very heavy filtering.
			double K = exp(-cycle_time/0.100);

			// Filter state output at time step (Ti) is given as: State(Ti) = K * State(Ti - 1) + (1 - K) * Input (Ti)
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_mean.toSec();

			// Here we obtain the time shift between the sensor and ROS clock
			clk_offset_mean = ros::Duration(clk_offset);

			// We obtain here the Final Aligned Timestamp by adding the time shift between the sensor and the ROS clock in the the timestamp of the measurements obtained by the sensor
			detections_rf.header.stamp += clk_offset_mean;
			//std::cout<<"Timestamp with respect to ROS Clock:"<<detections_rf.header.stamp<<std::endl;               

			localAlignmentReport_srrrf.header=detections_rf.header;
			std::cout<<"QTYObstacles SRR-RF : "<<detections_rf.detections.size()<<std::endl; 

			//QTYObstacles
			localAlignmentReport_srrrf.QtyObstacles.data = detections_rf.detections.size();

			localAlignmentReport_srrrf.ObstacleAlignement_1.clear();

			for(int didx=0;didx<detections_rf.detections.size();didx++)

                   	{
				std::cout<<detections_rf.detections[didx].detection_id<<" ";

				// fill obtacleAlignment.msg

				//Header
				tempObstacleAlignment_srrrf.header=detections_rf.header;

				//Track ID
				tempObstacleAlignment_srrrf.id.data=detections_rf.detections[didx].detection_id;

				//Position-X and Y 
				tempObstacleAlignment_srrrf.obstaclePosition.position.x=detections_rf.detections[didx].position.x;
				tempObstacleAlignment_srrrf.obstaclePosition.position.y=detections_rf.detections[didx].position.y;

				//Velocity-X and Y 
				tempObstacleAlignment_srrrf.obstacleVelocity.linear.x=detections_rf.detections[didx].velocity.x;
				tempObstacleAlignment_srrrf.obstacleVelocity.linear.y=detections_rf.detections[didx].velocity.y;


//-------------------------------------------------------------------------------------------------
// Info Unavailable 
//-------------------------------------------------------------------------------------------------

				//Relative Velocity-X 
				tempObstacleAlignment_srrrf.obstacleRelativeVelocity.linear.x = tempObstacleAlignment_srrrf.obstacleRelativeVelocity_linear_Unknown;
				tempObstacleAlignment_srrrf.obstacleRelativeVelocity.linear.y = tempObstacleAlignment_srrrf.obstacleRelativeVelocity_linear_Unknown;
				tempObstacleAlignment_srrrf.obstacleRelativeVelocity.linear.z = tempObstacleAlignment_srrrf.obstacleRelativeVelocity_linear_Unknown;
				tempObstacleAlignment_srrrf.obstacleRelativeVelocity.angular.x = tempObstacleAlignment_srrrf.obstacleRelativeVelocity_angular_Unknown;
				tempObstacleAlignment_srrrf.obstacleRelativeVelocity.angular.y = tempObstacleAlignment_srrrf.obstacleRelativeVelocity_angular_Unknown;
				tempObstacleAlignment_srrrf.obstacleRelativeVelocity.angular.z = tempObstacleAlignment_srrrf.obstacleRelativeVelocity_angular_Unknown;

				//Obstacle Acceleration
			       	tempObstacleAlignment_srrrf.obstacleAcceleration.linear.x= tempObstacleAlignment_srrrf.obstacleAcceleration_linear_Unknown;
				tempObstacleAlignment_srrrf.obstacleAcceleration.linear.y= tempObstacleAlignment_srrrf.obstacleAcceleration_linear_Unknown;
				tempObstacleAlignment_srrrf.obstacleAcceleration.linear.z= tempObstacleAlignment_srrrf.obstacleAcceleration_linear_Unknown;
	
				tempObstacleAlignment_srrrf.obstacleAcceleration.angular.x= tempObstacleAlignment_srrrf.obstacleAcceleration_angular_Unknown;
				tempObstacleAlignment_srrrf.obstacleAcceleration.angular.y= tempObstacleAlignment_srrrf.obstacleAcceleration_angular_Unknown;
				tempObstacleAlignment_srrrf.obstacleAcceleration.angular.z= tempObstacleAlignment_srrrf.obstacleAcceleration_angular_Unknown;

				//Obstacle Dimension-Length and Width (meter)
				tempObstacleAlignment_srrrf.obstacleDimensions.x = tempObstacleAlignment_srrrf.obstacleDimensions_Unknown;
				tempObstacleAlignment_srrrf.obstacleDimensions.y = tempObstacleAlignment_srrrf.obstacleDimensions_Unknown;
				tempObstacleAlignment_srrrf.obstacleDimensions.z = tempObstacleAlignment_srrrf.obstacleDimensions_Unknown;

				//Blinker Status 
				tempObstacleAlignment_srrrf.blinkerInfo = tempObstacleAlignment_srrrf.blinkerInfo_Unknown;

				//Cut_in_and_out
				tempObstacleAlignment_srrrf.cutInAndOut = tempObstacleAlignment_srrrf.cutInAndOut_Unknown;

				//Obstacle Classification
				tempObstacleAlignment_srrrf.obstacleType  = tempObstacleAlignment_srrrf.obstacleType_Unknown;

				//Obstacle Status
				tempObstacleAlignment_srrrf.obstacleStatus  = tempObstacleAlignment_srrrf.obstacleStatus_Unknown;

				//Obstacle Brake Lights
				tempObstacleAlignment_srrrf.obstacleBrakeLights  = tempObstacleAlignment_srrrf.obstacleBrakeLights_Unknown;

				//Closest in Path Vehicle
				tempObstacleAlignment_srrrf.cipvFlag  = tempObstacleAlignment_srrrf.cipvFlag_Unknown;

				//Obstacle Replaced
				tempObstacleAlignment_srrrf.obstacleReplaced  = tempObstacleAlignment_srrrf.obstacleReplaced_Unknown;

				//Obstacle Valid
				tempObstacleAlignment_srrrf.obstacleValid  = tempObstacleAlignment_srrrf.obstacleValid_Unknown;

				//Obstacle Age
				tempObstacleAlignment_srrrf.obstacleAge  = tempObstacleAlignment_srrrf.obstacleAge_Unknown;

				//Obstacle Lane
				tempObstacleAlignment_srrrf.obstacleLane  = tempObstacleAlignment_srrrf.obstacleLane_Unknown;

				//Obstacle Angle 
				tempObstacleAlignment_srrrf.obstacleAngle  = tempObstacleAlignment_srrrf.obstacleAngle_Unknown;

				//Obstacle Angle Variance 
				tempObstacleAlignment_srrrf.obstacleAngleVariance = tempObstacleAlignment_srrrf.obstacleAngleVariance_Unknown;

				//Obstacle Angle Rate 
				tempObstacleAlignment_srrrf.obstacleAngleRate  = tempObstacleAlignment_srrrf.obstacleAngleRate_Unknown;

				//Obstacle Scale Change (pix/sec)
				tempObstacleAlignment_srrrf.obstacleScaleChange  = tempObstacleAlignment_srrrf.obstacleScaleChange_Unknown;

				//Traffic Sign Recognition (TSR) sign type   
				tempObstacleAlignment_srrrf.visionOnlySignType = tempObstacleAlignment_srrrf.visionOnlySignType_Unknown;

				//Supplementary sign type - rain, snow, arrow etc.
				tempObstacleAlignment_srrrf.visionOnlySupplementarySignType = tempObstacleAlignment_srrrf.visionOnlySupplementarySignType_Unknown;

				//Sign Position
				tempObstacleAlignment_srrrf.signPosition.x= tempObstacleAlignment_srrrf.signPosition_Unknown;
				tempObstacleAlignment_srrrf.signPosition.y= tempObstacleAlignment_srrrf.signPosition_Unknown;
				tempObstacleAlignment_srrrf.signPosition.z= tempObstacleAlignment_srrrf.signPosition_Unknown;

				//Filter
				tempObstacleAlignment_srrrf.filterType = tempObstacleAlignment_srrrf.filterType_Unknown;

				//Position Variance - X and Y 
			       	tempObstacleAlignment_srrrf.obstaclePoseVariance.position.x = tempObstacleAlignment_srrrf.obstaclePoseVariance_position_Unknown;
			       	tempObstacleAlignment_srrrf.obstaclePoseVariance.position.y = tempObstacleAlignment_srrrf.obstaclePoseVariance_position_Unknown;
				tempObstacleAlignment_srrrf.obstaclePoseVariance.position.z = tempObstacleAlignment_srrrf.obstaclePoseVariance_position_Unknown;

				tempObstacleAlignment_srrrf.obstaclePoseVariance.orientation.x = tempObstacleAlignment_srrrf.obstaclePoseVariance_orientation_Unknown;
				tempObstacleAlignment_srrrf.obstaclePoseVariance.orientation.y = tempObstacleAlignment_srrrf.obstaclePoseVariance_orientation_Unknown;
				tempObstacleAlignment_srrrf.obstaclePoseVariance.orientation.z = tempObstacleAlignment_srrrf.obstaclePoseVariance_orientation_Unknown;
				tempObstacleAlignment_srrrf.obstaclePoseVariance.orientation.w = tempObstacleAlignment_srrrf.obstaclePoseVariance_orientation_Unknown;

				//Absolute Velocity Variance - X and Y
				tempObstacleAlignment_srrrf.obstacleVelocityVariance.linear.x = tempObstacleAlignment_srrrf.obstacleVelocityVariance_linear_Unknown;
				tempObstacleAlignment_srrrf.obstacleVelocityVariance.linear.y = tempObstacleAlignment_srrrf.obstacleVelocityVariance_linear_Unknown;
				tempObstacleAlignment_srrrf.obstacleVelocityVariance.linear.z = tempObstacleAlignment_srrrf.obstacleVelocityVariance_linear_Unknown;

				tempObstacleAlignment_srrrf.obstacleVelocityVariance.angular.x = tempObstacleAlignment_srrrf.obstacleVelocityVariance_angular_Unknown;
				tempObstacleAlignment_srrrf.obstacleVelocityVariance.angular.y = tempObstacleAlignment_srrrf.obstacleVelocityVariance_angular_Unknown;
				tempObstacleAlignment_srrrf.obstacleVelocityVariance.angular.z = tempObstacleAlignment_srrrf.obstacleVelocityVariance_angular_Unknown;

				//Relative Velocity Variance - X and Y
				tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance.linear.x = tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance_linear_Unknown;
				tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance.linear.y = tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance_linear_Unknown;
				tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance.linear.z = tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance_linear_Unknown;

				tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance.angular.x = tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance_angular_Unknown;
				tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance.angular.y = tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance_angular_Unknown;
				tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance.angular.z = tempObstacleAlignment_srrrf.obstacleRelativeVelocityVariance_angular_Unknown;

				//Classification probability
			       	tempObstacleAlignment_srrrf.classificationProbability = tempObstacleAlignment_srrrf.classificationProbability_Unknown;

				//Ground Height
			       	tempObstacleAlignment_srrrf.groundHeight.data = tempObstacleAlignment_srrrf.groundHeight_Unknown;

				//Date Acquisition
			       	tempObstacleAlignment_srrrf.dateAcquisition.data = tempObstacleAlignment_srrrf.dateAcquisition_Unknown;


				localAlignmentReport_srrrf.ObstacleAlignement_1.push_back(tempObstacleAlignment_srrrf);
                  	}

			std::cout<<std::endl;

			// Publish final aligned data topic

			pubAlignedReport.publish(localAlignmentReport_srrrf);
			
			received_detections_rf=false;

           	}

	loop_rate.sleep();

	}
        
   return 0;
}
        	
	
