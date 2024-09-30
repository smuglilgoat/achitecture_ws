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
#include "std_msgs/Float64.h" 

#include "ros/ros.h"

#include "project_s_msgs/Configurations.h"
#include "project_s_msgs/ObstacleFusionReport.h"
#include "project_s_msgs/LaneFusion.h"
#include "project_s_msgs/ElectronicHorizon.h"
#include "project_s_msgs/ElectronicHorizonArray.h"
#include "project_s_msgs/ElectronicHorizonReport.h"
#include "project_s_msgs/RoadModel.h"

#include "project_s_msgs/FineMapMatching.h"

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport obstacle_assignement;
project_s_msgs::LaneFusion lines_update;
project_s_msgs::ElectronicHorizon electronicHorizon;
project_s_msgs::ElectronicHorizonArray electronicHorizonArray;
project_s_msgs::ElectronicHorizonReport electronic_Horizon_Report;
project_s_msgs::ElectronicHorizonArray electronic_Horizon_Array;
project_s_msgs::RoadModel roadModel;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::FineMapMatching fine_map_matching;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool obstacleAssignmentReceived = false;
void obstaclesAssignmentdataCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& buffer)
{
	obstacle_assignement = *buffer;

	obstacleAssignmentReceived = true;
}

bool linesUpdateReceived = false;
void linesUpdateCallback(const project_s_msgs::LaneFusion::ConstPtr& buffer)
{
	lines_update = *buffer;

	linesUpdateReceived = true;
}

bool electronicHorizonReceived = false;
void electronicHorizonCallback(const project_s_msgs::ElectronicHorizonReport::ConstPtr& buffer)
{
	electronic_Horizon_Report = *buffer;

	electronicHorizonReceived = true;
}

bool electronicHorizonArrayReceived = false;
void electronicHorizonArrayCallback(const project_s_msgs::ElectronicHorizonArray::ConstPtr& buffer)
{
	electronic_Horizon_Array = *buffer;

	electronicHorizonArrayReceived = true;
}

bool roadModelReceived = false;
void roadModelCallback(const project_s_msgs::RoadModel::ConstPtr& ptrRoadModel)
{
  roadModel = *ptrRoadModel;

  roadModelReceived = true;
}

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
project_s_msgs::ehSpotCoordGeo CalculateGlobalePosition(project_s_msgs::ehSpotCoordGeo Spot[], uint NbrSpot, std_msgs::Float32 offset)
{	// renvoie latitude & longitude à un offset donné,		
	// par interpolation suivant un tableau qui doit couvrir cet offset.
	project_s_msgs::ehSpotCoordGeo GlobalePosition;
	uint i;

	for(i = 0; i < NbrSpot-1; i++){
		if((Spot[i].offset.data <= offset.data) && (offset.data <= Spot[i+1].offset.data)){
			break;
		}
	}

	if(i < NbrSpot-1){
		GlobalePosition.offset.data = offset.data;

		GlobalePosition.latitude  = Spot[i+1].latitude - Spot[i].latitude;
		GlobalePosition.latitude /= Spot[i+1].offset.data   - Spot[i].offset.data;
		GlobalePosition.latitude *= offset.data             - Spot[i].offset.data;

		GlobalePosition.longitude  = Spot[i+1].longitude - Spot[i].longitude;
		GlobalePosition.longitude /= Spot[i+1].offset.data    - Spot[i].offset.data;
		GlobalePosition.longitude *= offset.data              - Spot[i].offset.data;
	}

	return GlobalePosition;
}

#include<iomanip>
#include<cmath>
using namespace std;
//int polynomial_fit()
int polynomial_fit(int N, double x[], double y[], double coeff[3+1])
{
//    int i,j,k,n,N;
int i,j,k;
int n = 3;			// n is the degree of Polynomial 
    cout.precision(4);                        //set precision
    cout.setf(ios::fixed);
//    cout<<"\nEnter the no. of data pairs to be entered:\n";        //To find the size of arrays that will store x,y, and z values
//    cin>>N;
//    double x[N],y[N];
//    cout<<"\nEnter the x-axis values:\n";                //Input x-values
//    for (i=0;i<N;i++)
//        cin>>x[i];
//    cout<<"\nEnter the y-axis values:\n";                //Input y-values
//    for (i=0;i<N;i++)
//        cin>>y[i];
//    cout<<"\nWhat degree of Polynomial do you want to use for the fit?\n";
//    cin>>n;                                // n is the degree of Polynomial 
    double X[2*n+1];                        //Array that will store the values of sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
    for (i=0;i<2*n+1;i++)
    {
        X[i]=0;
        for (j=0;j<N;j++)
            X[i]=X[i]+pow(x[j],i);        //consecutive positions of the array will store N,sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
    }
    double B[n+1][n+2],a[n+1];            //B is the Normal matrix(augmented) that will store the equations, 'a' is for value of the final coefficients
    for (i=0;i<=n;i++)
        for (j=0;j<=n;j++)
            B[i][j]=X[i+j];            //Build the Normal matrix by storing the corresponding coefficients at the right positions except the last column of the matrix
    double Y[n+1];                    //Array to store the values of sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
    for (i=0;i<n+1;i++)
    {    
        Y[i]=0;
        for (j=0;j<N;j++)
        Y[i]=Y[i]+pow(x[j],i)*y[j];        //consecutive positions will store sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^n*yi)
    }
    for (i=0;i<=n;i++)
        B[i][n+1]=Y[i];                //load the values of Y as the last column of B(Normal Matrix but augmented)
    n=n+1;                //n is made n+1 because the Gaussian Elimination part below was for n equations, but here n is the degree of polynomial and for n degree we get n+1 equations
    cout<<"\nThe Normal(Augmented Matrix) is as follows:\n";    
    for (i=0;i<n;i++)            //print the Normal-augmented matrix
    {
        for (j=0;j<=n;j++)
            cout<<B[i][j]<<setw(16);
        cout<<"\n";
    }    
    for (i=0;i<n;i++)                    //From now Gaussian Elimination starts(can be ignored) to solve the set of linear equations (Pivotisation)
        for (k=i+1;k<n;k++)
            if (B[i][i]<B[k][i])
                for (j=0;j<=n;j++)
                {
                    double temp=B[i][j];
                    B[i][j]=B[k][j];
                    B[k][j]=temp;
                }
    
    for (i=0;i<n-1;i++)            //loop to perform the gauss elimination
        for (k=i+1;k<n;k++)
            {
                double t=B[k][i]/B[i][i];
                for (j=0;j<=n;j++)
                    B[k][j]=B[k][j]-t*B[i][j];    //make the elements below the pivot elements equal to zero or elimnate the variables
            }
    for (i=n-1;i>=0;i--)                //back-substitution
    {                        //x is an array whose values correspond to the values of x,y,z..
        a[i]=B[i][n];                //make the variable to be calculated equal to the rhs of the last equation
        for (j=0;j<n;j++)
            if (j!=i)            //then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
                a[i]=a[i]-B[i][j]*a[j];
        a[i]=a[i]/B[i][i];            //now finally divide the rhs by the coefficient of the variable to be calculated
    }
    cout<<"\nThe values of the coefficients are as follows:\n";
    for (i=0;i<n;i++)
        cout<<"x^"<<i<<"="<<a[i]<<endl;            // Print the values of x^0,x^1,x^2,x^3,....    
    cout<<"\nHence the fitted Polynomial is given by:\ny=";
    for (i=0;i<n;i++)
        cout<<" + ("<<a[i]<<")"<<"x^"<<i;
    cout<<"\n";
for(i=0;i<n;i++)
coeff[i] = a[i];
    return 0;
}//output attached as .jpg

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------
//#define LATITUDE_ORIGIN		+48.7965	// centré sur le parking de Segula@Trappes
//#define LONGITUDE_ORIGIN	+ 1.9872
#define RAYON_TERRE		6371000.0
//#define X_ORIGIN		0.0
//#define Y_ORIGIN		0.0

