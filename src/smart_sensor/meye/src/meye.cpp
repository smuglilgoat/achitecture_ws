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
#include <derived_object_msgs/ObjectWithCovariance.h>
#include <derived_object_msgs/LaneModels.h>


// Offsets 

geometry_msgs::Point offset_meye;
geometry_msgs::Point euler_meye;

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
derived_object_msgs::LaneModels lane_models;
derived_object_msgs::ObjectWithCovariance objects;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------

message_project_s::ObstacleAlignmentReport_1 localAlignmentReport_me;
message_project_s::ObstacleAlignment_1 tempObstacleAlignment_me;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------

bool obstacledataReceived = false;
void obstacledataDataCallback(const mobileye_560_660_msgs::ObstacleData::ConstPtr& buffer)
{
	obstacle_data = *buffer;
   
        obstacledataReceived = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])

{

	ros::init(argc, argv, std::string("mobileye_me_node"));

	ros::NodeHandle n;

//-------------------------------------------------------------------------------------------------
// Subscribers
//-------------------------------------------------------------------------------------------------
	
	ros::Subscriber sub_obstacle_data  = n.subscribe(std::string("/mobileye/parsed_tx/obstacle_data"), 1, obstacledataDataCallback);
	
//-------------------------------------------------------------------------------------------------
// Publishers -- Obstacle
//-------------------------------------------------------------------------------------------------		

	ros::Publisher pubAlignedReport = n.advertise<message_project_s::ObstacleAlignmentReport_1>(std::string("/camera_me_obstacles_align_data"), 1); 

//-------------------------------------------------------------------------------------------------
// Time Alignment
//-------------------------------------------------------------------------------------------------

	// It is the time shift between the sensor clock and ROS clock which we need to estimate in order to successfully implement TIME ALIGNMENT.
	ros::Duration clk_offset_mean;
	
	// Latency
	ros::Duration Latency(0.001);

	// Intialize "begin" with the current ROS time which is needed to compute the cycle_time
	ros::Time begin ;
	begin = ros::Time::now();
	ros::Duration Diff(0.09);

	// Loop Rate
	ros::Rate loop_rate(1000);

	//Obstacle Array
	std::vector<mobileye_560_660_msgs::ObstacleData> arrayObstacle;
     
	ros::Time Start ;
	Start = ros::Time::now();

	ros::Time Stop ;

//-------------------------------------------------------------------------------------------------
// Spatial Alignment Offsets
//-------------------------------------------------------------------------------------------------

/*geometry_msgs::Point offset_meye;
offset_meye.x = 0;
offset_meye.y = 0;
offset_meye.z = 0; 
geometry_msgs::Point euler_meye;
euler_meye.x = 0;  //roll
euler_meye.y = 0;  //pitch
euler_meye.z = 0;  //yaw
*/

	if (n.hasParam("/mobil_eye/offset_x"))
		n.getParam("/mobil_eye/offset_x", offset_meye.x);
	if (n.hasParam("/mobil_eye/offset_y"))
		n.getParam("/mobil_eye/offset_y", offset_meye.y);
	if (n.hasParam("/mobil_eye/offset_z"))
		n.getParam("/mobil_eye/offset_z", offset_meye.z);

	if (n.hasParam("/mobil_eye/yaw"))
		n.getParam("/mobil_eye/yaw", euler_meye.x);
	if (n.hasParam("/mobil_eye/pitch"))
		n.getParam("/mobil_eye/pitch", euler_meye.y);
	if (n.hasParam("/mobil_eye/roll"))
		n.getParam("/mobil_eye/roll", euler_meye.z);

	
	while(n.ok())

        {
		ros::spinOnce();

		if(obstacledataReceived)
                     
                {  

			// Initialize "current_time" with the current ROS machine time. It is actually the Receive_time or time of data reception by ROS node
			ros::Time current_time = ros::Time::now();

			// Gives the cycle time 
			double cycle_time = (current_time - begin).toSec(); 

			// Here the clk_offset represent the time_shift_raw which is given as: time_shift_raw = Receive_Time(ROS) - Sensor Timestamp - latency - Jitter
			double clk_offset  = (current_time - obstacle_data.header.stamp - Latency).toSec();

			// Implement 1st order low-pass filter 
			double K = exp(-cycle_time/0.100);

			// Filter state output at time step (Ti) is given as: State(Ti) = K * State(Ti - 1) + (1 - K) * Input (Ti)
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_mean.toSec();

			// Here we obtain the time shift between the sensor and ROS clock
			clk_offset_mean = ros::Duration(clk_offset);

			// We obtain here the Final Aligned Timestamp by adding the time shift between the sensor and the ROS clock in the the timestamp of the measurements obtained by the sensor
			obstacle_data.header.stamp += clk_offset_mean;
			
			if (arrayObstacle.empty()) Start = ros::Time::now();
			//std::cout<<"id : "<<obstacle_data.obstacle_id;
			//std::cout<<"  timestamp : "<<obstacle_data.header.stamp<<std::endl;
			
			if (!arrayObstacle.empty())
			{
				bool found = false;
				for (int j = 0; j < arrayObstacle.size(); j++)
				{
					if (arrayObstacle[j].obstacle_id == obstacle_data.obstacle_id) found = true;
				}
				if (!found) arrayObstacle.push_back(obstacle_data);
			}
			else arrayObstacle.push_back(obstacle_data);

 			obstacledataReceived=false; 					
		}
	
		Stop = ros::Time::now();
		//std::cout<<"Stop : "<<Stop<<std::endl;	
		
		if(Stop - Start >= Diff)
                     
                {
 			if(!arrayObstacle.empty()) 
			{
			
			//std::cout<<"Stop - Start : "<<Stop - Start<<std::endl;

			//HEADER -- Report -- Obstacle for now
			localAlignmentReport_me.header=arrayObstacle[0].header;

			//std::cout<<"Array size : "<<arrayObstacle.size()<<std::endl;

			//for(int k =0; k<arrayObstacle.size();k++)
			//std::cout<<"ID : "<<arrayObstacle[k].obstacle_id<<"\n\n";

			localAlignmentReport_me.ObstacleAlignement_1.clear();

	
			//QTYObstacles 

			localAlignmentReport_me.QtyObstacles.data = arrayObstacle.size();
			std::cout<<"QTYObstacles MobilEye : " << arrayObstacle.size()<< std::endl;


			//-------------------------------------------------------------------------------------------------
			// Fill in ObstacleAlignment.msg ---- Obstacle Data  
			//-------------------------------------------------------------------------------------------------

			for(int i=0;i<arrayObstacle.size();i++)

		      	{

				std::cout<<arrayObstacle[i].obstacle_id<<"  ";

				//Header
				tempObstacleAlignment_me.header = arrayObstacle[i].header;
				    
				//Obstacle ID
				tempObstacleAlignment_me.id.data = arrayObstacle[i].obstacle_id;

				//Position-X and Y (meter)
				tempObstacleAlignment_me.obstaclePosition.position.x = (arrayObstacle[i].obstacle_pos_x + offset_meye.x); 

				/*std::cout<<"offset - X : " << offset_meye.x<< std::endl;
				std::cout<<"offset - Y : " << offset_meye.y<< std::endl;
				std::cout<<"offset - Z : " << offset_meye.z<< std::endl;
				std::cout<<"Position OFFSET : " << tempObstacleAlignment_me.obstaclePosition.position.x<< std::endl;
				std::cout<<"Position Without OFFSET : " << arrayObstacle[i].obstacle_pos_x<< std::endl;*/

				tempObstacleAlignment_me.obstaclePosition.position.y = (arrayObstacle[i].obstacle_pos_y + offset_meye.y); 

				//Relative Velocity-X (meter/sec)
				tempObstacleAlignment_me.obstacleRelativeVelocity.linear.x = arrayObstacle[i].obstacle_rel_vel_x;
					 
				//Acceleration-X (meter/sec2)
				tempObstacleAlignment_me.obstacleAcceleration.linear.x = arrayObstacle[i].object_accel_x;

				//Obstacle Dimension-Length and Width (meter)
				tempObstacleAlignment_me.obstacleDimensions.x = arrayObstacle[i].obstacle_length;
				tempObstacleAlignment_me.obstacleDimensions.y = arrayObstacle[i].obstacle_width;

				//Blinker Status 
				tempObstacleAlignment_me.blinkerInfo = arrayObstacle[i].blinker_info;

				//Cut_in_and_out
				tempObstacleAlignment_me.cutInAndOut = arrayObstacle[i].cut_in_and_out;

				//Obstacle Classification
				tempObstacleAlignment_me.obstacleType  = arrayObstacle[i].obstacle_type;

				//Obstacle Status
				tempObstacleAlignment_me.obstacleStatus  = arrayObstacle[i].obstacle_status;

				//Obstacle Brake Lights
				tempObstacleAlignment_me.obstacleBrakeLights  = arrayObstacle[i].obstacle_brake_lights;

				//Closest in Path Vehicle
				tempObstacleAlignment_me.cipvFlag  = arrayObstacle[i].cipv_flag;

				//Obstacle Replaced
				tempObstacleAlignment_me.obstacleReplaced  = arrayObstacle[i].obstacle_replaced;

				//Obstacle Valid
				tempObstacleAlignment_me.obstacleValid  = arrayObstacle[i].obstacle_valid;

				//Obstacle Age
				tempObstacleAlignment_me.obstacleAge  = arrayObstacle[i].obstacle_age;

				//Obstacle Lane
				tempObstacleAlignment_me.obstacleLane  = arrayObstacle[i].obstacle_lane;

				//Obstacle Angle (degree)
				tempObstacleAlignment_me.obstacleAngle  = arrayObstacle[i].obstacle_angle;

				//Obstacle Angle Rate (degree/sec)
				tempObstacleAlignment_me.obstacleAngleRate  = arrayObstacle[i].obstacle_angle_rate;

				//Obstacle Scale Change (pix/sec)
				tempObstacleAlignment_me.obstacleScaleChange  = arrayObstacle[i].obstacle_scale_change;

//-------------------------------------------------------------------------------------------------
// Info Unavailable (TSR also in this implementation)
//-------------------------------------------------------------------------------------------------

				//Velocity-X and Y 
			       	//tempObstacleAlignment_me.obstacleVelocity.linear.x=tempObstacleAlignment_me.obstacleVelocity_linear_Unknown;
			       	//tempObstacleAlignment_me.obstacleVelocity.linear.y=tempObstacleAlignment_me.obstacleVelocity_linear_Unknown;
				//tempObstacleAlignment_me.obstacleVelocity.linear.z=tempObstacleAlignment_me.obstacleVelocity_linear_Unknown;

				//tempObstacleAlignment_me.obstacleVelocity.angular.x=tempObstacleAlignment_me.obstacleVelocity_angular_Unknown;
				//tempObstacleAlignment_me.obstacleVelocity.angular.y=tempObstacleAlignment_me.obstacleVelocity_angular_Unknown;
				//tempObstacleAlignment_me.obstacleVelocity.angular.z=tempObstacleAlignment_me.obstacleVelocity_angular_Unknown;

				//Obstacle Angle Variance 
				tempObstacleAlignment_me.obstacleAngleVariance = tempObstacleAlignment_me.obstacleAngleVariance_Unknown;

				//Traffic Sign Recognition (TSR) sign type   
				tempObstacleAlignment_me.visionOnlySignType= tempObstacleAlignment_me.visionOnlySignType_Unknown;

				//Supplementary sign type - rain, snow, arrow etc.
				tempObstacleAlignment_me.visionOnlySupplementarySignType= tempObstacleAlignment_me.visionOnlySupplementarySignType_Unknown;

				//Sign Position
				tempObstacleAlignment_me.signPosition.x=tempObstacleAlignment_me.signPosition_Unknown;
				tempObstacleAlignment_me.signPosition.y=tempObstacleAlignment_me.signPosition_Unknown;
				tempObstacleAlignment_me.signPosition.z=tempObstacleAlignment_me.signPosition_Unknown;

				//Filter
				tempObstacleAlignment_me.filterType = tempObstacleAlignment_me.filterType_Unknown;

				//Position Variance - X and Y 
			       	tempObstacleAlignment_me.obstaclePoseVariance.position.x = tempObstacleAlignment_me.obstaclePoseVariance_position_Unknown;
			       	tempObstacleAlignment_me.obstaclePoseVariance.position.y = tempObstacleAlignment_me.obstaclePoseVariance_position_Unknown;
				tempObstacleAlignment_me.obstaclePoseVariance.position.z = tempObstacleAlignment_me.obstaclePoseVariance_position_Unknown;

				tempObstacleAlignment_me.obstaclePoseVariance.orientation.x = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;
				tempObstacleAlignment_me.obstaclePoseVariance.orientation.y = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;
				tempObstacleAlignment_me.obstaclePoseVariance.orientation.z = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;
				tempObstacleAlignment_me.obstaclePoseVariance.orientation.w = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;

				//Absolute Velocity Variance - X and Y
				tempObstacleAlignment_me.obstacleVelocityVariance.linear.x = tempObstacleAlignment_me.obstacleVelocityVariance_linear_Unknown;
				tempObstacleAlignment_me.obstacleVelocityVariance.linear.y = tempObstacleAlignment_me.obstacleVelocityVariance_linear_Unknown;
				tempObstacleAlignment_me.obstacleVelocityVariance.linear.z = tempObstacleAlignment_me.obstacleVelocityVariance_linear_Unknown;

				tempObstacleAlignment_me.obstacleVelocityVariance.angular.x = tempObstacleAlignment_me.obstacleVelocityVariance_angular_Unknown;
				tempObstacleAlignment_me.obstacleVelocityVariance.angular.y = tempObstacleAlignment_me.obstacleVelocityVariance_angular_Unknown;
				tempObstacleAlignment_me.obstacleVelocityVariance.angular.z = tempObstacleAlignment_me.obstacleVelocityVariance_angular_Unknown;

				//Relative Velocity Variance - X and Y
				tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.x = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_linear_Unknown;
				tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.y = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_linear_Unknown;
				tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.z = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_linear_Unknown;

				tempObstacleAlignment_me.obstacleRelativeVelocityVariance.angular.x = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_angular_Unknown;
				tempObstacleAlignment_me.obstacleRelativeVelocityVariance.angular.y = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_angular_Unknown;
				tempObstacleAlignment_me.obstacleRelativeVelocityVariance.angular.z = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_angular_Unknown;



				//Classification probability
			       	tempObstacleAlignment_me.classificationProbability = tempObstacleAlignment_me.classificationProbability_Unknown;
				
				//Ground Height
			       	tempObstacleAlignment_me.groundHeight.data = tempObstacleAlignment_me.groundHeight_Unknown;

				//Date Acquisition
			       	tempObstacleAlignment_me.dateAcquisition.data = tempObstacleAlignment_me.dateAcquisition_Unknown;



				localAlignmentReport_me.ObstacleAlignement_1.push_back(tempObstacleAlignment_me);	
			}

			std::cout<<std::endl;

			// Publish final aligned data topic
	   		pubAlignedReport.publish(localAlignmentReport_me);

			//clear here
			arrayObstacle.clear();
			localAlignmentReport_me.QtyObstacles.data = 0;
						
         	}
		else
		{
			localAlignmentReport_me.ObstacleAlignement_1.clear();
			localAlignmentReport_me.QtyObstacles.data = 0;
			pubAlignedReport.publish(localAlignmentReport_me);
	
		}

		}
	loop_rate.sleep();
    
	}

    return 0;
}


