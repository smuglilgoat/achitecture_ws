// Generated by gencpp from file project_s_msgs/ehNbrLineCoordGeo.msg
// DO NOT EDIT!


#ifndef PROJECT_S_MSGS_MESSAGE_EHNBRLINECOORDGEO_H
#define PROJECT_S_MSGS_MESSAGE_EHNBRLINECOORDGEO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/UInt8.h>
#include <std_msgs/Float32.h>

namespace project_s_msgs
{
template <class ContainerAllocator>
struct ehNbrLineCoordGeo_
{
  typedef ehNbrLineCoordGeo_<ContainerAllocator> Type;

  ehNbrLineCoordGeo_()
    : Nbr()
    , offset()  {
    }
  ehNbrLineCoordGeo_(const ContainerAllocator& _alloc)
    : Nbr(_alloc)
    , offset(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _Nbr_type;
  _Nbr_type Nbr;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _offset_type;
  _offset_type offset;





  typedef boost::shared_ptr< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> const> ConstPtr;

}; // struct ehNbrLineCoordGeo_

typedef ::project_s_msgs::ehNbrLineCoordGeo_<std::allocator<void> > ehNbrLineCoordGeo;

typedef boost::shared_ptr< ::project_s_msgs::ehNbrLineCoordGeo > ehNbrLineCoordGeoPtr;
typedef boost::shared_ptr< ::project_s_msgs::ehNbrLineCoordGeo const> ehNbrLineCoordGeoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace project_s_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'shape_msgs': ['/opt/ros/kinetic/share/shape_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/kinetic/share/trajectory_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'project_s_msgs': ['/home/segula/Desktop/ava/achitecture_ws/src/project_s_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'mobileye_560_660_msgs': ['/home/dev/as_drivers_customer/install/share/mobileye_560_660_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ba129a5215116e7dd0de7b78069aec8a";
  }

  static const char* value(const ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xba129a5215116e7dULL;
  static const uint64_t static_value2 = 0xd0de7b78069aec8aULL;
};

template<class ContainerAllocator>
struct DataType< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project_s_msgs/ehNbrLineCoordGeo";
  }

  static const char* value(const ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/UInt8 Nbr\n\
std_msgs/Float32 offset\n\
\n\
\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/UInt8\n\
uint8 data\n\
\n\
================================================================================\n\
MSG: std_msgs/Float32\n\
float32 data\n\
";
  }

  static const char* value(const ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Nbr);
      stream.next(m.offset);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ehNbrLineCoordGeo_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project_s_msgs::ehNbrLineCoordGeo_<ContainerAllocator>& v)
  {
    s << indent << "Nbr: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.Nbr);
    s << indent << "offset: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.offset);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_S_MSGS_MESSAGE_EHNBRLINECOORDGEO_H
