// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ObstacleFusion = require('./ObstacleFusion.js');
let nav_msgs = _finder('nav_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ObstacleFusionReport {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.ObstacleFusion = null;
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
      if (initObj.hasOwnProperty('ObstacleFusion')) {
        this.ObstacleFusion = initObj.ObstacleFusion
      }
      else {
        this.ObstacleFusion = new Array(127).fill(new ObstacleFusion());
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
    // Serializes a message object of type ObstacleFusionReport
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Check that the constant length array field [ObstacleFusion] has the right length
    if (obj.ObstacleFusion.length !== 127) {
      throw new Error('Unable to serialize array field ObstacleFusion - length must be 127')
    }
    // Serialize message field [ObstacleFusion]
    obj.ObstacleFusion.forEach((val) => {
      bufferOffset = ObstacleFusion.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [QtyObstacles]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.QtyObstacles, buffer, bufferOffset);
    // Serialize message field [odom]
    bufferOffset = nav_msgs.msg.Odometry.serialize(obj.odom, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObstacleFusionReport
    let len;
    let data = new ObstacleFusionReport(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [ObstacleFusion]
    len = 127;
    data.ObstacleFusion = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.ObstacleFusion[i] = ObstacleFusion.deserialize(buffer, bufferOffset)
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
    object.ObstacleFusion.forEach((val) => {
      length += ObstacleFusion.getMessageSize(val);
    });
    length += nav_msgs.msg.Odometry.getMessageSize(object.odom);
    return length + 2;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ObstacleFusionReport';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '699d031838fdda967f55404a6c4b9748';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    uint8 OBSTACLE_FUSION_REPORT_SIZE = 127
    project_s_msgs/ObstacleFusion[127] ObstacleFusion
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
    MSG: project_s_msgs/ObstacleFusion
    Header header
    std_msgs/UInt8 id
    
    geometry_msgs/Pose obstaclePosition		# obstacle position
    geometry_msgs/Pose obstacleBodyCenter	        # Obstacle Center for Corner Computation
    float32 distanceCurviligne
    std_msgs/Float32 groundHeight			# ground height
    geometry_msgs/Twist obstacleVelocity		# obstacle speed
    geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
    geometry_msgs/Vector3 obstacleCap
    std_msgs/UInt8 existenceProbability
    std_msgs/UInt8 existenceState
    uint8 IDLE_TRACK    = 0
    uint8 PRE_TRACK	    = 1
    uint8 POST_TRACK    = 2
    uint8 CURRENT_TRACK = 3
    std_msgs/Float32 scoreDetection
    std_msgs/Float32 nbrDetection
    std_msgs/Float32 nbrVisibility
    std_msgs/Float32 scorePersistence
    std_msgs/Float32 nbrUpdate
    std_msgs/Float32 nbrAge
    time existenceFirstTime
    std_msgs/Float32 existenceDurationTime
    std_msgs/UInt8 anchorPoint			# reference point
    geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance
    geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance
    geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height
    uint8 obstacleClass
    uint8 vision_only_sign_type
    std_msgs/UInt8 classificationProbability
    
    uint8 obstacleAssignment
    uint8 ASSIGNMENT_COTE_DROIT  = 1
    uint8 ASSIGNMENT_COTE_GAUCHE = 2
    
    uint8 CORNER_FRONT_RIGHT= 0
    uint8 CORNER_FRONT_LEFT = 1
    uint8 CORNER_BACK_RIGHT = 2
    uint8 CORNER_BACK_LEFT  = 3
    geometry_msgs/Point[4] obstacleCorner
    
    uint8 OCCUPIED_LANE_INDEFINI  = 255
    uint8 NbrOccupiedLane
    uint8 INDEX_LINE_INDEFINI  = 255
    uint8[2] indexAssignmentLine
    std_msgs/Float32 positionLane
    std_msgs/Float32 departureRighttDistance
    std_msgs/Float32 departureLeftDistance
    
    std_msgs/Int16 trafficLights
    std_msgs/Int16 vehicleLights
    std_msgs/UInt16[3] idPiste			#define NBR_SENSOR		3	(voir obstacles_fusion.cpp)
    
    # History
    
    
    
    
    
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
    MSG: std_msgs/Float32
    float32 data
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
    MSG: std_msgs/Int16
    int16 data
    
    ================================================================================
    MSG: std_msgs/UInt16
    uint16 data
    
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
    const resolved = new ObstacleFusionReport(null);
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

    if (msg.ObstacleFusion !== undefined) {
      resolved.ObstacleFusion = new Array(127)
      for (let i = 0; i < resolved.ObstacleFusion.length; ++i) {
        if (msg.ObstacleFusion.length > i) {
          resolved.ObstacleFusion[i] = ObstacleFusion.Resolve(msg.ObstacleFusion[i]);
        }
        else {
          resolved.ObstacleFusion[i] = new ObstacleFusion();
        }
      }
    }
    else {
      resolved.ObstacleFusion = new Array(127).fill(new ObstacleFusion())
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

// Constants for message
ObstacleFusionReport.Constants = {
  OBSTACLE_FUSION_REPORT_SIZE: 127,
}

module.exports = ObstacleFusionReport;
