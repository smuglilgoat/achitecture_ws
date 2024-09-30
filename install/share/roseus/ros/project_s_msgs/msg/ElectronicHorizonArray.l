;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ElectronicHorizonArray)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ElectronicHorizonArray (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::ELECTRONICHORIZONARRAY")
  (make-package "PROJECT_S_MSGS::ELECTRONICHORIZONARRAY"))

(in-package "ROS")
;;//! \htmlinclude ElectronicHorizonArray.msg.html
(if (not (find-package "NAV_MSGS"))
  (ros::roseus-add-msgs "nav_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::ElectronicHorizonArray
  :super ros::object
  :slots (_header _id _PathsArray _NbrPath _indexMPP _odom ))

(defmethod project_s_msgs::ElectronicHorizonArray
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:PathsArray __PathsArray) (let (r) (dotimes (i 5) (push (instance project_s_msgs::ElectronicHorizon :init) r)) r))
    ((:NbrPath __NbrPath) (instance std_msgs::UInt8 :init))
    ((:indexMPP __indexMPP) (instance std_msgs::UInt8 :init))
    ((:odom __odom) (instance nav_msgs::Odometry :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _PathsArray __PathsArray)
   (setq _NbrPath __NbrPath)
   (setq _indexMPP __indexMPP)
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
  (:PathsArray
   (&rest __PathsArray)
   (if (keywordp (car __PathsArray))
       (send* _PathsArray __PathsArray)
     (progn
       (if __PathsArray (setq _PathsArray (car __PathsArray)))
       _PathsArray)))
  (:NbrPath
   (&rest __NbrPath)
   (if (keywordp (car __NbrPath))
       (send* _NbrPath __NbrPath)
     (progn
       (if __NbrPath (setq _NbrPath (car __NbrPath)))
       _NbrPath)))
  (:indexMPP
   (&rest __indexMPP)
   (if (keywordp (car __indexMPP))
       (send* _indexMPP __indexMPP)
     (progn
       (if __indexMPP (setq _indexMPP (car __indexMPP)))
       _indexMPP)))
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
    ;; project_s_msgs/ElectronicHorizon[5] _PathsArray
    (apply #'+ (send-all _PathsArray :serialization-length))
    ;; std_msgs/UInt8 _NbrPath
    (send _NbrPath :serialization-length)
    ;; std_msgs/UInt8 _indexMPP
    (send _indexMPP :serialization-length)
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
     ;; project_s_msgs/ElectronicHorizon[5] _PathsArray
     (dolist (elem _PathsArray)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _NbrPath
       (send _NbrPath :serialize s)
     ;; std_msgs/UInt8 _indexMPP
       (send _indexMPP :serialize s)
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
   ;; project_s_msgs/ElectronicHorizon[5] _PathsArray
   (dotimes (i 5)
     (send (elt _PathsArray i) :deserialize buf ptr-) (incf ptr- (send (elt _PathsArray i) :serialization-length))
     )
   ;; std_msgs/UInt8 _NbrPath
     (send _NbrPath :deserialize buf ptr-) (incf ptr- (send _NbrPath :serialization-length))
   ;; std_msgs/UInt8 _indexMPP
     (send _indexMPP :deserialize buf ptr-) (incf ptr- (send _indexMPP :serialization-length))
   ;; nav_msgs/Odometry _odom
     (send _odom :deserialize buf ptr-) (incf ptr- (send _odom :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ElectronicHorizonArray :md5sum-) "1944698f685c5272c5b7372763d0c8f3")
(setf (get project_s_msgs::ElectronicHorizonArray :datatype-) "project_s_msgs/ElectronicHorizonArray")
(setf (get project_s_msgs::ElectronicHorizonArray :definition-)
      "Header header
std_msgs/UInt8 id

project_s_msgs/ElectronicHorizon[5] PathsArray
std_msgs/UInt8 NbrPath
std_msgs/UInt8 indexMPP

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
MSG: std_msgs/Float32
float32 data
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
MSG: std_msgs/UInt16
uint16 data

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



(provide :project_s_msgs/ElectronicHorizonArray "1944698f685c5272c5b7372763d0c8f3")


