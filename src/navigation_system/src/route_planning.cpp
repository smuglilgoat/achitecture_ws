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

#include "project_s_msgs/RoutePlanning.h"

/*** Trigger on the Camera Sek data received **/


/** Defines **/
// block states
#define DATA_WAIT			0	// wait for data
#define PLAN_ROUTE			1	// plan the route
#define DATA_PUBLISH		2	// publish the data for the other nodes

/** Buffers **/
// declaring and initialising
project_s_msgs::RoutePlanning routePlanning;

uint8_t routePlanningState = DATA_WAIT;
/** Callback functions for receiving smart data **/



/*************************************************/

void planRoute(void)
{
	//fusionData.writeFromNonRT(<some fusion data>);
	
	/* RoutePlanning
		Header header
		std_msgs/UInt8 id

		project_s_msgs/Segment[] roadSegment		#segments array   
		std_msgs/UInt8 nbrLane
		std_msgs/UInt8 intersection
	 */


	routePlanningState = DATA_PUBLISH;
}

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("route_planning"));

	ros::NodeHandle n;

	ros::Publisher pub = n.advertise<project_s_msgs::RoutePlanning>(std::string("/route_planning_data"), 1);

	ros::Rate loop_rate(25);

	while(n.ok())
	{
		/** State machine **/
		switch(routePlanningState)
		{
			/** non-RT **/
			case DATA_WAIT:
				// we read the data here not outside in the main loop
				ros::spinOnce();
				loop_rate.sleep();
				routePlanningState = PLAN_ROUTE;
				break;
			case PLAN_ROUTE:
				// call fusion function
				planRoute();
				printf("\nFusing data\n");
				break;
			/** end non-RT **/
			/** RT **/
			case DATA_PUBLISH:
			    pub.publish(routePlanning);
			    /*project_s_msgs::LaneFusion laneFusionData = *(fusionData.readFromRT());
			    if (realtime_pub->trylock()){
					realtime_pub->msg_ = laneFusionData ;
					realtime_pub->msg_.header.stamp = ros::Time::now();
					realtime_pub->unlockAndPublish();
				}*/
			    printf("\nPublishing data\n");
			    routePlanningState = DATA_WAIT;
				break;
			/** end RT **/
			default :
				break;
		}

		loop_rate.sleep();
	}

	return 0;
}
