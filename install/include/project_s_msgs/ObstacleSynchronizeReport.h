// Generated by gencpp from file project_s_msgs/ObstacleSynchronizeReport.msg
// DO NOT EDIT!


#ifndef PROJECT_S_MSGS_MESSAGE_OBSTACLESYNCHRONIZEREPORT_H
#define PROJECT_S_MSGS_MESSAGE_OBSTACLESYNCHRONIZEREPORT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/UInt8.h>
#include <nav_msgs/Odometry.h>
#include <project_s_msgs/ObstacleAlignmentReport.h>

namespace project_s_msgs
{
template <class ContainerAllocator>
struct ObstacleSynchronizeReport_
{
  typedef ObstacleSynchronizeReport_<ContainerAllocator> Type;

  ObstacleSynchronizeReport_()
    : header()
    , id()
    , odom()
    , ObstacleSynchronizeReport()  {
    }
  ObstacleSynchronizeReport_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(_alloc)
    , odom(_alloc)
    , ObstacleSynchronizeReport()  {
  (void)_alloc;
      ObstacleSynchronizeReport.assign( ::project_s_msgs::ObstacleAlignmentReport_<ContainerAllocator> (_alloc));
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _id_type;
  _id_type id;

   typedef  ::nav_msgs::Odometry_<ContainerAllocator>  _odom_type;
  _odom_type odom;

   typedef boost::array< ::project_s_msgs::ObstacleAlignmentReport_<ContainerAllocator> , 3>  _ObstacleSynchronizeReport_type;
  _ObstacleSynchronizeReport_type ObstacleSynchronizeReport;





  typedef boost::shared_ptr< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> const> ConstPtr;

}; // struct ObstacleSynchronizeReport_

typedef ::project_s_msgs::ObstacleSynchronizeReport_<std::allocator<void> > ObstacleSynchronizeReport;

typedef boost::shared_ptr< ::project_s_msgs::ObstacleSynchronizeReport > ObstacleSynchronizeReportPtr;
typedef boost::shared_ptr< ::project_s_msgs::ObstacleSynchronizeReport const> ObstacleSynchronizeReportConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3e9ce45d4866adcea89f387b227a2abd";
  }

