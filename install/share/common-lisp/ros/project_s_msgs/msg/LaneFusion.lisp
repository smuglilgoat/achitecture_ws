; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude LaneFusion.msg.html

(cl:defclass <LaneFusion> (roslisp-msg-protocol:ros-message)
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
   (line
    :reader line
    :initarg :line
    :type (cl:vector project_s_msgs-msg:Line)
   :initform (cl:make-array 20 :element-type 'project_s_msgs-msg:Line :initial-element (cl:make-instance 'project_s_msgs-msg:Line)))
   (QtyLine
    :reader QtyLine
    :initarg :QtyLine
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (lanePosition
    :reader lanePosition
    :initarg :lanePosition
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (lanePoseVariance
    :reader lanePoseVariance
    :initarg :lanePoseVariance
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (laneClass
    :reader laneClass
    :initarg :laneClass
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (classificationProbability
    :reader classificationProbability
    :initarg :classificationProbability
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (laneQuality
    :reader laneQuality
    :initarg :laneQuality
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (roadBorder
    :reader roadBorder
    :initarg :roadBorder
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (dateFusion
    :reader dateFusion
    :initarg :dateFusion
    :type std_msgs-msg:UInt64
    :initform (cl:make-instance 'std_msgs-msg:UInt64))
   (odom
    :reader odom
    :initarg :odom
    :type nav_msgs-msg:Odometry
    :initform (cl:make-instance 'nav_msgs-msg:Odometry)))
)

(cl:defclass LaneFusion (<LaneFusion>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LaneFusion>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LaneFusion)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<LaneFusion> is deprecated: use project_s_msgs-msg:LaneFusion instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'line-val :lambda-list '(m))
(cl:defmethod line-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:line-val is deprecated.  Use project_s_msgs-msg:line instead.")
  (line m))

(cl:ensure-generic-function 'QtyLine-val :lambda-list '(m))
(cl:defmethod QtyLine-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:QtyLine-val is deprecated.  Use project_s_msgs-msg:QtyLine instead.")
  (QtyLine m))

(cl:ensure-generic-function 'lanePosition-val :lambda-list '(m))
(cl:defmethod lanePosition-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:lanePosition-val is deprecated.  Use project_s_msgs-msg:lanePosition instead.")
  (lanePosition m))

(cl:ensure-generic-function 'lanePoseVariance-val :lambda-list '(m))
(cl:defmethod lanePoseVariance-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:lanePoseVariance-val is deprecated.  Use project_s_msgs-msg:lanePoseVariance instead.")
  (lanePoseVariance m))

(cl:ensure-generic-function 'laneClass-val :lambda-list '(m))
(cl:defmethod laneClass-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:laneClass-val is deprecated.  Use project_s_msgs-msg:laneClass instead.")
  (laneClass m))

(cl:ensure-generic-function 'classificationProbability-val :lambda-list '(m))
(cl:defmethod classificationProbability-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:classificationProbability-val is deprecated.  Use project_s_msgs-msg:classificationProbability instead.")
  (classificationProbability m))

(cl:ensure-generic-function 'laneQuality-val :lambda-list '(m))
(cl:defmethod laneQuality-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:laneQuality-val is deprecated.  Use project_s_msgs-msg:laneQuality instead.")
  (laneQuality m))

(cl:ensure-generic-function 'roadBorder-val :lambda-list '(m))
(cl:defmethod roadBorder-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:roadBorder-val is deprecated.  Use project_s_msgs-msg:roadBorder instead.")
  (roadBorder m))

(cl:ensure-generic-function 'dateFusion-val :lambda-list '(m))
(cl:defmethod dateFusion-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:dateFusion-val is deprecated.  Use project_s_msgs-msg:dateFusion instead.")
  (dateFusion m))

(cl:ensure-generic-function 'odom-val :lambda-list '(m))
(cl:defmethod odom-val ((m <LaneFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:odom-val is deprecated.  Use project_s_msgs-msg:odom instead.")
  (odom m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LaneFusion>) ostream)
  "Serializes a message object of type '<LaneFusion>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'line))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'QtyLine) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'lanePosition) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'lanePoseVariance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'laneClass) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'classificationProbability) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'laneQuality) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'roadBorder) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'dateFusion) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'odom) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LaneFusion>) istream)
  "Deserializes a message object of type '<LaneFusion>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (cl:setf (cl:slot-value msg 'line) (cl:make-array 20))
  (cl:let ((vals (cl:slot-value msg 'line)))
    (cl:dotimes (i 20)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:Line))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'QtyLine) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'lanePosition) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'lanePoseVariance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'laneClass) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'classificationProbability) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'laneQuality) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'roadBorder) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'dateFusion) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'odom) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LaneFusion>)))
  "Returns string type for a message object of type '<LaneFusion>"
  "project_s_msgs/LaneFusion")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LaneFusion)))
  "Returns string type for a message object of type 'LaneFusion"
  "project_s_msgs/LaneFusion")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LaneFusion>)))
  "Returns md5sum for a message object of type '<LaneFusion>"
  "220d926e4a3ceb1cf1d7edbdff245ce3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LaneFusion)))
  "Returns md5sum for a message object of type 'LaneFusion"
  "220d926e4a3ceb1cf1d7edbdff245ce3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LaneFusion>)))
  "Returns full string definition for message of type '<LaneFusion>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%#geometry_msgs/Point[250] points~%~%#uint8 LINE_REPORT_SIZE = 20~%project_s_msgs/Line[20] line~%std_msgs/UInt8 QtyLine~%~%geometry_msgs/Pose lanePosition~%geometry_msgs/Pose lanePoseVariance~%std_msgs/UInt8 laneClass~%std_msgs/UInt8 classificationProbability~%std_msgs/UInt8 laneQuality~%std_msgs/UInt8 roadBorder~%std_msgs/UInt64 dateFusion~%nav_msgs/Odometry odom~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/Line~%Header header~%std_msgs/UInt8 id~%~%uint16 SEGMENT_REPORT_SIZE = 3000~%project_s_msgs/Segment[3000] segment~%std_msgs/UInt16 QtySegment~%std_msgs/Float32 lineClass	# class of the line~%std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)~%~%std_msgs/UInt8 existenceState~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%~%~%~%================================================================================~%MSG: project_s_msgs/Segment~%std_msgs/Float32 length		# length of the segment~%std_msgs/Float32 angle		# angle of the segment~%geometry_msgs/Point position~%geometry_msgs/Twist Velocity~%~%float32 offset~%float64 latitude~%float64 longitude~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/UInt64~%uint64 data~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LaneFusion)))
  "Returns full string definition for message of type 'LaneFusion"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%#geometry_msgs/Point[250] points~%~%#uint8 LINE_REPORT_SIZE = 20~%project_s_msgs/Line[20] line~%std_msgs/UInt8 QtyLine~%~%geometry_msgs/Pose lanePosition~%geometry_msgs/Pose lanePoseVariance~%std_msgs/UInt8 laneClass~%std_msgs/UInt8 classificationProbability~%std_msgs/UInt8 laneQuality~%std_msgs/UInt8 roadBorder~%std_msgs/UInt64 dateFusion~%nav_msgs/Odometry odom~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/Line~%Header header~%std_msgs/UInt8 id~%~%uint16 SEGMENT_REPORT_SIZE = 3000~%project_s_msgs/Segment[3000] segment~%std_msgs/UInt16 QtySegment~%std_msgs/Float32 lineClass	# class of the line~%std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)~%~%std_msgs/UInt8 existenceState~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%~%~%~%================================================================================~%MSG: project_s_msgs/Segment~%std_msgs/Float32 length		# length of the segment~%std_msgs/Float32 angle		# angle of the segment~%geometry_msgs/Point position~%geometry_msgs/Twist Velocity~%~%float32 offset~%float64 latitude~%float64 longitude~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/UInt64~%uint64 data~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LaneFusion>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'line) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'QtyLine))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'lanePosition))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'lanePoseVariance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'laneClass))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'classificationProbability))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'laneQuality))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'roadBorder))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'dateFusion))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'odom))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LaneFusion>))
  "Converts a ROS message object to a list"
  (cl:list 'LaneFusion
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':line (line msg))
    (cl:cons ':QtyLine (QtyLine msg))
    (cl:cons ':lanePosition (lanePosition msg))
    (cl:cons ':lanePoseVariance (lanePoseVariance msg))
    (cl:cons ':laneClass (laneClass msg))
    (cl:cons ':classificationProbability (classificationProbability msg))
    (cl:cons ':laneQuality (laneQuality msg))
    (cl:cons ':roadBorder (roadBorder msg))
    (cl:cons ':dateFusion (dateFusion msg))
    (cl:cons ':odom (odom msg))
))
