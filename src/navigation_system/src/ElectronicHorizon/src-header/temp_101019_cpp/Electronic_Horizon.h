#ifndef ELECTRONIC_HORIZON_H
#define ELECTRONIC_HORIZON_H

#include "Header.h"
#include "Miscellaneous.h"
#include "Parameters.h"
#include "project_s_msgs/MapMatching.h"
#include "project_s_msgs/RoutePlanning.h"
#include "project_s_msgs/ElectronicHorizonArray.h"

//-------------------------
// Intermediate parameters
//-------------------------

#define TCM_SPEED_LIMIT 15 // TCM = TrafficCalmingMeasure
#define UNLIMITED_SPEED_LIMIT 254
#define UNDEFINED_SPEED_LIMIT 255
#define CURV_UNKNOWN 9999.0
#define EPSILON 0.01

//--------------------------------------
// Intermediate structures and functors
//--------------------------------------

struct linklaneref
{
	::google::protobuf::uint64 laneGroupID;
	::google::protobuf::uint32 laneGroupHereTileID;
	double appliesToLinkRangeStart;
	double appliesToLinkRangeEnd;
	double appliesToLaneGroupRangeStart;
	double appliesToLaneGroupRangeEnd;
};

struct sortcompinf
{
	inline bool operator() (const linklaneref& struct1, const linklaneref& struct2)
	{
		return (struct1.appliesToLinkRangeStart < struct2.appliesToLinkRangeStart);
	}
};

//-----------
// Functions
//-----------

bool load_tile_centerline_data(::google::protobuf::uint32 NodeOrLinkTileID,
								::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile &topologyData,
								::com::here::pb::hdmap::external::v1::speed::SpeedAttributesLayerTile &speedAttributesData,
								::com::here::pb::hdmap::external::v1::adas::AdasAttributesLayerTile &adasAttributesData);

bool load_tile_LaneRoadRef_data(::google::protobuf::uint32 linkTileID,
								::com::here::pb::hdmap::external::v1::lanes::LaneRoadReferenceLayerTile &laneRoadReferenceData);

bool load_tile_lane_data(::google::protobuf::uint32 laneGroupTileID,
						::com::here::pb::hdmap::external::v1::lanes::LaneTopologyLayerTile &laneTopologyData,
						::com::here::pb::hdmap::external::v1::lanes::LaneGeometryPolylineLayerTile &laneGeometryPolylineData);

bool retrieve_node_data(const ::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile &topology_layer_tile, ::google::protobuf::uint32 node_ID, int &nodeIndex);

bool retrieve_link_data(const ::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile &topology_layer_tile,
						::google::protobuf::uint32 link_ID,
						int &linkIndex,
						::google::protobuf::uint32 startNodeID,
						::google::protobuf::uint32 endNodeID,
						bool &same_link_vs_route_direction);

bool select_priority_speed_limit(const ::com::here::pb::hdmap::external::v1::speed::SpeedAttributesLayerTile& speed_attributes_layer_tile,
								int i,
								int j,
								char& tempPriorityValue,
								int& tempSpeedlimitSpot);

bool retrieve_speed_attributes(const ::com::here::pb::hdmap::external::v1::speed::SpeedAttributesLayerTile& speed_attributes_layer_tile,
								int linkIndex,
								bool same_link_vs_route_direction,
								::google::protobuf::uint32 linkLength,
								::google::protobuf::uint32 lengthSum,
								project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
								unsigned int &indexSpeed,
								unsigned int SPEED_ARRAY_SIZE);

inline bool retrieve_route_origin_node_adas_attributes(project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data, unsigned int &indexCurv);

inline bool retrieve_route_final_node_adas_attributes(::google::protobuf::uint32 linkLength,
													::google::protobuf::uint32 lengthSum,
													project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
													unsigned int &indexCurv,
													unsigned int CURV_ARRAY_SIZE);

bool retrieve_node_adas_attributes(const ::com::here::pb::hdmap::external::v1::adas::AdasAttributesLayerTile& adas_attributes_layer_tile,
									int nodeIndex,
									::google::protobuf::uint32 first_link_ID,
									::google::protobuf::uint32 second_link_ID,
									::google::protobuf::uint32 linkLength,
									::google::protobuf::uint32 lengthSum,
									project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
									unsigned int &indexCurv,
									unsigned int CURV_ARRAY_SIZE);

