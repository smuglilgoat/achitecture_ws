#include "Electronic_Horizon.h"

#include "ros/ros.h"

#include "project_s_msgs/Configurations.h"

using namespace std;

bool load_tile_centerline_data(::google::protobuf::uint32 NodeOrLinkTileID,
								::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile &topologyData,
								::com::here::pb::hdmap::external::v1::speed::SpeedAttributesLayerTile &speedAttributesData,
								::com::here::pb::hdmap::external::v1::adas::AdasAttributesLayerTile &adasAttributesData)
{
	#ifdef PROJECT_S_SIMULATION
		string topologyLayerFile = "/home/dpa/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(NodeOrLinkTileID) + "/" + to_string(NodeOrLinkTileID) + "_hdmap-topology-geometry-bundle_topology-geometry";
		string speedAttributesLayerFile = "/home/dpa/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(NodeOrLinkTileID) + "/" + to_string(NodeOrLinkTileID) + "_hdmap-speed-attributes-bundle_speed-attributes";
		string adasAttributesLayerFile = "/home/dpa/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(NodeOrLinkTileID) + "/" + to_string(NodeOrLinkTileID) + "_hdmap-adas-attributes-bundle_adas-attributes";
	#endif
	#ifdef PROJECT_S_VEHICLE
		string topologyLayerFile = "/home/segula/Desktop/ava/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(NodeOrLinkTileID) + "/" + to_string(NodeOrLinkTileID) + "_hdmap-topology-geometry-bundle_topology-geometry";
		string speedAttributesLayerFile = "/home/segula/Desktop/ava/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(NodeOrLinkTileID) + "/" + to_string(NodeOrLinkTileID) + "_hdmap-speed-attributes-bundle_speed-attributes";
		string adasAttributesLayerFile = "/home/segula/Desktop/ava/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(NodeOrLinkTileID) + "/" + to_string(NodeOrLinkTileID) + "_hdmap-adas-attributes-bundle_adas-attributes";
	#endif

	{
		// Checking if this tile's topology layer file exists
		fstream input(topologyLayerFile, ios::in | ios::binary);
		if (!input)
		{
			cerr << topologyLayerFile << " :: This topology layer's tile binary file is not found." << endl;
			return true;
		}
		// This tile's topology layer file exists, trying to parse the data
		else if (!topologyData.ParseFromIstream(&input))
		{
			cerr << topologyLayerFile << " :: Failed to parse this topology layer's tile binary file." << endl;
			return true;
		}
	}

	{
		fstream input(speedAttributesLayerFile, ios::in | ios::binary);
		if (!input)
		{
			cerr << speedAttributesLayerFile << " :: This speed_attributes layer's tile binary file is not found." << endl;
			return true;
		}
		else if (!speedAttributesData.ParseFromIstream(&input))
		{
			cerr << speedAttributesLayerFile << " :: Failed to parse this speed_attributes layer's tile binary file." << endl;
			return true;
		}
	}

	{
		fstream input(adasAttributesLayerFile, ios::in | ios::binary);
		if (!input)
		{
			cerr << adasAttributesLayerFile << " :: This adas_attributes layer's tile binary file is not found." << endl;
			return true;
		}
		else if (!adasAttributesData.ParseFromIstream(&input))
		{
			cerr << adasAttributesLayerFile << " :: Failed to parse this adas_attributes layer's tile binary file." << endl;
			return true;
		}
	}

	return false;
}


bool load_tile_LaneRoadRef_data(::google::protobuf::uint32 linkTileID,
								::com::here::pb::hdmap::external::v1::lanes::LaneRoadReferenceLayerTile &laneRoadReferenceData)
{
	#ifdef PROJECT_S_SIMULATION
		string laneRoadReferenceLayerFile = "/home/dpa/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(linkTileID) + "/" + to_string(linkTileID) + "_hdmap-lane-road-references-bundle_lane-road-references";
	#endif
	#ifdef PROJECT_S_VEHICLE
		string laneRoadReferenceLayerFile = "/home/segula/Desktop/ava/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(linkTileID) + "/" + to_string(linkTileID) + "_hdmap-lane-road-references-bundle_lane-road-references";
	#endif

	{
		fstream input(laneRoadReferenceLayerFile, ios::in | ios::binary);
		if (!input)
		{
			cerr << laneRoadReferenceLayerFile << " :: This lane_road_reference layer's tile binary file is not found." << endl;
			return true;
		}
		else if (!laneRoadReferenceData.ParseFromIstream(&input))
		{
			cerr << laneRoadReferenceLayerFile << " :: Failed to parse this lane_road_reference layer's tile binary file." << endl;
			return true;
		}
	}

	return false;
}


bool load_tile_lane_data(::google::protobuf::uint32 laneGroupTileID,
						::com::here::pb::hdmap::external::v1::lanes::LaneTopologyLayerTile &laneTopologyData,
						::com::here::pb::hdmap::external::v1::lanes::LaneGeometryPolylineLayerTile &laneGeometryPolylineData)
{
	#ifdef PROJECT_S_SIMULATION
		string laneTopologyLayerFile = "/home/dpa/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(laneGroupTileID) + "/" + to_string(laneGroupTileID) + "_hdmap-lane-topology-bundle_lane-topology";
		string laneGeometryPolylineLayerFile = "/home/dpa/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(laneGroupTileID) + "/" + to_string(laneGroupTileID) + "_hdmap-lane-geometry-polyline-bundle_lane-geometry-polyline";
	#endif
	#ifdef PROJECT_S_VEHICLE
		string laneTopologyLayerFile = "/home/segula/Desktop/ava/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(laneGroupTileID) + "/" + to_string(laneGroupTileID) + "_hdmap-lane-topology-bundle_lane-topology";
		string laneGeometryPolylineLayerFile = "/home/segula/Desktop/ava/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(laneGroupTileID) + "/" + to_string(laneGroupTileID) + "_hdmap-lane-geometry-polyline-bundle_lane-geometry-polyline";
	#endif

	{
		fstream input(laneTopologyLayerFile, ios::in | ios::binary);
		if (!input)
		{
			cerr << laneTopologyLayerFile << " :: This lane_topology layer's tile binary file is not found." << endl;
			return true;
		}
		else if (!laneTopologyData.ParseFromIstream(&input))
		{
			cerr << laneTopologyLayerFile << " :: Failed to parse this lane_topology layer's tile binary file." << endl;
			return true;
		}
	}

	{
		fstream input(laneGeometryPolylineLayerFile, ios::in | ios::binary);
		if (!input)
		{
			cerr << laneGeometryPolylineLayerFile << " :: This lane_geometry_polyline layer's tile binary file is not found." << endl;
			return true;
		}
		else if (!laneGeometryPolylineData.ParseFromIstream(&input))
		{
			cerr << laneGeometryPolylineLayerFile << " :: Failed to parse this lane_geometry_polyline layer's tile binary file." << endl;
			return true;
		}
	}

	return false;
}


bool retrieve_node_data(const ::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile &topology_layer_tile, ::google::protobuf::uint32 node_ID, int &nodeIndex)
{
	nodeIndex = 0;
	while ((nodeIndex < topology_layer_tile.nodes_in_tile_size()) && (topology_layer_tile.nodes_in_tile(nodeIndex).node_id() != node_ID))
	{
		nodeIndex++;
	}

	if (nodeIndex >= topology_layer_tile.nodes_in_tile_size())
	{
		cerr << "Topology Layer's tile binary file or nodeID contains error. Cannot find nodeID." << endl;
		return true;
	}
	else return false;
}


bool retrieve_link_data(const ::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile &topology_layer_tile, 
						::google::protobuf::uint32 link_ID, 
						int &linkIndex, 
						::google::protobuf::uint32 startNodeID, 
						::google::protobuf::uint32 endNodeID, 
						bool &same_link_vs_route_direction)
{
	linkIndex = 0;
	while ((linkIndex < topology_layer_tile.links_starting_in_tile_size()) && (topology_layer_tile.links_starting_in_tile(linkIndex).link_id() != link_ID))
	{
		linkIndex++;
	}

	if (linkIndex < topology_layer_tile.links_starting_in_tile_size())
	{
		if (startNodeID == topology_layer_tile.links_starting_in_tile(linkIndex).start_node_id() && endNodeID == topology_layer_tile.links_starting_in_tile(linkIndex).end_node_ref().node_id())
		{
			same_link_vs_route_direction = true;
			return false;
		}
		else if (startNodeID == topology_layer_tile.links_starting_in_tile(linkIndex).end_node_ref().node_id() && endNodeID == topology_layer_tile.links_starting_in_tile(linkIndex).start_node_id())
		{
			same_link_vs_route_direction = false;
			return false;
		}
		else
		{
			cerr << "Error in startNodeID or endNodeID." << endl;
			return true;
		}
	}
	else
	{
		cerr << "Topology Layer's tile binary file contains error." << endl;
		return true;
	}
}


bool select_priority_speed_limit(const ::com::here::pb::hdmap::external::v1::speed::SpeedAttributesLayerTile& speed_attributes_layer_tile,
								int i,
								int j,
								char& tempPriorityValue,
								int& tempSpeedlimitSpot)
{
	switch (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).attribute_case())
	{
	case 1:
		tempPriorityValue = 2;
		if (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).speed_limit().is_unlimited())
		{
			tempSpeedlimitSpot = UNLIMITED_SPEED_LIMIT;
		}
		else
		{
			tempSpeedlimitSpot = speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).speed_limit().value();
		}
		break;
	case 2:
		tempPriorityValue = 1;
		switch (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).speed_category())
		{
		case 1:
			tempSpeedlimitSpot = 131;
			break;
		case 2:
			tempSpeedlimitSpot = 101;
			break;
		case 3:
			tempSpeedlimitSpot = 91;
			break;
		case 4:
			tempSpeedlimitSpot = 71;
			break;
		case 5:
			tempSpeedlimitSpot = 51;
			break;
		case 6:
			tempSpeedlimitSpot = 31;
			break;
		case 7:
			tempSpeedlimitSpot = 11;
			break;
		case 8:
			tempSpeedlimitSpot = 10;
			break;
		default:
			tempSpeedlimitSpot = 0;
			break;
		}
		break;
	case 3:
		tempPriorityValue = 0;
		tempSpeedlimitSpot = 0;
		break;
	case 4:
		switch (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).conditional_speed_limit().situation_case())
		{
		case 0:
			tempPriorityValue = 0;
			tempSpeedlimitSpot = 0;
			break;
		case 1:
			tempPriorityValue = 3;
			if (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).conditional_speed_limit().advisory().override_speed_limit().is_unlimited())
			{
				tempSpeedlimitSpot = UNLIMITED_SPEED_LIMIT;
			}
			else
			{
				tempSpeedlimitSpot = speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).conditional_speed_limit().advisory().override_speed_limit().value();
			}
			break;
		case 2:
			// For TrafficCalmingMeasure, where is no speed limitation value, a default value is taken
			tempPriorityValue = 3;
			tempSpeedlimitSpot = TCM_SPEED_LIMIT;
			break;
		case 3:
			tempPriorityValue = 3;
			if (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).conditional_speed_limit().location_proximity().overridespeedlimit().is_unlimited())
			{
				tempSpeedlimitSpot = UNLIMITED_SPEED_LIMIT;
			}
			else
			{
				tempSpeedlimitSpot = speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).conditional_speed_limit().location_proximity().overridespeedlimit().value();
			}
			break;
		case 4:
			tempPriorityValue = 3;
			if (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).conditional_speed_limit().environmental().override_speed_limit().is_unlimited())
			{
				tempSpeedlimitSpot = UNLIMITED_SPEED_LIMIT;
			}
			else
			{
				tempSpeedlimitSpot = speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).conditional_speed_limit().environmental().override_speed_limit().value();
			}
			break;
		case 5:
			tempPriorityValue = 3;
			if (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).conditional_speed_limit().time_dependent().override_speed_limit().is_unlimited())
			{
				tempSpeedlimitSpot = UNLIMITED_SPEED_LIMIT;
			}
			else
			{
				tempSpeedlimitSpot = speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(0).conditional_speed_limit().time_dependent().override_speed_limit().value();
			}
			break;
		case 6:
			tempPriorityValue = 0;
			tempSpeedlimitSpot = 0;
			break;
		default:
			tempPriorityValue = 0;
			tempSpeedlimitSpot = 0;
			break;
		}
		break;
	default:
		tempPriorityValue = 0;
		tempSpeedlimitSpot = 0;
		break;
	}

	for (int g(1); g < speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution_size(); g++)
	{
		switch (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).attribute_case())
		{
		case 1:
			if (tempPriorityValue < 2)
			{
				if (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).speed_limit().is_unlimited())
				{
					tempSpeedlimitSpot = UNLIMITED_SPEED_LIMIT;
				}
				else
				{
					tempSpeedlimitSpot = speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).speed_limit().value();
				}
				tempPriorityValue = 2;
			}
			break;
		case 2:
			if (tempPriorityValue < 1)
			{
				switch (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).speed_category())
				{
				case 1:
					tempSpeedlimitSpot = 131;
					break;
				case 2:
					tempSpeedlimitSpot = 101;
					break;
				case 3:
					tempSpeedlimitSpot = 91;
					break;
				case 4:
					tempSpeedlimitSpot = 71;
					break;
				case 5:
					tempSpeedlimitSpot = 51;
					break;
				case 6:
					tempSpeedlimitSpot = 31;
					break;
				case 7:
					tempSpeedlimitSpot = 11;
					break;
				case 8:
					tempSpeedlimitSpot = 10;
					break;
				default:
					tempSpeedlimitSpot = 0;
					break;
				}
				tempPriorityValue = 1;
			}
			break;
		case 4:
			switch (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).conditional_speed_limit().situation_case())
			{
			case 1:
				tempPriorityValue = 3;
				if (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).conditional_speed_limit().advisory().override_speed_limit().is_unlimited())
				{
					tempSpeedlimitSpot = UNLIMITED_SPEED_LIMIT;
				}
				else
				{
					tempSpeedlimitSpot = speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).conditional_speed_limit().advisory().override_speed_limit().value();
				}
				break;
			case 3:
				tempPriorityValue = 3;
				if (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).conditional_speed_limit().location_proximity().overridespeedlimit().is_unlimited())
				{
					tempSpeedlimitSpot = UNLIMITED_SPEED_LIMIT;
				}
				else
				{
					tempSpeedlimitSpot = speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).conditional_speed_limit().location_proximity().overridespeedlimit().value();
				}
				break;
			case 4:
				tempPriorityValue = 3;
				if (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).conditional_speed_limit().environmental().override_speed_limit().is_unlimited())
				{
					tempSpeedlimitSpot = UNLIMITED_SPEED_LIMIT;
				}
				else
				{
					tempSpeedlimitSpot = speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).conditional_speed_limit().environmental().override_speed_limit().value();
				}
				break;
			case 5:
				tempPriorityValue = 3;
				if (speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).conditional_speed_limit().time_dependent().override_speed_limit().is_unlimited())
				{
					tempSpeedlimitSpot = UNLIMITED_SPEED_LIMIT;
				}
				else
				{
					tempSpeedlimitSpot = speed_attributes_layer_tile.link_attribution(i).parametric_attribution(j).link_parametric_attribution(g).conditional_speed_limit().time_dependent().override_speed_limit().value();
				}
				break;
			}
			break;
		}
	}

	return false;
}


