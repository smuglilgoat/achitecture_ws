; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ehSegment.msg.html

(cl:defclass <ehSegment> (roslisp-msg-protocol:ros-message)
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
   (functionRoadClass
    :reader functionRoadClass
    :initarg :functionRoadClass
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (wayForm
    :reader wayForm
    :initarg :wayForm
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (effectiveSpeedLimit
    :reader effectiveSpeedLimit
    :initarg :effectiveSpeedLimit
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (nbLanesDrivingDirection
    :reader nbLanesDrivingDirection
    :initarg :nbLanesDrivingDirection
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (nbLanesOppositeDirection
    :reader nbLanesOppositeDirection
    :initarg :nbLanesOppositeDirection
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8)))
)

(cl:defclass ehSegment (<ehSegment>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ehSegment>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ehSegment)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ehSegment> is deprecated: use project_s_msgs-msg:ehSegment instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ehSegment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ehSegment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'offset-val :lambda-list '(m))
(cl:defmethod offset-val ((m <ehSegment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offset-val is deprecated.  Use project_s_msgs-msg:offset instead.")
  (offset m))

(cl:ensure-generic-function 'functionRoadClass-val :lambda-list '(m))
(cl:defmethod functionRoadClass-val ((m <ehSegment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:functionRoadClass-val is deprecated.  Use project_s_msgs-msg:functionRoadClass instead.")
  (functionRoadClass m))

(cl:ensure-generic-function 'wayForm-val :lambda-list '(m))
(cl:defmethod wayForm-val ((m <ehSegment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:wayForm-val is deprecated.  Use project_s_msgs-msg:wayForm instead.")
  (wayForm m))

(cl:ensure-generic-function 'effectiveSpeedLimit-val :lambda-list '(m))
(cl:defmethod effectiveSpeedLimit-val ((m <ehSegment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:effectiveSpeedLimit-val is deprecated.  Use project_s_msgs-msg:effectiveSpeedLimit instead.")
  (effectiveSpeedLimit m))

(cl:ensure-generic-function 'nbLanesDrivingDirection-val :lambda-list '(m))
(cl:defmethod nbLanesDrivingDirection-val ((m <ehSegment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbLanesDrivingDirection-val is deprecated.  Use project_s_msgs-msg:nbLanesDrivingDirection instead.")
  (nbLanesDrivingDirection m))

(cl:ensure-generic-function 'nbLanesOppositeDirection-val :lambda-list '(m))
(cl:defmethod nbLanesOppositeDirection-val ((m <ehSegment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbLanesOppositeDirection-val is deprecated.  Use project_s_msgs-msg:nbLanesOppositeDirection instead.")
  (nbLanesOppositeDirection m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ehSegment>) ostream)
  "Serializes a message object of type '<ehSegment>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'offset) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'functionRoadClass) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'wayForm) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'effectiveSpeedLimit) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbLanesDrivingDirection) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbLanesOppositeDirection) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ehSegment>) istream)
  "Deserializes a message object of type '<ehSegment>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'offset) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'functionRoadClass) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'wayForm) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'effectiveSpeedLimit) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbLanesDrivingDirection) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbLanesOppositeDirection) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ehSegment>)))
  "Returns string type for a message object of type '<ehSegment>"
  "project_s_msgs/ehSegment")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ehSegment)))
  "Returns string type for a message object of type 'ehSegment"
  "project_s_msgs/ehSegment")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ehSegment>)))
  "Returns md5sum for a message object of type '<ehSegment>"
  "6537588d17c4b8421cfde3df0a7fac39")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ehSegment)))
  "Returns md5sum for a message object of type 'ehSegment"
  "6537588d17c4b8421cfde3df0a7fac39")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ehSegment>)))
  "Returns full string definition for message of type '<ehSegment>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 effectiveSpeedLimit~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ehSegment)))
  "Returns full string definition for message of type 'ehSegment"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 effectiveSpeedLimit~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ehSegment>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'offset))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'functionRoadClass))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'wayForm))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'effectiveSpeedLimit))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbLanesDrivingDirection))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbLanesOppositeDirection))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ehSegment>))
  "Converts a ROS message object to a list"
  (cl:list 'ehSegment
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':offset (offset msg))
    (cl:cons ':functionRoadClass (functionRoadClass msg))
    (cl:cons ':wayForm (wayForm msg))
    (cl:cons ':effectiveSpeedLimit (effectiveSpeedLimit msg))
    (cl:cons ':nbLanesDrivingDirection (nbLanesDrivingDirection msg))
    (cl:cons ':nbLanesOppositeDirection (nbLanesOppositeDirection msg))
))
