;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::Segment)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'Segment (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::SEGMENT")
  (make-package "PROJECT_S_MSGS::SEGMENT"))

(in-package "ROS")
;;//! \htmlinclude Segment.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::Segment
  :super ros::object
  :slots (_length _angle _position _Velocity _offset _latitude _longitude ))

(defmethod project_s_msgs::Segment
  (:init
   (&key
    ((:length __length) (instance std_msgs::Float32 :init))
    ((:angle __angle) (instance std_msgs::Float32 :init))
    ((:position __position) (instance geometry_msgs::Point :init))
    ((:Velocity __Velocity) (instance geometry_msgs::Twist :init))
    ((:offset __offset) 0.0)
    ((:latitude __latitude) 0.0)
    ((:longitude __longitude) 0.0)
    )
   (send-super :init)
   (setq _length __length)
   (setq _angle __angle)
   (setq _position __position)
   (setq _Velocity __Velocity)
   (setq _offset (float __offset))
   (setq _latitude (float __latitude))
   (setq _longitude (float __longitude))
   self)
  (:length
   (&rest __length)
   (if (keywordp (car __length))
       (send* _length __length)
     (progn
       (if __length (setq _length (car __length)))
       _length)))
  (:angle
   (&rest __angle)
   (if (keywordp (car __angle))
       (send* _angle __angle)
     (progn
       (if __angle (setq _angle (car __angle)))
       _angle)))
  (:position
   (&rest __position)
   (if (keywordp (car __position))
       (send* _position __position)
     (progn
       (if __position (setq _position (car __position)))
       _position)))
  (:Velocity
   (&rest __Velocity)
   (if (keywordp (car __Velocity))
       (send* _Velocity __Velocity)
     (progn
       (if __Velocity (setq _Velocity (car __Velocity)))
       _Velocity)))
  (:offset
   (&optional __offset)
   (if __offset (setq _offset __offset)) _offset)
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Float32 _length
    (send _length :serialization-length)
    ;; std_msgs/Float32 _angle
    (send _angle :serialization-length)
    ;; geometry_msgs/Point _position
    (send _position :serialization-length)
    ;; geometry_msgs/Twist _Velocity
    (send _Velocity :serialization-length)
    ;; float32 _offset
    4
    ;; float64 _latitude
    8
    ;; float64 _longitude
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Float32 _length
       (send _length :serialize s)
     ;; std_msgs/Float32 _angle
       (send _angle :serialize s)
     ;; geometry_msgs/Point _position
       (send _position :serialize s)
     ;; geometry_msgs/Twist _Velocity
       (send _Velocity :serialize s)
     ;; float32 _offset
       (sys::poke _offset (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Float32 _length
     (send _length :deserialize buf ptr-) (incf ptr- (send _length :serialization-length))
   ;; std_msgs/Float32 _angle
     (send _angle :deserialize buf ptr-) (incf ptr- (send _angle :serialization-length))
   ;; geometry_msgs/Point _position
     (send _position :deserialize buf ptr-) (incf ptr- (send _position :serialization-length))
   ;; geometry_msgs/Twist _Velocity
     (send _Velocity :deserialize buf ptr-) (incf ptr- (send _Velocity :serialization-length))
   ;; float32 _offset
     (setq _offset (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _longitude
     (setq _longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get project_s_msgs::Segment :md5sum-) "0200b1b9a0c7d4e89df00f85e257450b")
(setf (get project_s_msgs::Segment :datatype-) "project_s_msgs/Segment")
(setf (get project_s_msgs::Segment :definition-)
      "std_msgs/Float32 length		# length of the segment
std_msgs/Float32 angle		# angle of the segment
geometry_msgs/Point position
geometry_msgs/Twist Velocity

float32 offset
float64 latitude
float64 longitude


================================================================================
MSG: std_msgs/Float32
float32 data
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

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
")



(provide :project_s_msgs/Segment "0200b1b9a0c7d4e89df00f85e257450b")


