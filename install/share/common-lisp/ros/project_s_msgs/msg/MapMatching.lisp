; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude MapMatching.msg.html

(cl:defclass <MapMatching> (roslisp-msg-protocol:ros-message)
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
   (link_ID
    :reader link_ID
    :initarg :link_ID
    :type std_msgs-msg:UInt32
    :initform (cl:make-instance 'std_msgs-msg:UInt32))
   (link_HEREtile_ID
    :reader link_HEREtile_ID
    :initarg :link_HEREtile_ID
    :type std_msgs-msg:UInt32
    :initform (cl:make-instance 'std_msgs-msg:UInt32))
   (Distance_Curviligne_Ego
    :reader Distance_Curviligne_Ego
    :initarg :Distance_Curviligne_Ego
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (latitude
    :reader latitude
    :initarg :latitude
    :type cl:float
    :initform 0.0)
   (longitude
    :reader longitude
    :initarg :longitude
    :type cl:float
    :initform 0.0)
   (cap
    :reader cap
    :initarg :cap
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32)))
)

(cl:defclass MapMatching (<MapMatching>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MapMatching>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MapMatching)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<MapMatching> is deprecated: use project_s_msgs-msg:MapMatching instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <MapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'link_ID-val :lambda-list '(m))
(cl:defmethod link_ID-val ((m <MapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:link_ID-val is deprecated.  Use project_s_msgs-msg:link_ID instead.")
  (link_ID m))

(cl:ensure-generic-function 'link_HEREtile_ID-val :lambda-list '(m))
(cl:defmethod link_HEREtile_ID-val ((m <MapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:link_HEREtile_ID-val is deprecated.  Use project_s_msgs-msg:link_HEREtile_ID instead.")
  (link_HEREtile_ID m))

(cl:ensure-generic-function 'Distance_Curviligne_Ego-val :lambda-list '(m))
(cl:defmethod Distance_Curviligne_Ego-val ((m <MapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Distance_Curviligne_Ego-val is deprecated.  Use project_s_msgs-msg:Distance_Curviligne_Ego instead.")
  (Distance_Curviligne_Ego m))

(cl:ensure-generic-function 'latitude-val :lambda-list '(m))
(cl:defmethod latitude-val ((m <MapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:latitude-val is deprecated.  Use project_s_msgs-msg:latitude instead.")
  (latitude m))

(cl:ensure-generic-function 'longitude-val :lambda-list '(m))
(cl:defmethod longitude-val ((m <MapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:longitude-val is deprecated.  Use project_s_msgs-msg:longitude instead.")
  (longitude m))

(cl:ensure-generic-function 'cap-val :lambda-list '(m))
(cl:defmethod cap-val ((m <MapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:cap-val is deprecated.  Use project_s_msgs-msg:cap instead.")
  (cap m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MapMatching>) ostream)
  "Serializes a message object of type '<MapMatching>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'link_ID) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'link_HEREtile_ID) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Distance_Curviligne_Ego) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'latitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'longitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'cap) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MapMatching>) istream)
  "Deserializes a message object of type '<MapMatching>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'link_ID) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'link_HEREtile_ID) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Distance_Curviligne_Ego) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'latitude) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'longitude) (roslisp-utils:decode-double-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'cap) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MapMatching>)))
  "Returns string type for a message object of type '<MapMatching>"
  "project_s_msgs/MapMatching")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MapMatching)))
  "Returns string type for a message object of type 'MapMatching"
  "project_s_msgs/MapMatching")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MapMatching>)))
  "Returns md5sum for a message object of type '<MapMatching>"
  "751b9780203e0387595b35e7afcb932c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MapMatching)))
  "Returns md5sum for a message object of type 'MapMatching"
  "751b9780203e0387595b35e7afcb932c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MapMatching>)))
  "Returns full string definition for message of type '<MapMatching>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 link_ID~%std_msgs/UInt32 link_HEREtile_ID~%std_msgs/Float32 Distance_Curviligne_Ego~%float64 latitude~%float64 longitude~%std_msgs/Float32 cap~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MapMatching)))
  "Returns full string definition for message of type 'MapMatching"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 link_ID~%std_msgs/UInt32 link_HEREtile_ID~%std_msgs/Float32 Distance_Curviligne_Ego~%float64 latitude~%float64 longitude~%std_msgs/Float32 cap~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MapMatching>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'link_ID))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'link_HEREtile_ID))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Distance_Curviligne_Ego))
     8
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'cap))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MapMatching>))
  "Converts a ROS message object to a list"
  (cl:list 'MapMatching
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':link_ID (link_ID msg))
    (cl:cons ':link_HEREtile_ID (link_HEREtile_ID msg))
    (cl:cons ':Distance_Curviligne_Ego (Distance_Curviligne_Ego msg))
    (cl:cons ':latitude (latitude msg))
    (cl:cons ':longitude (longitude msg))
    (cl:cons ':cap (cap msg))
))
