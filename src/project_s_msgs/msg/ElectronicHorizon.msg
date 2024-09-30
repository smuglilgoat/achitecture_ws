Header header
std_msgs/UInt8 id

std_msgs/UInt8 indexPath

uint8 SEGMENT_REPORT_SIZE = 50
project_s_msgs/ehSegment[50] ehSegment
std_msgs/UInt8 NbrSegment

uint8 STUB_REPORT_SIZE = 10
project_s_msgs/ehStub[10] ehStub
std_msgs/UInt8 NbrStub

uint16 SPOT_CURVATURE_REPORT_SIZE = 300
project_s_msgs/ehSpotCurvature[300] ehSpotCurvature
std_msgs/UInt16 NbrSpotCurvature

uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000
project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight
std_msgs/UInt16 NbrSpotCoordGeoRight
project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft
std_msgs/UInt16 NbrSpotCoordGeoLeft

uint8 LINE_REPORT_SIZE = 10
project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo
std_msgs/UInt8 QtyLineCoordGeo

uint8 ME_RIGHT_LINE = 0
uint8 ME_LEFT_LINE = 1
project_s_msgs/ehME[2] ehME

uint8 NBR_LINE_REPORT_SIZE = 100
project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo
std_msgs/UInt8 QtyNbrLineCoordGeo

uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50
project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign
std_msgs/UInt8 NbrSpotTrafficSign

project_s_msgs/ehPosition ehPosition

uint8 speedLimit_interpolMethod
uint8 curvature_interpolMethod
uint8 STEP = 0
uint8 LINEAR = 1

uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100
project_s_msgs/ehSegmentME[100] ehSegmentAO
std_msgs/UInt8 QtySegmentAO

uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100
project_s_msgs/ehSegmentME[100] ehSegmentEO
std_msgs/UInt8 QtySegmentEO

