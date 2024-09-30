// Generated by gencpp from file project_s_msgs/RoutePlanning.msg
// DO NOT EDIT!


#ifndef PROJECT_S_MSGS_MESSAGE_ROUTEPLANNING_H
#define PROJECT_S_MSGS_MESSAGE_ROUTEPLANNING_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/UInt8.h>
#include <project_s_msgs/Segment.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/UInt8.h>
#include <project_s_msgs/point_GPS.h>
#include <project_s_msgs/point_GPS.h>
#include <project_s_msgs/point_GPS.h>
#include <project_s_msgs/point_GPS.h>
#include <project_s_msgs/point_GPS.h>
#include <project_s_msgs/speed_limit.h>
#include <project_s_msgs/curvature.h>
#include <project_s_msgs/traffic_sign.h>
#include <project_s_msgs/segmentME.h>
#include <project_s_msgs/segmentME.h>

namespace project_s_msgs
{
template <class ContainerAllocator>
struct RoutePlanning_
{
  typedef RoutePlanning_<ContainerAllocator> Type;

  RoutePlanning_()
    : header()
    , id()
    , roadSegment()
    , nbrLane()
    , intersection()
    , list_Links_ID()
    , list_Links_HEREtile_ID()
    , list_Nodes_ID()
    , list_Nodes_HEREtile_ID()
    , list_Links_vs_Route_direction()
    , LIST_LINKS_SIZE(0)
    , NBRE_POINT_CIRCUIT_GPS(0)
    , NBRE_POINT_TABLEAU_GPS(0)
    , Tableau_circuit_GPS()
    , Tableau_circuit_GPS_gauche()
    , Tableau_circuit_GPS_droite()
    , Tableau_circuit_GPS_MEgauche()
    , Tableau_circuit_GPS_MEdroite()
    , Tableau_circuit_speedlimit()
    , Tableau_circuit_curvature()
    , Tableau_circuit_trafficsign()
    , Tableau_circuit_ehSegmentAO()
    , Tableau_circuit_ehSegmentEO()  {
    }
  RoutePlanning_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(_alloc)
    , roadSegment(_alloc)
    , nbrLane(_alloc)
    , intersection(_alloc)
    , list_Links_ID(_alloc)
    , list_Links_HEREtile_ID(_alloc)
    , list_Nodes_ID(_alloc)
    , list_Nodes_HEREtile_ID(_alloc)
    , list_Links_vs_Route_direction(_alloc)
    , LIST_LINKS_SIZE(0)
    , NBRE_POINT_CIRCUIT_GPS(0)
    , NBRE_POINT_TABLEAU_GPS(0)
    , Tableau_circuit_GPS(_alloc)
    , Tableau_circuit_GPS_gauche(_alloc)
    , Tableau_circuit_GPS_droite(_alloc)
    , Tableau_circuit_GPS_MEgauche(_alloc)
    , Tableau_circuit_GPS_MEdroite(_alloc)
    , Tableau_circuit_speedlimit(_alloc)
    , Tableau_circuit_curvature(_alloc)
    , Tableau_circuit_trafficsign(_alloc)
    , Tableau_circuit_ehSegmentAO(_alloc)
    , Tableau_circuit_ehSegmentEO(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _id_type;
  _id_type id;

   typedef std::vector< ::project_s_msgs::Segment_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::project_s_msgs::Segment_<ContainerAllocator> >::other >  _roadSegment_type;
  _roadSegment_type roadSegment;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _nbrLane_type;
  _nbrLane_type nbrLane;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _intersection_type;
  _intersection_type intersection;

   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _list_Links_ID_type;
  _list_Links_ID_type list_Links_ID;

   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _list_Links_HEREtile_ID_type;
  _list_Links_HEREtile_ID_type list_Links_HEREtile_ID;

   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _list_Nodes_ID_type;
  _list_Nodes_ID_type list_Nodes_ID;

   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _list_Nodes_HEREtile_ID_type;
  _list_Nodes_HEREtile_ID_type list_Nodes_HEREtile_ID;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _list_Links_vs_Route_direction_type;
  _list_Links_vs_Route_direction_type list_Links_vs_Route_direction;

   typedef uint32_t _LIST_LINKS_SIZE_type;
  _LIST_LINKS_SIZE_type LIST_LINKS_SIZE;

   typedef uint32_t _NBRE_POINT_CIRCUIT_GPS_type;
  _NBRE_POINT_CIRCUIT_GPS_type NBRE_POINT_CIRCUIT_GPS;

   typedef uint32_t _NBRE_POINT_TABLEAU_GPS_type;
  _NBRE_POINT_TABLEAU_GPS_type NBRE_POINT_TABLEAU_GPS;

   typedef std::vector< ::project_s_msgs::point_GPS_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::project_s_msgs::point_GPS_<ContainerAllocator> >::other >  _Tableau_circuit_GPS_type;
  _Tableau_circuit_GPS_type Tableau_circuit_GPS;

   typedef std::vector< ::project_s_msgs::point_GPS_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::project_s_msgs::point_GPS_<ContainerAllocator> >::other >  _Tableau_circuit_GPS_gauche_type;
  _Tableau_circuit_GPS_gauche_type Tableau_circuit_GPS_gauche;

   typedef std::vector< ::project_s_msgs::point_GPS_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::project_s_msgs::point_GPS_<ContainerAllocator> >::other >  _Tableau_circuit_GPS_droite_type;
  _Tableau_circuit_GPS_droite_type Tableau_circuit_GPS_droite;

   typedef std::vector< ::project_s_msgs::point_GPS_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::project_s_msgs::point_GPS_<ContainerAllocator> >::other >  _Tableau_circuit_GPS_MEgauche_type;
  _Tableau_circuit_GPS_MEgauche_type Tableau_circuit_GPS_MEgauche;

   typedef std::vector< ::project_s_msgs::point_GPS_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::project_s_msgs::point_GPS_<ContainerAllocator> >::other >  _Tableau_circuit_GPS_MEdroite_type;
  _Tableau_circuit_GPS_MEdroite_type Tableau_circuit_GPS_MEdroite;

   typedef std::vector< ::project_s_msgs::speed_limit_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::project_s_msgs::speed_limit_<ContainerAllocator> >::other >  _Tableau_circuit_speedlimit_type;
  _Tableau_circuit_speedlimit_type Tableau_circuit_speedlimit;

   typedef std::vector< ::project_s_msgs::curvature_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::project_s_msgs::curvature_<ContainerAllocator> >::other >  _Tableau_circuit_curvature_type;
  _Tableau_circuit_curvature_type Tableau_circuit_curvature;

   typedef std::vector< ::project_s_msgs::traffic_sign_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::project_s_msgs::traffic_sign_<ContainerAllocator> >::other >  _Tableau_circuit_trafficsign_type;
  _Tableau_circuit_trafficsign_type Tableau_circuit_trafficsign;

   typedef std::vector< ::project_s_msgs::segmentME_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::project_s_msgs::segmentME_<ContainerAllocator> >::other >  _Tableau_circuit_ehSegmentAO_type;
  _Tableau_circuit_ehSegmentAO_type Tableau_circuit_ehSegmentAO;

   typedef std::vector< ::project_s_msgs::segmentME_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::project_s_msgs::segmentME_<ContainerAllocator> >::other >  _Tableau_circuit_ehSegmentEO_type;
  _Tableau_circuit_ehSegmentEO_type Tableau_circuit_ehSegmentEO;





  typedef boost::shared_ptr< ::project_s_msgs::RoutePlanning_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project_s_msgs::RoutePlanning_<ContainerAllocator> const> ConstPtr;

}; // struct RoutePlanning_

typedef ::project_s_msgs::RoutePlanning_<std::allocator<void> > RoutePlanning;

typedef boost::shared_ptr< ::project_s_msgs::RoutePlanning > RoutePlanningPtr;
typedef boost::shared_ptr< ::project_s_msgs::RoutePlanning const> RoutePlanningConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project_s_msgs::RoutePlanning_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project_s_msgs::RoutePlanning_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::project_s_msgs::RoutePlanning_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::RoutePlanning_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::RoutePlanning_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::RoutePlanning_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::RoutePlanning_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::RoutePlanning_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project_s_msgs::RoutePlanning_<ContainerAllocator> >
{
  static const char* value()
  {
    return "686ce86a53e3fc605337589df78e8395";
  }

  static const char* value(const ::project_s_msgs::RoutePlanning_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x686ce86a53e3fc60ULL;
  static const uint64_t static_value2 = 0x5337589df78e8395ULL;
};

template<class ContainerAllocator>
struct DataType< ::project_s_msgs::RoutePlanning_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project_s_msgs/RoutePlanning";
  }

