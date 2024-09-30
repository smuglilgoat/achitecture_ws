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

//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------
// à compléter si d'autres capteurs
#define NBR_SENSOR		3	// 3 capteurs (Lidar, Radar, Camera), x 10 pistes locales max
#define ID_LIDAR		0
#define ID_RADAR		1
#define ID_CAMERA_ME		2

// construction d'une matrice avec toutes les pistes locales
struct struct_tableauAssociation{
	float distancepistelocale[NBR_SENSOR*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE][NBR_SENSOR*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE];
	struct{
		uint idPiste[NBR_SENSOR];
	}ExistenceDoublet[NBR_SENSOR][project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE];
};

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleAlignmentReport*  ptrSensor[NBR_SENSOR];
project_s_msgs::ObstacleSynchronizeReport ptrSensor_;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport             reportObstacleFusion;
project_s_msgs::ObstacleSynchronizeReportComplet ObstacleSynchronizeReportComplet;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedLocalTracksSynchro = false;
void localTracksSynchroCallback(const project_s_msgs::ObstacleSynchronizeReport::ConstPtr& ObstacleArray)
{
	ptrSensor_ = *ObstacleArray;

	receivedLocalTracksSynchro = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("local_tracks_association"));

	ros::NodeHandle n;

	ros::Publisher pub_local_tracks_association = n.advertise<project_s_msgs::ObstacleSynchronizeReportComplet>(std::string("/local_tracks_association_data"), 1);

	ros::Subscriber sub_local_tracks_synchro = n.subscribe(std::string("/local_tracks_synchro_data"), 1, localTracksSynchroCallback);

	ros::Rate loop_rate(100);

	// à compléter si d'autres capteurs
	ptrSensor[ID_LIDAR]     = &ptrSensor_.ObstacleSynchronizeReport[ID_LIDAR];
	ptrSensor[ID_RADAR]     = &ptrSensor_.ObstacleSynchronizeReport[ID_RADAR];
	ptrSensor[ID_CAMERA_ME] = &ptrSensor_.ObstacleSynchronizeReport[ID_CAMERA_ME];

	while(n.ok())
	{
		ros::spinOnce();

		if (receivedLocalTracksSynchro)
		{
			receivedLocalTracksSynchro = false;

			reportObstacleFusion        = project_s_msgs::ObstacleFusionReport();

			// on prend le report des pistes locales synchronisées comme référence de la fusion
			reportObstacleFusion.header = ptrSensor_.header;
			reportObstacleFusion.id     = ptrSensor_.id;
			reportObstacleFusion.odom   = ptrSensor_.odom;

//-------------------------------------------------------------------------------------------------
// 			calcul distances
//-------------------------------------------------------------------------------------------------

			struct_tableauAssociation tableauAssociation;

			// clear du tableau distancepistelocale
			for(int k = 0; k < NBR_SENSOR; k++){
				for(int i = 0; i < project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE; i++){
					for(int p = 0; p < NBR_SENSOR; p++){
						for(int j = 0; j < project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE; j++){
							tableauAssociation.distancepistelocale[k*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE + i]
											      [p*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE + j] = 0;
						}
					}
				}
			}

			// remplissage tableau distancepistelocale
			for(int k = 0;   k < NBR_SENSOR; k++){		// k < NBR_SENSOR-1 pas besoin, car de toute façon ne passera pas le test suivant sur p
				for(int p = k+1; p < NBR_SENSOR; p++){
					for(int i = 0; i < ptrSensor[k]->QtyObstacles.data; i++){
						for(int j = 0; j < ptrSensor[p]->QtyObstacles.data; j++){
							geometry_msgs::Point pt, pt_sigma;
							geometry_msgs::Vector3 velocity, velocity_sigma;
							float distance;

/*							// calcul distance arithmétique
							pt.x = ptrSensor[k]->ObstacleAlignement[i].obstaclePosition.position.x - ptrSensor[p]->ObstacleAlignement[j].obstaclePosition.position.x;
							pt.y = ptrSensor[k]->ObstacleAlignement[i].obstaclePosition.position.y - ptrSensor[p]->ObstacleAlignement[j].obstaclePosition.position.y;
							//pt.z = ptrSensor[k]->ObstacleAlignement[i].obstaclePosition.position.z - ptrSensor[p]->ObstacleAlignement[j].obstaclePosition.position.z;

							distance = std::pow(pt.x,2) + std::pow(pt.y,2);

												// on peut se passer de la racine carrée,
							distance = std::sqrt(distance);	// sinon version avec la racine carrée.
*/
							// calcul distance Mahalanobis
							pt.x = ptrSensor[k]->ObstacleAlignement[i].obstaclePosition.position.x - ptrSensor[p]->ObstacleAlignement[j].obstaclePosition.position.x;
							pt.y = ptrSensor[k]->ObstacleAlignement[i].obstaclePosition.position.y - ptrSensor[p]->ObstacleAlignement[j].obstaclePosition.position.y;
							//pt.z = ptrSensor[k]->ObstacleAlignement[i].obstaclePosition.position.z - ptrSensor[p]->ObstacleAlignement[j].obstaclePosition.position.z;

							pt_sigma.x = sqrt(ptrSensor[k]->ObstacleAlignement[i].obstaclePoseVariance.position.x) +
							               sqrt(ptrSensor[p]->ObstacleAlignement[j].obstaclePoseVariance.position.x);
							pt_sigma.y = sqrt(ptrSensor[k]->ObstacleAlignement[i].obstaclePoseVariance.position.y) +
							               sqrt(ptrSensor[p]->ObstacleAlignement[j].obstaclePoseVariance.position.y);
							/*pt_sigma.z = sqrt(ptrSensor[k]->ObstacleAlignement[i].obstaclePoseVariance.position.z) +
							               sqrt(ptrSensor[p]->ObstacleAlignement[j].obstaclePoseVariance.position.z);*/
							if(pt_sigma.x == 0) pt_sigma.x = 1; if(pt_sigma.y == 0) pt_sigma.y = 1; if(pt_sigma.z == 0) pt_sigma.z = 1;

							distance  = std::pow(pt.x,2) / std::pow(pt_sigma.x,2);
							distance += std::pow(pt.y,2) / std::pow(pt_sigma.y,2);
							//distance += std::pow(pt.z,2) / std::pow(pt_sigma.z,2);

							velocity.x = ptrSensor[k]->ObstacleAlignement[i].obstacleVelocity.linear.x - ptrSensor[p]->ObstacleAlignement[j].obstacleVelocity.linear.x;
							//velocity.y = ptrSensor[k]->ObstacleAlignement[i].obstacleVelocity.linear.y - ptrSensor[p]->ObstacleAlignement[j].obstacleVelocity.linear.y;
							//velocity.z = ptrSensor[k]->ObstacleAlignement[i].obstacleVelocity.linear.z - ptrSensor[p]->ObstacleAlignement[j].obstacleVelocity.linear.z;

							velocity_sigma.x = sqrt(ptrSensor[k]->ObstacleAlignement[i].obstacleVelocityVariance.linear.x) +
							                     sqrt(ptrSensor[p]->ObstacleAlignement[j].obstacleVelocityVariance.linear.x);
							/*velocity_sigma.y = sqrt(ptrSensor[k]->ObstacleAlignement[i].obstacleVelocityVariance.linear.y) +
							                     sqrt(ptrSensor[p]->ObstacleAlignement[j].obstacleVelocityVariance.linear.y);
							velocity_sigma.z = sqrt(ptrSensor[k]->ObstacleAlignement[i].obstacleVelocityVariance.linear.z) +
							                     sqrt(ptrSensor[p]->ObstacleAlignement[j].obstacleVelocityVariance.linear.z);*/
							if(velocity_sigma.x == 0) velocity_sigma.x = 1; if(velocity_sigma.y == 0) velocity_sigma.y = 1;
							if(velocity_sigma.z == 0) velocity_sigma.z = 1;

							distance += std::pow(velocity.x,2) / std::pow(velocity_sigma.x,2);
							//distance += std::pow(velocity.y,2) / std::pow(velocity_sigma.y,2);
							//distance += std::pow(velocity.z,2) / std::pow(velocity_sigma.z,2);

											// on peut se passer de la racine carrée,
							distance = std::sqrt(distance);	// sinon version avec la racine carrée.

							tableauAssociation.distancepistelocale[k*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE + i]
											      [p*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE + j] = distance;
						}
					}
				}
			}

//-------------------------------------------------------------------------------------------------
// 			association locale
//-------------------------------------------------------------------------------------------------

			// clear du tableau ExistenceDoublet
			for(int k = 0; k < NBR_SENSOR; k++){
				for(int i = 0; i < project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE; i++){
					for(int p = 0; p < NBR_SENSOR; p++){
						tableauAssociation.ExistenceDoublet[k][i].idPiste[p] = 0xFFFF;
					}
				}
			}

			// init du tableau ExistenceDoublet
			for(int k = 0; k < NBR_SENSOR; k++){
				for(int i = 0; i < (int)ptrSensor[k]->QtyObstacles.data; i++){
					tableauAssociation.ExistenceDoublet[k][i].idPiste[k] = i;
				}
			}

			//#define SEUIL_FUSION		4		// unity = meter (distance arithmetique)
			#define SEUIL_FUSION		9		// unity = sans dimension (distance Mhalanobis),
									// pour chaque composante (x, y, vx) on prend seuil = 3 sigma.
			#define INVALID_VALUE		-1		// mettre une valeur < 0

			// recherche doublet
			for(int k = 0; k < NBR_SENSOR; k++){
				for(int p = k+1; p < NBR_SENSOR; p++){
					bool fl_doublet_detected;	// initialisé au début de la boucle do{}

					do{
						// recherche de la distancepistelocale minimale dans la sous-matrice (k;p)
						int iMin;
						int jMin;
						float distanceMin = INVALID_VALUE;	// distance par défaut en attendant la première mise à jour
						fl_doublet_detected = false;

						for(int i = 0; i < ptrSensor[k]->QtyObstacles.data; i++){
							for(int j = 0; j < ptrSensor[p]->QtyObstacles.data; j++){
								float distance = tableauAssociation.distancepistelocale[k*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE + i]
														       [p*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE + j];
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

							// RAZ au tableau (k;p) de la colonne jMin et de la ligne iMin
							for(int i = 0; i < ptrSensor[k]->QtyObstacles.data; i++)
								tableauAssociation.distancepistelocale[k*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE + i]
												      [p*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE + jMin] = INVALID_VALUE;
							for(int j = 0; j < ptrSensor[p]->QtyObstacles.data; j++)
								tableauAssociation.distancepistelocale[k*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE + iMin]
												      [p*project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE + j] = INVALID_VALUE;

							//on mémorise que les pistes locales (k;iMin) et (p;jMin) sont associées
							tableauAssociation.ExistenceDoublet[k][iMin].idPiste[k] = iMin;	// déjà initialisé
							tableauAssociation.ExistenceDoublet[k][iMin].idPiste[p] = jMin;
							tableauAssociation.ExistenceDoublet[p][jMin].idPiste[k] = iMin;
							tableauAssociation.ExistenceDoublet[p][jMin].idPiste[p] = jMin;	// déjà initialisé
						}
					}while(fl_doublet_detected);
				}
			}

//-------------------------------------------------------------------------------------------------
// 			création de Groupes associés
//-------------------------------------------------------------------------------------------------

			uint id = 0;

			for(int k = 0; k < NBR_SENSOR; k++){
				for(int i = 0; i < (int)ptrSensor[k]->QtyObstacles.data; i++){
					bool fl_object_detected = false;
					uint idPiste[NBR_SENSOR];

					for(int p = 0; p < NBR_SENSOR; p++){
						uint j;
						j = idPiste[p] = tableauAssociation.ExistenceDoublet[k][i].idPiste[p];

						// RAZ du tableau d'association	-> piste(s) du premier capteur
						tableauAssociation.ExistenceDoublet[k][i].idPiste[p] = 0xFFFF;

						if(j != 0xFFFF){
							fl_object_detected = true;	// ce peut être un singlet, ou un doublet, ou un triplet, ...

							//			-> piste(s) du deuxième capteur :
							// -> soit la solution de RAZ toutes les pistes,
							if(p!=k){
								for(int l = 0; l < NBR_SENSOR; l++)
									tableauAssociation.ExistenceDoublet[p][j].idPiste[l] = 0xFFFF;
							}

							// -> soit la solution de RAZ seulement les 2 pistes déjà associées.
							//tableauAssociation.ExistenceDoublet[p][j].idPiste[k] = 0xFFFF;
							//tableauAssociation.ExistenceDoublet[p][j].idPiste[p] = 0xFFFF;
						}
					}

					if((fl_object_detected) && (id < project_s_msgs::ObstacleFusionReport::OBSTACLE_FUSION_REPORT_SIZE)){
						// on prend comme référence le capteur n°k
						reportObstacleFusion.ObstacleFusion[id].header  = ptrSensor[k]->ObstacleAlignement[i].header;
						reportObstacleFusion.ObstacleFusion[id].id.data = id;

						// on re-force la piste i du capteur k, qui a pu être RAZ auparavant
						idPiste[k] = i;

						for(int p = 0; p < NBR_SENSOR; p++){
							// vérifier dans ObstacleFusion.msg que idPiste est un tableau de dimension NBR_SENSOR
							reportObstacleFusion.ObstacleFusion[id].idPiste[p].data = idPiste[p];
						}

						id++;
					}
				}
			}

			reportObstacleFusion.QtyObstacles.data = id;

//-------------------------------------------------------------------------------------------------
//			publication
//-------------------------------------------------------------------------------------------------

			ObstacleSynchronizeReportComplet.ObstacleFusionReport      = reportObstacleFusion;
			ObstacleSynchronizeReportComplet.ObstacleSynchronizeReport = ptrSensor_;
			pub_local_tracks_association.publish(ObstacleSynchronizeReportComplet);
		}

		loop_rate.sleep();		
	}

	return 0;
}

