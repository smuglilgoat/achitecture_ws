; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude TargetSelection.msg.html

(cl:defclass <TargetSelection> (roslisp-msg-protocol:ros-message)
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
   (indexLane
    :reader indexLane
    :initarg :indexLane
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (targetDirection
    :reader targetDirection
    :initarg :targetDirection
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (targetDirectionProbability
    :reader targetDirectionProbability
    :initarg :targetDirectionProbability
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (distance
    :reader distance
    :initarg :distance
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (speed
    :reader speed
    :initarg :speed
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (timeToCollision
    :reader timeToCollision
    :initarg :timeToCollision
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32)))
)

(cl:defclass TargetSelection (<TargetSelection>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TargetSelection>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TargetSelection)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<TargetSelection> is deprecated: use project_s_msgs-msg:TargetSelection instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <TargetSelection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <TargetSelection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'indexLane-val :lambda-list '(m))
(cl:defmethod indexLane-val ((m <TargetSelection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:indexLane-val is deprecated.  Use project_s_msgs-msg:indexLane instead.")
  (indexLane m))

(cl:ensure-generic-function 'targetDirection-val :lambda-list '(m))
(cl:defmethod targetDirection-val ((m <TargetSelection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:targetDirection-val is deprecated.  Use project_s_msgs-msg:targetDirection instead.")
  (targetDirection m))

(cl:ensure-generic-function 'targetDirectionProbability-val :lambda-list '(m))
(cl:defmethod targetDirectionProbability-val ((m <TargetSelection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:targetDirectionProbability-val is deprecated.  Use project_s_msgs-msg:targetDirectionProbability instead.")
  (targetDirectionProbability m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <TargetSelection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:distance-val is deprecated.  Use project_s_msgs-msg:distance instead.")
  (distance m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <TargetSelection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:speed-val is deprecated.  Use project_s_msgs-msg:speed instead.")
  (speed m))

(cl:ensure-generic-function 'timeToCollision-val :lambda-list '(m))
(cl:defmethod timeToCollision-val ((m <TargetSelection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:timeToCollision-val is deprecated.  Use project_s_msgs-msg:timeToCollision instead.")
  (timeToCollision m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TargetSelection>) ostream)
  "Serializes a message object of type '<TargetSelection>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'indexLane) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'targetDirection) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'targetDirectionProbability) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'distance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'speed) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'timeToCollision) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TargetSelection>) istream)
  "Deserializes a message object of type '<TargetSelection>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'indexLane) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'targetDirection) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'targetDirectionProbability) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'distance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'speed) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'timeToCollision) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TargetSelection>)))
  "Returns string type for a message object of type '<TargetSelection>"
  "project_s_msgs/TargetSelection")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TargetSelection)))
  "Returns string type for a message object of type 'TargetSelection"
  "project_s_msgs/TargetSelection")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TargetSelection>)))
  "Returns md5sum for a message object of type '<TargetSelection>"
  "d3f1ac60f8428b7cd019b0bb611a0a65")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TargetSelection)))
  "Returns md5sum for a message object of type 'TargetSelection"
  "d3f1ac60f8428b7cd019b0bb611a0a65")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TargetSelection>)))
  "Returns full string definition for message of type '<TargetSelection>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 indexLane~%std_msgs/UInt8 targetDirection~%std_msgs/UInt8 targetDirectionProbability~%std_msgs/Float32 distance~%std_msgs/Float32 speed~%std_msgs/Float32 timeToCollision~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TargetSelection)))
  "Returns full string definition for message of type 'TargetSelection"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 indexLane~%std_msgs/UInt8 targetDirection~%std_msgs/UInt8 targetDirectionProbability~%std_msgs/Float32 distance~%std_msgs/Float32 speed~%std_msgs/Float32 timeToCollision~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TargetSelection>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'indexLane))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'targetDirection))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'targetDirectionProbability))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'distance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'speed))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'timeToCollision))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TargetSelection>))
  "Converts a ROS message object to a list"
  (cl:list 'TargetSelection
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':indexLane (indexLane msg))
    (cl:cons ':targetDirection (targetDirection msg))
    (cl:cons ':targetDirectionProbability (targetDirectionProbability msg))
    (cl:cons ':distance (distance msg))
    (cl:cons ':speed (speed msg))
    (cl:cons ':timeToCollision (timeToCollision msg))
))
