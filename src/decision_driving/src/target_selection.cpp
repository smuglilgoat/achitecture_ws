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

#include "project_s_msgs/ObstacleFusion.h"
#include "project_s_msgs/ObstacleFusionReport.h"
#include "project_s_msgs/TargetSelection.h"
#include "project_s_msgs/ObjectManoeuvre.h"
#include "project_s_msgs/RoutePlanning.h"

//#include "decision_driving/target_selection.h"



/** Defines **/
// block states
#define DATA_WAIT				0	// wait for data
#define TARGET_SELECTION		1	// select the target 
#define TARGET_PUBLISH			2	// publish the data


/** Buffers **/
project_s_msgs::ObstacleFusionReport currentObstacleAssignment;
project_s_msgs::ObjectManoeuvre mobileObjectManoeuvre;
project_s_msgs::RoutePlanning routePlanned;

/** State variables **/
uint8_t targetSelectionState = DATA_WAIT;

/** Published data **/
project_s_msgs::TargetSelection targetSelection;


/** Callback functions for receiving smart data **/
void obstaclesAssignmentCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& obstacleAssignment)
{
	currentObstacleAssignment = *obstacleAssignment;
	targetSelectionState = DATA_WAIT;
}

void mobileObjectManoeuvreCallback(const project_s_msgs::ObjectManoeuvre::ConstPtr& objectManoeuvre)
{
	mobileObjectManoeuvre = *objectManoeuvre;
	targetSelectionState = TARGET_SELECTION;
}

void routePlanningCallback(const project_s_msgs::RoutePlanning::ConstPtr& routePlanning)
{
	routePlanned = *routePlanning;
	targetSelectionState = DATA_WAIT;
}
/*************************************************/



void selectTarget(void)
{
	targetSelectionState = TARGET_PUBLISH;

}

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("target_selection"));

	ros::NodeHandle n;

	ros::Subscriber subObs = n.subscribe(std::string("/obstacles_assignment_data"), 1, obstaclesAssignmentCallback);
	ros::Subscriber subRoadModel = n.subscribe(std::string("/mobile_object_manoeuvre_data"), 1, mobileObjectManoeuvreCallback);
	ros::Subscriber subRoute = n.subscribe(std::string("/route_planning_data"), 1, routePlanningCallback);

	ros::Publisher pub = n.advertise<project_s_msgs::TargetSelection>(std::string("/target_selection_data"), 1);

	ros::Rate loop_rate(25);

	while(n.ok())
	{
		/** State machine **/
		switch(targetSelectionState)
		{
			case DATA_WAIT:
				// we read the data here not outside in the main loop
				ros::spinOnce();
				loop_rate.sleep();
				break;
			case TARGET_SELECTION:
				// call assignment function
				selectTarget();
				printf("\nAssignning obstacle\n");
				break;
			case TARGET_PUBLISH:
			    pub.publish(targetSelection);
			    printf("\nPublishing data\n");
			    targetSelectionState = DATA_WAIT;
				//printf("\nSent Obstacle data:\n Position x: %f \n Position y: %f \n Position z: %f \n",fusionData.obstaclePosition.position.x, fusionData.obstaclePosition.position.y, fusionData.obstaclePosition.position.z);
				break;
			default :
				break;
		}

		loop_rate.sleep();
	}

	return 0;
}

