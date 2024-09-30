// Auto-generated. Do not edit!

// (in-package message_project_s.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class sync {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.obstaclePosition = null;
      this.obstacleVelocity = null;
      this.obstacleAcceleration = null;
      this.trkID = null;
      this.trkLatrate = null;
      this.trkAngle = null;
      this.trkRange = null;
      this.trkWidth = null;
      this.trkRangeaccel = null;
      this.trkRangerate = null;
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
      if (initObj.hasOwnProperty('obstaclePosition')) {
        this.obstaclePosition = initObj.obstaclePosition
      }
      else {
        this.obstaclePosition = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('obstacleVelocity')) {
        this.obstacleVelocity = initObj.obstacleVelocity
      }
      else {
        this.obstacleVelocity = new geometry_msgs.msg.Twist();
      }
      if (initObj.hasOwnProperty('obstacleAcceleration')) {
        this.obstacleAcceleration = initObj.obstacleAcceleration
      }
      else {
        this.obstacleAcceleration = new geometry_msgs.msg.Accel();
      }
      if (initObj.hasOwnProperty('trkID')) {
        this.trkID = initObj.trkID
      }
      else {
        this.trkID = 0;
      }
      if (initObj.hasOwnProperty('trkLatrate')) {
        this.trkLatrate = initObj.trkLatrate
      }
      else {
        this.trkLatrate = 0.0;
      }
      if (initObj.hasOwnProperty('trkAngle')) {
        this.trkAngle = initObj.trkAngle
      }
      else {
        this.trkAngle = 0.0;
      }
      if (initObj.hasOwnProperty('trkRange')) {
        this.trkRange = initObj.trkRange
      }
      else {
        this.trkRange = 0.0;
      }
      if (initObj.hasOwnProperty('trkWidth')) {
        this.trkWidth = initObj.trkWidth
      }
      else {
        this.trkWidth = 0.0;
      }
      if (initObj.hasOwnProperty('trkRangeaccel')) {
        this.trkRangeaccel = initObj.trkRangeaccel
      }
      else {
        this.trkRangeaccel = 0.0;
      }
      if (initObj.hasOwnProperty('trkRangerate')) {
        this.trkRangerate = initObj.trkRangerate
      }
      else {
        this.trkRangerate = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type sync
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [obstaclePosition]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.obstaclePosition, buffer, bufferOffset);
    // Serialize message field [obstacleVelocity]
    bufferOffset = geometry_msgs.msg.Twist.serialize(obj.obstacleVelocity, buffer, bufferOffset);
    // Serialize message field [obstacleAcceleration]
    bufferOffset = geometry_msgs.msg.Accel.serialize(obj.obstacleAcceleration, buffer, bufferOffset);
    // Serialize message field [trkID]
    bufferOffset = _serializer.uint8(obj.trkID, buffer, bufferOffset);
    // Serialize message field [trkLatrate]
    bufferOffset = _serializer.float32(obj.trkLatrate, buffer, bufferOffset);
    // Serialize message field [trkAngle]
    bufferOffset = _serializer.float32(obj.trkAngle, buffer, bufferOffset);
    // Serialize message field [trkRange]
    bufferOffset = _serializer.float32(obj.trkRange, buffer, bufferOffset);
    // Serialize message field [trkWidth]
    bufferOffset = _serializer.float32(obj.trkWidth, buffer, bufferOffset);
    // Serialize message field [trkRangeaccel]
    bufferOffset = _serializer.float32(obj.trkRangeaccel, buffer, bufferOffset);
    // Serialize message field [trkRangerate]
    bufferOffset = _serializer.float32(obj.trkRangerate, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type sync
    let len;
    let data = new sync(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstaclePosition]
    data.obstaclePosition = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleVelocity]
    data.obstacleVelocity = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleAcceleration]
    data.obstacleAcceleration = geometry_msgs.msg.Accel.deserialize(buffer, bufferOffset);
    // Deserialize message field [trkID]
    data.trkID = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [trkLatrate]
    data.trkLatrate = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [trkAngle]
    data.trkAngle = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [trkRange]
    data.trkRange = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [trkWidth]
    data.trkWidth = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [trkRangeaccel]
    data.trkRangeaccel = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [trkRangerate]
    data.trkRangerate = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 178;
  }

  static datatype() {
    // Returns string type for a message object
    return 'message_project_s/sync';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8362c306ad17d94fd3f60283bbd12b35';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    geometry_msgs/Pose obstaclePosition		# obstacle position
    geometry_msgs/Twist obstacleVelocity		# obstacle speed
    geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
    uint8 trkID
    float32 trkLatrate
    float32 trkAngle
    float32 trkRange
    float32 trkWidth
    float32 trkRangeaccel
    float32 trkRangerate  
    
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
    MSG: geometry_msgs/Accel
    # This expresses acceleration in free space broken into its linear and angular parts.
    Vector3  linear
    Vector3  angular
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new sync(null);
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

    if (msg.obstaclePosition !== undefined) {
      resolved.obstaclePosition = geometry_msgs.msg.Pose.Resolve(msg.obstaclePosition)
    }
    else {
      resolved.obstaclePosition = new geometry_msgs.msg.Pose()
    }

    if (msg.obstacleVelocity !== undefined) {
      resolved.obstacleVelocity = geometry_msgs.msg.Twist.Resolve(msg.obstacleVelocity)
    }
    else {
      resolved.obstacleVelocity = new geometry_msgs.msg.Twist()
    }

    if (msg.obstacleAcceleration !== undefined) {
      resolved.obstacleAcceleration = geometry_msgs.msg.Accel.Resolve(msg.obstacleAcceleration)
    }
    else {
      resolved.obstacleAcceleration = new geometry_msgs.msg.Accel()
    }

    if (msg.trkID !== undefined) {
      resolved.trkID = msg.trkID;
    }
    else {
      resolved.trkID = 0
    }

    if (msg.trkLatrate !== undefined) {
      resolved.trkLatrate = msg.trkLatrate;
    }
    else {
      resolved.trkLatrate = 0.0
    }

    if (msg.trkAngle !== undefined) {
      resolved.trkAngle = msg.trkAngle;
    }
    else {
      resolved.trkAngle = 0.0
    }

    if (msg.trkRange !== undefined) {
      resolved.trkRange = msg.trkRange;
    }
    else {
      resolved.trkRange = 0.0
    }

    if (msg.trkWidth !== undefined) {
      resolved.trkWidth = msg.trkWidth;
    }
    else {
      resolved.trkWidth = 0.0
    }

    if (msg.trkRangeaccel !== undefined) {
      resolved.trkRangeaccel = msg.trkRangeaccel;
    }
    else {
      resolved.trkRangeaccel = 0.0
    }

    if (msg.trkRangerate !== undefined) {
      resolved.trkRangerate = msg.trkRangerate;
    }
    else {
      resolved.trkRangerate = 0.0
    }

    return resolved;
    }
};

module.exports = sync;
