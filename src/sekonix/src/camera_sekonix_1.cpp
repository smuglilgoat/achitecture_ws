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
#include <cmath>

#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>
#define	MEAN_NORMAL_DISTRIBUTION	1.0
#define	SD_NORMAL_DISTRIBUTION		0.005
boost::mt19937 generator;
boost::normal_distribution<> distribution(MEAN_NORMAL_DISTRIBUTION, SD_NORMAL_DISTRIBUTION);

#include "ros/ros.h"
#include <tf/transform_broadcaster.h>

#include "nav_msgs/Odometry.h"

#include "project_s_msgs/GenericSmartData.h"
#include "project_s_msgs/ObstacleReport.h"
#include "project_s_msgs/RouteLine.h"

project_s_msgs::ObstacleReport extractedObstacles;
project_s_msgs::ObstacleReport ObstacleRelative, ObstacleRelativePrecedent;
project_s_msgs::ObstacleReport reportObstacles;
std_msgs::UInt8 QtyObstacles;

project_s_msgs::RouteLine globalRouteLine;
project_s_msgs::RouteLine reportLines, reportLinesPrecedent;
std_msgs::UInt8 QtyLines;

nav_msgs::Odometry odom;

// Server parameters
double range = 0.0, fov = 0.0;
geometry_msgs::Point offset;

void odomCallback(const nav_msgs::Odometry::ConstPtr& odometry)
{
	odom = *odometry;
}

bool received = false;
void obstacleDataCallback(const project_s_msgs::ObstacleReport::ConstPtr& genericSmartDataArray)
{
	extractedObstacles = *genericSmartDataArray;

	received = true;
}

void routeLineDataCallback(const project_s_msgs::RouteLine::ConstPtr& routeLine)
{
	globalRouteLine = *routeLine;
}

