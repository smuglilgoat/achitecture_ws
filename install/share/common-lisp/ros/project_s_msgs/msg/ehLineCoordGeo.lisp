; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ehLineCoordGeo.msg.html

(cl:defclass <ehLineCoordGeo> (roslisp-msg-protocol:ros-message)
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
   (ehSpotCoordGeo
    :reader ehSpotCoordGeo
    :initarg :ehSpotCoordGeo
    :type (cl:vector project_s_msgs-msg:ehSpotCoordGeo)
   :initform (cl:make-array 3000 :element-type 'project_s_msgs-msg:ehSpotCoordGeo :initial-element (cl:make-instance 'project_s_msgs-msg:ehSpotCoordGeo)))
   (NbrSpotCoordGeo
    :reader NbrSpotCoordGeo
    :initarg :NbrSpotCoordGeo
    :type std_msgs-msg:UInt32
    :initform (cl:make-instance 'std_msgs-msg:UInt32)))
)

(cl:defclass ehLineCoordGeo (<ehLineCoordGeo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ehLineCoordGeo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ehLineCoordGeo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ehLineCoordGeo> is deprecated: use project_s_msgs-msg:ehLineCoordGeo instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ehLineCoordGeo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ehLineCoordGeo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'ehSpotCoordGeo-val :lambda-list '(m))
(cl:defmethod ehSpotCoordGeo-val ((m <ehLineCoordGeo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehSpotCoordGeo-val is deprecated.  Use project_s_msgs-msg:ehSpotCoordGeo instead.")
  (ehSpotCoordGeo m))

(cl:ensure-generic-function 'NbrSpotCoordGeo-val :lambda-list '(m))
(cl:defmethod NbrSpotCoordGeo-val ((m <ehLineCoordGeo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:NbrSpotCoordGeo-val is deprecated.  Use project_s_msgs-msg:NbrSpotCoordGeo instead.")
  (NbrSpotCoordGeo m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<ehLineCoordGeo>)))
    "Constants for message type '<ehLineCoordGeo>"
  '((:SPOT_REPORT_SIZE . 3000))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'ehLineCoordGeo)))
    "Constants for message type 'ehLineCoordGeo"
  '((:SPOT_REPORT_SIZE . 3000))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ehLineCoordGeo>) ostream)
  "Serializes a message object of type '<ehLineCoordGeo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehSpotCoordGeo))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'NbrSpotCoordGeo) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ehLineCoordGeo>) istream)
  "Deserializes a message object of type '<ehLineCoordGeo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (cl:setf (cl:slot-value msg 'ehSpotCoordGeo) (cl:make-array 3000))
  (cl:let ((vals (cl:slot-value msg 'ehSpotCoordGeo)))
    (cl:dotimes (i 3000)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehSpotCoordGeo))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'NbrSpotCoordGeo) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ehLineCoordGeo>)))
  "Returns string type for a message object of type '<ehLineCoordGeo>"
  "project_s_msgs/ehLineCoordGeo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ehLineCoordGeo)))
  "Returns string type for a message object of type 'ehLineCoordGeo"
  "project_s_msgs/ehLineCoordGeo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ehLineCoordGeo>)))
  "Returns md5sum for a message object of type '<ehLineCoordGeo>"
  "ead25328a4cdf8f2b075ecd4258a79fb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ehLineCoordGeo)))
  "Returns md5sum for a message object of type 'ehLineCoordGeo"
  "ead25328a4cdf8f2b075ecd4258a79fb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ehLineCoordGeo>)))
  "Returns full string definition for message of type '<ehLineCoordGeo>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 3000~%project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/ehSpotCoordGeo~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ehLineCoordGeo)))
  "Returns full string definition for message of type 'ehLineCoordGeo"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 3000~%project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/ehSpotCoordGeo~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ehLineCoordGeo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehSpotCoordGeo) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'NbrSpotCoordGeo))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ehLineCoordGeo>))
  "Converts a ROS message object to a list"
  (cl:list 'ehLineCoordGeo
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':ehSpotCoordGeo (ehSpotCoordGeo msg))
    (cl:cons ':NbrSpotCoordGeo (NbrSpotCoordGeo msg))
))
