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

class ehSegment {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.offset = null;
      this.functionRoadClass = null;
      this.wayForm = null;
      this.effectiveSpeedLimit = null;
      this.nbLanesDrivingDirection = null;
      this.nbLanesOppositeDirection = null;
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
      if (initObj.hasOwnProperty('functionRoadClass')) {
        this.functionRoadClass = initObj.functionRoadClass
      }
      else {
        this.functionRoadClass = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('wayForm')) {
        this.wayForm = initObj.wayForm
      }
      else {
        this.wayForm = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('effectiveSpeedLimit')) {
        this.effectiveSpeedLimit = initObj.effectiveSpeedLimit
      }
      else {
        this.effectiveSpeedLimit = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('nbLanesDrivingDirection')) {
        this.nbLanesDrivingDirection = initObj.nbLanesDrivingDirection
      }
      else {
        this.nbLanesDrivingDirection = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('nbLanesOppositeDirection')) {
        this.nbLanesOppositeDirection = initObj.nbLanesOppositeDirection
      }
      else {
        this.nbLanesOppositeDirection = new std_msgs.msg.UInt8();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ehSegment
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [offset]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.offset, buffer, bufferOffset);
    // Serialize message field [functionRoadClass]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.functionRoadClass, buffer, bufferOffset);
    // Serialize message field [wayForm]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.wayForm, buffer, bufferOffset);
    // Serialize message field [effectiveSpeedLimit]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.effectiveSpeedLimit, buffer, bufferOffset);
    // Serialize message field [nbLanesDrivingDirection]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.nbLanesDrivingDirection, buffer, bufferOffset);
    // Serialize message field [nbLanesOppositeDirection]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.nbLanesOppositeDirection, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ehSegment
    let len;
    let data = new ehSegment(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [offset]
    data.offset = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [functionRoadClass]
    data.functionRoadClass = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [wayForm]
    data.wayForm = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [effectiveSpeedLimit]
    data.effectiveSpeedLimit = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [nbLanesDrivingDirection]
    data.nbLanesDrivingDirection = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [nbLanesOppositeDirection]
    data.nbLanesOppositeDirection = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 10;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ehSegment';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6537588d17c4b8421cfde3df0a7fac39';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    #std_msgs/UInt8 indexPath
    std_msgs/Float32 offset
    std_msgs/UInt8 functionRoadClass
    std_msgs/UInt8 wayForm
    std_msgs/UInt8 effectiveSpeedLimit
    std_msgs/UInt8 nbLanesDrivingDirection
    std_msgs/UInt8 nbLanesOppositeDirection
    
    
    
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
    const resolved = new ehSegment(null);
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

    if (msg.functionRoadClass !== undefined) {
      resolved.functionRoadClass = std_msgs.msg.UInt8.Resolve(msg.functionRoadClass)
    }
    else {
      resolved.functionRoadClass = new std_msgs.msg.UInt8()
    }

    if (msg.wayForm !== undefined) {
      resolved.wayForm = std_msgs.msg.UInt8.Resolve(msg.wayForm)
    }
    else {
      resolved.wayForm = new std_msgs.msg.UInt8()
    }

    if (msg.effectiveSpeedLimit !== undefined) {
      resolved.effectiveSpeedLimit = std_msgs.msg.UInt8.Resolve(msg.effectiveSpeedLimit)
    }
    else {
      resolved.effectiveSpeedLimit = new std_msgs.msg.UInt8()
    }

    if (msg.nbLanesDrivingDirection !== undefined) {
      resolved.nbLanesDrivingDirection = std_msgs.msg.UInt8.Resolve(msg.nbLanesDrivingDirection)
    }
    else {
      resolved.nbLanesDrivingDirection = new std_msgs.msg.UInt8()
    }

    if (msg.nbLanesOppositeDirection !== undefined) {
      resolved.nbLanesOppositeDirection = std_msgs.msg.UInt8.Resolve(msg.nbLanesOppositeDirection)
    }
    else {
      resolved.nbLanesOppositeDirection = new std_msgs.msg.UInt8()
    }

    return resolved;
    }
};

module.exports = ehSegment;
