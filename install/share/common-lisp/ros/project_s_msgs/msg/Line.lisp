; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude Line.msg.html

(cl:defclass <Line> (roslisp-msg-protocol:ros-message)
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
   (segment
    :reader segment
    :initarg :segment
    :type (cl:vector project_s_msgs-msg:Segment)
   :initform (cl:make-array 3000 :element-type 'project_s_msgs-msg:Segment :initial-element (cl:make-instance 'project_s_msgs-msg:Segment)))
   (QtySegment
    :reader QtySegment
    :initarg :QtySegment
    :type std_msgs-msg:UInt16
    :initform (cl:make-instance 'std_msgs-msg:UInt16))
   (lineClass
    :reader lineClass
    :initarg :lineClass
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (idPiste
    :reader idPiste
    :initarg :idPiste
    :type (cl:vector std_msgs-msg:UInt16)
   :initform (cl:make-array 2 :element-type 'std_msgs-msg:UInt16 :initial-element (cl:make-instance 'std_msgs-msg:UInt16)))
   (existenceState
    :reader existenceState
    :initarg :existenceState
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (scoreDetection
    :reader scoreDetection
    :initarg :scoreDetection
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (nbrDetection
    :reader nbrDetection
    :initarg :nbrDetection
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (nbrVisibility
    :reader nbrVisibility
    :initarg :nbrVisibility
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (scorePersistence
    :reader scorePersistence
    :initarg :scorePersistence
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (nbrUpdate
    :reader nbrUpdate
    :initarg :nbrUpdate
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32))
   (nbrAge
    :reader nbrAge
    :initarg :nbrAge
    :type std_msgs-msg:Float32
    :initform (cl:make-instance 'std_msgs-msg:Float32)))
)

(cl:defclass Line (<Line>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Line>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Line)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<Line> is deprecated: use project_s_msgs-msg:Line instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'segment-val :lambda-list '(m))
(cl:defmethod segment-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:segment-val is deprecated.  Use project_s_msgs-msg:segment instead.")
  (segment m))

(cl:ensure-generic-function 'QtySegment-val :lambda-list '(m))
(cl:defmethod QtySegment-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:QtySegment-val is deprecated.  Use project_s_msgs-msg:QtySegment instead.")
  (QtySegment m))

(cl:ensure-generic-function 'lineClass-val :lambda-list '(m))
(cl:defmethod lineClass-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:lineClass-val is deprecated.  Use project_s_msgs-msg:lineClass instead.")
  (lineClass m))

(cl:ensure-generic-function 'idPiste-val :lambda-list '(m))
(cl:defmethod idPiste-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:idPiste-val is deprecated.  Use project_s_msgs-msg:idPiste instead.")
  (idPiste m))

(cl:ensure-generic-function 'existenceState-val :lambda-list '(m))
(cl:defmethod existenceState-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:existenceState-val is deprecated.  Use project_s_msgs-msg:existenceState instead.")
  (existenceState m))

(cl:ensure-generic-function 'scoreDetection-val :lambda-list '(m))
(cl:defmethod scoreDetection-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:scoreDetection-val is deprecated.  Use project_s_msgs-msg:scoreDetection instead.")
  (scoreDetection m))

(cl:ensure-generic-function 'nbrDetection-val :lambda-list '(m))
(cl:defmethod nbrDetection-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbrDetection-val is deprecated.  Use project_s_msgs-msg:nbrDetection instead.")
  (nbrDetection m))

(cl:ensure-generic-function 'nbrVisibility-val :lambda-list '(m))
(cl:defmethod nbrVisibility-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbrVisibility-val is deprecated.  Use project_s_msgs-msg:nbrVisibility instead.")
  (nbrVisibility m))

(cl:ensure-generic-function 'scorePersistence-val :lambda-list '(m))
(cl:defmethod scorePersistence-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:scorePersistence-val is deprecated.  Use project_s_msgs-msg:scorePersistence instead.")
  (scorePersistence m))

(cl:ensure-generic-function 'nbrUpdate-val :lambda-list '(m))
(cl:defmethod nbrUpdate-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbrUpdate-val is deprecated.  Use project_s_msgs-msg:nbrUpdate instead.")
  (nbrUpdate m))

(cl:ensure-generic-function 'nbrAge-val :lambda-list '(m))
(cl:defmethod nbrAge-val ((m <Line>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:nbrAge-val is deprecated.  Use project_s_msgs-msg:nbrAge instead.")
  (nbrAge m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<Line>)))
    "Constants for message type '<Line>"
  '((:SEGMENT_REPORT_SIZE . 3000))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'Line)))
    "Constants for message type 'Line"
  '((:SEGMENT_REPORT_SIZE . 3000))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Line>) ostream)
  "Serializes a message object of type '<Line>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'segment))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'QtySegment) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'lineClass) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'idPiste))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'existenceState) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'scoreDetection) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbrDetection) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbrVisibility) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'scorePersistence) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbrUpdate) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nbrAge) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Line>) istream)
  "Deserializes a message object of type '<Line>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (cl:setf (cl:slot-value msg 'segment) (cl:make-array 3000))
  (cl:let ((vals (cl:slot-value msg 'segment)))
    (cl:dotimes (i 3000)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:Segment))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'QtySegment) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'lineClass) istream)
  (cl:setf (cl:slot-value msg 'idPiste) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'idPiste)))
    (cl:dotimes (i 2)
    (cl:setf (cl:aref vals i) (cl:make-instance 'std_msgs-msg:UInt16))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'existenceState) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'scoreDetection) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbrDetection) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbrVisibility) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'scorePersistence) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbrUpdate) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nbrAge) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Line>)))
  "Returns string type for a message object of type '<Line>"
  "project_s_msgs/Line")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Line)))
  "Returns string type for a message object of type 'Line"
  "project_s_msgs/Line")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Line>)))
  "Returns md5sum for a message object of type '<Line>"
  "76c1d98fd2e545accf02a06698e73bb3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Line)))
  "Returns md5sum for a message object of type 'Line"
  "76c1d98fd2e545accf02a06698e73bb3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Line>)))
  "Returns full string definition for message of type '<Line>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%uint16 SEGMENT_REPORT_SIZE = 3000~%project_s_msgs/Segment[3000] segment~%std_msgs/UInt16 QtySegment~%std_msgs/Float32 lineClass	# class of the line~%std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)~%~%std_msgs/UInt8 existenceState~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/Segment~%std_msgs/Float32 length		# length of the segment~%std_msgs/Float32 angle		# angle of the segment~%geometry_msgs/Point position~%geometry_msgs/Twist Velocity~%~%float32 offset~%float64 latitude~%float64 longitude~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Line)))
  "Returns full string definition for message of type 'Line"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%uint16 SEGMENT_REPORT_SIZE = 3000~%project_s_msgs/Segment[3000] segment~%std_msgs/UInt16 QtySegment~%std_msgs/Float32 lineClass	# class of the line~%std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)~%~%std_msgs/UInt8 existenceState~%std_msgs/Float32 scoreDetection~%std_msgs/Float32 nbrDetection~%std_msgs/Float32 nbrVisibility~%std_msgs/Float32 scorePersistence~%std_msgs/Float32 nbrUpdate~%std_msgs/Float32 nbrAge~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/Segment~%std_msgs/Float32 length		# length of the segment~%std_msgs/Float32 angle		# angle of the segment~%geometry_msgs/Point position~%geometry_msgs/Twist Velocity~%~%float32 offset~%float64 latitude~%float64 longitude~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Line>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'segment) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'QtySegment))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'lineClass))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'idPiste) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'existenceState))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'scoreDetection))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbrDetection))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbrVisibility))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'scorePersistence))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbrUpdate))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nbrAge))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Line>))
  "Converts a ROS message object to a list"
  (cl:list 'Line
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':segment (segment msg))
    (cl:cons ':QtySegment (QtySegment msg))
    (cl:cons ':lineClass (lineClass msg))
    (cl:cons ':idPiste (idPiste msg))
    (cl:cons ':existenceState (existenceState msg))
    (cl:cons ':scoreDetection (scoreDetection msg))
    (cl:cons ':nbrDetection (nbrDetection msg))
    (cl:cons ':nbrVisibility (nbrVisibility msg))
    (cl:cons ':scorePersistence (scorePersistence msg))
    (cl:cons ':nbrUpdate (nbrUpdate msg))
    (cl:cons ':nbrAge (nbrAge msg))
))
