;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::Trajectory)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'Trajectory (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::TRAJECTORY")
  (make-package "PROJECT_S_MSGS::TRAJECTORY"))

(in-package "ROS")
;;//! \htmlinclude Trajectory.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "NAV_MSGS"))
  (ros::roseus-add-msgs "nav_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::Trajectory
  :super ros::object
  :slots (_header _id _setpointPosition _setpointVelocity _targetLength _targetSpeed _trajectoryLine _odom ))

(defmethod project_s_msgs::Trajectory
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:setpointPosition __setpointPosition) (instance geometry_msgs::Pose :init))
    ((:setpointVelocity __setpointVelocity) (instance geometry_msgs::Twist :init))
    ((:targetLength __targetLength) (instance std_msgs::Float32 :init))
    ((:targetSpeed __targetSpeed) (instance std_msgs::Float32 :init))
    ((:trajectoryLine __trajectoryLine) (instance project_s_msgs::Line :init))
    ((:odom __odom) (instance nav_msgs::Odometry :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _setpointPosition __setpointPosition)
   (setq _setpointVelocity __setpointVelocity)
   (setq _targetLength __targetLength)
   (setq _targetSpeed __targetSpeed)
   (setq _trajectoryLine __trajectoryLine)
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
  (:setpointPosition
   (&rest __setpointPosition)
   (if (keywordp (car __setpointPosition))
       (send* _setpointPosition __setpointPosition)
     (progn
       (if __setpointPosition (setq _setpointPosition (car __setpointPosition)))
       _setpointPosition)))
  (:setpointVelocity
   (&rest __setpointVelocity)
   (if (keywordp (car __setpointVelocity))
       (send* _setpointVelocity __setpointVelocity)
     (progn
       (if __setpointVelocity (setq _setpointVelocity (car __setpointVelocity)))
       _setpointVelocity)))
  (:targetLength
   (&rest __targetLength)
   (if (keywordp (car __targetLength))
       (send* _targetLength __targetLength)
     (progn
       (if __targetLength (setq _targetLength (car __targetLength)))
       _targetLength)))
  (:targetSpeed
   (&rest __targetSpeed)
   (if (keywordp (car __targetSpeed))
       (send* _targetSpeed __targetSpeed)
     (progn
       (if __targetSpeed (setq _targetSpeed (car __targetSpeed)))
       _targetSpeed)))
  (:trajectoryLine
   (&rest __trajectoryLine)
   (if (keywordp (car __trajectoryLine))
       (send* _trajectoryLine __trajectoryLine)
     (progn
       (if __trajectoryLine (setq _trajectoryLine (car __trajectoryLine)))
       _trajectoryLine)))
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
    ;; geometry_msgs/Pose _setpointPosition
    (send _setpointPosition :serialization-length)
    ;; geometry_msgs/Twist _setpointVelocity
    (send _setpointVelocity :serialization-length)
    ;; std_msgs/Float32 _targetLength
    (send _targetLength :serialization-length)
    ;; std_msgs/Float32 _targetSpeed
    (send _targetSpeed :serialization-length)
    ;; project_s_msgs/Line _trajectoryLine
    (send _trajectoryLine :serialization-length)
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
     ;; geometry_msgs/Pose _setpointPosition
       (send _setpointPosition :serialize s)
     ;; geometry_msgs/Twist _setpointVelocity
       (send _setpointVelocity :serialize s)
     ;; std_msgs/Float32 _targetLength
       (send _targetLength :serialize s)
     ;; std_msgs/Float32 _targetSpeed
       (send _targetSpeed :serialize s)
     ;; project_s_msgs/Line _trajectoryLine
       (send _trajectoryLine :serialize s)
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
   ;; geometry_msgs/Pose _setpointPosition
     (send _setpointPosition :deserialize buf ptr-) (incf ptr- (send _setpointPosition :serialization-length))
   ;; geometry_msgs/Twist _setpointVelocity
     (send _setpointVelocity :deserialize buf ptr-) (incf ptr- (send _setpointVelocity :serialization-length))
   ;; std_msgs/Float32 _targetLength
     (send _targetLength :deserialize buf ptr-) (incf ptr- (send _targetLength :serialization-length))
   ;; std_msgs/Float32 _targetSpeed
     (send _targetSpeed :deserialize buf ptr-) (incf ptr- (send _targetSpeed :serialization-length))
   ;; project_s_msgs/Line _trajectoryLine
     (send _trajectoryLine :deserialize buf ptr-) (incf ptr- (send _trajectoryLine :serialization-length))
   ;; nav_msgs/Odometry _odom
     (send _odom :deserialize buf ptr-) (incf ptr- (send _odom :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::Trajectory :md5sum-) "1841594a837a63ee15ae7b9c6f1d2f4c")
(setf (get project_s_msgs::Trajectory :datatype-) "project_s_msgs/Trajectory")
(setf (get project_s_msgs::Trajectory :definition-)
      "Header header
std_msgs/UInt8 id

geometry_msgs/Pose setpointPosition		# setpoint position
geometry_msgs/Twist setpointVelocity		# setpoint speed
std_msgs/Float32 targetLength
std_msgs/Float32 targetSpeed

project_s_msgs/Line trajectoryLine			#segments array
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
MSG: std_msgs/Float32
float32 data
================================================================================
MSG: project_s_msgs/Line
Header header
std_msgs/UInt8 id

uint16 SEGMENT_REPORT_SIZE = 3000
project_s_msgs/Segment[3000] segment
std_msgs/UInt16 QtySegment
std_msgs/Float32 lineClass	# class of the line
std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)

std_msgs/UInt8 existenceState
std_msgs/Float32 scoreDetection
std_msgs/Float32 nbrDetection
std_msgs/Float32 nbrVisibility
std_msgs/Float32 scorePersistence
std_msgs/Float32 nbrUpdate
std_msgs/Float32 nbrAge



================================================================================
MSG: project_s_msgs/Segment
std_msgs/Float32 length		# length of the segment
std_msgs/Float32 angle		# angle of the segment
geometry_msgs/Point position
geometry_msgs/Twist Velocity

float32 offset
float64 latitude
float64 longitude


================================================================================
MSG: std_msgs/UInt16
uint16 data

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



(provide :project_s_msgs/Trajectory "1841594a837a63ee15ae7b9c6f1d2f4c")


