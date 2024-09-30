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

#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>
#define	MEAN_NORMAL_DISTRIBUTION	1.0
#define	SD_NORMAL_DISTRIBUTION		0.005
boost::mt19937 generator;
boost::normal_distribution<> distribution(MEAN_NORMAL_DISTRIBUTION, SD_NORMAL_DISTRIBUTION);

#include "ros/ros.h"
#include <tf/transform_broadcaster.h>

#include "nav_msgs/Odometry.h"

#include "project_s_msgs/ObstacleReport.h"

project_s_msgs::ObstacleReport extractedObstacles;
project_s_msgs::ObstacleReport ObstacleRelative, ObstacleRelativePrecedent;
project_s_msgs::ObstacleReport reportObstacles;

std_msgs::UInt8 QtyObstacles;

nav_msgs::Odometry odom;

// Server parameters
double range = 0.0, fov = 0.0;
geometry_msgs::Point offset;

bool received = false;
void odomCallback(const nav_msgs::Odometry::ConstPtr& odometry)
{
	odom = *odometry;
}

void obstacleDataCallback(const project_s_msgs::ObstacleReport::ConstPtr& genericSmartDataArray)
{
	extractedObstacles = *genericSmartDataArray;

	received = true;
}

bool inView(project_s_msgs::GenericSmartData objectInView)
{
	double c1 = objectInView.obstaclePosition.position.x;
	double c2 = std::abs(objectInView.obstaclePosition.position.y);
	double i = std::sqrt(std::pow(c1,2)+std::pow(c2,2));
	
	if ((c2 == 0.0) && (c1 = 0.0))
		return false;
	
	if (((c2 == 0.0) && (c1 >= 2.0)) 
		|| ((c1 >= 2.0) && (c1/c2 > tan((M_PI - fov)/2)))
		&&  (i < range))
		return true;
	else
		return false;
		
}

geometry_msgs::Point computeRelativePosition(geometry_msgs::Point point, geometry_msgs::Point off_, nav_msgs::Odometry odomm)
{	// calculs de la position dans le repère du lidar sensor,
	// à partir de la position dans le repère absolu
	geometry_msgs::Point p;
	double theta = tf::getYaw(odomm.pose.pose.orientation);

	p.x =  (point.x - odomm.pose.pose.position.x) * cos(theta) + (point.y - odomm.pose.pose.position.y) * sin(theta);
	p.y = -(point.x - odomm.pose.pose.position.x) * sin(theta) + (point.y - odomm.pose.pose.position.y) * cos(theta);
	p.z =  (point.z - odomm.pose.pose.position.z);

	p.x -= off_.x;
	p.y -= off_.y;
	p.z -= off_.z;

	return p;
}

