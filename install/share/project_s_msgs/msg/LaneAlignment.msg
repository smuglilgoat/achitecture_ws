Header header
std_msgs/UInt8 id

#geometry_msgs/Point[250] points

uint8 LINE_REPORT_SIZE = 20
project_s_msgs/Line[20] line
std_msgs/UInt8 QtyLine

geometry_msgs/Pose lanePosition
geometry_msgs/Pose lanePoseVariance
std_msgs/UInt8 laneClass
std_msgs/UInt8 classificationProbability
std_msgs/UInt8 laneQuality
std_msgs/UInt64 dateAcquisition
nav_msgs/Odometry odom

# History




