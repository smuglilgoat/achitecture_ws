; Auto-generated. Do not edit!


(cl:in-package message_project_s-msg)


;//! \htmlinclude EgoDataReport.msg.html

(cl:defclass <EgoDataReport> (roslisp-msg-protocol:ros-message)
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
   (EgoData
    :reader EgoData
    :initarg :EgoData
    :type (cl:vector message_project_s-msg:EgoData)
   :initform (cl:make-array 10 :element-type 'message_project_s-msg:EgoData :initial-element (cl:make-instance 'message_project_s-msg:EgoData))))
)

(cl:defclass EgoDataReport (<EgoDataReport>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EgoDataReport>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EgoDataReport)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name message_project_s-msg:<EgoDataReport> is deprecated: use message_project_s-msg:EgoDataReport instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <EgoDataReport>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:header-val is deprecated.  Use message_project_s-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <EgoDataReport>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:id-val is deprecated.  Use message_project_s-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'EgoData-val :lambda-list '(m))
(cl:defmethod EgoData-val ((m <EgoDataReport>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader message_project_s-msg:EgoData-val is deprecated.  Use message_project_s-msg:EgoData instead.")
  (EgoData m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<EgoDataReport>)))
    "Constants for message type '<EgoDataReport>"
  '((:NBR_MAX_EGO_DATA . 10))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'EgoDataReport)))
    "Constants for message type 'EgoDataReport"
  '((:NBR_MAX_EGO_DATA . 10))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EgoDataReport>) ostream)
  "Serializes a message object of type '<EgoDataReport>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'EgoData))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EgoDataReport>) istream)
  "Deserializes a message object of type '<EgoDataReport>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (cl:setf (cl:slot-value msg 'EgoData) (cl:make-array 10))
  (cl:let ((vals (cl:slot-value msg 'EgoData)))
    (cl:dotimes (i 10)
    (cl:setf (cl:aref vals i) (cl:make-instance 'message_project_s-msg:EgoData))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EgoDataReport>)))
  "Returns string type for a message object of type '<EgoDataReport>"
  "message_project_s/EgoDataReport")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EgoDataReport)))
  "Returns string type for a message object of type 'EgoDataReport"
  "message_project_s/EgoDataReport")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EgoDataReport>)))
  "Returns md5sum for a message object of type '<EgoDataReport>"
  "81b9e8f980ada541cb5d9103d33a8e95")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EgoDataReport)))
  "Returns md5sum for a message object of type 'EgoDataReport"
  "81b9e8f980ada541cb5d9103d33a8e95")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EgoDataReport>)))
  "Returns full string definition for message of type '<EgoDataReport>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%uint8 NBR_MAX_EGO_DATA = 10~%message_project_s/EgoData[10] EgoData	# en concordance avec NBR_MAX_EGO_DATA/vehicle.cpp, local_tracks_synchro, global_tracks_prediction, road_model~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: message_project_s/EgoData~%time stamp~%~%geometry_msgs/Twist velocity~%geometry_msgs/Accel acceleration~%~%float64 latitude~%float64 longitude~%float64 cap~%~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EgoDataReport)))
  "Returns full string definition for message of type 'EgoDataReport"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%uint8 NBR_MAX_EGO_DATA = 10~%message_project_s/EgoData[10] EgoData	# en concordance avec NBR_MAX_EGO_DATA/vehicle.cpp, local_tracks_synchro, global_tracks_prediction, road_model~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: message_project_s/EgoData~%time stamp~%~%geometry_msgs/Twist velocity~%geometry_msgs/Accel acceleration~%~%float64 latitude~%float64 longitude~%float64 cap~%~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EgoDataReport>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'EgoData) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EgoDataReport>))
  "Converts a ROS message object to a list"
  (cl:list 'EgoDataReport
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':EgoData (EgoData msg))
))
