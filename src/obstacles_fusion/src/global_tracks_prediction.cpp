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

#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include "project_s_msgs/EgoDataReport.h"
#include "project_s_msgs/ObstacleSynchronizeReport.h"
#include "project_s_msgs/ObstacleFusionReport.h"

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::EgoDataReport bufferEgoData;
project_s_msgs::ObstacleSynchronizeReport extractedObstacleSynchronize;
project_s_msgs::ObstacleFusionReport reportObstacleFusion;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport predictionPisteGlobale;

//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// local CallBack
//-------------------------------------------------------------------------------------------------
bool receivedEgoData = false;
void egoDataCallback(const project_s_msgs::EgoDataReport::ConstPtr& EgoDataReport)
{
	bufferEgoData = *EgoDataReport;

	receivedEgoData = true;
}

bool receivedLocalTracksSynchro = false;
void localTracksSynchroCallback(const project_s_msgs::ObstacleSynchronizeReport::ConstPtr& ObstacleArray)
{
	extractedObstacleSynchronize = *ObstacleArray;

	receivedLocalTracksSynchro = true;
}

bool receivedGlobalTracksConfidence = false;
void globalTracksConfidenceCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& genericObstacleFusion)
{
	reportObstacleFusion = *genericObstacleFusion;

	receivedGlobalTracksConfidence = true;
}

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
// synchronisation temporelle
geometry_msgs::Pose obstacleSynchronisation(geometry_msgs::Point pt, geometry_msgs::Twist twist, double dt)
{
	geometry_msgs::Pose p;
	p.position.x = pt.x + twist.linear.x*dt;
	p.position.y = pt.y + twist.linear.y*dt;
	p.position.z = pt.z + twist.linear.z*dt;

	return p;
}

// Compute global position
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

void computeGlobalPositionSimplified(double velRef, double w,
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
void computeRelativePosition(geometry_msgs::Point ptRef, double velRef, double w, double theta,
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
	*ptMobile = p;

	velocity.linear.x = - velRef + velFixe.linear.x * c + velFixe.linear.y * s - w * ((ptFixe.x - ptRef.x) * s - (ptFixe.y - ptRef.y) * c);
	velocity.linear.y =          - velFixe.linear.x * s + velFixe.linear.y * c - w * ((ptFixe.x - ptRef.x) * c + (ptFixe.y - ptRef.y) * s);
	velocity.linear.z = 0;
	*velMobile = velocity; 
}

// modèle CYRA = Constant Yaw Rate and Acceleration
void CYRAMotion(double th, double v, double a, double w, double dt, double *dx, double *dy, double *dth, double *dv)
{
	double s, c, vsw, ds, dc, dvsw, asw2, cx, cy, dth_;

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

void CYRAMotionSimplified(double v, double a, double w, double dt, double *dx, double *dy, double *dth)
{	// version simplifiée avec th = 0
	double vsw, ds, dc, dvsw, asw2, dth_;

	if((dth_ = w*dt) == 0){
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
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("global_tracks_prediction"));

	ros::NodeHandle n;

	ros::Publisher pub_global_tracks_prediction = n.advertise<project_s_msgs::ObstacleFusionReport>(std::string("/global_tracks_prediction_data"), 1);

	ros::Subscriber subEgoData  = n.subscribe(std::string("/ego_data"), 1, egoDataCallback);
	ros::Subscriber sub_local_tracks_synchro = n.subscribe(std::string("/local_tracks_synchro_data"), 1, localTracksSynchroCallback);
	ros::Subscriber sub_global_tracks_confidence = n.subscribe(std::string("/global_tracks_confidence_data"), 1, globalTracksConfidenceCallback);

	ros::Rate loop_rate(100);

	while(n.ok())
	{
		ros::spinOnce();

		if (receivedEgoData)
		{
			receivedEgoData = false;
		}

		if (receivedGlobalTracksConfidence)
		{
			receivedGlobalTracksConfidence = false;
		}

		if (receivedLocalTracksSynchro)
		{
			receivedLocalTracksSynchro = false;

//-------------------------------------------------------------------------------------------------
// 			prediction d'état des pistes globales
//-------------------------------------------------------------------------------------------------
			predictionPisteGlobale              = reportObstacleFusion;
			predictionPisteGlobale.header.stamp = extractedObstacleSynchronize.header.stamp;	// màj du TimeStamp par rapport à la synchro locale
			predictionPisteGlobale.odom         = extractedObstacleSynchronize.odom;

			// recherche EgoData entre t1 et t2
			project_s_msgs::EgoData egoVehicleData;

			double tempsREF = ((predictionPisteGlobale.header.stamp).toSec() + (reportObstacleFusion.header.stamp).toSec()) / 2.0;
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

			// prédiction de GlobalTracksConfidence
			double dt = (predictionPisteGlobale.header.stamp - reportObstacleFusion.header.stamp).toSec();	// synchronisation  par rapport à la synchro locale

			// Prédiction déplacement ego-véhicule t1 --> t2
			double velRef = std::sqrt(std::pow(egoVehicleData.velocity.linear.x,2) + std::pow(egoVehicleData.velocity.linear.y,2));
			double w = egoVehicleData.velocity.angular.z;
			double a = egoVehicleData.acceleration.linear.x;

			double dx, dy, dth;
			CYRAMotionSimplified(velRef, a, w, dt, &dx, &dy, &dth);

			for(int i = 0; i < predictionPisteGlobale.QtyObstacles.data; i++){
				// Changement de repère Mobile --> Fixe
				geometry_msgs::Point ptFixe;
				geometry_msgs::Twist velFixe;

				computeGlobalPositionSimplified(velRef, w, 
				predictionPisteGlobale.ObstacleFusion[i].obstaclePosition.position, predictionPisteGlobale.ObstacleFusion[i].obstacleVelocity, &ptFixe, &velFixe);

				// Prédiction déplacement Objet t1 --> t2 dans Ref fixe, à vitesse absolu constante
				geometry_msgs::Pose poseFixe;
				poseFixe = obstacleSynchronisation(ptFixe, velFixe, dt);
				ptFixe = poseFixe.position;

				// Changement de repère Fixe --> Mobile
				geometry_msgs::Point ptRef; ptRef.x = dx; ptRef.y = dy;
				geometry_msgs::Point ptMobile;
				geometry_msgs::Twist velMobile;

				computeRelativePosition(ptRef, velRef, w, dth, ptFixe, velFixe, &ptMobile, &velMobile);

				predictionPisteGlobale.ObstacleFusion[i].obstaclePosition.position = ptMobile;
				predictionPisteGlobale.ObstacleFusion[i].obstacleVelocity          = velMobile;
			}

//-------------------------------------------------------------------------------------------------
//			publication
//-------------------------------------------------------------------------------------------------

			pub_global_tracks_prediction.publish(predictionPisteGlobale);
		}

		loop_rate.sleep();		
	}

	return 0;
}
