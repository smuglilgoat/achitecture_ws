// Generated by gencpp from file project_s_msgs/speed_limit.msg
// DO NOT EDIT!


#ifndef PROJECT_S_MSGS_MESSAGE_SPEED_LIMIT_H
#define PROJECT_S_MSGS_MESSAGE_SPEED_LIMIT_H


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
struct speed_limit_
{
  typedef speed_limit_<ContainerAllocator> Type;

  speed_limit_()
    : offset(0.0)
    , effectiveSpeedLimit(0)  {
    }
  speed_limit_(const ContainerAllocator& _alloc)
    : offset(0.0)
    , effectiveSpeedLimit(0)  {
  (void)_alloc;
    }



   typedef float _offset_type;
  _offset_type offset;

   typedef uint8_t _effectiveSpeedLimit_type;
  _effectiveSpeedLimit_type effectiveSpeedLimit;





  typedef boost::shared_ptr< ::project_s_msgs::speed_limit_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project_s_msgs::speed_limit_<ContainerAllocator> const> ConstPtr;

}; // struct speed_limit_

typedef ::project_s_msgs::speed_limit_<std::allocator<void> > speed_limit;

typedef boost::shared_ptr< ::project_s_msgs::speed_limit > speed_limitPtr;
typedef boost::shared_ptr< ::project_s_msgs::speed_limit const> speed_limitConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project_s_msgs::speed_limit_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project_s_msgs::speed_limit_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::project_s_msgs::speed_limit_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::speed_limit_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::speed_limit_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::speed_limit_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::speed_limit_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::speed_limit_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project_s_msgs::speed_limit_<ContainerAllocator> >
{
  static const char* value()
  {
    return "56f584c5e8b035f849b17a33fc0e3dfd";
  }

  static const char* value(const ::project_s_msgs::speed_limit_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x56f584c5e8b035f8ULL;
  static const uint64_t static_value2 = 0x49b17a33fc0e3dfdULL;
};

template<class ContainerAllocator>
struct DataType< ::project_s_msgs::speed_limit_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project_s_msgs/speed_limit";
  }

  static const char* value(const ::project_s_msgs::speed_limit_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project_s_msgs::speed_limit_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 offset\n\
uint8 effectiveSpeedLimit\n\
\n\
";
  }

  static const char* value(const ::project_s_msgs::speed_limit_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project_s_msgs::speed_limit_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.offset);
      stream.next(m.effectiveSpeedLimit);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct speed_limit_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project_s_msgs::speed_limit_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project_s_msgs::speed_limit_<ContainerAllocator>& v)
  {
    s << indent << "offset: ";
    Printer<float>::stream(s, indent + "  ", v.offset);
    s << indent << "effectiveSpeedLimit: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.effectiveSpeedLimit);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_S_MSGS_MESSAGE_SPEED_LIMIT_H
