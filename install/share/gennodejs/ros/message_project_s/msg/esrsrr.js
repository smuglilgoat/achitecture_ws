// Auto-generated. Do not edit!

// (in-package message_project_s.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class esrsrr {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.stampsrr = null;
      this.stampesr = null;
      this.seqesr = null;
      this.can_dsp_ts = null;
    }
    else {
      if (initObj.hasOwnProperty('stampsrr')) {
        this.stampsrr = initObj.stampsrr
      }
      else {
        this.stampsrr = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('stampesr')) {
        this.stampesr = initObj.stampesr
      }
      else {
        this.stampesr = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('seqesr')) {
        this.seqesr = initObj.seqesr
      }
      else {
        this.seqesr = 0;
      }
      if (initObj.hasOwnProperty('can_dsp_ts')) {
        this.can_dsp_ts = initObj.can_dsp_ts
      }
      else {
        this.can_dsp_ts = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type esrsrr
    // Serialize message field [stampsrr]
    bufferOffset = _serializer.time(obj.stampsrr, buffer, bufferOffset);
    // Serialize message field [stampesr]
    bufferOffset = _serializer.time(obj.stampesr, buffer, bufferOffset);
    // Serialize message field [seqesr]
    bufferOffset = _serializer.uint32(obj.seqesr, buffer, bufferOffset);
    // Serialize message field [can_dsp_ts]
    bufferOffset = _serializer.uint32(obj.can_dsp_ts, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type esrsrr
    let len;
    let data = new esrsrr(null);
    // Deserialize message field [stampsrr]
    data.stampsrr = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [stampesr]
    data.stampesr = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [seqesr]
    data.seqesr = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [can_dsp_ts]
    data.can_dsp_ts = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'message_project_s/esrsrr';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '67e39e1d269819b2e9c170bc6fb5fbb5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    time stampsrr
    time stampesr
    uint32 seqesr
    uint32 can_dsp_ts
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new esrsrr(null);
    if (msg.stampsrr !== undefined) {
      resolved.stampsrr = msg.stampsrr;
    }
    else {
      resolved.stampsrr = {secs: 0, nsecs: 0}
    }

    if (msg.stampesr !== undefined) {
      resolved.stampesr = msg.stampesr;
    }
    else {
      resolved.stampesr = {secs: 0, nsecs: 0}
    }

    if (msg.seqesr !== undefined) {
      resolved.seqesr = msg.seqesr;
    }
    else {
      resolved.seqesr = 0
    }

    if (msg.can_dsp_ts !== undefined) {
      resolved.can_dsp_ts = msg.can_dsp_ts;
    }
    else {
      resolved.can_dsp_ts = 0
    }

    return resolved;
    }
};

module.exports = esrsrr;
