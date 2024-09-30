; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude Side.msg.html

(cl:defclass <Side> (roslisp-msg-protocol:ros-message)
  ((segment
    :reader segment
    :initarg :segment
    :type (cl:vector project_s_msgs-msg:Segment)
   :initform (cl:make-array 100 :element-type 'project_s_msgs-msg:Segment :initial-element (cl:make-instance 'project_s_msgs-msg:Segment))))
)

(cl:defclass Side (<Side>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Side>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Side)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<Side> is deprecated: use project_s_msgs-msg:Side instead.")))

(cl:ensure-generic-function 'segment-val :lambda-list '(m))
(cl:defmethod segment-val ((m <Side>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:segment-val is deprecated.  Use project_s_msgs-msg:segment instead.")
  (segment m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Side>) ostream)
  "Serializes a message object of type '<Side>"
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'segment))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Side>) istream)
  "Deserializes a message object of type '<Side>"
  (cl:setf (cl:slot-value msg 'segment) (cl:make-array 100))
  (cl:let ((vals (cl:slot-value msg 'segment)))
    (cl:dotimes (i 100)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:Segment))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Side>)))
  "Returns string type for a message object of type '<Side>"
  "project_s_msgs/Side")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Side)))
  "Returns string type for a message object of type 'Side"
  "project_s_msgs/Side")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Side>)))
  "Returns md5sum for a message object of type '<Side>"
  "3cee93af1c46f02386b8de1d0844998c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Side)))
  "Returns md5sum for a message object of type 'Side"
  "3cee93af1c46f02386b8de1d0844998c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Side>)))
  "Returns full string definition for message of type '<Side>"
  (cl:format cl:nil "project_s_msgs/Segment[100] segment~%~%================================================================================~%MSG: project_s_msgs/Segment~%std_msgs/Float32 length		# length of the segment~%std_msgs/Float32 angle		# angle of the segment~%geometry_msgs/Point position~%geometry_msgs/Twist Velocity~%~%float32 offset~%float64 latitude~%float64 longitude~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Side)))
  "Returns full string definition for message of type 'Side"
  (cl:format cl:nil "project_s_msgs/Segment[100] segment~%~%================================================================================~%MSG: project_s_msgs/Segment~%std_msgs/Float32 length		# length of the segment~%std_msgs/Float32 angle		# angle of the segment~%geometry_msgs/Point position~%geometry_msgs/Twist Velocity~%~%float32 offset~%float64 latitude~%float64 longitude~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Side>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'segment) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Side>))
  "Converts a ROS message object to a list"
  (cl:list 'Side
    (cl:cons ':segment (segment msg))
))
