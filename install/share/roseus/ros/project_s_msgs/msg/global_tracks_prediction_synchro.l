;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::global_tracks_prediction_synchro)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'global_tracks_prediction_synchro (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::GLOBAL_TRACKS_PREDICTION_SYNCHRO")
  (make-package "PROJECT_S_MSGS::GLOBAL_TRACKS_PREDICTION_SYNCHRO"))

(in-package "ROS")
;;//! \htmlinclude global_tracks_prediction_synchro.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::global_tracks_prediction_synchro
  :super ros::object
  :slots (_header _id _obstaclePosition _headerPosition _groundHeight _obstacleVelocity _obstacleAcceleration _obstaclePoseVariance _headerPoseVariance _obstacleVelocityVariance _headerVelocityVariance _obstacleDimensions _obstacleClass _classificationProbability _dateAcquisition ))

(defmethod project_s_msgs::global_tracks_prediction_synchro
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:obstaclePosition __obstaclePosition) (instance geometry_msgs::Pose :init))
    ((:headerPosition __headerPosition) (instance std_msgs::Header :init))
    ((:groundHeight __groundHeight) (instance std_msgs::Float32 :init))
    ((:obstacleVelocity __obstacleVelocity) (instance geometry_msgs::Twist :init))
    ((:obstacleAcceleration __obstacleAcceleration) (instance geometry_msgs::Accel :init))
    ((:obstaclePoseVariance __obstaclePoseVariance) (instance geometry_msgs::Pose :init))
    ((:headerPoseVariance __headerPoseVariance) (instance std_msgs::Header :init))
    ((:obstacleVelocityVariance __obstacleVelocityVariance) (instance geometry_msgs::Twist :init))
    ((:headerVelocityVariance __headerVelocityVariance) (instance std_msgs::Header :init))
    ((:obstacleDimensions __obstacleDimensions) (instance geometry_msgs::Vector3 :init))
    ((:obstacleClass __obstacleClass) (instance std_msgs::UInt8 :init))
    ((:classificationProbability __classificationProbability) (instance std_msgs::UInt8 :init))
    ((:dateAcquisition __dateAcquisition) (instance std_msgs::Float64 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _obstaclePosition __obstaclePosition)
   (setq _headerPosition __headerPosition)
   (setq _groundHeight __groundHeight)
   (setq _obstacleVelocity __obstacleVelocity)
   (setq _obstacleAcceleration __obstacleAcceleration)
   (setq _obstaclePoseVariance __obstaclePoseVariance)
   (setq _headerPoseVariance __headerPoseVariance)
   (setq _obstacleVelocityVariance __obstacleVelocityVariance)
   (setq _headerVelocityVariance __headerVelocityVariance)
   (setq _obstacleDimensions __obstacleDimensions)
   (setq _obstacleClass __obstacleClass)
   (setq _classificationProbability __classificationProbability)
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
  (:headerPosition
   (&rest __headerPosition)
   (if (keywordp (car __headerPosition))
       (send* _headerPosition __headerPosition)
     (progn
       (if __headerPosition (setq _headerPosition (car __headerPosition)))
       _headerPosition)))
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
  (:obstaclePoseVariance
   (&rest __obstaclePoseVariance)
   (if (keywordp (car __obstaclePoseVariance))
       (send* _obstaclePoseVariance __obstaclePoseVariance)
     (progn
       (if __obstaclePoseVariance (setq _obstaclePoseVariance (car __obstaclePoseVariance)))
       _obstaclePoseVariance)))
  (:headerPoseVariance
   (&rest __headerPoseVariance)
   (if (keywordp (car __headerPoseVariance))
       (send* _headerPoseVariance __headerPoseVariance)
     (progn
       (if __headerPoseVariance (setq _headerPoseVariance (car __headerPoseVariance)))
       _headerPoseVariance)))
  (:obstacleVelocityVariance
   (&rest __obstacleVelocityVariance)
   (if (keywordp (car __obstacleVelocityVariance))
       (send* _obstacleVelocityVariance __obstacleVelocityVariance)
     (progn
       (if __obstacleVelocityVariance (setq _obstacleVelocityVariance (car __obstacleVelocityVariance)))
       _obstacleVelocityVariance)))
  (:headerVelocityVariance
   (&rest __headerVelocityVariance)
   (if (keywordp (car __headerVelocityVariance))
       (send* _headerVelocityVariance __headerVelocityVariance)
     (progn
       (if __headerVelocityVariance (setq _headerVelocityVariance (car __headerVelocityVariance)))
       _headerVelocityVariance)))
  (:obstacleDimensions
   (&rest __obstacleDimensions)
   (if (keywordp (car __obstacleDimensions))
       (send* _obstacleDimensions __obstacleDimensions)
     (progn
       (if __obstacleDimensions (setq _obstacleDimensions (car __obstacleDimensions)))
       _obstacleDimensions)))
  (:obstacleClass
   (&rest __obstacleClass)
   (if (keywordp (car __obstacleClass))
       (send* _obstacleClass __obstacleClass)
     (progn
       (if __obstacleClass (setq _obstacleClass (car __obstacleClass)))
       _obstacleClass)))
  (:classificationProbability
   (&rest __classificationProbability)
   (if (keywordp (car __classificationProbability))
       (send* _classificationProbability __classificationProbability)
     (progn
       (if __classificationProbability (setq _classificationProbability (car __classificationProbability)))
       _classificationProbability)))
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
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; geometry_msgs/Pose _obstaclePosition
    (send _obstaclePosition :serialization-length)
    ;; std_msgs/Header _headerPosition
    (send _headerPosition :serialization-length)
    ;; std_msgs/Float32 _groundHeight
    (send _groundHeight :serialization-length)
    ;; geometry_msgs/Twist _obstacleVelocity
    (send _obstacleVelocity :serialization-length)
    ;; geometry_msgs/Accel _obstacleAcceleration
    (send _obstacleAcceleration :serialization-length)
    ;; geometry_msgs/Pose _obstaclePoseVariance
    (send _obstaclePoseVariance :serialization-length)
    ;; std_msgs/Header _headerPoseVariance
    (send _headerPoseVariance :serialization-length)
    ;; geometry_msgs/Twist _obstacleVelocityVariance
    (send _obstacleVelocityVariance :serialization-length)
    ;; std_msgs/Header _headerVelocityVariance
    (send _headerVelocityVariance :serialization-length)
    ;; geometry_msgs/Vector3 _obstacleDimensions
    (send _obstacleDimensions :serialization-length)
    ;; std_msgs/UInt8 _obstacleClass
    (send _obstacleClass :serialization-length)
    ;; std_msgs/UInt8 _classificationProbability
    (send _classificationProbability :serialization-length)
    ;; std_msgs/Float64 _dateAcquisition
    (send _dateAcquisition :serialization-length)
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
     ;; std_msgs/Header _headerPosition
       (send _headerPosition :serialize s)
     ;; std_msgs/Float32 _groundHeight
       (send _groundHeight :serialize s)
     ;; geometry_msgs/Twist _obstacleVelocity
       (send _obstacleVelocity :serialize s)
     ;; geometry_msgs/Accel _obstacleAcceleration
       (send _obstacleAcceleration :serialize s)
     ;; geometry_msgs/Pose _obstaclePoseVariance
       (send _obstaclePoseVariance :serialize s)
     ;; std_msgs/Header _headerPoseVariance
       (send _headerPoseVariance :serialize s)
     ;; geometry_msgs/Twist _obstacleVelocityVariance
       (send _obstacleVelocityVariance :serialize s)
     ;; std_msgs/Header _headerVelocityVariance
       (send _headerVelocityVariance :serialize s)
     ;; geometry_msgs/Vector3 _obstacleDimensions
       (send _obstacleDimensions :serialize s)
     ;; std_msgs/UInt8 _obstacleClass
       (send _obstacleClass :serialize s)
     ;; std_msgs/UInt8 _classificationProbability
       (send _classificationProbability :serialize s)
     ;; std_msgs/Float64 _dateAcquisition
       (send _dateAcquisition :serialize s)
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
   ;; std_msgs/Header _headerPosition
     (send _headerPosition :deserialize buf ptr-) (incf ptr- (send _headerPosition :serialization-length))
   ;; std_msgs/Float32 _groundHeight
     (send _groundHeight :deserialize buf ptr-) (incf ptr- (send _groundHeight :serialization-length))
   ;; geometry_msgs/Twist _obstacleVelocity
     (send _obstacleVelocity :deserialize buf ptr-) (incf ptr- (send _obstacleVelocity :serialization-length))
   ;; geometry_msgs/Accel _obstacleAcceleration
     (send _obstacleAcceleration :deserialize buf ptr-) (incf ptr- (send _obstacleAcceleration :serialization-length))
   ;; geometry_msgs/Pose _obstaclePoseVariance
     (send _obstaclePoseVariance :deserialize buf ptr-) (incf ptr- (send _obstaclePoseVariance :serialization-length))
   ;; std_msgs/Header _headerPoseVariance
     (send _headerPoseVariance :deserialize buf ptr-) (incf ptr- (send _headerPoseVariance :serialization-length))
   ;; geometry_msgs/Twist _obstacleVelocityVariance
     (send _obstacleVelocityVariance :deserialize buf ptr-) (incf ptr- (send _obstacleVelocityVariance :serialization-length))
   ;; std_msgs/Header _headerVelocityVariance
     (send _headerVelocityVariance :deserialize buf ptr-) (incf ptr- (send _headerVelocityVariance :serialization-length))
   ;; geometry_msgs/Vector3 _obstacleDimensions
     (send _obstacleDimensions :deserialize buf ptr-) (incf ptr- (send _obstacleDimensions :serialization-length))
   ;; std_msgs/UInt8 _obstacleClass
     (send _obstacleClass :deserialize buf ptr-) (incf ptr- (send _obstacleClass :serialization-length))
   ;; std_msgs/UInt8 _classificationProbability
     (send _classificationProbability :deserialize buf ptr-) (incf ptr- (send _classificationProbability :serialization-length))
   ;; std_msgs/Float64 _dateAcquisition
     (send _dateAcquisition :deserialize buf ptr-) (incf ptr- (send _dateAcquisition :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::global_tracks_prediction_synchro :md5sum-) "159e2baf42cf24b53560d72be3905436")
(setf (get project_s_msgs::global_tracks_prediction_synchro :datatype-) "project_s_msgs/global_tracks_prediction_synchro")
(setf (get project_s_msgs::global_tracks_prediction_synchro :definition-)
      "Header header
std_msgs/UInt8 id

geometry_msgs/Pose obstaclePosition		# obstacle position
Header headerPosition
std_msgs/Float32 groundHeight			# ground height
geometry_msgs/Twist obstacleVelocity		# obstacle speed
geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance
Header headerPoseVariance
geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance
Header headerVelocityVariance
geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height
std_msgs/UInt8 obstacleClass
std_msgs/UInt8 classificationProbability
std_msgs/Float64 dateAcquisition

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
MSG: std_msgs/Float64
float64 data
")



(provide :project_s_msgs/global_tracks_prediction_synchro "159e2baf42cf24b53560d72be3905436")


