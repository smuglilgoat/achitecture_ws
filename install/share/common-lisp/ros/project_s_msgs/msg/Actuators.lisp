; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude Actuators.msg.html

(cl:defclass <Actuators> (roslisp-msg-protocol:ros-message)
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
   (Accelerator
    :reader Accelerator
    :initarg :Accelerator
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (brakePressure
    :reader brakePressure
    :initarg :brakePressure
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (steeringAngle
    :reader steeringAngle
    :initarg :steeringAngle
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32)))
)

(cl:defclass Actuators (<Actuators>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Actuators>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Actuators)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<Actuators> is deprecated: use project_s_msgs-msg:Actuators instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Actuators>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <Actuators>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'Accelerator-val :lambda-list '(m))
(cl:defmethod Accelerator-val ((m <Actuators>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:Accelerator-val is deprecated.  Use project_s_msgs-msg:Accelerator instead.")
  (Accelerator m))

(cl:ensure-generic-function 'brakePressure-val :lambda-list '(m))
(cl:defmethod brakePressure-val ((m <Actuators>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:brakePressure-val is deprecated.  Use project_s_msgs-msg:brakePressure instead.")
  (brakePressure m))

(cl:ensure-generic-function 'steeringAngle-val :lambda-list '(m))
(cl:defmethod steeringAngle-val ((m <Actuators>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:steeringAngle-val is deprecated.  Use project_s_msgs-msg:steeringAngle instead.")
  (steeringAngle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Actuators>) ostream)
  "Serializes a message object of type '<Actuators>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Accelerator) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'brakePressure) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'steeringAngle) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Actuators>) istream)
  "Deserializes a message object of type '<Actuators>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Accelerator) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'brakePressure) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'steeringAngle) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Actuators>)))
  "Returns string type for a message object of type '<Actuators>"
  "project_s_msgs/Actuators")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Actuators)))
  "Returns string type for a message object of type 'Actuators"
  "project_s_msgs/Actuators")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Actuators>)))
  "Returns md5sum for a message object of type '<Actuators>"
  "94218c4fc10da9425fa7248c8f707ac5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Actuators)))
  "Returns md5sum for a message object of type 'Actuators"
  "94218c4fc10da9425fa7248c8f707ac5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Actuators>)))
  "Returns full string definition for message of type '<Actuators>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 Accelerator~%std_msgs/Float32 brakePressure~%std_msgs/Float32 steeringAngle~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Actuators)))
  "Returns full string definition for message of type 'Actuators"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 Accelerator~%std_msgs/Float32 brakePressure~%std_msgs/Float32 steeringAngle~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Actuators>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Accelerator))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'brakePressure))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'steeringAngle))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Actuators>))
  "Converts a ROS message object to a list"
  (cl:list 'Actuators
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':Accelerator (Accelerator msg))
    (cl:cons ':brakePressure (brakePressure msg))
    (cl:cons ':steeringAngle (steeringAngle msg))
))
