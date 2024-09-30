; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ObjectManoeuvre.msg.html

(cl:defclass <ObjectManoeuvre> (roslisp-msg-protocol:ros-message)
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
   (indexOriginLane
    :reader indexOriginLane
    :initarg :indexOriginLane
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (objectManoeuvre
    :reader objectManoeuvre
    :initarg :objectManoeuvre
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (objectSignalisation
    :reader objectSignalisation
    :initarg :objectSignalisation
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (objectPrediction
    :reader objectPrediction
    :initarg :objectPrediction
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (objectPredictionProbability
    :reader objectPredictionProbability
    :initarg :objectPredictionProbability
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8)))
)

(cl:defclass ObjectManoeuvre (<ObjectManoeuvre>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ObjectManoeuvre>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ObjectManoeuvre)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ObjectManoeuvre> is deprecated: use project_s_msgs-msg:ObjectManoeuvre instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ObjectManoeuvre>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ObjectManoeuvre>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'indexOriginLane-val :lambda-list '(m))
(cl:defmethod indexOriginLane-val ((m <ObjectManoeuvre>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:indexOriginLane-val is deprecated.  Use project_s_msgs-msg:indexOriginLane instead.")
  (indexOriginLane m))

(cl:ensure-generic-function 'objectManoeuvre-val :lambda-list '(m))
(cl:defmethod objectManoeuvre-val ((m <ObjectManoeuvre>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:objectManoeuvre-val is deprecated.  Use project_s_msgs-msg:objectManoeuvre instead.")
  (objectManoeuvre m))

(cl:ensure-generic-function 'objectSignalisation-val :lambda-list '(m))
(cl:defmethod objectSignalisation-val ((m <ObjectManoeuvre>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:objectSignalisation-val is deprecated.  Use project_s_msgs-msg:objectSignalisation instead.")
  (objectSignalisation m))

(cl:ensure-generic-function 'objectPrediction-val :lambda-list '(m))
(cl:defmethod objectPrediction-val ((m <ObjectManoeuvre>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:objectPrediction-val is deprecated.  Use project_s_msgs-msg:objectPrediction instead.")
  (objectPrediction m))

(cl:ensure-generic-function 'objectPredictionProbability-val :lambda-list '(m))
(cl:defmethod objectPredictionProbability-val ((m <ObjectManoeuvre>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:objectPredictionProbability-val is deprecated.  Use project_s_msgs-msg:objectPredictionProbability instead.")
  (objectPredictionProbability m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ObjectManoeuvre>) ostream)
  "Serializes a message object of type '<ObjectManoeuvre>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'indexOriginLane) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'objectManoeuvre) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'objectSignalisation) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'objectPrediction) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'objectPredictionProbability) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ObjectManoeuvre>) istream)
  "Deserializes a message object of type '<ObjectManoeuvre>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'indexOriginLane) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'objectManoeuvre) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'objectSignalisation) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'objectPrediction) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'objectPredictionProbability) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ObjectManoeuvre>)))
  "Returns string type for a message object of type '<ObjectManoeuvre>"
  "project_s_msgs/ObjectManoeuvre")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ObjectManoeuvre)))
  "Returns string type for a message object of type 'ObjectManoeuvre"
  "project_s_msgs/ObjectManoeuvre")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ObjectManoeuvre>)))
  "Returns md5sum for a message object of type '<ObjectManoeuvre>"
  "fa042f189b42a91d1a2d603726c850b7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ObjectManoeuvre)))
  "Returns md5sum for a message object of type 'ObjectManoeuvre"
  "fa042f189b42a91d1a2d603726c850b7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ObjectManoeuvre>)))
  "Returns full string definition for message of type '<ObjectManoeuvre>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 indexOriginLane~%std_msgs/UInt8 objectManoeuvre~%std_msgs/UInt8 objectSignalisation~%std_msgs/UInt8 objectPrediction~%std_msgs/UInt8 objectPredictionProbability~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ObjectManoeuvre)))
  "Returns full string definition for message of type 'ObjectManoeuvre"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 indexOriginLane~%std_msgs/UInt8 objectManoeuvre~%std_msgs/UInt8 objectSignalisation~%std_msgs/UInt8 objectPrediction~%std_msgs/UInt8 objectPredictionProbability~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ObjectManoeuvre>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'indexOriginLane))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'objectManoeuvre))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'objectSignalisation))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'objectPrediction))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'objectPredictionProbability))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ObjectManoeuvre>))
  "Converts a ROS message object to a list"
  (cl:list 'ObjectManoeuvre
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':indexOriginLane (indexOriginLane msg))
    (cl:cons ':objectManoeuvre (objectManoeuvre msg))
    (cl:cons ':objectSignalisation (objectSignalisation msg))
    (cl:cons ':objectPrediction (objectPrediction msg))
    (cl:cons ':objectPredictionProbability (objectPredictionProbability msg))
))
