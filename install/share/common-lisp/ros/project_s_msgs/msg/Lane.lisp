; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude Lane.msg.html

(cl:defclass <Lane> (roslisp-msg-protocol:ros-message)
  ((idLineRight
    :reader idLineRight
    :initarg :idLineRight
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (idLineLeft
    :reader idLineLeft
    :initarg :idLineLeft
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (offsetStart
    :reader offsetStart
    :initarg :offsetStart
    :type cl:fixnum
    :initform 0)
   (offsetEnd
    :reader offsetEnd
    :initarg :offsetEnd
    :type cl:fixnum
    :initform 0)
   (trafficDirection
    :reader trafficDirection
    :initarg :trafficDirection
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (priority
    :reader priority
    :initarg :priority
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (speedLimit
    :reader speedLimit
    :initarg :speedLimit
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (TrafficSign
    :reader TrafficSign
    :initarg :TrafficSign
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (turnOffset
    :reader turnOffset
    :initarg :turnOffset
    :type cl:fixnum
    :initform 0)
   (turnRadius
    :reader turnRadius
    :initarg :turnRadius
    :type cl:float
    :initform 0.0)
   (crossRoadClass
    :reader crossRoadClass
    :initarg :crossRoadClass
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (crossRoadOffset
    :reader crossRoadOffset
    :initarg :crossRoadOffset
    :type cl:fixnum
    :initform 0)
   (crossRoadPriority
    :reader crossRoadPriority
    :initarg :crossRoadPriority
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8)))
)

(cl:defclass Lane (<Lane>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Lane>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Lane)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<Lane> is deprecated: use project_s_msgs-msg:Lane instead.")))

(cl:ensure-generic-function 'idLineRight-val :lambda-list '(m))
(cl:defmethod idLineRight-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:idLineRight-val is deprecated.  Use project_s_msgs-msg:idLineRight instead.")
  (idLineRight m))

(cl:ensure-generic-function 'idLineLeft-val :lambda-list '(m))
(cl:defmethod idLineLeft-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:idLineLeft-val is deprecated.  Use project_s_msgs-msg:idLineLeft instead.")
  (idLineLeft m))

(cl:ensure-generic-function 'offsetStart-val :lambda-list '(m))
(cl:defmethod offsetStart-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offsetStart-val is deprecated.  Use project_s_msgs-msg:offsetStart instead.")
  (offsetStart m))

(cl:ensure-generic-function 'offsetEnd-val :lambda-list '(m))
(cl:defmethod offsetEnd-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offsetEnd-val is deprecated.  Use project_s_msgs-msg:offsetEnd instead.")
  (offsetEnd m))

(cl:ensure-generic-function 'trafficDirection-val :lambda-list '(m))
(cl:defmethod trafficDirection-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:trafficDirection-val is deprecated.  Use project_s_msgs-msg:trafficDirection instead.")
  (trafficDirection m))

(cl:ensure-generic-function 'priority-val :lambda-list '(m))
(cl:defmethod priority-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:priority-val is deprecated.  Use project_s_msgs-msg:priority instead.")
  (priority m))

(cl:ensure-generic-function 'speedLimit-val :lambda-list '(m))
(cl:defmethod speedLimit-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:speedLimit-val is deprecated.  Use project_s_msgs-msg:speedLimit instead.")
  (speedLimit m))

(cl:ensure-generic-function 'TrafficSign-val :lambda-list '(m))
(cl:defmethod TrafficSign-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:TrafficSign-val is deprecated.  Use project_s_msgs-msg:TrafficSign instead.")
  (TrafficSign m))

(cl:ensure-generic-function 'turnOffset-val :lambda-list '(m))
(cl:defmethod turnOffset-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:turnOffset-val is deprecated.  Use project_s_msgs-msg:turnOffset instead.")
  (turnOffset m))

(cl:ensure-generic-function 'turnRadius-val :lambda-list '(m))
(cl:defmethod turnRadius-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:turnRadius-val is deprecated.  Use project_s_msgs-msg:turnRadius instead.")
  (turnRadius m))

(cl:ensure-generic-function 'crossRoadClass-val :lambda-list '(m))
(cl:defmethod crossRoadClass-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:crossRoadClass-val is deprecated.  Use project_s_msgs-msg:crossRoadClass instead.")
  (crossRoadClass m))

(cl:ensure-generic-function 'crossRoadOffset-val :lambda-list '(m))
(cl:defmethod crossRoadOffset-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:crossRoadOffset-val is deprecated.  Use project_s_msgs-msg:crossRoadOffset instead.")
  (crossRoadOffset m))

(cl:ensure-generic-function 'crossRoadPriority-val :lambda-list '(m))
(cl:defmethod crossRoadPriority-val ((m <Lane>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:crossRoadPriority-val is deprecated.  Use project_s_msgs-msg:crossRoadPriority instead.")
  (crossRoadPriority m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Lane>) ostream)
  "Serializes a message object of type '<Lane>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'idLineRight) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'idLineLeft) ostream)
  (cl:let* ((signed (cl:slot-value msg 'offsetStart)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'offsetEnd)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'trafficDirection) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'priority) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'speedLimit) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'TrafficSign) ostream)
  (cl:let* ((signed (cl:slot-value msg 'turnOffset)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'turnRadius))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'crossRoadClass) ostream)
  (cl:let* ((signed (cl:slot-value msg 'crossRoadOffset)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'crossRoadPriority) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Lane>) istream)
  "Deserializes a message object of type '<Lane>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'idLineRight) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'idLineLeft) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'offsetStart) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'offsetEnd) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'trafficDirection) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'priority) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'speedLimit) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'TrafficSign) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'turnOffset) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'turnRadius) (roslisp-utils:decode-single-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'crossRoadClass) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'crossRoadOffset) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'crossRoadPriority) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Lane>)))
  "Returns string type for a message object of type '<Lane>"
  "project_s_msgs/Lane")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Lane)))
  "Returns string type for a message object of type 'Lane"
  "project_s_msgs/Lane")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Lane>)))
  "Returns md5sum for a message object of type '<Lane>"
  "ac4b37c308258de2eff999751d19fd39")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Lane)))
  "Returns md5sum for a message object of type 'Lane"
  "ac4b37c308258de2eff999751d19fd39")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Lane>)))
  "Returns full string definition for message of type '<Lane>"
  (cl:format cl:nil "std_msgs/UInt8 idLineRight~%std_msgs/UInt8 idLineLeft~%int16 offsetStart~%int16 offsetEnd~%std_msgs/UInt8 trafficDirection~%std_msgs/UInt8 priority~%std_msgs/UInt8 speedLimit~%std_msgs/UInt8 TrafficSign~%int16 turnOffset~%float32 turnRadius~%std_msgs/UInt8 crossRoadClass~%int16 crossRoadOffset~%std_msgs/UInt8 crossRoadPriority~%~%~%~%~%~%~%~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Lane)))
  "Returns full string definition for message of type 'Lane"
  (cl:format cl:nil "std_msgs/UInt8 idLineRight~%std_msgs/UInt8 idLineLeft~%int16 offsetStart~%int16 offsetEnd~%std_msgs/UInt8 trafficDirection~%std_msgs/UInt8 priority~%std_msgs/UInt8 speedLimit~%std_msgs/UInt8 TrafficSign~%int16 turnOffset~%float32 turnRadius~%std_msgs/UInt8 crossRoadClass~%int16 crossRoadOffset~%std_msgs/UInt8 crossRoadPriority~%~%~%~%~%~%~%~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Lane>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'idLineRight))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'idLineLeft))
     2
     2
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'trafficDirection))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'priority))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'speedLimit))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'TrafficSign))
     2
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'crossRoadClass))
     2
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'crossRoadPriority))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Lane>))
  "Converts a ROS message object to a list"
  (cl:list 'Lane
    (cl:cons ':idLineRight (idLineRight msg))
    (cl:cons ':idLineLeft (idLineLeft msg))
    (cl:cons ':offsetStart (offsetStart msg))
    (cl:cons ':offsetEnd (offsetEnd msg))
    (cl:cons ':trafficDirection (trafficDirection msg))
    (cl:cons ':priority (priority msg))
    (cl:cons ':speedLimit (speedLimit msg))
    (cl:cons ':TrafficSign (TrafficSign msg))
    (cl:cons ':turnOffset (turnOffset msg))
    (cl:cons ':turnRadius (turnRadius msg))
    (cl:cons ':crossRoadClass (crossRoadClass msg))
    (cl:cons ':crossRoadOffset (crossRoadOffset msg))
    (cl:cons ':crossRoadPriority (crossRoadPriority msg))
))
