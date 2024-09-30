; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude MissionManagerModem.msg.html

(cl:defclass <MissionManagerModem> (roslisp-msg-protocol:ros-message)
  ((stamp
    :reader stamp
    :initarg :stamp
    :type cl:real
    :initform 0)
   (request
    :reader request
    :initarg :request
    :type cl:float
    :initform 0.0))
)

(cl:defclass MissionManagerModem (<MissionManagerModem>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MissionManagerModem>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MissionManagerModem)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<MissionManagerModem> is deprecated: use project_s_msgs-msg:MissionManagerModem instead.")))

(cl:ensure-generic-function 'stamp-val :lambda-list '(m))
(cl:defmethod stamp-val ((m <MissionManagerModem>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:stamp-val is deprecated.  Use project_s_msgs-msg:stamp instead.")
  (stamp m))

(cl:ensure-generic-function 'request-val :lambda-list '(m))
(cl:defmethod request-val ((m <MissionManagerModem>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:request-val is deprecated.  Use project_s_msgs-msg:request instead.")
  (request m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MissionManagerModem>) ostream)
  "Serializes a message object of type '<MissionManagerModem>"
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'stamp)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'stamp) (cl:floor (cl:slot-value msg 'stamp)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'request))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MissionManagerModem>) istream)
  "Deserializes a message object of type '<MissionManagerModem>"
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stamp) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'request) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MissionManagerModem>)))
  "Returns string type for a message object of type '<MissionManagerModem>"
  "project_s_msgs/MissionManagerModem")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MissionManagerModem)))
  "Returns string type for a message object of type 'MissionManagerModem"
  "project_s_msgs/MissionManagerModem")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MissionManagerModem>)))
  "Returns md5sum for a message object of type '<MissionManagerModem>"
  "37e4d8b8bd95addccb35ddd346779b1f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MissionManagerModem)))
  "Returns md5sum for a message object of type 'MissionManagerModem"
  "37e4d8b8bd95addccb35ddd346779b1f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MissionManagerModem>)))
  "Returns full string definition for message of type '<MissionManagerModem>"
  (cl:format cl:nil "time stamp~%~%float32 request~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MissionManagerModem)))
  "Returns full string definition for message of type 'MissionManagerModem"
  (cl:format cl:nil "time stamp~%~%float32 request~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MissionManagerModem>))
  (cl:+ 0
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MissionManagerModem>))
  "Converts a ROS message object to a list"
  (cl:list 'MissionManagerModem
    (cl:cons ':stamp (stamp msg))
    (cl:cons ':request (request msg))
))
