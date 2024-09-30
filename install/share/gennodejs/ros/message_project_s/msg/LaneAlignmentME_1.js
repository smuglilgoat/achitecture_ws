// Auto-generated. Do not edit!

// (in-package message_project_s.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class LaneAlignmentME_1 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.left_lane_type = null;
      this.left_quality = null;
      this.left_model_degree = null;
      this.left_position_parameter_c0 = null;
      this.left_curvature_parameter_c2 = null;
      this.left_curvature_derivative_parameter_c3 = null;
      this.left_marking_width = null;
      this.left_heading_angle_parameter_c1 = null;
      this.left_view_range = null;
      this.left_view_range_availability = null;
      this.right_lane_type = null;
      this.right_quality = null;
      this.right_model_degree = null;
      this.right_position_parameter_c0 = null;
      this.right_curvature_parameter_c2 = null;
      this.right_curvature_derivative_parameter_c3 = null;
      this.right_marking_width = null;
      this.right_heading_angle_parameter_c1 = null;
      this.right_view_range = null;
      this.right_view_range_availability = null;
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
      if (initObj.hasOwnProperty('left_lane_type')) {
        this.left_lane_type = initObj.left_lane_type
      }
      else {
        this.left_lane_type = 0;
      }
      if (initObj.hasOwnProperty('left_quality')) {
        this.left_quality = initObj.left_quality
      }
      else {
        this.left_quality = 0;
      }
      if (initObj.hasOwnProperty('left_model_degree')) {
        this.left_model_degree = initObj.left_model_degree
      }
      else {
        this.left_model_degree = 0;
      }
      if (initObj.hasOwnProperty('left_position_parameter_c0')) {
        this.left_position_parameter_c0 = initObj.left_position_parameter_c0
      }
      else {
        this.left_position_parameter_c0 = 0.0;
      }
      if (initObj.hasOwnProperty('left_curvature_parameter_c2')) {
        this.left_curvature_parameter_c2 = initObj.left_curvature_parameter_c2
      }
      else {
        this.left_curvature_parameter_c2 = 0.0;
      }
      if (initObj.hasOwnProperty('left_curvature_derivative_parameter_c3')) {
        this.left_curvature_derivative_parameter_c3 = initObj.left_curvature_derivative_parameter_c3
      }
      else {
        this.left_curvature_derivative_parameter_c3 = 0.0;
      }
      if (initObj.hasOwnProperty('left_marking_width')) {
        this.left_marking_width = initObj.left_marking_width
      }
      else {
        this.left_marking_width = 0.0;
      }
      if (initObj.hasOwnProperty('left_heading_angle_parameter_c1')) {
        this.left_heading_angle_parameter_c1 = initObj.left_heading_angle_parameter_c1
      }
      else {
        this.left_heading_angle_parameter_c1 = 0.0;
      }
      if (initObj.hasOwnProperty('left_view_range')) {
        this.left_view_range = initObj.left_view_range
      }
      else {
        this.left_view_range = 0.0;
      }
      if (initObj.hasOwnProperty('left_view_range_availability')) {
        this.left_view_range_availability = initObj.left_view_range_availability
      }
      else {
        this.left_view_range_availability = false;
      }
      if (initObj.hasOwnProperty('right_lane_type')) {
        this.right_lane_type = initObj.right_lane_type
      }
      else {
        this.right_lane_type = 0;
      }
      if (initObj.hasOwnProperty('right_quality')) {
        this.right_quality = initObj.right_quality
      }
      else {
        this.right_quality = 0;
      }
      if (initObj.hasOwnProperty('right_model_degree')) {
        this.right_model_degree = initObj.right_model_degree
      }
      else {
        this.right_model_degree = 0;
      }
      if (initObj.hasOwnProperty('right_position_parameter_c0')) {
        this.right_position_parameter_c0 = initObj.right_position_parameter_c0
      }
      else {
        this.right_position_parameter_c0 = 0.0;
      }
      if (initObj.hasOwnProperty('right_curvature_parameter_c2')) {
        this.right_curvature_parameter_c2 = initObj.right_curvature_parameter_c2
      }
      else {
        this.right_curvature_parameter_c2 = 0.0;
      }
      if (initObj.hasOwnProperty('right_curvature_derivative_parameter_c3')) {
        this.right_curvature_derivative_parameter_c3 = initObj.right_curvature_derivative_parameter_c3
      }
      else {
        this.right_curvature_derivative_parameter_c3 = 0.0;
      }
      if (initObj.hasOwnProperty('right_marking_width')) {
        this.right_marking_width = initObj.right_marking_width
      }
      else {
        this.right_marking_width = 0.0;
      }
      if (initObj.hasOwnProperty('right_heading_angle_parameter_c1')) {
        this.right_heading_angle_parameter_c1 = initObj.right_heading_angle_parameter_c1
      }
      else {
        this.right_heading_angle_parameter_c1 = 0.0;
      }
      if (initObj.hasOwnProperty('right_view_range')) {
        this.right_view_range = initObj.right_view_range
      }
      else {
        this.right_view_range = 0.0;
      }
      if (initObj.hasOwnProperty('right_view_range_availability')) {
        this.right_view_range_availability = initObj.right_view_range_availability
      }
      else {
        this.right_view_range_availability = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LaneAlignmentME_1
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [left_lane_type]
    bufferOffset = _serializer.uint8(obj.left_lane_type, buffer, bufferOffset);
    // Serialize message field [left_quality]
    bufferOffset = _serializer.uint8(obj.left_quality, buffer, bufferOffset);
    // Serialize message field [left_model_degree]
    bufferOffset = _serializer.uint8(obj.left_model_degree, buffer, bufferOffset);
    // Serialize message field [left_position_parameter_c0]
    bufferOffset = _serializer.float64(obj.left_position_parameter_c0, buffer, bufferOffset);
    // Serialize message field [left_curvature_parameter_c2]
    bufferOffset = _serializer.float64(obj.left_curvature_parameter_c2, buffer, bufferOffset);
    // Serialize message field [left_curvature_derivative_parameter_c3]
    bufferOffset = _serializer.float64(obj.left_curvature_derivative_parameter_c3, buffer, bufferOffset);
    // Serialize message field [left_marking_width]
    bufferOffset = _serializer.float32(obj.left_marking_width, buffer, bufferOffset);
    // Serialize message field [left_heading_angle_parameter_c1]
    bufferOffset = _serializer.float64(obj.left_heading_angle_parameter_c1, buffer, bufferOffset);
    // Serialize message field [left_view_range]
    bufferOffset = _serializer.float32(obj.left_view_range, buffer, bufferOffset);
    // Serialize message field [left_view_range_availability]
    bufferOffset = _serializer.bool(obj.left_view_range_availability, buffer, bufferOffset);
    // Serialize message field [right_lane_type]
    bufferOffset = _serializer.uint8(obj.right_lane_type, buffer, bufferOffset);
    // Serialize message field [right_quality]
    bufferOffset = _serializer.uint8(obj.right_quality, buffer, bufferOffset);
    // Serialize message field [right_model_degree]
    bufferOffset = _serializer.uint8(obj.right_model_degree, buffer, bufferOffset);
    // Serialize message field [right_position_parameter_c0]
    bufferOffset = _serializer.float64(obj.right_position_parameter_c0, buffer, bufferOffset);
    // Serialize message field [right_curvature_parameter_c2]
    bufferOffset = _serializer.float64(obj.right_curvature_parameter_c2, buffer, bufferOffset);
    // Serialize message field [right_curvature_derivative_parameter_c3]
    bufferOffset = _serializer.float64(obj.right_curvature_derivative_parameter_c3, buffer, bufferOffset);
    // Serialize message field [right_marking_width]
    bufferOffset = _serializer.float32(obj.right_marking_width, buffer, bufferOffset);
    // Serialize message field [right_heading_angle_parameter_c1]
    bufferOffset = _serializer.float64(obj.right_heading_angle_parameter_c1, buffer, bufferOffset);
    // Serialize message field [right_view_range]
    bufferOffset = _serializer.float32(obj.right_view_range, buffer, bufferOffset);
    // Serialize message field [right_view_range_availability]
    bufferOffset = _serializer.bool(obj.right_view_range_availability, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LaneAlignmentME_1
    let len;
    let data = new LaneAlignmentME_1(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [left_lane_type]
    data.left_lane_type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [left_quality]
    data.left_quality = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [left_model_degree]
    data.left_model_degree = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [left_position_parameter_c0]
    data.left_position_parameter_c0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [left_curvature_parameter_c2]
    data.left_curvature_parameter_c2 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [left_curvature_derivative_parameter_c3]
    data.left_curvature_derivative_parameter_c3 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [left_marking_width]
    data.left_marking_width = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [left_heading_angle_parameter_c1]
    data.left_heading_angle_parameter_c1 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [left_view_range]
    data.left_view_range = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [left_view_range_availability]
    data.left_view_range_availability = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [right_lane_type]
    data.right_lane_type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [right_quality]
    data.right_quality = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [right_model_degree]
    data.right_model_degree = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [right_position_parameter_c0]
    data.right_position_parameter_c0 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_curvature_parameter_c2]
    data.right_curvature_parameter_c2 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_curvature_derivative_parameter_c3]
    data.right_curvature_derivative_parameter_c3 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_marking_width]
    data.right_marking_width = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right_heading_angle_parameter_c1]
    data.right_heading_angle_parameter_c1 = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_view_range]
    data.right_view_range = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right_view_range_availability]
    data.right_view_range_availability = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 89;
  }

  static datatype() {
    // Returns string type for a message object
    return 'message_project_s/LaneAlignmentME_1';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '879c0a765df264cb0b3a43d9c8f4f61a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    uint8 left_lane_type
    uint8 left_quality
    uint8 left_model_degree
    float64 left_position_parameter_c0
    float64 left_curvature_parameter_c2
    float64 left_curvature_derivative_parameter_c3
    float32 left_marking_width
    float64 left_heading_angle_parameter_c1
    float32 left_view_range
    bool left_view_range_availability
    
    uint8 right_lane_type
    uint8 right_quality
    uint8 right_model_degree
    float64 right_position_parameter_c0
    float64 right_curvature_parameter_c2
    float64 right_curvature_derivative_parameter_c3
    float32 right_marking_width
    float64 right_heading_angle_parameter_c1
    float32 right_view_range
    bool right_view_range_availability
    
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
    const resolved = new LaneAlignmentME_1(null);
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

    if (msg.left_lane_type !== undefined) {
      resolved.left_lane_type = msg.left_lane_type;
    }
    else {
      resolved.left_lane_type = 0
    }

    if (msg.left_quality !== undefined) {
      resolved.left_quality = msg.left_quality;
    }
    else {
      resolved.left_quality = 0
    }

    if (msg.left_model_degree !== undefined) {
      resolved.left_model_degree = msg.left_model_degree;
    }
    else {
      resolved.left_model_degree = 0
    }

    if (msg.left_position_parameter_c0 !== undefined) {
      resolved.left_position_parameter_c0 = msg.left_position_parameter_c0;
    }
    else {
      resolved.left_position_parameter_c0 = 0.0
    }

    if (msg.left_curvature_parameter_c2 !== undefined) {
      resolved.left_curvature_parameter_c2 = msg.left_curvature_parameter_c2;
    }
    else {
      resolved.left_curvature_parameter_c2 = 0.0
    }

    if (msg.left_curvature_derivative_parameter_c3 !== undefined) {
      resolved.left_curvature_derivative_parameter_c3 = msg.left_curvature_derivative_parameter_c3;
    }
    else {
      resolved.left_curvature_derivative_parameter_c3 = 0.0
    }

    if (msg.left_marking_width !== undefined) {
      resolved.left_marking_width = msg.left_marking_width;
    }
    else {
      resolved.left_marking_width = 0.0
    }

    if (msg.left_heading_angle_parameter_c1 !== undefined) {
      resolved.left_heading_angle_parameter_c1 = msg.left_heading_angle_parameter_c1;
    }
    else {
      resolved.left_heading_angle_parameter_c1 = 0.0
    }

    if (msg.left_view_range !== undefined) {
      resolved.left_view_range = msg.left_view_range;
    }
    else {
      resolved.left_view_range = 0.0
    }

    if (msg.left_view_range_availability !== undefined) {
      resolved.left_view_range_availability = msg.left_view_range_availability;
    }
    else {
      resolved.left_view_range_availability = false
    }

    if (msg.right_lane_type !== undefined) {
      resolved.right_lane_type = msg.right_lane_type;
    }
    else {
      resolved.right_lane_type = 0
    }

    if (msg.right_quality !== undefined) {
      resolved.right_quality = msg.right_quality;
    }
    else {
      resolved.right_quality = 0
    }

    if (msg.right_model_degree !== undefined) {
      resolved.right_model_degree = msg.right_model_degree;
    }
    else {
      resolved.right_model_degree = 0
    }

    if (msg.right_position_parameter_c0 !== undefined) {
      resolved.right_position_parameter_c0 = msg.right_position_parameter_c0;
    }
    else {
      resolved.right_position_parameter_c0 = 0.0
    }

    if (msg.right_curvature_parameter_c2 !== undefined) {
      resolved.right_curvature_parameter_c2 = msg.right_curvature_parameter_c2;
    }
    else {
      resolved.right_curvature_parameter_c2 = 0.0
    }

    if (msg.right_curvature_derivative_parameter_c3 !== undefined) {
      resolved.right_curvature_derivative_parameter_c3 = msg.right_curvature_derivative_parameter_c3;
    }
    else {
      resolved.right_curvature_derivative_parameter_c3 = 0.0
    }

    if (msg.right_marking_width !== undefined) {
      resolved.right_marking_width = msg.right_marking_width;
    }
    else {
      resolved.right_marking_width = 0.0
    }

    if (msg.right_heading_angle_parameter_c1 !== undefined) {
      resolved.right_heading_angle_parameter_c1 = msg.right_heading_angle_parameter_c1;
    }
    else {
      resolved.right_heading_angle_parameter_c1 = 0.0
    }

    if (msg.right_view_range !== undefined) {
      resolved.right_view_range = msg.right_view_range;
    }
    else {
      resolved.right_view_range = 0.0
    }

    if (msg.right_view_range_availability !== undefined) {
      resolved.right_view_range_availability = msg.right_view_range_availability;
    }
    else {
      resolved.right_view_range_availability = false
    }

    return resolved;
    }
};

module.exports = LaneAlignmentME_1;
