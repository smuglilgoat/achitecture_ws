;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::traffic_sign)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'traffic_sign (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::TRAFFIC_SIGN")
  (make-package "PROJECT_S_MSGS::TRAFFIC_SIGN"))

(in-package "ROS")
;;//! \htmlinclude traffic_sign.msg.html


(defclass project_s_msgs::traffic_sign
  :super ros::object
  :slots (_offset _Sign_Type _Value _Lane _Sign_Location _latitude _longitude ))

(defmethod project_s_msgs::traffic_sign
  (:init
   (&key
    ((:offset __offset) 0.0)
    ((:Sign_Type __Sign_Type) 0)
    ((:Value __Value) 0)
    ((:Lane __Lane) 0)
    ((:Sign_Location __Sign_Location) 0)
    ((:latitude __latitude) 0.0)
    ((:longitude __longitude) 0.0)
    )
   (send-super :init)
   (setq _offset (float __offset))
   (setq _Sign_Type (round __Sign_Type))
   (setq _Value (round __Value))
   (setq _Lane (round __Lane))
   (setq _Sign_Location (round __Sign_Location))
   (setq _latitude (float __latitude))
   (setq _longitude (float __longitude))
   self)
  (:offset
   (&optional __offset)
   (if __offset (setq _offset __offset)) _offset)
  (:Sign_Type
   (&optional __Sign_Type)
   (if __Sign_Type (setq _Sign_Type __Sign_Type)) _Sign_Type)
  (:Value
   (&optional __Value)
   (if __Value (setq _Value __Value)) _Value)
  (:Lane
   (&optional __Lane)
   (if __Lane (setq _Lane __Lane)) _Lane)
  (:Sign_Location
   (&optional __Sign_Location)
   (if __Sign_Location (setq _Sign_Location __Sign_Location)) _Sign_Location)
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:serialization-length
   ()
   (+
    ;; float32 _offset
    4
    ;; uint8 _Sign_Type
    1
    ;; uint8 _Value
    1
    ;; uint8 _Lane
    1
    ;; uint8 _Sign_Location
    1
    ;; float64 _latitude
    8
    ;; float64 _longitude
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _offset
       (sys::poke _offset (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint8 _Sign_Type
       (write-byte _Sign_Type s)
     ;; uint8 _Value
       (write-byte _Value s)
     ;; uint8 _Lane
       (write-byte _Lane s)
     ;; uint8 _Sign_Location
       (write-byte _Sign_Location s)
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _offset
     (setq _offset (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint8 _Sign_Type
     (setq _Sign_Type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _Value
     (setq _Value (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _Lane
     (setq _Lane (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _Sign_Location
     (setq _Sign_Location (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _longitude
     (setq _longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get project_s_msgs::traffic_sign :md5sum-) "d26397acef9db1aa738fc0768aa46dd8")
(setf (get project_s_msgs::traffic_sign :datatype-) "project_s_msgs/traffic_sign")
(setf (get project_s_msgs::traffic_sign :definition-)
      "float32 offset
uint8 Sign_Type
uint8 Value
uint8 Lane
uint8 Sign_Location
float64 latitude
float64 longitude




")



(provide :project_s_msgs/traffic_sign "d26397acef9db1aa738fc0768aa46dd8")


