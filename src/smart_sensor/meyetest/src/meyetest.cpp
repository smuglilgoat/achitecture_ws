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

mobileye_560_660_msgs::ObstacleData obstacle_data;
mobileye_560_660_msgs::ObstacleStatus obstacle_status;

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

bool obstaclestatusReceived = false;
void obstaclestatusCallback(const mobileye_560_660_msgs::ObstacleStatus::ConstPtr& buffer)
{
	obstacle_status = *buffer;
   
        obstaclestatusReceived = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])

{

	ros::init(argc, argv, std::string("meyetest"));

	ros::NodeHandle n;

//-------------------------------------------------------------------------------------------------
// Subscribers
//-------------------------------------------------------------------------------------------------
	
	ros::Subscriber sub_obstacle_data  = n.subscribe(std::string("/mobileye/parsed_tx/obstacle_data"), 1, obstacledataDataCallback);
	ros::Subscriber sub_obstacle_status  = n.subscribe(std::string("/mobileye/parsed_tx/obstacle_status"), 1, obstaclestatusCallback);

//-------------------------------------------------------------------------------------------------
// Publishers -- Obstacle
//-------------------------------------------------------------------------------------------------		

	ros::Publisher pubAlignedReport = n.advertise<message_project_s::ObstacleAlignmentReport_1>(std::string("/camera_me_obstacles_align_data"), 1); 

//-------------------------------------------------------------------------------------------------
// Time Alignment
//-------------------------------------------------------------------------------------------------

	ros::Duration clk_offset_mean;
	ros::Duration Latency(0.001);
	ros::Time begin ;
	begin = ros::Time::now();
	ros::Rate loop_rate(100);

//-------------------------------------------------------------------------------------------------
// Spatial Alignment Offsets
//-------------------------------------------------------------------------------------------------
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

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//Declaration for Variance calculation 
//-------------------------------------------------------------------------------------------------

	double pos_x, pos_y, rel_vel_x; 
	double range, sigma_pos_x, sigma_pos_y, sigma_vel_x, sigma_vel_y, variance_pos_x, variance_pos_y, variance_vel_x, variance_vel_y;

//-------------------------------------------------------------------------------------------------

	
	while(n.ok())

        {
		ros::spinOnce();

		if(obstacledataReceived)

 		{  

			obstacledataReceived = false;
			
			ros::Time current_time = ros::Time::now();

			double cycle_time = (current_time - begin).toSec(); 

			double clk_offset  = (current_time - obstacle_data.header.stamp - Latency).toSec();

			double K = exp(-cycle_time/0.100);
			
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_mean.toSec();

			clk_offset_mean = ros::Duration(clk_offset);

			obstacle_data.header.stamp += clk_offset_mean;
				
			//HEADER -- Report
			localAlignmentReport_me.header=obstacle_data.header;

			//QTYObstacles 
			int number_of_obstacle = obstacle_status.num_obstacles, count = 0;

			std::vector<unsigned int> arrayObstacle_ID; 
			arrayObstacle_ID.push_back(obstacle_data.obstacle_id);

			//-------------------------------------------------------------------------------------------------
			// Fill in ObstacleAlignment.msg ---- Obstacle Data  
			//-------------------------------------------------------------------------------------------------

			//Header
			tempObstacleAlignment_me.header = obstacle_data.header;
			    
			//Obstacle ID
			tempObstacleAlignment_me.id.data = obstacle_data.obstacle_id;
			std::cout<<"ID : "<<obstacle_data.obstacle_id<<std::endl;

			//Position-X and Y (meter)

			pos_x = obstacle_data.obstacle_pos_x; 
			pos_y = obstacle_data.obstacle_pos_y;

			tempObstacleAlignment_me.obstaclePosition.position.x = (pos_x + offset_meye.x); 
			tempObstacleAlignment_me.obstaclePosition.position.y = (pos_y + offset_meye.y);

//-----------------------------------------
			// Obstacle Center for Corner Computation
			tempObstacleAlignment_me.obstacleBodyCenter.position.x = (pos_x + offset_meye.x); 
		       	tempObstacleAlignment_me.obstacleBodyCenter.position.y = (pos_y + offset_meye.y); 
//----------------------------------------- 

			//range calculation for std. dev.				
			range = sqrt(pow(pos_x,2) + pow(pos_y,2)); 

			std::cout<<"range: "<<range<<std::endl;
			std::cout<<"pos_x: "<<pos_x<<std::endl;
			std::cout<<"pos_y: "<<pos_y<<std::endl;

			//Computing the Standard Deviation - Position - X 
			if(range <= 15)
			{
			  sigma_pos_x = 1;
			}
			else if(range > 15 && range < 40)
			{
			  //linear interpolation between 15m and 40m
			  sigma_pos_x = (range + 10)/25; 
			}
			else if(range >= 40)
			{ 
			  sigma_pos_x = 2;
			}

			//Computing the Standard Deviation - Position - Y
			sigma_pos_y = std::max(0.15,(0.006*pos_x));

			//variance position
			variance_pos_x = pow(sigma_pos_x, 2);
			variance_pos_y = pow(sigma_pos_y, 2);


			//Relative Velocity-X (meter/sec)
			rel_vel_x = obstacle_data.obstacle_rel_vel_x;
			tempObstacleAlignment_me.obstacleRelativeVelocity.linear.x = rel_vel_x;

			//Computing the Standard Deviation - Rel. velocity - X 
			if(rel_vel_x <= 1)
			{
			  sigma_vel_x = 0.25;
			}
			else if(rel_vel_x > 1 && rel_vel_x < 2)
			{
			  //linear interpolation between 1m/s and 2m/s
			  sigma_vel_x = 0.75*rel_vel_x -0.5; 
			}
			else if(rel_vel_x >= 2)
			{ 
			  sigma_vel_x = 1;
			}

			//Computing the Standard Deviation - Rel. velocity - Y 
			sigma_vel_y = 15;

			//variance velocity
			variance_vel_x = pow(sigma_vel_x, 2);
			variance_vel_y = pow(sigma_vel_y, 2);



			//Position Variance - X and Y 
		       	tempObstacleAlignment_me.obstaclePoseVariance.position.x = variance_pos_x;
		       	tempObstacleAlignment_me.obstaclePoseVariance.position.y = variance_pos_y;



			//Relative Velocity Variance - X and Y
			tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.x = variance_vel_x;
			tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.y = variance_vel_y;



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


			//-------------------------------------------------------------------------------------------------
			// Info Unavailable (TSR also in this implementation)
			//-------------------------------------------------------------------------------------------------

		/*	//Velocity-X and Y 
		       	tempObstacleAlignment_me.obstacleVelocity.linear.x=tempObstacleAlignment_me.obstacleVelocity_linear_Unknown;
		       	tempObstacleAlignment_me.obstacleVelocity.linear.y=tempObstacleAlignment_me.obstacleVelocity_linear_Unknown;
			tempObstacleAlignment_me.obstacleVelocity.linear.z=tempObstacleAlignment_me.obstacleVelocity_linear_Unknown;

			tempObstacleAlignment_me.obstacleVelocity.angular.x=tempObstacleAlignment_me.obstacleVelocity_angular_Unknown;
			tempObstacleAlignment_me.obstacleVelocity.angular.y=tempObstacleAlignment_me.obstacleVelocity_angular_Unknown;
			tempObstacleAlignment_me.obstacleVelocity.angular.z=tempObstacleAlignment_me.obstacleVelocity_angular_Unknown;
		*/
			
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

/*			//Position Variance - X and Y 
		       	tempObstacleAlignment_me.obstaclePoseVariance.position.x = tempObstacleAlignment_me.obstaclePoseVariance_position_Unknown;
		       	tempObstacleAlignment_me.obstaclePoseVariance.position.y = tempObstacleAlignment_me.obstaclePoseVariance_position_Unknown;
			tempObstacleAlignment_me.obstaclePoseVariance.position.z = tempObstacleAlignment_me.obstaclePoseVariance_position_Unknown;

			tempObstacleAlignment_me.obstaclePoseVariance.orientation.x = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;
			tempObstacleAlignment_me.obstaclePoseVariance.orientation.y = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;
			tempObstacleAlignment_me.obstaclePoseVariance.orientation.z = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;
			tempObstacleAlignment_me.obstaclePoseVariance.orientation.w = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;

*/

			//Absolute Velocity Variance - X and Y
			tempObstacleAlignment_me.obstacleVelocityVariance.linear.x = tempObstacleAlignment_me.obstacleVelocityVariance_linear_Unknown;
			tempObstacleAlignment_me.obstacleVelocityVariance.linear.y = tempObstacleAlignment_me.obstacleVelocityVariance_linear_Unknown;
			tempObstacleAlignment_me.obstacleVelocityVariance.linear.z = tempObstacleAlignment_me.obstacleVelocityVariance_linear_Unknown;

			tempObstacleAlignment_me.obstacleVelocityVariance.angular.x = tempObstacleAlignment_me.obstacleVelocityVariance_angular_Unknown;
			tempObstacleAlignment_me.obstacleVelocityVariance.angular.y = tempObstacleAlignment_me.obstacleVelocityVariance_angular_Unknown;
			tempObstacleAlignment_me.obstacleVelocityVariance.angular.z = tempObstacleAlignment_me.obstacleVelocityVariance_angular_Unknown;


/*			//Relative Velocity Variance - X and Y
			tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.x = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_linear_Unknown;
			tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.y = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_linear_Unknown;
			tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.z = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_linear_Unknown;

			tempObstacleAlignment_me.obstacleRelativeVelocityVariance.angular.x = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_angular_Unknown;
			tempObstacleAlignment_me.obstacleRelativeVelocityVariance.angular.y = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_angular_Unknown;
			tempObstacleAlignment_me.obstacleRelativeVelocityVariance.angular.z = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_angular_Unknown;

*/


			//Classification probability
		       	tempObstacleAlignment_me.classificationProbability = tempObstacleAlignment_me.classificationProbability_Unknown;
			
			//Ground Height
		       	tempObstacleAlignment_me.groundHeight.data = tempObstacleAlignment_me.groundHeight_Unknown;

			//Date Acquisition
		       	tempObstacleAlignment_me.dateAcquisition.data = tempObstacleAlignment_me.dateAcquisition_Unknown;


			localAlignmentReport_me.ObstacleAlignement_1.push_back(tempObstacleAlignment_me);	

			count++;
		

			while(number_of_obstacle - count > 0)
		             
		        {  
				ros::spinOnce();

				number_of_obstacle = obstacle_status.num_obstacles;


				if(obstacledataReceived)
				{

		  			obstacledataReceived = false;

					bool found_id = false;

					for (int i = 0; i<arrayObstacle_ID.size(); i++)
					{
						if(arrayObstacle_ID[i] == obstacle_data.obstacle_id) found_id=true;
					}
		
					if(!found_id)
					{

						ros::Time current_time = ros::Time::now();

						double cycle_time = (current_time - begin).toSec(); 

						double clk_offset  = (current_time - obstacle_data.header.stamp - Latency).toSec();

						double K = exp(-cycle_time/0.100);
			
						clk_offset  = (1.0-K)*clk_offset;
						clk_offset +=      K *clk_offset_mean.toSec();

						clk_offset_mean = ros::Duration(clk_offset);

						obstacle_data.header.stamp += clk_offset_mean;

						arrayObstacle_ID.push_back(obstacle_data.obstacle_id);

						//-------------------------------------------------------------------------------------------------
						// Fill in ObstacleAlignment.msg ---- Obstacle Data  
						//-------------------------------------------------------------------------------------------------

						//Header
						tempObstacleAlignment_me.header = obstacle_data.header;
						    
						//Obstacle ID
						tempObstacleAlignment_me.id.data = obstacle_data.obstacle_id;
						std::cout<<"ID : "<<obstacle_data.obstacle_id<<std::endl;

						//Position-X and Y (meter)

						pos_x = obstacle_data.obstacle_pos_x; 
						pos_y = obstacle_data.obstacle_pos_y;

						tempObstacleAlignment_me.obstaclePosition.position.x = (pos_x + offset_meye.x); 
						tempObstacleAlignment_me.obstaclePosition.position.y = (pos_y + offset_meye.y); 

//-------------------------------------------------------
						// Obstacle Center for Corner Computation
						tempObstacleAlignment_me.obstacleBodyCenter.position.x = (pos_x + offset_meye.x); 
					       	tempObstacleAlignment_me.obstacleBodyCenter.position.y = (pos_y + offset_meye.y); 
//------------------------------------------------------

						//range calculation for std. dev.				
						range = sqrt(pow(pos_x,2) + pow(pos_y,2));

						std::cout<<"range: "<<range<<std::endl;
						std::cout<<"pos_x: "<<pos_x<<std::endl;
						std::cout<<"pos_y: "<<pos_y<<std::endl;

						//Computing the Standard Deviation - Position - X 
						if(range <= 15)
						{
						  sigma_pos_x = 1;
						}
						else if(range > 15 && range < 40)
						{
						  //linear interpolation between 15m and 40m
						  sigma_pos_x = (range + 10)/25; 
						}
						else if(range >= 40)
						{ 
						  sigma_pos_x = 2;
						}

						//Computing the Standard Deviation - Position - Y
						sigma_pos_y = std::max(0.15,(0.006*pos_x));


						//variance position
						variance_pos_x = pow(sigma_pos_x, 2);
						variance_pos_y = pow(sigma_pos_y, 2);

			 			//Relative Velocity-X (meter/sec)
						rel_vel_x = obstacle_data.obstacle_rel_vel_x;
						tempObstacleAlignment_me.obstacleRelativeVelocity.linear.x = rel_vel_x;

						//Computing the Standard Deviation - Rel. velocity - X 
						if(rel_vel_x <= 1)
						{
						  sigma_vel_x = 0.25;
						}
						else if(rel_vel_x > 1 && rel_vel_x < 2)
						{
						  //linear interpolation between 1m/s and 2m/s
			  			  sigma_vel_x = 0.75*rel_vel_x -0.5;  
						}
						else if(rel_vel_x >= 2)
						{ 
						  sigma_vel_x = 1;
						}

						//Computing the Standard Deviation - Rel. velocity - Y
						sigma_vel_y = 15;


						//variance velocity
						variance_vel_x = pow(sigma_vel_x, 2);
						variance_vel_y = pow(sigma_vel_y, 2);

						//Position Variance - X and Y 
					       	tempObstacleAlignment_me.obstaclePoseVariance.position.x = variance_pos_x;
					       	tempObstacleAlignment_me.obstaclePoseVariance.position.y = variance_pos_y;



						//Relative Velocity Variance - X and Y
						tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.x = variance_vel_x;
						tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.y = variance_vel_y;



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


						//-------------------------------------------------------------------------------------------------
						// Info Unavailable (TSR also in this implementation)
						//-------------------------------------------------------------------------------------------------

					/*	//Velocity-X and Y 
					       	tempObstacleAlignment_me.obstacleVelocity.linear.x=tempObstacleAlignment_me.obstacleVelocity_linear_Unknown;
					       	tempObstacleAlignment_me.obstacleVelocity.linear.y=tempObstacleAlignment_me.obstacleVelocity_linear_Unknown;
						tempObstacleAlignment_me.obstacleVelocity.linear.z=tempObstacleAlignment_me.obstacleVelocity_linear_Unknown;

						tempObstacleAlignment_me.obstacleVelocity.angular.x=tempObstacleAlignment_me.obstacleVelocity_angular_Unknown;
						tempObstacleAlignment_me.obstacleVelocity.angular.y=tempObstacleAlignment_me.obstacleVelocity_angular_Unknown;
						tempObstacleAlignment_me.obstacleVelocity.angular.z=tempObstacleAlignment_me.obstacleVelocity_angular_Unknown;
					*/
						
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

/*						//Position Variance - X and Y 
					       	tempObstacleAlignment_me.obstaclePoseVariance.position.x = tempObstacleAlignment_me.obstaclePoseVariance_position_Unknown;
					       	tempObstacleAlignment_me.obstaclePoseVariance.position.y = tempObstacleAlignment_me.obstaclePoseVariance_position_Unknown;
						tempObstacleAlignment_me.obstaclePoseVariance.position.z = tempObstacleAlignment_me.obstaclePoseVariance_position_Unknown;

						tempObstacleAlignment_me.obstaclePoseVariance.orientation.x = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;
						tempObstacleAlignment_me.obstaclePoseVariance.orientation.y = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;
						tempObstacleAlignment_me.obstaclePoseVariance.orientation.z = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;
						tempObstacleAlignment_me.obstaclePoseVariance.orientation.w = tempObstacleAlignment_me.obstaclePoseVariance_orientation_Unknown;

*/

						//Absolute Velocity Variance - X and Y
						tempObstacleAlignment_me.obstacleVelocityVariance.linear.x = tempObstacleAlignment_me.obstacleVelocityVariance_linear_Unknown;
						tempObstacleAlignment_me.obstacleVelocityVariance.linear.y = tempObstacleAlignment_me.obstacleVelocityVariance_linear_Unknown;
						tempObstacleAlignment_me.obstacleVelocityVariance.linear.z = tempObstacleAlignment_me.obstacleVelocityVariance_linear_Unknown;

						tempObstacleAlignment_me.obstacleVelocityVariance.angular.x = tempObstacleAlignment_me.obstacleVelocityVariance_angular_Unknown;
						tempObstacleAlignment_me.obstacleVelocityVariance.angular.y = tempObstacleAlignment_me.obstacleVelocityVariance_angular_Unknown;
						tempObstacleAlignment_me.obstacleVelocityVariance.angular.z = tempObstacleAlignment_me.obstacleVelocityVariance_angular_Unknown;



/*						//Relative Velocity Variance - X and Y
						tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.x = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_linear_Unknown;
						tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.y = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_linear_Unknown;
						tempObstacleAlignment_me.obstacleRelativeVelocityVariance.linear.z = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_linear_Unknown;

						tempObstacleAlignment_me.obstacleRelativeVelocityVariance.angular.x = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_angular_Unknown;
						tempObstacleAlignment_me.obstacleRelativeVelocityVariance.angular.y = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_angular_Unknown;
						tempObstacleAlignment_me.obstacleRelativeVelocityVariance.angular.z = tempObstacleAlignment_me.obstacleRelativeVelocityVariance_angular_Unknown;

*/


						//Classification probability
					       	tempObstacleAlignment_me.classificationProbability = tempObstacleAlignment_me.classificationProbability_Unknown;
			
						//Ground Height
					       	tempObstacleAlignment_me.groundHeight.data = tempObstacleAlignment_me.groundHeight_Unknown;

						//Date Acquisition
					       	tempObstacleAlignment_me.dateAcquisition.data = tempObstacleAlignment_me.dateAcquisition_Unknown;

						localAlignmentReport_me.ObstacleAlignement_1.push_back(tempObstacleAlignment_me);

						count++;

			}

			}
		}

			localAlignmentReport_me.QtyObstacles.data = count;

			// Publish final aligned data topic
	   		pubAlignedReport.publish(localAlignmentReport_me);
			localAlignmentReport_me.ObstacleAlignement_1.clear();
				
      		}


		else if(obstaclestatusReceived && obstacle_status.num_obstacles == 0)
		{
			obstaclestatusReceived=false;
		
			ros::Time current_time = ros::Time::now();

			double cycle_time = (current_time - begin).toSec(); 

			double clk_offset  = (current_time - obstacle_status.header.stamp - Latency).toSec();

			double K = exp(-cycle_time/0.100);
			
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_mean.toSec();

			clk_offset_mean = ros::Duration(clk_offset);

			obstacle_status.header.stamp += clk_offset_mean;
				
			//HEADER -- Report
			localAlignmentReport_me.header=obstacle_status.header;

			localAlignmentReport_me.ObstacleAlignement_1.clear();
			localAlignmentReport_me.QtyObstacles.data = 0;
			pubAlignedReport.publish(localAlignmentReport_me);
	
	 	}


		loop_rate.sleep();
	}

    return 0;
}




