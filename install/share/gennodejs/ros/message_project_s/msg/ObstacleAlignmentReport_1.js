// Auto-generated. Do not edit!

// (in-package message_project_s.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ObstacleAlignment_1 = require('./ObstacleAlignment_1.js');
let nav_msgs = _finder('nav_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ObstacleAlignmentReport_1 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.ObstacleAlignement_1 = null;
      this.QtyObstacles = null;
      this.odom = null;
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
      if (initObj.hasOwnProperty('ObstacleAlignement_1')) {
        this.ObstacleAlignement_1 = initObj.ObstacleAlignement_1
      }
      else {
        this.ObstacleAlignement_1 = [];
      }
      if (initObj.hasOwnProperty('QtyObstacles')) {
        this.QtyObstacles = initObj.QtyObstacles
      }
      else {
        this.QtyObstacles = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('odom')) {
        this.odom = initObj.odom
      }
      else {
        this.odom = new nav_msgs.msg.Odometry();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ObstacleAlignmentReport_1
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [ObstacleAlignement_1]
    // Serialize the length for message field [ObstacleAlignement_1]
    bufferOffset = _serializer.uint32(obj.ObstacleAlignement_1.length, buffer, bufferOffset);
    obj.ObstacleAlignement_1.forEach((val) => {
      bufferOffset = ObstacleAlignment_1.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [QtyObstacles]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.QtyObstacles, buffer, bufferOffset);
    // Serialize message field [odom]
    bufferOffset = nav_msgs.msg.Odometry.serialize(obj.odom, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObstacleAlignmentReport_1
    let len;
    let data = new ObstacleAlignmentReport_1(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [ObstacleAlignement_1]
    // Deserialize array length for message field [ObstacleAlignement_1]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.ObstacleAlignement_1 = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ObstacleAlignement_1[i] = ObstacleAlignment_1.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [QtyObstacles]
    data.QtyObstacles = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [odom]
    data.odom = nav_msgs.msg.Odometry.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.ObstacleAlignement_1.forEach((val) => {
      length += ObstacleAlignment_1.getMessageSize(val);
    });
    length += nav_msgs.msg.Odometry.getMessageSize(object.odom);
    return length + 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'message_project_s/ObstacleAlignmentReport_1';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4857983c7466f8b6a84b30dd769dde24';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    message_project_s/ObstacleAlignment_1[] ObstacleAlignement_1
    
    std_msgs/UInt8 QtyObstacles
    nav_msgs/Odometry odom
    
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
    MSG: message_project_s/ObstacleAlignment_1
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
                               
    uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type
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
    
    
    # History
    
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
    ================================================================================
    MSG: nav_msgs/Odometry
    # This represents an estimate of a position and velocity in free space.  
    # The pose in this message should be specified in the coordinate frame given by header.frame_id.
    # The twist in this message should be specified in the coordinate frame given by the child_frame_id
    Header header
    string child_frame_id
    geometry_msgs/PoseWithCovariance pose
    geometry_msgs/TwistWithCovariance twist
    
    ================================================================================
    MSG: geometry_msgs/PoseWithCovariance
    # This represents a pose in free space with uncertainty.
    
    Pose pose
    
    # Row-major representation of the 6x6 covariance matrix
    # The orientation parameters use a fixed-axis representation.
    # In order, the parameters are:
    # (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
    float64[36] covariance
    
    ================================================================================
    MSG: geometry_msgs/TwistWithCovariance
    # This expresses velocity in free space with uncertainty.
    
    Twist twist
    
    # Row-major representation of the 6x6 covariance matrix
    # The orientation parameters use a fixed-axis representation.
    # In order, the parameters are:
    # (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
    float64[36] covariance
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ObstacleAlignmentReport_1(null);
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

    if (msg.ObstacleAlignement_1 !== undefined) {
      resolved.ObstacleAlignement_1 = new Array(msg.ObstacleAlignement_1.length);
      for (let i = 0; i < resolved.ObstacleAlignement_1.length; ++i) {
        resolved.ObstacleAlignement_1[i] = ObstacleAlignment_1.Resolve(msg.ObstacleAlignement_1[i]);
      }
    }
    else {
      resolved.ObstacleAlignement_1 = []
    }

    if (msg.QtyObstacles !== undefined) {
      resolved.QtyObstacles = std_msgs.msg.UInt8.Resolve(msg.QtyObstacles)
    }
    else {
      resolved.QtyObstacles = new std_msgs.msg.UInt8()
    }

    if (msg.odom !== undefined) {
      resolved.odom = nav_msgs.msg.Odometry.Resolve(msg.odom)
    }
    else {
      resolved.odom = new nav_msgs.msg.Odometry()
    }

    return resolved;
    }
};

module.exports = ObstacleAlignmentReport_1;
