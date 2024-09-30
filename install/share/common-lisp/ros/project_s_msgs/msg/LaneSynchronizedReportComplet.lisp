; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude LaneSynchronizedReportComplet.msg.html

(cl:defclass <LaneSynchronizedReportComplet> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (laneAlignement
    :reader laneAlignement
    :initarg :laneAlignement
    :type project_s_msgs-msg:LaneAlignment
    :initform (cl:make-instance 'project_s_msgs-msg:LaneAlignment))
   (laneFusion
    :reader laneFusion
    :initarg :laneFusion
    :type project_s_msgs-msg:LaneFusion
    :initform (cl:make-instance 'project_s_msgs-msg:LaneFusion))
   (linesUpdate
    :reader linesUpdate
    :initarg :linesUpdate
    :type project_s_msgs-msg:LaneFusion
    :initform (cl:make-instance 'project_s_msgs-msg:LaneFusion)))
)

(cl:defclass LaneSynchronizedReportComplet (<LaneSynchronizedReportComplet>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LaneSynchronizedReportComplet>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LaneSynchronizedReportComplet)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<LaneSynchronizedReportComplet> is deprecated: use project_s_msgs-msg:LaneSynchronizedReportComplet instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LaneSynchronizedReportComplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'laneAlignement-val :lambda-list '(m))
(cl:defmethod laneAlignement-val ((m <LaneSynchronizedReportComplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:laneAlignement-val is deprecated.  Use project_s_msgs-msg:laneAlignement instead.")
  (laneAlignement m))

(cl:ensure-generic-function 'laneFusion-val :lambda-list '(m))
(cl:defmethod laneFusion-val ((m <LaneSynchronizedReportComplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:laneFusion-val is deprecated.  Use project_s_msgs-msg:laneFusion instead.")
  (laneFusion m))

(cl:ensure-generic-function 'linesUpdate-val :lambda-list '(m))
(cl:defmethod linesUpdate-val ((m <LaneSynchronizedReportComplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:linesUpdate-val is deprecated.  Use project_s_msgs-msg:linesUpdate instead.")
  (linesUpdate m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LaneSynchronizedReportComplet>) ostream)
  "Serializes a message object of type '<LaneSynchronizedReportComplet>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'laneAlignement) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'laneFusion) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'linesUpdate) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LaneSynchronizedReportComplet>) istream)
  "Deserializes a message object of type '<LaneSynchronizedReportComplet>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'laneAlignement) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'laneFusion) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'linesUpdate) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LaneSynchronizedReportComplet>)))
  "Returns string type for a message object of type '<LaneSynchronizedReportComplet>"
  "project_s_msgs/LaneSynchronizedReportComplet")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LaneSynchronizedReportComplet)))
  "Returns string type for a message object of type 'LaneSynchronizedReportComplet"
  "project_s_msgs/LaneSynchronizedReportComplet")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LaneSynchronizedReportComplet>)))
  "Returns md5sum for a message object of type '<LaneSynchronizedReportComplet>"
  "a30a0de87e442c4f5b3745db24215372")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LaneSynchronizedReportComplet)))
  "Returns md5sum for a message object of type 'LaneSynchronizedReportComplet"
  "a30a0de87e442c4f5b3745db24215372")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LaneSynchronizedReportComplet>)))
  "Returns full string definition for message of type '<LaneSynchronizedReportComplet>"
  (cl:format cl:nil "Header header~%~%project_s_msgs/LaneAlignment laneAlignement ~%project_s_msgs/LaneFusion laneFusion~%project_s_msgs/LaneFusion linesUpdate~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: project_s_msgs/LaneAlignment~%Header header~%std_msgs/UInt8 id~%~%#geometry_msgs/Point[250] points~%~%uint8 LINE_REPORT_SIZE = 20~%project_s_msgs/Line[20] line~%std_msgs/UInt8 QtyLine~%~%geometry_msgs/Pose lanePosition~%geometry_msgs/Pose lanePoseVariance~%std_msgs/UInt8 laneClass~%std_msgs/UInt8 classificationProbability~%std_msgs/UInt8 laneQuality~%std_msgs/UInt64 dateAcquisition~%nav_msgs/Odometry odom~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/Line~%Header header~%std_msgs/UInt8 id~%~%uint16 SEGMENT_REPORT_SIZE = 3000~%project_s_msgs/Segment[3000] segment~%std_msgs/UInt16 QtySegment~%std_msgs/Float32 lineClass	# class of the line~%std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)~%~%std_msgs/UInt8 existenceState~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%~%~%~%================================================================================~%MSG: project_s_msgs/Segment~%std_msgs/Float32 length		# length of the segment~%std_msgs/Float32 angle		# angle of the segment~%geometry_msgs/Point position~%geometry_msgs/Twist Velocity~%~%float32 offset~%float64 latitude~%float64 longitude~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/UInt64~%uint64 data~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: project_s_msgs/LaneFusion~%Header header~%std_msgs/UInt8 id~%~%#geometry_msgs/Point[250] points~%~%#uint8 LINE_REPORT_SIZE = 20~%project_s_msgs/Line[20] line~%std_msgs/UInt8 QtyLine~%~%geometry_msgs/Pose lanePosition~%geometry_msgs/Pose lanePoseVariance~%std_msgs/UInt8 laneClass~%std_msgs/UInt8 classificationProbability~%std_msgs/UInt8 laneQuality~%std_msgs/UInt8 roadBorder~%std_msgs/UInt64 dateFusion~%nav_msgs/Odometry odom~%~%# History~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LaneSynchronizedReportComplet)))
  "Returns full string definition for message of type 'LaneSynchronizedReportComplet"
  (cl:format cl:nil "Header header~%~%project_s_msgs/LaneAlignment laneAlignement ~%project_s_msgs/LaneFusion laneFusion~%project_s_msgs/LaneFusion linesUpdate~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: project_s_msgs/LaneAlignment~%Header header~%std_msgs/UInt8 id~%~%#geometry_msgs/Point[250] points~%~%uint8 LINE_REPORT_SIZE = 20~%project_s_msgs/Line[20] line~%std_msgs/UInt8 QtyLine~%~%geometry_msgs/Pose lanePosition~%geometry_msgs/Pose lanePoseVariance~%std_msgs/UInt8 laneClass~%std_msgs/UInt8 classificationProbability~%std_msgs/UInt8 laneQuality~%std_msgs/UInt64 dateAcquisition~%nav_msgs/Odometry odom~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/Line~%Header header~%std_msgs/UInt8 id~%~%uint16 SEGMENT_REPORT_SIZE = 3000~%project_s_msgs/Segment[3000] segment~%std_msgs/UInt16 QtySegment~%std_msgs/Float32 lineClass	# class of the line~%std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)~%~%std_msgs/UInt8 existenceState~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%~%~%~%================================================================================~%MSG: project_s_msgs/Segment~%std_msgs/Float32 length		# length of the segment~%std_msgs/Float32 angle		# angle of the segment~%geometry_msgs/Point position~%geometry_msgs/Twist Velocity~%~%float32 offset~%float64 latitude~%float64 longitude~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/UInt64~%uint64 data~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: project_s_msgs/LaneFusion~%Header header~%std_msgs/UInt8 id~%~%#geometry_msgs/Point[250] points~%~%#uint8 LINE_REPORT_SIZE = 20~%project_s_msgs/Line[20] line~%std_msgs/UInt8 QtyLine~%~%geometry_msgs/Pose lanePosition~%geometry_msgs/Pose lanePoseVariance~%std_msgs/UInt8 laneClass~%std_msgs/UInt8 classificationProbability~%std_msgs/UInt8 laneQuality~%std_msgs/UInt8 roadBorder~%std_msgs/UInt64 dateFusion~%nav_msgs/Odometry odom~%~%# History~%~%~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LaneSynchronizedReportComplet>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'laneAlignement))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'laneFusion))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'linesUpdate))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LaneSynchronizedReportComplet>))
  "Converts a ROS message object to a list"
  (cl:list 'LaneSynchronizedReportComplet
    (cl:cons ':header (header msg))
    (cl:cons ':laneAlignement (laneAlignement msg))
    (cl:cons ':laneFusion (laneFusion msg))
    (cl:cons ':linesUpdate (linesUpdate msg))
))
