;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::LaneAlignment)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'LaneAlignment (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::LANEALIGNMENT")
  (make-package "PROJECT_S_MSGS::LANEALIGNMENT"))

(in-package "ROS")
;;//! \htmlinclude LaneAlignment.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "NAV_MSGS"))
  (ros::roseus-add-msgs "nav_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*LINE_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::LANEALIGNMENT"))
(shadow '*LINE_REPORT_SIZE* (find-package "PROJECT_S_MSGS::LANEALIGNMENT"))
(defconstant project_s_msgs::LaneAlignment::*LINE_REPORT_SIZE* 20)
(defclass project_s_msgs::LaneAlignment
  :super ros::object
  :slots (_header _id _line _QtyLine _lanePosition _lanePoseVariance _laneClass _classificationProbability _laneQuality _dateAcquisition _odom ))

(defmethod project_s_msgs::LaneAlignment
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:line __line) (let (r) (dotimes (i 20) (push (instance project_s_msgs::Line :init) r)) r))
    ((:QtyLine __QtyLine) (instance std_msgs::UInt8 :init))
    ((:lanePosition __lanePosition) (instance geometry_msgs::Pose :init))
    ((:lanePoseVariance __lanePoseVariance) (instance geometry_msgs::Pose :init))
    ((:laneClass __laneClass) (instance std_msgs::UInt8 :init))
    ((:classificationProbability __classificationProbability) (instance std_msgs::UInt8 :init))
    ((:laneQuality __laneQuality) (instance std_msgs::UInt8 :init))
    ((:dateAcquisition __dateAcquisition) (instance std_msgs::UInt64 :init))
    ((:odom __odom) (instance nav_msgs::Odometry :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _line __line)
   (setq _QtyLine __QtyLine)
   (setq _lanePosition __lanePosition)
   (setq _lanePoseVariance __lanePoseVariance)
   (setq _laneClass __laneClass)
   (setq _classificationProbability __classificationProbability)
   (setq _laneQuality __laneQuality)
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
  (:line
   (&rest __line)
   (if (keywordp (car __line))
       (send* _line __line)
     (progn
       (if __line (setq _line (car __line)))
       _line)))
  (:QtyLine
   (&rest __QtyLine)
   (if (keywordp (car __QtyLine))
       (send* _QtyLine __QtyLine)
     (progn
       (if __QtyLine (setq _QtyLine (car __QtyLine)))
       _QtyLine)))
  (:lanePosition
   (&rest __lanePosition)
   (if (keywordp (car __lanePosition))
       (send* _lanePosition __lanePosition)
     (progn
       (if __lanePosition (setq _lanePosition (car __lanePosition)))
       _lanePosition)))
  (:lanePoseVariance
   (&rest __lanePoseVariance)
   (if (keywordp (car __lanePoseVariance))
       (send* _lanePoseVariance __lanePoseVariance)
     (progn
       (if __lanePoseVariance (setq _lanePoseVariance (car __lanePoseVariance)))
       _lanePoseVariance)))
  (:laneClass
   (&rest __laneClass)
   (if (keywordp (car __laneClass))
       (send* _laneClass __laneClass)
     (progn
       (if __laneClass (setq _laneClass (car __laneClass)))
       _laneClass)))
  (:classificationProbability
   (&rest __classificationProbability)
   (if (keywordp (car __classificationProbability))
       (send* _classificationProbability __classificationProbability)
     (progn
       (if __classificationProbability (setq _classificationProbability (car __classificationProbability)))
       _classificationProbability)))
  (:laneQuality
   (&rest __laneQuality)
   (if (keywordp (car __laneQuality))
       (send* _laneQuality __laneQuality)
     (progn
       (if __laneQuality (setq _laneQuality (car __laneQuality)))
       _laneQuality)))
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
    ;; project_s_msgs/Line[20] _line
    (apply #'+ (send-all _line :serialization-length))
    ;; std_msgs/UInt8 _QtyLine
    (send _QtyLine :serialization-length)
    ;; geometry_msgs/Pose _lanePosition
    (send _lanePosition :serialization-length)
    ;; geometry_msgs/Pose _lanePoseVariance
    (send _lanePoseVariance :serialization-length)
    ;; std_msgs/UInt8 _laneClass
    (send _laneClass :serialization-length)
    ;; std_msgs/UInt8 _classificationProbability
    (send _classificationProbability :serialization-length)
    ;; std_msgs/UInt8 _laneQuality
    (send _laneQuality :serialization-length)
    ;; std_msgs/UInt64 _dateAcquisition
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
     ;; project_s_msgs/Line[20] _line
     (dolist (elem _line)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _QtyLine
       (send _QtyLine :serialize s)
     ;; geometry_msgs/Pose _lanePosition
       (send _lanePosition :serialize s)
     ;; geometry_msgs/Pose _lanePoseVariance
       (send _lanePoseVariance :serialize s)
     ;; std_msgs/UInt8 _laneClass
       (send _laneClass :serialize s)
     ;; std_msgs/UInt8 _classificationProbability
       (send _classificationProbability :serialize s)
     ;; std_msgs/UInt8 _laneQuality
       (send _laneQuality :serialize s)
     ;; std_msgs/UInt64 _dateAcquisition
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
   ;; project_s_msgs/Line[20] _line
   (dotimes (i 20)
     (send (elt _line i) :deserialize buf ptr-) (incf ptr- (send (elt _line i) :serialization-length))
     )
   ;; std_msgs/UInt8 _QtyLine
     (send _QtyLine :deserialize buf ptr-) (incf ptr- (send _QtyLine :serialization-length))
   ;; geometry_msgs/Pose _lanePosition
     (send _lanePosition :deserialize buf ptr-) (incf ptr- (send _lanePosition :serialization-length))
   ;; geometry_msgs/Pose _lanePoseVariance
     (send _lanePoseVariance :deserialize buf ptr-) (incf ptr- (send _lanePoseVariance :serialization-length))
   ;; std_msgs/UInt8 _laneClass
     (send _laneClass :deserialize buf ptr-) (incf ptr- (send _laneClass :serialization-length))
   ;; std_msgs/UInt8 _classificationProbability
     (send _classificationProbability :deserialize buf ptr-) (incf ptr- (send _classificationProbability :serialization-length))
   ;; std_msgs/UInt8 _laneQuality
     (send _laneQuality :deserialize buf ptr-) (incf ptr- (send _laneQuality :serialization-length))
   ;; std_msgs/UInt64 _dateAcquisition
     (send _dateAcquisition :deserialize buf ptr-) (incf ptr- (send _dateAcquisition :serialization-length))
   ;; nav_msgs/Odometry _odom
     (send _odom :deserialize buf ptr-) (incf ptr- (send _odom :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::LaneAlignment :md5sum-) "0ce9eca73df9d44131a505be2c05a4ea")
(setf (get project_s_msgs::LaneAlignment :datatype-) "project_s_msgs/LaneAlignment")
(setf (get project_s_msgs::LaneAlignment :definition-)
      "Header header
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

")



(provide :project_s_msgs/LaneAlignment "0ce9eca73df9d44131a505be2c05a4ea")


