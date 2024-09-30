; Auto-generated. Do not edit!


(cl:in-package message_project_s-msg)


;//! \htmlinclude LaneAlignmentME_1.msg.html

(cl:defclass <LaneAlignmentME_1> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (id
    :reader id
    :initarg :id
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (left_lane_type
    :reader left_lane_type
    :initarg :left_lane_type
    :type cl:fixnum
    :initform 0)
   (left_quality
    :reader left_quality
    :initarg :left_quality
    :type cl:fixnum
    :initform 0)
   (left_model_degree
    :reader left_model_degree
    :initarg :left_model_degree
    :type cl:fixnum
    :initform 0)
   (left_position_parameter_c0
    :reader left_position_parameter_c0
    :initarg :left_position_parameter_c0
    :type cl:float
    :initform 0.0)
   (left_curvature_parameter_c2
    :reader left_curvature_parameter_c2
    :initarg :left_curvature_parameter_c2
    :type cl:float
    :initform 0.0)
   (left_curvature_derivative_parameter_c3
    :reader left_curvature_derivative_parameter_c3
    :initarg :left_curvature_derivative_parameter_c3
    :type cl:float
    :initform 0.0)
   (left_marking_width
    :reader left_marking_width
    :initarg :left_marking_width
    :type cl:float
    :initform 0.0)
   (left_heading_angle_parameter_c1
    :reader left_heading_angle_parameter_c1
    :initarg :left_heading_angle_parameter_c1
    :type cl:float
    :initform 0.0)
   (left_view_range
    :reader left_view_range
    :initarg :left_view_range
    :type cl:float
    :initform 0.0)
   (left_view_range_availability
    :reader left_view_range_availability
    :initarg :left_view_range_availability
    :type cl:boolean
    :initform cl:nil)
   (right_lane_type
    :reader right_lane_type
    :initarg :right_lane_type
    :type cl:fixnum
    :initform 0)
   (right_quality
    :reader right_quality
    :initarg :right_quality
    :type cl:fixnum
    :initform 0)
   (right_model_degree
    :reader right_model_degree
    :initarg :right_model_degree
    :type cl:fixnum
    :initform 0)
   (right_position_parameter_c0
    :reader right_position_parameter_c0
    :initarg :right_position_parameter_c0
    :type cl:float
    :initform 0.0)
   (right_curvature_parameter_c2
    :reader right_curvature_parameter_c2
    :initarg :right_curvature_parameter_c2
    :type cl:float
    :initform 0.0)
   (right_curvature_derivative_parameter_c3
    :reader right_curvature_derivative_parameter_c3
    :initarg :right_curvature_derivative_parameter_c3
    :type cl:float
    :initform 0.0)
   (right_marking_width
    :reader right_marking_width
    :initarg :right_marking_width
    :type cl:float
    :initform 0.0)
   (right_heading_angle_parameter_c1
    :reader right_heading_angle_parameter_c1
    :initarg :right_heading_angle_parameter_c1
    :type cl:float
    :initform 0.0)
   (right_view_range
    :reader right_view_range
    :initarg :right_view_range
    :type cl:float
    :initform 0.0)
   (right_view_range_availability
    :reader right_view_range_availability
    :initarg :right_view_range_availability
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass LaneAlignmentME_1 (<LaneAlignmentME_1>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LaneAlignmentME_1>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LaneAlignmentME_1)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name message_project_s-msg:<LaneAlignmentME_1> is deprecated: use message_project_s-msg:LaneAlignmentME_1 instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:header-val is deprecated.  Use message_project_s-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:id-val is deprecated.  Use message_project_s-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'left_lane_type-val :lambda-list '(m))
(cl:defmethod left_lane_type-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:left_lane_type-val is deprecated.  Use message_project_s-msg:left_lane_type instead.")
  (left_lane_type m))

(cl:ensure-generic-function 'left_quality-val :lambda-list '(m))
(cl:defmethod left_quality-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:left_quality-val is deprecated.  Use message_project_s-msg:left_quality instead.")
  (left_quality m))

(cl:ensure-generic-function 'left_model_degree-val :lambda-list '(m))
(cl:defmethod left_model_degree-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:left_model_degree-val is deprecated.  Use message_project_s-msg:left_model_degree instead.")
  (left_model_degree m))

(cl:ensure-generic-function 'left_position_parameter_c0-val :lambda-list '(m))
(cl:defmethod left_position_parameter_c0-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:left_position_parameter_c0-val is deprecated.  Use message_project_s-msg:left_position_parameter_c0 instead.")
  (left_position_parameter_c0 m))

(cl:ensure-generic-function 'left_curvature_parameter_c2-val :lambda-list '(m))
(cl:defmethod left_curvature_parameter_c2-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:left_curvature_parameter_c2-val is deprecated.  Use message_project_s-msg:left_curvature_parameter_c2 instead.")
  (left_curvature_parameter_c2 m))

(cl:ensure-generic-function 'left_curvature_derivative_parameter_c3-val :lambda-list '(m))
(cl:defmethod left_curvature_derivative_parameter_c3-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:left_curvature_derivative_parameter_c3-val is deprecated.  Use message_project_s-msg:left_curvature_derivative_parameter_c3 instead.")
  (left_curvature_derivative_parameter_c3 m))

(cl:ensure-generic-function 'left_marking_width-val :lambda-list '(m))
(cl:defmethod left_marking_width-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:left_marking_width-val is deprecated.  Use message_project_s-msg:left_marking_width instead.")
  (left_marking_width m))

(cl:ensure-generic-function 'left_heading_angle_parameter_c1-val :lambda-list '(m))
(cl:defmethod left_heading_angle_parameter_c1-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:left_heading_angle_parameter_c1-val is deprecated.  Use message_project_s-msg:left_heading_angle_parameter_c1 instead.")
  (left_heading_angle_parameter_c1 m))

(cl:ensure-generic-function 'left_view_range-val :lambda-list '(m))
(cl:defmethod left_view_range-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:left_view_range-val is deprecated.  Use message_project_s-msg:left_view_range instead.")
  (left_view_range m))

(cl:ensure-generic-function 'left_view_range_availability-val :lambda-list '(m))
(cl:defmethod left_view_range_availability-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:left_view_range_availability-val is deprecated.  Use message_project_s-msg:left_view_range_availability instead.")
  (left_view_range_availability m))

(cl:ensure-generic-function 'right_lane_type-val :lambda-list '(m))
(cl:defmethod right_lane_type-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:right_lane_type-val is deprecated.  Use message_project_s-msg:right_lane_type instead.")
  (right_lane_type m))

(cl:ensure-generic-function 'right_quality-val :lambda-list '(m))
(cl:defmethod right_quality-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:right_quality-val is deprecated.  Use message_project_s-msg:right_quality instead.")
  (right_quality m))

(cl:ensure-generic-function 'right_model_degree-val :lambda-list '(m))
(cl:defmethod right_model_degree-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:right_model_degree-val is deprecated.  Use message_project_s-msg:right_model_degree instead.")
  (right_model_degree m))

(cl:ensure-generic-function 'right_position_parameter_c0-val :lambda-list '(m))
(cl:defmethod right_position_parameter_c0-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:right_position_parameter_c0-val is deprecated.  Use message_project_s-msg:right_position_parameter_c0 instead.")
  (right_position_parameter_c0 m))

(cl:ensure-generic-function 'right_curvature_parameter_c2-val :lambda-list '(m))
(cl:defmethod right_curvature_parameter_c2-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:right_curvature_parameter_c2-val is deprecated.  Use message_project_s-msg:right_curvature_parameter_c2 instead.")
  (right_curvature_parameter_c2 m))

(cl:ensure-generic-function 'right_curvature_derivative_parameter_c3-val :lambda-list '(m))
(cl:defmethod right_curvature_derivative_parameter_c3-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:right_curvature_derivative_parameter_c3-val is deprecated.  Use message_project_s-msg:right_curvature_derivative_parameter_c3 instead.")
  (right_curvature_derivative_parameter_c3 m))

(cl:ensure-generic-function 'right_marking_width-val :lambda-list '(m))
(cl:defmethod right_marking_width-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:right_marking_width-val is deprecated.  Use message_project_s-msg:right_marking_width instead.")
  (right_marking_width m))

(cl:ensure-generic-function 'right_heading_angle_parameter_c1-val :lambda-list '(m))
(cl:defmethod right_heading_angle_parameter_c1-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:right_heading_angle_parameter_c1-val is deprecated.  Use message_project_s-msg:right_heading_angle_parameter_c1 instead.")
  (right_heading_angle_parameter_c1 m))

(cl:ensure-generic-function 'right_view_range-val :lambda-list '(m))
(cl:defmethod right_view_range-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:right_view_range-val is deprecated.  Use message_project_s-msg:right_view_range instead.")
  (right_view_range m))

(cl:ensure-generic-function 'right_view_range_availability-val :lambda-list '(m))
(cl:defmethod right_view_range_availability-val ((m <LaneAlignmentME_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:right_view_range_availability-val is deprecated.  Use message_project_s-msg:right_view_range_availability instead.")
  (right_view_range_availability m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LaneAlignmentME_1>) ostream)
  "Serializes a message object of type '<LaneAlignmentME_1>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_lane_type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_quality)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_model_degree)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_position_parameter_c0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_curvature_parameter_c2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_curvature_derivative_parameter_c3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_marking_width))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_heading_angle_parameter_c1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_view_range))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'left_view_range_availability) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_lane_type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_quality)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_model_degree)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_position_parameter_c0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_curvature_parameter_c2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_curvature_derivative_parameter_c3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_marking_width))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_heading_angle_parameter_c1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_view_range))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'right_view_range_availability) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LaneAlignmentME_1>) istream)
  "Deserializes a message object of type '<LaneAlignmentME_1>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_lane_type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_quality)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left_model_degree)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_position_parameter_c0) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_curvature_parameter_c2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_curvature_derivative_parameter_c3) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_marking_width) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_heading_angle_parameter_c1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_view_range) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'left_view_range_availability) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_lane_type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_quality)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right_model_degree)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_position_parameter_c0) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_curvature_parameter_c2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_curvature_derivative_parameter_c3) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_marking_width) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_heading_angle_parameter_c1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_view_range) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'right_view_range_availability) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LaneAlignmentME_1>)))
  "Returns string type for a message object of type '<LaneAlignmentME_1>"
  "message_project_s/LaneAlignmentME_1")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LaneAlignmentME_1)))
  "Returns string type for a message object of type 'LaneAlignmentME_1"
  "message_project_s/LaneAlignmentME_1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LaneAlignmentME_1>)))
  "Returns md5sum for a message object of type '<LaneAlignmentME_1>"
  "879c0a765df264cb0b3a43d9c8f4f61a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LaneAlignmentME_1)))
  "Returns md5sum for a message object of type 'LaneAlignmentME_1"
  "879c0a765df264cb0b3a43d9c8f4f61a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LaneAlignmentME_1>)))
  "Returns full string definition for message of type '<LaneAlignmentME_1>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%uint8 left_lane_type~%uint8 left_quality~%uint8 left_model_degree~%float64 left_position_parameter_c0~%float64 left_curvature_parameter_c2~%float64 left_curvature_derivative_parameter_c3~%float32 left_marking_width~%float64 left_heading_angle_parameter_c1~%float32 left_view_range~%bool left_view_range_availability~%~%uint8 right_lane_type~%uint8 right_quality~%uint8 right_model_degree~%float64 right_position_parameter_c0~%float64 right_curvature_parameter_c2~%float64 right_curvature_derivative_parameter_c3~%float32 right_marking_width~%float64 right_heading_angle_parameter_c1~%float32 right_view_range~%bool right_view_range_availability~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LaneAlignmentME_1)))
  "Returns full string definition for message of type 'LaneAlignmentME_1"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%uint8 left_lane_type~%uint8 left_quality~%uint8 left_model_degree~%float64 left_position_parameter_c0~%float64 left_curvature_parameter_c2~%float64 left_curvature_derivative_parameter_c3~%float32 left_marking_width~%float64 left_heading_angle_parameter_c1~%float32 left_view_range~%bool left_view_range_availability~%~%uint8 right_lane_type~%uint8 right_quality~%uint8 right_model_degree~%float64 right_position_parameter_c0~%float64 right_curvature_parameter_c2~%float64 right_curvature_derivative_parameter_c3~%float32 right_marking_width~%float64 right_heading_angle_parameter_c1~%float32 right_view_range~%bool right_view_range_availability~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LaneAlignmentME_1>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     1
     1
     1
     8
     8
     8
     4
     8
     4
     1
     1
     1
     1
     8
     8
     8
     4
     8
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LaneAlignmentME_1>))
  "Converts a ROS message object to a list"
  (cl:list 'LaneAlignmentME_1
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':left_lane_type (left_lane_type msg))
    (cl:cons ':left_quality (left_quality msg))
    (cl:cons ':left_model_degree (left_model_degree msg))
    (cl:cons ':left_position_parameter_c0 (left_position_parameter_c0 msg))
    (cl:cons ':left_curvature_parameter_c2 (left_curvature_parameter_c2 msg))
    (cl:cons ':left_curvature_derivative_parameter_c3 (left_curvature_derivative_parameter_c3 msg))
    (cl:cons ':left_marking_width (left_marking_width msg))
    (cl:cons ':left_heading_angle_parameter_c1 (left_heading_angle_parameter_c1 msg))
    (cl:cons ':left_view_range (left_view_range msg))
    (cl:cons ':left_view_range_availability (left_view_range_availability msg))
    (cl:cons ':right_lane_type (right_lane_type msg))
    (cl:cons ':right_quality (right_quality msg))
    (cl:cons ':right_model_degree (right_model_degree msg))
    (cl:cons ':right_position_parameter_c0 (right_position_parameter_c0 msg))
    (cl:cons ':right_curvature_parameter_c2 (right_curvature_parameter_c2 msg))
    (cl:cons ':right_curvature_derivative_parameter_c3 (right_curvature_derivative_parameter_c3 msg))
    (cl:cons ':right_marking_width (right_marking_width msg))
    (cl:cons ':right_heading_angle_parameter_c1 (right_heading_angle_parameter_c1 msg))
    (cl:cons ':right_view_range (right_view_range msg))
    (cl:cons ':right_view_range_availability (right_view_range_availability msg))
))
