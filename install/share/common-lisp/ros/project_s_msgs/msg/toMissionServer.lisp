; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude toMissionServer.msg.html

(cl:defclass <toMissionServer> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (idCar
    :reader idCar
    :initarg :idCar
    :type cl:integer
    :initform 0)
   (state
    :reader state
    :initarg :state
    :type cl:fixnum
    :initform 0)
   (mode
    :reader mode
    :initarg :mode
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

(cl:defclass toMissionServer (<toMissionServer>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <toMissionServer>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'toMissionServer)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<toMissionServer> is deprecated: use project_s_msgs-msg:toMissionServer instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <toMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'idCar-val :lambda-list '(m))
(cl:defmethod idCar-val ((m <toMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:idCar-val is deprecated.  Use project_s_msgs-msg:idCar instead.")
  (idCar m))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <toMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:state-val is deprecated.  Use project_s_msgs-msg:state instead.")
  (state m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <toMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:mode-val is deprecated.  Use project_s_msgs-msg:mode instead.")
  (mode m))

(cl:ensure-generic-function 'lat-val :lambda-list '(m))
(cl:defmethod lat-val ((m <toMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:lat-val is deprecated.  Use project_s_msgs-msg:lat instead.")
  (lat m))

(cl:ensure-generic-function 'lng-val :lambda-list '(m))
(cl:defmethod lng-val ((m <toMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:lng-val is deprecated.  Use project_s_msgs-msg:lng instead.")
  (lng m))

(cl:ensure-generic-function 'url-val :lambda-list '(m))
(cl:defmethod url-val ((m <toMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:url-val is deprecated.  Use project_s_msgs-msg:url instead.")
  (url m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <toMissionServer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:data-val is deprecated.  Use project_s_msgs-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<toMissionServer>)))
    "Constants for message type '<toMissionServer>"
  '((:UNAVAILABLE . 0)
    (:WAITING . 1)
    (:NAVIGATING . 2)
    (:ENDING . 3)
    (:SLEEPING . 4)
    (:ARDUINOMODE . 0)
    (:TRANSPARENTMODE . 1)
    (:BYFIELDMODE . 2))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'toMissionServer)))
    "Constants for message type 'toMissionServer"
  '((:UNAVAILABLE . 0)
    (:WAITING . 1)
    (:NAVIGATING . 2)
    (:ENDING . 3)
    (:SLEEPING . 4)
    (:ARDUINOMODE . 0)
    (:TRANSPARENTMODE . 1)
    (:BYFIELDMODE . 2))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <toMissionServer>) ostream)
  "Serializes a message object of type '<toMissionServer>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idCar)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idCar)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idCar)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idCar)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) ostream)
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <toMissionServer>) istream)
  "Deserializes a message object of type '<toMissionServer>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'idCar)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'idCar)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'idCar)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'idCar)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) (cl:read-byte istream))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<toMissionServer>)))
  "Returns string type for a message object of type '<toMissionServer>"
  "project_s_msgs/toMissionServer")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'toMissionServer)))
  "Returns string type for a message object of type 'toMissionServer"
  "project_s_msgs/toMissionServer")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<toMissionServer>)))
  "Returns md5sum for a message object of type '<toMissionServer>"
  "899b1544a91b69b2992d0ca875040be0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'toMissionServer)))
  "Returns md5sum for a message object of type 'toMissionServer"
  "899b1544a91b69b2992d0ca875040be0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<toMissionServer>)))
  "Returns full string definition for message of type '<toMissionServer>"
  (cl:format cl:nil "Header header				# Contains ROS timestamp, sequence & frame id			~%~%uint32 idCar				# Car Identification Number~%~%uint8 state				# Car status to server ~%uint8 UNAVAILABLE=0~%uint8 WAITING=1~%uint8 NAVIGATING=2~%uint8 ENDING=3~%uint8 SLEEPING=4~%~%uint8 mode~%uint8 ARDUINOMODE=0~%uint8 TRANSPARENTMODE=1~%uint8 BYFIELDMODE=2~%~%string lat				# Car position latitude~%string lng				# Car position longitude~%~%string url~%string data~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'toMissionServer)))
  "Returns full string definition for message of type 'toMissionServer"
  (cl:format cl:nil "Header header				# Contains ROS timestamp, sequence & frame id			~%~%uint32 idCar				# Car Identification Number~%~%uint8 state				# Car status to server ~%uint8 UNAVAILABLE=0~%uint8 WAITING=1~%uint8 NAVIGATING=2~%uint8 ENDING=3~%uint8 SLEEPING=4~%~%uint8 mode~%uint8 ARDUINOMODE=0~%uint8 TRANSPARENTMODE=1~%uint8 BYFIELDMODE=2~%~%string lat				# Car position latitude~%string lng				# Car position longitude~%~%string url~%string data~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <toMissionServer>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     1
     1
     4 (cl:length (cl:slot-value msg 'lat))
     4 (cl:length (cl:slot-value msg 'lng))
     4 (cl:length (cl:slot-value msg 'url))
     4 (cl:length (cl:slot-value msg 'data))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <toMissionServer>))
  "Converts a ROS message object to a list"
  (cl:list 'toMissionServer
    (cl:cons ':header (header msg))
    (cl:cons ':idCar (idCar msg))
    (cl:cons ':state (state msg))
    (cl:cons ':mode (mode msg))
    (cl:cons ':lat (lat msg))
    (cl:cons ':lng (lng msg))
    (cl:cons ':url (url msg))
    (cl:cons ':data (data msg))
))
