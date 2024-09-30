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

#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include "nav_msgs/Odometry.h"
#include <tf/transform_broadcaster.h>

#include "project_s_msgs/ObstacleSynchronizeReport.h"
#include "project_s_msgs/ObstacleFusionReport.h"
#include "project_s_msgs/GenericSmartData.h"

#include "project_s_msgs/Configurations.h"

// à compléter si d'autres capteurs
#define NBR_SENSOR		3	// 3 capteurs (Lidar, Radar, Camera), x 10 pistes locales max. En concordance avec ObstacleSynchronizeReport.msg
#define ID_LIDAR		0
#define ID_RADAR		1
#define ID_CAMERA_ME		2

#define	IDLE_TRACK	0
#define	PRE_TRACK	1
#define	POST_TRACK	2
#define	CURRENT_TRACK	3

project_s_msgs::ObstacleSynchronizeReport ptrSensor_;
project_s_msgs::ObstacleFusionReport extractedObstaclesLocale, Predictions, Confidence, Assignment, extractedObstacles;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedLocalTracksSynchro = false;
void localTracksSynchroCallback(const project_s_msgs::ObstacleSynchronizeReport::ConstPtr& ObstacleArray)
{
	ptrSensor_ = *ObstacleArray;

	receivedLocalTracksSynchro = true;
}

bool receivedLocalTracksFusion = false;
void obstacleLocaleCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& genericObstacleFusion)
{
	extractedObstaclesLocale = *genericObstacleFusion;

	receivedLocalTracksFusion = true;
}

bool receivedGlobalTracksPrediction = false;
void predictionCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& genericObstacleFusion)
{
	Predictions = *genericObstacleFusion;

	receivedGlobalTracksPrediction = true;
}

bool receivedGlobalTracksFusion = false;
void obstacleCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& genericObstacleFusion)
{
	extractedObstacles = *genericObstacleFusion;

	receivedGlobalTracksFusion = true;
}

bool receivedGlobalTracksConfidence = false;
void confidenceCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& genericObstacleFusion)
{
	Confidence = *genericObstacleFusion;

	receivedGlobalTracksConfidence = true;
}

bool receivedGlobalTracksAssignment = false;
void assignmentCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr& genericObstacleFusion)
{
	Assignment = *genericObstacleFusion;

	receivedGlobalTracksAssignment = true;
}

