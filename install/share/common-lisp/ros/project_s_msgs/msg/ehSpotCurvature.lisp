; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ehSpotCurvature.msg.html

(cl:defclass <ehSpotCurvature> (roslisp-msg-protocol:ros-message)
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
   (Value_0
    :reader Value_0
    :initarg :Value_0
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (Distance_1
    :reader Distance_1
    :initarg :Distance_1
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (Value_1
    :reader Value_1
    :initarg :Value_1
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32)))
)

(cl:defclass ehSpotCurvature (<ehSpotCurvature>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ehSpotCurvature>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ehSpotCurvature)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ehSpotCurvature> is deprecated: use project_s_msgs-msg:ehSpotCurvature instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ehSpotCurvature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ehSpotCurvature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'offset-val :lambda-list '(m))
(cl:defmethod offset-val ((m <ehSpotCurvature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offset-val is deprecated.  Use project_s_msgs-msg:offset instead.")
  (offset m))

(cl:ensure-generic-function 'Value_0-val :lambda-list '(m))
(cl:defmethod Value_0-val ((m <ehSpotCurvature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Value_0-val is deprecated.  Use project_s_msgs-msg:Value_0 instead.")
  (Value_0 m))

(cl:ensure-generic-function 'Distance_1-val :lambda-list '(m))
(cl:defmethod Distance_1-val ((m <ehSpotCurvature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Distance_1-val is deprecated.  Use project_s_msgs-msg:Distance_1 instead.")
  (Distance_1 m))

(cl:ensure-generic-function 'Value_1-val :lambda-list '(m))
(cl:defmethod Value_1-val ((m <ehSpotCurvature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Value_1-val is deprecated.  Use project_s_msgs-msg:Value_1 instead.")
  (Value_1 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ehSpotCurvature>) ostream)
  "Serializes a message object of type '<ehSpotCurvature>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'offset) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Value_0) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Distance_1) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Value_1) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ehSpotCurvature>) istream)
  "Deserializes a message object of type '<ehSpotCurvature>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'offset) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Value_0) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Distance_1) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Value_1) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ehSpotCurvature>)))
  "Returns string type for a message object of type '<ehSpotCurvature>"
  "project_s_msgs/ehSpotCurvature")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ehSpotCurvature)))
  "Returns string type for a message object of type 'ehSpotCurvature"
  "project_s_msgs/ehSpotCurvature")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ehSpotCurvature>)))
  "Returns md5sum for a message object of type '<ehSpotCurvature>"
  "9d76e4756ee6f85fb71ecf3f9d7549f6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ehSpotCurvature)))
  "Returns md5sum for a message object of type 'ehSpotCurvature"
  "9d76e4756ee6f85fb71ecf3f9d7549f6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ehSpotCurvature>)))
  "Returns full string definition for message of type '<ehSpotCurvature>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/Float32 Value_0~%std_msgs/Float32 Distance_1~%std_msgs/Float32 Value_1~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ehSpotCurvature)))
  "Returns full string definition for message of type 'ehSpotCurvature"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/Float32 Value_0~%std_msgs/Float32 Distance_1~%std_msgs/Float32 Value_1~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ehSpotCurvature>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'offset))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Value_0))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Distance_1))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Value_1))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ehSpotCurvature>))
  "Converts a ROS message object to a list"
  (cl:list 'ehSpotCurvature
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':offset (offset msg))
    (cl:cons ':Value_0 (Value_0 msg))
    (cl:cons ':Distance_1 (Distance_1 msg))
    (cl:cons ':Value_1 (Value_1 msg))
))
