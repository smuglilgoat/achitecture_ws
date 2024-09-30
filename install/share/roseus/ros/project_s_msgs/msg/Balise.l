;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::Balise)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'Balise (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::BALISE")
  (make-package "PROJECT_S_MSGS::BALISE"))

(in-package "ROS")
;;//! \htmlinclude Balise.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::Balise
  :super ros::object
  :slots (_header _id _position _class ))

(defmethod project_s_msgs::Balise
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:position __position) (instance geometry_msgs::Pose :init))
    ((:class __class) (instance std_msgs::UInt8 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _position __position)
   (setq _class __class)
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
  (:position
   (&rest __position)
   (if (keywordp (car __position))
       (send* _position __position)
     (progn
       (if __position (setq _position (car __position)))
       _position)))
  (:class
   (&rest __class)
   (if (keywordp (car __class))
       (send* _class __class)
     (progn
       (if __class (setq _class (car __class)))
       _class)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; geometry_msgs/Pose _position
    (send _position :serialization-length)
    ;; std_msgs/UInt8 _class
    (send _class :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; geometry_msgs/Pose _position
       (send _position :serialize s)
     ;; std_msgs/UInt8 _class
       (send _class :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; geometry_msgs/Pose _position
     (send _position :deserialize buf ptr-) (incf ptr- (send _position :serialization-length))
   ;; std_msgs/UInt8 _class
     (send _class :deserialize buf ptr-) (incf ptr- (send _class :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::Balise :md5sum-) "44e07a8e3f62d9f2c79894367aa4ccba")
(setf (get project_s_msgs::Balise :datatype-) "project_s_msgs/Balise")
(setf (get project_s_msgs::Balise :definition-)
      "Header header
std_msgs/UInt8 id

geometry_msgs/Pose position
std_msgs/UInt8 class





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
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :project_s_msgs/Balise "44e07a8e3f62d9f2c79894367aa4ccba")


