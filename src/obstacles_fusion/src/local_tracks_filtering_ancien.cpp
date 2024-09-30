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

#include "project_s_msgs/Configurations.h"

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
#ifdef PROJECT_S_SIMULATION
#include "project_s_msgs/ObstacleAlignmentReport.h"
project_s_msgs::ObstacleAlignmentReport  bufferCameraMe;
project_s_msgs::ObstacleAlignmentReport  bufferRadarESR;
project_s_msgs::ObstacleAlignmentReport  bufferLidar;
#endif

#ifdef PROJECT_S_VEHICLE
#include "message_project_s/ObstacleAlignmentReport_1.h"
message_project_s::ObstacleAlignmentReport_1  bufferCameraMe = message_project_s::ObstacleAlignmentReport_1 ();
message_project_s::ObstacleAlignmentReport_1  bufferRadarESR = message_project_s::ObstacleAlignmentReport_1 ();
message_project_s::ObstacleAlignmentReport_1  bufferLidar    = message_project_s::ObstacleAlignmentReport_1 ();
#endif

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
#include "project_s_msgs/ObstacleAlignmentReport.h"

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------

 
//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedCameraMe = false;
#ifdef PROJECT_S_SIMULATION
void cameraMeCallback(const project_s_msgs::ObstacleAlignmentReport::ConstPtr& ObstacleArray)
#endif
#ifdef PROJECT_S_VEHICLE
void cameraMeCallback(const message_project_s::ObstacleAlignmentReport_1::ConstPtr& ObstacleArray)
#endif
{
	bufferCameraMe = *ObstacleArray;

	receivedCameraMe = true;
}

bool receivedRadarESR = false;
#ifdef PROJECT_S_SIMULATION
void radarESRCallback(const project_s_msgs::ObstacleAlignmentReport::ConstPtr& ObstacleArray)
#endif
#ifdef PROJECT_S_VEHICLE
void radarESRCallback(const message_project_s::ObstacleAlignmentReport_1::ConstPtr& ObstacleArray)
#endif
{
	bufferRadarESR = *ObstacleArray;

	receivedRadarESR = true;
}

