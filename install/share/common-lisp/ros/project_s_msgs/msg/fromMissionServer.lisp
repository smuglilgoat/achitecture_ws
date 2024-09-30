; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude fromMissionServer.msg.html

(cl:defclass <fromMissionServer> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (mode
    :reader mode
    :initarg :mode
    :type cl:fixnum
    :initform 0)
   (err
    :reader err
    :initarg :err
    :type cl:boolean
    :initform cl:nil)
   (msg
    :reader msg
    :initarg :msg
    :type cl:string
    :initform "")
   (mission
    :reader mission
    :initarg :mission
    :type cl:fixnum
    :initform 0)
   (idUser
    :reader idUser
    :initarg :idUser
    :type cl:integer
    :initform 0)
   (errCode
    :reader errCode
    :initarg :errCode
    :type cl:fixnum
    :initform 0)
   (idCar
    :reader idCar
    :initarg :idCar
    :type cl:integer
    :initform 0)
   (stateCmd
    :reader stateCmd
    :initarg :stateCmd
    :type cl:fixnum
    :initform 0)
   (lat
    :reader lat
    :initarg :lat
    :type cl:string
    :initform "")
   (lng
    :reader lng
    :initarg :lng
    :type cl:string
    :initform "")
   (url
    :reader url
    :initarg :url
    :type cl:string
    :initform "")
   (data
    :reader data
    :initarg :data
    :type cl:string
    :initform ""))
)

