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
#include <std_msgs/String.h>

#include "ros/ros.h"

#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"

#include "nav_msgs/Odometry.h"
#include <tf/transform_broadcaster.h>

#include "project_s_msgs/ObstacleSynchronizeReport.h"
#include "project_s_msgs/ObstacleFusionReport.h"
#include "project_s_msgs/GenericSmartData.h"
#include "project_s_msgs/ObstacleAlignmentReport.h"
#include <mobileye_560_660_msgs/ObstacleData.h>
#include <ibeo_msgs/Object2280.h>
#include <ibeo_msgs/ObjectData2280.h>
#include <radar_msgs/RadarStatus.h>
#include <radar_msgs/RadarErrorStatus.h>
#include <radar_msgs/RadarTrackArray.h>

#include<message_project_s/LaneAlignmentME_1.h>


//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------
// Mobileye Callbacks - ObstacleData Filter Data Lane Data
//-------------------------------------------------------------------------------------------------

project_s_msgs::ObstacleAlignmentReport ME_obstacles_filtering;

bool received_ME_obstacles_filtering = false;
void ME_obstacles_filtering_Callback(const project_s_msgs::ObstacleAlignmentReport::ConstPtr& msg)
{
	ME_obstacles_filtering = *msg;

	received_ME_obstacles_filtering = true;
}


mobileye_560_660_msgs::ObstacleData obstacle_data;

bool obstacledataReceived = false;
void meyeobstacleDataCallback(const mobileye_560_660_msgs::ObstacleData::ConstPtr& buffer)
{
	obstacle_data = *buffer;
   
        obstacledataReceived = true;
}


message_project_s::LaneAlignmentME_1 lane_data;
bool lanedataReceived = false;
void LaneDataCallback(const message_project_s::LaneAlignmentME_1::ConstPtr& buffer)
{
	lane_data = *buffer;
   
        lanedataReceived = true;
}


//-------------------------------------------------------------------------------------------------
// IBEO LIDAR Callbacks - ObjectData and Filter Data
//-------------------------------------------------------------------------------------------------

ibeo_msgs::ObjectData2280 object_data_2280;

bool received_object_data_2280 = false;
void lidarobjectDataCallback(const ibeo_msgs::ObjectData2280::ConstPtr& buffer)
{
	object_data_2280 = *buffer;
        received_object_data_2280 = true;
}


project_s_msgs::ObstacleAlignmentReport lidar_obstacles_filtering;
bool received_lidar_obstacles_filtering = false;
void lidar_obstacles_filtering_Callback(const project_s_msgs::ObstacleAlignmentReport::ConstPtr& msg)
{
	lidar_obstacles_filtering = *msg;

	received_lidar_obstacles_filtering = true;
}


//-------------------------------------------------------------------------------------------------
// ESR Callbacks - Filter, Tracks and Tracks text
//-------------------------------------------------------------------------------------------------

project_s_msgs::ObstacleAlignmentReport ESR_obstacles_filtering;
bool received_ESR_obstacles_filtering = false;
void ESR_obstacles_filtering_Callback(const project_s_msgs::ObstacleAlignmentReport::ConstPtr& msg)
{
	ESR_obstacles_filtering = *msg;

	received_ESR_obstacles_filtering = true;
}

radar_msgs::RadarTrackArray radar_tracks, radar_tracks_text;

bool received_radar_tracks=false;
void radartracksDataCallback(const radar_msgs::RadarTrackArray::ConstPtr& buffer)
{
	radar_tracks = *buffer;
        received_radar_tracks=true;
        
}

bool received_radar_tracks_text=false;
void radartrackstextDataCallback(const radar_msgs::RadarTrackArray::ConstPtr& buffer)
{
	radar_tracks_text = *buffer;
        received_radar_tracks_text=true;
        
}

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("smart_sensor_markers"));

	ros::NodeHandle n;




