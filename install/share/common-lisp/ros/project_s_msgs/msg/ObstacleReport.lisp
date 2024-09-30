; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ObstacleReport.msg.html

(cl:defclass <ObstacleReport> (roslisp-msg-protocol:ros-message)
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
   (GenericSmartData
    :reader GenericSmartData
    :initarg :GenericSmartData
    :type (cl:vector project_s_msgs-msg:GenericSmartData)
   :initform (cl:make-array 64 :element-type 'project_s_msgs-msg:GenericSmartData :initial-element (cl:make-instance 'project_s_msgs-msg:GenericSmartData)))
   (QtySmartData
    :reader QtySmartData
    :initarg :QtySmartData
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (dateAcquisition
    :reader dateAcquisition
    :initarg :dateAcquisition
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64))
   (odom
    :reader odom
    :initarg :odom
    :type nav_msgs-msg:Odometry
    :initform (cl:make-instance 'nav_msgs-msg:Odometry)))
)

(cl:defclass ObstacleReport (<ObstacleReport>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ObstacleReport>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ObstacleReport)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ObstacleReport> is deprecated: use project_s_msgs-msg:ObstacleReport instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ObstacleReport>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ObstacleReport>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'GenericSmartData-val :lambda-list '(m))
(cl:defmethod GenericSmartData-val ((m <ObstacleReport>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:GenericSmartData-val is deprecated.  Use project_s_msgs-msg:GenericSmartData instead.")
  (GenericSmartData m))

(cl:ensure-generic-function 'QtySmartData-val :lambda-list '(m))
(cl:defmethod QtySmartData-val ((m <ObstacleReport>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:QtySmartData-val is deprecated.  Use project_s_msgs-msg:QtySmartData instead.")
  (QtySmartData m))

(cl:ensure-generic-function 'dateAcquisition-val :lambda-list '(m))
(cl:defmethod dateAcquisition-val ((m <ObstacleReport>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:dateAcquisition-val is deprecated.  Use project_s_msgs-msg:dateAcquisition instead.")
  (dateAcquisition m))

(cl:ensure-generic-function 'odom-val :lambda-list '(m))
(cl:defmethod odom-val ((m <ObstacleReport>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:odom-val is deprecated.  Use project_s_msgs-msg:odom instead.")
  (odom m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ObstacleReport>) ostream)
  "Serializes a message object of type '<ObstacleReport>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'GenericSmartData))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'QtySmartData) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'dateAcquisition) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'odom) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ObstacleReport>) istream)
  "Deserializes a message object of type '<ObstacleReport>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (cl:setf (cl:slot-value msg 'GenericSmartData) (cl:make-array 64))
  (cl:let ((vals (cl:slot-value msg 'GenericSmartData)))
    (cl:dotimes (i 64)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:GenericSmartData))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'QtySmartData) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'dateAcquisition) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'odom) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ObstacleReport>)))
  "Returns string type for a message object of type '<ObstacleReport>"
  "project_s_msgs/ObstacleReport")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ObstacleReport)))
  "Returns string type for a message object of type 'ObstacleReport"
  "project_s_msgs/ObstacleReport")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ObstacleReport>)))
  "Returns md5sum for a message object of type '<ObstacleReport>"
  "d66d512738eec8e99605306c6e973be5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ObstacleReport)))
  "Returns md5sum for a message object of type 'ObstacleReport"
  "d66d512738eec8e99605306c6e973be5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ObstacleReport>)))
  "Returns full string definition for message of type '<ObstacleReport>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%project_s_msgs/GenericSmartData[64] GenericSmartData		#GenericSmartData array   ~%std_msgs/UInt8 QtySmartData~%std_msgs/Float64 dateAcquisition~%nav_msgs/Odometry odom~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/GenericSmartData~%Header header~%std_msgs/UInt16 id~%~%geometry_msgs/Pose obstaclePosition		# obstacle position~%geometry_msgs/Twist obstacleVelocity		# obstacle speed~%geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration~%geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height~%geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance~%geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance~%~%uint8 OBSTACLE_CLASS_NONE = 0~%uint8 OBSTACLE_CLASS_SIGN = 1~%uint8 OBSTACLE_CLASS_PLOT = 2~%uint8 OBSTACLE_CLASS_INVALID = 255~%uint8 obstacleClass~%~%uint8 vision_only_sign_type~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ObstacleReport)))
  "Returns full string definition for message of type 'ObstacleReport"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%project_s_msgs/GenericSmartData[64] GenericSmartData		#GenericSmartData array   ~%std_msgs/UInt8 QtySmartData~%std_msgs/Float64 dateAcquisition~%nav_msgs/Odometry odom~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/GenericSmartData~%Header header~%std_msgs/UInt16 id~%~%geometry_msgs/Pose obstaclePosition		# obstacle position~%geometry_msgs/Twist obstacleVelocity		# obstacle speed~%geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration~%geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height~%geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance~%geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance~%~%uint8 OBSTACLE_CLASS_NONE = 0~%uint8 OBSTACLE_CLASS_SIGN = 1~%uint8 OBSTACLE_CLASS_PLOT = 2~%uint8 OBSTACLE_CLASS_INVALID = 255~%uint8 obstacleClass~%~%uint8 vision_only_sign_type~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ObstacleReport>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'GenericSmartData) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'QtySmartData))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'dateAcquisition))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'odom))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ObstacleReport>))
  "Converts a ROS message object to a list"
  (cl:list 'ObstacleReport
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':GenericSmartData (GenericSmartData msg))
    (cl:cons ':QtySmartData (QtySmartData msg))
    (cl:cons ':dateAcquisition (dateAcquisition msg))
    (cl:cons ':odom (odom msg))
))
