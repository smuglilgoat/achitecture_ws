#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <ctime>
#include <time.h> 
#include <sys/timeb.h>
#include <sys/time.h>  
#include <ros/callback_queue.h>
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
#include "project_s_msgs/EgoDataReport.h"
#include "project_s_msgs/ObstacleReport.h"

project_s_msgs::ObstacleReport extractedObstacles;
project_s_msgs::ObstacleReport ObstacleRelative, ObstacleRelativePrecedent;
project_s_msgs::ObstacleReport reportObstacles;
std_msgs::UInt8 QtyObstacles;

nav_msgs::Odometry odom;

project_s_msgs::EgoDataReport bufferEgoData;

// Server parameters
double range = 0.0, fov = 0.0;	// ATTENTION fov pas utilisé par la suite
geometry_msgs::Point offset;

bool receivedEgoData = false;
void egoDataCallback(const project_s_msgs::EgoDataReport::ConstPtr& EgoDataReport)
{
	bufferEgoData = *EgoDataReport;

	receivedEgoData = true;
}

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

bool inView(project_s_msgs::GenericSmartData objectInView)
{
	double c1 = objectInView.obstaclePosition.position.x;
	double c2 = std::abs(objectInView.obstaclePosition.position.y);
	double i = std::sqrt(pow(c1,2)+pow(c2,2));
	
	if (((c2 == 0.0) && (c1 <= 0.0)) || ((c1 <= 0.0) && (c1/c2 < -tan(M_PI/4))))
		return false;
	else if (i < range)
		return true;
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

// Compute relative position
void computeRelativePosition_(geometry_msgs::Point ptRef, double velRef, double w, double theta, geometry_msgs::Point off_,
geometry_msgs::Point ptFixe, geometry_msgs::Twist velFixe, geometry_msgs::Point *ptMobile, geometry_msgs::Twist *velMobile)
{	// calculs de la position dans le repère de l'ego,
	// à partir de la position dans le repère absolu.
	geometry_msgs::Point p;
	geometry_msgs::Twist velocity;

	double c = cos(theta);
	double s = sin(theta);

	p.x =  (ptFixe.x - ptRef.x) * c + (ptFixe.y - ptRef.y) * s;
	p.y = -(ptFixe.x - ptRef.x) * s + (ptFixe.y - ptRef.y) * c;
	p.z =  0;

p.x -= off_.x;
p.y -= off_.y;
p.z -= off_.z;

	*ptMobile = p;

	velocity.linear.x = - velRef + velFixe.linear.x * c + velFixe.linear.y * s - w * ((ptFixe.x - ptRef.x) * s - (ptFixe.y - ptRef.y) * c);
	velocity.linear.y =          - velFixe.linear.x * s + velFixe.linear.y * c - w * ((ptFixe.x - ptRef.x) * c + (ptFixe.y - ptRef.y) * s);
	velocity.linear.z = 0;
	*velMobile = velocity; 
}


void computeRelativeVitesse(geometry_msgs::Point ptRef, double velRef, double w, double theta,
geometry_msgs::Point ptFixe, geometry_msgs::Twist velFixe, geometry_msgs::Twist *velMobile)
{
	geometry_msgs::Twist velocity;

	double c = cos(theta);
	double s = sin(theta);

	velocity.linear.x = - velRef + velFixe.linear.x * c + velFixe.linear.y * s - w * ((ptFixe.x - ptRef.x) * s - (ptFixe.y - ptRef.y) * c);
	velocity.linear.y =          - velFixe.linear.x * s + velFixe.linear.y * c - w * ((ptFixe.x - ptRef.x) * c + (ptFixe.y - ptRef.y) * s);
	velocity.linear.z = 0;
	*velMobile = velocity; 
}

void computeGlobalPosition(geometry_msgs::Point ptRef, double velRef, double w, double theta,
geometry_msgs::Point ptMobile, geometry_msgs::Twist velMobile, geometry_msgs::Point *ptFixe, geometry_msgs::Twist *velFixe)
{	// calculs de la position dans le repère absolu,
	// à partir de la position dans le repère de l'égo.
	geometry_msgs::Point p;
	geometry_msgs::Twist velocity;

	double c = cos(theta);
	double s = sin(theta);

	p.x = ptMobile.x * c - ptMobile.y * s + ptRef.x;
	p.y = ptMobile.x * s + ptMobile.y * c + ptRef.y;
	p.z = 0;
	*ptFixe = p;

	velocity.linear.x = velRef * c + (velMobile.linear.x * c - velMobile.linear.y * s) - w * (ptMobile.x * s + ptMobile.y * c);
	velocity.linear.y = velRef * s + (velMobile.linear.x * s + velMobile.linear.y * c) + w * (ptMobile.x * c - ptMobile.y * s);
	velocity.linear.z = 0;
	*velFixe = velocity; 
}

int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("lidar_model"));

	ros::NodeHandle n;

	// Raport publisher with relative positions for the objects
	ros::Publisher pubRaport = n.advertise<project_s_msgs::ObstacleReport>(std::string("/lidar_obstacle"), 1);

	// Subscriber global reference obstacle data  
	ros::Subscriber subData = n.subscribe(std::string("/obstacles"), 1, obstacleDataCallback);

	// Subscriber odometry
	ros::Subscriber subOdom = n.subscribe(std::string("/odom"), 1, odomCallback);
