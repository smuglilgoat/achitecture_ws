; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude EgoDistanceCurviligne.msg.html

(cl:defclass <EgoDistanceCurviligne> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (id
    :reader id
    :initarg :id
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (distance
    :reader distance
    :initarg :distance
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (odom
    :reader odom
    :initarg :odom
    :type nav_msgs-msg:Odometry
    :initform (cl:make-instance 'nav_msgs-msg:Odometry))
   (latitude
    :reader latitude
    :initarg :latitude
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (longitude
    :reader longitude
    :initarg :longitude
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (cap
    :reader cap
    :initarg :cap
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32)))
)

(cl:defclass EgoDistanceCurviligne (<EgoDistanceCurviligne>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EgoDistanceCurviligne>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EgoDistanceCurviligne)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<EgoDistanceCurviligne> is deprecated: use project_s_msgs-msg:EgoDistanceCurviligne instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <EgoDistanceCurviligne>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <EgoDistanceCurviligne>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <EgoDistanceCurviligne>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:distance-val is deprecated.  Use project_s_msgs-msg:distance instead.")
  (distance m))

(cl:ensure-generic-function 'odom-val :lambda-list '(m))
(cl:defmethod odom-val ((m <EgoDistanceCurviligne>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:odom-val is deprecated.  Use project_s_msgs-msg:odom instead.")
  (odom m))

(cl:ensure-generic-function 'latitude-val :lambda-list '(m))
(cl:defmethod latitude-val ((m <EgoDistanceCurviligne>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:latitude-val is deprecated.  Use project_s_msgs-msg:latitude instead.")
  (latitude m))

(cl:ensure-generic-function 'longitude-val :lambda-list '(m))
(cl:defmethod longitude-val ((m <EgoDistanceCurviligne>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:longitude-val is deprecated.  Use project_s_msgs-msg:longitude instead.")
  (longitude m))

(cl:ensure-generic-function 'cap-val :lambda-list '(m))
(cl:defmethod cap-val ((m <EgoDistanceCurviligne>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:cap-val is deprecated.  Use project_s_msgs-msg:cap instead.")
  (cap m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EgoDistanceCurviligne>) ostream)
  "Serializes a message object of type '<EgoDistanceCurviligne>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'distance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'odom) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'latitude) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'longitude) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'cap) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EgoDistanceCurviligne>) istream)
  "Deserializes a message object of type '<EgoDistanceCurviligne>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'distance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'odom) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'latitude) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'longitude) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'cap) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EgoDistanceCurviligne>)))
  "Returns string type for a message object of type '<EgoDistanceCurviligne>"
  "project_s_msgs/EgoDistanceCurviligne")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EgoDistanceCurviligne)))
  "Returns string type for a message object of type 'EgoDistanceCurviligne"
  "project_s_msgs/EgoDistanceCurviligne")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EgoDistanceCurviligne>)))
  "Returns md5sum for a message object of type '<EgoDistanceCurviligne>"
  "2a1fd94cf2ac8a1014987ae82524a7bf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EgoDistanceCurviligne)))
  "Returns md5sum for a message object of type 'EgoDistanceCurviligne"
  "2a1fd94cf2ac8a1014987ae82524a7bf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EgoDistanceCurviligne>)))
  "Returns full string definition for message of type '<EgoDistanceCurviligne>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 distance~%nav_msgs/Odometry odom~%std_msgs/Float32 latitude~%std_msgs/Float32 longitude~%std_msgs/Float32 cap~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EgoDistanceCurviligne)))
  "Returns full string definition for message of type 'EgoDistanceCurviligne"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 distance~%nav_msgs/Odometry odom~%std_msgs/Float32 latitude~%std_msgs/Float32 longitude~%std_msgs/Float32 cap~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EgoDistanceCurviligne>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'distance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'odom))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'latitude))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'longitude))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'cap))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EgoDistanceCurviligne>))
  "Converts a ROS message object to a list"
  (cl:list 'EgoDistanceCurviligne
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':distance (distance msg))
    (cl:cons ':odom (odom msg))
    (cl:cons ':latitude (latitude msg))
    (cl:cons ':longitude (longitude msg))
    (cl:cons ':cap (cap msg))
))
