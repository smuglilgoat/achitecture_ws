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

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------

int main(int argc, char** argv)
{
	ros::init(argc, argv, "map_matching");

	ros::NodeHandle n;

	// Publisher

	// Subscriber 

	ros::Rate loop_rate(25);

  	while(n.ok())
	{
		ros::spinOnce();

		loop_rate.sleep();
	}

	return 0;
}
