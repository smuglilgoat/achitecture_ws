; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ObstacleFusionReportComplet.msg.html

(cl:defclass <ObstacleFusionReportComplet> (roslisp-msg-protocol:ros-message)
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
   (reportObstacleFusionGlobale
    :reader reportObstacleFusionGlobale
    :initarg :reportObstacleFusionGlobale
    :type project_s_msgs-msg:ObstacleFusionReport
    :initform (cl:make-instance 'project_s_msgs-msg:ObstacleFusionReport))
   (reportObstacleFusion
    :reader reportObstacleFusion
    :initarg :reportObstacleFusion
    :type project_s_msgs-msg:ObstacleFusionReport
    :initform (cl:make-instance 'project_s_msgs-msg:ObstacleFusionReport))
   (predictionPisteGlobale
    :reader predictionPisteGlobale
    :initarg :predictionPisteGlobale
    :type project_s_msgs-msg:ObstacleFusionReport
    :initform (cl:make-instance 'project_s_msgs-msg:ObstacleFusionReport)))
)

(cl:defclass ObstacleFusionReportComplet (<ObstacleFusionReportComplet>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ObstacleFusionReportComplet>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ObstacleFusionReportComplet)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ObstacleFusionReportComplet> is deprecated: use project_s_msgs-msg:ObstacleFusionReportComplet instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ObstacleFusionReportComplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ObstacleFusionReportComplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'reportObstacleFusionGlobale-val :lambda-list '(m))
(cl:defmethod reportObstacleFusionGlobale-val ((m <ObstacleFusionReportComplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:reportObstacleFusionGlobale-val is deprecated.  Use project_s_msgs-msg:reportObstacleFusionGlobale instead.")
  (reportObstacleFusionGlobale m))

(cl:ensure-generic-function 'reportObstacleFusion-val :lambda-list '(m))
(cl:defmethod reportObstacleFusion-val ((m <ObstacleFusionReportComplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:reportObstacleFusion-val is deprecated.  Use project_s_msgs-msg:reportObstacleFusion instead.")
  (reportObstacleFusion m))

(cl:ensure-generic-function 'predictionPisteGlobale-val :lambda-list '(m))
(cl:defmethod predictionPisteGlobale-val ((m <ObstacleFusionReportComplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:predictionPisteGlobale-val is deprecated.  Use project_s_msgs-msg:predictionPisteGlobale instead.")
  (predictionPisteGlobale m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ObstacleFusionReportComplet>) ostream)
  "Serializes a message object of type '<ObstacleFusionReportComplet>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'reportObstacleFusionGlobale) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'reportObstacleFusion) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'predictionPisteGlobale) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ObstacleFusionReportComplet>) istream)
  "Deserializes a message object of type '<ObstacleFusionReportComplet>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'reportObstacleFusionGlobale) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'reportObstacleFusion) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'predictionPisteGlobale) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ObstacleFusionReportComplet>)))
  "Returns string type for a message object of type '<ObstacleFusionReportComplet>"
  "project_s_msgs/ObstacleFusionReportComplet")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ObstacleFusionReportComplet)))
  "Returns string type for a message object of type 'ObstacleFusionReportComplet"
  "project_s_msgs/ObstacleFusionReportComplet")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ObstacleFusionReportComplet>)))
  "Returns md5sum for a message object of type '<ObstacleFusionReportComplet>"
  "188bbeb788eb767b2b450aba68ba2cb1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ObstacleFusionReportComplet)))
  "Returns md5sum for a message object of type 'ObstacleFusionReportComplet"
  "188bbeb788eb767b2b450aba68ba2cb1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ObstacleFusionReportComplet>)))
  "Returns full string definition for message of type '<ObstacleFusionReportComplet>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%project_s_msgs/ObstacleFusionReport reportObstacleFusionGlobale~%project_s_msgs/ObstacleFusionReport reportObstacleFusion~%project_s_msgs/ObstacleFusionReport predictionPisteGlobale~%~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/ObstacleFusionReport~%Header header~%std_msgs/UInt8 id~%~%uint8 OBSTACLE_FUSION_REPORT_SIZE = 127~%project_s_msgs/ObstacleFusion[127] ObstacleFusion~%std_msgs/UInt8 QtyObstacles~%nav_msgs/Odometry odom~%~%# History~%~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ObstacleFusion~%Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Pose obstaclePosition		# obstacle position~%geometry_msgs/Pose obstacleBodyCenter	        # Obstacle Center for Corner Computation~%float32 distanceCurviligne~%std_msgs/Float32 groundHeight			# ground height~%geometry_msgs/Twist obstacleVelocity		# obstacle speed~%geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration~%geometry_msgs/Vector3 obstacleCap~%std_msgs/UInt8 existenceProbability~%std_msgs/UInt8 existenceState~%uint8 IDLE_TRACK    = 0~%uint8 PRE_TRACK	    = 1~%uint8 POST_TRACK    = 2~%uint8 CURRENT_TRACK = 3~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%time existenceFirstTime~%std_msgs/Float32 existenceDurationTime~%std_msgs/UInt8 anchorPoint			# reference point~%geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance~%geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance~%geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height~%uint8 obstacleClass~%uint8 vision_only_sign_type~%std_msgs/UInt8 classificationProbability~%~%uint8 obstacleAssignment~%uint8 ASSIGNMENT_COTE_DROIT  = 1~%uint8 ASSIGNMENT_COTE_GAUCHE = 2~%~%uint8 CORNER_FRONT_RIGHT= 0~%uint8 CORNER_FRONT_LEFT = 1~%uint8 CORNER_BACK_RIGHT = 2~%uint8 CORNER_BACK_LEFT  = 3~%geometry_msgs/Point[4] obstacleCorner~%~%uint8 OCCUPIED_LANE_INDEFINI  = 255~%uint8 NbrOccupiedLane~%uint8 INDEX_LINE_INDEFINI  = 255~%uint8[2] indexAssignmentLine~%std_msgs/Float32 positionLane~%std_msgs/Float32 departureRighttDistance~%std_msgs/Float32 departureLeftDistance~%~%std_msgs/Int16 trafficLights~%std_msgs/Int16 vehicleLights~%std_msgs/UInt16[3] idPiste			#define NBR_SENSOR		3	(voir obstacles_fusion.cpp)~%~%# History~%~%~%~%~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Int16~%int16 data~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ObstacleFusionReportComplet)))
  "Returns full string definition for message of type 'ObstacleFusionReportComplet"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%project_s_msgs/ObstacleFusionReport reportObstacleFusionGlobale~%project_s_msgs/ObstacleFusionReport reportObstacleFusion~%project_s_msgs/ObstacleFusionReport predictionPisteGlobale~%~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/ObstacleFusionReport~%Header header~%std_msgs/UInt8 id~%~%uint8 OBSTACLE_FUSION_REPORT_SIZE = 127~%project_s_msgs/ObstacleFusion[127] ObstacleFusion~%std_msgs/UInt8 QtyObstacles~%nav_msgs/Odometry odom~%~%# History~%~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ObstacleFusion~%Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Pose obstaclePosition		# obstacle position~%geometry_msgs/Pose obstacleBodyCenter	        # Obstacle Center for Corner Computation~%float32 distanceCurviligne~%std_msgs/Float32 groundHeight			# ground height~%geometry_msgs/Twist obstacleVelocity		# obstacle speed~%geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration~%geometry_msgs/Vector3 obstacleCap~%std_msgs/UInt8 existenceProbability~%std_msgs/UInt8 existenceState~%uint8 IDLE_TRACK    = 0~%uint8 PRE_TRACK	    = 1~%uint8 POST_TRACK    = 2~%uint8 CURRENT_TRACK = 3~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%time existenceFirstTime~%std_msgs/Float32 existenceDurationTime~%std_msgs/UInt8 anchorPoint			# reference point~%geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance~%geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance~%geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height~%uint8 obstacleClass~%uint8 vision_only_sign_type~%std_msgs/UInt8 classificationProbability~%~%uint8 obstacleAssignment~%uint8 ASSIGNMENT_COTE_DROIT  = 1~%uint8 ASSIGNMENT_COTE_GAUCHE = 2~%~%uint8 CORNER_FRONT_RIGHT= 0~%uint8 CORNER_FRONT_LEFT = 1~%uint8 CORNER_BACK_RIGHT = 2~%uint8 CORNER_BACK_LEFT  = 3~%geometry_msgs/Point[4] obstacleCorner~%~%uint8 OCCUPIED_LANE_INDEFINI  = 255~%uint8 NbrOccupiedLane~%uint8 INDEX_LINE_INDEFINI  = 255~%uint8[2] indexAssignmentLine~%std_msgs/Float32 positionLane~%std_msgs/Float32 departureRighttDistance~%std_msgs/Float32 departureLeftDistance~%~%std_msgs/Int16 trafficLights~%std_msgs/Int16 vehicleLights~%std_msgs/UInt16[3] idPiste			#define NBR_SENSOR		3	(voir obstacles_fusion.cpp)~%~%# History~%~%~%~%~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Int16~%int16 data~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ObstacleFusionReportComplet>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'reportObstacleFusionGlobale))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'reportObstacleFusion))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'predictionPisteGlobale))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ObstacleFusionReportComplet>))
  "Converts a ROS message object to a list"
  (cl:list 'ObstacleFusionReportComplet
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':reportObstacleFusionGlobale (reportObstacleFusionGlobale msg))
    (cl:cons ':reportObstacleFusion (reportObstacleFusion msg))
    (cl:cons ':predictionPisteGlobale (predictionPisteGlobale msg))
))
