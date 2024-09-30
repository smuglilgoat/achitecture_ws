// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ehSegment = require('./ehSegment.js');
let ehStub = require('./ehStub.js');
let ehSpotCurvature = require('./ehSpotCurvature.js');
let ehSpotCoordGeo = require('./ehSpotCoordGeo.js');
let ehLineCoordGeo = require('./ehLineCoordGeo.js');
let ehME = require('./ehME.js');
let ehNbrLineCoordGeo = require('./ehNbrLineCoordGeo.js');
let ehSpotTrafficSign = require('./ehSpotTrafficSign.js');
let ehPosition = require('./ehPosition.js');
let ehSegmentME = require('./ehSegmentME.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ElectronicHorizon {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.indexPath = null;
      this.ehSegment = null;
      this.NbrSegment = null;
      this.ehStub = null;
      this.NbrStub = null;
      this.ehSpotCurvature = null;
      this.NbrSpotCurvature = null;
      this.ehSpotCoordGeoRight = null;
      this.NbrSpotCoordGeoRight = null;
      this.ehSpotCoordGeoLeft = null;
      this.NbrSpotCoordGeoLeft = null;
      this.ehLineCoordGeo = null;
      this.QtyLineCoordGeo = null;
      this.ehME = null;
      this.ehNbrLineCoordGeo = null;
      this.QtyNbrLineCoordGeo = null;
      this.ehSpotTrafficSign = null;
      this.NbrSpotTrafficSign = null;
      this.ehPosition = null;
      this.speedLimit_interpolMethod = null;
      this.curvature_interpolMethod = null;
      this.ehSegmentAO = null;
      this.QtySegmentAO = null;
      this.ehSegmentEO = null;
      this.QtySegmentEO = null;
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
      if (initObj.hasOwnProperty('indexPath')) {
        this.indexPath = initObj.indexPath
      }
      else {
        this.indexPath = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('ehSegment')) {
        this.ehSegment = initObj.ehSegment
      }
      else {
        this.ehSegment = new Array(50).fill(new ehSegment());
      }
      if (initObj.hasOwnProperty('NbrSegment')) {
        this.NbrSegment = initObj.NbrSegment
      }
      else {
        this.NbrSegment = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('ehStub')) {
        this.ehStub = initObj.ehStub
      }
      else {
        this.ehStub = new Array(10).fill(new ehStub());
      }
      if (initObj.hasOwnProperty('NbrStub')) {
        this.NbrStub = initObj.NbrStub
      }
      else {
        this.NbrStub = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('ehSpotCurvature')) {
        this.ehSpotCurvature = initObj.ehSpotCurvature
      }
      else {
        this.ehSpotCurvature = new Array(300).fill(new ehSpotCurvature());
      }
      if (initObj.hasOwnProperty('NbrSpotCurvature')) {
        this.NbrSpotCurvature = initObj.NbrSpotCurvature
      }
      else {
        this.NbrSpotCurvature = new std_msgs.msg.UInt16();
      }
      if (initObj.hasOwnProperty('ehSpotCoordGeoRight')) {
        this.ehSpotCoordGeoRight = initObj.ehSpotCoordGeoRight
      }
      else {
        this.ehSpotCoordGeoRight = new Array(2000).fill(new ehSpotCoordGeo());
      }
      if (initObj.hasOwnProperty('NbrSpotCoordGeoRight')) {
        this.NbrSpotCoordGeoRight = initObj.NbrSpotCoordGeoRight
      }
      else {
        this.NbrSpotCoordGeoRight = new std_msgs.msg.UInt16();
      }
      if (initObj.hasOwnProperty('ehSpotCoordGeoLeft')) {
        this.ehSpotCoordGeoLeft = initObj.ehSpotCoordGeoLeft
      }
      else {
        this.ehSpotCoordGeoLeft = new Array(2000).fill(new ehSpotCoordGeo());
      }
      if (initObj.hasOwnProperty('NbrSpotCoordGeoLeft')) {
        this.NbrSpotCoordGeoLeft = initObj.NbrSpotCoordGeoLeft
      }
      else {
        this.NbrSpotCoordGeoLeft = new std_msgs.msg.UInt16();
      }
      if (initObj.hasOwnProperty('ehLineCoordGeo')) {
        this.ehLineCoordGeo = initObj.ehLineCoordGeo
      }
      else {
        this.ehLineCoordGeo = new Array(10).fill(new ehLineCoordGeo());
      }
      if (initObj.hasOwnProperty('QtyLineCoordGeo')) {
        this.QtyLineCoordGeo = initObj.QtyLineCoordGeo
      }
      else {
        this.QtyLineCoordGeo = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('ehME')) {
        this.ehME = initObj.ehME
      }
      else {
        this.ehME = new Array(2).fill(new ehME());
      }
      if (initObj.hasOwnProperty('ehNbrLineCoordGeo')) {
        this.ehNbrLineCoordGeo = initObj.ehNbrLineCoordGeo
      }
      else {
        this.ehNbrLineCoordGeo = new Array(100).fill(new ehNbrLineCoordGeo());
      }
      if (initObj.hasOwnProperty('QtyNbrLineCoordGeo')) {
        this.QtyNbrLineCoordGeo = initObj.QtyNbrLineCoordGeo
      }
      else {
        this.QtyNbrLineCoordGeo = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('ehSpotTrafficSign')) {
        this.ehSpotTrafficSign = initObj.ehSpotTrafficSign
      }
      else {
        this.ehSpotTrafficSign = new Array(50).fill(new ehSpotTrafficSign());
      }
      if (initObj.hasOwnProperty('NbrSpotTrafficSign')) {
        this.NbrSpotTrafficSign = initObj.NbrSpotTrafficSign
      }
      else {
        this.NbrSpotTrafficSign = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('ehPosition')) {
        this.ehPosition = initObj.ehPosition
      }
      else {
        this.ehPosition = new ehPosition();
      }
      if (initObj.hasOwnProperty('speedLimit_interpolMethod')) {
        this.speedLimit_interpolMethod = initObj.speedLimit_interpolMethod
      }
      else {
        this.speedLimit_interpolMethod = 0;
      }
      if (initObj.hasOwnProperty('curvature_interpolMethod')) {
        this.curvature_interpolMethod = initObj.curvature_interpolMethod
      }
      else {
        this.curvature_interpolMethod = 0;
      }
      if (initObj.hasOwnProperty('ehSegmentAO')) {
        this.ehSegmentAO = initObj.ehSegmentAO
      }
      else {
        this.ehSegmentAO = new Array(100).fill(new ehSegmentME());
      }
      if (initObj.hasOwnProperty('QtySegmentAO')) {
        this.QtySegmentAO = initObj.QtySegmentAO
      }
      else {
        this.QtySegmentAO = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('ehSegmentEO')) {
        this.ehSegmentEO = initObj.ehSegmentEO
      }
      else {
        this.ehSegmentEO = new Array(100).fill(new ehSegmentME());
      }
      if (initObj.hasOwnProperty('QtySegmentEO')) {
        this.QtySegmentEO = initObj.QtySegmentEO
      }
      else {
        this.QtySegmentEO = new std_msgs.msg.UInt8();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ElectronicHorizon
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [indexPath]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.indexPath, buffer, bufferOffset);
    // Check that the constant length array field [ehSegment] has the right length
    if (obj.ehSegment.length !== 50) {
      throw new Error('Unable to serialize array field ehSegment - length must be 50')
    }
    // Serialize message field [ehSegment]
    obj.ehSegment.forEach((val) => {
      bufferOffset = ehSegment.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [NbrSegment]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.NbrSegment, buffer, bufferOffset);
    // Check that the constant length array field [ehStub] has the right length
    if (obj.ehStub.length !== 10) {
      throw new Error('Unable to serialize array field ehStub - length must be 10')
    }
    // Serialize message field [ehStub]
    obj.ehStub.forEach((val) => {
      bufferOffset = ehStub.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [NbrStub]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.NbrStub, buffer, bufferOffset);
    // Check that the constant length array field [ehSpotCurvature] has the right length
    if (obj.ehSpotCurvature.length !== 300) {
      throw new Error('Unable to serialize array field ehSpotCurvature - length must be 300')
    }
    // Serialize message field [ehSpotCurvature]
    obj.ehSpotCurvature.forEach((val) => {
      bufferOffset = ehSpotCurvature.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [NbrSpotCurvature]
    bufferOffset = std_msgs.msg.UInt16.serialize(obj.NbrSpotCurvature, buffer, bufferOffset);
    // Check that the constant length array field [ehSpotCoordGeoRight] has the right length
    if (obj.ehSpotCoordGeoRight.length !== 2000) {
      throw new Error('Unable to serialize array field ehSpotCoordGeoRight - length must be 2000')
    }
    // Serialize message field [ehSpotCoordGeoRight]
    obj.ehSpotCoordGeoRight.forEach((val) => {
      bufferOffset = ehSpotCoordGeo.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [NbrSpotCoordGeoRight]
    bufferOffset = std_msgs.msg.UInt16.serialize(obj.NbrSpotCoordGeoRight, buffer, bufferOffset);
    // Check that the constant length array field [ehSpotCoordGeoLeft] has the right length
    if (obj.ehSpotCoordGeoLeft.length !== 2000) {
      throw new Error('Unable to serialize array field ehSpotCoordGeoLeft - length must be 2000')
    }
    // Serialize message field [ehSpotCoordGeoLeft]
    obj.ehSpotCoordGeoLeft.forEach((val) => {
      bufferOffset = ehSpotCoordGeo.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [NbrSpotCoordGeoLeft]
    bufferOffset = std_msgs.msg.UInt16.serialize(obj.NbrSpotCoordGeoLeft, buffer, bufferOffset);
    // Check that the constant length array field [ehLineCoordGeo] has the right length
    if (obj.ehLineCoordGeo.length !== 10) {
      throw new Error('Unable to serialize array field ehLineCoordGeo - length must be 10')
    }
    // Serialize message field [ehLineCoordGeo]
    obj.ehLineCoordGeo.forEach((val) => {
      bufferOffset = ehLineCoordGeo.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [QtyLineCoordGeo]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.QtyLineCoordGeo, buffer, bufferOffset);
    // Check that the constant length array field [ehME] has the right length
    if (obj.ehME.length !== 2) {
      throw new Error('Unable to serialize array field ehME - length must be 2')
    }
    // Serialize message field [ehME]
    obj.ehME.forEach((val) => {
      bufferOffset = ehME.serialize(val, buffer, bufferOffset);
    });
    // Check that the constant length array field [ehNbrLineCoordGeo] has the right length
    if (obj.ehNbrLineCoordGeo.length !== 100) {
      throw new Error('Unable to serialize array field ehNbrLineCoordGeo - length must be 100')
    }
    // Serialize message field [ehNbrLineCoordGeo]
    obj.ehNbrLineCoordGeo.forEach((val) => {
      bufferOffset = ehNbrLineCoordGeo.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [QtyNbrLineCoordGeo]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.QtyNbrLineCoordGeo, buffer, bufferOffset);
    // Check that the constant length array field [ehSpotTrafficSign] has the right length
    if (obj.ehSpotTrafficSign.length !== 50) {
      throw new Error('Unable to serialize array field ehSpotTrafficSign - length must be 50')
    }
    // Serialize message field [ehSpotTrafficSign]
    obj.ehSpotTrafficSign.forEach((val) => {
      bufferOffset = ehSpotTrafficSign.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [NbrSpotTrafficSign]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.NbrSpotTrafficSign, buffer, bufferOffset);
    // Serialize message field [ehPosition]
    bufferOffset = ehPosition.serialize(obj.ehPosition, buffer, bufferOffset);
    // Serialize message field [speedLimit_interpolMethod]
    bufferOffset = _serializer.uint8(obj.speedLimit_interpolMethod, buffer, bufferOffset);
    // Serialize message field [curvature_interpolMethod]
    bufferOffset = _serializer.uint8(obj.curvature_interpolMethod, buffer, bufferOffset);
    // Check that the constant length array field [ehSegmentAO] has the right length
    if (obj.ehSegmentAO.length !== 100) {
      throw new Error('Unable to serialize array field ehSegmentAO - length must be 100')
    }
    // Serialize message field [ehSegmentAO]
    obj.ehSegmentAO.forEach((val) => {
      bufferOffset = ehSegmentME.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [QtySegmentAO]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.QtySegmentAO, buffer, bufferOffset);
    // Check that the constant length array field [ehSegmentEO] has the right length
    if (obj.ehSegmentEO.length !== 100) {
      throw new Error('Unable to serialize array field ehSegmentEO - length must be 100')
    }
    // Serialize message field [ehSegmentEO]
    obj.ehSegmentEO.forEach((val) => {
      bufferOffset = ehSegmentME.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [QtySegmentEO]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.QtySegmentEO, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ElectronicHorizon
    let len;
    let data = new ElectronicHorizon(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [indexPath]
    data.indexPath = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehSegment]
    len = 50;
    data.ehSegment = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehSegment[i] = ehSegment.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [NbrSegment]
    data.NbrSegment = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehStub]
    len = 10;
    data.ehStub = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehStub[i] = ehStub.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [NbrStub]
    data.NbrStub = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehSpotCurvature]
    len = 300;
    data.ehSpotCurvature = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehSpotCurvature[i] = ehSpotCurvature.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [NbrSpotCurvature]
    data.NbrSpotCurvature = std_msgs.msg.UInt16.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehSpotCoordGeoRight]
    len = 2000;
    data.ehSpotCoordGeoRight = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehSpotCoordGeoRight[i] = ehSpotCoordGeo.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [NbrSpotCoordGeoRight]
    data.NbrSpotCoordGeoRight = std_msgs.msg.UInt16.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehSpotCoordGeoLeft]
    len = 2000;
    data.ehSpotCoordGeoLeft = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehSpotCoordGeoLeft[i] = ehSpotCoordGeo.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [NbrSpotCoordGeoLeft]
    data.NbrSpotCoordGeoLeft = std_msgs.msg.UInt16.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehLineCoordGeo]
    len = 10;
    data.ehLineCoordGeo = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehLineCoordGeo[i] = ehLineCoordGeo.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [QtyLineCoordGeo]
    data.QtyLineCoordGeo = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehME]
    len = 2;
    data.ehME = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehME[i] = ehME.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [ehNbrLineCoordGeo]
    len = 100;
    data.ehNbrLineCoordGeo = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehNbrLineCoordGeo[i] = ehNbrLineCoordGeo.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [QtyNbrLineCoordGeo]
    data.QtyNbrLineCoordGeo = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehSpotTrafficSign]
    len = 50;
    data.ehSpotTrafficSign = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehSpotTrafficSign[i] = ehSpotTrafficSign.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [NbrSpotTrafficSign]
    data.NbrSpotTrafficSign = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehPosition]
    data.ehPosition = ehPosition.deserialize(buffer, bufferOffset);
    // Deserialize message field [speedLimit_interpolMethod]
    data.speedLimit_interpolMethod = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [curvature_interpolMethod]
    data.curvature_interpolMethod = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [ehSegmentAO]
    len = 100;
    data.ehSegmentAO = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehSegmentAO[i] = ehSegmentME.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [QtySegmentAO]
    data.QtySegmentAO = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [ehSegmentEO]
    len = 100;
    data.ehSegmentEO = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ehSegmentEO[i] = ehSegmentME.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [QtySegmentEO]
    data.QtySegmentEO = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.ehSegment.forEach((val) => {
      length += ehSegment.getMessageSize(val);
    });
    object.ehStub.forEach((val) => {
      length += ehStub.getMessageSize(val);
    });
    object.ehSpotCurvature.forEach((val) => {
      length += ehSpotCurvature.getMessageSize(val);
    });
    object.ehSpotCoordGeoRight.forEach((val) => {
      length += ehSpotCoordGeo.getMessageSize(val);
    });
    object.ehSpotCoordGeoLeft.forEach((val) => {
      length += ehSpotCoordGeo.getMessageSize(val);
    });
    object.ehLineCoordGeo.forEach((val) => {
      length += ehLineCoordGeo.getMessageSize(val);
    });
    object.ehME.forEach((val) => {
      length += ehME.getMessageSize(val);
    });
    object.ehSpotTrafficSign.forEach((val) => {
      length += ehSpotTrafficSign.getMessageSize(val);
    });
    length += ehPosition.getMessageSize(object.ehPosition);
    object.ehSegmentAO.forEach((val) => {
      length += ehSegmentME.getMessageSize(val);
    });
    object.ehSegmentEO.forEach((val) => {
      length += ehSegmentME.getMessageSize(val);
    });
    return length + 517;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ElectronicHorizon';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3734a37717a8e474a926575905e89801';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    std_msgs/UInt8 indexPath
    
    uint8 SEGMENT_REPORT_SIZE = 50
    project_s_msgs/ehSegment[50] ehSegment
    std_msgs/UInt8 NbrSegment
    
    uint8 STUB_REPORT_SIZE = 10
    project_s_msgs/ehStub[10] ehStub
    std_msgs/UInt8 NbrStub
    
    uint16 SPOT_CURVATURE_REPORT_SIZE = 300
    project_s_msgs/ehSpotCurvature[300] ehSpotCurvature
    std_msgs/UInt16 NbrSpotCurvature
    
    uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000
    project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight
    std_msgs/UInt16 NbrSpotCoordGeoRight
    project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft
    std_msgs/UInt16 NbrSpotCoordGeoLeft
    
    uint8 LINE_REPORT_SIZE = 10
    project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo
    std_msgs/UInt8 QtyLineCoordGeo
    
    uint8 ME_RIGHT_LINE = 0
    uint8 ME_LEFT_LINE = 1
    project_s_msgs/ehME[2] ehME
    
    uint8 NBR_LINE_REPORT_SIZE = 100
    project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo
    std_msgs/UInt8 QtyNbrLineCoordGeo
    
    uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50
    project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign
    std_msgs/UInt8 NbrSpotTrafficSign
    
    project_s_msgs/ehPosition ehPosition
    
    uint8 speedLimit_interpolMethod
    uint8 curvature_interpolMethod
    uint8 STEP = 0
    uint8 LINEAR = 1
    
    uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100
    project_s_msgs/ehSegmentME[100] ehSegmentAO
    std_msgs/UInt8 QtySegmentAO
    
    uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100
    project_s_msgs/ehSegmentME[100] ehSegmentEO
    std_msgs/UInt8 QtySegmentEO
    
    
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
    MSG: project_s_msgs/ehSegment
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
    MSG: std_msgs/Float32
    float32 data
    ================================================================================
    MSG: project_s_msgs/ehStub
    Header header
    std_msgs/UInt8 id
    
    #std_msgs/UInt8 indexPath
    std_msgs/Float32 offset
    std_msgs/UInt8 indexSubPath
    std_msgs/Float32 turnAngle
    std_msgs/UInt8 functionRoadClass
    std_msgs/UInt8 wayForm
    std_msgs/UInt8 nbLanesDrivingDirection
    std_msgs/UInt8 nbLanesOppositeDirection
    
    
    
    ================================================================================
    MSG: project_s_msgs/ehSpotCurvature
    Header header
    std_msgs/UInt8 id
    
    #std_msgs/UInt8 indexPath
    std_msgs/Float32 offset
    std_msgs/Float32 Value_0
    std_msgs/Float32 Distance_1
    std_msgs/Float32 Value_1
    
    
    
    ================================================================================
    MSG: std_msgs/UInt16
    uint16 data
    
    ================================================================================
    MSG: project_s_msgs/ehSpotCoordGeo
    Header header
    std_msgs/UInt8 id
    
    std_msgs/Float32 offset
    float64 latitude
    float64 longitude
    
    
    
    ================================================================================
    MSG: project_s_msgs/ehLineCoordGeo
    Header header
    std_msgs/UInt8 id
    
    uint32 SPOT_REPORT_SIZE = 3000
    project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo
    std_msgs/UInt32 NbrSpotCoordGeo
    
    
    ================================================================================
    MSG: std_msgs/UInt32
    uint32 data
    ================================================================================
    MSG: project_s_msgs/ehME
    Header header
    std_msgs/UInt8 id
    
    uint32 SPOT_REPORT_SIZE = 2000
    project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo
    std_msgs/UInt32 NbrSpotCoordGeo
    
    uint32 SEGMENT_ME_REPORT_SIZE = 100
    project_s_msgs/ehSegmentME[100] ehSegmentME
    std_msgs/UInt32 QtySegment
    
    ================================================================================
    MSG: project_s_msgs/ehSegmentME
    Header header
    std_msgs/UInt8 id
    
    std_msgs/UInt32 NbrSpot
    std_msgs/Float32 offset_debut
    std_msgs/Float32 offset_fin
    
    ================================================================================
    MSG: project_s_msgs/ehNbrLineCoordGeo
    std_msgs/UInt8 Nbr
    std_msgs/Float32 offset
    
    
    
    
    ================================================================================
    MSG: project_s_msgs/ehSpotTrafficSign
    Header header
    std_msgs/UInt8 id
    
    std_msgs/Float32 offset
    uint8 Sign_Type
    uint8 Value
    uint8 Lane
    uint8 Sign_Location
    float64 latitude
    float64 longitude
    
    
    
    
    ================================================================================
    MSG: project_s_msgs/ehPosition
    Header header
    std_msgs/UInt8 id
    
    #std_msgs/UInt8 indexPath
    std_msgs/Float32 offset
    float64 latitude
    float64 longitude
    std_msgs/Float32 cap
    std_msgs/UInt16 agePosition
    std_msgs/Float32 speed
    std_msgs/Float32 relativeHeading
    std_msgs/UInt8 currentLane
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ElectronicHorizon(null);
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

    if (msg.indexPath !== undefined) {
      resolved.indexPath = std_msgs.msg.UInt8.Resolve(msg.indexPath)
    }
    else {
      resolved.indexPath = new std_msgs.msg.UInt8()
    }

    if (msg.ehSegment !== undefined) {
      resolved.ehSegment = new Array(50)
      for (let i = 0; i < resolved.ehSegment.length; ++i) {
        if (msg.ehSegment.length > i) {
          resolved.ehSegment[i] = ehSegment.Resolve(msg.ehSegment[i]);
        }
        else {
          resolved.ehSegment[i] = new ehSegment();
        }
      }
    }
    else {
      resolved.ehSegment = new Array(50).fill(new ehSegment())
    }

    if (msg.NbrSegment !== undefined) {
      resolved.NbrSegment = std_msgs.msg.UInt8.Resolve(msg.NbrSegment)
    }
    else {
      resolved.NbrSegment = new std_msgs.msg.UInt8()
    }

    if (msg.ehStub !== undefined) {
      resolved.ehStub = new Array(10)
      for (let i = 0; i < resolved.ehStub.length; ++i) {
        if (msg.ehStub.length > i) {
          resolved.ehStub[i] = ehStub.Resolve(msg.ehStub[i]);
        }
        else {
          resolved.ehStub[i] = new ehStub();
        }
      }
    }
    else {
      resolved.ehStub = new Array(10).fill(new ehStub())
    }

    if (msg.NbrStub !== undefined) {
      resolved.NbrStub = std_msgs.msg.UInt8.Resolve(msg.NbrStub)
    }
    else {
      resolved.NbrStub = new std_msgs.msg.UInt8()
    }

    if (msg.ehSpotCurvature !== undefined) {
      resolved.ehSpotCurvature = new Array(300)
      for (let i = 0; i < resolved.ehSpotCurvature.length; ++i) {
        if (msg.ehSpotCurvature.length > i) {
          resolved.ehSpotCurvature[i] = ehSpotCurvature.Resolve(msg.ehSpotCurvature[i]);
        }
        else {
          resolved.ehSpotCurvature[i] = new ehSpotCurvature();
        }
      }
    }
    else {
      resolved.ehSpotCurvature = new Array(300).fill(new ehSpotCurvature())
    }

    if (msg.NbrSpotCurvature !== undefined) {
      resolved.NbrSpotCurvature = std_msgs.msg.UInt16.Resolve(msg.NbrSpotCurvature)
    }
    else {
      resolved.NbrSpotCurvature = new std_msgs.msg.UInt16()
    }

    if (msg.ehSpotCoordGeoRight !== undefined) {
      resolved.ehSpotCoordGeoRight = new Array(2000)
      for (let i = 0; i < resolved.ehSpotCoordGeoRight.length; ++i) {
        if (msg.ehSpotCoordGeoRight.length > i) {
          resolved.ehSpotCoordGeoRight[i] = ehSpotCoordGeo.Resolve(msg.ehSpotCoordGeoRight[i]);
        }
        else {
          resolved.ehSpotCoordGeoRight[i] = new ehSpotCoordGeo();
        }
      }
    }
    else {
      resolved.ehSpotCoordGeoRight = new Array(2000).fill(new ehSpotCoordGeo())
    }

    if (msg.NbrSpotCoordGeoRight !== undefined) {
      resolved.NbrSpotCoordGeoRight = std_msgs.msg.UInt16.Resolve(msg.NbrSpotCoordGeoRight)
    }
    else {
      resolved.NbrSpotCoordGeoRight = new std_msgs.msg.UInt16()
    }

    if (msg.ehSpotCoordGeoLeft !== undefined) {
      resolved.ehSpotCoordGeoLeft = new Array(2000)
      for (let i = 0; i < resolved.ehSpotCoordGeoLeft.length; ++i) {
        if (msg.ehSpotCoordGeoLeft.length > i) {
          resolved.ehSpotCoordGeoLeft[i] = ehSpotCoordGeo.Resolve(msg.ehSpotCoordGeoLeft[i]);
        }
        else {
          resolved.ehSpotCoordGeoLeft[i] = new ehSpotCoordGeo();
        }
      }
    }
    else {
      resolved.ehSpotCoordGeoLeft = new Array(2000).fill(new ehSpotCoordGeo())
    }

    if (msg.NbrSpotCoordGeoLeft !== undefined) {
      resolved.NbrSpotCoordGeoLeft = std_msgs.msg.UInt16.Resolve(msg.NbrSpotCoordGeoLeft)
    }
    else {
      resolved.NbrSpotCoordGeoLeft = new std_msgs.msg.UInt16()
    }

    if (msg.ehLineCoordGeo !== undefined) {
      resolved.ehLineCoordGeo = new Array(10)
      for (let i = 0; i < resolved.ehLineCoordGeo.length; ++i) {
        if (msg.ehLineCoordGeo.length > i) {
          resolved.ehLineCoordGeo[i] = ehLineCoordGeo.Resolve(msg.ehLineCoordGeo[i]);
        }
        else {
          resolved.ehLineCoordGeo[i] = new ehLineCoordGeo();
        }
      }
    }
    else {
      resolved.ehLineCoordGeo = new Array(10).fill(new ehLineCoordGeo())
    }

    if (msg.QtyLineCoordGeo !== undefined) {
      resolved.QtyLineCoordGeo = std_msgs.msg.UInt8.Resolve(msg.QtyLineCoordGeo)
    }
    else {
      resolved.QtyLineCoordGeo = new std_msgs.msg.UInt8()
    }

    if (msg.ehME !== undefined) {
      resolved.ehME = new Array(2)
      for (let i = 0; i < resolved.ehME.length; ++i) {
        if (msg.ehME.length > i) {
          resolved.ehME[i] = ehME.Resolve(msg.ehME[i]);
        }
        else {
          resolved.ehME[i] = new ehME();
        }
      }
    }
    else {
      resolved.ehME = new Array(2).fill(new ehME())
    }

    if (msg.ehNbrLineCoordGeo !== undefined) {
      resolved.ehNbrLineCoordGeo = new Array(100)
      for (let i = 0; i < resolved.ehNbrLineCoordGeo.length; ++i) {
        if (msg.ehNbrLineCoordGeo.length > i) {
          resolved.ehNbrLineCoordGeo[i] = ehNbrLineCoordGeo.Resolve(msg.ehNbrLineCoordGeo[i]);
        }
        else {
          resolved.ehNbrLineCoordGeo[i] = new ehNbrLineCoordGeo();
        }
      }
    }
    else {
      resolved.ehNbrLineCoordGeo = new Array(100).fill(new ehNbrLineCoordGeo())
    }

    if (msg.QtyNbrLineCoordGeo !== undefined) {
      resolved.QtyNbrLineCoordGeo = std_msgs.msg.UInt8.Resolve(msg.QtyNbrLineCoordGeo)
    }
    else {
      resolved.QtyNbrLineCoordGeo = new std_msgs.msg.UInt8()
    }

    if (msg.ehSpotTrafficSign !== undefined) {
      resolved.ehSpotTrafficSign = new Array(50)
      for (let i = 0; i < resolved.ehSpotTrafficSign.length; ++i) {
        if (msg.ehSpotTrafficSign.length > i) {
          resolved.ehSpotTrafficSign[i] = ehSpotTrafficSign.Resolve(msg.ehSpotTrafficSign[i]);
        }
        else {
          resolved.ehSpotTrafficSign[i] = new ehSpotTrafficSign();
        }
      }
    }
    else {
      resolved.ehSpotTrafficSign = new Array(50).fill(new ehSpotTrafficSign())
    }

    if (msg.NbrSpotTrafficSign !== undefined) {
      resolved.NbrSpotTrafficSign = std_msgs.msg.UInt8.Resolve(msg.NbrSpotTrafficSign)
    }
    else {
      resolved.NbrSpotTrafficSign = new std_msgs.msg.UInt8()
    }

    if (msg.ehPosition !== undefined) {
      resolved.ehPosition = ehPosition.Resolve(msg.ehPosition)
    }
    else {
      resolved.ehPosition = new ehPosition()
    }

    if (msg.speedLimit_interpolMethod !== undefined) {
      resolved.speedLimit_interpolMethod = msg.speedLimit_interpolMethod;
    }
    else {
      resolved.speedLimit_interpolMethod = 0
    }

    if (msg.curvature_interpolMethod !== undefined) {
      resolved.curvature_interpolMethod = msg.curvature_interpolMethod;
    }
    else {
      resolved.curvature_interpolMethod = 0
    }

    if (msg.ehSegmentAO !== undefined) {
      resolved.ehSegmentAO = new Array(100)
      for (let i = 0; i < resolved.ehSegmentAO.length; ++i) {
        if (msg.ehSegmentAO.length > i) {
          resolved.ehSegmentAO[i] = ehSegmentME.Resolve(msg.ehSegmentAO[i]);
        }
        else {
          resolved.ehSegmentAO[i] = new ehSegmentME();
        }
      }
    }
    else {
      resolved.ehSegmentAO = new Array(100).fill(new ehSegmentME())
    }

    if (msg.QtySegmentAO !== undefined) {
      resolved.QtySegmentAO = std_msgs.msg.UInt8.Resolve(msg.QtySegmentAO)
    }
    else {
      resolved.QtySegmentAO = new std_msgs.msg.UInt8()
    }

    if (msg.ehSegmentEO !== undefined) {
      resolved.ehSegmentEO = new Array(100)
      for (let i = 0; i < resolved.ehSegmentEO.length; ++i) {
        if (msg.ehSegmentEO.length > i) {
          resolved.ehSegmentEO[i] = ehSegmentME.Resolve(msg.ehSegmentEO[i]);
        }
        else {
          resolved.ehSegmentEO[i] = new ehSegmentME();
        }
      }
    }
    else {
      resolved.ehSegmentEO = new Array(100).fill(new ehSegmentME())
    }

    if (msg.QtySegmentEO !== undefined) {
      resolved.QtySegmentEO = std_msgs.msg.UInt8.Resolve(msg.QtySegmentEO)
    }
    else {
      resolved.QtySegmentEO = new std_msgs.msg.UInt8()
    }

    return resolved;
    }
};

// Constants for message
ElectronicHorizon.Constants = {
  SEGMENT_REPORT_SIZE: 50,
  STUB_REPORT_SIZE: 10,
  SPOT_CURVATURE_REPORT_SIZE: 300,
  SPOT_COORD_GEO_REPORT_SIZE: 2000,
  LINE_REPORT_SIZE: 10,
  ME_RIGHT_LINE: 0,
  ME_LEFT_LINE: 1,
  NBR_LINE_REPORT_SIZE: 100,
  SPOT_TRAFFIC_SIGN_REPORT_SIZE: 50,
  STEP: 0,
  LINEAR: 1,
  SEGMENT_ARRET_OBSTACLE_REPORT_SIZE: 100,
  SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE: 100,
}

module.exports = ElectronicHorizon;
