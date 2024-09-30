; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude global_tracks_prediction_synchro.msg.html

(cl:defclass <global_tracks_prediction_synchro> (roslisp-msg-protocol:ros-message)
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
   (headerPosition
    :reader headerPosition
    :initarg :headerPosition
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (groundHeight
    :reader groundHeight
    :initarg :groundHeight
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
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
   (obstaclePoseVariance
    :reader obstaclePoseVariance
    :initarg :obstaclePoseVariance
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (headerPoseVariance
    :reader headerPoseVariance
    :initarg :headerPoseVariance
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (obstacleVelocityVariance
    :reader obstacleVelocityVariance
    :initarg :obstacleVelocityVariance
    :type geometry_msgs-msg:Twist
    :initform (cl:make-instance 'geometry_msgs-msg:Twist))
   (headerVelocityVariance
    :reader headerVelocityVariance
    :initarg :headerVelocityVariance
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (obstacleDimensions
    :reader obstacleDimensions
    :initarg :obstacleDimensions
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (obstacleClass
    :reader obstacleClass
    :initarg :obstacleClass
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (classificationProbability
    :reader classificationProbability
    :initarg :classificationProbability
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (dateAcquisition
    :reader dateAcquisition
    :initarg :dateAcquisition
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64)))
)

(cl:defclass global_tracks_prediction_synchro (<global_tracks_prediction_synchro>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <global_tracks_prediction_synchro>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'global_tracks_prediction_synchro)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<global_tracks_prediction_synchro> is deprecated: use project_s_msgs-msg:global_tracks_prediction_synchro instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'obstaclePosition-val :lambda-list '(m))
(cl:defmethod obstaclePosition-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstaclePosition-val is deprecated.  Use project_s_msgs-msg:obstaclePosition instead.")
  (obstaclePosition m))

(cl:ensure-generic-function 'headerPosition-val :lambda-list '(m))
(cl:defmethod headerPosition-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:headerPosition-val is deprecated.  Use project_s_msgs-msg:headerPosition instead.")
  (headerPosition m))

(cl:ensure-generic-function 'groundHeight-val :lambda-list '(m))
(cl:defmethod groundHeight-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:groundHeight-val is deprecated.  Use project_s_msgs-msg:groundHeight instead.")
  (groundHeight m))

(cl:ensure-generic-function 'obstacleVelocity-val :lambda-list '(m))
(cl:defmethod obstacleVelocity-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleVelocity-val is deprecated.  Use project_s_msgs-msg:obstacleVelocity instead.")
  (obstacleVelocity m))

(cl:ensure-generic-function 'obstacleAcceleration-val :lambda-list '(m))
(cl:defmethod obstacleAcceleration-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleAcceleration-val is deprecated.  Use project_s_msgs-msg:obstacleAcceleration instead.")
  (obstacleAcceleration m))

(cl:ensure-generic-function 'obstaclePoseVariance-val :lambda-list '(m))
(cl:defmethod obstaclePoseVariance-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstaclePoseVariance-val is deprecated.  Use project_s_msgs-msg:obstaclePoseVariance instead.")
  (obstaclePoseVariance m))

(cl:ensure-generic-function 'headerPoseVariance-val :lambda-list '(m))
(cl:defmethod headerPoseVariance-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:headerPoseVariance-val is deprecated.  Use project_s_msgs-msg:headerPoseVariance instead.")
  (headerPoseVariance m))

(cl:ensure-generic-function 'obstacleVelocityVariance-val :lambda-list '(m))
(cl:defmethod obstacleVelocityVariance-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleVelocityVariance-val is deprecated.  Use project_s_msgs-msg:obstacleVelocityVariance instead.")
  (obstacleVelocityVariance m))

(cl:ensure-generic-function 'headerVelocityVariance-val :lambda-list '(m))
(cl:defmethod headerVelocityVariance-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:headerVelocityVariance-val is deprecated.  Use project_s_msgs-msg:headerVelocityVariance instead.")
  (headerVelocityVariance m))

(cl:ensure-generic-function 'obstacleDimensions-val :lambda-list '(m))
(cl:defmethod obstacleDimensions-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleDimensions-val is deprecated.  Use project_s_msgs-msg:obstacleDimensions instead.")
  (obstacleDimensions m))

(cl:ensure-generic-function 'obstacleClass-val :lambda-list '(m))
(cl:defmethod obstacleClass-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleClass-val is deprecated.  Use project_s_msgs-msg:obstacleClass instead.")
  (obstacleClass m))

(cl:ensure-generic-function 'classificationProbability-val :lambda-list '(m))
(cl:defmethod classificationProbability-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:classificationProbability-val is deprecated.  Use project_s_msgs-msg:classificationProbability instead.")
  (classificationProbability m))

(cl:ensure-generic-function 'dateAcquisition-val :lambda-list '(m))
(cl:defmethod dateAcquisition-val ((m <global_tracks_prediction_synchro>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:dateAcquisition-val is deprecated.  Use project_s_msgs-msg:dateAcquisition instead.")
  (dateAcquisition m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <global_tracks_prediction_synchro>) ostream)
  "Serializes a message object of type '<global_tracks_prediction_synchro>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstaclePosition) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'headerPosition) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'groundHeight) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleVelocity) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleAcceleration) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstaclePoseVariance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'headerPoseVariance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleVelocityVariance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'headerVelocityVariance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleDimensions) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleClass) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'classificationProbability) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'dateAcquisition) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <global_tracks_prediction_synchro>) istream)
  "Deserializes a message object of type '<global_tracks_prediction_synchro>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstaclePosition) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'headerPosition) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'groundHeight) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleVelocity) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleAcceleration) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstaclePoseVariance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'headerPoseVariance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleVelocityVariance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'headerVelocityVariance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleDimensions) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleClass) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'classificationProbability) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'dateAcquisition) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<global_tracks_prediction_synchro>)))
  "Returns string type for a message object of type '<global_tracks_prediction_synchro>"
  "project_s_msgs/global_tracks_prediction_synchro")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'global_tracks_prediction_synchro)))
  "Returns string type for a message object of type 'global_tracks_prediction_synchro"
  "project_s_msgs/global_tracks_prediction_synchro")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<global_tracks_prediction_synchro>)))
  "Returns md5sum for a message object of type '<global_tracks_prediction_synchro>"
  "159e2baf42cf24b53560d72be3905436")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'global_tracks_prediction_synchro)))
  "Returns md5sum for a message object of type 'global_tracks_prediction_synchro"
  "159e2baf42cf24b53560d72be3905436")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<global_tracks_prediction_synchro>)))
  "Returns full string definition for message of type '<global_tracks_prediction_synchro>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Pose obstaclePosition		# obstacle position~%Header headerPosition~%std_msgs/Float32 groundHeight			# ground height~%geometry_msgs/Twist obstacleVelocity		# obstacle speed~%geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration~%geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance~%Header headerPoseVariance~%geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance~%Header headerVelocityVariance~%geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height~%std_msgs/UInt8 obstacleClass~%std_msgs/UInt8 classificationProbability~%std_msgs/Float64 dateAcquisition~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'global_tracks_prediction_synchro)))
  "Returns full string definition for message of type 'global_tracks_prediction_synchro"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Pose obstaclePosition		# obstacle position~%Header headerPosition~%std_msgs/Float32 groundHeight			# ground height~%geometry_msgs/Twist obstacleVelocity		# obstacle speed~%geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration~%geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance~%Header headerPoseVariance~%geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance~%Header headerVelocityVariance~%geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height~%std_msgs/UInt8 obstacleClass~%std_msgs/UInt8 classificationProbability~%std_msgs/Float64 dateAcquisition~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <global_tracks_prediction_synchro>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstaclePosition))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'headerPosition))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'groundHeight))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleVelocity))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleAcceleration))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstaclePoseVariance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'headerPoseVariance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleVelocityVariance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'headerVelocityVariance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleDimensions))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleClass))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'classificationProbability))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'dateAcquisition))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <global_tracks_prediction_synchro>))
  "Converts a ROS message object to a list"
  (cl:list 'global_tracks_prediction_synchro
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':obstaclePosition (obstaclePosition msg))
    (cl:cons ':headerPosition (headerPosition msg))
    (cl:cons ':groundHeight (groundHeight msg))
    (cl:cons ':obstacleVelocity (obstacleVelocity msg))
    (cl:cons ':obstacleAcceleration (obstacleAcceleration msg))
    (cl:cons ':obstaclePoseVariance (obstaclePoseVariance msg))
    (cl:cons ':headerPoseVariance (headerPoseVariance msg))
    (cl:cons ':obstacleVelocityVariance (obstacleVelocityVariance msg))
    (cl:cons ':headerVelocityVariance (headerVelocityVariance msg))
    (cl:cons ':obstacleDimensions (obstacleDimensions msg))
    (cl:cons ':obstacleClass (obstacleClass msg))
    (cl:cons ':classificationProbability (classificationProbability msg))
    (cl:cons ':dateAcquisition (dateAcquisition msg))
))
