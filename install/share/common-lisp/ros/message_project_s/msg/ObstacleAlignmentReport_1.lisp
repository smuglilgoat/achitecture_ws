; Auto-generated. Do not edit!


(cl:in-package message_project_s-msg)


;//! \htmlinclude ObstacleAlignmentReport_1.msg.html

(cl:defclass <ObstacleAlignmentReport_1> (roslisp-msg-protocol:ros-message)
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
   (ObstacleAlignement_1
    :reader ObstacleAlignement_1
    :initarg :ObstacleAlignement_1
    :type (cl:vector message_project_s-msg:ObstacleAlignment_1)
   :initform (cl:make-array 0 :element-type 'message_project_s-msg:ObstacleAlignment_1 :initial-element (cl:make-instance 'message_project_s-msg:ObstacleAlignment_1)))
   (QtyObstacles
    :reader QtyObstacles
    :initarg :QtyObstacles
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (odom
    :reader odom
    :initarg :odom
    :type nav_msgs-msg:Odometry
    :initform (cl:make-instance 'nav_msgs-msg:Odometry)))
)

(cl:defclass ObstacleAlignmentReport_1 (<ObstacleAlignmentReport_1>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ObstacleAlignmentReport_1>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ObstacleAlignmentReport_1)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name message_project_s-msg:<ObstacleAlignmentReport_1> is deprecated: use message_project_s-msg:ObstacleAlignmentReport_1 instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ObstacleAlignmentReport_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:header-val is deprecated.  Use message_project_s-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ObstacleAlignmentReport_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:id-val is deprecated.  Use message_project_s-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'ObstacleAlignement_1-val :lambda-list '(m))
(cl:defmethod ObstacleAlignement_1-val ((m <ObstacleAlignmentReport_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:ObstacleAlignement_1-val is deprecated.  Use message_project_s-msg:ObstacleAlignement_1 instead.")
  (ObstacleAlignement_1 m))

(cl:ensure-generic-function 'QtyObstacles-val :lambda-list '(m))
(cl:defmethod QtyObstacles-val ((m <ObstacleAlignmentReport_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:QtyObstacles-val is deprecated.  Use message_project_s-msg:QtyObstacles instead.")
  (QtyObstacles m))

(cl:ensure-generic-function 'odom-val :lambda-list '(m))
(cl:defmethod odom-val ((m <ObstacleAlignmentReport_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:odom-val is deprecated.  Use message_project_s-msg:odom instead.")
  (odom m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ObstacleAlignmentReport_1>) ostream)
  "Serializes a message object of type '<ObstacleAlignmentReport_1>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'ObstacleAlignement_1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ObstacleAlignement_1))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'QtyObstacles) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'odom) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ObstacleAlignmentReport_1>) istream)
  "Deserializes a message object of type '<ObstacleAlignmentReport_1>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'ObstacleAlignement_1) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'ObstacleAlignement_1)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'message_project_s-msg:ObstacleAlignment_1))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'QtyObstacles) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'odom) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ObstacleAlignmentReport_1>)))
  "Returns string type for a message object of type '<ObstacleAlignmentReport_1>"
  "message_project_s/ObstacleAlignmentReport_1")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ObstacleAlignmentReport_1)))
  "Returns string type for a message object of type 'ObstacleAlignmentReport_1"
  "message_project_s/ObstacleAlignmentReport_1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ObstacleAlignmentReport_1>)))
  "Returns md5sum for a message object of type '<ObstacleAlignmentReport_1>"
  "4857983c7466f8b6a84b30dd769dde24")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ObstacleAlignmentReport_1)))
  "Returns md5sum for a message object of type 'ObstacleAlignmentReport_1"
  "4857983c7466f8b6a84b30dd769dde24")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ObstacleAlignmentReport_1>)))
  "Returns full string definition for message of type '<ObstacleAlignmentReport_1>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%message_project_s/ObstacleAlignment_1[] ObstacleAlignement_1~%~%std_msgs/UInt8 QtyObstacles~%nav_msgs/Odometry odom~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: message_project_s/ObstacleAlignment_1~%Header header~%std_msgs/UInt16 id~%~%geometry_msgs/Pose obstaclePosition	        		# obstacle position~%float64 obstaclePosition_linear_Unknown = 999~%float64 obstaclePosition_orientation_Unknown = 999~%~%geometry_msgs/Pose obstacleBodyCenter	        		# Obstacle Center for Corner Computation~%~%geometry_msgs/Twist obstacleVelocity	                    	# obstacle speed~%float64 obstacleVelocity_linear_Unknown = 999~%float64 obstacleVelocity_angular_Unknown = 999~%~%geometry_msgs/Twist obstacleRelativeVelocity	           	# obstacle relative velocity~%float64 obstacleRelativeVelocity_linear_Unknown = 999~%float64 obstacleRelativeVelocity_angular_Unknown = 999~%~%geometry_msgs/Accel obstacleAcceleration        		# obstacle acceleration~%float64 obstacleAcceleration_linear_Unknown = 999~%float64 obstacleAcceleration_angular_Unknown = 999~%~%geometry_msgs/Vector3 obstacleDimensions        		# obstacle - length and width~%float64 obstacleDimensions_Unknown = 999~%~%uint8 blinkerInfo                               		# blinker status (eg. left blinker on)~%uint8 blinkerInfo_Unknown=0~%~%uint8 cutInAndOut                               		# Vehicle cutting in or out of ego lane ~%uint8 cutInAndOut_Unknown=0~%~%uint8 obstacleType                             			# obstacle classification~%uint8 obstacleType_Unknown=7~%~%uint8 obstacleStatus                            		# obstacle’s moving status~%uint8 obstacleStatus_Unknown=0~%~%bool obstacleBrakeLights                        		# obstacle brake light on or off~%bool obstacleBrakeLights_Unknown=0 ~%~%int8 cipvFlag                                   		# If obstacle Closest in Path Vehicle~%int8 cipvFlag_Unknown=2~%~%int8 obstacleReplaced                           		# If obstacle replaced in this frame~%int8 obstacleReplaced_Unknown=2~%~%uint8 obstacleValid                             		# obstacle valid~%uint8 obstacleValid_Unknown=3~%~%uint16 obstacleAge                              		# obstacle age in number of frames~%uint16 obstacleAge_Unknown=256~%~%uint8 obstacleLane                              		# obstacle's lane (eg. ego lane or next lane)~%uint8 obstacleLane_Unknown=0~%~%float32 obstacleAngle                           		# angle to center of obstacle in degrees~%float32 obstacleAngle_Unknown = 999~%~%float32 obstacleAngleVariance                   		# Obstacle angle Variance (Lidar)~%float32 obstacleAngleVariance_Unknown=-1~%~%float32 obstacleAngleRate                       		# angle rate of the center of obstacle (degrees/sec)~%float32 obstacleAngleRate_Unknown = 999~%~%float64 obstacleScaleChange                     		# scale change from previous frame   ~%float64 obstacleScaleChange_Unknown = 999~%                           ~%uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type~%uint8 visionOnlySignType_Unknown=254~%~%uint8 visionOnlySupplementarySignType               		# Supplementary sign type - rain, snow, arrow etc. ~%uint8 visionOnlySupplementarySignType_Unknown=0~%~%geometry_msgs/Vector3 signPosition                  		# X-Longitudnal position, Y-Lateral position ,Z-Height of sign relative to ME~%float64 signPosition_Unknown = 999~%~%float64 filterType                                    		# filtering ~%float64 filterType_Unknown = 999~%~%geometry_msgs/Pose obstaclePoseVariance		                # obstacle position variance~%float64 obstaclePoseVariance_position_Unknown = -1~%float64 obstaclePoseVariance_orientation_Unknown = -1~%~%geometry_msgs/Twist obstacleVelocityVariance	                # obstacle speed variance~%float64 obstacleVelocityVariance_linear_Unknown = -1~%float64 obstacleVelocityVariance_angular_Unknown = -1~%~%geometry_msgs/Twist obstacleRelativeVelocityVariance	        # obstacle relative velocity variance~%float64 obstacleRelativeVelocityVariance_linear_Unknown = -1~%float64 obstacleRelativeVelocityVariance_angular_Unknown = -1~%~%std_msgs/Float32 groundHeight			                # ground height~%float64 groundHeight_Unknown = 999~%~%float64 classificationProbability~%float64 classificationProbability_Unknown = 999~%~%std_msgs/Float64 dateAcquisition~%float64 dateAcquisition_Unknown = 999~%~%~%# History~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ObstacleAlignmentReport_1)))
  "Returns full string definition for message of type 'ObstacleAlignmentReport_1"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%message_project_s/ObstacleAlignment_1[] ObstacleAlignement_1~%~%std_msgs/UInt8 QtyObstacles~%nav_msgs/Odometry odom~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: message_project_s/ObstacleAlignment_1~%Header header~%std_msgs/UInt16 id~%~%geometry_msgs/Pose obstaclePosition	        		# obstacle position~%float64 obstaclePosition_linear_Unknown = 999~%float64 obstaclePosition_orientation_Unknown = 999~%~%geometry_msgs/Pose obstacleBodyCenter	        		# Obstacle Center for Corner Computation~%~%geometry_msgs/Twist obstacleVelocity	                    	# obstacle speed~%float64 obstacleVelocity_linear_Unknown = 999~%float64 obstacleVelocity_angular_Unknown = 999~%~%geometry_msgs/Twist obstacleRelativeVelocity	           	# obstacle relative velocity~%float64 obstacleRelativeVelocity_linear_Unknown = 999~%float64 obstacleRelativeVelocity_angular_Unknown = 999~%~%geometry_msgs/Accel obstacleAcceleration        		# obstacle acceleration~%float64 obstacleAcceleration_linear_Unknown = 999~%float64 obstacleAcceleration_angular_Unknown = 999~%~%geometry_msgs/Vector3 obstacleDimensions        		# obstacle - length and width~%float64 obstacleDimensions_Unknown = 999~%~%uint8 blinkerInfo                               		# blinker status (eg. left blinker on)~%uint8 blinkerInfo_Unknown=0~%~%uint8 cutInAndOut                               		# Vehicle cutting in or out of ego lane ~%uint8 cutInAndOut_Unknown=0~%~%uint8 obstacleType                             			# obstacle classification~%uint8 obstacleType_Unknown=7~%~%uint8 obstacleStatus                            		# obstacle’s moving status~%uint8 obstacleStatus_Unknown=0~%~%bool obstacleBrakeLights                        		# obstacle brake light on or off~%bool obstacleBrakeLights_Unknown=0 ~%~%int8 cipvFlag                                   		# If obstacle Closest in Path Vehicle~%int8 cipvFlag_Unknown=2~%~%int8 obstacleReplaced                           		# If obstacle replaced in this frame~%int8 obstacleReplaced_Unknown=2~%~%uint8 obstacleValid                             		# obstacle valid~%uint8 obstacleValid_Unknown=3~%~%uint16 obstacleAge                              		# obstacle age in number of frames~%uint16 obstacleAge_Unknown=256~%~%uint8 obstacleLane                              		# obstacle's lane (eg. ego lane or next lane)~%uint8 obstacleLane_Unknown=0~%~%float32 obstacleAngle                           		# angle to center of obstacle in degrees~%float32 obstacleAngle_Unknown = 999~%~%float32 obstacleAngleVariance                   		# Obstacle angle Variance (Lidar)~%float32 obstacleAngleVariance_Unknown=-1~%~%float32 obstacleAngleRate                       		# angle rate of the center of obstacle (degrees/sec)~%float32 obstacleAngleRate_Unknown = 999~%~%float64 obstacleScaleChange                     		# scale change from previous frame   ~%float64 obstacleScaleChange_Unknown = 999~%                           ~%uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type~%uint8 visionOnlySignType_Unknown=254~%~%uint8 visionOnlySupplementarySignType               		# Supplementary sign type - rain, snow, arrow etc. ~%uint8 visionOnlySupplementarySignType_Unknown=0~%~%geometry_msgs/Vector3 signPosition                  		# X-Longitudnal position, Y-Lateral position ,Z-Height of sign relative to ME~%float64 signPosition_Unknown = 999~%~%float64 filterType                                    		# filtering ~%float64 filterType_Unknown = 999~%~%geometry_msgs/Pose obstaclePoseVariance		                # obstacle position variance~%float64 obstaclePoseVariance_position_Unknown = -1~%float64 obstaclePoseVariance_orientation_Unknown = -1~%~%geometry_msgs/Twist obstacleVelocityVariance	                # obstacle speed variance~%float64 obstacleVelocityVariance_linear_Unknown = -1~%float64 obstacleVelocityVariance_angular_Unknown = -1~%~%geometry_msgs/Twist obstacleRelativeVelocityVariance	        # obstacle relative velocity variance~%float64 obstacleRelativeVelocityVariance_linear_Unknown = -1~%float64 obstacleRelativeVelocityVariance_angular_Unknown = -1~%~%std_msgs/Float32 groundHeight			                # ground height~%float64 groundHeight_Unknown = 999~%~%float64 classificationProbability~%float64 classificationProbability_Unknown = 999~%~%std_msgs/Float64 dateAcquisition~%float64 dateAcquisition_Unknown = 999~%~%~%# History~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ObstacleAlignmentReport_1>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'ObstacleAlignement_1) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'QtyObstacles))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'odom))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ObstacleAlignmentReport_1>))
  "Converts a ROS message object to a list"
  (cl:list 'ObstacleAlignmentReport_1
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':ObstacleAlignement_1 (ObstacleAlignement_1 msg))
    (cl:cons ':QtyObstacles (QtyObstacles msg))
    (cl:cons ':odom (odom msg))
))
