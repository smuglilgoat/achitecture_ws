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
#include "nav_msgs/Odometry.h"
#include <tf/transform_broadcaster.h>

#include "project_s_msgs/ObstacleAlignmentReport.h"
#include "project_s_msgs/LaneAlignment.h"
#include <mobileye_560_660_msgs/LkaLane.h>
#include "project_s_msgs/LaneAlignmentME.h"
//#include "project_s_msgs/GenericSmartData.h"

project_s_msgs::ObstacleAlignmentReport extractedObstaclesAlign;
project_s_msgs::LaneAlignment extractedLinesAlign, lines_filtering;
nav_msgs::Odometry odomObstacle, odomLines;
mobileye_560_660_msgs::LkaLane left_lka_lane, right_lka_lane, next_lka_lane;
project_s_msgs::LaneAlignmentME laneAlignMEReport;

bool receivedObstacle = false;
bool receivedLine = false;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
void obstacleAlignCallback(const project_s_msgs::ObstacleAlignmentReport::ConstPtr& ObstacleAlignementArray)
{
	extractedObstaclesAlign = *ObstacleAlignementArray;
	odomObstacle = extractedObstaclesAlign.odom;

	receivedObstacle = true;
}

void LineAlignCallback(const project_s_msgs::LaneAlignment::ConstPtr& laneAlignment)
{
	extractedLinesAlign = *laneAlignment;
	odomLines = extractedLinesAlign.odom;

	receivedLine = true;
}

bool received_right_lka_lane = false;
void rightlkalaneDataCallback(const mobileye_560_660_msgs::LkaLane::ConstPtr& buffer)
{
	right_lka_lane = *buffer;

	received_right_lka_lane = true;
}

bool received_left_lka_lane = false;
void leftlkalaneDataCallback(const mobileye_560_660_msgs::LkaLane::ConstPtr& buffer)
{
	left_lka_lane = *buffer;

	received_left_lka_lane = true;
}

bool received_next_lka_lane = false;
void nextlkalaneDataCallback(const mobileye_560_660_msgs::LkaLane::ConstPtr& buffer)
{
	next_lka_lane = *buffer;

	received_next_lka_lane = true;
}

bool received_lane_align_report = false;
void laneAlignReportCallback(const project_s_msgs::LaneAlignmentME::ConstPtr& buffer)
{
	laneAlignMEReport = *buffer;

	received_lane_align_report = true;
}

bool linesfilteringReceived = false;
void linesFilteringDataCallback(const project_s_msgs::LaneAlignment::ConstPtr& buffer)
{
	lines_filtering = *buffer;

	linesfilteringReceived = true;
}

