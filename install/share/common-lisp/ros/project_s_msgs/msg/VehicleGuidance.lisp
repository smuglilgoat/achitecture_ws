; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude VehicleGuidance.msg.html

(cl:defclass <VehicleGuidance> (roslisp-msg-protocol:ros-message)
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
   (driveBrakingTorque
    :reader driveBrakingTorque
    :initarg :driveBrakingTorque
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (steeringWheelAngle
    :reader steeringWheelAngle
    :initarg :steeringWheelAngle
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32)))
)

(cl:defclass VehicleGuidance (<VehicleGuidance>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <VehicleGuidance>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'VehicleGuidance)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<VehicleGuidance> is deprecated: use project_s_msgs-msg:VehicleGuidance instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <VehicleGuidance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <VehicleGuidance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'driveBrakingTorque-val :lambda-list '(m))
(cl:defmethod driveBrakingTorque-val ((m <VehicleGuidance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:driveBrakingTorque-val is deprecated.  Use project_s_msgs-msg:driveBrakingTorque instead.")
  (driveBrakingTorque m))

(cl:ensure-generic-function 'steeringWheelAngle-val :lambda-list '(m))
(cl:defmethod steeringWheelAngle-val ((m <VehicleGuidance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:steeringWheelAngle-val is deprecated.  Use project_s_msgs-msg:steeringWheelAngle instead.")
  (steeringWheelAngle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <VehicleGuidance>) ostream)
  "Serializes a message object of type '<VehicleGuidance>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'driveBrakingTorque) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'steeringWheelAngle) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <VehicleGuidance>) istream)
  "Deserializes a message object of type '<VehicleGuidance>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'driveBrakingTorque) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'steeringWheelAngle) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<VehicleGuidance>)))
  "Returns string type for a message object of type '<VehicleGuidance>"
  "project_s_msgs/VehicleGuidance")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'VehicleGuidance)))
  "Returns string type for a message object of type 'VehicleGuidance"
  "project_s_msgs/VehicleGuidance")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<VehicleGuidance>)))
  "Returns md5sum for a message object of type '<VehicleGuidance>"
  "a30249730ffc4cf5ea06646bfb349079")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'VehicleGuidance)))
  "Returns md5sum for a message object of type 'VehicleGuidance"
  "a30249730ffc4cf5ea06646bfb349079")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<VehicleGuidance>)))
  "Returns full string definition for message of type '<VehicleGuidance>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 driveBrakingTorque~%std_msgs/Float32 steeringWheelAngle~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'VehicleGuidance)))
  "Returns full string definition for message of type 'VehicleGuidance"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 driveBrakingTorque~%std_msgs/Float32 steeringWheelAngle~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <VehicleGuidance>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'driveBrakingTorque))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'steeringWheelAngle))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <VehicleGuidance>))
  "Converts a ROS message object to a list"
  (cl:list 'VehicleGuidance
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':driveBrakingTorque (driveBrakingTorque msg))
    (cl:cons ':steeringWheelAngle (steeringWheelAngle msg))
))
