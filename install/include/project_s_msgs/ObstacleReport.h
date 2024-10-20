// Generated by gencpp from file project_s_msgs/ObstacleReport.msg
// DO NOT EDIT!


#ifndef PROJECT_S_MSGS_MESSAGE_OBSTACLEREPORT_H
#define PROJECT_S_MSGS_MESSAGE_OBSTACLEREPORT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/UInt8.h>
#include <project_s_msgs/GenericSmartData.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Float64.h>
#include <nav_msgs/Odometry.h>

namespace project_s_msgs
{
template <class ContainerAllocator>
struct ObstacleReport_
{
  typedef ObstacleReport_<ContainerAllocator> Type;

  ObstacleReport_()
    : header()
    , id()
    , GenericSmartData()
    , QtySmartData()
    , dateAcquisition()
    , odom()  {
    }
  ObstacleReport_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(_alloc)
    , GenericSmartData()
    , QtySmartData(_alloc)
    , dateAcquisition(_alloc)
    , odom(_alloc)  {
  (void)_alloc;
      GenericSmartData.assign( ::project_s_msgs::GenericSmartData_<ContainerAllocator> (_alloc));
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _id_type;
  _id_type id;

   typedef boost::array< ::project_s_msgs::GenericSmartData_<ContainerAllocator> , 64>  _GenericSmartData_type;
  _GenericSmartData_type GenericSmartData;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _QtySmartData_type;
  _QtySmartData_type QtySmartData;

   typedef  ::std_msgs::Float64_<ContainerAllocator>  _dateAcquisition_type;
  _dateAcquisition_type dateAcquisition;

   typedef  ::nav_msgs::Odometry_<ContainerAllocator>  _odom_type;
  _odom_type odom;





  typedef boost::shared_ptr< ::project_s_msgs::ObstacleReport_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project_s_msgs::ObstacleReport_<ContainerAllocator> const> ConstPtr;

}; // struct ObstacleReport_

typedef ::project_s_msgs::ObstacleReport_<std::allocator<void> > ObstacleReport;

typedef boost::shared_ptr< ::project_s_msgs::ObstacleReport > ObstacleReportPtr;
typedef boost::shared_ptr< ::project_s_msgs::ObstacleReport const> ObstacleReportConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project_s_msgs::ObstacleReport_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project_s_msgs::ObstacleReport_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::project_s_msgs::ObstacleReport_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::ObstacleReport_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::ObstacleReport_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::ObstacleReport_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::ObstacleReport_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::ObstacleReport_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project_s_msgs::ObstacleReport_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d66d512738eec8e99605306c6e973be5";
  }

  static const char* value(const ::project_s_msgs::ObstacleReport_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd66d512738eec8e9ULL;
  static const uint64_t static_value2 = 0x9605306c6e973be5ULL;
};

template<class ContainerAllocator>
struct DataType< ::project_s_msgs::ObstacleReport_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project_s_msgs/ObstacleReport";
  }

  static const char* value(const ::project_s_msgs::ObstacleReport_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project_s_msgs::ObstacleReport_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
std_msgs/UInt8 id\n\
\n\
project_s_msgs/GenericSmartData[64] GenericSmartData		#GenericSmartData array   \n\
std_msgs/UInt8 QtySmartData\n\
std_msgs/Float64 dateAcquisition\n\
nav_msgs/Odometry odom\n\
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
MSG: project_s_msgs/GenericSmartData\n\
Header header\n\
std_msgs/UInt16 id\n\
\n\
geometry_msgs/Pose obstaclePosition		# obstacle position\n\
geometry_msgs/Twist obstacleVelocity		# obstacle speed\n\
geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration\n\
geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height\n\
geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance\n\
geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance\n\
\n\
uint8 OBSTACLE_CLASS_NONE = 0\n\
uint8 OBSTACLE_CLASS_SIGN = 1\n\
uint8 OBSTACLE_CLASS_PLOT = 2\n\
uint8 OBSTACLE_CLASS_INVALID = 255\n\
uint8 obstacleClass\n\
\n\
uint8 vision_only_sign_type\n\
\n\
================================================================================\n\
MSG: std_msgs/UInt16\n\
uint16 data\n\
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
================================================================================\n\
MSG: geometry_msgs/Accel\n\
# This expresses acceleration in free space broken into its linear and angular parts.\n\
Vector3  linear\n\
Vector3  angular\n\
\n\
================================================================================\n\
MSG: std_msgs/Float64\n\
float64 data\n\
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
";
  }

  static const char* value(const ::project_s_msgs::ObstacleReport_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project_s_msgs::ObstacleReport_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.GenericSmartData);
      stream.next(m.QtySmartData);
      stream.next(m.dateAcquisition);
      stream.next(m.odom);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ObstacleReport_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project_s_msgs::ObstacleReport_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project_s_msgs::ObstacleReport_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.id);
    s << indent << "GenericSmartData[]" << std::endl;
    for (size_t i = 0; i < v.GenericSmartData.size(); ++i)
    {
      s << indent << "  GenericSmartData[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::GenericSmartData_<ContainerAllocator> >::stream(s, indent + "    ", v.GenericSmartData[i]);
    }
    s << indent << "QtySmartData: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.QtySmartData);
    s << indent << "dateAcquisition: ";
    s << std::endl;
    Printer< ::std_msgs::Float64_<ContainerAllocator> >::stream(s, indent + "  ", v.dateAcquisition);
    s << indent << "odom: ";
    s << std::endl;
    Printer< ::nav_msgs::Odometry_<ContainerAllocator> >::stream(s, indent + "  ", v.odom);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_S_MSGS_MESSAGE_OBSTACLEREPORT_H
