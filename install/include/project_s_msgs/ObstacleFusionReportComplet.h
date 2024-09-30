// Generated by gencpp from file project_s_msgs/ObstacleFusionReportComplet.msg
// DO NOT EDIT!


#ifndef PROJECT_S_MSGS_MESSAGE_OBSTACLEFUSIONREPORTCOMPLET_H
#define PROJECT_S_MSGS_MESSAGE_OBSTACLEFUSIONREPORTCOMPLET_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/UInt8.h>
#include <project_s_msgs/ObstacleFusionReport.h>
#include <project_s_msgs/ObstacleFusionReport.h>
#include <project_s_msgs/ObstacleFusionReport.h>

namespace project_s_msgs
{
template <class ContainerAllocator>
struct ObstacleFusionReportComplet_
{
  typedef ObstacleFusionReportComplet_<ContainerAllocator> Type;

  ObstacleFusionReportComplet_()
    : header()
    , id()
    , reportObstacleFusionGlobale()
    , reportObstacleFusion()
    , predictionPisteGlobale()  {
    }
  ObstacleFusionReportComplet_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(_alloc)
    , reportObstacleFusionGlobale(_alloc)
    , reportObstacleFusion(_alloc)
    , predictionPisteGlobale(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _id_type;
  _id_type id;

   typedef  ::project_s_msgs::ObstacleFusionReport_<ContainerAllocator>  _reportObstacleFusionGlobale_type;
  _reportObstacleFusionGlobale_type reportObstacleFusionGlobale;

   typedef  ::project_s_msgs::ObstacleFusionReport_<ContainerAllocator>  _reportObstacleFusion_type;
  _reportObstacleFusion_type reportObstacleFusion;

   typedef  ::project_s_msgs::ObstacleFusionReport_<ContainerAllocator>  _predictionPisteGlobale_type;
  _predictionPisteGlobale_type predictionPisteGlobale;





  typedef boost::shared_ptr< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> const> ConstPtr;

}; // struct ObstacleFusionReportComplet_

typedef ::project_s_msgs::ObstacleFusionReportComplet_<std::allocator<void> > ObstacleFusionReportComplet;

typedef boost::shared_ptr< ::project_s_msgs::ObstacleFusionReportComplet > ObstacleFusionReportCompletPtr;
typedef boost::shared_ptr< ::project_s_msgs::ObstacleFusionReportComplet const> ObstacleFusionReportCompletConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "188bbeb788eb767b2b450aba68ba2cb1";
  }

  static const char* value(const ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x188bbeb788eb767bULL;
  static const uint64_t static_value2 = 0x2b450aba68ba2cb1ULL;
};

template<class ContainerAllocator>
struct DataType< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project_s_msgs/ObstacleFusionReportComplet";
  }

  static const char* value(const ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
std_msgs/UInt8 id\n\
\n\
project_s_msgs/ObstacleFusionReport reportObstacleFusionGlobale\n\
project_s_msgs/ObstacleFusionReport reportObstacleFusion\n\
project_s_msgs/ObstacleFusionReport predictionPisteGlobale\n\
\n\
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
MSG: project_s_msgs/ObstacleFusionReport\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
uint8 OBSTACLE_FUSION_REPORT_SIZE = 127\n\
project_s_msgs/ObstacleFusion[127] ObstacleFusion\n\
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
MSG: project_s_msgs/ObstacleFusion\n\
Header header\n\
std_msgs/UInt8 id\n\
\n\
geometry_msgs/Pose obstaclePosition		# obstacle position\n\
geometry_msgs/Pose obstacleBodyCenter	        # Obstacle Center for Corner Computation\n\
float32 distanceCurviligne\n\
std_msgs/Float32 groundHeight			# ground height\n\
geometry_msgs/Twist obstacleVelocity		# obstacle speed\n\
geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration\n\
geometry_msgs/Vector3 obstacleCap\n\
std_msgs/UInt8 existenceProbability\n\
std_msgs/UInt8 existenceState\n\
uint8 IDLE_TRACK    = 0\n\
uint8 PRE_TRACK	    = 1\n\
uint8 POST_TRACK    = 2\n\
uint8 CURRENT_TRACK = 3\n\
std_msgs/Float32 scoreDetection\n\
std_msgs/Float32 nbrDetection\n\
std_msgs/Float32 nbrVisibility\n\
std_msgs/Float32 scorePersistence\n\
std_msgs/Float32 nbrUpdate\n\
std_msgs/Float32 nbrAge\n\
time existenceFirstTime\n\
std_msgs/Float32 existenceDurationTime\n\
std_msgs/UInt8 anchorPoint			# reference point\n\
geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance\n\
geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance\n\
geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height\n\
uint8 obstacleClass\n\
uint8 vision_only_sign_type\n\
std_msgs/UInt8 classificationProbability\n\
\n\
uint8 obstacleAssignment\n\
uint8 ASSIGNMENT_COTE_DROIT  = 1\n\
uint8 ASSIGNMENT_COTE_GAUCHE = 2\n\
\n\
uint8 CORNER_FRONT_RIGHT= 0\n\
uint8 CORNER_FRONT_LEFT = 1\n\
uint8 CORNER_BACK_RIGHT = 2\n\
uint8 CORNER_BACK_LEFT  = 3\n\
geometry_msgs/Point[4] obstacleCorner\n\
\n\
uint8 OCCUPIED_LANE_INDEFINI  = 255\n\
uint8 NbrOccupiedLane\n\
uint8 INDEX_LINE_INDEFINI  = 255\n\
uint8[2] indexAssignmentLine\n\
std_msgs/Float32 positionLane\n\
std_msgs/Float32 departureRighttDistance\n\
std_msgs/Float32 departureLeftDistance\n\
\n\
std_msgs/Int16 trafficLights\n\
std_msgs/Int16 vehicleLights\n\
std_msgs/UInt16[3] idPiste			#define NBR_SENSOR		3	(voir obstacles_fusion.cpp)\n\
\n\
# History\n\
\n\
\n\
\n\
\n\
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
MSG: std_msgs/Float32\n\
float32 data\n\
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
MSG: std_msgs/Int16\n\
int16 data\n\
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

  static const char* value(const ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.reportObstacleFusionGlobale);
      stream.next(m.reportObstacleFusion);
      stream.next(m.predictionPisteGlobale);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ObstacleFusionReportComplet_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project_s_msgs::ObstacleFusionReportComplet_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.id);
    s << indent << "reportObstacleFusionGlobale: ";
    s << std::endl;
    Printer< ::project_s_msgs::ObstacleFusionReport_<ContainerAllocator> >::stream(s, indent + "  ", v.reportObstacleFusionGlobale);
    s << indent << "reportObstacleFusion: ";
    s << std::endl;
    Printer< ::project_s_msgs::ObstacleFusionReport_<ContainerAllocator> >::stream(s, indent + "  ", v.reportObstacleFusion);
    s << indent << "predictionPisteGlobale: ";
    s << std::endl;
    Printer< ::project_s_msgs::ObstacleFusionReport_<ContainerAllocator> >::stream(s, indent + "  ", v.predictionPisteGlobale);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_S_MSGS_MESSAGE_OBSTACLEFUSIONREPORTCOMPLET_H