bool retrieve_speed_attributes(const ::com::here::pb::hdmap::external::v1::speed::SpeedAttributesLayerTile& speed_attributes_layer_tile,
								int linkIndex,
								bool same_link_vs_route_direction,
								::google::protobuf::uint32 linkLength,
								::google::protobuf::uint32 lengthSum,
								project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
								unsigned int &indexSpeed,
								unsigned int SPEED_ARRAY_SIZE)
{
	//------------------------------------------------------------------------------------------------------------------------------------
	// Sorting speed attributes by range & Elimination of duplications & Keep only route direction's speed limitation or BOTH direction's
	//------------------------------------------------------------------------------------------------------------------------------------

	vector<double> offsetSpots;
	char tempPriorityValue;
	int tempSpeedlimitSpot;

	// Sorting by range
	if (same_link_vs_route_direction)
	{
		for (int j(0); j < speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution_size(); j++)
		{
			offsetSpots.push_back(speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_start());
			offsetSpots.push_back(1.0 - speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_end());
		}
	}
	else
	{
		for (int j(0); j < speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution_size(); j++)
		{
			offsetSpots.push_back(speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_end());
			offsetSpots.push_back(1.0 - speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_start());
		}
	}

	sort(offsetSpots.begin(), offsetSpots.end());

	// Deleting duplications
	vector<int> found_duplication;

	for (int k(1); k < offsetSpots.size(); k++)
	{
		if (offsetSpots[k] <= (offsetSpots[k - 1] + 0.00000000000000005) && (offsetSpots[k - 1] - 0.00000000000000005) <= offsetSpots[k]) found_duplication.push_back(k);
	}
	for (int l(0); l < found_duplication.size(); l++)
	{
		offsetSpots.erase(offsetSpots.begin() + (found_duplication[l] - l));
	}

	vector<int> speedlimitSpots(offsetSpots.size(), UNDEFINED_SPEED_LIMIT);
	vector<char> priorityValues(offsetSpots.size(), UNDEFINED_SPEED_LIMIT);
	int start_index, end_index;

	int link_vs_route_dir;
	if (same_link_vs_route_direction) link_vs_route_dir = 2;
	else link_vs_route_dir = 3;

	for (int j(0); j < speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution_size(); j++)
	{
		if (speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_direction() == link_vs_route_dir || speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_direction() == 1)
		{
			if (link_vs_route_dir == 2)
			{
				for (int m(0); m < offsetSpots.size(); m++)
				{
					if ((speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_start() <= (offsetSpots[m] + 0.00000000000000005)) && ((offsetSpots[m] - 0.00000000000000005) <= speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_start())) start_index = m;
					if (((1.0 - speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_end()) <= (offsetSpots[m] + 0.00000000000000005)) && ((offsetSpots[m] - 0.00000000000000005) <= (1.0 - speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_end()))) end_index = m;
				}
			}
			else if (link_vs_route_dir == 3)
			{
				for (int m(0); m < offsetSpots.size(); m++)
				{
					if ((speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_end() <= (offsetSpots[m] + 0.00000000000000005)) && ((offsetSpots[m] - 0.00000000000000005) <= speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_end())) start_index = m;
					if (((1.0 - speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_start()) <= (offsetSpots[m] + 0.00000000000000005)) && ((offsetSpots[m] - 0.00000000000000005) <= (1.0 - speed_attributes_layer_tile.link_attribution(linkIndex).parametric_attribution(j).applies_to_range().range_offset_from_start()))) end_index = m;
				}
			}

			if (select_priority_speed_limit(speed_attributes_layer_tile, linkIndex, j, tempPriorityValue, tempSpeedlimitSpot)) return true;

			for (int f(start_index); f < end_index; f++)
			{
				if (tempPriorityValue > priorityValues[f])
				{
					priorityValues[f] = tempPriorityValue;
					speedlimitSpots[f] = tempSpeedlimitSpot;
				}
			}
		}
	}

	for (int n(0); n < offsetSpots.size(); n++)
	{
		offsetSpots[n] = offsetSpots[n] * linkLength + lengthSum;
	}

	if (indexSpeed == 0)
	{
		for (int o(0); indexSpeed < SPEED_ARRAY_SIZE && o < offsetSpots.size() - 1; o++)
		{
			electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].offset.data = offsetSpots[o];
			electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].effectiveSpeedLimit.data = speedlimitSpots[o];
			indexSpeed++;
		}

		if (indexSpeed < SPEED_ARRAY_SIZE)
		{
			electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].offset.data = offsetSpots[offsetSpots.size() - 1];
			electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].effectiveSpeedLimit.data = speedlimitSpots[offsetSpots.size() - 1];
		}
	}
	else
	{
		if (electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed - 1].effectiveSpeedLimit.data == speedlimitSpots[0])
		{
			for (int o(1); indexSpeed < SPEED_ARRAY_SIZE && o < offsetSpots.size() - 1; o++)
			{
				electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].offset.data = offsetSpots[o];
				electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].effectiveSpeedLimit.data = speedlimitSpots[o];
				indexSpeed++;
			}

			if (indexSpeed < SPEED_ARRAY_SIZE)
			{
				electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].offset.data = offsetSpots[offsetSpots.size() - 1];
				electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].effectiveSpeedLimit.data = speedlimitSpots[offsetSpots.size() - 1];
			}
		}
		else
		{
			for (int o(0); indexSpeed < SPEED_ARRAY_SIZE && o < offsetSpots.size() - 1; o++)
			{
				electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].offset.data = offsetSpots[o];
				electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].effectiveSpeedLimit.data = speedlimitSpots[o];
				indexSpeed++;
			}

			if (indexSpeed < SPEED_ARRAY_SIZE)
			{
				electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].offset.data = offsetSpots[offsetSpots.size() - 1];
				electronic_Horizon_data.PathsArray[0].ehSegment[indexSpeed].effectiveSpeedLimit.data = speedlimitSpots[offsetSpots.size() - 1];
			}
		}
	}

	return false;
}


inline bool retrieve_route_origin_node_adas_attributes(project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data, unsigned int &indexCurv)
{
	electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = 0;
	electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = CURV_UNKNOWN;
	indexCurv++;

	return false;
}


inline bool retrieve_route_final_node_adas_attributes(::google::protobuf::uint32 linkLength,
													::google::protobuf::uint32 lengthSum,
													project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
													unsigned int &indexCurv,
													unsigned int CURV_ARRAY_SIZE)
{
	if (indexCurv < CURV_ARRAY_SIZE)
	{
		if (electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv - 1].Value_0.data != CURV_UNKNOWN)
		{
			electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = linkLength + lengthSum;
			electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = CURV_UNKNOWN;
			indexCurv++;
		}
		else
		{
			electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv - 1].offset.data = lengthSum + linkLength;
			electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv - 1].Value_0.data = CURV_UNKNOWN;
		}
	}

	return false;
}


bool retrieve_node_adas_attributes(const ::com::here::pb::hdmap::external::v1::adas::AdasAttributesLayerTile& adas_attributes_layer_tile,
									int nodeIndex,
									::google::protobuf::uint32 first_link_ID,
									::google::protobuf::uint32 second_link_ID,
									::google::protobuf::uint32 linkLength,
									::google::protobuf::uint32 lengthSum,
									project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
									unsigned int &indexCurv,
									unsigned int CURV_ARRAY_SIZE)
{
	if (indexCurv < CURV_ARRAY_SIZE)
	{
		unsigned int tempIndexCurv(indexCurv);

		bool curvNotFound(true);

		for (int j(0); curvNotFound && j < adas_attributes_layer_tile.node_attribution(nodeIndex).intersection_traversal_attribution_size(); j++)
		{
			for (int k(0); curvNotFound && k < adas_attributes_layer_tile.node_attribution(nodeIndex).intersection_traversal_attribution(j).node_attribution_size(); k++)
			{
				if (adas_attributes_layer_tile.node_attribution(nodeIndex).intersection_traversal_attribution(j).node_attribution(k).has_intersection_traversal_values())
				{
					if (adas_attributes_layer_tile.node_attribution(nodeIndex).intersection_traversal_attribution(j).node_attribution(k).intersection_traversal_values().has_curvature())
					{
						if (adas_attributes_layer_tile.node_attribution(nodeIndex).intersection_traversal_attribution(j).to_link_refs(0).link_id() == second_link_ID && adas_attributes_layer_tile.node_attribution(nodeIndex).intersection_traversal_attribution(j).from_link_refs(0).link_id() == first_link_ID)
						{
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = linkLength + lengthSum;
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = (float)adas_attributes_layer_tile.node_attribution(nodeIndex).intersection_traversal_attribution(j).node_attribution(k).intersection_traversal_values().curvature().inverse_radius_millionths_of_meter() / 1000000.0;
							indexCurv++;
							curvNotFound = false;
						}
						else if (adas_attributes_layer_tile.node_attribution(nodeIndex).intersection_traversal_attribution(j).from_link_refs(0).link_id() == second_link_ID && adas_attributes_layer_tile.node_attribution(nodeIndex).intersection_traversal_attribution(j).to_link_refs(0).link_id() == first_link_ID)
						{
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = linkLength + lengthSum;
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = -((float)adas_attributes_layer_tile.node_attribution(nodeIndex).intersection_traversal_attribution(j).node_attribution(k).intersection_traversal_values().curvature().inverse_radius_millionths_of_meter() / 1000000.0);
							indexCurv++;
							curvNotFound = false;
						}
					}
				}
			}
		}

		if (indexCurv == tempIndexCurv)
		{
			if (indexCurv == 0)
			{
				electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = lengthSum;
				electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = CURV_UNKNOWN;
				indexCurv++;
			}
			else
			{
				if (electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv - 1].Value_0.data != CURV_UNKNOWN)
				{
					electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = lengthSum + linkLength;
					electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = CURV_UNKNOWN;
					indexCurv++;
				}
				else
				{
					electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv - 1].offset.data = lengthSum + linkLength;
					electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv - 1].Value_0.data = CURV_UNKNOWN;
				}
			}
		}
	}

	return false;
}


