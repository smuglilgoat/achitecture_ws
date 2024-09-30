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

class MapMatching {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.link_ID = null;
      this.link_HEREtile_ID = null;
      this.Distance_Curviligne_Ego = null;
      this.latitude = null;
      this.longitude = null;
      this.cap = null;
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
      if (initObj.hasOwnProperty('link_ID')) {
        this.link_ID = initObj.link_ID
      }
      else {
        this.link_ID = new std_msgs.msg.UInt32();
      }
      if (initObj.hasOwnProperty('link_HEREtile_ID')) {
        this.link_HEREtile_ID = initObj.link_HEREtile_ID
      }
      else {
        this.link_HEREtile_ID = new std_msgs.msg.UInt32();
      }
      if (initObj.hasOwnProperty('Distance_Curviligne_Ego')) {
        this.Distance_Curviligne_Ego = initObj.Distance_Curviligne_Ego
      }
      else {
        this.Distance_Curviligne_Ego = new std_msgs.msg.Float32();
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
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MapMatching
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [link_ID]
    bufferOffset = std_msgs.msg.UInt32.serialize(obj.link_ID, buffer, bufferOffset);
    // Serialize message field [link_HEREtile_ID]
    bufferOffset = std_msgs.msg.UInt32.serialize(obj.link_HEREtile_ID, buffer, bufferOffset);
    // Serialize message field [Distance_Curviligne_Ego]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.Distance_Curviligne_Ego, buffer, bufferOffset);
    // Serialize message field [latitude]
    bufferOffset = _serializer.float64(obj.latitude, buffer, bufferOffset);
    // Serialize message field [longitude]
    bufferOffset = _serializer.float64(obj.longitude, buffer, bufferOffset);
    // Serialize message field [cap]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.cap, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MapMatching
    let len;
    let data = new MapMatching(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [link_ID]
    data.link_ID = std_msgs.msg.UInt32.deserialize(buffer, bufferOffset);
    // Deserialize message field [link_HEREtile_ID]
    data.link_HEREtile_ID = std_msgs.msg.UInt32.deserialize(buffer, bufferOffset);
    // Deserialize message field [Distance_Curviligne_Ego]
    data.Distance_Curviligne_Ego = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [latitude]
    data.latitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [longitude]
    data.longitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [cap]
    data.cap = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 33;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/MapMatching';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '751b9780203e0387595b35e7afcb932c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    std_msgs/UInt32 link_ID
    std_msgs/UInt32 link_HEREtile_ID
    std_msgs/Float32 Distance_Curviligne_Ego
    float64 latitude
    float64 longitude
    std_msgs/Float32 cap
    
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
    MSG: std_msgs/UInt32
    uint32 data
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
    const resolved = new MapMatching(null);
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

    if (msg.link_ID !== undefined) {
      resolved.link_ID = std_msgs.msg.UInt32.Resolve(msg.link_ID)
    }
    else {
      resolved.link_ID = new std_msgs.msg.UInt32()
    }

    if (msg.link_HEREtile_ID !== undefined) {
      resolved.link_HEREtile_ID = std_msgs.msg.UInt32.Resolve(msg.link_HEREtile_ID)
    }
    else {
      resolved.link_HEREtile_ID = new std_msgs.msg.UInt32()
    }

    if (msg.Distance_Curviligne_Ego !== undefined) {
      resolved.Distance_Curviligne_Ego = std_msgs.msg.Float32.Resolve(msg.Distance_Curviligne_Ego)
    }
    else {
      resolved.Distance_Curviligne_Ego = new std_msgs.msg.Float32()
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

    return resolved;
    }
};

module.exports = MapMatching;
