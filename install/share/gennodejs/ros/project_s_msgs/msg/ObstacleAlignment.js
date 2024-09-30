// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


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
      this.obstacleBodyCenter = null;
      this.obstacleVelocity = null;
      this.obstacleRelativeVelocity = null;
      this.obstacleAcceleration = null;
      this.obstacleDimensions = null;
      this.blinkerInfo = null;
      this.cutInAndOut = null;
      this.obstacleType = null;
      this.obstacleStatus = null;
      this.obstacleBrakeLights = null;
      this.cipvFlag = null;
      this.obstacleReplaced = null;
      this.obstacleValid = null;
      this.obstacleAge = null;
      this.obstacleLane = null;
      this.obstacleAngle = null;
      this.obstacleAngleVariance = null;
      this.obstacleAngleRate = null;
      this.obstacleScaleChange = null;
      this.vision_only_sign_type = null;
      this.visionOnlySupplementarySignType = null;
      this.signPosition = null;
      this.filterType = null;
      this.obstaclePoseVariance = null;
      this.obstacleVelocityVariance = null;
      this.obstacleRelativeVelocityVariance = null;
      this.groundHeight = null;
      this.classificationProbability = null;
      this.dateAcquisition = null;
      this.obstacleClass = null;
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
        this.id = new std_msgs.msg.UInt16();
      }
      if (initObj.hasOwnProperty('obstaclePosition')) {
        this.obstaclePosition = initObj.obstaclePosition
      }
      else {
        this.obstaclePosition = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('obstacleBodyCenter')) {
        this.obstacleBodyCenter = initObj.obstacleBodyCenter
      }
      else {
        this.obstacleBodyCenter = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('obstacleVelocity')) {
        this.obstacleVelocity = initObj.obstacleVelocity
      }
      else {
        this.obstacleVelocity = new geometry_msgs.msg.Twist();
      }
      if (initObj.hasOwnProperty('obstacleRelativeVelocity')) {
        this.obstacleRelativeVelocity = initObj.obstacleRelativeVelocity
      }
      else {
        this.obstacleRelativeVelocity = new geometry_msgs.msg.Twist();
      }
      if (initObj.hasOwnProperty('obstacleAcceleration')) {
        this.obstacleAcceleration = initObj.obstacleAcceleration
      }
      else {
        this.obstacleAcceleration = new geometry_msgs.msg.Accel();
      }
      if (initObj.hasOwnProperty('obstacleDimensions')) {
        this.obstacleDimensions = initObj.obstacleDimensions
      }
      else {
        this.obstacleDimensions = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('blinkerInfo')) {
        this.blinkerInfo = initObj.blinkerInfo
      }
      else {
        this.blinkerInfo = 0;
      }
      if (initObj.hasOwnProperty('cutInAndOut')) {
        this.cutInAndOut = initObj.cutInAndOut
      }
      else {
        this.cutInAndOut = 0;
      }
      if (initObj.hasOwnProperty('obstacleType')) {
        this.obstacleType = initObj.obstacleType
      }
      else {
        this.obstacleType = 0;
      }
      if (initObj.hasOwnProperty('obstacleStatus')) {
        this.obstacleStatus = initObj.obstacleStatus
      }
      else {
        this.obstacleStatus = 0;
      }
      if (initObj.hasOwnProperty('obstacleBrakeLights')) {
        this.obstacleBrakeLights = initObj.obstacleBrakeLights
      }
      else {
        this.obstacleBrakeLights = false;
      }
      if (initObj.hasOwnProperty('cipvFlag')) {
        this.cipvFlag = initObj.cipvFlag
      }
      else {
        this.cipvFlag = 0;
      }
      if (initObj.hasOwnProperty('obstacleReplaced')) {
        this.obstacleReplaced = initObj.obstacleReplaced
      }
      else {
        this.obstacleReplaced = 0;
      }
      if (initObj.hasOwnProperty('obstacleValid')) {
        this.obstacleValid = initObj.obstacleValid
      }
      else {
        this.obstacleValid = 0;
      }
      if (initObj.hasOwnProperty('obstacleAge')) {
        this.obstacleAge = initObj.obstacleAge
      }
      else {
        this.obstacleAge = 0;
      }
      if (initObj.hasOwnProperty('obstacleLane')) {
        this.obstacleLane = initObj.obstacleLane
      }
      else {
        this.obstacleLane = 0;
      }
      if (initObj.hasOwnProperty('obstacleAngle')) {
        this.obstacleAngle = initObj.obstacleAngle
      }
      else {
        this.obstacleAngle = 0.0;
      }
      if (initObj.hasOwnProperty('obstacleAngleVariance')) {
        this.obstacleAngleVariance = initObj.obstacleAngleVariance
      }
      else {
        this.obstacleAngleVariance = 0.0;
      }
      if (initObj.hasOwnProperty('obstacleAngleRate')) {
        this.obstacleAngleRate = initObj.obstacleAngleRate
      }
      else {
        this.obstacleAngleRate = 0.0;
      }
      if (initObj.hasOwnProperty('obstacleScaleChange')) {
        this.obstacleScaleChange = initObj.obstacleScaleChange
      }
      else {
        this.obstacleScaleChange = 0.0;
      }
      if (initObj.hasOwnProperty('vision_only_sign_type')) {
        this.vision_only_sign_type = initObj.vision_only_sign_type
      }
      else {
        this.vision_only_sign_type = 0;
      }
      if (initObj.hasOwnProperty('visionOnlySupplementarySignType')) {
        this.visionOnlySupplementarySignType = initObj.visionOnlySupplementarySignType
      }
      else {
        this.visionOnlySupplementarySignType = 0;
      }
      if (initObj.hasOwnProperty('signPosition')) {
        this.signPosition = initObj.signPosition
      }
      else {
        this.signPosition = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('filterType')) {
        this.filterType = initObj.filterType
      }
      else {
        this.filterType = 0.0;
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
      if (initObj.hasOwnProperty('obstacleRelativeVelocityVariance')) {
        this.obstacleRelativeVelocityVariance = initObj.obstacleRelativeVelocityVariance
      }
      else {
        this.obstacleRelativeVelocityVariance = new geometry_msgs.msg.Twist();
      }
      if (initObj.hasOwnProperty('groundHeight')) {
        this.groundHeight = initObj.groundHeight
      }
      else {
        this.groundHeight = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('classificationProbability')) {
        this.classificationProbability = initObj.classificationProbability
      }
      else {
        this.classificationProbability = 0.0;
      }
      if (initObj.hasOwnProperty('dateAcquisition')) {
        this.dateAcquisition = initObj.dateAcquisition
      }
      else {
        this.dateAcquisition = new std_msgs.msg.Float64();
      }
      if (initObj.hasOwnProperty('obstacleClass')) {
        this.obstacleClass = initObj.obstacleClass
      }
      else {
        this.obstacleClass = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ObstacleAlignment
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt16.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [obstaclePosition]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.obstaclePosition, buffer, bufferOffset);
    // Serialize message field [obstacleBodyCenter]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.obstacleBodyCenter, buffer, bufferOffset);
    // Serialize message field [obstacleVelocity]
    bufferOffset = geometry_msgs.msg.Twist.serialize(obj.obstacleVelocity, buffer, bufferOffset);
    // Serialize message field [obstacleRelativeVelocity]
    bufferOffset = geometry_msgs.msg.Twist.serialize(obj.obstacleRelativeVelocity, buffer, bufferOffset);
    // Serialize message field [obstacleAcceleration]
    bufferOffset = geometry_msgs.msg.Accel.serialize(obj.obstacleAcceleration, buffer, bufferOffset);
    // Serialize message field [obstacleDimensions]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.obstacleDimensions, buffer, bufferOffset);
    // Serialize message field [blinkerInfo]
    bufferOffset = _serializer.uint8(obj.blinkerInfo, buffer, bufferOffset);
    // Serialize message field [cutInAndOut]
    bufferOffset = _serializer.uint8(obj.cutInAndOut, buffer, bufferOffset);
    // Serialize message field [obstacleType]
    bufferOffset = _serializer.uint8(obj.obstacleType, buffer, bufferOffset);
    // Serialize message field [obstacleStatus]
    bufferOffset = _serializer.uint8(obj.obstacleStatus, buffer, bufferOffset);
    // Serialize message field [obstacleBrakeLights]
    bufferOffset = _serializer.bool(obj.obstacleBrakeLights, buffer, bufferOffset);
    // Serialize message field [cipvFlag]
    bufferOffset = _serializer.int8(obj.cipvFlag, buffer, bufferOffset);
    // Serialize message field [obstacleReplaced]
    bufferOffset = _serializer.int8(obj.obstacleReplaced, buffer, bufferOffset);
    // Serialize message field [obstacleValid]
    bufferOffset = _serializer.uint8(obj.obstacleValid, buffer, bufferOffset);
    // Serialize message field [obstacleAge]
    bufferOffset = _serializer.uint16(obj.obstacleAge, buffer, bufferOffset);
    // Serialize message field [obstacleLane]
    bufferOffset = _serializer.uint8(obj.obstacleLane, buffer, bufferOffset);
    // Serialize message field [obstacleAngle]
    bufferOffset = _serializer.float32(obj.obstacleAngle, buffer, bufferOffset);
    // Serialize message field [obstacleAngleVariance]
    bufferOffset = _serializer.float32(obj.obstacleAngleVariance, buffer, bufferOffset);
    // Serialize message field [obstacleAngleRate]
    bufferOffset = _serializer.float32(obj.obstacleAngleRate, buffer, bufferOffset);
    // Serialize message field [obstacleScaleChange]
    bufferOffset = _serializer.float64(obj.obstacleScaleChange, buffer, bufferOffset);
    // Serialize message field [vision_only_sign_type]
    bufferOffset = _serializer.uint8(obj.vision_only_sign_type, buffer, bufferOffset);
    // Serialize message field [visionOnlySupplementarySignType]
    bufferOffset = _serializer.uint8(obj.visionOnlySupplementarySignType, buffer, bufferOffset);
    // Serialize message field [signPosition]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.signPosition, buffer, bufferOffset);
    // Serialize message field [filterType]
    bufferOffset = _serializer.float64(obj.filterType, buffer, bufferOffset);
    // Serialize message field [obstaclePoseVariance]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.obstaclePoseVariance, buffer, bufferOffset);
    // Serialize message field [obstacleVelocityVariance]
    bufferOffset = geometry_msgs.msg.Twist.serialize(obj.obstacleVelocityVariance, buffer, bufferOffset);
    // Serialize message field [obstacleRelativeVelocityVariance]
    bufferOffset = geometry_msgs.msg.Twist.serialize(obj.obstacleRelativeVelocityVariance, buffer, bufferOffset);
    // Serialize message field [groundHeight]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.groundHeight, buffer, bufferOffset);
    // Serialize message field [classificationProbability]
    bufferOffset = _serializer.float64(obj.classificationProbability, buffer, bufferOffset);
    // Serialize message field [dateAcquisition]
    bufferOffset = std_msgs.msg.Float64.serialize(obj.dateAcquisition, buffer, bufferOffset);
    // Serialize message field [obstacleClass]
    bufferOffset = _serializer.uint8(obj.obstacleClass, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObstacleAlignment
    let len;
    let data = new ObstacleAlignment(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt16.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstaclePosition]
    data.obstaclePosition = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleBodyCenter]
    data.obstacleBodyCenter = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleVelocity]
    data.obstacleVelocity = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleRelativeVelocity]
    data.obstacleRelativeVelocity = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleAcceleration]
    data.obstacleAcceleration = geometry_msgs.msg.Accel.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleDimensions]
    data.obstacleDimensions = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [blinkerInfo]
    data.blinkerInfo = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [cutInAndOut]
    data.cutInAndOut = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [obstacleType]
    data.obstacleType = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [obstacleStatus]
    data.obstacleStatus = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [obstacleBrakeLights]
    data.obstacleBrakeLights = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [cipvFlag]
    data.cipvFlag = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [obstacleReplaced]
    data.obstacleReplaced = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [obstacleValid]
    data.obstacleValid = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [obstacleAge]
    data.obstacleAge = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [obstacleLane]
    data.obstacleLane = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [obstacleAngle]
    data.obstacleAngle = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [obstacleAngleVariance]
    data.obstacleAngleVariance = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [obstacleAngleRate]
    data.obstacleAngleRate = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [obstacleScaleChange]
    data.obstacleScaleChange = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [vision_only_sign_type]
    data.vision_only_sign_type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [visionOnlySupplementarySignType]
    data.visionOnlySupplementarySignType = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [signPosition]
    data.signPosition = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [filterType]
    data.filterType = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [obstaclePoseVariance]
    data.obstaclePoseVariance = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleVelocityVariance]
    data.obstacleVelocityVariance = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleRelativeVelocityVariance]
    data.obstacleRelativeVelocityVariance = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset);
    // Deserialize message field [groundHeight]
    data.groundHeight = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [classificationProbability]
    data.classificationProbability = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [dateAcquisition]
    data.dateAcquisition = std_msgs.msg.Float64.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleClass]
    data.obstacleClass = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 520;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ObstacleAlignment';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '04280698b06b552ba012942a850d8950';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt16 id
    
    geometry_msgs/Pose obstaclePosition	        		# obstacle position
    float64 obstaclePosition_linear_Unknown = 999
    float64 obstaclePosition_orientation_Unknown = 999
    
    geometry_msgs/Pose obstacleBodyCenter	        		# Obstacle Center for Corner Computation
    
    geometry_msgs/Twist obstacleVelocity	                    	# obstacle speed
    float64 obstacleVelocity_linear_Unknown = 999
    float64 obstacleVelocity_angular_Unknown = 999
    
    geometry_msgs/Twist obstacleRelativeVelocity	           	# obstacle relative velocity
    float64 obstacleRelativeVelocity_linear_Unknown = 999
    float64 obstacleRelativeVelocity_angular_Unknown = 999
    
    geometry_msgs/Accel obstacleAcceleration        		# obstacle acceleration
    float64 obstacleAcceleration_linear_Unknown = 999
    float64 obstacleAcceleration_angular_Unknown = 999
    
    geometry_msgs/Vector3 obstacleDimensions        		# obstacle - length and width
    float64 obstacleDimensions_Unknown = 999
    
    uint8 blinkerInfo                               		# blinker status (eg. left blinker on)
    uint8 blinkerInfo_Unknown=0
    
    uint8 cutInAndOut                               		# Vehicle cutting in or out of ego lane 
    uint8 cutInAndOut_Unknown=0
    
    uint8 obstacleType                             			# obstacle classification
    uint8 obstacleType_Unknown=7
    
    uint8 obstacleStatus                            		# obstacle’s moving status
    uint8 obstacleStatus_Unknown=0
    
    bool obstacleBrakeLights                        		# obstacle brake light on or off
    bool obstacleBrakeLights_Unknown=0 
    
    int8 cipvFlag                                   		# If obstacle Closest in Path Vehicle
    int8 cipvFlag_Unknown=2
    
    int8 obstacleReplaced                           		# If obstacle replaced in this frame
    int8 obstacleReplaced_Unknown=2
    
    uint8 obstacleValid                             		# obstacle valid
    uint8 obstacleValid_Unknown=3
    
    uint16 obstacleAge                              		# obstacle age in number of frames
    uint16 obstacleAge_Unknown=256
    
    uint8 obstacleLane                              		# obstacle's lane (eg. ego lane or next lane)
    uint8 obstacleLane_Unknown=0
    
    float32 obstacleAngle                           		# angle to center of obstacle in degrees
    float32 obstacleAngle_Unknown = 999
    
    float32 obstacleAngleVariance                   		# Obstacle angle Variance (Lidar)
    float32 obstacleAngleVariance_Unknown=-1
    
    float32 obstacleAngleRate                       		# angle rate of the center of obstacle (degrees/sec)
    float32 obstacleAngleRate_Unknown = 999
    
    float64 obstacleScaleChange                     		# scale change from previous frame   
    float64 obstacleScaleChange_Unknown = 999
                               
    uint8 vision_only_sign_type
    #uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type
    uint8 visionOnlySignType_Unknown=254
    
    uint8 visionOnlySupplementarySignType               		# Supplementary sign type - rain, snow, arrow etc. 
    uint8 visionOnlySupplementarySignType_Unknown=0
    
    geometry_msgs/Vector3 signPosition                  		# X-Longitudnal position, Y-Lateral position ,Z-Height of sign relative to ME
    float64 signPosition_Unknown = 999
    
    float64 filterType                                    		# filtering 
    float64 filterType_Unknown = 999
    
    geometry_msgs/Pose obstaclePoseVariance		                # obstacle position variance
    float64 obstaclePoseVariance_position_Unknown = -1
    float64 obstaclePoseVariance_orientation_Unknown = -1
    
    geometry_msgs/Twist obstacleVelocityVariance	                # obstacle speed variance
    float64 obstacleVelocityVariance_linear_Unknown = -1
    float64 obstacleVelocityVariance_angular_Unknown = -1
    
    geometry_msgs/Twist obstacleRelativeVelocityVariance	        # obstacle relative velocity variance
    float64 obstacleRelativeVelocityVariance_linear_Unknown = -1
    float64 obstacleRelativeVelocityVariance_angular_Unknown = -1
    
    std_msgs/Float32 groundHeight			                # ground height
    float64 groundHeight_Unknown = 999
    
    float64 classificationProbability
    float64 classificationProbability_Unknown = 999
    
    std_msgs/Float64 dateAcquisition
    float64 dateAcquisition_Unknown = 999
    
    uint8 obstacleClass
    
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
    MSG: std_msgs/UInt16
    uint16 data
    
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
      resolved.id = std_msgs.msg.UInt16.Resolve(msg.id)
    }
    else {
      resolved.id = new std_msgs.msg.UInt16()
    }

    if (msg.obstaclePosition !== undefined) {
      resolved.obstaclePosition = geometry_msgs.msg.Pose.Resolve(msg.obstaclePosition)
    }
    else {
      resolved.obstaclePosition = new geometry_msgs.msg.Pose()
    }

    if (msg.obstacleBodyCenter !== undefined) {
      resolved.obstacleBodyCenter = geometry_msgs.msg.Pose.Resolve(msg.obstacleBodyCenter)
    }
    else {
      resolved.obstacleBodyCenter = new geometry_msgs.msg.Pose()
    }

    if (msg.obstacleVelocity !== undefined) {
      resolved.obstacleVelocity = geometry_msgs.msg.Twist.Resolve(msg.obstacleVelocity)
    }
    else {
      resolved.obstacleVelocity = new geometry_msgs.msg.Twist()
    }

    if (msg.obstacleRelativeVelocity !== undefined) {
      resolved.obstacleRelativeVelocity = geometry_msgs.msg.Twist.Resolve(msg.obstacleRelativeVelocity)
    }
    else {
      resolved.obstacleRelativeVelocity = new geometry_msgs.msg.Twist()
    }

    if (msg.obstacleAcceleration !== undefined) {
      resolved.obstacleAcceleration = geometry_msgs.msg.Accel.Resolve(msg.obstacleAcceleration)
    }
    else {
      resolved.obstacleAcceleration = new geometry_msgs.msg.Accel()
    }

    if (msg.obstacleDimensions !== undefined) {
      resolved.obstacleDimensions = geometry_msgs.msg.Vector3.Resolve(msg.obstacleDimensions)
    }
    else {
      resolved.obstacleDimensions = new geometry_msgs.msg.Vector3()
    }

    if (msg.blinkerInfo !== undefined) {
      resolved.blinkerInfo = msg.blinkerInfo;
    }
    else {
      resolved.blinkerInfo = 0
    }

    if (msg.cutInAndOut !== undefined) {
      resolved.cutInAndOut = msg.cutInAndOut;
    }
    else {
      resolved.cutInAndOut = 0
    }

    if (msg.obstacleType !== undefined) {
      resolved.obstacleType = msg.obstacleType;
    }
    else {
      resolved.obstacleType = 0
    }

    if (msg.obstacleStatus !== undefined) {
      resolved.obstacleStatus = msg.obstacleStatus;
    }
    else {
      resolved.obstacleStatus = 0
    }

    if (msg.obstacleBrakeLights !== undefined) {
      resolved.obstacleBrakeLights = msg.obstacleBrakeLights;
    }
    else {
      resolved.obstacleBrakeLights = false
    }

    if (msg.cipvFlag !== undefined) {
      resolved.cipvFlag = msg.cipvFlag;
    }
    else {
      resolved.cipvFlag = 0
    }

    if (msg.obstacleReplaced !== undefined) {
      resolved.obstacleReplaced = msg.obstacleReplaced;
    }
    else {
      resolved.obstacleReplaced = 0
    }

    if (msg.obstacleValid !== undefined) {
      resolved.obstacleValid = msg.obstacleValid;
    }
    else {
      resolved.obstacleValid = 0
    }

    if (msg.obstacleAge !== undefined) {
      resolved.obstacleAge = msg.obstacleAge;
    }
    else {
      resolved.obstacleAge = 0
    }

    if (msg.obstacleLane !== undefined) {
      resolved.obstacleLane = msg.obstacleLane;
    }
    else {
      resolved.obstacleLane = 0
    }

    if (msg.obstacleAngle !== undefined) {
      resolved.obstacleAngle = msg.obstacleAngle;
    }
    else {
      resolved.obstacleAngle = 0.0
    }

    if (msg.obstacleAngleVariance !== undefined) {
      resolved.obstacleAngleVariance = msg.obstacleAngleVariance;
    }
    else {
      resolved.obstacleAngleVariance = 0.0
    }

    if (msg.obstacleAngleRate !== undefined) {
      resolved.obstacleAngleRate = msg.obstacleAngleRate;
    }
    else {
      resolved.obstacleAngleRate = 0.0
    }

    if (msg.obstacleScaleChange !== undefined) {
      resolved.obstacleScaleChange = msg.obstacleScaleChange;
    }
    else {
      resolved.obstacleScaleChange = 0.0
    }

    if (msg.vision_only_sign_type !== undefined) {
      resolved.vision_only_sign_type = msg.vision_only_sign_type;
    }
    else {
      resolved.vision_only_sign_type = 0
    }

    if (msg.visionOnlySupplementarySignType !== undefined) {
      resolved.visionOnlySupplementarySignType = msg.visionOnlySupplementarySignType;
    }
    else {
      resolved.visionOnlySupplementarySignType = 0
    }

    if (msg.signPosition !== undefined) {
      resolved.signPosition = geometry_msgs.msg.Vector3.Resolve(msg.signPosition)
    }
    else {
      resolved.signPosition = new geometry_msgs.msg.Vector3()
    }

    if (msg.filterType !== undefined) {
      resolved.filterType = msg.filterType;
    }
    else {
      resolved.filterType = 0.0
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

    if (msg.obstacleRelativeVelocityVariance !== undefined) {
      resolved.obstacleRelativeVelocityVariance = geometry_msgs.msg.Twist.Resolve(msg.obstacleRelativeVelocityVariance)
    }
    else {
      resolved.obstacleRelativeVelocityVariance = new geometry_msgs.msg.Twist()
    }

    if (msg.groundHeight !== undefined) {
      resolved.groundHeight = std_msgs.msg.Float32.Resolve(msg.groundHeight)
    }
    else {
      resolved.groundHeight = new std_msgs.msg.Float32()
    }

    if (msg.classificationProbability !== undefined) {
      resolved.classificationProbability = msg.classificationProbability;
    }
    else {
      resolved.classificationProbability = 0.0
    }

    if (msg.dateAcquisition !== undefined) {
      resolved.dateAcquisition = std_msgs.msg.Float64.Resolve(msg.dateAcquisition)
    }
    else {
      resolved.dateAcquisition = new std_msgs.msg.Float64()
    }

    if (msg.obstacleClass !== undefined) {
      resolved.obstacleClass = msg.obstacleClass;
    }
    else {
      resolved.obstacleClass = 0
    }

    return resolved;
    }
};