bool retrieve_link_adas_attributes(const ::com::here::pb::hdmap::external::v1::adas::AdasAttributesLayerTile& adas_attributes_layer_tile,
									int linkIndex,
									bool same_link_vs_route_direction,
									::google::protobuf::uint32 linkLength,
									::google::protobuf::uint32 lengthSum,
									project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
									unsigned int &indexCurv,
									unsigned int CURV_ARRAY_SIZE)
{
	if (indexCurv < CURV_ARRAY_SIZE)
	{
		unsigned int tempIndexCurv(indexCurv);

		if (same_link_vs_route_direction)
		{
			for (int j(0); indexCurv < CURV_ARRAY_SIZE && j < adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution_size(); j++)
			{
				for (int k(0); indexCurv < CURV_ARRAY_SIZE && k < adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).link_point_attribution_size(); k++)
				{
					if (adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).link_point_attribution(k).has_link_point_curvature())
					{
						if (adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).applies_to_direction() == 2)
						{
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).applies_to_location() * linkLength + lengthSum;
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = (float)adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).link_point_attribution(k).link_point_curvature().inverse_radius_millionths_of_meter() / 1000000.0;
							indexCurv++;
						}
						else if (adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).applies_to_direction() == 3)
						{
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).applies_to_location() * linkLength + lengthSum;
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = -((float)adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).link_point_attribution(k).link_point_curvature().inverse_radius_millionths_of_meter() / 1000000.0);
							indexCurv++;
						}
						else
						{
							cerr << "Error :: Adas Attributes Layer -> Link Attribution: applies_to_direction." << endl;
							return true;
						}
					}
				}
			}
		}
		else
		{
			for (int j(adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution_size() - 1); indexCurv < CURV_ARRAY_SIZE && j >= 0; j--)
			{
				for (int k(0); indexCurv < CURV_ARRAY_SIZE && k < adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).link_point_attribution_size(); k++)
				{
					if (adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).link_point_attribution(k).has_link_point_curvature())
					{
						if (adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).applies_to_direction() == 3)
						{
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = (1 - adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).applies_to_location()) * linkLength + lengthSum;
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = (float)adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).link_point_attribution(k).link_point_curvature().inverse_radius_millionths_of_meter() / 1000000.0;
							indexCurv++;
						}
						else if (adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).applies_to_direction() == 2)
						{
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = (1 - adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).applies_to_location()) * linkLength + lengthSum;
							electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = -((float)adas_attributes_layer_tile.link_attribution(linkIndex).point_attribution(j).link_point_attribution(k).link_point_curvature().inverse_radius_millionths_of_meter() / 1000000.0);
							indexCurv++;
						}
						else
						{
							cerr << "Error :: Adas Attributes Layer -> Link: applies_to_direction." << endl;
							return true;
						}
					}
				}
			}
		}

		if (indexCurv == tempIndexCurv)
		{
			if (electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv - 1].Value_0.data != CURV_UNKNOWN)
			{
				electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = lengthSum + EPSILON;
				electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = CURV_UNKNOWN;
				indexCurv++;

				if (indexCurv < CURV_ARRAY_SIZE)
				{
					electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = lengthSum + linkLength - EPSILON;
					electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = CURV_UNKNOWN;
					indexCurv++;
				}
			}
			else
			{
				if (indexCurv == 1)
				{
					electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = lengthSum + linkLength - EPSILON;
					electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = CURV_UNKNOWN;
					indexCurv++;
				}
				else
				{
					if (electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv - 2].Value_0.data != CURV_UNKNOWN)
					{
						electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].offset.data = lengthSum + linkLength - EPSILON;
						electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv].Value_0.data = CURV_UNKNOWN;
						indexCurv++;
					}
					else
					{
						electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv - 1].offset.data = lengthSum + linkLength - EPSILON;
						electronic_Horizon_data.PathsArray[0].ehSpotCurvature[indexCurv - 1].Value_0.data = CURV_UNKNOWN;
					}
				}
			}
		}
	}

	return false;
}


bool retrieve_lane_road_reference(const ::com::here::pb::hdmap::external::v1::lanes::LaneRoadReferenceLayerTile &lane_road_reference_layer_tile,
								vector<::google::protobuf::uint32>& list_Links_ID,
								::google::protobuf::uint32 LIST_LINKS_SIZE,
								unsigned int linkIndex,
								bool same_link_vs_route_direction,
								vector<linklaneref> &list_LaneGroups)
{
	int i(0);
	while (i < lane_road_reference_layer_tile.link_lane_group_references_size() && list_Links_ID[linkIndex] != lane_road_reference_layer_tile.link_lane_group_references(i).link_local_ref())
	{
		i++;
	}

	if (i >= lane_road_reference_layer_tile.link_lane_group_references_size())
	{
		cerr << "Tile's Lane Road Reference Layer binary file contains error." << endl;
		return true;
	}

	if (!list_LaneGroups.empty()) list_LaneGroups.erase(list_LaneGroups.begin(), list_LaneGroups.end() - 1);

	vector<linklaneref> arrayReferenceCopy(lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references_size());
	int countStart(0), countEnd(0);

	if (same_link_vs_route_direction)
	{
		for (int j(0); j < lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references_size(); j++)
		{
			arrayReferenceCopy[j].laneGroupID = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).lane_group_ref().lane_group_id();
			arrayReferenceCopy[j].laneGroupHereTileID = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).lane_group_ref().lane_group_here_tile_id();
			arrayReferenceCopy[j].appliesToLinkRangeStart = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).applies_to_link_range().range_offset_from_start();
			arrayReferenceCopy[j].appliesToLinkRangeEnd = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).applies_to_link_range().range_offset_from_end();
			arrayReferenceCopy[j].appliesToLaneGroupRangeStart = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).applies_to_lane_group_range().range_offset_from_start();
			arrayReferenceCopy[j].appliesToLaneGroupRangeEnd = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).applies_to_lane_group_range().range_offset_from_end();
		}
	}
	else
	{
		for (int j(0); j < lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references_size(); j++)
		{
			arrayReferenceCopy[j].laneGroupID = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).lane_group_ref().lane_group_id();
			arrayReferenceCopy[j].laneGroupHereTileID = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).lane_group_ref().lane_group_here_tile_id();
			arrayReferenceCopy[j].appliesToLinkRangeStart = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).applies_to_link_range().range_offset_from_end();
			arrayReferenceCopy[j].appliesToLinkRangeEnd = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).applies_to_link_range().range_offset_from_start();
			arrayReferenceCopy[j].appliesToLaneGroupRangeStart = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).applies_to_lane_group_range().range_offset_from_start();
			arrayReferenceCopy[j].appliesToLaneGroupRangeEnd = lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references(j).applies_to_lane_group_range().range_offset_from_end();
		}
	}

	sort(arrayReferenceCopy.begin(), arrayReferenceCopy.end(), sortcompinf());

	for (int j(0); j < lane_road_reference_layer_tile.link_lane_group_references(i).lane_group_references_size(); j++)
	{
		if (arrayReferenceCopy[j].appliesToLinkRangeStart == 0 && arrayReferenceCopy[j].appliesToLinkRangeEnd != 0)
		{
			countStart++;
		}
		if (arrayReferenceCopy[j].appliesToLinkRangeEnd == 0 && arrayReferenceCopy[j].appliesToLinkRangeStart != 0)
		{
			countEnd++;
		}
	}

	if (linkIndex == 0)
	{
		if (countStart > 1) arrayReferenceCopy.erase(arrayReferenceCopy.begin(), arrayReferenceCopy.begin() + countStart - 1);

		if (countEnd >= 2)
		{
			bool found(false);
			int k(arrayReferenceCopy.size() - 1);
			while (k > (arrayReferenceCopy.size() - 1 - countEnd) && !found)
			{
				int l(0);
				while ((l < lane_road_reference_layer_tile.lane_group_link_references_size()) && arrayReferenceCopy[k].laneGroupID != lane_road_reference_layer_tile.lane_group_link_references(l).lane_group_ref())
				{
					l++;
				}

				if (l >= lane_road_reference_layer_tile.lane_group_link_references_size())
				{
					cerr << "Lane Road Reference Layer's tile binary file contains error." << endl;
					return true;
				}

				for (int m(0); m < lane_road_reference_layer_tile.lane_group_link_references(l).link_references_size() && !found; m++)
				{
					if (lane_road_reference_layer_tile.lane_group_link_references(l).link_references(m).link_ref().link_id() == list_Links_ID[linkIndex + 1])
					{
						found = true;
					}
				}

				k--;
			}

			if (!found)
			{
				cerr << "Lane Road Reference Layer's tile binary file contains error." << endl;
				return true;
			}
			else
			{
				for (int n(0), del(arrayReferenceCopy.size() - 1); n < countEnd; n++, del--)
				{
					if (del != k + 1)
					{
						arrayReferenceCopy.erase(arrayReferenceCopy.begin() + del);
					}
				}
			}
		}
	}
	else if (linkIndex == LIST_LINKS_SIZE - 1)
	{
		bool sameLaneIdFound(false);

		if (!list_LaneGroups.empty())
		{
			for (int c(0); c < countStart; c++)
			{
				if (arrayReferenceCopy[c].laneGroupID == list_LaneGroups[0].laneGroupID) sameLaneIdFound = true;
			}
		}

		if (sameLaneIdFound) arrayReferenceCopy.erase(arrayReferenceCopy.begin(), arrayReferenceCopy.begin() + countStart);
		else
		{
			if (countStart >= 2)
			{
				bool found(false);
				int k(0);
				while (k < countStart && !found)
				{
					int l(0);
					while ((l < lane_road_reference_layer_tile.lane_group_link_references_size()) && arrayReferenceCopy[k].laneGroupID != lane_road_reference_layer_tile.lane_group_link_references(l).lane_group_ref())
					{
						l++;
					}

					if (l >= lane_road_reference_layer_tile.lane_group_link_references_size())
					{
						cerr << "Lane Road Reference Layer's tile binary file contains error." << endl;
						return true;
					}

					for (int m(0); m < lane_road_reference_layer_tile.lane_group_link_references(l).link_references_size() && !found; m++)
					{
						if (lane_road_reference_layer_tile.lane_group_link_references(l).link_references(m).link_ref().link_id() == list_Links_ID[linkIndex - 1])
						{
							found = true;
						}
					}

					k++;
				}

				if (!found)
				{
					cerr << "Lane Road Reference Layer's tile binary file contains error." << endl;
					return true;
				}
				else
				{
					for (int n(0), del(0); n < countStart; n++, del++)
					{
						if (del != k - 1)
						{
							arrayReferenceCopy.erase(arrayReferenceCopy.begin() + del);

							k--, del--;
						}
					}
				}
			}
		}

		if (countEnd > 1) arrayReferenceCopy.erase(arrayReferenceCopy.end() - countEnd + 1, arrayReferenceCopy.end());
	}
	else
	{
		bool sameLaneIdFound(false);

		if (!list_LaneGroups.empty())
		{
			for (int c(0); c < countStart; c++)
			{
				if (arrayReferenceCopy[c].laneGroupID == list_LaneGroups[0].laneGroupID) sameLaneIdFound = true;
			}
		}

		if (sameLaneIdFound) arrayReferenceCopy.erase(arrayReferenceCopy.begin(), arrayReferenceCopy.begin() + countStart);
		else
		{
			if (countStart >= 2)
			{
				bool found(false);
				int k(0);
				while (k < countStart && !found)
				{
					int l(0);
					while ((l < lane_road_reference_layer_tile.lane_group_link_references_size()) && arrayReferenceCopy[k].laneGroupID != lane_road_reference_layer_tile.lane_group_link_references(l).lane_group_ref())
					{
						l++;
					}

					if (l >= lane_road_reference_layer_tile.lane_group_link_references_size())
					{
						cerr << "Lane Road Reference Layer's tile binary file contains error." << endl;
						return true;
					}

					for (int m(0); m < lane_road_reference_layer_tile.lane_group_link_references(l).link_references_size() && !found; m++)
					{
						if (lane_road_reference_layer_tile.lane_group_link_references(l).link_references(m).link_ref().link_id() == list_Links_ID[linkIndex - 1])
						{
							found = true;
						}
					}

					k++;
				}

				if (!found)
				{
					cerr << "Lane Road Reference Layer's tile binary file contains error." << endl;
					return true;
				}
				else
				{
					for (int n(0), del(0); n < countStart; n++, del++)
					{
						if (del != k - 1)
						{
							arrayReferenceCopy.erase(arrayReferenceCopy.begin() + del);

							k--, del--;
						}
					}
				}
			}
		}

		if (countEnd >= 2)
		{
			bool found(false);
			int k(arrayReferenceCopy.size() - 1);
			while (k > (arrayReferenceCopy.size() - 1 - countEnd) && !found)
			{
				int l(0);
				while ((l < lane_road_reference_layer_tile.lane_group_link_references_size()) && arrayReferenceCopy[k].laneGroupID != lane_road_reference_layer_tile.lane_group_link_references(l).lane_group_ref())
				{
					l++;
				}

				if (l >= lane_road_reference_layer_tile.lane_group_link_references_size())
				{
					cerr << "Lane Road Reference Layer's tile binary file contains error." << endl;
					return true;
				}

				for (int m(0); m < lane_road_reference_layer_tile.lane_group_link_references(l).link_references_size() && !found; m++)
				{
					if (lane_road_reference_layer_tile.lane_group_link_references(l).link_references(m).link_ref().link_id() == list_Links_ID[linkIndex + 1])
					{
						found = true;
					}
				}

				k--;
			}

			if (!found)
			{
				cerr << "Lane Road Reference Layer's tile binary file contains error." << endl;
				return true;
			}
			else
			{
				for (int n(0), del(arrayReferenceCopy.size() - 1); n < countEnd; n++, del--)
				{
					if (del != k + 1)
					{
						arrayReferenceCopy.erase(arrayReferenceCopy.begin() + del);
					}
				}
			}
		}
	}

	for (unsigned int it(0); it < arrayReferenceCopy.size(); it++)
	{
		list_LaneGroups.push_back(arrayReferenceCopy[it]);
	}

	return false;
}


