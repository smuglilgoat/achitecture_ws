#include "Route_Planning.h"
#include "RouteParam.h"

#include "ros/ros.h"
#include "std_msgs/UInt8.h"

using namespace std;

#define TRACKS_NB 20
#define FIRST_TRACK 11



/*
bool load_tile_centerline_data(::google::protobuf::uint32 LinkTileID,
								::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile &topologyData)
{
	string topologyLayerFile = "../data/HEREtile_" + to_string(LinkTileID) + "/" + to_string(LinkTileID) + "_hdmap-topology-geometry-bundle_topology-geometry";

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

	return false;
}


bool retrieve_link_geometry_data(project_s_msgs::RoutePlanning &route_planning_data)
{
	::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile topology_layer_tile;

	unsigned int linkOnRouteIndex(0);

	if(load_tile_centerline_data(route_planning_data.list_Links_HEREtile_ID[linkOnRouteIndex], topology_layer_tile)) return true;

	unsigned int index = 0;
	while ((index < topology_layer_tile.links_starting_in_tile_size()) && (topology_layer_tile.links_starting_in_tile(index).link_id() != route_planning_data.list_Links_ID[linkOnRouteIndex]))
	{
		index++;
	}

	if (index < topology_layer_tile.links_starting_in_tile_size())
	{
		unsigned int link_geometry_size = topology_layer_tile.links_starting_in_tile(index).geometry().here_2d_coordinate_diffs_size();

		route_planning_data.Tableau_circuit_GPS.resize(link_geometry_size);

		::google::protobuf::int64 coord = topology_layer_tile.tile_center_here_2d_coordinate();
		GpsCoord gps;

		for (unsigned int i(0); i < link_geometry_size; i++)
		{
			coord ^= topology_layer_tile.links_starting_in_tile(index).geometry().here_2d_coordinate_diffs(i);
			gps = twoDToLatLon(coord);

			route_planning_data.Tableau_circuit_GPS[i].latitude = gps.lat;
			route_planning_data.Tableau_circuit_GPS[i].longitude = gps.lon;
		}

		if (!route_planning_data.list_Links_vs_Route_direction[linkOnRouteIndex])
		{
			GpsCoord temp_gps;
			for (unsigned int i(0); i < link_geometry_size / 2; i++)
			{
				temp_gps.lat = route_planning_data.Tableau_circuit_GPS[i].latitude;
				temp_gps.lon = route_planning_data.Tableau_circuit_GPS[i].longitude;

				route_planning_data.Tableau_circuit_GPS[i].latitude = route_planning_data.Tableau_circuit_GPS[link_geometry_size - 1 - i].latitude;
				route_planning_data.Tableau_circuit_GPS[i].longitude = route_planning_data.Tableau_circuit_GPS[link_geometry_size - 1 - i].longitude;

				route_planning_data.Tableau_circuit_GPS[link_geometry_size - 1 - i].latitude = temp_gps.lat;
				route_planning_data.Tableau_circuit_GPS[link_geometry_size - 1 - i].longitude = temp_gps.lon;
			}
		}
	}
	else
	{
		cerr << "Topology Layer's tile binary file contains error." << endl;
		return true;
	}

	for (linkOnRouteIndex = 1; linkOnRouteIndex < route_planning_data.LIST_LINKS_SIZE; linkOnRouteIndex++)
	{
		if (route_planning_data.list_Links_HEREtile_ID[linkOnRouteIndex] != topology_layer_tile.here_tile_id())
		{
			if (load_tile_centerline_data(route_planning_data.list_Links_HEREtile_ID[linkOnRouteIndex], topology_layer_tile))
			{
				return true;
			}
		}

		index = 0;
		while ((index < topology_layer_tile.links_starting_in_tile_size()) && (topology_layer_tile.links_starting_in_tile(index).link_id() != route_planning_data.list_Links_ID[linkOnRouteIndex]))
		{
			index++;
		}

		if (index < topology_layer_tile.links_starting_in_tile_size())
		{
			unsigned int link_geometry_size = topology_layer_tile.links_starting_in_tile(index).geometry().here_2d_coordinate_diffs_size();

			unsigned int link_previous_geometry_size = route_planning_data.Tableau_circuit_GPS.size();

			route_planning_data.Tableau_circuit_GPS.resize(link_previous_geometry_size + link_geometry_size);

			::google::protobuf::int64 coord = topology_layer_tile.tile_center_here_2d_coordinate();
			GpsCoord gps;

			for (unsigned int i(0); i < link_geometry_size; i++)
			{
				coord ^= topology_layer_tile.links_starting_in_tile(index).geometry().here_2d_coordinate_diffs(i);
				gps = twoDToLatLon(coord);

				route_planning_data.Tableau_circuit_GPS[link_previous_geometry_size + i].latitude = gps.lat;
				route_planning_data.Tableau_circuit_GPS[link_previous_geometry_size + i].longitude = gps.lon;
			}

			if (!route_planning_data.list_Links_vs_Route_direction[linkOnRouteIndex])
			{
				GpsCoord temp_gps;
				for (unsigned int i(0); i < link_geometry_size / 2; i++)
				{
					temp_gps.lat = route_planning_data.Tableau_circuit_GPS[link_previous_geometry_size + i].latitude;
					temp_gps.lon = route_planning_data.Tableau_circuit_GPS[link_previous_geometry_size + i].longitude;

					route_planning_data.Tableau_circuit_GPS[link_previous_geometry_size + i].latitude = route_planning_data.Tableau_circuit_GPS[link_previous_geometry_size + link_geometry_size - 1 - i].latitude;
					route_planning_data.Tableau_circuit_GPS[link_previous_geometry_size + i].longitude = route_planning_data.Tableau_circuit_GPS[link_previous_geometry_size + link_geometry_size - 1 - i].longitude;

					route_planning_data.Tableau_circuit_GPS[link_previous_geometry_size + link_geometry_size - 1 - i].latitude = temp_gps.lat;
					route_planning_data.Tableau_circuit_GPS[link_previous_geometry_size + link_geometry_size - 1 - i].longitude = temp_gps.lon;
				}
			}
		}
		else
		{
			cerr << "Topology Layer's tile binary file contains error." << endl;
			return true;
		}
	}

	route_planning_data.NBRE_POINT_TABLEAU_GPS = route_planning_data.Tableau_circuit_GPS.size();

	return false;
}
*/