//------------------------------------------- MobilEye ---------------------------------------------------------------
	// Markers---Mobileye 
	visualization_msgs::Marker meye_obstacle_Markers;
	visualization_msgs::Marker meye_obstacle_Markers_text;
	visualization_msgs::Marker ME_obstacles_filtering_Marker;
	visualization_msgs::Marker ME_obstacles_filtering_Marker_text;

	//Marker - Lane 
	visualization_msgs::Marker lane_left_marker;
	visualization_msgs::Marker right_left_marker;	
	ros::Subscriber sub_lane = n.subscribe(std::string("/MobilEye_LaneAlignmentReport"), 1, LaneDataCallback);
	ros::Publisher pub_me_laneleftdata = n.advertise<visualization_msgs::Marker>(std::string("/Mobileye_LaneLeftData_Markers"), 1);
	ros::Publisher pub_me_lanerightdata = n.advertise<visualization_msgs::Marker>(std::string("/Mobileye_LaneRightData_Markers"), 1);


	//Mobileye - obstacle_data
	ros::Subscriber sub_me_obstacledata = n.subscribe(std::string("/mobileye/parsed_tx/obstacle_data"), 1, meyeobstacleDataCallback);
	ros::Publisher pub_me_obstacledata = n.advertise<visualization_msgs::Marker>(std::string("/Mobileye_ObstacleData_Markers"), 1);
	ros::Publisher pub_me_obstacledata_text = n.advertise<visualization_msgs::Marker>(std::string("/Mobileye_ObstacleData_Markers_Text"), 1);

	//Mobileye - obstacle Filtering data
	ros::Subscriber sub_ME_obstacles_filtering = n.subscribe(std::string("/camera_me_obstacles_filtering_data"), 1, ME_obstacles_filtering_Callback);
	ros::Publisher pub_ME_obstacles_filtering = n.advertise<visualization_msgs::Marker>(std::string("/camera_ME_obstacles_filtering_markers"), 1);
	ros::Publisher pub_ME_obstacles_filtering_text = n.advertise<visualization_msgs::Marker>(std::string("/camera_ME_obstacles_filtering_markers_text"), 1);

//------------------------------------------- IBEO ---------------------------------------------------------------
	// Markers---IBEO LIDAR
	visualization_msgs::Marker objectdata_2280_Markers;
	visualization_msgs::Marker lidar_obstacles_filtering_Marker;
	visualization_msgs::Marker lidar_Marker;
	visualization_msgs::MarkerArray lidar_bounding_box_Marker;


	//IBEO - objectdata 2280
	ros::Subscriber sub_lidar_objectdata = n.subscribe(std::string("/parsed_tx/object_data_2280"), 1, lidarobjectDataCallback);
	ros::Publisher pub_lidar_objectdata = n.advertise<visualization_msgs::Marker>(std::string("/Lidar_ObjectData_Markers"), 1);

	//IBEO - Filtering Data
ros::Subscriber sub_lidar_obstacles_filtering = n.subscribe(std::string("/lidar_obstacles_filtering_data"), 1, lidar_obstacles_filtering_Callback);
ros::Publisher pub_lidar_obstacles_filtering = n.advertise<visualization_msgs::Marker>(std::string("/lidar_obstacles_filtering_data_markers"), 1);

	//IBEO - Bounding Box
	ros::Publisher pub_lidar_bounding_box = n.advertise<visualization_msgs::MarkerArray>(std::string("/lidar_bounding_box_markers"), 1);

//---------------------------------------------------------------------------------------------------------------


//------------------------------------------- Delphi-ESR ----------------------------------------------------------
	// Markers---ESR 
	visualization_msgs::Marker ESR_obstacles_filtering_Marker;
	visualization_msgs::Marker radar_tracks_Marker;
	visualization_msgs::Marker radar_tracks_Marker_Text;

        //ESR - Filtering data
	ros::Subscriber sub_ESR_obstacles_filtering = n.subscribe(std::string("/radar_ESR_obstacles_filtering_data"), 1, ESR_obstacles_filtering_Callback);
	ros::Publisher pub_ESR_obstacles_filtering_rel = n.advertise<visualization_msgs::Marker>(std::string("/radar_ESR_obstacles_filtering_markers"), 1);

	//ESR - radar tracks data and text
	ros::Subscriber sub_radar_tracks = n.subscribe(std::string("/esr_1/as_tx/radar_tracks"), 1, radartracksDataCallback);
	ros::Subscriber sub_radar_tracks_text = n.subscribe(std::string("/esr_1/as_tx/radar_tracks"), 1, radartrackstextDataCallback);
	
	ros::Publisher pub_radar_tracks = n.advertise<visualization_msgs::Marker>(std::string("/Radar_Tracks_Markers"), 1);
	ros::Publisher pub_radar_tracks_text = n.advertise<visualization_msgs::Marker>(std::string("/Radar_Tracks_Markers_Text"), 1);
