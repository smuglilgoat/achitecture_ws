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

//-----------------------------------------------------------

class Side {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.segment = null;
    }
    else {
      if (initObj.hasOwnProperty('segment')) {
        this.segment = initObj.segment
      }
      else {
        this.segment = new Array(100).fill(new Segment());
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Side
    // Check that the constant length array field [segment] has the right length
    if (obj.segment.length !== 100) {
      throw new Error('Unable to serialize array field segment - length must be 100')
    }
    // Serialize message field [segment]
    obj.segment.forEach((val) => {
      bufferOffset = Segment.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Side
    let len;
    let data = new Side(null);
    // Deserialize message field [segment]
    len = 100;
    data.segment = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.segment[i] = Segment.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    return 100;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/Side';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3cee93af1c46f02386b8de1d0844998c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    project_s_msgs/Segment[100] segment
    
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
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Side(null);
    if (msg.segment !== undefined) {
      resolved.segment = new Array(100)
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
      resolved.segment = new Array(100).fill(new Segment())
    }

    return resolved;
    }
};

module.exports = Side;
