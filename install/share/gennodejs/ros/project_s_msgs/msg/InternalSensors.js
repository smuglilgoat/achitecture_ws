// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


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

class InternalSensors {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.vehicleleVelocity = null;
      this.vehicleAcceleration = null;
      this.steeringWheelAngle = null;
      this.timeStamp = null;
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
      if (initObj.hasOwnProperty('vehicleleVelocity')) {
        this.vehicleleVelocity = initObj.vehicleleVelocity
      }
      else {
        this.vehicleleVelocity = new geometry_msgs.msg.Twist();
      }
      if (initObj.hasOwnProperty('vehicleAcceleration')) {
        this.vehicleAcceleration = initObj.vehicleAcceleration
      }
      else {
        this.vehicleAcceleration = new geometry_msgs.msg.Accel();
      }
      if (initObj.hasOwnProperty('steeringWheelAngle')) {
        this.steeringWheelAngle = initObj.steeringWheelAngle
      }
      else {
        this.steeringWheelAngle = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('timeStamp')) {
        this.timeStamp = initObj.timeStamp
      }
      else {
        this.timeStamp = new std_msgs.msg.UInt64();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type InternalSensors
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [vehicleleVelocity]
    bufferOffset = geometry_msgs.msg.Twist.serialize(obj.vehicleleVelocity, buffer, bufferOffset);
    // Serialize message field [vehicleAcceleration]
    bufferOffset = geometry_msgs.msg.Accel.serialize(obj.vehicleAcceleration, buffer, bufferOffset);
    // Serialize message field [steeringWheelAngle]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.steeringWheelAngle, buffer, bufferOffset);
    // Serialize message field [timeStamp]
    bufferOffset = std_msgs.msg.UInt64.serialize(obj.timeStamp, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type InternalSensors
    let len;
    let data = new InternalSensors(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [vehicleleVelocity]
    data.vehicleleVelocity = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset);
    // Deserialize message field [vehicleAcceleration]
    data.vehicleAcceleration = geometry_msgs.msg.Accel.deserialize(buffer, bufferOffset);
    // Deserialize message field [steeringWheelAngle]
    data.steeringWheelAngle = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [timeStamp]
    data.timeStamp = std_msgs.msg.UInt64.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 109;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/InternalSensors';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c7afa49d12086db3055945e1a8731d66';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    geometry_msgs/Twist vehicleleVelocity
    geometry_msgs/Accel vehicleAcceleration
    std_msgs/Float32 steeringWheelAngle
    std_msgs/UInt64 timeStamp
    
    
    
    
    
    
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
    MSG: std_msgs/Float32
    float32 data
    ================================================================================
    MSG: std_msgs/UInt64
    uint64 data
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new InternalSensors(null);
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

    if (msg.vehicleleVelocity !== undefined) {
      resolved.vehicleleVelocity = geometry_msgs.msg.Twist.Resolve(msg.vehicleleVelocity)
    }
    else {
      resolved.vehicleleVelocity = new geometry_msgs.msg.Twist()
    }

    if (msg.vehicleAcceleration !== undefined) {
      resolved.vehicleAcceleration = geometry_msgs.msg.Accel.Resolve(msg.vehicleAcceleration)
    }
    else {
      resolved.vehicleAcceleration = new geometry_msgs.msg.Accel()
    }

    if (msg.steeringWheelAngle !== undefined) {
      resolved.steeringWheelAngle = std_msgs.msg.Float32.Resolve(msg.steeringWheelAngle)
    }
    else {
      resolved.steeringWheelAngle = new std_msgs.msg.Float32()
    }

    if (msg.timeStamp !== undefined) {
      resolved.timeStamp = std_msgs.msg.UInt64.Resolve(msg.timeStamp)
    }
    else {
      resolved.timeStamp = new std_msgs.msg.UInt64()
    }

    return resolved;
    }
};

module.exports = InternalSensors;