//---------------------------------------------------------------------------------------------------------------

	
	ros::Duration blink_of_an_eye(0.1); 

	ros::Rate loop_rate(100);

	while(n.ok())
	{
		ros::spinOnce();



//-------------------------------------------------------------------------------------------------
// Marker - MEye Lane
//-------------------------------------------------------------------------------------------------

	if (lanedataReceived)
	{
			lanedataReceived = false;

			lane_left_marker = visualization_msgs::Marker();
			lane_left_marker.header.frame_id = "/me_viz";
			lane_left_marker.header.stamp = ros::Time::now();
			lane_left_marker.lifetime = ros::Duration(1);
			lane_left_marker.id = 2;
			lane_left_marker.ns = "Left";
			lane_left_marker.action = visualization_msgs::Marker::MODIFY;
			lane_left_marker.pose.orientation.w = 1;

			//Marker type based on lane type
			if(lane_data.left_lane_type == 0)
			{
				lane_left_marker.type = visualization_msgs::Marker::LINE_LIST;
			}
			else
			{
				lane_left_marker.type = visualization_msgs::Marker::LINE_STRIP;
			}

			//Scale.x based on marking Width
			lane_left_marker.scale.x = lane_data.left_marking_width;
			lane_left_marker.scale.y = 0;
			lane_left_marker.scale.z = 0;

			//color based on Quality		
			if(lane_data.left_quality == 2)
			{
				lane_left_marker.color.r = 1.0f;
				lane_left_marker.color.g = 1.0f;
				lane_left_marker.color.b = 0.0f;
				lane_left_marker.color.a = 1.0;
			}
			
			else
			{
				lane_left_marker.color.r = 0.0f;
				lane_left_marker.color.g = 1.0f;
				lane_left_marker.color.b = 0.0f;
				lane_left_marker.color.a = 1.0;
			}

			//Interpolation From X=0 to X=30 for value of Y based on 3rd degree polynomial equation
			double C3_left = lane_data.left_curvature_derivative_parameter_c3;
			double C2_left = lane_data.left_curvature_parameter_c2;
			double C1_left = lane_data.left_heading_angle_parameter_c1;
			double C0_left = lane_data.left_position_parameter_c0;
			float range_left = floor(lane_data.left_view_range)+0.5;

			for (float i = 0; i <= range_left ; i+=0.5)
			{

				geometry_msgs::Point p;

				p.x = i;
				p.y = C3_left*pow(i,3)+C2_left*pow(i,2)+i*C1_left+C0_left;
				p.z = 0;

				lane_left_marker.points.push_back(p);
				
			
			}

				pub_me_laneleftdata.publish(lane_left_marker);
			

			right_left_marker = visualization_msgs::Marker();
			right_left_marker.header.frame_id = "/me_viz";
			right_left_marker.header.stamp = ros::Time::now();
			right_left_marker.lifetime = ros::Duration(1);
			right_left_marker.id = 1;
			right_left_marker.ns = "right";
			right_left_marker.action = visualization_msgs::Marker::MODIFY;
			right_left_marker.pose.orientation.w = 1;

			//Marker type based on lane type
		
			if(lane_data.right_lane_type  == 0)
			{
				right_left_marker.type = visualization_msgs::Marker::LINE_LIST;
			}
			else
			{
				right_left_marker.type = visualization_msgs::Marker::LINE_STRIP;
			}


			//Scale.x based on marking Width
			right_left_marker.scale.x = lane_data.right_marking_width;
			right_left_marker.scale.y = 0;
			right_left_marker.scale.z = 0;

			//color based on Quality		
			if(lane_data.right_quality == 2)
			{
				right_left_marker.color.r = 1.0f;
				right_left_marker.color.g = 1.0f;
				right_left_marker.color.b = 0.0f;
				right_left_marker.color.a = 1.0;
			}
			
			else
			{
				right_left_marker.color.r = 0.0f;
				right_left_marker.color.g = 1.0f;
				right_left_marker.color.b = 0.0f;
				right_left_marker.color.a = 1.0;
			}

			//Interpolation From X=0 to X=30 for value of Y based on 3rd degree polynomial equation
			double C3_right = lane_data.right_curvature_derivative_parameter_c3;
			double C2_right = lane_data.right_curvature_parameter_c2;
			double C1_right = lane_data.right_heading_angle_parameter_c1;
			double C0_right = lane_data.right_position_parameter_c0;
			float range_right = floor(lane_data.right_view_range)+0.5;

			for (float j = 0; j <= range_right ; j+=0.5)
			{

				geometry_msgs::Point p;

				p.x = j;
				p.y = C3_right*pow(j,3)+C2_right*pow(j,2)+j*C1_right+C0_right;
				p.z = 0;

				right_left_marker.points.push_back(p);
				
			
			}

				pub_me_lanerightdata.publish(right_left_marker);
			
	}


//-------------------------------------------------------------------------------------------------
// Marker - Mobileye  - Obstacle Filtering Data
//-------------------------------------------------------------------------------------------------

		if (received_ME_obstacles_filtering)
		{
			received_ME_obstacles_filtering = false;

			// Markers pour le repère relatif
			ME_obstacles_filtering_Marker = visualization_msgs::Marker();
			ME_obstacles_filtering_Marker.header.frame_id = "/base_link";
			ME_obstacles_filtering_Marker.header.stamp = ros::Time::now();
			ME_obstacles_filtering_Marker.lifetime = ros::Duration(0.2);
			ME_obstacles_filtering_Marker.id = 390;
			ME_obstacles_filtering_Marker.ns = "Obstacles_Fusion";
			ME_obstacles_filtering_Marker.type = visualization_msgs::Marker::CUBE_LIST;
			ME_obstacles_filtering_Marker.scale.x = 0.5;
			ME_obstacles_filtering_Marker.scale.y = 0.5;
			ME_obstacles_filtering_Marker.scale.z = 0.5;
			ME_obstacles_filtering_Marker.color.r = 1.0f;
			ME_obstacles_filtering_Marker.color.g = 0.0f;
			ME_obstacles_filtering_Marker.color.b = 0.0f;
			ME_obstacles_filtering_Marker.color.a = 1.0;
			ME_obstacles_filtering_Marker.action = visualization_msgs::Marker::MODIFY;
			ME_obstacles_filtering_Marker.pose.orientation.w = 1;

			/*for (int i = 0; i < ME_obstacles_filtering.QtyObstacles.data; i++)
			{
				ME_obstacles_filtering_Marker.points.push_back(ME_obstacles_filtering.ObstacleAlignement[i].obstaclePosition.position);
			}

			pub_ME_obstacles_filtering.publish(ME_obstacles_filtering_Marker);*/
		//}

//----------------------text marker ----------------------

			ME_obstacles_filtering_Marker_text = visualization_msgs::Marker();
			ME_obstacles_filtering_Marker_text.header.frame_id = "/base_link";
			ME_obstacles_filtering_Marker_text.header.stamp = ros::Time::now();
			ME_obstacles_filtering_Marker_text.lifetime = ros::Duration(0.2);
			ME_obstacles_filtering_Marker_text.id = 395;
			ME_obstacles_filtering_Marker_text.ns = "Obstacles_Fusion";
			ME_obstacles_filtering_Marker_text.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
			ME_obstacles_filtering_Marker_text.scale.x = 0.5;
			ME_obstacles_filtering_Marker_text.scale.y = 0.5;
			ME_obstacles_filtering_Marker_text.scale.z = 1.0;
			ME_obstacles_filtering_Marker_text.color.r = 1.0f;
			ME_obstacles_filtering_Marker_text.color.g = 1.0f;
			ME_obstacles_filtering_Marker_text.color.b = 1.0f;
			ME_obstacles_filtering_Marker_text.color.a = 1.0;
			ME_obstacles_filtering_Marker_text.action = visualization_msgs::Marker::MODIFY;
			ME_obstacles_filtering_Marker_text.pose.orientation.w = 1;

			for (int i = 0; i < ME_obstacles_filtering.QtyObstacles.data; i++)
			{
				
//Filter Marker
ME_obstacles_filtering_Marker.points.push_back(ME_obstacles_filtering.ObstacleAlignement[i].obstaclePosition.position);

//Filter Text Marker
ME_obstacles_filtering_Marker_text.pose.position.x = ME_obstacles_filtering.ObstacleAlignement[i].obstaclePosition.position.x;
				
ME_obstacles_filtering_Marker_text.pose.position.y = ME_obstacles_filtering.ObstacleAlignement[i].obstaclePosition.position.y;



				std::string my_id = "ID: ";
				int value =  ME_obstacles_filtering.ObstacleAlignement[i].id.data;
				std::string result;
                         	std::stringstream sstm;
                         	sstm << my_id << value;
			 	result = sstm.str();

				ME_obstacles_filtering_Marker_text.text = result;

				
		
			}

				pub_ME_obstacles_filtering.publish(ME_obstacles_filtering_Marker);

				pub_ME_obstacles_filtering_text.publish(ME_obstacles_filtering_Marker_text);
			//pub_ME_obstacles_filtering_text.publish(ME_obstacles_filtering_Marker_text);

		}
			

//-------------------------------------------------------------------------------------------------
// Marker - Mobileye  - Obstacle Data 2280
//-------------------------------------------------------------------------------------------------
		
		if (obstacledataReceived)
		{
			

			meye_obstacle_Markers = visualization_msgs::Marker();
			meye_obstacle_Markers.header.frame_id = "/base_link";
			meye_obstacle_Markers.header.stamp = ros::Time::now();
			meye_obstacle_Markers.lifetime = ros::Duration(0.2);
			meye_obstacle_Markers.id = 385;
			meye_obstacle_Markers.ns = "marker";
			meye_obstacle_Markers.type = visualization_msgs::Marker::SPHERE_LIST;
			meye_obstacle_Markers.action = visualization_msgs::Marker::MODIFY;
			meye_obstacle_Markers.scale.x = 0.5;
			meye_obstacle_Markers.scale.y = 0.5;
			meye_obstacle_Markers.scale.z = 0.5;
			meye_obstacle_Markers.color.r = 1.0f;
			meye_obstacle_Markers.color.g = 1.0f;
			meye_obstacle_Markers.color.b = 1.0f;
			meye_obstacle_Markers.color.a = 1.0;

			meye_obstacle_Markers.pose.orientation.w = 1;
		
									
			geometry_msgs::Point pt_meye;
			pt_meye.x = obstacle_data.obstacle_pos_x;
			pt_meye.y = obstacle_data.obstacle_pos_y;
			
			std::cout<<"Obstacle ID: " <<  obstacle_data.obstacle_id<< std::endl;
			meye_obstacle_Markers.points.push_back(pt_meye);

			 meye_obstacle_Markers_text = visualization_msgs::Marker();
			 meye_obstacle_Markers_text.header.frame_id = "/base_link";
			 meye_obstacle_Markers_text.header.stamp = ros::Time::now();
			 meye_obstacle_Markers_text.lifetime = ros::Duration(0.2);
			 meye_obstacle_Markers_text.id = 388;
			 meye_obstacle_Markers_text.ns = "marker";
			 meye_obstacle_Markers_text.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
			 meye_obstacle_Markers_text.action = visualization_msgs::Marker::MODIFY;
			 meye_obstacle_Markers_text.scale.x = 0.5;
			 meye_obstacle_Markers_text.scale.y = 0.5;
			 meye_obstacle_Markers_text.scale.z = 1.0;
			 meye_obstacle_Markers_text.color.r = 1.0f;
			 meye_obstacle_Markers_text.color.g = 0.0f;
			 meye_obstacle_Markers_text.color.b = 1.0f;
			 meye_obstacle_Markers_text.color.a = 1.0;

 			 meye_obstacle_Markers_text.pose.position.x = obstacle_data.obstacle_pos_x;
 			 meye_obstacle_Markers_text.pose.position.y = obstacle_data.obstacle_pos_y;

                         std::string my_id = "ID: ";
			 int value = obstacle_data.obstacle_id;
			 std::string result;
                         std::stringstream sstm;
                         sstm << my_id << value;
			 result = sstm.str();

			 std::cout<<"my_id: " << result <<std::endl;
			 meye_obstacle_Markers_text.pose.orientation.w = 1;
			 meye_obstacle_Markers_text.text = result;

			pub_me_obstacledata.publish(meye_obstacle_Markers);
			pub_me_obstacledata_text.publish(meye_obstacle_Markers_text);

			obstacledataReceived = false;
		}

//-------------------------------------------------------------------------------------------------
// Marker - IBEO LIDAR - Object Data 2280
//-------------------------------------------------------------------------------------------------

//--------------- Bounding Box ------------------------------------
		if (received_object_data_2280)
		{
			//received_object_data_2280 = false;

			// Markers pour le repère relatif
			lidar_bounding_box_Marker = visualization_msgs::MarkerArray();

			for (int i = 0; i < object_data_2280.objects.size(); i++)

			{
				lidar_Marker = visualization_msgs::Marker();

				lidar_Marker.header.frame_id = "/base_link";
				lidar_Marker.header.stamp = ros::Time::now();
				lidar_Marker.lifetime = ros::Duration();
				lidar_Marker.id = i;
				lidar_Marker.ns = "Obstacles_Assignment";
				lidar_Marker.type = visualization_msgs::Marker::CUBE;

				if((lidar_Marker.scale.x = object_data_2280.objects[i].object_box_size.x) == 0)
					lidar_Marker.scale.x = 0.5;
				if((lidar_Marker.scale.y = object_data_2280.objects[i].object_box_size.y) == 0)
					lidar_Marker.scale.y = 0.5;
				if((lidar_Marker.scale.z = 0) == 0)
					lidar_Marker.scale.z = 0.5;
				// Yellow by default				
				lidar_Marker.color.r = 1.0f;
				lidar_Marker.color.g = 0.0f;
				lidar_Marker.color.b = 0.0f;
				lidar_Marker.color.a = 0.5;
				lidar_Marker.action = visualization_msgs::Marker::MODIFY;

				/*lidar_Marker.pose.orientation.w = 1;
				lidar_Marker.pose.orientation.x = 0;
				lidar_Marker.pose.orientation.y = 0;
				lidar_Marker.pose.orientation.z = (object_data_2280.objects[i].object_box_orientation_angle);*/
				 lidar_Marker.pose.orientation = tf::createQuaternionMsgFromYaw(object_data_2280.objects[i].object_box_orientation_angle);

				lidar_Marker.pose.position.x = object_data_2280.objects[i].object_box_center.x;
				lidar_Marker.pose.position.y = object_data_2280.objects[i].object_box_center.y;
				lidar_bounding_box_Marker.markers.push_back(lidar_Marker);
			}

			pub_lidar_bounding_box.publish(lidar_bounding_box_Marker);

			}
//-----------------------------------------------------------------

		if (received_object_data_2280)
		{
			received_object_data_2280 = false;

			
			objectdata_2280_Markers = visualization_msgs::Marker();
			objectdata_2280_Markers.header.frame_id = "/base_link";
			objectdata_2280_Markers.header.stamp = ros::Time::now();
			objectdata_2280_Markers.lifetime = ros::Duration();
			objectdata_2280_Markers.id = 380;
			objectdata_2280_Markers.ns = "marker";
			objectdata_2280_Markers.type = visualization_msgs::Marker::SPHERE_LIST;
			objectdata_2280_Markers.action = visualization_msgs::Marker::MODIFY;
			objectdata_2280_Markers.scale.x = 0.5;
			objectdata_2280_Markers.scale.y = 0.5;
			objectdata_2280_Markers.scale.z = 0.5;
			objectdata_2280_Markers.color.r = 1.0f;
			objectdata_2280_Markers.color.g = 1.0f;
			objectdata_2280_Markers.color.b = 1.0f;
			objectdata_2280_Markers.color.a = 1.0;

			objectdata_2280_Markers.pose.orientation.w = 1;

			//std::cout<<"\n Size: "<<object_data_2280.objects.size()<<std::endl;
			for (int i = 0; i < object_data_2280.objects.size(); i++)
			{
								
				//std::cout<<object_data_2280.objects[i].id<<"  "	;			
				geometry_msgs::Point pt_ibeo;
				pt_ibeo.x = object_data_2280.objects[i].object_box_center.x;
				pt_ibeo.y = object_data_2280.objects[i].object_box_center.y;
				
				objectdata_2280_Markers.points.push_back(pt_ibeo);
				
			}

			pub_lidar_objectdata.publish(objectdata_2280_Markers);
		}

//-------------------------------------------------------------------------------------------------
// Marker - IBEO LIDAR - Filtering Data
//-------------------------------------------------------------------------------------------------
			if (received_lidar_obstacles_filtering)
			{
			received_lidar_obstacles_filtering = false;

		
			lidar_obstacles_filtering_Marker = visualization_msgs::Marker();
			lidar_obstacles_filtering_Marker.header.frame_id = "/base_link";
			lidar_obstacles_filtering_Marker.header.stamp = ros::Time::now();
			lidar_obstacles_filtering_Marker.lifetime = ros::Duration();
			lidar_obstacles_filtering_Marker.id = 381;
			lidar_obstacles_filtering_Marker.ns = "Obstacles_Fusion";
			lidar_obstacles_filtering_Marker.type = visualization_msgs::Marker::CUBE_LIST;
			lidar_obstacles_filtering_Marker.scale.x = 0.5;
			lidar_obstacles_filtering_Marker.scale.y = 0.5;
			lidar_obstacles_filtering_Marker.scale.z = 0.5;
			lidar_obstacles_filtering_Marker.color.r = 1.0f;
			lidar_obstacles_filtering_Marker.color.g = 1.0f;
			lidar_obstacles_filtering_Marker.color.b = 0.0f;
			lidar_obstacles_filtering_Marker.color.a = 1.0;
			lidar_obstacles_filtering_Marker.action = visualization_msgs::Marker::MODIFY;
			lidar_obstacles_filtering_Marker.pose.orientation.w = 1;

			for (int i = 0; i < lidar_obstacles_filtering.QtyObstacles.data; i++)
			{
				lidar_obstacles_filtering_Marker.points.push_back(lidar_obstacles_filtering.ObstacleAlignement[i].obstaclePosition.position);
			}

			pub_lidar_obstacles_filtering.publish(lidar_obstacles_filtering_Marker);
		}


//-------------------------------------------------------------------------------------------------
// Marker - ESR Filtering Data
//-------------------------------------------------------------------------------------------------

		if (received_ESR_obstacles_filtering)

		{
			received_ESR_obstacles_filtering = false;
	
			ESR_obstacles_filtering_Marker = visualization_msgs::Marker();

			ESR_obstacles_filtering_Marker.header.frame_id = "/base_link";
			ESR_obstacles_filtering_Marker.header.stamp = ros::Time::now();
			ESR_obstacles_filtering_Marker.lifetime = ros::Duration();
			ESR_obstacles_filtering_Marker.id = 370;
			ESR_obstacles_filtering_Marker.ns = "Obstacles_Fusion";
			ESR_obstacles_filtering_Marker.type = visualization_msgs::Marker::CUBE_LIST;
			ESR_obstacles_filtering_Marker.scale.x = 0.5;
			ESR_obstacles_filtering_Marker.scale.y = 0.5;
			ESR_obstacles_filtering_Marker.scale.z = 0.5;
			ESR_obstacles_filtering_Marker.color.r = 0.0f;
			ESR_obstacles_filtering_Marker.color.g = 1.0f;
			ESR_obstacles_filtering_Marker.color.b = 0.0f;
			ESR_obstacles_filtering_Marker.color.a = 1.0;
			ESR_obstacles_filtering_Marker.action = visualization_msgs::Marker::MODIFY;
			ESR_obstacles_filtering_Marker.pose.orientation.w = 1;

			for (int i = 0; i < ESR_obstacles_filtering.QtyObstacles.data; i++)
			{
				ESR_obstacles_filtering_Marker.points.push_back(ESR_obstacles_filtering.ObstacleAlignement[i].obstaclePosition.position);
			}

			pub_ESR_obstacles_filtering_rel.publish(ESR_obstacles_filtering_Marker);
		}

//-------------------------------------------------------------------------------------------------
// Marker - ESR /radar_tracks 
//-------------------------------------------------------------------------------------------------
		if (received_radar_tracks)
		{
			received_radar_tracks = false;

			radar_tracks_Marker = visualization_msgs::Marker();
			radar_tracks_Marker.header.frame_id = "/base_link";
			radar_tracks_Marker.header.stamp = ros::Time::now();
			radar_tracks_Marker.lifetime = ros::Duration();
			radar_tracks_Marker.id = 372;
			radar_tracks_Marker.ns = "marker";
			radar_tracks_Marker.type = visualization_msgs::Marker::SPHERE_LIST;
			radar_tracks_Marker.action = visualization_msgs::Marker::MODIFY;
			radar_tracks_Marker.scale.x = 0.5;
			radar_tracks_Marker.scale.y = 0.5;
			radar_tracks_Marker.scale.z = 0.5;
			radar_tracks_Marker.color.r = 1.0f;
			radar_tracks_Marker.color.g = 1.0f;
			radar_tracks_Marker.color.b = 1.0f;
			radar_tracks_Marker.color.a = 1.0;

			radar_tracks_Marker.pose.orientation.w = 1;

			for (int i = 0; i < radar_tracks.tracks.size(); i++)
			{
				geometry_msgs::Point pt;
				pt.x = radar_tracks.tracks[i].track_shape.points[0].x;
				pt.y = radar_tracks.tracks[i].track_shape.points[0].y;
				pt.z = radar_tracks.tracks[i].track_shape.points[0].z;
				radar_tracks_Marker.points.push_back(pt);
				//radar_tracks_Marker.text = "ID " + radar_tracks.tracks[i].track_id;

				/*
				geometry_msgs::Point pt;
				radar_tracks_Marker.pose.position.x = radar_tracks.tracks[i].track_shape.points[0].x;
				radar_tracks_Marker.pose.position.y = radar_tracks.tracks[i].track_shape.points[0].y;
				radar_tracks_Marker.pose.position.z = radar_tracks.tracks[i].track_shape.points[0].z;
				radar_tracks_Marker.points.push_back(pt);
				*/

			}

			pub_radar_tracks.publish(radar_tracks_Marker);
		}

//-------------------------------------------------------------------------------------------------
// Marker - ESR /radar_tracks - TEXT
//-------------------------------------------------------------------------------------------------

		/*if (received_radar_tracks_text)
		{
			received_radar_tracks_text = false;

			// Markers pour le repère relatif
			radar_tracks_Marker_Text = visualization_msgs::Marker();

			radar_tracks_Marker_Text.header.frame_id = "/base_link";
			radar_tracks_Marker_Text.header.stamp = ros::Time::now();
			radar_tracks_Marker_Text.lifetime = ros::Duration();
			radar_tracks_Marker_Text.id = 375;
			radar_tracks_Marker_Text.ns = "marker";
			radar_tracks_Marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
			radar_tracks_Marker_Text.action = visualization_msgs::Marker::MODIFY;
			radar_tracks_Marker_Text.scale.x = 0.5;
			radar_tracks_Marker_Text.scale.y = 0.5;
			radar_tracks_Marker_Text.scale.z = 0.5;
			radar_tracks_Marker_Text.color.r = 1.0f;
			radar_tracks_Marker_Text.color.g = 1.0f;
			radar_tracks_Marker_Text.color.b = 1.0f;
			radar_tracks_Marker_Text.color.a = 1.0;

			radar_tracks_Marker_Text.pose.orientation.w = 1;

			for (int i = 0; i < radar_tracks_text.tracks.size(); i++)
			{
				
			std_msgs::String st;
			st.data = radar_tracks_text.tracks[i].track_id;
			radar_tracks_Marker.text.push_back(st);

			//radar_tracks_Marker.text = "ID " + radar_tracks_text.tracks[i].track_id;

			}

			pub_radar_tracks.publish(radar_tracks_Marker);
		}*/

		
		//}

		loop_rate.sleep();
	}
	
	return 0;	
}
