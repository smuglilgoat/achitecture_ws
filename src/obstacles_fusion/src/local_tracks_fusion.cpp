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

#include "project_s_msgs/ObstacleSynchronizeReportComplet.h"
#include "project_s_msgs/ObstacleSynchronizeReport.h"
#include "project_s_msgs/ObstacleFusionReport.h"
#include "project_s_msgs/GenericSmartData.h"

#include "project_s_msgs/Configurations.h"

//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------
// à compléter si d'autres capteurs
#define NBR_SENSOR		3	// 3 capteurs (Lidar, Radar, Camera), x 10 pistes locales max
#define ID_LIDAR		0
#define ID_RADAR		1
#define ID_CAMERA_ME		2

struct struct_tableauSensorParameter{
	double range;
	double fov;
}tableauSensorParameter[NBR_SENSOR];

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleAlignmentReport*  ptrSensor[NBR_SENSOR];
project_s_msgs::ObstacleSynchronizeReport ptrSensor_;
project_s_msgs::ObstacleSynchronizeReportComplet ObstacleSynchronizeReportComplet;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport reportObstacleFusion;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedLocalTracksAssociation = false;
void localTracksAssociationCallback(const project_s_msgs::ObstacleSynchronizeReportComplet::ConstPtr& genericObstacleFusion)
{
	ObstacleSynchronizeReportComplet = *genericObstacleFusion;

	reportObstacleFusion = ObstacleSynchronizeReportComplet.ObstacleFusionReport;
	ptrSensor_           = ObstacleSynchronizeReportComplet.ObstacleSynchronizeReport;

	receivedLocalTracksAssociation = true;
}

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
bool inView(geometry_msgs::Point objectInView, double range, double fov)
{
	double c1 = objectInView.x;
	double c2 = std::abs(objectInView.y);
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

bool inViewLidar(geometry_msgs::Point objectInView, double range, double fov)
{
	double c1 = objectInView.x;
	double c2 = std::abs(objectInView.y);
	double i = std::sqrt(pow(c1,2)+pow(c2,2));
	
	if (((c2 == 0.0) && (c1 <= 0.0)) || ((c1 <= 0.0) && (c1/c2 < -tan(M_PI/4))))
		return false;
	else if (i < range)
		return true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("local_tracks_fusion"));

	ros::NodeHandle n;

	ros::Publisher pub_local_tracks_fusion = n.advertise<project_s_msgs::ObstacleFusionReport>(std::string("/local_tracks_fusion_data"), 1);

	ros::Subscriber sub_local_tracks_association = n.subscribe(std::string("/local_tracks_association_data"), 1, localTracksAssociationCallback);

	ros::Rate loop_rate(100);

	// à compléter si d'autres capteurs
	ptrSensor[ID_LIDAR]     = &ptrSensor_.ObstacleSynchronizeReport[ID_LIDAR];
	ptrSensor[ID_RADAR]     = &ptrSensor_.ObstacleSynchronizeReport[ID_RADAR];
	ptrSensor[ID_CAMERA_ME] = &ptrSensor_.ObstacleSynchronizeReport[ID_CAMERA_ME];

	if (n.hasParam("/lidar/range"))
		n.getParam("/lidar/range", tableauSensorParameter[ID_LIDAR].range);
	if (n.hasParam("/lidar/fov"))
		n.getParam("/lidar/fov", tableauSensorParameter[ID_LIDAR].fov);

	if (n.hasParam("/ESR_2_5/range_mid"))
		n.getParam("/ESR_2_5/range_mid", tableauSensorParameter[ID_RADAR].range);
	if (n.hasParam("/ESR_2_5/fov_mid_range"))
		n.getParam("/ESR_2_5/fov_mid_range", tableauSensorParameter[ID_RADAR].fov);

	if (n.hasParam("/mobil_eye/range"))
		n.getParam("/mobil_eye/range", tableauSensorParameter[ID_CAMERA_ME].range);
	if (n.hasParam("/mobil_eye/fov"))
		n.getParam("/mobil_eye/fov", tableauSensorParameter[ID_CAMERA_ME].fov);

	while(n.ok())
	{
		ros::spinOnce();

		if (receivedLocalTracksAssociation)
		{
			receivedLocalTracksAssociation = false;

//-------------------------------------------------------------------------------------------------
// 			fusion locale
//-------------------------------------------------------------------------------------------------

			for (int id = 0; id < reportObstacleFusion.QtyObstacles.data; id++){
				// fusion en faisant la moyenne pondérée (avec incertitude) des pistes locales
				int nbrPistes = 0;
				geometry_msgs::Vector3 sigma_Position = geometry_msgs::Vector3();
				geometry_msgs::Vector3 sigma_Velocity = geometry_msgs::Vector3();
				for(int p = 0; p < NBR_SENSOR; p++){
					int j;
					if((j = reportObstacleFusion.ObstacleFusion[id].idPiste[p].data) != 0xFFFF){


//------------------ Pass value of ObstacleBodyCenter in Fusion report -----------------------------

//reportObstacleFusion.ObstacleFusion[id].obstacleBodyCenter = ptrSensor[p]->ObstacleAlignement[j].obstacleBodyCenter;

//--------------------------------------------------------------------------------------------------


						reportObstacleFusion.ObstacleFusion[id].obstaclePosition.position.x +=
						ptrSensor[p]->ObstacleAlignement[j].obstaclePosition.position.x / sqrt(ptrSensor[p]->ObstacleAlignement[j].obstaclePoseVariance.position.x);
						sigma_Position.x += 1.0/sqrt(ptrSensor[p]->ObstacleAlignement[j].obstaclePoseVariance.position.x);
						reportObstacleFusion.ObstacleFusion[id].obstaclePosition.position.y +=
						ptrSensor[p]->ObstacleAlignement[j].obstaclePosition.position.y / sqrt(ptrSensor[p]->ObstacleAlignement[j].obstaclePoseVariance.position.y);
						sigma_Position.y += 1.0/sqrt(ptrSensor[p]->ObstacleAlignement[j].obstaclePoseVariance.position.y);

						reportObstacleFusion.ObstacleFusion[id].obstacleVelocity.linear.x +=
						ptrSensor[p]->ObstacleAlignement[j].obstacleVelocity.linear.x / sqrt(ptrSensor[p]->ObstacleAlignement[j].obstacleVelocityVariance.linear.x);
						sigma_Velocity.x += 1.0/sqrt(ptrSensor[p]->ObstacleAlignement[j].obstacleVelocityVariance.linear.x);
						reportObstacleFusion.ObstacleFusion[id].obstacleVelocity.linear.y +=
						ptrSensor[p]->ObstacleAlignement[j].obstacleVelocity.linear.y / sqrt(ptrSensor[p]->ObstacleAlignement[j].obstacleVelocityVariance.linear.y);
						sigma_Velocity.y += 1.0/sqrt(ptrSensor[p]->ObstacleAlignement[j].obstacleVelocityVariance.linear.y);

						reportObstacleFusion.ObstacleFusion[id].obstacleAcceleration.linear.x += ptrSensor[p]->ObstacleAlignement[j].obstacleAcceleration.linear.x;
						reportObstacleFusion.ObstacleFusion[id].obstacleAcceleration.linear.y += ptrSensor[p]->ObstacleAlignement[j].obstacleAcceleration.linear.y;

/*						reportObstacleFusion.ObstacleFusion[id].obstacleDimensions.x += ptrSensor[p]->ObstacleAlignement[j].obstacleDimensions.x;
						reportObstacleFusion.ObstacleFusion[id].obstacleDimensions.y += ptrSensor[p]->ObstacleAlignement[j].obstacleDimensions.y;*/

						nbrPistes++;
					}
				}

				reportObstacleFusion.ObstacleFusion[id].obstaclePosition.position.x /= sigma_Position.x;
				reportObstacleFusion.ObstacleFusion[id].obstaclePosition.position.y /= sigma_Position.y;

				reportObstacleFusion.ObstacleFusion[id].obstaclePoseVariance.position.x = 1.0/pow(sigma_Position.x, 2);
				reportObstacleFusion.ObstacleFusion[id].obstaclePoseVariance.position.y = 1.0/pow(sigma_Position.y, 2);

				reportObstacleFusion.ObstacleFusion[id].obstacleVelocity.linear.x /= sigma_Velocity.x;
				reportObstacleFusion.ObstacleFusion[id].obstacleVelocity.linear.y /= sigma_Velocity.y;

				reportObstacleFusion.ObstacleFusion[id].obstacleVelocityVariance.linear.x = 1.0/pow(sigma_Velocity.x, 2);
				reportObstacleFusion.ObstacleFusion[id].obstacleVelocityVariance.linear.y = 1.0/pow(sigma_Velocity.y, 2);

				reportObstacleFusion.ObstacleFusion[id].obstacleAcceleration.linear.x /= nbrPistes;
				reportObstacleFusion.ObstacleFusion[id].obstacleAcceleration.linear.y /= nbrPistes;

/*				reportObstacleFusion.ObstacleFusion[id].obstacleDimensions.x /= nbrPistes;
				reportObstacleFusion.ObstacleFusion[id].obstacleDimensions.y /= nbrPistes;*/

				int j;
				if((j = reportObstacleFusion.ObstacleFusion[id].idPiste[ID_LIDAR].data) != 0xFFFF){
					reportObstacleFusion.ObstacleFusion[id].obstacleDimensions = ptrSensor[ID_LIDAR]->ObstacleAlignement[j].obstacleDimensions;

//(Amit) Obstacle angle from OAlign report as obstacleCap in Fusion report----------------------------

		reportObstacleFusion.ObstacleFusion[id].obstacleCap.z = ptrSensor[ID_LIDAR]->ObstacleAlignement[j].obstacleAngle;

		reportObstacleFusion.ObstacleFusion[id].obstacleBodyCenter = ptrSensor[ID_LIDAR]->ObstacleAlignement[j].obstacleBodyCenter;

		std::cout<<"\nObstacleCap"<<reportObstacleFusion.ObstacleFusion[id].obstacleCap;

//---- -----------------------------------------------------------------------------------------------



				}
				else{
					reportObstacleFusion.ObstacleFusion[id].obstacleDimensions.x = 0.1;
					reportObstacleFusion.ObstacleFusion[id].obstacleDimensions.y = 0.1;
					reportObstacleFusion.ObstacleFusion[id].obstacleDimensions.z = 0.1;

					reportObstacleFusion.ObstacleFusion[id].obstacleCap.z = 0;	// 0 par défaut

					if((j = reportObstacleFusion.ObstacleFusion[id].idPiste[ID_RADAR].data) != 0xFFFF)
						reportObstacleFusion.ObstacleFusion[id].obstacleBodyCenter = ptrSensor[ID_RADAR]->ObstacleAlignement[j].obstacleBodyCenter;
					else if((j = reportObstacleFusion.ObstacleFusion[id].idPiste[ID_CAMERA_ME].data) != 0xFFFF)
						reportObstacleFusion.ObstacleFusion[id].obstacleBodyCenter = ptrSensor[ID_CAMERA_ME]->ObstacleAlignement[j].obstacleBodyCenter;
					//else
					//	reportObstacleFusion.ObstacleFusion[id].obstacleBodyCenter = ptrSensor[???]->ObstacleAlignement[j].obstacleBodyCenter;
				}

				if((j = reportObstacleFusion.ObstacleFusion[id].idPiste[ID_CAMERA_ME].data) != 0xFFFF){
					reportObstacleFusion.ObstacleFusion[id].obstacleClass         = ptrSensor[ID_CAMERA_ME]->ObstacleAlignement[j].obstacleClass;
					reportObstacleFusion.ObstacleFusion[id].vision_only_sign_type = ptrSensor[ID_CAMERA_ME]->ObstacleAlignement[j].vision_only_sign_type;
				}
				else{
					reportObstacleFusion.ObstacleFusion[id].obstacleClass         = project_s_msgs::GenericSmartData::OBSTACLE_CLASS_NONE;
					reportObstacleFusion.ObstacleFusion[id].vision_only_sign_type = 0;
				}

//-------------------------------------------------------------------------------------------------
// 			calcul de nbrDetection & nbrVisibility
//-------------------------------------------------------------------------------------------------

				reportObstacleFusion.ObstacleFusion[id].nbrDetection.data  = nbrPistes;

				reportObstacleFusion.ObstacleFusion[id].nbrVisibility.data = 0.0;
				for(int k = 0; k < NBR_SENSOR; k++){
					switch(k){
					case ID_LIDAR :
#ifdef PROJECT_S_VEHICLE
						//if(...)
// POUR TEST
reportObstacleFusion.ObstacleFusion[id].nbrVisibility.data = 3/*nbrPistes*/;
#endif
#ifdef PROJECT_S_SIMULATION
						if(inViewLidar(reportObstacleFusion.ObstacleFusion[id].obstaclePosition.position, tableauSensorParameter[k].range, tableauSensorParameter[k].fov))
							reportObstacleFusion.ObstacleFusion[id].nbrVisibility.data += 1.0;
#endif
						break;
					case ID_RADAR :
					case ID_CAMERA_ME :
#ifdef PROJECT_S_VEHICLE
						//if(...)
#endif
#ifdef PROJECT_S_SIMULATION
						if(inView(reportObstacleFusion.ObstacleFusion[id].obstaclePosition.position, tableauSensorParameter[k].range, tableauSensorParameter[k].fov))
							reportObstacleFusion.ObstacleFusion[id].nbrVisibility.data += 1.0;
#endif
						break;
					}
				}
			}

//-------------------------------------------------------------------------------------------------
//			publication
//-------------------------------------------------------------------------------------------------

			pub_local_tracks_fusion.publish(reportObstacleFusion);
		}

		loop_rate.sleep();		
	}

	return 0;
}

