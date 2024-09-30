; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude speed_limit.msg.html

(cl:defclass <speed_limit> (roslisp-msg-protocol:ros-message)
  ((offset
    :reader offset
    :initarg :offset
    :type cl:float
    :initform 0.0)
   (effectiveSpeedLimit
    :reader effectiveSpeedLimit
    :initarg :effectiveSpeedLimit
    :type cl:fixnum
    :initform 0))
)

(cl:defclass speed_limit (<speed_limit>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <speed_limit>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'speed_limit)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<speed_limit> is deprecated: use project_s_msgs-msg:speed_limit instead.")))

(cl:ensure-generic-function 'offset-val :lambda-list '(m))
(cl:defmethod offset-val ((m <speed_limit>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offset-val is deprecated.  Use project_s_msgs-msg:offset instead.")
  (offset m))

(cl:ensure-generic-function 'effectiveSpeedLimit-val :lambda-list '(m))
(cl:defmethod effectiveSpeedLimit-val ((m <speed_limit>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:effectiveSpeedLimit-val is deprecated.  Use project_s_msgs-msg:effectiveSpeedLimit instead.")
  (effectiveSpeedLimit m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <speed_limit>) ostream)
  "Serializes a message object of type '<speed_limit>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'offset))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'effectiveSpeedLimit)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <speed_limit>) istream)
  "Deserializes a message object of type '<speed_limit>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'offset) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'effectiveSpeedLimit)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<speed_limit>)))
  "Returns string type for a message object of type '<speed_limit>"
  "project_s_msgs/speed_limit")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'speed_limit)))
  "Returns string type for a message object of type 'speed_limit"
  "project_s_msgs/speed_limit")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<speed_limit>)))
  "Returns md5sum for a message object of type '<speed_limit>"
  "56f584c5e8b035f849b17a33fc0e3dfd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'speed_limit)))
  "Returns md5sum for a message object of type 'speed_limit"
  "56f584c5e8b035f849b17a33fc0e3dfd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<speed_limit>)))
  "Returns full string definition for message of type '<speed_limit>"
  (cl:format cl:nil "float32 offset~%uint8 effectiveSpeedLimit~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'speed_limit)))
  "Returns full string definition for message of type 'speed_limit"
  (cl:format cl:nil "float32 offset~%uint8 effectiveSpeedLimit~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <speed_limit>))
  (cl:+ 0
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <speed_limit>))
  "Converts a ROS message object to a list"
  (cl:list 'speed_limit
    (cl:cons ':offset (offset msg))
    (cl:cons ':effectiveSpeedLimit (effectiveSpeedLimit msg))
))