//-------------------------------------------------------------------------------------------------
// local functions
//-------------------------------------------------------------------------------------------------
geometry_msgs::Point computeGlobalPosition(geometry_msgs::Point point, nav_msgs::Odometry odom)
{	// calculs de la position dans le repère absolu,
	// à partir de la position dans le repère de l'égo (position déjà alignée)
	geometry_msgs::Point p;
	double theta = tf::getYaw(odom.pose.pose.orientation);

	p.x = odom.pose.pose.position.x + (point.x * cos(theta) - point.y * sin(theta));
	p.y = odom.pose.pose.position.y + (point.x * sin(theta) + point.y * cos(theta));
	p.z = odom.pose.pose.position.z +  point.z;

	return p;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//char * model = argv[2];

	//std::string topic1 = std::string(model);  

	ros::init(argc, argv, std::string("obstacles_fusion_markers"));

	ros::NodeHandle n;

	ros::Subscriber subLocalTracksSynchro = n.subscribe(std::string("/local_tracks_synchro_data"), 1, localTracksSynchroCallback);
	ros::Publisher pub_locale_tracks_synchro_rel = n.advertise<visualization_msgs::Marker>(std::string("/local_tracks_synchro_markers"), NBR_SENSOR);
	ros::Publisher pub_locale_tracks_synchro_abs = n.advertise<visualization_msgs::Marker>(std::string("/local_tracks_synchro_absolu_markers"), NBR_SENSOR);
	visualization_msgs::Marker relativeLocalTracksSynchroMarker[NBR_SENSOR], absoluLocalTracksSynchroMarker[NBR_SENSOR];

	ros::Subscriber subObstacles_Locale = n.subscribe(std::string("/local_tracks_fusion_data"), 1, obstacleLocaleCallback);
	ros::Publisher pub_locale_rel = n.advertise<visualization_msgs::Marker>(std::string("/local_tracks_fusion_markers"), 1);
	ros::Publisher pub_locale_abs = n.advertise<visualization_msgs::Marker>(std::string("/local_tracks_fusion_absolu_markers"), 1);

	ros::Subscriber sub_Prediction = n.subscribe(std::string("/global_tracks_prediction_data"), 1, predictionCallback);
	ros::Publisher pub_prediction_rel = n.advertise<visualization_msgs::Marker>(std::string("/global_tracks_prediction_markers"), 1);
	ros::Publisher pub_prediction_abs = n.advertise<visualization_msgs::Marker>(std::string("/global_tracks_prediction_absolu_markers"), 1);
	visualization_msgs::Marker relativeLocalMarker, absoluLocalMarker;
	visualization_msgs::Marker relativePredictionMarker, absoluPredictionMarker;

	ros::Subscriber subObstacles = n.subscribe(std::string("/global_tracks_update_data"), 1, obstacleCallback);
	ros::Publisher pubMarker = n.advertise<visualization_msgs::Marker>(std::string("/global_tracks_update_markers"), 1);
	ros::Publisher pub_obstacle_abs = n.advertise<visualization_msgs::Marker>(std::string("/global_tracks_update_absolu_markers"), 10);
	visualization_msgs::Marker marker, absoluObstacleMarker;

	ros::Subscriber sub_global_tracks_confidence = n.subscribe(std::string("/global_tracks_confidence_data"), 1, confidenceCallback);
	ros::Publisher pub_global_tracks_confidence_relative = n.advertise<visualization_msgs::MarkerArray>(std::string("/global_tracks_confidence_markers"), 1);
	ros::Publisher pub_global_tracks_confidence_absolu   = n.advertise<visualization_msgs::MarkerArray>(std::string("/global_tracks_confidence_absolu_markers"), 1);
	ros::Publisher pub_global_tracks_confidence_ID_relative = n.advertise<visualization_msgs::MarkerArray>(std::string("/global_tracks_confidence_ID_markers"), 1);
	visualization_msgs::MarkerArray relativeGlobalTracksConfidenceMarkerArray, absoluGlobalTracksConfidenceMarkerArray;
	visualization_msgs::MarkerArray relativeGlobalTracksConfidence_ID_MarkerArray;

	ros::Subscriber sub_global_tracks_assignment = n.subscribe(std::string("/obstacles_assignment_data"), 1, assignmentCallback);
	ros::Publisher pub_global_tracks_assignment_relative = n.advertise<visualization_msgs::MarkerArray>(std::string("/global_tracks_assignment_markers"), 1);
	ros::Publisher pub_global_tracks_assignment_absolu   = n.advertise<visualization_msgs::MarkerArray>(std::string("/global_tracks_assignement_absolu_markers"), 1);
	visualization_msgs::MarkerArray relativeGlobalTracksAssignmentMarkerArray, absoluGlobalTracksAssignmentMarkerArray;


//(Amit)---------------------------Bounding Box CornerObstacle Assignment -------------------------
	visualization_msgs::MarkerArray cornerMarkerArray;
	visualization_msgs::Marker 	cornerMarker;
	visualization_msgs::Marker 	obcMarker;

	ros::Publisher pub_corner_marker = n.advertise<visualization_msgs::MarkerArray>(std::string("/corner_markers"), 1);
	ros::Publisher pub_obc_marker = n.advertise<visualization_msgs::Marker>(std::string("/obc_markers"), 1);
//-------------------------------------------------------------------------------------------------


	ros::Duration blink_of_an_eye(0.01); 

	ros::Rate loop_rate(100);

	while(n.ok())
	{
		ros::spinOnce();


//-------------------TEST----Object body center-------------

		if (receivedGlobalTracksAssignment)
		{
			//receivedGlobalTracksAssignment = false;

			obcMarker = visualization_msgs::Marker();

			obcMarker.header.frame_id = "/base_link";
			obcMarker.header.stamp = ros::Time::now();
			obcMarker.lifetime = ros::Duration(0.2);
			
			obcMarker.ns = "Obstacles_Assignment";
			obcMarker.type = visualization_msgs::Marker::CUBE_LIST;
			obcMarker.scale.x = 0.5;
			obcMarker.scale.y = 0.5;
			obcMarker.scale.z = 0.5;				
			obcMarker.color.r = 0.0f;
			obcMarker.color.g = 0.0f;
			obcMarker.color.b = 1.0f;
			obcMarker.color.a = 1.0;
			obcMarker.action = visualization_msgs::Marker::MODIFY;
			obcMarker.pose.orientation.w = 1.0;

			for (int i = 0; i < Assignment.QtyObstacles.data; i++)

			{
				obcMarker.id =i;	
				obcMarker.points.push_back(Assignment.ObstacleFusion[i].obstacleBodyCenter.position);
				
			}

			pub_obc_marker.publish(obcMarker);
		
			}
//----------------------


//-------------------------------------------------------------------------------------------------
		if (receivedLocalTracksSynchro)
		{
			receivedLocalTracksSynchro = false;

			for(int k = 0; k < NBR_SENSOR; k++)
//int k = ID_CAMERA_ME;
			{
				// Markers pour le repère relatif
				relativeLocalTracksSynchroMarker[k] = visualization_msgs::Marker();

				relativeLocalTracksSynchroMarker[k].header.frame_id = "/base_link";
				relativeLocalTracksSynchroMarker[k].header.stamp = ros::Time::now();
				relativeLocalTracksSynchroMarker[k].lifetime = ros::Duration();
				relativeLocalTracksSynchroMarker[k].id = 300 + k;
				relativeLocalTracksSynchroMarker[k].ns = "Local_Tracks_Synchro";
				relativeLocalTracksSynchroMarker[k].type = visualization_msgs::Marker::SPHERE_LIST;
				relativeLocalTracksSynchroMarker[k].scale.x = 0.5;
				relativeLocalTracksSynchroMarker[k].scale.y = 0.5;
				relativeLocalTracksSynchroMarker[k].scale.z = 0.5;
				switch(k){
				case ID_LIDAR :
					relativeLocalTracksSynchroMarker[k].color.r = 0.0f;
					relativeLocalTracksSynchroMarker[k].color.g = 1.0f;
					relativeLocalTracksSynchroMarker[k].color.b = 0.0f;
					break;
				case ID_RADAR :
					relativeLocalTracksSynchroMarker[k].color.r = 0.0f;
					relativeLocalTracksSynchroMarker[k].color.g = 0.0f;
					relativeLocalTracksSynchroMarker[k].color.b = 1.0f;
					break;
				case ID_CAMERA_ME :
					relativeLocalTracksSynchroMarker[k].color.r = 1.0f;
					relativeLocalTracksSynchroMarker[k].color.g = 0.0f;
					relativeLocalTracksSynchroMarker[k].color.b = 0.0f;
					break;
				}
				relativeLocalTracksSynchroMarker[k].color.a = 1.0;
				relativeLocalTracksSynchroMarker[k].action = visualization_msgs::Marker::MODIFY;
				relativeLocalTracksSynchroMarker[k].pose.orientation.w = 1;

				// Markers pour le repère absolu
				absoluLocalTracksSynchroMarker[k] = visualization_msgs::Marker();

				absoluLocalTracksSynchroMarker[k].header.frame_id = "/odom";
				absoluLocalTracksSynchroMarker[k].header.stamp = ros::Time::now();
				absoluLocalTracksSynchroMarker[k].lifetime = ros::Duration();
				absoluLocalTracksSynchroMarker[k].id = 350 + k;
				absoluLocalTracksSynchroMarker[k].ns = "Local_Tracks_Synchro";
				absoluLocalTracksSynchroMarker[k].type = visualization_msgs::Marker::CUBE_LIST;
				absoluLocalTracksSynchroMarker[k].scale.x = 0.5;
				absoluLocalTracksSynchroMarker[k].scale.y = 0.5;
				absoluLocalTracksSynchroMarker[k].scale.z = 0.5;
				switch(k){
				case ID_LIDAR :
					absoluLocalTracksSynchroMarker[k].color.r = 0.0f;
					absoluLocalTracksSynchroMarker[k].color.g = 1.0f;
					absoluLocalTracksSynchroMarker[k].color.b = 0.0f;
					break;
				case ID_RADAR :
					absoluLocalTracksSynchroMarker[k].color.r = 0.0f;
					absoluLocalTracksSynchroMarker[k].color.g = 0.0f;
					absoluLocalTracksSynchroMarker[k].color.b = 1.0f;
					break;
				case ID_CAMERA_ME :
					absoluLocalTracksSynchroMarker[k].color.r = 1.0f;
					absoluLocalTracksSynchroMarker[k].color.g = 0.0f;
					absoluLocalTracksSynchroMarker[k].color.b = 0.0f;
					break;
				}
				absoluLocalTracksSynchroMarker[k].color.a = 1.0;
				absoluLocalTracksSynchroMarker[k].action = visualization_msgs::Marker::MODIFY;
				absoluLocalTracksSynchroMarker[k].pose.orientation.w = 1;

				for (int i = 0; i < ptrSensor_.ObstacleSynchronizeReport[k].QtyObstacles.data; i++)
				{
					relativeLocalTracksSynchroMarker[k].points.push_back(ptrSensor_.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstaclePosition.position);
#ifdef PROJECT_S_SIMULATION
					absoluLocalTracksSynchroMarker[k].points.push_back(computeGlobalPosition(ptrSensor_.ObstacleSynchronizeReport[k].ObstacleAlignement[i].obstaclePosition.position, 
														 ptrSensor_.odom));
#endif
				}

				pub_locale_tracks_synchro_rel.publish(relativeLocalTracksSynchroMarker[k]);
#ifdef PROJECT_S_SIMULATION
				pub_locale_tracks_synchro_abs.publish(absoluLocalTracksSynchroMarker[k]);
#endif
			}
		}

//-------------------------------------------------------------------------------------------------
		if (receivedLocalTracksFusion)
		{
			receivedLocalTracksFusion = false;

			// Markers pour le repère relatif
			relativeLocalMarker = visualization_msgs::Marker();

			relativeLocalMarker.header.frame_id = "/base_link";
			relativeLocalMarker.header.stamp = ros::Time::now();
			relativeLocalMarker.lifetime = ros::Duration();
			relativeLocalMarker.id = 331;
			relativeLocalMarker.ns = "Obstacles_Fusion";
			relativeLocalMarker.type = visualization_msgs::Marker::SPHERE_LIST;
			relativeLocalMarker.scale.x = 0.5;
			relativeLocalMarker.scale.y = 0.5;
			relativeLocalMarker.scale.z = 0.5;
			relativeLocalMarker.color.r = 1.0f;
			relativeLocalMarker.color.g = 1.0f;
			relativeLocalMarker.color.b = 1.0f;
			relativeLocalMarker.color.a = 1.0;
			relativeLocalMarker.action = visualization_msgs::Marker::MODIFY;
			relativeLocalMarker.pose.orientation.w = 1;

			// Markers pour le repère absolu
			absoluLocalMarker = visualization_msgs::Marker();

			absoluLocalMarker.header.frame_id = "/odom";
			absoluLocalMarker.header.stamp = ros::Time::now();
			absoluLocalMarker.lifetime = ros::Duration();
			absoluLocalMarker.id = 332;
			absoluLocalMarker.ns = "Obstacles_Fusion";
			absoluLocalMarker.type = visualization_msgs::Marker::CUBE_LIST;
			absoluLocalMarker.scale.x = 0.5;
			absoluLocalMarker.scale.y = 0.5;
			absoluLocalMarker.scale.z = 0.5;
			absoluLocalMarker.color.r = 1.0f;
			absoluLocalMarker.color.g = 1.0f;
			absoluLocalMarker.color.b = 1.0f;
			absoluLocalMarker.color.a = 1.0;
/*
if(extractedObstaclesLocale.ObstacleFusion[0].obstacleClass == project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN){
absoluLocalMarker.color.r = 1.0f;
absoluLocalMarker.color.g = 0.0f;
absoluLocalMarker.color.b = 0.0f;
}*/
			absoluLocalMarker.action = visualization_msgs::Marker::MODIFY;
			absoluLocalMarker.pose.orientation.w = 1;

			for (int i = 0; i < extractedObstaclesLocale.QtyObstacles.data; i++)
			{
				relativeLocalMarker.points.push_back(extractedObstaclesLocale.ObstacleFusion[i].obstaclePosition.position);
#ifdef PROJECT_S_SIMULATION
				absoluLocalMarker.points.push_back(computeGlobalPosition(extractedObstaclesLocale.ObstacleFusion[i].obstaclePosition.position, 
											 extractedObstaclesLocale.odom));
#endif
			}

			pub_locale_rel.publish(relativeLocalMarker);
#ifdef PROJECT_S_SIMULATION
			pub_locale_abs.publish(absoluLocalMarker);
#endif
		}

//-------------------------------------------------------------------------------------------------
		if (receivedGlobalTracksPrediction)
		{
			receivedGlobalTracksPrediction = false;

			// Markers pour le repère relatif
			relativePredictionMarker = visualization_msgs::Marker();

			relativePredictionMarker.header.frame_id = "/base_link";
			relativePredictionMarker.header.stamp = ros::Time::now();
			relativePredictionMarker.lifetime = ros::Duration();
			relativePredictionMarker.id = 333;
			relativePredictionMarker.ns = "Obstacles_Prediction";
			relativePredictionMarker.type = visualization_msgs::Marker::SPHERE_LIST;
			relativePredictionMarker.scale.x = 0.5;
			relativePredictionMarker.scale.y = 0.5;
			relativePredictionMarker.scale.z = 0.5;
			relativePredictionMarker.color.r = 1.0f;
			relativePredictionMarker.color.g = 1.0f;
			relativePredictionMarker.color.b = 1.0f;
			relativePredictionMarker.color.a = 1.0;
			relativePredictionMarker.action = visualization_msgs::Marker::MODIFY;
			relativePredictionMarker.pose.orientation.w = 1;

			// Markers pour le repère absolu
			absoluPredictionMarker = visualization_msgs::Marker();

			absoluPredictionMarker.header.frame_id = "/odom";
			absoluPredictionMarker.header.stamp = ros::Time::now();
			absoluPredictionMarker.lifetime = ros::Duration();
			absoluPredictionMarker.id = 334;
			absoluPredictionMarker.ns = "Obstacles_Prediction";
			absoluPredictionMarker.type = visualization_msgs::Marker::CUBE_LIST;
			absoluPredictionMarker.scale.x = 0.5;
			absoluPredictionMarker.scale.y = 0.5;
			absoluPredictionMarker.scale.z = 0.5;
			absoluPredictionMarker.color.r = 1.0f;
			absoluPredictionMarker.color.g = 1.0f;
			absoluPredictionMarker.color.b = 1.0f;
			absoluPredictionMarker.color.a = 1.0;

if(Predictions.ObstacleFusion[0].obstacleClass == project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN){
absoluPredictionMarker.color.r = 1.0f;
absoluPredictionMarker.color.g = 0.0f;
absoluPredictionMarker.color.b = 0.0f;
}
			absoluPredictionMarker.action = visualization_msgs::Marker::MODIFY;
			absoluPredictionMarker.pose.orientation.w = 1;

			for (int i = 0; i < Predictions.QtyObstacles.data; i++)
			{
				relativePredictionMarker.points.push_back(Predictions.ObstacleFusion[i].obstaclePosition.position);
#ifdef PROJECT_S_SIMULATION
				absoluPredictionMarker.points.push_back(computeGlobalPosition(Predictions.ObstacleFusion[i].obstaclePosition.position, 
											      Predictions.odom));
#endif
			}

			pub_prediction_rel.publish(relativePredictionMarker);
#ifdef PROJECT_S_SIMULATION
			pub_prediction_abs.publish(absoluPredictionMarker);
#endif
		}

//-------------------------------------------------------------------------------------------------
		if (receivedGlobalTracksFusion)
		{
			receivedGlobalTracksFusion = false;

			// Markers pour le repère relatif
			marker = visualization_msgs::Marker();

			marker.header.frame_id = "/base_link";
			marker.header.stamp = ros::Time::now();
			marker.lifetime = ros::Duration();
			marker.id = 363;
			marker.ns = "Obstacles_Update";
			marker.type = visualization_msgs::Marker::SPHERE_LIST;
			marker.scale.x = 0.5;
			marker.scale.y = 0.5;
			marker.scale.z = 0.5;
			marker.color.r = 1.0f;
			marker.color.g = 1.0f;
			marker.color.b = 1.0f;
			marker.color.a = 1.0;
			marker.action = visualization_msgs::Marker::MODIFY;
			marker.pose.orientation.w = 1;

			for (int i = 0; i < extractedObstacles.QtyObstacles.data; i++)
			{
				marker.points.push_back(extractedObstacles.ObstacleFusion[i].obstaclePosition.position);
			}

			pubMarker.publish(marker);

			// Markers pour le repère absolu
			for (int i = 0; i < 10; i++)
			{
				absoluObstacleMarker = visualization_msgs::Marker();

				absoluObstacleMarker.header.frame_id = "/odom";
				absoluObstacleMarker.header.stamp = ros::Time::now();
				absoluObstacleMarker.lifetime = ros::Duration();
				absoluObstacleMarker.id = 364+i;
				absoluObstacleMarker.ns = "Obstacles_Update";
				absoluObstacleMarker.type = visualization_msgs::Marker::CUBE;
				absoluObstacleMarker.scale.x = 0.5;
				absoluObstacleMarker.scale.y = 0.5;
				absoluObstacleMarker.scale.z = 0.5;
				absoluObstacleMarker.action = visualization_msgs::Marker::MODIFY;
				absoluObstacleMarker.pose.orientation.w = 1;

				if(i < extractedObstacles.QtyObstacles.data){

					switch(extractedObstacles.ObstacleFusion[i].obstacleClass){
					default:
					case project_s_msgs::GenericSmartData::OBSTACLE_CLASS_NONE :
					case project_s_msgs::GenericSmartData::OBSTACLE_CLASS_INVALID :
						absoluObstacleMarker.color.r = 1.0f;
						absoluObstacleMarker.color.g = 1.0f;
						absoluObstacleMarker.color.b = 1.0f;
						absoluObstacleMarker.color.a = 1.0;
					break;
					case project_s_msgs::GenericSmartData::OBSTACLE_CLASS_SIGN :
						absoluObstacleMarker.color.r = 1.0f;
						absoluObstacleMarker.color.g = 0.0f;
						absoluObstacleMarker.color.b = 0.0f;
						absoluObstacleMarker.color.a = 1.0;
					break;
					case project_s_msgs::GenericSmartData::OBSTACLE_CLASS_PLOT :
						absoluObstacleMarker.color.r = 0.0f;
						absoluObstacleMarker.color.g = 0.0f;
						absoluObstacleMarker.color.b = 1.0f;
						absoluObstacleMarker.color.a = 1.0;
					break;
					}

#ifdef PROJECT_S_SIMULATION
					absoluObstacleMarker.pose.position =  computeGlobalPosition(extractedObstacles.ObstacleFusion[i].obstaclePosition.position, 
												    extractedObstacles.odom);
#endif
				}
				else{
					//absoluObstacleMarker.color.r = 0.0f;
					//absoluObstacleMarker.color.g = 0.0f;
					//absoluObstacleMarker.color.b = 0.0f;
					//absoluObstacleMarker.color.a = 0.0;
					//absoluObstacleMarker.pose.position.x =
				}

#ifdef PROJECT_S_SIMULATION
				pub_obstacle_abs.publish(absoluObstacleMarker);
#endif
			}
		}

//-------------------------------------------------------------------------------------------------
		if (receivedGlobalTracksConfidence)
		{
			receivedGlobalTracksConfidence = false;

			// Markers pour le repère relatif
			relativeGlobalTracksConfidenceMarkerArray = visualization_msgs::MarkerArray();

			for (int i = 0; i < Confidence.QtyObstacles.data; i++)
			{
				visualization_msgs::Marker relativeGlobalTracksConfidenceMarker = visualization_msgs::Marker();

				relativeGlobalTracksConfidenceMarker.header.frame_id = "/base_link";
				relativeGlobalTracksConfidenceMarker.header.stamp = ros::Time::now();
				relativeGlobalTracksConfidenceMarker.lifetime = ros::Duration(0.2);
				relativeGlobalTracksConfidenceMarker.id = i;
				relativeGlobalTracksConfidenceMarker.ns = "Obstacles_Confidence";
				relativeGlobalTracksConfidenceMarker.type = visualization_msgs::Marker::SPHERE_LIST;
				relativeGlobalTracksConfidenceMarker.scale.x = 0.5;
				relativeGlobalTracksConfidenceMarker.scale.y = 0.5;
				relativeGlobalTracksConfidenceMarker.scale.z = 0.5;
				//relativeGlobalTracksConfidenceMarker.color.r = 1.0f;
				//relativeGlobalTracksConfidenceMarker.color.g = 1.0f;
				//relativeGlobalTracksConfidenceMarker.color.b = 1.0f;
				//relativeGlobalTracksConfidenceMarker.color.a = 1.0;
				relativeGlobalTracksConfidenceMarker.action = visualization_msgs::Marker::MODIFY;
				relativeGlobalTracksConfidenceMarker.pose.orientation.w = 1;

				switch(Confidence.ObstacleFusion[i].existenceState.data){
				default :
					relativeGlobalTracksConfidenceMarker.color.r = 1.0f;
					relativeGlobalTracksConfidenceMarker.color.g = 1.0f;
					relativeGlobalTracksConfidenceMarker.color.b = 0.0f;
					relativeGlobalTracksConfidenceMarker.color.a = 1.0;
					break;
				case IDLE_TRACK :
					relativeGlobalTracksConfidenceMarker.color.r = 0.0f;
					relativeGlobalTracksConfidenceMarker.color.g = 1.0f;
					relativeGlobalTracksConfidenceMarker.color.b = 0.0f;
					relativeGlobalTracksConfidenceMarker.color.a = 1.0;
					break;
				case PRE_TRACK :
					relativeGlobalTracksConfidenceMarker.color.r = 1.0f;
					relativeGlobalTracksConfidenceMarker.color.g = 0.0f;
					relativeGlobalTracksConfidenceMarker.color.b = 0.0f;
					relativeGlobalTracksConfidenceMarker.color.a = 1.0;
					break;
				case POST_TRACK :
					relativeGlobalTracksConfidenceMarker.color.r = 0.0f;
					relativeGlobalTracksConfidenceMarker.color.g = 0.0f;
					relativeGlobalTracksConfidenceMarker.color.b = 1.0f;
					relativeGlobalTracksConfidenceMarker.color.a = 1.0;
					break;
				case CURRENT_TRACK :
					relativeGlobalTracksConfidenceMarker.color.r = 1.0f;
					relativeGlobalTracksConfidenceMarker.color.g = 1.0f;
					relativeGlobalTracksConfidenceMarker.color.b = 1.0f;
					relativeGlobalTracksConfidenceMarker.color.a = 1.0;
					break;
				}

				relativeGlobalTracksConfidenceMarker.points.push_back(Confidence.ObstacleFusion[i].obstaclePosition.position);

				relativeGlobalTracksConfidenceMarkerArray.markers.push_back(relativeGlobalTracksConfidenceMarker);
			}

			pub_global_tracks_confidence_relative.publish(relativeGlobalTracksConfidenceMarkerArray);

			// Markers ID pour le repère relatif
			relativeGlobalTracksConfidence_ID_MarkerArray = visualization_msgs::MarkerArray();

			for (int i = 0; i < Confidence.QtyObstacles.data; i++)
			{
				visualization_msgs::Marker relativeGlobalTracksConfidence_ID_Marker;

				relativeGlobalTracksConfidence_ID_Marker = visualization_msgs::Marker();
				relativeGlobalTracksConfidence_ID_Marker.header.frame_id = "/base_link";
				relativeGlobalTracksConfidence_ID_Marker.header.stamp = ros::Time::now();
				relativeGlobalTracksConfidence_ID_Marker.lifetime = ros::Duration(0.2);
				relativeGlobalTracksConfidence_ID_Marker.id = i;
				relativeGlobalTracksConfidence_ID_Marker.ns = "Obstacles_Confidence_ID";
				relativeGlobalTracksConfidence_ID_Marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
				relativeGlobalTracksConfidence_ID_Marker.scale.x = 1;
				relativeGlobalTracksConfidence_ID_Marker.scale.y = 1;
				relativeGlobalTracksConfidence_ID_Marker.scale.z = 1;
				relativeGlobalTracksConfidence_ID_Marker.color.r = 1.0f;
				relativeGlobalTracksConfidence_ID_Marker.color.g = 1.0f;
				relativeGlobalTracksConfidence_ID_Marker.color.b = 1.0f;
				relativeGlobalTracksConfidence_ID_Marker.color.a = 1.0;
				relativeGlobalTracksConfidence_ID_Marker.action = visualization_msgs::Marker::MODIFY;
				relativeGlobalTracksConfidence_ID_Marker.pose.orientation.w = 1;


				int value =  Confidence.ObstacleFusion[i].id.data;
//				int value =  i;
                         	std::stringstream sstm;
                         	sstm << "ID: " << value;
				std::string text = sstm.str();
				relativeGlobalTracksConfidence_ID_Marker.text = text;

				relativeGlobalTracksConfidence_ID_Marker.pose.position = Confidence.ObstacleFusion[i].obstaclePosition.position;

				relativeGlobalTracksConfidence_ID_MarkerArray.markers.push_back(relativeGlobalTracksConfidence_ID_Marker);
			}

			pub_global_tracks_confidence_ID_relative.publish(relativeGlobalTracksConfidence_ID_MarkerArray);

			// Markers pour le repère absolu
			absoluGlobalTracksConfidenceMarkerArray = visualization_msgs::MarkerArray();

			for (int i = 0; i < Confidence.QtyObstacles.data; i++)
			{
				visualization_msgs::Marker absoluGlobalTracksConfidenceMarker = visualization_msgs::Marker();

				absoluGlobalTracksConfidenceMarker.header.frame_id = "/odom";
				absoluGlobalTracksConfidenceMarker.header.stamp = ros::Time::now();
				absoluGlobalTracksConfidenceMarker.lifetime = ros::Duration(0.2);
				absoluGlobalTracksConfidenceMarker.id = 340+i;
				absoluGlobalTracksConfidenceMarker.ns = "Obstacles_Confidence";
				absoluGlobalTracksConfidenceMarker.type = visualization_msgs::Marker::CUBE;
				absoluGlobalTracksConfidenceMarker.scale.x = 0.5;
				absoluGlobalTracksConfidenceMarker.scale.y = 0.5;
				absoluGlobalTracksConfidenceMarker.scale.z = 0.5;
				//absoluGlobalTracksConfidenceMarker.color.r = 1.0f;
				//absoluGlobalTracksConfidenceMarker.color.g = 1.0f;
				//absoluGlobalTracksConfidenceMarker.color.b = 1.0f;
				//absoluGlobalTracksConfidenceMarker.color.a = 1.0;
				absoluGlobalTracksConfidenceMarker.action = visualization_msgs::Marker::MODIFY;
				absoluGlobalTracksConfidenceMarker.pose.orientation.w = 1;

				switch(Confidence.ObstacleFusion[i].existenceState.data){
				default :
					absoluGlobalTracksConfidenceMarker.color.r = 1.0f;
					absoluGlobalTracksConfidenceMarker.color.g = 1.0f;
					absoluGlobalTracksConfidenceMarker.color.b = 0.0f;
					absoluGlobalTracksConfidenceMarker.color.a = 1.0;
					break;
				case IDLE_TRACK :
					absoluGlobalTracksConfidenceMarker.color.r = 0.0f;
					absoluGlobalTracksConfidenceMarker.color.g = 1.0f;
					absoluGlobalTracksConfidenceMarker.color.b = 0.0f;
					absoluGlobalTracksConfidenceMarker.color.a = 1.0;
					break;
				case PRE_TRACK :
					absoluGlobalTracksConfidenceMarker.color.r = 1.0f;
					absoluGlobalTracksConfidenceMarker.color.g = 0.0f;
					absoluGlobalTracksConfidenceMarker.color.b = 0.0f;
					absoluGlobalTracksConfidenceMarker.color.a = 1.0;
					break;
				case POST_TRACK :
					absoluGlobalTracksConfidenceMarker.color.r = 0.0f;
					absoluGlobalTracksConfidenceMarker.color.g = 0.0f;
					absoluGlobalTracksConfidenceMarker.color.b = 1.0f;
					absoluGlobalTracksConfidenceMarker.color.a = 1.0;
					break;
				case CURRENT_TRACK :
					absoluGlobalTracksConfidenceMarker.color.r = 1.0f;
					absoluGlobalTracksConfidenceMarker.color.g = 1.0f;
					absoluGlobalTracksConfidenceMarker.color.b = 1.0f;
					absoluGlobalTracksConfidenceMarker.color.a = 1.0;
					break;
				}

#ifdef PROJECT_S_SIMULATION
				absoluGlobalTracksConfidenceMarker.pose.position = computeGlobalPosition(Confidence.ObstacleFusion[i].obstaclePosition.position,
													 Confidence.odom);

				absoluGlobalTracksConfidenceMarkerArray.markers.push_back(absoluGlobalTracksConfidenceMarker);
#endif
			}

			pub_global_tracks_confidence_absolu.publish(absoluGlobalTracksConfidenceMarkerArray);
		}

//-------------------------------------------------------------------------------------------------
//(Amit) Marker - Corner
//-------------------------------------------------------------------------------------------------

		if (receivedGlobalTracksAssignment)
		{
			//receivedGlobalTracksAssignment = false;
			cornerMarkerArray = visualization_msgs::MarkerArray();

			for (int i = 0; i < Assignment.QtyObstacles.data; i++)
			{

				cornerMarker = visualization_msgs::Marker();
				cornerMarker.header.frame_id = "/base_link";
				cornerMarker.header.stamp = ros::Time::now();
				cornerMarker.lifetime = ros::Duration(0.2);
				cornerMarker.id = i;
				cornerMarker.ns = "Obstacles_Assignment";
				cornerMarker.type = visualization_msgs::Marker::LINE_STRIP;
				//if((cornerMarker.scale.x = Assignment.ObstacleFusion[i].obstacleDimensions.x) == 0)
				cornerMarker.scale.x = 0.2;
				//if((cornerMarker.scale.y = Assignment.ObstacleFusion[i].obstacleDimensions.y) == 0)
				cornerMarker.scale.y = 0.2;
				//if((cornerMarker.scale.z = Assignment.ObstacleFusion[i].obstacleDimensions.z) == 0)
				cornerMarker.scale.z = 0.2;
				// white by default				
				cornerMarker.color.r = 1.0f;
				cornerMarker.color.g = 1.0f;
				cornerMarker.color.b = 1.0f;
				cornerMarker.color.a = 1.0;
				cornerMarker.action = visualization_msgs::Marker::MODIFY;
				cornerMarker.pose.orientation.w = 1;

				geometry_msgs::Point p;

				p.x = Assignment.ObstacleFusion[i].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_RIGHT].x;
				p.y = Assignment.ObstacleFusion[i].obstacleCorner[0].y;
				p.z = Assignment.ObstacleFusion[i].obstacleCorner[0].z;
				cornerMarker.points.push_back(p);
				
				cornerMarkerArray.markers.push_back(cornerMarker);

				p.x = Assignment.ObstacleFusion[i].obstacleCorner[1].x;
				p.y = Assignment.ObstacleFusion[i].obstacleCorner[1].y;
				p.z = Assignment.ObstacleFusion[i].obstacleCorner[1].z;
				cornerMarker.points.push_back(p);
				cornerMarkerArray.markers.push_back(cornerMarker);

				p.x = Assignment.ObstacleFusion[i].obstacleCorner[3].x;
				p.y = Assignment.ObstacleFusion[i].obstacleCorner[3].y;
				p.z = Assignment.ObstacleFusion[i].obstacleCorner[3].z;
				cornerMarker.points.push_back(p);
				cornerMarkerArray.markers.push_back(cornerMarker);

				p.x = Assignment.ObstacleFusion[i].obstacleCorner[2].x;
				p.y = Assignment.ObstacleFusion[i].obstacleCorner[2].y;
				p.z = Assignment.ObstacleFusion[i].obstacleCorner[2].z;
				cornerMarker.points.push_back(p);
				cornerMarkerArray.markers.push_back(cornerMarker);

				p.x = Assignment.ObstacleFusion[i].obstacleCorner[0].x;
				p.y = Assignment.ObstacleFusion[i].obstacleCorner[0].y;
				p.z = Assignment.ObstacleFusion[i].obstacleCorner[0].z;
				cornerMarker.points.push_back(p);
				cornerMarkerArray.markers.push_back(cornerMarker);

			}

		pub_corner_marker.publish(cornerMarkerArray);
		
		}

//-------------------------------------------------------------------------------------------------
		if (receivedGlobalTracksAssignment)
		{
			receivedGlobalTracksAssignment = false;

			// Markers pour le repère relatif
			relativeGlobalTracksAssignmentMarkerArray = visualization_msgs::MarkerArray();

			for (int i = 0; i < Assignment.QtyObstacles.data; i++)
			{
				visualization_msgs::Marker relativeGlobalTracksAssignmentMarker = visualization_msgs::Marker();

				relativeGlobalTracksAssignmentMarker.header.frame_id = "/base_link";
				relativeGlobalTracksAssignmentMarker.header.stamp = ros::Time::now();
				relativeGlobalTracksAssignmentMarker.lifetime = ros::Duration(0.2);
				relativeGlobalTracksAssignmentMarker.id = i;
				relativeGlobalTracksAssignmentMarker.ns = "Obstacles_Assignment";
				relativeGlobalTracksAssignmentMarker.type = visualization_msgs::Marker::CUBE;
				if((relativeGlobalTracksAssignmentMarker.scale.x = Assignment.ObstacleFusion[i].obstacleDimensions.x) < 0.5)
					relativeGlobalTracksAssignmentMarker.scale.x = 0.5;
				if((relativeGlobalTracksAssignmentMarker.scale.y = Assignment.ObstacleFusion[i].obstacleDimensions.y) < 0.5)
					relativeGlobalTracksAssignmentMarker.scale.y = 0.5;
				if((relativeGlobalTracksAssignmentMarker.scale.z = Assignment.ObstacleFusion[i].obstacleDimensions.z) < 0.5)
					relativeGlobalTracksAssignmentMarker.scale.z = 0.5;
				// white by default				
				relativeGlobalTracksAssignmentMarker.color.r = 1.0f;
				relativeGlobalTracksAssignmentMarker.color.g = 1.0f;
				relativeGlobalTracksAssignmentMarker.color.b = 1.0f;
				relativeGlobalTracksAssignmentMarker.color.a = 1.0;
				relativeGlobalTracksAssignmentMarker.action = visualization_msgs::Marker::MODIFY;


//(Amit)----------------------------------Provide orientation + Obstacle center------------
relativeGlobalTracksAssignmentMarker.pose.orientation = tf::createQuaternionMsgFromYaw(Assignment.ObstacleFusion[i].obstacleCap.z);

//relativeGlobalTracksAssignmentMarker.pose.position = Assignment.ObstacleFusion[i].obstacleBodyCenter.position;		
		


//---------------------------------------------------------------------------------------------------------------------


				if(Assignment.ObstacleFusion[i].NbrOccupiedLane == 1){
					// obstacle dans la voie => red
					relativeGlobalTracksAssignmentMarker.color.r = 1.0f;
					relativeGlobalTracksAssignmentMarker.color.g = 0.0f;
					relativeGlobalTracksAssignmentMarker.color.b = 0.0f;
					relativeGlobalTracksAssignmentMarker.color.a = 1.0;
				}
				else if(Assignment.ObstacleFusion[i].indexAssignmentLine[0] == 1){
					// ligne de droite = LIGNE_CIRCUIT_GAUCHE
					// obstacle a gauche de la voie => blue
					relativeGlobalTracksAssignmentMarker.color.r = 0.0f;
					relativeGlobalTracksAssignmentMarker.color.g = 0.0f;
					relativeGlobalTracksAssignmentMarker.color.b = 1.0f;
					relativeGlobalTracksAssignmentMarker.color.a = 1.0;
				}
				else if(Assignment.ObstacleFusion[i].indexAssignmentLine[1] == 0){
					// ligne de gauche = LIGNE_CIRCUIT_DROITE
					// obstacle a droite de la voie => green
					relativeGlobalTracksAssignmentMarker.color.r = 0.0f;
					relativeGlobalTracksAssignmentMarker.color.g = 1.0f;
					relativeGlobalTracksAssignmentMarker.color.b = 0.0f;
					relativeGlobalTracksAssignmentMarker.color.a = 1.0;
				}

//(Amit) ------ Modify Marker Position ------------

geometry_msgs::Point obc_1;
obc_1.x = Assignment.ObstacleFusion[i].obstacleBodyCenter.position.x;
obc_1.y = Assignment.ObstacleFusion[i].obstacleBodyCenter.position.y;

//obc_1 = Assignment.ObstacleFusion[i].obstaclePosition.position;

//if(obc_1.x != 0 || obc_1.y != 0)
{

				relativeGlobalTracksAssignmentMarker.pose.position.x = obc_1.x;
				relativeGlobalTracksAssignmentMarker.pose.position.y = obc_1.y;

					/*relativeGlobalTracksAssignmentMarker.pose.position.x = obc_1.x;
					relativeGlobalTracksAssignmentMarker.pose.position.y = obc_1.y;*/

//-------------------------------------------------------------------------------------

				relativeGlobalTracksAssignmentMarkerArray.markers.push_back(relativeGlobalTracksAssignmentMarker);
			}

			}
			pub_global_tracks_assignment_relative.publish(relativeGlobalTracksAssignmentMarkerArray);

			// Markers pour le repère absolu
			absoluGlobalTracksAssignmentMarkerArray = visualization_msgs::MarkerArray();

			for (int i = 0; i < Assignment.QtyObstacles.data; i++)
			{
				visualization_msgs::Marker absoluGlobalTracksAssignmentMarker = visualization_msgs::Marker();

				absoluGlobalTracksAssignmentMarker.header.frame_id = "/odom";
				absoluGlobalTracksAssignmentMarker.header.stamp = ros::Time::now();
				absoluGlobalTracksAssignmentMarker.lifetime = ros::Duration(0.2);
				absoluGlobalTracksAssignmentMarker.id = 340+i;
				absoluGlobalTracksAssignmentMarker.ns = "Obstacles_Assignment";
				absoluGlobalTracksAssignmentMarker.type = visualization_msgs::Marker::CUBE;
				absoluGlobalTracksAssignmentMarker.scale.x = 0.5;
				absoluGlobalTracksAssignmentMarker.scale.y = 0.5;
				absoluGlobalTracksAssignmentMarker.scale.z = 0.5;
				//absoluGlobalTracksAssignmentMarker.color.r = 1.0f;
				//absoluGlobalTracksAssignmentMarker.color.g = 1.0f;
				//absoluGlobalTracksAssignmentMarker.color.b = 1.0f;
				//absoluGlobalTracksAssignmentMarker.color.a = 1.0;
				absoluGlobalTracksAssignmentMarker.action = visualization_msgs::Marker::MODIFY;
				absoluGlobalTracksAssignmentMarker.pose.orientation.w = 1;

/* A COMPLETER				switch(Assignment.ObstacleFusion[i].indexOccupiedLane[0]){
				default :
					absoluGlobalTracksAssignmentMarker.color.r = 1.0f;
					absoluGlobalTracksAssignmentMarker.color.g = 1.0f;
					absoluGlobalTracksAssignmentMarker.color.b = 0.0f;
					absoluGlobalTracksAssignmentMarker.color.a = 1.0;
					break;
				case 0 :
					absoluGlobalTracksAssignmentMarker.color.r = 1.0f;
					absoluGlobalTracksAssignmentMarker.color.g = 1.0f;
					absoluGlobalTracksAssignmentMarker.color.b = 1.0f;
					absoluGlobalTracksAssignmentMarker.color.a = 1.0;
					break;
				case 1 :
					absoluGlobalTracksAssignmentMarker.color.r = 0.0f;
					absoluGlobalTracksAssignmentMarker.color.g = 0.0f;
					absoluGlobalTracksAssignmentMarker.color.b = 1.0f;
					absoluGlobalTracksAssignmentMarker.color.a = 1.0;
					break;
				case 2 :
					absoluGlobalTracksAssignmentMarker.color.r = 1.0f;
					absoluGlobalTracksAssignmentMarker.color.g = 0.0f;
					absoluGlobalTracksAssignmentMarker.color.b = 0.0f;
					absoluGlobalTracksAssignmentMarker.color.a = 1.0;
					break;
				}*/

#ifdef PROJECT_S_SIMULATION
				absoluGlobalTracksAssignmentMarker.pose.position = computeGlobalPosition(Assignment.ObstacleFusion[i].obstaclePosition.position,
													 Assignment.odom);

				absoluGlobalTracksAssignmentMarkerArray.markers.push_back(absoluGlobalTracksAssignmentMarker);
#endif
			}

			pub_global_tracks_assignment_absolu.publish(absoluGlobalTracksAssignmentMarkerArray);
		}

		loop_rate.sleep();
	}
	
	return 0;	
}
