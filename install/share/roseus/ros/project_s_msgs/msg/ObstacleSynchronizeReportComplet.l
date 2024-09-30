;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ObstacleSynchronizeReportComplet)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ObstacleSynchronizeReportComplet (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::OBSTACLESYNCHRONIZEREPORTCOMPLET")
  (make-package "PROJECT_S_MSGS::OBSTACLESYNCHRONIZEREPORTCOMPLET"))

(in-package "ROS")
;;//! \htmlinclude ObstacleSynchronizeReportComplet.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::ObstacleSynchronizeReportComplet
  :super ros::object
  :slots (_header _id _ObstacleSynchronizeReport _ObstacleFusionReport ))

(defmethod project_s_msgs::ObstacleSynchronizeReportComplet
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:ObstacleSynchronizeReport __ObstacleSynchronizeReport) (instance project_s_msgs::ObstacleSynchronizeReport :init))
    ((:ObstacleFusionReport __ObstacleFusionReport) (instance project_s_msgs::ObstacleFusionReport :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _ObstacleSynchronizeReport __ObstacleSynchronizeReport)
   (setq _ObstacleFusionReport __ObstacleFusionReport)
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
  (:ObstacleSynchronizeReport
   (&rest __ObstacleSynchronizeReport)
   (if (keywordp (car __ObstacleSynchronizeReport))
       (send* _ObstacleSynchronizeReport __ObstacleSynchronizeReport)
     (progn
       (if __ObstacleSynchronizeReport (setq _ObstacleSynchronizeReport (car __ObstacleSynchronizeReport)))
       _ObstacleSynchronizeReport)))
  (:ObstacleFusionReport
   (&rest __ObstacleFusionReport)
   (if (keywordp (car __ObstacleFusionReport))
       (send* _ObstacleFusionReport __ObstacleFusionReport)
     (progn
       (if __ObstacleFusionReport (setq _ObstacleFusionReport (car __ObstacleFusionReport)))
       _ObstacleFusionReport)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; project_s_msgs/ObstacleSynchronizeReport _ObstacleSynchronizeReport
    (send _ObstacleSynchronizeReport :serialization-length)
    ;; project_s_msgs/ObstacleFusionReport _ObstacleFusionReport
    (send _ObstacleFusionReport :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; project_s_msgs/ObstacleSynchronizeReport _ObstacleSynchronizeReport
       (send _ObstacleSynchronizeReport :serialize s)
     ;; project_s_msgs/ObstacleFusionReport _ObstacleFusionReport
       (send _ObstacleFusionReport :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; project_s_msgs/ObstacleSynchronizeReport _ObstacleSynchronizeReport
     (send _ObstacleSynchronizeReport :deserialize buf ptr-) (incf ptr- (send _ObstacleSynchronizeReport :serialization-length))
   ;; project_s_msgs/ObstacleFusionReport _ObstacleFusionReport
     (send _ObstacleFusionReport :deserialize buf ptr-) (incf ptr- (send _ObstacleFusionReport :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ObstacleSynchronizeReportComplet :md5sum-) "6e152dddc1d8361d76321cd7de3a60ea")
(setf (get project_s_msgs::ObstacleSynchronizeReportComplet :datatype-) "project_s_msgs/ObstacleSynchronizeReportComplet")
(setf (get project_s_msgs::ObstacleSynchronizeReportComplet :definition-)
      "Header header
std_msgs/UInt8 id

project_s_msgs/ObstacleSynchronizeReport ObstacleSynchronizeReport
project_s_msgs/ObstacleFusionReport      ObstacleFusionReport

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
MSG: project_s_msgs/ObstacleSynchronizeReport
Header header
std_msgs/UInt8 id
nav_msgs/Odometry odom

project_s_msgs/ObstacleAlignmentReport[3] ObstacleSynchronizeReport	# en concordance avec #define NBR_SENSOR de obstacles_fusion/local_tracks_synchro.cpp

# History





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
================================================================================
MSG: project_s_msgs/ObstacleAlignmentReport
Header header
std_msgs/UInt8 id

uint8 OBSTACLE_ALIGNMENT_REPORT_SIZE = 127
project_s_msgs/ObstacleAlignment[127] ObstacleAlignement
std_msgs/UInt8 QtyObstacles
nav_msgs/Odometry odom

# History





================================================================================
MSG: project_s_msgs/ObstacleAlignment
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
                           
uint8 vision_only_sign_type
#uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type
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

uint8 obstacleClass

# History





================================================================================
MSG: std_msgs/UInt16
uint16 data

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
MSG: project_s_msgs/ObstacleFusionReport
Header header
std_msgs/UInt8 id

uint8 OBSTACLE_FUSION_REPORT_SIZE = 127
project_s_msgs/ObstacleFusion[127] ObstacleFusion
std_msgs/UInt8 QtyObstacles
nav_msgs/Odometry odom

# History





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
MSG: std_msgs/Int16
int16 data

")



(provide :project_s_msgs/ObstacleSynchronizeReportComplet "6e152dddc1d8361d76321cd7de3a60ea")


