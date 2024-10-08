// Generated by gencpp from file project_s_msgs/MissionManagerModem.msg
// DO NOT EDIT!


#ifndef PROJECT_S_MSGS_MESSAGE_MISSIONMANAGERMODEM_H
#define PROJECT_S_MSGS_MESSAGE_MISSIONMANAGERMODEM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace project_s_msgs
{
template <class ContainerAllocator>
struct MissionManagerModem_
{
  typedef MissionManagerModem_<ContainerAllocator> Type;

  MissionManagerModem_()
    : stamp()
    , request(0.0)  {
    }
  MissionManagerModem_(const ContainerAllocator& _alloc)
    : stamp()
    , request(0.0)  {
  (void)_alloc;
    }



   typedef ros::Time _stamp_type;
  _stamp_type stamp;

   typedef float _request_type;
  _request_type request;





  typedef boost::shared_ptr< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> const> ConstPtr;

}; // struct MissionManagerModem_

typedef ::project_s_msgs::MissionManagerModem_<std::allocator<void> > MissionManagerModem;

typedef boost::shared_ptr< ::project_s_msgs::MissionManagerModem > MissionManagerModemPtr;
typedef boost::shared_ptr< ::project_s_msgs::MissionManagerModem const> MissionManagerModemConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project_s_msgs::MissionManagerModem_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> >
{
  static const char* value()
  {
    return "37e4d8b8bd95addccb35ddd346779b1f";
  }

  static const char* value(const ::project_s_msgs::MissionManagerModem_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x37e4d8b8bd95addcULL;
  static const uint64_t static_value2 = 0xcb35ddd346779b1fULL;
};

template<class ContainerAllocator>
struct DataType< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project_s_msgs/MissionManagerModem";
  }

  static const char* value(const ::project_s_msgs::MissionManagerModem_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> >
{
  static const char* value()
  {
    return "time stamp\n\
\n\
float32 request\n\
\n\
";
  }

  static const char* value(const ::project_s_msgs::MissionManagerModem_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stamp);
      stream.next(m.request);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MissionManagerModem_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project_s_msgs::MissionManagerModem_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project_s_msgs::MissionManagerModem_<ContainerAllocator>& v)
  {
    s << indent << "stamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.stamp);
    s << indent << "request: ";
    Printer<float>::stream(s, indent + "  ", v.request);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_S_MSGS_MESSAGE_MISSIONMANAGERMODEM_H
