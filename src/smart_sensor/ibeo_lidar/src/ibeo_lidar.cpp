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
#include "network_interface/TCPFrame.h"
#include "sensor_msgs/PointCloud2.h"
#include "visualization_msgs/MarkerArray.h"

#include <pcl_conversions/pcl_conversions.h>
#include <pcl_msgs/PointIndices.h>
#include <pcl_msgs/ModelCoefficients.h>
#include <pcl_msgs/PolygonMesh.h>
#include <pcl_msgs/Vertices.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_ros/transforms.h>
#include <pcl/PCLPointCloud2.h>

#include <boost/foreach.hpp>

//message_project_s
#include<message_project_s/ObstacleAlignmentReport_1.h>
#include<message_project_s/ObstacleAlignment_1.h>

//IBEO_LIDAR
#include <ibeo_msgs/CameraImage.h>
#include <ibeo_msgs/ContourPointSigma.h>
#include <ibeo_msgs/DeviceStatus.h>
#include <ibeo_msgs/ErrorWarning.h>
#include <ibeo_msgs/HostVehicleState2805.h>
#include <ibeo_msgs/HostVehicleState2806.h>
#include <ibeo_msgs/HostVehicleState2807.h>
#include <ibeo_msgs/IbeoDataHeader.h>
#include <ibeo_msgs/MountingPositionF.h>
#include <ibeo_msgs/Object2221.h>
#include <ibeo_msgs/Object2225.h>
#include <ibeo_msgs/Object2270.h>
#include <ibeo_msgs/Object2271.h>
#include <ibeo_msgs/Object2280.h>
#include <ibeo_msgs/ObjectData2221.h>
#include <ibeo_msgs/ObjectData2225.h>
#include <ibeo_msgs/ObjectData2270.h>
#include <ibeo_msgs/ObjectData2271.h>
#include <ibeo_msgs/ObjectData2280.h>
#include <ibeo_msgs/Point2Df.h>
#include <ibeo_msgs/Point2Di.h>
#include <ibeo_msgs/Point2Dui.h>
#include <ibeo_msgs/ResolutionInfo.h>
#include <ibeo_msgs/ScanData2202.h>
#include <ibeo_msgs/ScanData2204.h>
#include <ibeo_msgs/ScanData2205.h>
#include <ibeo_msgs/ScanData2208.h>
#include <ibeo_msgs/ScannerInfo2204.h>
#include <ibeo_msgs/ScannerInfo2205.h>
#include <ibeo_msgs/ScanPoint2202.h>
#include <ibeo_msgs/ScanPoint2204.h>
#include <ibeo_msgs/ScanPoint2205.h>
#include <ibeo_msgs/ScanPoint2208.h>
#include <ibeo_msgs/Sigma2D.h>
#include <ibeo_msgs/Size2D.h>
#include <ibeo_msgs/TrackedProperties.h>
#include <ibeo_msgs/UntrackedProperties.h>
#include <ibeo_msgs/Velocity2D.h>

// Offsets 

geometry_msgs::Point offset_ibeo;
geometry_msgs::Point euler_ibeo;


//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------

network_interface::TCPFrame tcp_tx;

visualization_msgs::MarkerArray objects;

visualization_msgs::Marker object_contour_points;

sensor_msgs::PointCloud2 point_cloud;

pcl::PointCloud < pcl::PointXYZL > pcl_cloud;

ibeo_msgs::CameraImage camera_image;

ibeo_msgs::ScanData2205 scan_data_2205;

ibeo_msgs::ObjectData2280 object_data_2280;

ibeo_msgs::HostVehicleState2807 host_vehicle_state_2807;


//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------

message_project_s::ObstacleAlignmentReport_1 localAlignmentReport_ibeo;
message_project_s::ObstacleAlignment_1 tempObstacleAlignment_ibeo;

//-------------------------------------------------------------------------------------------------
// local CallBack
//-------------------------------------------------------------------------------------------------

