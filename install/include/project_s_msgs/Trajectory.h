// Generated by gencpp from file project_s_msgs/Trajectory.msg
// DO NOT EDIT!


#ifndef PROJECT_S_MSGS_MESSAGE_TRAJECTORY_H
#define PROJECT_S_MSGS_MESSAGE_TRAJECTORY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/UInt8.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32.h>
#include <project_s_msgs/Line.h>
#include <nav_msgs/Odometry.h>

namespace project_s_msgs
{
template <class ContainerAllocator>
struct Trajectory_
{
  typedef Trajectory_<ContainerAllocator> Type;

  Trajectory_()
    : header()
    , id()
    , setpointPosition()
    , setpointVelocity()
    , targetLength()
    , targetSpeed()
    , trajectoryLine()
    , odom()  {
    }
  Trajectory_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(_alloc)
    , setpointPosition(_alloc)
    , setpointVelocity(_alloc)
    , targetLength(_alloc)
    , targetSpeed(_alloc)
    , trajectoryLine(_alloc)
    , odom(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _id_type;
  _id_type id;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _setpointPosition_type;
  _setpointPosition_type setpointPosition;

   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _setpointVelocity_type;
  _setpointVelocity_type setpointVelocity;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _targetLength_type;
  _targetLength_type targetLength;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _targetSpeed_type;
  _targetSpeed_type targetSpeed;

   typedef  ::project_s_msgs::Line_<ContainerAllocator>  _trajectoryLine_type;
  _trajectoryLine_type trajectoryLine;

   typedef  ::nav_msgs::Odometry_<ContainerAllocator>  _odom_type;
  _odom_type odom;





  typedef boost::shared_ptr< ::project_s_msgs::Trajectory_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project_s_msgs::Trajectory_<ContainerAllocator> const> ConstPtr;

}; // struct Trajectory_

typedef ::project_s_msgs::Trajectory_<std::allocator<void> > Trajectory;

typedef boost::shared_ptr< ::project_s_msgs::Trajectory > TrajectoryPtr;
typedef boost::shared_ptr< ::project_s_msgs::Trajectory const> TrajectoryConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project_s_msgs::Trajectory_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project_s_msgs::Trajectory_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::project_s_msgs::Trajectory_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::Trajectory_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::Trajectory_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::Trajectory_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::Trajectory_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::Trajectory_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project_s_msgs::Trajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1841594a837a63ee15ae7b9c6f1d2f4c";
  }

  static const char* value(const ::project_s_msgs::Trajectory_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1841594a837a63eeULL;
  static const uint64_t static_value2 = 0x15ae7b9c6f1d2f4cULL;
};

template<class ContainerAllocator>
struct DataType< ::project_s_msgs::Trajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project_s_msgs/Trajectory";
  }

  static const char* value(const ::project_s_msgs::Trajectory_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project_s_msgs::Trajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
std_msgs/UInt8 id\n\
\n\
geometry_msgs/Pose setpointPosition		# setpoint position\n\
geometry_msgs/Twist setpointVelocity		# setpoint speed\n\
std_msgs/Float32 targetLength\n\
std_msgs/Float32 targetSpeed\n\
\n\
project_s_msgs/Line trajectoryLine			#segments array\n\
nav_msgs/Odometry odom\n\
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
MSG: std_msgs/Float32\n\
float32 data\n\
================================================================================\n\
MSG: project_s_msgs/Line\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
uint16 SEGMENT_REPORT_SIZE = 3000\n\
project_s_msgs/Segment[3000] segment\n\
std_msgs/UInt16 QtySegment\n\
std_msgs/Float32 lineClass	# class of the line\n\
std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)\n\
\n\
std_msgs/UInt8 existenceState\n\
std_msgs/Float32 scoreDetection\n\
std_msgs/Float32 nbrDetection\n\
std_msgs/Float32 nbrVisibility\n\
std_msgs/Float32 scorePersistence\n\
std_msgs/Float32 nbrUpdate\n\
std_msgs/Float32 nbrAge\n\
\n\
\n\
\n\
================================================================================\n\
MSG: project_s_msgs/Segment\n\
std_msgs/Float32 length		# length of the segment\n\
std_msgs/Float32 angle		# angle of the segment\n\
geometry_msgs/Point position\n\
geometry_msgs/Twist Velocity\n\
\n\
float32 offset\n\
float64 latitude\n\
float64 longitude\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/UInt16\n\
uint16 data\n\
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

  static const char* value(const ::project_s_msgs::Trajectory_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project_s_msgs::Trajectory_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.setpointPosition);
      stream.next(m.setpointVelocity);
      stream.next(m.targetLength);
      stream.next(m.targetSpeed);
      stream.next(m.trajectoryLine);
      stream.next(m.odom);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Trajectory_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project_s_msgs::Trajectory_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project_s_msgs::Trajectory_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.id);
    s << indent << "setpointPosition: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.setpointPosition);
    s << indent << "setpointVelocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.setpointVelocity);
    s << indent << "targetLength: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.targetLength);
    s << indent << "targetSpeed: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.targetSpeed);
    s << indent << "trajectoryLine: ";
    s << std::endl;
    Printer< ::project_s_msgs::Line_<ContainerAllocator> >::stream(s, indent + "  ", v.trajectoryLine);
    s << indent << "odom: ";
    s << std::endl;
    Printer< ::nav_msgs::Odometry_<ContainerAllocator> >::stream(s, indent + "  ", v.odom);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_S_MSGS_MESSAGE_TRAJECTORY_H
