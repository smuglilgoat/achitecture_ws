// Auto-generated. Do not edit!

// (in-package project_s_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let Segment = require('./Segment.js');
let point_GPS = require('./point_GPS.js');
let speed_limit = require('./speed_limit.js');
let curvature = require('./curvature.js');
let traffic_sign = require('./traffic_sign.js');
let segmentME = require('./segmentME.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class RoutePlanning {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.roadSegment = null;
      this.nbrLane = null;
      this.intersection = null;
      this.list_Links_ID = null;
      this.list_Links_HEREtile_ID = null;
      this.list_Nodes_ID = null;
      this.list_Nodes_HEREtile_ID = null;
      this.list_Links_vs_Route_direction = null;
      this.LIST_LINKS_SIZE = null;
      this.NBRE_POINT_CIRCUIT_GPS = null;
      this.NBRE_POINT_TABLEAU_GPS = null;
      this.Tableau_circuit_GPS = null;
      this.Tableau_circuit_GPS_gauche = null;
      this.Tableau_circuit_GPS_droite = null;
      this.Tableau_circuit_GPS_MEgauche = null;
      this.Tableau_circuit_GPS_MEdroite = null;
      this.Tableau_circuit_speedlimit = null;
      this.Tableau_circuit_curvature = null;
      this.Tableau_circuit_trafficsign = null;
      this.Tableau_circuit_ehSegmentAO = null;
      this.Tableau_circuit_ehSegmentEO = null;
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
      if (initObj.hasOwnProperty('roadSegment')) {
        this.roadSegment = initObj.roadSegment
      }
      else {
        this.roadSegment = [];
      }
      if (initObj.hasOwnProperty('nbrLane')) {
        this.nbrLane = initObj.nbrLane
      }
      else {
        this.nbrLane = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('intersection')) {
        this.intersection = initObj.intersection
      }
      else {
        this.intersection = new std_msgs.msg.UInt8();
      }
      if (initObj.hasOwnProperty('list_Links_ID')) {
        this.list_Links_ID = initObj.list_Links_ID
      }
      else {
        this.list_Links_ID = [];
      }
      if (initObj.hasOwnProperty('list_Links_HEREtile_ID')) {
        this.list_Links_HEREtile_ID = initObj.list_Links_HEREtile_ID
      }
      else {
        this.list_Links_HEREtile_ID = [];
      }
      if (initObj.hasOwnProperty('list_Nodes_ID')) {
        this.list_Nodes_ID = initObj.list_Nodes_ID
      }
      else {
        this.list_Nodes_ID = [];
      }
      if (initObj.hasOwnProperty('list_Nodes_HEREtile_ID')) {
        this.list_Nodes_HEREtile_ID = initObj.list_Nodes_HEREtile_ID
      }
      else {
        this.list_Nodes_HEREtile_ID = [];
      }
      if (initObj.hasOwnProperty('list_Links_vs_Route_direction')) {
        this.list_Links_vs_Route_direction = initObj.list_Links_vs_Route_direction
      }
      else {
        this.list_Links_vs_Route_direction = [];
      }
      if (initObj.hasOwnProperty('LIST_LINKS_SIZE')) {
        this.LIST_LINKS_SIZE = initObj.LIST_LINKS_SIZE
      }
      else {
        this.LIST_LINKS_SIZE = 0;
      }
      if (initObj.hasOwnProperty('NBRE_POINT_CIRCUIT_GPS')) {
        this.NBRE_POINT_CIRCUIT_GPS = initObj.NBRE_POINT_CIRCUIT_GPS
      }
      else {
        this.NBRE_POINT_CIRCUIT_GPS = 0;
      }
      if (initObj.hasOwnProperty('NBRE_POINT_TABLEAU_GPS')) {
        this.NBRE_POINT_TABLEAU_GPS = initObj.NBRE_POINT_TABLEAU_GPS
      }
      else {
        this.NBRE_POINT_TABLEAU_GPS = 0;
      }
      if (initObj.hasOwnProperty('Tableau_circuit_GPS')) {
        this.Tableau_circuit_GPS = initObj.Tableau_circuit_GPS
      }
      else {
        this.Tableau_circuit_GPS = [];
      }
      if (initObj.hasOwnProperty('Tableau_circuit_GPS_gauche')) {
        this.Tableau_circuit_GPS_gauche = initObj.Tableau_circuit_GPS_gauche
      }
      else {
        this.Tableau_circuit_GPS_gauche = [];
      }
      if (initObj.hasOwnProperty('Tableau_circuit_GPS_droite')) {
        this.Tableau_circuit_GPS_droite = initObj.Tableau_circuit_GPS_droite
      }
      else {
        this.Tableau_circuit_GPS_droite = [];
      }
      if (initObj.hasOwnProperty('Tableau_circuit_GPS_MEgauche')) {
        this.Tableau_circuit_GPS_MEgauche = initObj.Tableau_circuit_GPS_MEgauche
      }
      else {
        this.Tableau_circuit_GPS_MEgauche = [];
      }
      if (initObj.hasOwnProperty('Tableau_circuit_GPS_MEdroite')) {
        this.Tableau_circuit_GPS_MEdroite = initObj.Tableau_circuit_GPS_MEdroite
      }
      else {
        this.Tableau_circuit_GPS_MEdroite = [];
      }
      if (initObj.hasOwnProperty('Tableau_circuit_speedlimit')) {
        this.Tableau_circuit_speedlimit = initObj.Tableau_circuit_speedlimit
      }
      else {
        this.Tableau_circuit_speedlimit = [];
      }
      if (initObj.hasOwnProperty('Tableau_circuit_curvature')) {
        this.Tableau_circuit_curvature = initObj.Tableau_circuit_curvature
      }
      else {
        this.Tableau_circuit_curvature = [];
      }
      if (initObj.hasOwnProperty('Tableau_circuit_trafficsign')) {
        this.Tableau_circuit_trafficsign = initObj.Tableau_circuit_trafficsign
      }
      else {
        this.Tableau_circuit_trafficsign = [];
      }
      if (initObj.hasOwnProperty('Tableau_circuit_ehSegmentAO')) {
        this.Tableau_circuit_ehSegmentAO = initObj.Tableau_circuit_ehSegmentAO
      }
      else {
        this.Tableau_circuit_ehSegmentAO = [];
      }
      if (initObj.hasOwnProperty('Tableau_circuit_ehSegmentEO')) {
        this.Tableau_circuit_ehSegmentEO = initObj.Tableau_circuit_ehSegmentEO
      }
      else {
        this.Tableau_circuit_ehSegmentEO = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RoutePlanning
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.id, buffer, bufferOffset);
    // Serialize message field [roadSegment]
    // Serialize the length for message field [roadSegment]
    bufferOffset = _serializer.uint32(obj.roadSegment.length, buffer, bufferOffset);
    obj.roadSegment.forEach((val) => {
      bufferOffset = Segment.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [nbrLane]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.nbrLane, buffer, bufferOffset);
    // Serialize message field [intersection]
    bufferOffset = std_msgs.msg.UInt8.serialize(obj.intersection, buffer, bufferOffset);
    // Serialize message field [list_Links_ID]
    bufferOffset = _arraySerializer.uint32(obj.list_Links_ID, buffer, bufferOffset, null);
    // Serialize message field [list_Links_HEREtile_ID]
    bufferOffset = _arraySerializer.uint32(obj.list_Links_HEREtile_ID, buffer, bufferOffset, null);
    // Serialize message field [list_Nodes_ID]
    bufferOffset = _arraySerializer.uint32(obj.list_Nodes_ID, buffer, bufferOffset, null);
    // Serialize message field [list_Nodes_HEREtile_ID]
    bufferOffset = _arraySerializer.uint32(obj.list_Nodes_HEREtile_ID, buffer, bufferOffset, null);
    // Serialize message field [list_Links_vs_Route_direction]
    bufferOffset = _arraySerializer.bool(obj.list_Links_vs_Route_direction, buffer, bufferOffset, null);
    // Serialize message field [LIST_LINKS_SIZE]
    bufferOffset = _serializer.uint32(obj.LIST_LINKS_SIZE, buffer, bufferOffset);
    // Serialize message field [NBRE_POINT_CIRCUIT_GPS]
    bufferOffset = _serializer.uint32(obj.NBRE_POINT_CIRCUIT_GPS, buffer, bufferOffset);
    // Serialize message field [NBRE_POINT_TABLEAU_GPS]
    bufferOffset = _serializer.uint32(obj.NBRE_POINT_TABLEAU_GPS, buffer, bufferOffset);
    // Serialize message field [Tableau_circuit_GPS]
    // Serialize the length for message field [Tableau_circuit_GPS]
    bufferOffset = _serializer.uint32(obj.Tableau_circuit_GPS.length, buffer, bufferOffset);
    obj.Tableau_circuit_GPS.forEach((val) => {
      bufferOffset = point_GPS.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [Tableau_circuit_GPS_gauche]
    // Serialize the length for message field [Tableau_circuit_GPS_gauche]
    bufferOffset = _serializer.uint32(obj.Tableau_circuit_GPS_gauche.length, buffer, bufferOffset);
    obj.Tableau_circuit_GPS_gauche.forEach((val) => {
      bufferOffset = point_GPS.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [Tableau_circuit_GPS_droite]
    // Serialize the length for message field [Tableau_circuit_GPS_droite]
    bufferOffset = _serializer.uint32(obj.Tableau_circuit_GPS_droite.length, buffer, bufferOffset);
    obj.Tableau_circuit_GPS_droite.forEach((val) => {
      bufferOffset = point_GPS.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [Tableau_circuit_GPS_MEgauche]
    // Serialize the length for message field [Tableau_circuit_GPS_MEgauche]
    bufferOffset = _serializer.uint32(obj.Tableau_circuit_GPS_MEgauche.length, buffer, bufferOffset);
    obj.Tableau_circuit_GPS_MEgauche.forEach((val) => {
      bufferOffset = point_GPS.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [Tableau_circuit_GPS_MEdroite]
    // Serialize the length for message field [Tableau_circuit_GPS_MEdroite]
    bufferOffset = _serializer.uint32(obj.Tableau_circuit_GPS_MEdroite.length, buffer, bufferOffset);
    obj.Tableau_circuit_GPS_MEdroite.forEach((val) => {
      bufferOffset = point_GPS.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [Tableau_circuit_speedlimit]
    // Serialize the length for message field [Tableau_circuit_speedlimit]
    bufferOffset = _serializer.uint32(obj.Tableau_circuit_speedlimit.length, buffer, bufferOffset);
    obj.Tableau_circuit_speedlimit.forEach((val) => {
      bufferOffset = speed_limit.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [Tableau_circuit_curvature]
    // Serialize the length for message field [Tableau_circuit_curvature]
    bufferOffset = _serializer.uint32(obj.Tableau_circuit_curvature.length, buffer, bufferOffset);
    obj.Tableau_circuit_curvature.forEach((val) => {
      bufferOffset = curvature.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [Tableau_circuit_trafficsign]
    // Serialize the length for message field [Tableau_circuit_trafficsign]
    bufferOffset = _serializer.uint32(obj.Tableau_circuit_trafficsign.length, buffer, bufferOffset);
    obj.Tableau_circuit_trafficsign.forEach((val) => {
      bufferOffset = traffic_sign.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [Tableau_circuit_ehSegmentAO]
    // Serialize the length for message field [Tableau_circuit_ehSegmentAO]
    bufferOffset = _serializer.uint32(obj.Tableau_circuit_ehSegmentAO.length, buffer, bufferOffset);
    obj.Tableau_circuit_ehSegmentAO.forEach((val) => {
      bufferOffset = segmentME.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [Tableau_circuit_ehSegmentEO]
    // Serialize the length for message field [Tableau_circuit_ehSegmentEO]
    bufferOffset = _serializer.uint32(obj.Tableau_circuit_ehSegmentEO.length, buffer, bufferOffset);
    obj.Tableau_circuit_ehSegmentEO.forEach((val) => {
      bufferOffset = segmentME.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RoutePlanning
    let len;
    let data = new RoutePlanning(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [roadSegment]
    // Deserialize array length for message field [roadSegment]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.roadSegment = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.roadSegment[i] = Segment.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [nbrLane]
    data.nbrLane = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [intersection]
    data.intersection = std_msgs.msg.UInt8.deserialize(buffer, bufferOffset);
    // Deserialize message field [list_Links_ID]
    data.list_Links_ID = _arrayDeserializer.uint32(buffer, bufferOffset, null)
    // Deserialize message field [list_Links_HEREtile_ID]
    data.list_Links_HEREtile_ID = _arrayDeserializer.uint32(buffer, bufferOffset, null)
    // Deserialize message field [list_Nodes_ID]
    data.list_Nodes_ID = _arrayDeserializer.uint32(buffer, bufferOffset, null)
    // Deserialize message field [list_Nodes_HEREtile_ID]
    data.list_Nodes_HEREtile_ID = _arrayDeserializer.uint32(buffer, bufferOffset, null)
    // Deserialize message field [list_Links_vs_Route_direction]
    data.list_Links_vs_Route_direction = _arrayDeserializer.bool(buffer, bufferOffset, null)
    // Deserialize message field [LIST_LINKS_SIZE]
    data.LIST_LINKS_SIZE = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [NBRE_POINT_CIRCUIT_GPS]
    data.NBRE_POINT_CIRCUIT_GPS = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [NBRE_POINT_TABLEAU_GPS]
    data.NBRE_POINT_TABLEAU_GPS = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [Tableau_circuit_GPS]
    // Deserialize array length for message field [Tableau_circuit_GPS]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.Tableau_circuit_GPS = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.Tableau_circuit_GPS[i] = point_GPS.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [Tableau_circuit_GPS_gauche]
    // Deserialize array length for message field [Tableau_circuit_GPS_gauche]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.Tableau_circuit_GPS_gauche = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.Tableau_circuit_GPS_gauche[i] = point_GPS.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [Tableau_circuit_GPS_droite]
    // Deserialize array length for message field [Tableau_circuit_GPS_droite]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.Tableau_circuit_GPS_droite = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.Tableau_circuit_GPS_droite[i] = point_GPS.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [Tableau_circuit_GPS_MEgauche]
    // Deserialize array length for message field [Tableau_circuit_GPS_MEgauche]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.Tableau_circuit_GPS_MEgauche = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.Tableau_circuit_GPS_MEgauche[i] = point_GPS.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [Tableau_circuit_GPS_MEdroite]
    // Deserialize array length for message field [Tableau_circuit_GPS_MEdroite]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.Tableau_circuit_GPS_MEdroite = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.Tableau_circuit_GPS_MEdroite[i] = point_GPS.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [Tableau_circuit_speedlimit]
    // Deserialize array length for message field [Tableau_circuit_speedlimit]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.Tableau_circuit_speedlimit = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.Tableau_circuit_speedlimit[i] = speed_limit.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [Tableau_circuit_curvature]
    // Deserialize array length for message field [Tableau_circuit_curvature]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.Tableau_circuit_curvature = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.Tableau_circuit_curvature[i] = curvature.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [Tableau_circuit_trafficsign]
    // Deserialize array length for message field [Tableau_circuit_trafficsign]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.Tableau_circuit_trafficsign = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.Tableau_circuit_trafficsign[i] = traffic_sign.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [Tableau_circuit_ehSegmentAO]
    // Deserialize array length for message field [Tableau_circuit_ehSegmentAO]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.Tableau_circuit_ehSegmentAO = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.Tableau_circuit_ehSegmentAO[i] = segmentME.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [Tableau_circuit_ehSegmentEO]
    // Deserialize array length for message field [Tableau_circuit_ehSegmentEO]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.Tableau_circuit_ehSegmentEO = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.Tableau_circuit_ehSegmentEO[i] = segmentME.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 100 * object.roadSegment.length;
    length += 4 * object.list_Links_ID.length;
    length += 4 * object.list_Links_HEREtile_ID.length;
    length += 4 * object.list_Nodes_ID.length;
    length += 4 * object.list_Nodes_HEREtile_ID.length;
    length += object.list_Links_vs_Route_direction.length;
    length += 20 * object.Tableau_circuit_GPS.length;
    length += 20 * object.Tableau_circuit_GPS_gauche.length;
    length += 20 * object.Tableau_circuit_GPS_droite.length;
    length += 20 * object.Tableau_circuit_GPS_MEgauche.length;
    length += 20 * object.Tableau_circuit_GPS_MEdroite.length;
    length += 5 * object.Tableau_circuit_speedlimit.length;
    length += 8 * object.Tableau_circuit_curvature.length;
    length += 24 * object.Tableau_circuit_trafficsign.length;
    length += 12 * object.Tableau_circuit_ehSegmentAO.length;
    length += 12 * object.Tableau_circuit_ehSegmentEO.length;
    return length + 79;
  }

  static datatype() {
    // Returns string type for a message object
    return 'project_s_msgs/RoutePlanning';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '686ce86a53e3fc605337589df78e8395';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    std_msgs/UInt8 id
    
    project_s_msgs/Segment[] roadSegment		#segments array   
    std_msgs/UInt8 nbrLane
    std_msgs/UInt8 intersection
    
    uint32[] list_Links_ID
    uint32[] list_Links_HEREtile_ID
    uint32[] list_Nodes_ID
    uint32[] list_Nodes_HEREtile_ID
    bool[] list_Links_vs_Route_direction
    uint32 LIST_LINKS_SIZE
    
    uint32 NBRE_POINT_CIRCUIT_GPS
    uint32 NBRE_POINT_TABLEAU_GPS
    
    project_s_msgs/point_GPS[]   Tableau_circuit_GPS
    project_s_msgs/point_GPS[]   Tableau_circuit_GPS_gauche
    project_s_msgs/point_GPS[]   Tableau_circuit_GPS_droite
    
    project_s_msgs/point_GPS[]   Tableau_circuit_GPS_MEgauche
    project_s_msgs/point_GPS[]   Tableau_circuit_GPS_MEdroite
    
    project_s_msgs/speed_limit[] Tableau_circuit_speedlimit
    project_s_msgs/curvature[]   Tableau_circuit_curvature
    project_s_msgs/traffic_sign[]   Tableau_circuit_trafficsign
    
    
    project_s_msgs/segmentME[] Tableau_circuit_ehSegmentAO
    project_s_msgs/segmentME[] Tableau_circuit_ehSegmentEO
    
    
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
    MSG: project_s_msgs/point_GPS
    float64 latitude
    float64 longitude
    float32 offset
    
    
    ================================================================================
    MSG: project_s_msgs/speed_limit
    float32 offset
    uint8 effectiveSpeedLimit
    
    
    ================================================================================
    MSG: project_s_msgs/curvature
    float32 offset
    float32 value
    
    ================================================================================
    MSG: project_s_msgs/traffic_sign
    float32 offset
    uint8 Sign_Type
    uint8 Value
    uint8 Lane
    uint8 Sign_Location
    float64 latitude
    float64 longitude
    
    
    
    
    ================================================================================
    MSG: project_s_msgs/segmentME
    uint32 NbrSpot
    float32 offset_debut
    float32 offset_fin
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RoutePlanning(null);
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

    if (msg.roadSegment !== undefined) {
      resolved.roadSegment = new Array(msg.roadSegment.length);
      for (let i = 0; i < resolved.roadSegment.length; ++i) {
        resolved.roadSegment[i] = Segment.Resolve(msg.roadSegment[i]);
      }
    }
    else {
      resolved.roadSegment = []
    }

    if (msg.nbrLane !== undefined) {
      resolved.nbrLane = std_msgs.msg.UInt8.Resolve(msg.nbrLane)
    }
    else {
      resolved.nbrLane = new std_msgs.msg.UInt8()
    }

    if (msg.intersection !== undefined) {
      resolved.intersection = std_msgs.msg.UInt8.Resolve(msg.intersection)
    }
    else {
      resolved.intersection = new std_msgs.msg.UInt8()
    }

    if (msg.list_Links_ID !== undefined) {
      resolved.list_Links_ID = msg.list_Links_ID;
    }
    else {
      resolved.list_Links_ID = []
    }

    if (msg.list_Links_HEREtile_ID !== undefined) {
      resolved.list_Links_HEREtile_ID = msg.list_Links_HEREtile_ID;
    }
    else {
      resolved.list_Links_HEREtile_ID = []
    }

    if (msg.list_Nodes_ID !== undefined) {
      resolved.list_Nodes_ID = msg.list_Nodes_ID;
    }
    else {
      resolved.list_Nodes_ID = []
    }

    if (msg.list_Nodes_HEREtile_ID !== undefined) {
      resolved.list_Nodes_HEREtile_ID = msg.list_Nodes_HEREtile_ID;
    }
    else {
      resolved.list_Nodes_HEREtile_ID = []
    }

    if (msg.list_Links_vs_Route_direction !== undefined) {
      resolved.list_Links_vs_Route_direction = msg.list_Links_vs_Route_direction;
    }
    else {
      resolved.list_Links_vs_Route_direction = []
    }

    if (msg.LIST_LINKS_SIZE !== undefined) {
      resolved.LIST_LINKS_SIZE = msg.LIST_LINKS_SIZE;
    }
    else {
      resolved.LIST_LINKS_SIZE = 0
    }

    if (msg.NBRE_POINT_CIRCUIT_GPS !== undefined) {
      resolved.NBRE_POINT_CIRCUIT_GPS = msg.NBRE_POINT_CIRCUIT_GPS;
    }
    else {
      resolved.NBRE_POINT_CIRCUIT_GPS = 0
    }

    if (msg.NBRE_POINT_TABLEAU_GPS !== undefined) {
      resolved.NBRE_POINT_TABLEAU_GPS = msg.NBRE_POINT_TABLEAU_GPS;
    }
    else {
      resolved.NBRE_POINT_TABLEAU_GPS = 0
    }

    if (msg.Tableau_circuit_GPS !== undefined) {
      resolved.Tableau_circuit_GPS = new Array(msg.Tableau_circuit_GPS.length);
      for (let i = 0; i < resolved.Tableau_circuit_GPS.length; ++i) {
        resolved.Tableau_circuit_GPS[i] = point_GPS.Resolve(msg.Tableau_circuit_GPS[i]);
      }
    }
    else {
      resolved.Tableau_circuit_GPS = []
    }

    if (msg.Tableau_circuit_GPS_gauche !== undefined) {
      resolved.Tableau_circuit_GPS_gauche = new Array(msg.Tableau_circuit_GPS_gauche.length);
      for (let i = 0; i < resolved.Tableau_circuit_GPS_gauche.length; ++i) {
        resolved.Tableau_circuit_GPS_gauche[i] = point_GPS.Resolve(msg.Tableau_circuit_GPS_gauche[i]);
      }
    }
    else {
      resolved.Tableau_circuit_GPS_gauche = []
    }

    if (msg.Tableau_circuit_GPS_droite !== undefined) {
      resolved.Tableau_circuit_GPS_droite = new Array(msg.Tableau_circuit_GPS_droite.length);
      for (let i = 0; i < resolved.Tableau_circuit_GPS_droite.length; ++i) {
        resolved.Tableau_circuit_GPS_droite[i] = point_GPS.Resolve(msg.Tableau_circuit_GPS_droite[i]);
      }
    }
    else {
      resolved.Tableau_circuit_GPS_droite = []
    }

    if (msg.Tableau_circuit_GPS_MEgauche !== undefined) {
      resolved.Tableau_circuit_GPS_MEgauche = new Array(msg.Tableau_circuit_GPS_MEgauche.length);
      for (let i = 0; i < resolved.Tableau_circuit_GPS_MEgauche.length; ++i) {
        resolved.Tableau_circuit_GPS_MEgauche[i] = point_GPS.Resolve(msg.Tableau_circuit_GPS_MEgauche[i]);
      }
    }
    else {
      resolved.Tableau_circuit_GPS_MEgauche = []
    }

    if (msg.Tableau_circuit_GPS_MEdroite !== undefined) {
      resolved.Tableau_circuit_GPS_MEdroite = new Array(msg.Tableau_circuit_GPS_MEdroite.length);
      for (let i = 0; i < resolved.Tableau_circuit_GPS_MEdroite.length; ++i) {
        resolved.Tableau_circuit_GPS_MEdroite[i] = point_GPS.Resolve(msg.Tableau_circuit_GPS_MEdroite[i]);
      }
    }
    else {
      resolved.Tableau_circuit_GPS_MEdroite = []
    }

    if (msg.Tableau_circuit_speedlimit !== undefined) {
      resolved.Tableau_circuit_speedlimit = new Array(msg.Tableau_circuit_speedlimit.length);
      for (let i = 0; i < resolved.Tableau_circuit_speedlimit.length; ++i) {
        resolved.Tableau_circuit_speedlimit[i] = speed_limit.Resolve(msg.Tableau_circuit_speedlimit[i]);
      }
    }
    else {
      resolved.Tableau_circuit_speedlimit = []
    }

    if (msg.Tableau_circuit_curvature !== undefined) {
      resolved.Tableau_circuit_curvature = new Array(msg.Tableau_circuit_curvature.length);
      for (let i = 0; i < resolved.Tableau_circuit_curvature.length; ++i) {
        resolved.Tableau_circuit_curvature[i] = curvature.Resolve(msg.Tableau_circuit_curvature[i]);
      }
    }
    else {
      resolved.Tableau_circuit_curvature = []
    }

    if (msg.Tableau_circuit_trafficsign !== undefined) {
      resolved.Tableau_circuit_trafficsign = new Array(msg.Tableau_circuit_trafficsign.length);
      for (let i = 0; i < resolved.Tableau_circuit_trafficsign.length; ++i) {
        resolved.Tableau_circuit_trafficsign[i] = traffic_sign.Resolve(msg.Tableau_circuit_trafficsign[i]);
      }
    }
    else {
      resolved.Tableau_circuit_trafficsign = []
    }

    if (msg.Tableau_circuit_ehSegmentAO !== undefined) {
      resolved.Tableau_circuit_ehSegmentAO = new Array(msg.Tableau_circuit_ehSegmentAO.length);
      for (let i = 0; i < resolved.Tableau_circuit_ehSegmentAO.length; ++i) {
        resolved.Tableau_circuit_ehSegmentAO[i] = segmentME.Resolve(msg.Tableau_circuit_ehSegmentAO[i]);
      }
    }
    else {
      resolved.Tableau_circuit_ehSegmentAO = []
    }

    if (msg.Tableau_circuit_ehSegmentEO !== undefined) {
      resolved.Tableau_circuit_ehSegmentEO = new Array(msg.Tableau_circuit_ehSegmentEO.length);
      for (let i = 0; i < resolved.Tableau_circuit_ehSegmentEO.length; ++i) {
        resolved.Tableau_circuit_ehSegmentEO[i] = segmentME.Resolve(msg.Tableau_circuit_ehSegmentEO[i]);
      }
    }
    else {
      resolved.Tableau_circuit_ehSegmentEO = []
    }

    return resolved;
    }
};

module.exports = RoutePlanning;
