;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ehSpotCurvature)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ehSpotCurvature (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::EHSPOTCURVATURE")
  (make-package "PROJECT_S_MSGS::EHSPOTCURVATURE"))

(in-package "ROS")
;;//! \htmlinclude ehSpotCurvature.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::ehSpotCurvature
  :super ros::object
  :slots (_header _id _offset _Value_0 _Distance_1 _Value_1 ))

(defmethod project_s_msgs::ehSpotCurvature
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:offset __offset) (instance std_msgs::Float32 :init))
    ((:Value_0 __Value_0) (instance std_msgs::Float32 :init))
    ((:Distance_1 __Distance_1) (instance std_msgs::Float32 :init))
    ((:Value_1 __Value_1) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _offset __offset)
   (setq _Value_0 __Value_0)
   (setq _Distance_1 __Distance_1)
   (setq _Value_1 __Value_1)
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
  (:Value_0
   (&rest __Value_0)
   (if (keywordp (car __Value_0))
       (send* _Value_0 __Value_0)
     (progn
       (if __Value_0 (setq _Value_0 (car __Value_0)))
       _Value_0)))
  (:Distance_1
   (&rest __Distance_1)
   (if (keywordp (car __Distance_1))
       (send* _Distance_1 __Distance_1)
     (progn
       (if __Distance_1 (setq _Distance_1 (car __Distance_1)))
       _Distance_1)))
  (:Value_1
   (&rest __Value_1)
   (if (keywordp (car __Value_1))
       (send* _Value_1 __Value_1)
     (progn
       (if __Value_1 (setq _Value_1 (car __Value_1)))
       _Value_1)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/Float32 _offset
    (send _offset :serialization-length)
    ;; std_msgs/Float32 _Value_0
    (send _Value_0 :serialization-length)
    ;; std_msgs/Float32 _Distance_1
    (send _Distance_1 :serialization-length)
    ;; std_msgs/Float32 _Value_1
    (send _Value_1 :serialization-length)
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
     ;; std_msgs/Float32 _Value_0
       (send _Value_0 :serialize s)
     ;; std_msgs/Float32 _Distance_1
       (send _Distance_1 :serialize s)
     ;; std_msgs/Float32 _Value_1
       (send _Value_1 :serialize s)
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
   ;; std_msgs/Float32 _Value_0
     (send _Value_0 :deserialize buf ptr-) (incf ptr- (send _Value_0 :serialization-length))
   ;; std_msgs/Float32 _Distance_1
     (send _Distance_1 :deserialize buf ptr-) (incf ptr- (send _Distance_1 :serialization-length))
   ;; std_msgs/Float32 _Value_1
     (send _Value_1 :deserialize buf ptr-) (incf ptr- (send _Value_1 :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ehSpotCurvature :md5sum-) "9d76e4756ee6f85fb71ecf3f9d7549f6")
(setf (get project_s_msgs::ehSpotCurvature :datatype-) "project_s_msgs/ehSpotCurvature")
(setf (get project_s_msgs::ehSpotCurvature :definition-)
      "Header header
std_msgs/UInt8 id

#std_msgs/UInt8 indexPath
std_msgs/Float32 offset
std_msgs/Float32 Value_0
std_msgs/Float32 Distance_1
std_msgs/Float32 Value_1



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



(provide :project_s_msgs/ehSpotCurvature "9d76e4756ee6f85fb71ecf3f9d7549f6")


