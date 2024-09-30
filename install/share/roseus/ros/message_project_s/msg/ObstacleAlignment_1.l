;; Auto-generated. Do not edit!


(when (boundp 'message_project_s::ObstacleAlignment_1)
  (if (not (find-package "MESSAGE_PROJECT_S"))
    (make-package "MESSAGE_PROJECT_S"))
  (shadow 'ObstacleAlignment_1 (find-package "MESSAGE_PROJECT_S")))
(unless (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1")
  (make-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))

(in-package "ROS")
;;//! \htmlinclude ObstacleAlignment_1.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*OBSTACLEPOSITION_LINEAR_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEPOSITION_LINEAR_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEPOSITION_LINEAR_UNKNOWN* 999.0)
(intern "*OBSTACLEPOSITION_ORIENTATION_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEPOSITION_ORIENTATION_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEPOSITION_ORIENTATION_UNKNOWN* 999.0)
(intern "*OBSTACLEVELOCITY_LINEAR_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEVELOCITY_LINEAR_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEVELOCITY_LINEAR_UNKNOWN* 999.0)
(intern "*OBSTACLEVELOCITY_ANGULAR_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEVELOCITY_ANGULAR_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEVELOCITY_ANGULAR_UNKNOWN* 999.0)
(intern "*OBSTACLERELATIVEVELOCITY_LINEAR_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLERELATIVEVELOCITY_LINEAR_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLERELATIVEVELOCITY_LINEAR_UNKNOWN* 999.0)
(intern "*OBSTACLERELATIVEVELOCITY_ANGULAR_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLERELATIVEVELOCITY_ANGULAR_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLERELATIVEVELOCITY_ANGULAR_UNKNOWN* 999.0)
(intern "*OBSTACLEACCELERATION_LINEAR_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEACCELERATION_LINEAR_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEACCELERATION_LINEAR_UNKNOWN* 999.0)
(intern "*OBSTACLEACCELERATION_ANGULAR_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEACCELERATION_ANGULAR_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEACCELERATION_ANGULAR_UNKNOWN* 999.0)
(intern "*OBSTACLEDIMENSIONS_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEDIMENSIONS_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEDIMENSIONS_UNKNOWN* 999.0)
(intern "*BLINKERINFO_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*BLINKERINFO_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*BLINKERINFO_UNKNOWN* 0)
(intern "*CUTINANDOUT_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*CUTINANDOUT_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*CUTINANDOUT_UNKNOWN* 0)
(intern "*OBSTACLETYPE_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLETYPE_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLETYPE_UNKNOWN* 7)
(intern "*OBSTACLESTATUS_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLESTATUS_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLESTATUS_UNKNOWN* 0)
(intern "*OBSTACLEBRAKELIGHTS_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEBRAKELIGHTS_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEBRAKELIGHTS_UNKNOWN* nil)
(intern "*CIPVFLAG_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*CIPVFLAG_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*CIPVFLAG_UNKNOWN* 2)
(intern "*OBSTACLEREPLACED_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEREPLACED_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEREPLACED_UNKNOWN* 2)
(intern "*OBSTACLEVALID_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEVALID_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEVALID_UNKNOWN* 3)
(intern "*OBSTACLEAGE_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEAGE_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEAGE_UNKNOWN* 256)
(intern "*OBSTACLELANE_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLELANE_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLELANE_UNKNOWN* 0)
(intern "*OBSTACLEANGLE_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEANGLE_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEANGLE_UNKNOWN* 999.0)
(intern "*OBSTACLEANGLEVARIANCE_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEANGLEVARIANCE_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEANGLEVARIANCE_UNKNOWN* -1.0)
(intern "*OBSTACLEANGLERATE_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEANGLERATE_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEANGLERATE_UNKNOWN* 999.0)
(intern "*OBSTACLESCALECHANGE_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLESCALECHANGE_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLESCALECHANGE_UNKNOWN* 999.0)
(intern "*VISIONONLYSIGNTYPE_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*VISIONONLYSIGNTYPE_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*VISIONONLYSIGNTYPE_UNKNOWN* 254)
(intern "*VISIONONLYSUPPLEMENTARYSIGNTYPE_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*VISIONONLYSUPPLEMENTARYSIGNTYPE_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*VISIONONLYSUPPLEMENTARYSIGNTYPE_UNKNOWN* 0)
(intern "*SIGNPOSITION_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*SIGNPOSITION_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*SIGNPOSITION_UNKNOWN* 999.0)
(intern "*FILTERTYPE_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*FILTERTYPE_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*FILTERTYPE_UNKNOWN* 999.0)
(intern "*OBSTACLEPOSEVARIANCE_POSITION_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEPOSEVARIANCE_POSITION_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEPOSEVARIANCE_POSITION_UNKNOWN* -1.0)
(intern "*OBSTACLEPOSEVARIANCE_ORIENTATION_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEPOSEVARIANCE_ORIENTATION_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEPOSEVARIANCE_ORIENTATION_UNKNOWN* -1.0)
(intern "*OBSTACLEVELOCITYVARIANCE_LINEAR_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEVELOCITYVARIANCE_LINEAR_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEVELOCITYVARIANCE_LINEAR_UNKNOWN* -1.0)
(intern "*OBSTACLEVELOCITYVARIANCE_ANGULAR_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLEVELOCITYVARIANCE_ANGULAR_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLEVELOCITYVARIANCE_ANGULAR_UNKNOWN* -1.0)
(intern "*OBSTACLERELATIVEVELOCITYVARIANCE_LINEAR_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLERELATIVEVELOCITYVARIANCE_LINEAR_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLERELATIVEVELOCITYVARIANCE_LINEAR_UNKNOWN* -1.0)
(intern "*OBSTACLERELATIVEVELOCITYVARIANCE_ANGULAR_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*OBSTACLERELATIVEVELOCITYVARIANCE_ANGULAR_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*OBSTACLERELATIVEVELOCITYVARIANCE_ANGULAR_UNKNOWN* -1.0)
(intern "*GROUNDHEIGHT_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*GROUNDHEIGHT_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*GROUNDHEIGHT_UNKNOWN* 999.0)
(intern "*CLASSIFICATIONPROBABILITY_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*CLASSIFICATIONPROBABILITY_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*CLASSIFICATIONPROBABILITY_UNKNOWN* 999.0)
(intern "*DATEACQUISITION_UNKNOWN*" (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(shadow '*DATEACQUISITION_UNKNOWN* (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT_1"))
(defconstant message_project_s::ObstacleAlignment_1::*DATEACQUISITION_UNKNOWN* 999.0)
(defclass message_project_s::ObstacleAlignment_1
  :super ros::object
  :slots (_header _id _obstaclePosition _obstacleBodyCenter _obstacleVelocity _obstacleRelativeVelocity _obstacleAcceleration _obstacleDimensions _blinkerInfo _cutInAndOut _obstacleType _obstacleStatus _obstacleBrakeLights _cipvFlag _obstacleReplaced _obstacleValid _obstacleAge _obstacleLane _obstacleAngle _obstacleAngleVariance _obstacleAngleRate _obstacleScaleChange _visionOnlySignType _visionOnlySupplementarySignType _signPosition _filterType _obstaclePoseVariance _obstacleVelocityVariance _obstacleRelativeVelocityVariance _groundHeight _classificationProbability _dateAcquisition ))

(defmethod message_project_s::ObstacleAlignment_1
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt16 :init))
    ((:obstaclePosition __obstaclePosition) (instance geometry_msgs::Pose :init))
    ((:obstacleBodyCenter __obstacleBodyCenter) (instance geometry_msgs::Pose :init))
    ((:obstacleVelocity __obstacleVelocity) (instance geometry_msgs::Twist :init))
    ((:obstacleRelativeVelocity __obstacleRelativeVelocity) (instance geometry_msgs::Twist :init))
    ((:obstacleAcceleration __obstacleAcceleration) (instance geometry_msgs::Accel :init))
    ((:obstacleDimensions __obstacleDimensions) (instance geometry_msgs::Vector3 :init))
    ((:blinkerInfo __blinkerInfo) 0)
    ((:cutInAndOut __cutInAndOut) 0)
    ((:obstacleType __obstacleType) 0)
    ((:obstacleStatus __obstacleStatus) 0)
    ((:obstacleBrakeLights __obstacleBrakeLights) nil)
    ((:cipvFlag __cipvFlag) 0)
    ((:obstacleReplaced __obstacleReplaced) 0)
    ((:obstacleValid __obstacleValid) 0)
    ((:obstacleAge __obstacleAge) 0)
    ((:obstacleLane __obstacleLane) 0)
    ((:obstacleAngle __obstacleAngle) 0.0)
    ((:obstacleAngleVariance __obstacleAngleVariance) 0.0)
    ((:obstacleAngleRate __obstacleAngleRate) 0.0)
    ((:obstacleScaleChange __obstacleScaleChange) 0.0)
    ((:visionOnlySignType __visionOnlySignType) 0)
    ((:visionOnlySupplementarySignType __visionOnlySupplementarySignType) 0)
    ((:signPosition __signPosition) (instance geometry_msgs::Vector3 :init))
    ((:filterType __filterType) 0.0)
    ((:obstaclePoseVariance __obstaclePoseVariance) (instance geometry_msgs::Pose :init))
    ((:obstacleVelocityVariance __obstacleVelocityVariance) (instance geometry_msgs::Twist :init))
    ((:obstacleRelativeVelocityVariance __obstacleRelativeVelocityVariance) (instance geometry_msgs::Twist :init))
    ((:groundHeight __groundHeight) (instance std_msgs::Float32 :init))
    ((:classificationProbability __classificationProbability) 0.0)
    ((:dateAcquisition __dateAcquisition) (instance std_msgs::Float64 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _obstaclePosition __obstaclePosition)
   (setq _obstacleBodyCenter __obstacleBodyCenter)
   (setq _obstacleVelocity __obstacleVelocity)
   (setq _obstacleRelativeVelocity __obstacleRelativeVelocity)
   (setq _obstacleAcceleration __obstacleAcceleration)
   (setq _obstacleDimensions __obstacleDimensions)
   (setq _blinkerInfo (round __blinkerInfo))
   (setq _cutInAndOut (round __cutInAndOut))
   (setq _obstacleType (round __obstacleType))
   (setq _obstacleStatus (round __obstacleStatus))
   (setq _obstacleBrakeLights __obstacleBrakeLights)
   (setq _cipvFlag (round __cipvFlag))
   (setq _obstacleReplaced (round __obstacleReplaced))
   (setq _obstacleValid (round __obstacleValid))
   (setq _obstacleAge (round __obstacleAge))
   (setq _obstacleLane (round __obstacleLane))
   (setq _obstacleAngle (float __obstacleAngle))
   (setq _obstacleAngleVariance (float __obstacleAngleVariance))
   (setq _obstacleAngleRate (float __obstacleAngleRate))
   (setq _obstacleScaleChange (float __obstacleScaleChange))
   (setq _visionOnlySignType (round __visionOnlySignType))
   (setq _visionOnlySupplementarySignType (round __visionOnlySupplementarySignType))
   (setq _signPosition __signPosition)
   (setq _filterType (float __filterType))
   (setq _obstaclePoseVariance __obstaclePoseVariance)
   (setq _obstacleVelocityVariance __obstacleVelocityVariance)
   (setq _obstacleRelativeVelocityVariance __obstacleRelativeVelocityVariance)
   (setq _groundHeight __groundHeight)
   (setq _classificationProbability (float __classificationProbability))
   (setq _dateAcquisition __dateAcquisition)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:id
   (&rest __id)
   (if (keywordp (car __id))
       (send* _id __id)
     (progn
       (if __id (setq _id (car __id)))
       _id)))
  (:obstaclePosition
   (&rest __obstaclePosition)
   (if (keywordp (car __obstaclePosition))
       (send* _obstaclePosition __obstaclePosition)
     (progn
       (if __obstaclePosition (setq _obstaclePosition (car __obstaclePosition)))
       _obstaclePosition)))
  (:obstacleBodyCenter
   (&rest __obstacleBodyCenter)
   (if (keywordp (car __obstacleBodyCenter))
       (send* _obstacleBodyCenter __obstacleBodyCenter)
     (progn
       (if __obstacleBodyCenter (setq _obstacleBodyCenter (car __obstacleBodyCenter)))
       _obstacleBodyCenter)))
  (:obstacleVelocity
   (&rest __obstacleVelocity)
   (if (keywordp (car __obstacleVelocity))
       (send* _obstacleVelocity __obstacleVelocity)
     (progn
       (if __obstacleVelocity (setq _obstacleVelocity (car __obstacleVelocity)))
       _obstacleVelocity)))
  (:obstacleRelativeVelocity
   (&rest __obstacleRelativeVelocity)
   (if (keywordp (car __obstacleRelativeVelocity))
       (send* _obstacleRelativeVelocity __obstacleRelativeVelocity)
     (progn
       (if __obstacleRelativeVelocity (setq _obstacleRelativeVelocity (car __obstacleRelativeVelocity)))
       _obstacleRelativeVelocity)))
  (:obstacleAcceleration
   (&rest __obstacleAcceleration)
   (if (keywordp (car __obstacleAcceleration))
       (send* _obstacleAcceleration __obstacleAcceleration)
     (progn
       (if __obstacleAcceleration (setq _obstacleAcceleration (car __obstacleAcceleration)))
       _obstacleAcceleration)))
  (:obstacleDimensions
   (&rest __obstacleDimensions)
   (if (keywordp (car __obstacleDimensions))
       (send* _obstacleDimensions __obstacleDimensions)
     (progn
       (if __obstacleDimensions (setq _obstacleDimensions (car __obstacleDimensions)))
       _obstacleDimensions)))
  (:blinkerInfo
   (&optional __blinkerInfo)
   (if __blinkerInfo (setq _blinkerInfo __blinkerInfo)) _blinkerInfo)
  (:cutInAndOut
   (&optional __cutInAndOut)
   (if __cutInAndOut (setq _cutInAndOut __cutInAndOut)) _cutInAndOut)
  (:obstacleType
   (&optional __obstacleType)
   (if __obstacleType (setq _obstacleType __obstacleType)) _obstacleType)
  (:obstacleStatus
   (&optional __obstacleStatus)
   (if __obstacleStatus (setq _obstacleStatus __obstacleStatus)) _obstacleStatus)
  (:obstacleBrakeLights
   (&optional __obstacleBrakeLights)
   (if __obstacleBrakeLights (setq _obstacleBrakeLights __obstacleBrakeLights)) _obstacleBrakeLights)
  (:cipvFlag
   (&optional __cipvFlag)
   (if __cipvFlag (setq _cipvFlag __cipvFlag)) _cipvFlag)
  (:obstacleReplaced
   (&optional __obstacleReplaced)
   (if __obstacleReplaced (setq _obstacleReplaced __obstacleReplaced)) _obstacleReplaced)
  (:obstacleValid
   (&optional __obstacleValid)
   (if __obstacleValid (setq _obstacleValid __obstacleValid)) _obstacleValid)
  (:obstacleAge
   (&optional __obstacleAge)
   (if __obstacleAge (setq _obstacleAge __obstacleAge)) _obstacleAge)
  (:obstacleLane
   (&optional __obstacleLane)
   (if __obstacleLane (setq _obstacleLane __obstacleLane)) _obstacleLane)
  (:obstacleAngle
   (&optional __obstacleAngle)
   (if __obstacleAngle (setq _obstacleAngle __obstacleAngle)) _obstacleAngle)
  (:obstacleAngleVariance
   (&optional __obstacleAngleVariance)
   (if __obstacleAngleVariance (setq _obstacleAngleVariance __obstacleAngleVariance)) _obstacleAngleVariance)
  (:obstacleAngleRate
   (&optional __obstacleAngleRate)
   (if __obstacleAngleRate (setq _obstacleAngleRate __obstacleAngleRate)) _obstacleAngleRate)
  (:obstacleScaleChange
   (&optional __obstacleScaleChange)
   (if __obstacleScaleChange (setq _obstacleScaleChange __obstacleScaleChange)) _obstacleScaleChange)
  (:visionOnlySignType
   (&optional __visionOnlySignType)
   (if __visionOnlySignType (setq _visionOnlySignType __visionOnlySignType)) _visionOnlySignType)
  (:visionOnlySupplementarySignType
   (&optional __visionOnlySupplementarySignType)
   (if __visionOnlySupplementarySignType (setq _visionOnlySupplementarySignType __visionOnlySupplementarySignType)) _visionOnlySupplementarySignType)
  (:signPosition
   (&rest __signPosition)
   (if (keywordp (car __signPosition))
       (send* _signPosition __signPosition)
     (progn
       (if __signPosition (setq _signPosition (car __signPosition)))
       _signPosition)))
  (:filterType
   (&optional __filterType)
   (if __filterType (setq _filterType __filterType)) _filterType)
  (:obstaclePoseVariance
   (&rest __obstaclePoseVariance)
   (if (keywordp (car __obstaclePoseVariance))
       (send* _obstaclePoseVariance __obstaclePoseVariance)
     (progn
       (if __obstaclePoseVariance (setq _obstaclePoseVariance (car __obstaclePoseVariance)))
       _obstaclePoseVariance)))
  (:obstacleVelocityVariance
   (&rest __obstacleVelocityVariance)
   (if (keywordp (car __obstacleVelocityVariance))
       (send* _obstacleVelocityVariance __obstacleVelocityVariance)
     (progn
       (if __obstacleVelocityVariance (setq _obstacleVelocityVariance (car __obstacleVelocityVariance)))
       _obstacleVelocityVariance)))
  (:obstacleRelativeVelocityVariance
   (&rest __obstacleRelativeVelocityVariance)
   (if (keywordp (car __obstacleRelativeVelocityVariance))
       (send* _obstacleRelativeVelocityVariance __obstacleRelativeVelocityVariance)
     (progn
       (if __obstacleRelativeVelocityVariance (setq _obstacleRelativeVelocityVariance (car __obstacleRelativeVelocityVariance)))
       _obstacleRelativeVelocityVariance)))
  (:groundHeight
   (&rest __groundHeight)
   (if (keywordp (car __groundHeight))
       (send* _groundHeight __groundHeight)
     (progn
       (if __groundHeight (setq _groundHeight (car __groundHeight)))
       _groundHeight)))
  (:classificationProbability
   (&optional __classificationProbability)
   (if __classificationProbability (setq _classificationProbability __classificationProbability)) _classificationProbability)
  (:dateAcquisition
   (&rest __dateAcquisition)
   (if (keywordp (car __dateAcquisition))
       (send* _dateAcquisition __dateAcquisition)
     (progn
       (if __dateAcquisition (setq _dateAcquisition (car __dateAcquisition)))
       _dateAcquisition)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt16 _id
    (send _id :serialization-length)
    ;; geometry_msgs/Pose _obstaclePosition
    (send _obstaclePosition :serialization-length)
    ;; geometry_msgs/Pose _obstacleBodyCenter
    (send _obstacleBodyCenter :serialization-length)
    ;; geometry_msgs/Twist _obstacleVelocity
    (send _obstacleVelocity :serialization-length)
    ;; geometry_msgs/Twist _obstacleRelativeVelocity
    (send _obstacleRelativeVelocity :serialization-length)
    ;; geometry_msgs/Accel _obstacleAcceleration
    (send _obstacleAcceleration :serialization-length)
    ;; geometry_msgs/Vector3 _obstacleDimensions
    (send _obstacleDimensions :serialization-length)
    ;; uint8 _blinkerInfo
    1
    ;; uint8 _cutInAndOut
    1
    ;; uint8 _obstacleType
    1
    ;; uint8 _obstacleStatus
    1
    ;; bool _obstacleBrakeLights
    1
    ;; int8 _cipvFlag
    1
    ;; int8 _obstacleReplaced
    1
    ;; uint8 _obstacleValid
    1
    ;; uint16 _obstacleAge
    2
    ;; uint8 _obstacleLane
    1
    ;; float32 _obstacleAngle
    4
    ;; float32 _obstacleAngleVariance
    4
    ;; float32 _obstacleAngleRate
    4
    ;; float64 _obstacleScaleChange
    8
    ;; uint8 _visionOnlySignType
    1
    ;; uint8 _visionOnlySupplementarySignType
    1
    ;; geometry_msgs/Vector3 _signPosition
    (send _signPosition :serialization-length)
    ;; float64 _filterType
    8
    ;; geometry_msgs/Pose _obstaclePoseVariance
    (send _obstaclePoseVariance :serialization-length)
    ;; geometry_msgs/Twist _obstacleVelocityVariance
    (send _obstacleVelocityVariance :serialization-length)
    ;; geometry_msgs/Twist _obstacleRelativeVelocityVariance
    (send _obstacleRelativeVelocityVariance :serialization-length)
    ;; std_msgs/Float32 _groundHeight
    (send _groundHeight :serialization-length)
    ;; float64 _classificationProbability
    8
    ;; std_msgs/Float64 _dateAcquisition
    (send _dateAcquisition :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt16 _id
       (send _id :serialize s)
     ;; geometry_msgs/Pose _obstaclePosition
       (send _obstaclePosition :serialize s)
     ;; geometry_msgs/Pose _obstacleBodyCenter
       (send _obstacleBodyCenter :serialize s)
     ;; geometry_msgs/Twist _obstacleVelocity
       (send _obstacleVelocity :serialize s)
     ;; geometry_msgs/Twist _obstacleRelativeVelocity
       (send _obstacleRelativeVelocity :serialize s)
     ;; geometry_msgs/Accel _obstacleAcceleration
       (send _obstacleAcceleration :serialize s)
     ;; geometry_msgs/Vector3 _obstacleDimensions
       (send _obstacleDimensions :serialize s)
     ;; uint8 _blinkerInfo
       (write-byte _blinkerInfo s)
     ;; uint8 _cutInAndOut
       (write-byte _cutInAndOut s)
     ;; uint8 _obstacleType
       (write-byte _obstacleType s)
     ;; uint8 _obstacleStatus
       (write-byte _obstacleStatus s)
     ;; bool _obstacleBrakeLights
       (if _obstacleBrakeLights (write-byte -1 s) (write-byte 0 s))
     ;; int8 _cipvFlag
       (write-byte _cipvFlag s)
     ;; int8 _obstacleReplaced
       (write-byte _obstacleReplaced s)
     ;; uint8 _obstacleValid
       (write-byte _obstacleValid s)
     ;; uint16 _obstacleAge
       (write-word _obstacleAge s)
     ;; uint8 _obstacleLane
       (write-byte _obstacleLane s)
     ;; float32 _obstacleAngle
       (sys::poke _obstacleAngle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _obstacleAngleVariance
       (sys::poke _obstacleAngleVariance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _obstacleAngleRate
       (sys::poke _obstacleAngleRate (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float64 _obstacleScaleChange
       (sys::poke _obstacleScaleChange (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint8 _visionOnlySignType
       (write-byte _visionOnlySignType s)
     ;; uint8 _visionOnlySupplementarySignType
       (write-byte _visionOnlySupplementarySignType s)
     ;; geometry_msgs/Vector3 _signPosition
       (send _signPosition :serialize s)
     ;; float64 _filterType
       (sys::poke _filterType (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; geometry_msgs/Pose _obstaclePoseVariance
       (send _obstaclePoseVariance :serialize s)
     ;; geometry_msgs/Twist _obstacleVelocityVariance
       (send _obstacleVelocityVariance :serialize s)
     ;; geometry_msgs/Twist _obstacleRelativeVelocityVariance
       (send _obstacleRelativeVelocityVariance :serialize s)
     ;; std_msgs/Float32 _groundHeight
       (send _groundHeight :serialize s)
     ;; float64 _classificationProbability
       (sys::poke _classificationProbability (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; std_msgs/Float64 _dateAcquisition
       (send _dateAcquisition :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt16 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; geometry_msgs/Pose _obstaclePosition
     (send _obstaclePosition :deserialize buf ptr-) (incf ptr- (send _obstaclePosition :serialization-length))
   ;; geometry_msgs/Pose _obstacleBodyCenter
     (send _obstacleBodyCenter :deserialize buf ptr-) (incf ptr- (send _obstacleBodyCenter :serialization-length))
   ;; geometry_msgs/Twist _obstacleVelocity
     (send _obstacleVelocity :deserialize buf ptr-) (incf ptr- (send _obstacleVelocity :serialization-length))
   ;; geometry_msgs/Twist _obstacleRelativeVelocity
     (send _obstacleRelativeVelocity :deserialize buf ptr-) (incf ptr- (send _obstacleRelativeVelocity :serialization-length))
   ;; geometry_msgs/Accel _obstacleAcceleration
     (send _obstacleAcceleration :deserialize buf ptr-) (incf ptr- (send _obstacleAcceleration :serialization-length))
   ;; geometry_msgs/Vector3 _obstacleDimensions
     (send _obstacleDimensions :deserialize buf ptr-) (incf ptr- (send _obstacleDimensions :serialization-length))
   ;; uint8 _blinkerInfo
     (setq _blinkerInfo (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _cutInAndOut
     (setq _cutInAndOut (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _obstacleType
     (setq _obstacleType (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _obstacleStatus
     (setq _obstacleStatus (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _obstacleBrakeLights
     (setq _obstacleBrakeLights (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int8 _cipvFlag
     (setq _cipvFlag (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _cipvFlag 127) (setq _cipvFlag (- _cipvFlag 256)))
   ;; int8 _obstacleReplaced
     (setq _obstacleReplaced (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _obstacleReplaced 127) (setq _obstacleReplaced (- _obstacleReplaced 256)))
   ;; uint8 _obstacleValid
     (setq _obstacleValid (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint16 _obstacleAge
     (setq _obstacleAge (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _obstacleLane
     (setq _obstacleLane (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32 _obstacleAngle
     (setq _obstacleAngle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _obstacleAngleVariance
     (setq _obstacleAngleVariance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _obstacleAngleRate
     (setq _obstacleAngleRate (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float64 _obstacleScaleChange
     (setq _obstacleScaleChange (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint8 _visionOnlySignType
     (setq _visionOnlySignType (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _visionOnlySupplementarySignType
     (setq _visionOnlySupplementarySignType (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; geometry_msgs/Vector3 _signPosition
     (send _signPosition :deserialize buf ptr-) (incf ptr- (send _signPosition :serialization-length))
   ;; float64 _filterType
     (setq _filterType (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; geometry_msgs/Pose _obstaclePoseVariance
     (send _obstaclePoseVariance :deserialize buf ptr-) (incf ptr- (send _obstaclePoseVariance :serialization-length))
   ;; geometry_msgs/Twist _obstacleVelocityVariance
     (send _obstacleVelocityVariance :deserialize buf ptr-) (incf ptr- (send _obstacleVelocityVariance :serialization-length))
   ;; geometry_msgs/Twist _obstacleRelativeVelocityVariance
     (send _obstacleRelativeVelocityVariance :deserialize buf ptr-) (incf ptr- (send _obstacleRelativeVelocityVariance :serialization-length))
   ;; std_msgs/Float32 _groundHeight
     (send _groundHeight :deserialize buf ptr-) (incf ptr- (send _groundHeight :serialization-length))
   ;; float64 _classificationProbability
     (setq _classificationProbability (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; std_msgs/Float64 _dateAcquisition
     (send _dateAcquisition :deserialize buf ptr-) (incf ptr- (send _dateAcquisition :serialization-length))
   ;;
   self)
  )

(setf (get message_project_s::ObstacleAlignment_1 :md5sum-) "27f6a6ab5af7368643bc8a932319e35a")
(setf (get message_project_s::ObstacleAlignment_1 :datatype-) "message_project_s/ObstacleAlignment_1")
(setf (get message_project_s::ObstacleAlignment_1 :definition-)
      "Header header
std_msgs/UInt16 id

geometry_msgs/Pose obstaclePosition	        		# obstacle position
float64 obstaclePosition_linear_Unknown = 999
float64 obstaclePosition_orientation_Unknown = 999

geometry_msgs/Pose obstacleBodyCenter	        		# Obstacle Center for Corner Computation

geometry_msgs/Twist obstacleVelocity	                    	# obstacle speed
float64 obstacleVelocity_linear_Unknown = 999
float64 obstacleVelocity_angular_Unknown = 999

geometry_msgs/Twist obstacleRelativeVelocity	           	# obstacle relative velocity
float64 obstacleRelativeVelocity_linear_Unknown = 999
float64 obstacleRelativeVelocity_angular_Unknown = 999

geometry_msgs/Accel obstacleAcceleration        		# obstacle acceleration
float64 obstacleAcceleration_linear_Unknown = 999
float64 obstacleAcceleration_angular_Unknown = 999

geometry_msgs/Vector3 obstacleDimensions        		# obstacle - length and width
float64 obstacleDimensions_Unknown = 999

uint8 blinkerInfo                               		# blinker status (eg. left blinker on)
uint8 blinkerInfo_Unknown=0

uint8 cutInAndOut                               		# Vehicle cutting in or out of ego lane 
uint8 cutInAndOut_Unknown=0

uint8 obstacleType                             			# obstacle classification
uint8 obstacleType_Unknown=7

uint8 obstacleStatus                            		# obstacle’s moving status
uint8 obstacleStatus_Unknown=0

bool obstacleBrakeLights                        		# obstacle brake light on or off
bool obstacleBrakeLights_Unknown=0 

int8 cipvFlag                                   		# If obstacle Closest in Path Vehicle
int8 cipvFlag_Unknown=2

int8 obstacleReplaced                           		# If obstacle replaced in this frame
int8 obstacleReplaced_Unknown=2

uint8 obstacleValid                             		# obstacle valid
uint8 obstacleValid_Unknown=3

uint16 obstacleAge                              		# obstacle age in number of frames
uint16 obstacleAge_Unknown=256

uint8 obstacleLane                              		# obstacle's lane (eg. ego lane or next lane)
uint8 obstacleLane_Unknown=0

float32 obstacleAngle                           		# angle to center of obstacle in degrees
float32 obstacleAngle_Unknown = 999

float32 obstacleAngleVariance                   		# Obstacle angle Variance (Lidar)
float32 obstacleAngleVariance_Unknown=-1

float32 obstacleAngleRate                       		# angle rate of the center of obstacle (degrees/sec)
float32 obstacleAngleRate_Unknown = 999

float64 obstacleScaleChange                     		# scale change from previous frame   
float64 obstacleScaleChange_Unknown = 999
                           
uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type
uint8 visionOnlySignType_Unknown=254

uint8 visionOnlySupplementarySignType               		# Supplementary sign type - rain, snow, arrow etc. 
uint8 visionOnlySupplementarySignType_Unknown=0

geometry_msgs/Vector3 signPosition                  		# X-Longitudnal position, Y-Lateral position ,Z-Height of sign relative to ME
float64 signPosition_Unknown = 999

float64 filterType                                    		# filtering 
float64 filterType_Unknown = 999

geometry_msgs/Pose obstaclePoseVariance		                # obstacle position variance
float64 obstaclePoseVariance_position_Unknown = -1
float64 obstaclePoseVariance_orientation_Unknown = -1

geometry_msgs/Twist obstacleVelocityVariance	                # obstacle speed variance
float64 obstacleVelocityVariance_linear_Unknown = -1
float64 obstacleVelocityVariance_angular_Unknown = -1

geometry_msgs/Twist obstacleRelativeVelocityVariance	        # obstacle relative velocity variance
float64 obstacleRelativeVelocityVariance_linear_Unknown = -1
float64 obstacleRelativeVelocityVariance_angular_Unknown = -1

std_msgs/Float32 groundHeight			                # ground height
float64 groundHeight_Unknown = 999

float64 classificationProbability
float64 classificationProbability_Unknown = 999

std_msgs/Float64 dateAcquisition
float64 dateAcquisition_Unknown = 999


# History

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: std_msgs/UInt16
uint16 data

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
================================================================================
MSG: geometry_msgs/Accel
# This expresses acceleration in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

================================================================================
MSG: std_msgs/Float32
float32 data
================================================================================
MSG: std_msgs/Float64
float64 data
")



(provide :message_project_s/ObstacleAlignment_1 "27f6a6ab5af7368643bc8a932319e35a")


