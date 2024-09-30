; Auto-generated. Do not edit!


(cl:in-package message_project_s-msg)


;//! \htmlinclude esrsrr.msg.html

(cl:defclass <esrsrr> (roslisp-msg-protocol:ros-message)
  ((stampsrr
    :reader stampsrr
    :initarg :stampsrr
    :type cl:real
    :initform 0)
   (stampesr
    :reader stampesr
    :initarg :stampesr
    :type cl:real
    :initform 0)
   (seqesr
    :reader seqesr
    :initarg :seqesr
    :type cl:integer
    :initform 0)
   (can_dsp_ts
    :reader can_dsp_ts
    :initarg :can_dsp_ts
    :type cl:integer
    :initform 0))
)

(cl:defclass esrsrr (<esrsrr>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <esrsrr>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'esrsrr)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name message_project_s-msg:<esrsrr> is deprecated: use message_project_s-msg:esrsrr instead.")))

(cl:ensure-generic-function 'stampsrr-val :lambda-list '(m))
(cl:defmethod stampsrr-val ((m <esrsrr>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:stampsrr-val is deprecated.  Use message_project_s-msg:stampsrr instead.")
  (stampsrr m))

(cl:ensure-generic-function 'stampesr-val :lambda-list '(m))
(cl:defmethod stampesr-val ((m <esrsrr>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:stampesr-val is deprecated.  Use message_project_s-msg:stampesr instead.")
  (stampesr m))

(cl:ensure-generic-function 'seqesr-val :lambda-list '(m))
(cl:defmethod seqesr-val ((m <esrsrr>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:seqesr-val is deprecated.  Use message_project_s-msg:seqesr instead.")
  (seqesr m))

(cl:ensure-generic-function 'can_dsp_ts-val :lambda-list '(m))
(cl:defmethod can_dsp_ts-val ((m <esrsrr>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:can_dsp_ts-val is deprecated.  Use message_project_s-msg:can_dsp_ts instead.")
  (can_dsp_ts m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <esrsrr>) ostream)
  "Serializes a message object of type '<esrsrr>"
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'stampsrr)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'stampsrr) (cl:floor (cl:slot-value msg 'stampsrr)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'stampesr)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'stampesr) (cl:floor (cl:slot-value msg 'stampesr)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'seqesr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'seqesr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'seqesr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'seqesr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'can_dsp_ts)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'can_dsp_ts)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'can_dsp_ts)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'can_dsp_ts)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <esrsrr>) istream)
  "Deserializes a message object of type '<esrsrr>"
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stampsrr) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stampesr) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'seqesr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'seqesr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'seqesr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'seqesr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'can_dsp_ts)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'can_dsp_ts)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'can_dsp_ts)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'can_dsp_ts)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<esrsrr>)))
  "Returns string type for a message object of type '<esrsrr>"
  "message_project_s/esrsrr")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'esrsrr)))
  "Returns string type for a message object of type 'esrsrr"
  "message_project_s/esrsrr")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<esrsrr>)))
  "Returns md5sum for a message object of type '<esrsrr>"
  "67e39e1d269819b2e9c170bc6fb5fbb5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'esrsrr)))
  "Returns md5sum for a message object of type 'esrsrr"
  "67e39e1d269819b2e9c170bc6fb5fbb5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<esrsrr>)))
  "Returns full string definition for message of type '<esrsrr>"
  (cl:format cl:nil "~%time stampsrr~%time stampesr~%uint32 seqesr~%uint32 can_dsp_ts~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'esrsrr)))
  "Returns full string definition for message of type 'esrsrr"
  (cl:format cl:nil "~%time stampsrr~%time stampesr~%uint32 seqesr~%uint32 can_dsp_ts~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <esrsrr>))
  (cl:+ 0
     8
     8
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <esrsrr>))
  "Converts a ROS message object to a list"
  (cl:list 'esrsrr
    (cl:cons ':stampsrr (stampsrr msg))
    (cl:cons ':stampesr (stampesr msg))
    (cl:cons ':seqesr (seqesr msg))
    (cl:cons ':can_dsp_ts (can_dsp_ts msg))
))
