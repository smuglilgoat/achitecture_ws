;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::Actuators)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'Actuators (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::ACTUATORS")
  (make-package "PROJECT_S_MSGS::ACTUATORS"))

(in-package "ROS")
;;//! \htmlinclude Actuators.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::Actuators
  :super ros::object
  :slots (_header _id _Accelerator _brakePressure _steeringAngle ))

(defmethod project_s_msgs::Actuators
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:Accelerator __Accelerator) (instance std_msgs::Float32 :init))
    ((:brakePressure __brakePressure) (instance std_msgs::Float32 :init))
    ((:steeringAngle __steeringAngle) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _Accelerator __Accelerator)
   (setq _brakePressure __brakePressure)
   (setq _steeringAngle __steeringAngle)
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
  (:Accelerator
   (&rest __Accelerator)
   (if (keywordp (car __Accelerator))
       (send* _Accelerator __Accelerator)
     (progn
       (if __Accelerator (setq _Accelerator (car __Accelerator)))
       _Accelerator)))
  (:brakePressure
   (&rest __brakePressure)
   (if (keywordp (car __brakePressure))
       (send* _brakePressure __brakePressure)
     (progn
       (if __brakePressure (setq _brakePressure (car __brakePressure)))
       _brakePressure)))
  (:steeringAngle
   (&rest __steeringAngle)
   (if (keywordp (car __steeringAngle))
       (send* _steeringAngle __steeringAngle)
     (progn
       (if __steeringAngle (setq _steeringAngle (car __steeringAngle)))
       _steeringAngle)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/Float32 _Accelerator
    (send _Accelerator :serialization-length)
    ;; std_msgs/Float32 _brakePressure
    (send _brakePressure :serialization-length)
    ;; std_msgs/Float32 _steeringAngle
    (send _steeringAngle :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/Float32 _Accelerator
       (send _Accelerator :serialize s)
     ;; std_msgs/Float32 _brakePressure
       (send _brakePressure :serialize s)
     ;; std_msgs/Float32 _steeringAngle
       (send _steeringAngle :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/Float32 _Accelerator
     (send _Accelerator :deserialize buf ptr-) (incf ptr- (send _Accelerator :serialization-length))
   ;; std_msgs/Float32 _brakePressure
     (send _brakePressure :deserialize buf ptr-) (incf ptr- (send _brakePressure :serialization-length))
   ;; std_msgs/Float32 _steeringAngle
     (send _steeringAngle :deserialize buf ptr-) (incf ptr- (send _steeringAngle :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::Actuators :md5sum-) "94218c4fc10da9425fa7248c8f707ac5")
(setf (get project_s_msgs::Actuators :datatype-) "project_s_msgs/Actuators")
(setf (get project_s_msgs::Actuators :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/Float32 Accelerator
std_msgs/Float32 brakePressure
std_msgs/Float32 steeringAngle

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



(provide :project_s_msgs/Actuators "94218c4fc10da9425fa7248c8f707ac5")


