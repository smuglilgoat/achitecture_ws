; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ehNbrLineCoordGeo.msg.html

(cl:defclass <ehNbrLineCoordGeo> (roslisp-msg-protocol:ros-message)
  ((Nbr
    :reader Nbr
    :initarg :Nbr
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (offset
    :reader offset
    :initarg :offset
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32)))
)

(cl:defclass ehNbrLineCoordGeo (<ehNbrLineCoordGeo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ehNbrLineCoordGeo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ehNbrLineCoordGeo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ehNbrLineCoordGeo> is deprecated: use project_s_msgs-msg:ehNbrLineCoordGeo instead.")))

(cl:ensure-generic-function 'Nbr-val :lambda-list '(m))
(cl:defmethod Nbr-val ((m <ehNbrLineCoordGeo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Nbr-val is deprecated.  Use project_s_msgs-msg:Nbr instead.")
  (Nbr m))

(cl:ensure-generic-function 'offset-val :lambda-list '(m))
(cl:defmethod offset-val ((m <ehNbrLineCoordGeo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:offset-val is deprecated.  Use project_s_msgs-msg:offset instead.")
  (offset m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ehNbrLineCoordGeo>) ostream)
  "Serializes a message object of type '<ehNbrLineCoordGeo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Nbr) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'offset) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ehNbrLineCoordGeo>) istream)
  "Deserializes a message object of type '<ehNbrLineCoordGeo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Nbr) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'offset) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ehNbrLineCoordGeo>)))
  "Returns string type for a message object of type '<ehNbrLineCoordGeo>"
  "project_s_msgs/ehNbrLineCoordGeo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ehNbrLineCoordGeo)))
  "Returns string type for a message object of type 'ehNbrLineCoordGeo"
  "project_s_msgs/ehNbrLineCoordGeo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ehNbrLineCoordGeo>)))
  "Returns md5sum for a message object of type '<ehNbrLineCoordGeo>"
  "ba129a5215116e7dd0de7b78069aec8a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ehNbrLineCoordGeo)))
  "Returns md5sum for a message object of type 'ehNbrLineCoordGeo"
  "ba129a5215116e7dd0de7b78069aec8a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ehNbrLineCoordGeo>)))
  "Returns full string definition for message of type '<ehNbrLineCoordGeo>"
  (cl:format cl:nil "std_msgs/UInt8 Nbr~%std_msgs/Float32 offset~%~%~%~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ehNbrLineCoordGeo)))
  "Returns full string definition for message of type 'ehNbrLineCoordGeo"
  (cl:format cl:nil "std_msgs/UInt8 Nbr~%std_msgs/Float32 offset~%~%~%~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ehNbrLineCoordGeo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Nbr))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'offset))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ehNbrLineCoordGeo>))
  "Converts a ROS message object to a list"
  (cl:list 'ehNbrLineCoordGeo
    (cl:cons ':Nbr (Nbr msg))
    (cl:cons ':offset (offset msg))
))
