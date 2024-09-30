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
#include "project_s_msgs/ObstacleFusionReportComplet.h"

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport reportObstacleFusion;
project_s_msgs::ObstacleFusionReport predictionPisteGlobale;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport        reportObstacleFusionGlobale;
project_s_msgs::ObstacleFusionReportComplet reportObstacleFusionComplet;

//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------
// construction d'un tableau avec toutes les pistes globales
#define NBR_SOURCE_GLOBALE	2	// 2 sources de piste globale (fusion locale, prédiction) 
#define ID_PREDICTION_GLOBALE	0	// mettre à 0, pour commencer la création des objets globaux par ceux de la prédiction
#define ID_PISTE_GLOBALE	1

struct struct_tableauAssociationGlobale{
	float distancepisteglobale[project_s_msgs::ObstacleFusionReport::OBSTACLE_FUSION_REPORT_SIZE][project_s_msgs::ObstacleFusionReport::OBSTACLE_FUSION_REPORT_SIZE];
	struct{
		int idPiste[NBR_SOURCE_GLOBALE];
	}ExistenceDoublet[NBR_SOURCE_GLOBALE][project_s_msgs::ObstacleFusionReport::OBSTACLE_FUSION_REPORT_SIZE];
};

project_s_msgs::ObstacleFusionReport* ptrSourceGlobale[NBR_SOURCE_GLOBALE];

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedLocalTracksFusion = false;
void localTracksFusionCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& genericObstacleFusion)
{
	reportObstacleFusion = *genericObstacleFusion;

	receivedLocalTracksFusion = true;
}

