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

class ehNbrLineCoordGeo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Nbr = null;
      this.offset = null;
    }
    else {
      if (initObj.hasOwnProperty('Nbr')) {
        this.Nbr = initObj.Nbr
      }
      else {
        this.Nbr = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('offset')) {
        this.offset = initObj.offset
      }
      else {
        this.offset = new std_msgs.msg.Float32();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ehNbrLineCoordGeo
    // Serialize message field [Nbr]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.Nbr, buffer, bufferOffset);
    // Serialize message field [offset]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.offset, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ehNbrLineCoordGeo
    let len;
    let data = new ehNbrLineCoordGeo(null);
    // Deserialize message field [Nbr]
    data.Nbr = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [offset]
    data.offset = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ehNbrLineCoordGeo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ba129a5215116e7dd0de7b78069aec8a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/UInt8 Nbr
    std_msgs/Float32 offset
    
    
    
    
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
    const resolved = new ehNbrLineCoordGeo(null);
    if (msg.Nbr !== undefined) {
      resolved.Nbr = std_msgs.msg.UInt8.Resolve(msg.Nbr)
    }
    else {
      resolved.Nbr = new std_msgs.msg.UInt8()
    }

    if (msg.offset !== undefined) {
      resolved.offset = std_msgs.msg.Float32.Resolve(msg.offset)
    }
    else {
      resolved.offset = new std_msgs.msg.Float32()
    }

    return resolved;
    }
};

module.exports = ehNbrLineCoordGeo;
