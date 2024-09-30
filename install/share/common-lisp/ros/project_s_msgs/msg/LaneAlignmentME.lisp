; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude LaneAlignmentME.msg.html

(cl:defclass <LaneAlignmentME> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (line
    :reader line
    :initarg :line
    :type (cl:vector mobileye_560_660_msgs-msg:LkaLane)
   :initform (cl:make-array 5 :element-type 'mobileye_560_660_msgs-msg:LkaLane :initial-element (cl:make-instance 'mobileye_560_660_msgs-msg:LkaLane)))
   (line_min
    :reader line_min
    :initarg :line_min
    :type (cl:vector cl:float)
   :initform (cl:make-array 5 :element-type 'cl:float :initial-element 0.0))
   (line_max
    :reader line_max
    :initarg :line_max
    :type (cl:vector cl:float)
   :initform (cl:make-array 5 :element-type 'cl:float :initial-element 0.0))
   (QtyLine
    :reader QtyLine
    :initarg :QtyLine
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8)))
)

(cl:defclass LaneAlignmentME (<LaneAlignmentME>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LaneAlignmentME>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LaneAlignmentME)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<LaneAlignmentME> is deprecated: use project_s_msgs-msg:LaneAlignmentME instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LaneAlignmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'line-val :lambda-list '(m))
(cl:defmethod line-val ((m <LaneAlignmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:line-val is deprecated.  Use project_s_msgs-msg:line instead.")
  (line m))

(cl:ensure-generic-function 'line_min-val :lambda-list '(m))
(cl:defmethod line_min-val ((m <LaneAlignmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:line_min-val is deprecated.  Use project_s_msgs-msg:line_min instead.")
  (line_min m))

(cl:ensure-generic-function 'line_max-val :lambda-list '(m))
(cl:defmethod line_max-val ((m <LaneAlignmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:line_max-val is deprecated.  Use project_s_msgs-msg:line_max instead.")
  (line_max m))

(cl:ensure-generic-function 'QtyLine-val :lambda-list '(m))
(cl:defmethod QtyLine-val ((m <LaneAlignmentME>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:QtyLine-val is deprecated.  Use project_s_msgs-msg:QtyLine instead.")
  (QtyLine m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LaneAlignmentME>) ostream)
  "Serializes a message object of type '<LaneAlignmentME>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'line))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'line_min))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'line_max))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'QtyLine) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LaneAlignmentME>) istream)
  "Deserializes a message object of type '<LaneAlignmentME>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:setf (cl:slot-value msg 'line) (cl:make-array 5))
  (cl:let ((vals (cl:slot-value msg 'line)))
    (cl:dotimes (i 5)
    (cl:setf (cl:aref vals i) (cl:make-instance 'mobileye_560_660_msgs-msg:LkaLane))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (cl:setf (cl:slot-value msg 'line_min) (cl:make-array 5))
  (cl:let ((vals (cl:slot-value msg 'line_min)))
    (cl:dotimes (i 5)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'line_max) (cl:make-array 5))
  (cl:let ((vals (cl:slot-value msg 'line_max)))
    (cl:dotimes (i 5)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'QtyLine) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LaneAlignmentME>)))
  "Returns string type for a message object of type '<LaneAlignmentME>"
  "project_s_msgs/LaneAlignmentME")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LaneAlignmentME)))
  "Returns string type for a message object of type 'LaneAlignmentME"
  "project_s_msgs/LaneAlignmentME")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LaneAlignmentME>)))
  "Returns md5sum for a message object of type '<LaneAlignmentME>"
  "d378bfe1f7b07b92f50424d676c60576")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LaneAlignmentME)))
  "Returns md5sum for a message object of type 'LaneAlignmentME"
  "d378bfe1f7b07b92f50424d676c60576")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LaneAlignmentME>)))
  "Returns full string definition for message of type '<LaneAlignmentME>"
  (cl:format cl:nil "Header header~%~%mobileye_560_660_msgs/LkaLane[5] line~%float32[5] line_min~%float32[5] line_max~%std_msgs/UInt8 QtyLine~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: mobileye_560_660_msgs/LkaLane~%Header header~%~%uint8 LANE_CONFIDENCE_NONE = 0~%uint8 LANE_CONFIDENCE_LOW = 1~%uint8 LANE_CONFIDENCE_MED = 2~%uint8 LANE_CONFIDENCE_HIGH = 3~%~%uint8 LANE_TYPE_DASHED = 0~%uint8 LANE_TYPE_SOLID = 1~%uint8 LANE_TYPE_NONE = 2~%uint8 LANE_TYPE_ROAD_EDGE = 3~%uint8 LANE_TYPE_DOUBLE_LANE_MARK = 4~%uint8 LANE_TYPE_BOTTS_DOTS = 5~%uint8 LANE_TYPE_INVALID = 6~%~%uint8 lane_type~%uint8 quality~%uint8 model_degree~%float64 position_parameter_c0~%float64 curvature_parameter_c2~%float64 curvature_derivative_parameter_c3~%float32 marking_width~%float64 heading_angle_parameter_c1~%float32 view_range~%bool view_range_availability~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LaneAlignmentME)))
  "Returns full string definition for message of type 'LaneAlignmentME"
  (cl:format cl:nil "Header header~%~%mobileye_560_660_msgs/LkaLane[5] line~%float32[5] line_min~%float32[5] line_max~%std_msgs/UInt8 QtyLine~%~%# History~%~%~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: mobileye_560_660_msgs/LkaLane~%Header header~%~%uint8 LANE_CONFIDENCE_NONE = 0~%uint8 LANE_CONFIDENCE_LOW = 1~%uint8 LANE_CONFIDENCE_MED = 2~%uint8 LANE_CONFIDENCE_HIGH = 3~%~%uint8 LANE_TYPE_DASHED = 0~%uint8 LANE_TYPE_SOLID = 1~%uint8 LANE_TYPE_NONE = 2~%uint8 LANE_TYPE_ROAD_EDGE = 3~%uint8 LANE_TYPE_DOUBLE_LANE_MARK = 4~%uint8 LANE_TYPE_BOTTS_DOTS = 5~%uint8 LANE_TYPE_INVALID = 6~%~%uint8 lane_type~%uint8 quality~%uint8 model_degree~%float64 position_parameter_c0~%float64 curvature_parameter_c2~%float64 curvature_derivative_parameter_c3~%float32 marking_width~%float64 heading_angle_parameter_c1~%float32 view_range~%bool view_range_availability~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LaneAlignmentME>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'line) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'line_min) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'line_max) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'QtyLine))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LaneAlignmentME>))
  "Converts a ROS message object to a list"
  (cl:list 'LaneAlignmentME
    (cl:cons ':header (header msg))
    (cl:cons ':line (line msg))
    (cl:cons ':line_min (line_min msg))
    (cl:cons ':line_max (line_max msg))
    (cl:cons ':QtyLine (QtyLine msg))
))
