;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::speed_limit)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'speed_limit (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::SPEED_LIMIT")
  (make-package "PROJECT_S_MSGS::SPEED_LIMIT"))

(in-package "ROS")
;;//! \htmlinclude speed_limit.msg.html


(defclass project_s_msgs::speed_limit
  :super ros::object
  :slots (_offset _effectiveSpeedLimit ))

(defmethod project_s_msgs::speed_limit
  (:init
   (&key
    ((:offset __offset) 0.0)
    ((:effectiveSpeedLimit __effectiveSpeedLimit) 0)
    )
   (send-super :init)
   (setq _offset (float __offset))
   (setq _effectiveSpeedLimit (round __effectiveSpeedLimit))
   self)
  (:offset
   (&optional __offset)
   (if __offset (setq _offset __offset)) _offset)
  (:effectiveSpeedLimit
   (&optional __effectiveSpeedLimit)
   (if __effectiveSpeedLimit (setq _effectiveSpeedLimit __effectiveSpeedLimit)) _effectiveSpeedLimit)
  (:serialization-length
   ()
   (+
    ;; float32 _offset
    4
    ;; uint8 _effectiveSpeedLimit
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _offset
       (sys::poke _offset (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint8 _effectiveSpeedLimit
       (write-byte _effectiveSpeedLimit s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _offset
     (setq _offset (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint8 _effectiveSpeedLimit
     (setq _effectiveSpeedLimit (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get project_s_msgs::speed_limit :md5sum-) "56f584c5e8b035f849b17a33fc0e3dfd")
(setf (get project_s_msgs::speed_limit :datatype-) "project_s_msgs/speed_limit")
(setf (get project_s_msgs::speed_limit :definition-)
      "float32 offset
uint8 effectiveSpeedLimit


")



(provide :project_s_msgs/speed_limit "56f584c5e8b035f849b17a33fc0e3dfd")


