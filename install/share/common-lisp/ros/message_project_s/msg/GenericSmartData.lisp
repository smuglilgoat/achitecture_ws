; Auto-generated. Do not edit!


(cl:in-package message_project_s-msg)


;//! \htmlinclude GenericSmartData.msg.html

(cl:defclass <GenericSmartData> (roslisp-msg-protocol:ros-message)
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
   (obstaclePosition
    :reader obstaclePosition
    :initarg :obstaclePosition
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (obstacleVelocity
    :reader obstacleVelocity
    :initarg :obstacleVelocity
    :type geometry_msgs-msg:Twist
    :initform (cl:make-instance 'geometry_msgs-msg:Twist))
   (obstacleAcceleration
    :reader obstacleAcceleration
    :initarg :obstacleAcceleration
    :type geometry_msgs-msg:Accel
    :initform (cl:make-instance 'geometry_msgs-msg:Accel))
   (obstacleDimensions
    :reader obstacleDimensions
    :initarg :obstacleDimensions
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (obstaclePoseVariance
    :reader obstaclePoseVariance
    :initarg :obstaclePoseVariance
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (obstacleVelocityVariance
    :reader obstacleVelocityVariance
    :initarg :obstacleVelocityVariance
    :type geometry_msgs-msg:Twist
    :initform (cl:make-instance 'geometry_msgs-msg:Twist))
   (obstacleClass
    :reader obstacleClass
    :initarg :obstacleClass
    :type cl:fixnum
    :initform 0)
   (vision_only_sign_type
    :reader vision_only_sign_type
    :initarg :vision_only_sign_type
    :type cl:fixnum
    :initform 0))
)

(cl:defclass GenericSmartData (<GenericSmartData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GenericSmartData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GenericSmartData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name message_project_s-msg:<GenericSmartData> is deprecated: use message_project_s-msg:GenericSmartData instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <GenericSmartData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:header-val is deprecated.  Use message_project_s-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <GenericSmartData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:id-val is deprecated.  Use message_project_s-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'obstaclePosition-val :lambda-list '(m))
(cl:defmethod obstaclePosition-val ((m <GenericSmartData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:obstaclePosition-val is deprecated.  Use message_project_s-msg:obstaclePosition instead.")
  (obstaclePosition m))

(cl:ensure-generic-function 'obstacleVelocity-val :lambda-list '(m))
(cl:defmethod obstacleVelocity-val ((m <GenericSmartData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:obstacleVelocity-val is deprecated.  Use message_project_s-msg:obstacleVelocity instead.")
  (obstacleVelocity m))

(cl:ensure-generic-function 'obstacleAcceleration-val :lambda-list '(m))
(cl:defmethod obstacleAcceleration-val ((m <GenericSmartData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:obstacleAcceleration-val is deprecated.  Use message_project_s-msg:obstacleAcceleration instead.")
  (obstacleAcceleration m))

(cl:ensure-generic-function 'obstacleDimensions-val :lambda-list '(m))
(cl:defmethod obstacleDimensions-val ((m <GenericSmartData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:obstacleDimensions-val is deprecated.  Use message_project_s-msg:obstacleDimensions instead.")
  (obstacleDimensions m))

(cl:ensure-generic-function 'obstaclePoseVariance-val :lambda-list '(m))
(cl:defmethod obstaclePoseVariance-val ((m <GenericSmartData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:obstaclePoseVariance-val is deprecated.  Use message_project_s-msg:obstaclePoseVariance instead.")
  (obstaclePoseVariance m))

(cl:ensure-generic-function 'obstacleVelocityVariance-val :lambda-list '(m))
(cl:defmethod obstacleVelocityVariance-val ((m <GenericSmartData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:obstacleVelocityVariance-val is deprecated.  Use message_project_s-msg:obstacleVelocityVariance instead.")
  (obstacleVelocityVariance m))

(cl:ensure-generic-function 'obstacleClass-val :lambda-list '(m))
(cl:defmethod obstacleClass-val ((m <GenericSmartData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:obstacleClass-val is deprecated.  Use message_project_s-msg:obstacleClass instead.")
  (obstacleClass m))

(cl:ensure-generic-function 'vision_only_sign_type-val :lambda-list '(m))
(cl:defmethod vision_only_sign_type-val ((m <GenericSmartData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:vision_only_sign_type-val is deprecated.  Use message_project_s-msg:vision_only_sign_type instead.")
  (vision_only_sign_type m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<GenericSmartData>)))
    "Constants for message type '<GenericSmartData>"
  '((:OBSTACLE_CLASS_NONE . 0)
    (:OBSTACLE_CLASS_SIGN . 1)
    (:OBSTACLE_CLASS_PLOT . 2)
    (:OBSTACLE_CLASS_INVALID . 255))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'GenericSmartData)))
    "Constants for message type 'GenericSmartData"
  '((:OBSTACLE_CLASS_NONE . 0)
    (:OBSTACLE_CLASS_SIGN . 1)
    (:OBSTACLE_CLASS_PLOT . 2)
    (:OBSTACLE_CLASS_INVALID . 255))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GenericSmartData>) ostream)
  "Serializes a message object of type '<GenericSmartData>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstaclePosition) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleVelocity) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleAcceleration) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleDimensions) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstaclePoseVariance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleVelocityVariance) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleClass)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vision_only_sign_type)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GenericSmartData>) istream)
  "Deserializes a message object of type '<GenericSmartData>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstaclePosition) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleVelocity) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleAcceleration) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleDimensions) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstaclePoseVariance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleVelocityVariance) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleClass)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vision_only_sign_type)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GenericSmartData>)))
  "Returns string type for a message object of type '<GenericSmartData>"
  "message_project_s/GenericSmartData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GenericSmartData)))
  "Returns string type for a message object of type 'GenericSmartData"
  "message_project_s/GenericSmartData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GenericSmartData>)))
  "Returns md5sum for a message object of type '<GenericSmartData>"
  "79cccb639db4b52ccd3188161e904867")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GenericSmartData)))
  "Returns md5sum for a message object of type 'GenericSmartData"
  "79cccb639db4b52ccd3188161e904867")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GenericSmartData>)))
  "Returns full string definition for message of type '<GenericSmartData>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Pose obstaclePosition		# obstacle position~%geometry_msgs/Twist obstacleVelocity		# obstacle speed~%geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration~%geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height~%geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance~%geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance~%~%uint8 OBSTACLE_CLASS_NONE = 0~%uint8 OBSTACLE_CLASS_SIGN = 1~%uint8 OBSTACLE_CLASS_PLOT = 2~%uint8 OBSTACLE_CLASS_INVALID = 255~%uint8 obstacleClass~%~%uint8 vision_only_sign_type~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GenericSmartData)))
  "Returns full string definition for message of type 'GenericSmartData"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Pose obstaclePosition		# obstacle position~%geometry_msgs/Twist obstacleVelocity		# obstacle speed~%geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration~%geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height~%geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance~%geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance~%~%uint8 OBSTACLE_CLASS_NONE = 0~%uint8 OBSTACLE_CLASS_SIGN = 1~%uint8 OBSTACLE_CLASS_PLOT = 2~%uint8 OBSTACLE_CLASS_INVALID = 255~%uint8 obstacleClass~%~%uint8 vision_only_sign_type~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GenericSmartData>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstaclePosition))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleVelocity))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleAcceleration))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleDimensions))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstaclePoseVariance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleVelocityVariance))
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GenericSmartData>))
  "Converts a ROS message object to a list"
  (cl:list 'GenericSmartData
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':obstaclePosition (obstaclePosition msg))
    (cl:cons ':obstacleVelocity (obstacleVelocity msg))
    (cl:cons ':obstacleAcceleration (obstacleAcceleration msg))
    (cl:cons ':obstacleDimensions (obstacleDimensions msg))
    (cl:cons ':obstaclePoseVariance (obstaclePoseVariance msg))
    (cl:cons ':obstacleVelocityVariance (obstacleVelocityVariance msg))
    (cl:cons ':obstacleClass (obstacleClass msg))
    (cl:cons ':vision_only_sign_type (vision_only_sign_type msg))
))
