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
#include "project_s_msgs/RoadModel.h"

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport assignedObstacle;

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::ObstacleFusionReport obstacle;
project_s_msgs::RoadModel currentRoadModel;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool received_obstacleFusion = false;
void obstaclesFusionCallback(const project_s_msgs::ObstacleFusionReport::ConstPtr &obstacleFusion)
{
	obstacle = *obstacleFusion;

	received_obstacleFusion = true;
}

bool received_roadModel = false;
void roadModelCallback(const project_s_msgs::RoadModel::ConstPtr &roadModel)
{
	currentRoadModel = *roadModel;

	received_roadModel = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	// char * model = argv[2];

	// std::string topic1 = std::string(model);

	ros::init(argc, argv, std::string("obstacles_assignment"));

	ros::NodeHandle n;

	// ros::Subscriber subObs       = n.subscribe(std::string("/global_tracks_update_data"), 1, obstaclesFusionCallback);
	ros::Subscriber subObs = n.subscribe(std::string("/global_tracks_confidence_data"), 1, obstaclesFusionCallback);
	// ros::Subscriber subRoadModel = n.subscribe(std::string("/road_model_data")          , 1, roadModelCallback);
	// ros::Subscriber subRoadModel = n.subscribe(std::string("/road_model_lines_data")     , 1, roadModelCallback);
	ros::Subscriber subRoadModel = n.subscribe(std::string("/road_model_EH_data"), 1, roadModelCallback);

	ros::Publisher pub = n.advertise<project_s_msgs::ObstacleFusionReport>(std::string("/obstacles_assignment_data"), 1);

	ros::Rate loop_rate(100);

	while (n.ok())
	{
		ros::spinOnce();

		if (received_roadModel)
		{
			received_roadModel = false;
		}

		if (received_obstacleFusion)
		{
			received_obstacleFusion = false;

			assignedObstacle = obstacle; // en particulier header.stamp

			for (int id = 0; id < assignedObstacle.QtyObstacles.data; id++)

			{

				/*
				//-------------------------------------------------------------------------------------------------
								// Obstacle bouding box
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_RIGHT] = assignedObstacle.ObstacleFusion[id].obstaclePosition.position;
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_LEFT]  = assignedObstacle.ObstacleFusion[id].obstaclePosition.position;
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_RIGHT]  = assignedObstacle.ObstacleFusion[id].obstaclePosition.position;
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_LEFT]   = assignedObstacle.ObstacleFusion[id].obstaclePosition.position;

								int sign;

								if((assignedObstacle.ObstacleFusion[id].obstaclePosition.position.x*cos(assignedObstacle.ObstacleFusion[id].obstacleCap.z)
								  + assignedObstacle.ObstacleFusion[id].obstaclePosition.position.y*sin(assignedObstacle.ObstacleFusion[id].obstacleCap.z)) >= 0)
								{
									sign=1;
								}
								else
								{
									sign=-1;
								}

								float cos_cap = cos(assignedObstacle.ObstacleFusion[id].obstacleCap.z);
								float sin_cap = sin(assignedObstacle.ObstacleFusion[id].obstacleCap.z);

				*/

				//-------------------------BBOX CORNER------------------------------------------------------------

				// hyp : point d'ancrage = milieu de la face visible l'objet
				float cos_cap = cos(assignedObstacle.ObstacleFusion[id].obstacleCap.z);
				float sin_cap = sin(assignedObstacle.ObstacleFusion[id].obstacleCap.z);

				geometry_msgs::Point obc_1;
				obc_1 = assignedObstacle.ObstacleFusion[id].obstacleBodyCenter.position;
				// obc_1 = assignedObstacle.ObstacleFusion[id].obstaclePosition.position;

				// if(obc_1.x != 0 || obc_1.y != 0)
				{

					// Obstacle bouding box
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_RIGHT] = obc_1;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_LEFT] = obc_1;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_RIGHT] = obc_1;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_LEFT] = obc_1;

					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_RIGHT].x += assignedObstacle.ObstacleFusion[id].obstacleDimensions.x / 2.0 * cos_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_RIGHT].x += assignedObstacle.ObstacleFusion[id].obstacleDimensions.y / 2.0 * sin_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_RIGHT].y += assignedObstacle.ObstacleFusion[id].obstacleDimensions.x / 2.0 * sin_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_RIGHT].y -= assignedObstacle.ObstacleFusion[id].obstacleDimensions.y / 2.0 * cos_cap;

					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_LEFT].x += assignedObstacle.ObstacleFusion[id].obstacleDimensions.x / 2.0 * cos_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_LEFT].x -= assignedObstacle.ObstacleFusion[id].obstacleDimensions.y / 2.0 * sin_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_LEFT].y += assignedObstacle.ObstacleFusion[id].obstacleDimensions.x / 2.0 * sin_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_LEFT].y += assignedObstacle.ObstacleFusion[id].obstacleDimensions.y / 2.0 * cos_cap;

					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_RIGHT].x -= assignedObstacle.ObstacleFusion[id].obstacleDimensions.x / 2.0 * cos_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_RIGHT].x += assignedObstacle.ObstacleFusion[id].obstacleDimensions.y / 2.0 * sin_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_RIGHT].y -= assignedObstacle.ObstacleFusion[id].obstacleDimensions.x / 2.0 * sin_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_RIGHT].y -= assignedObstacle.ObstacleFusion[id].obstacleDimensions.y / 2.0 * cos_cap;

					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_LEFT].x -= assignedObstacle.ObstacleFusion[id].obstacleDimensions.x / 2.0 * cos_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_LEFT].x -= assignedObstacle.ObstacleFusion[id].obstacleDimensions.y / 2.0 * sin_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_LEFT].y -= assignedObstacle.ObstacleFusion[id].obstacleDimensions.x / 2.0 * sin_cap;
					assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_LEFT].y += assignedObstacle.ObstacleFusion[id].obstacleDimensions.y / 2.0 * cos_cap;
				}

				//------------------------------------------------------------------------------------------------
				/*

								// hyp : point d'ancrage = milieu de la face visible l'objet
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_RIGHT].x +=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.x*(sign)*cos_cap;
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_RIGHT].x +=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.y/2.0*sin_cap;
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_RIGHT].y +=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.x*(sign)*sin_cap;
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_RIGHT].y -=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.y/2.0*cos_cap;

								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_LEFT].x  +=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.x*(sign)*cos_cap;
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_LEFT].x  -=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.y/2.0*sin_cap;
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_LEFT].y  +=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.x*(sign)*sin_cap;
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_FRONT_LEFT].y  +=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.y/2.0*cos_cap;

								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_RIGHT].x  +=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.y/2.0*sin_cap;
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_RIGHT].y  -=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.y/2.0*cos_cap;

								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_LEFT].x   -=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.y/2.0*sin_cap;
								assignedObstacle.ObstacleFusion[id].obstacleCorner[project_s_msgs::ObstacleFusion::CORNER_BACK_LEFT].y   +=
								assignedObstacle.ObstacleFusion[id].obstacleDimensions.y/2.0*cos_cap;

				*/

				//-------------------------------------------------------------------------------------------------
				// check lane position of object
				uint index_corner_line_right[4], index_corner_line_left[4];
				bool corner_assigned_line_right[4] = {false, false, false, false};
				bool corner_assigned_line_left[4] = {false, false, false, false};
				float pt_1_corner_offset_align_right[4], pt_1_corner_offset_align_left[4];

				for (int k = 0; k < 4; k++)
				{
					geometry_msgs::Point pt_1 = assignedObstacle.ObstacleFusion[id].obstacleCorner[k];
					// geometry_msgs::Point pt_1 = assignedObstacle.ObstacleFusion[id].obstaclePosition.position;

					for (int i = 0; i < currentRoadModel.nbrLine.data; i++)
					{
						// geometry_msgs::Point pt_1_align;
						bool obstacle_assigned = false;
						float pt_1_offset_align;
						float distance_obstacle_ligne_MIN = -1;
						int m_MIN;

						for (int m = 0; m < currentRoadModel.roadLine[i].QtySegment.data - 1; m++)
						{
							geometry_msgs::Point pt_0, pt_2;
							pt_0 = currentRoadModel.roadLine[i].segment[m].position;
							pt_2 = currentRoadModel.roadLine[i].segment[m + 1].position;

							float pt_0_offset, pt_2_offset;
							pt_0_offset = currentRoadModel.roadLine[i].segment[m].offset;
							pt_2_offset = currentRoadModel.roadLine[i].segment[m + 1].offset;

							/*							// recherche segment le + proche de l'objet
														float distance_obstacle_ligne = sqrt(pow((pt_1.x-pt_0.x),2) + pow((pt_1.y-pt_0.y),2));
														if((distance_obstacle_ligne <= distance_obstacle_ligne_MIN) || (distance_obstacle_ligne_MIN == -1)){
															distance_obstacle_ligne_MIN = distance_obstacle_ligne;
															m_MIN = m;

															obstacle_assigned = true;

															// hyp : on suppose que l'objet est situé entre [m] et [m+1], plutôt qu'entre [m] et [m-1]
															// calcul de y_line par interpolation, en prenant x_line = x_object
															pt_1_align.x  =  pt_1.x;
															pt_1_align.y  =  pt_0.y;
															if((pt_2.x - pt_0.x) != 0)
																pt_1_align.y += (pt_2.y - pt_0.y) / (pt_2.x - pt_0.x) * (pt_1_align.x - pt_0.x);

															// calcul de offset_line par interpolation, en prenant x_line = x_object
															pt_1_offset_align  = pt_0_offset;
															if((pt_2.x - pt_0.x) != 0)
																pt_1_offset_align += (pt_2_offset - pt_0_offset) / (pt_2.x - pt_0.x) * (pt_1_align.x - pt_0.x);
														}*/

							// recherche du couple de segment le + proche de l'objet
							float distance_obstacle_ligne = sqrt(pow((pt_1.x - pt_0.x), 2) + pow((pt_1.y - pt_0.y), 2)) + sqrt(pow((pt_1.x - pt_2.x), 2) + pow((pt_1.y - pt_2.y), 2));
							if ((distance_obstacle_ligne <= distance_obstacle_ligne_MIN) || (distance_obstacle_ligne_MIN == -1))
							{
								distance_obstacle_ligne_MIN = distance_obstacle_ligne;
								m_MIN = m;

								obstacle_assigned = true;

								// calcul de offset_line par interpolation, en prenant x_line = x_object
								pt_1_offset_align = pt_0_offset;
								if ((pt_2.x - pt_0.x) != 0)
									pt_1_offset_align += (pt_2_offset - pt_0_offset) / (pt_2.x - pt_0.x) * (pt_1.x - pt_0.x);
							}
						}

						// check sign
						if (obstacle_assigned)
						{
							// calcul du placement de l'objet, par rapport à la ligne
							geometry_msgs::Point vecteur_ligne;
							vecteur_ligne.x = currentRoadModel.roadLine[i].segment[m_MIN + 1].position.x - currentRoadModel.roadLine[i].segment[m_MIN].position.x;
							vecteur_ligne.y = currentRoadModel.roadLine[i].segment[m_MIN + 1].position.y - currentRoadModel.roadLine[i].segment[m_MIN].position.y;

							geometry_msgs::Point vecteur_objet;
							vecteur_objet.x = pt_1.x - currentRoadModel.roadLine[i].segment[m_MIN].position.x;
							vecteur_objet.y = pt_1.y - currentRoadModel.roadLine[i].segment[m_MIN].position.y;

							// calcul produit vectoriel, composante Wz
							float w_z = (vecteur_ligne.x * vecteur_objet.y) - (vecteur_ligne.y * vecteur_objet.x);

							if (w_z >= 0)
							{
								// the line is on the right of the object, et on prend la dernière ligne classée à droite
								corner_assigned_line_right[k] = true;

								index_corner_line_right[k] = i;
								pt_1_corner_offset_align_right[k] = pt_1_offset_align;
							}
							else if (!corner_assigned_line_left[k])
							{
								// the line is on the left of the object, et on prend la première ligne classée à gauche
								corner_assigned_line_left[k] = true;

								index_corner_line_left[k] = i;
								pt_1_corner_offset_align_left[k] = pt_1_offset_align;
							}
						}
					}
				}

				// MaJ de obstacle_assigned_line_right/left, index_line_right/left, pt_1_offset_align_right/left
				geometry_msgs::Point pt_1_align_right, pt_1_align_left;
				uint index_line_right, index_line_left;
				// uint index_segment_right, index_segment_left;
				bool obstacle_assigned_line_right = false;
				bool obstacle_assigned_line_left = false;
				float pt_1_offset_align_right, pt_1_offset_align_left;

				index_line_right = 0xFFFF;
				index_line_left = 0xFFFF;
				for (int k = 0; k < 4; k++)
				{
					if (corner_assigned_line_right[k])
					{
						obstacle_assigned_line_right = true;
						// il faut garder la ligne la + à droite
						if ((index_line_right > index_corner_line_right[k]) || (index_line_right == 0xFFFF))
						{
							index_line_right = index_corner_line_right[k];
							pt_1_offset_align_right = pt_1_corner_offset_align_right[k];
						}
					}

					if (corner_assigned_line_left[k])
					{
						obstacle_assigned_line_left = true;
						// il faut garde la ligne la + à gauche
						if ((index_line_left < index_corner_line_left[k]) || (index_line_left == 0xFFFF))
						{
							index_line_left = index_corner_line_left[k];
							pt_1_offset_align_left = pt_1_corner_offset_align_left[k];
						}
					}
				}

				// create lane assignment attributes
				assignedObstacle.ObstacleFusion[id].indexAssignmentLine[0] = project_s_msgs::ObstacleFusion::INDEX_LINE_INDEFINI;
				assignedObstacle.ObstacleFusion[id].indexAssignmentLine[1] = project_s_msgs::ObstacleFusion::INDEX_LINE_INDEFINI;
				assignedObstacle.ObstacleFusion[id].NbrOccupiedLane = project_s_msgs::ObstacleFusion::OCCUPIED_LANE_INDEFINI;

				if (obstacle_assigned_line_right)
				{
					assignedObstacle.ObstacleFusion[id].indexAssignmentLine[0] = index_line_right; // hyp:	l'index de voie correspond à l'index de ligne de droite.
																								   //	les lignes sont triées de droite à gauche.
																								   //	les voies sont triées de droite à gauche.

					assignedObstacle.ObstacleFusion[id].distanceCurviligne = pt_1_offset_align_right;
				}

				if (obstacle_assigned_line_left)
				{
					assignedObstacle.ObstacleFusion[id].indexAssignmentLine[1] = index_line_left;
					assignedObstacle.ObstacleFusion[id].distanceCurviligne = pt_1_offset_align_left;
				}

				if ((obstacle_assigned_line_right) && (obstacle_assigned_line_left))
				{
					assignedObstacle.ObstacleFusion[id].distanceCurviligne = (pt_1_offset_align_right + pt_1_offset_align_left) / 2.0;

					if (assignedObstacle.ObstacleFusion[id].indexAssignmentLine[0] < assignedObstacle.ObstacleFusion[id].indexAssignmentLine[1])
					{
						assignedObstacle.ObstacleFusion[id].NbrOccupiedLane = 1;

						/*
						ROS_ERROR("id : %d   distanceCurviligne : %f", assignedObstacle.ObstacleFusion[id].id.data, assignedObstacle.ObstacleFusion[id].distanceCurviligne);
						ROS_ERROR("index_segment_left : %d currentRoadModel.offset : %f" , index_segment_left, currentRoadModel.roadLine[index_line_left].segment[index_segment_left].offset);
						*/

						/* A REMETTRE	*/				
												float lane_position;
												if((pt_1_align_left.y - pt_1_align_right.y) != 0)
													lane_position = (pt_1_align_left.y - pt_1_align_right.y) / (pt_1_align_left.y - pt_1_align_right.y) * 100.0;
												assignedObstacle.ObstacleFusion[id].positionLane.data = lane_position;
					}
				}

				//------------------------------------------------------------------------------------------------------------------

				/* A REMETTRE */			
								float max_right_departure, max_left_departure;
								bool first_right_departure = true, first_left_departure = true;
								// check lane position of each corner
								for(int j = 0; j < 4; j++){
									geometry_msgs::Point pt_1_align;
									geometry_msgs::Point pt_1 = assignedObstacle.ObstacleFusion[id].obstacleCorner[j];

									if(obstacle_assigned_line_right){
										for(int m = 0; m < currentRoadModel.roadLine[index_line_right].QtySegment.data-1; m++){
											geometry_msgs::Point pt_0, pt_2;
											pt_0 = currentRoadModel.roadLine[index_line_right].segment[m]  .position;
											pt_2 = currentRoadModel.roadLine[index_line_right].segment[m+1].position;

											if((pt_0.x <= pt_1.x) && (pt_1.x <= pt_2.x)){
												// calcul de y par interpolation
												pt_1_align.x  =  pt_1.x;
												pt_1_align.y  =  pt_0.y;
												if((pt_2.x - pt_0.x) != 0)
													pt_1_align.y += (pt_2.y - pt_0.y) / (pt_2.x - pt_0.x) * (pt_1_align.x - pt_0.x);
											}
										}

										// recherche max right departure
										float departure = pt_1_align.y - pt_1.y;

										if(first_right_departure){
											first_right_departure = false;
											max_right_departure = departure;
										}

										if(departure > max_right_departure)
											max_right_departure = departure;
									}

									if(obstacle_assigned_line_left){
										for(int m = 0; m < currentRoadModel.roadLine[index_line_left].QtySegment.data-1; m++){
											geometry_msgs::Point pt_0, pt_2;
											pt_0 = currentRoadModel.roadLine[index_line_left].segment[m]  .position;
											pt_2 = currentRoadModel.roadLine[index_line_left].segment[m+1].position;

											if((pt_0.x <= pt_1.x) && (pt_1.x <= pt_2.x)){
												// calcul de y par interpolation
												pt_1_align.x  =  pt_1.x;
												pt_1_align.y  =  pt_0.y;
												if((pt_2.x - pt_0.x) != 0)
													pt_1_align.y += (pt_2.y - pt_0.y) / (pt_2.x - pt_0.x) * (pt_1_align.x - pt_0.x);
											}
										}

										// recherche max left departure
										float departure = pt_1.y - pt_1_align.y;

										if(first_left_departure){
											first_left_departure = false;
											max_left_departure = departure;
										}

										if(departure > max_left_departure)
											max_left_departure = departure;
									}

								}

								// create lane assignment attributes
								//assignedObstacle.ObstacleFusion[id].obstacleAssignment = project_s_msgs::ObstacleFusion::ASSIGNMENT_COTE_DROIT;

								// conventions:	signe positif de departure signifie que le coin dépasse la ligne de xxx metre(à droite comme à gauche)
								//		signe négatif                                   est à l'intérieur de la voie (à droite comme à gauche)
								if(obstacle_assigned_line_right){
									assignedObstacle.ObstacleFusion[id].departureRighttDistance.data = max_right_departure;
								}

								if(obstacle_assigned_line_left){
									assignedObstacle.ObstacleFusion[id].departureLeftDistance.data = max_left_departure;
								}
			}

			pub.publish(assignedObstacle);
		}

		loop_rate.sleep();
	}

	return 0;
}