ros::Subscriber subEgoData  = n.subscribe(std::string("/ego_data"), 1, egoDataCallback);

	ros::Rate loop_rate(35);

	if (n.hasParam("/lidar/offset_x"))
		n.getParam("/lidar/offset_x", offset.x);
	if (n.hasParam("/lidar/offset_y"))
		n.getParam("/lidar/offset_y", offset.y);
	if (n.hasParam("/lidar/offset_z"))
		n.getParam("/lidar/offset_z", offset.z);
	if (n.hasParam("/lidar/range"))
		n.getParam("/lidar/range", range);
	if (n.hasParam("/lidar/fov"))
		n.getParam("/lidar/fov", fov);

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

// recherche EgoData entre t1 et t2
project_s_msgs::EgoData egoVehicleData;

double tempsREF = ((ObstacleRelative.header.stamp).toSec() + (ObstacleRelativePrecedent.header.stamp).toSec()) / 2.0;
int iMIN = 0;
double dtMIN = fabs((bufferEgoData.EgoData[iMIN].stamp).toSec() - tempsREF);
egoVehicleData = bufferEgoData.EgoData[iMIN];

for(int i = 0; i < project_s_msgs::EgoDataReport::NBR_MAX_EGO_DATA; i++){
	double dt = fabs((bufferEgoData.EgoData[i].stamp).toSec() - tempsREF);
	if(dt < dtMIN){
		dtMIN = dt;
		iMIN = i;
		egoVehicleData = bufferEgoData.EgoData[i];
	}
}

