// Auto-generated. Do not edit!

// (in-package message_project_s.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Time {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.Tn = null;
      this.Tn_1 = null;
      this.Ti = null;
      this.iMIN = null;
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
      if (initObj.hasOwnProperty('Tn')) {
        this.Tn = initObj.Tn
      }
      else {
        this.Tn = new std_msgs.msg.Float64();
      }
      if (initObj.hasOwnProperty('Tn_1')) {
        this.Tn_1 = initObj.Tn_1
      }
      else {
        this.Tn_1 = new std_msgs.msg.Float64();
      }
      if (initObj.hasOwnProperty('Ti')) {
        this.Ti = initObj.Ti
      }
      else {
        this.Ti = new std_msgs.msg.Float64();
      }
      if (initObj.hasOwnProperty('iMIN')) {
        this.iMIN = initObj.iMIN
      }
      else {
        this.iMIN = new std_msgs.msg.Float64();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Time
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [Tn]
    bufferOffset = std_msgs.msg.Float64.serialize(obj.Tn, buffer, bufferOffset);
    // Serialize message field [Tn_1]
    bufferOffset = std_msgs.msg.Float64.serialize(obj.Tn_1, buffer, bufferOffset);
    // Serialize message field [Ti]
    bufferOffset = std_msgs.msg.Float64.serialize(obj.Ti, buffer, bufferOffset);
    // Serialize message field [iMIN]
    bufferOffset = std_msgs.msg.Float64.serialize(obj.iMIN, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Time
    let len;
    let data = new Time(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [Tn]
    data.Tn = std_msgs.msg.Float64.deserialize(buffer, bufferOffset);
    // Deserialize message field [Tn_1]
    data.Tn_1 = std_msgs.msg.Float64.deserialize(buffer, bufferOffset);
    // Deserialize message field [Ti]
    data.Ti = std_msgs.msg.Float64.deserialize(buffer, bufferOffset);
    // Deserialize message field [iMIN]
    data.iMIN = std_msgs.msg.Float64.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 33;
  }

  static datatype() {
    // Returns string type for a message object
    return 'message_project_s/Time';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8478fcb0a41d3039f22925b77479cd7f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    std_msgs/Float64 Tn
    std_msgs/Float64 Tn_1
    std_msgs/Float64 Ti
    std_msgs/Float64 iMIN
    
    
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
    MSG: std_msgs/Float64
    float64 data
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Time(null);
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

    if (msg.Tn !== undefined) {
      resolved.Tn = std_msgs.msg.Float64.Resolve(msg.Tn)
    }
    else {
      resolved.Tn = new std_msgs.msg.Float64()
    }

    if (msg.Tn_1 !== undefined) {
      resolved.Tn_1 = std_msgs.msg.Float64.Resolve(msg.Tn_1)
    }
    else {
      resolved.Tn_1 = new std_msgs.msg.Float64()
    }

    if (msg.Ti !== undefined) {
      resolved.Ti = std_msgs.msg.Float64.Resolve(msg.Ti)
    }
    else {
      resolved.Ti = new std_msgs.msg.Float64()
    }

    if (msg.iMIN !== undefined) {
      resolved.iMIN = std_msgs.msg.Float64.Resolve(msg.iMIN)
    }
    else {
      resolved.iMIN = new std_msgs.msg.Float64()
    }

    return resolved;
    }
};

module.exports = Time;