  static const char* value(const ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3e9ce45d4866adceULL;
  static const uint64_t static_value2 = 0xa89f387b227a2abdULL;
};

template<class ContainerAllocator>
struct DataType< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project_s_msgs/ObstacleSynchronizeReport";
  }

  static const char* value(const ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
std_msgs/UInt8 id\n\
nav_msgs/Odometry odom\n\
\n\
project_s_msgs/ObstacleAlignmentReport[3] ObstacleSynchronizeReport	# en concordance avec #define NBR_SENSOR de obstacles_fusion/local_tracks_synchro.cpp\n\
\n\
# History\n\
\n\
\n\
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
================================================================================\n\
MSG: project_s_msgs/ObstacleAlignmentReport\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
uint8 OBSTACLE_ALIGNMENT_REPORT_SIZE = 127\n\
project_s_msgs/ObstacleAlignment[127] ObstacleAlignement\n\
std_msgs/UInt8 QtyObstacles\n\
nav_msgs/Odometry odom\n\
\n\
# History\n\
\n\
\n\
\n\
\n\
\n\
================================================================================\n\
MSG: project_s_msgs/ObstacleAlignment\n\
Header header\n\
std_msgs/UInt16 id\n\
\n\
geometry_msgs/Pose obstaclePosition	        		# obstacle position\n\
float64 obstaclePosition_linear_Unknown = 999\n\
float64 obstaclePosition_orientation_Unknown = 999\n\
\n\
geometry_msgs/Pose obstacleBodyCenter	        		# Obstacle Center for Corner Computation\n\
\n\
geometry_msgs/Twist obstacleVelocity	                    	# obstacle speed\n\
float64 obstacleVelocity_linear_Unknown = 999\n\
float64 obstacleVelocity_angular_Unknown = 999\n\
\n\
geometry_msgs/Twist obstacleRelativeVelocity	           	# obstacle relative velocity\n\
float64 obstacleRelativeVelocity_linear_Unknown = 999\n\
float64 obstacleRelativeVelocity_angular_Unknown = 999\n\
\n\
geometry_msgs/Accel obstacleAcceleration        		# obstacle acceleration\n\
float64 obstacleAcceleration_linear_Unknown = 999\n\
float64 obstacleAcceleration_angular_Unknown = 999\n\
\n\
geometry_msgs/Vector3 obstacleDimensions        		# obstacle - length and width\n\
float64 obstacleDimensions_Unknown = 999\n\
\n\
uint8 blinkerInfo                               		# blinker status (eg. left blinker on)\n\
uint8 blinkerInfo_Unknown=0\n\
\n\
uint8 cutInAndOut                               		# Vehicle cutting in or out of ego lane \n\
uint8 cutInAndOut_Unknown=0\n\
\n\
uint8 obstacleType                             			# obstacle classification\n\
uint8 obstacleType_Unknown=7\n\
\n\
uint8 obstacleStatus                            		# obstacle’s moving status\n\
uint8 obstacleStatus_Unknown=0\n\
\n\
bool obstacleBrakeLights                        		# obstacle brake light on or off\n\
bool obstacleBrakeLights_Unknown=0 \n\
\n\
int8 cipvFlag                                   		# If obstacle Closest in Path Vehicle\n\
int8 cipvFlag_Unknown=2\n\
\n\
int8 obstacleReplaced                           		# If obstacle replaced in this frame\n\
int8 obstacleReplaced_Unknown=2\n\
\n\
uint8 obstacleValid                             		# obstacle valid\n\
uint8 obstacleValid_Unknown=3\n\
\n\
uint16 obstacleAge                              		# obstacle age in number of frames\n\
uint16 obstacleAge_Unknown=256\n\
\n\
uint8 obstacleLane                              		# obstacle's lane (eg. ego lane or next lane)\n\
uint8 obstacleLane_Unknown=0\n\
\n\
float32 obstacleAngle                           		# angle to center of obstacle in degrees\n\
float32 obstacleAngle_Unknown = 999\n\
\n\
float32 obstacleAngleVariance                   		# Obstacle angle Variance (Lidar)\n\
float32 obstacleAngleVariance_Unknown=-1\n\
\n\
float32 obstacleAngleRate                       		# angle rate of the center of obstacle (degrees/sec)\n\
float32 obstacleAngleRate_Unknown = 999\n\
\n\
float64 obstacleScaleChange                     		# scale change from previous frame   \n\
float64 obstacleScaleChange_Unknown = 999\n\
                           \n\
uint8 vision_only_sign_type\n\
#uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type\n\
uint8 visionOnlySignType_Unknown=254\n\
\n\
uint8 visionOnlySupplementarySignType               		# Supplementary sign type - rain, snow, arrow etc. \n\
uint8 visionOnlySupplementarySignType_Unknown=0\n\
\n\
geometry_msgs/Vector3 signPosition                  		# X-Longitudnal position, Y-Lateral position ,Z-Height of sign relative to ME\n\
float64 signPosition_Unknown = 999\n\
\n\
float64 filterType                                    		# filtering \n\
float64 filterType_Unknown = 999\n\
\n\
geometry_msgs/Pose obstaclePoseVariance		                # obstacle position variance\n\
float64 obstaclePoseVariance_position_Unknown = -1\n\
float64 obstaclePoseVariance_orientation_Unknown = -1\n\
\n\
geometry_msgs/Twist obstacleVelocityVariance	                # obstacle speed variance\n\
float64 obstacleVelocityVariance_linear_Unknown = -1\n\
float64 obstacleVelocityVariance_angular_Unknown = -1\n\
\n\
geometry_msgs/Twist obstacleRelativeVelocityVariance	        # obstacle relative velocity variance\n\
float64 obstacleRelativeVelocityVariance_linear_Unknown = -1\n\
float64 obstacleRelativeVelocityVariance_angular_Unknown = -1\n\
\n\
std_msgs/Float32 groundHeight			                # ground height\n\
float64 groundHeight_Unknown = 999\n\
\n\
float64 classificationProbability\n\
float64 classificationProbability_Unknown = 999\n\
\n\
std_msgs/Float64 dateAcquisition\n\
float64 dateAcquisition_Unknown = 999\n\
\n\
uint8 obstacleClass\n\
\n\
# History\n\
\n\
\n\
\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/UInt16\n\
uint16 data\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Accel\n\
# This expresses acceleration in free space broken into its linear and angular parts.\n\
Vector3  linear\n\
Vector3  angular\n\
\n\
================================================================================\n\
MSG: std_msgs/Float32\n\
float32 data\n\
================================================================================\n\
MSG: std_msgs/Float64\n\
float64 data\n\
";
  }

  static const char* value(const ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.odom);
      stream.next(m.ObstacleSynchronizeReport);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ObstacleSynchronizeReport_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project_s_msgs::ObstacleSynchronizeReport_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.id);
    s << indent << "odom: ";
    s << std::endl;
    Printer< ::nav_msgs::Odometry_<ContainerAllocator> >::stream(s, indent + "  ", v.odom);
    s << indent << "ObstacleSynchronizeReport[]" << std::endl;
    for (size_t i = 0; i < v.ObstacleSynchronizeReport.size(); ++i)
    {
      s << indent << "  ObstacleSynchronizeReport[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::ObstacleAlignmentReport_<ContainerAllocator> >::stream(s, indent + "    ", v.ObstacleSynchronizeReport[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_S_MSGS_MESSAGE_OBSTACLESYNCHRONIZEREPORT_H