// I see the objects in ly view starting from 2 meters in a range of 20 meters
bool inViewRoute(geometry_msgs::Point point)
{
	double c1 = point.x;
	double c2 = std::abs(point.y);
	
	if ((c2 == 0.0) && (c1 = 0.0))
		return false;
	
	double i = std::sqrt(std::pow(c1,2)+std::pow(c2,2));
	
	if (((c2 == 0.0) && (c1 >= 2.0)) 
		|| ((c1 >= 2.0) && (c1/c2 > tan((M_PI - fov)/2)))
		&&  (i < range))
		return true;
	else
		return false;
		
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

// Compute relative position of the points from the car center to the camera position  which is
geometry_msgs::Point computeRelativePosition_(geometry_msgs::Point point, geometry_msgs::Point off_)
{	// calculs de la position dans le repère du camera sensor,
	// à partir de la position dans le repère absolu
	geometry_msgs::Point p;
	double theta = tf::getYaw(odom.pose.pose.orientation);

	p.x =  (point.x - odom.pose.pose.position.x) * cos(theta) + (point.y - odom.pose.pose.position.y) * sin(theta);
	p.y = -(point.x - odom.pose.pose.position.x) * sin(theta) + (point.y - odom.pose.pose.position.y) * cos(theta);
	p.z =  (point.z - odom.pose.pose.position.z);

	p.x -= off_.x;
	p.y -= off_.y;
	p.z -= off_.z;

	return p;
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

	ros::init(argc, argv, std::string("camera_sekonix_1"));

	ros::NodeHandle n;

	// Raport publisher with relative positions for the objects
	ros::Publisher pub_obstacles = n.advertise<project_s_msgs::ObstacleReport>(std::string("/camera_sekonix_obstacle"), 1);	
	ros::Publisher pub_route_lines = n.advertise<project_s_msgs::RouteLine>(std::string("/camera_sekonix_route_lines"), 1);

	// Subscriber global reference obstacle data  
	ros::Subscriber sub_obstacles = n.subscribe(std::string("/obstacles"), 1, obstacleDataCallback);
	ros::Subscriber sub_route_lines = n.subscribe("/line_data", 1, routeLineDataCallback);
	
	// Subscriber odometry
	ros::Subscriber subOdom = n.subscribe(std::string("/odom"), 1, odomCallback);

	ros::Rate loop_rate(30);

	bool flError = false;
	float error = 0;

	geometry_msgs::Point point_line;

	if (n.hasParam("/mobil_eye/offset_x"))
		n.getParam("/mobil_eye/offset_x", offset.x);
	if (n.hasParam("/mobil_eye/offset_y"))
		n.getParam("/mobil_eye/offset_y", offset.y);
	if (n.hasParam("/mobil_eye/offset_z"))
		n.getParam("/mobil_eye/offset_z", offset.z);
	if (n.hasParam("/mobil_eye/range"))
		n.getParam("/mobil_eye/range", range);
	if (n.hasParam("/mobil_eye/fov"))
		n.getParam("/mobil_eye/fov", fov);
	
	while(n.ok())
	{
		ros::spinOnce();

		// Transform intro ego relative position
		//if (received)
		{
			received = false;

//*******************
			// Lines handling
			reportLinesPrecedent = reportLines;	// sert au calcul de vitesse
			// reset the containers
			reportLines = project_s_msgs::RouteLine();

			reportLines.header.frame_id = "/base_link";
			reportLines.header.stamp = odom.header.stamp;
			reportLines.id = globalRouteLine.id;
			reportLines.dateAcquisition.data = (ros::Time::now()).toSec();		// A REVOIR
			// on enregistre la position absolue d'où le capteur fait le report
			reportLines.odom = odom;

			for (int j = 0; j < 5; j++)
			{
				bool flBouclage = false;
				int k = 0;
				int kk = 0;
				for (int i = 1; i < 250; i++)		// on ne commence pas à i=0, car point confondu avec le dernier point de la boucle
				{
					if (   globalRouteLine.line[j].segment[i].position.x != 0.0 
					    || globalRouteLine.line[j].segment[i].position.y != 0.0
					    || globalRouteLine.line[j].segment[i].position.z != 0.0)
					{
						// Calcul position relative
						point_line = computeRelativePosition_(globalRouteLine.line[j].segment[i].position, offset);				
						if (inViewRoute(point_line))
						{
							if(flError)
							{
								error = distribution(generator);
								point_line.x *= error;
								error = distribution(generator);
								point_line.y *= error;
							}

							if(i == 1)	// on ne commence pas à i=0, car point confondu avec le dernier point de la boucle
								flBouclage = true;

							if(flBouclage)
							{	// enregistrement des k points, avec gestion du bouclage de la route
								if(i<100)
								{	// enregistrement des kk premiers points
									reportLines.line[j].segment[k].position = point_line;
									kk++;
								}
								else
								{	// décalage des kk premiers points, qui doivent être en dernier
									for(int n = k; n > k-kk; n--)
									{
										reportLines.line[j].segment[n] = reportLines.line[j].segment[n-1];
									}
									// enregistrement du kème point à l'indice k-kk
									reportLines.line[j].segment[k-kk].position = point_line;
								}
							}
							else
							{	// enregistrement des k points, sans gestion du bouclage de la route
								reportLines.line[j].segment[k].position = point_line;
							}
							k++;

// ***************************************************   A REVOIR
							// calcul de la vitesse
							double dt;
							dt = reportLines.dateAcquisition.data - reportLinesPrecedent.dateAcquisition.data;

							if(reportLinesPrecedent.line[j].segment[k].position.x == 0)	// lors d'une 1ère détection, on met la vitesse à 0
								reportLinesPrecedent.line[j].segment[k].position.x = reportLines.line[j].segment[k].position.x;
							reportLines.line[j].segment[k].Velocity.linear.x =(  reportLines.line[j].segment[k].position.x \
													   - reportLinesPrecedent.line[j].segment[k].position.x) \
													   / dt;
							if(abs(reportLines.line[j].segment[k].Velocity.linear.x) > 4)
								reportLines.line[j].segment[k].Velocity.linear.x = reportLinesPrecedent.line[j].segment[k].Velocity.linear.x;

							if(reportLinesPrecedent.line[j].segment[k].position.y == 0)
								reportLinesPrecedent.line[j].segment[k].position.y = reportLines.line[j].segment[k].position.y;
							reportLines.line[j].segment[k].Velocity.linear.y =(  reportLines.line[j].segment[k].position.y \
													   - reportLinesPrecedent.line[j].segment[k].position.y) \
													   / dt;
							if(abs(reportLines.line[j].segment[k].Velocity.linear.y) > 4)
								reportLines.line[j].segment[k].Velocity.linear.y = reportLinesPrecedent.line[j].segment[k].Velocity.linear.y;

							reportLines.line[j].segment[k].Velocity.linear.z = 0;
						}
					}
				}
			}

			pub_route_lines.publish(reportLines);

//*******************
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

			pub_obstacles.publish(reportObstacles);
		}

		loop_rate.sleep();		
	}

	return 0;
}
