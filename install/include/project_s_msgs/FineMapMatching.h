// Generated by gencpp from file project_s_msgs/FineMapMatching.msg
// DO NOT EDIT!


#ifndef PROJECT_S_MSGS_MESSAGE_FINEMAPMATCHING_H
#define PROJECT_S_MSGS_MESSAGE_FINEMAPMATCHING_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32.h>
#include <project_s_msgs/ElectronicHorizonArray.h>

namespace project_s_msgs
{
template <class ContainerAllocator>
struct FineMapMatching_
{
  typedef FineMapMatching_<ContainerAllocator> Type;

  FineMapMatching_()
    : header()
    , id()
    , dCap()
    , d_x_lambert()
    , d_y_lambert()
    , d_latitude(0.0)
    , d_longitude(0.0)
    , electronicHorizonArray()  {
    }
  FineMapMatching_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(_alloc)
    , dCap(_alloc)
    , d_x_lambert(_alloc)
    , d_y_lambert(_alloc)
    , d_latitude(0.0)
    , d_longitude(0.0)
    , electronicHorizonArray(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _id_type;
  _id_type id;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _dCap_type;
  _dCap_type dCap;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _d_x_lambert_type;
  _d_x_lambert_type d_x_lambert;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _d_y_lambert_type;
  _d_y_lambert_type d_y_lambert;

   typedef double _d_latitude_type;
  _d_latitude_type d_latitude;

   typedef double _d_longitude_type;
  _d_longitude_type d_longitude;

   typedef  ::project_s_msgs::ElectronicHorizonArray_<ContainerAllocator>  _electronicHorizonArray_type;
  _electronicHorizonArray_type electronicHorizonArray;





  typedef boost::shared_ptr< ::project_s_msgs::FineMapMatching_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project_s_msgs::FineMapMatching_<ContainerAllocator> const> ConstPtr;

}; // struct FineMapMatching_

typedef ::project_s_msgs::FineMapMatching_<std::allocator<void> > FineMapMatching;

typedef boost::shared_ptr< ::project_s_msgs::FineMapMatching > FineMapMatchingPtr;
typedef boost::shared_ptr< ::project_s_msgs::FineMapMatching const> FineMapMatchingConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project_s_msgs::FineMapMatching_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project_s_msgs::FineMapMatching_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace project_s_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'shape_msgs': ['/opt/ros/kinetic/share/shape_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/kinetic/share/trajectory_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'project_s_msgs': ['/home/segula/Desktop/ava/achitecture_ws/src/project_s_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'mobileye_560_660_msgs': ['/home/dev/as_drivers_customer/install/share/mobileye_560_660_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::FineMapMatching_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::FineMapMatching_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::FineMapMatching_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::FineMapMatching_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::FineMapMatching_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::FineMapMatching_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project_s_msgs::FineMapMatching_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bbc6c31487a0775416bf98fdaad9098b";
  }

  static const char* value(const ::project_s_msgs::FineMapMatching_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbbc6c31487a07754ULL;
  static const uint64_t static_value2 = 0x16bf98fdaad9098bULL;
};

template<class ContainerAllocator>
struct DataType< ::project_s_msgs::FineMapMatching_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project_s_msgs/FineMapMatching";
  }

