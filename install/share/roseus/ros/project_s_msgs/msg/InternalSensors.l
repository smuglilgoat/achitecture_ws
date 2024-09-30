;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::InternalSensors)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'InternalSensors (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::INTERNALSENSORS")
  (make-package "PROJECT_S_MSGS::INTERNALSENSORS"))

(in-package "ROS")
;;//! \htmlinclude InternalSensors.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::InternalSensors
  :super ros::object
  :slots (_header _id _vehicleleVelocity _vehicleAcceleration _steeringWheelAngle _timeStamp ))

(defmethod project_s_msgs::InternalSensors
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:vehicleleVelocity __vehicleleVelocity) (instance geometry_msgs::Twist :init))
    ((:vehicleAcceleration __vehicleAcceleration) (instance geometry_msgs::Accel :init))
    ((:steeringWheelAngle __steeringWheelAngle) (instance std_msgs::Float32 :init))
    ((:timeStamp __timeStamp) (instance std_msgs::UInt64 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _vehicleleVelocity __vehicleleVelocity)
   (setq _vehicleAcceleration __vehicleAcceleration)
   (setq _steeringWheelAngle __steeringWheelAngle)
   (setq _timeStamp __timeStamp)
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
  (:vehicleleVelocity
   (&rest __vehicleleVelocity)
   (if (keywordp (car __vehicleleVelocity))
       (send* _vehicleleVelocity __vehicleleVelocity)
     (progn
       (if __vehicleleVelocity (setq _vehicleleVelocity (car __vehicleleVelocity)))
       _vehicleleVelocity)))
  (:vehicleAcceleration
   (&rest __vehicleAcceleration)
   (if (keywordp (car __vehicleAcceleration))
       (send* _vehicleAcceleration __vehicleAcceleration)
     (progn
       (if __vehicleAcceleration (setq _vehicleAcceleration (car __vehicleAcceleration)))
       _vehicleAcceleration)))
  (:steeringWheelAngle
   (&rest __steeringWheelAngle)
   (if (keywordp (car __steeringWheelAngle))
       (send* _steeringWheelAngle __steeringWheelAngle)
     (progn
       (if __steeringWheelAngle (setq _steeringWheelAngle (car __steeringWheelAngle)))
       _steeringWheelAngle)))
  (:timeStamp
   (&rest __timeStamp)
   (if (keywordp (car __timeStamp))
       (send* _timeStamp __timeStamp)
     (progn
       (if __timeStamp (setq _timeStamp (car __timeStamp)))
       _timeStamp)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; geometry_msgs/Twist _vehicleleVelocity
    (send _vehicleleVelocity :serialization-length)
    ;; geometry_msgs/Accel _vehicleAcceleration
    (send _vehicleAcceleration :serialization-length)
    ;; std_msgs/Float32 _steeringWheelAngle
    (send _steeringWheelAngle :serialization-length)
    ;; std_msgs/UInt64 _timeStamp
    (send _timeStamp :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; geometry_msgs/Twist _vehicleleVelocity
       (send _vehicleleVelocity :serialize s)
     ;; geometry_msgs/Accel _vehicleAcceleration
       (send _vehicleAcceleration :serialize s)
     ;; std_msgs/Float32 _steeringWheelAngle
       (send _steeringWheelAngle :serialize s)
     ;; std_msgs/UInt64 _timeStamp
       (send _timeStamp :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; geometry_msgs/Twist _vehicleleVelocity
     (send _vehicleleVelocity :deserialize buf ptr-) (incf ptr- (send _vehicleleVelocity :serialization-length))
   ;; geometry_msgs/Accel _vehicleAcceleration
     (send _vehicleAcceleration :deserialize buf ptr-) (incf ptr- (send _vehicleAcceleration :serialization-length))
   ;; std_msgs/Float32 _steeringWheelAngle
     (send _steeringWheelAngle :deserialize buf ptr-) (incf ptr- (send _steeringWheelAngle :serialization-length))
   ;; std_msgs/UInt64 _timeStamp
     (send _timeStamp :deserialize buf ptr-) (incf ptr- (send _timeStamp :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::InternalSensors :md5sum-) "c7afa49d12086db3055945e1a8731d66")
(setf (get project_s_msgs::InternalSensors :datatype-) "project_s_msgs/InternalSensors")
(setf (get project_s_msgs::InternalSensors :definition-)
      "Header header
std_msgs/UInt8 id

geometry_msgs/Twist vehicleleVelocity
geometry_msgs/Accel vehicleAcceleration
std_msgs/Float32 steeringWheelAngle
std_msgs/UInt64 timeStamp






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
MSG: std_msgs/UInt64
uint64 data
")



(provide :project_s_msgs/InternalSensors "c7afa49d12086db3055945e1a8731d66")


