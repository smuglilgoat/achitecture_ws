;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::TargetSelection)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'TargetSelection (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::TARGETSELECTION")
  (make-package "PROJECT_S_MSGS::TARGETSELECTION"))

(in-package "ROS")
;;//! \htmlinclude TargetSelection.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::TargetSelection
  :super ros::object
  :slots (_header _id _indexLane _targetDirection _targetDirectionProbability _distance _speed _timeToCollision ))

(defmethod project_s_msgs::TargetSelection
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:indexLane __indexLane) (instance std_msgs::UInt8 :init))
    ((:targetDirection __targetDirection) (instance std_msgs::UInt8 :init))
    ((:targetDirectionProbability __targetDirectionProbability) (instance std_msgs::UInt8 :init))
    ((:distance __distance) (instance std_msgs::Float32 :init))
    ((:speed __speed) (instance std_msgs::Float32 :init))
    ((:timeToCollision __timeToCollision) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _indexLane __indexLane)
   (setq _targetDirection __targetDirection)
   (setq _targetDirectionProbability __targetDirectionProbability)
   (setq _distance __distance)
   (setq _speed __speed)
   (setq _timeToCollision __timeToCollision)
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
  (:indexLane
   (&rest __indexLane)
   (if (keywordp (car __indexLane))
       (send* _indexLane __indexLane)
     (progn
       (if __indexLane (setq _indexLane (car __indexLane)))
       _indexLane)))
  (:targetDirection
   (&rest __targetDirection)
   (if (keywordp (car __targetDirection))
       (send* _targetDirection __targetDirection)
     (progn
       (if __targetDirection (setq _targetDirection (car __targetDirection)))
       _targetDirection)))
  (:targetDirectionProbability
   (&rest __targetDirectionProbability)
   (if (keywordp (car __targetDirectionProbability))
       (send* _targetDirectionProbability __targetDirectionProbability)
     (progn
       (if __targetDirectionProbability (setq _targetDirectionProbability (car __targetDirectionProbability)))
       _targetDirectionProbability)))
  (:distance
   (&rest __distance)
   (if (keywordp (car __distance))
       (send* _distance __distance)
     (progn
       (if __distance (setq _distance (car __distance)))
       _distance)))
  (:speed
   (&rest __speed)
   (if (keywordp (car __speed))
       (send* _speed __speed)
     (progn
       (if __speed (setq _speed (car __speed)))
       _speed)))
  (:timeToCollision
   (&rest __timeToCollision)
   (if (keywordp (car __timeToCollision))
       (send* _timeToCollision __timeToCollision)
     (progn
       (if __timeToCollision (setq _timeToCollision (car __timeToCollision)))
       _timeToCollision)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/UInt8 _indexLane
    (send _indexLane :serialization-length)
    ;; std_msgs/UInt8 _targetDirection
    (send _targetDirection :serialization-length)
    ;; std_msgs/UInt8 _targetDirectionProbability
    (send _targetDirectionProbability :serialization-length)
    ;; std_msgs/Float32 _distance
    (send _distance :serialization-length)
    ;; std_msgs/Float32 _speed
    (send _speed :serialization-length)
    ;; std_msgs/Float32 _timeToCollision
    (send _timeToCollision :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/UInt8 _indexLane
       (send _indexLane :serialize s)
     ;; std_msgs/UInt8 _targetDirection
       (send _targetDirection :serialize s)
     ;; std_msgs/UInt8 _targetDirectionProbability
       (send _targetDirectionProbability :serialize s)
     ;; std_msgs/Float32 _distance
       (send _distance :serialize s)
     ;; std_msgs/Float32 _speed
       (send _speed :serialize s)
     ;; std_msgs/Float32 _timeToCollision
       (send _timeToCollision :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/UInt8 _indexLane
     (send _indexLane :deserialize buf ptr-) (incf ptr- (send _indexLane :serialization-length))
   ;; std_msgs/UInt8 _targetDirection
     (send _targetDirection :deserialize buf ptr-) (incf ptr- (send _targetDirection :serialization-length))
   ;; std_msgs/UInt8 _targetDirectionProbability
     (send _targetDirectionProbability :deserialize buf ptr-) (incf ptr- (send _targetDirectionProbability :serialization-length))
   ;; std_msgs/Float32 _distance
     (send _distance :deserialize buf ptr-) (incf ptr- (send _distance :serialization-length))
   ;; std_msgs/Float32 _speed
     (send _speed :deserialize buf ptr-) (incf ptr- (send _speed :serialization-length))
   ;; std_msgs/Float32 _timeToCollision
     (send _timeToCollision :deserialize buf ptr-) (incf ptr- (send _timeToCollision :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::TargetSelection :md5sum-) "d3f1ac60f8428b7cd019b0bb611a0a65")
(setf (get project_s_msgs::TargetSelection :datatype-) "project_s_msgs/TargetSelection")
(setf (get project_s_msgs::TargetSelection :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/UInt8 indexLane
std_msgs/UInt8 targetDirection
std_msgs/UInt8 targetDirectionProbability
std_msgs/Float32 distance
std_msgs/Float32 speed
std_msgs/Float32 timeToCollision

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



(provide :project_s_msgs/TargetSelection "d3f1ac60f8428b7cd019b0bb611a0a65")


