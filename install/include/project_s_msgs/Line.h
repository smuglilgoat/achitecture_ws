// Generated by gencpp from file project_s_msgs/Line.msg
// DO NOT EDIT!


#ifndef PROJECT_S_MSGS_MESSAGE_LINE_H
#define PROJECT_S_MSGS_MESSAGE_LINE_H


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
#include <std_msgs/UInt16.h>
#include <std_msgs/Float32.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32.h>

namespace project_s_msgs
{
template <class ContainerAllocator>
struct Line_
{
  typedef Line_<ContainerAllocator> Type;

  Line_()
    : header()
    , id()
    , segment()
    , QtySegment()
    , lineClass()
    , idPiste()
    , existenceState()
    , scoreDetection()
    , nbrDetection()
    , nbrVisibility()
    , scorePersistence()
    , nbrUpdate()
    , nbrAge()  {
    }
  Line_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(_alloc)
    , segment()
    , QtySegment(_alloc)
    , lineClass(_alloc)
    , idPiste()
    , existenceState(_alloc)
    , scoreDetection(_alloc)
    , nbrDetection(_alloc)
    , nbrVisibility(_alloc)
    , scorePersistence(_alloc)
    , nbrUpdate(_alloc)
    , nbrAge(_alloc)  {
  (void)_alloc;
      segment.assign( ::project_s_msgs::Segment_<ContainerAllocator> (_alloc));

      idPiste.assign( ::std_msgs::UInt16_<ContainerAllocator> (_alloc));
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _id_type;
  _id_type id;

   typedef boost::array< ::project_s_msgs::Segment_<ContainerAllocator> , 3000>  _segment_type;
  _segment_type segment;

   typedef  ::std_msgs::UInt16_<ContainerAllocator>  _QtySegment_type;
  _QtySegment_type QtySegment;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _lineClass_type;
  _lineClass_type lineClass;

   typedef boost::array< ::std_msgs::UInt16_<ContainerAllocator> , 2>  _idPiste_type;
  _idPiste_type idPiste;

   typedef  ::std_msgs::UInt8_<ContainerAllocator>  _existenceState_type;
  _existenceState_type existenceState;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _scoreDetection_type;
  _scoreDetection_type scoreDetection;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _nbrDetection_type;
  _nbrDetection_type nbrDetection;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _nbrVisibility_type;
  _nbrVisibility_type nbrVisibility;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _scorePersistence_type;
  _scorePersistence_type scorePersistence;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _nbrUpdate_type;
  _nbrUpdate_type nbrUpdate;

   typedef  ::std_msgs::Float32_<ContainerAllocator>  _nbrAge_type;
  _nbrAge_type nbrAge;



  enum {
    SEGMENT_REPORT_SIZE = 3000u,
  };


  typedef boost::shared_ptr< ::project_s_msgs::Line_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project_s_msgs::Line_<ContainerAllocator> const> ConstPtr;

}; // struct Line_

typedef ::project_s_msgs::Line_<std::allocator<void> > Line;

typedef boost::shared_ptr< ::project_s_msgs::Line > LinePtr;
typedef boost::shared_ptr< ::project_s_msgs::Line const> LineConstPtr;

// constants requiring out of line definition

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project_s_msgs::Line_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project_s_msgs::Line_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::project_s_msgs::Line_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project_s_msgs::Line_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::Line_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project_s_msgs::Line_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::Line_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project_s_msgs::Line_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project_s_msgs::Line_<ContainerAllocator> >
{
  static const char* value()
  {
    return "76c1d98fd2e545accf02a06698e73bb3";
  }

  static const char* value(const ::project_s_msgs::Line_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x76c1d98fd2e545acULL;
  static const uint64_t static_value2 = 0xcf02a06698e73bb3ULL;
};

template<class ContainerAllocator>
struct DataType< ::project_s_msgs::Line_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project_s_msgs/Line";
  }

  static const char* value(const ::project_s_msgs::Line_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project_s_msgs::Line_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
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
MSG: std_msgs/UInt16\n\
uint16 data\n\
";
  }

  static const char* value(const ::project_s_msgs::Line_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project_s_msgs::Line_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.segment);
      stream.next(m.QtySegment);
      stream.next(m.lineClass);
      stream.next(m.idPiste);
      stream.next(m.existenceState);
      stream.next(m.scoreDetection);
      stream.next(m.nbrDetection);
      stream.next(m.nbrVisibility);
      stream.next(m.scorePersistence);
      stream.next(m.nbrUpdate);
      stream.next(m.nbrAge);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Line_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project_s_msgs::Line_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project_s_msgs::Line_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.id);
    s << indent << "segment[]" << std::endl;
    for (size_t i = 0; i < v.segment.size(); ++i)
    {
      s << indent << "  segment[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::project_s_msgs::Segment_<ContainerAllocator> >::stream(s, indent + "    ", v.segment[i]);
    }
    s << indent << "QtySegment: ";
    s << std::endl;
    Printer< ::std_msgs::UInt16_<ContainerAllocator> >::stream(s, indent + "  ", v.QtySegment);
    s << indent << "lineClass: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.lineClass);
    s << indent << "idPiste[]" << std::endl;
    for (size_t i = 0; i < v.idPiste.size(); ++i)
    {
      s << indent << "  idPiste[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::std_msgs::UInt16_<ContainerAllocator> >::stream(s, indent + "    ", v.idPiste[i]);
    }
    s << indent << "existenceState: ";
    s << std::endl;
    Printer< ::std_msgs::UInt8_<ContainerAllocator> >::stream(s, indent + "  ", v.existenceState);
    s << indent << "scoreDetection: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.scoreDetection);
    s << indent << "nbrDetection: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.nbrDetection);
    s << indent << "nbrVisibility: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.nbrVisibility);
    s << indent << "scorePersistence: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.scorePersistence);
    s << indent << "nbrUpdate: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.nbrUpdate);
    s << indent << "nbrAge: ";
    s << std::endl;
    Printer< ::std_msgs::Float32_<ContainerAllocator> >::stream(s, indent + "  ", v.nbrAge);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_S_MSGS_MESSAGE_LINE_H
