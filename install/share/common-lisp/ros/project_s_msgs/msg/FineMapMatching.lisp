; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude FineMapMatching.msg.html

(cl:defclass <FineMapMatching> (roslisp-msg-protocol:ros-message)
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
   (dCap
    :reader dCap
    :initarg :dCap
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (d_x_lambert
    :reader d_x_lambert
    :initarg :d_x_lambert
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (d_y_lambert
    :reader d_y_lambert
    :initarg :d_y_lambert
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (d_latitude
    :reader d_latitude
    :initarg :d_latitude
    :type cl:float
    :initform 0.0)
   (d_longitude
    :reader d_longitude
    :initarg :d_longitude
    :type cl:float
    :initform 0.0)
   (electronicHorizonArray
    :reader electronicHorizonArray
    :initarg :electronicHorizonArray
    :type project_s_msgs-msg:ElectronicHorizonArray
    :initform (cl:make-instance 'project_s_msgs-msg:ElectronicHorizonArray)))
)

(cl:defclass FineMapMatching (<FineMapMatching>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FineMapMatching>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FineMapMatching)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<FineMapMatching> is deprecated: use project_s_msgs-msg:FineMapMatching instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <FineMapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <FineMapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'dCap-val :lambda-list '(m))
(cl:defmethod dCap-val ((m <FineMapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:dCap-val is deprecated.  Use project_s_msgs-msg:dCap instead.")
  (dCap m))

(cl:ensure-generic-function 'd_x_lambert-val :lambda-list '(m))
(cl:defmethod d_x_lambert-val ((m <FineMapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:d_x_lambert-val is deprecated.  Use project_s_msgs-msg:d_x_lambert instead.")
  (d_x_lambert m))

(cl:ensure-generic-function 'd_y_lambert-val :lambda-list '(m))
(cl:defmethod d_y_lambert-val ((m <FineMapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:d_y_lambert-val is deprecated.  Use project_s_msgs-msg:d_y_lambert instead.")
  (d_y_lambert m))

(cl:ensure-generic-function 'd_latitude-val :lambda-list '(m))
(cl:defmethod d_latitude-val ((m <FineMapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:d_latitude-val is deprecated.  Use project_s_msgs-msg:d_latitude instead.")
  (d_latitude m))

(cl:ensure-generic-function 'd_longitude-val :lambda-list '(m))
(cl:defmethod d_longitude-val ((m <FineMapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:d_longitude-val is deprecated.  Use project_s_msgs-msg:d_longitude instead.")
  (d_longitude m))

(cl:ensure-generic-function 'electronicHorizonArray-val :lambda-list '(m))
(cl:defmethod electronicHorizonArray-val ((m <FineMapMatching>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:electronicHorizonArray-val is deprecated.  Use project_s_msgs-msg:electronicHorizonArray instead.")
  (electronicHorizonArray m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FineMapMatching>) ostream)
  "Serializes a message object of type '<FineMapMatching>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'dCap) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'd_x_lambert) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'd_y_lambert) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'd_latitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'd_longitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'electronicHorizonArray) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FineMapMatching>) istream)
  "Deserializes a message object of type '<FineMapMatching>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'dCap) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'd_x_lambert) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'd_y_lambert) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'd_latitude) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'd_longitude) (roslisp-utils:decode-double-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'electronicHorizonArray) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FineMapMatching>)))
  "Returns string type for a message object of type '<FineMapMatching>"
  "project_s_msgs/FineMapMatching")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FineMapMatching)))
  "Returns string type for a message object of type 'FineMapMatching"
  "project_s_msgs/FineMapMatching")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FineMapMatching>)))
  "Returns md5sum for a message object of type '<FineMapMatching>"
  "bbc6c31487a0775416bf98fdaad9098b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FineMapMatching)))
  "Returns md5sum for a message object of type 'FineMapMatching"
  "bbc6c31487a0775416bf98fdaad9098b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FineMapMatching>)))
  "Returns full string definition for message of type '<FineMapMatching>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 dCap~%~%std_msgs/Float32 d_x_lambert	# sens sud   -> nord, unité en m~%std_msgs/Float32 d_y_lambert	# sens ouest -> est , unité en m~%~%float64 d_latitude	# unité en °~%float64 d_longitude	# unité en °~%~%project_s_msgs/ElectronicHorizonArray electronicHorizonArray~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: project_s_msgs/ElectronicHorizonArray~%Header header~%std_msgs/UInt8 id~%~%project_s_msgs/ElectronicHorizon[5] PathsArray~%std_msgs/UInt8 NbrPath~%std_msgs/UInt8 indexMPP~%~%nav_msgs/Odometry odom~%~%~%~%================================================================================~%MSG: project_s_msgs/ElectronicHorizon~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 indexPath~%~%uint8 SEGMENT_REPORT_SIZE = 50~%project_s_msgs/ehSegment[50] ehSegment~%std_msgs/UInt8 NbrSegment~%~%uint8 STUB_REPORT_SIZE = 10~%project_s_msgs/ehStub[10] ehStub~%std_msgs/UInt8 NbrStub~%~%uint16 SPOT_CURVATURE_REPORT_SIZE = 300~%project_s_msgs/ehSpotCurvature[300] ehSpotCurvature~%std_msgs/UInt16 NbrSpotCurvature~%~%uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight~%std_msgs/UInt16 NbrSpotCoordGeoRight~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft~%std_msgs/UInt16 NbrSpotCoordGeoLeft~%~%uint8 LINE_REPORT_SIZE = 10~%project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo~%std_msgs/UInt8 QtyLineCoordGeo~%~%uint8 ME_RIGHT_LINE = 0~%uint8 ME_LEFT_LINE = 1~%project_s_msgs/ehME[2] ehME~%~%uint8 NBR_LINE_REPORT_SIZE = 100~%project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo~%std_msgs/UInt8 QtyNbrLineCoordGeo~%~%uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50~%project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign~%std_msgs/UInt8 NbrSpotTrafficSign~%~%project_s_msgs/ehPosition ehPosition~%~%uint8 speedLimit_interpolMethod~%uint8 curvature_interpolMethod~%uint8 STEP = 0~%uint8 LINEAR = 1~%~%uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentAO~%std_msgs/UInt8 QtySegmentAO~%~%uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentEO~%std_msgs/UInt8 QtySegmentEO~%~%~%================================================================================~%MSG: project_s_msgs/ehSegment~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 effectiveSpeedLimit~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: project_s_msgs/ehStub~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 indexSubPath~%std_msgs/Float32 turnAngle~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotCurvature~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/Float32 Value_0~%std_msgs/Float32 Distance_1~%std_msgs/Float32 Value_1~%~%~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: project_s_msgs/ehSpotCoordGeo~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%~%~%~%================================================================================~%MSG: project_s_msgs/ehLineCoordGeo~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 3000~%project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: project_s_msgs/ehME~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%uint32 SEGMENT_ME_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentME~%std_msgs/UInt32 QtySegment~%~%================================================================================~%MSG: project_s_msgs/ehSegmentME~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 NbrSpot~%std_msgs/Float32 offset_debut~%std_msgs/Float32 offset_fin~%~%================================================================================~%MSG: project_s_msgs/ehNbrLineCoordGeo~%std_msgs/UInt8 Nbr~%std_msgs/Float32 offset~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotTrafficSign~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%uint8 Sign_Type~%uint8 Value~%uint8 Lane~%uint8 Sign_Location~%float64 latitude~%float64 longitude~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehPosition~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%std_msgs/Float32 cap~%std_msgs/UInt16 agePosition~%std_msgs/Float32 speed~%std_msgs/Float32 relativeHeading~%std_msgs/UInt8 currentLane~%~%~%~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FineMapMatching)))
  "Returns full string definition for message of type 'FineMapMatching"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 dCap~%~%std_msgs/Float32 d_x_lambert	# sens sud   -> nord, unité en m~%std_msgs/Float32 d_y_lambert	# sens ouest -> est , unité en m~%~%float64 d_latitude	# unité en °~%float64 d_longitude	# unité en °~%~%project_s_msgs/ElectronicHorizonArray electronicHorizonArray~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: project_s_msgs/ElectronicHorizonArray~%Header header~%std_msgs/UInt8 id~%~%project_s_msgs/ElectronicHorizon[5] PathsArray~%std_msgs/UInt8 NbrPath~%std_msgs/UInt8 indexMPP~%~%nav_msgs/Odometry odom~%~%~%~%================================================================================~%MSG: project_s_msgs/ElectronicHorizon~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 indexPath~%~%uint8 SEGMENT_REPORT_SIZE = 50~%project_s_msgs/ehSegment[50] ehSegment~%std_msgs/UInt8 NbrSegment~%~%uint8 STUB_REPORT_SIZE = 10~%project_s_msgs/ehStub[10] ehStub~%std_msgs/UInt8 NbrStub~%~%uint16 SPOT_CURVATURE_REPORT_SIZE = 300~%project_s_msgs/ehSpotCurvature[300] ehSpotCurvature~%std_msgs/UInt16 NbrSpotCurvature~%~%uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight~%std_msgs/UInt16 NbrSpotCoordGeoRight~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft~%std_msgs/UInt16 NbrSpotCoordGeoLeft~%~%uint8 LINE_REPORT_SIZE = 10~%project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo~%std_msgs/UInt8 QtyLineCoordGeo~%~%uint8 ME_RIGHT_LINE = 0~%uint8 ME_LEFT_LINE = 1~%project_s_msgs/ehME[2] ehME~%~%uint8 NBR_LINE_REPORT_SIZE = 100~%project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo~%std_msgs/UInt8 QtyNbrLineCoordGeo~%~%uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50~%project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign~%std_msgs/UInt8 NbrSpotTrafficSign~%~%project_s_msgs/ehPosition ehPosition~%~%uint8 speedLimit_interpolMethod~%uint8 curvature_interpolMethod~%uint8 STEP = 0~%uint8 LINEAR = 1~%~%uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentAO~%std_msgs/UInt8 QtySegmentAO~%~%uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentEO~%std_msgs/UInt8 QtySegmentEO~%~%~%================================================================================~%MSG: project_s_msgs/ehSegment~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 effectiveSpeedLimit~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: project_s_msgs/ehStub~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 indexSubPath~%std_msgs/Float32 turnAngle~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotCurvature~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/Float32 Value_0~%std_msgs/Float32 Distance_1~%std_msgs/Float32 Value_1~%~%~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: project_s_msgs/ehSpotCoordGeo~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%~%~%~%================================================================================~%MSG: project_s_msgs/ehLineCoordGeo~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 3000~%project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: project_s_msgs/ehME~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%uint32 SEGMENT_ME_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentME~%std_msgs/UInt32 QtySegment~%~%================================================================================~%MSG: project_s_msgs/ehSegmentME~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 NbrSpot~%std_msgs/Float32 offset_debut~%std_msgs/Float32 offset_fin~%~%================================================================================~%MSG: project_s_msgs/ehNbrLineCoordGeo~%std_msgs/UInt8 Nbr~%std_msgs/Float32 offset~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotTrafficSign~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%uint8 Sign_Type~%uint8 Value~%uint8 Lane~%uint8 Sign_Location~%float64 latitude~%float64 longitude~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehPosition~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%std_msgs/Float32 cap~%std_msgs/UInt16 agePosition~%std_msgs/Float32 speed~%std_msgs/Float32 relativeHeading~%std_msgs/UInt8 currentLane~%~%~%~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FineMapMatching>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'dCap))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'd_x_lambert))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'd_y_lambert))
     8
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'electronicHorizonArray))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FineMapMatching>))
  "Converts a ROS message object to a list"
  (cl:list 'FineMapMatching
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':dCap (dCap msg))
    (cl:cons ':d_x_lambert (d_x_lambert msg))
    (cl:cons ':d_y_lambert (d_y_lambert msg))
    (cl:cons ':d_latitude (d_latitude msg))
    (cl:cons ':d_longitude (d_longitude msg))
    (cl:cons ':electronicHorizonArray (electronicHorizonArray msg))
))
