// Generated by gencpp from file message_project_s/ObstacleAlignmentReport_1.msg
// DO NOT EDIT!


#ifndef MESSAGE_PROJECT_S_MESSAGE_OBSTACLEALIGNMENTREPORT_1_H
#define MESSAGE_PROJECT_S_MESSAGE_OBSTACLEALIGNMENTREPORT_1_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/UInt8.h>
#include <message_project_s/ObstacleAlignment_1.h>
#include <std_msgs/UInt8.h>
#include <nav_msgs/Odometry.h>

namespace message_project_s
{
template <class ContainerAllocator>
struct ObstacleAlignmentReport_1_
{
  typedef ObstacleAlignmentReport_1_<ContainerAllocator> Type;

  ObstacleAlignmentReport_1_()
    : header()
    , id()
    , ObstacleAlignement_1()
    , QtyObstacles()
    , odom()  {
    }
  ObstacleAlignmentReport_1_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(_alloc)
    , ObstacleAlignement_1(_alloc)
    , QtyObstacles(_alloc)
    , odom(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _id_type;
  _id_type id;

   typedef std::vector< ::message_project_s::ObstacleAlignment_1_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::message_project_s::ObstacleAlignment_1_<ContainerAllocator> >::other >  _ObstacleAlignement_1_type;
  _ObstacleAlignement_1_type ObstacleAlignement_1;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _QtyObstacles_type;
  _QtyObstacles_type QtyObstacles;

   typedef  ::nav_msgs::Odometry_<ContainerAllocator>  _odom_type;
  _odom_type odom;





  typedef boost::shared_ptr< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> const> ConstPtr;

}; // struct ObstacleAlignmentReport_1_

typedef ::message_project_s::ObstacleAlignmentReport_1_<std::allocator<void> > ObstacleAlignmentReport_1;

typedef boost::shared_ptr< ::message_project_s::ObstacleAlignmentReport_1 > ObstacleAlignmentReport_1Ptr;
typedef boost::shared_ptr< ::message_project_s::ObstacleAlignmentReport_1 const> ObstacleAlignmentReport_1ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace message_project_s

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'shape_msgs': ['/opt/ros/kinetic/share/shape_msgs/cmake/../msg'], 'delphi_srr_msgs': ['/home/dev/as_drivers_customer/install/share/delphi_srr_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/kinetic/share/trajectory_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'delphi_esr_msgs': ['/home/dev/as_drivers_customer/install/share/delphi_esr_msgs/cmake/../msg'], 'message_project_s': ['/home/segula/Desktop/ava/achitecture_ws/src/smart_sensor/message_project_s/msg'], 'radar_msgs': ['/home/dev/as_drivers_customer/install/share/radar_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'mobileye_560_660_msgs': ['/home/dev/as_drivers_customer/install/share/mobileye_560_660_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4857983c7466f8b6a84b30dd769dde24";
  }

  static const char* value(const ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4857983c7466f8b6ULL;
  static const uint64_t static_value2 = 0xa84b30dd769dde24ULL;
};

template<class ContainerAllocator>
struct DataType< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> >
{
  static const char* value()
  {
    return "message_project_s/ObstacleAlignmentReport_1";
  }

  static const char* value(const ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
std_msgs/UInt8 id\n\
\n\
message_project_s/ObstacleAlignment_1[] ObstacleAlignement_1\n\
\n\
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
MSG: message_project_s/ObstacleAlignment_1\n\
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
uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type\n\
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
\n\
# History\n\
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
MSG: std_msgs/Float32\n\
float32 data\n\
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

  static const char* value(const ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.ObstacleAlignement_1);
      stream.next(m.QtyObstacles);
      stream.next(m.odom);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ObstacleAlignmentReport_1_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::message_project_s::ObstacleAlignmentReport_1_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.id);
    s << indent << "ObstacleAlignement_1[]" << std::endl;
    for (size_t i = 0; i < v.ObstacleAlignement_1.size(); ++i)
    {
      s << indent << "  ObstacleAlignement_1[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::message_project_s::ObstacleAlignment_1_<ContainerAllocator> >::stream(s, indent + "    ", v.ObstacleAlignement_1[i]);
    }
    s << indent << "QtyObstacles: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.QtyObstacles);
    s << indent << "odom: ";
    s << std::endl;
    Printer< ::nav_msgs::Odometry_<ContainerAllocator> >::stream(s, indent + "  ", v.odom);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MESSAGE_PROJECT_S_MESSAGE_OBSTACLEALIGNMENTREPORT_1_H