geometry_msgs::Twist computeRelativeVelocity(geometry_msgs::Point point, geometry_msgs::Point point_precedent, double dt)
{	// calculs de la vitesse dans le repère du lidar sensor,
	// à partir des positions dans le repère relatif
	geometry_msgs::Twist velocity;

	velocity.linear.x = (point.x - point_precedent.x) / dt;
	velocity.linear.y = (point.y - point_precedent.y) / dt;
	velocity.linear.z = 0;

	return velocity;
}

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("radar_SRR2_model"));

	ros::NodeHandle n;

	// Raport publisher with relative positions for the objects
	ros::Publisher pubRaport = n.advertise<project_s_msgs::ObstacleReport>(std::string("/radar_SRR2_obstacle"), 1);

	// Subscriber global reference obstacle data  
	ros::Subscriber subData = n.subscribe(std::string("/obstacles"), 1, obstacleDataCallback);

	// Subscriber odometry
	ros::Subscriber subOdom = n.subscribe(std::string("/odom"), 1, odomCallback);

	ros::Rate loop_rate(15);

	if (n.hasParam("/SSR2_AVG/offset_x"))
		n.getParam("/SSR2_AVG/offset_x", offset.x);
	if (n.hasParam("/SSR2_AVG/offset_y"))
		n.getParam("/SSR2_AVG/offset_y", offset.y);
	if (n.hasParam("/SSR2_AVG/offset_z"))
		n.getParam("/SSR2_AVG/offset_z", offset.z);
	if (n.hasParam("/SSR2_AVG/range"))
		n.getParam("/SSR2_AVG/range", range);
	if (n.hasParam("/SSR2_AVG/fov"))
		n.getParam("/SSR2_AVG/fov", fov);

	bool flError = false;
	float error = 0;

	while(n.ok())
	{
		ros::spinOnce();

		// Transform intro ego relative position
		//if (received)
		{
			received = false;

			// Obstacles handling
			ObstacleRelativePrecedent = ObstacleRelative;	// sert au calcul de vitesse

			// reset the containers
			ObstacleRelative = project_s_msgs::ObstacleReport();

			ObstacleRelative.header.frame_id = "/base_link";
			ObstacleRelative.header.stamp    = odom.header.stamp;
			ObstacleRelative.id              = extractedObstacles.id;
			ObstacleRelative.QtySmartData    = extractedObstacles.QtySmartData;
			// on enregistre la position absolue d'où le capteur fait le report
			ObstacleRelative.odom            = odom;

			// calculation of relative position and velocity
			double dt = (ObstacleRelative.header.stamp - ObstacleRelativePrecedent.header.stamp).toSec();
			if(dt == 0)
				dt = 1.0/35.0;
			for (int i = 0; i < extractedObstacles.QtySmartData.data; i++)
			{
				ObstacleRelative.GenericSmartData[i] = extractedObstacles.GenericSmartData[i];

				// calculs de la position dans le repère du lidar sensor
				ObstacleRelative.GenericSmartData[i].obstaclePosition.position = computeRelativePosition(ObstacleRelative.GenericSmartData[i].obstaclePosition.position,
															 offset, ObstacleRelative.odom);

				// calculs de la vitesse dans le repère du lidar sensor
				ObstacleRelative.GenericSmartData[i].obstacleVelocity = computeRelativeVelocity(ObstacleRelative.GenericSmartData[i].obstaclePosition.position, 
								    						ObstacleRelativePrecedent.GenericSmartData[i].obstaclePosition.position, dt);
			}

			// reset the containers
			reportObstacles = project_s_msgs::ObstacleReport();
			QtyObstacles.data = 0;

			reportObstacles.header.frame_id = "/base_link";
			reportObstacles.header.stamp    = ObstacleRelative.header.stamp;
			reportObstacles.id              = ObstacleRelative.id;
			// on enregistre la position absolue d'où le capteur fait le report
			reportObstacles.odom            = ObstacleRelative.odom;

			// send the data further
			for (int i = 0; i < ObstacleRelative.QtySmartData.data; i++)
			{
				// Verify if it is inView
				if (inView(ObstacleRelative.GenericSmartData[i]))
				{
					reportObstacles.GenericSmartData[QtyObstacles.data].header.frame_id  = "/base_link";
					reportObstacles.GenericSmartData[QtyObstacles.data].header.stamp     = ObstacleRelative.header.stamp;
					reportObstacles.GenericSmartData[QtyObstacles.data].id               = ObstacleRelative.GenericSmartData[i].id;
				
					reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePosition = ObstacleRelative.GenericSmartData[i].obstaclePosition;
					// ajout d'une erreur de mesure de position
					if(flError)
					{
						error = distribution(generator);
						//reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePosition.position.x += error;
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePosition.position.x *= error;
						error = distribution(generator);
						//reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePosition.position.y += error;
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePosition.position.y *= error;

						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePoseVariance.position.x = 
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePosition.position.x * SD_NORMAL_DISTRIBUTION;
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePoseVariance.position.y =
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePosition.position.y * SD_NORMAL_DISTRIBUTION;
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePoseVariance.position.z = 0.5;	// par défaut
					}
					else
					{
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePoseVariance.position.x = 0.5;	// par défaut
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePoseVariance.position.y = 0.5;	// par défaut
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePoseVariance.position.z = 0.5;	// par défaut
					}

					// màj de la vitesse
					reportObstacles.GenericSmartData[QtyObstacles.data].obstacleVelocity = ObstacleRelative.GenericSmartData[i].obstacleVelocity;

					// màj de l'incertitude de mesure de la vitesse
					reportObstacles.GenericSmartData[QtyObstacles.data].obstacleVelocityVariance.linear.x = 0.5;	// par défaut
					reportObstacles.GenericSmartData[QtyObstacles.data].obstacleVelocityVariance.linear.y = 0.5;	// par défaut
					reportObstacles.GenericSmartData[QtyObstacles.data].obstacleVelocityVariance.linear.z = 0.5;	// par défaut

					reportObstacles.GenericSmartData[QtyObstacles.data].obstacleDimensions = ObstacleRelative.GenericSmartData[i].obstacleDimensions; // length, width, height

					QtyObstacles.data++;
				}
			}

			reportObstacles.QtySmartData = QtyObstacles;

			pubRaport.publish(reportObstacles);
		}

		loop_rate.sleep();
	}
	
	return 0;
}
