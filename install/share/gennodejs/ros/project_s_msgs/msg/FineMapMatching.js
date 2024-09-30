// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ElectronicHorizonArray = require('./ElectronicHorizonArray.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class FineMapMatching {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.dCap = null;
      this.d_x_lambert = null;
      this.d_y_lambert = null;
      this.d_latitude = null;
      this.d_longitude = null;
      this.electronicHorizonArray = null;
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
      if (initObj.hasOwnProperty('dCap')) {
        this.dCap = initObj.dCap
      }
      else {
        this.dCap = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('d_x_lambert')) {
        this.d_x_lambert = initObj.d_x_lambert
      }
      else {
        this.d_x_lambert = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('d_y_lambert')) {
        this.d_y_lambert = initObj.d_y_lambert
      }
      else {
        this.d_y_lambert = new std_msgs.msg.Float32();
      }
      if (initObj.hasOwnProperty('d_latitude')) {
        this.d_latitude = initObj.d_latitude
      }
      else {
        this.d_latitude = 0.0;
      }
      if (initObj.hasOwnProperty('d_longitude')) {
        this.d_longitude = initObj.d_longitude
      }
      else {
        this.d_longitude = 0.0;
      }
      if (initObj.hasOwnProperty('electronicHorizonArray')) {
        this.electronicHorizonArray = initObj.electronicHorizonArray
      }
      else {
        this.electronicHorizonArray = new ElectronicHorizonArray();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FineMapMatching
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [dCap]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.dCap, buffer, bufferOffset);
    // Serialize message field [d_x_lambert]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.d_x_lambert, buffer, bufferOffset);
    // Serialize message field [d_y_lambert]
    bufferOffset = std_msgs.msg.Float32.serialize(obj.d_y_lambert, buffer, bufferOffset);
    // Serialize message field [d_latitude]
    bufferOffset = _serializer.float64(obj.d_latitude, buffer, bufferOffset);
    // Serialize message field [d_longitude]
    bufferOffset = _serializer.float64(obj.d_longitude, buffer, bufferOffset);
    // Serialize message field [electronicHorizonArray]
    bufferOffset = ElectronicHorizonArray.serialize(obj.electronicHorizonArray, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FineMapMatching
    let len;
    let data = new FineMapMatching(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [dCap]
    data.dCap = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [d_x_lambert]
    data.d_x_lambert = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [d_y_lambert]
    data.d_y_lambert = std_msgs.msg.Float32.deserialize(buffer, bufferOffset);
    // Deserialize message field [d_latitude]
    data.d_latitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [d_longitude]
    data.d_longitude = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [electronicHorizonArray]
    data.electronicHorizonArray = ElectronicHorizonArray.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += ElectronicHorizonArray.getMessageSize(object.electronicHorizonArray);
    return length + 29;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/FineMapMatching';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bbc6c31487a0775416bf98fdaad9098b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    std_msgs/Float32 dCap
    
    std_msgs/Float32 d_x_lambert	# sens sud   -> nord, unité en m
    std_msgs/Float32 d_y_lambert	# sens ouest -> est , unité en m
    
    float64 d_latitude	# unité en °
    float64 d_longitude	# unité en °
    
    project_s_msgs/ElectronicHorizonArray electronicHorizonArray
    
    
    
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
    MSG: std_msgs/Float32
    float32 data
    ================================================================================
    MSG: project_s_msgs/ElectronicHorizonArray
    Header header
    std_msgs/UInt8 id
    
    project_s_msgs/ElectronicHorizon[5] PathsArray
    std_msgs/UInt8 NbrPath
    std_msgs/UInt8 indexMPP
    
    nav_msgs/Odometry odom
    
    
    
    ================================================================================
    MSG: project_s_msgs/ElectronicHorizon
    Header header
    std_msgs/UInt8 id
    
    std_msgs/UInt8 indexPath
    
    uint8 SEGMENT_REPORT_SIZE = 50
    project_s_msgs/ehSegment[50] ehSegment
    std_msgs/UInt8 NbrSegment
    
    uint8 STUB_REPORT_SIZE = 10
    project_s_msgs/ehStub[10] ehStub
    std_msgs/UInt8 NbrStub
    
    uint16 SPOT_CURVATURE_REPORT_SIZE = 300
    project_s_msgs/ehSpotCurvature[300] ehSpotCurvature
    std_msgs/UInt16 NbrSpotCurvature
    
    uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000
    project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight
    std_msgs/UInt16 NbrSpotCoordGeoRight
    project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft
    std_msgs/UInt16 NbrSpotCoordGeoLeft
    
    uint8 LINE_REPORT_SIZE = 10
    project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo
    std_msgs/UInt8 QtyLineCoordGeo
    
    uint8 ME_RIGHT_LINE = 0
    uint8 ME_LEFT_LINE = 1
    project_s_msgs/ehME[2] ehME
    
    uint8 NBR_LINE_REPORT_SIZE = 100
    project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo
    std_msgs/UInt8 QtyNbrLineCoordGeo
    
    uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50
    project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign
    std_msgs/UInt8 NbrSpotTrafficSign
    
    project_s_msgs/ehPosition ehPosition
    
    uint8 speedLimit_interpolMethod
    uint8 curvature_interpolMethod
    uint8 STEP = 0
    uint8 LINEAR = 1
    
    uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100
    project_s_msgs/ehSegmentME[100] ehSegmentAO
    std_msgs/UInt8 QtySegmentAO
    
    uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100
    project_s_msgs/ehSegmentME[100] ehSegmentEO
    std_msgs/UInt8 QtySegmentEO
    
    
    ================================================================================
    MSG: project_s_msgs/ehSegment
    Header header
    std_msgs/UInt8 id
    
    #std_msgs/UInt8 indexPath
    std_msgs/Float32 offset
    std_msgs/UInt8 functionRoadClass
    std_msgs/UInt8 wayForm
    std_msgs/UInt8 effectiveSpeedLimit
    std_msgs/UInt8 nbLanesDrivingDirection
    std_msgs/UInt8 nbLanesOppositeDirection
    
    
    
    ================================================================================
    MSG: project_s_msgs/ehStub
    Header header
    std_msgs/UInt8 id
    
    #std_msgs/UInt8 indexPath
    std_msgs/Float32 offset
    std_msgs/UInt8 indexSubPath
    std_msgs/Float32 turnAngle
    std_msgs/UInt8 functionRoadClass
    std_msgs/UInt8 wayForm
    std_msgs/UInt8 nbLanesDrivingDirection
    std_msgs/UInt8 nbLanesOppositeDirection
    
    
    
    ================================================================================
    MSG: project_s_msgs/ehSpotCurvature
    Header header
    std_msgs/UInt8 id
    
    #std_msgs/UInt8 indexPath
    std_msgs/Float32 offset
    std_msgs/Float32 Value_0
    std_msgs/Float32 Distance_1
    std_msgs/Float32 Value_1
    
    
    
    ================================================================================
    MSG: std_msgs/UInt16
    uint16 data
    
    ================================================================================
    MSG: project_s_msgs/ehSpotCoordGeo
    Header header
    std_msgs/UInt8 id
    
    std_msgs/Float32 offset
    float64 latitude
    float64 longitude
    
    
    
    ================================================================================
    MSG: project_s_msgs/ehLineCoordGeo
    Header header
    std_msgs/UInt8 id
    
    uint32 SPOT_REPORT_SIZE = 3000
    project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo
    std_msgs/UInt32 NbrSpotCoordGeo
    
    
    ================================================================================
    MSG: std_msgs/UInt32
    uint32 data
    ================================================================================
    MSG: project_s_msgs/ehME
    Header header
    std_msgs/UInt8 id
    
    uint32 SPOT_REPORT_SIZE = 2000
    project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo
    std_msgs/UInt32 NbrSpotCoordGeo
    
    uint32 SEGMENT_ME_REPORT_SIZE = 100
    project_s_msgs/ehSegmentME[100] ehSegmentME
    std_msgs/UInt32 QtySegment
    
    ================================================================================
    MSG: project_s_msgs/ehSegmentME
    Header header
    std_msgs/UInt8 id
    
    std_msgs/UInt32 NbrSpot
    std_msgs/Float32 offset_debut
    std_msgs/Float32 offset_fin
    
    ================================================================================
    MSG: project_s_msgs/ehNbrLineCoordGeo
    std_msgs/UInt8 Nbr
    std_msgs/Float32 offset
    
    
    
    
    ================================================================================
    MSG: project_s_msgs/ehSpotTrafficSign
    Header header
    std_msgs/UInt8 id
    
    std_msgs/Float32 offset
    uint8 Sign_Type
    uint8 Value
    uint8 Lane
    uint8 Sign_Location
    float64 latitude
    float64 longitude
    
    
    
    
    ================================================================================
    MSG: project_s_msgs/ehPosition
    Header header
    std_msgs/UInt8 id
    
    #std_msgs/UInt8 indexPath
    std_msgs/Float32 offset
    float64 latitude
    float64 longitude
    std_msgs/Float32 cap
    std_msgs/UInt16 agePosition
    std_msgs/Float32 speed
    std_msgs/Float32 relativeHeading
    std_msgs/UInt8 currentLane
    
    
    
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
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FineMapMatching(null);
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

    if (msg.dCap !== undefined) {
      resolved.dCap = std_msgs.msg.Float32.Resolve(msg.dCap)
    }
    else {
      resolved.dCap = new std_msgs.msg.Float32()
    }

    if (msg.d_x_lambert !== undefined) {
      resolved.d_x_lambert = std_msgs.msg.Float32.Resolve(msg.d_x_lambert)
    }
    else {
      resolved.d_x_lambert = new std_msgs.msg.Float32()
    }

    if (msg.d_y_lambert !== undefined) {
      resolved.d_y_lambert = std_msgs.msg.Float32.Resolve(msg.d_y_lambert)
    }
    else {
      resolved.d_y_lambert = new std_msgs.msg.Float32()
    }

    if (msg.d_latitude !== undefined) {
      resolved.d_latitude = msg.d_latitude;
    }
    else {
      resolved.d_latitude = 0.0
    }

    if (msg.d_longitude !== undefined) {
      resolved.d_longitude = msg.d_longitude;
    }
    else {
      resolved.d_longitude = 0.0
    }

    if (msg.electronicHorizonArray !== undefined) {
      resolved.electronicHorizonArray = ElectronicHorizonArray.Resolve(msg.electronicHorizonArray)
    }
    else {
      resolved.electronicHorizonArray = new ElectronicHorizonArray()
    }

    return resolved;
    }
};

module.exports = FineMapMatching;
