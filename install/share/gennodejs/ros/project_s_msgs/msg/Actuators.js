// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Actuators {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.Accelerator = null;
      this.brakePressure = null;
      this.steeringAngle = null;
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
      if (initObj.hasOwnProperty('Accelerator')) {
        this.Accelerator = initObj.Accelerator
      }
      else {
        this.Accelerator = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('brakePressure')) {
        this.brakePressure = initObj.brakePressure
      }
      else {
        this.brakePressure = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('steeringAngle')) {
        this.steeringAngle = initObj.steeringAngle
      }
      else {
        this.steeringAngle = new std_msgs.msg.Float32();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Actuators
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [Accelerator]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.Accelerator, buffer, bufferOffset);
    // Serialize message field [brakePressure]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.brakePressure, buffer, bufferOffset);
    // Serialize message field [steeringAngle]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.steeringAngle, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Actuators
    let len;
    let data = new Actuators(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [Accelerator]
    data.Accelerator = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [brakePressure]
    data.brakePressure = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [steeringAngle]
    data.steeringAngle = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 13;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/Actuators';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '94218c4fc10da9425fa7248c8f707ac5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    std_msgs/Float32 Accelerator
    std_msgs/Float32 brakePressure
    std_msgs/Float32 steeringAngle
    
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
    MSG: std_msgs/Float32
    float32 data
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Actuators(null);
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

    if (msg.Accelerator !== undefined) {
      resolved.Accelerator = std_msgs.msg.Float32.Resolve(msg.Accelerator)
    }
    else {
      resolved.Accelerator = new std_msgs.msg.Float32()
    }

    if (msg.brakePressure !== undefined) {
      resolved.brakePressure = std_msgs.msg.Float32.Resolve(msg.brakePressure)
    }
    else {
      resolved.brakePressure = new std_msgs.msg.Float32()
    }

    if (msg.steeringAngle !== undefined) {
      resolved.steeringAngle = std_msgs.msg.Float32.Resolve(msg.steeringAngle)
    }
    else {
      resolved.steeringAngle = new std_msgs.msg.Float32()
    }

    return resolved;
    }
};

module.exports = Actuators;