bool retrieve_lane_data(const ::com::here::pb::hdmap::external::v1::lanes::LaneTopologyLayerTile &lane_topology_layer_tile1,
						const ::com::here::pb::hdmap::external::v1::lanes::LaneTopologyLayerTile &lane_topology_layer_tile2,
						vector<linklaneref>& list_LaneGroups,
						unsigned int laneIndex,
						bool firstExec,
						bool &same_laneGroup_vs_route_direction,
						::google::protobuf::uint32 &laneGroupLength)
{
	if (firstExec)
	{
		if (list_LaneGroups.size() <= 1)
		{
			cerr << "Error :: LaneGroup direction determination not possible." << endl;
			return true;
		}

		int c(0), n(0);

		while (c < lane_topology_layer_tile1.lane_groups_starting_in_tile_size() && lane_topology_layer_tile1.lane_groups_starting_in_tile(c).lane_group_id() != list_LaneGroups[laneIndex].laneGroupID)
		{
			c++;
		}

		if (c >= lane_topology_layer_tile1.lane_groups_starting_in_tile_size())
		{
			cerr << "Lane Topology Layer's tile binary file contains error." << endl;
			return true;
		}

		while (n < lane_topology_layer_tile2.lane_groups_starting_in_tile_size() && lane_topology_layer_tile2.lane_groups_starting_in_tile(n).lane_group_id() != list_LaneGroups[laneIndex + 1].laneGroupID)
		{
			n++;
		}

		if (n >= lane_topology_layer_tile2.lane_groups_starting_in_tile_size())
		{
			cerr << "Lane Topology Layer's tile binary file contains error." << endl;
			return true;
		}

		if ((lane_topology_layer_tile1.lane_groups_starting_in_tile(c).end_lane_group_connector_ref().lane_group_connector_id() == lane_topology_layer_tile2.lane_groups_starting_in_tile(n).start_lane_group_connector_ref())
			|| (lane_topology_layer_tile1.lane_groups_starting_in_tile(c).end_lane_group_connector_ref().lane_group_connector_id() == lane_topology_layer_tile2.lane_groups_starting_in_tile(n).end_lane_group_connector_ref().lane_group_connector_id()))
		{
			same_laneGroup_vs_route_direction = true;
		}
		else
		{
			same_laneGroup_vs_route_direction = false;
		}

		laneGroupLength = lane_topology_layer_tile1.lane_groups_starting_in_tile(c).lane_group_length_meters();

		return false;

	}
	else
	{
		int p(0), c(0);

		while ((p < lane_topology_layer_tile1.lane_groups_starting_in_tile_size()) && lane_topology_layer_tile1.lane_groups_starting_in_tile(p).lane_group_id() != list_LaneGroups[laneIndex - 1].laneGroupID)
		{
			p++;
		}

		if (p >= lane_topology_layer_tile1.lane_groups_starting_in_tile_size())
		{
			cerr << "Lane Topology Layer's tile binary file contains error." << endl;
			return true;
		}

		while (c < lane_topology_layer_tile2.lane_groups_starting_in_tile_size() && lane_topology_layer_tile2.lane_groups_starting_in_tile(c).lane_group_id() != list_LaneGroups[laneIndex].laneGroupID)
		{
			c++;
		}

		if (c >= lane_topology_layer_tile2.lane_groups_starting_in_tile_size())
		{
			cerr << "Lane Topology Layer's tile binary file contains error." << endl;
			return true;
		}

		if ((lane_topology_layer_tile2.lane_groups_starting_in_tile(c).start_lane_group_connector_ref() == lane_topology_layer_tile1.lane_groups_starting_in_tile(p).start_lane_group_connector_ref())
			|| (lane_topology_layer_tile2.lane_groups_starting_in_tile(c).start_lane_group_connector_ref() == lane_topology_layer_tile1.lane_groups_starting_in_tile(p).end_lane_group_connector_ref().lane_group_connector_id()))
		{
			same_laneGroup_vs_route_direction = true;
		}
		else
		{
			same_laneGroup_vs_route_direction = false;
		}

		laneGroupLength = lane_topology_layer_tile2.lane_groups_starting_in_tile(c).lane_group_length_meters();

		return false;
	}
}


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
											const unsigned int& NBRLINE_ARRAY_SIZE)
{
	int i(0);
	while (i < lane_geometry_polyline_layer_tile.lane_group_geometries_size() && lane_geometry_polyline_layer_tile.lane_group_geometries(i).lane_group_ref() != laneGroup.laneGroupID)
	{
		i++;
	}

	if (i >= lane_geometry_polyline_layer_tile.lane_group_geometries_size())
	{
		cerr << "Lane Geometry Polyline Layer's tile binary file contains error." << endl;
		return true;
	}

	double usedLength = ((1 - laneGroup.appliesToLaneGroupRangeEnd) - laneGroup.appliesToLaneGroupRangeStart) * laneGroupLength;

	const ::com::here::pb::hdmap::external::v1::lanes::LaneGroupGeometry& laneGroupStartingInTile = lane_geometry_polyline_layer_tile.lane_group_geometries(i);

	electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[qtyNbrLine].Nbr.data = laneGroupStartingInTile.lane_boundary_geometries_size();
	electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[qtyNbrLine].offset.data = 0.0;
	qtyNbrLine++;

	if (qtyNbrLine < NBRLINE_ARRAY_SIZE)
	{
		electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[qtyNbrLine].Nbr.data = 0;
		electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[qtyNbrLine].offset.data = usedLength;
	}

	::google::protobuf::int64 coord;
	GpsCoord gps1, gps2;
	int l(0);
	double lineLength;
	vector<double> linePointDist, lineLat, lineLon;
	unsigned int posQtyLineGeo;

	if (same_laneGroup_vs_route_direction)
	{
		for (int j(laneGroupStartingInTile.lane_boundary_geometries_size() - 1); j >= 0 && l < QTYLINE_ARRAY_SIZE; j--)
		{
			coord = lane_geometry_polyline_layer_tile.tile_center_here_3d_coordinate().here_2d_coordinate();

			lineLength = 0.0;
			posQtyLineGeo = qtyLineGeo[l];

			if (laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size() > 0 && qtyLineGeo[l] < LINEGEO_ARRAY_SIZE)
			{
				coord ^= laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs(0);
				gps1 = twoDToLatLon(coord);

				linePointDist.push_back(0.0);
				lineLat.push_back(gps1.lat);
				lineLon.push_back(gps1.lon);

				qtyLineGeo[l]++;
			}

			for (int k(1); k < laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size() && qtyLineGeo[l] < LINEGEO_ARRAY_SIZE; k++)
			{
				coord ^= laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs(k);
				gps2 = twoDToLatLon(coord);

				lineLength += pointTOpointDistance(gps1, gps2);
				linePointDist.push_back(lineLength);
				lineLat.push_back(gps2.lat);
				lineLon.push_back(gps2.lon);

				gps1 = gps2;

				qtyLineGeo[l]++;
			}

			for (int m(0); m < linePointDist.size(); m++)
			{
				float pointDistCalc = linePointDist[m] / lineLength * laneGroupLength;

				if (pointDistCalc >= (laneGroupLength - usedLength))
				{
					electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[posQtyLineGeo].latitude = lineLat[m];
					electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[posQtyLineGeo].longitude = lineLon[m];
					electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[posQtyLineGeo++].offset.data = pointDistCalc - (laneGroupLength - round(usedLength));
				}
				else qtyLineGeo[l]--;
			}

			linePointDist.clear();
			lineLat.clear();
			lineLon.clear();

			l++;
		}
	}
	else
	{
		unsigned int coordGeoIndex, tempQtyLineGeo;
		for (int j(0); j < laneGroupStartingInTile.lane_boundary_geometries_size() && l < QTYLINE_ARRAY_SIZE; j++)
		{
			coord = lane_geometry_polyline_layer_tile.tile_center_here_3d_coordinate().here_2d_coordinate();

			tempQtyLineGeo = qtyLineGeo[l];

			lineLength = 0.0;
			posQtyLineGeo = qtyLineGeo[l];

			if (laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size() > 0)
			{
				coordGeoIndex = qtyLineGeo[l] + laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size() - 1;

				coord ^= laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs(0);
				gps1 = twoDToLatLon(coord);

				if (coordGeoIndex < LINEGEO_ARRAY_SIZE)
				{
					linePointDist.push_back(0.0);
					lineLat.push_back(gps1.lat);
					lineLon.push_back(gps1.lon);

					qtyLineGeo[l]++;
				}
			}

			for (int k(1); k < laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size(); k++)
			{
				coordGeoIndex = tempQtyLineGeo + laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size() - 1 - k;

				coord ^= laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs(k);
				gps2 = twoDToLatLon(coord);

				lineLength += pointTOpointDistance(gps1, gps2);

				if (coordGeoIndex < LINEGEO_ARRAY_SIZE)
				{
					linePointDist.push_back(lineLength);
					lineLat.push_back(gps2.lat);
					lineLon.push_back(gps2.lon);

					qtyLineGeo[l]++;
				}

				gps1 = gps2;
			}

			for (int m(linePointDist.size() - 1); m >= 0; m--)
			{
				float pointDistCalc = (lineLength - linePointDist[m]) / lineLength * laneGroupLength;

				if (pointDistCalc >= (laneGroupLength - usedLength))
				{
					electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[posQtyLineGeo].latitude = lineLat[m];
					electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[posQtyLineGeo].longitude = lineLon[m];
					electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[posQtyLineGeo++].offset.data = pointDistCalc - (laneGroupLength - round(usedLength));
				}
				else qtyLineGeo[l]--;
			}

			linePointDist.clear();
			lineLat.clear();
			lineLon.clear();

			l++;
		}
	}

	laneGroupLengthSum += round(usedLength);
	return false;
}


bool retrieve_lane_geometry_polyline(const ::com::here::pb::hdmap::external::v1::lanes::LaneGeometryPolylineLayerTile& lane_geometry_polyline_layer_tile,
									const linklaneref& laneGroup,
									const bool& same_laneGroup_vs_route_direction,
									const ::google::protobuf::uint32& laneGroupLength,
									::google::protobuf::uint32 &laneGroupLengthSum,
									project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
									unsigned int *qtyLineGeo,
									const unsigned int& QTYLINE_ARRAY_SIZE,
									const unsigned int& LINEGEO_ARRAY_SIZE,
									unsigned int &qtyNbrLine,
									const unsigned int& NBRLINE_ARRAY_SIZE)
{
	int i(0);
	while (i < lane_geometry_polyline_layer_tile.lane_group_geometries_size() && lane_geometry_polyline_layer_tile.lane_group_geometries(i).lane_group_ref() != laneGroup.laneGroupID)
	{
		i++;
	}

	if (i >= lane_geometry_polyline_layer_tile.lane_group_geometries_size())
	{
		cerr << "Tile's Lane Geometry Polyline Layer binary file contains error." << endl;
		return true;
	}

	const ::com::here::pb::hdmap::external::v1::lanes::LaneGroupGeometry& laneGroupStartingInTile = lane_geometry_polyline_layer_tile.lane_group_geometries(i);

	if (qtyNbrLine < NBRLINE_ARRAY_SIZE)
	{
		if (electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[qtyNbrLine - 1].Nbr.data != laneGroupStartingInTile.lane_boundary_geometries_size())
		{
			electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[qtyNbrLine].Nbr.data = laneGroupStartingInTile.lane_boundary_geometries_size();
			qtyNbrLine++;
				
			if (qtyNbrLine < NBRLINE_ARRAY_SIZE)
			{
				electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[qtyNbrLine].Nbr.data = 0;
				electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[qtyNbrLine].offset.data = laneGroupLength + laneGroupLengthSum;
			}
		}
		else
		{
			electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[qtyNbrLine].offset.data = laneGroupLength + laneGroupLengthSum;
		}
	}

	::google::protobuf::int64 coord;
	GpsCoord gps1, gps2;
	int l(0);
	double lineLength;
	vector<double> linePointDist;
	unsigned int posQtyLineGeo;

	if (same_laneGroup_vs_route_direction)
	{
		for (int j(laneGroupStartingInTile.lane_boundary_geometries_size() - 1); j >= 0 && l < QTYLINE_ARRAY_SIZE; j--)
		{
			coord = lane_geometry_polyline_layer_tile.tile_center_here_3d_coordinate().here_2d_coordinate();

			lineLength = 0.0;
			posQtyLineGeo = qtyLineGeo[l];

			if (laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size() > 0 && qtyLineGeo[l] < LINEGEO_ARRAY_SIZE)
			{
				coord ^= laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs(0);
				gps1 = twoDToLatLon(coord);

				linePointDist.push_back(0.0);

				electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[qtyLineGeo[l]].latitude = gps1.lat;
				electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[qtyLineGeo[l]].longitude = gps1.lon;

				qtyLineGeo[l]++;
			}

			for (int k(1); k < laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size() && qtyLineGeo[l] < LINEGEO_ARRAY_SIZE; k++)
			{
				coord ^= laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs(k);
				gps2 = twoDToLatLon(coord);

				lineLength += pointTOpointDistance(gps1, gps2);
				linePointDist.push_back(lineLength);
				gps1 = gps2;

				electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[qtyLineGeo[l]].latitude = gps2.lat;
				electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[qtyLineGeo[l]].longitude = gps2.lon;

				qtyLineGeo[l]++;
			}

			for (int m(0); m < linePointDist.size(); m++)
			{
				electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[posQtyLineGeo + m].offset.data = linePointDist[m] / lineLength * laneGroupLength + laneGroupLengthSum;
			}

			linePointDist.clear();

			l++;
		}
	}
	else
	{
		unsigned int coordGeoIndex, tempQtyLineGeo;
		for (int j(0); j < laneGroupStartingInTile.lane_boundary_geometries_size() && l < QTYLINE_ARRAY_SIZE; j++)
		{
			coord = lane_geometry_polyline_layer_tile.tile_center_here_3d_coordinate().here_2d_coordinate();

			tempQtyLineGeo = qtyLineGeo[l];

			lineLength = 0.0;
			posQtyLineGeo = qtyLineGeo[l];

			if (laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size() > 0)
			{
				coordGeoIndex = qtyLineGeo[l] + laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size() - 1;

				coord ^= laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs(0);
				gps1 = twoDToLatLon(coord);

				if (coordGeoIndex < LINEGEO_ARRAY_SIZE)
				{
					linePointDist.push_back(0.0);

					electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[coordGeoIndex].latitude = gps1.lat;
					electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[coordGeoIndex].longitude = gps1.lon;

					qtyLineGeo[l]++;
				}
			}

			for (int k(1); k < laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size(); k++)
			{
				coordGeoIndex = tempQtyLineGeo + laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs_size() - 1 - k;

				coord ^= laneGroupStartingInTile.lane_boundary_geometries(j).geometry().here_2d_coordinate_diffs(k);
				gps2 = twoDToLatLon(coord);

				lineLength += pointTOpointDistance(gps1, gps2);

				if (coordGeoIndex < LINEGEO_ARRAY_SIZE)
				{
					linePointDist.push_back(lineLength);

					electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[coordGeoIndex].latitude = gps2.lat;
					electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[coordGeoIndex].longitude = gps2.lon;

					qtyLineGeo[l]++;
				}

				gps1 = gps2;
			}

			for (int m(linePointDist.size() - 1); m >= 0; m--)
			{
				electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[l].ehSpotCoordGeo[posQtyLineGeo++].offset.data = (lineLength - linePointDist[m]) / lineLength * laneGroupLength + laneGroupLengthSum;				
			}

			linePointDist.clear();

			l++;
		}
	}

	laneGroupLengthSum += laneGroupLength;
	return false;
}


