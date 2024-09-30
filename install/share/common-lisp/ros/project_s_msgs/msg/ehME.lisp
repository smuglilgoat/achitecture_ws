; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ehME.msg.html

(cl:defclass <ehME> (roslisp-msg-protocol:ros-message)
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
   :initform (cl:make-array 2000 :element-type 'project_s_msgs-msg:ehSpotCoordGeo :initial-element (cl:make-instance 'project_s_msgs-msg:ehSpotCoordGeo)))
   (NbrSpotCoordGeo
    :reader NbrSpotCoordGeo
    :initarg :NbrSpotCoordGeo
    :type std_msgs-msg:UInt32
    :initform (cl:make-instance 'std_msgs-msg:UInt32))
   (ehSegmentME
    :reader ehSegmentME
    :initarg :ehSegmentME
    :type (cl:vector project_s_msgs-msg:ehSegmentME)
   :initform (cl:make-array 100 :element-type 'project_s_msgs-msg:ehSegmentME :initial-element (cl:make-instance 'project_s_msgs-msg:ehSegmentME)))
   (QtySegment
    :reader QtySegment
    :initarg :QtySegment
    :type std_msgs-msg:UInt32
    :initform (cl:make-instance 'std_msgs-msg:UInt32)))
)

(cl:defclass ehME (<ehME>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ehME>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ehME)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ehME> is deprecated: use project_s_msgs-msg:ehME instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ehME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ehME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'ehSpotCoordGeo-val :lambda-list '(m))
(cl:defmethod ehSpotCoordGeo-val ((m <ehME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehSpotCoordGeo-val is deprecated.  Use project_s_msgs-msg:ehSpotCoordGeo instead.")
  (ehSpotCoordGeo m))

(cl:ensure-generic-function 'NbrSpotCoordGeo-val :lambda-list '(m))
(cl:defmethod NbrSpotCoordGeo-val ((m <ehME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:NbrSpotCoordGeo-val is deprecated.  Use project_s_msgs-msg:NbrSpotCoordGeo instead.")
  (NbrSpotCoordGeo m))

(cl:ensure-generic-function 'ehSegmentME-val :lambda-list '(m))
(cl:defmethod ehSegmentME-val ((m <ehME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehSegmentME-val is deprecated.  Use project_s_msgs-msg:ehSegmentME instead.")
  (ehSegmentME m))

(cl:ensure-generic-function 'QtySegment-val :lambda-list '(m))
(cl:defmethod QtySegment-val ((m <ehME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:QtySegment-val is deprecated.  Use project_s_msgs-msg:QtySegment instead.")
  (QtySegment m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<ehME>)))
    "Constants for message type '<ehME>"
  '((:SPOT_REPORT_SIZE . 2000)
    (:SEGMENT_ME_REPORT_SIZE . 100))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'ehME)))
    "Constants for message type 'ehME"
  '((:SPOT_REPORT_SIZE . 2000)
    (:SEGMENT_ME_REPORT_SIZE . 100))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ehME>) ostream)
  "Serializes a message object of type '<ehME>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehSpotCoordGeo))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'NbrSpotCoordGeo) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehSegmentME))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'QtySegment) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ehME>) istream)
  "Deserializes a message object of type '<ehME>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (cl:setf (cl:slot-value msg 'ehSpotCoordGeo) (cl:make-array 2000))
  (cl:let ((vals (cl:slot-value msg 'ehSpotCoordGeo)))
    (cl:dotimes (i 2000)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehSpotCoordGeo))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'NbrSpotCoordGeo) istream)
  (cl:setf (cl:slot-value msg 'ehSegmentME) (cl:make-array 100))
  (cl:let ((vals (cl:slot-value msg 'ehSegmentME)))
    (cl:dotimes (i 100)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehSegmentME))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'QtySegment) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ehME>)))
  "Returns string type for a message object of type '<ehME>"
  "project_s_msgs/ehME")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ehME)))
  "Returns string type for a message object of type 'ehME"
  "project_s_msgs/ehME")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ehME>)))
  "Returns md5sum for a message object of type '<ehME>"
  "e863f3ecd7a3f6b54ef653190281ff51")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ehME)))
  "Returns md5sum for a message object of type 'ehME"
  "e863f3ecd7a3f6b54ef653190281ff51")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ehME>)))
  "Returns full string definition for message of type '<ehME>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%uint32 SEGMENT_ME_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentME~%std_msgs/UInt32 QtySegment~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/ehSpotCoordGeo~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: project_s_msgs/ehSegmentME~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 NbrSpot~%std_msgs/Float32 offset_debut~%std_msgs/Float32 offset_fin~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ehME)))
  "Returns full string definition for message of type 'ehME"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%uint32 SEGMENT_ME_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentME~%std_msgs/UInt32 QtySegment~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/ehSpotCoordGeo~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: project_s_msgs/ehSegmentME~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 NbrSpot~%std_msgs/Float32 offset_debut~%std_msgs/Float32 offset_fin~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ehME>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehSpotCoordGeo) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'NbrSpotCoordGeo))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehSegmentME) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'QtySegment))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ehME>))
  "Converts a ROS message object to a list"
  (cl:list 'ehME
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':ehSpotCoordGeo (ehSpotCoordGeo msg))
    (cl:cons ':NbrSpotCoordGeo (NbrSpotCoordGeo msg))
    (cl:cons ':ehSegmentME (ehSegmentME msg))
    (cl:cons ':QtySegment (QtySegment msg))
))
