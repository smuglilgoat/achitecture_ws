Header header
std_msgs/UInt8 id

uint16 SEGMENT_REPORT_SIZE = 3000
project_s_msgs/Segment[3000] segment
std_msgs/UInt16 QtySegment
std_msgs/Float32 lineClass	# class of the line
std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)

std_msgs/UInt8 existenceState
std_msgs/Float32 scoreDetection
std_msgs/Float32 nbrDetection
std_msgs/Float32 nbrVisibility
std_msgs/Float32 scorePersistence
std_msgs/Float32 nbrUpdate
std_msgs/Float32 nbrAge


