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

#include "project_s_msgs/ObstacleFusionReport.h"
//#include "project_s_msgs/ObstacleAssignment.h"
#include "project_s_msgs/RoadModel.h"
#include "project_s_msgs/ObjectManoeuvre.h"

//#include "decision_driving/mobile_objects_manoeuvre.h"



/** Defines **/
// block states
#define OBSTACLE_WAIT			0	// wait for data
#define OBSTACLE_DETECT_PREDICT		1	// assign the obstacles 
#define OBSTACLE_PUBLISH		2	// assign the obstacles 


/** Buffers **/
project_s_msgs::ObstacleFusionReport obstacle;
project_s_msgs::RoadModel currentRoadModel;

/** State variables **/
uint8_t obstacleDetectState = OBSTACLE_WAIT;

/** Mobile obstacle data OUTPUT **/
project_s_msgs::ObjectManoeuvre mobileObjectManoeuvre;




/** Callback functions for receiving smart data **/
void obstaclesFusionCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& obstacleFusion)
{
	obstacle = *obstacleFusion;
	obstacleDetectState = OBSTACLE_DETECT_PREDICT;
}

void roadModelCallback(const project_s_msgs::RoadModel::ConstPtr& roadModel)
{
	currentRoadModel = *roadModel;
	obstacleDetectState = OBSTACLE_WAIT;
}
/*************************************************/



void obstacleDetectPredict(void)
{
	obstacleDetectState = OBSTACLE_PUBLISH;

}

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("mobile_object_manoeuvre"));

	ros::NodeHandle n;

	ros::Subscriber subObs = n.subscribe(std::string("/global_tracks_update_data"), 1, obstaclesFusionCallback);
	ros::Subscriber subRoadModel = n.subscribe(std::string("/road_model_data"), 1, roadModelCallback);

	ros::Publisher pub = n.advertise<project_s_msgs::ObjectManoeuvre>(std::string("/mobile_object_manoeuvre_data"), 1);

	ros::Rate loop_rate(25);

	while(n.ok())
	{
		/** State machine **/
		switch(obstacleDetectState)
		{
			case OBSTACLE_WAIT:
				// we read the data here not outside in the main loop
				ros::spinOnce();
				loop_rate.sleep();
				break;
			case OBSTACLE_DETECT_PREDICT:
				// call assignment function
				obstacleDetectPredict();
				printf("\nAssignning obstacle\n");
				break;
			case OBSTACLE_PUBLISH:
			    pub.publish(mobileObjectManoeuvre);
			    printf("\nPublishing data\n");
			    obstacleDetectState = OBSTACLE_WAIT;
				//printf("\nSent Obstacle data:\n Position x: %f \n Position y: %f \n Position z: %f \n",fusionData.obstaclePosition.position.x, fusionData.obstaclePosition.position.y, fusionData.obstaclePosition.position.z);
				break;
			default :
				break;
		}

		loop_rate.sleep();
	}

	return 0;
}
