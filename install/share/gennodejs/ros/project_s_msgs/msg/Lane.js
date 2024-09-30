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

class Lane {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.idLineRight = null;
      this.idLineLeft = null;
      this.offsetStart = null;
      this.offsetEnd = null;
      this.trafficDirection = null;
      this.priority = null;
      this.speedLimit = null;
      this.TrafficSign = null;
      this.turnOffset = null;
      this.turnRadius = null;
      this.crossRoadClass = null;
      this.crossRoadOffset = null;
      this.crossRoadPriority = null;
    }
    else {
      if (initObj.hasOwnProperty('idLineRight')) {
        this.idLineRight = initObj.idLineRight
      }
      else {
        this.idLineRight = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('idLineLeft')) {
        this.idLineLeft = initObj.idLineLeft
      }
      else {
        this.idLineLeft = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('offsetStart')) {
        this.offsetStart = initObj.offsetStart
      }
      else {
        this.offsetStart = 0;
      }
      if (initObj.hasOwnProperty('offsetEnd')) {
        this.offsetEnd = initObj.offsetEnd
      }
      else {
        this.offsetEnd = 0;
      }
      if (initObj.hasOwnProperty('trafficDirection')) {
        this.trafficDirection = initObj.trafficDirection
      }
      else {
        this.trafficDirection = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('priority')) {
        this.priority = initObj.priority
      }
      else {
        this.priority = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('speedLimit')) {
        this.speedLimit = initObj.speedLimit
      }
      else {
        this.speedLimit = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('TrafficSign')) {
        this.TrafficSign = initObj.TrafficSign
      }
      else {
        this.TrafficSign = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('turnOffset')) {
        this.turnOffset = initObj.turnOffset
      }
      else {
        this.turnOffset = 0;
      }
      if (initObj.hasOwnProperty('turnRadius')) {
        this.turnRadius = initObj.turnRadius
      }
      else {
        this.turnRadius = 0.0;
      }
      if (initObj.hasOwnProperty('crossRoadClass')) {
        this.crossRoadClass = initObj.crossRoadClass
      }
      else {
        this.crossRoadClass = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('crossRoadOffset')) {
        this.crossRoadOffset = initObj.crossRoadOffset
      }
      else {
        this.crossRoadOffset = 0;
      }
      if (initObj.hasOwnProperty('crossRoadPriority')) {
        this.crossRoadPriority = initObj.crossRoadPriority
      }
      else {
        this.crossRoadPriority = new std_msgs.msg.UInt8();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Lane
    // Serialize message field [idLineRight]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.idLineRight, buffer, bufferOffset);
    // Serialize message field [idLineLeft]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.idLineLeft, buffer, bufferOffset);
    // Serialize message field [offsetStart]
    bufferOffset = _serializer.int16(obj.offsetStart, buffer, bufferOffset);
    // Serialize message field [offsetEnd]
    bufferOffset = _serializer.int16(obj.offsetEnd, buffer, bufferOffset);
    // Serialize message field [trafficDirection]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.trafficDirection, buffer, bufferOffset);
    // Serialize message field [priority]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.priority, buffer, bufferOffset);
    // Serialize message field [speedLimit]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.speedLimit, buffer, bufferOffset);
    // Serialize message field [TrafficSign]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.TrafficSign, buffer, bufferOffset);
    // Serialize message field [turnOffset]
    bufferOffset = _serializer.int16(obj.turnOffset, buffer, bufferOffset);
    // Serialize message field [turnRadius]
    bufferOffset = _serializer.float32(obj.turnRadius, buffer, bufferOffset);
    // Serialize message field [crossRoadClass]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.crossRoadClass, buffer, bufferOffset);
    // Serialize message field [crossRoadOffset]
    bufferOffset = _serializer.int16(obj.crossRoadOffset, buffer, bufferOffset);
    // Serialize message field [crossRoadPriority]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.crossRoadPriority, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Lane
    let len;
    let data = new Lane(null);
    // Deserialize message field [idLineRight]
    data.idLineRight = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [idLineLeft]
    data.idLineLeft = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [offsetStart]
    data.offsetStart = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [offsetEnd]
    data.offsetEnd = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [trafficDirection]
    data.trafficDirection = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [priority]
    data.priority = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [speedLimit]
    data.speedLimit = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [TrafficSign]
    data.TrafficSign = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [turnOffset]
    data.turnOffset = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [turnRadius]
    data.turnRadius = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [crossRoadClass]
    data.crossRoadClass = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [crossRoadOffset]
    data.crossRoadOffset = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [crossRoadPriority]
    data.crossRoadPriority = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/Lane';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ac4b37c308258de2eff999751d19fd39';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/UInt8 idLineRight
    std_msgs/UInt8 idLineLeft
    int16 offsetStart
    int16 offsetEnd
    std_msgs/UInt8 trafficDirection
    std_msgs/UInt8 priority
    std_msgs/UInt8 speedLimit
    std_msgs/UInt8 TrafficSign
    int16 turnOffset
    float32 turnRadius
    std_msgs/UInt8 crossRoadClass
    int16 crossRoadOffset
    std_msgs/UInt8 crossRoadPriority
    
    
    
    
    
    
    
    
    ================================================================================
    MSG: std_msgs/UInt8
    uint8 data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Lane(null);
    if (msg.idLineRight !== undefined) {
      resolved.idLineRight = std_msgs.msg.UInt8.Resolve(msg.idLineRight)
    }
    else {
      resolved.idLineRight = new std_msgs.msg.UInt8()
    }

    if (msg.idLineLeft !== undefined) {
      resolved.idLineLeft = std_msgs.msg.UInt8.Resolve(msg.idLineLeft)
    }
    else {
      resolved.idLineLeft = new std_msgs.msg.UInt8()
    }

    if (msg.offsetStart !== undefined) {
      resolved.offsetStart = msg.offsetStart;
    }
    else {
      resolved.offsetStart = 0
    }

    if (msg.offsetEnd !== undefined) {
      resolved.offsetEnd = msg.offsetEnd;
    }
    else {
      resolved.offsetEnd = 0
    }

    if (msg.trafficDirection !== undefined) {
      resolved.trafficDirection = std_msgs.msg.UInt8.Resolve(msg.trafficDirection)
    }
    else {
      resolved.trafficDirection = new std_msgs.msg.UInt8()
    }

    if (msg.priority !== undefined) {
      resolved.priority = std_msgs.msg.UInt8.Resolve(msg.priority)
    }
    else {
      resolved.priority = new std_msgs.msg.UInt8()
    }

    if (msg.speedLimit !== undefined) {
      resolved.speedLimit = std_msgs.msg.UInt8.Resolve(msg.speedLimit)
    }
    else {
      resolved.speedLimit = new std_msgs.msg.UInt8()
    }

    if (msg.TrafficSign !== undefined) {
      resolved.TrafficSign = std_msgs.msg.UInt8.Resolve(msg.TrafficSign)
    }
    else {
      resolved.TrafficSign = new std_msgs.msg.UInt8()
    }

    if (msg.turnOffset !== undefined) {
      resolved.turnOffset = msg.turnOffset;
    }
    else {
      resolved.turnOffset = 0
    }

    if (msg.turnRadius !== undefined) {
      resolved.turnRadius = msg.turnRadius;
    }
    else {
      resolved.turnRadius = 0.0
    }

    if (msg.crossRoadClass !== undefined) {
      resolved.crossRoadClass = std_msgs.msg.UInt8.Resolve(msg.crossRoadClass)
    }
    else {
      resolved.crossRoadClass = new std_msgs.msg.UInt8()
    }

    if (msg.crossRoadOffset !== undefined) {
      resolved.crossRoadOffset = msg.crossRoadOffset;
    }
    else {
      resolved.crossRoadOffset = 0
    }

    if (msg.crossRoadPriority !== undefined) {
      resolved.crossRoadPriority = std_msgs.msg.UInt8.Resolve(msg.crossRoadPriority)
    }
    else {
      resolved.crossRoadPriority = new std_msgs.msg.UInt8()
    }

    return resolved;
    }
};

module.exports = Lane;
