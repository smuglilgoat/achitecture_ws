// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let GenericSmartData = require('./GenericSmartData.js');
let nav_msgs = _finder('nav_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ObstacleReport {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.GenericSmartData = null;
      this.QtySmartData = null;
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
      if (initObj.hasOwnProperty('GenericSmartData')) {
        this.GenericSmartData = initObj.GenericSmartData
      }
      else {
        this.GenericSmartData = new Array(64).fill(new GenericSmartData());
      }
      if (initObj.hasOwnProperty('QtySmartData')) {
        this.QtySmartData = initObj.QtySmartData
      }
      else {
        this.QtySmartData = new std_msgs.msg.UInt8();
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
    // Serializes a message object of type ObstacleReport
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Check that the constant length array field [GenericSmartData] has the right length
    if (obj.GenericSmartData.length !== 64) {
      throw new Error('Unable to serialize array field GenericSmartData - length must be 64')
    }
    // Serialize message field [GenericSmartData]
    obj.GenericSmartData.forEach((val) => {
      bufferOffset = GenericSmartData.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [QtySmartData]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.QtySmartData, buffer, bufferOffset);
    // Serialize message field [dateAcquisition]
    bufferOffset = std_msgs.msg.Float64.serialize(obj.dateAcquisition, buffer, bufferOffset);
    // Serialize message field [odom]
    bufferOffset = nav_msgs.msg.Odometry.serialize(obj.odom, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObstacleReport
    let len;
    let data = new ObstacleReport(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [GenericSmartData]
    len = 64;
    data.GenericSmartData = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.GenericSmartData[i] = GenericSmartData.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [QtySmartData]
    data.QtySmartData = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [dateAcquisition]
    data.dateAcquisition = std_msgs.msg.Float64.deserialize(buffer, bufferOffset);
    // Deserialize message field [odom]
    data.odom = nav_msgs.msg.Odometry.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.GenericSmartData.forEach((val) => {
      length += GenericSmartData.getMessageSize(val);
    });
    length += nav_msgs.msg.Odometry.getMessageSize(object.odom);
    return length + 10;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ObstacleReport';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd66d512738eec8e99605306c6e973be5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    project_s_msgs/GenericSmartData[64] GenericSmartData		#GenericSmartData array   
    std_msgs/UInt8 QtySmartData
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
    MSG: project_s_msgs/GenericSmartData
    Header header
    std_msgs/UInt16 id
    
    geometry_msgs/Pose obstaclePosition		# obstacle position
    geometry_msgs/Twist obstacleVelocity		# obstacle speed
    geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
    geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height
    geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance
    geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance
    
    uint8 OBSTACLE_CLASS_NONE = 0
    uint8 OBSTACLE_CLASS_SIGN = 1
    uint8 OBSTACLE_CLASS_PLOT = 2
    uint8 OBSTACLE_CLASS_INVALID = 255
    uint8 obstacleClass
    
    uint8 vision_only_sign_type
    
    ================================================================================
    MSG: std_msgs/UInt16
    uint16 data
    
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
    MSG: geometry_msgs/Accel
    # This expresses acceleration in free space broken into its linear and angular parts.
    Vector3  linear
    Vector3  angular
    
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
    const resolved = new ObstacleReport(null);
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

    if (msg.GenericSmartData !== undefined) {
      resolved.GenericSmartData = new Array(64)
      for (let i = 0; i < resolved.GenericSmartData.length; ++i) {
        if (msg.GenericSmartData.length > i) {
          resolved.GenericSmartData[i] = GenericSmartData.Resolve(msg.GenericSmartData[i]);
        }
        else {
          resolved.GenericSmartData[i] = new GenericSmartData();
        }
      }
    }
    else {
      resolved.GenericSmartData = new Array(64).fill(new GenericSmartData())
    }

    if (msg.QtySmartData !== undefined) {
      resolved.QtySmartData = std_msgs.msg.UInt8.Resolve(msg.QtySmartData)
    }
    else {
      resolved.QtySmartData = new std_msgs.msg.UInt8()
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

module.exports = ObstacleReport;
