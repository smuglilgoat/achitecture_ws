;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::Lane)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'Lane (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::LANE")
  (make-package "PROJECT_S_MSGS::LANE"))

(in-package "ROS")
;;//! \htmlinclude Lane.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::Lane
  :super ros::object
  :slots (_idLineRight _idLineLeft _offsetStart _offsetEnd _trafficDirection _priority _speedLimit _TrafficSign _turnOffset _turnRadius _crossRoadClass _crossRoadOffset _crossRoadPriority ))

(defmethod project_s_msgs::Lane
  (:init
   (&key
    ((:idLineRight __idLineRight) (instance std_msgs::UInt8 :init))
    ((:idLineLeft __idLineLeft) (instance std_msgs::UInt8 :init))
    ((:offsetStart __offsetStart) 0)
    ((:offsetEnd __offsetEnd) 0)
    ((:trafficDirection __trafficDirection) (instance std_msgs::UInt8 :init))
    ((:priority __priority) (instance std_msgs::UInt8 :init))
    ((:speedLimit __speedLimit) (instance std_msgs::UInt8 :init))
    ((:TrafficSign __TrafficSign) (instance std_msgs::UInt8 :init))
    ((:turnOffset __turnOffset) 0)
    ((:turnRadius __turnRadius) 0.0)
    ((:crossRoadClass __crossRoadClass) (instance std_msgs::UInt8 :init))
    ((:crossRoadOffset __crossRoadOffset) 0)
    ((:crossRoadPriority __crossRoadPriority) (instance std_msgs::UInt8 :init))
    )
   (send-super :init)
   (setq _idLineRight __idLineRight)
   (setq _idLineLeft __idLineLeft)
   (setq _offsetStart (round __offsetStart))
   (setq _offsetEnd (round __offsetEnd))
   (setq _trafficDirection __trafficDirection)
   (setq _priority __priority)
   (setq _speedLimit __speedLimit)
   (setq _TrafficSign __TrafficSign)
   (setq _turnOffset (round __turnOffset))
   (setq _turnRadius (float __turnRadius))
   (setq _crossRoadClass __crossRoadClass)
   (setq _crossRoadOffset (round __crossRoadOffset))
   (setq _crossRoadPriority __crossRoadPriority)
   self)
  (:idLineRight
   (&rest __idLineRight)
   (if (keywordp (car __idLineRight))
       (send* _idLineRight __idLineRight)
     (progn
       (if __idLineRight (setq _idLineRight (car __idLineRight)))
       _idLineRight)))
  (:idLineLeft
   (&rest __idLineLeft)
   (if (keywordp (car __idLineLeft))
       (send* _idLineLeft __idLineLeft)
     (progn
       (if __idLineLeft (setq _idLineLeft (car __idLineLeft)))
       _idLineLeft)))
  (:offsetStart
   (&optional __offsetStart)
   (if __offsetStart (setq _offsetStart __offsetStart)) _offsetStart)
  (:offsetEnd
   (&optional __offsetEnd)
   (if __offsetEnd (setq _offsetEnd __offsetEnd)) _offsetEnd)
  (:trafficDirection
   (&rest __trafficDirection)
   (if (keywordp (car __trafficDirection))
       (send* _trafficDirection __trafficDirection)
     (progn
       (if __trafficDirection (setq _trafficDirection (car __trafficDirection)))
       _trafficDirection)))
  (:priority
   (&rest __priority)
   (if (keywordp (car __priority))
       (send* _priority __priority)
     (progn
       (if __priority (setq _priority (car __priority)))
       _priority)))
  (:speedLimit
   (&rest __speedLimit)
   (if (keywordp (car __speedLimit))
       (send* _speedLimit __speedLimit)
     (progn
       (if __speedLimit (setq _speedLimit (car __speedLimit)))
       _speedLimit)))
  (:TrafficSign
   (&rest __TrafficSign)
   (if (keywordp (car __TrafficSign))
       (send* _TrafficSign __TrafficSign)
     (progn
       (if __TrafficSign (setq _TrafficSign (car __TrafficSign)))
       _TrafficSign)))
  (:turnOffset
   (&optional __turnOffset)
   (if __turnOffset (setq _turnOffset __turnOffset)) _turnOffset)
  (:turnRadius
   (&optional __turnRadius)
   (if __turnRadius (setq _turnRadius __turnRadius)) _turnRadius)
  (:crossRoadClass
   (&rest __crossRoadClass)
   (if (keywordp (car __crossRoadClass))
       (send* _crossRoadClass __crossRoadClass)
     (progn
       (if __crossRoadClass (setq _crossRoadClass (car __crossRoadClass)))
       _crossRoadClass)))
  (:crossRoadOffset
   (&optional __crossRoadOffset)
   (if __crossRoadOffset (setq _crossRoadOffset __crossRoadOffset)) _crossRoadOffset)
  (:crossRoadPriority
   (&rest __crossRoadPriority)
   (if (keywordp (car __crossRoadPriority))
       (send* _crossRoadPriority __crossRoadPriority)
     (progn
       (if __crossRoadPriority (setq _crossRoadPriority (car __crossRoadPriority)))
       _crossRoadPriority)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/UInt8 _idLineRight
    (send _idLineRight :serialization-length)
    ;; std_msgs/UInt8 _idLineLeft
    (send _idLineLeft :serialization-length)
    ;; int16 _offsetStart
    2
    ;; int16 _offsetEnd
    2
    ;; std_msgs/UInt8 _trafficDirection
    (send _trafficDirection :serialization-length)
    ;; std_msgs/UInt8 _priority
    (send _priority :serialization-length)
    ;; std_msgs/UInt8 _speedLimit
    (send _speedLimit :serialization-length)
    ;; std_msgs/UInt8 _TrafficSign
    (send _TrafficSign :serialization-length)
    ;; int16 _turnOffset
    2
    ;; float32 _turnRadius
    4
    ;; std_msgs/UInt8 _crossRoadClass
    (send _crossRoadClass :serialization-length)
    ;; int16 _crossRoadOffset
    2
    ;; std_msgs/UInt8 _crossRoadPriority
    (send _crossRoadPriority :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/UInt8 _idLineRight
       (send _idLineRight :serialize s)
     ;; std_msgs/UInt8 _idLineLeft
       (send _idLineLeft :serialize s)
     ;; int16 _offsetStart
       (write-word _offsetStart s)
     ;; int16 _offsetEnd
       (write-word _offsetEnd s)
     ;; std_msgs/UInt8 _trafficDirection
       (send _trafficDirection :serialize s)
     ;; std_msgs/UInt8 _priority
       (send _priority :serialize s)
     ;; std_msgs/UInt8 _speedLimit
       (send _speedLimit :serialize s)
     ;; std_msgs/UInt8 _TrafficSign
       (send _TrafficSign :serialize s)
     ;; int16 _turnOffset
       (write-word _turnOffset s)
     ;; float32 _turnRadius
       (sys::poke _turnRadius (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; std_msgs/UInt8 _crossRoadClass
       (send _crossRoadClass :serialize s)
     ;; int16 _crossRoadOffset
       (write-word _crossRoadOffset s)
     ;; std_msgs/UInt8 _crossRoadPriority
       (send _crossRoadPriority :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/UInt8 _idLineRight
     (send _idLineRight :deserialize buf ptr-) (incf ptr- (send _idLineRight :serialization-length))
   ;; std_msgs/UInt8 _idLineLeft
     (send _idLineLeft :deserialize buf ptr-) (incf ptr- (send _idLineLeft :serialization-length))
   ;; int16 _offsetStart
     (setq _offsetStart (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _offsetEnd
     (setq _offsetEnd (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; std_msgs/UInt8 _trafficDirection
     (send _trafficDirection :deserialize buf ptr-) (incf ptr- (send _trafficDirection :serialization-length))
   ;; std_msgs/UInt8 _priority
     (send _priority :deserialize buf ptr-) (incf ptr- (send _priority :serialization-length))
   ;; std_msgs/UInt8 _speedLimit
     (send _speedLimit :deserialize buf ptr-) (incf ptr- (send _speedLimit :serialization-length))
   ;; std_msgs/UInt8 _TrafficSign
     (send _TrafficSign :deserialize buf ptr-) (incf ptr- (send _TrafficSign :serialization-length))
   ;; int16 _turnOffset
     (setq _turnOffset (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float32 _turnRadius
     (setq _turnRadius (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; std_msgs/UInt8 _crossRoadClass
     (send _crossRoadClass :deserialize buf ptr-) (incf ptr- (send _crossRoadClass :serialization-length))
   ;; int16 _crossRoadOffset
     (setq _crossRoadOffset (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; std_msgs/UInt8 _crossRoadPriority
     (send _crossRoadPriority :deserialize buf ptr-) (incf ptr- (send _crossRoadPriority :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::Lane :md5sum-) "ac4b37c308258de2eff999751d19fd39")
(setf (get project_s_msgs::Lane :datatype-) "project_s_msgs/Lane")
(setf (get project_s_msgs::Lane :definition-)
      "std_msgs/UInt8 idLineRight
std_msgs/UInt8 idLineLeft
int16 offsetStart
int16 offsetEnd
std_msgs/UInt8 trafficDirection
std_msgs/UInt8 priority
std_msgs/UInt8 speedLimit
std_msgs/UInt8 TrafficSign
int16 turnOffset
float32 turnRadius
std_msgs/UInt8 crossRoadClass
int16 crossRoadOffset
std_msgs/UInt8 crossRoadPriority








================================================================================
MSG: std_msgs/UInt8
uint8 data

")



(provide :project_s_msgs/Lane "ac4b37c308258de2eff999751d19fd39")