//-------------------------------------------------------------------------------------------------
// local functions
//-------------------------------------------------------------------------------------------------
geometry_msgs::Point computeGlobalPosition(geometry_msgs::Point point, nav_msgs::Odometry odom)
{	// calculs de la position dans le repère absolu,
	// à partir de la position dans le repère de l'égo (position déjà alignée)
	geometry_msgs::Point p;
	double theta = tf::getYaw(odom.pose.pose.orientation);

	p.x = odom.pose.pose.position.x + (point.x * cos(theta) - point.y * sin(theta));
	p.y = odom.pose.pose.position.y + (point.x * sin(theta) + point.y * cos(theta));
	p.z = odom.pose.pose.position.z +  point.z;

	return p;
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

	ros::Publisher pub_obstacle_rel = n.advertise<visualization_msgs::Marker>(std::string("/camera_relative_obstacle_markers"), 1);
	ros::Publisher pub_obstacle_abs = n.advertise<visualization_msgs::Marker>(std::string("/camera_absolu_obstacle_markers"), 1);

	ros::Publisher pub_line_rel = n.advertise<visualization_msgs::Marker>(std::string("/camera_relative_line_markers"), 1);
	ros::Publisher pub_line_abs = n.advertise<visualization_msgs::Marker>(std::string("/camera_absolu_line_markers"), 1);

	ros::Subscriber subObstaclesAlign = n.subscribe(std::string("/camera_me_obstacles_align_data"), 1, obstacleAlignCallback);
	ros::Subscriber subLanesAlign = n.subscribe(std::string("/camera_me_route_alignment_data"), 1, LineAlignCallback);

	ros::Subscriber sub_right_lka_lane = n.subscribe(std::string("/parsed_tx/right_lka_lane"), 1, rightlkalaneDataCallback);
	ros::Publisher  pub_right_lka_lane = n.advertise<visualization_msgs::Marker>("/right_lka_lane_marker", 1);
	visualization_msgs::Marker right_lka_lane_marker;

	ros::Subscriber sub_left_lka_lane = n.subscribe(std::string("/parsed_tx/left_lka_lane"), 1, leftlkalaneDataCallback);
	ros::Publisher  pub_left_lka_lane = n.advertise<visualization_msgs::Marker>("/left_lka_lane_marker", 1);
	visualization_msgs::Marker left_lka_lane_marker;

	ros::Subscriber sub_next_lka_lane = n.subscribe(std::string("/parsed_tx/next_lka_lane"), 1, nextlkalaneDataCallback);
	ros::Publisher  pub_next_lka_lane = n.advertise<visualization_msgs::Marker>("/next_lka_lane_marker", 1);
	visualization_msgs::Marker next_lka_lane_marker;

	ros::Subscriber sub_lka_lane_report = n.subscribe(std::string("/camera_me_lines_align_report"), 1, laneAlignReportCallback);
	ros::Publisher  pub_right_lka_lane_align = n.advertise<visualization_msgs::Marker>("/right_lka_lane_align_marker", 1);
	ros::Publisher  pub_left_lka_lane_align  = n.advertise<visualization_msgs::Marker>("/left_lka_lane_align_marker",  1);
	ros::Publisher  pub_next_lka_lane_align  = n.advertise<visualization_msgs::Marker>("/next_lka_lane_align_marker",  1);
	visualization_msgs::Marker right_lka_lane_align_marker, left_lka_lane_align_marker, next_lka_lane_align_marker;

	ros::Subscriber sub_lines_filtering = n.subscribe(std::string("/lines_filtering_data"), 1, linesFilteringDataCallback);
	ros::Publisher  pub_lines_filtering = n.advertise<visualization_msgs::Marker>(std::string("/lines_filtering_markers"), 1);

	visualization_msgs::Marker relativeObstacleMarker, relativeLineMarker, absoluObstacleMarker, absoluLineMarker;

	ros::Duration blink_of_an_eye(0.01); 

	ros::Rate loop_rate(25);

	while(n.ok())
	{
		ros::spinOnce();

		if (receivedObstacle)
		{
			receivedObstacle = false;

			// Markers pour le repère relatif
			relativeObstacleMarker = visualization_msgs::Marker();

			relativeObstacleMarker.header.frame_id = "/base_link";
			relativeObstacleMarker.header.stamp = ros::Time::now();
			relativeObstacleMarker.lifetime = ros::Duration();
			relativeObstacleMarker.id = 221;
			relativeObstacleMarker.ns = "Obstacles";
			relativeObstacleMarker.type = visualization_msgs::Marker::SPHERE_LIST;
			relativeObstacleMarker.scale.x = 0.8;
			relativeObstacleMarker.scale.y = 0.8;
			relativeObstacleMarker.scale.z = 0.8;
			relativeObstacleMarker.color.r = 1.0f;
			relativeObstacleMarker.color.g = 0.0f;
			relativeObstacleMarker.color.b = 0.0f;
			relativeObstacleMarker.color.a = 1.0;
			relativeObstacleMarker.action = visualization_msgs::Marker::MODIFY;
			relativeObstacleMarker.pose.orientation.w = 1;	// équivalent à relativeObstacleMarker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

			// Markers pour le repère absolu
			absoluObstacleMarker = visualization_msgs::Marker();

			absoluObstacleMarker.header.frame_id = "/odom";
			absoluObstacleMarker.header.stamp = ros::Time::now();
			absoluObstacleMarker.lifetime = ros::Duration();
			absoluObstacleMarker.id = 222;
			absoluObstacleMarker.ns = "Obstacles";
			absoluObstacleMarker.type = visualization_msgs::Marker::CUBE_LIST;
			absoluObstacleMarker.scale.x = 0.8;
			absoluObstacleMarker.scale.y = 0.8;
			absoluObstacleMarker.scale.z = 0.8;
			absoluObstacleMarker.color.r = 1.0f;
			absoluObstacleMarker.color.g = 0.0f;
			absoluObstacleMarker.color.b = 0.0f;
			absoluObstacleMarker.color.a = 1.0;
/*
if(extractedObstaclesAlign.ObstacleAlignement[0].obstacleClass == project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN){
absoluObstacleMarker.color.r = 1.0f;
absoluObstacleMarker.color.g = 1.0f;
absoluObstacleMarker.color.b = 0.0f;
}*/
			absoluObstacleMarker.action = visualization_msgs::Marker::MODIFY;
			absoluObstacleMarker.pose.orientation.w = 1;	// équivalent à absoluObstacleMarker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

			for (int i = 0; i < extractedObstaclesAlign.QtyObstacles.data; i++)
			{
				relativeObstacleMarker.points.push_back(extractedObstaclesAlign.ObstacleAlignement[i].obstaclePosition.position);
				absoluObstacleMarker.points.push_back(computeGlobalPosition(extractedObstaclesAlign.ObstacleAlignement[i].obstaclePosition.position, odomObstacle));
			}

			pub_obstacle_rel.publish(relativeObstacleMarker);
			pub_obstacle_abs.publish(absoluObstacleMarker);
		}

		if (receivedLine)
		{
			receivedLine = false;

			// Markers pour le repère relatif
			relativeLineMarker = visualization_msgs::Marker();

			relativeLineMarker.header.frame_id = "/base_link";
			relativeLineMarker.header.stamp = ros::Time::now();
			relativeLineMarker.lifetime = ros::Duration();
			relativeLineMarker.id = 223;
			relativeLineMarker.ns = "route";
			relativeLineMarker.type = visualization_msgs::Marker::SPHERE_LIST;
			relativeLineMarker.scale.x = 0.3;
			relativeLineMarker.scale.y = 0.3;
			relativeLineMarker.scale.z = 0.3;
			relativeLineMarker.color.r = 1.0f;
			relativeLineMarker.color.g = 0.0f;
			relativeLineMarker.color.b = 0.0f;
			relativeLineMarker.color.a = 1.0;
			relativeLineMarker.action = visualization_msgs::Marker::MODIFY;
			relativeLineMarker.pose.orientation.w = 1;	// équivalent à relativeLineMarker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

			// Markers pour le repère absolu
			absoluLineMarker = visualization_msgs::Marker();

			absoluLineMarker.header.frame_id = "/odom";
			absoluLineMarker.header.stamp = ros::Time::now();
			absoluLineMarker.lifetime = ros::Duration();
			absoluLineMarker.id = 224;
			absoluLineMarker.ns = "route";
			absoluLineMarker.type = visualization_msgs::Marker::CUBE_LIST;
			absoluLineMarker.scale.x = 0.3;
			absoluLineMarker.scale.y = 0.3;
			absoluLineMarker.scale.z = 0.3;
			absoluLineMarker.color.r = 1.0f;
			absoluLineMarker.color.g = 0.0f;
			absoluLineMarker.color.b = 0.0f;
			absoluLineMarker.color.a = 1.0;
			absoluLineMarker.action = visualization_msgs::Marker::MODIFY;
			absoluLineMarker.pose.orientation.w = 1;	// équivalent à absoluLineMarker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

			for (int i = 0; i < 3; i++)		// extractedLinesAlign est un tableau	5 lignes de 250 segments
			{					// mais on se limite pour l'instant à	3 lignes de  10 segments
				for(int j = 0; j < 10; j++)
				{
					if((extractedLinesAlign.line[i].segment[j].position.x != 0) || (extractedLinesAlign.line[i].segment[j].position.y != 0))
					{
						relativeLineMarker.points.push_back(extractedLinesAlign.line[i].segment[j].position);
						absoluLineMarker.points.push_back(computeGlobalPosition(extractedLinesAlign.line[i].segment[j].position, odomLines));
					}
				}
			}

			pub_line_rel.publish(relativeLineMarker);
			pub_line_abs.publish(absoluLineMarker);
		}

		if(received_right_lka_lane)
		{
			received_right_lka_lane = false;

			right_lka_lane_marker = visualization_msgs::Marker();
			right_lka_lane_marker.header.frame_id = "/base_link";
			right_lka_lane_marker.header.stamp = ros::Time::now();
			right_lka_lane_marker.ns = "points_and_lines";
			right_lka_lane_marker.action = visualization_msgs::Marker::ADD;
			right_lka_lane_marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);
			right_lka_lane_marker.id = 10;
			right_lka_lane_marker.type = visualization_msgs::Marker::LINE_STRIP;
			right_lka_lane_marker.scale.x = 0.2;
			right_lka_lane_marker.color.r = 1.0;
			//right_lka_lane_marker.color.g = 0.0;
			//right_lka_lane_marker.color.b = 0.0;
			right_lka_lane_marker.color.a = 1.0;

			float X = right_lka_lane.marking_width;
			while(X <= right_lka_lane.view_range){
				geometry_msgs::Point p;
				p.x  = X;
				p.y  = right_lka_lane.position_parameter_c0;
				p.y += right_lka_lane.heading_angle_parameter_c1        *          p.x   ;
				p.y += right_lka_lane.curvature_parameter_c2            * std::pow(p.x,2);
				p.y += right_lka_lane.curvature_derivative_parameter_c3 * std::pow(p.x,3);

				right_lka_lane_marker.points.push_back(p);

				X++;
			}

			pub_right_lka_lane.publish(right_lka_lane_marker);
		}

		if(received_left_lka_lane)
		{
			received_left_lka_lane = false;

			left_lka_lane_marker = visualization_msgs::Marker();
			left_lka_lane_marker.header.frame_id = "/base_link";
			left_lka_lane_marker.header.stamp = ros::Time::now();
			left_lka_lane_marker.ns = "points_and_lines";
			left_lka_lane_marker.action = visualization_msgs::Marker::ADD;
			left_lka_lane_marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);
			left_lka_lane_marker.id = 11;
			left_lka_lane_marker.type = visualization_msgs::Marker::LINE_STRIP;
			left_lka_lane_marker.scale.x = 0.2;
			left_lka_lane_marker.color.r = 1.0;
			//left_lka_lane_marker.color.g = 0.0;
			//left_lka_lane_marker.color.b = 0.0;
			left_lka_lane_marker.color.a = 1.0;

			float X = left_lka_lane.marking_width;
			while(X <= left_lka_lane.view_range){
				geometry_msgs::Point p;
				p.x  = X;
				p.y  = left_lka_lane.position_parameter_c0;
				p.y += left_lka_lane.heading_angle_parameter_c1        *          p.x   ;
				p.y += left_lka_lane.curvature_parameter_c2            * std::pow(p.x,2);
				p.y += left_lka_lane.curvature_derivative_parameter_c3 * std::pow(p.x,3);

				left_lka_lane_marker.points.push_back(p);

				X++;
			}

			pub_left_lka_lane.publish(left_lka_lane_marker);
		}

		if(received_next_lka_lane)
		{
			received_next_lka_lane = false;

			next_lka_lane_marker = visualization_msgs::Marker();
			next_lka_lane_marker.header.frame_id = "/base_link";
			next_lka_lane_marker.header.stamp = ros::Time::now();
			next_lka_lane_marker.ns = "points_and_lines";
			next_lka_lane_marker.action = visualization_msgs::Marker::ADD;
			next_lka_lane_marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);
			next_lka_lane_marker.id = 12;
			next_lka_lane_marker.type = visualization_msgs::Marker::LINE_STRIP;
			next_lka_lane_marker.scale.x = 0.2;
			next_lka_lane_marker.color.r = 1.0;
			//next_lka_lane_marker.color.g = 0.0;
			//next_lka_lane_marker.color.b = 0.0;
			next_lka_lane_marker.color.a = 1.0;

			float X = next_lka_lane.marking_width;
			while(X <= next_lka_lane.view_range){
				geometry_msgs::Point p;
				p.x  = X;
				p.y  = next_lka_lane.position_parameter_c0;
				p.y += next_lka_lane.heading_angle_parameter_c1        *          p.x   ;
				p.y += next_lka_lane.curvature_parameter_c2            * std::pow(p.x,2);
				p.y += next_lka_lane.curvature_derivative_parameter_c3 * std::pow(p.x,3);

				next_lka_lane_marker.points.push_back(p);

				X++;
			}

			pub_next_lka_lane.publish(next_lka_lane_marker);
		}

		if(received_lane_align_report)
		{
			received_lane_align_report = false;

			right_lka_lane_align_marker = visualization_msgs::Marker();
			right_lka_lane_align_marker.header.frame_id = "/base_link";
			right_lka_lane_align_marker.header.stamp = ros::Time::now();
			right_lka_lane_align_marker.ns = "points_and_lines";
			right_lka_lane_align_marker.action = visualization_msgs::Marker::ADD;
			right_lka_lane_align_marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);
			right_lka_lane_align_marker.id = 21;
			right_lka_lane_align_marker.type = visualization_msgs::Marker::LINE_STRIP;
			right_lka_lane_align_marker.scale.x = 0.2;
			right_lka_lane_align_marker.color.r = 1.0;
			//right_lka_lane_align_marker.color.g = 0.0;
			//right_lka_lane_align_marker.color.b = 0.0;
			right_lka_lane_align_marker.color.a = 1.0;

			if(laneAlignMEReport.QtyLine.data > 0){
				float X = laneAlignMEReport.line[0].marking_width;
				while(X <= laneAlignMEReport.line[0].view_range){
					geometry_msgs::Point p;
					p.x  = X;
					p.y  = laneAlignMEReport.line[0].position_parameter_c0;
					p.y += laneAlignMEReport.line[0].heading_angle_parameter_c1        *          p.x   ;
					p.y += laneAlignMEReport.line[0].curvature_parameter_c2            * std::pow(p.x,2);
					p.y += laneAlignMEReport.line[0].curvature_derivative_parameter_c3 * std::pow(p.x,3);

					right_lka_lane_align_marker.points.push_back(p);

					X++;
				}
			}

			pub_right_lka_lane_align.publish(right_lka_lane_align_marker);

			left_lka_lane_align_marker = visualization_msgs::Marker();
			left_lka_lane_align_marker.header.frame_id = "/base_link";
			left_lka_lane_align_marker.header.stamp = ros::Time::now();
			left_lka_lane_align_marker.ns = "points_and_lines";
			left_lka_lane_align_marker.action = visualization_msgs::Marker::ADD;
			left_lka_lane_align_marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);
			left_lka_lane_align_marker.id = 22;
			left_lka_lane_align_marker.type = visualization_msgs::Marker::LINE_STRIP;
			left_lka_lane_align_marker.scale.x = 0.2;
			left_lka_lane_align_marker.color.r = 1.0;
			//left_lka_lane_align_marker.color.g = 0.0;
			//left_lka_lane_align_marker.color.b = 0.0;
			left_lka_lane_align_marker.color.a = 1.0;

			if(laneAlignMEReport.QtyLine.data > 1){
				float X = laneAlignMEReport.line[1].marking_width;
				while(X <= laneAlignMEReport.line[1].view_range){
					geometry_msgs::Point p;
					p.x  = X;
					p.y  = laneAlignMEReport.line[1].position_parameter_c0;
					p.y += laneAlignMEReport.line[1].heading_angle_parameter_c1        *          p.x   ;
					p.y += laneAlignMEReport.line[1].curvature_parameter_c2            * std::pow(p.x,2);
					p.y += laneAlignMEReport.line[1].curvature_derivative_parameter_c3 * std::pow(p.x,3);

					left_lka_lane_align_marker.points.push_back(p);

					X++;
				}
			}

			pub_left_lka_lane_align.publish(left_lka_lane_align_marker);

			next_lka_lane_align_marker = visualization_msgs::Marker();
			next_lka_lane_align_marker.header.frame_id = "/base_link";
			next_lka_lane_align_marker.header.stamp = ros::Time::now();
			next_lka_lane_align_marker.ns = "points_and_lines";
			next_lka_lane_align_marker.action = visualization_msgs::Marker::ADD;
			next_lka_lane_align_marker.pose.orientation = tf::createQuaternionMsgFromYaw(0);
			next_lka_lane_align_marker.id = 23;
			next_lka_lane_align_marker.type = visualization_msgs::Marker::LINE_STRIP;
			next_lka_lane_align_marker.scale.x = 0.2;
			next_lka_lane_align_marker.color.r = 1.0;
			//next_lka_lane_align_marker.color.g = 0.0;
			//next_lka_lane_align_marker.color.b = 0.0;
			next_lka_lane_align_marker.color.a = 1.0;

			if(laneAlignMEReport.QtyLine.data > 2){
				float X = laneAlignMEReport.line[2].marking_width;
				while(X <= laneAlignMEReport.line[2].view_range){
					geometry_msgs::Point p;
					p.x  = X;
					p.y  = laneAlignMEReport.line[2].position_parameter_c0;
					p.y += laneAlignMEReport.line[2].heading_angle_parameter_c1        *          p.x   ;
					p.y += laneAlignMEReport.line[2].curvature_parameter_c2            * std::pow(p.x,2);
					p.y += laneAlignMEReport.line[2].curvature_derivative_parameter_c3 * std::pow(p.x,3);

					next_lka_lane_align_marker.points.push_back(p);

					X++;
				}
			}

			pub_next_lka_lane_align.publish(next_lka_lane_align_marker);
		}

		if(linesfilteringReceived)
		{
			linesfilteringReceived = false;

			// Markers pour le repère relatif
			relativeLineMarker = visualization_msgs::Marker();

			relativeLineMarker.header.frame_id = "/base_link";
			relativeLineMarker.header.stamp = ros::Time::now();
			relativeLineMarker.lifetime = ros::Duration();
			relativeLineMarker.id = 225;
			relativeLineMarker.ns = "route";
			relativeLineMarker.type = visualization_msgs::Marker::SPHERE_LIST;
			relativeLineMarker.scale.x = 0.3;
			relativeLineMarker.scale.y = 0.3;
			relativeLineMarker.scale.z = 0.3;
			relativeLineMarker.color.r = 1.0f;
			relativeLineMarker.color.g = 0.0f;
			relativeLineMarker.color.b = 0.0f;
			relativeLineMarker.color.a = 1.0;
			relativeLineMarker.action = visualization_msgs::Marker::MODIFY;
			relativeLineMarker.pose.orientation.w = 1;	// équivalent à relativeLineMarker.pose.orientation = tf::createQuaternionMsgFromYaw(0);

			for(int i = 0; i < lines_filtering.QtyLine.data; i++){
				for(int j = 0; j < lines_filtering.line[i].QtySegment.data; j++){
					relativeLineMarker.points.push_back(lines_filtering.line[i].segment[j].position);
				}
			}

			pub_lines_filtering.publish(relativeLineMarker);
		}

		loop_rate.sleep();
	}

	return 0;
}
