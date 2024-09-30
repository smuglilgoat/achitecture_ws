;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ehSegment)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ehSegment (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::EHSEGMENT")
  (make-package "PROJECT_S_MSGS::EHSEGMENT"))

(in-package "ROS")
;;//! \htmlinclude ehSegment.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::ehSegment
  :super ros::object
  :slots (_header _id _offset _functionRoadClass _wayForm _effectiveSpeedLimit _nbLanesDrivingDirection _nbLanesOppositeDirection ))

(defmethod project_s_msgs::ehSegment
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:offset __offset) (instance std_msgs::Float32 :init))
    ((:functionRoadClass __functionRoadClass) (instance std_msgs::UInt8 :init))
    ((:wayForm __wayForm) (instance std_msgs::UInt8 :init))
    ((:effectiveSpeedLimit __effectiveSpeedLimit) (instance std_msgs::UInt8 :init))
    ((:nbLanesDrivingDirection __nbLanesDrivingDirection) (instance std_msgs::UInt8 :init))
    ((:nbLanesOppositeDirection __nbLanesOppositeDirection) (instance std_msgs::UInt8 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _offset __offset)
   (setq _functionRoadClass __functionRoadClass)
   (setq _wayForm __wayForm)
   (setq _effectiveSpeedLimit __effectiveSpeedLimit)
   (setq _nbLanesDrivingDirection __nbLanesDrivingDirection)
   (setq _nbLanesOppositeDirection __nbLanesOppositeDirection)
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
  (:functionRoadClass
   (&rest __functionRoadClass)
   (if (keywordp (car __functionRoadClass))
       (send* _functionRoadClass __functionRoadClass)
     (progn
       (if __functionRoadClass (setq _functionRoadClass (car __functionRoadClass)))
       _functionRoadClass)))
  (:wayForm
   (&rest __wayForm)
   (if (keywordp (car __wayForm))
       (send* _wayForm __wayForm)
     (progn
       (if __wayForm (setq _wayForm (car __wayForm)))
       _wayForm)))
  (:effectiveSpeedLimit
   (&rest __effectiveSpeedLimit)
   (if (keywordp (car __effectiveSpeedLimit))
       (send* _effectiveSpeedLimit __effectiveSpeedLimit)
     (progn
       (if __effectiveSpeedLimit (setq _effectiveSpeedLimit (car __effectiveSpeedLimit)))
       _effectiveSpeedLimit)))
  (:nbLanesDrivingDirection
   (&rest __nbLanesDrivingDirection)
   (if (keywordp (car __nbLanesDrivingDirection))
       (send* _nbLanesDrivingDirection __nbLanesDrivingDirection)
     (progn
       (if __nbLanesDrivingDirection (setq _nbLanesDrivingDirection (car __nbLanesDrivingDirection)))
       _nbLanesDrivingDirection)))
  (:nbLanesOppositeDirection
   (&rest __nbLanesOppositeDirection)
   (if (keywordp (car __nbLanesOppositeDirection))
       (send* _nbLanesOppositeDirection __nbLanesOppositeDirection)
     (progn
       (if __nbLanesOppositeDirection (setq _nbLanesOppositeDirection (car __nbLanesOppositeDirection)))
       _nbLanesOppositeDirection)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/Float32 _offset
    (send _offset :serialization-length)
    ;; std_msgs/UInt8 _functionRoadClass
    (send _functionRoadClass :serialization-length)
    ;; std_msgs/UInt8 _wayForm
    (send _wayForm :serialization-length)
    ;; std_msgs/UInt8 _effectiveSpeedLimit
    (send _effectiveSpeedLimit :serialization-length)
    ;; std_msgs/UInt8 _nbLanesDrivingDirection
    (send _nbLanesDrivingDirection :serialization-length)
    ;; std_msgs/UInt8 _nbLanesOppositeDirection
    (send _nbLanesOppositeDirection :serialization-length)
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
     ;; std_msgs/UInt8 _functionRoadClass
       (send _functionRoadClass :serialize s)
     ;; std_msgs/UInt8 _wayForm
       (send _wayForm :serialize s)
     ;; std_msgs/UInt8 _effectiveSpeedLimit
       (send _effectiveSpeedLimit :serialize s)
     ;; std_msgs/UInt8 _nbLanesDrivingDirection
       (send _nbLanesDrivingDirection :serialize s)
     ;; std_msgs/UInt8 _nbLanesOppositeDirection
       (send _nbLanesOppositeDirection :serialize s)
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
   ;; std_msgs/UInt8 _functionRoadClass
     (send _functionRoadClass :deserialize buf ptr-) (incf ptr- (send _functionRoadClass :serialization-length))
   ;; std_msgs/UInt8 _wayForm
     (send _wayForm :deserialize buf ptr-) (incf ptr- (send _wayForm :serialization-length))
   ;; std_msgs/UInt8 _effectiveSpeedLimit
     (send _effectiveSpeedLimit :deserialize buf ptr-) (incf ptr- (send _effectiveSpeedLimit :serialization-length))
   ;; std_msgs/UInt8 _nbLanesDrivingDirection
     (send _nbLanesDrivingDirection :deserialize buf ptr-) (incf ptr- (send _nbLanesDrivingDirection :serialization-length))
   ;; std_msgs/UInt8 _nbLanesOppositeDirection
     (send _nbLanesOppositeDirection :deserialize buf ptr-) (incf ptr- (send _nbLanesOppositeDirection :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ehSegment :md5sum-) "6537588d17c4b8421cfde3df0a7fac39")
(setf (get project_s_msgs::ehSegment :datatype-) "project_s_msgs/ehSegment")
(setf (get project_s_msgs::ehSegment :definition-)
      "Header header
std_msgs/UInt8 id

#std_msgs/UInt8 indexPath
std_msgs/Float32 offset
std_msgs/UInt8 functionRoadClass
std_msgs/UInt8 wayForm
std_msgs/UInt8 effectiveSpeedLimit
std_msgs/UInt8 nbLanesDrivingDirection
std_msgs/UInt8 nbLanesOppositeDirection



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
")



(provide :project_s_msgs/ehSegment "6537588d17c4b8421cfde3df0a7fac39")


