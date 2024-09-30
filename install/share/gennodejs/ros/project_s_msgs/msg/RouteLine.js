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

class RouteLine {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.points = null;
      this.line = null;
      this.dateAcquisition = null;
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
      if (initObj.hasOwnProperty('points')) {
        this.points = initObj.points
      }
      else {
        this.points = new Array(250).fill(new geometry_msgs.msg.Point());
      }
      if (initObj.hasOwnProperty('line')) {
        this.line = initObj.line
      }
      else {
        this.line = new Array(5).fill(new Line());
      }
      if (initObj.hasOwnProperty('dateAcquisition')) {
        this.dateAcquisition = initObj.dateAcquisition
      }
      else {
        this.dateAcquisition = new std_msgs.msg.Float64();
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
    // Serializes a message object of type RouteLine
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Check that the constant length array field [points] has the right length
    if (obj.points.length !== 250) {
      throw new Error('Unable to serialize array field points - length must be 250')
    }
    // Serialize message field [points]
    obj.points.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point.serialize(val, buffer, bufferOffset);
    });
    // Check that the constant length array field [line] has the right length
    if (obj.line.length !== 5) {
      throw new Error('Unable to serialize array field line - length must be 5')
    }
    // Serialize message field [line]
    obj.line.forEach((val) => {
      bufferOffset = Line.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [dateAcquisition]
    bufferOffset = std_msgs.msg.Float64.serialize(obj.dateAcquisition, buffer, bufferOffset);
    // Serialize message field [odom]
    bufferOffset = nav_msgs.msg.Odometry.serialize(obj.odom, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RouteLine
    let len;
    let data = new RouteLine(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [points]
    len = 250;
    data.points = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.points[i] = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [line]
    len = 5;
    data.line = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.line[i] = Line.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [dateAcquisition]
    data.dateAcquisition = std_msgs.msg.Float64.deserialize(buffer, bufferOffset);
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
    return length + 6009;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/RouteLine';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5c1345baa2f400a3bbff31393a457845';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    geometry_msgs/Point[250] points
    
    project_s_msgs/Line[5] line
    
    std_msgs/Float64 dateAcquisition
    nav_msgs/Odometry odom
    
    
    
    
    
    
    
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
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
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
    MSG: std_msgs/Float64
    float64 data
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
    const resolved = new RouteLine(null);
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

    if (msg.points !== undefined) {
      resolved.points = new Array(250)
      for (let i = 0; i < resolved.points.length; ++i) {
        if (msg.points.length > i) {
          resolved.points[i] = geometry_msgs.msg.Point.Resolve(msg.points[i]);
        }
        else {
          resolved.points[i] = new geometry_msgs.msg.Point();
        }
      }
    }
    else {
      resolved.points = new Array(250).fill(new geometry_msgs.msg.Point())
    }

    if (msg.line !== undefined) {
      resolved.line = new Array(5)
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
      resolved.line = new Array(5).fill(new Line())
    }

    if (msg.dateAcquisition !== undefined) {
      resolved.dateAcquisition = std_msgs.msg.Float64.Resolve(msg.dateAcquisition)
    }
    else {
      resolved.dateAcquisition = new std_msgs.msg.Float64()
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

module.exports = RouteLine;
