// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let LaneAlignment = require('./LaneAlignment.js');
let LaneFusion = require('./LaneFusion.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class LaneSynchronizedReport {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.laneAlignement = null;
      this.laneFusion = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('laneAlignement')) {
        this.laneAlignement = initObj.laneAlignement
      }
      else {
        this.laneAlignement = new LaneAlignment();
      }
      if (initObj.hasOwnProperty('laneFusion')) {
        this.laneFusion = initObj.laneFusion
      }
      else {
        this.laneFusion = new LaneFusion();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LaneSynchronizedReport
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [laneAlignement]
    bufferOffset = LaneAlignment.serialize(obj.laneAlignement, buffer, bufferOffset);
    // Serialize message field [laneFusion]
    bufferOffset = LaneFusion.serialize(obj.laneFusion, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LaneSynchronizedReport
    let len;
    let data = new LaneSynchronizedReport(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [laneAlignement]
    data.laneAlignement = LaneAlignment.deserialize(buffer, bufferOffset);
    // Deserialize message field [laneFusion]
    data.laneFusion = LaneFusion.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += LaneAlignment.getMessageSize(object.laneAlignement);
    length += LaneFusion.getMessageSize(object.laneFusion);
    return length;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/LaneSynchronizedReport';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0015369a55dde05f8919cae4085b780e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    project_s_msgs/LaneAlignment laneAlignement 
    project_s_msgs/LaneFusion laneFusion
    
    # History
    
    
    
    
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    ================================================================================
    MSG: project_s_msgs/LaneAlignment
    Header header
    std_msgs/UInt8 id
    
    #geometry_msgs/Point[250] points
    
    uint8 LINE_REPORT_SIZE = 20
    project_s_msgs/Line[20] line
    std_msgs/UInt8 QtyLine
    
    geometry_msgs/Pose lanePosition
    geometry_msgs/Pose lanePoseVariance
    std_msgs/UInt8 laneClass
    std_msgs/UInt8 classificationProbability
    std_msgs/UInt8 laneQuality
    std_msgs/UInt64 dateAcquisition
    nav_msgs/Odometry odom
    
    # History
    
    
    
    
    
    ================================================================================
    MSG: std_msgs/UInt8
    uint8 data
    
    ================================================================================
    MSG: project_s_msgs/Line
    Header header
    std_msgs/UInt8 id
    
    uint16 SEGMENT_REPORT_SIZE = 3000
    project_s_msgs/Segment[3000] segment
    std_msgs/UInt16 QtySegment
    std_msgs/Float32 lineClass	# class of the line
    std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)
    
    std_msgs/UInt8 existenceState
    std_msgs/Float32 scoreDetection
    std_msgs/Float32 nbrDetection
    std_msgs/Float32 nbrVisibility
    std_msgs/Float32 scorePersistence
    std_msgs/Float32 nbrUpdate
    std_msgs/Float32 nbrAge
    
    
    
    ================================================================================
    MSG: project_s_msgs/Segment
    std_msgs/Float32 length		# length of the segment
    std_msgs/Float32 angle		# angle of the segment
    geometry_msgs/Point position
    geometry_msgs/Twist Velocity
    
    float32 offset
    float64 latitude
    float64 longitude
    
    
    ================================================================================
    MSG: std_msgs/Float32
    float32 data
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Twist
    # This expresses velocity in free space broken into its linear and angular parts.
    Vector3  linear
    Vector3  angular
    
    ================================================================================
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    ================================================================================
    MSG: std_msgs/UInt16
    uint16 data
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    ================================================================================
    MSG: std_msgs/UInt64
    uint64 data
    ================================================================================
    MSG: nav_msgs/Odometry
    # This represents an estimate of a position and velocity in free space.  
    # The pose in this message should be specified in the coordinate frame given by header.frame_id.
    # The twist in this message should be specified in the coordinate frame given by the child_frame_id
    Header header
    string child_frame_id
    geometry_msgs/PoseWithCovariance pose
    geometry_msgs/TwistWithCovariance twist
    
    ================================================================================
    MSG: geometry_msgs/PoseWithCovariance
    # This represents a pose in free space with uncertainty.
    
    Pose pose
    
    # Row-major representation of the 6x6 covariance matrix
    # The orientation parameters use a fixed-axis representation.
    # In order, the parameters are:
    # (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
    float64[36] covariance
    
    ================================================================================
    MSG: geometry_msgs/TwistWithCovariance
    # This expresses velocity in free space with uncertainty.
    
    Twist twist
    
    # Row-major representation of the 6x6 covariance matrix
    # The orientation parameters use a fixed-axis representation.
    # In order, the parameters are:
    # (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
    float64[36] covariance
    
    ================================================================================
    MSG: project_s_msgs/LaneFusion
    Header header
    std_msgs/UInt8 id
    
    #geometry_msgs/Point[250] points
    
    #uint8 LINE_REPORT_SIZE = 20
    project_s_msgs/Line[20] line
    std_msgs/UInt8 QtyLine
    
    geometry_msgs/Pose lanePosition
    geometry_msgs/Pose lanePoseVariance
    std_msgs/UInt8 laneClass
    std_msgs/UInt8 classificationProbability
    std_msgs/UInt8 laneQuality
    std_msgs/UInt8 roadBorder
    std_msgs/UInt64 dateFusion
    nav_msgs/Odometry odom
    
    # History
    
    
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new LaneSynchronizedReport(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.laneAlignement !== undefined) {
      resolved.laneAlignement = LaneAlignment.Resolve(msg.laneAlignement)
    }
    else {
      resolved.laneAlignement = new LaneAlignment()
    }

    if (msg.laneFusion !== undefined) {
      resolved.laneFusion = LaneFusion.Resolve(msg.laneFusion)
    }
    else {
      resolved.laneFusion = new LaneFusion()
    }

    return resolved;
    }
};

module.exports = LaneSynchronizedReport;
