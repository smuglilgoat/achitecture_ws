#include <stdio.h>
#include <stdlib.h>
#include <sstream>
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
#include <math.h>
#include <std_msgs/String.h>
#include "ros/ros.h"
#include <tf/transform_broadcaster.h>
#include "visualization_msgs/Marker.h"
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud2_iterator.h>
#include <tuple>
#include <map>

 
#include "project_s_msgs/Configurations.h"

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
 

 #include "message_project_s/ObstacleAlignmentReport_1.h"
message_project_s::ObstacleAlignmentReport_1  bufferCameraMe = message_project_s::ObstacleAlignmentReport_1 ();
message_project_s::ObstacleAlignmentReport_1  bufferRadarESR = message_project_s::ObstacleAlignmentReport_1 ();
message_project_s::ObstacleAlignmentReport_1  bufferLidar    = message_project_s::ObstacleAlignmentReport_1 ();

// Abdessamed: Début
sensor_msgs::PointCloud2 pointcloud;
#define	obstacleDimensions_default_ibeo_x		3  				// 3m
#define	obstacleDimensions_default_ibeo_y		3  				// 3m
//#define obstacleVelocity_max_ibeo_x				2  				// 2m par second
//#define obstacleVelocity_max_ibeo_y				2  				// 2m par second
#define size_cell_for_ibeo						0.1  			// 20 cm
#define size_cell_for_esr						0.1  			// 20 cm
#define size_zone_y								20 				// taille de la zone de filtrage (axe y) 5 pour chaque coté    
#define size_zone_x_fin							100 			// fin de la zone de filtrage (axe X)
#define size_zone_x_debut						-20	  			
#define zone_vehicule_length					4 			 	// au dela de la longueur du vehicule pour éviter les nuages de points collés sur les 3 capteurs
#define zone_vehicule_width						1 			 	 
#define Raduis_max_for_esr_box				   	0.5 //1  				// Rayon entre nuage de point et le track esr 
#define Raduis_max_for_ibeo_box				   	0.5  			// Rayon entre nuage de point et l'objet de ibeo 

std::vector<std::pair<const float, const float> > cell_pointcloud_for_esr,cell_pointcloud_for_ibeo;
std::map<std::pair<float, float>, int> counts_for_esr,counts_for_ibeo;                                                         

// Fin 

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
#include "project_s_msgs/ObstacleAlignmentReport.h"

//-------------------------------------------------------------------------------------------------
// local function
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedCameraMe = false;
 
 void cameraMeCallback(const message_project_s::ObstacleAlignmentReport_1::ConstPtr& ObstacleArray)
{
	bufferCameraMe = *ObstacleArray;

	receivedCameraMe = true;
}

bool receivedRadarESR = false;
 
 void radarESRCallback(const message_project_s::ObstacleAlignmentReport_1::ConstPtr& ObstacleArray)
 {
	bufferRadarESR = *ObstacleArray;

	receivedRadarESR = true;
}

bool receivedLidar = false;
 
 void lidarCallback(const message_project_s::ObstacleAlignmentReport_1::ConstPtr& ObstacleArray)
 {
	bufferLidar = *ObstacleArray;

	receivedLidar = true;
}

bool receivedLidar_pointcloud = false;

void  callback_lidar_point(const sensor_msgs::PointCloud2ConstPtr &msg)
{

	pointcloud = *msg;

	receivedLidar_pointcloud = true; 

}



