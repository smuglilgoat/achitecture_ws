;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ObjectManoeuvre)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ObjectManoeuvre (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::OBJECTMANOEUVRE")
  (make-package "PROJECT_S_MSGS::OBJECTMANOEUVRE"))

(in-package "ROS")
;;//! \htmlinclude ObjectManoeuvre.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::ObjectManoeuvre
  :super ros::object
  :slots (_header _id _indexOriginLane _objectManoeuvre _objectSignalisation _objectPrediction _objectPredictionProbability ))

(defmethod project_s_msgs::ObjectManoeuvre
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:indexOriginLane __indexOriginLane) (instance std_msgs::UInt8 :init))
    ((:objectManoeuvre __objectManoeuvre) (instance std_msgs::UInt8 :init))
    ((:objectSignalisation __objectSignalisation) (instance std_msgs::UInt8 :init))
    ((:objectPrediction __objectPrediction) (instance std_msgs::UInt8 :init))
    ((:objectPredictionProbability __objectPredictionProbability) (instance std_msgs::UInt8 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _indexOriginLane __indexOriginLane)
   (setq _objectManoeuvre __objectManoeuvre)
   (setq _objectSignalisation __objectSignalisation)
   (setq _objectPrediction __objectPrediction)
   (setq _objectPredictionProbability __objectPredictionProbability)
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
  (:indexOriginLane
   (&rest __indexOriginLane)
   (if (keywordp (car __indexOriginLane))
       (send* _indexOriginLane __indexOriginLane)
     (progn
       (if __indexOriginLane (setq _indexOriginLane (car __indexOriginLane)))
       _indexOriginLane)))
  (:objectManoeuvre
   (&rest __objectManoeuvre)
   (if (keywordp (car __objectManoeuvre))
       (send* _objectManoeuvre __objectManoeuvre)
     (progn
       (if __objectManoeuvre (setq _objectManoeuvre (car __objectManoeuvre)))
       _objectManoeuvre)))
  (:objectSignalisation
   (&rest __objectSignalisation)
   (if (keywordp (car __objectSignalisation))
       (send* _objectSignalisation __objectSignalisation)
     (progn
       (if __objectSignalisation (setq _objectSignalisation (car __objectSignalisation)))
       _objectSignalisation)))
  (:objectPrediction
   (&rest __objectPrediction)
   (if (keywordp (car __objectPrediction))
       (send* _objectPrediction __objectPrediction)
     (progn
       (if __objectPrediction (setq _objectPrediction (car __objectPrediction)))
       _objectPrediction)))
  (:objectPredictionProbability
   (&rest __objectPredictionProbability)
   (if (keywordp (car __objectPredictionProbability))
       (send* _objectPredictionProbability __objectPredictionProbability)
     (progn
       (if __objectPredictionProbability (setq _objectPredictionProbability (car __objectPredictionProbability)))
       _objectPredictionProbability)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/UInt8 _indexOriginLane
    (send _indexOriginLane :serialization-length)
    ;; std_msgs/UInt8 _objectManoeuvre
    (send _objectManoeuvre :serialization-length)
    ;; std_msgs/UInt8 _objectSignalisation
    (send _objectSignalisation :serialization-length)
    ;; std_msgs/UInt8 _objectPrediction
    (send _objectPrediction :serialization-length)
    ;; std_msgs/UInt8 _objectPredictionProbability
    (send _objectPredictionProbability :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/UInt8 _indexOriginLane
       (send _indexOriginLane :serialize s)
     ;; std_msgs/UInt8 _objectManoeuvre
       (send _objectManoeuvre :serialize s)
     ;; std_msgs/UInt8 _objectSignalisation
       (send _objectSignalisation :serialize s)
     ;; std_msgs/UInt8 _objectPrediction
       (send _objectPrediction :serialize s)
     ;; std_msgs/UInt8 _objectPredictionProbability
       (send _objectPredictionProbability :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/UInt8 _indexOriginLane
     (send _indexOriginLane :deserialize buf ptr-) (incf ptr- (send _indexOriginLane :serialization-length))
   ;; std_msgs/UInt8 _objectManoeuvre
     (send _objectManoeuvre :deserialize buf ptr-) (incf ptr- (send _objectManoeuvre :serialization-length))
   ;; std_msgs/UInt8 _objectSignalisation
     (send _objectSignalisation :deserialize buf ptr-) (incf ptr- (send _objectSignalisation :serialization-length))
   ;; std_msgs/UInt8 _objectPrediction
     (send _objectPrediction :deserialize buf ptr-) (incf ptr- (send _objectPrediction :serialization-length))
   ;; std_msgs/UInt8 _objectPredictionProbability
     (send _objectPredictionProbability :deserialize buf ptr-) (incf ptr- (send _objectPredictionProbability :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ObjectManoeuvre :md5sum-) "fa042f189b42a91d1a2d603726c850b7")
(setf (get project_s_msgs::ObjectManoeuvre :datatype-) "project_s_msgs/ObjectManoeuvre")
(setf (get project_s_msgs::ObjectManoeuvre :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/UInt8 indexOriginLane
std_msgs/UInt8 objectManoeuvre
std_msgs/UInt8 objectSignalisation
std_msgs/UInt8 objectPrediction
std_msgs/UInt8 objectPredictionProbability

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

")



(provide :project_s_msgs/ObjectManoeuvre "fa042f189b42a91d1a2d603726c850b7")


