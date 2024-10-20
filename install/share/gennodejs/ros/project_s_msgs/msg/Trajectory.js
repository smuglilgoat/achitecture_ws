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

class Trajectory {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.setpointPosition = null;
      this.setpointVelocity = null;
      this.targetLength = null;
      this.targetSpeed = null;
      this.trajectoryLine = null;
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
      if (initObj.hasOwnProperty('setpointPosition')) {
        this.setpointPosition = initObj.setpointPosition
      }
      else {
        this.setpointPosition = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('setpointVelocity')) {
        this.setpointVelocity = initObj.setpointVelocity
      }
      else {
        this.setpointVelocity = new geometry_msgs.msg.Twist();
      }
      if (initObj.hasOwnProperty('targetLength')) {
        this.targetLength = initObj.targetLength
      }
      else {
        this.targetLength = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('targetSpeed')) {
        this.targetSpeed = initObj.targetSpeed
      }
      else {
        this.targetSpeed = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('trajectoryLine')) {
        this.trajectoryLine = initObj.trajectoryLine
      }
      else {
        this.trajectoryLine = new Line();
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
    // Serializes a message object of type Trajectory
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [setpointPosition]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.setpointPosition, buffer, bufferOffset);
    // Serialize message field [setpointVelocity]
    bufferOffset = geometry_msgs.msg.Twist.serialize(obj.setpointVelocity, buffer, bufferOffset);
    // Serialize message field [targetLength]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.targetLength, buffer, bufferOffset);
    // Serialize message field [targetSpeed]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.targetSpeed, buffer, bufferOffset);
    // Serialize message field [trajectoryLine]
    bufferOffset = Line.serialize(obj.trajectoryLine, buffer, bufferOffset);
    // Serialize message field [odom]
    bufferOffset = nav_msgs.msg.Odometry.serialize(obj.odom, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Trajectory
    let len;
    let data = new Trajectory(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [setpointPosition]
    data.setpointPosition = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [setpointVelocity]
    data.setpointVelocity = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset);
    // Deserialize message field [targetLength]
    data.targetLength = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [targetSpeed]
    data.targetSpeed = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [trajectoryLine]
    data.trajectoryLine = Line.deserialize(buffer, bufferOffset);
    // Deserialize message field [odom]
    data.odom = nav_msgs.msg.Odometry.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += Line.getMessageSize(object.trajectoryLine);
    length += nav_msgs.msg.Odometry.getMessageSize(object.odom);
    return length + 113;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/Trajectory';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1841594a837a63ee15ae7b9c6f1d2f4c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    geometry_msgs/Pose setpointPosition		# setpoint position
    geometry_msgs/Twist setpointVelocity		# setpoint speed
    std_msgs/Float32 targetLength
    std_msgs/Float32 targetSpeed
    
    project_s_msgs/Line trajectoryLine			#segments array
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
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
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
    MSG: std_msgs/Float32
    float32 data
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
    MSG: std_msgs/UInt16
    uint16 data
    
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
    const resolved = new Trajectory(null);
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

    if (msg.setpointPosition !== undefined) {
      resolved.setpointPosition = geometry_msgs.msg.Pose.Resolve(msg.setpointPosition)
    }
    else {
      resolved.setpointPosition = new geometry_msgs.msg.Pose()
    }

    if (msg.setpointVelocity !== undefined) {
      resolved.setpointVelocity = geometry_msgs.msg.Twist.Resolve(msg.setpointVelocity)
    }
    else {
      resolved.setpointVelocity = new geometry_msgs.msg.Twist()
    }

    if (msg.targetLength !== undefined) {
      resolved.targetLength = std_msgs.msg.Float32.Resolve(msg.targetLength)
    }
    else {
      resolved.targetLength = new std_msgs.msg.Float32()
    }

    if (msg.targetSpeed !== undefined) {
      resolved.targetSpeed = std_msgs.msg.Float32.Resolve(msg.targetSpeed)
    }
    else {
      resolved.targetSpeed = new std_msgs.msg.Float32()
    }

    if (msg.trajectoryLine !== undefined) {
      resolved.trajectoryLine = Line.Resolve(msg.trajectoryLine)
    }
    else {
      resolved.trajectoryLine = new Line()
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

module.exports = Trajectory;
