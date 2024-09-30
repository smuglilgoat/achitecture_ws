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

class ehPosition {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.offset = null;
      this.latitude = null;
      this.longitude = null;
      this.cap = null;
      this.agePosition = null;
      this.speed = null;
      this.relativeHeading = null;
      this.currentLane = null;
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
      if (initObj.hasOwnProperty('latitude')) {
        this.latitude = initObj.latitude
      }
      else {
        this.latitude = 0.0;
      }
      if (initObj.hasOwnProperty('longitude')) {
        this.longitude = initObj.longitude
      }
      else {
        this.longitude = 0.0;
      }
      if (initObj.hasOwnProperty('cap')) {
        this.cap = initObj.cap
      }
      else {
        this.cap = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('agePosition')) {
        this.agePosition = initObj.agePosition
      }
      else {
        this.agePosition = new std_msgs.msg.UInt16();
      }
      if (initObj.hasOwnProperty('speed')) {
        this.speed = initObj.speed
      }
      else {
        this.speed = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('relativeHeading')) {
        this.relativeHeading = initObj.relativeHeading
      }
      else {
        this.relativeHeading = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('currentLane')) {
        this.currentLane = initObj.currentLane
      }
      else {
        this.currentLane = new std_msgs.msg.UInt8();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ehPosition
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [offset]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.offset, buffer, bufferOffset);
    // Serialize message field [latitude]
    bufferOffset = _serializer.float64(obj.latitude, buffer, bufferOffset);
    // Serialize message field [longitude]
    bufferOffset = _serializer.float64(obj.longitude, buffer, bufferOffset);
    // Serialize message field [cap]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.cap, buffer, bufferOffset);
    // Serialize message field [agePosition]
    bufferOffset = std_msgs.msg.UInt16.serialize(obj.agePosition, buffer, bufferOffset);
    // Serialize message field [speed]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.speed, buffer, bufferOffset);
    // Serialize message field [relativeHeading]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.relativeHeading, buffer, bufferOffset);
    // Serialize message field [currentLane]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.currentLane, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ehPosition
    let len;
    let data = new ehPosition(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [offset]
    data.offset = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [latitude]
    data.latitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [longitude]
    data.longitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [cap]
    data.cap = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [agePosition]
    data.agePosition = std_msgs.msg.UInt16.deserialize(buffer, bufferOffset);
    // Deserialize message field [speed]
    data.speed = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [relativeHeading]
    data.relativeHeading = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [currentLane]
    data.currentLane = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 36;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ehPosition';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '834273fcaebed780b99909cf00aa6ac8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    #std_msgs/UInt8 indexPath
    std_msgs/Float32 offset
    float64 latitude
    float64 longitude
    std_msgs/Float32 cap
    std_msgs/UInt16 agePosition
    std_msgs/Float32 speed
    std_msgs/Float32 relativeHeading
    std_msgs/UInt8 currentLane
    
    
    
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
    ================================================================================
    MSG: std_msgs/UInt16
    uint16 data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ehPosition(null);
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

    if (msg.latitude !== undefined) {
      resolved.latitude = msg.latitude;
    }
    else {
      resolved.latitude = 0.0
    }

    if (msg.longitude !== undefined) {
      resolved.longitude = msg.longitude;
    }
    else {
      resolved.longitude = 0.0
    }

    if (msg.cap !== undefined) {
      resolved.cap = std_msgs.msg.Float32.Resolve(msg.cap)
    }
    else {
      resolved.cap = new std_msgs.msg.Float32()
    }

    if (msg.agePosition !== undefined) {
      resolved.agePosition = std_msgs.msg.UInt16.Resolve(msg.agePosition)
    }
    else {
      resolved.agePosition = new std_msgs.msg.UInt16()
    }

    if (msg.speed !== undefined) {
      resolved.speed = std_msgs.msg.Float32.Resolve(msg.speed)
    }
    else {
      resolved.speed = new std_msgs.msg.Float32()
    }

    if (msg.relativeHeading !== undefined) {
      resolved.relativeHeading = std_msgs.msg.Float32.Resolve(msg.relativeHeading)
    }
    else {
      resolved.relativeHeading = new std_msgs.msg.Float32()
    }

    if (msg.currentLane !== undefined) {
      resolved.currentLane = std_msgs.msg.UInt8.Resolve(msg.currentLane)
    }
    else {
      resolved.currentLane = new std_msgs.msg.UInt8()
    }

    return resolved;
    }
};

module.exports = ehPosition;
