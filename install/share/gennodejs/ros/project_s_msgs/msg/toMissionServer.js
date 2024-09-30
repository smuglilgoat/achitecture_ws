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

class toMissionServer {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.idCar = null;
      this.state = null;
      this.mode = null;
      this.lat = null;
      this.lng = null;
      this.url = null;
      this.data = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('idCar')) {
        this.idCar = initObj.idCar
      }
      else {
        this.idCar = 0;
      }
      if (initObj.hasOwnProperty('state')) {
        this.state = initObj.state
      }
      else {
        this.state = 0;
      }
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = 0;
      }
      if (initObj.hasOwnProperty('lat')) {
        this.lat = initObj.lat
      }
      else {
        this.lat = '';
      }
      if (initObj.hasOwnProperty('lng')) {
        this.lng = initObj.lng
      }
      else {
        this.lng = '';
      }
      if (initObj.hasOwnProperty('url')) {
        this.url = initObj.url
      }
      else {
        this.url = '';
      }
      if (initObj.hasOwnProperty('data')) {
        this.data = initObj.data
      }
      else {
        this.data = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type toMissionServer
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [idCar]
    bufferOffset = _serializer.uint32(obj.idCar, buffer, bufferOffset);
    // Serialize message field [state]
    bufferOffset = _serializer.uint8(obj.state, buffer, bufferOffset);
    // Serialize message field [mode]
    bufferOffset = _serializer.uint8(obj.mode, buffer, bufferOffset);
    // Serialize message field [lat]
    bufferOffset = _serializer.string(obj.lat, buffer, bufferOffset);
    // Serialize message field [lng]
    bufferOffset = _serializer.string(obj.lng, buffer, bufferOffset);
    // Serialize message field [url]
    bufferOffset = _serializer.string(obj.url, buffer, bufferOffset);
    // Serialize message field [data]
    bufferOffset = _serializer.string(obj.data, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type toMissionServer
    let len;
    let data = new toMissionServer(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [idCar]
    data.idCar = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [state]
    data.state = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [mode]
    data.mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [lat]
    data.lat = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [lng]
    data.lng = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [url]
    data.url = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [data]
    data.data = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += object.lat.length;
    length += object.lng.length;
    length += object.url.length;
    length += object.data.length;
    return length + 22;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/toMissionServer';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '899b1544a91b69b2992d0ca875040be0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header				# Contains ROS timestamp, sequence & frame id			
    
    uint32 idCar				# Car Identification Number
    
    uint8 state				# Car status to server 
    uint8 UNAVAILABLE=0
    uint8 WAITING=1
    uint8 NAVIGATING=2
    uint8 ENDING=3
    uint8 SLEEPING=4
    
    uint8 mode
    uint8 ARDUINOMODE=0
    uint8 TRANSPARENTMODE=1
    uint8 BYFIELDMODE=2
    
    string lat				# Car position latitude
    string lng				# Car position longitude
    
    string url
    string data
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new toMissionServer(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.idCar !== undefined) {
      resolved.idCar = msg.idCar;
    }
    else {
      resolved.idCar = 0
    }

    if (msg.state !== undefined) {
      resolved.state = msg.state;
    }
    else {
      resolved.state = 0
    }

    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = 0
    }

    if (msg.lat !== undefined) {
      resolved.lat = msg.lat;
    }
    else {
      resolved.lat = ''
    }

    if (msg.lng !== undefined) {
      resolved.lng = msg.lng;
    }
    else {
      resolved.lng = ''
    }

    if (msg.url !== undefined) {
      resolved.url = msg.url;
    }
    else {
      resolved.url = ''
    }

    if (msg.data !== undefined) {
      resolved.data = msg.data;
    }
    else {
      resolved.data = ''
    }

    return resolved;
    }
};

// Constants for message
toMissionServer.Constants = {
  UNAVAILABLE: 0,
  WAITING: 1,
  NAVIGATING: 2,
  ENDING: 3,
  SLEEPING: 4,
  ARDUINOMODE: 0,
  TRANSPARENTMODE: 1,
  BYFIELDMODE: 2,
}

module.exports = toMissionServer;
