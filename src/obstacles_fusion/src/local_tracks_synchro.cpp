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

#include "ros/ros.h"
#include <nav_msgs/Odometry.h>

#include "project_s_msgs/EgoDataReport.h"
#include "project_s_msgs/ObstacleSynchronizeReport.h"
#include "project_s_msgs/ObstacleAlignmentReport.h"
#include "project_s_msgs/Time.h"

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::EgoDataReport bufferEgoData = project_s_msgs::EgoDataReport();

project_s_msgs::ObstacleAlignmentReport bufferCameraMe = project_s_msgs::ObstacleAlignmentReport();
project_s_msgs::ObstacleAlignmentReport bufferRadarESR = project_s_msgs::ObstacleAlignmentReport();
project_s_msgs::ObstacleAlignmentReport bufferLidar    = project_s_msgs::ObstacleAlignmentReport();
project_s_msgs::Time DeltaTime;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
// à compléter si d'autres capteurs
#define NBR_SENSOR		3 
#define ID_LIDAR		0
#define ID_RADAR		1
#define ID_CAMERA_ME		2

project_s_msgs::ObstacleSynchronizeReport ptrSensor;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedEgoData = false;
void egoDataCallback(const project_s_msgs::EgoDataReport::ConstPtr& EgoDataReport)
{
	bufferEgoData = *EgoDataReport;

	receivedEgoData = true;
}

// Callback functions for receiving smart data
bool receivedCameraMe = false;
void cameraMeCallback(const project_s_msgs::ObstacleAlignmentReport::ConstPtr& ObstacleArray)
{
	bufferCameraMe = *ObstacleArray;

	receivedCameraMe = true;
}

bool receivedRadarESR = false;
void radarESRCallback(const project_s_msgs::ObstacleAlignmentReport::ConstPtr& ObstacleArray)
{
	bufferRadarESR = *ObstacleArray;

	receivedRadarESR = true;
}

bool receivedLidar = false;
void lidarCallback(const project_s_msgs::ObstacleAlignmentReport::ConstPtr& ObstacleArray)
{
	bufferLidar = *ObstacleArray;

	receivedLidar = true;
}

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
// synchronisation temporelle
geometry_msgs::Pose obstacleSynchronisation(geometry_msgs::Pose pose, geometry_msgs::Twist twist, float dt)
{
	geometry_msgs::Pose p;
	p.position.x = pose.position.x + twist.linear.x*dt;
	p.position.y = pose.position.y + twist.linear.y*dt;
	p.position.z = pose.position.z + twist.linear.z*dt;

	return p;
}

// Compute global position
void computeGlobalPosition(geometry_msgs::Point ptRef, float velRef, float w, float theta,
geometry_msgs::Point ptMobile, geometry_msgs::Twist velMobile, geometry_msgs::Point *ptFixe, geometry_msgs::Twist *velFixe)
{	// calculs de la position dans le repère absolu,
	// à partir de la position dans le repère de l'égo.
	geometry_msgs::Point p;
	geometry_msgs::Twist velocity;

	float c = cos(theta);
	float s = sin(theta);

	p.x = ptMobile.x * c - ptMobile.y * s + ptRef.x;
	p.y = ptMobile.x * s + ptMobile.y * c + ptRef.y;
	p.z = 0;
	*ptFixe = p;

	velocity.linear.x = velRef * c + (velMobile.linear.x * c - velMobile.linear.y * s) - w * (ptMobile.x * s + ptMobile.y * c);
	velocity.linear.y = velRef * s + (velMobile.linear.x * s + velMobile.linear.y * c) + w * (ptMobile.x * c - ptMobile.y * s);
	velocity.linear.z = 0;
	*velFixe = velocity; 
}

void computeGlobalPositionSimplified(float velRef, float w,
geometry_msgs::Point ptMobile, geometry_msgs::Twist velMobile, geometry_msgs::Point *ptFixe, geometry_msgs::Twist *velFixe)
{	// version simplifiée avec ptRef = (0, 0) et theta = 0
	geometry_msgs::Point p;
	geometry_msgs::Twist velocity;

	p.x = ptMobile.x;
	p.y = ptMobile.y;
	p.z = 0;
	*ptFixe = p;

	velocity.linear.x = velRef + velMobile.linear.x - w * ptMobile.y;
	velocity.linear.y =          velMobile.linear.y + w * ptMobile.x;
	velocity.linear.z = 0;
	*velFixe = velocity; 
}

// Compute relative position
void computeRelativePosition(geometry_msgs::Point ptRef, float velRef, float w, float theta,
geometry_msgs::Point ptFixe, geometry_msgs::Twist velFixe, geometry_msgs::Point *ptMobile, geometry_msgs::Twist *velMobile)
{	// calculs de la position dans le repère de l'ego,
	// à partir de la position dans le repère absolu.
	geometry_msgs::Point p;
	geometry_msgs::Twist velocity;

	float c = cos(theta);
	float s = sin(theta);

	p.x =  (ptFixe.x - ptRef.x) * c + (ptFixe.y - ptRef.y) * s;
	p.y = -(ptFixe.x - ptRef.x) * s + (ptFixe.y - ptRef.y) * c;
	p.z =  0;
	*ptMobile = p;

	velocity.linear.x = - velRef + velFixe.linear.x * c + velFixe.linear.y * s - w * ((ptFixe.x - ptRef.x) * s - (ptFixe.y - ptRef.y) * c);
	velocity.linear.y =          - velFixe.linear.x * s + velFixe.linear.y * c - w * ((ptFixe.x - ptRef.x) * c + (ptFixe.y - ptRef.y) * s);
	velocity.linear.z = 0;
	*velMobile = velocity; 
}


