;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::MapMatching)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'MapMatching (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::MAPMATCHING")
  (make-package "PROJECT_S_MSGS::MAPMATCHING"))

(in-package "ROS")
;;//! \htmlinclude MapMatching.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::MapMatching
  :super ros::object
  :slots (_header _id _link_ID _link_HEREtile_ID _Distance_Curviligne_Ego _latitude _longitude _cap ))

(defmethod project_s_msgs::MapMatching
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:link_ID __link_ID) (instance std_msgs::UInt32 :init))
    ((:link_HEREtile_ID __link_HEREtile_ID) (instance std_msgs::UInt32 :init))
    ((:Distance_Curviligne_Ego __Distance_Curviligne_Ego) (instance std_msgs::Float32 :init))
    ((:latitude __latitude) 0.0)
    ((:longitude __longitude) 0.0)
    ((:cap __cap) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _link_ID __link_ID)
   (setq _link_HEREtile_ID __link_HEREtile_ID)
   (setq _Distance_Curviligne_Ego __Distance_Curviligne_Ego)
   (setq _latitude (float __latitude))
   (setq _longitude (float __longitude))
   (setq _cap __cap)
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
  (:link_ID
   (&rest __link_ID)
   (if (keywordp (car __link_ID))
       (send* _link_ID __link_ID)
     (progn
       (if __link_ID (setq _link_ID (car __link_ID)))
       _link_ID)))
  (:link_HEREtile_ID
   (&rest __link_HEREtile_ID)
   (if (keywordp (car __link_HEREtile_ID))
       (send* _link_HEREtile_ID __link_HEREtile_ID)
     (progn
       (if __link_HEREtile_ID (setq _link_HEREtile_ID (car __link_HEREtile_ID)))
       _link_HEREtile_ID)))
  (:Distance_Curviligne_Ego
   (&rest __Distance_Curviligne_Ego)
   (if (keywordp (car __Distance_Curviligne_Ego))
       (send* _Distance_Curviligne_Ego __Distance_Curviligne_Ego)
     (progn
       (if __Distance_Curviligne_Ego (setq _Distance_Curviligne_Ego (car __Distance_Curviligne_Ego)))
       _Distance_Curviligne_Ego)))
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:cap
   (&rest __cap)
   (if (keywordp (car __cap))
       (send* _cap __cap)
     (progn
       (if __cap (setq _cap (car __cap)))
       _cap)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/UInt32 _link_ID
    (send _link_ID :serialization-length)
    ;; std_msgs/UInt32 _link_HEREtile_ID
    (send _link_HEREtile_ID :serialization-length)
    ;; std_msgs/Float32 _Distance_Curviligne_Ego
    (send _Distance_Curviligne_Ego :serialization-length)
    ;; float64 _latitude
    8
    ;; float64 _longitude
    8
    ;; std_msgs/Float32 _cap
    (send _cap :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/UInt32 _link_ID
       (send _link_ID :serialize s)
     ;; std_msgs/UInt32 _link_HEREtile_ID
       (send _link_HEREtile_ID :serialize s)
     ;; std_msgs/Float32 _Distance_Curviligne_Ego
       (send _Distance_Curviligne_Ego :serialize s)
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; std_msgs/Float32 _cap
       (send _cap :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/UInt32 _link_ID
     (send _link_ID :deserialize buf ptr-) (incf ptr- (send _link_ID :serialization-length))
   ;; std_msgs/UInt32 _link_HEREtile_ID
     (send _link_HEREtile_ID :deserialize buf ptr-) (incf ptr- (send _link_HEREtile_ID :serialization-length))
   ;; std_msgs/Float32 _Distance_Curviligne_Ego
     (send _Distance_Curviligne_Ego :deserialize buf ptr-) (incf ptr- (send _Distance_Curviligne_Ego :serialization-length))
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _longitude
     (setq _longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; std_msgs/Float32 _cap
     (send _cap :deserialize buf ptr-) (incf ptr- (send _cap :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::MapMatching :md5sum-) "751b9780203e0387595b35e7afcb932c")
(setf (get project_s_msgs::MapMatching :datatype-) "project_s_msgs/MapMatching")
(setf (get project_s_msgs::MapMatching :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/UInt32 link_ID
std_msgs/UInt32 link_HEREtile_ID
std_msgs/Float32 Distance_Curviligne_Ego
float64 latitude
float64 longitude
std_msgs/Float32 cap

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
MSG: std_msgs/UInt32
uint32 data
================================================================================
MSG: std_msgs/Float32
float32 data
")



(provide :project_s_msgs/MapMatching "751b9780203e0387595b35e7afcb932c")


