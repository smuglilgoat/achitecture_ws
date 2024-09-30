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

#include "project_s_msgs/LaneAlignment.h"
#include "project_s_msgs/LaneFusion.h"
#include "project_s_msgs/LaneSynchronizedReport.h"
#include "project_s_msgs/EgoDataReport.h"

#define REAR_MAX_RANGE	-5.0	// valeur négative pour étendre le range vers l'arrière (par rapport au referentiel ego)
#define FRONT_MAX_RANGE	15.0

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::LaneAlignment lines_filtering;
project_s_msgs::LaneFusion    lines_update;
project_s_msgs::EgoDataReport EgoData;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::LaneSynchronizedReport lines_synchronization;

//-------------------------------------------------------------------------------------------------
// local functions
//-------------------------------------------------------------------------------------------------
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

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool linesfilteringReceived = false;
void linesFilteringDataCallback(const project_s_msgs::LaneAlignment::ConstPtr& buffer)
{
	lines_filtering = *buffer;

	linesfilteringReceived = true;
}

bool linesUpdateReceived = false;
void linesUpdateDataCallback(const project_s_msgs::LaneFusion::ConstPtr& buffer)
{
	lines_update = *buffer;

	linesUpdateReceived = true;
}

bool receivedEgoData = false;
void egoDataCallback(const project_s_msgs::EgoDataReport::ConstPtr& buffer)
{
	EgoData = *buffer;

	receivedEgoData = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "lines_synchronization");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher pub_lines_synchronization = n.advertise<project_s_msgs::LaneSynchronizedReport>(std::string("/lines_synchronization_data"), 1);

	// Subscriber
	ros::Subscriber sub_lines_filtering = n.subscribe(std::string("/lines_filtering_data"), 1, linesFilteringDataCallback);
	ros::Subscriber sub_lines_update    = n.subscribe(std::string("/lines_update_data"),    1, linesUpdateDataCallback);
	ros::Subscriber subEgoData          = n.subscribe(std::string("/ego_data"),             1, egoDataCallback);

	ros::Rate loop_rate(1000);

  	while(n.ok())
	{
		ros::spinOnce();

		if(linesfilteringReceived){
			linesfilteringReceived = false;

			// recherche EgoData entre t1 et t2
			project_s_msgs::EgoData egoVehicleData;

			double tempsREF = ((lines_filtering.header.stamp).toSec() + (lines_update.header.stamp).toSec()) / 2.0;

			int iMIN = 0;
			double dtMIN = fabs((EgoData.EgoData[iMIN].stamp).toSec() - tempsREF);
			egoVehicleData = EgoData.EgoData[iMIN];

			for(int i = 0; i < project_s_msgs::EgoDataReport::NBR_MAX_EGO_DATA; i++){
				double dt = fabs((EgoData.EgoData[i].stamp).toSec() - tempsREF);
				if(dt < dtMIN){
					dtMIN = dt;
					iMIN = i;
					egoVehicleData = EgoData.EgoData[i];
				}
			}

			// prédiction CYRA
			double dt = (lines_filtering.header.stamp - lines_update.header.stamp).toSec();	// synchronisation par rapport au report camera
			double velRef = std::sqrt(std::pow(egoVehicleData.velocity.linear.x,2) + std::pow(egoVehicleData.velocity.linear.y,2));
			double w = egoVehicleData.velocity.angular.z;
			double a = egoVehicleData.acceleration.linear.x;
			double dx, dy, dth;
			CYRAMotionSimplified(velRef, a, w, dt, &dx, &dy, &dth);

			for(int j = 0; j < lines_update.QtyLine.data; j++){
				// synchronisation de lines_update
				for(int i = 0; i < lines_update.line[j].QtySegment.data; i++){
					geometry_msgs::Point ptFixe; ptFixe = lines_update.line[j].segment[i].position;
					geometry_msgs::Twist velFixe_zero = geometry_msgs::Twist();
					geometry_msgs::Point ptRef; ptRef.x = dx; ptRef.y = dy;

					geometry_msgs::Point ptMobile;
					geometry_msgs::Twist velMobile;

					// Changement de repère Fixe --> Mobile
					computeRelativePosition(ptRef, velRef, w, dth, ptFixe, velFixe_zero, &ptMobile, &velMobile);

					lines_update.line[j].segment[i].position = ptMobile;
				}

				// tracked line reduction
				uint i = 0;
				uint QtySegment = lines_update.line[j].QtySegment.data;
				while(i < QtySegment){
					double distance = std::sqrt(std::pow(lines_update.line[j].segment[i].position.x,2) + std::pow(lines_update.line[j].segment[i].position.y,2));
					if(lines_update.line[j].segment[i].position.x < 0)
						distance = -distance;
					if(   (distance < REAR_MAX_RANGE)
					   || (distance > FRONT_MAX_RANGE))
					{
						QtySegment--;
						for(uint m = i; m < QtySegment; m++)
							lines_update.line[j].segment[m] = lines_update.line[j].segment[m+1];
						i--;
					}
					i++;
				}

				lines_update.line[j].QtySegment.data = QtySegment;
			}

			for(int j = 0; j < lines_filtering.QtyLine.data; j++){
				// lines_filtering reduction
				uint i = 0;
				uint QtySegment = lines_filtering.line[j].QtySegment.data;
				while(i < QtySegment){
					double distance = std::sqrt(std::pow(lines_filtering.line[j].segment[i].position.x,2) + std::pow(lines_filtering.line[j].segment[i].position.y,2));
					if(lines_filtering.line[j].segment[i].position.x < 0)
						distance = -distance;
					if(   (distance < REAR_MAX_RANGE)
					   || (distance > FRONT_MAX_RANGE))
					{
						QtySegment--;
						for(uint m = i; m < QtySegment; m++)
							lines_filtering.line[j].segment[m] = lines_filtering.line[j].segment[m+1];
						i--;
					}
					i++;
				}

				lines_filtering.line[j].QtySegment.data = QtySegment;
			}

			// màj & publish
			lines_synchronization.header         = lines_filtering.header;
			lines_synchronization.laneAlignement = lines_filtering;
			lines_synchronization.laneFusion     = lines_update;

			pub_lines_synchronization.publish(lines_synchronization);
		}

		loop_rate.sleep();
	}

	return 0;
}
