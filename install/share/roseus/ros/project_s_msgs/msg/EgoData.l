;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::EgoData)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'EgoData (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::EGODATA")
  (make-package "PROJECT_S_MSGS::EGODATA"))

(in-package "ROS")
;;//! \htmlinclude EgoData.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass project_s_msgs::EgoData
  :super ros::object
  :slots (_stamp _velocity _acceleration _latitude _longitude _cap ))

(defmethod project_s_msgs::EgoData
  (:init
   (&key
    ((:stamp __stamp) (instance ros::time :init))
    ((:velocity __velocity) (instance geometry_msgs::Twist :init))
    ((:acceleration __acceleration) (instance geometry_msgs::Accel :init))
    ((:latitude __latitude) 0.0)
    ((:longitude __longitude) 0.0)
    ((:cap __cap) 0.0)
    )
   (send-super :init)
   (setq _stamp __stamp)
   (setq _velocity __velocity)
   (setq _acceleration __acceleration)
   (setq _latitude (float __latitude))
   (setq _longitude (float __longitude))
   (setq _cap (float __cap))
   self)
  (:stamp
   (&optional __stamp)
   (if __stamp (setq _stamp __stamp)) _stamp)
  (:velocity
   (&rest __velocity)
   (if (keywordp (car __velocity))
       (send* _velocity __velocity)
     (progn
       (if __velocity (setq _velocity (car __velocity)))
       _velocity)))
  (:acceleration
   (&rest __acceleration)
   (if (keywordp (car __acceleration))
       (send* _acceleration __acceleration)
     (progn
       (if __acceleration (setq _acceleration (car __acceleration)))
       _acceleration)))
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:cap
   (&optional __cap)
   (if __cap (setq _cap __cap)) _cap)
  (:serialization-length
   ()
   (+
    ;; time _stamp
    8
    ;; geometry_msgs/Twist _velocity
    (send _velocity :serialization-length)
    ;; geometry_msgs/Accel _acceleration
    (send _acceleration :serialization-length)
    ;; float64 _latitude
    8
    ;; float64 _longitude
    8
    ;; float32 _cap
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; time _stamp
       (write-long (send _stamp :sec) s) (write-long (send _stamp :nsec) s)
     ;; geometry_msgs/Twist _velocity
       (send _velocity :serialize s)
     ;; geometry_msgs/Accel _acceleration
       (send _acceleration :serialize s)
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float32 _cap
       (sys::poke _cap (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; time _stamp
     (send _stamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _stamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; geometry_msgs/Twist _velocity
     (send _velocity :deserialize buf ptr-) (incf ptr- (send _velocity :serialization-length))
   ;; geometry_msgs/Accel _acceleration
     (send _acceleration :deserialize buf ptr-) (incf ptr- (send _acceleration :serialization-length))
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _longitude
     (setq _longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float32 _cap
     (setq _cap (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get project_s_msgs::EgoData :md5sum-) "d78259856396c0f87777d9538bea5d37")
(setf (get project_s_msgs::EgoData :datatype-) "project_s_msgs/EgoData")
(setf (get project_s_msgs::EgoData :definition-)
      "time stamp

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



(provide :project_s_msgs/EgoData "d78259856396c0f87777d9538bea5d37")