double e_exentricite;
double n_constante;
double rho_0;

void Init_Convertion_Coord_Geo_vers_Carto(void)
{
	double a_demi_grand_axe = RAYON_TERRE; //6378137;
	double f_aplatissement = 1/298.257222101;
	double b_demi_petit_axe;
	b_demi_petit_axe = a_demi_grand_axe * (1 - f_aplatissement);
	//double e_exentricite;
	e_exentricite = sqrt((pow(a_demi_grand_axe,2) - pow(b_demi_petit_axe,2)) / pow(a_demi_grand_axe,2));
	double phi_1 = 44.0/180.0*M_PI;
	double phi_2 = 49.0/180.0*M_PI;

	//calcul de n_constante
	double n_denominateur;

	n_denominateur  = tan(phi_2/2.0 + M_PI/4.0);
	n_denominateur *= pow(1 + e_exentricite*sin(phi_1), e_exentricite/2.0);
	n_denominateur *= pow(1 - e_exentricite*sin(phi_2), e_exentricite/2.0);

	n_constante     = tan(phi_1/2.0 + M_PI/4.0);
	n_constante    *= pow(1 - e_exentricite*sin(phi_1), e_exentricite/2.0);
	n_constante    *= pow(1 + e_exentricite*sin(phi_2), e_exentricite/2.0);

	n_denominateur  = log(n_constante / n_denominateur);

	n_constante  = log(cos(phi_2)/cos(phi_1));
	n_constante += 0.5 * log(1 - pow(e_exentricite*sin(phi_1), 2)) / (1 - pow(e_exentricite*sin(phi_2), 2));

	n_constante /= n_denominateur;

	// calcul de rho_0
	rho_0  = pow((1 - e_exentricite*sin(phi_1)) / (1 + e_exentricite*sin(phi_1)), e_exentricite/2.0);
	rho_0 *= tan(phi_1/2.0 + M_PI/4.0);
	rho_0  = pow(rho_0, n_constante);
	rho_0 *= a_demi_grand_axe*cos(phi_1);
	rho_0 /= n_constante*sqrt(1 - pow(e_exentricite*sin(phi_1), 2));
}

double rho_de_phi(double phi)	// phi en radian
{
	double rho;

	rho  = pow((1 + e_exentricite*sin(phi)) / (1 - e_exentricite*sin(phi)), e_exentricite/2.0);
	rho /= tan(phi/2.0 + M_PI/4.0);
	rho  = pow(rho, n_constante);
	rho *= rho_0;

	return rho;		// rho en mètre
}

geometry_msgs::Point Convertion_Coord_Geo_vers_Carto_(double phi, double lambda)// phi    = latitude,  en degré
{										// lambda = longitude, en degré
	geometry_msgs::Point Coord_Carto;

	Coord_Carto.x =                 + rho_de_phi(phi/180.0*M_PI) * sin(n_constante*lambda/180.0*M_PI);
	Coord_Carto.y = rho_de_phi(0.0) - rho_de_phi(phi/180.0*M_PI) * cos(n_constante*lambda/180.0*M_PI);

	return Coord_Carto;							// x croissant vers l'est
}										// y croissant vers le nord

