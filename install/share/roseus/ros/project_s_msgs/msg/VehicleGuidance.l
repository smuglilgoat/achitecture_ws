;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::VehicleGuidance)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'VehicleGuidance (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::VEHICLEGUIDANCE")
  (make-package "PROJECT_S_MSGS::VEHICLEGUIDANCE"))

(in-package "ROS")
;;//! \htmlinclude VehicleGuidance.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::VehicleGuidance
  :super ros::object
  :slots (_header _id _driveBrakingTorque _steeringWheelAngle ))

(defmethod project_s_msgs::VehicleGuidance
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:driveBrakingTorque __driveBrakingTorque) (instance std_msgs::Float32 :init))
    ((:steeringWheelAngle __steeringWheelAngle) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _driveBrakingTorque __driveBrakingTorque)
   (setq _steeringWheelAngle __steeringWheelAngle)
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
  (:driveBrakingTorque
   (&rest __driveBrakingTorque)
   (if (keywordp (car __driveBrakingTorque))
       (send* _driveBrakingTorque __driveBrakingTorque)
     (progn
       (if __driveBrakingTorque (setq _driveBrakingTorque (car __driveBrakingTorque)))
       _driveBrakingTorque)))
  (:steeringWheelAngle
   (&rest __steeringWheelAngle)
   (if (keywordp (car __steeringWheelAngle))
       (send* _steeringWheelAngle __steeringWheelAngle)
     (progn
       (if __steeringWheelAngle (setq _steeringWheelAngle (car __steeringWheelAngle)))
       _steeringWheelAngle)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/Float32 _driveBrakingTorque
    (send _driveBrakingTorque :serialization-length)
    ;; std_msgs/Float32 _steeringWheelAngle
    (send _steeringWheelAngle :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/Float32 _driveBrakingTorque
       (send _driveBrakingTorque :serialize s)
     ;; std_msgs/Float32 _steeringWheelAngle
       (send _steeringWheelAngle :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/Float32 _driveBrakingTorque
     (send _driveBrakingTorque :deserialize buf ptr-) (incf ptr- (send _driveBrakingTorque :serialization-length))
   ;; std_msgs/Float32 _steeringWheelAngle
     (send _steeringWheelAngle :deserialize buf ptr-) (incf ptr- (send _steeringWheelAngle :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::VehicleGuidance :md5sum-) "a30249730ffc4cf5ea06646bfb349079")
(setf (get project_s_msgs::VehicleGuidance :datatype-) "project_s_msgs/VehicleGuidance")
(setf (get project_s_msgs::VehicleGuidance :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/Float32 driveBrakingTorque
std_msgs/Float32 steeringWheelAngle

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
")



(provide :project_s_msgs/VehicleGuidance "a30249730ffc4cf5ea06646bfb349079")


