;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::fromMissionServer)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'fromMissionServer (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER")
  (make-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))

(in-package "ROS")
;;//! \htmlinclude fromMissionServer.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*ARDUINOMODE*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*ARDUINOMODE* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*ARDUINOMODE* 0)
(intern "*TRANSPARENTMODE*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*TRANSPARENTMODE* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*TRANSPARENTMODE* 1)
(intern "*BYFIELDMODE*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*BYFIELDMODE* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*BYFIELDMODE* 2)
(intern "*MISSIONSEARCHERROR*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*MISSIONSEARCHERROR* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*MISSIONSEARCHERROR* 1)
(intern "*NOMISSIONAVAILABLE*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*NOMISSIONAVAILABLE* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*NOMISSIONAVAILABLE* 2)
(intern "*MISSIONASSIGNMENTERROR*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*MISSIONASSIGNMENTERROR* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*MISSIONASSIGNMENTERROR* 3)
(intern "*SERVERERROR*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*SERVERERROR* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*SERVERERROR* 4)
(intern "*UNAVAILABLE*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*UNAVAILABLE* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*UNAVAILABLE* 0)
(intern "*WAITING*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*WAITING* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*WAITING* 1)
(intern "*NAVIGATING*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*NAVIGATING* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*NAVIGATING* 2)
(intern "*ENDING*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*ENDING* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*ENDING* 3)
(intern "*SLEEPING*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*SLEEPING* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*SLEEPING* 4)
(intern "*WAKEUP*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*WAKEUP* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*WAKEUP* 5)
(intern "*NAVIGATE*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*NAVIGATE* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*NAVIGATE* 6)
(intern "*ENDOFNAV*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*ENDOFNAV* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*ENDOFNAV* 7)
(intern "*SLEEP*" (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(shadow '*SLEEP* (find-package "PROJECT_S_MSGS::FROMMISSIONSERVER"))
(defconstant project_s_msgs::fromMissionServer::*SLEEP* 8)
(defclass project_s_msgs::fromMissionServer
  :super ros::object
  :slots (_header _mode _err _msg _mission _idUser _errCode _idCar _stateCmd _lat _lng _url _data ))

(defmethod project_s_msgs::fromMissionServer
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:mode __mode) 0)
    ((:err __err) nil)
    ((:msg __msg) "")
    ((:mission __mission) 0)
    ((:idUser __idUser) 0)
    ((:errCode __errCode) 0)
    ((:idCar __idCar) 0)
    ((:stateCmd __stateCmd) 0)
    ((:lat __lat) "")
    ((:lng __lng) "")
    ((:url __url) "")
    ((:data __data) "")
    )
   (send-super :init)
   (setq _header __header)
   (setq _mode (round __mode))
   (setq _err __err)
   (setq _msg (string __msg))
   (setq _mission (round __mission))
   (setq _idUser (round __idUser))
   (setq _errCode (round __errCode))
   (setq _idCar (round __idCar))
   (setq _stateCmd (round __stateCmd))
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
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:err
   (&optional __err)
   (if __err (setq _err __err)) _err)
  (:msg
   (&optional __msg)
   (if __msg (setq _msg __msg)) _msg)
  (:mission
   (&optional __mission)
   (if __mission (setq _mission __mission)) _mission)
  (:idUser
   (&optional __idUser)
   (if __idUser (setq _idUser __idUser)) _idUser)
  (:errCode
   (&optional __errCode)
   (if __errCode (setq _errCode __errCode)) _errCode)
  (:idCar
   (&optional __idCar)
   (if __idCar (setq _idCar __idCar)) _idCar)
  (:stateCmd
   (&optional __stateCmd)
   (if __stateCmd (setq _stateCmd __stateCmd)) _stateCmd)
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
    ;; uint8 _mode
    1
    ;; bool _err
    1
    ;; string _msg
    4 (length _msg)
    ;; uint8 _mission
    1
    ;; uint32 _idUser
    4
    ;; uint8 _errCode
    1
    ;; uint32 _idCar
    4
    ;; uint8 _stateCmd
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
     ;; uint8 _mode
       (write-byte _mode s)
     ;; bool _err
       (if _err (write-byte -1 s) (write-byte 0 s))
     ;; string _msg
       (write-long (length _msg) s) (princ _msg s)
     ;; uint8 _mission
       (write-byte _mission s)
     ;; uint32 _idUser
       (write-long _idUser s)
     ;; uint8 _errCode
       (write-byte _errCode s)
     ;; uint32 _idCar
       (write-long _idCar s)
     ;; uint8 _stateCmd
       (write-byte _stateCmd s)
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
   ;; uint8 _mode
     (setq _mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _err
     (setq _err (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _msg
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _msg (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _mission
     (setq _mission (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32 _idUser
     (setq _idUser (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _errCode
     (setq _errCode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32 _idCar
     (setq _idCar (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _stateCmd
     (setq _stateCmd (sys::peek buf ptr- :char)) (incf ptr- 1)
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

(setf (get project_s_msgs::fromMissionServer :md5sum-) "1c5f3191cc67c5d61eb019c231f37790")
(setf (get project_s_msgs::fromMissionServer :datatype-) "project_s_msgs/fromMissionServer")
(setf (get project_s_msgs::fromMissionServer :definition-)
      "Header header				# Contains ROS timestamp, sequence & frame id

uint8 mode
uint8 ARDUINOMODE=0
uint8 TRANSPARENTMODE=1
uint8 BYFIELDMODE=2

bool err				# Server msg error: false, true
string msg				# text message (for information only)
uint8 mission				# Track number
uint32 idUser				# User Identification Number

uint8 errCode				
uint8 MissionSearchError=1
uint8 NoMissionAvailable=2
uint8 MissionAssignmentError=3
uint8 ServerError=4

uint32 idCar				# Car Identification Number

uint8 stateCmd				# Car status echo & command from server
uint8 UNAVAILABLE=0
uint8 WAITING=1
uint8 NAVIGATING=2
uint8 ENDING=3
uint8 SLEEPING=4
uint8 WAKEUP=5
uint8 NAVIGATE=6
uint8 ENDOFNAV=7
uint8 SLEEP=8

string lat				# Car position latitude
string lng				# Car position longitude

string url				# Echo of the URL Request
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



(provide :project_s_msgs/fromMissionServer "1c5f3191cc67c5d61eb019c231f37790")


