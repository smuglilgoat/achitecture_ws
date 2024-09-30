Header header
std_msgs/UInt8 id

std_msgs/UInt8 nbrLine
project_s_msgs/Line[10] roadLine			#segments array

project_s_msgs/ElectronicHorizon electronicHorizon

uint32 SPEED_LIMIT_ARRAY_SIZE = 310
project_s_msgs/Speed[310] speedEnveloppe

uint8 AMER_ARRAY_SIZE = 50
geometry_msgs/Point[50] amer
std_msgs/UInt8 nbrAmer


nav_msgs/Odometry odom

