// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ObstacleSynchronizeReport = require('./ObstacleSynchronizeReport.js');
let ObstacleFusionReport = require('./ObstacleFusionReport.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ObstacleSynchronizeReportComplet {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.ObstacleSynchronizeReport = null;
      this.ObstacleFusionReport = null;
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
      if (initObj.hasOwnProperty('ObstacleSynchronizeReport')) {
        this.ObstacleSynchronizeReport = initObj.ObstacleSynchronizeReport
      }
      else {
        this.ObstacleSynchronizeReport = new ObstacleSynchronizeReport();
      }
      if (initObj.hasOwnProperty('ObstacleFusionReport')) {
        this.ObstacleFusionReport = initObj.ObstacleFusionReport
      }
      else {
        this.ObstacleFusionReport = new ObstacleFusionReport();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ObstacleSynchronizeReportComplet
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [ObstacleSynchronizeReport]
    bufferOffset = ObstacleSynchronizeReport.serialize(obj.ObstacleSynchronizeReport, buffer, bufferOffset);
    // Serialize message field [ObstacleFusionReport]
    bufferOffset = ObstacleFusionReport.serialize(obj.ObstacleFusionReport, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObstacleSynchronizeReportComplet
    let len;
    let data = new ObstacleSynchronizeReportComplet(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [ObstacleSynchronizeReport]
    data.ObstacleSynchronizeReport = ObstacleSynchronizeReport.deserialize(buffer, bufferOffset);
    // Deserialize message field [ObstacleFusionReport]
    data.ObstacleFusionReport = ObstacleFusionReport.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += ObstacleSynchronizeReport.getMessageSize(object.ObstacleSynchronizeReport);
    length += ObstacleFusionReport.getMessageSize(object.ObstacleFusionReport);
    return length + 1;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ObstacleSynchronizeReportComplet';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6e152dddc1d8361d76321cd7de3a60ea';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    project_s_msgs/ObstacleSynchronizeReport ObstacleSynchronizeReport
    project_s_msgs/ObstacleFusionReport      ObstacleFusionReport
    
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
    MSG: project_s_msgs/ObstacleSynchronizeReport
    Header header
    std_msgs/UInt8 id
    nav_msgs/Odometry odom
    
    project_s_msgs/ObstacleAlignmentReport[3] ObstacleSynchronizeReport	# en concordance avec #define NBR_SENSOR de obstacles_fusion/local_tracks_synchro.cpp
    
    # History
    
    
    
    
    
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
    MSG: geometry_msgs/TwistWithCovariance
    # This expresses velocity in free space with uncertainty.
    
    Twist twist
    
    # Row-major representation of the 6x6 covariance matrix
    # The orientation parameters use a fixed-axis representation.
    # In order, the parameters are:
    # (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
    float64[36] covariance
    
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
    MSG: project_s_msgs/ObstacleAlignmentReport
    Header header
    std_msgs/UInt8 id
    
    uint8 OBSTACLE_ALIGNMENT_REPORT_SIZE = 127
    project_s_msgs/ObstacleAlignment[127] ObstacleAlignement
    std_msgs/UInt8 QtyObstacles
    nav_msgs/Odometry odom
    
    # History
    
    
    
    
    
    ================================================================================
    MSG: project_s_msgs/ObstacleAlignment
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
    MSG: std_msgs/UInt16
    uint16 data
    
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
    MSG: project_s_msgs/ObstacleFusionReport
    Header header
    std_msgs/UInt8 id
    
    uint8 OBSTACLE_FUSION_REPORT_SIZE = 127
    project_s_msgs/ObstacleFusion[127] ObstacleFusion
    std_msgs/UInt8 QtyObstacles
    nav_msgs/Odometry odom
    
    # History
    
    
    
    
    
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
    MSG: std_msgs/Int16
    int16 data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ObstacleSynchronizeReportComplet(null);
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

    if (msg.ObstacleSynchronizeReport !== undefined) {
      resolved.ObstacleSynchronizeReport = ObstacleSynchronizeReport.Resolve(msg.ObstacleSynchronizeReport)
    }
    else {
      resolved.ObstacleSynchronizeReport = new ObstacleSynchronizeReport()
    }

    if (msg.ObstacleFusionReport !== undefined) {
      resolved.ObstacleFusionReport = ObstacleFusionReport.Resolve(msg.ObstacleFusionReport)
    }
    else {
      resolved.ObstacleFusionReport = new ObstacleFusionReport()
    }

    return resolved;
    }
};

module.exports = ObstacleSynchronizeReportComplet;
