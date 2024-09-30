;; Auto-generated. Do not edit!


(when (boundp 'message_project_s::LaneAlignmentME_1)
  (if (not (find-package "MESSAGE_PROJECT_S"))
    (make-package "MESSAGE_PROJECT_S"))
  (shadow 'LaneAlignmentME_1 (find-package "MESSAGE_PROJECT_S")))
(unless (find-package "MESSAGE_PROJECT_S::LANEALIGNMENTME_1")
  (make-package "MESSAGE_PROJECT_S::LANEALIGNMENTME_1"))

(in-package "ROS")
;;//! \htmlinclude LaneAlignmentME_1.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass message_project_s::LaneAlignmentME_1
  :super ros::object
  :slots (_header _id _left_lane_type _left_quality _left_model_degree _left_position_parameter_c0 _left_curvature_parameter_c2 _left_curvature_derivative_parameter_c3 _left_marking_width _left_heading_angle_parameter_c1 _left_view_range _left_view_range_availability _right_lane_type _right_quality _right_model_degree _right_position_parameter_c0 _right_curvature_parameter_c2 _right_curvature_derivative_parameter_c3 _right_marking_width _right_heading_angle_parameter_c1 _right_view_range _right_view_range_availability ))

(defmethod message_project_s::LaneAlignmentME_1
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:left_lane_type __left_lane_type) 0)
    ((:left_quality __left_quality) 0)
    ((:left_model_degree __left_model_degree) 0)
    ((:left_position_parameter_c0 __left_position_parameter_c0) 0.0)
    ((:left_curvature_parameter_c2 __left_curvature_parameter_c2) 0.0)
    ((:left_curvature_derivative_parameter_c3 __left_curvature_derivative_parameter_c3) 0.0)
    ((:left_marking_width __left_marking_width) 0.0)
    ((:left_heading_angle_parameter_c1 __left_heading_angle_parameter_c1) 0.0)
    ((:left_view_range __left_view_range) 0.0)
    ((:left_view_range_availability __left_view_range_availability) nil)
    ((:right_lane_type __right_lane_type) 0)
    ((:right_quality __right_quality) 0)
    ((:right_model_degree __right_model_degree) 0)
    ((:right_position_parameter_c0 __right_position_parameter_c0) 0.0)
    ((:right_curvature_parameter_c2 __right_curvature_parameter_c2) 0.0)
    ((:right_curvature_derivative_parameter_c3 __right_curvature_derivative_parameter_c3) 0.0)
    ((:right_marking_width __right_marking_width) 0.0)
    ((:right_heading_angle_parameter_c1 __right_heading_angle_parameter_c1) 0.0)
    ((:right_view_range __right_view_range) 0.0)
    ((:right_view_range_availability __right_view_range_availability) nil)
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _left_lane_type (round __left_lane_type))
   (setq _left_quality (round __left_quality))
   (setq _left_model_degree (round __left_model_degree))
   (setq _left_position_parameter_c0 (float __left_position_parameter_c0))
   (setq _left_curvature_parameter_c2 (float __left_curvature_parameter_c2))
   (setq _left_curvature_derivative_parameter_c3 (float __left_curvature_derivative_parameter_c3))
   (setq _left_marking_width (float __left_marking_width))
   (setq _left_heading_angle_parameter_c1 (float __left_heading_angle_parameter_c1))
   (setq _left_view_range (float __left_view_range))
   (setq _left_view_range_availability __left_view_range_availability)
   (setq _right_lane_type (round __right_lane_type))
   (setq _right_quality (round __right_quality))
   (setq _right_model_degree (round __right_model_degree))
   (setq _right_position_parameter_c0 (float __right_position_parameter_c0))
   (setq _right_curvature_parameter_c2 (float __right_curvature_parameter_c2))
   (setq _right_curvature_derivative_parameter_c3 (float __right_curvature_derivative_parameter_c3))
   (setq _right_marking_width (float __right_marking_width))
   (setq _right_heading_angle_parameter_c1 (float __right_heading_angle_parameter_c1))
   (setq _right_view_range (float __right_view_range))
   (setq _right_view_range_availability __right_view_range_availability)
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
  (:left_lane_type
   (&optional __left_lane_type)
   (if __left_lane_type (setq _left_lane_type __left_lane_type)) _left_lane_type)
  (:left_quality
   (&optional __left_quality)
   (if __left_quality (setq _left_quality __left_quality)) _left_quality)
  (:left_model_degree
   (&optional __left_model_degree)
   (if __left_model_degree (setq _left_model_degree __left_model_degree)) _left_model_degree)
  (:left_position_parameter_c0
   (&optional __left_position_parameter_c0)
   (if __left_position_parameter_c0 (setq _left_position_parameter_c0 __left_position_parameter_c0)) _left_position_parameter_c0)
  (:left_curvature_parameter_c2
   (&optional __left_curvature_parameter_c2)
   (if __left_curvature_parameter_c2 (setq _left_curvature_parameter_c2 __left_curvature_parameter_c2)) _left_curvature_parameter_c2)
  (:left_curvature_derivative_parameter_c3
   (&optional __left_curvature_derivative_parameter_c3)
   (if __left_curvature_derivative_parameter_c3 (setq _left_curvature_derivative_parameter_c3 __left_curvature_derivative_parameter_c3)) _left_curvature_derivative_parameter_c3)
  (:left_marking_width
   (&optional __left_marking_width)
   (if __left_marking_width (setq _left_marking_width __left_marking_width)) _left_marking_width)
  (:left_heading_angle_parameter_c1
   (&optional __left_heading_angle_parameter_c1)
   (if __left_heading_angle_parameter_c1 (setq _left_heading_angle_parameter_c1 __left_heading_angle_parameter_c1)) _left_heading_angle_parameter_c1)
  (:left_view_range
   (&optional __left_view_range)
   (if __left_view_range (setq _left_view_range __left_view_range)) _left_view_range)
  (:left_view_range_availability
   (&optional __left_view_range_availability)
   (if __left_view_range_availability (setq _left_view_range_availability __left_view_range_availability)) _left_view_range_availability)
  (:right_lane_type
   (&optional __right_lane_type)
   (if __right_lane_type (setq _right_lane_type __right_lane_type)) _right_lane_type)
  (:right_quality
   (&optional __right_quality)
   (if __right_quality (setq _right_quality __right_quality)) _right_quality)
  (:right_model_degree
   (&optional __right_model_degree)
   (if __right_model_degree (setq _right_model_degree __right_model_degree)) _right_model_degree)
  (:right_position_parameter_c0
   (&optional __right_position_parameter_c0)
   (if __right_position_parameter_c0 (setq _right_position_parameter_c0 __right_position_parameter_c0)) _right_position_parameter_c0)
  (:right_curvature_parameter_c2
   (&optional __right_curvature_parameter_c2)
   (if __right_curvature_parameter_c2 (setq _right_curvature_parameter_c2 __right_curvature_parameter_c2)) _right_curvature_parameter_c2)
  (:right_curvature_derivative_parameter_c3
   (&optional __right_curvature_derivative_parameter_c3)
   (if __right_curvature_derivative_parameter_c3 (setq _right_curvature_derivative_parameter_c3 __right_curvature_derivative_parameter_c3)) _right_curvature_derivative_parameter_c3)
  (:right_marking_width
   (&optional __right_marking_width)
   (if __right_marking_width (setq _right_marking_width __right_marking_width)) _right_marking_width)
  (:right_heading_angle_parameter_c1
   (&optional __right_heading_angle_parameter_c1)
   (if __right_heading_angle_parameter_c1 (setq _right_heading_angle_parameter_c1 __right_heading_angle_parameter_c1)) _right_heading_angle_parameter_c1)
  (:right_view_range
   (&optional __right_view_range)
   (if __right_view_range (setq _right_view_range __right_view_range)) _right_view_range)
  (:right_view_range_availability
   (&optional __right_view_range_availability)
   (if __right_view_range_availability (setq _right_view_range_availability __right_view_range_availability)) _right_view_range_availability)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; uint8 _left_lane_type
    1
    ;; uint8 _left_quality
    1
    ;; uint8 _left_model_degree
    1
    ;; float64 _left_position_parameter_c0
    8
    ;; float64 _left_curvature_parameter_c2
    8
    ;; float64 _left_curvature_derivative_parameter_c3
    8
    ;; float32 _left_marking_width
    4
    ;; float64 _left_heading_angle_parameter_c1
    8
    ;; float32 _left_view_range
    4
    ;; bool _left_view_range_availability
    1
    ;; uint8 _right_lane_type
    1
    ;; uint8 _right_quality
    1
    ;; uint8 _right_model_degree
    1
    ;; float64 _right_position_parameter_c0
    8
    ;; float64 _right_curvature_parameter_c2
    8
    ;; float64 _right_curvature_derivative_parameter_c3
    8
    ;; float32 _right_marking_width
    4
    ;; float64 _right_heading_angle_parameter_c1
    8
    ;; float32 _right_view_range
    4
    ;; bool _right_view_range_availability
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; uint8 _left_lane_type
       (write-byte _left_lane_type s)
     ;; uint8 _left_quality
       (write-byte _left_quality s)
     ;; uint8 _left_model_degree
       (write-byte _left_model_degree s)
     ;; float64 _left_position_parameter_c0
       (sys::poke _left_position_parameter_c0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _left_curvature_parameter_c2
       (sys::poke _left_curvature_parameter_c2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _left_curvature_derivative_parameter_c3
       (sys::poke _left_curvature_derivative_parameter_c3 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float32 _left_marking_width
       (sys::poke _left_marking_width (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float64 _left_heading_angle_parameter_c1
       (sys::poke _left_heading_angle_parameter_c1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float32 _left_view_range
       (sys::poke _left_view_range (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _left_view_range_availability
       (if _left_view_range_availability (write-byte -1 s) (write-byte 0 s))
     ;; uint8 _right_lane_type
       (write-byte _right_lane_type s)
     ;; uint8 _right_quality
       (write-byte _right_quality s)
     ;; uint8 _right_model_degree
       (write-byte _right_model_degree s)
     ;; float64 _right_position_parameter_c0
       (sys::poke _right_position_parameter_c0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_curvature_parameter_c2
       (sys::poke _right_curvature_parameter_c2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_curvature_derivative_parameter_c3
       (sys::poke _right_curvature_derivative_parameter_c3 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float32 _right_marking_width
       (sys::poke _right_marking_width (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float64 _right_heading_angle_parameter_c1
       (sys::poke _right_heading_angle_parameter_c1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float32 _right_view_range
       (sys::poke _right_view_range (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _right_view_range_availability
       (if _right_view_range_availability (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; uint8 _left_lane_type
     (setq _left_lane_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _left_quality
     (setq _left_quality (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _left_model_degree
     (setq _left_model_degree (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _left_position_parameter_c0
     (setq _left_position_parameter_c0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _left_curvature_parameter_c2
     (setq _left_curvature_parameter_c2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _left_curvature_derivative_parameter_c3
     (setq _left_curvature_derivative_parameter_c3 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float32 _left_marking_width
     (setq _left_marking_width (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float64 _left_heading_angle_parameter_c1
     (setq _left_heading_angle_parameter_c1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float32 _left_view_range
     (setq _left_view_range (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _left_view_range_availability
     (setq _left_view_range_availability (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint8 _right_lane_type
     (setq _right_lane_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _right_quality
     (setq _right_quality (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _right_model_degree
     (setq _right_model_degree (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _right_position_parameter_c0
     (setq _right_position_parameter_c0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_curvature_parameter_c2
     (setq _right_curvature_parameter_c2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_curvature_derivative_parameter_c3
     (setq _right_curvature_derivative_parameter_c3 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float32 _right_marking_width
     (setq _right_marking_width (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float64 _right_heading_angle_parameter_c1
     (setq _right_heading_angle_parameter_c1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float32 _right_view_range
     (setq _right_view_range (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _right_view_range_availability
     (setq _right_view_range_availability (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get message_project_s::LaneAlignmentME_1 :md5sum-) "879c0a765df264cb0b3a43d9c8f4f61a")
(setf (get message_project_s::LaneAlignmentME_1 :datatype-) "message_project_s/LaneAlignmentME_1")
(setf (get message_project_s::LaneAlignmentME_1 :definition-)
      "Header header
std_msgs/UInt8 id

uint8 left_lane_type
uint8 left_quality
uint8 left_model_degree
float64 left_position_parameter_c0
float64 left_curvature_parameter_c2
float64 left_curvature_derivative_parameter_c3
float32 left_marking_width
float64 left_heading_angle_parameter_c1
float32 left_view_range
bool left_view_range_availability

uint8 right_lane_type
uint8 right_quality
uint8 right_model_degree
float64 right_position_parameter_c0
float64 right_curvature_parameter_c2
float64 right_curvature_derivative_parameter_c3
float32 right_marking_width
float64 right_heading_angle_parameter_c1
float32 right_view_range
bool right_view_range_availability

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



(provide :message_project_s/LaneAlignmentME_1 "879c0a765df264cb0b3a43d9c8f4f61a")


