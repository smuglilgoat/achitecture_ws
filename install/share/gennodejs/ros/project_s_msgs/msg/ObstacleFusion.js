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

class ObstacleFusion {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.obstaclePosition = null;
      this.obstacleBodyCenter = null;
      this.distanceCurviligne = null;
      this.groundHeight = null;
      this.obstacleVelocity = null;
      this.obstacleAcceleration = null;
      this.obstacleCap = null;
      this.existenceProbability = null;
      this.existenceState = null;
      this.scoreDetection = null;
      this.nbrDetection = null;
      this.nbrVisibility = null;
      this.scorePersistence = null;
      this.nbrUpdate = null;
      this.nbrAge = null;
      this.existenceFirstTime = null;
      this.existenceDurationTime = null;
      this.anchorPoint = null;
      this.obstaclePoseVariance = null;
      this.obstacleVelocityVariance = null;
      this.obstacleDimensions = null;
      this.obstacleClass = null;
      this.vision_only_sign_type = null;
      this.classificationProbability = null;
      this.obstacleAssignment = null;
      this.obstacleCorner = null;
      this.NbrOccupiedLane = null;
      this.indexAssignmentLine = null;
      this.positionLane = null;
      this.departureRighttDistance = null;
      this.departureLeftDistance = null;
      this.trafficLights = null;
      this.vehicleLights = null;
      this.idPiste = null;
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
      if (initObj.hasOwnProperty('obstacleBodyCenter')) {
        this.obstacleBodyCenter = initObj.obstacleBodyCenter
      }
      else {
        this.obstacleBodyCenter = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('distanceCurviligne')) {
        this.distanceCurviligne = initObj.distanceCurviligne
      }
      else {
        this.distanceCurviligne = 0.0;
      }
      if (initObj.hasOwnProperty('groundHeight')) {
        this.groundHeight = initObj.groundHeight
      }
      else {
        this.groundHeight = new std_msgs.msg.Float32();
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
      if (initObj.hasOwnProperty('obstacleCap')) {
        this.obstacleCap = initObj.obstacleCap
      }
      else {
        this.obstacleCap = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('existenceProbability')) {
        this.existenceProbability = initObj.existenceProbability
      }
      else {
        this.existenceProbability = new std_msgs.msg.UInt8();
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
      if (initObj.hasOwnProperty('existenceFirstTime')) {
        this.existenceFirstTime = initObj.existenceFirstTime
      }
      else {
        this.existenceFirstTime = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('existenceDurationTime')) {
        this.existenceDurationTime = initObj.existenceDurationTime
      }
      else {
        this.existenceDurationTime = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('anchorPoint')) {
        this.anchorPoint = initObj.anchorPoint
      }
      else {
        this.anchorPoint = new std_msgs.msg.UInt8();
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
      if (initObj.hasOwnProperty('obstacleAssignment')) {
        this.obstacleAssignment = initObj.obstacleAssignment
      }
      else {
        this.obstacleAssignment = 0;
      }
      if (initObj.hasOwnProperty('obstacleCorner')) {
        this.obstacleCorner = initObj.obstacleCorner
      }
      else {
        this.obstacleCorner = new Array(4).fill(new geometry_msgs.msg.Point());
      }
      if (initObj.hasOwnProperty('NbrOccupiedLane')) {
        this.NbrOccupiedLane = initObj.NbrOccupiedLane
      }
      else {
        this.NbrOccupiedLane = 0;
      }
      if (initObj.hasOwnProperty('indexAssignmentLine')) {
        this.indexAssignmentLine = initObj.indexAssignmentLine
      }
      else {
        this.indexAssignmentLine = new Array(2).fill(0);
      }
      if (initObj.hasOwnProperty('positionLane')) {
        this.positionLane = initObj.positionLane
      }
      else {
        this.positionLane = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('departureRighttDistance')) {
        this.departureRighttDistance = initObj.departureRighttDistance
      }
      else {
        this.departureRighttDistance = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('departureLeftDistance')) {
        this.departureLeftDistance = initObj.departureLeftDistance
      }
      else {
        this.departureLeftDistance = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('trafficLights')) {
        this.trafficLights = initObj.trafficLights
      }
      else {
        this.trafficLights = new std_msgs.msg.Int16();
      }
      if (initObj.hasOwnProperty('vehicleLights')) {
        this.vehicleLights = initObj.vehicleLights
      }
      else {
        this.vehicleLights = new std_msgs.msg.Int16();
      }
      if (initObj.hasOwnProperty('idPiste')) {
        this.idPiste = initObj.idPiste
      }
      else {
        this.idPiste = new Array(3).fill(new std_msgs.msg.UInt16());
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ObstacleFusion
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [obstaclePosition]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.obstaclePosition, buffer, bufferOffset);
    // Serialize message field [obstacleBodyCenter]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.obstacleBodyCenter, buffer, bufferOffset);
    // Serialize message field [distanceCurviligne]
    bufferOffset = _serializer.float32(obj.distanceCurviligne, buffer, bufferOffset);
    // Serialize message field [groundHeight]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.groundHeight, buffer, bufferOffset);
    // Serialize message field [obstacleVelocity]
    bufferOffset = geometry_msgs.msg.Twist.serialize(obj.obstacleVelocity, buffer, bufferOffset);
    // Serialize message field [obstacleAcceleration]
    bufferOffset = geometry_msgs.msg.Accel.serialize(obj.obstacleAcceleration, buffer, bufferOffset);
    // Serialize message field [obstacleCap]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.obstacleCap, buffer, bufferOffset);
    // Serialize message field [existenceProbability]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.existenceProbability, buffer, bufferOffset);
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
    // Serialize message field [existenceFirstTime]
    bufferOffset = _serializer.time(obj.existenceFirstTime, buffer, bufferOffset);
    // Serialize message field [existenceDurationTime]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.existenceDurationTime, buffer, bufferOffset);
    // Serialize message field [anchorPoint]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.anchorPoint, buffer, bufferOffset);
    // Serialize message field [obstaclePoseVariance]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.obstaclePoseVariance, buffer, bufferOffset);
    // Serialize message field [obstacleVelocityVariance]
    bufferOffset = geometry_msgs.msg.Twist.serialize(obj.obstacleVelocityVariance, buffer, bufferOffset);
    // Serialize message field [obstacleDimensions]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.obstacleDimensions, buffer, bufferOffset);
    // Serialize message field [obstacleClass]
    bufferOffset = _serializer.uint8(obj.obstacleClass, buffer, bufferOffset);
    // Serialize message field [vision_only_sign_type]
    bufferOffset = _serializer.uint8(obj.vision_only_sign_type, buffer, bufferOffset);
    // Serialize message field [classificationProbability]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.classificationProbability, buffer, bufferOffset);
    // Serialize message field [obstacleAssignment]
    bufferOffset = _serializer.uint8(obj.obstacleAssignment, buffer, bufferOffset);
    // Check that the constant length array field [obstacleCorner] has the right length
    if (obj.obstacleCorner.length !== 4) {
      throw new Error('Unable to serialize array field obstacleCorner - length must be 4')
    }
    // Serialize message field [obstacleCorner]
    obj.obstacleCorner.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [NbrOccupiedLane]
    bufferOffset = _serializer.uint8(obj.NbrOccupiedLane, buffer, bufferOffset);
    // Check that the constant length array field [indexAssignmentLine] has the right length
    if (obj.indexAssignmentLine.length !== 2) {
      throw new Error('Unable to serialize array field indexAssignmentLine - length must be 2')
    }
    // Serialize message field [indexAssignmentLine]
    bufferOffset = _arraySerializer.uint8(obj.indexAssignmentLine, buffer, bufferOffset, 2);
    // Serialize message field [positionLane]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.positionLane, buffer, bufferOffset);
    // Serialize message field [departureRighttDistance]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.departureRighttDistance, buffer, bufferOffset);
    // Serialize message field [departureLeftDistance]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.departureLeftDistance, buffer, bufferOffset);
    // Serialize message field [trafficLights]
    bufferOffset = std_msgs.msg.Int16.serialize(obj.trafficLights, buffer, bufferOffset);
    // Serialize message field [vehicleLights]
    bufferOffset = std_msgs.msg.Int16.serialize(obj.vehicleLights, buffer, bufferOffset);
    // Check that the constant length array field [idPiste] has the right length
    if (obj.idPiste.length !== 3) {
      throw new Error('Unable to serialize array field idPiste - length must be 3')
    }
    // Serialize message field [idPiste]
    obj.idPiste.forEach((val) => {
      bufferOffset = std_msgs.msg.UInt16.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObstacleFusion
    let len;
    let data = new ObstacleFusion(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstaclePosition]
    data.obstaclePosition = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleBodyCenter]
    data.obstacleBodyCenter = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [distanceCurviligne]
    data.distanceCurviligne = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [groundHeight]
    data.groundHeight = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleVelocity]
    data.obstacleVelocity = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleAcceleration]
    data.obstacleAcceleration = geometry_msgs.msg.Accel.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleCap]
    data.obstacleCap = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [existenceProbability]
    data.existenceProbability = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
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
    // Deserialize message field [existenceFirstTime]
    data.existenceFirstTime = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [existenceDurationTime]
    data.existenceDurationTime = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [anchorPoint]
    data.anchorPoint = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstaclePoseVariance]
    data.obstaclePoseVariance = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleVelocityVariance]
    data.obstacleVelocityVariance = geometry_msgs.msg.Twist.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleDimensions]
    data.obstacleDimensions = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleClass]
    data.obstacleClass = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [vision_only_sign_type]
    data.vision_only_sign_type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [classificationProbability]
    data.classificationProbability = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [obstacleAssignment]
    data.obstacleAssignment = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [obstacleCorner]
    len = 4;
    data.obstacleCorner = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.obstacleCorner[i] = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [NbrOccupiedLane]
    data.NbrOccupiedLane = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [indexAssignmentLine]
    data.indexAssignmentLine = _arrayDeserializer.uint8(buffer, bufferOffset, 2)
    // Deserialize message field [positionLane]
    data.positionLane = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [departureRighttDistance]
    data.departureRighttDistance = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [departureLeftDistance]
    data.departureLeftDistance = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [trafficLights]
    data.trafficLights = std_msgs.msg.Int16.deserialize(buffer, bufferOffset);
    // Deserialize message field [vehicleLights]
    data.vehicleLights = std_msgs.msg.Int16.deserialize(buffer, bufferOffset);
    // Deserialize message field [idPiste]
    len = 3;
    data.idPiste = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.idPiste[i] = std_msgs.msg.UInt16.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 533;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/ObstacleFusion';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '664d48d67f466ce15a45b6a2d40f7977';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ObstacleFusion(null);
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

    if (msg.obstacleBodyCenter !== undefined) {
      resolved.obstacleBodyCenter = geometry_msgs.msg.Pose.Resolve(msg.obstacleBodyCenter)
    }
    else {
      resolved.obstacleBodyCenter = new geometry_msgs.msg.Pose()
    }

    if (msg.distanceCurviligne !== undefined) {
      resolved.distanceCurviligne = msg.distanceCurviligne;
    }
    else {
      resolved.distanceCurviligne = 0.0
    }

    if (msg.groundHeight !== undefined) {
      resolved.groundHeight = std_msgs.msg.Float32.Resolve(msg.groundHeight)
    }
    else {
      resolved.groundHeight = new std_msgs.msg.Float32()
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

    if (msg.obstacleCap !== undefined) {
      resolved.obstacleCap = geometry_msgs.msg.Vector3.Resolve(msg.obstacleCap)
    }
    else {
      resolved.obstacleCap = new geometry_msgs.msg.Vector3()
    }

    if (msg.existenceProbability !== undefined) {
      resolved.existenceProbability = std_msgs.msg.UInt8.Resolve(msg.existenceProbability)
    }
    else {
      resolved.existenceProbability = new std_msgs.msg.UInt8()
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

    if (msg.existenceFirstTime !== undefined) {
      resolved.existenceFirstTime = msg.existenceFirstTime;
    }
    else {
      resolved.existenceFirstTime = {secs: 0, nsecs: 0}
    }

    if (msg.existenceDurationTime !== undefined) {
      resolved.existenceDurationTime = std_msgs.msg.Float32.Resolve(msg.existenceDurationTime)
    }
    else {
      resolved.existenceDurationTime = new std_msgs.msg.Float32()
    }

    if (msg.anchorPoint !== undefined) {
      resolved.anchorPoint = std_msgs.msg.UInt8.Resolve(msg.anchorPoint)
    }
    else {
      resolved.anchorPoint = new std_msgs.msg.UInt8()
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

    if (msg.obstacleAssignment !== undefined) {
      resolved.obstacleAssignment = msg.obstacleAssignment;
    }
    else {
      resolved.obstacleAssignment = 0
    }

    if (msg.obstacleCorner !== undefined) {
      resolved.obstacleCorner = new Array(4)
      for (let i = 0; i < resolved.obstacleCorner.length; ++i) {
        if (msg.obstacleCorner.length > i) {
          resolved.obstacleCorner[i] = geometry_msgs.msg.Point.Resolve(msg.obstacleCorner[i]);
        }
        else {
          resolved.obstacleCorner[i] = new geometry_msgs.msg.Point();
        }
      }
    }
    else {
      resolved.obstacleCorner = new Array(4).fill(new geometry_msgs.msg.Point())
    }

    if (msg.NbrOccupiedLane !== undefined) {
      resolved.NbrOccupiedLane = msg.NbrOccupiedLane;
    }
    else {
      resolved.NbrOccupiedLane = 0
    }

    if (msg.indexAssignmentLine !== undefined) {
      resolved.indexAssignmentLine = msg.indexAssignmentLine;
    }
    else {
      resolved.indexAssignmentLine = new Array(2).fill(0)
    }

    if (msg.positionLane !== undefined) {
      resolved.positionLane = std_msgs.msg.Float32.Resolve(msg.positionLane)
    }
    else {
      resolved.positionLane = new std_msgs.msg.Float32()
    }

    if (msg.departureRighttDistance !== undefined) {
      resolved.departureRighttDistance = std_msgs.msg.Float32.Resolve(msg.departureRighttDistance)
    }
    else {
      resolved.departureRighttDistance = new std_msgs.msg.Float32()
    }

    if (msg.departureLeftDistance !== undefined) {
      resolved.departureLeftDistance = std_msgs.msg.Float32.Resolve(msg.departureLeftDistance)
    }
    else {
      resolved.departureLeftDistance = new std_msgs.msg.Float32()
    }

    if (msg.trafficLights !== undefined) {
      resolved.trafficLights = std_msgs.msg.Int16.Resolve(msg.trafficLights)
    }
    else {
      resolved.trafficLights = new std_msgs.msg.Int16()
    }

    if (msg.vehicleLights !== undefined) {
      resolved.vehicleLights = std_msgs.msg.Int16.Resolve(msg.vehicleLights)
    }
    else {
      resolved.vehicleLights = new std_msgs.msg.Int16()
    }

    if (msg.idPiste !== undefined) {
      resolved.idPiste = new Array(3)
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
      resolved.idPiste = new Array(3).fill(new std_msgs.msg.UInt16())
    }

    return resolved;
    }
};

// Constants for message
ObstacleFusion.Constants = {
  IDLE_TRACK: 0,
  PRE_TRACK: 1,
  POST_TRACK: 2,
  CURRENT_TRACK: 3,
  ASSIGNMENT_COTE_DROIT: 1,
  ASSIGNMENT_COTE_GAUCHE: 2,
  CORNER_FRONT_RIGHT: 0,
  CORNER_FRONT_LEFT: 1,
  CORNER_BACK_RIGHT: 2,
  CORNER_BACK_LEFT: 3,
  OCCUPIED_LANE_INDEFINI: 255,
  INDEX_LINE_INDEFINI: 255,
}

module.exports = ObstacleFusion;
