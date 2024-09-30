;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ObstacleReport)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ObstacleReport (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::OBSTACLEREPORT")
  (make-package "PROJECT_S_MSGS::OBSTACLEREPORT"))

(in-package "ROS")
;;//! \htmlinclude ObstacleReport.msg.html
(if (not (find-package "NAV_MSGS"))
  (ros::roseus-add-msgs "nav_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::ObstacleReport
  :super ros::object
  :slots (_header _id _GenericSmartData _QtySmartData _dateAcquisition _odom ))

(defmethod project_s_msgs::ObstacleReport
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:GenericSmartData __GenericSmartData) (let (r) (dotimes (i 64) (push (instance project_s_msgs::GenericSmartData :init) r)) r))
    ((:QtySmartData __QtySmartData) (instance std_msgs::UInt8 :init))
    ((:dateAcquisition __dateAcquisition) (instance std_msgs::Float64 :init))
    ((:odom __odom) (instance nav_msgs::Odometry :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _GenericSmartData __GenericSmartData)
   (setq _QtySmartData __QtySmartData)
   (setq _dateAcquisition __dateAcquisition)
   (setq _odom __odom)
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
  (:GenericSmartData
   (&rest __GenericSmartData)
   (if (keywordp (car __GenericSmartData))
       (send* _GenericSmartData __GenericSmartData)
     (progn
       (if __GenericSmartData (setq _GenericSmartData (car __GenericSmartData)))
       _GenericSmartData)))
  (:QtySmartData
   (&rest __QtySmartData)
   (if (keywordp (car __QtySmartData))
       (send* _QtySmartData __QtySmartData)
     (progn
       (if __QtySmartData (setq _QtySmartData (car __QtySmartData)))
       _QtySmartData)))
  (:dateAcquisition
   (&rest __dateAcquisition)
   (if (keywordp (car __dateAcquisition))
       (send* _dateAcquisition __dateAcquisition)
     (progn
       (if __dateAcquisition (setq _dateAcquisition (car __dateAcquisition)))
       _dateAcquisition)))
  (:odom
   (&rest __odom)
   (if (keywordp (car __odom))
       (send* _odom __odom)
     (progn
       (if __odom (setq _odom (car __odom)))
       _odom)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; project_s_msgs/GenericSmartData[64] _GenericSmartData
    (apply #'+ (send-all _GenericSmartData :serialization-length))
    ;; std_msgs/UInt8 _QtySmartData
    (send _QtySmartData :serialization-length)
    ;; std_msgs/Float64 _dateAcquisition
    (send _dateAcquisition :serialization-length)
    ;; nav_msgs/Odometry _odom
    (send _odom :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; project_s_msgs/GenericSmartData[64] _GenericSmartData
     (dolist (elem _GenericSmartData)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _QtySmartData
       (send _QtySmartData :serialize s)
     ;; std_msgs/Float64 _dateAcquisition
       (send _dateAcquisition :serialize s)
     ;; nav_msgs/Odometry _odom
       (send _odom :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; project_s_msgs/GenericSmartData[64] _GenericSmartData
   (dotimes (i 64)
     (send (elt _GenericSmartData i) :deserialize buf ptr-) (incf ptr- (send (elt _GenericSmartData i) :serialization-length))
     )
   ;; std_msgs/UInt8 _QtySmartData
     (send _QtySmartData :deserialize buf ptr-) (incf ptr- (send _QtySmartData :serialization-length))
   ;; std_msgs/Float64 _dateAcquisition
     (send _dateAcquisition :deserialize buf ptr-) (incf ptr- (send _dateAcquisition :serialization-length))
   ;; nav_msgs/Odometry _odom
     (send _odom :deserialize buf ptr-) (incf ptr- (send _odom :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ObstacleReport :md5sum-) "d66d512738eec8e99605306c6e973be5")
(setf (get project_s_msgs::ObstacleReport :datatype-) "project_s_msgs/ObstacleReport")
(setf (get project_s_msgs::ObstacleReport :definition-)
      "Header header
std_msgs/UInt8 id

project_s_msgs/GenericSmartData[64] GenericSmartData		#GenericSmartData array   
std_msgs/UInt8 QtySmartData
std_msgs/Float64 dateAcquisition
nav_msgs/Odometry odom


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
MSG: project_s_msgs/GenericSmartData
Header header
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
MSG: std_msgs/Float64
float64 data
================================================================================
MSG: nav_msgs/Odometry
# This represents an estimate of a position and velocity in free space.  
# The pose in this message should be specified in the coordinate frame given by header.frame_id.
# The twist in this message should be specified in the coordinate frame given by the child_frame_id
Header header
string child_frame_id
geometry_msgs/PoseWithCovariance pose
geometry_msgs/TwistWithCovariance twist

================================================================================
MSG: geometry_msgs/PoseWithCovariance
# This represents a pose in free space with uncertainty.

Pose pose

# Row-major representation of the 6x6 covariance matrix
# The orientation parameters use a fixed-axis representation.
# In order, the parameters are:
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
float64[36] covariance

================================================================================
MSG: geometry_msgs/TwistWithCovariance
# This expresses velocity in free space with uncertainty.

Twist twist

# Row-major representation of the 6x6 covariance matrix
# The orientation parameters use a fixed-axis representation.
# In order, the parameters are:
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
float64[36] covariance

")



(provide :project_s_msgs/ObstacleReport "d66d512738eec8e99605306c6e973be5")


