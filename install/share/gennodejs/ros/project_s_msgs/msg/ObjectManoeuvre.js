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

class ObjectManoeuvre {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.indexOriginLane = null;
      this.objectManoeuvre = null;
      this.objectSignalisation = null;
      this.objectPrediction = null;
      this.objectPredictionProbability = null;
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
      if (initObj.hasOwnProperty('indexOriginLane')) {
        this.indexOriginLane = initObj.indexOriginLane
      }
      else {
        this.indexOriginLane = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('objectManoeuvre')) {
        this.objectManoeuvre = initObj.objectManoeuvre
      }
      else {
        this.objectManoeuvre = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('objectSignalisation')) {
        this.objectSignalisation = initObj.objectSignalisation
      }
      else {
        this.objectSignalisation = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('objectPrediction')) {
        this.objectPrediction = initObj.objectPrediction
      }
      else {
        this.objectPrediction = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('objectPredictionProbability')) {
        this.objectPredictionProbability = initObj.objectPredictionProbability
      }
      else {
        this.objectPredictionProbability = new std_msgs.msg.UInt8();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ObjectManoeuvre
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [indexOriginLane]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.indexOriginLane, buffer, bufferOffset);
    // Serialize message field [objectManoeuvre]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.objectManoeuvre, buffer, bufferOffset);
    // Serialize message field [objectSignalisation]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.objectSignalisation, buffer, bufferOffset);
    // Serialize message field [objectPrediction]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.objectPrediction, buffer, bufferOffset);
    // Serialize message field [objectPredictionProbability]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.objectPredictionProbability, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObjectManoeuvre
    let len;
    let data = new ObjectManoeuvre(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [indexOriginLane]
    data.indexOriginLane = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [objectManoeuvre]
    data.objectManoeuvre = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [objectSignalisation]
    data.objectSignalisation = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [objectPrediction]
    data.objectPrediction = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [objectPredictionProbability]
    data.objectPredictionProbability = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ObjectManoeuvre';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fa042f189b42a91d1a2d603726c850b7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    std_msgs/UInt8 indexOriginLane
    std_msgs/UInt8 objectManoeuvre
    std_msgs/UInt8 objectSignalisation
    std_msgs/UInt8 objectPrediction
    std_msgs/UInt8 objectPredictionProbability
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ObjectManoeuvre(null);
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

    if (msg.indexOriginLane !== undefined) {
      resolved.indexOriginLane = std_msgs.msg.UInt8.Resolve(msg.indexOriginLane)
    }
    else {
      resolved.indexOriginLane = new std_msgs.msg.UInt8()
    }

    if (msg.objectManoeuvre !== undefined) {
      resolved.objectManoeuvre = std_msgs.msg.UInt8.Resolve(msg.objectManoeuvre)
    }
    else {
      resolved.objectManoeuvre = new std_msgs.msg.UInt8()
    }

    if (msg.objectSignalisation !== undefined) {
      resolved.objectSignalisation = std_msgs.msg.UInt8.Resolve(msg.objectSignalisation)
    }
    else {
      resolved.objectSignalisation = new std_msgs.msg.UInt8()
    }

    if (msg.objectPrediction !== undefined) {
      resolved.objectPrediction = std_msgs.msg.UInt8.Resolve(msg.objectPrediction)
    }
    else {
      resolved.objectPrediction = new std_msgs.msg.UInt8()
    }

    if (msg.objectPredictionProbability !== undefined) {
      resolved.objectPredictionProbability = std_msgs.msg.UInt8.Resolve(msg.objectPredictionProbability)
    }
    else {
      resolved.objectPredictionProbability = new std_msgs.msg.UInt8()
    }

    return resolved;
    }
};

module.exports = ObjectManoeuvre;