// Compute relative position
geometry_msgs::Point computeRelativePosition(geometry_msgs::Point ptRef, float theta, geometry_msgs::Point ptFixe)
{	// calculs de la position dans le repère de l'ego,
	// à partir de la position dans le repère absolu.
	geometry_msgs::Point p;

	double c = cos(theta);
	double s = sin(theta);

	p.x =  (ptFixe.x - ptRef.x) * c + (ptFixe.y - ptRef.y) * s;
	p.y = -(ptFixe.x - ptRef.x) * s + (ptFixe.y - ptRef.y) * c;
	p.z =  0;
	return p;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	ros::init(argc, argv, "fine_map_matching");

	ros::NodeHandle n;

	// Publisher
	ros::Publisher pub_fine_map_matching = n.advertise<project_s_msgs::FineMapMatching>(std::string("/fine_map_matching_data"), 1);
	ros::Publisher pub_fine_map_matching_progress = n.advertise<std_msgs::Float64>(std::string("/fine_map_matching_progress"), 1);  // added

	// Subscriber
	ros::Subscriber sub_obstacles_assignment = n.subscribe(std::string("/obstacles_assignment_data"), 1, obstaclesAssignmentdataCallback); 
	ros::Subscriber sub_lines_update         = n.subscribe(std::string("/lines_update_data")        , 1, linesUpdateCallback); 
	ros::Subscriber sub_electronic_horizon   = n.subscribe(std::string("/electronic_horizon_data")  , 1, electronicHorizonCallback); 
	ros::Subscriber sub_electronic_horizon_array	= n.subscribe(std::string("/electronic_horizon_array_data"),	1, electronicHorizonArrayCallback);
	ros::Subscriber roadmodel_sub = n.subscribe(std::string("/road_model_data"), 1, roadModelCallback);


	Init_Convertion_Coord_Geo_vers_Carto();

	int indexMPP_precedent;

	ros::Time current_time, last_time;
	last_time = ros::Time::now();

	ros::Rate loop_rate(10);

	double K;
	double dt = 0.08;
	float  CONSTANTE_TEMPS=	1;
	std_msgs::Float64 amer_matching_progress;  //Added


  	while(n.ok())
	{
		ros::spinOnce();

		current_time = ros::Time::now();

		bool matching_initial = false;
		if(n.hasParam("/matching_initial"))
			n.getParam("/matching_initial", matching_initial);

		//----------
		if(obstacleAssignmentReceived){
			
			printf("obstacleAssignmentReceived %d  \n",obstacleAssignmentReceived);
			obstacleAssignmentReceived = false;

			/*			// Recherche de l'EH le mieux synchronisé
			double tempsREF = (obstacle_assignement.header.stamp).toSec();
			uint iMIN = 0;
			double dtMIN = fabs((electronic_Horizon_Report.ElectronicHorizonArray[iMIN].header.stamp).toSec() - tempsREF);
			electronicHorizonArray = electronic_Horizon_Report.ElectronicHorizonArray[iMIN];

			#define NBR_MAX_EH	5	// en concordance avec ElectronicHorizonReport.msg
			for(uint i = 0; i < NBR_MAX_EH; i++){
				double dt = fabs((electronic_Horizon_Report.ElectronicHorizonArray[i].header.stamp).toSec() - tempsREF);
				if(dt < dtMIN){
					dtMIN = dt;
					iMIN = i;
					electronicHorizonArray = electronic_Horizon_Report.ElectronicHorizonArray[iMIN];
				}
			}

			fine_map_matching.header.stamp = electronicHorizonArray.header.stamp;

			uint i_Spot = 0xFF;
			uint j_Obstacle = 0xFF;
			float spot_distance_min = 200;
			float ecart_spot_obstacle_assoc = 200;

			int indexMPP = electronicHorizonArray.indexMPP.data;
			// pour chaque Traffic Sign déclarés par l'EH
			for(uint i=0; i<electronicHorizonArray.PathsArray[indexMPP].NbrSpotTrafficSign.data; i++){
				float offset_ecart = electronicHorizonArray.PathsArray[indexMPP].ehSpotTrafficSign[i].offset.data - electronicHorizonArray.PathsArray[indexMPP].ehPosition.offset.data;

				#define OFFSET_SEUIL	20.0
				// test si l'égo se rapproche suffisamment du Traffic Sign
				if((offset_ecart >= 0) && (offset_ecart < OFFSET_SEUIL)){
					for(uint j=0; j<obstacle_assignement.QtyObstacles.data; j++){
						// calcul de l'écart entre le Traffic Sign (EH) et le global track (Fusion capteurs)
						float obstacle_distance;
						geometry_msgs::Point tangente;

						tangente.x = cos(fine_map_matching.dCap.data);
						tangente.y = sin(fine_map_matching.dCap.data);

						obstacle_distance  = tangente.x * obstacle_assignement.ObstacleFusion[j].obstaclePosition.position.x;
						obstacle_distance += tangente.y * obstacle_assignement.ObstacleFusion[j].obstaclePosition.position.y;

						//obstacle_distance  = std::pow(obstacle_assignement.ObstacleFusion[j].obstaclePosition.position.x, 2);
						//obstacle_distance += std::pow(obstacle_assignement.ObstacleFusion[j].obstaclePosition.position.y, 2);
						//obstacle_distance  = std::sqrt(obstacle_distance);

						float ecart_spot_obstacle;
						ecart_spot_obstacle = offset_ecart - obstacle_distance;

						// test sur tous les objets vus par les capteurs :
						// association par attribut, et par assignement, et par écart minimum requis
						#define ECART_SEUIL	2.0
						if(  (obstacle_assignement.ObstacleFusion[j].obstacleClass == electronicHorizonArray.PathsArray[indexMPP].ehSpotTrafficSign[i].Sign_Type)
						//   &&(obstacle_assignement.ObstacleFusion[j].obstacleAssignment == project_s_msgs::ObstacleFusion::ASSIGNMENT_COTE_DROIT)
						   &&(abs(ecart_spot_obstacle) < ECART_SEUIL)){
							// recherche du spot le + près (& obstacle associé)
							if(spot_distance_min > electronicHorizonArray.PathsArray[indexMPP].ehSpotTrafficSign[i].offset.data){
								spot_distance_min = electronicHorizonArray.PathsArray[indexMPP].ehSpotTrafficSign[i].offset.data;
								i_Spot = i;
								j_Obstacle = j;
								ecart_spot_obstacle_assoc = ecart_spot_obstacle;
							}
						}
					}
				}
			}

			if(indexMPP != indexMPP_precedent)
				fine_map_matching.dX.data = 0;
			indexMPP_precedent = indexMPP;

			if((i_Spot != 0xFF) && (j_Obstacle != 0xFF)){
				fine_map_matching.dX.data = ecart_spot_obstacle_assoc;
			}

			//fine_map_matching.dX.data = 0.0;

			fine_map_matching.electronicHorizonArray = electronicHorizonArray;

						// publication
						//pub_fine_map_matching.publish(fine_map_matching);
			*/
			// conversion des amers de l'EH, GPS -> Ref Ego.
			// récupération de la position GPS du véhicule
			geometry_msgs::Point ptRef;
			ptRef = Convertion_Coord_Geo_vers_Carto_((double)electronic_Horizon_Array.PathsArray[0].ehPosition.latitude,
								 (double)electronic_Horizon_Array.PathsArray[0].ehPosition.longitude);

			geometry_msgs::Point ptFixe;
			float distance_Amer_Ego;
			int indice_amer = 0;

			// amers donnés par l'EH
			project_s_msgs::ObstacleFusionReport amer_EH;
			for(int i = 0; i < electronic_Horizon_Array.PathsArray[0].NbrSpotTrafficSign.data; i++){
				distance_Amer_Ego = electronic_Horizon_Array.PathsArray[0].ehSpotTrafficSign[i].offset.data - electronic_Horizon_Array.PathsArray[0].ehPosition.offset.data;
				if((0.0 <= distance_Amer_Ego) && (distance_Amer_Ego <= +20.0)){
					ptFixe = Convertion_Coord_Geo_vers_Carto_((double)electronic_Horizon_Array.PathsArray[0].ehSpotTrafficSign[i].latitude, \
										  (double)electronic_Horizon_Array.PathsArray[0].ehSpotTrafficSign[i].longitude);

					// convertion dans le repère de l'égo (lambert --> ego)
					geometry_msgs::Point ptMobile = computeRelativePosition(ptRef,((float)90.0-electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/(float)180.0*(float)M_PI, ptFixe);
					// rappel : le cap est dans le sens anti-trigo, par rapport au Y de Lambert,
					//	    et comme dans cette conversion il faut le sens trigo, par rapport à X, il faut mettre 90°-cap.
					//          de plus le cap est donné par l'imu en degré, il faut donc le traduire en rad.
					amer_EH.ObstacleFusion[indice_amer].obstaclePosition.position = ptMobile;

					indice_amer++;
				}
			}

			amer_EH.QtyObstacles.data = indice_amer;

			// recherche sur tous les obstacles, pour association amer|obstacle
			bool amer_assigned = false;
			float distance_MIN = 0;
			geometry_msgs::Point pt_EH;
			geometry_msgs::Point pt_ME;

			for(int a = 0; a < amer_EH.QtyObstacles.data; a++){
				// pour tous les amers donnés par EH
				geometry_msgs::Point pt_amer;
				pt_amer = amer_EH.ObstacleFusion[a].obstaclePosition.position;

				for(uint i=0; i<obstacle_assignement.QtyObstacles.data; i++){
					// pour chaque obstacles vus par les capteurs
					geometry_msgs::Point pt_obstacle;
					pt_obstacle = obstacle_assignement.ObstacleFusion[i].obstaclePosition.position;

					float distance;
					if(matching_initial)
						distance = std::sqrt(std::pow(pt_obstacle.x            ,2) + std::pow(pt_obstacle.y            ,2));
					else
						distance = std::sqrt(std::pow(pt_obstacle.x - pt_amer.x,2) + std::pow(pt_obstacle.y - pt_amer.y,2));

					// recherche de l'obstacle le plus proche de l'amer
					if((matching_initial || (distance < (float)4.0)) && ((distance < distance_MIN) || (!amer_assigned))){
						amer_assigned = true;
						distance_MIN = distance;

						pt_EH = pt_amer;
						pt_ME = pt_obstacle;
					}
				}
			}

			if(amer_assigned){

				 printf("amer_assigned %d  \n",amer_assigned);

				double d_X = pt_EH.x - pt_ME.x;
				double d_Y = pt_EH.y - pt_ME.y;	// convention : d_Y > 0 si le point EH est à gauche du point ME.
								// d_Y représente l'EH par rapport à ME (la réalité du terrain)

				if(matching_initial || ((abs(d_X) < 2.0) && (abs(d_Y) < 2.0))){
					// on met à jour le fine map matching si l'écart entre l'amer et l'obstacle < 2m

					// conversion du vecteur de correction de coord Lambert --> coord Ego
					geometry_msgs::Point ptOrigin; ptOrigin.x = 0; ptOrigin.y = 0; 
					geometry_msgs::Point Correction_Carto;
					Correction_Carto.x = fine_map_matching.d_x_lambert.data;
					Correction_Carto.y = fine_map_matching.d_y_lambert.data;

					geometry_msgs::Point Correction_Ego = computeRelativePosition(ptOrigin, ((float)90.0-electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/(float)180.0*(float)M_PI, \
												      Correction_Carto);

					// MàJ du vecteur de correction, dans le ref Ego, avec filtrage
					// lissage de vth au 1er ordre
					//(current_time - last_time).toSec();
					last_time = current_time;

					//#define CONSTANTE_TEMPS	10
					K = exp(-dt/CONSTANTE_TEMPS);
					//K = 0.94;


					double Correction_Ego_precedent_x = Correction_Ego.x;
					//					Correction_Ego.x  =      K * Correction_Ego_precedent_x;
					//					Correction_Ego.x += (1.0-K)*(Correction_Ego_precedent_x + d_X);
					double Correction_Ego_precedent_y = Correction_Ego.y;
					//					Correction_Ego.y  =      K * Correction_Ego_precedent_y;
					//					Correction_Ego.y += (1.0-K)*(Correction_Ego_precedent_y + d_Y);
					Correction_Ego.x += (1.0-K)*d_X;
					Correction_Ego.y += (1.0-K)*d_Y;
					// conversion du vecteur de correction de coord Ego --> coord Lambert
					Correction_Carto = computeRelativePosition(ptOrigin, ((float)-90.0+electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/(float)180.0*(float)M_PI, Correction_Ego);

					//Correction_Carto.x = 0;
					//Correction_Carto.y = 0;
					//MàJ du topic  
					fine_map_matching.d_x_lambert.data = Correction_Carto.x;

					//std::cerr<< "Correction_Carto.x = " <<  Correction_Carto.x << "; Correction_Carto.y = " <<  Correction_Carto.y << std::endl;

					fine_map_matching.d_y_lambert.data = Correction_Carto.y;

					// conversion du vecteur de coord Lambert --> coord GPS
					double d_latitude, d_longitude;
					d_latitude  = Correction_Carto.y / (double)RAYON_TERRE * (double)180.0 / (double)M_PI;
					d_longitude = Correction_Carto.x / ((double)RAYON_TERRE*cos(electronic_Horizon_Array.PathsArray[0].ehPosition.latitude/180.0*M_PI)) * (double)180.0 / (double)M_PI;
					// rappel : lattitude & longitude sont à fournir en degré.

					//d_latitude = 0;
					//d_longitude = 0;
					//MàJ du topic  
					fine_map_matching.d_latitude  = d_latitude;
					fine_map_matching.d_longitude = d_longitude;
					
					//printf("d_X %f  \n",d_X);
					//printf("d_Y %f  \n",d_Y);
					//printf("amer_matching_progress %f  \n",100*(1-((abs(d_X)+abs(d_Y))/2)/(2)));
					amer_matching_progress.data=100*(1-((abs(d_X)+abs(d_Y))/2)/2);  //Added  (d_X+d_Y)/2) : l'erreur de matching ; 
					// ((d_X+d_Y)/2)/(2) : l'erreur de matching normalisée sur 2 m
					// 100 : pourcentage 


				}
			}

			// publication
			pub_fine_map_matching.publish(fine_map_matching);
			 
			pub_fine_map_matching_progress.publish(amer_matching_progress); // Added

		}

		//----------
		if(linesUpdateReceived){
			//if(true){
			linesUpdateReceived = false;
			/*
			// Recherche de l'EH le mieux synchronisé
			double tempsREF = (lines_update.header.stamp).toSec();
			uint iMIN = 0;
			double dtMIN = fabs((electronic_Horizon_Report.ElectronicHorizonArray[iMIN].header.stamp).toSec() - tempsREF);
			electronicHorizonArray = electronic_Horizon_Report.ElectronicHorizonArray[iMIN];

			#define NBR_MAX_EH	5	// en concordance avec ElectronicHorizonReport.msg
			for(uint i = 0; i < NBR_MAX_EH; i++){
				double dt = fabs((electronic_Horizon_Report.ElectronicHorizonArray[i].header.stamp).toSec() - tempsREF);
				if(dt < dtMIN){
					dtMIN = dt;
					iMIN = i;
					electronicHorizonArray = electronic_Horizon_Report.ElectronicHorizonArray[iMIN];
				}
			}

				fine_map_matching.header.stamp = electronicHorizonArray.header.stamp;

				ROS_ERROR("lines_update             : %f", tempsREF);
				tempsREF = (electronic_Horizon_Report.ElectronicHorizonArray[0].header.stamp).toSec();
				ROS_ERROR("electronicHorizonArray_0 : %f", tempsREF);
				tempsREF = (electronic_Horizon_Report.ElectronicHorizonArray[1].header.stamp).toSec();
				ROS_ERROR("electronicHorizonArray_1 : %f", tempsREF);
				ROS_ERROR("iMIN : %i", iMIN);
				*/

				/*double dt = (fine_map_matching.header.stamp - lines_update.header.stamp).toSec();
				if(abs(dt) < 0.005)
							{
				tempsREF = (lines_update.header.stamp).toSec();
				ROS_ERROR("lines_update      : %f", tempsREF);
				tempsREF = (fine_map_matching.header.stamp).toSec();
				ROS_ERROR("fine_map_matching : %f", tempsREF);
				*/

				/*
			// recherche du premier point avec x>0, et du premier point avec x<0
			// ligne de droite
			geometry_msgs::Point pt1_d, pt2_d; pt1_d.x = pt2_d.x = 0;
			bool fl_valid_d = false;
			int N = 0;
			if(lines_update.QtyLine.data > 0)
				N = lines_update.line[0].QtySegment.data;
			for(int i=0;i<N;i++)
				// hyp : les segments sont classés par ordre croissant de x
				if((lines_update.line[0].segment[i].position.x > 0) && (pt1_d.x == 0))
					pt1_d = lines_update.line[0].segment[i].position;
			for(int i=N-1;i>=0;i--)
				if((lines_update.line[0].segment[i].position.x < 0) && (pt2_d.x == 0))
					pt2_d = lines_update.line[0].segment[i].position;
			if((pt1_d.x > 0) && (pt2_d.x < 0))
				fl_valid_d = true;

			// ligne de gauche
			geometry_msgs::Point pt1_g, pt2_g; pt1_g.x = pt2_g.x = 0;
			bool fl_valid_g = false;
			N = 0;
			if(lines_update.QtyLine.data > 1)
				N = lines_update.line[1].QtySegment.data;
			for(int i=0;i<N;i++)
				// hyp : les segments sont classés par ordre croissant de x
				if((lines_update.line[1].segment[i].position.x > 0) && (pt1_g.x == 0))
					pt1_g = lines_update.line[1].segment[i].position;
			for(int i=N-1;i>=0;i--)
				if((lines_update.line[1].segment[i].position.x < 0) && (pt2_g.x == 0))
					pt2_g = lines_update.line[1].segment[i].position;
			if((pt1_g.x > 0) && (pt2_g.x < 0))
				fl_valid_g = true;

			// calcul de la correction de cap
			float dCap_d = 0;
			if(fl_valid_d){
				dCap_d  = pt1_d.x - pt2_d.x;
				dCap_d /= std::sqrt(std::pow(pt1_d.x - pt2_d.x,2) + std::pow(pt1_d.y - pt2_d.y,2));
				dCap_d  = acos(dCap_d);
				if(pt1_d.y > pt2_d.y)
					dCap_d = -dCap_d;
			}

			float dCap_g = 0;
			if(fl_valid_g){
				dCap_g  = pt1_g.x - pt2_g.x;
				dCap_g /= std::sqrt(std::pow(pt1_g.x - pt2_g.x,2) + std::pow(pt1_g.y - pt2_g.y,2));
				dCap_g  = acos(dCap_g);
				if(pt1_g.y > pt2_g.y)
					dCap_g = -dCap_g;
			}

			float dCap = 0;
			if(fl_valid_d){
				if(fl_valid_g)
					dCap = (dCap_d + dCap_g)/2.0;
				else
					dCap = dCap_d;
			}
			else{
				if(fl_valid_g)
					dCap = dCap_g;
			}

			// calcul de la correction latérale
			float dY = 0;
			geometry_msgs::Point pt_inter_d, pt_inter_g;

			//pt_inter_d.x = 0; fait à l'init
			if(fl_valid_d){
				pt_inter_d.y  = pt1_d.y      - pt2_d.y;
				pt_inter_d.y /= pt1_d.x      - pt2_d.x;
				pt_inter_d.y *= pt_inter_d.x - pt2_d.x;
				pt_inter_d.y += pt2_d.y;
			}

			//pt_inter_g.x = 0; fait à l'init
			if(fl_valid_g){
				pt_inter_g.y  = pt1_g.y      - pt2_g.y;
				pt_inter_g.y /= pt1_g.x      - pt2_g.x;
				pt_inter_g.y *= pt_inter_g.x - pt2_g.x;
				pt_inter_g.y += pt2_g.y;
			}

			if((fl_valid_d) && (fl_valid_g))
				dY = -(pt_inter_d.y + pt_inter_g.y)/2.0;

			dY *= cos(dCap);

			fine_map_matching.dCap.data = dCap;
			fine_map_matching.dY.data = dY;
			fine_map_matching.dY.data *= -1.0;

			// publication
			pub_fine_map_matching.publish(fine_map_matching);
			//}*/

			// conversion des lignes de l'EH, GPS -> Ref Ego.
			// récupération de la position GPS du véhicule
			geometry_msgs::Point ptRef;
			ptRef = Convertion_Coord_Geo_vers_Carto_(electronic_Horizon_Array.PathsArray[0].ehPosition.latitude,
								 electronic_Horizon_Array.PathsArray[0].ehPosition.longitude);

			geometry_msgs::Point ptFixe;
			float distance_Spot_Ego;
			int indice_segment = 0;

			// ligne de droite
			project_s_msgs::Line LineRight;

			/*			for(int i = 0; i < electronic_Horizon_Array.PathsArray[0].ehLineCoordGeo[0].NbrSpotCoordGeo.data; i++){
							distance_Spot_Ego = electronic_Horizon_Array.PathsArray[0].ehLineCoordGeo[0].ehSpotCoordGeo[i].offset.data - electronic_Horizon_Array.PathsArray[0].ehPosition.offset.data;
							if((-15.0 <= distance_Spot_Ego) && (distance_Spot_Ego <= +30.0)){
								ptFixe = Convertion_Coord_Geo_vers_Carto_(electronic_Horizon_Array.PathsArray[0].ehLineCoordGeo[0].ehSpotCoordGeo[i].latitude, \
													electronic_Horizon_Array.PathsArray[0].ehLineCoordGeo[0].ehSpotCoordGeo[i].longitude);

								// convertion dans le repère de l'égo (lambert --> ego)
								geometry_msgs::Point ptMobile = computeRelativePosition(ptRef,(90-electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/180.0*M_PI, ptFixe);
								// rappel : le cap est dans le sens anti-trigo, par rapport au Y de Lambert,
								//	    et comme dans cette conversion il faut le sens trigo, par rapport à X, il faut mettre 90°-cap.
								//          de plus le cap est donné par l'imu en degré, il faut donc le traduire en rad.
								LineRight.segment[indice_segment].position = ptMobile;

								indice_segment++;
							}
						}

			*/


			// NOUVELLE VERSION ligne enregistrée de ME
			//for(int i = 0; i < electronic_Horizon_Array.PathsArray[0].ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].QtySegment.data; i++){
			for(int i = 0; i < project_s_msgs::ehME::SPOT_REPORT_SIZE; i++){
				distance_Spot_Ego = electronic_Horizon_Array.PathsArray[0].ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].ehSpotCoordGeo[i].offset.data - electronic_Horizon_Array.PathsArray[0].ehPosition.offset.data;
				if((-15.0 <= distance_Spot_Ego) && (distance_Spot_Ego <= +30.0)){
					ptFixe = Convertion_Coord_Geo_vers_Carto_(electronic_Horizon_Array.PathsArray[0].ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].ehSpotCoordGeo[i].latitude, \
										electronic_Horizon_Array.PathsArray[0].ehME[project_s_msgs::ElectronicHorizon::ME_RIGHT_LINE].ehSpotCoordGeo[i].longitude);

					// convertion dans le repère de l'égo (lambert --> ego)
					geometry_msgs::Point ptMobile = computeRelativePosition(ptRef,(90-electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/180.0*M_PI, ptFixe);
					// rappel : le cap est dans le sens anti-trigo, par rapport au Y de Lambert,
					//	    et comme dans cette conversion il faut le sens trigo, par rapport à X, il faut mettre 90°-cap.
					//          de plus le cap est donné par l'imu en degré, il faut donc le traduire en rad.
					LineRight.segment[indice_segment].position = ptMobile;

					indice_segment++;
				}
			}
			// FIN


			LineRight.QtySegment.data = indice_segment;

			// ligne de gauche
			indice_segment = 0;
			project_s_msgs::Line LineLeft;
			/*			for(int i = 0; i < electronic_Horizon_Array.PathsArray[0].ehLineCoordGeo[1].NbrSpotCoordGeo.data; i++){
							distance_Spot_Ego = electronic_Horizon_Array.PathsArray[0].ehLineCoordGeo[1].ehSpotCoordGeo[i].offset.data - electronic_Horizon_Array.PathsArray[0].ehPosition.offset.data;
							if((-15.0 <= distance_Spot_Ego) && (distance_Spot_Ego <= +30.0)){
								ptFixe = Convertion_Coord_Geo_vers_Carto_(electronic_Horizon_Array.PathsArray[0].ehLineCoordGeo[1].ehSpotCoordGeo[i].latitude, \
													electronic_Horizon_Array.PathsArray[0].ehLineCoordGeo[1].ehSpotCoordGeo[i].longitude);

								
								geometry_msgs::Point ptMobile = computeRelativePosition(ptRef,(90-electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/180.0*M_PI, ptFixe);
								LineLeft.segment[indice_segment].position = ptMobile;

								indice_segment++;
							}
						}
			*/

				// NOUVELLE VERSION ligne enregistrée de ME
				for(int i = 0; i < project_s_msgs::ehME::SPOT_REPORT_SIZE; i++){
					distance_Spot_Ego = electronic_Horizon_Array.PathsArray[0].ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].ehSpotCoordGeo[i].offset.data - electronic_Horizon_Array.PathsArray[0].ehPosition.offset.data;
					if((-15.0 <= distance_Spot_Ego) && (distance_Spot_Ego <= +30.0)){
						ptFixe = Convertion_Coord_Geo_vers_Carto_(electronic_Horizon_Array.PathsArray[0].ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].ehSpotCoordGeo[i].latitude, \
											electronic_Horizon_Array.PathsArray[0].ehME[project_s_msgs::ElectronicHorizon::ME_LEFT_LINE].ehSpotCoordGeo[i].longitude);

						
						geometry_msgs::Point ptMobile = computeRelativePosition(ptRef,(90-electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/180.0*M_PI, ptFixe);
						LineLeft.segment[indice_segment].position = ptMobile;

						indice_segment++;
					}
				}
				//FIN 
			LineLeft.QtySegment.data = indice_segment;

			// VERSION : fine map matching sur lignes de droite & gauche

			// comparaison avec les lignes vues par ME.
			// calcul, pour le premier point de ligne vue par ME au-delà de 0m, du point aligné sur les lignes de l'EH, dans le repère de l'ego
			bool obstacle_assigned_R = false;
			geometry_msgs::Point pt_1_ME_R;
			geometry_msgs::Point pt_1_align_R;
			double Cap_EH_R = 0;
			double Cap_ME_R = 0;

			for(int l = 0; l < lines_update.QtyLine.data; l++){
				// pour toutes les lignes vues par ME
				for(int m = 0; m < lines_update.line[l].QtySegment.data-1; m++){
					geometry_msgs::Point pt_1;
					pt_1 = lines_update.line[l].segment[m].position;

					if((pt_1.x >= 0) && (pt_1.y < 0) && (!obstacle_assigned_R)){
						// le premier point de x > 0, pour la première ligne vue par ME à droite

						for(int i = 0; i < LineRight.QtySegment.data-1; i++){
							// pour chaque points de la ligne de droite de l'EH
							geometry_msgs::Point pt_0, pt_2;
							pt_0 = LineRight.segment[i].position;
							pt_2 = LineRight.segment[i+1].position;

							// recherche du couple de segment qui encadre le point en X
							if((pt_0.x <= pt_1.x) && (pt_1.x < pt_2.x)){
								obstacle_assigned_R = true;

								pt_1_ME_R = pt_1;

								// alignement du point de l'EH au niveau du point de ME
								pt_1_align_R.x  = pt_1.x;
								pt_1_align_R.y  = pt_2.y         - pt_0.y;
								pt_1_align_R.y /= pt_2.x         - pt_0.x;
								pt_1_align_R.y *= pt_1_align_R.x - pt_0.x;
								pt_1_align_R.y += pt_0.y;

								Cap_EH_R = (pt_2.y - pt_0.y) / (pt_2.x - pt_0.x);
								Cap_EH_R = atan(Cap_EH_R);

								Cap_ME_R =  (lines_update.line[l].segment[m].position.y - lines_update.line[l].segment[m+1].position.y)
									  / (lines_update.line[l].segment[m].position.x - lines_update.line[l].segment[m+1].position.x);
								Cap_ME_R = atan(Cap_ME_R);
							}
						}
					}
				}
			}

			if(obstacle_assigned_R){
				double d_Cap = -Cap_EH_R + Cap_ME_R;
				double d_Y = pt_1_align_R.y - pt_1_ME_R.y;	// convention : d_Y > 0 si le point EH est à gauche du point ME.
										// d_Y représente l'EH par rapport à ME (la réalité du terrain)
										//d_Y = 0;
				if(  (abs(d_Cap) < 20/180.0*M_PI) && (abs(Cap_EH_R) < 25/180.0*M_PI) && (abs(Cap_ME_R) < 25/180.0*M_PI)
				   &&(abs(d_Y) < 2.0)){
					// on met à jour le fine map matching si d_Cap (entre ligne EH et ligne ME) < 20°

					// conversion du vecteur de correction de coord Lambert --> coord Ego
					geometry_msgs::Point ptOrigin; ptOrigin.x = 0; ptOrigin.y = 0; 
					geometry_msgs::Point Correction_Carto;
					Correction_Carto.x = fine_map_matching.d_x_lambert.data;
					Correction_Carto.y = fine_map_matching.d_y_lambert.data;

					geometry_msgs::Point Correction_Ego = computeRelativePosition(ptOrigin, (90-electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/180.0*M_PI, \
												      Correction_Carto);

					// MàJ du vecteur de correction, dans le ref Ego, avec filtrage
					// lissage de vth au 1er ordre
					// dt =  (current_time - last_time).toSec();
					last_time = current_time;

					//#define CONSTANTE_TEMPS	1
					 K = exp(-dt/CONSTANTE_TEMPS);
					// K = 0.97;
					//Correction_Ego.x  =       Correction_Ego.x;	inchangé, car le fine map matching sur les lignes ne peut pas renseigner sur dx.
					double Correction_Ego_precedent = Correction_Ego.y;
					Correction_Ego.y  =      K * Correction_Ego_precedent;
					Correction_Ego.y += (1.0-K)*(Correction_Ego_precedent + d_Y);

					// conversion du vecteur de correction de coord Ego --> coord Lambert
					Correction_Carto = computeRelativePosition(ptOrigin, (-90+electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/180.0*M_PI, Correction_Ego);
					//Correction_Carto.x = 0;
					//Correction_Carto.y = 0;
					//MàJ du topic  
					fine_map_matching.d_x_lambert.data = Correction_Carto.x;
					fine_map_matching.d_y_lambert.data = Correction_Carto.y;

					// conversion du vecteur de coord Lambert --> coord GPS
					double d_latitude, d_longitude;
					d_latitude  = Correction_Carto.y /  (double)RAYON_TERRE                                                                             * (double)180.0 / (double)M_PI;
					d_longitude = Correction_Carto.x / ((double)RAYON_TERRE*cos(electronic_Horizon_Array.PathsArray[0].ehPosition.latitude/180.0*M_PI)) * (double)180.0 / (double)M_PI;
					// rappel : lattitude & longitude sont à fournir en degré.
					//d_latitude = 0;
					//d_longitude = 0;

					//MàJ du topic  
					fine_map_matching.d_latitude  = d_latitude;
					fine_map_matching.d_longitude = d_longitude;

					// màj de dCap
					fine_map_matching.dCap.data += (1.0-K)*(d_Cap*180.0/M_PI);
					fine_map_matching.dCap.data  = 0;
				}
			}

			bool obstacle_assigned_L = false;
			geometry_msgs::Point pt_1_ME_L;
			geometry_msgs::Point pt_1_align_L;
			double Cap_EH_L = 0;
			double Cap_ME_L = 0;

			for(int l = 0; l < lines_update.QtyLine.data; l++){
				// pour toutes les lignes vues par ME
				for(int m = 0; m < lines_update.line[l].QtySegment.data-1; m++){
					geometry_msgs::Point pt_1;
					pt_1 = lines_update.line[l].segment[m].position;

					if((pt_1.x >= 0) && (pt_1.y > 0) && (!obstacle_assigned_L)){
						// le premier point de x > 0, pour la première ligne vue par ME à gauche

						for(int i = 0; i < LineLeft.QtySegment.data-1; i++){
							// pour chaque points de la ligne de gauche de l'EH
							geometry_msgs::Point pt_0, pt_2;
							pt_0 = LineLeft.segment[i].position;
							pt_2 = LineLeft.segment[i+1].position;

							// recherche du couple de segment qui encadre le point en X
							if((pt_0.x <= pt_1.x) && (pt_1.x < pt_2.x)){
								obstacle_assigned_L = true;

								pt_1_ME_L = pt_1;

								// alignement du point de l'EH au niveau du point de ME
								pt_1_align_L.x  = pt_1.x;
								pt_1_align_L.y  = pt_2.y         - pt_0.y;
								pt_1_align_L.y /= pt_2.x         - pt_0.x;
								pt_1_align_L.y *= pt_1_align_L.x - pt_0.x;
								pt_1_align_L.y += pt_0.y;

								Cap_EH_L = (pt_2.y - pt_0.y) / (pt_2.x - pt_0.x);
								Cap_EH_L = atan(Cap_EH_L);

								Cap_ME_L =  (lines_update.line[l].segment[m].position.y - lines_update.line[l].segment[m+1].position.y)
									  / (lines_update.line[l].segment[m].position.x - lines_update.line[l].segment[m+1].position.x);
								Cap_ME_L = atan(Cap_ME_L);
							}
						}
					}
				}
			}

			if(obstacle_assigned_L){
				double d_Cap = -Cap_EH_L + Cap_ME_L;
				double d_Y = pt_1_align_L.y - pt_1_ME_L.y;	// convention : d_Y > 0 si le point EH est à gauche du point ME.
										// d_Y représente l'EH par rapport à ME (la réalité du terrain)
				//d_Y = 0;
				if(  (abs(d_Cap) < 20/180.0*M_PI) && (abs(Cap_EH_L) < 25/180.0*M_PI) && (abs(Cap_ME_L) < 25/180.0*M_PI)
				   &&(abs(d_Y) < 2.0)){
					// on met à jour le fine map matching si d_Cap (entre ligne EH et ligne ME) < 20°

					// conversion du vecteur de correction de coord Lambert --> coord Ego
					geometry_msgs::Point ptOrigin; ptOrigin.x = 0; ptOrigin.y = 0; 
					geometry_msgs::Point Correction_Carto;
					Correction_Carto.x = fine_map_matching.d_x_lambert.data;
					Correction_Carto.y = fine_map_matching.d_y_lambert.data;

					geometry_msgs::Point Correction_Ego = computeRelativePosition(ptOrigin, (90-electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/180.0*M_PI, \
												      Correction_Carto);

					// MàJ du vecteur de correction, dans le ref Ego, avec filtrage
					// lissage de vth au 1er ordre
					//(current_time - last_time).toSec();
					last_time = current_time;

					K = exp(-dt/CONSTANTE_TEMPS);
					// K = 0.97;
					//Correction_Ego.x  =       Correction_Ego.x;	inchangé, car le fine map matching sur les lignes ne peut pas renseigner sur dx.
					double Correction_Ego_precedent = Correction_Ego.y;
					Correction_Ego.y  =      K * Correction_Ego_precedent;
					Correction_Ego.y += (1.0-K)*(Correction_Ego_precedent + d_Y);

					// conversion du vecteur de correction de coord Ego --> coord Lambert
					Correction_Carto = computeRelativePosition(ptOrigin, (-90+electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/180.0*M_PI, Correction_Ego);
					//Correction_Carto.x = 0;
					//Correction_Carto.y = 0;
					//MàJ du topic  
					fine_map_matching.d_x_lambert.data = Correction_Carto.x;
					fine_map_matching.d_y_lambert.data = Correction_Carto.y;

					// conversion du vecteur de coord Lambert --> coord GPS
					double d_latitude, d_longitude;
					d_latitude  = Correction_Carto.y /  (double)RAYON_TERRE                                                                             * (double)180.0 / (double)M_PI;
					d_longitude = Correction_Carto.x / ((double)RAYON_TERRE*cos(electronic_Horizon_Array.PathsArray[0].ehPosition.latitude/180.0*M_PI)) * (double)180.0 / (double)M_PI;
					// rappel : lattitude & longitude sont à fournir en degré.
					//d_latitude = 0;
					//d_longitude = 0;

					//MàJ du topic  
					fine_map_matching.d_latitude  = d_latitude;
					fine_map_matching.d_longitude = d_longitude;

					// màj de dCap
					fine_map_matching.dCap.data += (1.0-K)*(d_Cap*180.0/M_PI);
					fine_map_matching.dCap.data  = 0;
				}
			}
			// FIN VERSION : fine map matching sur lignes de droite & gauche

			/*			// VERSION : fine map matching sur suivi de trace

			bool obstacle_assigned = false;
			geometry_msgs::Point pt_1_ME;
			geometry_msgs::Point pt_1_align;
			double Cap_EH = 0;
			double Cap_ME = 0;

			for(int l = 0; l < lines_update.QtyLine.data; l++){
				// pour toutes les lignes vues par ME
				for(int m = 0; m < lines_update.line[l].QtySegment.data-1; m++){
					geometry_msgs::Point pt_1;
					pt_1 = lines_update.line[l].segment[m].position;

					if((pt_1.x >= 0) && (!obstacle_assigned)){
						// le premier point de x > 0, sans condition ligne vue par ME à droite ou à gauche

						for(uint i=0; i<roadModel.roadLine[3].QtySegment.data; i++){
							// pour chaque points de la consigne de trajectoire
							geometry_msgs::Point pt_0, pt_2;
							pt_0 = roadModel.roadLine[3].segment[i].position;
							pt_2 = roadModel.roadLine[3].segment[i+1].position;

							// recherche du couple de segment qui encadre le point en X
							if((pt_0.x <= pt_1.x) && (pt_1.x < pt_2.x)){
								obstacle_assigned = true;

								pt_1_ME = pt_1;

								// alignement du point de l'EH au niveau du point de ME
								pt_1_align.x  = pt_1.x;
								pt_1_align.y  = pt_2.y       - pt_0.y;
								pt_1_align.y /= pt_2.x       - pt_0.x;
								pt_1_align.y *= pt_1_align.x - pt_0.x;
								pt_1_align.y += pt_0.y;

								Cap_EH = (pt_2.y - pt_0.y) / (pt_2.x - pt_0.x);
								Cap_EH = atan(Cap_EH);

								Cap_ME =  (lines_update.line[l].segment[m].position.y - lines_update.line[l].segment[m+1].position.y)
									/ (lines_update.line[l].segment[m].position.x - lines_update.line[l].segment[m+1].position.x);
								Cap_ME = atan(Cap_ME);
							}
						}
					}
				}
			}

				//fine_map_matching.d_x_lambert.data = -1.0;
				//fine_map_matching.d_y_lambert.data = -1.0;

				//electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data = -60;

				//Cap_EH = 0; Cap_ME = 0;

				if(obstacle_assigned){
					//			if(false){
				//if(true){
				double d_Cap = Cap_EH - Cap_ME;
				double d_Y = pt_1_align.y - pt_1_ME.y;	// convention : d_Y > 0 si le point EH est à gauche du point ME.
									// d_Y représente l'EH par rapport à ME (la réalité du terrain)
				//d_Y = +1;
				if(  (abs(d_Cap) < 20/180.0*M_PI) && (abs(Cap_EH) < 25/180.0*M_PI) && (abs(Cap_ME) < 25/180.0*M_PI)
				   &&(abs(d_Y) < 2.0)){
					// on met à jour le fine map matching si d_Cap (entre ligne EH et ligne ME) < 20°

					// conversion du vecteur de correction de coord Lambert --> coord Ego
					geometry_msgs::Point ptOrigin; ptOrigin.x = 0; ptOrigin.y = 0; 
					geometry_msgs::Point Correction_Carto;
					Correction_Carto.x = fine_map_matching.d_x_lambert.data;
					Correction_Carto.y = fine_map_matching.d_y_lambert.data;

					geometry_msgs::Point Correction_Ego = computeRelativePosition(ptOrigin, (90-electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/180.0*M_PI, \
												      Correction_Carto);

					// MàJ du vecteur de correction, dans le ref Ego, avec filtrage
					// lissage de vth au 1er ordre
					//(current_time - last_time).toSec();
					last_time = current_time;

					#define CONSTANTE_TEMPS	1
					double K = exp(-dt/CONSTANTE_TEMPS);
					//K = 0;
					//Correction_Ego.x  =       Correction_Ego.x;	inchangé, car le fine map matching sur les lignes ne peut pas renseigner sur dx.
					double Correction_Ego_precedent = Correction_Ego.y;
					Correction_Ego.y  =      K * Correction_Ego_precedent;
					Correction_Ego.y += (1.0-K)*(Correction_Ego_precedent + d_Y);

					// conversion du vecteur de correction de coord Ego --> coord Lambert
					Correction_Carto = computeRelativePosition(ptOrigin, (-90+electronic_Horizon_Array.PathsArray[0].ehPosition.cap.data)/180.0*M_PI, Correction_Ego);

					//MàJ du topic  
					fine_map_matching.d_x_lambert.data = Correction_Carto.x;
					fine_map_matching.d_y_lambert.data = Correction_Carto.y;

					// conversion du vecteur de coord Lambert --> coord GPS
					//electronic_Horizon_Array.PathsArray[0].ehPosition.latitude.data = 45;
					double d_latitude, d_longitude;
					d_latitude  = Correction_Carto.y /  RAYON_TERRE                                                                                  * 180.0 / M_PI;
					d_longitude = Correction_Carto.x / (RAYON_TERRE*cos(electronic_Horizon_Array.PathsArray[0].ehPosition.latitude/180.0*M_PI)) * 180.0 / M_PI;
					// rappel : lattitude & longitude sont à fournir en degré.

					//MàJ du topic  
					fine_map_matching.d_latitude  = d_latitude;
					fine_map_matching.d_longitude = d_longitude;

					// màj de dCap
					fine_map_matching.dCap.data  += (1.0-K)*(d_Cap*180.0/M_PI);

					//fine_map_matching.d_latitude.data  = 0;
					//fine_map_matching.d_longitude.data = 0;
				}
			}
			// FIN VERSION : fine map matching sur suivi de trace*/

			// publication
			pub_fine_map_matching.publish(fine_map_matching);




		}

		//----------
		if(electronicHorizonReceived){
			electronicHorizonReceived = false;

		//			electronicHorizonArray = electronic_Horizon_Report.ElectronicHorizonArray[0];

		//fine_map_matching = project_s_msgs::FineMapMatching();
		//fine_map_matching.header.stamp = electronicHorizonArray.header.stamp;

		//pub_fine_map_matching.publish(fine_map_matching);

		}

		//----------
		if(roadModelReceived){
			roadModelReceived = false;
		}

		loop_rate.sleep();
	}

	return 0;
}
