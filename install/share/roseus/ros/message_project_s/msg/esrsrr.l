;; Auto-generated. Do not edit!


(when (boundp 'message_project_s::esrsrr)
  (if (not (find-package "MESSAGE_PROJECT_S"))
    (make-package "MESSAGE_PROJECT_S"))
  (shadow 'esrsrr (find-package "MESSAGE_PROJECT_S")))
(unless (find-package "MESSAGE_PROJECT_S::ESRSRR")
  (make-package "MESSAGE_PROJECT_S::ESRSRR"))

(in-package "ROS")
;;//! \htmlinclude esrsrr.msg.html


(defclass message_project_s::esrsrr
  :super ros::object
  :slots (_stampsrr _stampesr _seqesr _can_dsp_ts ))

(defmethod message_project_s::esrsrr
  (:init
   (&key
    ((:stampsrr __stampsrr) (instance ros::time :init))
    ((:stampesr __stampesr) (instance ros::time :init))
    ((:seqesr __seqesr) 0)
    ((:can_dsp_ts __can_dsp_ts) 0)
    )
   (send-super :init)
   (setq _stampsrr __stampsrr)
   (setq _stampesr __stampesr)
   (setq _seqesr (round __seqesr))
   (setq _can_dsp_ts (round __can_dsp_ts))
   self)
  (:stampsrr
   (&optional __stampsrr)
   (if __stampsrr (setq _stampsrr __stampsrr)) _stampsrr)
  (:stampesr
   (&optional __stampesr)
   (if __stampesr (setq _stampesr __stampesr)) _stampesr)
  (:seqesr
   (&optional __seqesr)
   (if __seqesr (setq _seqesr __seqesr)) _seqesr)
  (:can_dsp_ts
   (&optional __can_dsp_ts)
   (if __can_dsp_ts (setq _can_dsp_ts __can_dsp_ts)) _can_dsp_ts)
  (:serialization-length
   ()
   (+
    ;; time _stampsrr
    8
    ;; time _stampesr
    8
    ;; uint32 _seqesr
    4
    ;; uint32 _can_dsp_ts
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; time _stampsrr
       (write-long (send _stampsrr :sec) s) (write-long (send _stampsrr :nsec) s)
     ;; time _stampesr
       (write-long (send _stampesr :sec) s) (write-long (send _stampesr :nsec) s)
     ;; uint32 _seqesr
       (write-long _seqesr s)
     ;; uint32 _can_dsp_ts
       (write-long _can_dsp_ts s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; time _stampsrr
     (send _stampsrr :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _stampsrr :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; time _stampesr
     (send _stampesr :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _stampesr :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _seqesr
     (setq _seqesr (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _can_dsp_ts
     (setq _can_dsp_ts (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get message_project_s::esrsrr :md5sum-) "67e39e1d269819b2e9c170bc6fb5fbb5")
(setf (get message_project_s::esrsrr :datatype-) "message_project_s/esrsrr")
(setf (get message_project_s::esrsrr :definition-)
      "
time stampsrr
time stampesr
uint32 seqesr
uint32 can_dsp_ts

")



(provide :message_project_s/esrsrr "67e39e1d269819b2e9c170bc6fb5fbb5")