(cl:defclass fromMissionServer (<fromMissionServer>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <fromMissionServer>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'fromMissionServer)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<fromMissionServer> is deprecated: use project_s_msgs-msg:fromMissionServer instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:mode-val is deprecated.  Use project_s_msgs-msg:mode instead.")
  (mode m))

(cl:ensure-generic-function 'err-val :lambda-list '(m))
(cl:defmethod err-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:err-val is deprecated.  Use project_s_msgs-msg:err instead.")
  (err m))

(cl:ensure-generic-function 'msg-val :lambda-list '(m))
(cl:defmethod msg-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:msg-val is deprecated.  Use project_s_msgs-msg:msg instead.")
  (msg m))

(cl:ensure-generic-function 'mission-val :lambda-list '(m))
(cl:defmethod mission-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:mission-val is deprecated.  Use project_s_msgs-msg:mission instead.")
  (mission m))

(cl:ensure-generic-function 'idUser-val :lambda-list '(m))
(cl:defmethod idUser-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:idUser-val is deprecated.  Use project_s_msgs-msg:idUser instead.")
  (idUser m))

(cl:ensure-generic-function 'errCode-val :lambda-list '(m))
(cl:defmethod errCode-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:errCode-val is deprecated.  Use project_s_msgs-msg:errCode instead.")
  (errCode m))

(cl:ensure-generic-function 'idCar-val :lambda-list '(m))
(cl:defmethod idCar-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:idCar-val is deprecated.  Use project_s_msgs-msg:idCar instead.")
  (idCar m))

(cl:ensure-generic-function 'stateCmd-val :lambda-list '(m))
(cl:defmethod stateCmd-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:stateCmd-val is deprecated.  Use project_s_msgs-msg:stateCmd instead.")
  (stateCmd m))

(cl:ensure-generic-function 'lat-val :lambda-list '(m))
(cl:defmethod lat-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:lat-val is deprecated.  Use project_s_msgs-msg:lat instead.")
  (lat m))

(cl:ensure-generic-function 'lng-val :lambda-list '(m))
(cl:defmethod lng-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:lng-val is deprecated.  Use project_s_msgs-msg:lng instead.")
  (lng m))

(cl:ensure-generic-function 'url-val :lambda-list '(m))
(cl:defmethod url-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:url-val is deprecated.  Use project_s_msgs-msg:url instead.")
  (url m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <fromMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:data-val is deprecated.  Use project_s_msgs-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<fromMissionServer>)))
    "Constants for message type '<fromMissionServer>"
  '((:ARDUINOMODE . 0)
    (:TRANSPARENTMODE . 1)
    (:BYFIELDMODE . 2)
    (:MISSIONSEARCHERROR . 1)
    (:NOMISSIONAVAILABLE . 2)
    (:MISSIONASSIGNMENTERROR . 3)
    (:SERVERERROR . 4)
    (:UNAVAILABLE . 0)
    (:WAITING . 1)
    (:NAVIGATING . 2)
    (:ENDING . 3)
    (:SLEEPING . 4)
    (:WAKEUP . 5)
    (:NAVIGATE . 6)
    (:ENDOFNAV . 7)
    (:SLEEP . 8))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'fromMissionServer)))
    "Constants for message type 'fromMissionServer"
  '((:ARDUINOMODE . 0)
    (:TRANSPARENTMODE . 1)
    (:BYFIELDMODE . 2)
    (:MISSIONSEARCHERROR . 1)
    (:NOMISSIONAVAILABLE . 2)
    (:MISSIONASSIGNMENTERROR . 3)
    (:SERVERERROR . 4)
    (:UNAVAILABLE . 0)
    (:WAITING . 1)
    (:NAVIGATING . 2)
    (:ENDING . 3)
    (:SLEEPING . 4)
    (:WAKEUP . 5)
    (:NAVIGATE . 6)
    (:ENDOFNAV . 7)
    (:SLEEP . 8))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <fromMissionServer>) ostream)
  "Serializes a message object of type '<fromMissionServer>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'err) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'msg))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mission)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idUser)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idUser)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idUser)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idUser)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'errCode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idCar)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idCar)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idCar)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idCar)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'stateCmd)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'lat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'lat))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'lng))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'lng))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'url))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'url))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <fromMissionServer>) istream)
  "Deserializes a message object of type '<fromMissionServer>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'err) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'msg) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'msg) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mission)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idUser)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idUser)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idUser)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idUser)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'errCode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idCar)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idCar)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idCar)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idCar)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'stateCmd)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'lat) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'lat) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'lng) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'lng) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'url) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'url) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'data) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'data) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<fromMissionServer>)))
  "Returns string type for a message object of type '<fromMissionServer>"
  "project_s_msgs/fromMissionServer")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'fromMissionServer)))
  "Returns string type for a message object of type 'fromMissionServer"
  "project_s_msgs/fromMissionServer")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<fromMissionServer>)))
  "Returns md5sum for a message object of type '<fromMissionServer>"
  "1c5f3191cc67c5d61eb019c231f37790")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'fromMissionServer)))
  "Returns md5sum for a message object of type 'fromMissionServer"
  "1c5f3191cc67c5d61eb019c231f37790")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<fromMissionServer>)))
  "Returns full string definition for message of type '<fromMissionServer>"
  (cl:format cl:nil "Header header				# Contains ROS timestamp, sequence & frame id~%~%uint8 mode~%uint8 ARDUINOMODE=0~%uint8 TRANSPARENTMODE=1~%uint8 BYFIELDMODE=2~%~%bool err				# Server msg error: false, true~%string msg				# text message (for information only)~%uint8 mission				# Track number~%uint32 idUser				# User Identification Number~%~%uint8 errCode				~%uint8 MissionSearchError=1~%uint8 NoMissionAvailable=2~%uint8 MissionAssignmentError=3~%uint8 ServerError=4~%~%uint32 idCar				# Car Identification Number~%~%uint8 stateCmd				# Car status echo & command from server~%uint8 UNAVAILABLE=0~%uint8 WAITING=1~%uint8 NAVIGATING=2~%uint8 ENDING=3~%uint8 SLEEPING=4~%uint8 WAKEUP=5~%uint8 NAVIGATE=6~%uint8 ENDOFNAV=7~%uint8 SLEEP=8~%~%string lat				# Car position latitude~%string lng				# Car position longitude~%~%string url				# Echo of the URL Request~%string data~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'fromMissionServer)))
  "Returns full string definition for message of type 'fromMissionServer"
  (cl:format cl:nil "Header header				# Contains ROS timestamp, sequence & frame id~%~%uint8 mode~%uint8 ARDUINOMODE=0~%uint8 TRANSPARENTMODE=1~%uint8 BYFIELDMODE=2~%~%bool err				# Server msg error: false, true~%string msg				# text message (for information only)~%uint8 mission				# Track number~%uint32 idUser				# User Identification Number~%~%uint8 errCode				~%uint8 MissionSearchError=1~%uint8 NoMissionAvailable=2~%uint8 MissionAssignmentError=3~%uint8 ServerError=4~%~%uint32 idCar				# Car Identification Number~%~%uint8 stateCmd				# Car status echo & command from server~%uint8 UNAVAILABLE=0~%uint8 WAITING=1~%uint8 NAVIGATING=2~%uint8 ENDING=3~%uint8 SLEEPING=4~%uint8 WAKEUP=5~%uint8 NAVIGATE=6~%uint8 ENDOFNAV=7~%uint8 SLEEP=8~%~%string lat				# Car position latitude~%string lng				# Car position longitude~%~%string url				# Echo of the URL Request~%string data~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <fromMissionServer>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     4 (cl:length (cl:slot-value msg 'msg))
     1
     4
     1
     4
     1
     4 (cl:length (cl:slot-value msg 'lat))
     4 (cl:length (cl:slot-value msg 'lng))
     4 (cl:length (cl:slot-value msg 'url))
     4 (cl:length (cl:slot-value msg 'data))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <fromMissionServer>))
  "Converts a ROS message object to a list"
  (cl:list 'fromMissionServer
    (cl:cons ':header (header msg))
    (cl:cons ':mode (mode msg))
    (cl:cons ':err (err msg))
    (cl:cons ':msg (msg msg))
    (cl:cons ':mission (mission msg))
    (cl:cons ':idUser (idUser msg))
    (cl:cons ':errCode (errCode msg))
    (cl:cons ':idCar (idCar msg))
    (cl:cons ':stateCmd (stateCmd msg))
    (cl:cons ':lat (lat msg))
    (cl:cons ':lng (lng msg))
    (cl:cons ':url (url msg))
    (cl:cons ':data (data msg))
))
