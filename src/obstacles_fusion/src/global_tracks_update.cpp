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
#include "project_s_msgs/GenericSmartData.h"

//-------------------------------------------------------------------------------------------------
// local data
//-------------------------------------------------------------------------------------------------

// ----- Global Fusion -----
//#include <X11/Xlib.h>		// déjà fait dans CImg.h
//#include <math.h>
#define cimg_display 0		// forcer cette variable, sinon error de compil liée à X11 Window
#include "obstacles_fusion/CImg.h"
using namespace cimg_library;

// à compléter si d'autres capteurs
#define NBR_SENSOR		3	// 3 capteurs (Lidar, Radar, Camera)

#define NBR_SOURCE_GLOBALE	2	// 2 sources de piste globale (fusion locale, prédiction) 
#define ID_PREDICTION_GLOBALE	0
#define ID_PISTE_LOCALE		1

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReportComplet reportObstacleFusionComplet;
project_s_msgs::ObstacleFusionReport reportObstacleFusion;
project_s_msgs::ObstacleFusionReport predictionPisteGlobale;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport reportObstacleFusionGlobale;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedGlobalTracksAssociation = false;
void globalTracksAssociationCallback(const project_s_msgs::ObstacleFusionReportComplet::ConstPtr& genericObstacleFusion)
{
	reportObstacleFusionComplet = *genericObstacleFusion;

	reportObstacleFusion        = reportObstacleFusionComplet.reportObstacleFusion;
	predictionPisteGlobale      = reportObstacleFusionComplet.predictionPisteGlobale;
	reportObstacleFusionGlobale = reportObstacleFusionComplet.reportObstacleFusionGlobale;

	receivedGlobalTracksAssociation = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("global_tracks_update"));

	ros::NodeHandle n;

	ros::Publisher pub_global_tracks_update = n.advertise<project_s_msgs::ObstacleFusionReport>(std::string("/global_tracks_update_data"), 1);

	ros::Subscriber sub_global_tracks_association = n.subscribe(std::string("/global_tracks_association_data"), 1, globalTracksAssociationCallback);

	ros::Rate loop_rate(100);

	while(n.ok())
	{
		ros::spinOnce();

		if (receivedGlobalTracksAssociation)
		{
			receivedGlobalTracksAssociation = false;

//-------------------------------------------------------------------------------------------------
// 			fusion globale
//-------------------------------------------------------------------------------------------------

			for(int id = 0; id < reportObstacleFusionGlobale.QtyObstacles.data; id++){
				CImg<double> gObjP(4,4,1,1,0), gObjX(1,4,1,1,0), sObjP(4,4,1,1,0), sObjX(1,4,1,1,0);	// gObj... = Global Objet
															// sObj... = Super Observateur
															// ....X   = vecteur d'état
															// ....P   = matrice de covariance
				// pas nécessaire car RAZ lors de la déclaration
				gObjP(0,0) = gObjP(0,1) = gObjP(0,2) = gObjP(0,3) = 0;
				gObjP(1,0) = gObjP(1,1) = gObjP(1,2) = gObjP(1,3) = 0;
				gObjP(2,0) = gObjP(2,1) = gObjP(2,2) = gObjP(2,3) = 0;
				gObjP(3,0) = gObjP(3,1) = gObjP(3,2) = gObjP(3,3) = 0;

				gObjX(0,0) = gObjX(0,1) = gObjX(0,2) = gObjX(0,3) = 0;

				sObjP(0,0) = sObjP(0,1) = sObjP(0,2) = sObjP(0,3) = 0;
				sObjP(1,0) = sObjP(1,1) = sObjP(1,2) = sObjP(1,3) = 0;
				sObjP(2,0) = sObjP(2,1) = sObjP(2,2) = sObjP(2,3) = 0;
				sObjP(3,0) = sObjP(3,1) = sObjP(3,2) = sObjP(3,3) = 0;

				sObjX(0,0) = sObjX(0,1) = sObjX(0,2) = sObjX(0,3) = 0;

				CImg<double> K(4,4);	// gain du filtre

				CImg<double> Q(4,4,1,1,0);
				Q(0,0)=Q(0,1)=Q(0,2)=Q(0,3)=0;
				Q(1,0)=Q(1,1)=Q(1,2)=Q(1,3)=0;
				Q(2,0)=Q(2,1)=Q(2,2)=Q(2,3)=0;
				Q(3,0)=Q(3,1)=Q(3,2)=Q(3,3)=0;
				Q(0,0)=0.25; Q(1,1)=0.01; Q(2,2)=1; Q(3,3)=0.25;	// d'où viennent ces valeurs, récupérées du code d'Adam ???

				int id_piste_prediction = reportObstacleFusionGlobale.ObstacleFusion[id].idPiste[ID_PREDICTION_GLOBALE].data;
				int id_piste_locale     = reportObstacleFusionGlobale.ObstacleFusion[id].idPiste[ID_PISTE_LOCALE].data;
				int id_piste_globale    = reportObstacleFusionGlobale.ObstacleFusion[id].id.data;

				if((id_piste_prediction == 0xFFFF) && (id_piste_locale == 0xFFFF)){
					// Error
					continue;
				}

				if(id_piste_prediction == 0xFFFF){
					// nouvel objet, pas associé à une piste globale

					reportObstacleFusionGlobale.ObstacleFusion[id] = reportObstacleFusion.ObstacleFusion[id_piste_locale];
				}
				else if(id_piste_locale == 0xFFFF){
					// ancien objet, pas associé à une piste locale

					reportObstacleFusionGlobale.ObstacleFusion[id] = predictionPisteGlobale.ObstacleFusion[id_piste_prediction];
				}
				else{
					// objet en cours

					// par défaut, on reprend les caractéristiques de la piste locale (accélération, dimensions, cap, classification, ...)
					reportObstacleFusionGlobale.ObstacleFusion[id] = reportObstacleFusion.ObstacleFusion[id_piste_locale];

					gObjP(0,0) = predictionPisteGlobale.ObstacleFusion[id_piste_prediction].obstaclePoseVariance.position.x;
					gObjP(1,1) = predictionPisteGlobale.ObstacleFusion[id_piste_prediction].obstaclePoseVariance.position.y;
					gObjP(2,2) = predictionPisteGlobale.ObstacleFusion[id_piste_prediction].obstacleVelocityVariance.linear.x;
					gObjP(3,3) = predictionPisteGlobale.ObstacleFusion[id_piste_prediction].obstacleVelocityVariance.linear.y;

					gObjX(0,0) = predictionPisteGlobale.ObstacleFusion[id_piste_prediction].obstaclePosition.position.x;
					gObjX(0,1) = predictionPisteGlobale.ObstacleFusion[id_piste_prediction].obstaclePosition.position.y;
					gObjX(0,2) = predictionPisteGlobale.ObstacleFusion[id_piste_prediction].obstacleVelocity.linear.x;
					gObjX(0,3) = predictionPisteGlobale.ObstacleFusion[id_piste_prediction].obstacleVelocity.linear.y;

					sObjP(0,0) = reportObstacleFusion.ObstacleFusion[id_piste_locale].obstaclePoseVariance.position.x;
					sObjP(1,1) = reportObstacleFusion.ObstacleFusion[id_piste_locale].obstaclePoseVariance.position.y;
					sObjP(2,2) = reportObstacleFusion.ObstacleFusion[id_piste_locale].obstacleVelocityVariance.linear.x;
					sObjP(3,3) = reportObstacleFusion.ObstacleFusion[id_piste_locale].obstacleVelocityVariance.linear.y;

					sObjX(0,0) = reportObstacleFusion.ObstacleFusion[id_piste_locale].obstaclePosition.position.x;
					sObjX(0,1) = reportObstacleFusion.ObstacleFusion[id_piste_locale].obstaclePosition.position.y;
					sObjX(0,2) = reportObstacleFusion.ObstacleFusion[id_piste_locale].obstacleVelocity.linear.x;
					sObjX(0,3) = reportObstacleFusion.ObstacleFusion[id_piste_locale].obstacleVelocity.linear.y;

					// prédiction de la matrice de covariance de la Piste Globale
					gObjP = gObjP + Q;

					// calcul du gain du filtre de Kalman
					K = gObjP * (gObjP + sObjP).get_invert();

					// calcul du vecteur d'état de la Piste Globale
					gObjX = gObjX + K * (sObjX - gObjX);

					reportObstacleFusionGlobale.ObstacleFusion[id].obstaclePosition.position.x = gObjX(0,0);
					reportObstacleFusionGlobale.ObstacleFusion[id].obstaclePosition.position.y = gObjX(0,1);
					reportObstacleFusionGlobale.ObstacleFusion[id].obstacleVelocity.linear.x   = gObjX(0,2);
					reportObstacleFusionGlobale.ObstacleFusion[id].obstacleVelocity.linear.y   = gObjX(0,3);

					CImg<double> I(4,4);	// matrice identité 4 x 4
					I.identity_matrix();

					// calcul de la matrice de covariance de la Piste Globale
					gObjP = (I-K) * gObjP * (I-K).get_transpose() + K * sObjP * K.get_transpose();

					reportObstacleFusionGlobale.ObstacleFusion[id].obstaclePoseVariance.position.x   = gObjP(0,0);
					reportObstacleFusionGlobale.ObstacleFusion[id].obstaclePoseVariance.position.y   = gObjP(1,1);
					reportObstacleFusionGlobale.ObstacleFusion[id].obstacleVelocityVariance.linear.x = gObjP(2,2);
					reportObstacleFusionGlobale.ObstacleFusion[id].obstacleVelocityVariance.linear.y = gObjP(3,3);
				}

				// regarding Confidence Management
				if(id_piste_prediction != 0xFFFF){
					// détection déjà vu dans Prediction
					reportObstacleFusionGlobale.ObstacleFusion[id].existenceState.data = predictionPisteGlobale.ObstacleFusion[id_piste_prediction].existenceState.data;

					reportObstacleFusionGlobale.ObstacleFusion[id].nbrUpdate.data      = predictionPisteGlobale.ObstacleFusion[id_piste_prediction].nbrUpdate.data;
					reportObstacleFusionGlobale.ObstacleFusion[id].nbrAge.data         = predictionPisteGlobale.ObstacleFusion[id_piste_prediction].nbrAge.data;
				}
				else{
					// première détection
					reportObstacleFusionGlobale.ObstacleFusion[id].existenceState.data = project_s_msgs::ObstacleFusion::IDLE_TRACK;

					reportObstacleFusionGlobale.ObstacleFusion[id].nbrUpdate.data      = 0;
					reportObstacleFusionGlobale.ObstacleFusion[id].nbrAge.data         = 0;
				}

				if(id_piste_locale != 0xFFFF){
					// détection vu par PISTE_GLOBALE
					reportObstacleFusionGlobale.ObstacleFusion[id].nbrUpdate.data    += 1.0;
				//	reportObstacleFusionGlobale.ObstacleFusion[id].nbrAge.data        = 

					reportObstacleFusionGlobale.ObstacleFusion[id].nbrDetection.data  = reportObstacleFusion.ObstacleFusion[id_piste_locale].nbrDetection.data;
					reportObstacleFusionGlobale.ObstacleFusion[id].nbrVisibility.data = reportObstacleFusion.ObstacleFusion[id_piste_locale].nbrVisibility.data;
				}
				else{
					reportObstacleFusionGlobale.ObstacleFusion[id].nbrUpdate.data    -= 1.0;
				//	reportObstacleFusionGlobale.ObstacleFusion[id].nbrAge.data        = 

					reportObstacleFusionGlobale.ObstacleFusion[id].nbrDetection.data  = 0;
					reportObstacleFusionGlobale.ObstacleFusion[id].nbrVisibility.data = 0;
				}
				reportObstacleFusionGlobale.ObstacleFusion[id].nbrAge.data += 1.0;

				// on limite nbrUpdate et nbrAge
				if(reportObstacleFusionGlobale.ObstacleFusion[id].nbrUpdate.data > 10.0)
					reportObstacleFusionGlobale.ObstacleFusion[id].nbrUpdate.data = 10.0;
				if(reportObstacleFusionGlobale.ObstacleFusion[id].nbrUpdate.data < 0.0)
					reportObstacleFusionGlobale.ObstacleFusion[id].nbrUpdate.data = 0.0;
				if(reportObstacleFusionGlobale.ObstacleFusion[id].nbrAge.data > 10.0)
					reportObstacleFusionGlobale.ObstacleFusion[id].nbrAge.data = 10.0;

				// soit : on remet dans ObstacleFusion[].idPiste[] les indices des pistes locales qui ont servi (éventuellement) à l'association locale,
				/*if(id_piste_locale != 0xFFFF){
					for (int m = 0; m < NBR_SENSOR; m++)
						reportObstacleFusionGlobale.ObstacleFusion[id].idPiste[m] = reportObstacleFusion.ObstacleFusion[id_piste_locale].idPiste[m];
				}
				else{
					for (int m = 0; m < NBR_SENSOR; m++)
						reportObstacleFusionGlobale.ObstacleFusion[id].idPiste[m].data = 0xFFFF;
				}*/
				// soit : on remet dans ObstacleFusion[].idPiste[] les indices des pistes globales & locales qui ont servi à l'association globale.
				reportObstacleFusionGlobale.ObstacleFusion[id].idPiste[ID_PREDICTION_GLOBALE].data = id_piste_prediction;
				reportObstacleFusionGlobale.ObstacleFusion[id].idPiste[ID_PISTE_LOCALE].data       = id_piste_locale;
				reportObstacleFusionGlobale.ObstacleFusion[id].idPiste[2].data                     = 0xFFFF;

				reportObstacleFusionGlobale.ObstacleFusion[id].id.data = id_piste_globale;
			}

//-------------------------------------------------------------------------------------------------
//			publication
//-------------------------------------------------------------------------------------------------

			pub_global_tracks_update.publish(reportObstacleFusionGlobale);
		}

		loop_rate.sleep();		
	}

	return 0;
}
