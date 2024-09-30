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

class VehicleGuidance {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.driveBrakingTorque = null;
      this.steeringWheelAngle = null;
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
      if (initObj.hasOwnProperty('driveBrakingTorque')) {
        this.driveBrakingTorque = initObj.driveBrakingTorque
      }
      else {
        this.driveBrakingTorque = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('steeringWheelAngle')) {
        this.steeringWheelAngle = initObj.steeringWheelAngle
      }
      else {
        this.steeringWheelAngle = new std_msgs.msg.Float32();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type VehicleGuidance
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [driveBrakingTorque]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.driveBrakingTorque, buffer, bufferOffset);
    // Serialize message field [steeringWheelAngle]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.steeringWheelAngle, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type VehicleGuidance
    let len;
    let data = new VehicleGuidance(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [driveBrakingTorque]
    data.driveBrakingTorque = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [steeringWheelAngle]
    data.steeringWheelAngle = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 9;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/VehicleGuidance';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a30249730ffc4cf5ea06646bfb349079';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    std_msgs/Float32 driveBrakingTorque
    std_msgs/Float32 steeringWheelAngle
    
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
    const resolved = new VehicleGuidance(null);
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

    if (msg.driveBrakingTorque !== undefined) {
      resolved.driveBrakingTorque = std_msgs.msg.Float32.Resolve(msg.driveBrakingTorque)
    }
    else {
      resolved.driveBrakingTorque = new std_msgs.msg.Float32()
    }

    if (msg.steeringWheelAngle !== undefined) {
      resolved.steeringWheelAngle = std_msgs.msg.Float32.Resolve(msg.steeringWheelAngle)
    }
    else {
      resolved.steeringWheelAngle = new std_msgs.msg.Float32()
    }

    return resolved;
    }
};

module.exports = VehicleGuidance;
