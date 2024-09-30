;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ObstacleFusion)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ObstacleFusion (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::OBSTACLEFUSION")
  (make-package "PROJECT_S_MSGS::OBSTACLEFUSION"))

(in-package "ROS")
;;//! \htmlinclude ObstacleFusion.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*IDLE_TRACK*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*IDLE_TRACK* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*IDLE_TRACK* 0)
(intern "*PRE_TRACK*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*PRE_TRACK* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*PRE_TRACK* 1)
(intern "*POST_TRACK*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*POST_TRACK* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*POST_TRACK* 2)
(intern "*CURRENT_TRACK*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*CURRENT_TRACK* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*CURRENT_TRACK* 3)
(intern "*ASSIGNMENT_COTE_DROIT*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*ASSIGNMENT_COTE_DROIT* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*ASSIGNMENT_COTE_DROIT* 1)
(intern "*ASSIGNMENT_COTE_GAUCHE*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*ASSIGNMENT_COTE_GAUCHE* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*ASSIGNMENT_COTE_GAUCHE* 2)
(intern "*CORNER_FRONT_RIGHT*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*CORNER_FRONT_RIGHT* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*CORNER_FRONT_RIGHT* 0)
(intern "*CORNER_FRONT_LEFT*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*CORNER_FRONT_LEFT* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*CORNER_FRONT_LEFT* 1)
(intern "*CORNER_BACK_RIGHT*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*CORNER_BACK_RIGHT* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*CORNER_BACK_RIGHT* 2)
(intern "*CORNER_BACK_LEFT*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*CORNER_BACK_LEFT* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*CORNER_BACK_LEFT* 3)
(intern "*OCCUPIED_LANE_INDEFINI*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*OCCUPIED_LANE_INDEFINI* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*OCCUPIED_LANE_INDEFINI* 255)
(intern "*INDEX_LINE_INDEFINI*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(shadow '*INDEX_LINE_INDEFINI* (find-package "PROJECT_S_MSGS::OBSTACLEFUSION"))
(defconstant project_s_msgs::ObstacleFusion::*INDEX_LINE_INDEFINI* 255)
(defclass project_s_msgs::ObstacleFusion
  :super ros::object
  :slots (_header _id _obstaclePosition _obstacleBodyCenter _distanceCurviligne _groundHeight _obstacleVelocity _obstacleAcceleration _obstacleCap _existenceProbability _existenceState _scoreDetection _nbrDetection _nbrVisibility _scorePersistence _nbrUpdate _nbrAge _existenceFirstTime _existenceDurationTime _anchorPoint _obstaclePoseVariance _obstacleVelocityVariance _obstacleDimensions _obstacleClass _vision_only_sign_type _classificationProbability _obstacleAssignment _obstacleCorner _NbrOccupiedLane _indexAssignmentLine _positionLane _departureRighttDistance _departureLeftDistance _trafficLights _vehicleLights _idPiste ))

(defmethod project_s_msgs::ObstacleFusion
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:obstaclePosition __obstaclePosition) (instance geometry_msgs::Pose :init))
    ((:obstacleBodyCenter __obstacleBodyCenter) (instance geometry_msgs::Pose :init))
    ((:distanceCurviligne __distanceCurviligne) 0.0)
    ((:groundHeight __groundHeight) (instance std_msgs::Float32 :init))
    ((:obstacleVelocity __obstacleVelocity) (instance geometry_msgs::Twist :init))
    ((:obstacleAcceleration __obstacleAcceleration) (instance geometry_msgs::Accel :init))
    ((:obstacleCap __obstacleCap) (instance geometry_msgs::Vector3 :init))
    ((:existenceProbability __existenceProbability) (instance std_msgs::UInt8 :init))
    ((:existenceState __existenceState) (instance std_msgs::UInt8 :init))
    ((:scoreDetection __scoreDetection) (instance std_msgs::Float32 :init))
    ((:nbrDetection __nbrDetection) (instance std_msgs::Float32 :init))
    ((:nbrVisibility __nbrVisibility) (instance std_msgs::Float32 :init))
    ((:scorePersistence __scorePersistence) (instance std_msgs::Float32 :init))
    ((:nbrUpdate __nbrUpdate) (instance std_msgs::Float32 :init))
    ((:nbrAge __nbrAge) (instance std_msgs::Float32 :init))
    ((:existenceFirstTime __existenceFirstTime) (instance ros::time :init))
    ((:existenceDurationTime __existenceDurationTime) (instance std_msgs::Float32 :init))
    ((:anchorPoint __anchorPoint) (instance std_msgs::UInt8 :init))
    ((:obstaclePoseVariance __obstaclePoseVariance) (instance geometry_msgs::Pose :init))
    ((:obstacleVelocityVariance __obstacleVelocityVariance) (instance geometry_msgs::Twist :init))
    ((:obstacleDimensions __obstacleDimensions) (instance geometry_msgs::Vector3 :init))
    ((:obstacleClass __obstacleClass) 0)
    ((:vision_only_sign_type __vision_only_sign_type) 0)
    ((:classificationProbability __classificationProbability) (instance std_msgs::UInt8 :init))
    ((:obstacleAssignment __obstacleAssignment) 0)
    ((:obstacleCorner __obstacleCorner) (let (r) (dotimes (i 4) (push (instance geometry_msgs::Point :init) r)) r))
    ((:NbrOccupiedLane __NbrOccupiedLane) 0)
    ((:indexAssignmentLine __indexAssignmentLine) (make-array 2 :initial-element 0 :element-type :char))
    ((:positionLane __positionLane) (instance std_msgs::Float32 :init))
    ((:departureRighttDistance __departureRighttDistance) (instance std_msgs::Float32 :init))
    ((:departureLeftDistance __departureLeftDistance) (instance std_msgs::Float32 :init))
    ((:trafficLights __trafficLights) (instance std_msgs::Int16 :init))
    ((:vehicleLights __vehicleLights) (instance std_msgs::Int16 :init))
    ((:idPiste __idPiste) (let (r) (dotimes (i 3) (push (instance std_msgs::UInt16 :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _obstaclePosition __obstaclePosition)
   (setq _obstacleBodyCenter __obstacleBodyCenter)
   (setq _distanceCurviligne (float __distanceCurviligne))
   (setq _groundHeight __groundHeight)
   (setq _obstacleVelocity __obstacleVelocity)
   (setq _obstacleAcceleration __obstacleAcceleration)
   (setq _obstacleCap __obstacleCap)
   (setq _existenceProbability __existenceProbability)
   (setq _existenceState __existenceState)
   (setq _scoreDetection __scoreDetection)
   (setq _nbrDetection __nbrDetection)
   (setq _nbrVisibility __nbrVisibility)
   (setq _scorePersistence __scorePersistence)
   (setq _nbrUpdate __nbrUpdate)
   (setq _nbrAge __nbrAge)
   (setq _existenceFirstTime __existenceFirstTime)
   (setq _existenceDurationTime __existenceDurationTime)
   (setq _anchorPoint __anchorPoint)
   (setq _obstaclePoseVariance __obstaclePoseVariance)
   (setq _obstacleVelocityVariance __obstacleVelocityVariance)
   (setq _obstacleDimensions __obstacleDimensions)
   (setq _obstacleClass (round __obstacleClass))
   (setq _vision_only_sign_type (round __vision_only_sign_type))
   (setq _classificationProbability __classificationProbability)
   (setq _obstacleAssignment (round __obstacleAssignment))
   (setq _obstacleCorner __obstacleCorner)
   (setq _NbrOccupiedLane (round __NbrOccupiedLane))
   (setq _indexAssignmentLine __indexAssignmentLine)
   (setq _positionLane __positionLane)
   (setq _departureRighttDistance __departureRighttDistance)
   (setq _departureLeftDistance __departureLeftDistance)
   (setq _trafficLights __trafficLights)
   (setq _vehicleLights __vehicleLights)
   (setq _idPiste __idPiste)
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
  (:distanceCurviligne
   (&optional __distanceCurviligne)
   (if __distanceCurviligne (setq _distanceCurviligne __distanceCurviligne)) _distanceCurviligne)
  (:groundHeight
   (&rest __groundHeight)
   (if (keywordp (car __groundHeight))
       (send* _groundHeight __groundHeight)
     (progn
       (if __groundHeight (setq _groundHeight (car __groundHeight)))
       _groundHeight)))
  (:obstacleVelocity
   (&rest __obstacleVelocity)
   (if (keywordp (car __obstacleVelocity))
       (send* _obstacleVelocity __obstacleVelocity)
     (progn
       (if __obstacleVelocity (setq _obstacleVelocity (car __obstacleVelocity)))
       _obstacleVelocity)))
  (:obstacleAcceleration
   (&rest __obstacleAcceleration)
   (if (keywordp (car __obstacleAcceleration))
       (send* _obstacleAcceleration __obstacleAcceleration)
     (progn
       (if __obstacleAcceleration (setq _obstacleAcceleration (car __obstacleAcceleration)))
       _obstacleAcceleration)))
  (:obstacleCap
   (&rest __obstacleCap)
   (if (keywordp (car __obstacleCap))
       (send* _obstacleCap __obstacleCap)
     (progn
       (if __obstacleCap (setq _obstacleCap (car __obstacleCap)))
       _obstacleCap)))
  (:existenceProbability
   (&rest __existenceProbability)
   (if (keywordp (car __existenceProbability))
       (send* _existenceProbability __existenceProbability)
     (progn
       (if __existenceProbability (setq _existenceProbability (car __existenceProbability)))
       _existenceProbability)))
  (:existenceState
   (&rest __existenceState)
   (if (keywordp (car __existenceState))
       (send* _existenceState __existenceState)
     (progn
       (if __existenceState (setq _existenceState (car __existenceState)))
       _existenceState)))
  (:scoreDetection
   (&rest __scoreDetection)
   (if (keywordp (car __scoreDetection))
       (send* _scoreDetection __scoreDetection)
     (progn
       (if __scoreDetection (setq _scoreDetection (car __scoreDetection)))
       _scoreDetection)))
  (:nbrDetection
   (&rest __nbrDetection)
   (if (keywordp (car __nbrDetection))
       (send* _nbrDetection __nbrDetection)
     (progn
       (if __nbrDetection (setq _nbrDetection (car __nbrDetection)))
       _nbrDetection)))
  (:nbrVisibility
   (&rest __nbrVisibility)
   (if (keywordp (car __nbrVisibility))
       (send* _nbrVisibility __nbrVisibility)
     (progn
       (if __nbrVisibility (setq _nbrVisibility (car __nbrVisibility)))
       _nbrVisibility)))
  (:scorePersistence
   (&rest __scorePersistence)
   (if (keywordp (car __scorePersistence))
       (send* _scorePersistence __scorePersistence)
     (progn
       (if __scorePersistence (setq _scorePersistence (car __scorePersistence)))
       _scorePersistence)))
  (:nbrUpdate
   (&rest __nbrUpdate)
   (if (keywordp (car __nbrUpdate))
       (send* _nbrUpdate __nbrUpdate)
     (progn
       (if __nbrUpdate (setq _nbrUpdate (car __nbrUpdate)))
       _nbrUpdate)))
  (:nbrAge
   (&rest __nbrAge)
   (if (keywordp (car __nbrAge))
       (send* _nbrAge __nbrAge)
     (progn
       (if __nbrAge (setq _nbrAge (car __nbrAge)))
       _nbrAge)))
  (:existenceFirstTime
   (&optional __existenceFirstTime)
   (if __existenceFirstTime (setq _existenceFirstTime __existenceFirstTime)) _existenceFirstTime)
  (:existenceDurationTime
   (&rest __existenceDurationTime)
   (if (keywordp (car __existenceDurationTime))
       (send* _existenceDurationTime __existenceDurationTime)
     (progn
       (if __existenceDurationTime (setq _existenceDurationTime (car __existenceDurationTime)))
       _existenceDurationTime)))
  (:anchorPoint
   (&rest __anchorPoint)
   (if (keywordp (car __anchorPoint))
       (send* _anchorPoint __anchorPoint)
     (progn
       (if __anchorPoint (setq _anchorPoint (car __anchorPoint)))
       _anchorPoint)))
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
  (:obstacleDimensions
   (&rest __obstacleDimensions)
   (if (keywordp (car __obstacleDimensions))
       (send* _obstacleDimensions __obstacleDimensions)
     (progn
       (if __obstacleDimensions (setq _obstacleDimensions (car __obstacleDimensions)))
       _obstacleDimensions)))
  (:obstacleClass
   (&optional __obstacleClass)
   (if __obstacleClass (setq _obstacleClass __obstacleClass)) _obstacleClass)
  (:vision_only_sign_type
   (&optional __vision_only_sign_type)
   (if __vision_only_sign_type (setq _vision_only_sign_type __vision_only_sign_type)) _vision_only_sign_type)
  (:classificationProbability
   (&rest __classificationProbability)
   (if (keywordp (car __classificationProbability))
       (send* _classificationProbability __classificationProbability)
     (progn
       (if __classificationProbability (setq _classificationProbability (car __classificationProbability)))
       _classificationProbability)))
  (:obstacleAssignment
   (&optional __obstacleAssignment)
   (if __obstacleAssignment (setq _obstacleAssignment __obstacleAssignment)) _obstacleAssignment)
  (:obstacleCorner
   (&rest __obstacleCorner)
   (if (keywordp (car __obstacleCorner))
       (send* _obstacleCorner __obstacleCorner)
     (progn
       (if __obstacleCorner (setq _obstacleCorner (car __obstacleCorner)))
       _obstacleCorner)))
  (:NbrOccupiedLane
   (&optional __NbrOccupiedLane)
   (if __NbrOccupiedLane (setq _NbrOccupiedLane __NbrOccupiedLane)) _NbrOccupiedLane)
  (:indexAssignmentLine
   (&optional __indexAssignmentLine)
   (if __indexAssignmentLine (setq _indexAssignmentLine __indexAssignmentLine)) _indexAssignmentLine)
  (:positionLane
   (&rest __positionLane)
   (if (keywordp (car __positionLane))
       (send* _positionLane __positionLane)
     (progn
       (if __positionLane (setq _positionLane (car __positionLane)))
       _positionLane)))
  (:departureRighttDistance
   (&rest __departureRighttDistance)
   (if (keywordp (car __departureRighttDistance))
       (send* _departureRighttDistance __departureRighttDistance)
     (progn
       (if __departureRighttDistance (setq _departureRighttDistance (car __departureRighttDistance)))
       _departureRighttDistance)))
  (:departureLeftDistance
   (&rest __departureLeftDistance)
   (if (keywordp (car __departureLeftDistance))
       (send* _departureLeftDistance __departureLeftDistance)
     (progn
       (if __departureLeftDistance (setq _departureLeftDistance (car __departureLeftDistance)))
       _departureLeftDistance)))
  (:trafficLights
   (&rest __trafficLights)
   (if (keywordp (car __trafficLights))
       (send* _trafficLights __trafficLights)
     (progn
       (if __trafficLights (setq _trafficLights (car __trafficLights)))
       _trafficLights)))
  (:vehicleLights
   (&rest __vehicleLights)
   (if (keywordp (car __vehicleLights))
       (send* _vehicleLights __vehicleLights)
     (progn
       (if __vehicleLights (setq _vehicleLights (car __vehicleLights)))
       _vehicleLights)))
  (:idPiste
   (&rest __idPiste)
   (if (keywordp (car __idPiste))
       (send* _idPiste __idPiste)
     (progn
       (if __idPiste (setq _idPiste (car __idPiste)))
       _idPiste)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; geometry_msgs/Pose _obstaclePosition
    (send _obstaclePosition :serialization-length)
    ;; geometry_msgs/Pose _obstacleBodyCenter
    (send _obstacleBodyCenter :serialization-length)
    ;; float32 _distanceCurviligne
    4
    ;; std_msgs/Float32 _groundHeight
    (send _groundHeight :serialization-length)
    ;; geometry_msgs/Twist _obstacleVelocity
    (send _obstacleVelocity :serialization-length)
    ;; geometry_msgs/Accel _obstacleAcceleration
    (send _obstacleAcceleration :serialization-length)
    ;; geometry_msgs/Vector3 _obstacleCap
    (send _obstacleCap :serialization-length)
    ;; std_msgs/UInt8 _existenceProbability
    (send _existenceProbability :serialization-length)
    ;; std_msgs/UInt8 _existenceState
    (send _existenceState :serialization-length)
    ;; std_msgs/Float32 _scoreDetection
    (send _scoreDetection :serialization-length)
    ;; std_msgs/Float32 _nbrDetection
    (send _nbrDetection :serialization-length)
    ;; std_msgs/Float32 _nbrVisibility
    (send _nbrVisibility :serialization-length)
    ;; std_msgs/Float32 _scorePersistence
    (send _scorePersistence :serialization-length)
    ;; std_msgs/Float32 _nbrUpdate
    (send _nbrUpdate :serialization-length)
    ;; std_msgs/Float32 _nbrAge
    (send _nbrAge :serialization-length)
    ;; time _existenceFirstTime
    8
    ;; std_msgs/Float32 _existenceDurationTime
    (send _existenceDurationTime :serialization-length)
    ;; std_msgs/UInt8 _anchorPoint
    (send _anchorPoint :serialization-length)
    ;; geometry_msgs/Pose _obstaclePoseVariance
    (send _obstaclePoseVariance :serialization-length)
    ;; geometry_msgs/Twist _obstacleVelocityVariance
    (send _obstacleVelocityVariance :serialization-length)
    ;; geometry_msgs/Vector3 _obstacleDimensions
    (send _obstacleDimensions :serialization-length)
    ;; uint8 _obstacleClass
    1
    ;; uint8 _vision_only_sign_type
    1
    ;; std_msgs/UInt8 _classificationProbability
    (send _classificationProbability :serialization-length)
    ;; uint8 _obstacleAssignment
    1
    ;; geometry_msgs/Point[4] _obstacleCorner
    (apply #'+ (send-all _obstacleCorner :serialization-length))
    ;; uint8 _NbrOccupiedLane
    1
    ;; uint8[2] _indexAssignmentLine
    (* 1    2)
    ;; std_msgs/Float32 _positionLane
    (send _positionLane :serialization-length)
    ;; std_msgs/Float32 _departureRighttDistance
    (send _departureRighttDistance :serialization-length)
    ;; std_msgs/Float32 _departureLeftDistance
    (send _departureLeftDistance :serialization-length)
    ;; std_msgs/Int16 _trafficLights
    (send _trafficLights :serialization-length)
    ;; std_msgs/Int16 _vehicleLights
    (send _vehicleLights :serialization-length)
    ;; std_msgs/UInt16[3] _idPiste
    (apply #'+ (send-all _idPiste :serialization-length))
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; geometry_msgs/Pose _obstaclePosition
       (send _obstaclePosition :serialize s)
     ;; geometry_msgs/Pose _obstacleBodyCenter
       (send _obstacleBodyCenter :serialize s)
     ;; float32 _distanceCurviligne
       (sys::poke _distanceCurviligne (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; std_msgs/Float32 _groundHeight
       (send _groundHeight :serialize s)
     ;; geometry_msgs/Twist _obstacleVelocity
       (send _obstacleVelocity :serialize s)
     ;; geometry_msgs/Accel _obstacleAcceleration
       (send _obstacleAcceleration :serialize s)
     ;; geometry_msgs/Vector3 _obstacleCap
       (send _obstacleCap :serialize s)
     ;; std_msgs/UInt8 _existenceProbability
       (send _existenceProbability :serialize s)
     ;; std_msgs/UInt8 _existenceState
       (send _existenceState :serialize s)
     ;; std_msgs/Float32 _scoreDetection
       (send _scoreDetection :serialize s)
     ;; std_msgs/Float32 _nbrDetection
       (send _nbrDetection :serialize s)
     ;; std_msgs/Float32 _nbrVisibility
       (send _nbrVisibility :serialize s)
     ;; std_msgs/Float32 _scorePersistence
       (send _scorePersistence :serialize s)
     ;; std_msgs/Float32 _nbrUpdate
       (send _nbrUpdate :serialize s)
     ;; std_msgs/Float32 _nbrAge
       (send _nbrAge :serialize s)
     ;; time _existenceFirstTime
       (write-long (send _existenceFirstTime :sec) s) (write-long (send _existenceFirstTime :nsec) s)
     ;; std_msgs/Float32 _existenceDurationTime
       (send _existenceDurationTime :serialize s)
     ;; std_msgs/UInt8 _anchorPoint
       (send _anchorPoint :serialize s)
     ;; geometry_msgs/Pose _obstaclePoseVariance
       (send _obstaclePoseVariance :serialize s)
     ;; geometry_msgs/Twist _obstacleVelocityVariance
       (send _obstacleVelocityVariance :serialize s)
     ;; geometry_msgs/Vector3 _obstacleDimensions
       (send _obstacleDimensions :serialize s)
     ;; uint8 _obstacleClass
       (write-byte _obstacleClass s)
     ;; uint8 _vision_only_sign_type
       (write-byte _vision_only_sign_type s)
     ;; std_msgs/UInt8 _classificationProbability
       (send _classificationProbability :serialize s)
     ;; uint8 _obstacleAssignment
       (write-byte _obstacleAssignment s)
     ;; geometry_msgs/Point[4] _obstacleCorner
     (dolist (elem _obstacleCorner)
       (send elem :serialize s)
       )
     ;; uint8 _NbrOccupiedLane
       (write-byte _NbrOccupiedLane s)
     ;; uint8[2] _indexAssignmentLine
     (princ _indexAssignmentLine s)
     ;; std_msgs/Float32 _positionLane
       (send _positionLane :serialize s)
     ;; std_msgs/Float32 _departureRighttDistance
       (send _departureRighttDistance :serialize s)
     ;; std_msgs/Float32 _departureLeftDistance
       (send _departureLeftDistance :serialize s)
     ;; std_msgs/Int16 _trafficLights
       (send _trafficLights :serialize s)
     ;; std_msgs/Int16 _vehicleLights
       (send _vehicleLights :serialize s)
     ;; std_msgs/UInt16[3] _idPiste
     (dolist (elem _idPiste)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; geometry_msgs/Pose _obstaclePosition
     (send _obstaclePosition :deserialize buf ptr-) (incf ptr- (send _obstaclePosition :serialization-length))
   ;; geometry_msgs/Pose _obstacleBodyCenter
     (send _obstacleBodyCenter :deserialize buf ptr-) (incf ptr- (send _obstacleBodyCenter :serialization-length))
   ;; float32 _distanceCurviligne
     (setq _distanceCurviligne (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; std_msgs/Float32 _groundHeight
     (send _groundHeight :deserialize buf ptr-) (incf ptr- (send _groundHeight :serialization-length))
   ;; geometry_msgs/Twist _obstacleVelocity
     (send _obstacleVelocity :deserialize buf ptr-) (incf ptr- (send _obstacleVelocity :serialization-length))
   ;; geometry_msgs/Accel _obstacleAcceleration
     (send _obstacleAcceleration :deserialize buf ptr-) (incf ptr- (send _obstacleAcceleration :serialization-length))
   ;; geometry_msgs/Vector3 _obstacleCap
     (send _obstacleCap :deserialize buf ptr-) (incf ptr- (send _obstacleCap :serialization-length))
   ;; std_msgs/UInt8 _existenceProbability
     (send _existenceProbability :deserialize buf ptr-) (incf ptr- (send _existenceProbability :serialization-length))
   ;; std_msgs/UInt8 _existenceState
     (send _existenceState :deserialize buf ptr-) (incf ptr- (send _existenceState :serialization-length))
   ;; std_msgs/Float32 _scoreDetection
     (send _scoreDetection :deserialize buf ptr-) (incf ptr- (send _scoreDetection :serialization-length))
   ;; std_msgs/Float32 _nbrDetection
     (send _nbrDetection :deserialize buf ptr-) (incf ptr- (send _nbrDetection :serialization-length))
   ;; std_msgs/Float32 _nbrVisibility
     (send _nbrVisibility :deserialize buf ptr-) (incf ptr- (send _nbrVisibility :serialization-length))
   ;; std_msgs/Float32 _scorePersistence
     (send _scorePersistence :deserialize buf ptr-) (incf ptr- (send _scorePersistence :serialization-length))
   ;; std_msgs/Float32 _nbrUpdate
     (send _nbrUpdate :deserialize buf ptr-) (incf ptr- (send _nbrUpdate :serialization-length))
   ;; std_msgs/Float32 _nbrAge
     (send _nbrAge :deserialize buf ptr-) (incf ptr- (send _nbrAge :serialization-length))
   ;; time _existenceFirstTime
     (send _existenceFirstTime :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _existenceFirstTime :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; std_msgs/Float32 _existenceDurationTime
     (send _existenceDurationTime :deserialize buf ptr-) (incf ptr- (send _existenceDurationTime :serialization-length))
   ;; std_msgs/UInt8 _anchorPoint
     (send _anchorPoint :deserialize buf ptr-) (incf ptr- (send _anchorPoint :serialization-length))
   ;; geometry_msgs/Pose _obstaclePoseVariance
     (send _obstaclePoseVariance :deserialize buf ptr-) (incf ptr- (send _obstaclePoseVariance :serialization-length))
   ;; geometry_msgs/Twist _obstacleVelocityVariance
     (send _obstacleVelocityVariance :deserialize buf ptr-) (incf ptr- (send _obstacleVelocityVariance :serialization-length))
   ;; geometry_msgs/Vector3 _obstacleDimensions
     (send _obstacleDimensions :deserialize buf ptr-) (incf ptr- (send _obstacleDimensions :serialization-length))
   ;; uint8 _obstacleClass
     (setq _obstacleClass (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _vision_only_sign_type
     (setq _vision_only_sign_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; std_msgs/UInt8 _classificationProbability
     (send _classificationProbability :deserialize buf ptr-) (incf ptr- (send _classificationProbability :serialization-length))
   ;; uint8 _obstacleAssignment
     (setq _obstacleAssignment (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; geometry_msgs/Point[4] _obstacleCorner
   (dotimes (i 4)
     (send (elt _obstacleCorner i) :deserialize buf ptr-) (incf ptr- (send (elt _obstacleCorner i) :serialization-length))
     )
   ;; uint8 _NbrOccupiedLane
     (setq _NbrOccupiedLane (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8[2] _indexAssignmentLine
   (setq _indexAssignmentLine (make-array 2 :element-type :char))
   (replace _indexAssignmentLine buf :start2 ptr-) (incf ptr- 2)
   ;; std_msgs/Float32 _positionLane
     (send _positionLane :deserialize buf ptr-) (incf ptr- (send _positionLane :serialization-length))
   ;; std_msgs/Float32 _departureRighttDistance
     (send _departureRighttDistance :deserialize buf ptr-) (incf ptr- (send _departureRighttDistance :serialization-length))
   ;; std_msgs/Float32 _departureLeftDistance
     (send _departureLeftDistance :deserialize buf ptr-) (incf ptr- (send _departureLeftDistance :serialization-length))
   ;; std_msgs/Int16 _trafficLights
     (send _trafficLights :deserialize buf ptr-) (incf ptr- (send _trafficLights :serialization-length))
   ;; std_msgs/Int16 _vehicleLights
     (send _vehicleLights :deserialize buf ptr-) (incf ptr- (send _vehicleLights :serialization-length))
   ;; std_msgs/UInt16[3] _idPiste
   (dotimes (i 3)
     (send (elt _idPiste i) :deserialize buf ptr-) (incf ptr- (send (elt _idPiste i) :serialization-length))
     )
   ;;
   self)
  )

(setf (get project_s_msgs::ObstacleFusion :md5sum-) "664d48d67f466ce15a45b6a2d40f7977")
(setf (get project_s_msgs::ObstacleFusion :datatype-) "project_s_msgs/ObstacleFusion")
(setf (get project_s_msgs::ObstacleFusion :definition-)
      "Header header
std_msgs/UInt8 id

geometry_msgs/Pose obstaclePosition		# obstacle position
geometry_msgs/Pose obstacleBodyCenter	        # Obstacle Center for Corner Computation
float32 distanceCurviligne
std_msgs/Float32 groundHeight			# ground height
geometry_msgs/Twist obstacleVelocity		# obstacle speed
geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
geometry_msgs/Vector3 obstacleCap
std_msgs/UInt8 existenceProbability
std_msgs/UInt8 existenceState
uint8 IDLE_TRACK    = 0
uint8 PRE_TRACK	    = 1
uint8 POST_TRACK    = 2
uint8 CURRENT_TRACK = 3
std_msgs/Float32 scoreDetection
std_msgs/Float32 nbrDetection
std_msgs/Float32 nbrVisibility
std_msgs/Float32 scorePersistence
std_msgs/Float32 nbrUpdate
std_msgs/Float32 nbrAge
time existenceFirstTime
std_msgs/Float32 existenceDurationTime
std_msgs/UInt8 anchorPoint			# reference point
geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance
geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance
geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height
uint8 obstacleClass
uint8 vision_only_sign_type
std_msgs/UInt8 classificationProbability

uint8 obstacleAssignment
uint8 ASSIGNMENT_COTE_DROIT  = 1
uint8 ASSIGNMENT_COTE_GAUCHE = 2

uint8 CORNER_FRONT_RIGHT= 0
uint8 CORNER_FRONT_LEFT = 1
uint8 CORNER_BACK_RIGHT = 2
uint8 CORNER_BACK_LEFT  = 3
geometry_msgs/Point[4] obstacleCorner

uint8 OCCUPIED_LANE_INDEFINI  = 255
uint8 NbrOccupiedLane
uint8 INDEX_LINE_INDEFINI  = 255
uint8[2] indexAssignmentLine
std_msgs/Float32 positionLane
std_msgs/Float32 departureRighttDistance
std_msgs/Float32 departureLeftDistance

std_msgs/Int16 trafficLights
std_msgs/Int16 vehicleLights
std_msgs/UInt16[3] idPiste			#define NBR_SENSOR		3	(voir obstacles_fusion.cpp)

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
MSG: std_msgs/UInt8
uint8 data

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
MSG: std_msgs/Float32
float32 data
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
MSG: std_msgs/Int16
int16 data

================================================================================
MSG: std_msgs/UInt16
uint16 data

")



(provide :project_s_msgs/ObstacleFusion "664d48d67f466ce15a45b6a2d40f7977")


