#ifndef ROUTE_PLANNING_H
#define ROUTE_PLANNING_H

#include "Header.h"
#include "Miscellaneous.h"
#include "project_s_msgs/RoutePlanning.h"

//-----------
// Functions
//-----------

bool load_tile_centerline_data(::google::protobuf::uint32 LinkTileID,
								::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile &topologyData);

bool retrieve_link_geometry_data(project_s_msgs::RoutePlanning &route_planning_data);

bool route_planning(project_s_msgs::RoutePlanning &route_planning_data, int choice);

#endif // !ROUTE_PLANNING_H
