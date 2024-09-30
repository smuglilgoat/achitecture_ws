;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ehSegmentME)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ehSegmentME (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::EHSEGMENTME")
  (make-package "PROJECT_S_MSGS::EHSEGMENTME"))

(in-package "ROS")
;;//! \htmlinclude ehSegmentME.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::ehSegmentME
  :super ros::object
  :slots (_header _id _NbrSpot _offset_debut _offset_fin ))

(defmethod project_s_msgs::ehSegmentME
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:NbrSpot __NbrSpot) (instance std_msgs::UInt32 :init))
    ((:offset_debut __offset_debut) (instance std_msgs::Float32 :init))
    ((:offset_fin __offset_fin) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _NbrSpot __NbrSpot)
   (setq _offset_debut __offset_debut)
   (setq _offset_fin __offset_fin)
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
  (:NbrSpot
   (&rest __NbrSpot)
   (if (keywordp (car __NbrSpot))
       (send* _NbrSpot __NbrSpot)
     (progn
       (if __NbrSpot (setq _NbrSpot (car __NbrSpot)))
       _NbrSpot)))
  (:offset_debut
   (&rest __offset_debut)
   (if (keywordp (car __offset_debut))
       (send* _offset_debut __offset_debut)
     (progn
       (if __offset_debut (setq _offset_debut (car __offset_debut)))
       _offset_debut)))
  (:offset_fin
   (&rest __offset_fin)
   (if (keywordp (car __offset_fin))
       (send* _offset_fin __offset_fin)
     (progn
       (if __offset_fin (setq _offset_fin (car __offset_fin)))
       _offset_fin)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/UInt32 _NbrSpot
    (send _NbrSpot :serialization-length)
    ;; std_msgs/Float32 _offset_debut
    (send _offset_debut :serialization-length)
    ;; std_msgs/Float32 _offset_fin
    (send _offset_fin :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/UInt32 _NbrSpot
       (send _NbrSpot :serialize s)
     ;; std_msgs/Float32 _offset_debut
       (send _offset_debut :serialize s)
     ;; std_msgs/Float32 _offset_fin
       (send _offset_fin :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/UInt32 _NbrSpot
     (send _NbrSpot :deserialize buf ptr-) (incf ptr- (send _NbrSpot :serialization-length))
   ;; std_msgs/Float32 _offset_debut
     (send _offset_debut :deserialize buf ptr-) (incf ptr- (send _offset_debut :serialization-length))
   ;; std_msgs/Float32 _offset_fin
     (send _offset_fin :deserialize buf ptr-) (incf ptr- (send _offset_fin :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ehSegmentME :md5sum-) "fc1755dbec2ea339a235fdf3e4d21311")
(setf (get project_s_msgs::ehSegmentME :datatype-) "project_s_msgs/ehSegmentME")
(setf (get project_s_msgs::ehSegmentME :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/UInt32 NbrSpot
std_msgs/Float32 offset_debut
std_msgs/Float32 offset_fin

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



(provide :project_s_msgs/ehSegmentME "fc1755dbec2ea339a235fdf3e4d21311")