inline void initEH(project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
					unsigned int CURV_ARRAY_SIZE,
					unsigned int SPEED_ARRAY_SIZE,
					unsigned int QTYLINE_ARRAY_SIZE,
					unsigned int LINEGEO_ARRAY_SIZE,
					unsigned int NBRLINE_ARRAY_SIZE,
					int &histoFirstLinkOnRouteIndex,
					int &histoLastPlusOneLinkOnRouteIndex,
					vector<::google::protobuf::uint32> &histoLinkLength,
					vector<bool> &histo_same_link_vs_route_direction,
					::google::protobuf::uint32 &linkLengthSum,
					::google::protobuf::uint32 &laneGroupLengthSum,
					unsigned int &indexCurv,
					unsigned int &indexSpeed,
					unsigned int *qtyLineGeo,
					unsigned int &qtyNbrLine,
					vector<linklaneref> &list_LaneGroups)
{
	histoFirstLinkOnRouteIndex = -1;
	histoLastPlusOneLinkOnRouteIndex = -1;
	histoLinkLength.clear();
	histo_same_link_vs_route_direction.clear();
	linkLengthSum = 0;
	laneGroupLengthSum = 0;
	indexCurv = 0;
	indexSpeed = 0;
	qtyNbrLine = 0;
	list_LaneGroups.clear();

	for (int i(0); i < QTYLINE_ARRAY_SIZE; i++) qtyLineGeo[i] = 0;


	for (int ini(0); ini < SPEED_ARRAY_SIZE; ini++)
	{
		electronic_Horizon_data.PathsArray[0].ehSegment[ini].offset.data = 0.0;
		electronic_Horizon_data.PathsArray[0].ehSegment[ini].effectiveSpeedLimit.data = 0;
	}

	electronic_Horizon_data.PathsArray[0].NbrSegment.data = 0;

	for (int ini(0); ini < CURV_ARRAY_SIZE; ini++)
	{
		electronic_Horizon_data.PathsArray[0].ehSpotCurvature[ini].offset.data = 0.0;
		electronic_Horizon_data.PathsArray[0].ehSpotCurvature[ini].Value_0.data = 0.0;
	}

	electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data = 0;

	for (int init(0); init < QTYLINE_ARRAY_SIZE; init++)
	{
		for (int ini(0); ini < LINEGEO_ARRAY_SIZE; ini++)
		{
			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[init].ehSpotCoordGeo[ini].offset.data = 0.0;
			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[init].ehSpotCoordGeo[ini].latitude = 0.0;
			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[init].ehSpotCoordGeo[ini].longitude = 0.0;
		}

		electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[init].NbrSpotCoordGeo.data = 0;
	}

	electronic_Horizon_data.PathsArray[0].QtyLineCoordGeo.data = 0;

	for (int ini(0); ini < NBRLINE_ARRAY_SIZE; ini++)
	{
		electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[ini].Nbr.data = 0;
		electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[ini].offset.data = 0.0;
	}

	electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data = 0;
}


