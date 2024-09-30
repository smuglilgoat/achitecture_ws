// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ehSpotCoordGeo = require('./ehSpotCoordGeo.js');
let ehSegmentME = require('./ehSegmentME.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ehME {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.ehSpotCoordGeo = null;
      this.NbrSpotCoordGeo = null;
      this.ehSegmentME = null;
      this.QtySegment = null;
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
      if (initObj.hasOwnProperty('ehSpotCoordGeo')) {
        this.ehSpotCoordGeo = initObj.ehSpotCoordGeo
      }
      else {
        this.ehSpotCoordGeo = new Array(2000).fill(new ehSpotCoordGeo());
      }
      if (initObj.hasOwnProperty('NbrSpotCoordGeo')) {
        this.NbrSpotCoordGeo = initObj.NbrSpotCoordGeo
      }
      else {
        this.NbrSpotCoordGeo = new std_msgs.msg.UInt32();
      }
      if (initObj.hasOwnProperty('ehSegmentME')) {
        this.ehSegmentME = initObj.ehSegmentME
      }
      else {
        this.ehSegmentME = new Array(100).fill(new ehSegmentME());
      }
      if (initObj.hasOwnProperty('QtySegment')) {
        this.QtySegment = initObj.QtySegment
      }
      else {
        this.QtySegment = new std_msgs.msg.UInt32();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ehME
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Check that the constant length array field [ehSpotCoordGeo] has the right length
    if (obj.ehSpotCoordGeo.length !== 2000) {
      throw new Error('Unable to serialize array field ehSpotCoordGeo - length must be 2000')
    }
    // Serialize message field [ehSpotCoordGeo]
    obj.ehSpotCoordGeo.forEach((val) => {
      bufferOffset = ehSpotCoordGeo.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [NbrSpotCoordGeo]
    bufferOffset = std_msgs.msg.UInt32.serialize(obj.NbrSpotCoordGeo, buffer, bufferOffset);
    // Check that the constant length array field [ehSegmentME] has the right length
    if (obj.ehSegmentME.length !== 100) {
      throw new Error('Unable to serialize array field ehSegmentME - length must be 100')
    }
    // Serialize message field [ehSegmentME]
    obj.ehSegmentME.forEach((val) => {
      bufferOffset = ehSegmentME.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [QtySegment]
    bufferOffset = std_msgs.msg.UInt32.serialize(obj.QtySegment, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ehME
    let len;
    let data = new ehME(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehSpotCoordGeo]
    len = 2000;
    data.ehSpotCoordGeo = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehSpotCoordGeo[i] = ehSpotCoordGeo.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [NbrSpotCoordGeo]
    data.NbrSpotCoordGeo = std_msgs.msg.UInt32.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehSegmentME]
    len = 100;
    data.ehSegmentME = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehSegmentME[i] = ehSegmentME.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [QtySegment]
    data.QtySegment = std_msgs.msg.UInt32.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.ehSpotCoordGeo.forEach((val) => {
      length += ehSpotCoordGeo.getMessageSize(val);
    });
    object.ehSegmentME.forEach((val) => {
      length += ehSegmentME.getMessageSize(val);
    });
    return length + 9;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ehME';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e863f3ecd7a3f6b54ef653190281ff51';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    uint32 SPOT_REPORT_SIZE = 2000
    project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo
    std_msgs/UInt32 NbrSpotCoordGeo
    
    uint32 SEGMENT_ME_REPORT_SIZE = 100
    project_s_msgs/ehSegmentME[100] ehSegmentME
    std_msgs/UInt32 QtySegment
    
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
    MSG: project_s_msgs/ehSpotCoordGeo
    Header header
    std_msgs/UInt8 id
    
    std_msgs/Float32 offset
    float64 latitude
    float64 longitude
    
    
    
    ================================================================================
    MSG: std_msgs/Float32
    float32 data
    ================================================================================
    MSG: std_msgs/UInt32
    uint32 data
    ================================================================================
    MSG: project_s_msgs/ehSegmentME
    Header header
    std_msgs/UInt8 id
    
    std_msgs/UInt32 NbrSpot
    std_msgs/Float32 offset_debut
    std_msgs/Float32 offset_fin
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ehME(null);
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

    if (msg.ehSpotCoordGeo !== undefined) {
      resolved.ehSpotCoordGeo = new Array(2000)
      for (let i = 0; i < resolved.ehSpotCoordGeo.length; ++i) {
        if (msg.ehSpotCoordGeo.length > i) {
          resolved.ehSpotCoordGeo[i] = ehSpotCoordGeo.Resolve(msg.ehSpotCoordGeo[i]);
        }
        else {
          resolved.ehSpotCoordGeo[i] = new ehSpotCoordGeo();
        }
      }
    }
    else {
      resolved.ehSpotCoordGeo = new Array(2000).fill(new ehSpotCoordGeo())
    }

    if (msg.NbrSpotCoordGeo !== undefined) {
      resolved.NbrSpotCoordGeo = std_msgs.msg.UInt32.Resolve(msg.NbrSpotCoordGeo)
    }
    else {
      resolved.NbrSpotCoordGeo = new std_msgs.msg.UInt32()
    }

    if (msg.ehSegmentME !== undefined) {
      resolved.ehSegmentME = new Array(100)
      for (let i = 0; i < resolved.ehSegmentME.length; ++i) {
        if (msg.ehSegmentME.length > i) {
          resolved.ehSegmentME[i] = ehSegmentME.Resolve(msg.ehSegmentME[i]);
        }
        else {
          resolved.ehSegmentME[i] = new ehSegmentME();
        }
      }
    }
    else {
      resolved.ehSegmentME = new Array(100).fill(new ehSegmentME())
    }

    if (msg.QtySegment !== undefined) {
      resolved.QtySegment = std_msgs.msg.UInt32.Resolve(msg.QtySegment)
    }
    else {
      resolved.QtySegment = new std_msgs.msg.UInt32()
    }

    return resolved;
    }
};

// Constants for message
ehME.Constants = {
  SPOT_REPORT_SIZE: 2000,
  SEGMENT_ME_REPORT_SIZE: 100,
}

module.exports = ehME;
