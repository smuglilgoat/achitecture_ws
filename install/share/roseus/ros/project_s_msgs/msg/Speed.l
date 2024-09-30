;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::Speed)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'Speed (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::SPEED")
  (make-package "PROJECT_S_MSGS::SPEED"))

(in-package "ROS")
;;//! \htmlinclude Speed.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::Speed
  :super ros::object
  :slots (_header _id _offset _speed ))

(defmethod project_s_msgs::Speed
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:offset __offset) (instance std_msgs::Float32 :init))
    ((:speed __speed) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _offset __offset)
   (setq _speed __speed)
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
  (:speed
   (&rest __speed)
   (if (keywordp (car __speed))
       (send* _speed __speed)
     (progn
       (if __speed (setq _speed (car __speed)))
       _speed)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/Float32 _offset
    (send _offset :serialization-length)
    ;; std_msgs/Float32 _speed
    (send _speed :serialization-length)
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
     ;; std_msgs/Float32 _speed
       (send _speed :serialize s)
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
   ;; std_msgs/Float32 _speed
     (send _speed :deserialize buf ptr-) (incf ptr- (send _speed :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::Speed :md5sum-) "6d470655cf163287a0a2b9e868be5fa3")
(setf (get project_s_msgs::Speed :datatype-) "project_s_msgs/Speed")
(setf (get project_s_msgs::Speed :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/Float32 offset
std_msgs/Float32 speed


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



(provide :project_s_msgs/Speed "6d470655cf163287a0a2b9e868be5fa3")


