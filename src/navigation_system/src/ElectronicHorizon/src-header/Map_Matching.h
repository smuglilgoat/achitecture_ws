#ifndef MAP_MATCHING_H
#define MAP_MATCHING_H

#include "Header.h"
#include "Miscellaneous.h"
#include "project_s_msgs/MapMatching.h"
#include "project_s_msgs/EgoDataReport.h"
#include "project_s_msgs/RoutePlanning.h"
#include "project_s_msgs/FineMapMatching.h"

//-------------------------
// Intermediate parameters
//-------------------------

#define GPS_PRECISION_DISTANCE 20.0	// In meter
#define ANGLE_TOLERANCE 45.0	// In degree

//-----------
// Functions
//-----------

bool map_matching(const project_s_msgs::EgoDataReport& ego_data_report, project_s_msgs::MapMatching &Map_Matching_data, const project_s_msgs::RoutePlanning& Route_Planning_data, double d_latitude, double d_longitude, float d_Cap);

#endif // !MAP_MATCHING_H