bool electronic_horizon(project_s_msgs::ElectronicHorizonArray &electronic_Horizon_data,
						project_s_msgs::MapMatching Map_Matching_data,
						project_s_msgs::RoutePlanning Route_Planning_data)
{
	const unsigned int CURV_ARRAY_SIZE = sizeof(electronic_Horizon_data.PathsArray[0].ehSpotCurvature) / sizeof(electronic_Horizon_data.PathsArray[0].ehSpotCurvature[0]);
	const unsigned int SPEED_ARRAY_SIZE = sizeof(electronic_Horizon_data.PathsArray[0].ehSegment) / sizeof(electronic_Horizon_data.PathsArray[0].ehSegment[0]);
	const unsigned int QTYLINE_ARRAY_SIZE = sizeof(electronic_Horizon_data.PathsArray[0].ehLineCoordGeo) / sizeof(electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[0]);
	const unsigned int LINEGEO_ARRAY_SIZE = sizeof(electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[0].ehSpotCoordGeo) / sizeof(electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[0].ehSpotCoordGeo[0]);
	const unsigned int NBRLINE_ARRAY_SIZE = sizeof(electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo) / sizeof(electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[0]);
	const unsigned int SIGN_ARRAY_SIZE = sizeof(electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign) / sizeof(electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[0]);

	if (Route_Planning_data.LIST_LINKS_SIZE != 100)	// NORMAL MODE
	{
		static int histoFirstLinkOnRouteIndex = -1;
		static int histoLastPlusOneLinkOnRouteIndex = -1;
		static vector<::google::protobuf::uint32> histoLinkLength;
		static vector<bool> histo_same_link_vs_route_direction;
		static ::google::protobuf::uint32 linkLengthSum(0), laneGroupLengthSum(0);
		static unsigned int indexCurv(0), indexSpeed(0), qtyLineGeo[QTYLINE_ARRAY_SIZE] = { 0 }, qtyNbrLine(0);
		static vector<linklaneref> list_LaneGroups;

		// topology_layer_tile class instance
		static ::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile topology_layer_tile;

		// speed_attributes_layer_tile class instance
		static ::com::here::pb::hdmap::external::v1::speed::SpeedAttributesLayerTile speed_attributes_layer_tile;

		// adas_attributes_layer_tile class instance
		static ::com::here::pb::hdmap::external::v1::adas::AdasAttributesLayerTile adas_attributes_layer_tile;

		// lane_road_reference_layer_tile class instance
		static ::com::here::pb::hdmap::external::v1::lanes::LaneRoadReferenceLayerTile lane_road_reference_layer_tile;

		// lane_topology_layer_tile class instances
		static ::com::here::pb::hdmap::external::v1::lanes::LaneTopologyLayerTile lane_topology_layer_tile1, lane_topology_layer_tile2;

		// lane_geometry_polyline_layer_tile class instances
		static ::com::here::pb::hdmap::external::v1::lanes::LaneGeometryPolylineLayerTile lane_geometry_polyline_layer_tile1, lane_geometry_polyline_layer_tile2;


		int linkOnRouteIndex(0);

		while ((linkOnRouteIndex < Route_Planning_data.LIST_LINKS_SIZE) && (Map_Matching_data.link_ID.data != Route_Planning_data.list_Links_ID[linkOnRouteIndex]))
		{
			linkOnRouteIndex++;
		}

		if (linkOnRouteIndex < Route_Planning_data.LIST_LINKS_SIZE)
		{
			if (electronic_Horizon_data.PathsArray[0].NbrSegment.data == 0)
			{
				histoFirstLinkOnRouteIndex = linkOnRouteIndex;

				bool error;

				error = load_tile_centerline_data(Route_Planning_data.list_Nodes_HEREtile_ID[linkOnRouteIndex], topology_layer_tile, speed_attributes_layer_tile, adas_attributes_layer_tile);
				if (error) return true;

				int nodeIndex;
				::google::protobuf::uint32 linkLength(0);

				error = retrieve_node_data(topology_layer_tile, Route_Planning_data.list_Nodes_ID[linkOnRouteIndex], nodeIndex);
				if (error) return true;

				if (linkOnRouteIndex == 0)
				{
					retrieve_route_origin_node_adas_attributes(electronic_Horizon_data, indexCurv);
				}
				else
				{
					error = retrieve_node_adas_attributes(adas_attributes_layer_tile, nodeIndex, Route_Planning_data.list_Links_ID[linkOnRouteIndex - 1], Route_Planning_data.list_Links_ID[linkOnRouteIndex], 0, 0, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
					if (error)
					{
						cerr << "Error :: retrieve_node_adas_attributes." << endl;

						initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

						return true;
					}
				}

				if (Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex] != topology_layer_tile.here_tile_id())
				{
					if (load_tile_centerline_data(Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex], topology_layer_tile, speed_attributes_layer_tile, adas_attributes_layer_tile))
					{
						return true;
					}
				}

				int linkIndex;
				bool same_link_vs_route_direction;

				error = retrieve_link_data(topology_layer_tile, Route_Planning_data.list_Links_ID[linkOnRouteIndex], linkIndex, Route_Planning_data.list_Nodes_ID[linkOnRouteIndex], Route_Planning_data.list_Nodes_ID[linkOnRouteIndex + 1], same_link_vs_route_direction);
				if (error)
				{
					cerr << "Error :: retrieve_link_data." << endl;

					initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

					return true;
				}

				linkLength = topology_layer_tile.links_starting_in_tile(linkIndex).link_length_meters();
				histoLinkLength.push_back(linkLength);

				histo_same_link_vs_route_direction.push_back(same_link_vs_route_direction);

				error = retrieve_speed_attributes(speed_attributes_layer_tile, linkIndex, same_link_vs_route_direction, linkLength, linkLengthSum, electronic_Horizon_data, indexSpeed, SPEED_ARRAY_SIZE);
				if (error)
				{
					cerr << "Error :: retrieve_speed_attributes." << endl;

					initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

					return true;
				}

				error = retrieve_link_adas_attributes(adas_attributes_layer_tile, linkIndex, same_link_vs_route_direction, linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
				if (error)
				{
					cerr << "Error :: retrieve_link_adas_attributes." << endl;

					initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

					return true;
				}

				bool same_laneGroup_vs_route_direction;
				::google::protobuf::uint32 laneGroupLength(0);

				if (load_tile_LaneRoadRef_data(Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex], lane_road_reference_layer_tile))
				{
					return true;
				}

				error = retrieve_lane_road_reference(lane_road_reference_layer_tile, Route_Planning_data.list_Links_ID, Route_Planning_data.LIST_LINKS_SIZE, linkOnRouteIndex, same_link_vs_route_direction, list_LaneGroups);
				if (error)
				{
					cerr << "Error :: retrieve_lane_road_reference." << endl;

					initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

					return true;
				}

				if (load_tile_lane_data(list_LaneGroups[0].laneGroupHereTileID, lane_topology_layer_tile1, lane_geometry_polyline_layer_tile1))
				{
					return true;
				}

				if (load_tile_lane_data(list_LaneGroups[1].laneGroupHereTileID, lane_topology_layer_tile2, lane_geometry_polyline_layer_tile2))
				{
					return true;
				}

				error = retrieve_lane_data(lane_topology_layer_tile1, lane_topology_layer_tile2, list_LaneGroups, 0, true, same_laneGroup_vs_route_direction, laneGroupLength);
				if (error)
				{
					cerr << "Error :: retrieve_lane_data." << endl;

					initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

					return true;
				}

				error = retrieve_first_lane_geometry_polyline(lane_geometry_polyline_layer_tile1, list_LaneGroups[0], same_laneGroup_vs_route_direction, laneGroupLength, laneGroupLengthSum, electronic_Horizon_data, qtyLineGeo, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, qtyNbrLine, NBRLINE_ARRAY_SIZE);
				if (error)
				{
					cerr << "Error :: retrieve_first_lane_geometry_polyline." << endl;

					initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

					return true;
				}

				for (int a(1); a < list_LaneGroups.size(); a++)
				{
					if (list_LaneGroups[a].laneGroupHereTileID != lane_topology_layer_tile2.here_tile_id())
					{
						if (load_tile_lane_data(list_LaneGroups[a].laneGroupHereTileID, lane_topology_layer_tile2, lane_geometry_polyline_layer_tile2))
						{
							return true;
						}
					}

					if (list_LaneGroups[a - 1].laneGroupHereTileID != lane_topology_layer_tile1.here_tile_id())
					{
						if (load_tile_lane_data(list_LaneGroups[a - 1].laneGroupHereTileID, lane_topology_layer_tile1, lane_geometry_polyline_layer_tile1))
						{
							return true;
						}
					}

					error = retrieve_lane_data(lane_topology_layer_tile1, lane_topology_layer_tile2, list_LaneGroups, a, false, same_laneGroup_vs_route_direction, laneGroupLength);
					if (error)
					{
						cerr << "Error :: retrieve_lane_data." << endl;

						initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

						return true;
					}

					error = retrieve_lane_geometry_polyline(lane_geometry_polyline_layer_tile2, list_LaneGroups[a], same_laneGroup_vs_route_direction, laneGroupLength, laneGroupLengthSum, electronic_Horizon_data, qtyLineGeo, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, qtyNbrLine, NBRLINE_ARRAY_SIZE);
					if (error)
					{
						cerr << "Error :: retrieve_lane_geometry_polyline." << endl;

						initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

						return true;
					}

					if (list_LaneGroups[a - 1].laneGroupHereTileID != list_LaneGroups[a].laneGroupHereTileID)
					{
						lane_topology_layer_tile1 = lane_topology_layer_tile2;
						lane_geometry_polyline_layer_tile1 = lane_geometry_polyline_layer_tile2;
					}
				}

				if (Route_Planning_data.list_Nodes_HEREtile_ID[linkOnRouteIndex + 1] != topology_layer_tile.here_tile_id())
				{
					if (load_tile_centerline_data(Route_Planning_data.list_Nodes_HEREtile_ID[linkOnRouteIndex + 1], topology_layer_tile, speed_attributes_layer_tile, adas_attributes_layer_tile))
					{
						return true;
					}
				}

				error = retrieve_node_data(topology_layer_tile, Route_Planning_data.list_Nodes_ID[linkOnRouteIndex + 1], nodeIndex);
				if (error) return true;

				if (linkOnRouteIndex == Route_Planning_data.LIST_LINKS_SIZE - 1)
				{
					retrieve_route_final_node_adas_attributes(linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
				}
				else
				{
					error = retrieve_node_adas_attributes(adas_attributes_layer_tile, nodeIndex, Route_Planning_data.list_Links_ID[linkOnRouteIndex], Route_Planning_data.list_Links_ID[linkOnRouteIndex + 1], linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
					if (error)
					{
						cerr << "Error :: retrieve_node_adas_attributes." << endl;

						initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

						return true;
					}
				}

				linkLengthSum += linkLength;
				linkOnRouteIndex++;

				while (linkOnRouteIndex < Route_Planning_data.LIST_LINKS_SIZE && (((float)linkLengthSum - Map_Matching_data.Distance_Curviligne_Ego.data) < EHorizonExtend))
				{
					if (Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex] != topology_layer_tile.here_tile_id())
					{
						if (load_tile_centerline_data(Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex], topology_layer_tile, speed_attributes_layer_tile, adas_attributes_layer_tile))
						{
							return true;
						}
					}

					error = retrieve_link_data(topology_layer_tile, Route_Planning_data.list_Links_ID[linkOnRouteIndex], linkIndex, Route_Planning_data.list_Nodes_ID[linkOnRouteIndex], Route_Planning_data.list_Nodes_ID[linkOnRouteIndex + 1], same_link_vs_route_direction);
					if (error)
					{
						cerr << "Error :: retrieve_link_data." << endl;

						initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

						return true;
					}

					linkLength = topology_layer_tile.links_starting_in_tile(linkIndex).link_length_meters();
					histoLinkLength.push_back(linkLength);

					histo_same_link_vs_route_direction.push_back(same_link_vs_route_direction);

					error = retrieve_speed_attributes(speed_attributes_layer_tile, linkIndex, same_link_vs_route_direction, linkLength, linkLengthSum, electronic_Horizon_data, indexSpeed, SPEED_ARRAY_SIZE);
					if (error)
					{
						cerr << "Error :: retrieve_speed_attributes." << endl;

						initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

						return true;
					}

					error = retrieve_link_adas_attributes(adas_attributes_layer_tile, linkIndex, same_link_vs_route_direction, linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
					if (error)
					{
						cerr << "Error :: retrieve_link_adas_attributes." << endl;

						initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

						return true;
					}

					if (Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex] != lane_road_reference_layer_tile.here_tile_id())
					{
						if (load_tile_LaneRoadRef_data(Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex], lane_road_reference_layer_tile))
						{
							return true;
						}
					}

					error = retrieve_lane_road_reference(lane_road_reference_layer_tile, Route_Planning_data.list_Links_ID, Route_Planning_data.LIST_LINKS_SIZE, linkOnRouteIndex, same_link_vs_route_direction, list_LaneGroups);
					if (error)
					{
						cerr << "Error :: retrieve_lane_road_reference." << endl;

						initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

						return true;
					}

					for (int a(1); a < list_LaneGroups.size(); a++)
					{
						if (list_LaneGroups[a].laneGroupHereTileID != lane_topology_layer_tile2.here_tile_id())
						{
							if (load_tile_lane_data(list_LaneGroups[a].laneGroupHereTileID, lane_topology_layer_tile2, lane_geometry_polyline_layer_tile2))
							{
								return true;
							}
						}

						if (list_LaneGroups[a - 1].laneGroupHereTileID != lane_topology_layer_tile1.here_tile_id())
						{
							if (load_tile_lane_data(list_LaneGroups[a - 1].laneGroupHereTileID, lane_topology_layer_tile1, lane_geometry_polyline_layer_tile1))
							{
								return true;
							}
						}

						error = retrieve_lane_data(lane_topology_layer_tile1, lane_topology_layer_tile2, list_LaneGroups, a, false, same_laneGroup_vs_route_direction, laneGroupLength);
						if (error)
						{
							cerr << "Error :: retrieve_lane_data." << endl;

							initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

							return true;
						}

						error = retrieve_lane_geometry_polyline(lane_geometry_polyline_layer_tile2, list_LaneGroups[a], same_laneGroup_vs_route_direction, laneGroupLength, laneGroupLengthSum, electronic_Horizon_data, qtyLineGeo, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, qtyNbrLine, NBRLINE_ARRAY_SIZE);
						if (error)
						{
							cerr << "Error :: retrieve_lane_geometry_polyline." << endl;

							initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

							return true;
						}

						if (list_LaneGroups[a - 1].laneGroupHereTileID != list_LaneGroups[a].laneGroupHereTileID)
						{
							lane_topology_layer_tile1 = lane_topology_layer_tile2;
							lane_geometry_polyline_layer_tile1 = lane_geometry_polyline_layer_tile2;
						}
					}

					if (Route_Planning_data.list_Nodes_HEREtile_ID[linkOnRouteIndex + 1] != topology_layer_tile.here_tile_id())
					{
						if (load_tile_centerline_data(Route_Planning_data.list_Nodes_HEREtile_ID[linkOnRouteIndex + 1], topology_layer_tile, speed_attributes_layer_tile, adas_attributes_layer_tile))
						{
							return true;
						}
					}

					error = retrieve_node_data(topology_layer_tile, Route_Planning_data.list_Nodes_ID[linkOnRouteIndex + 1], nodeIndex);
					if (error) return true;

					if (linkOnRouteIndex == Route_Planning_data.LIST_LINKS_SIZE - 1)
					{
						retrieve_route_final_node_adas_attributes(linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
					}
					else
					{
						error = retrieve_node_adas_attributes(adas_attributes_layer_tile, nodeIndex, Route_Planning_data.list_Links_ID[linkOnRouteIndex], Route_Planning_data.list_Links_ID[linkOnRouteIndex + 1], linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
						if (error)
						{
							cerr << "Error :: retrieve_node_adas_attributes." << endl;

							initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

							return true;
						}
					}

					linkLengthSum += linkLength;
					linkOnRouteIndex++;
				}

				histoLastPlusOneLinkOnRouteIndex = linkOnRouteIndex;

				if (indexSpeed < SPEED_ARRAY_SIZE) electronic_Horizon_data.PathsArray[0].NbrSegment.data = indexSpeed + 1;
				else
				{
					electronic_Horizon_data.PathsArray[0].NbrSegment.data = SPEED_ARRAY_SIZE;
					electronic_Horizon_data.PathsArray[0].ehSegment[SPEED_ARRAY_SIZE - 1].effectiveSpeedLimit.data = UNDEFINED_SPEED_LIMIT;
				}

				electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data = indexCurv;

				electronic_Horizon_data.PathsArray[0].QtyLineCoordGeo.data = 0;
				for (int h(0); h < QTYLINE_ARRAY_SIZE; h++)
				{
					electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[h].NbrSpotCoordGeo.data = qtyLineGeo[h];
					if (qtyLineGeo[h] != 0) electronic_Horizon_data.PathsArray[0].QtyLineCoordGeo.data++;
				}

				if (qtyNbrLine < NBRLINE_ARRAY_SIZE) electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data = qtyNbrLine + 1;
				else electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data = qtyNbrLine;
			}
			else
			{
				if (histoFirstLinkOnRouteIndex < linkOnRouteIndex)
				{
					if (linkOnRouteIndex > histoLastPlusOneLinkOnRouteIndex)
					{
						cerr << "Error :: Ego went too far compared to the history. Some links data are missing." << endl;

						initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

						return true;
					}

					::google::protobuf::uint32 linkLengthToSubtract(0), laneGroupLengthToSubtract(0);

					for (int i(0); i < (linkOnRouteIndex - histoFirstLinkOnRouteIndex); i++)
					{
						linkLengthToSubtract += histoLinkLength[i];
					}
					laneGroupLengthToSubtract = linkLengthToSubtract;

					linkLengthSum -= linkLengthToSubtract;
					laneGroupLengthSum -= laneGroupLengthToSubtract;

					histoLinkLength.erase(histoLinkLength.begin(), histoLinkLength.begin() + (linkOnRouteIndex - histoFirstLinkOnRouteIndex));

					histo_same_link_vs_route_direction.erase(histo_same_link_vs_route_direction.begin(), histo_same_link_vs_route_direction.begin() + (linkOnRouteIndex - histoFirstLinkOnRouteIndex));

					histoFirstLinkOnRouteIndex = linkOnRouteIndex;

					for (int i(0); i < electronic_Horizon_data.PathsArray[0].NbrSegment.data; i++)
					{
						electronic_Horizon_data.PathsArray[0].ehSegment[i].offset.data -= linkLengthToSubtract;
					}

					{
						int i(0);
						while (i < electronic_Horizon_data.PathsArray[0].NbrSegment.data && electronic_Horizon_data.PathsArray[0].ehSegment[i].offset.data < rearEHorizonExtend)
						{
							i++;
						}

						if (i != 0)
						{
							electronic_Horizon_data.PathsArray[0].ehSegment[i - 1].offset.data = rearEHorizonExtend;

							if (i > 1)
							{
								for (int j(0); j < electronic_Horizon_data.PathsArray[0].NbrSegment.data - (i - 1); j++)
								{
									electronic_Horizon_data.PathsArray[0].ehSegment[j].offset.data = electronic_Horizon_data.PathsArray[0].ehSegment[i - 1 + j].offset.data;
									electronic_Horizon_data.PathsArray[0].ehSegment[j].effectiveSpeedLimit.data = electronic_Horizon_data.PathsArray[0].ehSegment[i - 1 + j].effectiveSpeedLimit.data;
								}

								for (int j(electronic_Horizon_data.PathsArray[0].NbrSegment.data - (i - 1)); j < electronic_Horizon_data.PathsArray[0].NbrSegment.data; j++)
								{
									electronic_Horizon_data.PathsArray[0].ehSegment[j].offset.data = 0.0;
									electronic_Horizon_data.PathsArray[0].ehSegment[j].effectiveSpeedLimit.data = 0;
								}
							}

							electronic_Horizon_data.PathsArray[0].NbrSegment.data -= i - 1;
							indexSpeed -= i - 1;
						}
					}

					for (int i(0); i < electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data; i++)
					{
						electronic_Horizon_data.PathsArray[0].ehSpotCurvature[i].offset.data -= linkLengthToSubtract;
					}

					{
						int i(0);
						while (i < electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data && electronic_Horizon_data.PathsArray[0].ehSpotCurvature[i].offset.data < rearEHorizonExtend)
						{
							i++;
						}

						if (i != 0)
						{
							if (i > 1)
							{
								for (int j(0); j < electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data - (i - 1); j++)
								{
									electronic_Horizon_data.PathsArray[0].ehSpotCurvature[j].offset.data = electronic_Horizon_data.PathsArray[0].ehSpotCurvature[i - 1 + j].offset.data;
									electronic_Horizon_data.PathsArray[0].ehSpotCurvature[j].Value_0.data = electronic_Horizon_data.PathsArray[0].ehSpotCurvature[i - 1 + j].Value_0.data;
								}

								for (int j(electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data - (i - 1)); j < electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data; j++)
								{
									electronic_Horizon_data.PathsArray[0].ehSpotCurvature[j].offset.data = 0.0;
									electronic_Horizon_data.PathsArray[0].ehSpotCurvature[j].Value_0.data = 0;
								}
							}

							electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data -= i - 1;
							indexCurv -= i - 1;
						}
					}

					for (int i(0); i < electronic_Horizon_data.PathsArray[0].QtyLineCoordGeo.data; i++)
					{
						for (int j(0); j < electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[i].NbrSpotCoordGeo.data; j++)
						{
							electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[i].ehSpotCoordGeo[j].offset.data -= laneGroupLengthToSubtract;
						}
					}

					{
						for (int k(0); k < electronic_Horizon_data.PathsArray[0].QtyLineCoordGeo.data; k++)
						{
							int i(0);
							while (i < electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].NbrSpotCoordGeo.data && electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].ehSpotCoordGeo[i].offset.data < rearEHorizonExtend)
							{
								i++;
							}

							if (i != 0)
							{
								if (i > 1)
								{
									for (int j(0); j < electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].NbrSpotCoordGeo.data - (i - 1); j++)
									{
										electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].ehSpotCoordGeo[j].offset.data = electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].ehSpotCoordGeo[i - 1 + j].offset.data;
										electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].ehSpotCoordGeo[j].latitude = electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].ehSpotCoordGeo[i - 1 + j].latitude;
										electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].ehSpotCoordGeo[j].longitude = electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].ehSpotCoordGeo[i - 1 + j].longitude;
									}

									for (int j(electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].NbrSpotCoordGeo.data - (i - 1)); j < electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].NbrSpotCoordGeo.data; j++)
									{
										electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].ehSpotCoordGeo[j].offset.data = 0.0;
										electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].ehSpotCoordGeo[j].latitude = 0.0;
										electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].ehSpotCoordGeo[j].longitude = 0.0;
									}
								}

								electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[k].NbrSpotCoordGeo.data -= i - 1;
								qtyLineGeo[k] -= i - 1;
							}
						}
					}

					for (int i(0); i < electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data; i++)
					{
						electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[i].offset.data -= laneGroupLengthToSubtract;
					}

					{
						int i(0);
						while (i < electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data && electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[i].offset.data < rearEHorizonExtend)
						{
							i++;
						}

						if (i != 0)
						{
							electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[i - 1].offset.data = rearEHorizonExtend;

							if (i > 1)
							{
								for (int j(0); j < electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data - (i - 1); j++)
								{
									electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[j].offset.data = electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[i - 1 + j].offset.data;
									electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[j].Nbr.data = electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[i - 1 + j].Nbr.data;
								}

								for (int j(electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data - (i - 1)); j < electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data; j++)
								{
									electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[j].offset.data = 0.0;
									electronic_Horizon_data.PathsArray[0].ehNbrLineCoordGeo[j].Nbr.data = 0;
								}
							}

							electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data -= i - 1;
							qtyNbrLine -= i - 1;
						}
					}

					if ((linkLengthSum + linkLengthToSubtract) > EHorizonExtend && ((float)linkLengthSum - Map_Matching_data.Distance_Curviligne_Ego.data) < EHorizonExtend)
					{
						linkOnRouteIndex = histoLastPlusOneLinkOnRouteIndex;

						if (linkOnRouteIndex < Route_Planning_data.LIST_LINKS_SIZE)
						{
							bool error;
							::google::protobuf::uint32 linkLength(0);
							int linkIndex, nodeIndex;
							bool same_link_vs_route_direction, same_laneGroup_vs_route_direction;
							::google::protobuf::uint32 laneGroupLength(0);

							while (linkOnRouteIndex < Route_Planning_data.LIST_LINKS_SIZE && (((float)linkLengthSum - Map_Matching_data.Distance_Curviligne_Ego.data) < EHorizonExtend))
							{
								if (Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex] != topology_layer_tile.here_tile_id())
								{
									if (load_tile_centerline_data(Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex], topology_layer_tile, speed_attributes_layer_tile, adas_attributes_layer_tile))
									{
										return true;
									}
								}

								error = retrieve_link_data(topology_layer_tile, Route_Planning_data.list_Links_ID[linkOnRouteIndex], linkIndex, Route_Planning_data.list_Nodes_ID[linkOnRouteIndex], Route_Planning_data.list_Nodes_ID[linkOnRouteIndex + 1], same_link_vs_route_direction);
								if (error)
								{
									cerr << "Error :: retrieve_link_data." << endl;

									initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

									return true;
								}

								linkLength = topology_layer_tile.links_starting_in_tile(linkIndex).link_length_meters();
								histoLinkLength.push_back(linkLength);

								histo_same_link_vs_route_direction.push_back(same_link_vs_route_direction);

								error = retrieve_speed_attributes(speed_attributes_layer_tile, linkIndex, same_link_vs_route_direction, linkLength, linkLengthSum, electronic_Horizon_data, indexSpeed, SPEED_ARRAY_SIZE);
								if (error)
								{
									cerr << "Error :: retrieve_speed_attributes." << endl;

									initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

									return true;
								}

								error = retrieve_link_adas_attributes(adas_attributes_layer_tile, linkIndex, same_link_vs_route_direction, linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
								if (error)
								{
									cerr << "Error :: retrieve_link_adas_attributes." << endl;

									initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

									return true;
								}

								if (Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex] != lane_road_reference_layer_tile.here_tile_id())
								{
									if (load_tile_LaneRoadRef_data(Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex], lane_road_reference_layer_tile))
									{
										return true;
									}
								}

								error = retrieve_lane_road_reference(lane_road_reference_layer_tile, Route_Planning_data.list_Links_ID, Route_Planning_data.LIST_LINKS_SIZE, linkOnRouteIndex, same_link_vs_route_direction, list_LaneGroups);
								if (error)
								{
									cerr << "Error :: retrieve_lane_road_reference." << endl;

									initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

									return true;
								}

								for (int a(1); a < list_LaneGroups.size(); a++)
								{
									if (list_LaneGroups[a].laneGroupHereTileID != lane_topology_layer_tile2.here_tile_id())
									{
										if (load_tile_lane_data(list_LaneGroups[a].laneGroupHereTileID, lane_topology_layer_tile2, lane_geometry_polyline_layer_tile2))
										{
											return true;
										}
									}

									if (list_LaneGroups[a - 1].laneGroupHereTileID != lane_topology_layer_tile1.here_tile_id())
									{
										if (load_tile_lane_data(list_LaneGroups[a - 1].laneGroupHereTileID, lane_topology_layer_tile1, lane_geometry_polyline_layer_tile1))
										{
											return true;
										}
									}

									error = retrieve_lane_data(lane_topology_layer_tile1, lane_topology_layer_tile2, list_LaneGroups, a, false, same_laneGroup_vs_route_direction, laneGroupLength);
									if (error)
									{
										cerr << "Error :: retrieve_lane_data." << endl;

										initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

										return true;
									}

									error = retrieve_lane_geometry_polyline(lane_geometry_polyline_layer_tile2, list_LaneGroups[a], same_laneGroup_vs_route_direction, laneGroupLength, laneGroupLengthSum, electronic_Horizon_data, qtyLineGeo, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, qtyNbrLine, NBRLINE_ARRAY_SIZE);
									if (error)
									{
										cerr << "Error :: retrieve_lane_geometry_polyline." << endl;

										initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

										return true;
									}

									if (list_LaneGroups[a - 1].laneGroupHereTileID != list_LaneGroups[a].laneGroupHereTileID)
									{
										lane_topology_layer_tile1 = lane_topology_layer_tile2;
										lane_geometry_polyline_layer_tile1 = lane_geometry_polyline_layer_tile2;
									}
								}

								if (Route_Planning_data.list_Nodes_HEREtile_ID[linkOnRouteIndex + 1] != topology_layer_tile.here_tile_id())
								{
									if (load_tile_centerline_data(Route_Planning_data.list_Nodes_HEREtile_ID[linkOnRouteIndex + 1], topology_layer_tile, speed_attributes_layer_tile, adas_attributes_layer_tile))
									{
										return true;
									}
								}

								error = retrieve_node_data(topology_layer_tile, Route_Planning_data.list_Nodes_ID[linkOnRouteIndex + 1], nodeIndex);
								if (error) return true;

								if (linkOnRouteIndex == Route_Planning_data.LIST_LINKS_SIZE - 1)
								{
									retrieve_route_final_node_adas_attributes(linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
								}
								else
								{
									error = retrieve_node_adas_attributes(adas_attributes_layer_tile, nodeIndex, Route_Planning_data.list_Links_ID[linkOnRouteIndex], Route_Planning_data.list_Links_ID[linkOnRouteIndex + 1], linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
									if (error)
									{
										cerr << "Error :: retrieve_node_adas_attributes." << endl;

										initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

										return true;
									}
								}

								linkLengthSum += linkLength;
								linkOnRouteIndex++;
							}

							histoLastPlusOneLinkOnRouteIndex = linkOnRouteIndex;

							if (indexSpeed < SPEED_ARRAY_SIZE) electronic_Horizon_data.PathsArray[0].NbrSegment.data = indexSpeed + 1;
							else
							{
								electronic_Horizon_data.PathsArray[0].NbrSegment.data = SPEED_ARRAY_SIZE;
								electronic_Horizon_data.PathsArray[0].ehSegment[SPEED_ARRAY_SIZE - 1].effectiveSpeedLimit.data = UNDEFINED_SPEED_LIMIT;
							}

							electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data = indexCurv;

							electronic_Horizon_data.PathsArray[0].QtyLineCoordGeo.data = 0;
							for (int h(0); h < QTYLINE_ARRAY_SIZE; h++)
							{
								electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[h].NbrSpotCoordGeo.data = qtyLineGeo[h];
								if (qtyLineGeo[h] != 0) electronic_Horizon_data.PathsArray[0].QtyLineCoordGeo.data++;
							}

							if (qtyNbrLine < NBRLINE_ARRAY_SIZE) electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data = qtyNbrLine + 1;
							else electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data = qtyNbrLine;
						}
					}
				}
				else if (histoFirstLinkOnRouteIndex == linkOnRouteIndex)
				{
					if (linkLengthSum > EHorizonExtend && ((float)linkLengthSum - Map_Matching_data.Distance_Curviligne_Ego.data) < EHorizonExtend)
					{
						linkOnRouteIndex = histoLastPlusOneLinkOnRouteIndex;

						if (linkOnRouteIndex < Route_Planning_data.LIST_LINKS_SIZE)
						{
							bool error;
							::google::protobuf::uint32 linkLength(0);
							int linkIndex, nodeIndex;
							bool same_link_vs_route_direction, same_laneGroup_vs_route_direction;
							::google::protobuf::uint32 laneGroupLength(0);

							while (linkOnRouteIndex < Route_Planning_data.LIST_LINKS_SIZE && (((float)linkLengthSum - Map_Matching_data.Distance_Curviligne_Ego.data) < EHorizonExtend))
							{
								if (Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex] != topology_layer_tile.here_tile_id())
								{
									if (load_tile_centerline_data(Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex], topology_layer_tile, speed_attributes_layer_tile, adas_attributes_layer_tile))
									{
										return true;
									}
								}

								error = retrieve_link_data(topology_layer_tile, Route_Planning_data.list_Links_ID[linkOnRouteIndex], linkIndex, Route_Planning_data.list_Nodes_ID[linkOnRouteIndex], Route_Planning_data.list_Nodes_ID[linkOnRouteIndex + 1], same_link_vs_route_direction);
								if (error)
								{
									cerr << "Error :: retrieve_link_data." << endl;

									initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

									return true;
								}

								linkLength = topology_layer_tile.links_starting_in_tile(linkIndex).link_length_meters();
								histoLinkLength.push_back(linkLength);

								histo_same_link_vs_route_direction.push_back(same_link_vs_route_direction);

								error = retrieve_speed_attributes(speed_attributes_layer_tile, linkIndex, same_link_vs_route_direction, linkLength, linkLengthSum, electronic_Horizon_data, indexSpeed, SPEED_ARRAY_SIZE);
								if (error)
								{
									cerr << "Error :: retrieve_speed_attributes." << endl;

									initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

									return true;
								}

								error = retrieve_link_adas_attributes(adas_attributes_layer_tile, linkIndex, same_link_vs_route_direction, linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
								if (error)
								{
									cerr << "Error :: retrieve_link_adas_attributes." << endl;

									initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

									return true;
								}

								if (Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex] != lane_road_reference_layer_tile.here_tile_id())
								{
									if (load_tile_LaneRoadRef_data(Route_Planning_data.list_Links_HEREtile_ID[linkOnRouteIndex], lane_road_reference_layer_tile))
									{
										return true;
									}
								}

								error = retrieve_lane_road_reference(lane_road_reference_layer_tile, Route_Planning_data.list_Links_ID, Route_Planning_data.LIST_LINKS_SIZE, linkOnRouteIndex, same_link_vs_route_direction, list_LaneGroups);
								if (error)
								{
									cerr << "Error :: retrieve_lane_road_reference." << endl;

									initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

									return true;
								}

								for (int a(1); a < list_LaneGroups.size(); a++)
								{
									if (list_LaneGroups[a].laneGroupHereTileID != lane_topology_layer_tile2.here_tile_id())
									{
										if (load_tile_lane_data(list_LaneGroups[a].laneGroupHereTileID, lane_topology_layer_tile2, lane_geometry_polyline_layer_tile2))
										{
											return true;
										}
									}

									if (list_LaneGroups[a - 1].laneGroupHereTileID != lane_topology_layer_tile1.here_tile_id())
									{
										if (load_tile_lane_data(list_LaneGroups[a - 1].laneGroupHereTileID, lane_topology_layer_tile1, lane_geometry_polyline_layer_tile1))
										{
											return true;
										}
									}

									error = retrieve_lane_data(lane_topology_layer_tile1, lane_topology_layer_tile2, list_LaneGroups, a, false, same_laneGroup_vs_route_direction, laneGroupLength);
									if (error)
									{
										cerr << "Error :: retrieve_lane_data." << endl;

										initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

										return true;
									}

									error = retrieve_lane_geometry_polyline(lane_geometry_polyline_layer_tile2, list_LaneGroups[a], same_laneGroup_vs_route_direction, laneGroupLength, laneGroupLengthSum, electronic_Horizon_data, qtyLineGeo, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, qtyNbrLine, NBRLINE_ARRAY_SIZE);
									if (error)
									{
										cerr << "Error :: retrieve_lane_geometry_polyline." << endl;

										initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

										return true;
									}

									if (list_LaneGroups[a - 1].laneGroupHereTileID != list_LaneGroups[a].laneGroupHereTileID)
									{
										lane_topology_layer_tile1 = lane_topology_layer_tile2;
										lane_geometry_polyline_layer_tile1 = lane_geometry_polyline_layer_tile2;
									}
								}

								if (Route_Planning_data.list_Nodes_HEREtile_ID[linkOnRouteIndex + 1] != topology_layer_tile.here_tile_id())
								{
									if (load_tile_centerline_data(Route_Planning_data.list_Nodes_HEREtile_ID[linkOnRouteIndex + 1], topology_layer_tile, speed_attributes_layer_tile, adas_attributes_layer_tile))
									{
										return true;
									}
								}

								error = retrieve_node_data(topology_layer_tile, Route_Planning_data.list_Nodes_ID[linkOnRouteIndex + 1], nodeIndex);
								if (error) return true;

								if (linkOnRouteIndex == Route_Planning_data.LIST_LINKS_SIZE - 1)
								{
									retrieve_route_final_node_adas_attributes(linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
								}
								else
								{
									error = retrieve_node_adas_attributes(adas_attributes_layer_tile, nodeIndex, Route_Planning_data.list_Links_ID[linkOnRouteIndex], Route_Planning_data.list_Links_ID[linkOnRouteIndex + 1], linkLength, linkLengthSum, electronic_Horizon_data, indexCurv, CURV_ARRAY_SIZE);
									if (error)
									{
										cerr << "Error :: retrieve_node_adas_attributes." << endl;

										initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

										return true;
									}
								}

								linkLengthSum += linkLength;
								linkOnRouteIndex++;
							}

							histoLastPlusOneLinkOnRouteIndex = linkOnRouteIndex;

							if (indexSpeed < SPEED_ARRAY_SIZE) electronic_Horizon_data.PathsArray[0].NbrSegment.data = indexSpeed + 1;
							else
							{
								electronic_Horizon_data.PathsArray[0].NbrSegment.data = SPEED_ARRAY_SIZE;
								electronic_Horizon_data.PathsArray[0].ehSegment[SPEED_ARRAY_SIZE - 1].effectiveSpeedLimit.data = UNDEFINED_SPEED_LIMIT;
							}

							electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data = indexCurv;

							electronic_Horizon_data.PathsArray[0].QtyLineCoordGeo.data = 0;
							for (int h(0); h < QTYLINE_ARRAY_SIZE; h++)
							{
								electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[h].NbrSpotCoordGeo.data = qtyLineGeo[h];
								if (qtyLineGeo[h] != 0) electronic_Horizon_data.PathsArray[0].QtyLineCoordGeo.data++;
							}

							if (qtyNbrLine < NBRLINE_ARRAY_SIZE) electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data = qtyNbrLine + 1;
							else electronic_Horizon_data.PathsArray[0].QtyNbrLineCoordGeo.data = qtyNbrLine;
						}
					}
				}
				else
				{
					cerr << "Ego is going backward on the route" << endl;

					initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

					return true;
				}
			}

			electronic_Horizon_data.PathsArray[0].ehPosition.offset.data = Map_Matching_data.Distance_Curviligne_Ego.data;
			electronic_Horizon_data.PathsArray[0].ehPosition.latitude = Map_Matching_data.latitude;
			electronic_Horizon_data.PathsArray[0].ehPosition.longitude = Map_Matching_data.longitude;
			electronic_Horizon_data.PathsArray[0].ehPosition.cap = Map_Matching_data.cap;

			return false;
		}
		else
		{
			cerr << "Ego's link not on the route" << endl;

			initEH(electronic_Horizon_data, CURV_ARRAY_SIZE, SPEED_ARRAY_SIZE, QTYLINE_ARRAY_SIZE, LINEGEO_ARRAY_SIZE, NBRLINE_ARRAY_SIZE, histoFirstLinkOnRouteIndex, histoLastPlusOneLinkOnRouteIndex, histoLinkLength, histo_same_link_vs_route_direction, linkLengthSum, laneGroupLengthSum, indexCurv, indexSpeed, qtyLineGeo, qtyNbrLine, list_LaneGroups);

			return true;
		}
	}
	else	// DEMO MODE
	{
		electronic_Horizon_data.PathsArray[0].ehPosition.offset = Map_Matching_data.Distance_Curviligne_Ego;
		electronic_Horizon_data.PathsArray[0].ehPosition.latitude = Map_Matching_data.latitude;
		electronic_Horizon_data.PathsArray[0].ehPosition.longitude = Map_Matching_data.longitude;
		electronic_Horizon_data.PathsArray[0].ehPosition.cap = Map_Matching_data.cap;

		for (int i = 0; i < Route_Planning_data.Tableau_circuit_speedlimit.size() && i < SPEED_ARRAY_SIZE; i++)
		{
			electronic_Horizon_data.PathsArray[0].ehSegment[i].offset.data = Route_Planning_data.Tableau_circuit_speedlimit[i].offset;

			electronic_Horizon_data.PathsArray[0].ehSegment[i].effectiveSpeedLimit.data = Route_Planning_data.Tableau_circuit_speedlimit[i].effectiveSpeedLimit;
		}

		if (Route_Planning_data.Tableau_circuit_speedlimit.size() < SPEED_ARRAY_SIZE)
		{
			electronic_Horizon_data.PathsArray[0].NbrSegment.data = Route_Planning_data.Tableau_circuit_speedlimit.size();
		}
		else
		{
			electronic_Horizon_data.PathsArray[0].NbrSegment.data = SPEED_ARRAY_SIZE;
		}


		for (int i = 0; i < Route_Planning_data.Tableau_circuit_curvature.size() && i < CURV_ARRAY_SIZE; i++)
		{
			electronic_Horizon_data.PathsArray[0].ehSpotCurvature[i].offset.data = Route_Planning_data.Tableau_circuit_curvature[i].offset;

			electronic_Horizon_data.PathsArray[0].ehSpotCurvature[i].Value_0.data = Route_Planning_data.Tableau_circuit_curvature[i].value;
		}

		if (Route_Planning_data.Tableau_circuit_curvature.size() < CURV_ARRAY_SIZE)
		{
			electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data = Route_Planning_data.Tableau_circuit_curvature.size();
		}
		else
		{
			electronic_Horizon_data.PathsArray[0].NbrSpotCurvature.data = CURV_ARRAY_SIZE;
		}


		for (int i = 0; i < Route_Planning_data.Tableau_circuit_GPS_droite.size() && i < LINEGEO_ARRAY_SIZE; i++)
		{
			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[0].ehSpotCoordGeo[i].latitude = Route_Planning_data.Tableau_circuit_GPS_droite[i].latitude;

			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[0].ehSpotCoordGeo[i].longitude = Route_Planning_data.Tableau_circuit_GPS_droite[i].longitude;

			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[0].ehSpotCoordGeo[i].offset.data = Route_Planning_data.Tableau_circuit_GPS_droite[i].offset;
		}

		if (Route_Planning_data.Tableau_circuit_GPS_droite.size() < LINEGEO_ARRAY_SIZE)
		{
			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[0].NbrSpotCoordGeo.data = Route_Planning_data.Tableau_circuit_GPS_droite.size();
		}
		else
		{
			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[0].NbrSpotCoordGeo.data = LINEGEO_ARRAY_SIZE;
		}


		for (int i = 0; i < Route_Planning_data.Tableau_circuit_GPS_gauche.size() && i < LINEGEO_ARRAY_SIZE; i++)
		{
			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[1].ehSpotCoordGeo[i].latitude = Route_Planning_data.Tableau_circuit_GPS_gauche[i].latitude;

			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[1].ehSpotCoordGeo[i].longitude = Route_Planning_data.Tableau_circuit_GPS_gauche[i].longitude;

			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[1].ehSpotCoordGeo[i].offset.data = Route_Planning_data.Tableau_circuit_GPS_gauche[i].offset;
		}

		if (Route_Planning_data.Tableau_circuit_GPS_gauche.size() < LINEGEO_ARRAY_SIZE)
		{
			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[1].NbrSpotCoordGeo.data = Route_Planning_data.Tableau_circuit_GPS_gauche.size();
		}
		else
		{
			electronic_Horizon_data.PathsArray[0].ehLineCoordGeo[1].NbrSpotCoordGeo.data = LINEGEO_ARRAY_SIZE;
		}


		electronic_Horizon_data.PathsArray[0].QtyLineCoordGeo.data = 2;


		for (int i = 0; i < Route_Planning_data.Tableau_circuit_trafficsign.size() && i < SIGN_ARRAY_SIZE; i++)
		{
			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[i].offset.data = Route_Planning_data.Tableau_circuit_trafficsign[i].offset;

			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[i].Sign_Type = Route_Planning_data.Tableau_circuit_trafficsign[i].Sign_Type;

			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[i].Value = Route_Planning_data.Tableau_circuit_trafficsign[i].Value;

			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[i].Lane = Route_Planning_data.Tableau_circuit_trafficsign[i].Lane;

			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[i].Sign_Location = Route_Planning_data.Tableau_circuit_trafficsign[i].Sign_Location;

			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[i].latitude =  Route_Planning_data.Tableau_circuit_trafficsign[i].latitude;

			electronic_Horizon_data.PathsArray[0].ehSpotTrafficSign[i].longitude =  Route_Planning_data.Tableau_circuit_trafficsign[i].longitude;
		}

		if (Route_Planning_data.Tableau_circuit_trafficsign.size() < SIGN_ARRAY_SIZE)
		{
			electronic_Horizon_data.PathsArray[0].NbrSpotTrafficSign.data = Route_Planning_data.Tableau_circuit_trafficsign.size();
		}
		else
		{
			electronic_Horizon_data.PathsArray[0].NbrSpotTrafficSign.data = SIGN_ARRAY_SIZE;
		}


		return false;
	}
}

