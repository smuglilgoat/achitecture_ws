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

//#include <mobileye_560_660_msgs/LkaLane.h>
//#include <mobileye_560_660_msgs/LkaReferencePoints.h>
#include "project_s_msgs/LaneAlignment.h"
//#include "project_s_msgs/LaneAlignmentME.h"
#include "message_project_s/LaneAlignmentME_1.h"

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
//project_s_msgs::LaneAlignmentME laneAlignMEReport;
message_project_s::LaneAlignmentME_1 laneAlignMEReport;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::LaneAlignment lines_filtering;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool received_lane_align_report = false;
//void laneAlignReportCallback(const project_s_msgs::LaneAlignmentME::ConstPtr& buffer)
void laneAlignReportCallback(const message_project_s::LaneAlignmentME_1::ConstPtr& buffer)
{
	laneAlignMEReport = *buffer;

	received_lane_align_report = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "lines_filtering");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher pub_lines_filtering = n.advertise<project_s_msgs::LaneAlignment>(std::string("/lines_filtering_data"), 1);

	// Subscriber
	//ros::Subscriber sub_lka_lane_report = n.subscribe(std::string("/camera_me_lines_align_report"), 1, laneAlignReportCallback);
	ros::Subscriber sub_lka_lane_report = n.subscribe(std::string("/MobilEye_LaneAlignmentReport"), 1, laneAlignReportCallback);

	ros::Rate loop_rate(100);

  	while(n.ok())
	{
		ros::spinOnce();

		if(received_lane_align_report){
			received_lane_align_report = false;

			lines_filtering        = project_s_msgs::LaneAlignment();
			lines_filtering.header = laneAlignMEReport.header;

			//for(int i = 0; i < laneAlignMEReport.QtyLine.data; i++)
int i = -1;
			// RIGHT_LINE
			if(laneAlignMEReport.right_quality != 0)
			{
i++;
				geometry_msgs::Point pt;
				//#define ERREUR_MAX	1

				uint QtySegment = 0;

				// premier point
#define OFFSET_MIN	5
				pt.x  = OFFSET_MIN;
if(laneAlignMEReport.right_view_range < OFFSET_MIN)
pt.x  = laneAlignMEReport.right_view_range;
				pt.y  = laneAlignMEReport.right_position_parameter_c0;
				pt.y += laneAlignMEReport.right_heading_angle_parameter_c1        *          pt.x;
				pt.y += laneAlignMEReport.right_curvature_parameter_c2            * std::pow(pt.x,2);
				pt.y += laneAlignMEReport.right_curvature_derivative_parameter_c3 * std::pow(pt.x,3);

				uint j=0;
				lines_filtering.line[i].segment[j].position = pt;
				QtySegment++;

				// points suivants
				//#define NBR_POINTS_MAX	15.0
				//double delta_x = (laneAlignMEReport.line_max[i] - pt.x) / NBR_POINTS_MAX;
				//double delta_x = (laneAlignMEReport.right_view_range - pt.x) / NBR_POINTS_MAX;
				//if(delta_x < 1.0)
				//	delta_x = 1.0;
#define DELTA_X	2.0
				double delta_x = DELTA_X;

				pt.x += delta_x;
				while(pt.x < laneAlignMEReport.right_view_range){
					pt.y  = laneAlignMEReport.right_position_parameter_c0;
					pt.y += laneAlignMEReport.right_heading_angle_parameter_c1        *          pt.x;
					pt.y += laneAlignMEReport.right_curvature_parameter_c2            * std::pow(pt.x,2);
					pt.y += laneAlignMEReport.right_curvature_derivative_parameter_c3 * std::pow(pt.x,3);

					if(j < project_s_msgs::Line::SEGMENT_REPORT_SIZE-1){
					j++;
					lines_filtering.line[i].segment[j].position = pt;
					QtySegment++;
					}

					pt.x += delta_x;
				}

				// dernier point
				pt.x  = laneAlignMEReport.right_view_range;
				pt.y  = laneAlignMEReport.right_position_parameter_c0;
				pt.y += laneAlignMEReport.right_heading_angle_parameter_c1        *          pt.x;
				pt.y += laneAlignMEReport.right_curvature_parameter_c2            * std::pow(pt.x,2);
				pt.y += laneAlignMEReport.right_curvature_derivative_parameter_c3 * std::pow(pt.x,3);


				j++;
				lines_filtering.line[i].segment[j].position = pt;
				QtySegment++;

				lines_filtering.line[i].QtySegment.data = QtySegment;
			}

			// LEFT_LINE
			if(laneAlignMEReport.left_quality != 0)
			{
i++;
				geometry_msgs::Point pt;

				uint QtySegment = 0;

				// premier point
				pt.x  = OFFSET_MIN;
if(laneAlignMEReport.left_view_range < OFFSET_MIN)
pt.x  = laneAlignMEReport.left_view_range;
				pt.y  = laneAlignMEReport.left_position_parameter_c0;
				pt.y += laneAlignMEReport.left_heading_angle_parameter_c1        *          pt.x;
				pt.y += laneAlignMEReport.left_curvature_parameter_c2            * std::pow(pt.x,2);
				pt.y += laneAlignMEReport.left_curvature_derivative_parameter_c3 * std::pow(pt.x,3);

				uint j=0;
				lines_filtering.line[i].segment[j].position = pt;
				QtySegment++;

				// points suivants
				//#define NBR_POINTS_MAX	15.0
				//double delta_x = (laneAlignMEReport.left_view_range - pt.x) / NBR_POINTS_MAX;
				//if(delta_x < 1.0)
				//	delta_x = 1.0;
				double delta_x = DELTA_X;

				pt.x += delta_x;
				while(pt.x < laneAlignMEReport.left_view_range){
					pt.y  = laneAlignMEReport.left_position_parameter_c0;
					pt.y += laneAlignMEReport.left_heading_angle_parameter_c1        *          pt.x;
					pt.y += laneAlignMEReport.left_curvature_parameter_c2            * std::pow(pt.x,2);
					pt.y += laneAlignMEReport.left_curvature_derivative_parameter_c3 * std::pow(pt.x,3);

					if(j < project_s_msgs::Line::SEGMENT_REPORT_SIZE-1){
					j++;
					lines_filtering.line[i].segment[j].position = pt;
					QtySegment++;
					}

					pt.x += delta_x;
				}

				// dernier point
				pt.x  = laneAlignMEReport.left_view_range;
				pt.y  = laneAlignMEReport.left_position_parameter_c0;
				pt.y += laneAlignMEReport.left_heading_angle_parameter_c1        *          pt.x;
				pt.y += laneAlignMEReport.left_curvature_parameter_c2            * std::pow(pt.x,2);
				pt.y += laneAlignMEReport.left_curvature_derivative_parameter_c3 * std::pow(pt.x,3);


				j++;
				lines_filtering.line[i].segment[j].position = pt;
				QtySegment++;

				lines_filtering.line[i].QtySegment.data = QtySegment;
			}

			//lines_filtering.QtyLine = laneAlignMEReport.QtyLine;
			lines_filtering.QtyLine.data = i+1;

			pub_lines_filtering.publish(lines_filtering);
		}

		loop_rate.sleep();
	}

	return 0;
}
