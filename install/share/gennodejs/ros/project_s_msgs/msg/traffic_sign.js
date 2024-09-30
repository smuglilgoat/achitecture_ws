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

class traffic_sign {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.offset = null;
      this.Sign_Type = null;
      this.Value = null;
      this.Lane = null;
      this.Sign_Location = null;
      this.latitude = null;
      this.longitude = null;
    }
    else {
      if (initObj.hasOwnProperty('offset')) {
        this.offset = initObj.offset
      }
      else {
        this.offset = 0.0;
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
    // Serializes a message object of type traffic_sign
    // Serialize message field [offset]
    bufferOffset = _serializer.float32(obj.offset, buffer, bufferOffset);
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
    //deserializes a message object of type traffic_sign
    let len;
    let data = new traffic_sign(null);
    // Deserialize message field [offset]
    data.offset = _deserializer.float32(buffer, bufferOffset);
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
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/traffic_sign';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd26397acef9db1aa738fc0768aa46dd8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 offset
    uint8 Sign_Type
    uint8 Value
    uint8 Lane
    uint8 Sign_Location
    float64 latitude
    float64 longitude
    
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new traffic_sign(null);
    if (msg.offset !== undefined) {
      resolved.offset = msg.offset;
    }
    else {
      resolved.offset = 0.0
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

module.exports = traffic_sign;
