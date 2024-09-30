;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::FineMapMatching)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'FineMapMatching (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::FINEMAPMATCHING")
  (make-package "PROJECT_S_MSGS::FINEMAPMATCHING"))

(in-package "ROS")
;;//! \htmlinclude FineMapMatching.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::FineMapMatching
  :super ros::object
  :slots (_header _id _dCap _d_x_lambert _d_y_lambert _d_latitude _d_longitude _electronicHorizonArray ))

(defmethod project_s_msgs::FineMapMatching
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:dCap __dCap) (instance std_msgs::Float32 :init))
    ((:d_x_lambert __d_x_lambert) (instance std_msgs::Float32 :init))
    ((:d_y_lambert __d_y_lambert) (instance std_msgs::Float32 :init))
    ((:d_latitude __d_latitude) 0.0)
    ((:d_longitude __d_longitude) 0.0)
    ((:electronicHorizonArray __electronicHorizonArray) (instance project_s_msgs::ElectronicHorizonArray :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _dCap __dCap)
   (setq _d_x_lambert __d_x_lambert)
   (setq _d_y_lambert __d_y_lambert)
   (setq _d_latitude (float __d_latitude))
   (setq _d_longitude (float __d_longitude))
   (setq _electronicHorizonArray __electronicHorizonArray)
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
  (:dCap
   (&rest __dCap)
   (if (keywordp (car __dCap))
       (send* _dCap __dCap)
     (progn
       (if __dCap (setq _dCap (car __dCap)))
       _dCap)))
  (:d_x_lambert
   (&rest __d_x_lambert)
   (if (keywordp (car __d_x_lambert))
       (send* _d_x_lambert __d_x_lambert)
     (progn
       (if __d_x_lambert (setq _d_x_lambert (car __d_x_lambert)))
       _d_x_lambert)))
  (:d_y_lambert
   (&rest __d_y_lambert)
   (if (keywordp (car __d_y_lambert))
       (send* _d_y_lambert __d_y_lambert)
     (progn
       (if __d_y_lambert (setq _d_y_lambert (car __d_y_lambert)))
       _d_y_lambert)))
  (:d_latitude
   (&optional __d_latitude)
   (if __d_latitude (setq _d_latitude __d_latitude)) _d_latitude)
  (:d_longitude
   (&optional __d_longitude)
   (if __d_longitude (setq _d_longitude __d_longitude)) _d_longitude)
  (:electronicHorizonArray
   (&rest __electronicHorizonArray)
   (if (keywordp (car __electronicHorizonArray))
       (send* _electronicHorizonArray __electronicHorizonArray)
     (progn
       (if __electronicHorizonArray (setq _electronicHorizonArray (car __electronicHorizonArray)))
       _electronicHorizonArray)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/Float32 _dCap
    (send _dCap :serialization-length)
    ;; std_msgs/Float32 _d_x_lambert
    (send _d_x_lambert :serialization-length)
    ;; std_msgs/Float32 _d_y_lambert
    (send _d_y_lambert :serialization-length)
    ;; float64 _d_latitude
    8
    ;; float64 _d_longitude
    8
    ;; project_s_msgs/ElectronicHorizonArray _electronicHorizonArray
    (send _electronicHorizonArray :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/Float32 _dCap
       (send _dCap :serialize s)
     ;; std_msgs/Float32 _d_x_lambert
       (send _d_x_lambert :serialize s)
     ;; std_msgs/Float32 _d_y_lambert
       (send _d_y_lambert :serialize s)
     ;; float64 _d_latitude
       (sys::poke _d_latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _d_longitude
       (sys::poke _d_longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; project_s_msgs/ElectronicHorizonArray _electronicHorizonArray
       (send _electronicHorizonArray :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/Float32 _dCap
     (send _dCap :deserialize buf ptr-) (incf ptr- (send _dCap :serialization-length))
   ;; std_msgs/Float32 _d_x_lambert
     (send _d_x_lambert :deserialize buf ptr-) (incf ptr- (send _d_x_lambert :serialization-length))
   ;; std_msgs/Float32 _d_y_lambert
     (send _d_y_lambert :deserialize buf ptr-) (incf ptr- (send _d_y_lambert :serialization-length))
   ;; float64 _d_latitude
     (setq _d_latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _d_longitude
     (setq _d_longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; project_s_msgs/ElectronicHorizonArray _electronicHorizonArray
     (send _electronicHorizonArray :deserialize buf ptr-) (incf ptr- (send _electronicHorizonArray :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::FineMapMatching :md5sum-) "bbc6c31487a0775416bf98fdaad9098b")
(setf (get project_s_msgs::FineMapMatching :datatype-) "project_s_msgs/FineMapMatching")
(setf (get project_s_msgs::FineMapMatching :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/Float32 dCap

std_msgs/Float32 d_x_lambert	# sens sud   -> nord, unité en m
std_msgs/Float32 d_y_lambert	# sens ouest -> est , unité en m

float64 d_latitude	# unité en °
float64 d_longitude	# unité en °

project_s_msgs/ElectronicHorizonArray electronicHorizonArray



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
MSG: project_s_msgs/ElectronicHorizonArray
Header header
std_msgs/UInt8 id

project_s_msgs/ElectronicHorizon[5] PathsArray
std_msgs/UInt8 NbrPath
std_msgs/UInt8 indexMPP

nav_msgs/Odometry odom



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



(provide :project_s_msgs/FineMapMatching "bbc6c31487a0775416bf98fdaad9098b")


