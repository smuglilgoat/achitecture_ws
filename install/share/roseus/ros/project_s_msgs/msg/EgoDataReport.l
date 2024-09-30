;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::EgoDataReport)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'EgoDataReport (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::EGODATAREPORT")
  (make-package "PROJECT_S_MSGS::EGODATAREPORT"))

(in-package "ROS")
;;//! \htmlinclude EgoDataReport.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*NBR_MAX_EGO_DATA*" (find-package "PROJECT_S_MSGS::EGODATAREPORT"))
(shadow '*NBR_MAX_EGO_DATA* (find-package "PROJECT_S_MSGS::EGODATAREPORT"))
(defconstant project_s_msgs::EgoDataReport::*NBR_MAX_EGO_DATA* 10)
(defclass project_s_msgs::EgoDataReport
  :super ros::object
  :slots (_header _id _EgoData ))

(defmethod project_s_msgs::EgoDataReport
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:EgoData __EgoData) (let (r) (dotimes (i 10) (push (instance project_s_msgs::EgoData :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _EgoData __EgoData)
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
  (:EgoData
   (&rest __EgoData)
   (if (keywordp (car __EgoData))
       (send* _EgoData __EgoData)
     (progn
       (if __EgoData (setq _EgoData (car __EgoData)))
       _EgoData)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; project_s_msgs/EgoData[10] _EgoData
    (apply #'+ (send-all _EgoData :serialization-length))
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; project_s_msgs/EgoData[10] _EgoData
     (dolist (elem _EgoData)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; project_s_msgs/EgoData[10] _EgoData
   (dotimes (i 10)
     (send (elt _EgoData i) :deserialize buf ptr-) (incf ptr- (send (elt _EgoData i) :serialization-length))
     )
   ;;
   self)
  )

(setf (get project_s_msgs::EgoDataReport :md5sum-) "4c22f2f7b4f8443a0c599fc0f8a1800a")
(setf (get project_s_msgs::EgoDataReport :datatype-) "project_s_msgs/EgoDataReport")
(setf (get project_s_msgs::EgoDataReport :definition-)
      "Header header
std_msgs/UInt8 id

uint8 NBR_MAX_EGO_DATA = 10
project_s_msgs/EgoData[10] EgoData	# en concordance avec NBR_MAX_EGO_DATA/vehicle.cpp, local_tracks_synchro, global_tracks_prediction, road_model

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
MSG: project_s_msgs/EgoData
time stamp

geometry_msgs/Twist velocity
geometry_msgs/Accel acceleration

float64 latitude
float64 longitude
float32 cap


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

")



(provide :project_s_msgs/EgoDataReport "4c22f2f7b4f8443a0c599fc0f8a1800a")


