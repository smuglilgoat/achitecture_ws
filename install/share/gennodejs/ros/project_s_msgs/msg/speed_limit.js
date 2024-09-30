// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class speed_limit {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.offset = null;
      this.effectiveSpeedLimit = null;
    }
    else {
      if (initObj.hasOwnProperty('offset')) {
        this.offset = initObj.offset
      }
      else {
        this.offset = 0.0;
      }
      if (initObj.hasOwnProperty('effectiveSpeedLimit')) {
        this.effectiveSpeedLimit = initObj.effectiveSpeedLimit
      }
      else {
        this.effectiveSpeedLimit = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type speed_limit
    // Serialize message field [offset]
    bufferOffset = _serializer.float32(obj.offset, buffer, bufferOffset);
    // Serialize message field [effectiveSpeedLimit]
    bufferOffset = _serializer.uint8(obj.effectiveSpeedLimit, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type speed_limit
    let len;
    let data = new speed_limit(null);
    // Deserialize message field [offset]
    data.offset = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [effectiveSpeedLimit]
    data.effectiveSpeedLimit = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/speed_limit';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '56f584c5e8b035f849b17a33fc0e3dfd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 offset
    uint8 effectiveSpeedLimit
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new speed_limit(null);
    if (msg.offset !== undefined) {
      resolved.offset = msg.offset;
    }
    else {
      resolved.offset = 0.0
    }

    if (msg.effectiveSpeedLimit !== undefined) {
      resolved.effectiveSpeedLimit = msg.effectiveSpeedLimit;
    }
    else {
      resolved.effectiveSpeedLimit = 0
    }

    return resolved;
    }
};

module.exports = speed_limit;
