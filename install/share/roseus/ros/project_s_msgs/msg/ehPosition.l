;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ehPosition)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ehPosition (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::EHPOSITION")
  (make-package "PROJECT_S_MSGS::EHPOSITION"))

(in-package "ROS")
;;//! \htmlinclude ehPosition.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::ehPosition
  :super ros::object
  :slots (_header _id _offset _latitude _longitude _cap _agePosition _speed _relativeHeading _currentLane ))

(defmethod project_s_msgs::ehPosition
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:offset __offset) (instance std_msgs::Float32 :init))
    ((:latitude __latitude) 0.0)
    ((:longitude __longitude) 0.0)
    ((:cap __cap) (instance std_msgs::Float32 :init))
    ((:agePosition __agePosition) (instance std_msgs::UInt16 :init))
    ((:speed __speed) (instance std_msgs::Float32 :init))
    ((:relativeHeading __relativeHeading) (instance std_msgs::Float32 :init))
    ((:currentLane __currentLane) (instance std_msgs::UInt8 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _offset __offset)
   (setq _latitude (float __latitude))
   (setq _longitude (float __longitude))
   (setq _cap __cap)
   (setq _agePosition __agePosition)
   (setq _speed __speed)
   (setq _relativeHeading __relativeHeading)
   (setq _currentLane __currentLane)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:id
   (&rest __id)
   (if (keywordp (car __id))
       (send* _id __id)
     (progn
       (if __id (setq _id (car __id)))
       _id)))
  (:offset
   (&rest __offset)
   (if (keywordp (car __offset))
       (send* _offset __offset)
     (progn
       (if __offset (setq _offset (car __offset)))
       _offset)))
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:cap
   (&rest __cap)
   (if (keywordp (car __cap))
       (send* _cap __cap)
     (progn
       (if __cap (setq _cap (car __cap)))
       _cap)))
  (:agePosition
   (&rest __agePosition)
   (if (keywordp (car __agePosition))
       (send* _agePosition __agePosition)
     (progn
       (if __agePosition (setq _agePosition (car __agePosition)))
       _agePosition)))
  (:speed
   (&rest __speed)
   (if (keywordp (car __speed))
       (send* _speed __speed)
     (progn
       (if __speed (setq _speed (car __speed)))
       _speed)))
  (:relativeHeading
   (&rest __relativeHeading)
   (if (keywordp (car __relativeHeading))
       (send* _relativeHeading __relativeHeading)
     (progn
       (if __relativeHeading (setq _relativeHeading (car __relativeHeading)))
       _relativeHeading)))
  (:currentLane
   (&rest __currentLane)
   (if (keywordp (car __currentLane))
       (send* _currentLane __currentLane)
     (progn
       (if __currentLane (setq _currentLane (car __currentLane)))
       _currentLane)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/Float32 _offset
    (send _offset :serialization-length)
    ;; float64 _latitude
    8
    ;; float64 _longitude
    8
    ;; std_msgs/Float32 _cap
    (send _cap :serialization-length)
    ;; std_msgs/UInt16 _agePosition
    (send _agePosition :serialization-length)
    ;; std_msgs/Float32 _speed
    (send _speed :serialization-length)
    ;; std_msgs/Float32 _relativeHeading
    (send _relativeHeading :serialization-length)
    ;; std_msgs/UInt8 _currentLane
    (send _currentLane :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/Float32 _offset
       (send _offset :serialize s)
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; std_msgs/Float32 _cap
       (send _cap :serialize s)
     ;; std_msgs/UInt16 _agePosition
       (send _agePosition :serialize s)
     ;; std_msgs/Float32 _speed
       (send _speed :serialize s)
     ;; std_msgs/Float32 _relativeHeading
       (send _relativeHeading :serialize s)
     ;; std_msgs/UInt8 _currentLane
       (send _currentLane :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/Float32 _offset
     (send _offset :deserialize buf ptr-) (incf ptr- (send _offset :serialization-length))
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _longitude
     (setq _longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; std_msgs/Float32 _cap
     (send _cap :deserialize buf ptr-) (incf ptr- (send _cap :serialization-length))
   ;; std_msgs/UInt16 _agePosition
     (send _agePosition :deserialize buf ptr-) (incf ptr- (send _agePosition :serialization-length))
   ;; std_msgs/Float32 _speed
     (send _speed :deserialize buf ptr-) (incf ptr- (send _speed :serialization-length))
   ;; std_msgs/Float32 _relativeHeading
     (send _relativeHeading :deserialize buf ptr-) (incf ptr- (send _relativeHeading :serialization-length))
   ;; std_msgs/UInt8 _currentLane
     (send _currentLane :deserialize buf ptr-) (incf ptr- (send _currentLane :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ehPosition :md5sum-) "834273fcaebed780b99909cf00aa6ac8")
(setf (get project_s_msgs::ehPosition :datatype-) "project_s_msgs/ehPosition")
(setf (get project_s_msgs::ehPosition :definition-)
      "Header header
std_msgs/UInt8 id

#std_msgs/UInt8 indexPath
std_msgs/Float32 offset
float64 latitude
float64 longitude
std_msgs/Float32 cap
std_msgs/UInt16 agePosition
std_msgs/Float32 speed
std_msgs/Float32 relativeHeading
std_msgs/UInt8 currentLane



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

================================================================================
MSG: std_msgs/UInt8
uint8 data

================================================================================
MSG: std_msgs/Float32
float32 data
================================================================================
MSG: std_msgs/UInt16
uint16 data

")



(provide :project_s_msgs/ehPosition "834273fcaebed780b99909cf00aa6ac8")