void tcptxDataCallback(const network_interface::TCPFrame::ConstPtr& buffer)
{
	tcp_tx = *buffer;
}

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

bool received = false;
void pointcloudDataCallback(const sensor_msgs::PointCloud2::ConstPtr& buffer)
{	
        point_cloud = *buffer;                      
        received = true;    
}

void objectsDataCallback(const visualization_msgs::MarkerArray::ConstPtr& buffer)
{
	objects = *buffer;
}

void objectcontourpointsDataCallback(const visualization_msgs::Marker::ConstPtr& buffer)
{
	object_contour_points = *buffer;
}


void scandata2205DataCallback(const ibeo_msgs::ScanData2205::ConstPtr& buffer)
{
	scan_data_2205 = *buffer;
}

//Callback function for Object Data

bool received_object_data_2280 = false;
void objectdata2280DataCallback(const ibeo_msgs::ObjectData2280::ConstPtr& buffer)
{
	object_data_2280 = *buffer;
        received_object_data_2280 = true;
}


//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
	 
	
	ros::init(argc, argv, std::string("Ibeo_Lidar_node"));
	ros::NodeHandle n;

  
//-------------------------------------------------------------------------------------------------
// Subscribers
//-------------------------------------------------------------------------------------------------
  
	ros::Subscriber sub_tcp_tx                  = n.subscribe(std::string("/tcp_tx") , 1, tcptxDataCallback);
	ros::Subscriber sub_point_cloud             = n.subscribe(std::string("/as_tx/point_cloud") , 1, pointcloudDataCallback);
	ros::Subscriber sub_objects                 = n.subscribe(std::string("/as_tx/objects") , 1, objectsDataCallback);
	ros::Subscriber sub_object_contour_points   = n.subscribe(std::string("/as_tx/object_contour_points") , 1, objectcontourpointsDataCallback);
	ros::Subscriber sub_scan_data_2205          = n.subscribe(std::string("/parsed_tx/scan_data_2205") , 1, scandata2205DataCallback);
	ros::Subscriber sub_object_data_2280        = n.subscribe(std::string("/parsed_tx/object_data_2280") , 1, objectdata2280DataCallback);
	

//-------------------------------------------------------------------------------------------------
// Publisher
//-------------------------------------------------------------------------------------------------

	ros::Publisher pubAlignedReport = n.advertise<message_project_s::ObstacleAlignmentReport_1>(std::string("/lidar_obstacles_align_data"), 1);
  


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

//-------------------------------------------------------------------------------------------------
// Spatial Alignment Offsets
//-------------------------------------------------------------------------------------------------


	if (n.hasParam("/lidar/offset_x"))
		n.getParam("/lidar/offset_x", offset_ibeo.x);
	if (n.hasParam("/lidar/offset_y"))
		n.getParam("/lidar/offset_y", offset_ibeo.y);
	if (n.hasParam("/lidar/offset_z"))
		n.getParam("/lidar/offset_z", offset_ibeo.z);

	if (n.hasParam("/lidar/yaw"))
		n.getParam("/lidar/yaw", euler_ibeo.x);
	if (n.hasParam("/lidar/pitch"))
		n.getParam("/lidar/pitch", euler_ibeo.y);
	if (n.hasParam("/lidar/roll"))
		n.getParam("/lidar/roll", euler_ibeo.z);

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//Declaration for Variance calculation 
//-------------------------------------------------------------------------------------------------

	double variance_pos_x = pow(0.2,2); 
	double variance_pos_y = pow(0.2,2); 

	double variance_vel_x = pow(0.25,2); 
	double variance_vel_y = pow(15,2);