//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	ros::init(argc, argv, std::string("local_tracks_filtering"));

	ros::NodeHandle n;

	ros::Publisher pub_camera_me_obstacles_filtering = n.advertise<project_s_msgs::ObstacleAlignmentReport>(std::string("/camera_me_obstacles_filtering_data"), 1);
	ros::Publisher pub_lidar_obstacles_filtering     = n.advertise<project_s_msgs::ObstacleAlignmentReport>(std::string("/lidar_obstacles_filtering_data"), 1);
	ros::Publisher pub_radar_ESR_filtering           = n.advertise<project_s_msgs::ObstacleAlignmentReport>(std::string("/radar_ESR_obstacles_filtering_data"), 1);

	ros::Subscriber subMe       = n.subscribe(std::string("/camera_me_obstacles_align_data"), 1, cameraMeCallback);
	ros::Subscriber subLidar    = n.subscribe(std::string("/lidar_obstacles_align_data"), 1, lidarCallback);
	ros::Subscriber subRadarESR = n.subscribe(std::string("/radar_ESR_obstacles_align_data"), 1,radarESRCallback);
	ros::Subscriber sub 		= n.subscribe(std::string("/as_tx/point_cloud"), 1,  callback_lidar_point);  


	ros::Rate loop_rate(100);	

	while(n.ok())
	{
		ros::spinOnce();



		// Abdessamed: Début

		if (receivedLidar_pointcloud)
		{
			for (sensor_msgs::PointCloud2ConstIterator<float> it(pointcloud, "x"); it != it.end(); ++it)
			{
				//if (it[0] < size_zone_x_fin   && it[0] > size_zone_x_debut  && it[1] < size_zone_y && it[1] > -size_zone_y)
				if (it[0] > size_zone_x_debut  && it[1] < size_zone_y && it[1] > -size_zone_y)
				{
					if (!  (it[0] > 0 && it[0] < zone_vehicule_length  && it[1] < zone_vehicule_width  && it[1] > -zone_vehicule_width ))
					//if (  (it[0] < 0   || it[0] > 4)  && (it[1] > 0.5  || it[1] < -0.5 )  ) //zone_vehicule_width   zone_vehicule_length
					{
						cell_pointcloud_for_esr.push_back(std::make_pair(trunc(it[0] / size_cell_for_esr) * size_cell_for_esr  , trunc(it[1] / size_cell_for_esr) * size_cell_for_esr ));
						cell_pointcloud_for_ibeo.push_back(std::make_pair(trunc(it[0] / size_cell_for_ibeo) * size_cell_for_ibeo  , trunc(it[1] / size_cell_for_ibeo) * size_cell_for_ibeo ));
						//std::cout<<"Point x:"  <<it[0]<<" y:"<<it[1]<<std::endl;

					}
				}
			}
			for (const auto &p : cell_pointcloud_for_esr)   ++counts_for_esr[p]; 
			for (const auto &p : cell_pointcloud_for_ibeo)   ++counts_for_ibeo[p]; 

			receivedLidar_pointcloud=false;
 
		}
		// Fin

		if (receivedRadarESR)
		{
			project_s_msgs::ObstacleAlignmentReport radaresr;

			uint QtyObstacles = 0;
			uint id =0;
			float distance_pointLidar_esr_track;
 			for(int i=0; i < bufferRadarESR.ObstacleAlignement_1.size(); i++)
			{
				// Abdessamed: Début

 				bool track_esr_is_valide = false; 

				for (const auto &p : counts_for_esr)
				{
					distance_pointLidar_esr_track=sqrt(pow((bufferRadarESR.ObstacleAlignement_1[i].obstaclePosition.position.x- p.first.first),2)+
													   pow((bufferRadarESR.ObstacleAlignement_1[i].obstaclePosition.position.y- p.first.second),2));
					if (distance_pointLidar_esr_track<Raduis_max_for_esr_box) {track_esr_is_valide=true;
					//std::cout<<"Point x:"  <<p.first.first<<" y:"<<p.first.second<<std::endl;
					//std::cout<<"distance   "<<distance_pointLidar_esr_track<<std::endl;
					}

				}

				if(track_esr_is_valide == true && id < project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE){
					QtyObstacles++;
					//std::cout<<"obstacle valide number "<<i<<std::endl;
 					radaresr.ObstacleAlignement[id].header = bufferRadarESR.ObstacleAlignement_1[i].header;

					radaresr.ObstacleAlignement[id].id     = bufferRadarESR.ObstacleAlignement_1[i].id;

					radaresr.ObstacleAlignement[id].obstaclePosition = bufferRadarESR.ObstacleAlignement_1[i].obstaclePosition;

					//--------------------------------------------
					radaresr.ObstacleAlignement[id].obstacleBodyCenter = bufferRadarESR.ObstacleAlignement_1[i].obstacleBodyCenter;
					//	radaresr.ObstacleAlignement[id].obstacleBodyCenter = bufferRadarESR.ObstacleAlignement_1[i].obstaclePosition;
					//--------------------------------------------


					radaresr.ObstacleAlignement[id].obstacleVelocity = bufferRadarESR.ObstacleAlignement_1[i].obstacleRelativeVelocity;		// ObstacleAlignement[].obstacleVelocity est utilise par la suite, dans la fusion, comme une vitesse relative

					radaresr.ObstacleAlignement[id].obstacleRelativeVelocity = bufferRadarESR.ObstacleAlignement_1[i].obstacleRelativeVelocity;

					radaresr.ObstacleAlignement[id].obstacleAcceleration = bufferRadarESR.ObstacleAlignement_1[i].obstacleAcceleration;

					radaresr.ObstacleAlignement[id].obstacleDimensions = bufferRadarESR.ObstacleAlignement_1[i].obstacleDimensions;

					radaresr.ObstacleAlignement[id].blinkerInfo = bufferRadarESR.ObstacleAlignement_1[i].blinkerInfo;

					radaresr.ObstacleAlignement[id].cutInAndOut = bufferRadarESR.ObstacleAlignement_1[i].cutInAndOut;

					radaresr.ObstacleAlignement[id].obstacleType = bufferRadarESR.ObstacleAlignement_1[i].obstacleType;

					radaresr.ObstacleAlignement[id].obstacleStatus = bufferRadarESR.ObstacleAlignement_1[i].obstacleStatus;

					radaresr.ObstacleAlignement[id].obstacleBrakeLights = bufferRadarESR.ObstacleAlignement_1[i].obstacleBrakeLights;

					radaresr.ObstacleAlignement[id].cipvFlag = bufferRadarESR.ObstacleAlignement_1[i].cipvFlag;

					radaresr.ObstacleAlignement[id].obstacleReplaced = bufferRadarESR.ObstacleAlignement_1[i].obstacleReplaced;

					radaresr.ObstacleAlignement[id].obstacleValid = bufferRadarESR.ObstacleAlignement_1[i].obstacleValid;

					radaresr.ObstacleAlignement[id].obstacleAge = bufferRadarESR.ObstacleAlignement_1[i].obstacleAge;

					radaresr.ObstacleAlignement[id].obstacleLane = bufferRadarESR.ObstacleAlignement_1[i].obstacleLane;

					radaresr.ObstacleAlignement[id].obstacleAngle = bufferRadarESR.ObstacleAlignement_1[i].obstacleAngle;

					radaresr.ObstacleAlignement[id].obstacleAngleVariance = bufferRadarESR.ObstacleAlignement_1[i].obstacleAngleVariance;

					radaresr.ObstacleAlignement[id].obstacleAngleRate = bufferRadarESR.ObstacleAlignement_1[i].obstacleAngleRate;

					radaresr.ObstacleAlignement[id].obstacleScaleChange = bufferRadarESR.ObstacleAlignement_1[i].obstacleScaleChange;

					radaresr.ObstacleAlignement[id].vision_only_sign_type = bufferRadarESR.ObstacleAlignement_1[i].visionOnlySignType;

					radaresr.ObstacleAlignement[id].visionOnlySupplementarySignType = bufferRadarESR.ObstacleAlignement_1[i].visionOnlySupplementarySignType;

					radaresr.ObstacleAlignement[id].signPosition = bufferRadarESR.ObstacleAlignement_1[i].signPosition;

					radaresr.ObstacleAlignement[id].filterType = bufferRadarESR.ObstacleAlignement_1[i].filterType;

					radaresr.ObstacleAlignement[id].obstaclePoseVariance = bufferRadarESR.ObstacleAlignement_1[i].obstaclePoseVariance;

					radaresr.ObstacleAlignement[id].obstacleVelocityVariance = bufferRadarESR.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;	// ObstacleAlignement[].obstacleVelocityVariance est utilise par la suite, dans la fusion, comme une variance de vitesse relative

					radaresr.ObstacleAlignement[id].obstacleRelativeVelocityVariance = bufferRadarESR.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;

					radaresr.ObstacleAlignement[id].groundHeight = bufferRadarESR.ObstacleAlignement_1[i].groundHeight;

					radaresr.ObstacleAlignement[id].classificationProbability = bufferRadarESR.ObstacleAlignement_1[i].classificationProbability;

					radaresr.ObstacleAlignement[id].dateAcquisition = bufferRadarESR.ObstacleAlignement_1[i].dateAcquisition;

					radaresr.ObstacleAlignement[id].obstacleClass = 0;

					id++; // added
				}
			}
 
				cell_pointcloud_for_esr.clear();
				counts_for_esr.clear();

			radaresr.header = bufferRadarESR.header;
			radaresr.QtyObstacles.data = QtyObstacles;
			radaresr.odom = bufferRadarESR.odom;

			std::cout<<"QTY Obstacle ESR: "<<bufferRadarESR.QtyObstacles<<std::endl;

			receivedRadarESR = false;

			pub_radar_ESR_filtering.publish(radaresr);
		}

		if (receivedLidar)
		{	
			project_s_msgs::ObstacleAlignmentReport lidaribeo;

			uint QtyObstacles = 0;

			uint id =0;
			float distance_pointLidar_ibeo_objet;

			for(int i=0; i < bufferLidar.ObstacleAlignement_1.size(); i++)
			{		
					bool objet_lidar_is_valide = false; 

					// Setting maximum ibeo bounding box default size 

											//unit number_of_cell_beside = 0;
						for (const auto &p : counts_for_ibeo)
						{
							distance_pointLidar_ibeo_objet=sqrt(pow((bufferLidar.ObstacleAlignement_1[i].obstaclePosition.position.x- p.first.first),2)+
																pow((bufferLidar.ObstacleAlignement_1[i].obstaclePosition.position.y- p.first.second),2));


							
							if (distance_pointLidar_ibeo_objet<Raduis_max_for_ibeo_box) {
								objet_lidar_is_valide = true;
								std::cout<<"distance objet-pointcloud  "<<distance_pointLidar_ibeo_objet<<std::endl;
								std::cout<<"box center y  "<<bufferLidar.ObstacleAlignement_1[i].obstaclePosition.position.y<<std::endl;
								std::cout<<"box center x  "<<bufferLidar.ObstacleAlignement_1[i].obstaclePosition.position.x<<std::endl;

							}
						}

					if (bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.x > obstacleDimensions_default_ibeo_x || 
						bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.y > obstacleDimensions_default_ibeo_y) {



						if (objet_lidar_is_valide && id < project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE)
						{

							if (bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.x > obstacleDimensions_default_ibeo_x &&
								bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.y > obstacleDimensions_default_ibeo_y)
								{
								lidaribeo.ObstacleAlignement[id].obstacleDimensions.x =obstacleDimensions_default_ibeo_x;
								lidaribeo.ObstacleAlignement[id].obstacleDimensions.y =obstacleDimensions_default_ibeo_y;
								}

							else if (bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.x > obstacleDimensions_default_ibeo_x &&
									bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.y < obstacleDimensions_default_ibeo_y)
								{
								lidaribeo.ObstacleAlignement[id].obstacleDimensions.x = obstacleDimensions_default_ibeo_x;
								lidaribeo.ObstacleAlignement[id].obstacleDimensions.y = bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.y;
								}

							else if (bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.y > obstacleDimensions_default_ibeo_y &&
									bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.x < obstacleDimensions_default_ibeo_x)
								{
								lidaribeo.ObstacleAlignement[id].obstacleDimensions.y = obstacleDimensions_default_ibeo_y;
								lidaribeo.ObstacleAlignement[id].obstacleDimensions.x = bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.x;
								}
						}
					}
					else if (objet_lidar_is_valide && id < project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE)
					{
							//lidaribeo.ObstacleAlignement[id].obstacleDimensions = bufferLidar.ObstacleAlignement_1[i].obstacleDimensions;
								lidaribeo.ObstacleAlignement[id].obstacleDimensions.x = bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.x;
								lidaribeo.ObstacleAlignement[id].obstacleDimensions.y = bufferLidar.ObstacleAlignement_1[i].obstacleDimensions.y;

							objet_lidar_is_valide = true;
					}

			

				if(	objet_lidar_is_valide == true && id < project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE){
					QtyObstacles++;
					
					lidaribeo.ObstacleAlignement[id].header = bufferLidar.ObstacleAlignement_1[i].header;

					lidaribeo.ObstacleAlignement[id].id     = bufferLidar.ObstacleAlignement_1[i].id;

					lidaribeo.ObstacleAlignement[id].obstaclePosition = bufferLidar.ObstacleAlignement_1[i].obstaclePosition;


					//--------------------------------------------

					lidaribeo.ObstacleAlignement[id].obstacleBodyCenter = bufferLidar.ObstacleAlignement_1[i].obstacleBodyCenter;
					//lidaribeo.ObstacleAlignement[i].obstacleBodyCenter = bufferLidar.ObstacleAlignement_1[i].obstaclePosition;

					//--------------------------------------------

					lidaribeo.ObstacleAlignement[id].obstacleVelocity = bufferLidar.ObstacleAlignement_1[i].obstacleRelativeVelocity;		// ObstacleAlignement[].obstacleVelocity est utilise par la suite, dans la fusion, comme une vitesse relative

					lidaribeo.ObstacleAlignement[id].obstacleRelativeVelocity = bufferLidar.ObstacleAlignement_1[i].obstacleRelativeVelocity;

					lidaribeo.ObstacleAlignement[id].obstacleAcceleration = bufferLidar.ObstacleAlignement_1[i].obstacleAcceleration;

					lidaribeo.ObstacleAlignement[id].blinkerInfo = bufferLidar.ObstacleAlignement_1[i].blinkerInfo;

					lidaribeo.ObstacleAlignement[id].cutInAndOut = bufferLidar.ObstacleAlignement_1[i].cutInAndOut;

					lidaribeo.ObstacleAlignement[id].obstacleType = bufferLidar.ObstacleAlignement_1[i].obstacleType;

					lidaribeo.ObstacleAlignement[id].obstacleStatus = bufferLidar.ObstacleAlignement_1[i].obstacleStatus;

					lidaribeo.ObstacleAlignement[id].obstacleBrakeLights = bufferLidar.ObstacleAlignement_1[i].obstacleBrakeLights;

					lidaribeo.ObstacleAlignement[id].cipvFlag = bufferLidar.ObstacleAlignement_1[i].cipvFlag;

					lidaribeo.ObstacleAlignement[id].obstacleReplaced = bufferLidar.ObstacleAlignement_1[i].obstacleReplaced;

					lidaribeo.ObstacleAlignement[id].obstacleValid = bufferLidar.ObstacleAlignement_1[i].obstacleValid;

					lidaribeo.ObstacleAlignement[id].obstacleAge = bufferLidar.ObstacleAlignement_1[i].obstacleAge;

					lidaribeo.ObstacleAlignement[id].obstacleLane = bufferLidar.ObstacleAlignement_1[i].obstacleLane;

					lidaribeo.ObstacleAlignement[id].obstacleAngle = bufferLidar.ObstacleAlignement_1[i].obstacleAngle;

					lidaribeo.ObstacleAlignement[id].obstacleAngleVariance = bufferLidar.ObstacleAlignement_1[i].obstacleAngleVariance;

					lidaribeo.ObstacleAlignement[id].obstacleAngleRate = bufferLidar.ObstacleAlignement_1[i].obstacleAngleRate;

					lidaribeo.ObstacleAlignement[id].obstacleScaleChange = bufferLidar.ObstacleAlignement_1[i].obstacleScaleChange;

					lidaribeo.ObstacleAlignement[id].vision_only_sign_type = bufferLidar.ObstacleAlignement_1[i].visionOnlySignType;

					lidaribeo.ObstacleAlignement[id].visionOnlySupplementarySignType = bufferLidar.ObstacleAlignement_1[i].visionOnlySupplementarySignType;

					lidaribeo.ObstacleAlignement[id].signPosition = bufferLidar.ObstacleAlignement_1[i].signPosition;

					lidaribeo.ObstacleAlignement[id].filterType = bufferLidar.ObstacleAlignement_1[i].filterType;

					lidaribeo.ObstacleAlignement[id].obstaclePoseVariance = bufferLidar.ObstacleAlignement_1[i].obstaclePoseVariance;

					lidaribeo.ObstacleAlignement[id].obstacleVelocityVariance = bufferLidar.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;	// ObstacleAlignement[].obstacleVelocityVariance est utilise par la suite, dans la fusion, comme une variance de vitesse relative

					lidaribeo.ObstacleAlignement[id].obstacleRelativeVelocityVariance = bufferLidar.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;

					lidaribeo.ObstacleAlignement[id].groundHeight = bufferLidar.ObstacleAlignement_1[i].groundHeight;

					lidaribeo.ObstacleAlignement[id].classificationProbability = bufferLidar.ObstacleAlignement_1[i].classificationProbability;

					lidaribeo.ObstacleAlignement[id].dateAcquisition = bufferLidar.ObstacleAlignement_1[i].dateAcquisition;

					lidaribeo.ObstacleAlignement[id].obstacleClass = 0;

					id++;
				}
			}


			cell_pointcloud_for_ibeo.clear();
			counts_for_ibeo.clear();
			lidaribeo.header = bufferLidar.header;
			lidaribeo.QtyObstacles.data = QtyObstacles;
			lidaribeo.odom = bufferLidar.odom;

			std::cout<<"QTY Obstacle IBEO: "<<bufferLidar.QtyObstacles<<std::endl;

			receivedLidar = false;

			pub_lidar_obstacles_filtering.publish(lidaribeo);
		}

		if (receivedCameraMe)
		{
			project_s_msgs::ObstacleAlignmentReport camme;

			uint QtyObstacles = 0;

			for(int i=0; i < bufferCameraMe.ObstacleAlignement_1.size(); i++)
			{		
				if(i < project_s_msgs::ObstacleAlignmentReport::OBSTACLE_ALIGNMENT_REPORT_SIZE){
					QtyObstacles++;

					camme.ObstacleAlignement[i].header = bufferCameraMe.ObstacleAlignement_1[i].header;

					camme.ObstacleAlignement[i].id     = bufferCameraMe.ObstacleAlignement_1[i].id;

					camme.ObstacleAlignement[i].obstaclePosition = bufferCameraMe.ObstacleAlignement_1[i].obstaclePosition;


				//--------------------------------------------

				camme.ObstacleAlignement[i].obstacleBodyCenter = bufferCameraMe.ObstacleAlignement_1[i].obstacleBodyCenter;
				//camme.ObstacleAlignement[i].obstacleBodyCenter = bufferCameraMe.ObstacleAlignement_1[i].obstaclePosition;
				//--------------------------------------------



					camme.ObstacleAlignement[i].obstacleVelocity = bufferCameraMe.ObstacleAlignement_1[i].obstacleRelativeVelocity;		// ObstacleAlignement[].obstacleVelocity est utilise par la suite, dans la fusion, comme une vitesse relative

					camme.ObstacleAlignement[i].obstacleRelativeVelocity = bufferCameraMe.ObstacleAlignement_1[i].obstacleRelativeVelocity;

					camme.ObstacleAlignement[i].obstacleAcceleration = bufferCameraMe.ObstacleAlignement_1[i].obstacleAcceleration;

					camme.ObstacleAlignement[i].obstacleDimensions = bufferCameraMe.ObstacleAlignement_1[i].obstacleDimensions;

					camme.ObstacleAlignement[i].blinkerInfo = bufferCameraMe.ObstacleAlignement_1[i].blinkerInfo;

					camme.ObstacleAlignement[i].cutInAndOut = bufferCameraMe.ObstacleAlignement_1[i].cutInAndOut;

					camme.ObstacleAlignement[i].obstacleType = bufferCameraMe.ObstacleAlignement_1[i].obstacleType;

					camme.ObstacleAlignement[i].obstacleStatus = bufferCameraMe.ObstacleAlignement_1[i].obstacleStatus;

					camme.ObstacleAlignement[i].obstacleBrakeLights = bufferCameraMe.ObstacleAlignement_1[i].obstacleBrakeLights;

					camme.ObstacleAlignement[i].cipvFlag = bufferCameraMe.ObstacleAlignement_1[i].cipvFlag;

					camme.ObstacleAlignement[i].obstacleReplaced = bufferCameraMe.ObstacleAlignement_1[i].obstacleReplaced;

					camme.ObstacleAlignement[i].obstacleValid = bufferCameraMe.ObstacleAlignement_1[i].obstacleValid;

					camme.ObstacleAlignement[i].obstacleAge = bufferCameraMe.ObstacleAlignement_1[i].obstacleAge;

					camme.ObstacleAlignement[i].obstacleLane = bufferCameraMe.ObstacleAlignement_1[i].obstacleLane;

					camme.ObstacleAlignement[i].obstacleAngle = bufferCameraMe.ObstacleAlignement_1[i].obstacleAngle;

					camme.ObstacleAlignement[i].obstacleAngleVariance = bufferCameraMe.ObstacleAlignement_1[i].obstacleAngleVariance;

					camme.ObstacleAlignement[i].obstacleAngleRate = bufferCameraMe.ObstacleAlignement_1[i].obstacleAngleRate;

					camme.ObstacleAlignement[i].obstacleScaleChange = bufferCameraMe.ObstacleAlignement_1[i].obstacleScaleChange;

					camme.ObstacleAlignement[i].vision_only_sign_type = bufferCameraMe.ObstacleAlignement_1[i].visionOnlySignType;

					camme.ObstacleAlignement[i].visionOnlySupplementarySignType = bufferCameraMe.ObstacleAlignement_1[i].visionOnlySupplementarySignType;

					camme.ObstacleAlignement[i].signPosition = bufferCameraMe.ObstacleAlignement_1[i].signPosition;

					camme.ObstacleAlignement[i].filterType = bufferCameraMe.ObstacleAlignement_1[i].filterType;

					camme.ObstacleAlignement[i].obstaclePoseVariance = bufferCameraMe.ObstacleAlignement_1[i].obstaclePoseVariance;

					camme.ObstacleAlignement[i].obstacleVelocityVariance = bufferCameraMe.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;	// ObstacleAlignement[].obstacleVelocityVariance est utilise par la suite, dans la fusion, comme une variance de vitesse relative

					camme.ObstacleAlignement[i].obstacleRelativeVelocityVariance = bufferCameraMe.ObstacleAlignement_1[i].obstacleRelativeVelocityVariance;

					camme.ObstacleAlignement[i].groundHeight = bufferCameraMe.ObstacleAlignement_1[i].groundHeight;

					camme.ObstacleAlignement[i].classificationProbability = bufferCameraMe.ObstacleAlignement_1[i].classificationProbability;

					camme.ObstacleAlignement[i].dateAcquisition = bufferCameraMe.ObstacleAlignement_1[i].dateAcquisition;

					camme.ObstacleAlignement[i].obstacleClass = 0;
				}
			}

			camme.header = bufferCameraMe.header;
			camme.QtyObstacles.data = QtyObstacles;
			camme.odom = bufferCameraMe.odom;

			std::cout<<"QTY Obstacle Meye: "<<bufferCameraMe.QtyObstacles<<std::endl;

			receivedCameraMe = false;

			pub_camera_me_obstacles_filtering.publish(camme);
		}

		loop_rate.sleep();		
	}

	return 0;
}








