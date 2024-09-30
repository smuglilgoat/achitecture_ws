// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let Line = require('./Line.js');
let nav_msgs = _finder('nav_msgs');
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class LaneFusion {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.line = null;
      this.QtyLine = null;
      this.lanePosition = null;
      this.lanePoseVariance = null;
      this.laneClass = null;
      this.classificationProbability = null;
      this.laneQuality = null;
      this.roadBorder = null;
      this.dateFusion = null;
      this.odom = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('line')) {
        this.line = initObj.line
      }
      else {
        this.line = new Array(20).fill(new Line());
      }
      if (initObj.hasOwnProperty('QtyLine')) {
        this.QtyLine = initObj.QtyLine
      }
      else {
        this.QtyLine = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('lanePosition')) {
        this.lanePosition = initObj.lanePosition
      }
      else {
        this.lanePosition = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('lanePoseVariance')) {
        this.lanePoseVariance = initObj.lanePoseVariance
      }
      else {
        this.lanePoseVariance = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('laneClass')) {
        this.laneClass = initObj.laneClass
      }
      else {
        this.laneClass = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('classificationProbability')) {
        this.classificationProbability = initObj.classificationProbability
      }
      else {
        this.classificationProbability = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('laneQuality')) {
        this.laneQuality = initObj.laneQuality
      }
      else {
        this.laneQuality = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('roadBorder')) {
        this.roadBorder = initObj.roadBorder
      }
      else {
        this.roadBorder = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('dateFusion')) {
        this.dateFusion = initObj.dateFusion
      }
      else {
        this.dateFusion = new std_msgs.msg.UInt64();
      }
      if (initObj.hasOwnProperty('odom')) {
        this.odom = initObj.odom
      }
      else {
        this.odom = new nav_msgs.msg.Odometry();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LaneFusion
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Check that the constant length array field [line] has the right length
    if (obj.line.length !== 20) {
      throw new Error('Unable to serialize array field line - length must be 20')
    }
    // Serialize message field [line]
    obj.line.forEach((val) => {
      bufferOffset = Line.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [QtyLine]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.QtyLine, buffer, bufferOffset);
    // Serialize message field [lanePosition]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.lanePosition, buffer, bufferOffset);
    // Serialize message field [lanePoseVariance]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.lanePoseVariance, buffer, bufferOffset);
    // Serialize message field [laneClass]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.laneClass, buffer, bufferOffset);
    // Serialize message field [classificationProbability]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.classificationProbability, buffer, bufferOffset);
    // Serialize message field [laneQuality]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.laneQuality, buffer, bufferOffset);
    // Serialize message field [roadBorder]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.roadBorder, buffer, bufferOffset);
    // Serialize message field [dateFusion]
    bufferOffset = std_msgs.msg.UInt64.serialize(obj.dateFusion, buffer, bufferOffset);
    // Serialize message field [odom]
    bufferOffset = nav_msgs.msg.Odometry.serialize(obj.odom, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LaneFusion
    let len;
    let data = new LaneFusion(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [line]
    len = 20;
    data.line = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.line[i] = Line.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [QtyLine]
    data.QtyLine = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [lanePosition]
    data.lanePosition = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [lanePoseVariance]
    data.lanePoseVariance = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [laneClass]
    data.laneClass = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [classificationProbability]
    data.classificationProbability = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [laneQuality]
    data.laneQuality = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [roadBorder]
    data.roadBorder = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [dateFusion]
    data.dateFusion = std_msgs.msg.UInt64.deserialize(buffer, bufferOffset);
    // Deserialize message field [odom]
    data.odom = nav_msgs.msg.Odometry.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.line.forEach((val) => {
      length += Line.getMessageSize(val);
    });
    length += nav_msgs.msg.Odometry.getMessageSize(object.odom);
    return length + 126;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/LaneFusion';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '220d926e4a3ceb1cf1d7edbdff245ce3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new LaneFusion(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.id !== undefined) {
      resolved.id = std_msgs.msg.UInt8.Resolve(msg.id)
    }
    else {
      resolved.id = new std_msgs.msg.UInt8()
    }

    if (msg.line !== undefined) {
      resolved.line = new Array(20)
      for (let i = 0; i < resolved.line.length; ++i) {
        if (msg.line.length > i) {
          resolved.line[i] = Line.Resolve(msg.line[i]);
        }
        else {
          resolved.line[i] = new Line();
        }
      }
    }
    else {
      resolved.line = new Array(20).fill(new Line())
    }

    if (msg.QtyLine !== undefined) {
      resolved.QtyLine = std_msgs.msg.UInt8.Resolve(msg.QtyLine)
    }
    else {
      resolved.QtyLine = new std_msgs.msg.UInt8()
    }

    if (msg.lanePosition !== undefined) {
      resolved.lanePosition = geometry_msgs.msg.Pose.Resolve(msg.lanePosition)
    }
    else {
      resolved.lanePosition = new geometry_msgs.msg.Pose()
    }

    if (msg.lanePoseVariance !== undefined) {
      resolved.lanePoseVariance = geometry_msgs.msg.Pose.Resolve(msg.lanePoseVariance)
    }
    else {
      resolved.lanePoseVariance = new geometry_msgs.msg.Pose()
    }

    if (msg.laneClass !== undefined) {
      resolved.laneClass = std_msgs.msg.UInt8.Resolve(msg.laneClass)
    }
    else {
      resolved.laneClass = new std_msgs.msg.UInt8()
    }

    if (msg.classificationProbability !== undefined) {
      resolved.classificationProbability = std_msgs.msg.UInt8.Resolve(msg.classificationProbability)
    }
    else {
      resolved.classificationProbability = new std_msgs.msg.UInt8()
    }

    if (msg.laneQuality !== undefined) {
      resolved.laneQuality = std_msgs.msg.UInt8.Resolve(msg.laneQuality)
    }
    else {
      resolved.laneQuality = new std_msgs.msg.UInt8()
    }

    if (msg.roadBorder !== undefined) {
      resolved.roadBorder = std_msgs.msg.UInt8.Resolve(msg.roadBorder)
    }
    else {
      resolved.roadBorder = new std_msgs.msg.UInt8()
    }

    if (msg.dateFusion !== undefined) {
      resolved.dateFusion = std_msgs.msg.UInt64.Resolve(msg.dateFusion)
    }
    else {
      resolved.dateFusion = new std_msgs.msg.UInt64()
    }

    if (msg.odom !== undefined) {
      resolved.odom = nav_msgs.msg.Odometry.Resolve(msg.odom)
    }
    else {
      resolved.odom = new nav_msgs.msg.Odometry()
    }

    return resolved;
    }
};

module.exports = LaneFusion;
