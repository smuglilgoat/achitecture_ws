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

class ehSegmentME {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.NbrSpot = null;
      this.offset_debut = null;
      this.offset_fin = null;
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
      if (initObj.hasOwnProperty('NbrSpot')) {
        this.NbrSpot = initObj.NbrSpot
      }
      else {
        this.NbrSpot = new std_msgs.msg.UInt32();
      }
      if (initObj.hasOwnProperty('offset_debut')) {
        this.offset_debut = initObj.offset_debut
      }
      else {
        this.offset_debut = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('offset_fin')) {
        this.offset_fin = initObj.offset_fin
      }
      else {
        this.offset_fin = new std_msgs.msg.Float32();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ehSegmentME
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [NbrSpot]
    bufferOffset = std_msgs.msg.UInt32.serialize(obj.NbrSpot, buffer, bufferOffset);
    // Serialize message field [offset_debut]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.offset_debut, buffer, bufferOffset);
    // Serialize message field [offset_fin]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.offset_fin, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ehSegmentME
    let len;
    let data = new ehSegmentME(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [NbrSpot]
    data.NbrSpot = std_msgs.msg.UInt32.deserialize(buffer, bufferOffset);
    // Deserialize message field [offset_debut]
    data.offset_debut = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [offset_fin]
    data.offset_fin = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 13;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ehSegmentME';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fc1755dbec2ea339a235fdf3e4d21311';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    std_msgs/UInt32 NbrSpot
    std_msgs/Float32 offset_debut
    std_msgs/Float32 offset_fin
    
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
    MSG: std_msgs/UInt32
    uint32 data
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
    const resolved = new ehSegmentME(null);
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

    if (msg.NbrSpot !== undefined) {
      resolved.NbrSpot = std_msgs.msg.UInt32.Resolve(msg.NbrSpot)
    }
    else {
      resolved.NbrSpot = new std_msgs.msg.UInt32()
    }

    if (msg.offset_debut !== undefined) {
      resolved.offset_debut = std_msgs.msg.Float32.Resolve(msg.offset_debut)
    }
    else {
      resolved.offset_debut = new std_msgs.msg.Float32()
    }

    if (msg.offset_fin !== undefined) {
      resolved.offset_fin = std_msgs.msg.Float32.Resolve(msg.offset_fin)
    }
    else {
      resolved.offset_fin = new std_msgs.msg.Float32()
    }

    return resolved;
    }
};

module.exports = ehSegmentME;