bool route_planning(project_s_msgs::RoutePlanning &Route_Planning_data, std_msgs::UInt8 Circuit_Choice_data)
{
	unsigned char choice = Circuit_Choice_data.data;
	
	switch (choice)
	{
	case 1:

		Route_Planning_data.list_Links_ID.resize(LIST1_LINKS_SIZE);
		Route_Planning_data.list_Links_HEREtile_ID.resize(LIST1_LINKS_SIZE);
		Route_Planning_data.list_Nodes_ID.resize(LIST1_LINKS_SIZE + 1);
		Route_Planning_data.list_Nodes_HEREtile_ID.resize(LIST1_LINKS_SIZE + 1);
		Route_Planning_data.list_Links_vs_Route_direction.resize(LIST1_LINKS_SIZE);

		for (int i = 0; i < LIST1_LINKS_SIZE; i++)
		{
			Route_Planning_data.list_Links_ID[i] = list1_Links_ID[i];
			Route_Planning_data.list_Links_HEREtile_ID[i] = list1_Links_HEREtile_ID[i];
			Route_Planning_data.list_Nodes_ID[i] = list1_Nodes_ID[i];
			Route_Planning_data.list_Nodes_HEREtile_ID[i] = list1_Nodes_HEREtile_ID[i];
			Route_Planning_data.list_Links_vs_Route_direction[i] = list1_Links_vs_Route_direction[i];
		}
		Route_Planning_data.list_Nodes_ID[LIST1_LINKS_SIZE] = list1_Nodes_ID[LIST1_LINKS_SIZE];
		Route_Planning_data.list_Nodes_HEREtile_ID[LIST1_LINKS_SIZE] = list1_Nodes_HEREtile_ID[LIST1_LINKS_SIZE];

		Route_Planning_data.LIST_LINKS_SIZE = LIST1_LINKS_SIZE;
		
/*		if (retrieve_link_geometry_data(Route_Planning_data))
		{
			cerr << "Geometry retrieve error." << endl;
			return true;
		}*/

		break;
	case 2:

		Route_Planning_data.list_Links_ID.resize(LIST2_LINKS_SIZE);
		Route_Planning_data.list_Links_HEREtile_ID.resize(LIST2_LINKS_SIZE);
		Route_Planning_data.list_Nodes_ID.resize(LIST2_LINKS_SIZE + 1);
		Route_Planning_data.list_Nodes_HEREtile_ID.resize(LIST2_LINKS_SIZE + 1);
		Route_Planning_data.list_Links_vs_Route_direction.resize(LIST2_LINKS_SIZE);

		for (int i = 0; i < LIST2_LINKS_SIZE; i++)
		{
			Route_Planning_data.list_Links_ID[i] = list2_Links_ID[i];
			Route_Planning_data.list_Links_HEREtile_ID[i] = list2_Links_HEREtile_ID[i];
			Route_Planning_data.list_Nodes_ID[i] = list2_Nodes_ID[i];
			Route_Planning_data.list_Nodes_HEREtile_ID[i] = list2_Nodes_HEREtile_ID[i];
			Route_Planning_data.list_Links_vs_Route_direction[i] = list2_Links_vs_Route_direction[i];
		}
		Route_Planning_data.list_Nodes_ID[LIST2_LINKS_SIZE] = list2_Nodes_ID[LIST2_LINKS_SIZE];
		Route_Planning_data.list_Nodes_HEREtile_ID[LIST2_LINKS_SIZE] = list2_Nodes_HEREtile_ID[LIST2_LINKS_SIZE];

		Route_Planning_data.LIST_LINKS_SIZE = LIST2_LINKS_SIZE;

/*		if (retrieve_link_geometry_data(Route_Planning_data))
		{
			cerr << "Geometry retrieve error." << endl;
			return true;
		}*/

		break;
	case 3:

		Route_Planning_data.list_Links_ID.resize(LIST4_LINKS_SIZE);
		Route_Planning_data.list_Links_HEREtile_ID.resize(LIST4_LINKS_SIZE);
		Route_Planning_data.list_Nodes_ID.resize(LIST4_LINKS_SIZE + 1);
		Route_Planning_data.list_Nodes_HEREtile_ID.resize(LIST4_LINKS_SIZE + 1);
		Route_Planning_data.list_Links_vs_Route_direction.resize(LIST4_LINKS_SIZE);

		for (int i = 0; i < LIST4_LINKS_SIZE; i++)
		{
			Route_Planning_data.list_Links_ID[i] = list4_Links_ID[i];
			Route_Planning_data.list_Links_HEREtile_ID[i] = list4_Links_HEREtile_ID[i];
			Route_Planning_data.list_Nodes_ID[i] = list4_Nodes_ID[i];
			Route_Planning_data.list_Nodes_HEREtile_ID[i] = list4_Nodes_HEREtile_ID[i];
			Route_Planning_data.list_Links_vs_Route_direction[i] = list4_Links_vs_Route_direction[i];
		}
		Route_Planning_data.list_Nodes_ID[LIST4_LINKS_SIZE] = list4_Nodes_ID[LIST4_LINKS_SIZE];
		Route_Planning_data.list_Nodes_HEREtile_ID[LIST4_LINKS_SIZE] = list4_Nodes_HEREtile_ID[LIST4_LINKS_SIZE];

		Route_Planning_data.LIST_LINKS_SIZE = LIST4_LINKS_SIZE;

/*		if (retrieve_link_geometry_data(Route_Planning_data))
		{
			cerr << "Geometry retrieve error." << endl;
			return true;
		}*/

		break;
	case 4:

		Route_Planning_data.list_Links_ID.resize(LIST5_LINKS_SIZE);
		Route_Planning_data.list_Links_HEREtile_ID.resize(LIST5_LINKS_SIZE);
		Route_Planning_data.list_Nodes_ID.resize(LIST5_LINKS_SIZE + 1);
		Route_Planning_data.list_Nodes_HEREtile_ID.resize(LIST5_LINKS_SIZE + 1);
		Route_Planning_data.list_Links_vs_Route_direction.resize(LIST5_LINKS_SIZE);

		for (int i = 0; i < LIST5_LINKS_SIZE; i++)
		{
			Route_Planning_data.list_Links_ID[i] = list5_Links_ID[i];
			Route_Planning_data.list_Links_HEREtile_ID[i] = list5_Links_HEREtile_ID[i];
			Route_Planning_data.list_Nodes_ID[i] = list5_Nodes_ID[i];
			Route_Planning_data.list_Nodes_HEREtile_ID[i] = list5_Nodes_HEREtile_ID[i];
			Route_Planning_data.list_Links_vs_Route_direction[i] = list5_Links_vs_Route_direction[i];
		}
		Route_Planning_data.list_Nodes_ID[LIST5_LINKS_SIZE] = list5_Nodes_ID[LIST5_LINKS_SIZE];
		Route_Planning_data.list_Nodes_HEREtile_ID[LIST5_LINKS_SIZE] = list5_Nodes_HEREtile_ID[LIST5_LINKS_SIZE];

		Route_Planning_data.LIST_LINKS_SIZE = LIST5_LINKS_SIZE;

/*		if (retrieve_link_geometry_data(Route_Planning_data))
		{
			cerr << "Geometry retrieve error." << endl;
			return true;
		}*/

		break;
	case 5:

		Route_Planning_data.list_Links_ID.resize(LIST7_LINKS_SIZE);
		Route_Planning_data.list_Links_HEREtile_ID.resize(LIST7_LINKS_SIZE);
		Route_Planning_data.list_Nodes_ID.resize(LIST7_LINKS_SIZE + 1);
		Route_Planning_data.list_Nodes_HEREtile_ID.resize(LIST7_LINKS_SIZE + 1);
		Route_Planning_data.list_Links_vs_Route_direction.resize(LIST7_LINKS_SIZE);

		for (int i = 0; i < LIST7_LINKS_SIZE; i++)
		{
			Route_Planning_data.list_Links_ID[i] = list7_Links_ID[i];
			Route_Planning_data.list_Links_HEREtile_ID[i] = list7_Links_HEREtile_ID[i];
			Route_Planning_data.list_Nodes_ID[i] = list7_Nodes_ID[i];
			Route_Planning_data.list_Nodes_HEREtile_ID[i] = list7_Nodes_HEREtile_ID[i];
			Route_Planning_data.list_Links_vs_Route_direction[i] = list7_Links_vs_Route_direction[i];
		}
		Route_Planning_data.list_Nodes_ID[LIST7_LINKS_SIZE] = list7_Nodes_ID[LIST7_LINKS_SIZE];
		Route_Planning_data.list_Nodes_HEREtile_ID[LIST7_LINKS_SIZE] = list7_Nodes_HEREtile_ID[LIST7_LINKS_SIZE];

		Route_Planning_data.LIST_LINKS_SIZE = LIST7_LINKS_SIZE;

/*		if (retrieve_link_geometry_data(Route_Planning_data))
		{
			cerr << "Geometry retrieve error." << endl;
			return true;
		}*/

		break;
	case 6:

		Route_Planning_data.list_Links_ID.resize(LISTS_LINKS_SIZE);
		Route_Planning_data.list_Links_HEREtile_ID.resize(LISTS_LINKS_SIZE);
		Route_Planning_data.list_Nodes_ID.resize(LISTS_LINKS_SIZE + 1);
		Route_Planning_data.list_Nodes_HEREtile_ID.resize(LISTS_LINKS_SIZE + 1);
		Route_Planning_data.list_Links_vs_Route_direction.resize(LISTS_LINKS_SIZE);

		for (int i = 0; i < LISTS_LINKS_SIZE; i++)
		{
			Route_Planning_data.list_Links_ID[i] = listS_Links_ID[i];
			Route_Planning_data.list_Links_HEREtile_ID[i] = listS_Links_HEREtile_ID[i];
			Route_Planning_data.list_Nodes_ID[i] = listS_Nodes_ID[i];
			Route_Planning_data.list_Nodes_HEREtile_ID[i] = listS_Nodes_HEREtile_ID[i];
			Route_Planning_data.list_Links_vs_Route_direction[i] = listS_Links_vs_Route_direction[i];
		}
		Route_Planning_data.list_Nodes_ID[LISTS_LINKS_SIZE] = listS_Nodes_ID[LISTS_LINKS_SIZE];
		Route_Planning_data.list_Nodes_HEREtile_ID[LISTS_LINKS_SIZE] = listS_Nodes_HEREtile_ID[LISTS_LINKS_SIZE];

		Route_Planning_data.LIST_LINKS_SIZE = LISTS_LINKS_SIZE;

/*		if (retrieve_link_geometry_data(Route_Planning_data))
		{
			cerr << "Geometry retrieve error." << endl;
			return true;
		}*/

		break;
	case 7:

		break;
	case 8:

		break;
	case 9:

		break;
	case 10:

		break;
	default:
		
		if((choice >= FIRST_TRACK) && (choice < (FIRST_TRACK + TRACKS_NB)))
		{
			Route_Planning_data.LIST_LINKS_SIZE = 100;
			
			
			/************************************
			///// To delete, just for test!
			*************************************/
			
			/*
			if(choice == 14) choice = 12;
			else if (choice == 23) choice = 13;
			else if (choice == 15) choice = 14;
			*/
			
			/************************************
			*************************************/
			
			int tracksId = choice - FIRST_TRACK;
			
			int Size_Tableau_circuit_GPS = tracks_tab[tracksId].centreNb;
			int Size_Tableau_circuit_GPS_gauche = tracks_tab[tracksId].gaucheNb;
			int Size_Tableau_circuit_GPS_droite = tracks_tab[tracksId].droiteNb;	// Size_Tableau_circuit_GPS_droite == Size_Tableau_circuit_GPS_gauche
			int Size_Tableau_circuit_GPS_MEgauche = tracks_tab[tracksId].MEgaucheNb;
			int Size_Tableau_circuit_GPS_MEdroite = tracks_tab[tracksId].MEdroiteNb;
			int Size_speedlimit = tracks_tab[tracksId].speedlimitNb;
			int Size_curvature = tracks_tab[tracksId].curvatureNb;
			int Size_trafficsign = tracks_tab[tracksId].trafficsignNb;

			int Size_ehSegmentAO = ehSegmentAOEO_tab[tracksId].AO_Nb;
			int Size_ehSegmentEO = ehSegmentAOEO_tab[tracksId].EO_Nb;

			Route_Planning_data.NBRE_POINT_TABLEAU_GPS = Size_Tableau_circuit_GPS;
			Route_Planning_data.NBRE_POINT_CIRCUIT_GPS = Size_Tableau_circuit_GPS_gauche;
			Route_Planning_data.Tableau_circuit_GPS.resize(Size_Tableau_circuit_GPS);
			Route_Planning_data.Tableau_circuit_GPS_gauche.resize(Size_Tableau_circuit_GPS_gauche);
			Route_Planning_data.Tableau_circuit_GPS_droite.resize(Size_Tableau_circuit_GPS_droite);
			Route_Planning_data.Tableau_circuit_GPS_MEgauche.resize(Size_Tableau_circuit_GPS_MEgauche);
			Route_Planning_data.Tableau_circuit_GPS_MEdroite.resize(Size_Tableau_circuit_GPS_MEdroite);
			Route_Planning_data.Tableau_circuit_speedlimit.resize(Size_speedlimit);
			Route_Planning_data.Tableau_circuit_curvature.resize(Size_curvature);
			Route_Planning_data.Tableau_circuit_trafficsign.resize(Size_trafficsign);

			Route_Planning_data.Tableau_circuit_ehSegmentAO.resize(Size_ehSegmentAO);
			Route_Planning_data.Tableau_circuit_ehSegmentEO.resize(Size_ehSegmentEO);


			for (int i = 0; i < Size_Tableau_circuit_GPS; i++)
			{
				Route_Planning_data.Tableau_circuit_GPS[i].latitude = tracks_tab[tracksId].centre_tab[i].latitude;
				Route_Planning_data.Tableau_circuit_GPS[i].longitude = tracks_tab[tracksId].centre_tab[i].longitude;
				Route_Planning_data.Tableau_circuit_GPS[i].offset = tracks_tab[tracksId].centre_tab[i].offset;
			}

			
			for (int i = 0; i < Size_Tableau_circuit_GPS_gauche; i++)
			{
				Route_Planning_data.Tableau_circuit_GPS_gauche[i].latitude = tracks_tab[tracksId].gauche_tab[i].latitude;
				Route_Planning_data.Tableau_circuit_GPS_gauche[i].longitude = tracks_tab[tracksId].gauche_tab[i].longitude;
				Route_Planning_data.Tableau_circuit_GPS_gauche[i].offset = tracks_tab[tracksId].gauche_tab[i].offset;
			}

			
			for (int i = 0; i < Size_Tableau_circuit_GPS_droite; i++)
			{
				Route_Planning_data.Tableau_circuit_GPS_droite[i].latitude = tracks_tab[tracksId].droite_tab[i].latitude;
				Route_Planning_data.Tableau_circuit_GPS_droite[i].longitude = tracks_tab[tracksId].droite_tab[i].longitude;
				Route_Planning_data.Tableau_circuit_GPS_droite[i].offset = tracks_tab[tracksId].droite_tab[i].offset;
			}

			
			for (int i = 0; i < Size_Tableau_circuit_GPS_MEgauche; i++)
			{
				Route_Planning_data.Tableau_circuit_GPS_MEgauche[i].latitude = tracks_tab[tracksId].MEgauche_tab[i].latitude;
				Route_Planning_data.Tableau_circuit_GPS_MEgauche[i].longitude = tracks_tab[tracksId].MEgauche_tab[i].longitude;
				Route_Planning_data.Tableau_circuit_GPS_MEgauche[i].offset = tracks_tab[tracksId].MEgauche_tab[i].offset;
			}

			
			for (int i = 0; i < Size_Tableau_circuit_GPS_MEdroite; i++)
			{
				Route_Planning_data.Tableau_circuit_GPS_MEdroite[i].latitude = tracks_tab[tracksId].MEdroite_tab[i].latitude;
				Route_Planning_data.Tableau_circuit_GPS_MEdroite[i].longitude = tracks_tab[tracksId].MEdroite_tab[i].longitude;
				Route_Planning_data.Tableau_circuit_GPS_MEdroite[i].offset = tracks_tab[tracksId].MEdroite_tab[i].offset;
			}

			for (int i = 0; i < Size_speedlimit; i++)
			{
				Route_Planning_data.Tableau_circuit_speedlimit[i].effectiveSpeedLimit = tracks_tab[tracksId].speed_limit_tab[i].effectiveSpeedLimit;
				Route_Planning_data.Tableau_circuit_speedlimit[i].offset = tracks_tab[tracksId].speed_limit_tab[i].offset;
			}

			for (int i = 0; i < Size_curvature; i++)
			{
				Route_Planning_data.Tableau_circuit_curvature[i].value = tracks_tab[tracksId].curvature_tab[i].value;
				Route_Planning_data.Tableau_circuit_curvature[i].offset = tracks_tab[tracksId].curvature_tab[i].offset;
			}

			for (int i = 0; i < Size_trafficsign; i++)
			{
				Route_Planning_data.Tableau_circuit_trafficsign[i].offset = tracks_tab[tracksId].traffic_sign_tab[i].offset;
				Route_Planning_data.Tableau_circuit_trafficsign[i].Sign_Type = tracks_tab[tracksId].traffic_sign_tab[i].Sign_Type;
				Route_Planning_data.Tableau_circuit_trafficsign[i].Lane = tracks_tab[tracksId].traffic_sign_tab[i].Lane;
				Route_Planning_data.Tableau_circuit_trafficsign[i].Sign_Location = tracks_tab[tracksId].traffic_sign_tab[i].Sign_Location;
				Route_Planning_data.Tableau_circuit_trafficsign[i].Value = tracks_tab[tracksId].traffic_sign_tab[i].Value;
				Route_Planning_data.Tableau_circuit_trafficsign[i].latitude = tracks_tab[tracksId].traffic_sign_tab[i].latitude;
				Route_Planning_data.Tableau_circuit_trafficsign[i].longitude = tracks_tab[tracksId].traffic_sign_tab[i].longitude;
			}



			for (int i = 0; i < Size_ehSegmentAO; i++)
			{
				Route_Planning_data.Tableau_circuit_ehSegmentAO[i].NbrSpot = ehSegmentAOEO_tab[tracksId].AO_tab[i].NbrSpot;
				Route_Planning_data.Tableau_circuit_ehSegmentAO[i].offset_debut = ehSegmentAOEO_tab[tracksId].AO_tab[i].offset_debut;
				Route_Planning_data.Tableau_circuit_ehSegmentAO[i].offset_fin = ehSegmentAOEO_tab[tracksId].AO_tab[i].offset_fin;
			}

			for (int i = 0; i < Size_ehSegmentEO; i++)
			{
				Route_Planning_data.Tableau_circuit_ehSegmentEO[i].NbrSpot = ehSegmentAOEO_tab[tracksId].EO_tab[i].NbrSpot;
				Route_Planning_data.Tableau_circuit_ehSegmentEO[i].offset_debut = ehSegmentAOEO_tab[tracksId].EO_tab[i].offset_debut;
				Route_Planning_data.Tableau_circuit_ehSegmentEO[i].offset_fin = ehSegmentAOEO_tab[tracksId].EO_tab[i].offset_fin;
			}





		}
		else
		{
			cerr << "Itinerary choice error." << endl;
			return true;
		}
	}

	return false;
}

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
std_msgs::UInt8 Circuit_Choice_data;

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::RoutePlanning Route_Planning_data;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedCircuitChoice = false;
void circuitChoiceCallback(const std_msgs::UInt8::ConstPtr& msg)
{
	Circuit_Choice_data = *msg;

	receivedCircuitChoice = true;
}