// Constants for message
ObstacleAlignment.Constants = {
  OBSTACLEPOSITION_LINEAR_UNKNOWN: 999.0,
  OBSTACLEPOSITION_ORIENTATION_UNKNOWN: 999.0,
  OBSTACLEVELOCITY_LINEAR_UNKNOWN: 999.0,
  OBSTACLEVELOCITY_ANGULAR_UNKNOWN: 999.0,
  OBSTACLERELATIVEVELOCITY_LINEAR_UNKNOWN: 999.0,
  OBSTACLERELATIVEVELOCITY_ANGULAR_UNKNOWN: 999.0,
  OBSTACLEACCELERATION_LINEAR_UNKNOWN: 999.0,
  OBSTACLEACCELERATION_ANGULAR_UNKNOWN: 999.0,
  OBSTACLEDIMENSIONS_UNKNOWN: 999.0,
  BLINKERINFO_UNKNOWN: 0,
  CUTINANDOUT_UNKNOWN: 0,
  OBSTACLETYPE_UNKNOWN: 7,
  OBSTACLESTATUS_UNKNOWN: 0,
  OBSTACLEBRAKELIGHTS_UNKNOWN: false,
  CIPVFLAG_UNKNOWN: 2,
  OBSTACLEREPLACED_UNKNOWN: 2,
  OBSTACLEVALID_UNKNOWN: 3,
  OBSTACLEAGE_UNKNOWN: 256,
  OBSTACLELANE_UNKNOWN: 0,
  OBSTACLEANGLE_UNKNOWN: 999.0,
  OBSTACLEANGLEVARIANCE_UNKNOWN: -1.0,
  OBSTACLEANGLERATE_UNKNOWN: 999.0,
  OBSTACLESCALECHANGE_UNKNOWN: 999.0,
  VISIONONLYSIGNTYPE_UNKNOWN: 254,
  VISIONONLYSUPPLEMENTARYSIGNTYPE_UNKNOWN: 0,
  SIGNPOSITION_UNKNOWN: 999.0,
  FILTERTYPE_UNKNOWN: 999.0,
  OBSTACLEPOSEVARIANCE_POSITION_UNKNOWN: -1.0,
  OBSTACLEPOSEVARIANCE_ORIENTATION_UNKNOWN: -1.0,
  OBSTACLEVELOCITYVARIANCE_LINEAR_UNKNOWN: -1.0,
  OBSTACLEVELOCITYVARIANCE_ANGULAR_UNKNOWN: -1.0,
  OBSTACLERELATIVEVELOCITYVARIANCE_LINEAR_UNKNOWN: -1.0,
  OBSTACLERELATIVEVELOCITYVARIANCE_ANGULAR_UNKNOWN: -1.0,
  GROUNDHEIGHT_UNKNOWN: 999.0,
  CLASSIFICATIONPROBABILITY_UNKNOWN: 999.0,
  DATEACQUISITION_UNKNOWN: 999.0,
}

module.exports = ObstacleAlignment;
