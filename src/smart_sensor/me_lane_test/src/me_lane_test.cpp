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

//message_project_s -> Obstacle

#include<message_project_s/ObstacleAlignmentReport_1.h>
#include<message_project_s/ObstacleAlignment_1.h>

//message_project_s -> Lane

#include<message_project_s/LaneAlignmentME_1.h>

//Message Filters
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/sync_policies/exact_time.h>
#include <message_filters/time_synchronizer.h>
#include "boost/bind.hpp"
using namespace message_filters;

//Mobileye_560_660
#include <can_msgs/Frame.h>
#include <mobileye_560_660_msgs/Lane.h>
#include <mobileye_560_660_msgs/Ahbc.h>
#include <mobileye_560_660_msgs/AhbcGradual.h>
#include <mobileye_560_660_msgs/AwsDisplay.h>
#include <mobileye_560_660_msgs/FixedFoe.h>
#include <mobileye_560_660_msgs/LkaLane.h>
#include <mobileye_560_660_msgs/LkaReferencePoints.h>
#include <mobileye_560_660_msgs/LkaNumOfNextLaneMarkersReported.h>
#include <mobileye_560_660_msgs/Tsr.h>
#include <mobileye_560_660_msgs/TsrVisionOnly.h>
#include <mobileye_560_660_msgs/AftermarketLane.h>
#include <mobileye_560_660_msgs/LkaNumOfNextLaneMarkersReported.h>
#include <mobileye_560_660_msgs/ObstacleData.h>
#include <mobileye_560_660_msgs/ObstacleStatus.h>
#include <visualization_msgs/Marker.h>



//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------

can_msgs::Frame can_tx;
mobileye_560_660_msgs::AftermarketLane aftermarket_lane;
mobileye_560_660_msgs::Ahbc ahbc;
mobileye_560_660_msgs::AhbcGradual ahbc_gradual;
mobileye_560_660_msgs::AwsDisplay aws_display;
mobileye_560_660_msgs::FixedFoe fixed_foe;
mobileye_560_660_msgs::Lane lane;
mobileye_560_660_msgs::LkaLane left_lka_lane, right_lka_lane, next_lka_lanes;
mobileye_560_660_msgs::LkaNumOfNextLaneMarkersReported lka_num_of_next_lane_markers_reported;
mobileye_560_660_msgs::LkaReferencePoints lka_reference_points;
mobileye_560_660_msgs::ObstacleData obstacle_data;
mobileye_560_660_msgs::ObstacleStatus obstacle_status;
mobileye_560_660_msgs::Tsr tsr;
mobileye_560_660_msgs::TsrVisionOnly tsr_vision_only;
visualization_msgs::Marker lane_markers, object_markers;

//-------------------------------------------------------------------------------------------------
// output data -> Obstacle
//-------------------------------------------------------------------------------------------------

message_project_s::ObstacleAlignmentReport_1 localAlignmentReport_me;
message_project_s::ObstacleAlignment_1 tempObstacleAlignment_me;


//-------------------------------------------------------------------------------------------------
// output data -> Lane
//-------------------------------------------------------------------------------------------------

message_project_s::LaneAlignmentME_1 laneAlignmentReport_me;


//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------

bool received_can_tx = false;
void cantxDataCallback(const can_msgs::Frame::ConstPtr& buffer)
{
	can_tx = *buffer;
	received_can_tx = true;
}

void aftermarketlaneDataCallback(const mobileye_560_660_msgs::AftermarketLane::ConstPtr& buffer)
{
	aftermarket_lane = *buffer;
}

void ahbcDataCallback(const mobileye_560_660_msgs::Ahbc::ConstPtr& buffer)
{
	ahbc = *buffer;
}

void ahbcgradualDataCallback(const mobileye_560_660_msgs::AhbcGradual::ConstPtr& buffer)
{
	ahbc_gradual = *buffer;
}

void awsdisplayDataCallback(const mobileye_560_660_msgs::AwsDisplay::ConstPtr& buffer)
{
	aws_display = *buffer;
}

void fixedfoeDataCallback(const mobileye_560_660_msgs::FixedFoe::ConstPtr& buffer)
{
	fixed_foe = *buffer;
}

void laneDataCallback(const mobileye_560_660_msgs::Lane::ConstPtr& buffer)
{
	lane = *buffer;
}

bool leftlkalaneReceived = false;
void leftlkalaneDataCallback(const mobileye_560_660_msgs::LkaLane::ConstPtr& buffer)
{
	left_lka_lane = *buffer;

	leftlkalaneReceived = true;
}

bool rightlkalaneReceived = false;
void rightlkalaneDataCallback(const mobileye_560_660_msgs::LkaLane::ConstPtr& buffer)
{
	right_lka_lane = *buffer;

	rightlkalaneReceived = true;
}

bool nextlkalanesReceived = false;
void nextlkalanesDataCallback(const mobileye_560_660_msgs::LkaLane::ConstPtr& buffer)
{
	next_lka_lanes = *buffer;

	nextlkalanesReceived = true;
}

void lkanumofnextlanemarkersreportedDataCallback(const mobileye_560_660_msgs::LkaNumOfNextLaneMarkersReported::ConstPtr& buffer)
{
	lka_num_of_next_lane_markers_reported = *buffer;
}

void lkareferencepointsDataCallback(const mobileye_560_660_msgs::LkaReferencePoints::ConstPtr& buffer)
{
	lka_reference_points = *buffer;
}

bool obstacledataReceived = false;
void obstacledataDataCallback(const mobileye_560_660_msgs::ObstacleData::ConstPtr& buffer)
{
	obstacle_data = *buffer;
   
        obstacledataReceived = true;
}

void obstaclestatusDataCallback(const mobileye_560_660_msgs::ObstacleStatus::ConstPtr& buffer)
{
	obstacle_status = *buffer;
}

bool tsrReceived = false;
void tsrDataCallback(const mobileye_560_660_msgs::Tsr::ConstPtr& buffer)
{
	tsr = *buffer;
   
        tsrReceived = true;
}

void tsrvisiononlyDataCallback(const mobileye_560_660_msgs::TsrVisionOnly::ConstPtr& buffer)
{
	tsr_vision_only = *buffer;
   
}

void lanemarkersDataCallback(const visualization_msgs::Marker::ConstPtr& buffer)
{
	lane_markers = *buffer;
}

void objectmarkersDataCallback(const visualization_msgs::Marker::ConstPtr& buffer)
{
	object_markers = *buffer;
}



//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])

