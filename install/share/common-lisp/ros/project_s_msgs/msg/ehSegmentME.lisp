; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ehSegmentME.msg.html

(cl:defclass <ehSegmentME> (roslisp-msg-protocol:ros-message)
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
   (NbrSpot
    :reader NbrSpot
    :initarg :NbrSpot
    :type std_msgs-msg:UInt32
    :initform (cl:make-instance 'std_msgs-msg:UInt32))
   (offset_debut
    :reader offset_debut
    :initarg :offset_debut
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (offset_fin
    :reader offset_fin
    :initarg :offset_fin
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32)))
)

(cl:defclass ehSegmentME (<ehSegmentME>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ehSegmentME>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ehSegmentME)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ehSegmentME> is deprecated: use project_s_msgs-msg:ehSegmentME instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ehSegmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ehSegmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'NbrSpot-val :lambda-list '(m))
(cl:defmethod NbrSpot-val ((m <ehSegmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:NbrSpot-val is deprecated.  Use project_s_msgs-msg:NbrSpot instead.")
  (NbrSpot m))

(cl:ensure-generic-function 'offset_debut-val :lambda-list '(m))
(cl:defmethod offset_debut-val ((m <ehSegmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offset_debut-val is deprecated.  Use project_s_msgs-msg:offset_debut instead.")
  (offset_debut m))

(cl:ensure-generic-function 'offset_fin-val :lambda-list '(m))
(cl:defmethod offset_fin-val ((m <ehSegmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offset_fin-val is deprecated.  Use project_s_msgs-msg:offset_fin instead.")
  (offset_fin m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ehSegmentME>) ostream)
  "Serializes a message object of type '<ehSegmentME>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'NbrSpot) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'offset_debut) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'offset_fin) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ehSegmentME>) istream)
  "Deserializes a message object of type '<ehSegmentME>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'NbrSpot) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'offset_debut) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'offset_fin) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ehSegmentME>)))
  "Returns string type for a message object of type '<ehSegmentME>"
  "project_s_msgs/ehSegmentME")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ehSegmentME)))
  "Returns string type for a message object of type 'ehSegmentME"
  "project_s_msgs/ehSegmentME")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ehSegmentME>)))
  "Returns md5sum for a message object of type '<ehSegmentME>"
  "fc1755dbec2ea339a235fdf3e4d21311")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ehSegmentME)))
  "Returns md5sum for a message object of type 'ehSegmentME"
  "fc1755dbec2ea339a235fdf3e4d21311")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ehSegmentME>)))
  "Returns full string definition for message of type '<ehSegmentME>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 NbrSpot~%std_msgs/Float32 offset_debut~%std_msgs/Float32 offset_fin~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ehSegmentME)))
  "Returns full string definition for message of type 'ehSegmentME"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 NbrSpot~%std_msgs/Float32 offset_debut~%std_msgs/Float32 offset_fin~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ehSegmentME>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'NbrSpot))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'offset_debut))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'offset_fin))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ehSegmentME>))
  "Converts a ROS message object to a list"
  (cl:list 'ehSegmentME
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':NbrSpot (NbrSpot msg))
    (cl:cons ':offset_debut (offset_debut msg))
    (cl:cons ':offset_fin (offset_fin msg))
))