  static const char* value(const ::project_s_msgs::FineMapMatching_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project_s_msgs::FineMapMatching_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
std_msgs/UInt8 id\n\
\n\
std_msgs/Float32 dCap\n\
\n\
std_msgs/Float32 d_x_lambert	# sens sud   -> nord, unité en m\n\
std_msgs/Float32 d_y_lambert	# sens ouest -> est , unité en m\n\
\n\
float64 d_latitude	# unité en °\n\
float64 d_longitude	# unité en °\n\
\n\
project_s_msgs/ElectronicHorizonArray electronicHorizonArray\n\
\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: std_msgs/UInt8\n\
uint8 data\n\
\n\
================================================================================\n\
MSG: std_msgs/Float32\n\
float32 data\n\
================================================================================\n\
MSG: project_s_msgs/ElectronicHorizonArray\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
project_s_msgs/ElectronicHorizon[5] PathsArray\n\
std_msgs/UInt8 NbrPath\n\
std_msgs/UInt8 indexMPP\n\
\n\
nav_msgs/Odometry odom\n\
\n\
\n\
\n\
================================================================================\n\
MSG: project_s_msgs/ElectronicHorizon\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
std_msgs/UInt8 indexPath\n\
\n\
uint8 SEGMENT_REPORT_SIZE = 50\n\
project_s_msgs/ehSegment[50] ehSegment\n\
std_msgs/UInt8 NbrSegment\n\
\n\
uint8 STUB_REPORT_SIZE = 10\n\
project_s_msgs/ehStub[10] ehStub\n\
std_msgs/UInt8 NbrStub\n\
\n\
uint16 SPOT_CURVATURE_REPORT_SIZE = 300\n\
project_s_msgs/ehSpotCurvature[300] ehSpotCurvature\n\
std_msgs/UInt16 NbrSpotCurvature\n\
\n\
uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000\n\
project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight\n\
std_msgs/UInt16 NbrSpotCoordGeoRight\n\
project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft\n\
std_msgs/UInt16 NbrSpotCoordGeoLeft\n\
\n\
uint8 LINE_REPORT_SIZE = 10\n\
project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo\n\
std_msgs/UInt8 QtyLineCoordGeo\n\
\n\
uint8 ME_RIGHT_LINE = 0\n\
uint8 ME_LEFT_LINE = 1\n\
project_s_msgs/ehME[2] ehME\n\
\n\
uint8 NBR_LINE_REPORT_SIZE = 100\n\
project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo\n\
std_msgs/UInt8 QtyNbrLineCoordGeo\n\
\n\
uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50\n\
project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign\n\
std_msgs/UInt8 NbrSpotTrafficSign\n\
\n\
project_s_msgs/ehPosition ehPosition\n\
\n\
uint8 speedLimit_interpolMethod\n\
uint8 curvature_interpolMethod\n\
uint8 STEP = 0\n\
uint8 LINEAR = 1\n\
\n\
uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100\n\
project_s_msgs/ehSegmentME[100] ehSegmentAO\n\
std_msgs/UInt8 QtySegmentAO\n\
\n\
uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100\n\
project_s_msgs/ehSegmentME[100] ehSegmentEO\n\
std_msgs/UInt8 QtySegmentEO\n\
\n\
\n\
================================================================================\n\
MSG: project_s_msgs/ehSegment\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
#std_msgs/UInt8 indexPath\n\
std_msgs/Float32 offset\n\
std_msgs/UInt8 functionRoadClass\n\
std_msgs/UInt8 wayForm\n\
std_msgs/UInt8 effectiveSpeedLimit\n\
std_msgs/UInt8 nbLanesDrivingDirection\n\
std_msgs/UInt8 nbLanesOppositeDirection\n\
\n\
\n\
\n\
================================================================================\n\
MSG: project_s_msgs/ehStub\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
#std_msgs/UInt8 indexPath\n\
std_msgs/Float32 offset\n\
std_msgs/UInt8 indexSubPath\n\
std_msgs/Float32 turnAngle\n\
std_msgs/UInt8 functionRoadClass\n\
std_msgs/UInt8 wayForm\n\
std_msgs/UInt8 nbLanesDrivingDirection\n\
std_msgs/UInt8 nbLanesOppositeDirection\n\
\n\
\n\
\n\
================================================================================\n\
MSG: project_s_msgs/ehSpotCurvature\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
#std_msgs/UInt8 indexPath\n\
std_msgs/Float32 offset\n\
std_msgs/Float32 Value_0\n\
std_msgs/Float32 Distance_1\n\
std_msgs/Float32 Value_1\n\
\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/UInt16\n\
uint16 data\n\
\n\
================================================================================\n\
MSG: project_s_msgs/ehSpotCoordGeo\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
std_msgs/Float32 offset\n\
float64 latitude\n\
float64 longitude\n\
\n\
\n\
\n\
================================================================================\n\
MSG: project_s_msgs/ehLineCoordGeo\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
uint32 SPOT_REPORT_SIZE = 3000\n\
project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo\n\
std_msgs/UInt32 NbrSpotCoordGeo\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/UInt32\n\
uint32 data\n\
================================================================================\n\
MSG: project_s_msgs/ehME\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
uint32 SPOT_REPORT_SIZE = 2000\n\
project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo\n\
std_msgs/UInt32 NbrSpotCoordGeo\n\
\n\
uint32 SEGMENT_ME_REPORT_SIZE = 100\n\
project_s_msgs/ehSegmentME[100] ehSegmentME\n\
std_msgs/UInt32 QtySegment\n\
\n\
================================================================================\n\
MSG: project_s_msgs/ehSegmentME\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
std_msgs/UInt32 NbrSpot\n\
std_msgs/Float32 offset_debut\n\
std_msgs/Float32 offset_fin\n\
\n\
================================================================================\n\
MSG: project_s_msgs/ehNbrLineCoordGeo\n\
std_msgs/UInt8 Nbr\n\
std_msgs/Float32 offset\n\
\n\
\n\
\n\
\n\
================================================================================\n\
MSG: project_s_msgs/ehSpotTrafficSign\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
std_msgs/Float32 offset\n\
uint8 Sign_Type\n\
uint8 Value\n\
uint8 Lane\n\
uint8 Sign_Location\n\
float64 latitude\n\
float64 longitude\n\
\n\
\n\
\n\
\n\
================================================================================\n\
MSG: project_s_msgs/ehPosition\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
#std_msgs/UInt8 indexPath\n\
std_msgs/Float32 offset\n\
float64 latitude\n\
float64 longitude\n\
std_msgs/Float32 cap\n\
std_msgs/UInt16 agePosition\n\
std_msgs/Float32 speed\n\
std_msgs/Float32 relativeHeading\n\
std_msgs/UInt8 currentLane\n\
\n\
\n\
\n\
================================================================================\n\
MSG: nav_msgs/Odometry\n\
# This represents an estimate of a position and velocity in free space.  \n\
# The pose in this message should be specified in the coordinate frame given by header.frame_id.\n\
# The twist in this message should be specified in the coordinate frame given by the child_frame_id\n\
Header header\n\
string child_frame_id\n\
geometry_msgs/PoseWithCovariance pose\n\
geometry_msgs/TwistWithCovariance twist\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseWithCovariance\n\
# This represents a pose in free space with uncertainty.\n\
\n\
Pose pose\n\
\n\
# Row-major representation of the 6x6 covariance matrix\n\
# The orientation parameters use a fixed-axis representation.\n\
# In order, the parameters are:\n\
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n\
float64[36] covariance\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
================================================================================\n\
MSG: geometry_msgs/TwistWithCovariance\n\
# This expresses velocity in free space with uncertainty.\n\
\n\
Twist twist\n\
\n\
# Row-major representation of the 6x6 covariance matrix\n\
# The orientation parameters use a fixed-axis representation.\n\
# In order, the parameters are:\n\
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n\
float64[36] covariance\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Twist\n\
# This expresses velocity in free space broken into its linear and angular parts.\n\
Vector3  linear\n\
Vector3  angular\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::project_s_msgs::FineMapMatching_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project_s_msgs::FineMapMatching_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.dCap);
      stream.next(m.d_x_lambert);
      stream.next(m.d_y_lambert);
      stream.next(m.d_latitude);
      stream.next(m.d_longitude);
      stream.next(m.electronicHorizonArray);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct FineMapMatching_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project_s_msgs::FineMapMatching_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project_s_msgs::FineMapMatching_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.id);
    s << indent << "dCap: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.dCap);
    s << indent << "d_x_lambert: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.d_x_lambert);
    s << indent << "d_y_lambert: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.d_y_lambert);
    s << indent << "d_latitude: ";
    Printer<double>::stream(s, indent + "  ", v.d_latitude);
    s << indent << "d_longitude: ";
    Printer<double>::stream(s, indent + "  ", v.d_longitude);
    s << indent << "electronicHorizonArray: ";
    s << std::endl;
    Printer< ::project_s_msgs::ElectronicHorizonArray_<ContainerAllocator> >::stream(s, indent + "  ", v.electronicHorizonArray);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_S_MSGS_MESSAGE_FINEMAPMATCHING_H
