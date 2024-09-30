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

#include "ros/ros.h"
#include <tf/transform_broadcaster.h>

#include "visualization_msgs/Marker.h"
#include "project_s_msgs/ObstacleReport.h"
#include "project_s_msgs/ObstacleAlignmentReport.h"
#include "project_s_msgs/RouteLine.h"
#include "project_s_msgs/LaneAlignment.h"
#include "project_s_msgs/LaneAlignmentME.h"

#include <mobileye_560_660_msgs/Lane.h>
#include <mobileye_560_660_msgs/LkaLane.h>
#include <mobileye_560_660_msgs/LkaReferencePoints.h>
#include <mobileye_560_660_msgs/AftermarketLane.h>
#include <mobileye_560_660_msgs/LkaNumOfNextLaneMarkersReported.h>

#include <mobileye_560_660_msgs/ObstacleData.h>
#include <mobileye_560_660_msgs/ObstacleStatus.h>

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleReport extractedObstacle;
project_s_msgs::RouteLine extractedLine;

mobileye_560_660_msgs::Lane Lane;
mobileye_560_660_msgs::LkaLane left_lka_lane, right_lka_lane, next_lka_lane;
mobileye_560_660_msgs::LkaReferencePoints lka_reference_points;
mobileye_560_660_msgs::AftermarketLane aftermarket_lane;
mobileye_560_660_msgs::LkaNumOfNextLaneMarkersReported lka_num_of_next_lane;

mobileye_560_660_msgs::ObstacleData obstacle_data;
mobileye_560_660_msgs::ObstacleStatus obstacle_status;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleAlignmentReport reportObstacle;
project_s_msgs::LaneAlignment laneAlignReport;
project_s_msgs::LaneAlignmentME laneAlignMEReport;

//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------
geometry_msgs::Point offset, offset_line;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool received = false;
void obstacleDataCallback(const project_s_msgs::ObstacleReport::ConstPtr& ObstacleArray)
{
	extractedObstacle = *ObstacleArray;

	received = true;
}

bool routeLineReceived = false;
void linesDataCallback(const project_s_msgs::RouteLine::ConstPtr& routeLine)
{
	extractedLine = *routeLine;

	routeLineReceived = true;
}

