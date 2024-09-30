// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let EgoData = require('./EgoData.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class EgoDataReport {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.EgoData = null;
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
      if (initObj.hasOwnProperty('EgoData')) {
        this.EgoData = initObj.EgoData
      }
      else {
        this.EgoData = new Array(10).fill(new EgoData());
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type EgoDataReport
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Check that the constant length array field [EgoData] has the right length
    if (obj.EgoData.length !== 10) {
      throw new Error('Unable to serialize array field EgoData - length must be 10')
    }
    // Serialize message field [EgoData]
    obj.EgoData.forEach((val) => {
      bufferOffset = EgoData.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type EgoDataReport
    let len;
    let data = new EgoDataReport(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [EgoData]
    len = 10;
    data.EgoData = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.EgoData[i] = EgoData.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 1241;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/EgoDataReport';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4c22f2f7b4f8443a0c599fc0f8a1800a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    uint8 NBR_MAX_EGO_DATA = 10
    project_s_msgs/EgoData[10] EgoData	# en concordance avec NBR_MAX_EGO_DATA/vehicle.cpp, local_tracks_synchro, global_tracks_prediction, road_model
    
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
    MSG: project_s_msgs/EgoData
    time stamp
    
    geometry_msgs/Twist velocity
    geometry_msgs/Accel acceleration
    
    float64 latitude
    float64 longitude
    float32 cap
    
    
    ================================================================================
    MSG: geometry_msgs/Twist
    # This expresses velocity in free space broken into its linear and angular parts.
    Vector3  linear
    Vector3  angular
    
    ================================================================================
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    ================================================================================
    MSG: geometry_msgs/Accel
    # This expresses acceleration in free space broken into its linear and angular parts.
    Vector3  linear
    Vector3  angular
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new EgoDataReport(null);
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

    if (msg.EgoData !== undefined) {
      resolved.EgoData = new Array(10)
      for (let i = 0; i < resolved.EgoData.length; ++i) {
        if (msg.EgoData.length > i) {
          resolved.EgoData[i] = EgoData.Resolve(msg.EgoData[i]);
        }
        else {
          resolved.EgoData[i] = new EgoData();
        }
      }
    }
    else {
      resolved.EgoData = new Array(10).fill(new EgoData())
    }

    return resolved;
    }
};

// Constants for message
EgoDataReport.Constants = {
  NBR_MAX_EGO_DATA: 10,
}

module.exports = EgoDataReport;
