;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::point_GPS)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'point_GPS (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::POINT_GPS")
  (make-package "PROJECT_S_MSGS::POINT_GPS"))

(in-package "ROS")
;;//! \htmlinclude point_GPS.msg.html


(defclass project_s_msgs::point_GPS
  :super ros::object
  :slots (_latitude _longitude _offset ))

(defmethod project_s_msgs::point_GPS
  (:init
   (&key
    ((:latitude __latitude) 0.0)
    ((:longitude __longitude) 0.0)
    ((:offset __offset) 0.0)
    )
   (send-super :init)
   (setq _latitude (float __latitude))
   (setq _longitude (float __longitude))
   (setq _offset (float __offset))
   self)
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:offset
   (&optional __offset)
   (if __offset (setq _offset __offset)) _offset)
  (:serialization-length
   ()
   (+
    ;; float64 _latitude
    8
    ;; float64 _longitude
    8
    ;; float32 _offset
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float32 _offset
       (sys::poke _offset (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _longitude
     (setq _longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float32 _offset
     (setq _offset (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get project_s_msgs::point_GPS :md5sum-) "a1ce28cd8c783030409f079a32beb33d")
(setf (get project_s_msgs::point_GPS :datatype-) "project_s_msgs/point_GPS")
(setf (get project_s_msgs::point_GPS :definition-)
      "float64 latitude
float64 longitude
float32 offset


")



(provide :project_s_msgs/point_GPS "a1ce28cd8c783030409f079a32beb33d")


