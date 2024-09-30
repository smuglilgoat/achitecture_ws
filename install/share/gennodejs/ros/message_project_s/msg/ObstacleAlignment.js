// Auto-generated. Do not edit!

// (in-package message_project_s.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ObstacleAlignment {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.obstaclePosition = null;
      this.obstacleVelocity = null;
      this.obstacleAcceleration = null;
      this.obstaclePoseVariance = null;
      this.obstacleVelocityVariance = null;
      this.obstacleDimensions = null;
      this.groundHeight = null;
      this.obstacleClass = null;
      this.vision_only_sign_type = null;
      this.classificationProbability = null;
      this.dateAcquisition = null;
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
      if (initObj.hasOwnProperty('obstaclePosition')) {
        this.obstaclePosition = initObj.obstaclePosition
      }
      else {
        this.obstaclePosition = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('obstacleVelocity')) {
        this.obstacleVelocity = initObj.obstacleVelocity
      }
      else {
        this.obstacleVelocity = new geometry_msgs.msg.Twist();
      }
      if (initObj.hasOwnProperty('obstacleAcceleration')) {
        this.obstacleAcceleration = initObj.obstacleAcceleration
      }
      else {
        this.obstacleAcceleration = new geometry_msgs.msg.Accel();
      }
      if (initObj.hasOwnProperty('obstaclePoseVariance')) {
        this.obstaclePoseVariance = initObj.obstaclePoseVariance
      }
      else {
        this.obstaclePoseVariance = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('obstacleVelocityVariance')) {
        this.obstacleVelocityVariance = initObj.obstacleVelocityVariance
      }
      else {
        this.obstacleVelocityVariance = new geometry_msgs.msg.Twist();
      }
      if (initObj.hasOwnProperty('obstacleDimensions')) {
        this.obstacleDimensions = initObj.obstacleDimensions
      }
      else {
        this.obstacleDimensions = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('groundHeight')) {
        this.groundHeight = initObj.groundHeight
      }
      else {
        this.groundHeight = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('obstacleClass')) {
        this.obstacleClass = initObj.obstacleClass
      }
      else {
        this.obstacleClass = 0;
      }
      if (initObj.hasOwnProperty('vision_only_sign_type')) {
        this.vision_only_sign_type = initObj.vision_only_sign_type
      }
      else {
        this.vision_only_sign_type = 0;
      }
      if (initObj.hasOwnProperty('classificationProbability')) {
        this.classificationProbability = initObj.classificationProbability
      }
      else {
        this.classificationProbability = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('dateAcquisition')) {
        this.dateAcquisition = initObj.dateAcquisition
      }
      else {
        this.dateAcquisition = new std_msgs.msg.Float64();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ObstacleAlignment
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [obstaclePosition]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.obstaclePosition, buffer, bufferOffset);
    // Serialize message field [obstacleVelocity]
    bufferOffset = geometry_msgs.msg.Twist.serialize(obj.obstacleVelocity, buffer, bufferOffset);
    // Serialize message field [obstacleAcceleration]
    bufferOffset = geometry_msgs.msg.Accel.serialize(obj.obstacleAcceleration, buffer, bufferOffset);
    // Serialize message field [obstaclePoseVariance]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.obstaclePoseVariance, buffer, bufferOffset);
    // Serialize message field [obstacleVelocityVariance]
    bufferOffset = geometry_msgs.msg.Twist.serialize(obj.obstacleVelocityVariance, buffer, bufferOffset);
    // Serialize message field [obstacleDimensions]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.obstacleDimensions, buffer, bufferOffset);
    // Serialize message field [groundHeight]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.groundHeight, buffer, bufferOffset);
    // Serialize message field [obstacleClass]
    bufferOffset = _serializer.uint8(obj.obstacleClass, buffer, bufferOffset);
    // Serialize message field [vision_only_sign_type]
    bufferOffset = _serializer.uint8(obj.vision_only_sign_type, buffer, bufferOffset);
    // Serialize message field [classificationProbability]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.classificationProbability, buffer, bufferOffset);
    // Serialize message field [dateAcquisition]
    bufferOffset = std_msgs.msg.Float64.serialize(obj.dateAcquisition, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObstacleAlignment
    let len;
    let data = new ObstacleAlignment(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstaclePosition]
    data.obstaclePosition = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleVelocity]
    data.obstacleVelocity = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleAcceleration]
    data.obstacleAcceleration = geometry_msgs.msg.Accel.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstaclePoseVariance]
    data.obstaclePoseVariance = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleVelocityVariance]
    data.obstacleVelocityVariance = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleDimensions]
    data.obstacleDimensions = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [groundHeight]
    data.groundHeight = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleClass]
    data.obstacleClass = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [vision_only_sign_type]
    data.vision_only_sign_type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [classificationProbability]
    data.classificationProbability = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [dateAcquisition]
    data.dateAcquisition = std_msgs.msg.Float64.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 296;
  }

  static datatype() {
    // Returns string type for a message object
    return 'message_project_s/ObstacleAlignment';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dce63e168b330791d863e425f8e25292';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    geometry_msgs/Pose obstaclePosition		# obstacle position
    geometry_msgs/Twist obstacleVelocity		# obstacle speed
    geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
    geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance
    geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance
    geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height
    std_msgs/Float32 groundHeight			# ground height
    uint8 obstacleClass
    uint8 vision_only_sign_type
    std_msgs/UInt8 classificationProbability
    std_msgs/Float64 dateAcquisition
    
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
    MSG: std_msgs/UInt8
    uint8 data
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
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
    
    ================================================================================
    MSG: std_msgs/Float32
    float32 data
    ================================================================================
    MSG: std_msgs/Float64
    float64 data
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ObstacleAlignment(null);
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

    if (msg.obstaclePosition !== undefined) {
      resolved.obstaclePosition = geometry_msgs.msg.Pose.Resolve(msg.obstaclePosition)
    }
    else {
      resolved.obstaclePosition = new geometry_msgs.msg.Pose()
    }

    if (msg.obstacleVelocity !== undefined) {
      resolved.obstacleVelocity = geometry_msgs.msg.Twist.Resolve(msg.obstacleVelocity)
    }
    else {
      resolved.obstacleVelocity = new geometry_msgs.msg.Twist()
    }

    if (msg.obstacleAcceleration !== undefined) {
      resolved.obstacleAcceleration = geometry_msgs.msg.Accel.Resolve(msg.obstacleAcceleration)
    }
    else {
      resolved.obstacleAcceleration = new geometry_msgs.msg.Accel()
    }

    if (msg.obstaclePoseVariance !== undefined) {
      resolved.obstaclePoseVariance = geometry_msgs.msg.Pose.Resolve(msg.obstaclePoseVariance)
    }
    else {
      resolved.obstaclePoseVariance = new geometry_msgs.msg.Pose()
    }

    if (msg.obstacleVelocityVariance !== undefined) {
      resolved.obstacleVelocityVariance = geometry_msgs.msg.Twist.Resolve(msg.obstacleVelocityVariance)
    }
    else {
      resolved.obstacleVelocityVariance = new geometry_msgs.msg.Twist()
    }

    if (msg.obstacleDimensions !== undefined) {
      resolved.obstacleDimensions = geometry_msgs.msg.Vector3.Resolve(msg.obstacleDimensions)
    }
    else {
      resolved.obstacleDimensions = new geometry_msgs.msg.Vector3()
    }

    if (msg.groundHeight !== undefined) {
      resolved.groundHeight = std_msgs.msg.Float32.Resolve(msg.groundHeight)
    }
    else {
      resolved.groundHeight = new std_msgs.msg.Float32()
    }

    if (msg.obstacleClass !== undefined) {
      resolved.obstacleClass = msg.obstacleClass;
    }
    else {
      resolved.obstacleClass = 0
    }

    if (msg.vision_only_sign_type !== undefined) {
      resolved.vision_only_sign_type = msg.vision_only_sign_type;
    }
    else {
      resolved.vision_only_sign_type = 0
    }

    if (msg.classificationProbability !== undefined) {
      resolved.classificationProbability = std_msgs.msg.UInt8.Resolve(msg.classificationProbability)
    }
    else {
      resolved.classificationProbability = new std_msgs.msg.UInt8()
    }

    if (msg.dateAcquisition !== undefined) {
      resolved.dateAcquisition = std_msgs.msg.Float64.Resolve(msg.dateAcquisition)
    }
    else {
      resolved.dateAcquisition = new std_msgs.msg.Float64()
    }

    return resolved;
    }
};

module.exports = ObstacleAlignment;
