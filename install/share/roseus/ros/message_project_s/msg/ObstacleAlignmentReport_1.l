;; Auto-generated. Do not edit!


(when (boundp 'message_project_s::ObstacleAlignmentReport_1)
  (if (not (find-package "MESSAGE_PROJECT_S"))
    (make-package "MESSAGE_PROJECT_S"))
  (shadow 'ObstacleAlignmentReport_1 (find-package "MESSAGE_PROJECT_S")))
(unless (find-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENTREPORT_1")
  (make-package "MESSAGE_PROJECT_S::OBSTACLEALIGNMENTREPORT_1"))

(in-package "ROS")
;;//! \htmlinclude ObstacleAlignmentReport_1.msg.html
(if (not (find-package "NAV_MSGS"))
  (ros::roseus-add-msgs "nav_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass message_project_s::ObstacleAlignmentReport_1
  :super ros::object
  :slots (_header _id _ObstacleAlignement_1 _QtyObstacles _odom ))

(defmethod message_project_s::ObstacleAlignmentReport_1
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:ObstacleAlignement_1 __ObstacleAlignement_1) (let (r) (dotimes (i 0) (push (instance message_project_s::ObstacleAlignment_1 :init) r)) r))
    ((:QtyObstacles __QtyObstacles) (instance std_msgs::UInt8 :init))
    ((:odom __odom) (instance nav_msgs::Odometry :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _ObstacleAlignement_1 __ObstacleAlignement_1)
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
  (:ObstacleAlignement_1
   (&rest __ObstacleAlignement_1)
   (if (keywordp (car __ObstacleAlignement_1))
       (send* _ObstacleAlignement_1 __ObstacleAlignement_1)
     (progn
       (if __ObstacleAlignement_1 (setq _ObstacleAlignement_1 (car __ObstacleAlignement_1)))
       _ObstacleAlignement_1)))
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
    ;; message_project_s/ObstacleAlignment_1[] _ObstacleAlignement_1
    (apply #'+ (send-all _ObstacleAlignement_1 :serialization-length)) 4
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
     ;; message_project_s/ObstacleAlignment_1[] _ObstacleAlignement_1
     (write-long (length _ObstacleAlignement_1) s)
     (dolist (elem _ObstacleAlignement_1)
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
   ;; message_project_s/ObstacleAlignment_1[] _ObstacleAlignement_1
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _ObstacleAlignement_1 (let (r) (dotimes (i n) (push (instance message_project_s::ObstacleAlignment_1 :init) r)) r))
     (dolist (elem- _ObstacleAlignement_1)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; std_msgs/UInt8 _QtyObstacles
     (send _QtyObstacles :deserialize buf ptr-) (incf ptr- (send _QtyObstacles :serialization-length))
   ;; nav_msgs/Odometry _odom
     (send _odom :deserialize buf ptr-) (incf ptr- (send _odom :serialization-length))
   ;;
   self)
  )

(setf (get message_project_s::ObstacleAlignmentReport_1 :md5sum-) "4857983c7466f8b6a84b30dd769dde24")
(setf (get message_project_s::ObstacleAlignmentReport_1 :datatype-) "message_project_s/ObstacleAlignmentReport_1")
(setf (get message_project_s::ObstacleAlignmentReport_1 :definition-)
      "Header header
std_msgs/UInt8 id

message_project_s/ObstacleAlignment_1[] ObstacleAlignement_1

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
MSG: message_project_s/ObstacleAlignment_1
Header header
std_msgs/UInt16 id

geometry_msgs/Pose obstaclePosition	        		# obstacle position
float64 obstaclePosition_linear_Unknown = 999
float64 obstaclePosition_orientation_Unknown = 999

geometry_msgs/Pose obstacleBodyCenter	        		# Obstacle Center for Corner Computation

geometry_msgs/Twist obstacleVelocity	                    	# obstacle speed
float64 obstacleVelocity_linear_Unknown = 999
float64 obstacleVelocity_angular_Unknown = 999

geometry_msgs/Twist obstacleRelativeVelocity	           	# obstacle relative velocity
float64 obstacleRelativeVelocity_linear_Unknown = 999
float64 obstacleRelativeVelocity_angular_Unknown = 999

geometry_msgs/Accel obstacleAcceleration        		# obstacle acceleration
float64 obstacleAcceleration_linear_Unknown = 999
float64 obstacleAcceleration_angular_Unknown = 999

geometry_msgs/Vector3 obstacleDimensions        		# obstacle - length and width
float64 obstacleDimensions_Unknown = 999

uint8 blinkerInfo                               		# blinker status (eg. left blinker on)
uint8 blinkerInfo_Unknown=0

uint8 cutInAndOut                               		# Vehicle cutting in or out of ego lane 
uint8 cutInAndOut_Unknown=0

uint8 obstacleType                             			# obstacle classification
uint8 obstacleType_Unknown=7

uint8 obstacleStatus                            		# obstacle’s moving status
uint8 obstacleStatus_Unknown=0

bool obstacleBrakeLights                        		# obstacle brake light on or off
bool obstacleBrakeLights_Unknown=0 

int8 cipvFlag                                   		# If obstacle Closest in Path Vehicle
int8 cipvFlag_Unknown=2

int8 obstacleReplaced                           		# If obstacle replaced in this frame
int8 obstacleReplaced_Unknown=2

uint8 obstacleValid                             		# obstacle valid
uint8 obstacleValid_Unknown=3

uint16 obstacleAge                              		# obstacle age in number of frames
uint16 obstacleAge_Unknown=256

uint8 obstacleLane                              		# obstacle's lane (eg. ego lane or next lane)
uint8 obstacleLane_Unknown=0

float32 obstacleAngle                           		# angle to center of obstacle in degrees
float32 obstacleAngle_Unknown = 999

float32 obstacleAngleVariance                   		# Obstacle angle Variance (Lidar)
float32 obstacleAngleVariance_Unknown=-1

float32 obstacleAngleRate                       		# angle rate of the center of obstacle (degrees/sec)
float32 obstacleAngleRate_Unknown = 999

float64 obstacleScaleChange                     		# scale change from previous frame   
float64 obstacleScaleChange_Unknown = 999
                           
uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type
uint8 visionOnlySignType_Unknown=254

uint8 visionOnlySupplementarySignType               		# Supplementary sign type - rain, snow, arrow etc. 
uint8 visionOnlySupplementarySignType_Unknown=0

geometry_msgs/Vector3 signPosition                  		# X-Longitudnal position, Y-Lateral position ,Z-Height of sign relative to ME
float64 signPosition_Unknown = 999

float64 filterType                                    		# filtering 
float64 filterType_Unknown = 999

geometry_msgs/Pose obstaclePoseVariance		                # obstacle position variance
float64 obstaclePoseVariance_position_Unknown = -1
float64 obstaclePoseVariance_orientation_Unknown = -1

geometry_msgs/Twist obstacleVelocityVariance	                # obstacle speed variance
float64 obstacleVelocityVariance_linear_Unknown = -1
float64 obstacleVelocityVariance_angular_Unknown = -1

geometry_msgs/Twist obstacleRelativeVelocityVariance	        # obstacle relative velocity variance
float64 obstacleRelativeVelocityVariance_linear_Unknown = -1
float64 obstacleRelativeVelocityVariance_angular_Unknown = -1

std_msgs/Float32 groundHeight			                # ground height
float64 groundHeight_Unknown = 999

float64 classificationProbability
float64 classificationProbability_Unknown = 999

std_msgs/Float64 dateAcquisition
float64 dateAcquisition_Unknown = 999


# History

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
MSG: std_msgs/Float32
float32 data
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



(provide :message_project_s/ObstacleAlignmentReport_1 "4857983c7466f8b6a84b30dd769dde24")


