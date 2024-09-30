;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ehLineCoordGeo)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ehLineCoordGeo (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::EHLINECOORDGEO")
  (make-package "PROJECT_S_MSGS::EHLINECOORDGEO"))

(in-package "ROS")
;;//! \htmlinclude ehLineCoordGeo.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*SPOT_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::EHLINECOORDGEO"))
(shadow '*SPOT_REPORT_SIZE* (find-package "PROJECT_S_MSGS::EHLINECOORDGEO"))
(defconstant project_s_msgs::ehLineCoordGeo::*SPOT_REPORT_SIZE* 3000)
(defclass project_s_msgs::ehLineCoordGeo
  :super ros::object
  :slots (_header _id _ehSpotCoordGeo _NbrSpotCoordGeo ))

(defmethod project_s_msgs::ehLineCoordGeo
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:ehSpotCoordGeo __ehSpotCoordGeo) (let (r) (dotimes (i 3000) (push (instance project_s_msgs::ehSpotCoordGeo :init) r)) r))
    ((:NbrSpotCoordGeo __NbrSpotCoordGeo) (instance std_msgs::UInt32 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _ehSpotCoordGeo __ehSpotCoordGeo)
   (setq _NbrSpotCoordGeo __NbrSpotCoordGeo)
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
  (:ehSpotCoordGeo
   (&rest __ehSpotCoordGeo)
   (if (keywordp (car __ehSpotCoordGeo))
       (send* _ehSpotCoordGeo __ehSpotCoordGeo)
     (progn
       (if __ehSpotCoordGeo (setq _ehSpotCoordGeo (car __ehSpotCoordGeo)))
       _ehSpotCoordGeo)))
  (:NbrSpotCoordGeo
   (&rest __NbrSpotCoordGeo)
   (if (keywordp (car __NbrSpotCoordGeo))
       (send* _NbrSpotCoordGeo __NbrSpotCoordGeo)
     (progn
       (if __NbrSpotCoordGeo (setq _NbrSpotCoordGeo (car __NbrSpotCoordGeo)))
       _NbrSpotCoordGeo)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; project_s_msgs/ehSpotCoordGeo[3000] _ehSpotCoordGeo
    (apply #'+ (send-all _ehSpotCoordGeo :serialization-length))
    ;; std_msgs/UInt32 _NbrSpotCoordGeo
    (send _NbrSpotCoordGeo :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; project_s_msgs/ehSpotCoordGeo[3000] _ehSpotCoordGeo
     (dolist (elem _ehSpotCoordGeo)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt32 _NbrSpotCoordGeo
       (send _NbrSpotCoordGeo :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; project_s_msgs/ehSpotCoordGeo[3000] _ehSpotCoordGeo
   (dotimes (i 3000)
     (send (elt _ehSpotCoordGeo i) :deserialize buf ptr-) (incf ptr- (send (elt _ehSpotCoordGeo i) :serialization-length))
     )
   ;; std_msgs/UInt32 _NbrSpotCoordGeo
     (send _NbrSpotCoordGeo :deserialize buf ptr-) (incf ptr- (send _NbrSpotCoordGeo :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ehLineCoordGeo :md5sum-) "ead25328a4cdf8f2b075ecd4258a79fb")
(setf (get project_s_msgs::ehLineCoordGeo :datatype-) "project_s_msgs/ehLineCoordGeo")
(setf (get project_s_msgs::ehLineCoordGeo :definition-)
      "Header header
std_msgs/UInt8 id

uint32 SPOT_REPORT_SIZE = 3000
project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo
std_msgs/UInt32 NbrSpotCoordGeo


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
MSG: project_s_msgs/ehSpotCoordGeo
Header header
std_msgs/UInt8 id

std_msgs/Float32 offset
float64 latitude
float64 longitude



================================================================================
MSG: std_msgs/Float32
float32 data
================================================================================
MSG: std_msgs/UInt32
uint32 data
")



(provide :project_s_msgs/ehLineCoordGeo "ead25328a4cdf8f2b075ecd4258a79fb")


