;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ehNbrLineCoordGeo)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ehNbrLineCoordGeo (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::EHNBRLINECOORDGEO")
  (make-package "PROJECT_S_MSGS::EHNBRLINECOORDGEO"))

(in-package "ROS")
;;//! \htmlinclude ehNbrLineCoordGeo.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::ehNbrLineCoordGeo
  :super ros::object
  :slots (_Nbr _offset ))

(defmethod project_s_msgs::ehNbrLineCoordGeo
  (:init
   (&key
    ((:Nbr __Nbr) (instance std_msgs::UInt8 :init))
    ((:offset __offset) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _Nbr __Nbr)
   (setq _offset __offset)
   self)
  (:Nbr
   (&rest __Nbr)
   (if (keywordp (car __Nbr))
       (send* _Nbr __Nbr)
     (progn
       (if __Nbr (setq _Nbr (car __Nbr)))
       _Nbr)))
  (:offset
   (&rest __offset)
   (if (keywordp (car __offset))
       (send* _offset __offset)
     (progn
       (if __offset (setq _offset (car __offset)))
       _offset)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/UInt8 _Nbr
    (send _Nbr :serialization-length)
    ;; std_msgs/Float32 _offset
    (send _offset :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/UInt8 _Nbr
       (send _Nbr :serialize s)
     ;; std_msgs/Float32 _offset
       (send _offset :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/UInt8 _Nbr
     (send _Nbr :deserialize buf ptr-) (incf ptr- (send _Nbr :serialization-length))
   ;; std_msgs/Float32 _offset
     (send _offset :deserialize buf ptr-) (incf ptr- (send _offset :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ehNbrLineCoordGeo :md5sum-) "ba129a5215116e7dd0de7b78069aec8a")
(setf (get project_s_msgs::ehNbrLineCoordGeo :datatype-) "project_s_msgs/ehNbrLineCoordGeo")
(setf (get project_s_msgs::ehNbrLineCoordGeo :definition-)
      "std_msgs/UInt8 Nbr
std_msgs/Float32 offset




================================================================================
MSG: std_msgs/UInt8
uint8 data

================================================================================
MSG: std_msgs/Float32
float32 data
")



(provide :project_s_msgs/ehNbrLineCoordGeo "ba129a5215116e7dd0de7b78069aec8a")


