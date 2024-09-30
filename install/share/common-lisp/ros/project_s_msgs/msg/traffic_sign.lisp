; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude traffic_sign.msg.html

(cl:defclass <traffic_sign> (roslisp-msg-protocol:ros-message)
  ((offset
    :reader offset
    :initarg :offset
    :type cl:float
    :initform 0.0)
   (Sign_Type
    :reader Sign_Type
    :initarg :Sign_Type
    :type cl:fixnum
    :initform 0)
   (Value
    :reader Value
    :initarg :Value
    :type cl:fixnum
    :initform 0)
   (Lane
    :reader Lane
    :initarg :Lane
    :type cl:fixnum
    :initform 0)
   (Sign_Location
    :reader Sign_Location
    :initarg :Sign_Location
    :type cl:fixnum
    :initform 0)
   (latitude
    :reader latitude
    :initarg :latitude
    :type cl:float
    :initform 0.0)
   (longitude
    :reader longitude
    :initarg :longitude
    :type cl:float
    :initform 0.0))
)

(cl:defclass traffic_sign (<traffic_sign>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <traffic_sign>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'traffic_sign)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<traffic_sign> is deprecated: use project_s_msgs-msg:traffic_sign instead.")))

(cl:ensure-generic-function 'offset-val :lambda-list '(m))
(cl:defmethod offset-val ((m <traffic_sign>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offset-val is deprecated.  Use project_s_msgs-msg:offset instead.")
  (offset m))

(cl:ensure-generic-function 'Sign_Type-val :lambda-list '(m))
(cl:defmethod Sign_Type-val ((m <traffic_sign>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Sign_Type-val is deprecated.  Use project_s_msgs-msg:Sign_Type instead.")
  (Sign_Type m))

(cl:ensure-generic-function 'Value-val :lambda-list '(m))
(cl:defmethod Value-val ((m <traffic_sign>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Value-val is deprecated.  Use project_s_msgs-msg:Value instead.")
  (Value m))

(cl:ensure-generic-function 'Lane-val :lambda-list '(m))
(cl:defmethod Lane-val ((m <traffic_sign>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Lane-val is deprecated.  Use project_s_msgs-msg:Lane instead.")
  (Lane m))

(cl:ensure-generic-function 'Sign_Location-val :lambda-list '(m))
(cl:defmethod Sign_Location-val ((m <traffic_sign>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Sign_Location-val is deprecated.  Use project_s_msgs-msg:Sign_Location instead.")
  (Sign_Location m))

(cl:ensure-generic-function 'latitude-val :lambda-list '(m))
(cl:defmethod latitude-val ((m <traffic_sign>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:latitude-val is deprecated.  Use project_s_msgs-msg:latitude instead.")
  (latitude m))

(cl:ensure-generic-function 'longitude-val :lambda-list '(m))
(cl:defmethod longitude-val ((m <traffic_sign>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:longitude-val is deprecated.  Use project_s_msgs-msg:longitude instead.")
  (longitude m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <traffic_sign>) ostream)
  "Serializes a message object of type '<traffic_sign>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'offset))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Sign_Type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Value)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Lane)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Sign_Location)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'latitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'longitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <traffic_sign>) istream)
  "Deserializes a message object of type '<traffic_sign>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'offset) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Sign_Type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Value)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Lane)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'Sign_Location)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'latitude) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'longitude) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<traffic_sign>)))
  "Returns string type for a message object of type '<traffic_sign>"
  "project_s_msgs/traffic_sign")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'traffic_sign)))
  "Returns string type for a message object of type 'traffic_sign"
  "project_s_msgs/traffic_sign")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<traffic_sign>)))
  "Returns md5sum for a message object of type '<traffic_sign>"
  "d26397acef9db1aa738fc0768aa46dd8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'traffic_sign)))
  "Returns md5sum for a message object of type 'traffic_sign"
  "d26397acef9db1aa738fc0768aa46dd8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<traffic_sign>)))
  "Returns full string definition for message of type '<traffic_sign>"
  (cl:format cl:nil "float32 offset~%uint8 Sign_Type~%uint8 Value~%uint8 Lane~%uint8 Sign_Location~%float64 latitude~%float64 longitude~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'traffic_sign)))
  "Returns full string definition for message of type 'traffic_sign"
  (cl:format cl:nil "float32 offset~%uint8 Sign_Type~%uint8 Value~%uint8 Lane~%uint8 Sign_Location~%float64 latitude~%float64 longitude~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <traffic_sign>))
  (cl:+ 0
     4
     1
     1
     1
     1
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <traffic_sign>))
  "Converts a ROS message object to a list"
  (cl:list 'traffic_sign
    (cl:cons ':offset (offset msg))
    (cl:cons ':Sign_Type (Sign_Type msg))
    (cl:cons ':Value (Value msg))
    (cl:cons ':Lane (Lane msg))
    (cl:cons ':Sign_Location (Sign_Location msg))
    (cl:cons ':latitude (latitude msg))
    (cl:cons ':longitude (longitude msg))
))
