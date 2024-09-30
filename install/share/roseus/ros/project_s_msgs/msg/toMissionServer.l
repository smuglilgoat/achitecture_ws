;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::toMissionServer)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'toMissionServer (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::TOMISSIONSERVER")
  (make-package "PROJECT_S_MSGS::TOMISSIONSERVER"))

(in-package "ROS")
;;//! \htmlinclude toMissionServer.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*UNAVAILABLE*" (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(shadow '*UNAVAILABLE* (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(defconstant project_s_msgs::toMissionServer::*UNAVAILABLE* 0)
(intern "*WAITING*" (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(shadow '*WAITING* (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(defconstant project_s_msgs::toMissionServer::*WAITING* 1)
(intern "*NAVIGATING*" (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(shadow '*NAVIGATING* (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(defconstant project_s_msgs::toMissionServer::*NAVIGATING* 2)
(intern "*ENDING*" (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(shadow '*ENDING* (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(defconstant project_s_msgs::toMissionServer::*ENDING* 3)
(intern "*SLEEPING*" (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(shadow '*SLEEPING* (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(defconstant project_s_msgs::toMissionServer::*SLEEPING* 4)
(intern "*ARDUINOMODE*" (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(shadow '*ARDUINOMODE* (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(defconstant project_s_msgs::toMissionServer::*ARDUINOMODE* 0)
(intern "*TRANSPARENTMODE*" (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(shadow '*TRANSPARENTMODE* (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(defconstant project_s_msgs::toMissionServer::*TRANSPARENTMODE* 1)
(intern "*BYFIELDMODE*" (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(shadow '*BYFIELDMODE* (find-package "PROJECT_S_MSGS::TOMISSIONSERVER"))
(defconstant project_s_msgs::toMissionServer::*BYFIELDMODE* 2)
(defclass project_s_msgs::toMissionServer
  :super ros::object
  :slots (_header _idCar _state _mode _lat _lng _url _data ))

(defmethod project_s_msgs::toMissionServer
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:idCar __idCar) 0)
    ((:state __state) 0)
    ((:mode __mode) 0)
    ((:lat __lat) "")
    ((:lng __lng) "")
    ((:url __url) "")
    ((:data __data) "")
    )
   (send-super :init)
   (setq _header __header)
   (setq _idCar (round __idCar))
   (setq _state (round __state))
   (setq _mode (round __mode))
   (setq _lat (string __lat))
   (setq _lng (string __lng))
   (setq _url (string __url))
   (setq _data (string __data))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:idCar
   (&optional __idCar)
   (if __idCar (setq _idCar __idCar)) _idCar)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:lat
   (&optional __lat)
   (if __lat (setq _lat __lat)) _lat)
  (:lng
   (&optional __lng)
   (if __lng (setq _lng __lng)) _lng)
  (:url
   (&optional __url)
   (if __url (setq _url __url)) _url)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _idCar
    4
    ;; uint8 _state
    1
    ;; uint8 _mode
    1
    ;; string _lat
    4 (length _lat)
    ;; string _lng
    4 (length _lng)
    ;; string _url
    4 (length _url)
    ;; string _data
    4 (length _data)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _idCar
       (write-long _idCar s)
     ;; uint8 _state
       (write-byte _state s)
     ;; uint8 _mode
       (write-byte _mode s)
     ;; string _lat
       (write-long (length _lat) s) (princ _lat s)
     ;; string _lng
       (write-long (length _lng) s) (princ _lng s)
     ;; string _url
       (write-long (length _url) s) (princ _url s)
     ;; string _data
       (write-long (length _data) s) (princ _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _idCar
     (setq _idCar (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _state
     (setq _state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _mode
     (setq _mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; string _lat
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _lat (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _lng
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _lng (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _url
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _url (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _data
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _data (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get project_s_msgs::toMissionServer :md5sum-) "899b1544a91b69b2992d0ca875040be0")
(setf (get project_s_msgs::toMissionServer :datatype-) "project_s_msgs/toMissionServer")
(setf (get project_s_msgs::toMissionServer :definition-)
      "Header header				# Contains ROS timestamp, sequence & frame id			

uint32 idCar				# Car Identification Number

uint8 state				# Car status to server 
uint8 UNAVAILABLE=0
uint8 WAITING=1
uint8 NAVIGATING=2
uint8 ENDING=3
uint8 SLEEPING=4

uint8 mode
uint8 ARDUINOMODE=0
uint8 TRANSPARENTMODE=1
uint8 BYFIELDMODE=2

string lat				# Car position latitude
string lng				# Car position longitude

string url
string data

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :project_s_msgs/toMissionServer "899b1544a91b69b2992d0ca875040be0")


