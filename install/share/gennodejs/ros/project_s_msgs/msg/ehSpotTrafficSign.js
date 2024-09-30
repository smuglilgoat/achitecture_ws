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

class ehSpotTrafficSign {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.offset = null;
      this.Sign_Type = null;
      this.Value = null;
      this.Lane = null;
      this.Sign_Location = null;
      this.latitude = null;
      this.longitude = null;
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
      if (initObj.hasOwnProperty('Sign_Type')) {
        this.Sign_Type = initObj.Sign_Type
      }
      else {
        this.Sign_Type = 0;
      }
      if (initObj.hasOwnProperty('Value')) {
        this.Value = initObj.Value
      }
      else {
        this.Value = 0;
      }
      if (initObj.hasOwnProperty('Lane')) {
        this.Lane = initObj.Lane
      }
      else {
        this.Lane = 0;
      }
      if (initObj.hasOwnProperty('Sign_Location')) {
        this.Sign_Location = initObj.Sign_Location
      }
      else {
        this.Sign_Location = 0;
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
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ehSpotTrafficSign
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [offset]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.offset, buffer, bufferOffset);
    // Serialize message field [Sign_Type]
    bufferOffset = _serializer.uint8(obj.Sign_Type, buffer, bufferOffset);
    // Serialize message field [Value]
    bufferOffset = _serializer.uint8(obj.Value, buffer, bufferOffset);
    // Serialize message field [Lane]
    bufferOffset = _serializer.uint8(obj.Lane, buffer, bufferOffset);
    // Serialize message field [Sign_Location]
    bufferOffset = _serializer.uint8(obj.Sign_Location, buffer, bufferOffset);
    // Serialize message field [latitude]
    bufferOffset = _serializer.float64(obj.latitude, buffer, bufferOffset);
    // Serialize message field [longitude]
    bufferOffset = _serializer.float64(obj.longitude, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ehSpotTrafficSign
    let len;
    let data = new ehSpotTrafficSign(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [offset]
    data.offset = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [Sign_Type]
    data.Sign_Type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [Value]
    data.Value = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [Lane]
    data.Lane = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [Sign_Location]
    data.Sign_Location = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [latitude]
    data.latitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [longitude]
    data.longitude = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 25;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ehSpotTrafficSign';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'af1c38cf4ea201cb74580c0ad2e95c49';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    std_msgs/Float32 offset
    uint8 Sign_Type
    uint8 Value
    uint8 Lane
    uint8 Sign_Location
    float64 latitude
    float64 longitude
    
    
    
    
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
    const resolved = new ehSpotTrafficSign(null);
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

    if (msg.Sign_Type !== undefined) {
      resolved.Sign_Type = msg.Sign_Type;
    }
    else {
      resolved.Sign_Type = 0
    }

    if (msg.Value !== undefined) {
      resolved.Value = msg.Value;
    }
    else {
      resolved.Value = 0
    }

    if (msg.Lane !== undefined) {
      resolved.Lane = msg.Lane;
    }
    else {
      resolved.Lane = 0
    }

    if (msg.Sign_Location !== undefined) {
      resolved.Sign_Location = msg.Sign_Location;
    }
    else {
      resolved.Sign_Location = 0
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

    return resolved;
    }
};

module.exports = ehSpotTrafficSign;