{

	ros::init(argc, argv, std::string("mobileye_node"));

	ros::NodeHandle n;

//-------------------------------------------------------------------------------------------------
// Subscribers
//-------------------------------------------------------------------------------------------------

	ros::Subscriber sub_can_tx  = n.subscribe(std::string("/mobileye/can_tx"),  1, cantxDataCallback);
	ros::Subscriber sub_aftermarket_lane = n.subscribe(std::string("/mobileye/parsed_tx/aftermarket_lane"), 1, aftermarketlaneDataCallback);
	ros::Subscriber sub_ahbc = n.subscribe(std::string("/mobileye/parsed_tx/ahbc"),  1, ahbcDataCallback);
	ros::Subscriber sub_ahbc_gradual = n.subscribe(std::string("/mobileye/mobileye/parsed_tx/ahbc_gradual"),  1, ahbcgradualDataCallback);
	ros::Subscriber sub_aws_display = n.subscribe(std::string("/mobileye/parsed_tx/aws_display"),  1, awsdisplayDataCallback);
	ros::Subscriber sub_fixed_foe = n.subscribe(std::string("/mobileye/parsed_tx/fixed_foe"),  1, fixedfoeDataCallback);
	ros::Subscriber sub_lane = n.subscribe(std::string("/mobileye/parsed_tx/lane"),  1, laneDataCallback);
	ros::Subscriber sub_left_lka_lane = n.subscribe(std::string("/mobileye/parsed_tx/left_lka_lane"),  1, leftlkalaneDataCallback);
	ros::Subscriber sub_right_lka_lane = n.subscribe(std::string("/mobileye/parsed_tx/right_lka_lane"),  1, rightlkalaneDataCallback);
	ros::Subscriber sub_next_lka_lanes = n.subscribe(std::string("/mobileye/parsed_tx/next_lka_lanes"),  1, nextlkalanesDataCallback);
	ros::Subscriber sub_lka_num_of_next_lane_markers_reported = n.subscribe(std::string("/mobileye/parsed_tx/lka_num_of_next_lane_markers_reported"), 1, lkanumofnextlanemarkersreportedDataCallback);
	ros::Subscriber sub_lka_reference_points = n.subscribe(std::string("/mobileye/parsed_tx/lka_reference_points"), 1, lkareferencepointsDataCallback);
	ros::Subscriber sub_obstacle_data  = n.subscribe(std::string("/mobileye/parsed_tx/obstacle_data"), 1, obstacledataDataCallback);
	ros::Subscriber sub_obstacle_status  = n.subscribe(std::string("/mobileye/parsed_tx/obstacle_status"), 1, obstaclestatusDataCallback);
	ros::Subscriber sub_tsr = n.subscribe(std::string("/mobileye/parsed_tx/tsr"), 1, tsrDataCallback);
	ros::Subscriber sub_tsr_vision_only = n.subscribe(std::string("/mobileye/parsed_tx/tsr_vision_only"), 1, tsrvisiononlyDataCallback);
	ros::Subscriber sub_lane_markers = n.subscribe(std::string("/mobileye/as_tx/lane_markers"), 1, lanemarkersDataCallback);
	//ros::Subscriber sub_lane_models = n.subscribe(std::string("/mobileye/as_tx/lane_models"), 1, lanemodelsDataCallback);
	ros::Subscriber sub_object_markers = n.subscribe(std::string("/mobileye/as_tx/object_markers"), 1, objectmarkersDataCallback);
	//ros::Subscriber sub_objects = n.subscribe(std::string("/mobileye/as_tx/objects"), 1, objectsDataCallback);


//-------------------------------------------------------------------------------------------------
// Publishers -- Obstacle
//-------------------------------------------------------------------------------------------------		

	ros::Publisher pubAlignedReport = n.advertise<message_project_s::ObstacleAlignmentReport_1>(std::string("/MobilEye_ObstacleAlignmentReport"), 1); 

//-------------------------------------------------------------------------------------------------
// Publishers -- Lane
//-------------------------------------------------------------------------------------------------

	ros::Publisher pubLaneAlignedReport = n.advertise<message_project_s::LaneAlignmentME_1>(std::string("/MobilEye_LaneAlignmentReport"), 1); 


//-------------------------------------------------------------------------------------------------
// Time Alignment
//-------------------------------------------------------------------------------------------------

	// It is the time shift between the sensor clock and ROS clock which we need to estimate in order to successfully implement TIME ALIGNMENT.
	ros::Duration clk_offset_mean, clk_offset_mean_tsr;
	ros::Duration clk_offset_right_mean, clk_offset_left_mean, clk_offset_next_mean;

	// Latency is the duration between time at which environment is sampled by the sensor and the time at which processed data (derived from raw data sample) is received on the ROS machine. It is measured physically and set into the software. Ex: here its 0.001 
	ros::Duration Latency(0.001);

	// Intialize "begin" with the current ROS time which is needed to compute the cycle_time
	ros::Time begin;
	begin = ros::Time::now();

	ros::Time begintsr;
	begintsr = ros::Time::now();

	ros::Time last_time_right, last_time_left, last_time_next;
	last_time_right = last_time_left = last_time_next = ros::Time::now();

	// Loop rate
	ros::Rate loop_rate(1000);

	// Left right array
	std::vector<mobileye_560_660_msgs::LkaLane> arrayLeft;
	std::vector<mobileye_560_660_msgs::LkaLane> arrayRight;


while(n.ok())

        {
		ros::spinOnce();

/*		if(obstacledataReceived)
                     
                {  

			// Initialize "current_time" with the current ROS machine time. It is actually the Receive_time or time of data reception by ROS node
			ros::Time current_time = ros::Time::now();


			// Gives the cycle time 
			double cycle_time = (current_time - begin).toSec(); 

			// Here the clk_offset represent the time_shift_raw which is given as: time_shift_raw = Receive_Time(ROS) - Sensor Timestamp - latency - Jitter
			double clk_offset  = (current_time - obstacle_data.header.stamp - Latency).toSec();

			// Implement 1st order low-pass filter (Exponential Filter / Smoothing). Gain K = Exp (-cycle_time/Time_constant). Time_constant is supposed to be big enough so that the filtered jitter tends to zero. As time_constant approaches 0, K goes to zero, so there is no-filtering and the output equals the new input. As the time_constant gets very large, K approaches to 1, so that the new input is almost ignored - very heavy filtering.
			double K = exp(-cycle_time/0.100);

			// Filter state output at time step (Ti) is given as: State(Ti) = K * State(Ti - 1) + (1 - K) * Input (Ti)
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_mean.toSec();

			// Here we obtain the time shift between the sensor and ROS clock
			clk_offset_mean = ros::Duration(clk_offset);

			// We obtain here the Final Aligned Timestamp by adding the time shift between the sensor and the ROS clock in the the timestamp of the measurements obtained by the sensor
			obstacle_data.header.stamp += clk_offset_mean;

			std::cout<<"\nObstacle Timestamp with respect to ROS Clock: "<<obstacle_data.header.stamp<<std::endl;		      

			localAlignmentReport_me.header=obstacle_data.header;
			std::cout<<"Obstacle ID : "<<obstacle_data.obstacle_id<<std::endl;

			localAlignmentReport_me.ObstacleAlignement_1.clear();

//-------------------------------------------------------------------------------------------------
// Fill in ObstacleAlignment.msg ---- Obstacle Data  
//-------------------------------------------------------------------------------------------------

			//-------------------------------------------------------------------------
			//Header
			tempObstacleAlignment_me.header = obstacle_data.header;
		            
		        //Obstacle ID
		        tempObstacleAlignment_me.id.data = obstacle_data.obstacle_id;

		        //Position-X and Y (meter)
		        tempObstacleAlignment_me.obstaclePosition.position.x = obstacle_data.obstacle_pos_x; 
		        tempObstacleAlignment_me.obstaclePosition.position.y = obstacle_data.obstacle_pos_y; 

		        //Relative Velocity-X (meter/sec)
		        tempObstacleAlignment_me.obstacleRelativeVelocity.linear.x = obstacle_data.obstacle_rel_vel_x;
		                 
		        //Acceleration-X (meter/sec2)
		        tempObstacleAlignment_me.obstacleAcceleration.linear.x = obstacle_data.object_accel_x;

		        //Obstacle Dimension-Length and Width (meter)
		        tempObstacleAlignment_me.obstacleDimensions.x = obstacle_data.obstacle_length;
		        tempObstacleAlignment_me.obstacleDimensions.y = obstacle_data.obstacle_width;

		        //Blinker Status 
		        tempObstacleAlignment_me.blinkerInfo = obstacle_data.blinker_info;

		        //Cut_in_and_out
		        tempObstacleAlignment_me.cutInAndOut = obstacle_data.cut_in_and_out;

		        //Obstacle Classification
		        tempObstacleAlignment_me.obstacleType  = obstacle_data.obstacle_type;

		        //Obstacle Status
		        tempObstacleAlignment_me.obstacleStatus  = obstacle_data.obstacle_status;

		        //Obstacle Brake Lights
		        tempObstacleAlignment_me.obstacleBrakeLights  = obstacle_data.obstacle_brake_lights;

		        //Closest in Path Vehicle
		        tempObstacleAlignment_me.cipvFlag  = obstacle_data.cipv_flag;

		        //Obstacle Replaced
		        tempObstacleAlignment_me.obstacleReplaced  = obstacle_data.obstacle_replaced;

		        //Obstacle Valid
		        tempObstacleAlignment_me.obstacleValid  = obstacle_data.obstacle_valid;

		        //Obstacle Age
		        tempObstacleAlignment_me.obstacleAge  = obstacle_data.obstacle_age;

		        //Obstacle Lane
		        tempObstacleAlignment_me.obstacleLane  = obstacle_data.obstacle_lane;

		        //Obstacle Angle (degree)
		        tempObstacleAlignment_me.obstacleAngle  = obstacle_data.obstacle_angle;

		        //Obstacle Angle Rate (degree/sec)
		        tempObstacleAlignment_me.obstacleAngleRate  = obstacle_data.obstacle_angle_rate;

		        //Obstacle Scale Change (pix/sec)
		        tempObstacleAlignment_me.obstacleScaleChange  = obstacle_data.obstacle_scale_change;
			//-------------------------------------------------------------------------

			localAlignmentReport_me.ObstacleAlignement_1.push_back(tempObstacleAlignment_me);		   

		       	// Publish final aligned data topic

		   	pubAlignedReport.publish(localAlignmentReport_me);

		   	obstacledataReceived=false;
	       
		}
*/

/*
		if(tsrReceived)
                     
                {  
 
			// Initialize "current_time" with the current ROS machine time. It is actually the Receive_time or time of data reception by ROS node
			ros::Time current_time = ros::Time::now();

			// Gives the cycle time 
			double cycle_time = (current_time - begintsr).toSec(); 

			// Here the clk_offset represent the time_shift_raw which is given as: time_shift_raw = Receive_Time(ROS) - Sensor Timestamp - latency - Jitter
			double clk_offset  = (current_time - tsr.header.stamp - Latency).toSec();

			// Implement 1st order low-pass filter (Exponential Filter / Smoothing). Gain K = Exp (-cycle_time/Time_constant). Time_constant is supposed to be big enough so that the filtered jitter tends to zero. As time_constant approaches 0, K goes to zero, so there is no-filtering and the output equals the new input. As the time_constant gets very large, K approaches to 1, so that the new input is almost ignored - very heavy filtering.
			double K = exp(-cycle_time/0.100);

			// Filter state output at time step (Ti) is given as: State(Ti) = K * State(Ti - 1) + (1 - K) * Input (Ti)
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_mean_tsr.toSec();

			// Here we obtain the time shift between the sensor and ROS clock
			clk_offset_mean_tsr = ros::Duration(clk_offset);

			// We obtain here the Final Aligned Timestamp by adding the time shift between the sensor and the ROS clock in the the timestamp of the measurements obtained by the sensor
			tsr.header.stamp += clk_offset_mean;

			std::cout<<"TSR Timestamp with respect to ROS Clock: "<<tsr.header.stamp<<std::endl;

			localAlignmentReport_me.header=tsr.header;

			localAlignmentReport_me.ObstacleAlignement_1.clear();

//-------------------------------------------------------------------------------------------------
// Fill in ObstacleAlignment.msg ---- Traffic Sign Data 
//-------------------------------------------------------------------------------------------------

			//Header
			tempObstacleAlignment_me.header = tsr.header;

			//Traffic Sign Recognition (TSR) sign type   
		        tempObstacleAlignment_me.visionOnlySignType= tsr.vision_only_sign_type;

		        //Supplementary sign type - rain, snow, arrow etc.
		        tempObstacleAlignment_me.visionOnlySupplementarySignType= tsr.vision_only_supplementary_sign_type;

		        //X-Longitudnal position, Y-Lateral position and Z-Height of the sign
		        tempObstacleAlignment_me.signPosition.x=tsr.sign_position_x;
		        tempObstacleAlignment_me.signPosition.y=tsr.sign_position_y;
		        tempObstacleAlignment_me.signPosition.z=tsr.sign_position_z;

		        //Filter
		        tempObstacleAlignment_me.filterType = tsr.filter_type;

  			localAlignmentReport_me.ObstacleAlignement_1.push_back(tempObstacleAlignment_me);

		       	// Publish final aligned data topic

		   	pubAlignedReport.publish(localAlignmentReport_me);

		   	tsrReceived=false;
	       
		}

*/


		if( leftlkalaneReceived && (left_lka_lane.quality > 1))

                {

			// Gives the Timestamps of the measurements provided by the sensor  
			std::cout<<"\nTimestamp Left Lane with respect to Sensor Clock: "<<left_lka_lane.header.stamp<<std::endl;

			ros::Time current_time = ros::Time::now();

			// Gives the cycle time 
			double cycle_time = (current_time - last_time_left).toSec();

			// Here the clk_offset represent the time_shift_raw which is given as: time_shift_raw = Receive_Time(ROS) - Sensor Timestamp - latency - Jitter
			double clk_offset  = (current_time - left_lka_lane.header.stamp - Latency).toSec();

			double K = exp(-cycle_time/0.100);

			// Filter state output at time step (Ti) is given as: State(Ti) = K * State(Ti - 1) + (1 - K) * Input (Ti)
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_left_mean.toSec();


			// Here we obtain the time shift between the sensor and ROS clock
			clk_offset_left_mean = ros::Duration(clk_offset);

			left_lka_lane.header.stamp += clk_offset_left_mean;


			arrayLeft.push_back(left_lka_lane);

			std::cout<<"  \nLeft Timestamp  : "<<left_lka_lane.header.stamp<<std::endl;

			leftlkalaneReceived = false;

		}


		if(rightlkalaneReceived && (right_lka_lane.quality > 1))

                {

			// Gives the Timestamps of the measurements provided by the sensor  
			std::cout<<"\nTimestamp Right Lane with respect to Sensor Clock: "<<right_lka_lane.header.stamp<<std::endl;
			ros::Time current_time = ros::Time::now();

			// Gives the cycle time 
			double cycle_time = (current_time - last_time_right).toSec();

			// Here the clk_offset represent the time_shift_raw which is given as: time_shift_raw = Receive_Time(ROS) - Sensor Timestamp - latency - Jitter
			double clk_offset  = (current_time - right_lka_lane.header.stamp - Latency).toSec();

			double K = exp(-cycle_time/0.100);
			
			// Filter state output at time step (Ti) is given as: State(Ti) = K * State(Ti - 1) + (1 - K) * Input (Ti)
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_right_mean.toSec();

			// Here we obtain the time shift between the sensor and ROS clock
			clk_offset_right_mean = ros::Duration(clk_offset);

			right_lka_lane.header.stamp += clk_offset_right_mean;

			arrayRight.push_back(right_lka_lane);

			std::cout<<"  \nRight Timestamp : "<<right_lka_lane.header.stamp<<std::endl;

			rightlkalaneReceived = false;

		}


		std::cout<<"~";

		ros::Duration StampDiff;
		ros::Duration StampComp;
		ros::Duration TimeOffset(0.100);
		ros::Duration TimeZero(0);
                        
//-------------------------------------------------------------------------------------------------
//   CASE 1 : Array left and Right == 1
//-------------------------------------------------------------------------------------------------

		if((arrayLeft.size() == 1 && arrayRight.size() == 1))

		{

			StampDiff = arrayLeft[0].header.stamp - arrayRight[0].header.stamp;
			
			if (StampDiff >= TimeZero)
			{
				StampComp = StampDiff;
          		}
			else
			{
				StampComp = -StampDiff; 
			}

//-------------------------------------------------------------------------------------------------
//   CASE 1a: Both Left Right Together
//-------------------------------------------------------------------------------------------------
			
			if (StampComp <= TimeOffset)
			{
				
//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp less than the 
//  considered TimeOffset, So both Left and Right lane info included in report. 
//-------------------------------------------------------------------------------------------------

		                //HEADER -- Left for now

		               laneAlignmentReport_me.header = arrayLeft[0].header;
//-------------------------------------------------------------------------------------------------
//LEFT FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
				//Lane type
				laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
				//Quality
				laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
				//Model Degree
				laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
				//Position Parameter C0
				laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
				//Curvature Parameter C2
				laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
				//Curvature Derivative Parameter C3
				laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
				//Marking Width
				laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
				//Heading Angle Parameter C1
				laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
				//View Range 
				laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
				//View Range Availability
				laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;
//-------------------------------------------------------------------------------------------------
//RIGHT FILL --------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
				//Lane type
				laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
				//Quality
				laneAlignmentReport_me.right_quality = arrayRight[0].quality;
				//Model Degree
				laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
				//Position Parameter C0
				laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
				//Curvature Parameter C2
				laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
				//Curvature Derivative Parameter C3
				laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
				//Marking Width
				laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
				//Heading Angle Parameter C1
				laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
				//View Range 
				laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
				//View Range Availability
				laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;

				//PUBLISH---------------------------------------
				pubLaneAlignedReport.publish(laneAlignmentReport_me);

				arrayLeft.pop_back();
				arrayRight.pop_back();

			}

			else
			{
//-------------------------------------------------------------------------------------------------
//   CASE 1b: if Left lane data came before Right 
//-------------------------------------------------------------------------------------------------
				if (arrayLeft[0].header.stamp < arrayRight[0].header.stamp)
				{
					
//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp greater than the 
//  considered TimeOffset. Left lane message arrived before Right so, Left lane info included in report 
//  while all Right lane info set to 0
//-------------------------------------------------------------------------------------------------
					//HEADER -- Left 

				        laneAlignmentReport_me.header = arrayLeft[0].header;
//-------------------------------------------------------------------------------------------------
//LEFT FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
					//Lane type
					laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
					//Quality
					laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
					//Model Degree
					laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
					//Position Parameter C0
					laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
					//Curvature Parameter C2
					laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
					//Curvature Derivative Parameter C3
					laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
					//Marking Width
					laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
					//Heading Angle Parameter C1
					laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
					//View Range 
					laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
					//View Range Availability
					laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//All RIGHT --> 0   -------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

					laneAlignmentReport_me.right_lane_type = 0;
					//Quality
					laneAlignmentReport_me.right_quality = 0;
					//Model Degree
					laneAlignmentReport_me.right_model_degree = 0;
					//Position Parameter C0
					laneAlignmentReport_me.right_position_parameter_c0 = 0;
					//Curvature Parameter C2
					laneAlignmentReport_me.right_curvature_parameter_c2 = 0;
					//Curvature Derivative Parameter C3
					laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = 0;
					//Marking Width
					laneAlignmentReport_me.right_marking_width = 0;
					//Heading Angle Parameter C1
					laneAlignmentReport_me.right_heading_angle_parameter_c1 = 0;
					//View Range 
					laneAlignmentReport_me.right_view_range = 0;
					//View Range Availability
					laneAlignmentReport_me.right_view_range_availability = false;

					//PUBLISH---------------------------------------
					pubLaneAlignedReport.publish(laneAlignmentReport_me);
					
					arrayLeft.pop_back();
		
				}

				else

				{
//-------------------------------------------------------------------------------------------------
//   CASE 1c: if Right lane data came before Left 
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp greater than the 
//  considered TimeOffset. Right lane message arrived before Left so, Right lane info included in report 
//  while all Left lane info set to 0
//-------------------------------------------------------------------------------------------------

					 //HEADER -- Right
				        laneAlignmentReport_me.header = arrayRight[0].header;

//-------------------------------------------------------------------------------------------------
//RIGHT FILL --------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
					//Lane type
					laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
					//Quality
					laneAlignmentReport_me.right_quality = arrayRight[0].quality;
					//Model Degree
					laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
					//Position Parameter C0
					laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
					//Curvature Parameter C2
					laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
					//Curvature Derivative Parameter C3
					laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
					//Marking Width
					laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
					//Heading Angle Parameter C1
					laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
					//View Range 
					laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
					//View Range Availability
					laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;


//-------------------------------------------------------------------------------------------------
//All Left --> 0   --------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
 			
					//Lane type
					laneAlignmentReport_me.left_lane_type = 0;
					//Quality
					laneAlignmentReport_me.left_quality = 0;
					//Model Degree
					laneAlignmentReport_me.left_model_degree = 0;
					//Position Parameter C0
					laneAlignmentReport_me.left_position_parameter_c0 = 0;
					//Curvature Parameter C2
					laneAlignmentReport_me.left_curvature_parameter_c2 = 0;
					//Curvature Derivative Parameter C3
					laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = 0;
					//Marking Width
					laneAlignmentReport_me.left_marking_width = 0;
					//Heading Angle Parameter C1
					laneAlignmentReport_me.left_heading_angle_parameter_c1 = 0;
					//View Range 
					laneAlignmentReport_me.left_view_range = 0;
					//View Range Availability
					laneAlignmentReport_me.left_view_range_availability = false;		  


					//PUBLISH---------------------------------------
					pubLaneAlignedReport.publish(laneAlignmentReport_me);
					
					arrayRight.pop_back();


				}
			}
		}

			else if (arrayLeft.size() == 2 && arrayRight.empty())
			{

//-------------------------------------------------------------------------------------------------
//   CASE 2 : Array left == 2 and Array Right == 0
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//  Two messages available on Left lane topic and no message yet on right lane topic. So, we fill in 
//  the report with the first message that arrived on the left lane topic and set the info for 
//  right lane as 0
//-------------------------------------------------------------------------------------------------			
			
				//HEADER -- Left 
	
		                 laneAlignmentReport_me.header = arrayLeft[0].header;

//-------------------------------------------------------------------------------------------------
//LEFT FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
				//Lane type
				laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
				//Quality
				laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
				//Model Degree
				laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
				//Position Parameter C0
				laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
				//Curvature Parameter C2
				laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
				//Curvature Derivative Parameter C3
				laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
				//Marking Width
				laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
				//Heading Angle Parameter C1
				laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
				//View Range 
				laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
				//View Range Availability
				laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//All RIGHT --> 0   -------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------  

				laneAlignmentReport_me.right_lane_type = 0;
				//Quality
				laneAlignmentReport_me.right_quality = 0;
				//Model Degree
				laneAlignmentReport_me.right_model_degree = 0;
				//Position Parameter C0
				laneAlignmentReport_me.right_position_parameter_c0 = 0;
				//Curvature Parameter C2
				laneAlignmentReport_me.right_curvature_parameter_c2 = 0;
				//Curvature Derivative Parameter C3
				laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = 0;
				//Marking Width
				laneAlignmentReport_me.right_marking_width = 0;
				//Heading Angle Parameter C1
				laneAlignmentReport_me.right_heading_angle_parameter_c1 = 0;
				//View Range 
				laneAlignmentReport_me.right_view_range = 0;
				//View Range Availability
				laneAlignmentReport_me.right_view_range_availability = false;

				//PUBLISH---------------------------------------
				pubLaneAlignedReport.publish(laneAlignmentReport_me);

				arrayLeft.erase(arrayLeft.begin());
                             
			}

			else if (arrayLeft.empty() && arrayRight.size() == 2)
			
			{

//-------------------------------------------------------------------------------------------------
//   CASE 3 : Array left == 0 and Array Right == 2
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//  Two messages available on Right lane topic and no message yet on left lane topic. So, we fill in 
//  the report with the first message that arrived on the right lane topic and set the info for 
//  left lane as 0
//-------------------------------------------------------------------------------------------------

				//HEADER -- Right

		                laneAlignmentReport_me.header = arrayRight[0].header;

//-------------------------------------------------------------------------------------------------
//RIGHT FILL --------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
				//Lane type
				laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
				//Quality
				laneAlignmentReport_me.right_quality = arrayRight[0].quality;
				//Model Degree
				laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
				//Position Parameter C0
				laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
				//Curvature Parameter C2
				laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
				//Curvature Derivative Parameter C3
				laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
				//Marking Width
				laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
				//Heading Angle Parameter C1
				laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
				//View Range 
				laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
				//View Range Availability
				laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//All Left --> 0   --------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------  

				//Lane type
				laneAlignmentReport_me.left_lane_type = 0;
				//Quality
				laneAlignmentReport_me.left_quality = 0;
				//Model Degree
				laneAlignmentReport_me.left_model_degree = 0;
				//Position Parameter C0
				laneAlignmentReport_me.left_position_parameter_c0 = 0;
				//Curvature Parameter C2
				laneAlignmentReport_me.left_curvature_parameter_c2 = 0;
				//Curvature Derivative Parameter C3
				laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = 0;
				//Marking Width
				laneAlignmentReport_me.left_marking_width = 0;
				//Heading Angle Parameter C1
				laneAlignmentReport_me.left_heading_angle_parameter_c1 = 0;
				//View Range 
				laneAlignmentReport_me.left_view_range = 0;
				//View Range Availability
				laneAlignmentReport_me.left_view_range_availability = false;		  

				//PUBLISH---------------------------------------
				pubLaneAlignedReport.publish(laneAlignmentReport_me);

				arrayRight.erase(arrayRight.begin());

			}


			//---------------CASE ----2 Right 1 Left and vice versa-------------------------


			else if (arrayLeft.size() == 2 && arrayRight.size() == 1)

			{

//-------------------------------------------------------------------------------------------------
//   CASE 4 : Array left == 2 and Array Right == 1
//-------------------------------------------------------------------------------------------------

				StampDiff = arrayLeft[0].header.stamp - arrayRight[0].header.stamp;

				if (StampDiff >= TimeZero)
				{
					StampComp = StampDiff;
		  		}
				else
				{
					StampComp = -StampDiff;
				}


				if (StampComp <= TimeOffset)
				{

//-------------------------------------------------------------------------------------------------
//   CASE 4.1a : left[0] with right[0] close enough to be placed in report together
//-------------------------------------------------------------------------------------------------



					//HEADER -- Left for now

                         		laneAlignmentReport_me.header = arrayLeft[0].header;

//-------------------------------------------------------------------------------------------------
//LEFT FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
					//Lane type
					laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
					//Quality
					laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
					//Model Degree
					laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
					//Position Parameter C0
					laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
					//Curvature Parameter C2
					laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
					//Curvature Derivative Parameter C3
					laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
					//Marking Width
					laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
					//Heading Angle Parameter C1
					laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
					//View Range
					laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
					//View Range Availability
					laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//RIGHT FILL --------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
					//Lane type
					laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
					//Quality
					laneAlignmentReport_me.right_quality = arrayRight[0].quality;
					//Model Degree
					laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
					//Position Parameter C0
					laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
					//Curvature Parameter C2
					laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
					//Curvature Derivative Parameter C3
					laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
					//Marking Width
					laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
					//Heading Angle Parameter C1
					laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
					//View Range
					laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
					//View Range Availability
					laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;


					//PUBLISH---------------------------------------
					pubLaneAlignedReport.publish(laneAlignmentReport_me);

					arrayLeft.erase(arrayLeft.begin());
					arrayRight.pop_back();

				}

				else
				{

					if (arrayLeft[0].header.stamp < arrayRight[0].header.stamp)
					{

//-------------------------------------------------------------------------------------------------
//   CASE 4.1b : left[0] came before right[0] (Normally it should be always true) 
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp greater than the
//  considered TimeOffset. L[0] arrived before R[0] so, Left lane info included in report + removed from buffer
//  while all Right lane info set to 0
//-------------------------------------------------------------------------------------------------
						//HEADER -- Left

						laneAlignmentReport_me.header = arrayLeft[0].header;
//-------------------------------------------------------------------------------------------------
//LEFT FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
						//Lane type
						laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
						//Quality
						laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
						//Model Degree
						laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
						//Position Parameter C0
						laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
						//Curvature Parameter C2
						laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
						//Marking Width
						laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
						//View Range
						laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
						//View Range Availability
						laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//All RIGHT --> 0   -------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

						laneAlignmentReport_me.right_lane_type = 0;
						//Quality
						laneAlignmentReport_me.right_quality = 0;
						//Model Degree
						laneAlignmentReport_me.right_model_degree = 0;
						//Position Parameter C0
						laneAlignmentReport_me.right_position_parameter_c0 = 0;
						//Curvature Parameter C2
						laneAlignmentReport_me.right_curvature_parameter_c2 = 0;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = 0;
						//Marking Width
						laneAlignmentReport_me.right_marking_width = 0;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.right_heading_angle_parameter_c1 = 0;
						//View Range
						laneAlignmentReport_me.right_view_range = 0;
						//View Range Availability
						laneAlignmentReport_me.right_view_range_availability = false;

						//PUBLISH---------------------------------------
						pubLaneAlignedReport.publish(laneAlignmentReport_me);

						arrayLeft.erase(arrayLeft.begin());
//*********************

//-------------------------------------------------------------------------------------------------
//   CASE 4.1b.1c : We published left[0] and then erase so Left[1] -> Left[0] so we compare Timestamp again of Left[0] with Right [0] 
//-------------------------------------------------------------------------------------------------

						StampDiff = arrayLeft[0].header.stamp - arrayRight[0].header.stamp;

						if (StampDiff >= TimeZero)
						{
							StampComp = StampDiff;
				  		}
						else
						{
							StampComp = -StampDiff;
						}


						if (StampComp <= TimeOffset)
						{

//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp less than the
//  considered TimeOffset, So both Left and Right lane info included in report.
//-------------------------------------------------------------------------------------------------

							//HEADER -- Left for now

						       laneAlignmentReport_me.header = arrayLeft[0].header;
//-------------------------------------------------------------------------------------------------
//LEFT FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
							//Lane type
							laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
							//Quality
							laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
							//Model Degree
							laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
							//Position Parameter C0
							laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
							//Curvature Parameter C2
							laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
							//Curvature Derivative Parameter C3
							laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
							//Marking Width
							laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
							//Heading Angle Parameter C1
							laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
							//View Range
							laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
							//View Range Availability
							laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//RIGHT FILL --------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
							//Lane type
							laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
							//Quality
							laneAlignmentReport_me.right_quality = arrayRight[0].quality;
							//Model Degree
							laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
							//Position Parameter C0
							laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
							//Curvature Parameter C2
							laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
							//Curvature Derivative Parameter C3
							laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
							//Marking Width
							laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
							//Heading Angle Parameter C1
							laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
							//View Range
							laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
							//View Range Availability
							laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;

							//PUBLISH---------------------------------------
							pubLaneAlignedReport.publish(laneAlignmentReport_me);

							arrayLeft.pop_back();
							arrayRight.pop_back();

						}

						else
						{

							if (arrayLeft[0].header.stamp < arrayRight[0].header.stamp)
							{

//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp greater than the
//  considered TimeOffset. Left lane message arrived before Right so, Left lane info included in report
//  while all Right lane info set to 0
//-------------------------------------------------------------------------------------------------
								//HEADER -- Left

								laneAlignmentReport_me.header = arrayLeft[0].header;
//-------------------------------------------------------------------------------------------------
//LEFT FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
								//Lane type
								laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
								//Quality
								laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
								//Model Degree
								laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
								//Position Parameter C0
								laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
								//Curvature Parameter C2
								laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
								//Curvature Derivative Parameter C3
								laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
								//Marking Width
								laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
								//Heading Angle Parameter C1
								laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
								//View Range
								laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
								//View Range Availability
								laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//All RIGHT --> 0   -------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

								laneAlignmentReport_me.right_lane_type = 0;
								//Quality
								laneAlignmentReport_me.right_quality = 0;
								//Model Degree
								laneAlignmentReport_me.right_model_degree = 0;
								//Position Parameter C0
								laneAlignmentReport_me.right_position_parameter_c0 = 0;
								//Curvature Parameter C2
								laneAlignmentReport_me.right_curvature_parameter_c2 = 0;
								//Curvature Derivative Parameter C3
								laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = 0;
								//Marking Width
								laneAlignmentReport_me.right_marking_width = 0;
								//Heading Angle Parameter C1
								laneAlignmentReport_me.right_heading_angle_parameter_c1 = 0;
								//View Range
								laneAlignmentReport_me.right_view_range = 0;
								//View Range Availability
								laneAlignmentReport_me.right_view_range_availability = false;

								//PUBLISH---------------------------------------
								pubLaneAlignedReport.publish(laneAlignmentReport_me);

								arrayLeft.pop_back();

							}

							else

							{

//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp greater than the
//  considered TimeOffset. Right lane message arrived before Left so, Right lane info included in report
//  while all Left lane info set to 0
//-------------------------------------------------------------------------------------------------

								 //HEADER -- Right

								laneAlignmentReport_me.header = arrayRight[0].header;

//-------------------------------------------------------------------------------------------------
//RIGHT FILL --------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
								//Lane type
								laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
								//Quality
								laneAlignmentReport_me.right_quality = arrayRight[0].quality;
								//Model Degree
								laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
								//Position Parameter C0
								laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
								//Curvature Parameter C2
								laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
								//Curvature Derivative Parameter C3
								laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
								//Marking Width
								laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
								//Heading Angle Parameter C1
								laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
								//View Range
								laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
								//View Range Availability
								laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;


//-------------------------------------------------------------------------------------------------
//All Left --> 0   --------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

								//Lane type
								laneAlignmentReport_me.left_lane_type = 0;
								//Quality
								laneAlignmentReport_me.left_quality = 0;
								//Model Degree
								laneAlignmentReport_me.left_model_degree = 0;
								//Position Parameter C0
								laneAlignmentReport_me.left_position_parameter_c0 = 0;
								//Curvature Parameter C2
								laneAlignmentReport_me.left_curvature_parameter_c2 = 0;
								//Curvature Derivative Parameter C3
								laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = 0;
								//Marking Width
								laneAlignmentReport_me.left_marking_width = 0;
								//Heading Angle Parameter C1
								laneAlignmentReport_me.left_heading_angle_parameter_c1 = 0;
								//View Range
								laneAlignmentReport_me.left_view_range = 0;
								//View Range Availability
								laneAlignmentReport_me.left_view_range_availability = false;


								//PUBLISH---------------------------------------
								pubLaneAlignedReport.publish(laneAlignmentReport_me);

								arrayRight.pop_back();


							}
						}

					}

					else

					{

//-------------------------------------------------------------------------------------------------
//  ---This case normally not possible ----  
//  Message available on both Left and Right lane topic with a difference in timestamp greater than the
//  considered TimeOffset. Right lane message arrived before Left so, Right lane info included in report
//  while all Left lane info set to 0
//-------------------------------------------------------------------------------------------------

						 //HEADER -- Right

						laneAlignmentReport_me.header = arrayRight[0].header;

//-------------------------------------------------------------------------------------------------
//RIGHT FILL --------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
						//Lane type
						laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
						//Quality
						laneAlignmentReport_me.right_quality = arrayRight[0].quality;
						//Model Degree
						laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
						//Position Parameter C0
						laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
						//Curvature Parameter C2
						laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
						//Marking Width
						laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
						//View Range
						laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
						//View Range Availability
						laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;


//-------------------------------------------------------------------------------------------------
//All Left --> 0   --------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

						//Lane type
						laneAlignmentReport_me.left_lane_type = 0;
						//Quality
						laneAlignmentReport_me.left_quality = 0;
						//Model Degree
						laneAlignmentReport_me.left_model_degree = 0;
						//Position Parameter C0
						laneAlignmentReport_me.left_position_parameter_c0 = 0;
						//Curvature Parameter C2
						laneAlignmentReport_me.left_curvature_parameter_c2 = 0;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = 0;
						//Marking Width
						laneAlignmentReport_me.left_marking_width = 0;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.left_heading_angle_parameter_c1 = 0;
						//View Range
						laneAlignmentReport_me.left_view_range = 0;
						//View Range Availability
						laneAlignmentReport_me.left_view_range_availability = false;


						//PUBLISH---------------------------------------
						pubLaneAlignedReport.publish(laneAlignmentReport_me);

						arrayRight.pop_back();

						//case 20

						//HEADER -- Left

						 laneAlignmentReport_me.header = arrayLeft[0].header;

//-------------------------------------------------------------------------------------------------
//LEFT FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
						//Lane type
						laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
						//Quality
						laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
						//Model Degree
						laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
						//Position Parameter C0
						laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
						//Curvature Parameter C2
						laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
						//Marking Width
						laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
						//View Range
						laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
						//View Range Availability
						laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//All RIGHT --> 0   -------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

						laneAlignmentReport_me.right_lane_type = 0;
						//Quality
						laneAlignmentReport_me.right_quality = 0;
						//Model Degree
						laneAlignmentReport_me.right_model_degree = 0;
						//Position Parameter C0
						laneAlignmentReport_me.right_position_parameter_c0 = 0;
						//Curvature Parameter C2
						laneAlignmentReport_me.right_curvature_parameter_c2 = 0;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = 0;
						//Marking Width
						laneAlignmentReport_me.right_marking_width = 0;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.right_heading_angle_parameter_c1 = 0;
						//View Range
						laneAlignmentReport_me.right_view_range = 0;
						//View Range Availability
						laneAlignmentReport_me.right_view_range_availability = false;

						//PUBLISH---------------------------------------
						pubLaneAlignedReport.publish(laneAlignmentReport_me);

						arrayLeft.erase(arrayLeft.begin());



					}
				}

			}


			else if (arrayRight.size() == 2 && arrayLeft.size() == 1)

			{

				StampDiff = arrayLeft[0].header.stamp - arrayRight[0].header.stamp;

				if (StampDiff >= TimeZero)
				{
					StampComp = StampDiff;
		  		}
				else
				{
					StampComp = -StampDiff;
				}


				if (StampComp <= TimeOffset)
				{

//-------------------------------------------------------------------------------------------------
//  Two messages available on Left lane topic and 1 message on right lane topic. So, we fill in
//  the report with the first message that arrived on the left lane topic and the only message
//  on the right lane.
//-------------------------------------------------------------------------------------------------

//HEADER -- Left for now

                         		laneAlignmentReport_me.header = arrayLeft[0].header;

//-------------------------------------------------------------------------------------------------
//LEFT FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
					//Lane type
					laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
					//Quality
					laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
					//Model Degree
					laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
					//Position Parameter C0
					laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
					//Curvature Parameter C2
					laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
					//Curvature Derivative Parameter C3
					laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
					//Marking Width
					laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
					//Heading Angle Parameter C1
					laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
					//View Range
					laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
					//View Range Availability
					laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//RIGHT FILL --------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
					//Lane type
					laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
					//Quality
					laneAlignmentReport_me.right_quality = arrayRight[0].quality;
					//Model Degree
					laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
					//Position Parameter C0
					laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
					//Curvature Parameter C2
					laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
					//Curvature Derivative Parameter C3
					laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
					//Marking Width
					laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
					//Heading Angle Parameter C1
					laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
					//View Range
					laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
					//View Range Availability
					laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;


					//PUBLISH---------------------------------------
					pubLaneAlignedReport.publish(laneAlignmentReport_me);

					arrayRight.erase(arrayRight.begin());
					arrayLeft.pop_back();

				}

				else
				{

					if (arrayRight[0].header.stamp < arrayLeft[0].header.stamp)
					{

//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp greater than the
//  considered TimeOffset. Left lane message arrived before Right so, Left lane info included in report
//  while all Right lane info set to 0
//-------------------------------------------------------------------------------------------------
						//HEADER -- Right

						laneAlignmentReport_me.header = arrayRight[0].header;
//-------------------------------------------------------------------------------------------------
//Right FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
						//Lane type
						laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
						//Quality
						laneAlignmentReport_me.right_quality = arrayRight[0].quality;
						//Model Degree
						laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
						//Position Parameter C0
						laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
						//Curvature Parameter C2
						laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
						//Marking Width
						laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
						//View Range
						laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
						//View Range Availability
						laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//All Left --> 0   -------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

						laneAlignmentReport_me.left_lane_type = 0;
						//Quality
						laneAlignmentReport_me.left_quality = 0;
						//Model Degree
						laneAlignmentReport_me.left_model_degree = 0;
						//Position Parameter C0
						laneAlignmentReport_me.left_position_parameter_c0 = 0;
						//Curvature Parameter C2
						laneAlignmentReport_me.left_curvature_parameter_c2 = 0;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = 0;
						//Marking Width
						laneAlignmentReport_me.left_marking_width = 0;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.left_heading_angle_parameter_c1 = 0;
						//View Range
						laneAlignmentReport_me.left_view_range = 0;
						//View Range Availability
						laneAlignmentReport_me.left_view_range_availability = false;

						//PUBLISH---------------------------------------
						pubLaneAlignedReport.publish(laneAlignmentReport_me);

						arrayRight.erase(arrayRight.begin());
//*********************

						StampDiff = arrayLeft[0].header.stamp - arrayRight[0].header.stamp;

						if (StampDiff >= TimeZero)
						{
							StampComp = StampDiff;
				  		}
						else
						{
							StampComp = -StampDiff;
						}


						if (StampComp <= TimeOffset)
						{

//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp less than the
//  considered TimeOffset, So both Left and Right lane info included in report.
//-------------------------------------------------------------------------------------------------

							//HEADER -- Left for now

                            				laneAlignmentReport_me.header = arrayLeft[0].header;
//-------------------------------------------------------------------------------------------------
//LEFT FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
							//Lane type
							laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
							//Quality
							laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
							//Model Degree
							laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
							//Position Parameter C0
							laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
							//Curvature Parameter C2
							laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
							//Curvature Derivative Parameter C3
							laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
							//Marking Width
							laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
							//Heading Angle Parameter C1
							laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
							//View Range
							laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
							//View Range Availability
							laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;
//-------------------------------------------------------------------------------------------------
//RIGHT FILL --------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
							//Lane type
							laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
							//Quality
							laneAlignmentReport_me.right_quality = arrayRight[0].quality;
							//Model Degree
							laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
							//Position Parameter C0
							laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
							//Curvature Parameter C2
							laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
							//Curvature Derivative Parameter C3
							laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
							//Marking Width
							laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
							//Heading Angle Parameter C1
							laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
							//View Range
							laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
							//View Range Availability
							laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;

							//PUBLISH---------------------------------------
							pubLaneAlignedReport.publish(laneAlignmentReport_me);

							arrayLeft.pop_back();
							arrayRight.pop_back();

						}

						else
						{

							if (arrayLeft[0].header.stamp < arrayRight[0].header.stamp)
							{

//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp greater than the
//  considered TimeOffset. Left lane message arrived before Right so, Left lane info included in report
//  while all Right lane info set to 0
//-------------------------------------------------------------------------------------------------
								//HEADER -- Left

								laneAlignmentReport_me.header = arrayLeft[0].header;
//-------------------------------------------------------------------------------------------------
//LEFT FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
								//Lane type
								laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
								//Quality
								laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
								//Model Degree
								laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
								//Position Parameter C0
								laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
								//Curvature Parameter C2
								laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
								//Curvature Derivative Parameter C3
								laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
								//Marking Width
								laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
								//Heading Angle Parameter C1
								laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
								//View Range
								laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
								//View Range Availability
								laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//All RIGHT --> 0   -------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

								laneAlignmentReport_me.right_lane_type = 0;
								//Quality
								laneAlignmentReport_me.right_quality = 0;
								//Model Degree
								laneAlignmentReport_me.right_model_degree = 0;
								//Position Parameter C0
								laneAlignmentReport_me.right_position_parameter_c0 = 0;
								//Curvature Parameter C2
								laneAlignmentReport_me.right_curvature_parameter_c2 = 0;
								//Curvature Derivative Parameter C3
								laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = 0;
								//Marking Width
								laneAlignmentReport_me.right_marking_width = 0;
								//Heading Angle Parameter C1
								laneAlignmentReport_me.right_heading_angle_parameter_c1 = 0;
								//View Range
								laneAlignmentReport_me.right_view_range = 0;
								//View Range Availability
								laneAlignmentReport_me.right_view_range_availability = false;

								//PUBLISH---------------------------------------
								pubLaneAlignedReport.publish(laneAlignmentReport_me);

								arrayLeft.pop_back();

							}

							else

							{

//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp greater than the
//  considered TimeOffset. Right lane message arrived before Left so, Right lane info included in report
//  while all Left lane info set to 0
//-------------------------------------------------------------------------------------------------

								 //HEADER -- Right

								laneAlignmentReport_me.header = arrayRight[0].header;

//-------------------------------------------------------------------------------------------------
//RIGHT FILL --------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
								//Lane type
								laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
								//Quality
								laneAlignmentReport_me.right_quality = arrayRight[0].quality;
								//Model Degree
								laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
								//Position Parameter C0
								laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
								//Curvature Parameter C2
								laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
								//Curvature Derivative Parameter C3
								laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
								//Marking Width
								laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
								//Heading Angle Parameter C1
								laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
								//View Range
								laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
								//View Range Availability
								laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;


//-------------------------------------------------------------------------------------------------
//All Left --> 0   --------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

								//Lane type
								laneAlignmentReport_me.left_lane_type = 0;
								//Quality
								laneAlignmentReport_me.left_quality = 0;
								//Model Degree
								laneAlignmentReport_me.left_model_degree = 0;
								//Position Parameter C0
								laneAlignmentReport_me.left_position_parameter_c0 = 0;
								//Curvature Parameter C2
								laneAlignmentReport_me.left_curvature_parameter_c2 = 0;
								//Curvature Derivative Parameter C3
								laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = 0;
								//Marking Width
								laneAlignmentReport_me.left_marking_width = 0;
								//Heading Angle Parameter C1
								laneAlignmentReport_me.left_heading_angle_parameter_c1 = 0;
								//View Range
								laneAlignmentReport_me.left_view_range = 0;
								//View Range Availability
								laneAlignmentReport_me.left_view_range_availability = false;


								//PUBLISH---------------------------------------
								pubLaneAlignedReport.publish(laneAlignmentReport_me);

								arrayRight.pop_back();


							}
						}

					}

					else

					{

//-------------------------------------------------------------------------------------------------
//  Message available on both Left and Right lane topic with a difference in timestamp greater than the
//  considered TimeOffset. Right lane message arrived before Left so, Right lane info included in report
//  while all Left lane info set to 0
//-------------------------------------------------------------------------------------------------

						 //HEADER -- Left

						laneAlignmentReport_me.header = arrayLeft[0].header;

//-------------------------------------------------------------------------------------------------
//Left FILL --------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
						//Lane type
						laneAlignmentReport_me.left_lane_type = arrayLeft[0].lane_type;
						//Quality
						laneAlignmentReport_me.left_quality = arrayLeft[0].quality;
						//Model Degree
						laneAlignmentReport_me.left_model_degree = arrayLeft[0].model_degree;
						//Position Parameter C0
						laneAlignmentReport_me.left_position_parameter_c0 = arrayLeft[0].position_parameter_c0;
						//Curvature Parameter C2
						laneAlignmentReport_me.left_curvature_parameter_c2 = arrayLeft[0].curvature_parameter_c2;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = arrayLeft[0].curvature_derivative_parameter_c3;
						//Marking Width
						laneAlignmentReport_me.left_marking_width = arrayLeft[0].marking_width;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.left_heading_angle_parameter_c1 = arrayLeft[0].heading_angle_parameter_c1;
						//View Range
						laneAlignmentReport_me.left_view_range = arrayLeft[0].view_range;
						//View Range Availability
						laneAlignmentReport_me.left_view_range_availability = arrayLeft[0].view_range_availability;


//-------------------------------------------------------------------------------------------------
//All Right --> 0   --------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

						//Lane type
						laneAlignmentReport_me.right_lane_type = 0;
						//Quality
						laneAlignmentReport_me.right_quality = 0;
						//Model Degree
						laneAlignmentReport_me.right_model_degree = 0;
						//Position Parameter C0
						laneAlignmentReport_me.right_position_parameter_c0 = 0;
						//Curvature Parameter C2
						laneAlignmentReport_me.right_curvature_parameter_c2 = 0;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = 0;
						//Marking Width
						laneAlignmentReport_me.right_marking_width = 0;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.right_heading_angle_parameter_c1 = 0;
						//View Range
						laneAlignmentReport_me.right_view_range = 0;
						//View Range Availability
						laneAlignmentReport_me.right_view_range_availability = false;


						//PUBLISH---------------------------------------
						pubLaneAlignedReport.publish(laneAlignmentReport_me);

						arrayLeft.pop_back();

						//case 2R0L

						//HEADER -- Right

						 laneAlignmentReport_me.header = arrayRight[0].header;

//-------------------------------------------------------------------------------------------------
//Right FILL ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
						//Lane type
						laneAlignmentReport_me.right_lane_type = arrayRight[0].lane_type;
						//Quality
						laneAlignmentReport_me.right_quality = arrayRight[0].quality;
						//Model Degree
						laneAlignmentReport_me.right_model_degree = arrayRight[0].model_degree;
						//Position Parameter C0
						laneAlignmentReport_me.right_position_parameter_c0 = arrayRight[0].position_parameter_c0;
						//Curvature Parameter C2
						laneAlignmentReport_me.right_curvature_parameter_c2 = arrayRight[0].curvature_parameter_c2;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.right_curvature_derivative_parameter_c3 = arrayRight[0].curvature_derivative_parameter_c3;
						//Marking Width
						laneAlignmentReport_me.right_marking_width = arrayRight[0].marking_width;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.right_heading_angle_parameter_c1 = arrayRight[0].heading_angle_parameter_c1;
						//View Range
						laneAlignmentReport_me.right_view_range = arrayRight[0].view_range;
						//View Range Availability
						laneAlignmentReport_me.right_view_range_availability = arrayRight[0].view_range_availability;

//-------------------------------------------------------------------------------------------------
//All Left --> 0   -------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

						//Lane type
						laneAlignmentReport_me.left_lane_type = 0;
						//Quality
						laneAlignmentReport_me.left_quality = 0;
						//Model Degree
						laneAlignmentReport_me.left_model_degree = 0;
						//Position Parameter C0
						laneAlignmentReport_me.left_position_parameter_c0 = 0;
						//Curvature Parameter C2
						laneAlignmentReport_me.left_curvature_parameter_c2 = 0;
						//Curvature Derivative Parameter C3
						laneAlignmentReport_me.left_curvature_derivative_parameter_c3 = 0;
						//Marking Width
						laneAlignmentReport_me.left_marking_width = 0;
						//Heading Angle Parameter C1
						laneAlignmentReport_me.left_heading_angle_parameter_c1 = 0;
						//View Range
						laneAlignmentReport_me.left_view_range = 0;
						//View Range Availability
						laneAlignmentReport_me.left_view_range_availability = false;

						//PUBLISH---------------------------------------
						pubLaneAlignedReport.publish(laneAlignmentReport_me);

						arrayRight.erase(arrayRight.begin());



					}
				}

			}



//---------------Case 21 (End) ------------------

	loop_rate.sleep();
    
	}

    return 0;
}




