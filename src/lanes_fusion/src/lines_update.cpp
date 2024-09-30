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

#include "project_s_msgs/ObstacleFusion.h"
#include "project_s_msgs/LaneFusion.h"
#include "project_s_msgs/GenericSmartData.h"
#include "project_s_msgs/RouteLine.h"
#include "project_s_msgs/LaneAlignment.h"
#include "project_s_msgs/LaneSynchronizedReportComplet.h"

//#include "lanes_fusion/lanes_fusion.h"

#define ID_LINE_FUSION		0
#define ID_LINE_MOBILEYE	1

// ----- Confidence Management -----
//#define SCORE_DETECTION_SEUIL	0.3	// (on passe en CURRENT_TRACK par exemple avec 1 vues / 3 capteurs)
//#define SCORE_DETECTION_SEUIL	0.6	// (on passe en CURRENT_TRACK par exemple avec 2 vues / 3 capteurs)
//#define SCORE_DETECTION_SEUIL	1.0	// (on passe en CURRENT_TRACK par exemple avec 3 vues / 3 capteurs)
#define SCORE_DETECTION_SEUIL	2.0	// (on passe en CURRENT_TRACK par exemple avec 6 vues / 3 capteurs --> permet de "neutraliser" scoreDetection pour test)

//#define SCORE_DETECTION_SEUIL	0.9	// (on passe en CURRENT_TRACK si 90% des capteurs concernés voient l'objet)

#define SCORE_PERSISTENCE_INF	0.50	// SCORE_PERSISTENCE_INF <= 0.5 < SCORE_PERSISTENCE_SUP
#define SCORE_PERSISTENCE_SUP	0.90

#define	IDLE_TRACK	0
#define	PRE_TRACK	1
#define	POST_TRACK	2
#define	CURRENT_TRACK	3
#define	DEFAULT_TRACK	100

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::LaneAlignment                 bufferCameraMeLineAligned;
project_s_msgs::LaneSynchronizedReportComplet lines_association;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::LaneFusion fusionData;
project_s_msgs::LaneFusion lines_update;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool laneAlignmentReceived = false;
void cameraMeLineAlignedCallback(const project_s_msgs::LaneAlignment::ConstPtr& laneAlignment)
{
	bufferCameraMeLineAligned = *laneAlignment;
	laneAlignmentReceived = true;
}