//-------------------------------------------------------------------------------------------------
// Main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	ros::init(argc, argv, std::string("route_planning"));

	ros::NodeHandle n;

	ros::Publisher pub_route_planning_data = n.advertise<project_s_msgs::RoutePlanning>(std::string("/route_planning_data"), 1);
	
	ros::Subscriber subCircuitChoice = n.subscribe(std::string("/circuit_choice"), 1, circuitChoiceCallback);
	
	ros::Rate loop_rate(1);
	
	bool error;
/*	
	cout << "Please choose a itinerary between 1 and FIRST_TRACK + TRACKS_NB:" << endl;
	cout << "1 - Itinerary 1 + Trappes + Av. Jean d'Alembert" << endl;
	cout << "2 - Itinerary 2 + Trappes + R.-P. Marechal Leclerc" << endl;
	cout << "3 - Itinerary 4 + Elancourt + R. Copenhague - Bd Jean Moulin" << endl;
	cout << "4 - Itinerary 5 + Elancourt + R. Copenhague - Bd Helsinki" << endl;
	cout << "5 - Itinerary 7 + Trappes + Rue de Montfort" << endl;
	cout << "6 - Itinerary Trappes Segula parking lot - HERE" << endl;
	cout << "7 - Itinerary Trappes Segula parking lot - Circuit Oval" << endl;
	cout << "8 - Itinerary Trappes Segula parking lot - Circuit 8" << endl;
	cout << "9 - Itinerary La Ferte Vidame" << endl;
	cout << "10 - Current Itinerary" << endl;
	cout << ">=11 - Other Itineraries" << endl;
*/	
	while (n.ok())
	{
		ros::spinOnce();
		
		if(receivedCircuitChoice)
		{
			receivedCircuitChoice = false;
			
			if (Circuit_Choice_data.data < 1 || Circuit_Choice_data.data >= FIRST_TRACK + TRACKS_NB)
			{
				cerr << "\nError itinerary choice\n";
			}
			else
			{
				error = route_planning(Route_Planning_data, Circuit_Choice_data);

				if (error) cerr << "\nError: route_planning\n";
				else pub_route_planning_data.publish(Route_Planning_data);
			}
		}
		
		loop_rate.sleep();
	}

	return 0;
}
