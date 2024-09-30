;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::LaneAlignmentME)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'LaneAlignmentME (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::LANEALIGNMENTME")
  (make-package "PROJECT_S_MSGS::LANEALIGNMENTME"))

(in-package "ROS")
;;//! \htmlinclude LaneAlignmentME.msg.html
(if (not (find-package "MOBILEYE_560_660_MSGS"))
  (ros::roseus-add-msgs "mobileye_560_660_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::LaneAlignmentME
  :super ros::object
  :slots (_header _line _line_min _line_max _QtyLine ))

(defmethod project_s_msgs::LaneAlignmentME
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:line __line) (let (r) (dotimes (i 5) (push (instance mobileye_560_660_msgs::LkaLane :init) r)) r))
    ((:line_min __line_min) (make-array 5 :initial-element 0.0 :element-type :float))
    ((:line_max __line_max) (make-array 5 :initial-element 0.0 :element-type :float))
    ((:QtyLine __QtyLine) (instance std_msgs::UInt8 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _line __line)
   (setq _line_min __line_min)
   (setq _line_max __line_max)
   (setq _QtyLine __QtyLine)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:line
   (&rest __line)
   (if (keywordp (car __line))
       (send* _line __line)
     (progn
       (if __line (setq _line (car __line)))
       _line)))
  (:line_min
   (&optional __line_min)
   (if __line_min (setq _line_min __line_min)) _line_min)
  (:line_max
   (&optional __line_max)
   (if __line_max (setq _line_max __line_max)) _line_max)
  (:QtyLine
   (&rest __QtyLine)
   (if (keywordp (car __QtyLine))
       (send* _QtyLine __QtyLine)
     (progn
       (if __QtyLine (setq _QtyLine (car __QtyLine)))
       _QtyLine)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; mobileye_560_660_msgs/LkaLane[5] _line
    (apply #'+ (send-all _line :serialization-length))
    ;; float32[5] _line_min
    (* 4    5)
    ;; float32[5] _line_max
    (* 4    5)
    ;; std_msgs/UInt8 _QtyLine
    (send _QtyLine :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; mobileye_560_660_msgs/LkaLane[5] _line
     (dolist (elem _line)
       (send elem :serialize s)
       )
     ;; float32[5] _line_min
     (dotimes (i 5)
       (sys::poke (elt _line_min i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[5] _line_max
     (dotimes (i 5)
       (sys::poke (elt _line_max i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; std_msgs/UInt8 _QtyLine
       (send _QtyLine :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; mobileye_560_660_msgs/LkaLane[5] _line
   (dotimes (i 5)
     (send (elt _line i) :deserialize buf ptr-) (incf ptr- (send (elt _line i) :serialization-length))
     )
   ;; float32[5] _line_min
   (dotimes (i (length _line_min))
     (setf (elt _line_min i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[5] _line_max
   (dotimes (i (length _line_max))
     (setf (elt _line_max i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; std_msgs/UInt8 _QtyLine
     (send _QtyLine :deserialize buf ptr-) (incf ptr- (send _QtyLine :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::LaneAlignmentME :md5sum-) "d378bfe1f7b07b92f50424d676c60576")
(setf (get project_s_msgs::LaneAlignmentME :datatype-) "project_s_msgs/LaneAlignmentME")
(setf (get project_s_msgs::LaneAlignmentME :definition-)
      "Header header

mobileye_560_660_msgs/LkaLane[5] line
float32[5] line_min
float32[5] line_max
std_msgs/UInt8 QtyLine

# History





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
MSG: mobileye_560_660_msgs/LkaLane
Header header

uint8 LANE_CONFIDENCE_NONE = 0
uint8 LANE_CONFIDENCE_LOW = 1
uint8 LANE_CONFIDENCE_MED = 2
uint8 LANE_CONFIDENCE_HIGH = 3

uint8 LANE_TYPE_DASHED = 0
uint8 LANE_TYPE_SOLID = 1
uint8 LANE_TYPE_NONE = 2
uint8 LANE_TYPE_ROAD_EDGE = 3
uint8 LANE_TYPE_DOUBLE_LANE_MARK = 4
uint8 LANE_TYPE_BOTTS_DOTS = 5
uint8 LANE_TYPE_INVALID = 6

uint8 lane_type
uint8 quality
uint8 model_degree
float64 position_parameter_c0
float64 curvature_parameter_c2
float64 curvature_derivative_parameter_c3
float32 marking_width
float64 heading_angle_parameter_c1
float32 view_range
bool view_range_availability

================================================================================
MSG: std_msgs/UInt8
uint8 data

")



(provide :project_s_msgs/LaneAlignmentME "d378bfe1f7b07b92f50424d676c60576")