bool receivedLidar = false;
#ifdef PROJECT_S_SIMULATION
void lidarCallback(const project_s_msgs::ObstacleAlignmentReport::ConstPtr& ObstacleArray)
#endif
#ifdef PROJECT_S_VEHICLE
void lidarCallback(const message_project_s::ObstacleAlignmentReport_1::ConstPtr& ObstacleArray)
#endif
{
	bufferLidar = *ObstacleArray;

	receivedLidar = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	ros::init(argc, argv, std::string("local_tracks_filtering"));

	ros::NodeHandle n;

	ros::Publisher pub_camera_me_obstacles_filtering = n.advertise<project_s_msgs::ObstacleAlignmentReport>(std::string("/camera_me_obstacles_filtering_data"), 1);
	ros::Publisher pub_lidar_obstacles_filtering     = n.advertise<project_s_msgs::ObstacleAlignmentReport>(std::string("/lidar_obstacles_filtering_data"), 1);
	ros::Publisher pub_radar_ESR_filtering           = n.advertise<project_s_msgs::ObstacleAlignmentReport>(std::string("/radar_ESR_obstacles_filtering_data"), 1);

	ros::Subscriber subMe       = n.subscribe(std::string("/camera_me_obstacles_align_data"), 1, cameraMeCallback);
	ros::Subscriber subLidar    = n.subscribe(std::string("/lidar_obstacles_align_data"), 1, lidarCallback);
	ros::Subscriber subRadarESR = n.subscribe(std::string("/radar_ESR_obstacles_align_data"), 1,radarESRCallback);

	ros::Rate loop_rate(100);	

	while(n.ok())
	{
		ros::spinOnce();

		if (receivedRadarESR)
		{
			project_s_msgs::ObstacleAlignmentReport radaresr;

			uint QtyObstacles = 0;
#ifdef PROJECT_S_SIMULATION
			for(int i=0; i < bufferRadarESR.QtyObstacles.data; i++)
#endif
#ifdef PROJECT_S_VEHICLE
			for(int i=0; i < bufferRadarESR.ObstacleAlignement_1.size(); i++)
#endif
			{
				if(i < project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE){
					QtyObstacles++;
#ifdef PROJECT_S_SIMULATION
					radaresr.ObstacleAlignement[i] = bufferRadarESR.ObstacleAlignement[i];
#endif
#ifdef PROJECT_S_VEHICLE
					radaresr.ObstacleAlignement[i].header = bufferRadarESR.ObstacleAlignement_1[i].header;

					radaresr.ObstacleAlignement[i].id     = bufferRadarESR.ObstacleAlignement_1[i].id;

					radaresr.ObstacleAlignement[i].obstaclePosition = bufferRadarESR.ObstacleAlignement_1[i].obstaclePosition;

//--------------------------------------------
	radaresr.ObstacleAlignement[i].obstacleBodyCenter = bufferRadarESR.ObstacleAlignement_1[i].obstacleBodyCenter;
//	radaresr.ObstacleAlignement[i].obstacleBodyCenter = bufferRadarESR.ObstacleAlignement_1[i].obstaclePosition;
//--------------------------------------------


					radaresr.ObstacleAlignement[i].obstacleVelocity = bufferRadarESR.ObstacleAlignement_1[i].obstacleRelativeVelocity;		// ObstacleAlignement[].obstacleVelocity est utilise par la suite, dans la fusion, comme une vitesse relative

					radaresr.ObstacleAlignement[i].obstacleRelativeVelocity = bufferRadarESR.ObstacleAlignement_1[i].obstacleRelativeVelocity;

					radaresr.ObstacleAlignement[i].obstacleAcceleration = bufferRadarESR.ObstacleAlignement_1[i].obstacleAcceleration;

					radaresr.ObstacleAlignement[i].obstacleDimensions = bufferRadarESR.ObstacleAlignement_1[i].obstacleDimensions;

					radaresr.ObstacleAlignement[i].blinkerInfo = bufferRadarESR.ObstacleAlignement_1[i].blinkerInfo;

					radaresr.ObstacleAlignement[i].cutInAndOut = bufferRadarESR.ObstacleAlignement_1[i].cutInAndOut;

					radaresr.ObstacleAlignement[i].obstacleType = bufferRadarESR.ObstacleAlignement_1[i].obstacleType;

					radaresr.ObstacleAlignement[i].obstacleStatus = bufferRadarESR.ObstacleAlignement_1[i].obstacleStatus;

					radaresr.ObstacleAlignement[i].obstacleBrakeLights = bufferRadarESR.ObstacleAlignement_1[i].obstacleBrakeLights;

					radaresr.ObstacleAlignement[i].cipvFlag = bufferRadarESR.ObstacleAlignement_1[i].cipvFlag;

					radaresr.ObstacleAlignement[i].obstacleReplaced = bufferRadarESR.ObstacleAlignement_1[i].obstacleReplaced;

					radaresr.ObstacleAlignement[i].obstacleValid = bufferRadarESR.ObstacleAlignement_1[i].obstacleValid;

					radaresr.ObstacleAlignement[i].obstacleAge = bufferRadarESR.ObstacleAlignement_1[i].obstacleAge;

					radaresr.ObstacleAlignement[i].obstacleLane = bufferRadarESR.ObstacleAlignement_1[i].obstacleLane;

					radaresr.ObstacleAlignement[i].obstacleAngle = bufferRadarESR.ObstacleAlignement_1[i].obstacleAngle;

					radaresr.ObstacleAlignement[i].obstacleAngleVariance = bufferRadarESR.ObstacleAlignement_1[i].obstacleAngleVariance;

					radaresr.ObstacleAlignement[i].obstacleAngleRate = bufferRadarESR.ObstacleAlignement_1[i].obstacleAngleRate;

					radaresr.ObstacleAlignement[i].obstacleScaleChange = bufferRadarESR.ObstacleAlignement_1[i].obstacleScaleChange;

					radaresr.ObstacleAlignement[i].vision_only_sign_type = bufferRadarESR.ObstacleAlignement_1[i].visionOnlySignType;

					radaresr.ObstacleAlignement[i].visionOnlySupplementarySignType = bufferRadarESR.ObstacleAlignement_1[i].visionOnlySupplementarySignType;

					radaresr.ObstacleAlignement[i].signPosition = bufferRadarESR.ObstacleAlignement_1[i].signPosition;

					radaresr.ObstacleAlignement[i].filterType = bufferRadarESR.ObstacleAlignement_1[i].filterType;

					radaresr.ObstacleAlignement[i].obstaclePoseVariance = bufferRadarESR.ObstacleAlignement_1[i].obstaclePoseVariance;

					radaresr.ObstacleAlignement[i].obstacleVelocityVariance = bufferRadarESR.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;	// ObstacleAlignement[].obstacleVelocityVariance est utilise par la suite, dans la fusion, comme une variance de vitesse relative

					radaresr.ObstacleAlignement[i].obstacleRelativeVelocityVariance = bufferRadarESR.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;

					radaresr.ObstacleAlignement[i].groundHeight = bufferRadarESR.ObstacleAlignement_1[i].groundHeight;

					radaresr.ObstacleAlignement[i].classificationProbability = bufferRadarESR.ObstacleAlignement_1[i].classificationProbability;

					radaresr.ObstacleAlignement[i].dateAcquisition = bufferRadarESR.ObstacleAlignement_1[i].dateAcquisition;

					radaresr.ObstacleAlignement[i].obstacleClass = 0;
#endif
				}
			}

			radaresr.header = bufferRadarESR.header;
			radaresr.QtyObstacles.data = QtyObstacles;
			radaresr.odom = bufferRadarESR.odom;

			std::cout<<"QTY Obstacle ESR: "<<bufferRadarESR.QtyObstacles<<std::endl;

			receivedRadarESR = false;

			pub_radar_ESR_filtering.publish(radaresr);
		}

		if (receivedLidar)
		{	
			project_s_msgs::ObstacleAlignmentReport lidaribeo;

			uint QtyObstacles = 0;
#ifdef PROJECT_S_SIMULATION
			for(int i=0; i < bufferLidar.QtyObstacles.data; i++)
#endif
#ifdef PROJECT_S_VEHICLE
			for(int i=0; i < bufferLidar.ObstacleAlignement_1.size(); i++)
#endif
			{		
				if(i < project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE){
					QtyObstacles++;
#ifdef PROJECT_S_SIMULATION
					lidaribeo.ObstacleAlignement[i] = bufferLidar.ObstacleAlignement[i];
#endif
#ifdef PROJECT_S_VEHICLE
					lidaribeo.ObstacleAlignement[i].header = bufferLidar.ObstacleAlignement_1[i].header;

					lidaribeo.ObstacleAlignement[i].id     = bufferLidar.ObstacleAlignement_1[i].id;

					lidaribeo.ObstacleAlignement[i].obstaclePosition = bufferLidar.ObstacleAlignement_1[i].obstaclePosition;


//--------------------------------------------

lidaribeo.ObstacleAlignement[i].obstacleBodyCenter = bufferLidar.ObstacleAlignement_1[i].obstacleBodyCenter;
//lidaribeo.ObstacleAlignement[i].obstacleBodyCenter = bufferLidar.ObstacleAlignement_1[i].obstaclePosition;

//--------------------------------------------


					lidaribeo.ObstacleAlignement[i].obstacleVelocity = bufferLidar.ObstacleAlignement_1[i].obstacleRelativeVelocity;		// ObstacleAlignement[].obstacleVelocity est utilise par la suite, dans la fusion, comme une vitesse relative

					lidaribeo.ObstacleAlignement[i].obstacleRelativeVelocity = bufferLidar.ObstacleAlignement_1[i].obstacleRelativeVelocity;

					lidaribeo.ObstacleAlignement[i].obstacleAcceleration = bufferLidar.ObstacleAlignement_1[i].obstacleAcceleration;

					lidaribeo.ObstacleAlignement[i].obstacleDimensions = bufferLidar.ObstacleAlignement_1[i].obstacleDimensions;

					lidaribeo.ObstacleAlignement[i].blinkerInfo = bufferLidar.ObstacleAlignement_1[i].blinkerInfo;

					lidaribeo.ObstacleAlignement[i].cutInAndOut = bufferLidar.ObstacleAlignement_1[i].cutInAndOut;

					lidaribeo.ObstacleAlignement[i].obstacleType = bufferLidar.ObstacleAlignement_1[i].obstacleType;

					lidaribeo.ObstacleAlignement[i].obstacleStatus = bufferLidar.ObstacleAlignement_1[i].obstacleStatus;

					lidaribeo.ObstacleAlignement[i].obstacleBrakeLights = bufferLidar.ObstacleAlignement_1[i].obstacleBrakeLights;

					lidaribeo.ObstacleAlignement[i].cipvFlag = bufferLidar.ObstacleAlignement_1[i].cipvFlag;

					lidaribeo.ObstacleAlignement[i].obstacleReplaced = bufferLidar.ObstacleAlignement_1[i].obstacleReplaced;

					lidaribeo.ObstacleAlignement[i].obstacleValid = bufferLidar.ObstacleAlignement_1[i].obstacleValid;

					lidaribeo.ObstacleAlignement[i].obstacleAge = bufferLidar.ObstacleAlignement_1[i].obstacleAge;

					lidaribeo.ObstacleAlignement[i].obstacleLane = bufferLidar.ObstacleAlignement_1[i].obstacleLane;

					lidaribeo.ObstacleAlignement[i].obstacleAngle = bufferLidar.ObstacleAlignement_1[i].obstacleAngle;

					lidaribeo.ObstacleAlignement[i].obstacleAngleVariance = bufferLidar.ObstacleAlignement_1[i].obstacleAngleVariance;

					lidaribeo.ObstacleAlignement[i].obstacleAngleRate = bufferLidar.ObstacleAlignement_1[i].obstacleAngleRate;

					lidaribeo.ObstacleAlignement[i].obstacleScaleChange = bufferLidar.ObstacleAlignement_1[i].obstacleScaleChange;

					lidaribeo.ObstacleAlignement[i].vision_only_sign_type = bufferLidar.ObstacleAlignement_1[i].visionOnlySignType;

					lidaribeo.ObstacleAlignement[i].visionOnlySupplementarySignType = bufferLidar.ObstacleAlignement_1[i].visionOnlySupplementarySignType;

					lidaribeo.ObstacleAlignement[i].signPosition = bufferLidar.ObstacleAlignement_1[i].signPosition;

					lidaribeo.ObstacleAlignement[i].filterType = bufferLidar.ObstacleAlignement_1[i].filterType;

					lidaribeo.ObstacleAlignement[i].obstaclePoseVariance = bufferLidar.ObstacleAlignement_1[i].obstaclePoseVariance;

					lidaribeo.ObstacleAlignement[i].obstacleVelocityVariance = bufferLidar.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;	// ObstacleAlignement[].obstacleVelocityVariance est utilise par la suite, dans la fusion, comme une variance de vitesse relative

					lidaribeo.ObstacleAlignement[i].obstacleRelativeVelocityVariance = bufferLidar.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;

					lidaribeo.ObstacleAlignement[i].groundHeight = bufferLidar.ObstacleAlignement_1[i].groundHeight;

					lidaribeo.ObstacleAlignement[i].classificationProbability = bufferLidar.ObstacleAlignement_1[i].classificationProbability;

					lidaribeo.ObstacleAlignement[i].dateAcquisition = bufferLidar.ObstacleAlignement_1[i].dateAcquisition;

					lidaribeo.ObstacleAlignement[i].obstacleClass = 0;
#endif
				}
			}

			lidaribeo.header = bufferLidar.header;
			lidaribeo.QtyObstacles.data = QtyObstacles;
			lidaribeo.odom = bufferLidar.odom;

			std::cout<<"QTY Obstacle IBEO: "<<bufferLidar.QtyObstacles<<std::endl;

			receivedLidar = false;

			pub_lidar_obstacles_filtering.publish(lidaribeo);
		}

		if (receivedCameraMe)
		{
			project_s_msgs::ObstacleAlignmentReport camme;

			uint QtyObstacles = 0;
#ifdef PROJECT_S_SIMULATION
			for(int i=0; i < bufferCameraMe.QtyObstacles.data; i++)
#endif
#ifdef PROJECT_S_VEHICLE
			for(int i=0; i < bufferCameraMe.ObstacleAlignement_1.size(); i++)
#endif
			{		
				if(i < project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE){
					QtyObstacles++;
#ifdef PROJECT_S_SIMULATION
					camme.ObstacleAlignement[i] = bufferCameraMe.ObstacleAlignement[i];
#endif
#ifdef PROJECT_S_VEHICLE
					camme.ObstacleAlignement[i].header = bufferCameraMe.ObstacleAlignement_1[i].header;

					camme.ObstacleAlignement[i].id     = bufferCameraMe.ObstacleAlignement_1[i].id;

					camme.ObstacleAlignement[i].obstaclePosition = bufferCameraMe.ObstacleAlignement_1[i].obstaclePosition;


//--------------------------------------------

camme.ObstacleAlignement[i].obstacleBodyCenter = bufferCameraMe.ObstacleAlignement_1[i].obstacleBodyCenter;
//camme.ObstacleAlignement[i].obstacleBodyCenter = bufferCameraMe.ObstacleAlignement_1[i].obstaclePosition;
//--------------------------------------------



					camme.ObstacleAlignement[i].obstacleVelocity = bufferCameraMe.ObstacleAlignement_1[i].obstacleRelativeVelocity;		// ObstacleAlignement[].obstacleVelocity est utilise par la suite, dans la fusion, comme une vitesse relative

					camme.ObstacleAlignement[i].obstacleRelativeVelocity = bufferCameraMe.ObstacleAlignement_1[i].obstacleRelativeVelocity;

					camme.ObstacleAlignement[i].obstacleAcceleration = bufferCameraMe.ObstacleAlignement_1[i].obstacleAcceleration;

					camme.ObstacleAlignement[i].obstacleDimensions = bufferCameraMe.ObstacleAlignement_1[i].obstacleDimensions;

					camme.ObstacleAlignement[i].blinkerInfo = bufferCameraMe.ObstacleAlignement_1[i].blinkerInfo;

					camme.ObstacleAlignement[i].cutInAndOut = bufferCameraMe.ObstacleAlignement_1[i].cutInAndOut;

					camme.ObstacleAlignement[i].obstacleType = bufferCameraMe.ObstacleAlignement_1[i].obstacleType;

					camme.ObstacleAlignement[i].obstacleStatus = bufferCameraMe.ObstacleAlignement_1[i].obstacleStatus;

					camme.ObstacleAlignement[i].obstacleBrakeLights = bufferCameraMe.ObstacleAlignement_1[i].obstacleBrakeLights;

					camme.ObstacleAlignement[i].cipvFlag = bufferCameraMe.ObstacleAlignement_1[i].cipvFlag;

					camme.ObstacleAlignement[i].obstacleReplaced = bufferCameraMe.ObstacleAlignement_1[i].obstacleReplaced;

					camme.ObstacleAlignement[i].obstacleValid = bufferCameraMe.ObstacleAlignement_1[i].obstacleValid;

					camme.ObstacleAlignement[i].obstacleAge = bufferCameraMe.ObstacleAlignement_1[i].obstacleAge;

					camme.ObstacleAlignement[i].obstacleLane = bufferCameraMe.ObstacleAlignement_1[i].obstacleLane;

					camme.ObstacleAlignement[i].obstacleAngle = bufferCameraMe.ObstacleAlignement_1[i].obstacleAngle;

					camme.ObstacleAlignement[i].obstacleAngleVariance = bufferCameraMe.ObstacleAlignement_1[i].obstacleAngleVariance;

					camme.ObstacleAlignement[i].obstacleAngleRate = bufferCameraMe.ObstacleAlignement_1[i].obstacleAngleRate;

					camme.ObstacleAlignement[i].obstacleScaleChange = bufferCameraMe.ObstacleAlignement_1[i].obstacleScaleChange;

					camme.ObstacleAlignement[i].vision_only_sign_type = bufferCameraMe.ObstacleAlignement_1[i].visionOnlySignType;

					camme.ObstacleAlignement[i].visionOnlySupplementarySignType = bufferCameraMe.ObstacleAlignement_1[i].visionOnlySupplementarySignType;

					camme.ObstacleAlignement[i].signPosition = bufferCameraMe.ObstacleAlignement_1[i].signPosition;

					camme.ObstacleAlignement[i].filterType = bufferCameraMe.ObstacleAlignement_1[i].filterType;

					camme.ObstacleAlignement[i].obstaclePoseVariance = bufferCameraMe.ObstacleAlignement_1[i].obstaclePoseVariance;

					camme.ObstacleAlignement[i].obstacleVelocityVariance = bufferCameraMe.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;	// ObstacleAlignement[].obstacleVelocityVariance est utilise par la suite, dans la fusion, comme une variance de vitesse relative

					camme.ObstacleAlignement[i].obstacleRelativeVelocityVariance = bufferCameraMe.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;

					camme.ObstacleAlignement[i].groundHeight = bufferCameraMe.ObstacleAlignement_1[i].groundHeight;

					camme.ObstacleAlignement[i].classificationProbability = bufferCameraMe.ObstacleAlignement_1[i].classificationProbability;

					camme.ObstacleAlignement[i].dateAcquisition = bufferCameraMe.ObstacleAlignement_1[i].dateAcquisition;

					camme.ObstacleAlignement[i].obstacleClass = 0;
#endif
				}
			}

			camme.header = bufferCameraMe.header;
			camme.QtyObstacles.data = QtyObstacles;
			camme.odom = bufferCameraMe.odom;

			std::cout<<"QTY Obstacle Meye: "<<bufferCameraMe.QtyObstacles<<std::endl;

			receivedCameraMe = false;

			pub_camera_me_obstacles_filtering.publish(camme);
		}

		loop_rate.sleep();		
	}

	return 0;
}








