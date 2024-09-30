// Generated by gencpp from file project_s_msgs/ehLineCoordGeo.msg
// DO NOT EDIT!


#ifndef PROJECT_S_MSGS_MESSAGE_EHLINECOORDGEO_H
#define PROJECT_S_MSGS_MESSAGE_EHLINECOORDGEO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/UInt8.h>
#include <project_s_msgs/ehSpotCoordGeo.h>
#include <std_msgs/UInt32.h>

namespace project_s_msgs
{
template <class ContainerAllocator>
struct ehLineCoordGeo_
{
  typedef ehLineCoordGeo_<ContainerAllocator> Type;

  ehLineCoordGeo_()
    : header()
    , id()
    , ehSpotCoordGeo()
    , NbrSpotCoordGeo()  {
    }
  ehLineCoordGeo_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(_alloc)
    , ehSpotCoordGeo()
    , NbrSpotCoordGeo(_alloc)  {
  (void)_alloc;
      ehSpotCoordGeo.assign( ::project_s_msgs::ehSpotCoordGeo_<ContainerAllocator> (_alloc));
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _id_type;
  _id_type id;

   typedef boost::array< ::project_s_msgs::ehSpotCoordGeo_<ContainerAllocator> , 3000>  _ehSpotCoordGeo_type;
  _ehSpotCoordGeo_type ehSpotCoordGeo;

   typedef  ::std_msgs::UInt32_<ContainerAllocator>  _NbrSpotCoordGeo_type;
  _NbrSpotCoordGeo_type NbrSpotCoordGeo;



  enum {
    SPOT_REPORT_SIZE = 3000u,
  };


  typedef boost::shared_ptr< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> const> ConstPtr;

}; // struct ehLineCoordGeo_

typedef ::project_s_msgs::ehLineCoordGeo_<std::allocator<void> > ehLineCoordGeo;

typedef boost::shared_ptr< ::project_s_msgs::ehLineCoordGeo > ehLineCoordGeoPtr;
typedef boost::shared_ptr< ::project_s_msgs::ehLineCoordGeo const> ehLineCoordGeoConstPtr;

// constants requiring out of line definition

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ead25328a4cdf8f2b075ecd4258a79fb";
  }

  static const char* value(const ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xead25328a4cdf8f2ULL;
  static const uint64_t static_value2 = 0xb075ecd4258a79fbULL;
};

template<class ContainerAllocator>
struct DataType< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project_s_msgs/ehLineCoordGeo";
  }

  static const char* value(const ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
std_msgs/UInt8 id\n\
\n\
uint32 SPOT_REPORT_SIZE = 3000\n\
project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo\n\
std_msgs/UInt32 NbrSpotCoordGeo\n\
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
MSG: std_msgs/Float32\n\
float32 data\n\
================================================================================\n\
MSG: std_msgs/UInt32\n\
uint32 data\n\
";
  }

  static const char* value(const ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.ehSpotCoordGeo);
      stream.next(m.NbrSpotCoordGeo);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ehLineCoordGeo_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project_s_msgs::ehLineCoordGeo_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.id);
    s << indent << "ehSpotCoordGeo[]" << std::endl;
    for (size_t i = 0; i < v.ehSpotCoordGeo.size(); ++i)
    {
      s << indent << "  ehSpotCoordGeo[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::ehSpotCoordGeo_<ContainerAllocator> >::stream(s, indent + "    ", v.ehSpotCoordGeo[i]);
    }
    s << indent << "NbrSpotCoordGeo: ";
    s << std::endl;
    Printer< ::std_msgs::UInt32_<ContainerAllocator> >::stream(s, indent + "  ", v.NbrSpotCoordGeo);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_S_MSGS_MESSAGE_EHLINECOORDGEO_H
