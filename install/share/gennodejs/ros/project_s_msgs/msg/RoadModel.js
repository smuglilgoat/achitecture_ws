// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let Line = require('./Line.js');
let ElectronicHorizon = require('./ElectronicHorizon.js');
let Speed = require('./Speed.js');
let nav_msgs = _finder('nav_msgs');
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class RoadModel {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.nbrLine = null;
      this.roadLine = null;
      this.electronicHorizon = null;
      this.speedEnveloppe = null;
      this.amer = null;
      this.nbrAmer = null;
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
      if (initObj.hasOwnProperty('nbrLine')) {
        this.nbrLine = initObj.nbrLine
      }
      else {
        this.nbrLine = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('roadLine')) {
        this.roadLine = initObj.roadLine
      }
      else {
        this.roadLine = new Array(10).fill(new Line());
      }
      if (initObj.hasOwnProperty('electronicHorizon')) {
        this.electronicHorizon = initObj.electronicHorizon
      }
      else {
        this.electronicHorizon = new ElectronicHorizon();
      }
      if (initObj.hasOwnProperty('speedEnveloppe')) {
        this.speedEnveloppe = initObj.speedEnveloppe
      }
      else {
        this.speedEnveloppe = new Array(310).fill(new Speed());
      }
      if (initObj.hasOwnProperty('amer')) {
        this.amer = initObj.amer
      }
      else {
        this.amer = new Array(50).fill(new geometry_msgs.msg.Point());
      }
      if (initObj.hasOwnProperty('nbrAmer')) {
        this.nbrAmer = initObj.nbrAmer
      }
      else {
        this.nbrAmer = new std_msgs.msg.UInt8();
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
    // Serializes a message object of type RoadModel
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [nbrLine]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.nbrLine, buffer, bufferOffset);
    // Check that the constant length array field [roadLine] has the right length
    if (obj.roadLine.length !== 10) {
      throw new Error('Unable to serialize array field roadLine - length must be 10')
    }
    // Serialize message field [roadLine]
    obj.roadLine.forEach((val) => {
      bufferOffset = Line.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [electronicHorizon]
    bufferOffset = ElectronicHorizon.serialize(obj.electronicHorizon, buffer, bufferOffset);
    // Check that the constant length array field [speedEnveloppe] has the right length
    if (obj.speedEnveloppe.length !== 310) {
      throw new Error('Unable to serialize array field speedEnveloppe - length must be 310')
    }
    // Serialize message field [speedEnveloppe]
    obj.speedEnveloppe.forEach((val) => {
      bufferOffset = Speed.serialize(val, buffer, bufferOffset);
    });
    // Check that the constant length array field [amer] has the right length
    if (obj.amer.length !== 50) {
      throw new Error('Unable to serialize array field amer - length must be 50')
    }
    // Serialize message field [amer]
    obj.amer.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [nbrAmer]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.nbrAmer, buffer, bufferOffset);
    // Serialize message field [odom]
    bufferOffset = nav_msgs.msg.Odometry.serialize(obj.odom, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RoadModel
    let len;
    let data = new RoadModel(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [nbrLine]
    data.nbrLine = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [roadLine]
    len = 10;
    data.roadLine = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.roadLine[i] = Line.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [electronicHorizon]
    data.electronicHorizon = ElectronicHorizon.deserialize(buffer, bufferOffset);
    // Deserialize message field [speedEnveloppe]
    len = 310;
    data.speedEnveloppe = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.speedEnveloppe[i] = Speed.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [amer]
    len = 50;
    data.amer = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.amer[i] = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [nbrAmer]
    data.nbrAmer = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [odom]
    data.odom = nav_msgs.msg.Odometry.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.roadLine.forEach((val) => {
      length += Line.getMessageSize(val);
    });
    length += ElectronicHorizon.getMessageSize(object.electronicHorizon);
    object.speedEnveloppe.forEach((val) => {
      length += Speed.getMessageSize(val);
    });
    length += nav_msgs.msg.Odometry.getMessageSize(object.odom);
    return length + 1203;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/RoadModel';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8e9f6188ebbf41f73c6179086ef32107';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    std_msgs/UInt8 nbrLine
    project_s_msgs/Line[10] roadLine			#segments array
    
    project_s_msgs/ElectronicHorizon electronicHorizon
    
    uint32 SPEED_LIMIT_ARRAY_SIZE = 310
    project_s_msgs/Speed[310] speedEnveloppe
    
    uint8 AMER_ARRAY_SIZE = 50
    geometry_msgs/Point[50] amer
    std_msgs/UInt8 nbrAmer
    
    
    nav_msgs/Odometry odom
    
    
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
    MSG: project_s_msgs/Line
    Header header
    std_msgs/UInt8 id
    
    uint16 SEGMENT_REPORT_SIZE = 3000
    project_s_msgs/Segment[3000] segment
    std_msgs/UInt16 QtySegment
    std_msgs/Float32 lineClass	# class of the line
    std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)
    
    std_msgs/UInt8 existenceState
    std_msgs/Float32 scoreDetection
    std_msgs/Float32 nbrDetection
    std_msgs/Float32 nbrVisibility
    std_msgs/Float32 scorePersistence
    std_msgs/Float32 nbrUpdate
    std_msgs/Float32 nbrAge
    
    
    
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
    ================================================================================
    MSG: std_msgs/UInt16
    uint16 data
    
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
    MSG: project_s_msgs/Speed
    Header header
    std_msgs/UInt8 id
    
    std_msgs/Float32 offset
    std_msgs/Float32 speed
    
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RoadModel(null);
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

    if (msg.nbrLine !== undefined) {
      resolved.nbrLine = std_msgs.msg.UInt8.Resolve(msg.nbrLine)
    }
    else {
      resolved.nbrLine = new std_msgs.msg.UInt8()
    }

    if (msg.roadLine !== undefined) {
      resolved.roadLine = new Array(10)
      for (let i = 0; i < resolved.roadLine.length; ++i) {
        if (msg.roadLine.length > i) {
          resolved.roadLine[i] = Line.Resolve(msg.roadLine[i]);
        }
        else {
          resolved.roadLine[i] = new Line();
        }
      }
    }
    else {
      resolved.roadLine = new Array(10).fill(new Line())
    }

    if (msg.electronicHorizon !== undefined) {
      resolved.electronicHorizon = ElectronicHorizon.Resolve(msg.electronicHorizon)
    }
    else {
      resolved.electronicHorizon = new ElectronicHorizon()
    }

    if (msg.speedEnveloppe !== undefined) {
      resolved.speedEnveloppe = new Array(310)
      for (let i = 0; i < resolved.speedEnveloppe.length; ++i) {
        if (msg.speedEnveloppe.length > i) {
          resolved.speedEnveloppe[i] = Speed.Resolve(msg.speedEnveloppe[i]);
        }
        else {
          resolved.speedEnveloppe[i] = new Speed();
        }
      }
    }
    else {
      resolved.speedEnveloppe = new Array(310).fill(new Speed())
    }

    if (msg.amer !== undefined) {
      resolved.amer = new Array(50)
      for (let i = 0; i < resolved.amer.length; ++i) {
        if (msg.amer.length > i) {
          resolved.amer[i] = geometry_msgs.msg.Point.Resolve(msg.amer[i]);
        }
        else {
          resolved.amer[i] = new geometry_msgs.msg.Point();
        }
      }
    }
    else {
      resolved.amer = new Array(50).fill(new geometry_msgs.msg.Point())
    }

    if (msg.nbrAmer !== undefined) {
      resolved.nbrAmer = std_msgs.msg.UInt8.Resolve(msg.nbrAmer)
    }
    else {
      resolved.nbrAmer = new std_msgs.msg.UInt8()
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
RoadModel.Constants = {
  SPEED_LIMIT_ARRAY_SIZE: 310,
  AMER_ARRAY_SIZE: 50,
}

module.exports = RoadModel;