//-------------------------------------------------------------------------------------------------



	while(n.ok())

	{
		ros::spinOnce();
                
                if (received_object_data_2280)

		{ 

			// Initialize "current_time" with the current ROS machine time.Receive_time or time of data reception by ROS node
		      	ros::Time current_time = ros::Time::now();
	       
		  	// Gives the cycle time 
		  	double cycle_time = (current_time - begin).toSec(); 

		  	//clk_offset represent the time_shift_raw: time_shift_raw = Receive_Time(ROS) - Sensor Timestamp - latency - Jitter
		   	double clk_offset  = (current_time - object_data_2280.header.stamp - Latency).toSec();

		  	// Implement 1st order low-pass filter (Exponential Filter / Smoothing). Gain K = Exp (-cycle_time/Time_constant). 
		    	double K = exp(-cycle_time/0.100);

		   	// Filter state output at time step (Ti) is given as: State(Ti) = K * State(Ti - 1) + (1 - K) * Input (Ti)
		   	clk_offset  = (1.0-K)*clk_offset;
	 	   	clk_offset +=      K *clk_offset_mean.toSec();

		   	// Here we obtain the time shift between the sensor and ROS clock
		   	clk_offset_mean = ros::Duration(clk_offset);   

			// Final Aligned Timestamp 
		   	object_data_2280.header.stamp += clk_offset_mean;
		    

		  	localAlignmentReport_ibeo.header = object_data_2280.header;
	  
		      	localAlignmentReport_ibeo.ObstacleAlignement_1.clear();

			//QTYObstacles
			localAlignmentReport_ibeo.QtyObstacles.data = object_data_2280.objects.size();


			for(int oidx = 0;oidx<object_data_2280.objects.size();oidx++)
              
			{


//------------------------------------------------------------------------------------------------------------------------					
				std::cout<<"ID: "<<object_data_2280.objects[oidx].id<<"  ";

//-----------------------------	ALIGNMENT -------------------------------------------------------

				float Xalign, Yalign;				
				
				// C Center of object bounding box
				float Xc = (object_data_2280.objects[oidx].object_box_center.x);
				float Yc = (object_data_2280.objects[oidx].object_box_center.y);

				//Orientation of Box
				float Theta = (object_data_2280.objects[oidx].object_box_orientation_angle);

				//Dimensions of Box
				float Size_x = (object_data_2280.objects[oidx].object_box_size.x);
				float Size_y = (object_data_2280.objects[oidx].object_box_size.y);

				//Position of Ibeo sensor
				float Xs = 0;
				float Ys = 0; 

				//unit vector corresponding to box orientation and Size_x 
				float U1 = cos(Theta);
				float U2 = sin(Theta);

				//unit vector normal to , corresponding to Size_y
				float V1 = (-1)*sin(Theta);
				float V2 = cos(Theta);

				//R -> unit vector of object direction from sensor position S 
				float X1 = (Xc - Xs); 
				float Y1 = (Yc - Ys);
				
				float R1 = (X1)/sqrt((pow(X1,2)) + (pow(Y1,2)));
				float R2 = (Y1)/sqrt((pow(X1,2)) + (pow(Y1,2)));

				// (calibration corresponding to minimum ratio between object box sides lengths to select corner anchor point)
				float k = 0.5;

				//Scalar Products Computation R.U = R1.U1 + R2.U2				
				float RU = (R1*U1 + R2*U2);
	
				//Scalar Products Computation R.V = R1.V1 + R2.V2
				float RV = (R1*V1 + R2*V2);

				//Anchor Point Alignment 
				bool Bool_1, Bool_2;

				Bool_1 = ((k*fabs(RV)*Size_x) < (fabs(RU)*Size_y));
				std::cout<<"\nBool_1: "<<Bool_1<<std::endl;

				Bool_2 = ((k*fabs(RU)*Size_y) < (fabs(RV)*Size_x));
				std::cout<<"Bool_2: "<<Bool_2<<std::endl;
 				if(Size_x == 0 && Size_y == 0)
				{
					
					Xalign = Xc;
					Yalign = Yc;
                             	}

				else
				{	
					
					if(Bool_1 && Bool_2)
					//Case1: Anchor point for Alignment = box corner
					{

		Xalign = ( (Xc) - ((RU/fabs(RU)) * (Size_x/2) * (cos(Theta))) + ((RV/fabs(RV)) * (Size_y/2) * (sin(Theta))) );
		Yalign = ( (Yc) - ((RU/fabs(RU)) * (Size_x/2) * (sin(Theta))) - ((RV/fabs(RV)) * (Size_y/2) * (cos(Theta))) );
				
					} 

					else if(Bool_1 && !Bool_2)
					//Case2: Anchor point  = middle of "size_y side"
					{

		Xalign = ( (Xc) - ((RU/fabs(RU)) * (Size_x/2) * (cos(Theta))) );
		Yalign = ( (Yc) - ((RU/fabs(RU)) * (Size_x/2) * (sin(Theta))) );		
						
					}

					else if(!Bool_1 && Bool_2)
					//Case3: Anchor point  = middle of "size_x side"
					{

		Xalign = ( (Xc) + ((RV/fabs(RV)) * (Size_y/2) * (sin(Theta))) );
		Yalign = ( (Yc) - ((RV/fabs(RV)) * (Size_y/2) * (cos(Theta))) );					
					
					}	
					
				}	

				//Position - X and Y 
				tempObstacleAlignment_ibeo.obstaclePosition.position.x = Xalign;
		       		tempObstacleAlignment_ibeo.obstaclePosition.position.y = Yalign;

				std::cout<<"\nXalign: "<<Xalign<<std::endl;
				std::cout<<"Yalign: "<<Yalign<<std::endl;

//-----------------------------------------
				// Obstacle Center for Corner Computation
				tempObstacleAlignment_ibeo.obstacleBodyCenter.position.x = Xc;
		       		tempObstacleAlignment_ibeo.obstacleBodyCenter.position.y = Yc;
//-----------------------------------------


//-----------------------------------------------------------------------------------------------------	

/*
				//sign function 
				
				int sign; 
				 
				if(((object_data_2280.objects[oidx].object_box_center.x)*cos(object_data_2280.objects[oidx].object_box_orientation_angle)) + (object_data_2280.objects[oidx].object_box_center.y)*sin(object_data_2280.objects[oidx].object_box_orientation_angle) >= 0)

				{
				 sign = 1;
				}

				else

				{
				 sign = -1;
				}

				float xref, yref;

				//if (object_data_2280.objects[oidx].reference_point_location == 9)

				//{
   					xref = ((object_data_2280.objects[oidx].object_box_center.x) - sign*((object_data_2280.objects[oidx].object_box_size.x/2)*cos(object_data_2280.objects[oidx].object_box_orientation_angle)));

   					yref = ((object_data_2280.objects[oidx].object_box_center.y) - sign*((object_data_2280.objects[oidx].object_box_size.x/2)*sin(object_data_2280.objects[oidx].object_box_orientation_angle)));


					//Position - X and Y 
					tempObstacleAlignment_ibeo.obstaclePosition.position.x = xref;
			       		tempObstacleAlignment_ibeo.obstaclePosition.position.y = yref;
				//}

				//else

				//{
				//Position - X and Y 
				//std::cout<<"else ref point: "<<object_data_2280.objects[oidx].reference_point_location<<std::endl;

				float postx_without_offset = ( object_data_2280.objects[oidx].object_box_center.x); 			       	

				tempObstacleAlignment_ibeo.obstaclePosition.position.x = ( object_data_2280.objects[oidx].object_box_center.x + offset_ibeo.x );
			       	tempObstacleAlignment_ibeo.obstaclePosition.position.y = ( object_data_2280.objects[oidx].object_box_center.y + offset_ibeo.y );

				}
*/

//------------------------------------------------------------------------------------------------------------------------

				//Header
			       	tempObstacleAlignment_ibeo.header = object_data_2280.header;

				//Track ID
			       	tempObstacleAlignment_ibeo.id.data = object_data_2280.objects[oidx].id;
				
				//Position variance sigma_pos_x and sigma_pos_y = 0.2
				tempObstacleAlignment_ibeo.obstaclePoseVariance.position.x = variance_pos_x;
			 	tempObstacleAlignment_ibeo.obstaclePoseVariance.position.y = variance_pos_y;
			
				//Object Classification
			       	tempObstacleAlignment_ibeo.obstacleType = object_data_2280.objects[oidx].classification;

				//Object Classification Certainty
			       	tempObstacleAlignment_ibeo.classificationProbability = object_data_2280.objects[oidx].classification_certainty;

				//Absolute Velocity - X and Y
				tempObstacleAlignment_ibeo.obstacleVelocity.linear.x = object_data_2280.objects[oidx].absolute_velocity.x;
				tempObstacleAlignment_ibeo.obstacleVelocity.linear.y = object_data_2280.objects[oidx].absolute_velocity.y;

				//Absolute Velocity Variance - X and Y
				tempObstacleAlignment_ibeo.obstacleVelocityVariance.linear.x = pow(object_data_2280.objects[oidx].absolute_velocity_sigma.x,2);
				tempObstacleAlignment_ibeo.obstacleVelocityVariance.linear.y = pow(object_data_2280.objects[oidx].absolute_velocity_sigma.y,2);

				//Relative Velocity - X and Y
				tempObstacleAlignment_ibeo.obstacleRelativeVelocity.linear.x = object_data_2280.objects[oidx].relative_velocity.x;
				tempObstacleAlignment_ibeo.obstacleRelativeVelocity.linear.y = object_data_2280.objects[oidx].relative_velocity.y;

/*
				//Relative Velocity Variance - X and Y
				tempObstacleAlignment_ibeo.obstacleRelativeVelocityVariance.linear.x = pow(object_data_2280.objects[oidx].relative_velocity_sigma.x,2);
				tempObstacleAlignment_ibeo.obstacleRelativeVelocityVariance.linear.y = pow(object_data_2280.objects[oidx].relative_velocity_sigma.y,2);

*/

				//Relative Velocity variance sigma_vel_x = 0.25 and sigma_vel_y = 15

				tempObstacleAlignment_ibeo.obstacleRelativeVelocityVariance.linear.x = variance_vel_x;
			 	tempObstacleAlignment_ibeo.obstacleRelativeVelocityVariance.linear.y = variance_vel_y;

				//Object Age
				tempObstacleAlignment_ibeo.obstacleAge = object_data_2280.objects[oidx].object_age;

				//Object Orientation Angle 
				tempObstacleAlignment_ibeo.obstacleAngle = object_data_2280.objects[oidx].object_box_orientation_angle;

				//Object Orientation Angle Variance 
				tempObstacleAlignment_ibeo.obstacleAngleVariance = pow(object_data_2280.objects[oidx].object_box_orientation_angle_sigma, 2);

				//Object Size
				tempObstacleAlignment_ibeo.obstacleDimensions.x = object_data_2280.objects[oidx].object_box_size.x;
				tempObstacleAlignment_ibeo.obstacleDimensions.y = object_data_2280.objects[oidx].object_box_size.y;

//-------------------------------------------------------------------------------------------------
// Info Unavailable
//-------------------------------------------------------------------------------------------------

/*				
				//Obstacle Acceleration
			       	tempObstacleAlignment_ibeo.obstacleAcceleration.linear.x= tempObstacleAlignment_ibeo.obstacleAcceleration_linear_Unknown;
				tempObstacleAlignment_ibeo.obstacleAcceleration.linear.y= tempObstacleAlignment_ibeo.obstacleAcceleration_linear_Unknown;
				tempObstacleAlignment_ibeo.obstacleAcceleration.linear.z= tempObstacleAlignment_ibeo.obstacleAcceleration_linear_Unknown;
	
				tempObstacleAlignment_ibeo.obstacleAcceleration.angular.x= tempObstacleAlignment_ibeo.obstacleAcceleration_angular_Unknown;
				tempObstacleAlignment_ibeo.obstacleAcceleration.angular.y= tempObstacleAlignment_ibeo.obstacleAcceleration_angular_Unknown;
				tempObstacleAlignment_ibeo.obstacleAcceleration.angular.z= tempObstacleAlignment_ibeo.obstacleAcceleration_angular_Unknown;

*/

				//Blinker Status 
				tempObstacleAlignment_ibeo.blinkerInfo = tempObstacleAlignment_ibeo.blinkerInfo_Unknown;

				//Cut_in_and_out
				tempObstacleAlignment_ibeo.cutInAndOut = tempObstacleAlignment_ibeo.cutInAndOut_Unknown;

				//Obstacle Status
				tempObstacleAlignment_ibeo.obstacleStatus  = tempObstacleAlignment_ibeo.obstacleStatus_Unknown;

				//Obstacle Brake Lights
				tempObstacleAlignment_ibeo.obstacleBrakeLights  = tempObstacleAlignment_ibeo.obstacleBrakeLights_Unknown;

				//Closest in Path Vehicle
				tempObstacleAlignment_ibeo.cipvFlag  = tempObstacleAlignment_ibeo.cipvFlag_Unknown;

				//Obstacle Replaced
				tempObstacleAlignment_ibeo.obstacleReplaced  = tempObstacleAlignment_ibeo.obstacleReplaced_Unknown;

				//Obstacle Valid
				tempObstacleAlignment_ibeo.obstacleValid  = tempObstacleAlignment_ibeo.obstacleValid_Unknown;

				//Obstacle Lane
				tempObstacleAlignment_ibeo.obstacleLane  = tempObstacleAlignment_ibeo.obstacleLane_Unknown;

				//Obstacle Angle Rate (degree/sec)
				tempObstacleAlignment_ibeo.obstacleAngleRate  = tempObstacleAlignment_ibeo.obstacleAngleRate_Unknown;

				//Obstacle Scale Change (pix/sec)
				tempObstacleAlignment_ibeo.obstacleScaleChange  = tempObstacleAlignment_ibeo.obstacleScaleChange_Unknown;

				//Traffic Sign Recognition (TSR) sign type   
				tempObstacleAlignment_ibeo.visionOnlySignType = tempObstacleAlignment_ibeo.visionOnlySignType_Unknown;

				//Supplementary sign type - rain, snow, arrow etc.
				tempObstacleAlignment_ibeo.visionOnlySupplementarySignType = tempObstacleAlignment_ibeo.visionOnlySupplementarySignType_Unknown;

				//Sign Position
				tempObstacleAlignment_ibeo.signPosition.x=tempObstacleAlignment_ibeo.signPosition_Unknown;
				tempObstacleAlignment_ibeo.signPosition.y=tempObstacleAlignment_ibeo.signPosition_Unknown;
				tempObstacleAlignment_ibeo.signPosition.z=tempObstacleAlignment_ibeo.signPosition_Unknown;

				//Filter
				tempObstacleAlignment_ibeo.filterType = tempObstacleAlignment_ibeo.filterType_Unknown;

				//Ground Height
			       	tempObstacleAlignment_ibeo.groundHeight.data = tempObstacleAlignment_ibeo.groundHeight_Unknown;

				//Date Acquisition
			       	tempObstacleAlignment_ibeo.dateAcquisition.data = tempObstacleAlignment_ibeo.dateAcquisition_Unknown;

			     	localAlignmentReport_ibeo.ObstacleAlignement_1.push_back(tempObstacleAlignment_ibeo);

				
			}

      			std::cout<<std::endl;

			// Publish final aligned data topic
		     	pubAlignedReport.publish(localAlignmentReport_ibeo);
		      	received_object_data_2280 = false;

               	}

                loop_rate.sleep();
        }

    return 0;
}			
           
