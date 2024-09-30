; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ObstacleFusion.msg.html

(cl:defclass <ObstacleFusion> (roslisp-msg-protocol:ros-message)
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
   (obstacleBodyCenter
    :reader obstacleBodyCenter
    :initarg :obstacleBodyCenter
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (distanceCurviligne
    :reader distanceCurviligne
    :initarg :distanceCurviligne
    :type cl:float
    :initform 0.0)
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
   (obstacleCap
    :reader obstacleCap
    :initarg :obstacleCap
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (existenceProbability
    :reader existenceProbability
    :initarg :existenceProbability
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (existenceState
    :reader existenceState
    :initarg :existenceState
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (scoreDetection
    :reader scoreDetection
    :initarg :scoreDetection
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (nbrDetection
    :reader nbrDetection
    :initarg :nbrDetection
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (nbrVisibility
    :reader nbrVisibility
    :initarg :nbrVisibility
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (scorePersistence
    :reader scorePersistence
    :initarg :scorePersistence
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (nbrUpdate
    :reader nbrUpdate
    :initarg :nbrUpdate
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (nbrAge
    :reader nbrAge
    :initarg :nbrAge
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (existenceFirstTime
    :reader existenceFirstTime
    :initarg :existenceFirstTime
    :type cl:real
    :initform 0)
   (existenceDurationTime
    :reader existenceDurationTime
    :initarg :existenceDurationTime
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (anchorPoint
    :reader anchorPoint
    :initarg :anchorPoint
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
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
   (obstacleDimensions
    :reader obstacleDimensions
    :initarg :obstacleDimensions
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (obstacleClass
    :reader obstacleClass
    :initarg :obstacleClass
    :type cl:fixnum
    :initform 0)
   (vision_only_sign_type
    :reader vision_only_sign_type
    :initarg :vision_only_sign_type
    :type cl:fixnum
    :initform 0)
   (classificationProbability
    :reader classificationProbability
    :initarg :classificationProbability
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (obstacleAssignment
    :reader obstacleAssignment
    :initarg :obstacleAssignment
    :type cl:fixnum
    :initform 0)
   (obstacleCorner
    :reader obstacleCorner
    :initarg :obstacleCorner
    :type (cl:vector geometry_msgs-msg:Point)
   :initform (cl:make-array 4 :element-type 'geometry_msgs-msg:Point :initial-element (cl:make-instance 'geometry_msgs-msg:Point)))
   (NbrOccupiedLane
    :reader NbrOccupiedLane
    :initarg :NbrOccupiedLane
    :type cl:fixnum
    :initform 0)
   (indexAssignmentLine
    :reader indexAssignmentLine
    :initarg :indexAssignmentLine
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 2 :element-type 'cl:fixnum :initial-element 0))
   (positionLane
    :reader positionLane
    :initarg :positionLane
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (departureRighttDistance
    :reader departureRighttDistance
    :initarg :departureRighttDistance
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (departureLeftDistance
    :reader departureLeftDistance
    :initarg :departureLeftDistance
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (trafficLights
    :reader trafficLights
    :initarg :trafficLights
    :type std_msgs-msg:Int16
    :initform (cl:make-instance 'std_msgs-msg:Int16))
   (vehicleLights
    :reader vehicleLights
    :initarg :vehicleLights
    :type std_msgs-msg:Int16
    :initform (cl:make-instance 'std_msgs-msg:Int16))
   (idPiste
    :reader idPiste
    :initarg :idPiste
    :type (cl:vector std_msgs-msg:UInt16)
   :initform (cl:make-array 3 :element-type 'std_msgs-msg:UInt16 :initial-element (cl:make-instance 'std_msgs-msg:UInt16))))
)

(cl:defclass ObstacleFusion (<ObstacleFusion>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ObstacleFusion>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ObstacleFusion)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ObstacleFusion> is deprecated: use project_s_msgs-msg:ObstacleFusion instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'obstaclePosition-val :lambda-list '(m))
(cl:defmethod obstaclePosition-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstaclePosition-val is deprecated.  Use project_s_msgs-msg:obstaclePosition instead.")
  (obstaclePosition m))

(cl:ensure-generic-function 'obstacleBodyCenter-val :lambda-list '(m))
(cl:defmethod obstacleBodyCenter-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleBodyCenter-val is deprecated.  Use project_s_msgs-msg:obstacleBodyCenter instead.")
  (obstacleBodyCenter m))

(cl:ensure-generic-function 'distanceCurviligne-val :lambda-list '(m))
(cl:defmethod distanceCurviligne-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:distanceCurviligne-val is deprecated.  Use project_s_msgs-msg:distanceCurviligne instead.")
  (distanceCurviligne m))

(cl:ensure-generic-function 'groundHeight-val :lambda-list '(m))
(cl:defmethod groundHeight-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:groundHeight-val is deprecated.  Use project_s_msgs-msg:groundHeight instead.")
  (groundHeight m))

(cl:ensure-generic-function 'obstacleVelocity-val :lambda-list '(m))
(cl:defmethod obstacleVelocity-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleVelocity-val is deprecated.  Use project_s_msgs-msg:obstacleVelocity instead.")
  (obstacleVelocity m))

(cl:ensure-generic-function 'obstacleAcceleration-val :lambda-list '(m))
(cl:defmethod obstacleAcceleration-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleAcceleration-val is deprecated.  Use project_s_msgs-msg:obstacleAcceleration instead.")
  (obstacleAcceleration m))

(cl:ensure-generic-function 'obstacleCap-val :lambda-list '(m))
(cl:defmethod obstacleCap-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleCap-val is deprecated.  Use project_s_msgs-msg:obstacleCap instead.")
  (obstacleCap m))

(cl:ensure-generic-function 'existenceProbability-val :lambda-list '(m))
(cl:defmethod existenceProbability-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:existenceProbability-val is deprecated.  Use project_s_msgs-msg:existenceProbability instead.")
  (existenceProbability m))

(cl:ensure-generic-function 'existenceState-val :lambda-list '(m))
(cl:defmethod existenceState-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:existenceState-val is deprecated.  Use project_s_msgs-msg:existenceState instead.")
  (existenceState m))

(cl:ensure-generic-function 'scoreDetection-val :lambda-list '(m))
(cl:defmethod scoreDetection-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:scoreDetection-val is deprecated.  Use project_s_msgs-msg:scoreDetection instead.")
  (scoreDetection m))

(cl:ensure-generic-function 'nbrDetection-val :lambda-list '(m))
(cl:defmethod nbrDetection-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbrDetection-val is deprecated.  Use project_s_msgs-msg:nbrDetection instead.")
  (nbrDetection m))

(cl:ensure-generic-function 'nbrVisibility-val :lambda-list '(m))
(cl:defmethod nbrVisibility-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbrVisibility-val is deprecated.  Use project_s_msgs-msg:nbrVisibility instead.")
  (nbrVisibility m))

(cl:ensure-generic-function 'scorePersistence-val :lambda-list '(m))
(cl:defmethod scorePersistence-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:scorePersistence-val is deprecated.  Use project_s_msgs-msg:scorePersistence instead.")
  (scorePersistence m))

(cl:ensure-generic-function 'nbrUpdate-val :lambda-list '(m))
(cl:defmethod nbrUpdate-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbrUpdate-val is deprecated.  Use project_s_msgs-msg:nbrUpdate instead.")
  (nbrUpdate m))

(cl:ensure-generic-function 'nbrAge-val :lambda-list '(m))
(cl:defmethod nbrAge-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbrAge-val is deprecated.  Use project_s_msgs-msg:nbrAge instead.")
  (nbrAge m))

(cl:ensure-generic-function 'existenceFirstTime-val :lambda-list '(m))
(cl:defmethod existenceFirstTime-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:existenceFirstTime-val is deprecated.  Use project_s_msgs-msg:existenceFirstTime instead.")
  (existenceFirstTime m))

(cl:ensure-generic-function 'existenceDurationTime-val :lambda-list '(m))
(cl:defmethod existenceDurationTime-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:existenceDurationTime-val is deprecated.  Use project_s_msgs-msg:existenceDurationTime instead.")
  (existenceDurationTime m))

(cl:ensure-generic-function 'anchorPoint-val :lambda-list '(m))
(cl:defmethod anchorPoint-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:anchorPoint-val is deprecated.  Use project_s_msgs-msg:anchorPoint instead.")
  (anchorPoint m))

(cl:ensure-generic-function 'obstaclePoseVariance-val :lambda-list '(m))
(cl:defmethod obstaclePoseVariance-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstaclePoseVariance-val is deprecated.  Use project_s_msgs-msg:obstaclePoseVariance instead.")
  (obstaclePoseVariance m))

(cl:ensure-generic-function 'obstacleVelocityVariance-val :lambda-list '(m))
(cl:defmethod obstacleVelocityVariance-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleVelocityVariance-val is deprecated.  Use project_s_msgs-msg:obstacleVelocityVariance instead.")
  (obstacleVelocityVariance m))

(cl:ensure-generic-function 'obstacleDimensions-val :lambda-list '(m))
(cl:defmethod obstacleDimensions-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleDimensions-val is deprecated.  Use project_s_msgs-msg:obstacleDimensions instead.")
  (obstacleDimensions m))

(cl:ensure-generic-function 'obstacleClass-val :lambda-list '(m))
(cl:defmethod obstacleClass-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleClass-val is deprecated.  Use project_s_msgs-msg:obstacleClass instead.")
  (obstacleClass m))

(cl:ensure-generic-function 'vision_only_sign_type-val :lambda-list '(m))
(cl:defmethod vision_only_sign_type-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:vision_only_sign_type-val is deprecated.  Use project_s_msgs-msg:vision_only_sign_type instead.")
  (vision_only_sign_type m))

(cl:ensure-generic-function 'classificationProbability-val :lambda-list '(m))
(cl:defmethod classificationProbability-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:classificationProbability-val is deprecated.  Use project_s_msgs-msg:classificationProbability instead.")
  (classificationProbability m))

(cl:ensure-generic-function 'obstacleAssignment-val :lambda-list '(m))
(cl:defmethod obstacleAssignment-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleAssignment-val is deprecated.  Use project_s_msgs-msg:obstacleAssignment instead.")
  (obstacleAssignment m))

(cl:ensure-generic-function 'obstacleCorner-val :lambda-list '(m))
(cl:defmethod obstacleCorner-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:obstacleCorner-val is deprecated.  Use project_s_msgs-msg:obstacleCorner instead.")
  (obstacleCorner m))

(cl:ensure-generic-function 'NbrOccupiedLane-val :lambda-list '(m))
(cl:defmethod NbrOccupiedLane-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:NbrOccupiedLane-val is deprecated.  Use project_s_msgs-msg:NbrOccupiedLane instead.")
  (NbrOccupiedLane m))

(cl:ensure-generic-function 'indexAssignmentLine-val :lambda-list '(m))
(cl:defmethod indexAssignmentLine-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:indexAssignmentLine-val is deprecated.  Use project_s_msgs-msg:indexAssignmentLine instead.")
  (indexAssignmentLine m))

(cl:ensure-generic-function 'positionLane-val :lambda-list '(m))
(cl:defmethod positionLane-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:positionLane-val is deprecated.  Use project_s_msgs-msg:positionLane instead.")
  (positionLane m))

(cl:ensure-generic-function 'departureRighttDistance-val :lambda-list '(m))
(cl:defmethod departureRighttDistance-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:departureRighttDistance-val is deprecated.  Use project_s_msgs-msg:departureRighttDistance instead.")
  (departureRighttDistance m))

(cl:ensure-generic-function 'departureLeftDistance-val :lambda-list '(m))
(cl:defmethod departureLeftDistance-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:departureLeftDistance-val is deprecated.  Use project_s_msgs-msg:departureLeftDistance instead.")
  (departureLeftDistance m))

(cl:ensure-generic-function 'trafficLights-val :lambda-list '(m))
(cl:defmethod trafficLights-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:trafficLights-val is deprecated.  Use project_s_msgs-msg:trafficLights instead.")
  (trafficLights m))

(cl:ensure-generic-function 'vehicleLights-val :lambda-list '(m))
(cl:defmethod vehicleLights-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:vehicleLights-val is deprecated.  Use project_s_msgs-msg:vehicleLights instead.")
  (vehicleLights m))

(cl:ensure-generic-function 'idPiste-val :lambda-list '(m))
(cl:defmethod idPiste-val ((m <ObstacleFusion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:idPiste-val is deprecated.  Use project_s_msgs-msg:idPiste instead.")
  (idPiste m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<ObstacleFusion>)))
    "Constants for message type '<ObstacleFusion>"
  '((:IDLE_TRACK . 0)
    (:PRE_TRACK . 1)
    (:POST_TRACK . 2)
    (:CURRENT_TRACK . 3)
    (:ASSIGNMENT_COTE_DROIT . 1)
    (:ASSIGNMENT_COTE_GAUCHE . 2)
    (:CORNER_FRONT_RIGHT . 0)
    (:CORNER_FRONT_LEFT . 1)
    (:CORNER_BACK_RIGHT . 2)
    (:CORNER_BACK_LEFT . 3)
    (:OCCUPIED_LANE_INDEFINI . 255)
    (:INDEX_LINE_INDEFINI . 255))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'ObstacleFusion)))
    "Constants for message type 'ObstacleFusion"
  '((:IDLE_TRACK . 0)
    (:PRE_TRACK . 1)
    (:POST_TRACK . 2)
    (:CURRENT_TRACK . 3)
    (:ASSIGNMENT_COTE_DROIT . 1)
    (:ASSIGNMENT_COTE_GAUCHE . 2)
    (:CORNER_FRONT_RIGHT . 0)
    (:CORNER_FRONT_LEFT . 1)
    (:CORNER_BACK_RIGHT . 2)
    (:CORNER_BACK_LEFT . 3)
    (:OCCUPIED_LANE_INDEFINI . 255)
    (:INDEX_LINE_INDEFINI . 255))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ObstacleFusion>) ostream)
  "Serializes a message object of type '<ObstacleFusion>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstaclePosition) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleBodyCenter) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'distanceCurviligne))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'groundHeight) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleVelocity) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleAcceleration) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleCap) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'existenceProbability) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'existenceState) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'scoreDetection) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbrDetection) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbrVisibility) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'scorePersistence) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbrUpdate) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbrAge) ostream)
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'existenceFirstTime)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'existenceFirstTime) (cl:floor (cl:slot-value msg 'existenceFirstTime)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'existenceDurationTime) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'anchorPoint) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstaclePoseVariance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleVelocityVariance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'obstacleDimensions) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleClass)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vision_only_sign_type)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'classificationProbability) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleAssignment)) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'obstacleCorner))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'NbrOccupiedLane)) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'indexAssignmentLine))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'positionLane) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'departureRighttDistance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'departureLeftDistance) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'trafficLights) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vehicleLights) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'idPiste))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ObstacleFusion>) istream)
  "Deserializes a message object of type '<ObstacleFusion>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstaclePosition) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleBodyCenter) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distanceCurviligne) (roslisp-utils:decode-single-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'groundHeight) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleVelocity) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleAcceleration) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleCap) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'existenceProbability) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'existenceState) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'scoreDetection) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbrDetection) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbrVisibility) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'scorePersistence) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbrUpdate) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbrAge) istream)
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'existenceFirstTime) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'existenceDurationTime) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'anchorPoint) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstaclePoseVariance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleVelocityVariance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'obstacleDimensions) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleClass)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vision_only_sign_type)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'classificationProbability) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'obstacleAssignment)) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'obstacleCorner) (cl:make-array 4))
  (cl:let ((vals (cl:slot-value msg 'obstacleCorner)))
    (cl:dotimes (i 4)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'NbrOccupiedLane)) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'indexAssignmentLine) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'indexAssignmentLine)))
    (cl:dotimes (i 2)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'positionLane) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'departureRighttDistance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'departureLeftDistance) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'trafficLights) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vehicleLights) istream)
  (cl:setf (cl:slot-value msg 'idPiste) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'idPiste)))
    (cl:dotimes (i 3)
    (cl:setf (cl:aref vals i) (cl:make-instance 'std_msgs-msg:UInt16))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ObstacleFusion>)))
  "Returns string type for a message object of type '<ObstacleFusion>"
  "project_s_msgs/ObstacleFusion")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ObstacleFusion)))
  "Returns string type for a message object of type 'ObstacleFusion"
  "project_s_msgs/ObstacleFusion")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ObstacleFusion>)))
  "Returns md5sum for a message object of type '<ObstacleFusion>"
  "664d48d67f466ce15a45b6a2d40f7977")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ObstacleFusion)))
  "Returns md5sum for a message object of type 'ObstacleFusion"
  "664d48d67f466ce15a45b6a2d40f7977")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ObstacleFusion>)))
  "Returns full string definition for message of type '<ObstacleFusion>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Pose obstaclePosition		# obstacle position~%geometry_msgs/Pose obstacleBodyCenter	        # Obstacle Center for Corner Computation~%float32 distanceCurviligne~%std_msgs/Float32 groundHeight			# ground height~%geometry_msgs/Twist obstacleVelocity		# obstacle speed~%geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration~%geometry_msgs/Vector3 obstacleCap~%std_msgs/UInt8 existenceProbability~%std_msgs/UInt8 existenceState~%uint8 IDLE_TRACK    = 0~%uint8 PRE_TRACK	    = 1~%uint8 POST_TRACK    = 2~%uint8 CURRENT_TRACK = 3~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%time existenceFirstTime~%std_msgs/Float32 existenceDurationTime~%std_msgs/UInt8 anchorPoint			# reference point~%geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance~%geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance~%geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height~%uint8 obstacleClass~%uint8 vision_only_sign_type~%std_msgs/UInt8 classificationProbability~%~%uint8 obstacleAssignment~%uint8 ASSIGNMENT_COTE_DROIT  = 1~%uint8 ASSIGNMENT_COTE_GAUCHE = 2~%~%uint8 CORNER_FRONT_RIGHT= 0~%uint8 CORNER_FRONT_LEFT = 1~%uint8 CORNER_BACK_RIGHT = 2~%uint8 CORNER_BACK_LEFT  = 3~%geometry_msgs/Point[4] obstacleCorner~%~%uint8 OCCUPIED_LANE_INDEFINI  = 255~%uint8 NbrOccupiedLane~%uint8 INDEX_LINE_INDEFINI  = 255~%uint8[2] indexAssignmentLine~%std_msgs/Float32 positionLane~%std_msgs/Float32 departureRighttDistance~%std_msgs/Float32 departureLeftDistance~%~%std_msgs/Int16 trafficLights~%std_msgs/Int16 vehicleLights~%std_msgs/UInt16[3] idPiste			#define NBR_SENSOR		3	(voir obstacles_fusion.cpp)~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Int16~%int16 data~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ObstacleFusion)))
  "Returns full string definition for message of type 'ObstacleFusion"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%geometry_msgs/Pose obstaclePosition		# obstacle position~%geometry_msgs/Pose obstacleBodyCenter	        # Obstacle Center for Corner Computation~%float32 distanceCurviligne~%std_msgs/Float32 groundHeight			# ground height~%geometry_msgs/Twist obstacleVelocity		# obstacle speed~%geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration~%geometry_msgs/Vector3 obstacleCap~%std_msgs/UInt8 existenceProbability~%std_msgs/UInt8 existenceState~%uint8 IDLE_TRACK    = 0~%uint8 PRE_TRACK	    = 1~%uint8 POST_TRACK    = 2~%uint8 CURRENT_TRACK = 3~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%time existenceFirstTime~%std_msgs/Float32 existenceDurationTime~%std_msgs/UInt8 anchorPoint			# reference point~%geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance~%geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance~%geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height~%uint8 obstacleClass~%uint8 vision_only_sign_type~%std_msgs/UInt8 classificationProbability~%~%uint8 obstacleAssignment~%uint8 ASSIGNMENT_COTE_DROIT  = 1~%uint8 ASSIGNMENT_COTE_GAUCHE = 2~%~%uint8 CORNER_FRONT_RIGHT= 0~%uint8 CORNER_FRONT_LEFT = 1~%uint8 CORNER_BACK_RIGHT = 2~%uint8 CORNER_BACK_LEFT  = 3~%geometry_msgs/Point[4] obstacleCorner~%~%uint8 OCCUPIED_LANE_INDEFINI  = 255~%uint8 NbrOccupiedLane~%uint8 INDEX_LINE_INDEFINI  = 255~%uint8[2] indexAssignmentLine~%std_msgs/Float32 positionLane~%std_msgs/Float32 departureRighttDistance~%std_msgs/Float32 departureLeftDistance~%~%std_msgs/Int16 trafficLights~%std_msgs/Int16 vehicleLights~%std_msgs/UInt16[3] idPiste			#define NBR_SENSOR		3	(voir obstacles_fusion.cpp)~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: std_msgs/Int16~%int16 data~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ObstacleFusion>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstaclePosition))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleBodyCenter))
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'groundHeight))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleVelocity))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleAcceleration))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleCap))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'existenceProbability))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'existenceState))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'scoreDetection))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbrDetection))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbrVisibility))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'scorePersistence))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbrUpdate))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbrAge))
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'existenceDurationTime))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'anchorPoint))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstaclePoseVariance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleVelocityVariance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'obstacleDimensions))
     1
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'classificationProbability))
     1
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'obstacleCorner) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     1
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'indexAssignmentLine) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'positionLane))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'departureRighttDistance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'departureLeftDistance))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'trafficLights))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vehicleLights))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'idPiste) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ObstacleFusion>))
  "Converts a ROS message object to a list"
  (cl:list 'ObstacleFusion
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':obstaclePosition (obstaclePosition msg))
    (cl:cons ':obstacleBodyCenter (obstacleBodyCenter msg))
    (cl:cons ':distanceCurviligne (distanceCurviligne msg))
    (cl:cons ':groundHeight (groundHeight msg))
    (cl:cons ':obstacleVelocity (obstacleVelocity msg))
    (cl:cons ':obstacleAcceleration (obstacleAcceleration msg))
    (cl:cons ':obstacleCap (obstacleCap msg))
    (cl:cons ':existenceProbability (existenceProbability msg))
    (cl:cons ':existenceState (existenceState msg))
    (cl:cons ':scoreDetection (scoreDetection msg))
    (cl:cons ':nbrDetection (nbrDetection msg))
    (cl:cons ':nbrVisibility (nbrVisibility msg))
    (cl:cons ':scorePersistence (scorePersistence msg))
    (cl:cons ':nbrUpdate (nbrUpdate msg))
    (cl:cons ':nbrAge (nbrAge msg))
    (cl:cons ':existenceFirstTime (existenceFirstTime msg))
    (cl:cons ':existenceDurationTime (existenceDurationTime msg))
    (cl:cons ':anchorPoint (anchorPoint msg))
    (cl:cons ':obstaclePoseVariance (obstaclePoseVariance msg))
    (cl:cons ':obstacleVelocityVariance (obstacleVelocityVariance msg))
    (cl:cons ':obstacleDimensions (obstacleDimensions msg))
    (cl:cons ':obstacleClass (obstacleClass msg))
    (cl:cons ':vision_only_sign_type (vision_only_sign_type msg))
    (cl:cons ':classificationProbability (classificationProbability msg))
    (cl:cons ':obstacleAssignment (obstacleAssignment msg))
    (cl:cons ':obstacleCorner (obstacleCorner msg))
    (cl:cons ':NbrOccupiedLane (NbrOccupiedLane msg))
    (cl:cons ':indexAssignmentLine (indexAssignmentLine msg))
    (cl:cons ':positionLane (positionLane msg))
    (cl:cons ':departureRighttDistance (departureRighttDistance msg))
    (cl:cons ':departureLeftDistance (departureLeftDistance msg))
    (cl:cons ':trafficLights (trafficLights msg))
    (cl:cons ':vehicleLights (vehicleLights msg))
    (cl:cons ':idPiste (idPiste msg))
))
