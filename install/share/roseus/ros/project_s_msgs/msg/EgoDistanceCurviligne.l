;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::EgoDistanceCurviligne)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'EgoDistanceCurviligne (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::EGODISTANCECURVILIGNE")
  (make-package "PROJECT_S_MSGS::EGODISTANCECURVILIGNE"))

(in-package "ROS")
;;//! \htmlinclude EgoDistanceCurviligne.msg.html
(if (not (find-package "NAV_MSGS"))
  (ros::roseus-add-msgs "nav_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::EgoDistanceCurviligne
  :super ros::object
  :slots (_header _id _distance _odom _latitude _longitude _cap ))

(defmethod project_s_msgs::EgoDistanceCurviligne
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:distance __distance) (instance std_msgs::Float32 :init))
    ((:odom __odom) (instance nav_msgs::Odometry :init))
    ((:latitude __latitude) (instance std_msgs::Float32 :init))
    ((:longitude __longitude) (instance std_msgs::Float32 :init))
    ((:cap __cap) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _distance __distance)
   (setq _odom __odom)
   (setq _latitude __latitude)
   (setq _longitude __longitude)
   (setq _cap __cap)
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
  (:distance
   (&rest __distance)
   (if (keywordp (car __distance))
       (send* _distance __distance)
     (progn
       (if __distance (setq _distance (car __distance)))
       _distance)))
  (:odom
   (&rest __odom)
   (if (keywordp (car __odom))
       (send* _odom __odom)
     (progn
       (if __odom (setq _odom (car __odom)))
       _odom)))
  (:latitude
   (&rest __latitude)
   (if (keywordp (car __latitude))
       (send* _latitude __latitude)
     (progn
       (if __latitude (setq _latitude (car __latitude)))
       _latitude)))
  (:longitude
   (&rest __longitude)
   (if (keywordp (car __longitude))
       (send* _longitude __longitude)
     (progn
       (if __longitude (setq _longitude (car __longitude)))
       _longitude)))
  (:cap
   (&rest __cap)
   (if (keywordp (car __cap))
       (send* _cap __cap)
     (progn
       (if __cap (setq _cap (car __cap)))
       _cap)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/Float32 _distance
    (send _distance :serialization-length)
    ;; nav_msgs/Odometry _odom
    (send _odom :serialization-length)
    ;; std_msgs/Float32 _latitude
    (send _latitude :serialization-length)
    ;; std_msgs/Float32 _longitude
    (send _longitude :serialization-length)
    ;; std_msgs/Float32 _cap
    (send _cap :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/Float32 _distance
       (send _distance :serialize s)
     ;; nav_msgs/Odometry _odom
       (send _odom :serialize s)
     ;; std_msgs/Float32 _latitude
       (send _latitude :serialize s)
     ;; std_msgs/Float32 _longitude
       (send _longitude :serialize s)
     ;; std_msgs/Float32 _cap
       (send _cap :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/Float32 _distance
     (send _distance :deserialize buf ptr-) (incf ptr- (send _distance :serialization-length))
   ;; nav_msgs/Odometry _odom
     (send _odom :deserialize buf ptr-) (incf ptr- (send _odom :serialization-length))
   ;; std_msgs/Float32 _latitude
     (send _latitude :deserialize buf ptr-) (incf ptr- (send _latitude :serialization-length))
   ;; std_msgs/Float32 _longitude
     (send _longitude :deserialize buf ptr-) (incf ptr- (send _longitude :serialization-length))
   ;; std_msgs/Float32 _cap
     (send _cap :deserialize buf ptr-) (incf ptr- (send _cap :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::EgoDistanceCurviligne :md5sum-) "2a1fd94cf2ac8a1014987ae82524a7bf")
(setf (get project_s_msgs::EgoDistanceCurviligne :datatype-) "project_s_msgs/EgoDistanceCurviligne")
(setf (get project_s_msgs::EgoDistanceCurviligne :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/Float32 distance
nav_msgs/Odometry odom
std_msgs/Float32 latitude
std_msgs/Float32 longitude
std_msgs/Float32 cap

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
MSG: std_msgs/Float32
float32 data
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
MSG: geometry_msgs/TwistWithCovariance
# This expresses velocity in free space with uncertainty.

Twist twist

# Row-major representation of the 6x6 covariance matrix
# The orientation parameters use a fixed-axis representation.
# In order, the parameters are:
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
float64[36] covariance

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
")



(provide :project_s_msgs/EgoDistanceCurviligne "2a1fd94cf2ac8a1014987ae82524a7bf")


