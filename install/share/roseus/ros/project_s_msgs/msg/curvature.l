;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::curvature)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'curvature (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::CURVATURE")
  (make-package "PROJECT_S_MSGS::CURVATURE"))

(in-package "ROS")
;;//! \htmlinclude curvature.msg.html


(defclass project_s_msgs::curvature
  :super ros::object
  :slots (_offset _value ))

(defmethod project_s_msgs::curvature
  (:init
   (&key
    ((:offset __offset) 0.0)
    ((:value __value) 0.0)
    )
   (send-super :init)
   (setq _offset (float __offset))
   (setq _value (float __value))
   self)
  (:offset
   (&optional __offset)
   (if __offset (setq _offset __offset)) _offset)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; float32 _offset
    4
    ;; float32 _value
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _offset
       (sys::poke _offset (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _value
       (sys::poke _value (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _offset
     (setq _offset (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _value
     (setq _value (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get project_s_msgs::curvature :md5sum-) "a89e5e12d6932ebdd9f391c7e9fea59b")
(setf (get project_s_msgs::curvature :datatype-) "project_s_msgs/curvature")
(setf (get project_s_msgs::curvature :definition-)
      "float32 offset
float32 value

")



(provide :project_s_msgs/curvature "a89e5e12d6932ebdd9f391c7e9fea59b")