bool retrieve_link_adas_attributes(const ::com::here::pb::hdmap::external::v1::adas::AdasAttributesLayerTile& adas_attributes_layer_tile,
									int linkIndex,
									bool same_link_vs_route_direction,
									::google::protobuf::uint32 linkLength,
									::google::protobuf::uint32 lengthSum,
									project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
									unsigned int &indexCurv,
									unsigned int CURV_ARRAY_SIZE);

bool retrieve_lane_road_reference(const ::com::here::pb::hdmap::external::v1::lanes::LaneRoadReferenceLayerTile &lane_road_reference_layer_tile,
								std::vector<::google::protobuf::uint32>& list_Links_ID,
								::google::protobuf::uint32 LIST_LINKS_SIZE,
								unsigned int linkIndex,
								bool same_link_vs_route_direction,
								std::vector<linklaneref> &list_LaneGroups);

bool retrieve_lane_data(const ::com::here::pb::hdmap::external::v1::lanes::LaneTopologyLayerTile &lane_topology_layer_tile1,
						const ::com::here::pb::hdmap::external::v1::lanes::LaneTopologyLayerTile &lane_topology_layer_tile2,
						std::vector<linklaneref>& list_LaneGroups,
						unsigned int laneIndex,
						bool firstExec,
						bool &same_laneGroup_vs_route_direction,
						::google::protobuf::uint32 &laneGroupLength);

bool retrieve_first_lane_geometry_polyline(const ::com::here::pb::hdmap::external::v1::lanes::LaneGeometryPolylineLayerTile& lane_geometry_polyline_layer_tile,
											const linklaneref& laneGroup,
											const bool& same_laneGroup_vs_route_direction,
											const ::google::protobuf::uint32& laneGroupLength,
											::google::protobuf::uint32 &laneGroupLengthSum,
											project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
											unsigned int *qtyLineGeo,
											const unsigned int& QTYLINE_ARRAY_SIZE,
											const unsigned int& LINEGEO_ARRAY_SIZE,
											unsigned int &qtyNbrLine,
											const unsigned int& NBRLINE_ARRAY_SIZE);

bool retrieve_lane_geometry_polyline(const com::here::pb::hdmap::external::v1::lanes::LaneGeometryPolylineLayerTile& lane_polyline_layer_tile,
									const linklaneref& laneGroup,
									const bool& same_laneGroup_vs_route_direction,
									const ::google::protobuf::uint32& laneGroupLength,
									::google::protobuf::uint32 &laneGroupLengthSum,
									project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
									unsigned int *qtyLineGeo,
									const unsigned int& QTYLINE_ARRAY_SIZE,
									const unsigned int& LINEGEO_ARRAY_SIZE,
									unsigned int &qtyNbrLine,
									const unsigned int& NBRLINE_ARRAY_SIZE);

inline void initEH(project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
					unsigned int CURV_ARRAY_SIZE,
					unsigned int SPEED_ARRAY_SIZE,
					unsigned int QTYLINE_ARRAY_SIZE,
					unsigned int LINEGEO_ARRAY_SIZE,
					unsigned int NBRLINE_ARRAY_SIZE,
					int &histoFirstLinkOnRouteIndex,
					int &histoLastPlusOneLinkOnRouteIndex,
					std::vector<::google::protobuf::uint32> &histoLinkLength,
					std::vector<bool> &histo_same_link_vs_route_direction,
					::google::protobuf::uint32 &linkLengthSum,
					::google::protobuf::uint32 &laneGroupLengthSum,
					unsigned int &indexCurv,
					unsigned int &indexSpeed,
					unsigned int *qtyLineGeo,
					unsigned int &qtyNbrLine,
					std::vector<linklaneref> &list_LaneGroups);

bool electronic_horizon(project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
						project_s_msgs::MapMatching Map_Matching_data,
						project_s_msgs::RoutePlanning Route_Planning_data);

#endif // !ELECTRONIC_HORIZON_H
