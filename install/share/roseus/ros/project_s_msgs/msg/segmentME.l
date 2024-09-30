;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::segmentME)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'segmentME (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::SEGMENTME")
  (make-package "PROJECT_S_MSGS::SEGMENTME"))

(in-package "ROS")
;;//! \htmlinclude segmentME.msg.html


(defclass project_s_msgs::segmentME
  :super ros::object
  :slots (_NbrSpot _offset_debut _offset_fin ))

(defmethod project_s_msgs::segmentME
  (:init
   (&key
    ((:NbrSpot __NbrSpot) 0)
    ((:offset_debut __offset_debut) 0.0)
    ((:offset_fin __offset_fin) 0.0)
    )
   (send-super :init)
   (setq _NbrSpot (round __NbrSpot))
   (setq _offset_debut (float __offset_debut))
   (setq _offset_fin (float __offset_fin))
   self)
  (:NbrSpot
   (&optional __NbrSpot)
   (if __NbrSpot (setq _NbrSpot __NbrSpot)) _NbrSpot)
  (:offset_debut
   (&optional __offset_debut)
   (if __offset_debut (setq _offset_debut __offset_debut)) _offset_debut)
  (:offset_fin
   (&optional __offset_fin)
   (if __offset_fin (setq _offset_fin __offset_fin)) _offset_fin)
  (:serialization-length
   ()
   (+
    ;; uint32 _NbrSpot
    4
    ;; float32 _offset_debut
    4
    ;; float32 _offset_fin
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _NbrSpot
       (write-long _NbrSpot s)
     ;; float32 _offset_debut
       (sys::poke _offset_debut (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _offset_fin
       (sys::poke _offset_fin (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _NbrSpot
     (setq _NbrSpot (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _offset_debut
     (setq _offset_debut (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _offset_fin
     (setq _offset_fin (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get project_s_msgs::segmentME :md5sum-) "db8cd94b2ab5d013db8e670f53a36229")
(setf (get project_s_msgs::segmentME :datatype-) "project_s_msgs/segmentME")
(setf (get project_s_msgs::segmentME :definition-)
      "uint32 NbrSpot
float32 offset_debut
float32 offset_fin



")



(provide :project_s_msgs/segmentME "db8cd94b2ab5d013db8e670f53a36229")


