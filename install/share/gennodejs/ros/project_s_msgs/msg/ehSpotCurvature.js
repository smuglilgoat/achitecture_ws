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

class ehSpotCurvature {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.offset = null;
      this.Value_0 = null;
      this.Distance_1 = null;
      this.Value_1 = null;
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
      if (initObj.hasOwnProperty('offset')) {
        this.offset = initObj.offset
      }
      else {
        this.offset = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('Value_0')) {
        this.Value_0 = initObj.Value_0
      }
      else {
        this.Value_0 = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('Distance_1')) {
        this.Distance_1 = initObj.Distance_1
      }
      else {
        this.Distance_1 = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('Value_1')) {
        this.Value_1 = initObj.Value_1
      }
      else {
        this.Value_1 = new std_msgs.msg.Float32();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ehSpotCurvature
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [offset]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.offset, buffer, bufferOffset);
    // Serialize message field [Value_0]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.Value_0, buffer, bufferOffset);
    // Serialize message field [Distance_1]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.Distance_1, buffer, bufferOffset);
    // Serialize message field [Value_1]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.Value_1, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ehSpotCurvature
    let len;
    let data = new ehSpotCurvature(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [offset]
    data.offset = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [Value_0]
    data.Value_0 = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [Distance_1]
    data.Distance_1 = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [Value_1]
    data.Value_1 = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 17;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ehSpotCurvature';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9d76e4756ee6f85fb71ecf3f9d7549f6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    #std_msgs/UInt8 indexPath
    std_msgs/Float32 offset
    std_msgs/Float32 Value_0
    std_msgs/Float32 Distance_1
    std_msgs/Float32 Value_1
    
    
    
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
    const resolved = new ehSpotCurvature(null);
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

    if (msg.offset !== undefined) {
      resolved.offset = std_msgs.msg.Float32.Resolve(msg.offset)
    }
    else {
      resolved.offset = new std_msgs.msg.Float32()
    }

    if (msg.Value_0 !== undefined) {
      resolved.Value_0 = std_msgs.msg.Float32.Resolve(msg.Value_0)
    }
    else {
      resolved.Value_0 = new std_msgs.msg.Float32()
    }

    if (msg.Distance_1 !== undefined) {
      resolved.Distance_1 = std_msgs.msg.Float32.Resolve(msg.Distance_1)
    }
    else {
      resolved.Distance_1 = new std_msgs.msg.Float32()
    }

    if (msg.Value_1 !== undefined) {
      resolved.Value_1 = std_msgs.msg.Float32.Resolve(msg.Value_1)
    }
    else {
      resolved.Value_1 = new std_msgs.msg.Float32()
    }

    return resolved;
    }
};

module.exports = ehSpotCurvature;
