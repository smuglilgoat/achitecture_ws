;; Auto-generated. Do not edit!


(when (boundp 'message_project_s::sync)
  (if (not (find-package "MESSAGE_PROJECT_S"))
    (make-package "MESSAGE_PROJECT_S"))
  (shadow 'sync (find-package "MESSAGE_PROJECT_S")))
(unless (find-package "MESSAGE_PROJECT_S::SYNC")
  (make-package "MESSAGE_PROJECT_S::SYNC"))

(in-package "ROS")
;;//! \htmlinclude sync.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass message_project_s::sync
  :super ros::object
  :slots (_header _id _obstaclePosition _obstacleVelocity _obstacleAcceleration _trkID _trkLatrate _trkAngle _trkRange _trkWidth _trkRangeaccel _trkRangerate ))

(defmethod message_project_s::sync
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:obstaclePosition __obstaclePosition) (instance geometry_msgs::Pose :init))
    ((:obstacleVelocity __obstacleVelocity) (instance geometry_msgs::Twist :init))
    ((:obstacleAcceleration __obstacleAcceleration) (instance geometry_msgs::Accel :init))
    ((:trkID __trkID) 0)
    ((:trkLatrate __trkLatrate) 0.0)
    ((:trkAngle __trkAngle) 0.0)
    ((:trkRange __trkRange) 0.0)
    ((:trkWidth __trkWidth) 0.0)
    ((:trkRangeaccel __trkRangeaccel) 0.0)
    ((:trkRangerate __trkRangerate) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _obstaclePosition __obstaclePosition)
   (setq _obstacleVelocity __obstacleVelocity)
   (setq _obstacleAcceleration __obstacleAcceleration)
   (setq _trkID (round __trkID))
   (setq _trkLatrate (float __trkLatrate))
   (setq _trkAngle (float __trkAngle))
   (setq _trkRange (float __trkRange))
   (setq _trkWidth (float __trkWidth))
   (setq _trkRangeaccel (float __trkRangeaccel))
   (setq _trkRangerate (float __trkRangerate))
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
  (:obstaclePosition
   (&rest __obstaclePosition)
   (if (keywordp (car __obstaclePosition))
       (send* _obstaclePosition __obstaclePosition)
     (progn
       (if __obstaclePosition (setq _obstaclePosition (car __obstaclePosition)))
       _obstaclePosition)))
  (:obstacleVelocity
   (&rest __obstacleVelocity)
   (if (keywordp (car __obstacleVelocity))
       (send* _obstacleVelocity __obstacleVelocity)
     (progn
       (if __obstacleVelocity (setq _obstacleVelocity (car __obstacleVelocity)))
       _obstacleVelocity)))
  (:obstacleAcceleration
   (&rest __obstacleAcceleration)
   (if (keywordp (car __obstacleAcceleration))
       (send* _obstacleAcceleration __obstacleAcceleration)
     (progn
       (if __obstacleAcceleration (setq _obstacleAcceleration (car __obstacleAcceleration)))
       _obstacleAcceleration)))
  (:trkID
   (&optional __trkID)
   (if __trkID (setq _trkID __trkID)) _trkID)
  (:trkLatrate
   (&optional __trkLatrate)
   (if __trkLatrate (setq _trkLatrate __trkLatrate)) _trkLatrate)
  (:trkAngle
   (&optional __trkAngle)
   (if __trkAngle (setq _trkAngle __trkAngle)) _trkAngle)
  (:trkRange
   (&optional __trkRange)
   (if __trkRange (setq _trkRange __trkRange)) _trkRange)
  (:trkWidth
   (&optional __trkWidth)
   (if __trkWidth (setq _trkWidth __trkWidth)) _trkWidth)
  (:trkRangeaccel
   (&optional __trkRangeaccel)
   (if __trkRangeaccel (setq _trkRangeaccel __trkRangeaccel)) _trkRangeaccel)
  (:trkRangerate
   (&optional __trkRangerate)
   (if __trkRangerate (setq _trkRangerate __trkRangerate)) _trkRangerate)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; geometry_msgs/Pose _obstaclePosition
    (send _obstaclePosition :serialization-length)
    ;; geometry_msgs/Twist _obstacleVelocity
    (send _obstacleVelocity :serialization-length)
    ;; geometry_msgs/Accel _obstacleAcceleration
    (send _obstacleAcceleration :serialization-length)
    ;; uint8 _trkID
    1
    ;; float32 _trkLatrate
    4
    ;; float32 _trkAngle
    4
    ;; float32 _trkRange
    4
    ;; float32 _trkWidth
    4
    ;; float32 _trkRangeaccel
    4
    ;; float32 _trkRangerate
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; geometry_msgs/Pose _obstaclePosition
       (send _obstaclePosition :serialize s)
     ;; geometry_msgs/Twist _obstacleVelocity
       (send _obstacleVelocity :serialize s)
     ;; geometry_msgs/Accel _obstacleAcceleration
       (send _obstacleAcceleration :serialize s)
     ;; uint8 _trkID
       (write-byte _trkID s)
     ;; float32 _trkLatrate
       (sys::poke _trkLatrate (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _trkAngle
       (sys::poke _trkAngle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _trkRange
       (sys::poke _trkRange (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _trkWidth
       (sys::poke _trkWidth (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _trkRangeaccel
       (sys::poke _trkRangeaccel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _trkRangerate
       (sys::poke _trkRangerate (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; geometry_msgs/Pose _obstaclePosition
     (send _obstaclePosition :deserialize buf ptr-) (incf ptr- (send _obstaclePosition :serialization-length))
   ;; geometry_msgs/Twist _obstacleVelocity
     (send _obstacleVelocity :deserialize buf ptr-) (incf ptr- (send _obstacleVelocity :serialization-length))
   ;; geometry_msgs/Accel _obstacleAcceleration
     (send _obstacleAcceleration :deserialize buf ptr-) (incf ptr- (send _obstacleAcceleration :serialization-length))
   ;; uint8 _trkID
     (setq _trkID (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32 _trkLatrate
     (setq _trkLatrate (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _trkAngle
     (setq _trkAngle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _trkRange
     (setq _trkRange (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _trkWidth
     (setq _trkWidth (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _trkRangeaccel
     (setq _trkRangeaccel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _trkRangerate
     (setq _trkRangerate (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get message_project_s::sync :md5sum-) "8362c306ad17d94fd3f60283bbd12b35")
(setf (get message_project_s::sync :datatype-) "message_project_s/sync")
(setf (get message_project_s::sync :definition-)
      "Header header
std_msgs/UInt8 id

geometry_msgs/Pose obstaclePosition		# obstacle position
geometry_msgs/Twist obstacleVelocity		# obstacle speed
geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
uint8 trkID
float32 trkLatrate
float32 trkAngle
float32 trkRange
float32 trkWidth
float32 trkRangeaccel
float32 trkRangerate  

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
MSG: geometry_msgs/Accel
# This expresses acceleration in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

")



(provide :message_project_s/sync "8362c306ad17d94fd3f60283bbd12b35")


