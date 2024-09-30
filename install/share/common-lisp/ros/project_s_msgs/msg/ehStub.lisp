; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ehStub.msg.html

(cl:defclass <ehStub> (roslisp-msg-protocol:ros-message)
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
   (indexSubPath
    :reader indexSubPath
    :initarg :indexSubPath
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (turnAngle
    :reader turnAngle
    :initarg :turnAngle
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

(cl:defclass ehStub (<ehStub>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ehStub>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ehStub)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ehStub> is deprecated: use project_s_msgs-msg:ehStub instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ehStub>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ehStub>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'offset-val :lambda-list '(m))
(cl:defmethod offset-val ((m <ehStub>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offset-val is deprecated.  Use project_s_msgs-msg:offset instead.")
  (offset m))

(cl:ensure-generic-function 'indexSubPath-val :lambda-list '(m))
(cl:defmethod indexSubPath-val ((m <ehStub>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:indexSubPath-val is deprecated.  Use project_s_msgs-msg:indexSubPath instead.")
  (indexSubPath m))

(cl:ensure-generic-function 'turnAngle-val :lambda-list '(m))
(cl:defmethod turnAngle-val ((m <ehStub>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:turnAngle-val is deprecated.  Use project_s_msgs-msg:turnAngle instead.")
  (turnAngle m))

(cl:ensure-generic-function 'functionRoadClass-val :lambda-list '(m))
(cl:defmethod functionRoadClass-val ((m <ehStub>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:functionRoadClass-val is deprecated.  Use project_s_msgs-msg:functionRoadClass instead.")
  (functionRoadClass m))

(cl:ensure-generic-function 'wayForm-val :lambda-list '(m))
(cl:defmethod wayForm-val ((m <ehStub>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:wayForm-val is deprecated.  Use project_s_msgs-msg:wayForm instead.")
  (wayForm m))

(cl:ensure-generic-function 'nbLanesDrivingDirection-val :lambda-list '(m))
(cl:defmethod nbLanesDrivingDirection-val ((m <ehStub>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbLanesDrivingDirection-val is deprecated.  Use project_s_msgs-msg:nbLanesDrivingDirection instead.")
  (nbLanesDrivingDirection m))

(cl:ensure-generic-function 'nbLanesOppositeDirection-val :lambda-list '(m))
(cl:defmethod nbLanesOppositeDirection-val ((m <ehStub>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbLanesOppositeDirection-val is deprecated.  Use project_s_msgs-msg:nbLanesOppositeDirection instead.")
  (nbLanesOppositeDirection m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ehStub>) ostream)
  "Serializes a message object of type '<ehStub>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'offset) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'indexSubPath) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'turnAngle) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'functionRoadClass) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'wayForm) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbLanesDrivingDirection) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbLanesOppositeDirection) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ehStub>) istream)
  "Deserializes a message object of type '<ehStub>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'offset) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'indexSubPath) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'turnAngle) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'functionRoadClass) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'wayForm) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbLanesDrivingDirection) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbLanesOppositeDirection) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ehStub>)))
  "Returns string type for a message object of type '<ehStub>"
  "project_s_msgs/ehStub")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ehStub)))
  "Returns string type for a message object of type 'ehStub"
  "project_s_msgs/ehStub")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ehStub>)))
  "Returns md5sum for a message object of type '<ehStub>"
  "c119249a96bd27bec3a52d59a68f5895")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ehStub)))
  "Returns md5sum for a message object of type 'ehStub"
  "c119249a96bd27bec3a52d59a68f5895")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ehStub>)))
  "Returns full string definition for message of type '<ehStub>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 indexSubPath~%std_msgs/Float32 turnAngle~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ehStub)))
  "Returns full string definition for message of type 'ehStub"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 indexSubPath~%std_msgs/Float32 turnAngle~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ehStub>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'offset))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'indexSubPath))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'turnAngle))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'functionRoadClass))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'wayForm))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbLanesDrivingDirection))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbLanesOppositeDirection))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ehStub>))
  "Converts a ROS message object to a list"
  (cl:list 'ehStub
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':offset (offset msg))
    (cl:cons ':indexSubPath (indexSubPath msg))
    (cl:cons ':turnAngle (turnAngle msg))
    (cl:cons ':functionRoadClass (functionRoadClass msg))
    (cl:cons ':wayForm (wayForm msg))
    (cl:cons ':nbLanesDrivingDirection (nbLanesDrivingDirection msg))
    (cl:cons ':nbLanesOppositeDirection (nbLanesOppositeDirection msg))
))
