#include "Map_Matching.h"

#include "ros/ros.h"

#include "project_s_msgs/Configurations.h"

using namespace std;

bool map_matching(const project_s_msgs::EgoDataReport& ego_data_report, project_s_msgs::MapMatching &Map_Matching_data, const project_s_msgs::RoutePlanning& Route_Planning_data, double d_latitude, double d_longitude, float d_Cap)
{
	if (Route_Planning_data.LIST_LINKS_SIZE != 100)
	{
		vector<unsigned int> unique_HEREtiles_ID(Route_Planning_data.list_Links_HEREtile_ID);
		vector<::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile> list_topology_layer_tile;

		sort(unique_HEREtiles_ID.begin(), unique_HEREtiles_ID.end());
		unique_HEREtiles_ID.erase(unique(unique_HEREtiles_ID.begin(), unique_HEREtiles_ID.end()), unique_HEREtiles_ID.end());

		{
			string temp_topology_layer_file;
			::com::here::pb::hdmap::external::v1::topology::TopologyLayerTile temp_topology_layer_tile;

			for (int a(0); a < unique_HEREtiles_ID.size(); a++)
			{
				#ifdef PROJECT_S_SIMULATION
					temp_topology_layer_file = "/home/dpa/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(unique_HEREtiles_ID[a]) + "/" + to_string(unique_HEREtiles_ID[a]) + "_hdmap-topology-geometry-bundle_topology-geometry";
				#endif
				#ifdef PROJECT_S_VEHICLE
					temp_topology_layer_file = "/home/segula/Desktop/ava/achitecture_ws/src/navigation_system/src/ElectronicHorizon/data/HEREtile_" + to_string(unique_HEREtiles_ID[a]) + "/" + to_string(unique_HEREtiles_ID[a]) + "_hdmap-topology-geometry-bundle_topology-geometry";
				#endif

				fstream temp_input(temp_topology_layer_file, ios::in | ios::binary);
				// Check if the tile's topology layer file exists
				if (!temp_input)
				{
					cerr << "Tile's topology layer binary file not found." << endl;
					return true;
				}
				// Trying to read and parse the existing tile's topology layer file
				else if (!temp_topology_layer_tile.ParseFromIstream(&temp_input))
				{
					cerr << "Failed to parse tile's topology layer binary file." << endl;
					return true;
				}
				else
				{
					list_topology_layer_tile.push_back(temp_topology_layer_tile);
				}
			}
		}

		static bool first_exec(true);
		static int saved_index(0);
		vector<::google::protobuf::uint32> links_ID_to_search;
		vector<int> links_index_of_search;

		if (first_exec)
		{
			for (int s(0); s < Route_Planning_data.LIST_LINKS_SIZE; s++)
			{
				links_ID_to_search.push_back(Route_Planning_data.list_Links_ID[s]);
				links_index_of_search.push_back(s);
			}

			first_exec = false;
		}
		else
		{
			for (int s(saved_index); s < Route_Planning_data.LIST_LINKS_SIZE && s < saved_index + 2; s++)
			{
				links_ID_to_search.push_back(Route_Planning_data.list_Links_ID[s]);
				links_index_of_search.push_back(s);
			}
		}

		GpsCoord latlon;
		latlon.lat = ego_data_report.EgoData[0].latitude + d_latitude;
		latlon.lon = ego_data_report.EgoData[0].longitude + d_longitude;

		CartoCoord xy;
		xy = convLatLonToXY(latlon);

		::google::protobuf::uint32 link_id(0), link_tile_id(0);
		float offset(0.0), lengthSum;
		double dist(GPS_PRECISION_DISTANCE);
		double theta;
		double temp_dist;
		float temp_offset;
		GpsCoord gps;
		CartoCoord xyA, xyB, xyH;

		for (int b(0); b < list_topology_layer_tile.size(); b++)
		{
			for (int i(0); i < list_topology_layer_tile[b].links_starting_in_tile_size(); i++)
			{
				const ::com::here::pb::hdmap::external::v1::topology::Link& linkStartingInTile(list_topology_layer_tile[b].links_starting_in_tile(i));

				int c(0);
				vector<int> found_link_index;

				for (int h(0); h < links_ID_to_search.size(); h++)
				{
					if (linkStartingInTile.link_id() == links_ID_to_search[h])
					{
						c++;
						found_link_index.push_back(links_index_of_search[h]);

						links_ID_to_search.erase(links_ID_to_search.begin() + h);
						links_index_of_search.erase(links_index_of_search.begin() + h);
						h--;
					}
				}

				if (c > 0)
				{
					lengthSum = 0.0;

					::google::protobuf::int64 coord(list_topology_layer_tile[b].tile_center_here_2d_coordinate());

					coord ^= linkStartingInTile.geometry().here_2d_coordinate_diffs(0);
					gps = twoDToLatLon(coord);
					xyA = convLatLonToXY(gps);

					int sel_index(-1);

					for (int j(1); j < linkStartingInTile.geometry().here_2d_coordinate_diffs_size(); j++)
					{
						coord ^= linkStartingInTile.geometry().here_2d_coordinate_diffs(j);
						gps = twoDToLatLon(coord);
						xyB = convLatLonToXY(gps);

						double alpha, beta, gamma, delta, maxi, mini;
						alpha = xyB.x - xyA.x;
						beta = xyB.y - xyA.y;
						gamma = alpha * xy.x + beta * xy.y;
						delta = xyB.x * xyA.y - xyA.x * xyB.y;

						xyH.x = (alpha * gamma - beta * delta) / (alpha * alpha + beta * beta);
						xyH.y = (beta * gamma + alpha * delta) / (alpha * alpha + beta * beta);

						if (abs(alpha) >= abs(beta))
						{
							if (xyA.x > xyB.x) { maxi = xyA.x; mini = xyB.x; }
							else { maxi = xyB.x; mini = xyA.x; }

							if (mini <= xyH.x && xyH.x <= maxi)
							{
								temp_dist = sqrt((xy.x - xyH.x) * (xy.x - xyH.x) + (xy.y - xyH.y) * (xy.y - xyH.y));

								temp_offset = sqrt((xyA.x - xyH.x) * (xyA.x - xyH.x) + (xyA.y - xyH.y) * (xyA.y - xyH.y));
							}
							else
							{
								double mA(sqrt((xy.x - xyA.x) * (xy.x - xyA.x) + (xy.y - xyA.y) * (xy.y - xyA.y)));
								double mB(sqrt((xy.x - xyB.x) * (xy.x - xyB.x) + (xy.y - xyB.y) * (xy.y - xyB.y)));

								if (mA < mB)
								{
									temp_dist = mA;

									temp_offset = 0;
								}
								else
								{
									temp_dist = mB;

									temp_offset = sqrt((xyA.x - xyB.x) * (xyA.x - xyB.x) + (xyA.y - xyB.y) * (xyA.y - xyB.y));
								}
							}
						}
						else
						{
							if (xyA.y > xyB.y) { maxi = xyA.y; mini = xyB.y; }
							else { maxi = xyB.y; mini = xyA.y; }

							if (mini <= xyH.y && xyH.y <= maxi)
							{
								temp_dist = sqrt((xy.x - xyH.x) * (xy.x - xyH.x) + (xy.y - xyH.y) * (xy.y - xyH.y));

								temp_offset = sqrt((xyA.x - xyH.x) * (xyA.x - xyH.x) + (xyA.y - xyH.y) * (xyA.y - xyH.y));
							}
							else
							{
								double mA(sqrt((xy.x - xyA.x) * (xy.x - xyA.x) + (xy.y - xyA.y) * (xy.y - xyA.y)));
								double mB(sqrt((xy.x - xyB.x) * (xy.x - xyB.x) + (xy.y - xyB.y) * (xy.y - xyB.y)));

								if (mA < mB)
								{
									temp_dist = mA;

									temp_offset = 0;
								}
								else
								{
									temp_dist = mB;

									temp_offset = sqrt((xyA.x - xyB.x) * (xyA.x - xyB.x) + (xyA.y - xyB.y) * (xyA.y - xyB.y));
								}
							}
						}

						for (int g(0); g < c; g++)
						{
							if (Route_Planning_data.list_Links_vs_Route_direction[found_link_index[g]])
								theta = acos((xyB.y - xyA.y) / sqrt(pow(xyB.x - xyA.x, 2) + pow(xyB.y - xyA.y, 2))) * ((xyB.x - xyA.x >= 0) ? 1 : -1);
							else
								theta = acos((xyA.y - xyB.y) / sqrt(pow(xyA.x - xyB.x, 2) + pow(xyA.y - xyB.y, 2))) * ((xyA.x - xyB.x >= 0) ? 1 : -1);

							if (temp_dist < dist && abs(ego_data_report.EgoData[0].cap + d_Cap - (int)(theta * 180.0 / PI + 360.0) % 360) < ANGLE_TOLERANCE)
							{
								dist = temp_dist;

								offset = temp_offset + lengthSum;

								link_id = linkStartingInTile.link_id();
								link_tile_id = list_topology_layer_tile[b].here_tile_id();

								sel_index = g;

								saved_index = found_link_index[g];
							}
						}

						lengthSum += sqrt((xyA.x - xyB.x) * (xyA.x - xyB.x) + (xyA.y - xyB.y) * (xyA.y - xyB.y));

						xyA = xyB;
					}

					if (link_id == linkStartingInTile.link_id() && sel_index != -1)
					{
						if (!Route_Planning_data.list_Links_vs_Route_direction[found_link_index[sel_index]]) offset = lengthSum - offset;
					}
				}
			}
		}

		if (link_id != 0)
		{
			Map_Matching_data.link_ID.data = link_id;
			Map_Matching_data.link_HEREtile_ID.data = link_tile_id;
			Map_Matching_data.Distance_Curviligne_Ego.data = offset;
			Map_Matching_data.latitude = ego_data_report.EgoData[0].latitude + d_latitude;
			Map_Matching_data.longitude = ego_data_report.EgoData[0].longitude + d_longitude;
			Map_Matching_data.cap.data = ego_data_report.EgoData[0].cap + d_Cap;
		}
		else
		{
			first_exec = true;

			Map_Matching_data.link_ID.data = 0;
			Map_Matching_data.link_HEREtile_ID.data = 0;
			Map_Matching_data.Distance_Curviligne_Ego.data = 0.0;
			Map_Matching_data.latitude = ego_data_report.EgoData[0].latitude + d_latitude;
			Map_Matching_data.longitude = ego_data_report.EgoData[0].longitude + d_longitude;
			Map_Matching_data.cap.data = ego_data_report.EgoData[0].cap + d_Cap;
		}

		return false;
	}
	else
	{
		GpsCoord latlon;
		latlon.lat = ego_data_report.EgoData[0].latitude + d_latitude;
		latlon.lon = ego_data_report.EgoData[0].longitude + d_longitude;

		CartoCoord xy;
		xy = convLatLonToXY(latlon);

//		double offset_min, offset_match, lengthSum(0.0);
		double min_offset, match_offset;
		double dist_min, dist_match(GPS_PRECISION_DISTANCE);
		double theta;

		{
			double temp_dist;
			double temp_offset;
			GpsCoord gps;
			CartoCoord xyA, xyB, xyH;

			gps.lat = Route_Planning_data.Tableau_circuit_GPS[0].latitude;
			gps.lon = Route_Planning_data.Tableau_circuit_GPS[0].longitude;
			xyA = convLatLonToXY(gps);

			{
				gps.lat = Route_Planning_data.Tableau_circuit_GPS[1].latitude;
				gps.lon = Route_Planning_data.Tableau_circuit_GPS[1].longitude;
				xyB = convLatLonToXY(gps);

				double alpha, beta, gamma, delta, maxi, mini;
				alpha = xyB.x - xyA.x;
				beta = xyB.y - xyA.y;
				gamma = alpha * xy.x + beta * xy.y;
				delta = xyB.x * xyA.y - xyA.x * xyB.y;

				xyH.x = (alpha * gamma - beta * delta) / (alpha * alpha + beta * beta);
				xyH.y = (beta * gamma + alpha * delta) / (alpha * alpha + beta * beta);

				if (abs(alpha) >= abs(beta))
				{
					if (xyA.x > xyB.x) { maxi = xyA.x; mini = xyB.x; }
					else { maxi = xyB.x; mini = xyA.x; }

					if (mini <= xyH.x && xyH.x <= maxi)
					{
						temp_dist = sqrt((xy.x - xyH.x) * (xy.x - xyH.x) + (xy.y - xyH.y) * (xy.y - xyH.y));

						temp_offset = sqrt((xyA.x - xyH.x) * (xyA.x - xyH.x) + (xyA.y - xyH.y) * (xyA.y - xyH.y));
					}
					else
					{
						double mA(sqrt((xy.x - xyA.x) * (xy.x - xyA.x) + (xy.y - xyA.y) * (xy.y - xyA.y)));
						double mB(sqrt((xy.x - xyB.x) * (xy.x - xyB.x) + (xy.y - xyB.y) * (xy.y - xyB.y)));

						if (mA < mB)
						{
							temp_dist = mA;

							temp_offset = 0;
						}
						else
						{
							temp_dist = mB;

							temp_offset = sqrt((xyA.x - xyB.x) * (xyA.x - xyB.x) + (xyA.y - xyB.y) * (xyA.y - xyB.y));
						}
					}
				}
				else
				{
					if (xyA.y > xyB.y) { maxi = xyA.y; mini = xyB.y; }
					else { maxi = xyB.y; mini = xyA.y; }

					if (mini <= xyH.y && xyH.y <= maxi)
					{
						temp_dist = sqrt((xy.x - xyH.x) * (xy.x - xyH.x) + (xy.y - xyH.y) * (xy.y - xyH.y));

						temp_offset = sqrt((xyA.x - xyH.x) * (xyA.x - xyH.x) + (xyA.y - xyH.y) * (xyA.y - xyH.y));
					}
					else
					{
						double mA(sqrt((xy.x - xyA.x) * (xy.x - xyA.x) + (xy.y - xyA.y) * (xy.y - xyA.y)));
						double mB(sqrt((xy.x - xyB.x) * (xy.x - xyB.x) + (xy.y - xyB.y) * (xy.y - xyB.y)));

						if (mA < mB)
						{
							temp_dist = mA;

							temp_offset = 0;
						}
						else
						{
							temp_dist = mB;

							temp_offset = sqrt((xyA.x - xyB.x) * (xyA.x - xyB.x) + (xyA.y - xyB.y) * (xyA.y - xyB.y));
						}
					}
				}

				dist_min = temp_dist;

//				offset_min = temp_offset;
				min_offset = temp_offset;

				theta = acos((xyB.y - xyA.y) / sqrt(pow(xyB.x - xyA.x, 2) + pow(xyB.y - xyA.y, 2))) * ((xyB.x - xyA.x >= 0) ? 1 : -1);

				if (temp_dist < dist_match && abs(ego_data_report.EgoData[0].cap  + d_Cap - (int)(theta * 180.0 / PI + 360.0) % 360) < ANGLE_TOLERANCE)
				{
					dist_match = temp_dist;

//					offset_match = temp_offset;
					match_offset = temp_offset;
				}

//				lengthSum = sqrt((xyA.x - xyB.x) * (xyA.x - xyB.x) + (xyA.y - xyB.y) * (xyA.y - xyB.y));

				xyA = xyB;
			}

			for (int j(2); j < Route_Planning_data.Tableau_circuit_GPS.size(); j++)
			{
				gps.lat = Route_Planning_data.Tableau_circuit_GPS[j].latitude;
				gps.lon = Route_Planning_data.Tableau_circuit_GPS[j].longitude;
				xyB = convLatLonToXY(gps);

				double alpha, beta, gamma, delta, maxi, mini;
				alpha = xyB.x - xyA.x;
				beta = xyB.y - xyA.y;
				gamma = alpha * xy.x + beta * xy.y;
				delta = xyB.x * xyA.y - xyA.x * xyB.y;

				xyH.x = (alpha * gamma - beta * delta) / (alpha * alpha + beta * beta);
				xyH.y = (beta * gamma + alpha * delta) / (alpha * alpha + beta * beta);

				if (abs(alpha) >= abs(beta))
				{
					if (xyA.x > xyB.x) { maxi = xyA.x; mini = xyB.x; }
					else { maxi = xyB.x; mini = xyA.x; }

					if (mini <= xyH.x && xyH.x <= maxi)
					{
						temp_dist = sqrt((xy.x - xyH.x) * (xy.x - xyH.x) + (xy.y - xyH.y) * (xy.y - xyH.y));

						temp_offset = sqrt((xyA.x - xyH.x) * (xyA.x - xyH.x) + (xyA.y - xyH.y) * (xyA.y - xyH.y));
					}
					else
					{
						double mA(sqrt((xy.x - xyA.x) * (xy.x - xyA.x) + (xy.y - xyA.y) * (xy.y - xyA.y)));
						double mB(sqrt((xy.x - xyB.x) * (xy.x - xyB.x) + (xy.y - xyB.y) * (xy.y - xyB.y)));

						if (mA < mB)
						{
							temp_dist = mA;

							temp_offset = 0;
						}
						else
						{
							temp_dist = mB;

							temp_offset = sqrt((xyA.x - xyB.x) * (xyA.x - xyB.x) + (xyA.y - xyB.y) * (xyA.y - xyB.y));
						}
					}
				}
				else
				{
					if (xyA.y > xyB.y) { maxi = xyA.y; mini = xyB.y; }
					else { maxi = xyB.y; mini = xyA.y; }

					if (mini <= xyH.y && xyH.y <= maxi)
					{
						temp_dist = sqrt((xy.x - xyH.x) * (xy.x - xyH.x) + (xy.y - xyH.y) * (xy.y - xyH.y));

						temp_offset = sqrt((xyA.x - xyH.x) * (xyA.x - xyH.x) + (xyA.y - xyH.y) * (xyA.y - xyH.y));
					}
					else
					{
						double mA(sqrt((xy.x - xyA.x) * (xy.x - xyA.x) + (xy.y - xyA.y) * (xy.y - xyA.y)));
						double mB(sqrt((xy.x - xyB.x) * (xy.x - xyB.x) + (xy.y - xyB.y) * (xy.y - xyB.y)));

						if (mA < mB)
						{
							temp_dist = mA;

							temp_offset = 0;
						}
						else
						{
							temp_dist = mB;

							temp_offset = sqrt((xyA.x - xyB.x) * (xyA.x - xyB.x) + (xyA.y - xyB.y) * (xyA.y - xyB.y));
						}
					}
				}

				if (temp_dist < dist_min)
				{
					dist_min = temp_dist;

//					offset_min = temp_offset + lengthSum;
					min_offset = temp_offset + Route_Planning_data.Tableau_circuit_GPS[j - 1].offset;
				}

				theta = acos((xyB.y - xyA.y) / sqrt(pow(xyB.x - xyA.x, 2) + pow(xyB.y - xyA.y, 2))) * ((xyB.x - xyA.x >= 0) ? 1 : -1);

				if (temp_dist < dist_match && abs(ego_data_report.EgoData[0].cap  + d_Cap - (int)(theta * 180.0 / PI + 360.0) % 360) < ANGLE_TOLERANCE)
				{
					dist_match = temp_dist;

//					offset_match = temp_offset + lengthSum;
					match_offset = temp_offset + Route_Planning_data.Tableau_circuit_GPS[j - 1].offset;
				}

//				lengthSum += sqrt((xyA.x - xyB.x) * (xyA.x - xyB.x) + (xyA.y - xyB.y) * (xyA.y - xyB.y));

				xyA = xyB;
			}
		}

		if (dist_match < GPS_PRECISION_DISTANCE)
		{
//			Map_Matching_data.Distance_Curviligne_Ego.data = offset_match;
			Map_Matching_data.Distance_Curviligne_Ego.data = match_offset;
			Map_Matching_data.latitude = ego_data_report.EgoData[0].latitude + d_latitude;
			Map_Matching_data.longitude = ego_data_report.EgoData[0].longitude + d_longitude;
			Map_Matching_data.cap.data = ego_data_report.EgoData[0].cap + d_Cap;
		}
		else
		{
//			Map_Matching_data.Distance_Curviligne_Ego.data = offset_min;
			Map_Matching_data.Distance_Curviligne_Ego.data = min_offset;
			Map_Matching_data.latitude = ego_data_report.EgoData[0].latitude + d_latitude;
			Map_Matching_data.longitude = ego_data_report.EgoData[0].longitude + d_longitude;
			Map_Matching_data.cap.data = ego_data_report.EgoData[0].cap + d_Cap;
		}

		return false;
	}
}

