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

class segmentME {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.NbrSpot = null;
      this.offset_debut = null;
      this.offset_fin = null;
    }
    else {
      if (initObj.hasOwnProperty('NbrSpot')) {
        this.NbrSpot = initObj.NbrSpot
      }
      else {
        this.NbrSpot = 0;
      }
      if (initObj.hasOwnProperty('offset_debut')) {
        this.offset_debut = initObj.offset_debut
      }
      else {
        this.offset_debut = 0.0;
      }
      if (initObj.hasOwnProperty('offset_fin')) {
        this.offset_fin = initObj.offset_fin
      }
      else {
        this.offset_fin = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type segmentME
    // Serialize message field [NbrSpot]
    bufferOffset = _serializer.uint32(obj.NbrSpot, buffer, bufferOffset);
    // Serialize message field [offset_debut]
    bufferOffset = _serializer.float32(obj.offset_debut, buffer, bufferOffset);
    // Serialize message field [offset_fin]
    bufferOffset = _serializer.float32(obj.offset_fin, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type segmentME
    let len;
    let data = new segmentME(null);
    // Deserialize message field [NbrSpot]
    data.NbrSpot = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [offset_debut]
    data.offset_debut = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [offset_fin]
    data.offset_fin = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/segmentME';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'db8cd94b2ab5d013db8e670f53a36229';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 NbrSpot
    float32 offset_debut
    float32 offset_fin
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new segmentME(null);
    if (msg.NbrSpot !== undefined) {
      resolved.NbrSpot = msg.NbrSpot;
    }
    else {
      resolved.NbrSpot = 0
    }

    if (msg.offset_debut !== undefined) {
      resolved.offset_debut = msg.offset_debut;
    }
    else {
      resolved.offset_debut = 0.0
    }

    if (msg.offset_fin !== undefined) {
      resolved.offset_fin = msg.offset_fin;
    }
    else {
      resolved.offset_fin = 0.0
    }

    return resolved;
    }
};

module.exports = segmentME;
