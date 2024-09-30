; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude Time.msg.html

(cl:defclass <Time> (roslisp-msg-protocol:ros-message)
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
   (Tn
    :reader Tn
    :initarg :Tn
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64))
   (Tn_1
    :reader Tn_1
    :initarg :Tn_1
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64))
   (Ti
    :reader Ti
    :initarg :Ti
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64))
   (iMIN
    :reader iMIN
    :initarg :iMIN
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64)))
)

(cl:defclass Time (<Time>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Time>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Time)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<Time> is deprecated: use project_s_msgs-msg:Time instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <Time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'Tn-val :lambda-list '(m))
(cl:defmethod Tn-val ((m <Time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Tn-val is deprecated.  Use project_s_msgs-msg:Tn instead.")
  (Tn m))

(cl:ensure-generic-function 'Tn_1-val :lambda-list '(m))
(cl:defmethod Tn_1-val ((m <Time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Tn_1-val is deprecated.  Use project_s_msgs-msg:Tn_1 instead.")
  (Tn_1 m))

(cl:ensure-generic-function 'Ti-val :lambda-list '(m))
(cl:defmethod Ti-val ((m <Time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Ti-val is deprecated.  Use project_s_msgs-msg:Ti instead.")
  (Ti m))

(cl:ensure-generic-function 'iMIN-val :lambda-list '(m))
(cl:defmethod iMIN-val ((m <Time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:iMIN-val is deprecated.  Use project_s_msgs-msg:iMIN instead.")
  (iMIN m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Time>) ostream)
  "Serializes a message object of type '<Time>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Tn) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Tn_1) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Ti) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'iMIN) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Time>) istream)
  "Deserializes a message object of type '<Time>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Tn) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Tn_1) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Ti) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'iMIN) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Time>)))
  "Returns string type for a message object of type '<Time>"
  "project_s_msgs/Time")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Time)))
  "Returns string type for a message object of type 'Time"
  "project_s_msgs/Time")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Time>)))
  "Returns md5sum for a message object of type '<Time>"
  "8478fcb0a41d3039f22925b77479cd7f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Time)))
  "Returns md5sum for a message object of type 'Time"
  "8478fcb0a41d3039f22925b77479cd7f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Time>)))
  "Returns full string definition for message of type '<Time>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/Float64 Tn~%std_msgs/Float64 Tn_1~%std_msgs/Float64 Ti~%std_msgs/Float64 iMIN~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Time)))
  "Returns full string definition for message of type 'Time"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/Float64 Tn~%std_msgs/Float64 Tn_1~%std_msgs/Float64 Ti~%std_msgs/Float64 iMIN~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Time>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Tn))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Tn_1))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Ti))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'iMIN))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Time>))
  "Converts a ROS message object to a list"
  (cl:list 'Time
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':Tn (Tn msg))
    (cl:cons ':Tn_1 (Tn_1 msg))
    (cl:cons ':Ti (Ti msg))
    (cl:cons ':iMIN (iMIN msg))
))
