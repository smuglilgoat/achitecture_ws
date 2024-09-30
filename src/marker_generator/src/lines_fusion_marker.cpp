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

#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include "nav_msgs/Odometry.h"
#include <tf/transform_broadcaster.h>

#include "project_s_msgs/LaneAlignment.h"
#include "project_s_msgs/LaneSynchronizedReport.h"
#include "project_s_msgs/LaneFusion.h"

#define	IDLE_TRACK	0
#define	PRE_TRACK	1
#define	POST_TRACK	2
#define	CURRENT_TRACK	3

project_s_msgs::LaneAlignment          lines_filtering;
project_s_msgs::LaneSynchronizedReport lines_synchronization;
project_s_msgs::LaneFusion             lines_update;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool linesFilteringReceived = false;
void linesFilteringDataCallback(const project_s_msgs::LaneAlignment::ConstPtr& buffer)
{
	lines_filtering = *buffer;

	linesFilteringReceived = true;
}

bool linesSynchronizationReceived = false;
void linesSynchronizationDataCallback(const project_s_msgs::LaneSynchronizedReport::ConstPtr& buffer)
{
	lines_synchronization = *buffer;

	linesSynchronizationReceived = true;
}

bool linesUpdateReceived = false;
void linesUpdateDataCallback(const project_s_msgs::LaneFusion::ConstPtr& buffer)
{
	lines_update = *buffer;

	linesUpdateReceived = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("obstacles_markers_me"));

	ros::NodeHandle n;

	ros::Subscriber sub_lines_filtering = n.subscribe(std::string("/lines_filtering_data"), 1, linesFilteringDataCallback); 
	ros::Publisher  pub_lines_filtering = n.advertise<visualization_msgs::Marker>("/lines_filtering_marker", 1);
	visualization_msgs::Marker lines_filtering_marker;

	ros::Subscriber sub_lines_synchronization = n.subscribe(std::string("/lines_synchronization_data"), 1, linesSynchronizationDataCallback); 
	ros::Publisher  pub_lines_synchronization_filtered     = n.advertise<visualization_msgs::Marker>("/lines_synchronization_filtered_marker",     1);
	ros::Publisher  pub_lines_synchronization_synchronized = n.advertise<visualization_msgs::Marker>("/lines_synchronization_synchronized_marker", 1);
	visualization_msgs::Marker marker;

	ros::Subscriber sub_lines_update = n.subscribe(std::string("/lines_update_data"), 1, linesUpdateDataCallback);
	ros::Publisher  pub_lines_update = n.advertise<visualization_msgs::MarkerArray>("/lines_update_marker", 1);
	visualization_msgs::MarkerArray markerArray;

	ros::Duration blink_of_an_eye(0.01); 

	ros::Rate loop_rate(25);

	while(n.ok())
	{
		ros::spinOnce();

		if(linesFilteringReceived){
			linesFilteringReceived = false;

			// Markers pour les lignes filtering
			lines_filtering_marker = visualization_msgs::Marker();

			lines_filtering_marker.header.frame_id = "/base_link";
			lines_filtering_marker.header.stamp = ros::Time::now();
			lines_filtering_marker.lifetime = ros::Duration(0.2);
			lines_filtering_marker.id = 232;
			lines_filtering_marker.ns = "route";
			lines_filtering_marker.type = visualization_msgs::Marker::SPHERE_LIST;
			lines_filtering_marker.scale.x = 0.3;
			lines_filtering_marker.scale.y = 0.3;
			lines_filtering_marker.scale.z = 0.3;
			lines_filtering_marker.color.r = 1.0f;
			lines_filtering_marker.color.g = 1.0f;
			lines_filtering_marker.color.b = 1.0f;
			lines_filtering_marker.color.a = 1.0;
			lines_filtering_marker.action = visualization_msgs::Marker::MODIFY;
			lines_filtering_marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

			for(int i = 0; i < lines_filtering.QtyLine.data; i++){
				for(int j = 0; j < lines_filtering.line[i].QtySegment.data; j++){
					lines_filtering_marker.points.push_back(lines_filtering.line[i].segment[j].position);
				}
			}

			pub_lines_filtering.publish(lines_filtering_marker);
		}

		if(linesSynchronizationReceived){
			linesSynchronizationReceived = false;

			// Markers pour les lignes filtrées
			marker = visualization_msgs::Marker();

			marker.header.frame_id = "/base_link";
			marker.header.stamp = ros::Time::now();
			marker.lifetime = ros::Duration(0.2);
			marker.id = 230;
			marker.ns = "route";
			marker.type = visualization_msgs::Marker::SPHERE_LIST;
			marker.scale.x = 0.3;
			marker.scale.y = 0.3;
			marker.scale.z = 0.3;
			marker.color.r = 1.0f;
			marker.color.g = 0.0f;
			marker.color.b = 0.0f;
			marker.color.a = 1.0;
			marker.action = visualization_msgs::Marker::MODIFY;
			marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

			for(int i = 0; i < lines_synchronization.laneAlignement.QtyLine.data; i++){
				for(int j = 0; j < lines_synchronization.laneAlignement.line[i].QtySegment.data; j++){
					marker.points.push_back(lines_synchronization.laneAlignement.line[i].segment[j].position);
				}
			}

			pub_lines_synchronization_filtered.publish(marker);

			// Markers pour les lignes update synchronisées
			marker = visualization_msgs::Marker();

			marker.header.frame_id = "/base_link";
			marker.header.stamp = ros::Time::now();
			marker.lifetime = ros::Duration(0.2);
			marker.id = 231;
			marker.ns = "route";
			marker.type = visualization_msgs::Marker::SPHERE_LIST;
			marker.scale.x = 0.3;
			marker.scale.y = 0.3;
			marker.scale.z = 0.3;
			marker.color.r = 0.0f;
			marker.color.g = 1.0f;
			marker.color.b = 0.0f;
			marker.color.a = 1.0;
			marker.action = visualization_msgs::Marker::MODIFY;
			marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

			for(int i = 0; i < lines_synchronization.laneFusion.QtyLine.data; i++){
				for(int j = 0; j < lines_synchronization.laneFusion.line[i].QtySegment.data; j++){
					marker.points.push_back(lines_synchronization.laneFusion.line[i].segment[j].position);
				}
			}

			pub_lines_synchronization_synchronized.publish(marker);
		}

		if(linesUpdateReceived){
			linesUpdateReceived = false;

			markerArray = visualization_msgs::MarkerArray();

			for(int i = 0; i < lines_update.QtyLine.data; i++){
				marker = visualization_msgs::Marker();

				marker.header.frame_id = "/base_link";
				marker.header.stamp = ros::Time::now();
				marker.lifetime = ros::Duration(0.2);
				marker.id = 240+i;
				marker.ns = "route";
				marker.type = visualization_msgs::Marker::SPHERE_LIST;
				marker.scale.x = 0.3;
				marker.scale.y = 0.3;
				marker.scale.z = 0.3;
				switch(lines_update.line[i].existenceState.data){
				default :
					marker.color.r = 1.0f;
					marker.color.g = 1.0f;
					marker.color.b = 0.0f;
					marker.color.a = 1.0;
					break;
				case IDLE_TRACK :
					marker.color.r = 0.0f;
					marker.color.g = 1.0f;
					marker.color.b = 0.0f;
					marker.color.a = 1.0;
					break;
				case PRE_TRACK :
					marker.color.r = 1.0f;
					marker.color.g = 0.0f;
					marker.color.b = 0.0f;
					marker.color.a = 1.0;
					break;
				case POST_TRACK :
					marker.color.r = 0.0f;
					marker.color.g = 0.0f;
					marker.color.b = 1.0f;
					marker.color.a = 1.0;
					break;
				case CURRENT_TRACK :
					marker.color.r = 1.0f;
					marker.color.g = 1.0f;
					marker.color.b = 1.0f;
					marker.color.a = 1.0;
					break;
				}
				marker.action = visualization_msgs::Marker::MODIFY;
				marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

				for(int j = 0; j < lines_update.line[i].QtySegment.data; j++){
					marker.points.push_back(lines_update.line[i].segment[j].position);
				}

				markerArray.markers.push_back(marker);
			}

			pub_lines_update.publish(markerArray);
		}

		loop_rate.sleep();
	}

	return 0;
}