  static const char* value(const ::project_s_msgs::RoutePlanning_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project_s_msgs::RoutePlanning_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
std_msgs/UInt8 id\n\
\n\
project_s_msgs/Segment[] roadSegment		#segments array   \n\
std_msgs/UInt8 nbrLane\n\
std_msgs/UInt8 intersection\n\
\n\
uint32[] list_Links_ID\n\
uint32[] list_Links_HEREtile_ID\n\
uint32[] list_Nodes_ID\n\
uint32[] list_Nodes_HEREtile_ID\n\
bool[] list_Links_vs_Route_direction\n\
uint32 LIST_LINKS_SIZE\n\
\n\
uint32 NBRE_POINT_CIRCUIT_GPS\n\
uint32 NBRE_POINT_TABLEAU_GPS\n\
\n\
project_s_msgs/point_GPS[]   Tableau_circuit_GPS\n\
project_s_msgs/point_GPS[]   Tableau_circuit_GPS_gauche\n\
project_s_msgs/point_GPS[]   Tableau_circuit_GPS_droite\n\
\n\
project_s_msgs/point_GPS[]   Tableau_circuit_GPS_MEgauche\n\
project_s_msgs/point_GPS[]   Tableau_circuit_GPS_MEdroite\n\
\n\
project_s_msgs/speed_limit[] Tableau_circuit_speedlimit\n\
project_s_msgs/curvature[]   Tableau_circuit_curvature\n\
project_s_msgs/traffic_sign[]   Tableau_circuit_trafficsign\n\
\n\
\n\
project_s_msgs/segmentME[] Tableau_circuit_ehSegmentAO\n\
project_s_msgs/segmentME[] Tableau_circuit_ehSegmentEO\n\
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
MSG: std_msgs/Float32\n\
float32 data\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
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
MSG: project_s_msgs/point_GPS\n\
float64 latitude\n\
float64 longitude\n\
float32 offset\n\
\n\
\n\
================================================================================\n\
MSG: project_s_msgs/speed_limit\n\
float32 offset\n\
uint8 effectiveSpeedLimit\n\
\n\
\n\
================================================================================\n\
MSG: project_s_msgs/curvature\n\
float32 offset\n\
float32 value\n\
\n\
================================================================================\n\
MSG: project_s_msgs/traffic_sign\n\
float32 offset\n\
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
MSG: project_s_msgs/segmentME\n\
uint32 NbrSpot\n\
float32 offset_debut\n\
float32 offset_fin\n\
\n\
\n\
";
  }

