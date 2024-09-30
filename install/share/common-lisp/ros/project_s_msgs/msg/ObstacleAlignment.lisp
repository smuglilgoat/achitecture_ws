; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ObstacleAlignment.msg.html

(cl:defclass <ObstacleAlignment> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (id
    :reader id
    :initarg :id
    :type std_msgs-msg:UInt16
    :initform (cl:make-instance 'std_msgs-msg:UInt16))
   (obstaclePosition
    :reader obstaclePosition
    :initarg :obstaclePosition
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (obstacleBodyCenter
    :reader obstacleBodyCenter
    :initarg :obstacleBodyCenter
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (obstacleVelocity
    :reader obstacleVelocity
    :initarg :obstacleVelocity
    :type geometry_msgs-msg:Twist
    :initform (cl:make-instance 'geometry_msgs-msg:Twist))
   (obstacleRelativeVelocity
    :reader obstacleRelativeVelocity
    :initarg :obstacleRelativeVelocity
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
   (blinkerInfo
    :reader blinkerInfo
    :initarg :blinkerInfo
    :type cl:fixnum
    :initform 0)
   (cutInAndOut
    :reader cutInAndOut
    :initarg :cutInAndOut
    :type cl:fixnum
    :initform 0)
   (obstacleType
    :reader obstacleType
    :initarg :obstacleType
    :type cl:fixnum
    :initform 0)
   (obstacleStatus
    :reader obstacleStatus
    :initarg :obstacleStatus
    :type cl:fixnum
    :initform 0)
   (obstacleBrakeLights
    :reader obstacleBrakeLights
    :initarg :obstacleBrakeLights
    :type cl:boolean
    :initform cl:nil)
   (cipvFlag
    :reader cipvFlag
    :initarg :cipvFlag
    :type cl:fixnum
    :initform 0)
   (obstacleReplaced
    :reader obstacleReplaced
    :initarg :obstacleReplaced
    :type cl:fixnum
    :initform 0)
   (obstacleValid
    :reader obstacleValid
    :initarg :obstacleValid
    :type cl:fixnum
    :initform 0)
   (obstacleAge
    :reader obstacleAge
    :initarg :obstacleAge
    :type cl:fixnum
    :initform 0)
   (obstacleLane
    :reader obstacleLane
    :initarg :obstacleLane
    :type cl:fixnum
    :initform 0)
   (obstacleAngle
    :reader obstacleAngle
    :initarg :obstacleAngle
    :type cl:float
    :initform 0.0)
   (obstacleAngleVariance
    :reader obstacleAngleVariance
    :initarg :obstacleAngleVariance
    :type cl:float
    :initform 0.0)
   (obstacleAngleRate
    :reader obstacleAngleRate
    :initarg :obstacleAngleRate
    :type cl:float
    :initform 0.0)
   (obstacleScaleChange
    :reader obstacleScaleChange
    :initarg :obstacleScaleChange
    :type cl:float
    :initform 0.0)
   (vision_only_sign_type
    :reader vision_only_sign_type
    :initarg :vision_only_sign_type
    :type cl:fixnum
    :initform 0)
   (visionOnlySupplementarySignType
    :reader visionOnlySupplementarySignType
    :initarg :visionOnlySupplementarySignType
    :type cl:fixnum
    :initform 0)
   (signPosition
    :reader signPosition
    :initarg :signPosition
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (filterType
    :reader filterType
    :initarg :filterType
    :type cl:float
    :initform 0.0)
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
   (obstacleRelativeVelocityVariance
    :reader obstacleRelativeVelocityVariance
    :initarg :obstacleRelativeVelocityVariance
    :type geometry_msgs-msg:Twist
    :initform (cl:make-instance 'geometry_msgs-msg:Twist))
   (groundHeight
    :reader groundHeight
    :initarg :groundHeight
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (classificationProbability
    :reader classificationProbability
    :initarg :classificationProbability
    :type cl:float
    :initform 0.0)
   (dateAcquisition
    :reader dateAcquisition
    :initarg :dateAcquisition
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64))
   (obstacleClass
    :reader obstacleClass
    :initarg :obstacleClass
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ObstacleAlignment (<ObstacleAlignment>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ObstacleAlignment>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ObstacleAlignment)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ObstacleAlignment> is deprecated: use project_s_msgs-msg:ObstacleAlignment instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'obstaclePosition-val :lambda-list '(m))
(cl:defmethod obstaclePosition-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstaclePosition-val is deprecated.  Use project_s_msgs-msg:obstaclePosition instead.")
  (obstaclePosition m))

(cl:ensure-generic-function 'obstacleBodyCenter-val :lambda-list '(m))
(cl:defmethod obstacleBodyCenter-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleBodyCenter-val is deprecated.  Use project_s_msgs-msg:obstacleBodyCenter instead.")
  (obstacleBodyCenter m))

(cl:ensure-generic-function 'obstacleVelocity-val :lambda-list '(m))
(cl:defmethod obstacleVelocity-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleVelocity-val is deprecated.  Use project_s_msgs-msg:obstacleVelocity instead.")
  (obstacleVelocity m))

(cl:ensure-generic-function 'obstacleRelativeVelocity-val :lambda-list '(m))
(cl:defmethod obstacleRelativeVelocity-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleRelativeVelocity-val is deprecated.  Use project_s_msgs-msg:obstacleRelativeVelocity instead.")
  (obstacleRelativeVelocity m))

(cl:ensure-generic-function 'obstacleAcceleration-val :lambda-list '(m))
(cl:defmethod obstacleAcceleration-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleAcceleration-val is deprecated.  Use project_s_msgs-msg:obstacleAcceleration instead.")
  (obstacleAcceleration m))

(cl:ensure-generic-function 'obstacleDimensions-val :lambda-list '(m))
(cl:defmethod obstacleDimensions-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleDimensions-val is deprecated.  Use project_s_msgs-msg:obstacleDimensions instead.")
  (obstacleDimensions m))

(cl:ensure-generic-function 'blinkerInfo-val :lambda-list '(m))
(cl:defmethod blinkerInfo-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:blinkerInfo-val is deprecated.  Use project_s_msgs-msg:blinkerInfo instead.")
  (blinkerInfo m))

(cl:ensure-generic-function 'cutInAndOut-val :lambda-list '(m))
(cl:defmethod cutInAndOut-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:cutInAndOut-val is deprecated.  Use project_s_msgs-msg:cutInAndOut instead.")
  (cutInAndOut m))

(cl:ensure-generic-function 'obstacleType-val :lambda-list '(m))
(cl:defmethod obstacleType-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleType-val is deprecated.  Use project_s_msgs-msg:obstacleType instead.")
  (obstacleType m))

(cl:ensure-generic-function 'obstacleStatus-val :lambda-list '(m))
(cl:defmethod obstacleStatus-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleStatus-val is deprecated.  Use project_s_msgs-msg:obstacleStatus instead.")
  (obstacleStatus m))

(cl:ensure-generic-function 'obstacleBrakeLights-val :lambda-list '(m))
(cl:defmethod obstacleBrakeLights-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleBrakeLights-val is deprecated.  Use project_s_msgs-msg:obstacleBrakeLights instead.")
  (obstacleBrakeLights m))

(cl:ensure-generic-function 'cipvFlag-val :lambda-list '(m))
(cl:defmethod cipvFlag-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:cipvFlag-val is deprecated.  Use project_s_msgs-msg:cipvFlag instead.")
  (cipvFlag m))

(cl:ensure-generic-function 'obstacleReplaced-val :lambda-list '(m))
(cl:defmethod obstacleReplaced-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleReplaced-val is deprecated.  Use project_s_msgs-msg:obstacleReplaced instead.")
  (obstacleReplaced m))

(cl:ensure-generic-function 'obstacleValid-val :lambda-list '(m))
(cl:defmethod obstacleValid-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleValid-val is deprecated.  Use project_s_msgs-msg:obstacleValid instead.")
  (obstacleValid m))

(cl:ensure-generic-function 'obstacleAge-val :lambda-list '(m))
(cl:defmethod obstacleAge-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleAge-val is deprecated.  Use project_s_msgs-msg:obstacleAge instead.")
  (obstacleAge m))

(cl:ensure-generic-function 'obstacleLane-val :lambda-list '(m))
(cl:defmethod obstacleLane-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleLane-val is deprecated.  Use project_s_msgs-msg:obstacleLane instead.")
  (obstacleLane m))

(cl:ensure-generic-function 'obstacleAngle-val :lambda-list '(m))
(cl:defmethod obstacleAngle-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleAngle-val is deprecated.  Use project_s_msgs-msg:obstacleAngle instead.")
  (obstacleAngle m))

(cl:ensure-generic-function 'obstacleAngleVariance-val :lambda-list '(m))
(cl:defmethod obstacleAngleVariance-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleAngleVariance-val is deprecated.  Use project_s_msgs-msg:obstacleAngleVariance instead.")
  (obstacleAngleVariance m))

(cl:ensure-generic-function 'obstacleAngleRate-val :lambda-list '(m))
(cl:defmethod obstacleAngleRate-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleAngleRate-val is deprecated.  Use project_s_msgs-msg:obstacleAngleRate instead.")
  (obstacleAngleRate m))

(cl:ensure-generic-function 'obstacleScaleChange-val :lambda-list '(m))
(cl:defmethod obstacleScaleChange-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleScaleChange-val is deprecated.  Use project_s_msgs-msg:obstacleScaleChange instead.")
  (obstacleScaleChange m))

(cl:ensure-generic-function 'vision_only_sign_type-val :lambda-list '(m))
(cl:defmethod vision_only_sign_type-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:vision_only_sign_type-val is deprecated.  Use project_s_msgs-msg:vision_only_sign_type instead.")
  (vision_only_sign_type m))

(cl:ensure-generic-function 'visionOnlySupplementarySignType-val :lambda-list '(m))
(cl:defmethod visionOnlySupplementarySignType-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:visionOnlySupplementarySignType-val is deprecated.  Use project_s_msgs-msg:visionOnlySupplementarySignType instead.")
  (visionOnlySupplementarySignType m))

(cl:ensure-generic-function 'signPosition-val :lambda-list '(m))
(cl:defmethod signPosition-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:signPosition-val is deprecated.  Use project_s_msgs-msg:signPosition instead.")
  (signPosition m))

(cl:ensure-generic-function 'filterType-val :lambda-list '(m))
(cl:defmethod filterType-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:filterType-val is deprecated.  Use project_s_msgs-msg:filterType instead.")
  (filterType m))

(cl:ensure-generic-function 'obstaclePoseVariance-val :lambda-list '(m))
(cl:defmethod obstaclePoseVariance-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstaclePoseVariance-val is deprecated.  Use project_s_msgs-msg:obstaclePoseVariance instead.")
  (obstaclePoseVariance m))

(cl:ensure-generic-function 'obstacleVelocityVariance-val :lambda-list '(m))
(cl:defmethod obstacleVelocityVariance-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleVelocityVariance-val is deprecated.  Use project_s_msgs-msg:obstacleVelocityVariance instead.")
  (obstacleVelocityVariance m))

(cl:ensure-generic-function 'obstacleRelativeVelocityVariance-val :lambda-list '(m))
(cl:defmethod obstacleRelativeVelocityVariance-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleRelativeVelocityVariance-val is deprecated.  Use project_s_msgs-msg:obstacleRelativeVelocityVariance instead.")
  (obstacleRelativeVelocityVariance m))

(cl:ensure-generic-function 'groundHeight-val :lambda-list '(m))
(cl:defmethod groundHeight-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:groundHeight-val is deprecated.  Use project_s_msgs-msg:groundHeight instead.")
  (groundHeight m))

(cl:ensure-generic-function 'classificationProbability-val :lambda-list '(m))
(cl:defmethod classificationProbability-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:classificationProbability-val is deprecated.  Use project_s_msgs-msg:classificationProbability instead.")
  (classificationProbability m))

(cl:ensure-generic-function 'dateAcquisition-val :lambda-list '(m))
(cl:defmethod dateAcquisition-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:dateAcquisition-val is deprecated.  Use project_s_msgs-msg:dateAcquisition instead.")
  (dateAcquisition m))

(cl:ensure-generic-function 'obstacleClass-val :lambda-list '(m))
(cl:defmethod obstacleClass-val ((m <ObstacleAlignment>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleClass-val is deprecated.  Use project_s_msgs-msg:obstacleClass instead.")
  (obstacleClass m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<ObstacleAlignment>)))
    "Constants for message type '<ObstacleAlignment>"
  '((:OBSTACLEPOSITION_LINEAR_UNKNOWN . 999.0)
    (:OBSTACLEPOSITION_ORIENTATION_UNKNOWN . 999.0)
    (:OBSTACLEVELOCITY_LINEAR_UNKNOWN . 999.0)
    (:OBSTACLEVELOCITY_ANGULAR_UNKNOWN . 999.0)
    (:OBSTACLERELATIVEVELOCITY_LINEAR_UNKNOWN . 999.0)
    (:OBSTACLERELATIVEVELOCITY_ANGULAR_UNKNOWN . 999.0)
    (:OBSTACLEACCELERATION_LINEAR_UNKNOWN . 999.0)
    (:OBSTACLEACCELERATION_ANGULAR_UNKNOWN . 999.0)
    (:OBSTACLEDIMENSIONS_UNKNOWN . 999.0)
    (:BLINKERINFO_UNKNOWN . 0)
    (:CUTINANDOUT_UNKNOWN . 0)
    (:OBSTACLETYPE_UNKNOWN . 7)
    (:OBSTACLESTATUS_UNKNOWN . 0)
    (:OBSTACLEBRAKELIGHTS_UNKNOWN . False)
    (:CIPVFLAG_UNKNOWN . 2)
    (:OBSTACLEREPLACED_UNKNOWN . 2)
    (:OBSTACLEVALID_UNKNOWN . 3)
    (:OBSTACLEAGE_UNKNOWN . 256)
    (:OBSTACLELANE_UNKNOWN . 0)
    (:OBSTACLEANGLE_UNKNOWN . 999.0)
    (:OBSTACLEANGLEVARIANCE_UNKNOWN . -1.0)
    (:OBSTACLEANGLERATE_UNKNOWN . 999.0)
    (:OBSTACLESCALECHANGE_UNKNOWN . 999.0)
    (:VISIONONLYSIGNTYPE_UNKNOWN . 254)
    (:VISIONONLYSUPPLEMENTARYSIGNTYPE_UNKNOWN . 0)
    (:SIGNPOSITION_UNKNOWN . 999.0)
    (:FILTERTYPE_UNKNOWN . 999.0)
    (:OBSTACLEPOSEVARIANCE_POSITION_UNKNOWN . -1.0)
    (:OBSTACLEPOSEVARIANCE_ORIENTATION_UNKNOWN . -1.0)
    (:OBSTACLEVELOCITYVARIANCE_LINEAR_UNKNOWN . -1.0)
    (:OBSTACLEVELOCITYVARIANCE_ANGULAR_UNKNOWN . -1.0)
    (:OBSTACLERELATIVEVELOCITYVARIANCE_LINEAR_UNKNOWN . -1.0)
    (:OBSTACLERELATIVEVELOCITYVARIANCE_ANGULAR_UNKNOWN . -1.0)
    (:GROUNDHEIGHT_UNKNOWN . 999.0)
    (:CLASSIFICATIONPROBABILITY_UNKNOWN . 999.0)
    (:DATEACQUISITION_UNKNOWN . 999.0))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'ObstacleAlignment)))
    "Constants for message type 'ObstacleAlignment"
  '((:OBSTACLEPOSITION_LINEAR_UNKNOWN . 999.0)
    (:OBSTACLEPOSITION_ORIENTATION_UNKNOWN . 999.0)
    (:OBSTACLEVELOCITY_LINEAR_UNKNOWN . 999.0)
    (:OBSTACLEVELOCITY_ANGULAR_UNKNOWN . 999.0)
    (:OBSTACLERELATIVEVELOCITY_LINEAR_UNKNOWN . 999.0)
    (:OBSTACLERELATIVEVELOCITY_ANGULAR_UNKNOWN . 999.0)
    (:OBSTACLEACCELERATION_LINEAR_UNKNOWN . 999.0)
    (:OBSTACLEACCELERATION_ANGULAR_UNKNOWN . 999.0)
    (:OBSTACLEDIMENSIONS_UNKNOWN . 999.0)
    (:BLINKERINFO_UNKNOWN . 0)
    (:CUTINANDOUT_UNKNOWN . 0)
    (:OBSTACLETYPE_UNKNOWN . 7)
    (:OBSTACLESTATUS_UNKNOWN . 0)
    (:OBSTACLEBRAKELIGHTS_UNKNOWN . False)
    (:CIPVFLAG_UNKNOWN . 2)
    (:OBSTACLEREPLACED_UNKNOWN . 2)
    (:OBSTACLEVALID_UNKNOWN . 3)
    (:OBSTACLEAGE_UNKNOWN . 256)
    (:OBSTACLELANE_UNKNOWN . 0)
    (:OBSTACLEANGLE_UNKNOWN . 999.0)
    (:OBSTACLEANGLEVARIANCE_UNKNOWN . -1.0)
    (:OBSTACLEANGLERATE_UNKNOWN . 999.0)
    (:OBSTACLESCALECHANGE_UNKNOWN . 999.0)
    (:VISIONONLYSIGNTYPE_UNKNOWN . 254)
    (:VISIONONLYSUPPLEMENTARYSIGNTYPE_UNKNOWN . 0)
    (:SIGNPOSITION_UNKNOWN . 999.0)
    (:FILTERTYPE_UNKNOWN . 999.0)
    (:OBSTACLEPOSEVARIANCE_POSITION_UNKNOWN . -1.0)
    (:OBSTACLEPOSEVARIANCE_ORIENTATION_UNKNOWN . -1.0)
    (:OBSTACLEVELOCITYVARIANCE_LINEAR_UNKNOWN . -1.0)
    (:OBSTACLEVELOCITYVARIANCE_ANGULAR_UNKNOWN . -1.0)
    (:OBSTACLERELATIVEVELOCITYVARIANCE_LINEAR_UNKNOWN . -1.0)
    (:OBSTACLERELATIVEVELOCITYVARIANCE_ANGULAR_UNKNOWN . -1.0)
    (:GROUNDHEIGHT_UNKNOWN . 999.0)
    (:CLASSIFICATIONPROBABILITY_UNKNOWN . 999.0)
    (:DATEACQUISITION_UNKNOWN . 999.0))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ObstacleAlignment>) ostream)
  "Serializes a message object of type '<ObstacleAlignment>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstaclePosition) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleBodyCenter) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleVelocity) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleRelativeVelocity) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleAcceleration) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleDimensions) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'blinkerInfo)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cutInAndOut)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleType)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleStatus)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'obstacleBrakeLights) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'cipvFlag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'obstacleReplaced)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleValid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleAge)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'obstacleAge)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleLane)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'obstacleAngle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'obstacleAngleVariance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'obstacleAngleRate))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'obstacleScaleChange))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vision_only_sign_type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'visionOnlySupplementarySignType)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'signPosition) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'filterType))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstaclePoseVariance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleVelocityVariance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleRelativeVelocityVariance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'groundHeight) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'classificationProbability))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'dateAcquisition) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleClass)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ObstacleAlignment>) istream)
  "Deserializes a message object of type '<ObstacleAlignment>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstaclePosition) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleBodyCenter) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleVelocity) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleRelativeVelocity) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleAcceleration) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleDimensions) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'blinkerInfo)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'cutInAndOut)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleType)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleStatus)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'obstacleBrakeLights) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cipvFlag) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'obstacleReplaced) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleValid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleAge)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'obstacleAge)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleLane)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'obstacleAngle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'obstacleAngleVariance) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'obstacleAngleRate) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'obstacleScaleChange) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vision_only_sign_type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'visionOnlySupplementarySignType)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'signPosition) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'filterType) (roslisp-utils:decode-double-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstaclePoseVariance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleVelocityVariance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleRelativeVelocityVariance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'groundHeight) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'classificationProbability) (roslisp-utils:decode-double-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'dateAcquisition) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleClass)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ObstacleAlignment>)))
  "Returns string type for a message object of type '<ObstacleAlignment>"
  "project_s_msgs/ObstacleAlignment")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ObstacleAlignment)))
  "Returns string type for a message object of type 'ObstacleAlignment"
  "project_s_msgs/ObstacleAlignment")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ObstacleAlignment>)))
  "Returns md5sum for a message object of type '<ObstacleAlignment>"
  "04280698b06b552ba012942a850d8950")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ObstacleAlignment)))
  "Returns md5sum for a message object of type 'ObstacleAlignment"
  "04280698b06b552ba012942a850d8950")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ObstacleAlignment>)))
  "Returns full string definition for message of type '<ObstacleAlignment>"
  (cl:format cl:nil "Header header~%std_msgs/UInt16 id~%~%geometry_msgs/Pose obstaclePosition	        		# obstacle position~%float64 obstaclePosition_linear_Unknown = 999~%float64 obstaclePosition_orientation_Unknown = 999~%~%geometry_msgs/Pose obstacleBodyCenter	        		# Obstacle Center for Corner Computation~%~%geometry_msgs/Twist obstacleVelocity	                    	# obstacle speed~%float64 obstacleVelocity_linear_Unknown = 999~%float64 obstacleVelocity_angular_Unknown = 999~%~%geometry_msgs/Twist obstacleRelativeVelocity	           	# obstacle relative velocity~%float64 obstacleRelativeVelocity_linear_Unknown = 999~%float64 obstacleRelativeVelocity_angular_Unknown = 999~%~%geometry_msgs/Accel obstacleAcceleration        		# obstacle acceleration~%float64 obstacleAcceleration_linear_Unknown = 999~%float64 obstacleAcceleration_angular_Unknown = 999~%~%geometry_msgs/Vector3 obstacleDimensions        		# obstacle - length and width~%float64 obstacleDimensions_Unknown = 999~%~%uint8 blinkerInfo                               		# blinker status (eg. left blinker on)~%uint8 blinkerInfo_Unknown=0~%~%uint8 cutInAndOut                               		# Vehicle cutting in or out of ego lane ~%uint8 cutInAndOut_Unknown=0~%~%uint8 obstacleType                             			# obstacle classification~%uint8 obstacleType_Unknown=7~%~%uint8 obstacleStatus                            		# obstacle’s moving status~%uint8 obstacleStatus_Unknown=0~%~%bool obstacleBrakeLights                        		# obstacle brake light on or off~%bool obstacleBrakeLights_Unknown=0 ~%~%int8 cipvFlag                                   		# If obstacle Closest in Path Vehicle~%int8 cipvFlag_Unknown=2~%~%int8 obstacleReplaced                           		# If obstacle replaced in this frame~%int8 obstacleReplaced_Unknown=2~%~%uint8 obstacleValid                             		# obstacle valid~%uint8 obstacleValid_Unknown=3~%~%uint16 obstacleAge                              		# obstacle age in number of frames~%uint16 obstacleAge_Unknown=256~%~%uint8 obstacleLane                              		# obstacle's lane (eg. ego lane or next lane)~%uint8 obstacleLane_Unknown=0~%~%float32 obstacleAngle                           		# angle to center of obstacle in degrees~%float32 obstacleAngle_Unknown = 999~%~%float32 obstacleAngleVariance                   		# Obstacle angle Variance (Lidar)~%float32 obstacleAngleVariance_Unknown=-1~%~%float32 obstacleAngleRate                       		# angle rate of the center of obstacle (degrees/sec)~%float32 obstacleAngleRate_Unknown = 999~%~%float64 obstacleScaleChange                     		# scale change from previous frame   ~%float64 obstacleScaleChange_Unknown = 999~%                           ~%uint8 vision_only_sign_type~%#uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type~%uint8 visionOnlySignType_Unknown=254~%~%uint8 visionOnlySupplementarySignType               		# Supplementary sign type - rain, snow, arrow etc. ~%uint8 visionOnlySupplementarySignType_Unknown=0~%~%geometry_msgs/Vector3 signPosition                  		# X-Longitudnal position, Y-Lateral position ,Z-Height of sign relative to ME~%float64 signPosition_Unknown = 999~%~%float64 filterType                                    		# filtering ~%float64 filterType_Unknown = 999~%~%geometry_msgs/Pose obstaclePoseVariance		                # obstacle position variance~%float64 obstaclePoseVariance_position_Unknown = -1~%float64 obstaclePoseVariance_orientation_Unknown = -1~%~%geometry_msgs/Twist obstacleVelocityVariance	                # obstacle speed variance~%float64 obstacleVelocityVariance_linear_Unknown = -1~%float64 obstacleVelocityVariance_angular_Unknown = -1~%~%geometry_msgs/Twist obstacleRelativeVelocityVariance	        # obstacle relative velocity variance~%float64 obstacleRelativeVelocityVariance_linear_Unknown = -1~%float64 obstacleRelativeVelocityVariance_angular_Unknown = -1~%~%std_msgs/Float32 groundHeight			                # ground height~%float64 groundHeight_Unknown = 999~%~%float64 classificationProbability~%float64 classificationProbability_Unknown = 999~%~%std_msgs/Float64 dateAcquisition~%float64 dateAcquisition_Unknown = 999~%~%uint8 obstacleClass~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ObstacleAlignment)))
  "Returns full string definition for message of type 'ObstacleAlignment"
  (cl:format cl:nil "Header header~%std_msgs/UInt16 id~%~%geometry_msgs/Pose obstaclePosition	        		# obstacle position~%float64 obstaclePosition_linear_Unknown = 999~%float64 obstaclePosition_orientation_Unknown = 999~%~%geometry_msgs/Pose obstacleBodyCenter	        		# Obstacle Center for Corner Computation~%~%geometry_msgs/Twist obstacleVelocity	                    	# obstacle speed~%float64 obstacleVelocity_linear_Unknown = 999~%float64 obstacleVelocity_angular_Unknown = 999~%~%geometry_msgs/Twist obstacleRelativeVelocity	           	# obstacle relative velocity~%float64 obstacleRelativeVelocity_linear_Unknown = 999~%float64 obstacleRelativeVelocity_angular_Unknown = 999~%~%geometry_msgs/Accel obstacleAcceleration        		# obstacle acceleration~%float64 obstacleAcceleration_linear_Unknown = 999~%float64 obstacleAcceleration_angular_Unknown = 999~%~%geometry_msgs/Vector3 obstacleDimensions        		# obstacle - length and width~%float64 obstacleDimensions_Unknown = 999~%~%uint8 blinkerInfo                               		# blinker status (eg. left blinker on)~%uint8 blinkerInfo_Unknown=0~%~%uint8 cutInAndOut                               		# Vehicle cutting in or out of ego lane ~%uint8 cutInAndOut_Unknown=0~%~%uint8 obstacleType                             			# obstacle classification~%uint8 obstacleType_Unknown=7~%~%uint8 obstacleStatus                            		# obstacle’s moving status~%uint8 obstacleStatus_Unknown=0~%~%bool obstacleBrakeLights                        		# obstacle brake light on or off~%bool obstacleBrakeLights_Unknown=0 ~%~%int8 cipvFlag                                   		# If obstacle Closest in Path Vehicle~%int8 cipvFlag_Unknown=2~%~%int8 obstacleReplaced                           		# If obstacle replaced in this frame~%int8 obstacleReplaced_Unknown=2~%~%uint8 obstacleValid                             		# obstacle valid~%uint8 obstacleValid_Unknown=3~%~%uint16 obstacleAge                              		# obstacle age in number of frames~%uint16 obstacleAge_Unknown=256~%~%uint8 obstacleLane                              		# obstacle's lane (eg. ego lane or next lane)~%uint8 obstacleLane_Unknown=0~%~%float32 obstacleAngle                           		# angle to center of obstacle in degrees~%float32 obstacleAngle_Unknown = 999~%~%float32 obstacleAngleVariance                   		# Obstacle angle Variance (Lidar)~%float32 obstacleAngleVariance_Unknown=-1~%~%float32 obstacleAngleRate                       		# angle rate of the center of obstacle (degrees/sec)~%float32 obstacleAngleRate_Unknown = 999~%~%float64 obstacleScaleChange                     		# scale change from previous frame   ~%float64 obstacleScaleChange_Unknown = 999~%                           ~%uint8 vision_only_sign_type~%#uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type~%uint8 visionOnlySignType_Unknown=254~%~%uint8 visionOnlySupplementarySignType               		# Supplementary sign type - rain, snow, arrow etc. ~%uint8 visionOnlySupplementarySignType_Unknown=0~%~%geometry_msgs/Vector3 signPosition                  		# X-Longitudnal position, Y-Lateral position ,Z-Height of sign relative to ME~%float64 signPosition_Unknown = 999~%~%float64 filterType                                    		# filtering ~%float64 filterType_Unknown = 999~%~%geometry_msgs/Pose obstaclePoseVariance		                # obstacle position variance~%float64 obstaclePoseVariance_position_Unknown = -1~%float64 obstaclePoseVariance_orientation_Unknown = -1~%~%geometry_msgs/Twist obstacleVelocityVariance	                # obstacle speed variance~%float64 obstacleVelocityVariance_linear_Unknown = -1~%float64 obstacleVelocityVariance_angular_Unknown = -1~%~%geometry_msgs/Twist obstacleRelativeVelocityVariance	        # obstacle relative velocity variance~%float64 obstacleRelativeVelocityVariance_linear_Unknown = -1~%float64 obstacleRelativeVelocityVariance_angular_Unknown = -1~%~%std_msgs/Float32 groundHeight			                # ground height~%float64 groundHeight_Unknown = 999~%~%float64 classificationProbability~%float64 classificationProbability_Unknown = 999~%~%std_msgs/Float64 dateAcquisition~%float64 dateAcquisition_Unknown = 999~%~%uint8 obstacleClass~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ObstacleAlignment>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstaclePosition))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleBodyCenter))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleVelocity))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleRelativeVelocity))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleAcceleration))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleDimensions))
     1
     1
     1
     1
     1
     1
     1
     1
     2
     1
     4
     4
     4
     8
     1
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'signPosition))
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstaclePoseVariance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleVelocityVariance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleRelativeVelocityVariance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'groundHeight))
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'dateAcquisition))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ObstacleAlignment>))
  "Converts a ROS message object to a list"
  (cl:list 'ObstacleAlignment
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':obstaclePosition (obstaclePosition msg))
    (cl:cons ':obstacleBodyCenter (obstacleBodyCenter msg))
    (cl:cons ':obstacleVelocity (obstacleVelocity msg))
    (cl:cons ':obstacleRelativeVelocity (obstacleRelativeVelocity msg))
    (cl:cons ':obstacleAcceleration (obstacleAcceleration msg))
    (cl:cons ':obstacleDimensions (obstacleDimensions msg))
    (cl:cons ':blinkerInfo (blinkerInfo msg))
    (cl:cons ':cutInAndOut (cutInAndOut msg))
    (cl:cons ':obstacleType (obstacleType msg))
    (cl:cons ':obstacleStatus (obstacleStatus msg))
    (cl:cons ':obstacleBrakeLights (obstacleBrakeLights msg))
    (cl:cons ':cipvFlag (cipvFlag msg))
    (cl:cons ':obstacleReplaced (obstacleReplaced msg))
    (cl:cons ':obstacleValid (obstacleValid msg))
    (cl:cons ':obstacleAge (obstacleAge msg))
    (cl:cons ':obstacleLane (obstacleLane msg))
    (cl:cons ':obstacleAngle (obstacleAngle msg))
    (cl:cons ':obstacleAngleVariance (obstacleAngleVariance msg))
    (cl:cons ':obstacleAngleRate (obstacleAngleRate msg))
    (cl:cons ':obstacleScaleChange (obstacleScaleChange msg))
    (cl:cons ':vision_only_sign_type (vision_only_sign_type msg))
    (cl:cons ':visionOnlySupplementarySignType (visionOnlySupplementarySignType msg))
    (cl:cons ':signPosition (signPosition msg))
    (cl:cons ':filterType (filterType msg))
    (cl:cons ':obstaclePoseVariance (obstaclePoseVariance msg))
    (cl:cons ':obstacleVelocityVariance (obstacleVelocityVariance msg))
    (cl:cons ':obstacleRelativeVelocityVariance (obstacleRelativeVelocityVariance msg))
    (cl:cons ':groundHeight (groundHeight msg))
    (cl:cons ':classificationProbability (classificationProbability msg))
    (cl:cons ':dateAcquisition (dateAcquisition msg))
    (cl:cons ':obstacleClass (obstacleClass msg))
))
