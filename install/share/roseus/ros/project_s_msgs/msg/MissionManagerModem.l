;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::MissionManagerModem)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'MissionManagerModem (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::MISSIONMANAGERMODEM")
  (make-package "PROJECT_S_MSGS::MISSIONMANAGERMODEM"))

(in-package "ROS")
;;//! \htmlinclude MissionManagerModem.msg.html


(defclass project_s_msgs::MissionManagerModem
  :super ros::object
  :slots (_stamp _request ))

(defmethod project_s_msgs::MissionManagerModem
  (:init
   (&key
    ((:stamp __stamp) (instance ros::time :init))
    ((:request __request) 0.0)
    )
   (send-super :init)
   (setq _stamp __stamp)
   (setq _request (float __request))
   self)
  (:stamp
   (&optional __stamp)
   (if __stamp (setq _stamp __stamp)) _stamp)
  (:request
   (&optional __request)
   (if __request (setq _request __request)) _request)
  (:serialization-length
   ()
   (+
    ;; time _stamp
    8
    ;; float32 _request
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; time _stamp
       (write-long (send _stamp :sec) s) (write-long (send _stamp :nsec) s)
     ;; float32 _request
       (sys::poke _request (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; time _stamp
     (send _stamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _stamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _request
     (setq _request (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get project_s_msgs::MissionManagerModem :md5sum-) "37e4d8b8bd95addccb35ddd346779b1f")
(setf (get project_s_msgs::MissionManagerModem :datatype-) "project_s_msgs/MissionManagerModem")
(setf (get project_s_msgs::MissionManagerModem :definition-)
      "time stamp

float32 request


")



(provide :project_s_msgs/MissionManagerModem "37e4d8b8bd95addccb35ddd346779b1f")


