; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude RoadModel.msg.html

(cl:defclass <RoadModel> (roslisp-msg-protocol:ros-message)
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
   (nbrLine
    :reader nbrLine
    :initarg :nbrLine
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (roadLine
    :reader roadLine
    :initarg :roadLine
    :type (cl:vector project_s_msgs-msg:Line)
   :initform (cl:make-array 10 :element-type 'project_s_msgs-msg:Line :initial-element (cl:make-instance 'project_s_msgs-msg:Line)))
   (electronicHorizon
    :reader electronicHorizon
    :initarg :electronicHorizon
    :type project_s_msgs-msg:ElectronicHorizon
    :initform (cl:make-instance 'project_s_msgs-msg:ElectronicHorizon))
   (speedEnveloppe
    :reader speedEnveloppe
    :initarg :speedEnveloppe
    :type (cl:vector project_s_msgs-msg:Speed)
   :initform (cl:make-array 310 :element-type 'project_s_msgs-msg:Speed :initial-element (cl:make-instance 'project_s_msgs-msg:Speed)))
   (amer
    :reader amer
    :initarg :amer
    :type (cl:vector geometry_msgs-msg:Point)
   :initform (cl:make-array 50 :element-type 'geometry_msgs-msg:Point :initial-element (cl:make-instance 'geometry_msgs-msg:Point)))
   (nbrAmer
    :reader nbrAmer
    :initarg :nbrAmer
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (odom
    :reader odom
    :initarg :odom
    :type nav_msgs-msg:Odometry
    :initform (cl:make-instance 'nav_msgs-msg:Odometry)))
)

(cl:defclass RoadModel (<RoadModel>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RoadModel>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RoadModel)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<RoadModel> is deprecated: use project_s_msgs-msg:RoadModel instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <RoadModel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <RoadModel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'nbrLine-val :lambda-list '(m))
(cl:defmethod nbrLine-val ((m <RoadModel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbrLine-val is deprecated.  Use project_s_msgs-msg:nbrLine instead.")
  (nbrLine m))

(cl:ensure-generic-function 'roadLine-val :lambda-list '(m))
(cl:defmethod roadLine-val ((m <RoadModel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:roadLine-val is deprecated.  Use project_s_msgs-msg:roadLine instead.")
  (roadLine m))

(cl:ensure-generic-function 'electronicHorizon-val :lambda-list '(m))
(cl:defmethod electronicHorizon-val ((m <RoadModel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:electronicHorizon-val is deprecated.  Use project_s_msgs-msg:electronicHorizon instead.")
  (electronicHorizon m))

(cl:ensure-generic-function 'speedEnveloppe-val :lambda-list '(m))
(cl:defmethod speedEnveloppe-val ((m <RoadModel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:speedEnveloppe-val is deprecated.  Use project_s_msgs-msg:speedEnveloppe instead.")
  (speedEnveloppe m))

(cl:ensure-generic-function 'amer-val :lambda-list '(m))
(cl:defmethod amer-val ((m <RoadModel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:amer-val is deprecated.  Use project_s_msgs-msg:amer instead.")
  (amer m))

(cl:ensure-generic-function 'nbrAmer-val :lambda-list '(m))
(cl:defmethod nbrAmer-val ((m <RoadModel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbrAmer-val is deprecated.  Use project_s_msgs-msg:nbrAmer instead.")
  (nbrAmer m))

(cl:ensure-generic-function 'odom-val :lambda-list '(m))
(cl:defmethod odom-val ((m <RoadModel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:odom-val is deprecated.  Use project_s_msgs-msg:odom instead.")
  (odom m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<RoadModel>)))
    "Constants for message type '<RoadModel>"
  '((:SPEED_LIMIT_ARRAY_SIZE . 310)
    (:AMER_ARRAY_SIZE . 50))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'RoadModel)))
    "Constants for message type 'RoadModel"
  '((:SPEED_LIMIT_ARRAY_SIZE . 310)
    (:AMER_ARRAY_SIZE . 50))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RoadModel>) ostream)
  "Serializes a message object of type '<RoadModel>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbrLine) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'roadLine))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'electronicHorizon) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'speedEnveloppe))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'amer))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbrAmer) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'odom) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RoadModel>) istream)
  "Deserializes a message object of type '<RoadModel>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbrLine) istream)
  (cl:setf (cl:slot-value msg 'roadLine) (cl:make-array 10))
  (cl:let ((vals (cl:slot-value msg 'roadLine)))
    (cl:dotimes (i 10)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:Line))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'electronicHorizon) istream)
  (cl:setf (cl:slot-value msg 'speedEnveloppe) (cl:make-array 310))
  (cl:let ((vals (cl:slot-value msg 'speedEnveloppe)))
    (cl:dotimes (i 310)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:Speed))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (cl:setf (cl:slot-value msg 'amer) (cl:make-array 50))
  (cl:let ((vals (cl:slot-value msg 'amer)))
    (cl:dotimes (i 50)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbrAmer) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'odom) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RoadModel>)))
  "Returns string type for a message object of type '<RoadModel>"
  "project_s_msgs/RoadModel")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RoadModel)))
  "Returns string type for a message object of type 'RoadModel"
  "project_s_msgs/RoadModel")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RoadModel>)))
  "Returns md5sum for a message object of type '<RoadModel>"
  "8e9f6188ebbf41f73c6179086ef32107")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RoadModel)))
  "Returns md5sum for a message object of type 'RoadModel"
  "8e9f6188ebbf41f73c6179086ef32107")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RoadModel>)))
  "Returns full string definition for message of type '<RoadModel>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 nbrLine~%project_s_msgs/Line[10] roadLine			#segments array~%~%project_s_msgs/ElectronicHorizon electronicHorizon~%~%uint32 SPEED_LIMIT_ARRAY_SIZE = 310~%project_s_msgs/Speed[310] speedEnveloppe~%~%uint8 AMER_ARRAY_SIZE = 50~%geometry_msgs/Point[50] amer~%std_msgs/UInt8 nbrAmer~%~%~%nav_msgs/Odometry odom~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/Line~%Header header~%std_msgs/UInt8 id~%~%uint16 SEGMENT_REPORT_SIZE = 3000~%project_s_msgs/Segment[3000] segment~%std_msgs/UInt16 QtySegment~%std_msgs/Float32 lineClass	# class of the line~%std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)~%~%std_msgs/UInt8 existenceState~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%~%~%~%================================================================================~%MSG: project_s_msgs/Segment~%std_msgs/Float32 length		# length of the segment~%std_msgs/Float32 angle		# angle of the segment~%geometry_msgs/Point position~%geometry_msgs/Twist Velocity~%~%float32 offset~%float64 latitude~%float64 longitude~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: project_s_msgs/ElectronicHorizon~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 indexPath~%~%uint8 SEGMENT_REPORT_SIZE = 50~%project_s_msgs/ehSegment[50] ehSegment~%std_msgs/UInt8 NbrSegment~%~%uint8 STUB_REPORT_SIZE = 10~%project_s_msgs/ehStub[10] ehStub~%std_msgs/UInt8 NbrStub~%~%uint16 SPOT_CURVATURE_REPORT_SIZE = 300~%project_s_msgs/ehSpotCurvature[300] ehSpotCurvature~%std_msgs/UInt16 NbrSpotCurvature~%~%uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight~%std_msgs/UInt16 NbrSpotCoordGeoRight~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft~%std_msgs/UInt16 NbrSpotCoordGeoLeft~%~%uint8 LINE_REPORT_SIZE = 10~%project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo~%std_msgs/UInt8 QtyLineCoordGeo~%~%uint8 ME_RIGHT_LINE = 0~%uint8 ME_LEFT_LINE = 1~%project_s_msgs/ehME[2] ehME~%~%uint8 NBR_LINE_REPORT_SIZE = 100~%project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo~%std_msgs/UInt8 QtyNbrLineCoordGeo~%~%uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50~%project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign~%std_msgs/UInt8 NbrSpotTrafficSign~%~%project_s_msgs/ehPosition ehPosition~%~%uint8 speedLimit_interpolMethod~%uint8 curvature_interpolMethod~%uint8 STEP = 0~%uint8 LINEAR = 1~%~%uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentAO~%std_msgs/UInt8 QtySegmentAO~%~%uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentEO~%std_msgs/UInt8 QtySegmentEO~%~%~%================================================================================~%MSG: project_s_msgs/ehSegment~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 effectiveSpeedLimit~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: project_s_msgs/ehStub~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 indexSubPath~%std_msgs/Float32 turnAngle~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotCurvature~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/Float32 Value_0~%std_msgs/Float32 Distance_1~%std_msgs/Float32 Value_1~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotCoordGeo~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%~%~%~%================================================================================~%MSG: project_s_msgs/ehLineCoordGeo~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 3000~%project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: project_s_msgs/ehME~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%uint32 SEGMENT_ME_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentME~%std_msgs/UInt32 QtySegment~%~%================================================================================~%MSG: project_s_msgs/ehSegmentME~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 NbrSpot~%std_msgs/Float32 offset_debut~%std_msgs/Float32 offset_fin~%~%================================================================================~%MSG: project_s_msgs/ehNbrLineCoordGeo~%std_msgs/UInt8 Nbr~%std_msgs/Float32 offset~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotTrafficSign~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%uint8 Sign_Type~%uint8 Value~%uint8 Lane~%uint8 Sign_Location~%float64 latitude~%float64 longitude~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehPosition~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%std_msgs/Float32 cap~%std_msgs/UInt16 agePosition~%std_msgs/Float32 speed~%std_msgs/Float32 relativeHeading~%std_msgs/UInt8 currentLane~%~%~%~%================================================================================~%MSG: project_s_msgs/Speed~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%std_msgs/Float32 speed~%~%~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RoadModel)))
  "Returns full string definition for message of type 'RoadModel"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 nbrLine~%project_s_msgs/Line[10] roadLine			#segments array~%~%project_s_msgs/ElectronicHorizon electronicHorizon~%~%uint32 SPEED_LIMIT_ARRAY_SIZE = 310~%project_s_msgs/Speed[310] speedEnveloppe~%~%uint8 AMER_ARRAY_SIZE = 50~%geometry_msgs/Point[50] amer~%std_msgs/UInt8 nbrAmer~%~%~%nav_msgs/Odometry odom~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/Line~%Header header~%std_msgs/UInt8 id~%~%uint16 SEGMENT_REPORT_SIZE = 3000~%project_s_msgs/Segment[3000] segment~%std_msgs/UInt16 QtySegment~%std_msgs/Float32 lineClass	# class of the line~%std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)~%~%std_msgs/UInt8 existenceState~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%~%~%~%================================================================================~%MSG: project_s_msgs/Segment~%std_msgs/Float32 length		# length of the segment~%std_msgs/Float32 angle		# angle of the segment~%geometry_msgs/Point position~%geometry_msgs/Twist Velocity~%~%float32 offset~%float64 latitude~%float64 longitude~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: project_s_msgs/ElectronicHorizon~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 indexPath~%~%uint8 SEGMENT_REPORT_SIZE = 50~%project_s_msgs/ehSegment[50] ehSegment~%std_msgs/UInt8 NbrSegment~%~%uint8 STUB_REPORT_SIZE = 10~%project_s_msgs/ehStub[10] ehStub~%std_msgs/UInt8 NbrStub~%~%uint16 SPOT_CURVATURE_REPORT_SIZE = 300~%project_s_msgs/ehSpotCurvature[300] ehSpotCurvature~%std_msgs/UInt16 NbrSpotCurvature~%~%uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight~%std_msgs/UInt16 NbrSpotCoordGeoRight~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft~%std_msgs/UInt16 NbrSpotCoordGeoLeft~%~%uint8 LINE_REPORT_SIZE = 10~%project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo~%std_msgs/UInt8 QtyLineCoordGeo~%~%uint8 ME_RIGHT_LINE = 0~%uint8 ME_LEFT_LINE = 1~%project_s_msgs/ehME[2] ehME~%~%uint8 NBR_LINE_REPORT_SIZE = 100~%project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo~%std_msgs/UInt8 QtyNbrLineCoordGeo~%~%uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50~%project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign~%std_msgs/UInt8 NbrSpotTrafficSign~%~%project_s_msgs/ehPosition ehPosition~%~%uint8 speedLimit_interpolMethod~%uint8 curvature_interpolMethod~%uint8 STEP = 0~%uint8 LINEAR = 1~%~%uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentAO~%std_msgs/UInt8 QtySegmentAO~%~%uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentEO~%std_msgs/UInt8 QtySegmentEO~%~%~%================================================================================~%MSG: project_s_msgs/ehSegment~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 effectiveSpeedLimit~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: project_s_msgs/ehStub~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 indexSubPath~%std_msgs/Float32 turnAngle~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotCurvature~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/Float32 Value_0~%std_msgs/Float32 Distance_1~%std_msgs/Float32 Value_1~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotCoordGeo~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%~%~%~%================================================================================~%MSG: project_s_msgs/ehLineCoordGeo~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 3000~%project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: project_s_msgs/ehME~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%uint32 SEGMENT_ME_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentME~%std_msgs/UInt32 QtySegment~%~%================================================================================~%MSG: project_s_msgs/ehSegmentME~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 NbrSpot~%std_msgs/Float32 offset_debut~%std_msgs/Float32 offset_fin~%~%================================================================================~%MSG: project_s_msgs/ehNbrLineCoordGeo~%std_msgs/UInt8 Nbr~%std_msgs/Float32 offset~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotTrafficSign~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%uint8 Sign_Type~%uint8 Value~%uint8 Lane~%uint8 Sign_Location~%float64 latitude~%float64 longitude~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehPosition~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%std_msgs/Float32 cap~%std_msgs/UInt16 agePosition~%std_msgs/Float32 speed~%std_msgs/Float32 relativeHeading~%std_msgs/UInt8 currentLane~%~%~%~%================================================================================~%MSG: project_s_msgs/Speed~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%std_msgs/Float32 speed~%~%~%================================================================================~%MSG: nav_msgs/Odometry~%# This represents an estimate of a position and velocity in free space.  ~%# The pose in this message should be specified in the coordinate frame given by header.frame_id.~%# The twist in this message should be specified in the coordinate frame given by the child_frame_id~%Header header~%string child_frame_id~%geometry_msgs/PoseWithCovariance pose~%geometry_msgs/TwistWithCovariance twist~%~%================================================================================~%MSG: geometry_msgs/PoseWithCovariance~%# This represents a pose in free space with uncertainty.~%~%Pose pose~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/TwistWithCovariance~%# This expresses velocity in free space with uncertainty.~%~%Twist twist~%~%# Row-major representation of the 6x6 covariance matrix~%# The orientation parameters use a fixed-axis representation.~%# In order, the parameters are:~%# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)~%float64[36] covariance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RoadModel>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbrLine))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'roadLine) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'electronicHorizon))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'speedEnveloppe) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'amer) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbrAmer))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'odom))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RoadModel>))
  "Converts a ROS message object to a list"
  (cl:list 'RoadModel
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':nbrLine (nbrLine msg))
    (cl:cons ':roadLine (roadLine msg))
    (cl:cons ':electronicHorizon (electronicHorizon msg))
    (cl:cons ':speedEnveloppe (speedEnveloppe msg))
    (cl:cons ':amer (amer msg))
    (cl:cons ':nbrAmer (nbrAmer msg))
    (cl:cons ':odom (odom msg))
))
