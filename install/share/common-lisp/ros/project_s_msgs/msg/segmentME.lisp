; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude segmentME.msg.html

(cl:defclass <segmentME> (roslisp-msg-protocol:ros-message)
  ((NbrSpot
    :reader NbrSpot
    :initarg :NbrSpot
    :type cl:integer
    :initform 0)
   (offset_debut
    :reader offset_debut
    :initarg :offset_debut
    :type cl:float
    :initform 0.0)
   (offset_fin
    :reader offset_fin
    :initarg :offset_fin
    :type cl:float
    :initform 0.0))
)

(cl:defclass segmentME (<segmentME>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <segmentME>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'segmentME)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<segmentME> is deprecated: use project_s_msgs-msg:segmentME instead.")))

(cl:ensure-generic-function 'NbrSpot-val :lambda-list '(m))
(cl:defmethod NbrSpot-val ((m <segmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:NbrSpot-val is deprecated.  Use project_s_msgs-msg:NbrSpot instead.")
  (NbrSpot m))

(cl:ensure-generic-function 'offset_debut-val :lambda-list '(m))
(cl:defmethod offset_debut-val ((m <segmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offset_debut-val is deprecated.  Use project_s_msgs-msg:offset_debut instead.")
  (offset_debut m))

(cl:ensure-generic-function 'offset_fin-val :lambda-list '(m))
(cl:defmethod offset_fin-val ((m <segmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offset_fin-val is deprecated.  Use project_s_msgs-msg:offset_fin instead.")
  (offset_fin m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <segmentME>) ostream)
  "Serializes a message object of type '<segmentME>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'NbrSpot)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'NbrSpot)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'NbrSpot)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'NbrSpot)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'offset_debut))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'offset_fin))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <segmentME>) istream)
  "Deserializes a message object of type '<segmentME>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'NbrSpot)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'NbrSpot)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'NbrSpot)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'NbrSpot)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'offset_debut) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'offset_fin) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<segmentME>)))
  "Returns string type for a message object of type '<segmentME>"
  "project_s_msgs/segmentME")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'segmentME)))
  "Returns string type for a message object of type 'segmentME"
  "project_s_msgs/segmentME")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<segmentME>)))
  "Returns md5sum for a message object of type '<segmentME>"
  "db8cd94b2ab5d013db8e670f53a36229")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'segmentME)))
  "Returns md5sum for a message object of type 'segmentME"
  "db8cd94b2ab5d013db8e670f53a36229")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<segmentME>)))
  "Returns full string definition for message of type '<segmentME>"
  (cl:format cl:nil "uint32 NbrSpot~%float32 offset_debut~%float32 offset_fin~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'segmentME)))
  "Returns full string definition for message of type 'segmentME"
  (cl:format cl:nil "uint32 NbrSpot~%float32 offset_debut~%float32 offset_fin~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <segmentME>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <segmentME>))
  "Converts a ROS message object to a list"
  (cl:list 'segmentME
    (cl:cons ':NbrSpot (NbrSpot msg))
    (cl:cons ':offset_debut (offset_debut msg))
    (cl:cons ':offset_fin (offset_fin msg))
))
