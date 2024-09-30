;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ehSpotTrafficSign)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ehSpotTrafficSign (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::EHSPOTTRAFFICSIGN")
  (make-package "PROJECT_S_MSGS::EHSPOTTRAFFICSIGN"))

(in-package "ROS")
;;//! \htmlinclude ehSpotTrafficSign.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::ehSpotTrafficSign
  :super ros::object
  :slots (_header _id _offset _Sign_Type _Value _Lane _Sign_Location _latitude _longitude ))

(defmethod project_s_msgs::ehSpotTrafficSign
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:offset __offset) (instance std_msgs::Float32 :init))
    ((:Sign_Type __Sign_Type) 0)
    ((:Value __Value) 0)
    ((:Lane __Lane) 0)
    ((:Sign_Location __Sign_Location) 0)
    ((:latitude __latitude) 0.0)
    ((:longitude __longitude) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _offset __offset)
   (setq _Sign_Type (round __Sign_Type))
   (setq _Value (round __Value))
   (setq _Lane (round __Lane))
   (setq _Sign_Location (round __Sign_Location))
   (setq _latitude (float __latitude))
   (setq _longitude (float __longitude))
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
  (:offset
   (&rest __offset)
   (if (keywordp (car __offset))
       (send* _offset __offset)
     (progn
       (if __offset (setq _offset (car __offset)))
       _offset)))
  (:Sign_Type
   (&optional __Sign_Type)
   (if __Sign_Type (setq _Sign_Type __Sign_Type)) _Sign_Type)
  (:Value
   (&optional __Value)
   (if __Value (setq _Value __Value)) _Value)
  (:Lane
   (&optional __Lane)
   (if __Lane (setq _Lane __Lane)) _Lane)
  (:Sign_Location
   (&optional __Sign_Location)
   (if __Sign_Location (setq _Sign_Location __Sign_Location)) _Sign_Location)
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/Float32 _offset
    (send _offset :serialization-length)
    ;; uint8 _Sign_Type
    1
    ;; uint8 _Value
    1
    ;; uint8 _Lane
    1
    ;; uint8 _Sign_Location
    1
    ;; float64 _latitude
    8
    ;; float64 _longitude
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/Float32 _offset
       (send _offset :serialize s)
     ;; uint8 _Sign_Type
       (write-byte _Sign_Type s)
     ;; uint8 _Value
       (write-byte _Value s)
     ;; uint8 _Lane
       (write-byte _Lane s)
     ;; uint8 _Sign_Location
       (write-byte _Sign_Location s)
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/Float32 _offset
     (send _offset :deserialize buf ptr-) (incf ptr- (send _offset :serialization-length))
   ;; uint8 _Sign_Type
     (setq _Sign_Type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _Value
     (setq _Value (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _Lane
     (setq _Lane (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _Sign_Location
     (setq _Sign_Location (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _longitude
     (setq _longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get project_s_msgs::ehSpotTrafficSign :md5sum-) "af1c38cf4ea201cb74580c0ad2e95c49")
(setf (get project_s_msgs::ehSpotTrafficSign :datatype-) "project_s_msgs/ehSpotTrafficSign")
(setf (get project_s_msgs::ehSpotTrafficSign :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/Float32 offset
uint8 Sign_Type
uint8 Value
uint8 Lane
uint8 Sign_Location
float64 latitude
float64 longitude




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



(provide :project_s_msgs/ehSpotTrafficSign "af1c38cf4ea201cb74580c0ad2e95c49")


