;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::RoadModel)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'RoadModel (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::ROADMODEL")
  (make-package "PROJECT_S_MSGS::ROADMODEL"))

(in-package "ROS")
;;//! \htmlinclude RoadModel.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "NAV_MSGS"))
  (ros::roseus-add-msgs "nav_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*SPEED_LIMIT_ARRAY_SIZE*" (find-package "PROJECT_S_MSGS::ROADMODEL"))
(shadow '*SPEED_LIMIT_ARRAY_SIZE* (find-package "PROJECT_S_MSGS::ROADMODEL"))
(defconstant project_s_msgs::RoadModel::*SPEED_LIMIT_ARRAY_SIZE* 310)
(intern "*AMER_ARRAY_SIZE*" (find-package "PROJECT_S_MSGS::ROADMODEL"))
(shadow '*AMER_ARRAY_SIZE* (find-package "PROJECT_S_MSGS::ROADMODEL"))
(defconstant project_s_msgs::RoadModel::*AMER_ARRAY_SIZE* 50)
(defclass project_s_msgs::RoadModel
  :super ros::object
  :slots (_header _id _nbrLine _roadLine _electronicHorizon _speedEnveloppe _amer _nbrAmer _odom ))

(defmethod project_s_msgs::RoadModel
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:nbrLine __nbrLine) (instance std_msgs::UInt8 :init))
    ((:roadLine __roadLine) (let (r) (dotimes (i 10) (push (instance project_s_msgs::Line :init) r)) r))
    ((:electronicHorizon __electronicHorizon) (instance project_s_msgs::ElectronicHorizon :init))
    ((:speedEnveloppe __speedEnveloppe) (let (r) (dotimes (i 310) (push (instance project_s_msgs::Speed :init) r)) r))
    ((:amer __amer) (let (r) (dotimes (i 50) (push (instance geometry_msgs::Point :init) r)) r))
    ((:nbrAmer __nbrAmer) (instance std_msgs::UInt8 :init))
    ((:odom __odom) (instance nav_msgs::Odometry :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _nbrLine __nbrLine)
   (setq _roadLine __roadLine)
   (setq _electronicHorizon __electronicHorizon)
   (setq _speedEnveloppe __speedEnveloppe)
   (setq _amer __amer)
   (setq _nbrAmer __nbrAmer)
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
  (:nbrLine
   (&rest __nbrLine)
   (if (keywordp (car __nbrLine))
       (send* _nbrLine __nbrLine)
     (progn
       (if __nbrLine (setq _nbrLine (car __nbrLine)))
       _nbrLine)))
  (:roadLine
   (&rest __roadLine)
   (if (keywordp (car __roadLine))
       (send* _roadLine __roadLine)
     (progn
       (if __roadLine (setq _roadLine (car __roadLine)))
       _roadLine)))
  (:electronicHorizon
   (&rest __electronicHorizon)
   (if (keywordp (car __electronicHorizon))
       (send* _electronicHorizon __electronicHorizon)
     (progn
       (if __electronicHorizon (setq _electronicHorizon (car __electronicHorizon)))
       _electronicHorizon)))
  (:speedEnveloppe
   (&rest __speedEnveloppe)
   (if (keywordp (car __speedEnveloppe))
       (send* _speedEnveloppe __speedEnveloppe)
     (progn
       (if __speedEnveloppe (setq _speedEnveloppe (car __speedEnveloppe)))
       _speedEnveloppe)))
  (:amer
   (&rest __amer)
   (if (keywordp (car __amer))
       (send* _amer __amer)
     (progn
       (if __amer (setq _amer (car __amer)))
       _amer)))
  (:nbrAmer
   (&rest __nbrAmer)
   (if (keywordp (car __nbrAmer))
       (send* _nbrAmer __nbrAmer)
     (progn
       (if __nbrAmer (setq _nbrAmer (car __nbrAmer)))
       _nbrAmer)))
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
    ;; std_msgs/UInt8 _nbrLine
    (send _nbrLine :serialization-length)
    ;; project_s_msgs/Line[10] _roadLine
    (apply #'+ (send-all _roadLine :serialization-length))
    ;; project_s_msgs/ElectronicHorizon _electronicHorizon
    (send _electronicHorizon :serialization-length)
    ;; project_s_msgs/Speed[310] _speedEnveloppe
    (apply #'+ (send-all _speedEnveloppe :serialization-length))
    ;; geometry_msgs/Point[50] _amer
    (apply #'+ (send-all _amer :serialization-length))
    ;; std_msgs/UInt8 _nbrAmer
    (send _nbrAmer :serialization-length)
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
     ;; std_msgs/UInt8 _nbrLine
       (send _nbrLine :serialize s)
     ;; project_s_msgs/Line[10] _roadLine
     (dolist (elem _roadLine)
       (send elem :serialize s)
       )
     ;; project_s_msgs/ElectronicHorizon _electronicHorizon
       (send _electronicHorizon :serialize s)
     ;; project_s_msgs/Speed[310] _speedEnveloppe
     (dolist (elem _speedEnveloppe)
       (send elem :serialize s)
       )
     ;; geometry_msgs/Point[50] _amer
     (dolist (elem _amer)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _nbrAmer
       (send _nbrAmer :serialize s)
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
   ;; std_msgs/UInt8 _nbrLine
     (send _nbrLine :deserialize buf ptr-) (incf ptr- (send _nbrLine :serialization-length))
   ;; project_s_msgs/Line[10] _roadLine
   (dotimes (i 10)
     (send (elt _roadLine i) :deserialize buf ptr-) (incf ptr- (send (elt _roadLine i) :serialization-length))
     )
   ;; project_s_msgs/ElectronicHorizon _electronicHorizon
     (send _electronicHorizon :deserialize buf ptr-) (incf ptr- (send _electronicHorizon :serialization-length))
   ;; project_s_msgs/Speed[310] _speedEnveloppe
   (dotimes (i 310)
     (send (elt _speedEnveloppe i) :deserialize buf ptr-) (incf ptr- (send (elt _speedEnveloppe i) :serialization-length))
     )
   ;; geometry_msgs/Point[50] _amer
   (dotimes (i 50)
     (send (elt _amer i) :deserialize buf ptr-) (incf ptr- (send (elt _amer i) :serialization-length))
     )
   ;; std_msgs/UInt8 _nbrAmer
     (send _nbrAmer :deserialize buf ptr-) (incf ptr- (send _nbrAmer :serialization-length))
   ;; nav_msgs/Odometry _odom
     (send _odom :deserialize buf ptr-) (incf ptr- (send _odom :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::RoadModel :md5sum-) "8e9f6188ebbf41f73c6179086ef32107")
(setf (get project_s_msgs::RoadModel :datatype-) "project_s_msgs/RoadModel")
(setf (get project_s_msgs::RoadModel :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/UInt8 nbrLine
project_s_msgs/Line[10] roadLine			#segments array

project_s_msgs/ElectronicHorizon electronicHorizon

uint32 SPEED_LIMIT_ARRAY_SIZE = 310
project_s_msgs/Speed[310] speedEnveloppe

uint8 AMER_ARRAY_SIZE = 50
geometry_msgs/Point[50] amer
std_msgs/UInt8 nbrAmer


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
MSG: project_s_msgs/ElectronicHorizon
Header header
std_msgs/UInt8 id

std_msgs/UInt8 indexPath

uint8 SEGMENT_REPORT_SIZE = 50
project_s_msgs/ehSegment[50] ehSegment
std_msgs/UInt8 NbrSegment

uint8 STUB_REPORT_SIZE = 10
project_s_msgs/ehStub[10] ehStub
std_msgs/UInt8 NbrStub

uint16 SPOT_CURVATURE_REPORT_SIZE = 300
project_s_msgs/ehSpotCurvature[300] ehSpotCurvature
std_msgs/UInt16 NbrSpotCurvature

uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000
project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight
std_msgs/UInt16 NbrSpotCoordGeoRight
project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft
std_msgs/UInt16 NbrSpotCoordGeoLeft

uint8 LINE_REPORT_SIZE = 10
project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo
std_msgs/UInt8 QtyLineCoordGeo

uint8 ME_RIGHT_LINE = 0
uint8 ME_LEFT_LINE = 1
project_s_msgs/ehME[2] ehME

uint8 NBR_LINE_REPORT_SIZE = 100
project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo
std_msgs/UInt8 QtyNbrLineCoordGeo

uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50
project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign
std_msgs/UInt8 NbrSpotTrafficSign

project_s_msgs/ehPosition ehPosition

uint8 speedLimit_interpolMethod
uint8 curvature_interpolMethod
uint8 STEP = 0
uint8 LINEAR = 1

uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100
project_s_msgs/ehSegmentME[100] ehSegmentAO
std_msgs/UInt8 QtySegmentAO

uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100
project_s_msgs/ehSegmentME[100] ehSegmentEO
std_msgs/UInt8 QtySegmentEO


================================================================================
MSG: project_s_msgs/ehSegment
Header header
std_msgs/UInt8 id

#std_msgs/UInt8 indexPath
std_msgs/Float32 offset
std_msgs/UInt8 functionRoadClass
std_msgs/UInt8 wayForm
std_msgs/UInt8 effectiveSpeedLimit
std_msgs/UInt8 nbLanesDrivingDirection
std_msgs/UInt8 nbLanesOppositeDirection



================================================================================
MSG: project_s_msgs/ehStub
Header header
std_msgs/UInt8 id

#std_msgs/UInt8 indexPath
std_msgs/Float32 offset
std_msgs/UInt8 indexSubPath
std_msgs/Float32 turnAngle
std_msgs/UInt8 functionRoadClass
std_msgs/UInt8 wayForm
std_msgs/UInt8 nbLanesDrivingDirection
std_msgs/UInt8 nbLanesOppositeDirection



================================================================================
MSG: project_s_msgs/ehSpotCurvature
Header header
std_msgs/UInt8 id

#std_msgs/UInt8 indexPath
std_msgs/Float32 offset
std_msgs/Float32 Value_0
std_msgs/Float32 Distance_1
std_msgs/Float32 Value_1



================================================================================
MSG: project_s_msgs/ehSpotCoordGeo
Header header
std_msgs/UInt8 id

std_msgs/Float32 offset
float64 latitude
float64 longitude



================================================================================
MSG: project_s_msgs/ehLineCoordGeo
Header header
std_msgs/UInt8 id

uint32 SPOT_REPORT_SIZE = 3000
project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo
std_msgs/UInt32 NbrSpotCoordGeo


================================================================================
MSG: std_msgs/UInt32
uint32 data
================================================================================
MSG: project_s_msgs/ehME
Header header
std_msgs/UInt8 id

uint32 SPOT_REPORT_SIZE = 2000
project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo
std_msgs/UInt32 NbrSpotCoordGeo

uint32 SEGMENT_ME_REPORT_SIZE = 100
project_s_msgs/ehSegmentME[100] ehSegmentME
std_msgs/UInt32 QtySegment

================================================================================
MSG: project_s_msgs/ehSegmentME
Header header
std_msgs/UInt8 id

std_msgs/UInt32 NbrSpot
std_msgs/Float32 offset_debut
std_msgs/Float32 offset_fin

================================================================================
MSG: project_s_msgs/ehNbrLineCoordGeo
std_msgs/UInt8 Nbr
std_msgs/Float32 offset




================================================================================
MSG: project_s_msgs/ehSpotTrafficSign
Header header
std_msgs/UInt8 id

std_msgs/Float32 offset
uint8 Sign_Type
uint8 Value
uint8 Lane
uint8 Sign_Location
float64 latitude
float64 longitude




================================================================================
MSG: project_s_msgs/ehPosition
Header header
std_msgs/UInt8 id

#std_msgs/UInt8 indexPath
std_msgs/Float32 offset
float64 latitude
float64 longitude
std_msgs/Float32 cap
std_msgs/UInt16 agePosition
std_msgs/Float32 speed
std_msgs/Float32 relativeHeading
std_msgs/UInt8 currentLane



================================================================================
MSG: project_s_msgs/Speed
Header header
std_msgs/UInt8 id

std_msgs/Float32 offset
std_msgs/Float32 speed


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

")



(provide :project_s_msgs/RoadModel "8e9f6188ebbf41f73c6179086ef32107")