bool receivedGlobalTracksPrediction = false;
void globalTracksPredictionCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& genericObstacleFusion)
{
	predictionPisteGlobale = *genericObstacleFusion;

	receivedGlobalTracksPrediction = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("global_tracks_association"));

	ros::NodeHandle n;

	ros::Publisher pub_global_tracks_association = n.advertise<project_s_msgs::ObstacleFusionReportComplet>(std::string("/global_tracks_association_data"), 1);

	ros::Subscriber sub_local_tracks_fusion      = n.subscribe(std::string("/local_tracks_fusion_data"), 1, localTracksFusionCallback);
	ros::Subscriber sub_global_tracks_prediction = n.subscribe(std::string("/global_tracks_prediction_data"), 1, globalTracksPredictionCallback);

	ros::Rate loop_rate(100);

	ptrSourceGlobale[ID_PISTE_GLOBALE]      = &reportObstacleFusion;
	ptrSourceGlobale[ID_PREDICTION_GLOBALE] = &predictionPisteGlobale;

	unsigned char id_last = 0;	// représente l'id du dernier objet enregistré dans le range [1...255]

	while(n.ok())
	{
		ros::spinOnce();

		if (receivedLocalTracksFusion || receivedGlobalTracksPrediction)
		{
			receivedLocalTracksFusion = false;
			receivedGlobalTracksPrediction = false;

			if(reportObstacleFusion.header.stamp == predictionPisteGlobale.header.stamp)
			{
//-------------------------------------------------------------------------------------------------
//			calcul distances globales
//-------------------------------------------------------------------------------------------------

			struct_tableauAssociationGlobale tableauAssociationGlobale;

			// clear du tableau distancepistelocale
			for(int i = 0; i < project_s_msgs::ObstacleFusionReport::OBSTACLE_FUSION_REPORT_SIZE; i++)
				for(int j = 0; j < project_s_msgs::ObstacleFusionReport::OBSTACLE_FUSION_REPORT_SIZE; j++)
					tableauAssociationGlobale.distancepisteglobale[i][j] = 0;

			// remplissage tableau distancepisteglobale
			for(int i = 0; i < reportObstacleFusion.QtyObstacles.data; i++){
				for(int j = 0; j < predictionPisteGlobale.QtyObstacles.data; j++){
					geometry_msgs::Point pt, pt_sigma;
					geometry_msgs::Vector3 velocity, velocity_sigma;
					float distance;
/*
					// calcul distance arithmétique
					pt.x =	reportObstacleFusion.ObstacleFusion[i].obstaclePosition.position.x - 
						predictionPisteGlobale.ObstacleFusion[j].obstaclePosition.position.x;
					pt.y =	reportObstacleFusion.ObstacleFusion[i].obstaclePosition.position.y - 
						predictionPisteGlobale.ObstacleFusion[j].obstaclePosition.position.y;

					distance  = std::sqrt(std::pow(pt.x,2) + std::pow(pt.y,2));
*/
					// calcul distance Mahalanobis
					pt.x =	reportObstacleFusion.ObstacleFusion[i].obstaclePosition.position.x - 
						predictionPisteGlobale.ObstacleFusion[j].obstaclePosition.position.x;
					pt.y =	reportObstacleFusion.ObstacleFusion[i].obstaclePosition.position.y - 
						predictionPisteGlobale.ObstacleFusion[j].obstaclePosition.position.y;
					/*pt.z =	reportObstacleFusion.ObstacleFusion[i].obstaclePosition.position.z - 
						predictionPisteGlobale.ObstacleFusion[j].obstaclePosition.position.z;*/

					pt_sigma.x = sqrt(reportObstacleFusion.ObstacleFusion[i].obstaclePoseVariance.position.x) +
					               sqrt(predictionPisteGlobale.ObstacleFusion[j].obstaclePoseVariance.position.x);
					pt_sigma.y = sqrt(reportObstacleFusion.ObstacleFusion[i].obstaclePoseVariance.position.y) +
					               sqrt(predictionPisteGlobale.ObstacleFusion[j].obstaclePoseVariance.position.y);
					/*pt_sigma.z = sqrt(reportObstacleFusion.ObstacleFusion[i].obstaclePoseVariance.position.z) +
					               sqrt(predictionPisteGlobale.ObstacleFusion[j].obstaclePoseVariance.position.z);*/
					if(pt_sigma.x == 0) pt_sigma.x = 1; if(pt_sigma.y == 0) pt_sigma.y = 1; if(pt_sigma.z == 0) pt_sigma.z = 1;

					distance  = std::pow(pt.x,2) / std::pow(pt_sigma.x,2);
					distance += std::pow(pt.y,2) / std::pow(pt_sigma.y,2);
					//distance += std::pow(pt.z,2) / std::pow(pt_sigma.z,2);

					velocity.x =	reportObstacleFusion.ObstacleFusion[i].obstacleVelocity.linear.x - 
							predictionPisteGlobale.ObstacleFusion[j].obstacleVelocity.linear.x;
					/*velocity.y =	reportObstacleFusion.ObstacleFusion[i].obstacleVelocity.linear.y - 
							predictionPisteGlobale.ObstacleFusion[j].obstacleVelocity.linear.y;
					velocity.z =	reportObstacleFusion.ObstacleFusion[i].obstacleVelocity.linear.z - 
							predictionPisteGlobale.ObstacleFusion[j].obstacleVelocity.linear.z;*/

					velocity_sigma.x = sqrt(reportObstacleFusion.ObstacleFusion[i].obstacleVelocityVariance.linear.x) +
					                     sqrt(predictionPisteGlobale.ObstacleFusion[j].obstacleVelocityVariance.linear.x);
					/*velocity_sigma.y = sqrt(reportObstacleFusion.ObstacleFusion[i].obstacleVelocityVariance.linear.y) +
					                     sqrt(predictionPisteGlobale.ObstacleFusion[j].obstacleVelocityVariance.linear.y);
					velocity_sigma.z = sqrt(reportObstacleFusion.ObstacleFusion[i].obstacleVelocityVariance.linear.z) +
					                     sqrt(predictionPisteGlobale.ObstacleFusion[j].obstacleVelocityVariance.linear.z);*/
					if(velocity_sigma.x == 0) velocity_sigma.x = 1; if(velocity_sigma.y == 0) velocity_sigma.y = 1;
					if(velocity_sigma.z == 0) velocity_sigma.z = 1;

					distance += std::pow(velocity.x,2) / std::pow(velocity_sigma.x,2);
					/*distance += std::pow(velocity.y,2) / std::pow(velocity_sigma.y,2);
					distance += std::pow(velocity.z,2) / std::pow(velocity_sigma.z,2);*/

										// on peut se passer de la racine carrée
					distance = std::sqrt(distance);	// sinon version avec la racine carrée

					tableauAssociationGlobale.distancepisteglobale[i][j] = distance;
				}
			}

//-------------------------------------------------------------------------------------------------
// 			association globale
//-------------------------------------------------------------------------------------------------

			// clear du tableau ExistenceDoublet
			for(int k = 0; k < NBR_SOURCE_GLOBALE; k++)
				for(int i = 0; i < project_s_msgs::ObstacleFusionReport::OBSTACLE_FUSION_REPORT_SIZE; i++)
					for(int p = 0; p < NBR_SOURCE_GLOBALE; p++)
						tableauAssociationGlobale.ExistenceDoublet[k][i].idPiste[p] = 0xFFFF;

			// init du tableau ExistenceDoublet
			for(int k = 0; k < NBR_SOURCE_GLOBALE; k++)
				for(int i = 0; i < ptrSourceGlobale[k]->QtyObstacles.data; i++)
					tableauAssociationGlobale.ExistenceDoublet[k][i].idPiste[k] = i;

			//#define SEUIL_FUSION		2		// unity = meter (distance arithmetique)
			#define SEUIL_FUSION		9		// unity = sans dimension (distance Mhalanobis),
									// pour chaque composante (x, y, vx) on prend seuil = 3 sigma.
			#define INVALID_VALUE		-1		// mettre une valeur < 0

			// recherche doublet
			bool fl_doublet_detected;	// initialisé au début de la boucle do{}

			do{
				// recherche de la distancepistelocale minimale dans la sous-matrice (k;p)
				int iMin;
				int jMin;
				float distanceMin = INVALID_VALUE;	// distance par défaut en attendant la première mise à jour
				fl_doublet_detected = false;

				for(int i = 0; i < reportObstacleFusion.QtyObstacles.data; i++){
					for(int j = 0; j < predictionPisteGlobale.QtyObstacles.data; j++){
						float distance = tableauAssociationGlobale.distancepisteglobale[i][j];
						if(distance != INVALID_VALUE){
							if((distanceMin == INVALID_VALUE) || (distanceMin > distance)){
								iMin = i;
								jMin = j;
								distanceMin = distance;
							}
						}
					}
				}

				// test si la distancepistelocale minimale remplit les conditions d'un doublet
				if((distanceMin != INVALID_VALUE) && (distanceMin <= SEUIL_FUSION)){
					// c'est un doublet
					fl_doublet_detected = true;

					// RAZ au tableau de la colone jMin et de la ligne iMin
					for(int i = 0; i < reportObstacleFusion.QtyObstacles.data; i++)
						tableauAssociationGlobale.distancepisteglobale[i][jMin] = INVALID_VALUE;
					for(int j = 0; j < predictionPisteGlobale.QtyObstacles.data; j++)
						tableauAssociationGlobale.distancepisteglobale[iMin][j] = INVALID_VALUE;

					//on mémorise que les pistes globales (ID_PISTE_GLOBALE;iMin) et (ID_PREDICTION_GLOBALE;jMin) sont associées
					tableauAssociationGlobale.ExistenceDoublet[ID_PISTE_GLOBALE][iMin].idPiste[ID_PISTE_GLOBALE] = iMin;		// déjà initialisé
					tableauAssociationGlobale.ExistenceDoublet[ID_PISTE_GLOBALE][iMin].idPiste[ID_PREDICTION_GLOBALE] = jMin;
					tableauAssociationGlobale.ExistenceDoublet[ID_PREDICTION_GLOBALE][jMin].idPiste[ID_PISTE_GLOBALE] = iMin;
					tableauAssociationGlobale.ExistenceDoublet[ID_PREDICTION_GLOBALE][jMin].idPiste[ID_PREDICTION_GLOBALE] = jMin;	// déjà initialisé
				}
			}while(fl_doublet_detected);

//-------------------------------------------------------------------------------------------------
// 			fusion globale
//-------------------------------------------------------------------------------------------------

			// RAZ de la variable de Piste Globale
			reportObstacleFusionGlobale        = project_s_msgs::ObstacleFusionReport();
			reportObstacleFusionGlobale.header = reportObstacleFusion.header;
			reportObstacleFusionGlobale.id     = reportObstacleFusion.id;
			reportObstacleFusionGlobale.odom   = reportObstacleFusion.odom;

			uint id = 0;

			for(int k = 0; k < NBR_SOURCE_GLOBALE; k++){
				for(int i = 0; i < ptrSourceGlobale[k]->QtyObstacles.data; i++){
					bool fl_object_detected = false;
					int idPiste[NBR_SOURCE_GLOBALE];

					for(int p = 0; p < NBR_SOURCE_GLOBALE; p++){
						int j;
						j = idPiste[p] = tableauAssociationGlobale.ExistenceDoublet[k][i].idPiste[p];

						if(j != 0xFFFF){
							fl_object_detected = true;	// ce peut être un objet nouveau/associé/ancien

							// RAZ du tableau d'association -> piste(s) associée(s) du deuxième capteur
							if(p!=k){
								for(int l = 0; l < NBR_SOURCE_GLOBALE; l++)
									tableauAssociationGlobale.ExistenceDoublet[p][j].idPiste[l] = 0xFFFF;
							}
						}

						// RAZ du tableau d'association -> piste du premier capteur
						tableauAssociationGlobale.ExistenceDoublet[k][i].idPiste[p] = 0xFFFF;
					}

					if((fl_object_detected) && (id < project_s_msgs::ObstacleFusionReport::OBSTACLE_FUSION_REPORT_SIZE)){
						// on prend comme référence le capteur n°k
						reportObstacleFusionGlobale.ObstacleFusion[id].header = ptrSourceGlobale[k]->ObstacleFusion[i].header;

						// gestion de l'id :
						if(k == ID_PREDICTION_GLOBALE){
							reportObstacleFusionGlobale.ObstacleFusion[id].id.data = ptrSourceGlobale[k]->ObstacleFusion[i].id.data;
						}
						else{
							// recherche du 1er id de libre, supérieur à id_last, et on reboucle par 1
							bool recommence;
							unsigned char id_next = id_last;							
							do{
								recommence = false;
								if(++id_next == 0) id_next = 1;
								for(int j = 0; j < id; j++){
									if(reportObstacleFusionGlobale.ObstacleFusion[j].id.data == id_next)
										recommence = true;
								}
							}while(recommence);
							reportObstacleFusionGlobale.ObstacleFusion[id].id.data = id_last = id_next;
						}

						// màj de idPiste
						for(int p = 0; p < NBR_SOURCE_GLOBALE; p++){
							reportObstacleFusionGlobale.ObstacleFusion[id].idPiste[p].data = idPiste[p];
						}
						reportObstacleFusionGlobale.ObstacleFusion[id].idPiste[2].data = 0xFFFF;

						id++;
					}
				}
			}

			reportObstacleFusionGlobale.QtyObstacles.data = id;

//-------------------------------------------------------------------------------------------------
//			publication
//-------------------------------------------------------------------------------------------------

			reportObstacleFusionComplet.reportObstacleFusion        = reportObstacleFusion;
			reportObstacleFusionComplet.predictionPisteGlobale      = predictionPisteGlobale;
			reportObstacleFusionComplet.reportObstacleFusionGlobale = reportObstacleFusionGlobale;
			pub_global_tracks_association.publish(reportObstacleFusionComplet);
			}
		}

		loop_rate.sleep();
	}

	return 0;
}