  static const char* value(const ::project_s_msgs::RoutePlanning_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project_s_msgs::RoutePlanning_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.roadSegment);
      stream.next(m.nbrLane);
      stream.next(m.intersection);
      stream.next(m.list_Links_ID);
      stream.next(m.list_Links_HEREtile_ID);
      stream.next(m.list_Nodes_ID);
      stream.next(m.list_Nodes_HEREtile_ID);
      stream.next(m.list_Links_vs_Route_direction);
      stream.next(m.LIST_LINKS_SIZE);
      stream.next(m.NBRE_POINT_CIRCUIT_GPS);
      stream.next(m.NBRE_POINT_TABLEAU_GPS);
      stream.next(m.Tableau_circuit_GPS);
      stream.next(m.Tableau_circuit_GPS_gauche);
      stream.next(m.Tableau_circuit_GPS_droite);
      stream.next(m.Tableau_circuit_GPS_MEgauche);
      stream.next(m.Tableau_circuit_GPS_MEdroite);
      stream.next(m.Tableau_circuit_speedlimit);
      stream.next(m.Tableau_circuit_curvature);
      stream.next(m.Tableau_circuit_trafficsign);
      stream.next(m.Tableau_circuit_ehSegmentAO);
      stream.next(m.Tableau_circuit_ehSegmentEO);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RoutePlanning_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project_s_msgs::RoutePlanning_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project_s_msgs::RoutePlanning_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.id);
    s << indent << "roadSegment[]" << std::endl;
    for (size_t i = 0; i < v.roadSegment.size(); ++i)
    {
      s << indent << "  roadSegment[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::Segment_<ContainerAllocator> >::stream(s, indent + "    ", v.roadSegment[i]);
    }
    s << indent << "nbrLane: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.nbrLane);
    s << indent << "intersection: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.intersection);
    s << indent << "list_Links_ID[]" << std::endl;
    for (size_t i = 0; i < v.list_Links_ID.size(); ++i)
    {
      s << indent << "  list_Links_ID[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.list_Links_ID[i]);
    }
    s << indent << "list_Links_HEREtile_ID[]" << std::endl;
    for (size_t i = 0; i < v.list_Links_HEREtile_ID.size(); ++i)
    {
      s << indent << "  list_Links_HEREtile_ID[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.list_Links_HEREtile_ID[i]);
    }
    s << indent << "list_Nodes_ID[]" << std::endl;
    for (size_t i = 0; i < v.list_Nodes_ID.size(); ++i)
    {
      s << indent << "  list_Nodes_ID[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.list_Nodes_ID[i]);
    }
    s << indent << "list_Nodes_HEREtile_ID[]" << std::endl;
    for (size_t i = 0; i < v.list_Nodes_HEREtile_ID.size(); ++i)
    {
      s << indent << "  list_Nodes_HEREtile_ID[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.list_Nodes_HEREtile_ID[i]);
    }
    s << indent << "list_Links_vs_Route_direction[]" << std::endl;
    for (size_t i = 0; i < v.list_Links_vs_Route_direction.size(); ++i)
    {
      s << indent << "  list_Links_vs_Route_direction[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.list_Links_vs_Route_direction[i]);
    }
    s << indent << "LIST_LINKS_SIZE: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.LIST_LINKS_SIZE);
    s << indent << "NBRE_POINT_CIRCUIT_GPS: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.NBRE_POINT_CIRCUIT_GPS);
    s << indent << "NBRE_POINT_TABLEAU_GPS: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.NBRE_POINT_TABLEAU_GPS);
    s << indent << "Tableau_circuit_GPS[]" << std::endl;
    for (size_t i = 0; i < v.Tableau_circuit_GPS.size(); ++i)
    {
      s << indent << "  Tableau_circuit_GPS[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::point_GPS_<ContainerAllocator> >::stream(s, indent + "    ", v.Tableau_circuit_GPS[i]);
    }
    s << indent << "Tableau_circuit_GPS_gauche[]" << std::endl;
    for (size_t i = 0; i < v.Tableau_circuit_GPS_gauche.size(); ++i)
    {
      s << indent << "  Tableau_circuit_GPS_gauche[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::point_GPS_<ContainerAllocator> >::stream(s, indent + "    ", v.Tableau_circuit_GPS_gauche[i]);
    }
    s << indent << "Tableau_circuit_GPS_droite[]" << std::endl;
    for (size_t i = 0; i < v.Tableau_circuit_GPS_droite.size(); ++i)
    {
      s << indent << "  Tableau_circuit_GPS_droite[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::point_GPS_<ContainerAllocator> >::stream(s, indent + "    ", v.Tableau_circuit_GPS_droite[i]);
    }
    s << indent << "Tableau_circuit_GPS_MEgauche[]" << std::endl;
    for (size_t i = 0; i < v.Tableau_circuit_GPS_MEgauche.size(); ++i)
    {
      s << indent << "  Tableau_circuit_GPS_MEgauche[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::point_GPS_<ContainerAllocator> >::stream(s, indent + "    ", v.Tableau_circuit_GPS_MEgauche[i]);
    }
    s << indent << "Tableau_circuit_GPS_MEdroite[]" << std::endl;
    for (size_t i = 0; i < v.Tableau_circuit_GPS_MEdroite.size(); ++i)
    {
      s << indent << "  Tableau_circuit_GPS_MEdroite[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::point_GPS_<ContainerAllocator> >::stream(s, indent + "    ", v.Tableau_circuit_GPS_MEdroite[i]);
    }
    s << indent << "Tableau_circuit_speedlimit[]" << std::endl;
    for (size_t i = 0; i < v.Tableau_circuit_speedlimit.size(); ++i)
    {
      s << indent << "  Tableau_circuit_speedlimit[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::speed_limit_<ContainerAllocator> >::stream(s, indent + "    ", v.Tableau_circuit_speedlimit[i]);
    }
    s << indent << "Tableau_circuit_curvature[]" << std::endl;
    for (size_t i = 0; i < v.Tableau_circuit_curvature.size(); ++i)
    {
      s << indent << "  Tableau_circuit_curvature[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::curvature_<ContainerAllocator> >::stream(s, indent + "    ", v.Tableau_circuit_curvature[i]);
    }
    s << indent << "Tableau_circuit_trafficsign[]" << std::endl;
    for (size_t i = 0; i < v.Tableau_circuit_trafficsign.size(); ++i)
    {
      s << indent << "  Tableau_circuit_trafficsign[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::traffic_sign_<ContainerAllocator> >::stream(s, indent + "    ", v.Tableau_circuit_trafficsign[i]);
    }
    s << indent << "Tableau_circuit_ehSegmentAO[]" << std::endl;
    for (size_t i = 0; i < v.Tableau_circuit_ehSegmentAO.size(); ++i)
    {
      s << indent << "  Tableau_circuit_ehSegmentAO[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::segmentME_<ContainerAllocator> >::stream(s, indent + "    ", v.Tableau_circuit_ehSegmentAO[i]);
    }
    s << indent << "Tableau_circuit_ehSegmentEO[]" << std::endl;
    for (size_t i = 0; i < v.Tableau_circuit_ehSegmentEO.size(); ++i)
    {
      s << indent << "  Tableau_circuit_ehSegmentEO[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::segmentME_<ContainerAllocator> >::stream(s, indent + "    ", v.Tableau_circuit_ehSegmentEO[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_S_MSGS_MESSAGE_ROUTEPLANNING_H
