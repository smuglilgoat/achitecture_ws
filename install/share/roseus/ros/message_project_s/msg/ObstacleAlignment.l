;; Auto-generated. Do not edit!


(when (boundp 'message_project_s::ObstacleAlignment)
  (if (not (find-package "MESSAGE_PROJECT_S"))
    (make-package "MESSAGE_PROJECT_S"))
  (shadow 'ObstacleAlignment (find-package "MESSAGE_PROJECT_S")))
(unless (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT")
  (make-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENT"))

(in-package "ROS")
;;//! \htmlinclude ObstacleAlignment.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass message_project_s::ObstacleAlignment
  :super ros::object
  :slots (_header _id _obstaclePosition _obstacleVelocity _obstacleAcceleration _obstaclePoseVariance _obstacleVelocityVariance _obstacleDimensions _groundHeight _obstacleClass _vision_only_sign_type _classificationProbability _dateAcquisition ))

(defmethod message_project_s::ObstacleAlignment
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:obstaclePosition __obstaclePosition) (instance geometry_msgs::Pose :init))
    ((:obstacleVelocity __obstacleVelocity) (instance geometry_msgs::Twist :init))
    ((:obstacleAcceleration __obstacleAcceleration) (instance geometry_msgs::Accel :init))
    ((:obstaclePoseVariance __obstaclePoseVariance) (instance geometry_msgs::Pose :init))
    ((:obstacleVelocityVariance __obstacleVelocityVariance) (instance geometry_msgs::Twist :init))
    ((:obstacleDimensions __obstacleDimensions) (instance geometry_msgs::Vector3 :init))
    ((:groundHeight __groundHeight) (instance std_msgs::Float32 :init))
    ((:obstacleClass __obstacleClass) 0)
    ((:vision_only_sign_type __vision_only_sign_type) 0)
    ((:classificationProbability __classificationProbability) (instance std_msgs::UInt8 :init))
    ((:dateAcquisition __dateAcquisition) (instance std_msgs::Float64 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _obstaclePosition __obstaclePosition)
   (setq _obstacleVelocity __obstacleVelocity)
   (setq _obstacleAcceleration __obstacleAcceleration)
   (setq _obstaclePoseVariance __obstaclePoseVariance)
   (setq _obstacleVelocityVariance __obstacleVelocityVariance)
   (setq _obstacleDimensions __obstacleDimensions)
   (setq _groundHeight __groundHeight)
   (setq _obstacleClass (round __obstacleClass))
   (setq _vision_only_sign_type (round __vision_only_sign_type))
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
  (:groundHeight
   (&rest __groundHeight)
   (if (keywordp (car __groundHeight))
       (send* _groundHeight __groundHeight)
     (progn
       (if __groundHeight (setq _groundHeight (car __groundHeight)))
       _groundHeight)))
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
    ;; geometry_msgs/Twist _obstacleVelocity
    (send _obstacleVelocity :serialization-length)
    ;; geometry_msgs/Accel _obstacleAcceleration
    (send _obstacleAcceleration :serialization-length)
    ;; geometry_msgs/Pose _obstaclePoseVariance
    (send _obstaclePoseVariance :serialization-length)
    ;; geometry_msgs/Twist _obstacleVelocityVariance
    (send _obstacleVelocityVariance :serialization-length)
    ;; geometry_msgs/Vector3 _obstacleDimensions
    (send _obstacleDimensions :serialization-length)
    ;; std_msgs/Float32 _groundHeight
    (send _groundHeight :serialization-length)
    ;; uint8 _obstacleClass
    1
    ;; uint8 _vision_only_sign_type
    1
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
     ;; geometry_msgs/Twist _obstacleVelocity
       (send _obstacleVelocity :serialize s)
     ;; geometry_msgs/Accel _obstacleAcceleration
       (send _obstacleAcceleration :serialize s)
     ;; geometry_msgs/Pose _obstaclePoseVariance
       (send _obstaclePoseVariance :serialize s)
     ;; geometry_msgs/Twist _obstacleVelocityVariance
       (send _obstacleVelocityVariance :serialize s)
     ;; geometry_msgs/Vector3 _obstacleDimensions
       (send _obstacleDimensions :serialize s)
     ;; std_msgs/Float32 _groundHeight
       (send _groundHeight :serialize s)
     ;; uint8 _obstacleClass
       (write-byte _obstacleClass s)
     ;; uint8 _vision_only_sign_type
       (write-byte _vision_only_sign_type s)
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
   ;; geometry_msgs/Twist _obstacleVelocity
     (send _obstacleVelocity :deserialize buf ptr-) (incf ptr- (send _obstacleVelocity :serialization-length))
   ;; geometry_msgs/Accel _obstacleAcceleration
     (send _obstacleAcceleration :deserialize buf ptr-) (incf ptr- (send _obstacleAcceleration :serialization-length))
   ;; geometry_msgs/Pose _obstaclePoseVariance
     (send _obstaclePoseVariance :deserialize buf ptr-) (incf ptr- (send _obstaclePoseVariance :serialization-length))
   ;; geometry_msgs/Twist _obstacleVelocityVariance
     (send _obstacleVelocityVariance :deserialize buf ptr-) (incf ptr- (send _obstacleVelocityVariance :serialization-length))
   ;; geometry_msgs/Vector3 _obstacleDimensions
     (send _obstacleDimensions :deserialize buf ptr-) (incf ptr- (send _obstacleDimensions :serialization-length))
   ;; std_msgs/Float32 _groundHeight
     (send _groundHeight :deserialize buf ptr-) (incf ptr- (send _groundHeight :serialization-length))
   ;; uint8 _obstacleClass
     (setq _obstacleClass (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _vision_only_sign_type
     (setq _vision_only_sign_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; std_msgs/UInt8 _classificationProbability
     (send _classificationProbability :deserialize buf ptr-) (incf ptr- (send _classificationProbability :serialization-length))
   ;; std_msgs/Float64 _dateAcquisition
     (send _dateAcquisition :deserialize buf ptr-) (incf ptr- (send _dateAcquisition :serialization-length))
   ;;
   self)
  )

(setf (get message_project_s::ObstacleAlignment :md5sum-) "dce63e168b330791d863e425f8e25292")
(setf (get message_project_s::ObstacleAlignment :datatype-) "message_project_s/ObstacleAlignment")
(setf (get message_project_s::ObstacleAlignment :definition-)
      "Header header
std_msgs/UInt8 id

geometry_msgs/Pose obstaclePosition		# obstacle position
geometry_msgs/Twist obstacleVelocity		# obstacle speed
geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance
geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance
geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height
std_msgs/Float32 groundHeight			# ground height
uint8 obstacleClass
uint8 vision_only_sign_type
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



(provide :message_project_s/ObstacleAlignment "dce63e168b330791d863e425f8e25292")