void laneDataCallback(const mobileye_560_660_msgs::Lane::ConstPtr& buffer)
{
	Lane = *buffer;
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

bool nextlkalaneReceived = false;
void nextlkalaneDataCallback(const mobileye_560_660_msgs::LkaLane::ConstPtr& buffer)
{
	next_lka_lane = *buffer;

	nextlkalaneReceived = true;
}

void lkareferencepointsDataCallback(const mobileye_560_660_msgs::LkaReferencePoints::ConstPtr& buffer)
{
	lka_reference_points = *buffer;
}

void aftermarketlaneDataCallback(const mobileye_560_660_msgs::AftermarketLane::ConstPtr& buffer)
{
	aftermarket_lane = *buffer;
}

void lkanumofnextlaneDataCallback(const mobileye_560_660_msgs::LkaNumOfNextLaneMarkersReported::ConstPtr& buffer)
{
	lka_num_of_next_lane = *buffer;
}

void obstacleCallback(const mobileye_560_660_msgs::ObstacleData::ConstPtr& buffer)
{
	obstacle_data = *buffer;
}

void obstacleStatusCallback(const mobileye_560_660_msgs::ObstacleStatus::ConstPtr& buffer)
{
	obstacle_status = *buffer;
}

//-------------------------------------------------------------------------------------------------
// local functions
//-------------------------------------------------------------------------------------------------
// alignement spatial
geometry_msgs::Point obstacleAlignment(geometry_msgs::Point point, geometry_msgs::Point off_)
{
	geometry_msgs::Point p;
	p.x = point.x + off_.x; // add the camera's position to ego reference and the ego reference position relative to the center of the car
	p.y = point.y + off_.y;
	p.z = point.z + off_.z;

	return p;
}

// alignement spatial
geometry_msgs::Point lineAlignment(geometry_msgs::Point point, geometry_msgs::Point off_)
{
	geometry_msgs::Point p;
	p.x = point.x + off_.x; // add the camera's position to ego reference and the ego reference position relative to the center of the car
	p.y = point.y + off_.y;
	p.z = point.z + off_.z;

	return p;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("camera_me_alignment"));

	ros::NodeHandle n;

	// Subscriber global reference obstacle data  
	ros::Subscriber subData  = n.subscribe(std::string("/camera_me_data_extraction_obstacle"),    1, obstacleDataCallback);
	ros::Subscriber subLines = n.subscribe(std::string("/camera_me_data_extraction_route_lines"), 1, linesDataCallback);

	ros::Subscriber sub_lane                 = n.subscribe(std::string("/parsed_tx/lane"),                                  1, laneDataCallback);
	ros::Subscriber sub_left_lka_lane        = n.subscribe(std::string("/parsed_tx/left_lka_lane"),                         1, leftlkalaneDataCallback);
	ros::Subscriber sub_right_lka_lane       = n.subscribe(std::string("/parsed_tx/right_lka_lane"),                        1, rightlkalaneDataCallback);
	ros::Subscriber sub_next_lka_lane        = n.subscribe(std::string("/parsed_tx/next_lka_lane"),                         1, nextlkalaneDataCallback);
	ros::Subscriber sub_lka_reference_points = n.subscribe(std::string("/parsed_tx/lka_reference_points"),                  1, lkareferencepointsDataCallback);
	ros::Subscriber sub_aftermarket_lane     = n.subscribe(std::string("/parsed_tx/aftermarket_lane"),                      1, aftermarketlaneDataCallback);
	ros::Subscriber sub_lka_num_of_next_lane = n.subscribe(std::string("/parsed_tx/lka_num_of_next_lane_markers_reported"), 1, lkanumofnextlaneDataCallback);

	ros::Subscriber sub_obstacle_data   = n.subscribe(std::string("/parsed_tx/obstacle_data"),   1, obstacleCallback);
	ros::Subscriber sub_obstacle_status = n.subscribe(std::string("/parsed_tx/obstacle_status"), 1, obstacleStatusCallback);

	// Raport publisher with relative positions for the objects with the car
	ros::Publisher pubRaport         = n.advertise<project_s_msgs::ObstacleAlignmentReport>(std::string("/camera_me_obstacles_align_data"), 1);
	ros::Publisher pubLaneAlign      = n.advertise<project_s_msgs::LaneAlignment>          (std::string("/camera_me_route_alignment_data"), 1);
	ros::Publisher pub_lane_align_ME = n.advertise<project_s_msgs::LaneAlignmentME>        (std::string("/camera_me_lines_align_report"),   1);

	ros::Duration clk_offset_right_mean, clk_offset_left_mean, clk_offset_next_mean;
	ros::Duration Latency(0.001);	// to precise

	ros::Time last_time_right, last_time_left, last_time_next;
	last_time_right = last_time_left = last_time_next = ros::Time::now();

	ros::Rate loop_rate(1000);

	if (n.hasParam("/mobil_eye/offset_x"))
		n.getParam("/mobil_eye/offset_x", offset.x);
	if (n.hasParam("/mobil_eye/offset_y"))
		n.getParam("/mobil_eye/offset_y", offset.y);
	if (n.hasParam("/mobil_eye/offset_z"))
		n.getParam("/mobil_eye/offset_z", offset.z);
	if (n.hasParam("/mobil_eye/offset_line_x"))
		n.getParam("/mobil_eye/offset_line_x", offset_line.x);
	if (n.hasParam("/mobil_eye/offset_line_y"))
		n.getParam("/mobil_eye/offset_line_y", offset_line.y);
	if (n.hasParam("/mobil_eye/offset_line_z"))
		n.getParam("/mobil_eye/offset_line_z", offset_line.z);

	geometry_msgs::Point egoRelativePosition;
	
	while(n.ok())
	{
		ros::spinOnce();

		if (received)
		{
			received = false;

			reportObstacle              = project_s_msgs::ObstacleAlignmentReport();
			reportObstacle.header       = extractedObstacle.header;
			reportObstacle.id           = extractedObstacle.id;
			reportObstacle.odom         = extractedObstacle.odom;
			reportObstacle.QtyObstacles = extractedObstacle.QtySmartData;

			for(int i = 0; i < extractedObstacle.QtySmartData.data; i++)
			{
				reportObstacle.ObstacleAlignement[i].header                   = extractedObstacle.GenericSmartData[i].header;
				reportObstacle.ObstacleAlignement[i].id                       = extractedObstacle.GenericSmartData[i].id;
				reportObstacle.ObstacleAlignement[i].obstaclePosition         = extractedObstacle.GenericSmartData[i].obstaclePosition;
				reportObstacle.ObstacleAlignement[i].obstaclePoseVariance     = extractedObstacle.GenericSmartData[i].obstaclePoseVariance;
				reportObstacle.ObstacleAlignement[i].obstacleVelocity         = extractedObstacle.GenericSmartData[i].obstacleVelocity;
				reportObstacle.ObstacleAlignement[i].obstacleVelocityVariance = extractedObstacle.GenericSmartData[i].obstacleVelocityVariance;
				reportObstacle.ObstacleAlignement[i].obstacleAcceleration     = extractedObstacle.GenericSmartData[i].obstacleAcceleration;
				reportObstacle.ObstacleAlignement[i].obstacleDimensions       = extractedObstacle.GenericSmartData[i].obstacleDimensions;
				reportObstacle.ObstacleAlignement[i].obstacleClass            = extractedObstacle.GenericSmartData[i].obstacleClass;
				reportObstacle.ObstacleAlignement[i].vision_only_sign_type    = extractedObstacle.GenericSmartData[i].vision_only_sign_type;

				// alignement spatial
				egoRelativePosition = obstacleAlignment(reportObstacle.ObstacleAlignement[i].obstaclePosition.position, offset);
				reportObstacle.ObstacleAlignement[i].obstaclePosition.position = egoRelativePosition;
			}

			pubRaport.publish(reportObstacle);
		}

		if(routeLineReceived)
		{
			routeLineReceived = false;

			laneAlignReport        = project_s_msgs::LaneAlignment();
			laneAlignReport.header = extractedLine.header;
			laneAlignReport.id     = extractedLine.id;
			laneAlignReport.odom   = extractedLine.odom;

			for(int i = 0; i < 3; i++)	// extractedLine est un tableau		5 lignes de 250 segments
			{				// mais on se limite pour l'instant à	3 lignes de  10 segments
				for(int j = 0; j < 10; j++)
				{
					if((extractedLine.line[i].segment[j].position.x != 0) || (extractedLine.line[i].segment[j].position.y != 0))
					{
						laneAlignReport.line[i].segment[j].position = extractedLine.line[i].segment[j].position;
						laneAlignReport.line[i].segment[j].Velocity = extractedLine.line[i].segment[j].Velocity;

						// alignement spatial
						egoRelativePosition = lineAlignment(extractedLine.line[i].segment[j].position, offset_line);
						laneAlignReport.line[i].segment[j].position = egoRelativePosition;
					}
				}
			}

			pubLaneAlign.publish(laneAlignReport);
		}

		if(rightlkalaneReceived)
		{
			//rightlkalaneReceived = false;

			ros::Time current_time = ros::Time::now();
			double dt = (current_time - last_time_right).toSec();
			last_time_right = current_time;

			// time alignment
			double clk_offset  = (current_time - right_lka_lane.header.stamp - Latency).toSec();	
					// hyp : right_lka_lane.header.stamp = timestamp de la prise d'échantillon.
					//	 ros::Time::now() représente la date de réception, à remplacer par la date de réception CAN au plus près.

			double K = exp(-dt/0.100);
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_right_mean.toSec();
			clk_offset_right_mean = ros::Duration(clk_offset);
			right_lka_lane.header.stamp += clk_offset_right_mean;

			// spatial alignment,
			// on commence par _c0, avant que _c1, _c2, _c3 ne soient modifiés.
			right_lka_lane.position_parameter_c0      += -      right_lka_lane.curvature_derivative_parameter_c3 * std::pow(offset_line.x,3);
			right_lka_lane.position_parameter_c0      +=        right_lka_lane.curvature_parameter_c2            * std::pow(offset_line.x,2);
			right_lka_lane.position_parameter_c0      += -      right_lka_lane.heading_angle_parameter_c1        *          offset_line.x     + offset_line.y;

			right_lka_lane.heading_angle_parameter_c1 +=  3.0 * right_lka_lane.curvature_derivative_parameter_c3 * std::pow(offset_line.x,2);
			right_lka_lane.heading_angle_parameter_c1 += -2.0 * right_lka_lane.curvature_parameter_c2            *          offset_line.x;

			right_lka_lane.curvature_parameter_c2     += -3.0 * right_lka_lane.curvature_derivative_parameter_c3 * offset_line.x;

			//right_lka_lane.curvature_derivative_parameter_c3  = inchangé

			right_lka_lane.marking_width += offset_line.x;		// A REVOIR
			right_lka_lane.view_range += offset_line.x;

			laneAlignMEReport.header = right_lka_lane.header;
		}

		if(leftlkalaneReceived)
		{
			//leftlkalaneReceived = false;

			ros::Time current_time = ros::Time::now();
			double dt = (current_time - last_time_left).toSec();
			last_time_left = current_time;

			// time alignment
			double clk_offset  = (current_time - left_lka_lane.header.stamp - Latency).toSec();	

			double K = exp(-dt/0.100);
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_left_mean.toSec();
			clk_offset_left_mean = ros::Duration(clk_offset);
			left_lka_lane.header.stamp += clk_offset_left_mean;

			// spatial alignment
			left_lka_lane.position_parameter_c0      += -      left_lka_lane.curvature_derivative_parameter_c3 * std::pow(offset_line.x,3);
			left_lka_lane.position_parameter_c0      +=        left_lka_lane.curvature_parameter_c2            * std::pow(offset_line.x,2);
			left_lka_lane.position_parameter_c0      += -      left_lka_lane.heading_angle_parameter_c1        *          offset_line.x     + offset_line.y;

			left_lka_lane.heading_angle_parameter_c1 +=  3.0 * left_lka_lane.curvature_derivative_parameter_c3 * std::pow(offset_line.x,2);
			left_lka_lane.heading_angle_parameter_c1 += -2.0 * left_lka_lane.curvature_parameter_c2            *          offset_line.x;

			left_lka_lane.curvature_parameter_c2     += -3.0 * left_lka_lane.curvature_derivative_parameter_c3 * offset_line.x;

			//left_lka_lane.curvature_derivative_parameter_c3  = inchangé

			left_lka_lane.marking_width += offset_line.x;		// A REVOIR
			left_lka_lane.view_range += offset_line.x;

			laneAlignMEReport.header = left_lka_lane.header;
		}

		if(nextlkalaneReceived)
		{
			//nextlkalaneReceived = false;

			ros::Time current_time = ros::Time::now();
			double dt = (current_time - last_time_next).toSec();
			last_time_next = current_time;

			// time alignment
			double clk_offset  = (current_time - next_lka_lane.header.stamp - Latency).toSec();	

			double K = exp(-dt/0.100);
			clk_offset  = (1.0-K)*clk_offset;
			clk_offset +=      K *clk_offset_next_mean.toSec();
			clk_offset_next_mean = ros::Duration(clk_offset);
			next_lka_lane.header.stamp += clk_offset_next_mean;

			// spatial alignment
			next_lka_lane.position_parameter_c0      += -      next_lka_lane.curvature_derivative_parameter_c3 * std::pow(offset_line.x,3);
			next_lka_lane.position_parameter_c0      +=        next_lka_lane.curvature_parameter_c2            * std::pow(offset_line.x,2);
			next_lka_lane.position_parameter_c0      += -      next_lka_lane.heading_angle_parameter_c1        *          offset_line.x     + offset_line.y;

			next_lka_lane.heading_angle_parameter_c1 +=  3.0 * next_lka_lane.curvature_derivative_parameter_c3 * std::pow(offset_line.x,2);
			next_lka_lane.heading_angle_parameter_c1 += -2.0 * next_lka_lane.curvature_parameter_c2            *          offset_line.x;

			next_lka_lane.curvature_parameter_c2     += -3.0 * next_lka_lane.curvature_derivative_parameter_c3 * offset_line.x;

			//next_lka_lane.curvature_derivative_parameter_c3  = inchangé

			next_lka_lane.marking_width += offset_line.x;		// A REVOIR
			next_lka_lane.view_range += offset_line.x;

			laneAlignMEReport.header = next_lka_lane.header;
		}

		if(rightlkalaneReceived || leftlkalaneReceived || nextlkalaneReceived){
			rightlkalaneReceived = false;
			leftlkalaneReceived  = false;
			nextlkalaneReceived  = false;

			uint QtyLine = 0;
			ros::Duration Ecart_Temps;
			ros::Duration ECART_TEMPS_LIMITE(0.100);

			Ecart_Temps  = laneAlignMEReport.header.stamp - right_lka_lane.header.stamp;
			if(Ecart_Temps <= ECART_TEMPS_LIMITE){
				laneAlignMEReport.line[QtyLine] = right_lka_lane;
laneAlignMEReport.line_min[QtyLine] = right_lka_lane.marking_width;	// A REVOIR
laneAlignMEReport.line_max[QtyLine] = right_lka_lane.view_range;
				QtyLine++;
			}
			Ecart_Temps  = laneAlignMEReport.header.stamp - left_lka_lane.header.stamp;
			if(Ecart_Temps <= ECART_TEMPS_LIMITE){
				laneAlignMEReport.line[QtyLine] = left_lka_lane;
laneAlignMEReport.line_min[QtyLine] = left_lka_lane.marking_width;	// A REVOIR
laneAlignMEReport.line_max[QtyLine] = left_lka_lane.view_range;
				QtyLine++;
			}
			Ecart_Temps  = laneAlignMEReport.header.stamp - next_lka_lane.header.stamp;
			if(Ecart_Temps <= ECART_TEMPS_LIMITE){
				laneAlignMEReport.line[QtyLine] = next_lka_lane;
laneAlignMEReport.line_min[QtyLine] = next_lka_lane.marking_width;	// A REVOIR
laneAlignMEReport.line_max[QtyLine] = next_lka_lane.view_range;
				QtyLine++;
			}

			laneAlignMEReport.QtyLine.data = QtyLine;

			pub_lane_align_ME.publish(laneAlignMEReport);
		}

		loop_rate.sleep();
	}

	return 0;
}
