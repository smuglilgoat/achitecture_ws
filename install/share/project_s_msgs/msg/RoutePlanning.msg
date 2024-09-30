Header header
std_msgs/UInt8 id

project_s_msgs/Segment[] roadSegment		#segments array   
std_msgs/UInt8 nbrLane
std_msgs/UInt8 intersection

uint32[] list_Links_ID
uint32[] list_Links_HEREtile_ID
uint32[] list_Nodes_ID
uint32[] list_Nodes_HEREtile_ID
bool[] list_Links_vs_Route_direction
uint32 LIST_LINKS_SIZE

uint32 NBRE_POINT_CIRCUIT_GPS
uint32 NBRE_POINT_TABLEAU_GPS

project_s_msgs/point_GPS[]   Tableau_circuit_GPS
project_s_msgs/point_GPS[]   Tableau_circuit_GPS_gauche
project_s_msgs/point_GPS[]   Tableau_circuit_GPS_droite

project_s_msgs/point_GPS[]   Tableau_circuit_GPS_MEgauche
project_s_msgs/point_GPS[]   Tableau_circuit_GPS_MEdroite

project_s_msgs/speed_limit[] Tableau_circuit_speedlimit
project_s_msgs/curvature[]   Tableau_circuit_curvature
project_s_msgs/traffic_sign[]   Tableau_circuit_trafficsign


project_s_msgs/segmentME[] Tableau_circuit_ehSegmentAO
project_s_msgs/segmentME[] Tableau_circuit_ehSegmentEO

