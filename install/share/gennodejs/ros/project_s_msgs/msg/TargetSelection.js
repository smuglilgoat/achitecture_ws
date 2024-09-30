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

class TargetSelection {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.indexLane = null;
      this.targetDirection = null;
      this.targetDirectionProbability = null;
      this.distance = null;
      this.speed = null;
      this.timeToCollision = null;
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
      if (initObj.hasOwnProperty('indexLane')) {
        this.indexLane = initObj.indexLane
      }
      else {
        this.indexLane = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('targetDirection')) {
        this.targetDirection = initObj.targetDirection
      }
      else {
        this.targetDirection = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('targetDirectionProbability')) {
        this.targetDirectionProbability = initObj.targetDirectionProbability
      }
      else {
        this.targetDirectionProbability = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('distance')) {
        this.distance = initObj.distance
      }
      else {
        this.distance = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('speed')) {
        this.speed = initObj.speed
      }
      else {
        this.speed = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('timeToCollision')) {
        this.timeToCollision = initObj.timeToCollision
      }
      else {
        this.timeToCollision = new std_msgs.msg.Float32();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type TargetSelection
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [indexLane]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.indexLane, buffer, bufferOffset);
    // Serialize message field [targetDirection]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.targetDirection, buffer, bufferOffset);
    // Serialize message field [targetDirectionProbability]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.targetDirectionProbability, buffer, bufferOffset);
    // Serialize message field [distance]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.distance, buffer, bufferOffset);
    // Serialize message field [speed]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.speed, buffer, bufferOffset);
    // Serialize message field [timeToCollision]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.timeToCollision, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type TargetSelection
    let len;
    let data = new TargetSelection(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [indexLane]
    data.indexLane = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [targetDirection]
    data.targetDirection = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [targetDirectionProbability]
    data.targetDirectionProbability = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [distance]
    data.distance = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [speed]
    data.speed = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [timeToCollision]
    data.timeToCollision = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/TargetSelection';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd3f1ac60f8428b7cd019b0bb611a0a65';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    std_msgs/UInt8 indexLane
    std_msgs/UInt8 targetDirection
    std_msgs/UInt8 targetDirectionProbability
    std_msgs/Float32 distance
    std_msgs/Float32 speed
    std_msgs/Float32 timeToCollision
    
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
    const resolved = new TargetSelection(null);
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

    if (msg.indexLane !== undefined) {
      resolved.indexLane = std_msgs.msg.UInt8.Resolve(msg.indexLane)
    }
    else {
      resolved.indexLane = new std_msgs.msg.UInt8()
    }

    if (msg.targetDirection !== undefined) {
      resolved.targetDirection = std_msgs.msg.UInt8.Resolve(msg.targetDirection)
    }
    else {
      resolved.targetDirection = new std_msgs.msg.UInt8()
    }

    if (msg.targetDirectionProbability !== undefined) {
      resolved.targetDirectionProbability = std_msgs.msg.UInt8.Resolve(msg.targetDirectionProbability)
    }
    else {
      resolved.targetDirectionProbability = new std_msgs.msg.UInt8()
    }

    if (msg.distance !== undefined) {
      resolved.distance = std_msgs.msg.Float32.Resolve(msg.distance)
    }
    else {
      resolved.distance = new std_msgs.msg.Float32()
    }

    if (msg.speed !== undefined) {
      resolved.speed = std_msgs.msg.Float32.Resolve(msg.speed)
    }
    else {
      resolved.speed = new std_msgs.msg.Float32()
    }

    if (msg.timeToCollision !== undefined) {
      resolved.timeToCollision = std_msgs.msg.Float32.Resolve(msg.timeToCollision)
    }
    else {
      resolved.timeToCollision = new std_msgs.msg.Float32()
    }

    return resolved;
    }
};

module.exports = TargetSelection;
