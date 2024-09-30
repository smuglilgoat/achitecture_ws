// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let Segment = require('./Segment.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Line {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.segment = null;
      this.QtySegment = null;
      this.lineClass = null;
      this.idPiste = null;
      this.existenceState = null;
      this.scoreDetection = null;
      this.nbrDetection = null;
      this.nbrVisibility = null;
      this.scorePersistence = null;
      this.nbrUpdate = null;
      this.nbrAge = null;
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
      if (initObj.hasOwnProperty('segment')) {
        this.segment = initObj.segment
      }
      else {
        this.segment = new Array(3000).fill(new Segment());
      }
      if (initObj.hasOwnProperty('QtySegment')) {
        this.QtySegment = initObj.QtySegment
      }
      else {
        this.QtySegment = new std_msgs.msg.UInt16();
      }
      if (initObj.hasOwnProperty('lineClass')) {
        this.lineClass = initObj.lineClass
      }
      else {
        this.lineClass = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('idPiste')) {
        this.idPiste = initObj.idPiste
      }
      else {
        this.idPiste = new Array(2).fill(new std_msgs.msg.UInt16());
      }
      if (initObj.hasOwnProperty('existenceState')) {
        this.existenceState = initObj.existenceState
      }
      else {
        this.existenceState = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('scoreDetection')) {
        this.scoreDetection = initObj.scoreDetection
      }
      else {
        this.scoreDetection = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('nbrDetection')) {
        this.nbrDetection = initObj.nbrDetection
      }
      else {
        this.nbrDetection = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('nbrVisibility')) {
        this.nbrVisibility = initObj.nbrVisibility
      }
      else {
        this.nbrVisibility = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('scorePersistence')) {
        this.scorePersistence = initObj.scorePersistence
      }
      else {
        this.scorePersistence = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('nbrUpdate')) {
        this.nbrUpdate = initObj.nbrUpdate
      }
      else {
        this.nbrUpdate = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('nbrAge')) {
        this.nbrAge = initObj.nbrAge
      }
      else {
        this.nbrAge = new std_msgs.msg.Float32();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Line
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Check that the constant length array field [segment] has the right length
    if (obj.segment.length !== 3000) {
      throw new Error('Unable to serialize array field segment - length must be 3000')
    }
    // Serialize message field [segment]
    obj.segment.forEach((val) => {
      bufferOffset = Segment.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [QtySegment]
    bufferOffset = std_msgs.msg.UInt16.serialize(obj.QtySegment, buffer, bufferOffset);
    // Serialize message field [lineClass]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.lineClass, buffer, bufferOffset);
    // Check that the constant length array field [idPiste] has the right length
    if (obj.idPiste.length !== 2) {
      throw new Error('Unable to serialize array field idPiste - length must be 2')
    }
    // Serialize message field [idPiste]
    obj.idPiste.forEach((val) => {
      bufferOffset = std_msgs.msg.UInt16.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [existenceState]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.existenceState, buffer, bufferOffset);
    // Serialize message field [scoreDetection]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.scoreDetection, buffer, bufferOffset);
    // Serialize message field [nbrDetection]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.nbrDetection, buffer, bufferOffset);
    // Serialize message field [nbrVisibility]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.nbrVisibility, buffer, bufferOffset);
    // Serialize message field [scorePersistence]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.scorePersistence, buffer, bufferOffset);
    // Serialize message field [nbrUpdate]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.nbrUpdate, buffer, bufferOffset);
    // Serialize message field [nbrAge]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.nbrAge, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Line
    let len;
    let data = new Line(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [segment]
    len = 3000;
    data.segment = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.segment[i] = Segment.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [QtySegment]
    data.QtySegment = std_msgs.msg.UInt16.deserialize(buffer, bufferOffset);
    // Deserialize message field [lineClass]
    data.lineClass = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [idPiste]
    len = 2;
    data.idPiste = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.idPiste[i] = std_msgs.msg.UInt16.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [existenceState]
    data.existenceState = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [scoreDetection]
    data.scoreDetection = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [nbrDetection]
    data.nbrDetection = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [nbrVisibility]
    data.nbrVisibility = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [scorePersistence]
    data.scorePersistence = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [nbrUpdate]
    data.nbrUpdate = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [nbrAge]
    data.nbrAge = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 300036;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/Line';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '76c1d98fd2e545accf02a06698e73bb3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    uint16 SEGMENT_REPORT_SIZE = 3000
    project_s_msgs/Segment[3000] segment
    std_msgs/UInt16 QtySegment
    std_msgs/Float32 lineClass	# class of the line
    std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)
    
    std_msgs/UInt8 existenceState
    std_msgs/Float32 scoreDetection
    std_msgs/Float32 nbrDetection
    std_msgs/Float32 nbrVisibility
    std_msgs/Float32 scorePersistence
    std_msgs/Float32 nbrUpdate
    std_msgs/Float32 nbrAge
    
    
    
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
    MSG: project_s_msgs/Segment
    std_msgs/Float32 length		# length of the segment
    std_msgs/Float32 angle		# angle of the segment
    geometry_msgs/Point position
    geometry_msgs/Twist Velocity
    
    float32 offset
    float64 latitude
    float64 longitude
    
    
    ================================================================================
    MSG: std_msgs/Float32
    float32 data
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
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
    MSG: std_msgs/UInt16
    uint16 data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Line(null);
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

    if (msg.segment !== undefined) {
      resolved.segment = new Array(3000)
      for (let i = 0; i < resolved.segment.length; ++i) {
        if (msg.segment.length > i) {
          resolved.segment[i] = Segment.Resolve(msg.segment[i]);
        }
        else {
          resolved.segment[i] = new Segment();
        }
      }
    }
    else {
      resolved.segment = new Array(3000).fill(new Segment())
    }

    if (msg.QtySegment !== undefined) {
      resolved.QtySegment = std_msgs.msg.UInt16.Resolve(msg.QtySegment)
    }
    else {
      resolved.QtySegment = new std_msgs.msg.UInt16()
    }

    if (msg.lineClass !== undefined) {
      resolved.lineClass = std_msgs.msg.Float32.Resolve(msg.lineClass)
    }
    else {
      resolved.lineClass = new std_msgs.msg.Float32()
    }

    if (msg.idPiste !== undefined) {
      resolved.idPiste = new Array(2)
      for (let i = 0; i < resolved.idPiste.length; ++i) {
        if (msg.idPiste.length > i) {
          resolved.idPiste[i] = std_msgs.msg.UInt16.Resolve(msg.idPiste[i]);
        }
        else {
          resolved.idPiste[i] = new std_msgs.msg.UInt16();
        }
      }
    }
    else {
      resolved.idPiste = new Array(2).fill(new std_msgs.msg.UInt16())
    }

    if (msg.existenceState !== undefined) {
      resolved.existenceState = std_msgs.msg.UInt8.Resolve(msg.existenceState)
    }
    else {
      resolved.existenceState = new std_msgs.msg.UInt8()
    }

    if (msg.scoreDetection !== undefined) {
      resolved.scoreDetection = std_msgs.msg.Float32.Resolve(msg.scoreDetection)
    }
    else {
      resolved.scoreDetection = new std_msgs.msg.Float32()
    }

    if (msg.nbrDetection !== undefined) {
      resolved.nbrDetection = std_msgs.msg.Float32.Resolve(msg.nbrDetection)
    }
    else {
      resolved.nbrDetection = new std_msgs.msg.Float32()
    }

    if (msg.nbrVisibility !== undefined) {
      resolved.nbrVisibility = std_msgs.msg.Float32.Resolve(msg.nbrVisibility)
    }
    else {
      resolved.nbrVisibility = new std_msgs.msg.Float32()
    }

    if (msg.scorePersistence !== undefined) {
      resolved.scorePersistence = std_msgs.msg.Float32.Resolve(msg.scorePersistence)
    }
    else {
      resolved.scorePersistence = new std_msgs.msg.Float32()
    }

    if (msg.nbrUpdate !== undefined) {
      resolved.nbrUpdate = std_msgs.msg.Float32.Resolve(msg.nbrUpdate)
    }
    else {
      resolved.nbrUpdate = new std_msgs.msg.Float32()
    }

    if (msg.nbrAge !== undefined) {
      resolved.nbrAge = std_msgs.msg.Float32.Resolve(msg.nbrAge)
    }
    else {
      resolved.nbrAge = new std_msgs.msg.Float32()
    }

    return resolved;
    }
};

// Constants for message
Line.Constants = {
  SEGMENT_REPORT_SIZE: 3000,
}

module.exports = Line;