//-------------------------------------------------------------------------------------------------
// Inputs
//-------------------------------------------------------------------------------------------------
project_s_msgs::MapMatching Map_Matching_data;
project_s_msgs::RoutePlanning Route_Planning_data;

//-------------------------------------------------------------------------------------------------
// Outputs
//-------------------------------------------------------------------------------------------------
project_s_msgs::ElectronicHorizonArray electronic_Horizon_data;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedMapMatching = false;
void mapmatchingCallback(const project_s_msgs::MapMatching::ConstPtr& msg)
{
	Map_Matching_data = *msg;

	receivedMapMatching = true;
}

bool receivedRoutePlanning = false;
void routePlanningCallback(const project_s_msgs::RoutePlanning::ConstPtr& msg)
{
	Route_Planning_data = *msg;

	receivedRoutePlanning = true;
}

//-------------------------------------------------------------------------------------------------
// Main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	ros::init(argc, argv, std::string("electronic_horizon_array"));

	ros::NodeHandle n;

	ros::Subscriber sub_map_matching_data = n.subscribe(std::string("/map_matching_data"), 1, mapmatchingCallback);
	
	ros::Subscriber subRoutePlanning = n.subscribe(std::string("/route_planning_data"), 1, routePlanningCallback);

	ros::Publisher pub_electronic_horizon_array_data = n.advertise<project_s_msgs::ElectronicHorizonArray>(std::string("/electronic_horizon_array_data"), 1);

	ros::Rate loop_rate(10);

	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
	while(!receivedRoutePlanning)
	{
		ros::spinOnce();
		
		loop_rate.sleep();
	}

	while (n.ok())
	{
		ros::spinOnce();
		
		if(receivedMapMatching)
		{
			receivedMapMatching = false;

			bool error;
			
			error = electronic_horizon(electronic_Horizon_data, Map_Matching_data, Route_Planning_data);		

			if (error) cerr << "\nError: electronic_horizon\n";
			else
			{
				pub_electronic_horizon_array_data.publish(electronic_Horizon_data);

				cout << "\nelectronic_horizon ok\n";
			}
		}

		loop_rate.sleep();
	}

	return 0;
}
