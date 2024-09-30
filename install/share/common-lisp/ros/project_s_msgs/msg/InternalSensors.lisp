; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude InternalSensors.msg.html

(cl:defclass <InternalSensors> (roslisp-msg-protocol:ros-message)
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
   (vehicleleVelocity
    :reader vehicleleVelocity
    :initarg :vehicleleVelocity
    :type geometry_msgs-msg:Twist
    :initform (cl:make-instance 'geometry_msgs-msg:Twist))
   (vehicleAcceleration
    :reader vehicleAcceleration
    :initarg :vehicleAcceleration
    :type geometry_msgs-msg:Accel
    :initform (cl:make-instance 'geometry_msgs-msg:Accel))
   (steeringWheelAngle
    :reader steeringWheelAngle
    :initarg :steeringWheelAngle
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (timeStamp
    :reader timeStamp
    :initarg :timeStamp
    :type std_msgs-msg:UInt64
    :initform (cl:make-instance 'std_msgs-msg:UInt64)))
)

(cl:defclass InternalSensors (<InternalSensors>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <InternalSensors>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'InternalSensors)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<InternalSensors> is deprecated: use project_s_msgs-msg:InternalSensors instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <InternalSensors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <InternalSensors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'vehicleleVelocity-val :lambda-list '(m))
(cl:defmethod vehicleleVelocity-val ((m <InternalSensors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:vehicleleVelocity-val is deprecated.  Use project_s_msgs-msg:vehicleleVelocity instead.")
  (vehicleleVelocity m))

(cl:ensure-generic-function 'vehicleAcceleration-val :lambda-list '(m))
(cl:defmethod vehicleAcceleration-val ((m <InternalSensors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:vehicleAcceleration-val is deprecated.  Use project_s_msgs-msg:vehicleAcceleration instead.")
  (vehicleAcceleration m))

(cl:ensure-generic-function 'steeringWheelAngle-val :lambda-list '(m))
(cl:defmethod steeringWheelAngle-val ((m <InternalSensors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:steeringWheelAngle-val is deprecated.  Use project_s_msgs-msg:steeringWheelAngle instead.")
  (steeringWheelAngle m))

(cl:ensure-generic-function 'timeStamp-val :lambda-list '(m))
(cl:defmethod timeStamp-val ((m <InternalSensors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:timeStamp-val is deprecated.  Use project_s_msgs-msg:timeStamp instead.")
  (timeStamp m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <InternalSensors>) ostream)
  "Serializes a message object of type '<InternalSensors>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vehicleleVelocity) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vehicleAcceleration) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'steeringWheelAngle) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'timeStamp) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <InternalSensors>) istream)
  "Deserializes a message object of type '<InternalSensors>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vehicleleVelocity) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vehicleAcceleration) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'steeringWheelAngle) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'timeStamp) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<InternalSensors>)))
  "Returns string type for a message object of type '<InternalSensors>"
  "project_s_msgs/InternalSensors")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'InternalSensors)))
  "Returns string type for a message object of type 'InternalSensors"
  "project_s_msgs/InternalSensors")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<InternalSensors>)))
  "Returns md5sum for a message object of type '<InternalSensors>"
  "c7afa49d12086db3055945e1a8731d66")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'InternalSensors)))
  "Returns md5sum for a message object of type 'InternalSensors"
  "c7afa49d12086db3055945e1a8731d66")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<InternalSensors>)))
  "Returns full string definition for message of type '<InternalSensors>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Twist vehicleleVelocity~%geometry_msgs/Accel vehicleAcceleration~%std_msgs/Float32 steeringWheelAngle~%std_msgs/UInt64 timeStamp~%~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/UInt64~%uint64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'InternalSensors)))
  "Returns full string definition for message of type 'InternalSensors"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Twist vehicleleVelocity~%geometry_msgs/Accel vehicleAcceleration~%std_msgs/Float32 steeringWheelAngle~%std_msgs/UInt64 timeStamp~%~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/UInt64~%uint64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <InternalSensors>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vehicleleVelocity))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vehicleAcceleration))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'steeringWheelAngle))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'timeStamp))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <InternalSensors>))
  "Converts a ROS message object to a list"
  (cl:list 'InternalSensors
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':vehicleleVelocity (vehicleleVelocity msg))
    (cl:cons ':vehicleAcceleration (vehicleAcceleration msg))
    (cl:cons ':steeringWheelAngle (steeringWheelAngle msg))
    (cl:cons ':timeStamp (timeStamp msg))
))
