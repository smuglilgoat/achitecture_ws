; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude Balise.msg.html

(cl:defclass <Balise> (roslisp-msg-protocol:ros-message)
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
   (position
    :reader position
    :initarg :position
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (class
    :reader class
    :initarg :class
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8)))
)

(cl:defclass Balise (<Balise>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Balise>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Balise)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<Balise> is deprecated: use project_s_msgs-msg:Balise instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Balise>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <Balise>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <Balise>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:position-val is deprecated.  Use project_s_msgs-msg:position instead.")
  (position m))

(cl:ensure-generic-function 'class-val :lambda-list '(m))
(cl:defmethod class-val ((m <Balise>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:class-val is deprecated.  Use project_s_msgs-msg:class instead.")
  (class m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Balise>) ostream)
  "Serializes a message object of type '<Balise>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'position) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'class) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Balise>) istream)
  "Deserializes a message object of type '<Balise>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'position) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'class) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Balise>)))
  "Returns string type for a message object of type '<Balise>"
  "project_s_msgs/Balise")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Balise)))
  "Returns string type for a message object of type 'Balise"
  "project_s_msgs/Balise")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Balise>)))
  "Returns md5sum for a message object of type '<Balise>"
  "44e07a8e3f62d9f2c79894367aa4ccba")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Balise)))
  "Returns md5sum for a message object of type 'Balise"
  "44e07a8e3f62d9f2c79894367aa4ccba")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Balise>)))
  "Returns full string definition for message of type '<Balise>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Pose position~%std_msgs/UInt8 class~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Balise)))
  "Returns full string definition for message of type 'Balise"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Pose position~%std_msgs/UInt8 class~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Balise>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'position))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'class))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Balise>))
  "Converts a ROS message object to a list"
  (cl:list 'Balise
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':position (position msg))
    (cl:cons ':class (class msg))
))