bool linesAssociationReceived = false;
void linesAssociationDataCallback(const project_s_msgs::LaneSynchronizedReportComplet::ConstPtr& buffer)
{
	lines_association = *buffer;

	linesAssociationReceived = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("lines_update"));

	ros::NodeHandle n;

	// Publisher
	ros::Publisher pub              = n.advertise<project_s_msgs::LaneFusion>(std::string("/lanes_fusion_data"), 1);
	ros::Publisher pub_lines_update = n.advertise<project_s_msgs::LaneFusion>(std::string("/lines_update_data"), 1);

	// Subscriber
	ros::Subscriber subMeLineAligned      = n.subscribe(std::string("/camera_me_route_alignment_data"), 1, cameraMeLineAlignedCallback);
	ros::Subscriber sub_lines_association = n.subscribe(std::string("/lines_association_data"),         1, linesAssociationDataCallback);

	ros::Rate loop_rate(1000);

	while(n.ok())
	{
		ros::spinOnce();

		if(laneAlignmentReceived)
		{
			laneAlignmentReceived = false;

			fusionData = project_s_msgs::LaneFusion();
			fusionData.id = bufferCameraMeLineAligned.id;
			fusionData.odom = bufferCameraMeLineAligned.odom;

			for(int i = 0; i < 3; i++)	// bufferCameraMeLineAligned est un tableau	5 lignes
			{				// mais on se limite pour l'instant à		3 lignes
				fusionData.line[i] = bufferCameraMeLineAligned.line[i];
			}

			pub.publish(fusionData);
		}

		if(linesAssociationReceived)
		{
			linesAssociationReceived = false;

			lines_update = lines_association.linesUpdate;
			//lines_update.header = lines_association.header // déjà fait dans lines_association.linesUpdate

//-------------------------------------------------------------------------------------------------
//			Fusion
//-------------------------------------------------------------------------------------------------
// i, j --> lignes
// m, n --> segment
			for(int id = 0; id < lines_update.QtyLine.data; id++){
				int i = lines_update.line[id].idPiste[ID_LINE_FUSION]  .data;
				int j = lines_update.line[id].idPiste[ID_LINE_MOBILEYE].data;

				project_s_msgs::Line lines_zero = project_s_msgs::Line();
				lines_zero.existenceState.data = DEFAULT_TRACK;

				if(i != 0xFFFF){
					// on part d'une ligne trackée,
					if(j != 0xFFFF){
					// si la ligne trackée est associée à une ligne ME, on fusionne les 2

						uint QtySegment = 0;

						// ajout de tous les points de la ligne trackée
						for(int m = 0; m < lines_association.laneFusion.line[i].QtySegment.data; m++){
							bool pt_commun = false;
							geometry_msgs::Point pt_1, pt_1_align;
							pt_1 = lines_association.laneFusion.line[i].segment[m].position;

							// recherche partie commune de la ligne trackée et de la ligne ME
							for(int n = 0; n < lines_association.laneAlignement.line[j].QtySegment.data-1; n++){
								geometry_msgs::Point pt_0, pt_2;
								pt_0 = lines_association.laneAlignement.line[j].segment[n]  .position;
								pt_2 = lines_association.laneAlignement.line[j].segment[n+1].position;

								if((pt_0.x <= pt_1.x) && (pt_1.x <= pt_2.x)){
									// partie commune
									pt_commun = true;

									// calcul de y par interpolation
									pt_1_align.x  =  pt_1.x;
									pt_1_align.y  =  pt_0.y;
									pt_1_align.y += (pt_2.y - pt_0.y) / (pt_2.x - pt_0.x) * (pt_1_align.x - pt_0.x);
 
									// moyenne en y de laneFusion & laneAlignement
									pt_1_align.y = (pt_1.y + pt_1_align.y)/2;
								}
							}

							if(pt_commun)
								lines_update.line[id].segment[QtySegment].position = pt_1_align;
							else
								lines_update.line[id].segment[QtySegment].position = pt_1;

							QtySegment++;
						}

						// ajout des points de la ligne ME qui ne sont pas communs à la ligne trackée
						geometry_msgs::Point pt_debut, pt_fin;
						pt_debut = lines_association.laneFusion.line[i].segment[0]           .position;
						pt_fin   = lines_association.laneFusion.line[i].segment[QtySegment-1].position;

						for(int n = 0; n < lines_association.laneAlignement.line[j].QtySegment.data; n++){
							geometry_msgs::Point pt_ME = lines_association.laneAlignement.line[j].segment[n].position;

							if((pt_ME.x < pt_debut.x) || (pt_fin.x < pt_ME.x)){
							//if(pt_fin.x < pt_ME.x){
								lines_update.line[id].segment[QtySegment].position = pt_ME;
								QtySegment++;
							}
						}

						lines_update.line[id].QtySegment.data = QtySegment;

						// on remet les points dans l'ordre croissant de x
						for(int m = 0; m < lines_update.line[id].QtySegment.data; m++){
							int n_min = m;
							geometry_msgs::Point pt_min = lines_update.line[id].segment[n_min].position;
							for(int n = m; n < lines_update.line[id].QtySegment.data; n++){
								if(lines_update.line[id].segment[n].position.x < pt_min.x){
									n_min = n;
									pt_min = lines_update.line[id].segment[n_min].position;
								}
							}

							for(int n = n_min; n > m; n--)
								lines_update.line[id].segment[n].position = lines_update.line[id].segment[n-1].position;

							lines_update.line[id].segment[m].position = pt_min;
						}
					}
					else{
					// si la ligne trackée n'est pas associée, on la transmet
						//lines_update.line[id] = lines_association.laneFusion.line[i];
						// on passe tous les segments plutot que la ligne entière, car lines_update.line[id] est déjà renseigné sur existenceState,...,idPiste
						for(int m = 0; m < lines_association.laneFusion.line[i].QtySegment.data; m++)
							lines_update.line[id].segment[m] = lines_association.laneFusion.line[i].segment[m];
						lines_update.line[id].QtySegment = lines_association.laneFusion.line[i].QtySegment;
					}
				}
				else if(j != 0xFFFF){
					// dans le cas d'une ligne ME non associée, on la transmet
					//lines_update.line[id] = lines_association.laneAlignement.line[j];
					// on passe tous les segments plutot que la ligne entière, car lines_update.line[id] est déjà renseigné sur existenceState,...,idPiste
					for(int n = 0; n < lines_association.laneAlignement.line[j].QtySegment.data; n++)
						lines_update.line[id].segment[n] = lines_association.laneAlignement.line[j].segment[n];
					lines_update.line[id].QtySegment = lines_association.laneAlignement.line[j].QtySegment;
				}
				else{
					lines_update.line[id] = lines_zero;
				}
			}

//-------------------------------------------------------------------------------------------------
//			Confidence Management
//-------------------------------------------------------------------------------------------------

			for(int i = 0; i < lines_update.QtyLine.data; i++){
				// calculation of scoreDetection
				if(lines_update.line[i].nbrVisibility.data == 0){
					lines_update.line[i].scoreDetection.data = 0;
				}
				else{
					lines_update.line[i].scoreDetection.data = lines_update.line[i].nbrDetection.data / lines_update.line[i].nbrVisibility.data;
				}

				// calculation of scorePersistence
				lines_update.line[i].scorePersistence.data = lines_update.line[i].nbrUpdate.data / (lines_update.line[i].nbrAge.data + 1.0);

				switch(lines_update.line[i].existenceState.data){
				case IDLE_TRACK :
					if(lines_update.line[i].scoreDetection.data < SCORE_DETECTION_SEUIL){
						// évènement E1
						lines_update.line[i].existenceState.data = PRE_TRACK;
					}
					else{
						// évènement E2
						lines_update.line[i].existenceState.data = CURRENT_TRACK;
					}
					break;
				case PRE_TRACK :
					if(lines_update.line[i].scorePersistence.data < SCORE_PERSISTENCE_INF){
						// évènement E3
						lines_update.line[i].existenceState.data = IDLE_TRACK;
					}
					if(   (lines_update.line[i].scoreDetection.data >= SCORE_DETECTION_SEUIL)
					   || (lines_update.line[i].scorePersistence.data >= SCORE_PERSISTENCE_SUP)){
						// évènement E4
						lines_update.line[i].existenceState.data = CURRENT_TRACK;
					}
					break;
				case CURRENT_TRACK :
					if(   (lines_update.line[i].scoreDetection.data < SCORE_DETECTION_SEUIL)
					   && (lines_update.line[i].scorePersistence.data < SCORE_PERSISTENCE_SUP)){
						// évènement E5
						lines_update.line[i].existenceState.data = POST_TRACK;
					}
					break;
				case POST_TRACK :
					if(   (lines_update.line[i].scoreDetection.data >= SCORE_DETECTION_SEUIL)
					   || (lines_update.line[i].scorePersistence.data >= SCORE_PERSISTENCE_SUP)){
						// évènement E6
						lines_update.line[i].existenceState.data = CURRENT_TRACK;
					}
					if(   (lines_update.line[i].scorePersistence.data < SCORE_PERSISTENCE_INF)
					   && (lines_update.line[i].QtySegment.data == 0))
						// le test sur QtySegment permet d'éliminer la ligne trackée seulement si elle disparait par le test (distance < REAR_MAX_RANGE) /
						//                                                                                                 voir lines_synchronisation.cpp
					{
						// évènement E7
						lines_update.line[i].existenceState.data = IDLE_TRACK;
					}
					break;
				default :
					lines_update.line[i].existenceState.data = IDLE_TRACK;
					break;
				}
			}

			// élimination des IDLE_TRACK
			int id = 0;
			int QtyLines = lines_update.QtyLine.data;
			while(id < QtyLines){
				if(lines_update.line[id].existenceState.data == IDLE_TRACK){
					QtyLines--;
					for(int i = id; i < QtyLines; i++)
						lines_update.line[i] = lines_update.line[i+1];
					id--;
				}

				id++;
			}
			lines_update.QtyLine.data = QtyLines;

			// classement des lignes CURRENT_TRACK et POST_TRACK par ordre croissant de droite à gauche
			for(int id = 0; id < lines_update.QtyLine.data; id++){
				int i_droite = id;
				project_s_msgs::Line line_droite = lines_update.line[i_droite];
				for(int i = id; i < lines_update.QtyLine.data; i++){
					if(  (lines_update.line[i].existenceState.data == CURRENT_TRACK)
					   ||(lines_update.line[i].existenceState.data == POST_TRACK)){
					// le plus à droite correspond à un y le plus petit
						if(lines_update.line[i].segment[0].position.y < line_droite.segment[0].position.y){
							i_droite = i;
							line_droite = lines_update.line[i_droite];
						}
					}
				}

				for(int i = i_droite; i > id; i--)
					lines_update.line[i] = lines_update.line[i-1];

				lines_update.line[id] = line_droite;
			}

//ROS_ERROR("QtyLine : %d", lines_update.QtyLine.data);

//-------------------------------------------------------------------------------------------------
//			publication
//-------------------------------------------------------------------------------------------------

			pub_lines_update.publish(lines_update);
		}

		loop_rate.sleep();
	}

	return 0;
}
