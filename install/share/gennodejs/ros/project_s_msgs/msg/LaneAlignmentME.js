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
let mobileye_560_660_msgs = _finder('mobileye_560_660_msgs');

//-----------------------------------------------------------

class LaneAlignmentME {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.line = null;
      this.line_min = null;
      this.line_max = null;
      this.QtyLine = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('line')) {
        this.line = initObj.line
      }
      else {
        this.line = new Array(5).fill(new mobileye_560_660_msgs.msg.LkaLane());
      }
      if (initObj.hasOwnProperty('line_min')) {
        this.line_min = initObj.line_min
      }
      else {
        this.line_min = new Array(5).fill(0);
      }
      if (initObj.hasOwnProperty('line_max')) {
        this.line_max = initObj.line_max
      }
      else {
        this.line_max = new Array(5).fill(0);
      }
      if (initObj.hasOwnProperty('QtyLine')) {
        this.QtyLine = initObj.QtyLine
      }
      else {
        this.QtyLine = new std_msgs.msg.UInt8();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LaneAlignmentME
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Check that the constant length array field [line] has the right length
    if (obj.line.length !== 5) {
      throw new Error('Unable to serialize array field line - length must be 5')
    }
    // Serialize message field [line]
    obj.line.forEach((val) => {
      bufferOffset = mobileye_560_660_msgs.msg.LkaLane.serialize(val, buffer, bufferOffset);
    });
    // Check that the constant length array field [line_min] has the right length
    if (obj.line_min.length !== 5) {
      throw new Error('Unable to serialize array field line_min - length must be 5')
    }
    // Serialize message field [line_min]
    bufferOffset = _arraySerializer.float32(obj.line_min, buffer, bufferOffset, 5);
    // Check that the constant length array field [line_max] has the right length
    if (obj.line_max.length !== 5) {
      throw new Error('Unable to serialize array field line_max - length must be 5')
    }
    // Serialize message field [line_max]
    bufferOffset = _arraySerializer.float32(obj.line_max, buffer, bufferOffset, 5);
    // Serialize message field [QtyLine]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.QtyLine, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LaneAlignmentME
    let len;
    let data = new LaneAlignmentME(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [line]
    len = 5;
    data.line = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.line[i] = mobileye_560_660_msgs.msg.LkaLane.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [line_min]
    data.line_min = _arrayDeserializer.float32(buffer, bufferOffset, 5)
    // Deserialize message field [line_max]
    data.line_max = _arrayDeserializer.float32(buffer, bufferOffset, 5)
    // Deserialize message field [QtyLine]
    data.QtyLine = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.line.forEach((val) => {
      length += mobileye_560_660_msgs.msg.LkaLane.getMessageSize(val);
    });
    return length + 41;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/LaneAlignmentME';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd378bfe1f7b07b92f50424d676c60576';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    mobileye_560_660_msgs/LkaLane[5] line
    float32[5] line_min
    float32[5] line_max
    std_msgs/UInt8 QtyLine
    
    # History
    
    
    
    
    
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
    MSG: mobileye_560_660_msgs/LkaLane
    Header header
    
    uint8 LANE_CONFIDENCE_NONE = 0
    uint8 LANE_CONFIDENCE_LOW = 1
    uint8 LANE_CONFIDENCE_MED = 2
    uint8 LANE_CONFIDENCE_HIGH = 3
    
    uint8 LANE_TYPE_DASHED = 0
    uint8 LANE_TYPE_SOLID = 1
    uint8 LANE_TYPE_NONE = 2
    uint8 LANE_TYPE_ROAD_EDGE = 3
    uint8 LANE_TYPE_DOUBLE_LANE_MARK = 4
    uint8 LANE_TYPE_BOTTS_DOTS = 5
    uint8 LANE_TYPE_INVALID = 6
    
    uint8 lane_type
    uint8 quality
    uint8 model_degree
    float64 position_parameter_c0
    float64 curvature_parameter_c2
    float64 curvature_derivative_parameter_c3
    float32 marking_width
    float64 heading_angle_parameter_c1
    float32 view_range
    bool view_range_availability
    
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
    const resolved = new LaneAlignmentME(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.line !== undefined) {
      resolved.line = new Array(5)
      for (let i = 0; i < resolved.line.length; ++i) {
        if (msg.line.length > i) {
          resolved.line[i] = mobileye_560_660_msgs.msg.LkaLane.Resolve(msg.line[i]);
        }
        else {
          resolved.line[i] = new mobileye_560_660_msgs.msg.LkaLane();
        }
      }
    }
    else {
      resolved.line = new Array(5).fill(new mobileye_560_660_msgs.msg.LkaLane())
    }

    if (msg.line_min !== undefined) {
      resolved.line_min = msg.line_min;
    }
    else {
      resolved.line_min = new Array(5).fill(0)
    }

    if (msg.line_max !== undefined) {
      resolved.line_max = msg.line_max;
    }
    else {
      resolved.line_max = new Array(5).fill(0)
    }

    if (msg.QtyLine !== undefined) {
      resolved.QtyLine = std_msgs.msg.UInt8.Resolve(msg.QtyLine)
    }
    else {
      resolved.QtyLine = new std_msgs.msg.UInt8()
    }

    return resolved;
    }
};

module.exports = LaneAlignmentME;
