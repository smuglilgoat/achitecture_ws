;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::GenericSmartData)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'GenericSmartData (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::GENERICSMARTDATA")
  (make-package "PROJECT_S_MSGS::GENERICSMARTDATA"))

(in-package "ROS")
;;//! \htmlinclude GenericSmartData.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*OBSTACLE_CLASS_NONE*" (find-package "PROJECT_S_MSGS::GENERICSMARTDATA"))
(shadow '*OBSTACLE_CLASS_NONE* (find-package "PROJECT_S_MSGS::GENERICSMARTDATA"))
(defconstant project_s_msgs::GenericSmartData::*OBSTACLE_CLASS_NONE* 0)
(intern "*OBSTACLE_CLASS_SIGN*" (find-package "PROJECT_S_MSGS::GENERICSMARTDATA"))
(shadow '*OBSTACLE_CLASS_SIGN* (find-package "PROJECT_S_MSGS::GENERICSMARTDATA"))
(defconstant project_s_msgs::GenericSmartData::*OBSTACLE_CLASS_SIGN* 1)
(intern "*OBSTACLE_CLASS_PLOT*" (find-package "PROJECT_S_MSGS::GENERICSMARTDATA"))
(shadow '*OBSTACLE_CLASS_PLOT* (find-package "PROJECT_S_MSGS::GENERICSMARTDATA"))
(defconstant project_s_msgs::GenericSmartData::*OBSTACLE_CLASS_PLOT* 2)
(intern "*OBSTACLE_CLASS_INVALID*" (find-package "PROJECT_S_MSGS::GENERICSMARTDATA"))
(shadow '*OBSTACLE_CLASS_INVALID* (find-package "PROJECT_S_MSGS::GENERICSMARTDATA"))
(defconstant project_s_msgs::GenericSmartData::*OBSTACLE_CLASS_INVALID* 255)
(defclass project_s_msgs::GenericSmartData
  :super ros::object
  :slots (_header _id _obstaclePosition _obstacleVelocity _obstacleAcceleration _obstacleDimensions _obstaclePoseVariance _obstacleVelocityVariance _obstacleClass _vision_only_sign_type ))

(defmethod project_s_msgs::GenericSmartData
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt16 :init))
    ((:obstaclePosition __obstaclePosition) (instance geometry_msgs::Pose :init))
    ((:obstacleVelocity __obstacleVelocity) (instance geometry_msgs::Twist :init))
    ((:obstacleAcceleration __obstacleAcceleration) (instance geometry_msgs::Accel :init))
    ((:obstacleDimensions __obstacleDimensions) (instance geometry_msgs::Vector3 :init))
    ((:obstaclePoseVariance __obstaclePoseVariance) (instance geometry_msgs::Pose :init))
    ((:obstacleVelocityVariance __obstacleVelocityVariance) (instance geometry_msgs::Twist :init))
    ((:obstacleClass __obstacleClass) 0)
    ((:vision_only_sign_type __vision_only_sign_type) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _obstaclePosition __obstaclePosition)
   (setq _obstacleVelocity __obstacleVelocity)
   (setq _obstacleAcceleration __obstacleAcceleration)
   (setq _obstacleDimensions __obstacleDimensions)
   (setq _obstaclePoseVariance __obstaclePoseVariance)
   (setq _obstacleVelocityVariance __obstacleVelocityVariance)
   (setq _obstacleClass (round __obstacleClass))
   (setq _vision_only_sign_type (round __vision_only_sign_type))
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
  (:obstacleDimensions
   (&rest __obstacleDimensions)
   (if (keywordp (car __obstacleDimensions))
       (send* _obstacleDimensions __obstacleDimensions)
     (progn
       (if __obstacleDimensions (setq _obstacleDimensions (car __obstacleDimensions)))
       _obstacleDimensions)))
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
  (:obstacleClass
   (&optional __obstacleClass)
   (if __obstacleClass (setq _obstacleClass __obstacleClass)) _obstacleClass)
  (:vision_only_sign_type
   (&optional __vision_only_sign_type)
   (if __vision_only_sign_type (setq _vision_only_sign_type __vision_only_sign_type)) _vision_only_sign_type)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt16 _id
    (send _id :serialization-length)
    ;; geometry_msgs/Pose _obstaclePosition
    (send _obstaclePosition :serialization-length)
    ;; geometry_msgs/Twist _obstacleVelocity
    (send _obstacleVelocity :serialization-length)
    ;; geometry_msgs/Accel _obstacleAcceleration
    (send _obstacleAcceleration :serialization-length)
    ;; geometry_msgs/Vector3 _obstacleDimensions
    (send _obstacleDimensions :serialization-length)
    ;; geometry_msgs/Pose _obstaclePoseVariance
    (send _obstaclePoseVariance :serialization-length)
    ;; geometry_msgs/Twist _obstacleVelocityVariance
    (send _obstacleVelocityVariance :serialization-length)
    ;; uint8 _obstacleClass
    1
    ;; uint8 _vision_only_sign_type
    1
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
     ;; geometry_msgs/Twist _obstacleVelocity
       (send _obstacleVelocity :serialize s)
     ;; geometry_msgs/Accel _obstacleAcceleration
       (send _obstacleAcceleration :serialize s)
     ;; geometry_msgs/Vector3 _obstacleDimensions
       (send _obstacleDimensions :serialize s)
     ;; geometry_msgs/Pose _obstaclePoseVariance
       (send _obstaclePoseVariance :serialize s)
     ;; geometry_msgs/Twist _obstacleVelocityVariance
       (send _obstacleVelocityVariance :serialize s)
     ;; uint8 _obstacleClass
       (write-byte _obstacleClass s)
     ;; uint8 _vision_only_sign_type
       (write-byte _vision_only_sign_type s)
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
   ;; geometry_msgs/Twist _obstacleVelocity
     (send _obstacleVelocity :deserialize buf ptr-) (incf ptr- (send _obstacleVelocity :serialization-length))
   ;; geometry_msgs/Accel _obstacleAcceleration
     (send _obstacleAcceleration :deserialize buf ptr-) (incf ptr- (send _obstacleAcceleration :serialization-length))
   ;; geometry_msgs/Vector3 _obstacleDimensions
     (send _obstacleDimensions :deserialize buf ptr-) (incf ptr- (send _obstacleDimensions :serialization-length))
   ;; geometry_msgs/Pose _obstaclePoseVariance
     (send _obstaclePoseVariance :deserialize buf ptr-) (incf ptr- (send _obstaclePoseVariance :serialization-length))
   ;; geometry_msgs/Twist _obstacleVelocityVariance
     (send _obstacleVelocityVariance :deserialize buf ptr-) (incf ptr- (send _obstacleVelocityVariance :serialization-length))
   ;; uint8 _obstacleClass
     (setq _obstacleClass (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _vision_only_sign_type
     (setq _vision_only_sign_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get project_s_msgs::GenericSmartData :md5sum-) "78b8f97069427362961d828004f4a726")
(setf (get project_s_msgs::GenericSmartData :datatype-) "project_s_msgs/GenericSmartData")
(setf (get project_s_msgs::GenericSmartData :definition-)
      "Header header
std_msgs/UInt16 id

geometry_msgs/Pose obstaclePosition		# obstacle position
geometry_msgs/Twist obstacleVelocity		# obstacle speed
geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height
geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance
geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance

uint8 OBSTACLE_CLASS_NONE = 0
uint8 OBSTACLE_CLASS_SIGN = 1
uint8 OBSTACLE_CLASS_PLOT = 2
uint8 OBSTACLE_CLASS_INVALID = 255
uint8 obstacleClass

uint8 vision_only_sign_type

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

")



(provide :project_s_msgs/GenericSmartData "78b8f97069427362961d828004f4a726")


