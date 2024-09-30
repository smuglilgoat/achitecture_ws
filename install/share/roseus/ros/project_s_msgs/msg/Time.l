;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::Time)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'Time (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::TIME")
  (make-package "PROJECT_S_MSGS::TIME"))

(in-package "ROS")
;;//! \htmlinclude Time.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::Time
  :super ros::object
  :slots (_header _id _Tn _Tn_1 _Ti _iMIN ))

(defmethod project_s_msgs::Time
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:Tn __Tn) (instance std_msgs::Float64 :init))
    ((:Tn_1 __Tn_1) (instance std_msgs::Float64 :init))
    ((:Ti __Ti) (instance std_msgs::Float64 :init))
    ((:iMIN __iMIN) (instance std_msgs::Float64 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _Tn __Tn)
   (setq _Tn_1 __Tn_1)
   (setq _Ti __Ti)
   (setq _iMIN __iMIN)
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
  (:Tn
   (&rest __Tn)
   (if (keywordp (car __Tn))
       (send* _Tn __Tn)
     (progn
       (if __Tn (setq _Tn (car __Tn)))
       _Tn)))
  (:Tn_1
   (&rest __Tn_1)
   (if (keywordp (car __Tn_1))
       (send* _Tn_1 __Tn_1)
     (progn
       (if __Tn_1 (setq _Tn_1 (car __Tn_1)))
       _Tn_1)))
  (:Ti
   (&rest __Ti)
   (if (keywordp (car __Ti))
       (send* _Ti __Ti)
     (progn
       (if __Ti (setq _Ti (car __Ti)))
       _Ti)))
  (:iMIN
   (&rest __iMIN)
   (if (keywordp (car __iMIN))
       (send* _iMIN __iMIN)
     (progn
       (if __iMIN (setq _iMIN (car __iMIN)))
       _iMIN)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/Float64 _Tn
    (send _Tn :serialization-length)
    ;; std_msgs/Float64 _Tn_1
    (send _Tn_1 :serialization-length)
    ;; std_msgs/Float64 _Ti
    (send _Ti :serialization-length)
    ;; std_msgs/Float64 _iMIN
    (send _iMIN :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/Float64 _Tn
       (send _Tn :serialize s)
     ;; std_msgs/Float64 _Tn_1
       (send _Tn_1 :serialize s)
     ;; std_msgs/Float64 _Ti
       (send _Ti :serialize s)
     ;; std_msgs/Float64 _iMIN
       (send _iMIN :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/Float64 _Tn
     (send _Tn :deserialize buf ptr-) (incf ptr- (send _Tn :serialization-length))
   ;; std_msgs/Float64 _Tn_1
     (send _Tn_1 :deserialize buf ptr-) (incf ptr- (send _Tn_1 :serialization-length))
   ;; std_msgs/Float64 _Ti
     (send _Ti :deserialize buf ptr-) (incf ptr- (send _Ti :serialization-length))
   ;; std_msgs/Float64 _iMIN
     (send _iMIN :deserialize buf ptr-) (incf ptr- (send _iMIN :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::Time :md5sum-) "8478fcb0a41d3039f22925b77479cd7f")
(setf (get project_s_msgs::Time :datatype-) "project_s_msgs/Time")
(setf (get project_s_msgs::Time :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/Float64 Tn
std_msgs/Float64 Tn_1
std_msgs/Float64 Ti
std_msgs/Float64 iMIN


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
MSG: std_msgs/Float64
float64 data
")



(provide :project_s_msgs/Time "8478fcb0a41d3039f22925b77479cd7f")