double w;
//w = egoVehicleData.velocity.angular.z;
w = odom.twist.twist.angular.z;
float dth_odom;
dth_odom = tf::getYaw(odom.pose.pose.orientation);

			for (int i = 0; i < extractedObstacles.QtySmartData.data; i++)
			{
				ObstacleRelative.GenericSmartData[i] = extractedObstacles.GenericSmartData[i];

				// calculs de la position dans le repère du lidar sensor
				ObstacleRelative.GenericSmartData[i].obstaclePosition.position = computeRelativePosition(ObstacleRelative.GenericSmartData[i].obstaclePosition.position,
															 offset, ObstacleRelative.odom);

				// calculs de la vitesse dans le repère du lidar sensor
				ObstacleRelative.GenericSmartData[i].obstacleVelocity = computeRelativeVelocity(ObstacleRelative.GenericSmartData[i].obstaclePosition.position, 
								    						ObstacleRelativePrecedent.GenericSmartData[i].obstaclePosition.position, dt);

/*
// extractedObstacles.GenericSmartData[i].obstacleVelocity à màj dans generation_smart_data.cpp
computeRelativeVitesse(ObstacleRelative.odom.pose.pose.position, 5, w, dth_odom,
extractedObstacles.GenericSmartData[i].obstaclePosition.position, extractedObstacles.GenericSmartData[i].obstacleVelocity, 
&ObstacleRelative.GenericSmartData[i].obstacleVelocity);
*/
/*
computeRelativePosition_(ObstacleRelative.odom.pose.pose.position, 5, w, dth_odom, offset,
extractedObstacles.GenericSmartData[i].obstaclePosition.position, extractedObstacles.GenericSmartData[i].obstacleVelocity, 
&ObstacleRelative.GenericSmartData[i].obstaclePosition.position,  &ObstacleRelative.GenericSmartData[i].obstacleVelocity);
*/
/*
if(i==0){
ROS_ERROR("obstaclePosition.x : %f", ObstacleRelative.GenericSmartData[i].obstaclePosition.position.x);
ROS_ERROR("obstaclePosition.y : %f", ObstacleRelative.GenericSmartData[i].obstaclePosition.position.y);
ROS_ERROR("obstacleVelocity.x : %f", ObstacleRelative.GenericSmartData[i].obstacleVelocity.linear.x);
ROS_ERROR("obstacleVelocity.y : %f", ObstacleRelative.GenericSmartData[i].obstacleVelocity.linear.y);
}
*/
/*
// test pour vérifier f-1°f = Id
geometry_msgs::Point ptFixe_zero = geometry_msgs::Point();
geometry_msgs::Point ptFixe;
geometry_msgs::Twist velFixe;
computeGlobalPosition(ObstacleRelative.odom.pose.pose.position, 5, w, dth_odom,
ObstacleRelative.GenericSmartData[i].obstaclePosition.position, ObstacleRelative.GenericSmartData[i].obstacleVelocity, 
&ptFixe, &velFixe);

if(i==0){
ROS_ERROR("obstaclePositionAbsolu.x : %f", ptFixe.x);
ROS_ERROR("obstaclePositionAbsolu.y : %f", ptFixe.y);
ROS_ERROR("obstacleVelocityAbsolu.x : %f", velFixe.linear.x);
ROS_ERROR("obstacleVelocityAbsolu.y : %f", velFixe.linear.y);
}
*/			}

//ROS_ERROR("obstacleVelocity.x : %f" ,ObstacleRelative.GenericSmartData[0].obstacleVelocity.linear.x);
//ROS_ERROR("obstacleVelocity.y : %f" ,ObstacleRelative.GenericSmartData[0].obstacleVelocity.linear.y);
//ROS_ERROR("obstacleVelocity   : %f" ,std::sqrt(std::pow(ObstacleRelative.GenericSmartData[0].obstacleVelocity.linear.x,2) + std::pow(ObstacleRelative.GenericSmartData[0].obstacleVelocity.linear.y,2)));

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
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePoseVariance.position.x = 1;	// par défaut
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePoseVariance.position.y = 1;	// par défaut
						reportObstacles.GenericSmartData[QtyObstacles.data].obstaclePoseVariance.position.z = 1;	// par défaut
					}

					// màj de la vitesse
					reportObstacles.GenericSmartData[QtyObstacles.data].obstacleVelocity = ObstacleRelative.GenericSmartData[i].obstacleVelocity;

					// màj de l'incertitude de mesure de la vitesse
					reportObstacles.GenericSmartData[QtyObstacles.data].obstacleVelocityVariance.linear.x = 1;	// par défaut
					reportObstacles.GenericSmartData[QtyObstacles.data].obstacleVelocityVariance.linear.y = 1;	// par défaut
					reportObstacles.GenericSmartData[QtyObstacles.data].obstacleVelocityVariance.linear.z = 1;	// par défaut

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
