;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ObstacleFusionReport)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ObstacleFusionReport (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::OBSTACLEFUSIONREPORT")
  (make-package "PROJECT_S_MSGS::OBSTACLEFUSIONREPORT"))

(in-package "ROS")
;;//! \htmlinclude ObstacleFusionReport.msg.html
(if (not (find-package "NAV_MSGS"))
  (ros::roseus-add-msgs "nav_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*OBSTACLE_FUSION_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::OBSTACLEFUSIONREPORT"))
(shadow '*OBSTACLE_FUSION_REPORT_SIZE* (find-package "PROJECT_S_MSGS::OBSTACLEFUSIONREPORT"))
(defconstant project_s_msgs::ObstacleFusionReport::*OBSTACLE_FUSION_REPORT_SIZE* 127)
(defclass project_s_msgs::ObstacleFusionReport
  :super ros::object
  :slots (_header _id _ObstacleFusion _QtyObstacles _odom ))

(defmethod project_s_msgs::ObstacleFusionReport
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:ObstacleFusion __ObstacleFusion) (let (r) (dotimes (i 127) (push (instance project_s_msgs::ObstacleFusion :init) r)) r))
    ((:QtyObstacles __QtyObstacles) (instance std_msgs::UInt8 :init))
    ((:odom __odom) (instance nav_msgs::Odometry :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _ObstacleFusion __ObstacleFusion)
   (setq _QtyObstacles __QtyObstacles)
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
  (:ObstacleFusion
   (&rest __ObstacleFusion)
   (if (keywordp (car __ObstacleFusion))
       (send* _ObstacleFusion __ObstacleFusion)
     (progn
       (if __ObstacleFusion (setq _ObstacleFusion (car __ObstacleFusion)))
       _ObstacleFusion)))
  (:QtyObstacles
   (&rest __QtyObstacles)
   (if (keywordp (car __QtyObstacles))
       (send* _QtyObstacles __QtyObstacles)
     (progn
       (if __QtyObstacles (setq _QtyObstacles (car __QtyObstacles)))
       _QtyObstacles)))
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
    ;; project_s_msgs/ObstacleFusion[127] _ObstacleFusion
    (apply #'+ (send-all _ObstacleFusion :serialization-length))
    ;; std_msgs/UInt8 _QtyObstacles
    (send _QtyObstacles :serialization-length)
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
     ;; project_s_msgs/ObstacleFusion[127] _ObstacleFusion
     (dolist (elem _ObstacleFusion)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _QtyObstacles
       (send _QtyObstacles :serialize s)
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
   ;; project_s_msgs/ObstacleFusion[127] _ObstacleFusion
   (dotimes (i 127)
     (send (elt _ObstacleFusion i) :deserialize buf ptr-) (incf ptr- (send (elt _ObstacleFusion i) :serialization-length))
     )
   ;; std_msgs/UInt8 _QtyObstacles
     (send _QtyObstacles :deserialize buf ptr-) (incf ptr- (send _QtyObstacles :serialization-length))
   ;; nav_msgs/Odometry _odom
     (send _odom :deserialize buf ptr-) (incf ptr- (send _odom :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ObstacleFusionReport :md5sum-) "699d031838fdda967f55404a6c4b9748")
(setf (get project_s_msgs::ObstacleFusionReport :datatype-) "project_s_msgs/ObstacleFusionReport")
(setf (get project_s_msgs::ObstacleFusionReport :definition-)
      "Header header
std_msgs/UInt8 id

uint8 OBSTACLE_FUSION_REPORT_SIZE = 127
project_s_msgs/ObstacleFusion[127] ObstacleFusion
std_msgs/UInt8 QtyObstacles
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
MSG: project_s_msgs/ObstacleFusion
Header header
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



(provide :project_s_msgs/ObstacleFusionReport "699d031838fdda967f55404a6c4b9748")