// modèle CYRA = Constant Yaw Rate and Acceleration
void CYRAMotion(float th, float v, float a, float w, float dt, float *dx, float *dy, float *dth, float *dv)
{
	float s, c, vsw, ds, dc, dvsw, asw2, cx, cy, dth_;

	if((dth_ = w*dt) == 0){
		s = sin(th);
		c = cos(th);

		*dx = (v*dt + 0.5*a*dt*dt)*c;
		*dy = (v*dt + 0.5*a*dt*dt)*s;
		*dth = 0;
		*dv = a*dt;
	}
	else{
		s = sin(th);
		c = cos(th);
		ds = sin(th + dth_);
		dc = cos(th + dth_);
		asw2 = a/(w*w);
		vsw = v/w;
		dvsw = (v + a*dt)/w;

		cx = vsw * s - asw2 * c;
		cy = vsw * c - asw2 * s;

		*dx = asw2*dc + dvsw*ds + cx;
		*dy = asw2*ds - dvsw*dc + cy;
		*dth = dth_;
		*dv = a*dt;
	}
}


void CYRAMotionSimplified(float v, float a, float w, float dt, float *dx, float *dy, float *dth)
{	// version simplifiée avec th = 0
	float vsw, ds, dc, dvsw, asw2, dth_;
	bool dtNeg = false;

if(dt<0.0)
{
dtNeg = true;
dt = -dt;
}

dth_ = w*dt;
	if(dth_ == 0){
		*dx = (v*dt + 0.5*a*dt*dt);
		*dy = 0;
		*dth = 0;
		//*dv = a*dt;
	}
	else{
		ds = sin(dth_);
		dc = cos(dth_);
		asw2 = a/(w*w);
		vsw = v/w;
		dvsw = (v + a*dt)/w;

		*dx = asw2*dc + dvsw*ds - asw2;
		*dy = asw2*ds - dvsw*dc + vsw;
		*dth = dth_;
		//*dv = a*dt;
	}

if(dtNeg){
float ddx, ddy;
ddx = -(*dx*cos(dth_) + *dy*sin(dth_));
ddy = +(*dx*sin(dth_) - *dy*cos(dth_));
*dx  = ddx;
*dy  = ddy;
*dth = -*dth;
}
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	ros::init(argc, argv, std::string("local_track_synchro"));

	ros::NodeHandle n;

	ros::Publisher pub_local_tracks_synchro = n.advertise<project_s_msgs::ObstacleSynchronizeReport>(std::string("/local_tracks_synchro_data"), 1);
	ros::Publisher pub_time_synchro = n.advertise<project_s_msgs::Time>(std::string("/time_synchro_data"), 1);

	ros::Subscriber subEgoData  = n.subscribe(std::string("/ego_data"), 1, egoDataCallback);
	ros::Subscriber subMe       = n.subscribe(std::string("/camera_me_obstacles_filtering_data"), 1, cameraMeCallback);
	ros::Subscriber subLidar    = n.subscribe(std::string("/lidar_obstacles_filtering_data"), 1, lidarCallback);
	ros::Subscriber subRadarESR = n.subscribe(std::string("/radar_ESR_obstacles_filtering_data"), 1,radarESRCallback);

	ros::Rate loop_rate(100);	

	while(n.ok())
	{

		ros::spinOnce();

		if (receivedEgoData)
		{
			receivedEgoData = false;
			std::cout<<"-------------------------------------------------EGO DATA ----"<<std::endl;
		}

		if (receivedCameraMe)
		{
			receivedCameraMe = false;
			ptrSensor.ObstacleSynchronizeReport[ID_CAMERA_ME] = bufferCameraMe;
			std::cout<<"---Meye ---- "<<std::endl;
		}

		if (receivedRadarESR)
		{
			receivedRadarESR = false;
			ptrSensor.ObstacleSynchronizeReport[ID_RADAR] = bufferRadarESR;
			std::cout<<"------------Esr ---- "<<std::endl;
		}

		if (receivedLidar)
		{
			receivedLidar = false;
			ptrSensor.ObstacleSynchronizeReport[ID_LIDAR] = bufferLidar;
			std::cout<<"---------------------Ibeo ---- "<<std::endl;
		
			//on prend le lidar comme référence de la fusion
			ptrSensor.header = bufferLidar.header;
			ptrSensor.id     = bufferLidar.id;
			ptrSensor.odom   = bufferLidar.odom;

//-------------------------------------------------------------------------------------------------
// 			synchronisation temporelle
//-------------------------------------------------------------------------------------------------

			ros::Time     currentTime = ptrSensor.header.stamp;  // on prend le capteur xxx comme référence de la synchro temporelle
			nav_msgs::Odometry currentOdom = ptrSensor.odom;
			geometry_msgs::Pose egoRelativePose;

			// modèle CYRA
			project_s_msgs::EgoData egoVehicleData;			
	
			for(int k = 0; k < NBR_SENSOR; k++)
			{
				double dt = (currentTime - ptrSensor.ObstacleSynchronizeReport[k].header.stamp).toSec();

				//std::cout<<"---- DT ---- "<<dt<<std::endl;

				// recherche EgoData entre t1 et t2
				double tempsREF = ((currentTime).toSec() + (ptrSensor.ObstacleSynchronizeReport[k].header.stamp).toSec()) / 2.0;
				int iMIN = 0;
				double dtMIN = fabs((bufferEgoData.EgoData[iMIN].stamp).toSec() - tempsREF);
				egoVehicleData = bufferEgoData.EgoData[iMIN];
				//std::cout<<"----tempsREF ---- "<<tempsREF<<std::endl;
				//std::cout<<"----dtMIN ---- "<<dtMIN<<std::endl;
			
				for(int i = 0; i < project_s_msgs::EgoDataReport::NBR_MAX_EGO_DATA; i++)
				{
					double dt_ = fabs((bufferEgoData.EgoData[i].stamp).toSec() - tempsREF);
					//std::cout<<"----dt_ ---- "<<dt_<<std::endl;
					if(dt_ < dtMIN)
					{
						dtMIN = dt_;
						iMIN = i;
						egoVehicleData = bufferEgoData.EgoData[i];
					}
				}

				DeltaTime.Tn.data   = (currentTime).toSec();
				DeltaTime.Tn_1.data = (ptrSensor.ObstacleSynchronizeReport[k].header.stamp).toSec();
				DeltaTime.Ti.data   = (bufferEgoData.EgoData[iMIN].stamp).toSec();
				DeltaTime.iMIN.data = iMIN;

				//std::cout<<"----iMIN ---- "<<iMIN<<std::endl;

				ptrSensor.ObstacleSynchronizeReport[k].header.stamp = currentTime; // màj du timestamp des pistes locales synchronisées
				ptrSensor.ObstacleSynchronizeReport[k].odom         = currentOdom;

				//std::cout<<"----currentTime ---- "<<currentTime<<std::endl;

				for(int i = 0; i < ptrSensor.ObstacleSynchronizeReport[k].QtyObstacles.data; i++)
				{
					float velRef = std::sqrt(std::pow(egoVehicleData.velocity.linear.x,2) + std::pow(egoVehicleData.velocity.linear.y,2));
					float w = egoVehicleData.velocity.angular.z;

					//std::cout<<"----velRef : "<<velRef<<std::endl;	

					geometry_msgs::Point ptFixe;
					geometry_msgs::Pose poseFixe;
					geometry_msgs::Twist velFixe;

					// Changement de repère Mobile --> Fixe
					computeGlobalPositionSimplified(velRef, w,
					ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstaclePosition.position,
					ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstacleVelocity, &ptFixe, &velFixe);

					// Prédiction déplacement Objet t1 --> t2
					poseFixe.position = ptFixe;
					poseFixe = obstacleSynchronisation(poseFixe, velFixe, dt);
					ptFixe = poseFixe.position;
					
					float a = egoVehicleData.acceleration.linear.x;
					float dx, dy, dth;
					CYRAMotionSimplified(velRef, a, w, dt, &dx, &dy, &dth);

					//std::cout<<"----dx ---- "<<dx<<std::endl;

					// Changement de repère Fixe --> Mobile
					geometry_msgs::Point ptRef; ptRef.x = dx; ptRef.y = dy;
					geometry_msgs::Point ptMobile;
					geometry_msgs::Twist velMobile;
					computeRelativePosition(ptRef, velRef, w, dth, ptFixe, velFixe, &ptMobile, &velMobile);

					ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstaclePosition.position = ptMobile;
					ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstacleVelocity          = velMobile;

					//std::cout<<"----velMobile ---- "<<velMobile<<std::endl;
					//std::cout<<"----ptMobile ---- "<<ptMobile<<std::endl;

//if(ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstaclePoseVariance.position.x == -1)
//	ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstaclePoseVariance.position.x = 1;
//else
// 	on garde la valeur
//if(ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstaclePoseVariance.position.y == -1)
//	ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstaclePoseVariance.position.y = 1;

//if(ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstacleVelocityVariance.linear.x == -1)
//	ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstacleVelocityVariance.linear.x = 1;
//if(ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstacleVelocityVariance.linear.y == -1)
//	ptrSensor.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstacleVelocityVariance.linear.y = 1;
				}
			
			}

//-------------------------------------------------------------------------------------------------
//			publication
//-------------------------------------------------------------------------------------------------
			pub_local_tracks_synchro.publish(ptrSensor);
//			pub_time_synchro.publish(DeltaTime);
		}

		loop_rate.sleep();		
	}

	return 0;
}








