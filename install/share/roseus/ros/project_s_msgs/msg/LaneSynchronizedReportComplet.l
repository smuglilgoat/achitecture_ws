;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::LaneSynchronizedReportComplet)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'LaneSynchronizedReportComplet (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::LANESYNCHRONIZEDREPORTCOMPLET")
  (make-package "PROJECT_S_MSGS::LANESYNCHRONIZEDREPORTCOMPLET"))

(in-package "ROS")
;;//! \htmlinclude LaneSynchronizedReportComplet.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::LaneSynchronizedReportComplet
  :super ros::object
  :slots (_header _laneAlignement _laneFusion _linesUpdate ))

(defmethod project_s_msgs::LaneSynchronizedReportComplet
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:laneAlignement __laneAlignement) (instance project_s_msgs::LaneAlignment :init))
    ((:laneFusion __laneFusion) (instance project_s_msgs::LaneFusion :init))
    ((:linesUpdate __linesUpdate) (instance project_s_msgs::LaneFusion :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _laneAlignement __laneAlignement)
   (setq _laneFusion __laneFusion)
   (setq _linesUpdate __linesUpdate)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:laneAlignement
   (&rest __laneAlignement)
   (if (keywordp (car __laneAlignement))
       (send* _laneAlignement __laneAlignement)
     (progn
       (if __laneAlignement (setq _laneAlignement (car __laneAlignement)))
       _laneAlignement)))
  (:laneFusion
   (&rest __laneFusion)
   (if (keywordp (car __laneFusion))
       (send* _laneFusion __laneFusion)
     (progn
       (if __laneFusion (setq _laneFusion (car __laneFusion)))
       _laneFusion)))
  (:linesUpdate
   (&rest __linesUpdate)
   (if (keywordp (car __linesUpdate))
       (send* _linesUpdate __linesUpdate)
     (progn
       (if __linesUpdate (setq _linesUpdate (car __linesUpdate)))
       _linesUpdate)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; project_s_msgs/LaneAlignment _laneAlignement
    (send _laneAlignement :serialization-length)
    ;; project_s_msgs/LaneFusion _laneFusion
    (send _laneFusion :serialization-length)
    ;; project_s_msgs/LaneFusion _linesUpdate
    (send _linesUpdate :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; project_s_msgs/LaneAlignment _laneAlignement
       (send _laneAlignement :serialize s)
     ;; project_s_msgs/LaneFusion _laneFusion
       (send _laneFusion :serialize s)
     ;; project_s_msgs/LaneFusion _linesUpdate
       (send _linesUpdate :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; project_s_msgs/LaneAlignment _laneAlignement
     (send _laneAlignement :deserialize buf ptr-) (incf ptr- (send _laneAlignement :serialization-length))
   ;; project_s_msgs/LaneFusion _laneFusion
     (send _laneFusion :deserialize buf ptr-) (incf ptr- (send _laneFusion :serialization-length))
   ;; project_s_msgs/LaneFusion _linesUpdate
     (send _linesUpdate :deserialize buf ptr-) (incf ptr- (send _linesUpdate :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::LaneSynchronizedReportComplet :md5sum-) "a30a0de87e442c4f5b3745db24215372")
(setf (get project_s_msgs::LaneSynchronizedReportComplet :datatype-) "project_s_msgs/LaneSynchronizedReportComplet")
(setf (get project_s_msgs::LaneSynchronizedReportComplet :definition-)
      "Header header

project_s_msgs/LaneAlignment laneAlignement 
project_s_msgs/LaneFusion laneFusion
project_s_msgs/LaneFusion linesUpdate

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
MSG: project_s_msgs/LaneAlignment
Header header
std_msgs/UInt8 id

#geometry_msgs/Point[250] points

uint8 LINE_REPORT_SIZE = 20
project_s_msgs/Line[20] line
std_msgs/UInt8 QtyLine

geometry_msgs/Pose lanePosition
geometry_msgs/Pose lanePoseVariance
std_msgs/UInt8 laneClass
std_msgs/UInt8 classificationProbability
std_msgs/UInt8 laneQuality
std_msgs/UInt64 dateAcquisition
nav_msgs/Odometry odom

# History





================================================================================
MSG: std_msgs/UInt8
uint8 data

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
MSG: std_msgs/Float32
float32 data
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

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
MSG: std_msgs/UInt16
uint16 data

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: std_msgs/UInt64
uint64 data
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

================================================================================
MSG: project_s_msgs/LaneFusion
Header header
std_msgs/UInt8 id

#geometry_msgs/Point[250] points

#uint8 LINE_REPORT_SIZE = 20
project_s_msgs/Line[20] line
std_msgs/UInt8 QtyLine

geometry_msgs/Pose lanePosition
geometry_msgs/Pose lanePoseVariance
std_msgs/UInt8 laneClass
std_msgs/UInt8 classificationProbability
std_msgs/UInt8 laneQuality
std_msgs/UInt8 roadBorder
std_msgs/UInt64 dateFusion
nav_msgs/Odometry odom

# History





")



(provide :project_s_msgs/LaneSynchronizedReportComplet "a30a0de87e442c4f5b3745db24215372")


