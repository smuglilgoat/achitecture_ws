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

#include "project_s_msgs/LaneSynchronizedReport.h"
#include "project_s_msgs/LaneSynchronizedReportComplet.h"

#define NBR_SOURCE_LINE		2	// 2 sources de lines (fusion, ME) 
#define ID_LINE_FUSION		0
#define ID_LINE_MOBILEYE	1
struct struct_tableauAssociationLine{
	float distance[project_s_msgs::LaneAlignment::LINE_REPORT_SIZE][project_s_msgs::LaneAlignment::LINE_REPORT_SIZE];
	struct{
		int idPiste[NBR_SOURCE_LINE];
	}ExistenceDoublet[NBR_SOURCE_LINE][project_s_msgs::LaneAlignment::LINE_REPORT_SIZE];
};
#define SEUIL_ASSOCIATION	0.5		// unity = meter, ou meter²
//#define SEUIL_ASSOCIATION	0.0		// unity = meter, ou meter²
#define INVALID_VALUE		-1		// mettre une valeur < 0

// concerne la confidence
#define	IDLE_TRACK	0
#define	PRE_TRACK	1
#define	POST_TRACK	2
#define	CURRENT_TRACK	3
#define	DEFAULT_TRACK	100

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::LaneSynchronizedReport lines_synchronization;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::LaneSynchronizedReportComplet lines_association;
project_s_msgs::LaneFusion                    linesUpdate;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool linesSynchronizationReceived = false;
void linesSynchronizationDataCallback(const project_s_msgs::LaneSynchronizedReport::ConstPtr& buffer)
{
	lines_synchronization = *buffer;

	linesSynchronizationReceived = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "lines_association");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher pub_lines_association = n.advertise<project_s_msgs::LaneSynchronizedReportComplet>(std::string("/lines_association_data"), 1);

	// Subscriber
	ros::Subscriber sub_lines_synchronization = n.subscribe(std::string("/lines_synchronization_data"), 1, linesSynchronizationDataCallback); 

	ros::Rate loop_rate(1000);

  	while(n.ok())
	{
		ros::spinOnce();

		if(linesSynchronizationReceived){
			linesSynchronizationReceived = false;

//-------------------------------------------------------------------------------------------------
//			calcul distances
//-------------------------------------------------------------------------------------------------

// k, p --> source de lignes
// i, j --> lignes
// m, n --> segment
			struct_tableauAssociationLine tableauAssociationLine;

			// clear du tableau distance
			for(int i = 0; i < project_s_msgs::LaneAlignment::LINE_REPORT_SIZE; i++)
				for(int j = 0; j < project_s_msgs::LaneAlignment::LINE_REPORT_SIZE; j++)
					tableauAssociationLine.distance[i][j] = INVALID_VALUE;

			// remplissage tableau tableauAssociationLine
			for(int i = 0; i < lines_synchronization.laneFusion.QtyLine.data; i++){
				for(int j = 0; j < lines_synchronization.laneAlignement.QtyLine.data; j++){
					float distance = 0;
					uint nbrPoints = 0;

					// calcul distance
					for(int m = 0; m < lines_synchronization.laneFusion.line[i].QtySegment.data; m++){
						geometry_msgs::Point pt_1;
						pt_1 = lines_synchronization.laneFusion.line[i].segment[m].position;

						// recherche partie commune
						for(int n = 0; n < lines_synchronization.laneAlignement.line[j].QtySegment.data-1; n++){
							geometry_msgs::Point pt_0, pt_1_align, pt_2;
							pt_0 = lines_synchronization.laneAlignement.line[j].segment[n]  .position;
							pt_2 = lines_synchronization.laneAlignement.line[j].segment[n+1].position;

							if((pt_0.x <= pt_1.x) && (pt_1.x <= pt_2.x)){
								// calcul de y par interpolation
								pt_1_align.x  =  pt_1.x;
								pt_1_align.y  =  pt_0.y;
								pt_1_align.y += (pt_2.y - pt_0.y) / (pt_2.x - pt_0.x) * (pt_1_align.x - pt_0.x);
 
								// calcul de |delta_y|²
								float fl_buffer;
								fl_buffer = pt_1.y - pt_1_align.y;
								distance += std::pow(fl_buffer,2);

								nbrPoints++;
							}
						}
					}

					if(nbrPoints != 0){
						distance  = std::sqrt(distance);
						distance /= nbrPoints;
					}
					else{
						distance = INVALID_VALUE;
					}

					tableauAssociationLine.distance[i][j] = distance;	// [i][ ]	correspond à la ième ligne de laneFusion
												// [ ][j]	correspond à la jème ligne de laneAlignement
				}
			}

//-------------------------------------------------------------------------------------------------
// 			association
//-------------------------------------------------------------------------------------------------

			// clear du tableau ExistenceDoublet
			for(int k = 0; k < NBR_SOURCE_LINE; k++)
				for(int i = 0; i < project_s_msgs::LaneAlignment::LINE_REPORT_SIZE; i++)
					for(int p = 0; p < NBR_SOURCE_LINE; p++)
						tableauAssociationLine.ExistenceDoublet[k][i].idPiste[p] = 0xFFFF;

			// init du tableau ExistenceDoublet
			for(int i = 0; i < lines_synchronization.laneFusion.QtyLine.data; i++)
				tableauAssociationLine.ExistenceDoublet[ID_LINE_FUSION][i].idPiste[ID_LINE_FUSION] = i;
			for(int j = 0; j < lines_synchronization.laneAlignement.QtyLine.data; j++)
				tableauAssociationLine.ExistenceDoublet[ID_LINE_MOBILEYE][j].idPiste[ID_LINE_MOBILEYE] = j;

			bool fl_doublet_detected;	// initialisé au début de la boucle do{}

			do{
				// recherche de la distance minimale entre les lignes synchronisées et les lignes alignées
				int iMin;
				int jMin;
				float distanceMin = INVALID_VALUE;	// distance par défaut en attendant la première mise à jour
				fl_doublet_detected = false;

				for(int i = 0; i < lines_synchronization.laneFusion.QtyLine.data; i++){
					for(int j = 0; j < lines_synchronization.laneAlignement.QtyLine.data; j++){
						float distance = tableauAssociationLine.distance[i][j];

						if(distance != INVALID_VALUE)
						{	// test car tableauAssociationLine.distance[i][j] peut être remis à INVALID_VALUE lors du RAZ de la colone jMin et de la ligne iMin
							if((distanceMin == INVALID_VALUE) || (distanceMin > distance)){
								iMin = i;
								jMin = j;
								distanceMin = distance;
							}
						}
					}
				}

				// test si la distance minimale remplit les conditions d'un doublet
				if((distanceMin != INVALID_VALUE) && (distanceMin < SEUIL_ASSOCIATION)){
					// c'est un doublet
					fl_doublet_detected = true;

					// RAZ au tableau de la colone jMin et de la ligne iMin
					for(int i = 0; i < lines_synchronization.laneFusion.QtyLine.data; i++)
						tableauAssociationLine.distance[i][jMin] = INVALID_VALUE;
					for(int j = 0; j < lines_synchronization.laneAlignement.QtyLine.data; j++)
						tableauAssociationLine.distance[iMin][j] = INVALID_VALUE;

					//on mémorise que les pistes globales (ID_PISTE_GLOBALE;iMin) et (ID_PREDICTION_GLOBALE;jMin) sont associées
					tableauAssociationLine.ExistenceDoublet[ID_LINE_FUSION][iMin]  .idPiste[ID_LINE_FUSION]   = iMin;	// déjà initialisé
					tableauAssociationLine.ExistenceDoublet[ID_LINE_FUSION][iMin]  .idPiste[ID_LINE_MOBILEYE] = jMin;
					tableauAssociationLine.ExistenceDoublet[ID_LINE_MOBILEYE][jMin].idPiste[ID_LINE_FUSION]   = iMin;
					tableauAssociationLine.ExistenceDoublet[ID_LINE_MOBILEYE][jMin].idPiste[ID_LINE_MOBILEYE] = jMin;	// déjà initialisé
				}
			}while(fl_doublet_detected);

//-------------------------------------------------------------------------------------------------
// 			association / création des lignes fusionnées
//-------------------------------------------------------------------------------------------------

			// RAZ de la variable de Piste Globale
			linesUpdate        = project_s_msgs::LaneFusion();
			linesUpdate.header = lines_synchronization.header;
			//linesUpdate.id     = 
			//linesUpdate.odom   = 

			uint id = 0;

			{int k = ID_LINE_FUSION;
				for(int i = 0; i < lines_synchronization.laneFusion.QtyLine.data; i++){
					bool fl_doublet_detected = false;
					int idPiste[NBR_SOURCE_LINE];

					for(int p = 0; p < NBR_SOURCE_LINE; p++){
						int j;
						j = idPiste[p] = tableauAssociationLine.ExistenceDoublet[k][i].idPiste[p];

						if(j != 0xFFFF){
							fl_doublet_detected = true;

							// RAZ du tableau d'association -> piste(s) associée(s) du deuxième capteur
							if(p!=k){
								for(int l = 0; l < NBR_SOURCE_LINE; l++)
									tableauAssociationLine.ExistenceDoublet[p][j].idPiste[l] = 0xFFFF;
							}
						}

						// RAZ du tableau d'association -> piste du premier capteur
						tableauAssociationLine.ExistenceDoublet[k][i].idPiste[p] = 0xFFFF;
					}

					if(fl_doublet_detected){
						if(id > project_s_msgs::LaneAlignment::LINE_REPORT_SIZE-1)
							id = project_s_msgs::LaneAlignment::LINE_REPORT_SIZE-1;
						for(int p = 0; p < NBR_SOURCE_LINE; p++){
							linesUpdate.line[id].idPiste[p].data = idPiste[p];
						}

						id++;
					}
				}
			}

			{int k = ID_LINE_MOBILEYE;
				for(int i = 0; i < lines_synchronization.laneAlignement.QtyLine.data; i++){
					bool fl_doublet_detected = false;
					int idPiste[NBR_SOURCE_LINE];

					for(int p = 0; p < NBR_SOURCE_LINE; p++){
						int j;
						j = idPiste[p] = tableauAssociationLine.ExistenceDoublet[k][i].idPiste[p];

						if(j != 0xFFFF){
							fl_doublet_detected = true;

							// RAZ du tableau d'association -> piste(s) associée(s) du deuxième capteur
							if(p!=k){
								for(int l = 0; l < NBR_SOURCE_LINE; l++)
									tableauAssociationLine.ExistenceDoublet[p][j].idPiste[l] = 0xFFFF;
							}
						}

						// RAZ du tableau d'association -> piste du premier capteur
						tableauAssociationLine.ExistenceDoublet[k][i].idPiste[p] = 0xFFFF;
					}

					if(fl_doublet_detected){
						// on prend comme référence le capteur n°k
						//linesUpdate.ObstacleFusion[id].header  = ptrSourceGlobale[k]->ObstacleFusion[i].header;
						//reportObstacleFusionGlobale.ObstacleFusion[id].id.data = id;
						if(id > project_s_msgs::LaneAlignment::LINE_REPORT_SIZE-1)
							id = project_s_msgs::LaneAlignment::LINE_REPORT_SIZE-1;
						for(int p = 0; p < NBR_SOURCE_LINE; p++){
							linesUpdate.line[id].idPiste[p].data = idPiste[p];
						}

						id++;
					}
				}
			}

			linesUpdate.QtyLine.data = id;

//-------------------------------------------------------------------------------------------------
// 			Confidence management
//-------------------------------------------------------------------------------------------------

			for(int id = 0; id < linesUpdate.QtyLine.data; id++){
				int j;
				if((j = linesUpdate.line[id].idPiste[ID_LINE_FUSION].data) != 0xFFFF){
					// détection déjà vu dans Prediction
					linesUpdate.line[id].existenceState.data = lines_synchronization.laneFusion.line[j].existenceState.data;
					linesUpdate.line[id].nbrUpdate.data      = lines_synchronization.laneFusion.line[j].nbrUpdate.data;
					linesUpdate.line[id].nbrAge.data         = lines_synchronization.laneFusion.line[j].nbrAge.data;
				}
				else{
					// première détection
					linesUpdate.line[id].existenceState.data = IDLE_TRACK;
					linesUpdate.line[id].nbrUpdate.data      = 0;
					linesUpdate.line[id].nbrAge.data         = 0;
				}

				if((j = linesUpdate.line[id].idPiste[ID_LINE_MOBILEYE].data) != 0xFFFF){
					// détection vu par MOBILEYE
					linesUpdate.line[id].nbrUpdate.data += 1.0;

					linesUpdate.line[id].nbrDetection.data  = lines_synchronization.laneAlignement.line[j].nbrDetection.data;
					linesUpdate.line[id].nbrVisibility.data = lines_synchronization.laneAlignement.line[j].nbrVisibility.data;
				}
				else{
					linesUpdate.line[id].nbrUpdate.data -= 1.0;

					linesUpdate.line[id].nbrDetection.data  = 0;
					linesUpdate.line[id].nbrVisibility.data = 0;
				}
				linesUpdate.line[id].nbrAge.data += 1.0;

				//if((linesUpdate.line[id].idPiste[ID_LINE_FUSION].data == 0xFFFF) && (linesUpdate.line[id].idPiste[ID_LINE_MOBILEYE].data == 0xFFFF)){
				//	linesUpdate.line[id].existenceState.data = DEFAULT_TRACK;
				//}

				// on limite nbrUpdate et nbrAge
				if(linesUpdate.line[id].nbrUpdate.data > 20.0)
					linesUpdate.line[id].nbrUpdate.data = 20.0;
				if(linesUpdate.line[id].nbrUpdate.data < 0.0)
					linesUpdate.line[id].nbrUpdate.data = 0.0;
				if(linesUpdate.line[id].nbrAge.data > 20.0)
					linesUpdate.line[id].nbrAge.data = 20.0;
			}

//-------------------------------------------------------------------------------------------------
//			publication
//-------------------------------------------------------------------------------------------------

			lines_association.header         = lines_synchronization.header;
			lines_association.laneAlignement = lines_synchronization.laneAlignement;
			lines_association.laneFusion     = lines_synchronization.laneFusion;
			lines_association.linesUpdate    = linesUpdate;

			pub_lines_association.publish(lines_association);
		}

		loop_rate.sleep();
	}

	return 0;
}
