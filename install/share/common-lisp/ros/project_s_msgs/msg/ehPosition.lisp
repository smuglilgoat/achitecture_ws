; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ehPosition.msg.html

(cl:defclass <ehPosition> (roslisp-msg-protocol:ros-message)
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
   (offset
    :reader offset
    :initarg :offset
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
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (agePosition
    :reader agePosition
    :initarg :agePosition
    :type std_msgs-msg:UInt16
    :initform (cl:make-instance 'std_msgs-msg:UInt16))
   (speed
    :reader speed
    :initarg :speed
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (relativeHeading
    :reader relativeHeading
    :initarg :relativeHeading
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (currentLane
    :reader currentLane
    :initarg :currentLane
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8)))
)

(cl:defclass ehPosition (<ehPosition>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ehPosition>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ehPosition)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ehPosition> is deprecated: use project_s_msgs-msg:ehPosition instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ehPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ehPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'offset-val :lambda-list '(m))
(cl:defmethod offset-val ((m <ehPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offset-val is deprecated.  Use project_s_msgs-msg:offset instead.")
  (offset m))

(cl:ensure-generic-function 'latitude-val :lambda-list '(m))
(cl:defmethod latitude-val ((m <ehPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:latitude-val is deprecated.  Use project_s_msgs-msg:latitude instead.")
  (latitude m))

(cl:ensure-generic-function 'longitude-val :lambda-list '(m))
(cl:defmethod longitude-val ((m <ehPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:longitude-val is deprecated.  Use project_s_msgs-msg:longitude instead.")
  (longitude m))

(cl:ensure-generic-function 'cap-val :lambda-list '(m))
(cl:defmethod cap-val ((m <ehPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:cap-val is deprecated.  Use project_s_msgs-msg:cap instead.")
  (cap m))

(cl:ensure-generic-function 'agePosition-val :lambda-list '(m))
(cl:defmethod agePosition-val ((m <ehPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:agePosition-val is deprecated.  Use project_s_msgs-msg:agePosition instead.")
  (agePosition m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <ehPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:speed-val is deprecated.  Use project_s_msgs-msg:speed instead.")
  (speed m))

(cl:ensure-generic-function 'relativeHeading-val :lambda-list '(m))
(cl:defmethod relativeHeading-val ((m <ehPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:relativeHeading-val is deprecated.  Use project_s_msgs-msg:relativeHeading instead.")
  (relativeHeading m))

(cl:ensure-generic-function 'currentLane-val :lambda-list '(m))
(cl:defmethod currentLane-val ((m <ehPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:currentLane-val is deprecated.  Use project_s_msgs-msg:currentLane instead.")
  (currentLane m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ehPosition>) ostream)
  "Serializes a message object of type '<ehPosition>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'offset) ostream)
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
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'agePosition) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'speed) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'relativeHeading) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'currentLane) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ehPosition>) istream)
  "Deserializes a message object of type '<ehPosition>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'offset) istream)
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
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'agePosition) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'speed) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'relativeHeading) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'currentLane) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ehPosition>)))
  "Returns string type for a message object of type '<ehPosition>"
  "project_s_msgs/ehPosition")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ehPosition)))
  "Returns string type for a message object of type 'ehPosition"
  "project_s_msgs/ehPosition")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ehPosition>)))
  "Returns md5sum for a message object of type '<ehPosition>"
  "834273fcaebed780b99909cf00aa6ac8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ehPosition)))
  "Returns md5sum for a message object of type 'ehPosition"
  "834273fcaebed780b99909cf00aa6ac8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ehPosition>)))
  "Returns full string definition for message of type '<ehPosition>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%std_msgs/Float32 cap~%std_msgs/UInt16 agePosition~%std_msgs/Float32 speed~%std_msgs/Float32 relativeHeading~%std_msgs/UInt8 currentLane~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ehPosition)))
  "Returns full string definition for message of type 'ehPosition"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%std_msgs/Float32 cap~%std_msgs/UInt16 agePosition~%std_msgs/Float32 speed~%std_msgs/Float32 relativeHeading~%std_msgs/UInt8 currentLane~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ehPosition>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'offset))
     8
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'cap))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'agePosition))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'speed))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'relativeHeading))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'currentLane))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ehPosition>))
  "Converts a ROS message object to a list"
  (cl:list 'ehPosition
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':offset (offset msg))
    (cl:cons ':latitude (latitude msg))
    (cl:cons ':longitude (longitude msg))
    (cl:cons ':cap (cap msg))
    (cl:cons ':agePosition (agePosition msg))
    (cl:cons ':speed (speed msg))
    (cl:cons ':relativeHeading (relativeHeading msg))
    (cl:cons ':currentLane (currentLane msg))
))
