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

#include "project_s_msgs/ObstacleFusionReport.h"

//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------
// ----- Confidence Management -----
//#define SCORE_DETECTION_SEUIL	0.3	// (on passe en CURRENT_TRACK par exemple avec 1 vues / 3 capteurs)
//#define SCORE_DETECTION_SEUIL	0.6	// (on passe en CURRENT_TRACK par exemple avec 2 vues / 3 capteurs)
//#define SCORE_DETECTION_SEUIL	1.0	// (on passe en CURRENT_TRACK par exemple avec 3 vues / 3 capteurs)
//#define SCORE_DETECTION_SEUIL	2.0	// (on passe en CURRENT_TRACK par exemple avec 6 vues / 3 capteurs --> permet de "neutraliser" scoreDetection pour test)

#define SCORE_DETECTION_SEUIL	0.6

#define SCORE_PERSISTENCE_INF	0.10	// SCORE_PERSISTENCE_INF <= 0.5 < SCORE_PERSISTENCE_SUP
#define SCORE_PERSISTENCE_SUP	0.80

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport reportObstacleFusion;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport reportObstacleFusionGlobale;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedGlobalTracksUpdate = false;
void globalTracksUpdateCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& genericObstacleFusion)
{
	reportObstacleFusion = *genericObstacleFusion;

	receivedGlobalTracksUpdate = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("global_tracks_confidence"));

	ros::NodeHandle n;

	ros::Publisher pub_global_tracks_confidence = n.advertise<project_s_msgs::ObstacleFusionReport>(std::string("/global_tracks_confidence_data"), 1);

	ros::Subscriber sub_global_tracks_update = n.subscribe(std::string("/global_tracks_update_data"), 1, globalTracksUpdateCallback);

	ros::Rate loop_rate(100);

	while(n.ok())
	{
		ros::spinOnce();

		if (receivedGlobalTracksUpdate)
		{
			receivedGlobalTracksUpdate = false;

			reportObstacleFusionGlobale = reportObstacleFusion;	// comprend .header .id .odom

//-------------------------------------------------------------------------------------------------
//			Confidence Management
//-------------------------------------------------------------------------------------------------

			for (int i = 0; i < reportObstacleFusionGlobale.QtyObstacles.data; i++){

				// calculation of scoreDetection
				if(reportObstacleFusionGlobale.ObstacleFusion[i].nbrVisibility.data == 0){
					reportObstacleFusionGlobale.ObstacleFusion[i].scoreDetection.data = 0;
				}
				else{
					reportObstacleFusionGlobale.ObstacleFusion[i].scoreDetection.data = reportObstacleFusionGlobale.ObstacleFusion[i].nbrDetection.data /
													    reportObstacleFusionGlobale.ObstacleFusion[i].nbrVisibility.data;
				}

				// calculation of scorePersistence
				reportObstacleFusionGlobale.ObstacleFusion[i].scorePersistence.data = reportObstacleFusionGlobale.ObstacleFusion[i].nbrUpdate.data /
												     (reportObstacleFusionGlobale.ObstacleFusion[i].nbrAge.data + 1.0);

				switch(reportObstacleFusionGlobale.ObstacleFusion[i].existenceState.data){
				case project_s_msgs::ObstacleFusion::IDLE_TRACK :
					if(reportObstacleFusionGlobale.ObstacleFusion[i].scoreDetection.data < SCORE_DETECTION_SEUIL){
						// évènement E1
						reportObstacleFusionGlobale.ObstacleFusion[i].existenceState.data = project_s_msgs::ObstacleFusion::PRE_TRACK;
					}
					else{
						// évènement E2
						reportObstacleFusionGlobale.ObstacleFusion[i].existenceState.data = project_s_msgs::ObstacleFusion::CURRENT_TRACK;
					}
					break;
				case project_s_msgs::ObstacleFusion::PRE_TRACK :
					if(reportObstacleFusionGlobale.ObstacleFusion[i].scorePersistence.data < SCORE_PERSISTENCE_INF){
						// évènement E3
						reportObstacleFusionGlobale.ObstacleFusion[i].existenceState.data = project_s_msgs::ObstacleFusion::IDLE_TRACK;
					}
					if(   (reportObstacleFusionGlobale.ObstacleFusion[i].scoreDetection.data >= SCORE_DETECTION_SEUIL)
					   || (reportObstacleFusionGlobale.ObstacleFusion[i].scorePersistence.data >= SCORE_PERSISTENCE_SUP)){
						// évènement E4
						reportObstacleFusionGlobale.ObstacleFusion[i].existenceState.data = project_s_msgs::ObstacleFusion::CURRENT_TRACK;
					}
					break;
				case project_s_msgs::ObstacleFusion::CURRENT_TRACK :
					if(   (reportObstacleFusionGlobale.ObstacleFusion[i].scoreDetection.data < SCORE_DETECTION_SEUIL)
					   && (reportObstacleFusionGlobale.ObstacleFusion[i].scorePersistence.data < SCORE_PERSISTENCE_SUP)){
						// évènement E5
						reportObstacleFusionGlobale.ObstacleFusion[i].existenceState.data = project_s_msgs::ObstacleFusion::POST_TRACK;
					}
					break;
				case project_s_msgs::ObstacleFusion::POST_TRACK :
					if(   (reportObstacleFusionGlobale.ObstacleFusion[i].scoreDetection.data >= SCORE_DETECTION_SEUIL)
					   || (reportObstacleFusionGlobale.ObstacleFusion[i].scorePersistence.data >= SCORE_PERSISTENCE_SUP)){
						// évènement E6
						reportObstacleFusionGlobale.ObstacleFusion[i].existenceState.data = project_s_msgs::ObstacleFusion::CURRENT_TRACK;
					}
					if(reportObstacleFusionGlobale.ObstacleFusion[i].scorePersistence.data < SCORE_PERSISTENCE_INF){
						// évènement E7
						reportObstacleFusionGlobale.ObstacleFusion[i].existenceState.data = project_s_msgs::ObstacleFusion::IDLE_TRACK;
					}
					break;
				default :
					reportObstacleFusionGlobale.ObstacleFusion[i].existenceState.data = project_s_msgs::ObstacleFusion::IDLE_TRACK;
					break;
				}
			}


			// élimination des IDLE_TRACK
			int id = 0;
			int QtyObstacles = reportObstacleFusionGlobale.QtyObstacles.data;
			while(id < QtyObstacles){
				if(reportObstacleFusionGlobale.ObstacleFusion[id].existenceState.data == project_s_msgs::ObstacleFusion::IDLE_TRACK){
					reportObstacleFusionGlobale.QtyObstacles.data--;
					for(int i = id; i < reportObstacleFusionGlobale.QtyObstacles.data; i++)
						reportObstacleFusionGlobale.ObstacleFusion[i] = reportObstacleFusionGlobale.ObstacleFusion[i+1];
					id--;
				}

				id++;
				QtyObstacles = reportObstacleFusionGlobale.QtyObstacles.data;
			}

//-------------------------------------------------------------------------------------------------
//			publication
//-------------------------------------------------------------------------------------------------

			pub_global_tracks_confidence.publish(reportObstacleFusionGlobale);
		}

		loop_rate.sleep();		
	}

	return 0;
}