//-------------------------------------------------------------------------------------------------
// output data
//-------------------------------------------------------------------------------------------------
project_s_msgs::MapMatching Map_Matching_data;

//-------------------------------------------------------------------------------------------------
// input data
//-------------------------------------------------------------------------------------------------
project_s_msgs::EgoDataReport ego_data_report;
project_s_msgs::RoutePlanning Route_Planning_data;
project_s_msgs::FineMapMatching Fine_Map_Matching_data;

//-------------------------------------------------------------------------------------------------
// local Callback
//-------------------------------------------------------------------------------------------------
bool receivedEgoDataReport = false;
void egoDataCallback(const project_s_msgs::EgoDataReport::ConstPtr& buffer)
{
	ego_data_report = *buffer;

	receivedEgoDataReport = true;
}

bool receivedRoutePlanning = false;
void routePlanningCallback(const project_s_msgs::RoutePlanning::ConstPtr& buffer)
{
	Route_Planning_data = *buffer;

	receivedRoutePlanning = true;
}

bool receivedFineMapMatching = false;
void fineMapMatchingCallback(const project_s_msgs::FineMapMatching::ConstPtr& buffer)
{
	Fine_Map_Matching_data = *buffer;

	receivedFineMapMatching = true;
}

//-------------------------------------------------------------------------------------------------
// main
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	ros::init(argc, argv, std::string("map_matching"));

	ros::NodeHandle n;
	
	ros::Subscriber subEgoData = n.subscribe(std::string("/ego_data"), 1, egoDataCallback);
	
	ros::Subscriber subRoutePlanning = n.subscribe(std::string("/route_planning_data"), 1, routePlanningCallback);
	
	ros::Subscriber subFineMapMatching = n.subscribe(std::string("/fine_map_matching_data"), 1, fineMapMatchingCallback);

	ros::Publisher pub_map_matching_data = n.advertise<project_s_msgs::MapMatching>(std::string("/map_matching_data"), 1);

	ros::Rate loop_rate(10);
	
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
	while(!receivedRoutePlanning)
	{
		ros::spinOnce();
		
		loop_rate.sleep();
	}

	while(n.ok())
	{
		ros::spinOnce();

		if(receivedFineMapMatching)
		{
			receivedFineMapMatching = false;
		}
		
		if(receivedEgoDataReport)
		{
			receivedEgoDataReport = false;
		
			bool error;
		
			error = map_matching(ego_data_report, Map_Matching_data, Route_Planning_data, Fine_Map_Matching_data.d_latitude, Fine_Map_Matching_data.d_longitude, Fine_Map_Matching_data.dCap.data);		

			if (error) cerr << "\nError: map_matching\n";
			else pub_map_matching_data.publish(Map_Matching_data);
		}
		
		loop_rate.sleep();
	}

	return 0;
}
