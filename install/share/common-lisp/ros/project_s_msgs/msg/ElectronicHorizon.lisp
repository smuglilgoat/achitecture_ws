; Auto-generated. Do not edit!


(cl:in-package project_s_msgs-msg)


;//! \htmlinclude ElectronicHorizon.msg.html

(cl:defclass <ElectronicHorizon> (roslisp-msg-protocol:ros-message)
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
   (indexPath
    :reader indexPath
    :initarg :indexPath
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (ehSegment
    :reader ehSegment
    :initarg :ehSegment
    :type (cl:vector project_s_msgs-msg:ehSegment)
   :initform (cl:make-array 50 :element-type 'project_s_msgs-msg:ehSegment :initial-element (cl:make-instance 'project_s_msgs-msg:ehSegment)))
   (NbrSegment
    :reader NbrSegment
    :initarg :NbrSegment
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (ehStub
    :reader ehStub
    :initarg :ehStub
    :type (cl:vector project_s_msgs-msg:ehStub)
   :initform (cl:make-array 10 :element-type 'project_s_msgs-msg:ehStub :initial-element (cl:make-instance 'project_s_msgs-msg:ehStub)))
   (NbrStub
    :reader NbrStub
    :initarg :NbrStub
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (ehSpotCurvature
    :reader ehSpotCurvature
    :initarg :ehSpotCurvature
    :type (cl:vector project_s_msgs-msg:ehSpotCurvature)
   :initform (cl:make-array 300 :element-type 'project_s_msgs-msg:ehSpotCurvature :initial-element (cl:make-instance 'project_s_msgs-msg:ehSpotCurvature)))
   (NbrSpotCurvature
    :reader NbrSpotCurvature
    :initarg :NbrSpotCurvature
    :type std_msgs-msg:UInt16
    :initform (cl:make-instance 'std_msgs-msg:UInt16))
   (ehSpotCoordGeoRight
    :reader ehSpotCoordGeoRight
    :initarg :ehSpotCoordGeoRight
    :type (cl:vector project_s_msgs-msg:ehSpotCoordGeo)
   :initform (cl:make-array 2000 :element-type 'project_s_msgs-msg:ehSpotCoordGeo :initial-element (cl:make-instance 'project_s_msgs-msg:ehSpotCoordGeo)))
   (NbrSpotCoordGeoRight
    :reader NbrSpotCoordGeoRight
    :initarg :NbrSpotCoordGeoRight
    :type std_msgs-msg:UInt16
    :initform (cl:make-instance 'std_msgs-msg:UInt16))
   (ehSpotCoordGeoLeft
    :reader ehSpotCoordGeoLeft
    :initarg :ehSpotCoordGeoLeft
    :type (cl:vector project_s_msgs-msg:ehSpotCoordGeo)
   :initform (cl:make-array 2000 :element-type 'project_s_msgs-msg:ehSpotCoordGeo :initial-element (cl:make-instance 'project_s_msgs-msg:ehSpotCoordGeo)))
   (NbrSpotCoordGeoLeft
    :reader NbrSpotCoordGeoLeft
    :initarg :NbrSpotCoordGeoLeft
    :type std_msgs-msg:UInt16
    :initform (cl:make-instance 'std_msgs-msg:UInt16))
   (ehLineCoordGeo
    :reader ehLineCoordGeo
    :initarg :ehLineCoordGeo
    :type (cl:vector project_s_msgs-msg:ehLineCoordGeo)
   :initform (cl:make-array 10 :element-type 'project_s_msgs-msg:ehLineCoordGeo :initial-element (cl:make-instance 'project_s_msgs-msg:ehLineCoordGeo)))
   (QtyLineCoordGeo
    :reader QtyLineCoordGeo
    :initarg :QtyLineCoordGeo
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (ehME
    :reader ehME
    :initarg :ehME
    :type (cl:vector project_s_msgs-msg:ehME)
   :initform (cl:make-array 2 :element-type 'project_s_msgs-msg:ehME :initial-element (cl:make-instance 'project_s_msgs-msg:ehME)))
   (ehNbrLineCoordGeo
    :reader ehNbrLineCoordGeo
    :initarg :ehNbrLineCoordGeo
    :type (cl:vector project_s_msgs-msg:ehNbrLineCoordGeo)
   :initform (cl:make-array 100 :element-type 'project_s_msgs-msg:ehNbrLineCoordGeo :initial-element (cl:make-instance 'project_s_msgs-msg:ehNbrLineCoordGeo)))
   (QtyNbrLineCoordGeo
    :reader QtyNbrLineCoordGeo
    :initarg :QtyNbrLineCoordGeo
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (ehSpotTrafficSign
    :reader ehSpotTrafficSign
    :initarg :ehSpotTrafficSign
    :type (cl:vector project_s_msgs-msg:ehSpotTrafficSign)
   :initform (cl:make-array 50 :element-type 'project_s_msgs-msg:ehSpotTrafficSign :initial-element (cl:make-instance 'project_s_msgs-msg:ehSpotTrafficSign)))
   (NbrSpotTrafficSign
    :reader NbrSpotTrafficSign
    :initarg :NbrSpotTrafficSign
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (ehPosition
    :reader ehPosition
    :initarg :ehPosition
    :type project_s_msgs-msg:ehPosition
    :initform (cl:make-instance 'project_s_msgs-msg:ehPosition))
   (speedLimit_interpolMethod
    :reader speedLimit_interpolMethod
    :initarg :speedLimit_interpolMethod
    :type cl:fixnum
    :initform 0)
   (curvature_interpolMethod
    :reader curvature_interpolMethod
    :initarg :curvature_interpolMethod
    :type cl:fixnum
    :initform 0)
   (ehSegmentAO
    :reader ehSegmentAO
    :initarg :ehSegmentAO
    :type (cl:vector project_s_msgs-msg:ehSegmentME)
   :initform (cl:make-array 100 :element-type 'project_s_msgs-msg:ehSegmentME :initial-element (cl:make-instance 'project_s_msgs-msg:ehSegmentME)))
   (QtySegmentAO
    :reader QtySegmentAO
    :initarg :QtySegmentAO
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8))
   (ehSegmentEO
    :reader ehSegmentEO
    :initarg :ehSegmentEO
    :type (cl:vector project_s_msgs-msg:ehSegmentME)
   :initform (cl:make-array 100 :element-type 'project_s_msgs-msg:ehSegmentME :initial-element (cl:make-instance 'project_s_msgs-msg:ehSegmentME)))
   (QtySegmentEO
    :reader QtySegmentEO
    :initarg :QtySegmentEO
    :type std_msgs-msg:UInt8
    :initform (cl:make-instance 'std_msgs-msg:UInt8)))
)

(cl:defclass ElectronicHorizon (<ElectronicHorizon>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ElectronicHorizon>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ElectronicHorizon)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project_s_msgs-msg:<ElectronicHorizon> is deprecated: use project_s_msgs-msg:ElectronicHorizon instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:header-val is deprecated.  Use project_s_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:id-val is deprecated.  Use project_s_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'indexPath-val :lambda-list '(m))
(cl:defmethod indexPath-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:indexPath-val is deprecated.  Use project_s_msgs-msg:indexPath instead.")
  (indexPath m))

(cl:ensure-generic-function 'ehSegment-val :lambda-list '(m))
(cl:defmethod ehSegment-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehSegment-val is deprecated.  Use project_s_msgs-msg:ehSegment instead.")
  (ehSegment m))

(cl:ensure-generic-function 'NbrSegment-val :lambda-list '(m))
(cl:defmethod NbrSegment-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:NbrSegment-val is deprecated.  Use project_s_msgs-msg:NbrSegment instead.")
  (NbrSegment m))

(cl:ensure-generic-function 'ehStub-val :lambda-list '(m))
(cl:defmethod ehStub-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehStub-val is deprecated.  Use project_s_msgs-msg:ehStub instead.")
  (ehStub m))

(cl:ensure-generic-function 'NbrStub-val :lambda-list '(m))
(cl:defmethod NbrStub-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:NbrStub-val is deprecated.  Use project_s_msgs-msg:NbrStub instead.")
  (NbrStub m))

(cl:ensure-generic-function 'ehSpotCurvature-val :lambda-list '(m))
(cl:defmethod ehSpotCurvature-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehSpotCurvature-val is deprecated.  Use project_s_msgs-msg:ehSpotCurvature instead.")
  (ehSpotCurvature m))

(cl:ensure-generic-function 'NbrSpotCurvature-val :lambda-list '(m))
(cl:defmethod NbrSpotCurvature-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:NbrSpotCurvature-val is deprecated.  Use project_s_msgs-msg:NbrSpotCurvature instead.")
  (NbrSpotCurvature m))

(cl:ensure-generic-function 'ehSpotCoordGeoRight-val :lambda-list '(m))
(cl:defmethod ehSpotCoordGeoRight-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehSpotCoordGeoRight-val is deprecated.  Use project_s_msgs-msg:ehSpotCoordGeoRight instead.")
  (ehSpotCoordGeoRight m))

(cl:ensure-generic-function 'NbrSpotCoordGeoRight-val :lambda-list '(m))
(cl:defmethod NbrSpotCoordGeoRight-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:NbrSpotCoordGeoRight-val is deprecated.  Use project_s_msgs-msg:NbrSpotCoordGeoRight instead.")
  (NbrSpotCoordGeoRight m))

(cl:ensure-generic-function 'ehSpotCoordGeoLeft-val :lambda-list '(m))
(cl:defmethod ehSpotCoordGeoLeft-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehSpotCoordGeoLeft-val is deprecated.  Use project_s_msgs-msg:ehSpotCoordGeoLeft instead.")
  (ehSpotCoordGeoLeft m))

(cl:ensure-generic-function 'NbrSpotCoordGeoLeft-val :lambda-list '(m))
(cl:defmethod NbrSpotCoordGeoLeft-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:NbrSpotCoordGeoLeft-val is deprecated.  Use project_s_msgs-msg:NbrSpotCoordGeoLeft instead.")
  (NbrSpotCoordGeoLeft m))

(cl:ensure-generic-function 'ehLineCoordGeo-val :lambda-list '(m))
(cl:defmethod ehLineCoordGeo-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehLineCoordGeo-val is deprecated.  Use project_s_msgs-msg:ehLineCoordGeo instead.")
  (ehLineCoordGeo m))

(cl:ensure-generic-function 'QtyLineCoordGeo-val :lambda-list '(m))
(cl:defmethod QtyLineCoordGeo-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:QtyLineCoordGeo-val is deprecated.  Use project_s_msgs-msg:QtyLineCoordGeo instead.")
  (QtyLineCoordGeo m))

(cl:ensure-generic-function 'ehME-val :lambda-list '(m))
(cl:defmethod ehME-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehME-val is deprecated.  Use project_s_msgs-msg:ehME instead.")
  (ehME m))

(cl:ensure-generic-function 'ehNbrLineCoordGeo-val :lambda-list '(m))
(cl:defmethod ehNbrLineCoordGeo-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehNbrLineCoordGeo-val is deprecated.  Use project_s_msgs-msg:ehNbrLineCoordGeo instead.")
  (ehNbrLineCoordGeo m))

(cl:ensure-generic-function 'QtyNbrLineCoordGeo-val :lambda-list '(m))
(cl:defmethod QtyNbrLineCoordGeo-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:QtyNbrLineCoordGeo-val is deprecated.  Use project_s_msgs-msg:QtyNbrLineCoordGeo instead.")
  (QtyNbrLineCoordGeo m))

(cl:ensure-generic-function 'ehSpotTrafficSign-val :lambda-list '(m))
(cl:defmethod ehSpotTrafficSign-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehSpotTrafficSign-val is deprecated.  Use project_s_msgs-msg:ehSpotTrafficSign instead.")
  (ehSpotTrafficSign m))

(cl:ensure-generic-function 'NbrSpotTrafficSign-val :lambda-list '(m))
(cl:defmethod NbrSpotTrafficSign-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:NbrSpotTrafficSign-val is deprecated.  Use project_s_msgs-msg:NbrSpotTrafficSign instead.")
  (NbrSpotTrafficSign m))

(cl:ensure-generic-function 'ehPosition-val :lambda-list '(m))
(cl:defmethod ehPosition-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehPosition-val is deprecated.  Use project_s_msgs-msg:ehPosition instead.")
  (ehPosition m))

(cl:ensure-generic-function 'speedLimit_interpolMethod-val :lambda-list '(m))
(cl:defmethod speedLimit_interpolMethod-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:speedLimit_interpolMethod-val is deprecated.  Use project_s_msgs-msg:speedLimit_interpolMethod instead.")
  (speedLimit_interpolMethod m))

(cl:ensure-generic-function 'curvature_interpolMethod-val :lambda-list '(m))
(cl:defmethod curvature_interpolMethod-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:curvature_interpolMethod-val is deprecated.  Use project_s_msgs-msg:curvature_interpolMethod instead.")
  (curvature_interpolMethod m))

(cl:ensure-generic-function 'ehSegmentAO-val :lambda-list '(m))
(cl:defmethod ehSegmentAO-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehSegmentAO-val is deprecated.  Use project_s_msgs-msg:ehSegmentAO instead.")
  (ehSegmentAO m))

(cl:ensure-generic-function 'QtySegmentAO-val :lambda-list '(m))
(cl:defmethod QtySegmentAO-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:QtySegmentAO-val is deprecated.  Use project_s_msgs-msg:QtySegmentAO instead.")
  (QtySegmentAO m))

(cl:ensure-generic-function 'ehSegmentEO-val :lambda-list '(m))
(cl:defmethod ehSegmentEO-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:ehSegmentEO-val is deprecated.  Use project_s_msgs-msg:ehSegmentEO instead.")
  (ehSegmentEO m))

(cl:ensure-generic-function 'QtySegmentEO-val :lambda-list '(m))
(cl:defmethod QtySegmentEO-val ((m <ElectronicHorizon>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project_s_msgs-msg:QtySegmentEO-val is deprecated.  Use project_s_msgs-msg:QtySegmentEO instead.")
  (QtySegmentEO m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<ElectronicHorizon>)))
    "Constants for message type '<ElectronicHorizon>"
  '((:SEGMENT_REPORT_SIZE . 50)
    (:STUB_REPORT_SIZE . 10)
    (:SPOT_CURVATURE_REPORT_SIZE . 300)
    (:SPOT_COORD_GEO_REPORT_SIZE . 2000)
    (:LINE_REPORT_SIZE . 10)
    (:ME_RIGHT_LINE . 0)
    (:ME_LEFT_LINE . 1)
    (:NBR_LINE_REPORT_SIZE . 100)
    (:SPOT_TRAFFIC_SIGN_REPORT_SIZE . 50)
    (:STEP . 0)
    (:LINEAR . 1)
    (:SEGMENT_ARRET_OBSTACLE_REPORT_SIZE . 100)
    (:SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE . 100))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'ElectronicHorizon)))
    "Constants for message type 'ElectronicHorizon"
  '((:SEGMENT_REPORT_SIZE . 50)
    (:STUB_REPORT_SIZE . 10)
    (:SPOT_CURVATURE_REPORT_SIZE . 300)
    (:SPOT_COORD_GEO_REPORT_SIZE . 2000)
    (:LINE_REPORT_SIZE . 10)
    (:ME_RIGHT_LINE . 0)
    (:ME_LEFT_LINE . 1)
    (:NBR_LINE_REPORT_SIZE . 100)
    (:SPOT_TRAFFIC_SIGN_REPORT_SIZE . 50)
    (:STEP . 0)
    (:LINEAR . 1)
    (:SEGMENT_ARRET_OBSTACLE_REPORT_SIZE . 100)
    (:SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE . 100))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ElectronicHorizon>) ostream)
  "Serializes a message object of type '<ElectronicHorizon>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'indexPath) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehSegment))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'NbrSegment) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehStub))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'NbrStub) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehSpotCurvature))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'NbrSpotCurvature) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehSpotCoordGeoRight))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'NbrSpotCoordGeoRight) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehSpotCoordGeoLeft))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'NbrSpotCoordGeoLeft) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehLineCoordGeo))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'QtyLineCoordGeo) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehME))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehNbrLineCoordGeo))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'QtyNbrLineCoordGeo) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehSpotTrafficSign))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'NbrSpotTrafficSign) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'ehPosition) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'speedLimit_interpolMethod)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'curvature_interpolMethod)) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehSegmentAO))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'QtySegmentAO) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'ehSegmentEO))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'QtySegmentEO) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ElectronicHorizon>) istream)
  "Deserializes a message object of type '<ElectronicHorizon>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'indexPath) istream)
  (cl:setf (cl:slot-value msg 'ehSegment) (cl:make-array 50))
  (cl:let ((vals (cl:slot-value msg 'ehSegment)))
    (cl:dotimes (i 50)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehSegment))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'NbrSegment) istream)
  (cl:setf (cl:slot-value msg 'ehStub) (cl:make-array 10))
  (cl:let ((vals (cl:slot-value msg 'ehStub)))
    (cl:dotimes (i 10)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehStub))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'NbrStub) istream)
  (cl:setf (cl:slot-value msg 'ehSpotCurvature) (cl:make-array 300))
  (cl:let ((vals (cl:slot-value msg 'ehSpotCurvature)))
    (cl:dotimes (i 300)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehSpotCurvature))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'NbrSpotCurvature) istream)
  (cl:setf (cl:slot-value msg 'ehSpotCoordGeoRight) (cl:make-array 2000))
  (cl:let ((vals (cl:slot-value msg 'ehSpotCoordGeoRight)))
    (cl:dotimes (i 2000)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehSpotCoordGeo))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'NbrSpotCoordGeoRight) istream)
  (cl:setf (cl:slot-value msg 'ehSpotCoordGeoLeft) (cl:make-array 2000))
  (cl:let ((vals (cl:slot-value msg 'ehSpotCoordGeoLeft)))
    (cl:dotimes (i 2000)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehSpotCoordGeo))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'NbrSpotCoordGeoLeft) istream)
  (cl:setf (cl:slot-value msg 'ehLineCoordGeo) (cl:make-array 10))
  (cl:let ((vals (cl:slot-value msg 'ehLineCoordGeo)))
    (cl:dotimes (i 10)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehLineCoordGeo))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'QtyLineCoordGeo) istream)
  (cl:setf (cl:slot-value msg 'ehME) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'ehME)))
    (cl:dotimes (i 2)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehME))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (cl:setf (cl:slot-value msg 'ehNbrLineCoordGeo) (cl:make-array 100))
  (cl:let ((vals (cl:slot-value msg 'ehNbrLineCoordGeo)))
    (cl:dotimes (i 100)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehNbrLineCoordGeo))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'QtyNbrLineCoordGeo) istream)
  (cl:setf (cl:slot-value msg 'ehSpotTrafficSign) (cl:make-array 50))
  (cl:let ((vals (cl:slot-value msg 'ehSpotTrafficSign)))
    (cl:dotimes (i 50)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehSpotTrafficSign))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'NbrSpotTrafficSign) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'ehPosition) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'speedLimit_interpolMethod)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'curvature_interpolMethod)) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'ehSegmentAO) (cl:make-array 100))
  (cl:let ((vals (cl:slot-value msg 'ehSegmentAO)))
    (cl:dotimes (i 100)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehSegmentME))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'QtySegmentAO) istream)
  (cl:setf (cl:slot-value msg 'ehSegmentEO) (cl:make-array 100))
  (cl:let ((vals (cl:slot-value msg 'ehSegmentEO)))
    (cl:dotimes (i 100)
    (cl:setf (cl:aref vals i) (cl:make-instance 'project_s_msgs-msg:ehSegmentME))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'QtySegmentEO) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ElectronicHorizon>)))
  "Returns string type for a message object of type '<ElectronicHorizon>"
  "project_s_msgs/ElectronicHorizon")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ElectronicHorizon)))
  "Returns string type for a message object of type 'ElectronicHorizon"
  "project_s_msgs/ElectronicHorizon")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ElectronicHorizon>)))
  "Returns md5sum for a message object of type '<ElectronicHorizon>"
  "3734a37717a8e474a926575905e89801")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ElectronicHorizon)))
  "Returns md5sum for a message object of type 'ElectronicHorizon"
  "3734a37717a8e474a926575905e89801")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ElectronicHorizon>)))
  "Returns full string definition for message of type '<ElectronicHorizon>"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 indexPath~%~%uint8 SEGMENT_REPORT_SIZE = 50~%project_s_msgs/ehSegment[50] ehSegment~%std_msgs/UInt8 NbrSegment~%~%uint8 STUB_REPORT_SIZE = 10~%project_s_msgs/ehStub[10] ehStub~%std_msgs/UInt8 NbrStub~%~%uint16 SPOT_CURVATURE_REPORT_SIZE = 300~%project_s_msgs/ehSpotCurvature[300] ehSpotCurvature~%std_msgs/UInt16 NbrSpotCurvature~%~%uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight~%std_msgs/UInt16 NbrSpotCoordGeoRight~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft~%std_msgs/UInt16 NbrSpotCoordGeoLeft~%~%uint8 LINE_REPORT_SIZE = 10~%project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo~%std_msgs/UInt8 QtyLineCoordGeo~%~%uint8 ME_RIGHT_LINE = 0~%uint8 ME_LEFT_LINE = 1~%project_s_msgs/ehME[2] ehME~%~%uint8 NBR_LINE_REPORT_SIZE = 100~%project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo~%std_msgs/UInt8 QtyNbrLineCoordGeo~%~%uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50~%project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign~%std_msgs/UInt8 NbrSpotTrafficSign~%~%project_s_msgs/ehPosition ehPosition~%~%uint8 speedLimit_interpolMethod~%uint8 curvature_interpolMethod~%uint8 STEP = 0~%uint8 LINEAR = 1~%~%uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentAO~%std_msgs/UInt8 QtySegmentAO~%~%uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentEO~%std_msgs/UInt8 QtySegmentEO~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/ehSegment~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 effectiveSpeedLimit~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: project_s_msgs/ehStub~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 indexSubPath~%std_msgs/Float32 turnAngle~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotCurvature~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/Float32 Value_0~%std_msgs/Float32 Distance_1~%std_msgs/Float32 Value_1~%~%~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: project_s_msgs/ehSpotCoordGeo~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%~%~%~%================================================================================~%MSG: project_s_msgs/ehLineCoordGeo~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 3000~%project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: project_s_msgs/ehME~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%uint32 SEGMENT_ME_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentME~%std_msgs/UInt32 QtySegment~%~%================================================================================~%MSG: project_s_msgs/ehSegmentME~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 NbrSpot~%std_msgs/Float32 offset_debut~%std_msgs/Float32 offset_fin~%~%================================================================================~%MSG: project_s_msgs/ehNbrLineCoordGeo~%std_msgs/UInt8 Nbr~%std_msgs/Float32 offset~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotTrafficSign~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%uint8 Sign_Type~%uint8 Value~%uint8 Lane~%uint8 Sign_Location~%float64 latitude~%float64 longitude~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehPosition~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%std_msgs/Float32 cap~%std_msgs/UInt16 agePosition~%std_msgs/Float32 speed~%std_msgs/Float32 relativeHeading~%std_msgs/UInt8 currentLane~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ElectronicHorizon)))
  "Returns full string definition for message of type 'ElectronicHorizon"
  (cl:format cl:nil "Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt8 indexPath~%~%uint8 SEGMENT_REPORT_SIZE = 50~%project_s_msgs/ehSegment[50] ehSegment~%std_msgs/UInt8 NbrSegment~%~%uint8 STUB_REPORT_SIZE = 10~%project_s_msgs/ehStub[10] ehStub~%std_msgs/UInt8 NbrStub~%~%uint16 SPOT_CURVATURE_REPORT_SIZE = 300~%project_s_msgs/ehSpotCurvature[300] ehSpotCurvature~%std_msgs/UInt16 NbrSpotCurvature~%~%uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight~%std_msgs/UInt16 NbrSpotCoordGeoRight~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft~%std_msgs/UInt16 NbrSpotCoordGeoLeft~%~%uint8 LINE_REPORT_SIZE = 10~%project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo~%std_msgs/UInt8 QtyLineCoordGeo~%~%uint8 ME_RIGHT_LINE = 0~%uint8 ME_LEFT_LINE = 1~%project_s_msgs/ehME[2] ehME~%~%uint8 NBR_LINE_REPORT_SIZE = 100~%project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo~%std_msgs/UInt8 QtyNbrLineCoordGeo~%~%uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50~%project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign~%std_msgs/UInt8 NbrSpotTrafficSign~%~%project_s_msgs/ehPosition ehPosition~%~%uint8 speedLimit_interpolMethod~%uint8 curvature_interpolMethod~%uint8 STEP = 0~%uint8 LINEAR = 1~%~%uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentAO~%std_msgs/UInt8 QtySegmentAO~%~%uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentEO~%std_msgs/UInt8 QtySegmentEO~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: std_msgs/UInt8~%uint8 data~%~%================================================================================~%MSG: project_s_msgs/ehSegment~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 effectiveSpeedLimit~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: std_msgs/Float32~%float32 data~%================================================================================~%MSG: project_s_msgs/ehStub~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/UInt8 indexSubPath~%std_msgs/Float32 turnAngle~%std_msgs/UInt8 functionRoadClass~%std_msgs/UInt8 wayForm~%std_msgs/UInt8 nbLanesDrivingDirection~%std_msgs/UInt8 nbLanesOppositeDirection~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotCurvature~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%std_msgs/Float32 Value_0~%std_msgs/Float32 Distance_1~%std_msgs/Float32 Value_1~%~%~%~%================================================================================~%MSG: std_msgs/UInt16~%uint16 data~%~%================================================================================~%MSG: project_s_msgs/ehSpotCoordGeo~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%~%~%~%================================================================================~%MSG: project_s_msgs/ehLineCoordGeo~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 3000~%project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%~%================================================================================~%MSG: std_msgs/UInt32~%uint32 data~%================================================================================~%MSG: project_s_msgs/ehME~%Header header~%std_msgs/UInt8 id~%~%uint32 SPOT_REPORT_SIZE = 2000~%project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo~%std_msgs/UInt32 NbrSpotCoordGeo~%~%uint32 SEGMENT_ME_REPORT_SIZE = 100~%project_s_msgs/ehSegmentME[100] ehSegmentME~%std_msgs/UInt32 QtySegment~%~%================================================================================~%MSG: project_s_msgs/ehSegmentME~%Header header~%std_msgs/UInt8 id~%~%std_msgs/UInt32 NbrSpot~%std_msgs/Float32 offset_debut~%std_msgs/Float32 offset_fin~%~%================================================================================~%MSG: project_s_msgs/ehNbrLineCoordGeo~%std_msgs/UInt8 Nbr~%std_msgs/Float32 offset~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehSpotTrafficSign~%Header header~%std_msgs/UInt8 id~%~%std_msgs/Float32 offset~%uint8 Sign_Type~%uint8 Value~%uint8 Lane~%uint8 Sign_Location~%float64 latitude~%float64 longitude~%~%~%~%~%================================================================================~%MSG: project_s_msgs/ehPosition~%Header header~%std_msgs/UInt8 id~%~%#std_msgs/UInt8 indexPath~%std_msgs/Float32 offset~%float64 latitude~%float64 longitude~%std_msgs/Float32 cap~%std_msgs/UInt16 agePosition~%std_msgs/Float32 speed~%std_msgs/Float32 relativeHeading~%std_msgs/UInt8 currentLane~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ElectronicHorizon>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'indexPath))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehSegment) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'NbrSegment))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehStub) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'NbrStub))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehSpotCurvature) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'NbrSpotCurvature))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehSpotCoordGeoRight) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'NbrSpotCoordGeoRight))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehSpotCoordGeoLeft) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'NbrSpotCoordGeoLeft))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehLineCoordGeo) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'QtyLineCoordGeo))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehME) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehNbrLineCoordGeo) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'QtyNbrLineCoordGeo))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehSpotTrafficSign) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'NbrSpotTrafficSign))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'ehPosition))
     1
     1
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehSegmentAO) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'QtySegmentAO))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ehSegmentEO) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'QtySegmentEO))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ElectronicHorizon>))
  "Converts a ROS message object to a list"
  (cl:list 'ElectronicHorizon
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':indexPath (indexPath msg))
    (cl:cons ':ehSegment (ehSegment msg))
    (cl:cons ':NbrSegment (NbrSegment msg))
    (cl:cons ':ehStub (ehStub msg))
    (cl:cons ':NbrStub (NbrStub msg))
    (cl:cons ':ehSpotCurvature (ehSpotCurvature msg))
    (cl:cons ':NbrSpotCurvature (NbrSpotCurvature msg))
    (cl:cons ':ehSpotCoordGeoRight (ehSpotCoordGeoRight msg))
    (cl:cons ':NbrSpotCoordGeoRight (NbrSpotCoordGeoRight msg))
    (cl:cons ':ehSpotCoordGeoLeft (ehSpotCoordGeoLeft msg))
    (cl:cons ':NbrSpotCoordGeoLeft (NbrSpotCoordGeoLeft msg))
    (cl:cons ':ehLineCoordGeo (ehLineCoordGeo msg))
    (cl:cons ':QtyLineCoordGeo (QtyLineCoordGeo msg))
    (cl:cons ':ehME (ehME msg))
    (cl:cons ':ehNbrLineCoordGeo (ehNbrLineCoordGeo msg))
    (cl:cons ':QtyNbrLineCoordGeo (QtyNbrLineCoordGeo msg))
    (cl:cons ':ehSpotTrafficSign (ehSpotTrafficSign msg))
    (cl:cons ':NbrSpotTrafficSign (NbrSpotTrafficSign msg))
    (cl:cons ':ehPosition (ehPosition msg))
    (cl:cons ':speedLimit_interpolMethod (speedLimit_interpolMethod msg))
    (cl:cons ':curvature_interpolMethod (curvature_interpolMethod msg))
    (cl:cons ':ehSegmentAO (ehSegmentAO msg))
    (cl:cons ':QtySegmentAO (QtySegmentAO msg))
    (cl:cons ':ehSegmentEO (ehSegmentEO msg))
    (cl:cons ':QtySegmentEO (QtySegmentEO msg))
))
