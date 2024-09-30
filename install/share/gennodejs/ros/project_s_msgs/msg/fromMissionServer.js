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

class fromMissionServer {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.mode = null;
      this.err = null;
      this.msg = null;
      this.mission = null;
      this.idUser = null;
      this.errCode = null;
      this.idCar = null;
      this.stateCmd = null;
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
      if (initObj.hasOwnProperty('mode')) {
        this.mode = initObj.mode
      }
      else {
        this.mode = 0;
      }
      if (initObj.hasOwnProperty('err')) {
        this.err = initObj.err
      }
      else {
        this.err = false;
      }
      if (initObj.hasOwnProperty('msg')) {
        this.msg = initObj.msg
      }
      else {
        this.msg = '';
      }
      if (initObj.hasOwnProperty('mission')) {
        this.mission = initObj.mission
      }
      else {
        this.mission = 0;
      }
      if (initObj.hasOwnProperty('idUser')) {
        this.idUser = initObj.idUser
      }
      else {
        this.idUser = 0;
      }
      if (initObj.hasOwnProperty('errCode')) {
        this.errCode = initObj.errCode
      }
      else {
        this.errCode = 0;
      }
      if (initObj.hasOwnProperty('idCar')) {
        this.idCar = initObj.idCar
      }
      else {
        this.idCar = 0;
      }
      if (initObj.hasOwnProperty('stateCmd')) {
        this.stateCmd = initObj.stateCmd
      }
      else {
        this.stateCmd = 0;
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
    // Serializes a message object of type fromMissionServer
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [mode]
    bufferOffset = _serializer.uint8(obj.mode, buffer, bufferOffset);
    // Serialize message field [err]
    bufferOffset = _serializer.bool(obj.err, buffer, bufferOffset);
    // Serialize message field [msg]
    bufferOffset = _serializer.string(obj.msg, buffer, bufferOffset);
    // Serialize message field [mission]
    bufferOffset = _serializer.uint8(obj.mission, buffer, bufferOffset);
    // Serialize message field [idUser]
    bufferOffset = _serializer.uint32(obj.idUser, buffer, bufferOffset);
    // Serialize message field [errCode]
    bufferOffset = _serializer.uint8(obj.errCode, buffer, bufferOffset);
    // Serialize message field [idCar]
    bufferOffset = _serializer.uint32(obj.idCar, buffer, bufferOffset);
    // Serialize message field [stateCmd]
    bufferOffset = _serializer.uint8(obj.stateCmd, buffer, bufferOffset);
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
    //deserializes a message object of type fromMissionServer
    let len;
    let data = new fromMissionServer(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [mode]
    data.mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [err]
    data.err = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [msg]
    data.msg = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [mission]
    data.mission = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [idUser]
    data.idUser = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [errCode]
    data.errCode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [idCar]
    data.idCar = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [stateCmd]
    data.stateCmd = _deserializer.uint8(buffer, bufferOffset);
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
    length += object.msg.length;
    length += object.lat.length;
    length += object.lng.length;
    length += object.url.length;
    length += object.data.length;
    return length + 33;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/fromMissionServer';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1c5f3191cc67c5d61eb019c231f37790';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header				# Contains ROS timestamp, sequence & frame id
    
    uint8 mode
    uint8 ARDUINOMODE=0
    uint8 TRANSPARENTMODE=1
    uint8 BYFIELDMODE=2
    
    bool err				# Server msg error: false, true
    string msg				# text message (for information only)
    uint8 mission				# Track number
    uint32 idUser				# User Identification Number
    
    uint8 errCode				
    uint8 MissionSearchError=1
    uint8 NoMissionAvailable=2
    uint8 MissionAssignmentError=3
    uint8 ServerError=4
    
    uint32 idCar				# Car Identification Number
    
    uint8 stateCmd				# Car status echo & command from server
    uint8 UNAVAILABLE=0
    uint8 WAITING=1
    uint8 NAVIGATING=2
    uint8 ENDING=3
    uint8 SLEEPING=4
    uint8 WAKEUP=5
    uint8 NAVIGATE=6
    uint8 ENDOFNAV=7
    uint8 SLEEP=8
    
    string lat				# Car position latitude
    string lng				# Car position longitude
    
    string url				# Echo of the URL Request
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
    const resolved = new fromMissionServer(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.mode !== undefined) {
      resolved.mode = msg.mode;
    }
    else {
      resolved.mode = 0
    }

    if (msg.err !== undefined) {
      resolved.err = msg.err;
    }
    else {
      resolved.err = false
    }

    if (msg.msg !== undefined) {
      resolved.msg = msg.msg;
    }
    else {
      resolved.msg = ''
    }

    if (msg.mission !== undefined) {
      resolved.mission = msg.mission;
    }
    else {
      resolved.mission = 0
    }

    if (msg.idUser !== undefined) {
      resolved.idUser = msg.idUser;
    }
    else {
      resolved.idUser = 0
    }

    if (msg.errCode !== undefined) {
      resolved.errCode = msg.errCode;
    }
    else {
      resolved.errCode = 0
    }

    if (msg.idCar !== undefined) {
      resolved.idCar = msg.idCar;
    }
    else {
      resolved.idCar = 0
    }

    if (msg.stateCmd !== undefined) {
      resolved.stateCmd = msg.stateCmd;
    }
    else {
      resolved.stateCmd = 0
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
fromMissionServer.Constants = {
  ARDUINOMODE: 0,
  TRANSPARENTMODE: 1,
  BYFIELDMODE: 2,
  MISSIONSEARCHERROR: 1,
  NOMISSIONAVAILABLE: 2,
  MISSIONASSIGNMENTERROR: 3,
  SERVERERROR: 4,
  UNAVAILABLE: 0,
  WAITING: 1,
  NAVIGATING: 2,
  ENDING: 3,
  SLEEPING: 4,
  WAKEUP: 5,
  NAVIGATE: 6,
  ENDOFNAV: 7,
  SLEEP: 8,
}

module.exports = fromMissionServer;
