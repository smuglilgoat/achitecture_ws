;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::ElectronicHorizon)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'ElectronicHorizon (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON")
  (make-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))

(in-package "ROS")
;;//! \htmlinclude ElectronicHorizon.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*SEGMENT_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*SEGMENT_REPORT_SIZE* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*SEGMENT_REPORT_SIZE* 50)
(intern "*STUB_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*STUB_REPORT_SIZE* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*STUB_REPORT_SIZE* 10)
(intern "*SPOT_CURVATURE_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*SPOT_CURVATURE_REPORT_SIZE* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*SPOT_CURVATURE_REPORT_SIZE* 300)
(intern "*SPOT_COORD_GEO_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*SPOT_COORD_GEO_REPORT_SIZE* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*SPOT_COORD_GEO_REPORT_SIZE* 2000)
(intern "*LINE_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*LINE_REPORT_SIZE* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*LINE_REPORT_SIZE* 10)
(intern "*ME_RIGHT_LINE*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*ME_RIGHT_LINE* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*ME_RIGHT_LINE* 0)
(intern "*ME_LEFT_LINE*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*ME_LEFT_LINE* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*ME_LEFT_LINE* 1)
(intern "*NBR_LINE_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*NBR_LINE_REPORT_SIZE* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*NBR_LINE_REPORT_SIZE* 100)
(intern "*SPOT_TRAFFIC_SIGN_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*SPOT_TRAFFIC_SIGN_REPORT_SIZE* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*SPOT_TRAFFIC_SIGN_REPORT_SIZE* 50)
(intern "*STEP*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*STEP* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*STEP* 0)
(intern "*LINEAR*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*LINEAR* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*LINEAR* 1)
(intern "*SEGMENT_ARRET_OBSTACLE_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*SEGMENT_ARRET_OBSTACLE_REPORT_SIZE* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*SEGMENT_ARRET_OBSTACLE_REPORT_SIZE* 100)
(intern "*SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(shadow '*SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE* (find-package "PROJECT_S_MSGS::ELECTRONICHORIZON"))
(defconstant project_s_msgs::ElectronicHorizon::*SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE* 100)
(defclass project_s_msgs::ElectronicHorizon
  :super ros::object
  :slots (_header _id _indexPath _ehSegment _NbrSegment _ehStub _NbrStub _ehSpotCurvature _NbrSpotCurvature _ehSpotCoordGeoRight _NbrSpotCoordGeoRight _ehSpotCoordGeoLeft _NbrSpotCoordGeoLeft _ehLineCoordGeo _QtyLineCoordGeo _ehME _ehNbrLineCoordGeo _QtyNbrLineCoordGeo _ehSpotTrafficSign _NbrSpotTrafficSign _ehPosition _speedLimit_interpolMethod _curvature_interpolMethod _ehSegmentAO _QtySegmentAO _ehSegmentEO _QtySegmentEO ))

(defmethod project_s_msgs::ElectronicHorizon
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:indexPath __indexPath) (instance std_msgs::UInt8 :init))
    ((:ehSegment __ehSegment) (let (r) (dotimes (i 50) (push (instance project_s_msgs::ehSegment :init) r)) r))
    ((:NbrSegment __NbrSegment) (instance std_msgs::UInt8 :init))
    ((:ehStub __ehStub) (let (r) (dotimes (i 10) (push (instance project_s_msgs::ehStub :init) r)) r))
    ((:NbrStub __NbrStub) (instance std_msgs::UInt8 :init))
    ((:ehSpotCurvature __ehSpotCurvature) (let (r) (dotimes (i 300) (push (instance project_s_msgs::ehSpotCurvature :init) r)) r))
    ((:NbrSpotCurvature __NbrSpotCurvature) (instance std_msgs::UInt16 :init))
    ((:ehSpotCoordGeoRight __ehSpotCoordGeoRight) (let (r) (dotimes (i 2000) (push (instance project_s_msgs::ehSpotCoordGeo :init) r)) r))
    ((:NbrSpotCoordGeoRight __NbrSpotCoordGeoRight) (instance std_msgs::UInt16 :init))
    ((:ehSpotCoordGeoLeft __ehSpotCoordGeoLeft) (let (r) (dotimes (i 2000) (push (instance project_s_msgs::ehSpotCoordGeo :init) r)) r))
    ((:NbrSpotCoordGeoLeft __NbrSpotCoordGeoLeft) (instance std_msgs::UInt16 :init))
    ((:ehLineCoordGeo __ehLineCoordGeo) (let (r) (dotimes (i 10) (push (instance project_s_msgs::ehLineCoordGeo :init) r)) r))
    ((:QtyLineCoordGeo __QtyLineCoordGeo) (instance std_msgs::UInt8 :init))
    ((:ehME __ehME) (let (r) (dotimes (i 2) (push (instance project_s_msgs::ehME :init) r)) r))
    ((:ehNbrLineCoordGeo __ehNbrLineCoordGeo) (let (r) (dotimes (i 100) (push (instance project_s_msgs::ehNbrLineCoordGeo :init) r)) r))
    ((:QtyNbrLineCoordGeo __QtyNbrLineCoordGeo) (instance std_msgs::UInt8 :init))
    ((:ehSpotTrafficSign __ehSpotTrafficSign) (let (r) (dotimes (i 50) (push (instance project_s_msgs::ehSpotTrafficSign :init) r)) r))
    ((:NbrSpotTrafficSign __NbrSpotTrafficSign) (instance std_msgs::UInt8 :init))
    ((:ehPosition __ehPosition) (instance project_s_msgs::ehPosition :init))
    ((:speedLimit_interpolMethod __speedLimit_interpolMethod) 0)
    ((:curvature_interpolMethod __curvature_interpolMethod) 0)
    ((:ehSegmentAO __ehSegmentAO) (let (r) (dotimes (i 100) (push (instance project_s_msgs::ehSegmentME :init) r)) r))
    ((:QtySegmentAO __QtySegmentAO) (instance std_msgs::UInt8 :init))
    ((:ehSegmentEO __ehSegmentEO) (let (r) (dotimes (i 100) (push (instance project_s_msgs::ehSegmentME :init) r)) r))
    ((:QtySegmentEO __QtySegmentEO) (instance std_msgs::UInt8 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _indexPath __indexPath)
   (setq _ehSegment __ehSegment)
   (setq _NbrSegment __NbrSegment)
   (setq _ehStub __ehStub)
   (setq _NbrStub __NbrStub)
   (setq _ehSpotCurvature __ehSpotCurvature)
   (setq _NbrSpotCurvature __NbrSpotCurvature)
   (setq _ehSpotCoordGeoRight __ehSpotCoordGeoRight)
   (setq _NbrSpotCoordGeoRight __NbrSpotCoordGeoRight)
   (setq _ehSpotCoordGeoLeft __ehSpotCoordGeoLeft)
   (setq _NbrSpotCoordGeoLeft __NbrSpotCoordGeoLeft)
   (setq _ehLineCoordGeo __ehLineCoordGeo)
   (setq _QtyLineCoordGeo __QtyLineCoordGeo)
   (setq _ehME __ehME)
   (setq _ehNbrLineCoordGeo __ehNbrLineCoordGeo)
   (setq _QtyNbrLineCoordGeo __QtyNbrLineCoordGeo)
   (setq _ehSpotTrafficSign __ehSpotTrafficSign)
   (setq _NbrSpotTrafficSign __NbrSpotTrafficSign)
   (setq _ehPosition __ehPosition)
   (setq _speedLimit_interpolMethod (round __speedLimit_interpolMethod))
   (setq _curvature_interpolMethod (round __curvature_interpolMethod))
   (setq _ehSegmentAO __ehSegmentAO)
   (setq _QtySegmentAO __QtySegmentAO)
   (setq _ehSegmentEO __ehSegmentEO)
   (setq _QtySegmentEO __QtySegmentEO)
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
  (:indexPath
   (&rest __indexPath)
   (if (keywordp (car __indexPath))
       (send* _indexPath __indexPath)
     (progn
       (if __indexPath (setq _indexPath (car __indexPath)))
       _indexPath)))
  (:ehSegment
   (&rest __ehSegment)
   (if (keywordp (car __ehSegment))
       (send* _ehSegment __ehSegment)
     (progn
       (if __ehSegment (setq _ehSegment (car __ehSegment)))
       _ehSegment)))
  (:NbrSegment
   (&rest __NbrSegment)
   (if (keywordp (car __NbrSegment))
       (send* _NbrSegment __NbrSegment)
     (progn
       (if __NbrSegment (setq _NbrSegment (car __NbrSegment)))
       _NbrSegment)))
  (:ehStub
   (&rest __ehStub)
   (if (keywordp (car __ehStub))
       (send* _ehStub __ehStub)
     (progn
       (if __ehStub (setq _ehStub (car __ehStub)))
       _ehStub)))
  (:NbrStub
   (&rest __NbrStub)
   (if (keywordp (car __NbrStub))
       (send* _NbrStub __NbrStub)
     (progn
       (if __NbrStub (setq _NbrStub (car __NbrStub)))
       _NbrStub)))
  (:ehSpotCurvature
   (&rest __ehSpotCurvature)
   (if (keywordp (car __ehSpotCurvature))
       (send* _ehSpotCurvature __ehSpotCurvature)
     (progn
       (if __ehSpotCurvature (setq _ehSpotCurvature (car __ehSpotCurvature)))
       _ehSpotCurvature)))
  (:NbrSpotCurvature
   (&rest __NbrSpotCurvature)
   (if (keywordp (car __NbrSpotCurvature))
       (send* _NbrSpotCurvature __NbrSpotCurvature)
     (progn
       (if __NbrSpotCurvature (setq _NbrSpotCurvature (car __NbrSpotCurvature)))
       _NbrSpotCurvature)))
  (:ehSpotCoordGeoRight
   (&rest __ehSpotCoordGeoRight)
   (if (keywordp (car __ehSpotCoordGeoRight))
       (send* _ehSpotCoordGeoRight __ehSpotCoordGeoRight)
     (progn
       (if __ehSpotCoordGeoRight (setq _ehSpotCoordGeoRight (car __ehSpotCoordGeoRight)))
       _ehSpotCoordGeoRight)))
  (:NbrSpotCoordGeoRight
   (&rest __NbrSpotCoordGeoRight)
   (if (keywordp (car __NbrSpotCoordGeoRight))
       (send* _NbrSpotCoordGeoRight __NbrSpotCoordGeoRight)
     (progn
       (if __NbrSpotCoordGeoRight (setq _NbrSpotCoordGeoRight (car __NbrSpotCoordGeoRight)))
       _NbrSpotCoordGeoRight)))
  (:ehSpotCoordGeoLeft
   (&rest __ehSpotCoordGeoLeft)
   (if (keywordp (car __ehSpotCoordGeoLeft))
       (send* _ehSpotCoordGeoLeft __ehSpotCoordGeoLeft)
     (progn
       (if __ehSpotCoordGeoLeft (setq _ehSpotCoordGeoLeft (car __ehSpotCoordGeoLeft)))
       _ehSpotCoordGeoLeft)))
  (:NbrSpotCoordGeoLeft
   (&rest __NbrSpotCoordGeoLeft)
   (if (keywordp (car __NbrSpotCoordGeoLeft))
       (send* _NbrSpotCoordGeoLeft __NbrSpotCoordGeoLeft)
     (progn
       (if __NbrSpotCoordGeoLeft (setq _NbrSpotCoordGeoLeft (car __NbrSpotCoordGeoLeft)))
       _NbrSpotCoordGeoLeft)))
  (:ehLineCoordGeo
   (&rest __ehLineCoordGeo)
   (if (keywordp (car __ehLineCoordGeo))
       (send* _ehLineCoordGeo __ehLineCoordGeo)
     (progn
       (if __ehLineCoordGeo (setq _ehLineCoordGeo (car __ehLineCoordGeo)))
       _ehLineCoordGeo)))
  (:QtyLineCoordGeo
   (&rest __QtyLineCoordGeo)
   (if (keywordp (car __QtyLineCoordGeo))
       (send* _QtyLineCoordGeo __QtyLineCoordGeo)
     (progn
       (if __QtyLineCoordGeo (setq _QtyLineCoordGeo (car __QtyLineCoordGeo)))
       _QtyLineCoordGeo)))
  (:ehME
   (&rest __ehME)
   (if (keywordp (car __ehME))
       (send* _ehME __ehME)
     (progn
       (if __ehME (setq _ehME (car __ehME)))
       _ehME)))
  (:ehNbrLineCoordGeo
   (&rest __ehNbrLineCoordGeo)
   (if (keywordp (car __ehNbrLineCoordGeo))
       (send* _ehNbrLineCoordGeo __ehNbrLineCoordGeo)
     (progn
       (if __ehNbrLineCoordGeo (setq _ehNbrLineCoordGeo (car __ehNbrLineCoordGeo)))
       _ehNbrLineCoordGeo)))
  (:QtyNbrLineCoordGeo
   (&rest __QtyNbrLineCoordGeo)
   (if (keywordp (car __QtyNbrLineCoordGeo))
       (send* _QtyNbrLineCoordGeo __QtyNbrLineCoordGeo)
     (progn
       (if __QtyNbrLineCoordGeo (setq _QtyNbrLineCoordGeo (car __QtyNbrLineCoordGeo)))
       _QtyNbrLineCoordGeo)))
  (:ehSpotTrafficSign
   (&rest __ehSpotTrafficSign)
   (if (keywordp (car __ehSpotTrafficSign))
       (send* _ehSpotTrafficSign __ehSpotTrafficSign)
     (progn
       (if __ehSpotTrafficSign (setq _ehSpotTrafficSign (car __ehSpotTrafficSign)))
       _ehSpotTrafficSign)))
  (:NbrSpotTrafficSign
   (&rest __NbrSpotTrafficSign)
   (if (keywordp (car __NbrSpotTrafficSign))
       (send* _NbrSpotTrafficSign __NbrSpotTrafficSign)
     (progn
       (if __NbrSpotTrafficSign (setq _NbrSpotTrafficSign (car __NbrSpotTrafficSign)))
       _NbrSpotTrafficSign)))
  (:ehPosition
   (&rest __ehPosition)
   (if (keywordp (car __ehPosition))
       (send* _ehPosition __ehPosition)
     (progn
       (if __ehPosition (setq _ehPosition (car __ehPosition)))
       _ehPosition)))
  (:speedLimit_interpolMethod
   (&optional __speedLimit_interpolMethod)
   (if __speedLimit_interpolMethod (setq _speedLimit_interpolMethod __speedLimit_interpolMethod)) _speedLimit_interpolMethod)
  (:curvature_interpolMethod
   (&optional __curvature_interpolMethod)
   (if __curvature_interpolMethod (setq _curvature_interpolMethod __curvature_interpolMethod)) _curvature_interpolMethod)
  (:ehSegmentAO
   (&rest __ehSegmentAO)
   (if (keywordp (car __ehSegmentAO))
       (send* _ehSegmentAO __ehSegmentAO)
     (progn
       (if __ehSegmentAO (setq _ehSegmentAO (car __ehSegmentAO)))
       _ehSegmentAO)))
  (:QtySegmentAO
   (&rest __QtySegmentAO)
   (if (keywordp (car __QtySegmentAO))
       (send* _QtySegmentAO __QtySegmentAO)
     (progn
       (if __QtySegmentAO (setq _QtySegmentAO (car __QtySegmentAO)))
       _QtySegmentAO)))
  (:ehSegmentEO
   (&rest __ehSegmentEO)
   (if (keywordp (car __ehSegmentEO))
       (send* _ehSegmentEO __ehSegmentEO)
     (progn
       (if __ehSegmentEO (setq _ehSegmentEO (car __ehSegmentEO)))
       _ehSegmentEO)))
  (:QtySegmentEO
   (&rest __QtySegmentEO)
   (if (keywordp (car __QtySegmentEO))
       (send* _QtySegmentEO __QtySegmentEO)
     (progn
       (if __QtySegmentEO (setq _QtySegmentEO (car __QtySegmentEO)))
       _QtySegmentEO)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; std_msgs/UInt8 _indexPath
    (send _indexPath :serialization-length)
    ;; project_s_msgs/ehSegment[50] _ehSegment
    (apply #'+ (send-all _ehSegment :serialization-length))
    ;; std_msgs/UInt8 _NbrSegment
    (send _NbrSegment :serialization-length)
    ;; project_s_msgs/ehStub[10] _ehStub
    (apply #'+ (send-all _ehStub :serialization-length))
    ;; std_msgs/UInt8 _NbrStub
    (send _NbrStub :serialization-length)
    ;; project_s_msgs/ehSpotCurvature[300] _ehSpotCurvature
    (apply #'+ (send-all _ehSpotCurvature :serialization-length))
    ;; std_msgs/UInt16 _NbrSpotCurvature
    (send _NbrSpotCurvature :serialization-length)
    ;; project_s_msgs/ehSpotCoordGeo[2000] _ehSpotCoordGeoRight
    (apply #'+ (send-all _ehSpotCoordGeoRight :serialization-length))
    ;; std_msgs/UInt16 _NbrSpotCoordGeoRight
    (send _NbrSpotCoordGeoRight :serialization-length)
    ;; project_s_msgs/ehSpotCoordGeo[2000] _ehSpotCoordGeoLeft
    (apply #'+ (send-all _ehSpotCoordGeoLeft :serialization-length))
    ;; std_msgs/UInt16 _NbrSpotCoordGeoLeft
    (send _NbrSpotCoordGeoLeft :serialization-length)
    ;; project_s_msgs/ehLineCoordGeo[10] _ehLineCoordGeo
    (apply #'+ (send-all _ehLineCoordGeo :serialization-length))
    ;; std_msgs/UInt8 _QtyLineCoordGeo
    (send _QtyLineCoordGeo :serialization-length)
    ;; project_s_msgs/ehME[2] _ehME
    (apply #'+ (send-all _ehME :serialization-length))
    ;; project_s_msgs/ehNbrLineCoordGeo[100] _ehNbrLineCoordGeo
    (apply #'+ (send-all _ehNbrLineCoordGeo :serialization-length))
    ;; std_msgs/UInt8 _QtyNbrLineCoordGeo
    (send _QtyNbrLineCoordGeo :serialization-length)
    ;; project_s_msgs/ehSpotTrafficSign[50] _ehSpotTrafficSign
    (apply #'+ (send-all _ehSpotTrafficSign :serialization-length))
    ;; std_msgs/UInt8 _NbrSpotTrafficSign
    (send _NbrSpotTrafficSign :serialization-length)
    ;; project_s_msgs/ehPosition _ehPosition
    (send _ehPosition :serialization-length)
    ;; uint8 _speedLimit_interpolMethod
    1
    ;; uint8 _curvature_interpolMethod
    1
    ;; project_s_msgs/ehSegmentME[100] _ehSegmentAO
    (apply #'+ (send-all _ehSegmentAO :serialization-length))
    ;; std_msgs/UInt8 _QtySegmentAO
    (send _QtySegmentAO :serialization-length)
    ;; project_s_msgs/ehSegmentME[100] _ehSegmentEO
    (apply #'+ (send-all _ehSegmentEO :serialization-length))
    ;; std_msgs/UInt8 _QtySegmentEO
    (send _QtySegmentEO :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; std_msgs/UInt8 _indexPath
       (send _indexPath :serialize s)
     ;; project_s_msgs/ehSegment[50] _ehSegment
     (dolist (elem _ehSegment)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _NbrSegment
       (send _NbrSegment :serialize s)
     ;; project_s_msgs/ehStub[10] _ehStub
     (dolist (elem _ehStub)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _NbrStub
       (send _NbrStub :serialize s)
     ;; project_s_msgs/ehSpotCurvature[300] _ehSpotCurvature
     (dolist (elem _ehSpotCurvature)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt16 _NbrSpotCurvature
       (send _NbrSpotCurvature :serialize s)
     ;; project_s_msgs/ehSpotCoordGeo[2000] _ehSpotCoordGeoRight
     (dolist (elem _ehSpotCoordGeoRight)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt16 _NbrSpotCoordGeoRight
       (send _NbrSpotCoordGeoRight :serialize s)
     ;; project_s_msgs/ehSpotCoordGeo[2000] _ehSpotCoordGeoLeft
     (dolist (elem _ehSpotCoordGeoLeft)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt16 _NbrSpotCoordGeoLeft
       (send _NbrSpotCoordGeoLeft :serialize s)
     ;; project_s_msgs/ehLineCoordGeo[10] _ehLineCoordGeo
     (dolist (elem _ehLineCoordGeo)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _QtyLineCoordGeo
       (send _QtyLineCoordGeo :serialize s)
     ;; project_s_msgs/ehME[2] _ehME
     (dolist (elem _ehME)
       (send elem :serialize s)
       )
     ;; project_s_msgs/ehNbrLineCoordGeo[100] _ehNbrLineCoordGeo
     (dolist (elem _ehNbrLineCoordGeo)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _QtyNbrLineCoordGeo
       (send _QtyNbrLineCoordGeo :serialize s)
     ;; project_s_msgs/ehSpotTrafficSign[50] _ehSpotTrafficSign
     (dolist (elem _ehSpotTrafficSign)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _NbrSpotTrafficSign
       (send _NbrSpotTrafficSign :serialize s)
     ;; project_s_msgs/ehPosition _ehPosition
       (send _ehPosition :serialize s)
     ;; uint8 _speedLimit_interpolMethod
       (write-byte _speedLimit_interpolMethod s)
     ;; uint8 _curvature_interpolMethod
       (write-byte _curvature_interpolMethod s)
     ;; project_s_msgs/ehSegmentME[100] _ehSegmentAO
     (dolist (elem _ehSegmentAO)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _QtySegmentAO
       (send _QtySegmentAO :serialize s)
     ;; project_s_msgs/ehSegmentME[100] _ehSegmentEO
     (dolist (elem _ehSegmentEO)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _QtySegmentEO
       (send _QtySegmentEO :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; std_msgs/UInt8 _indexPath
     (send _indexPath :deserialize buf ptr-) (incf ptr- (send _indexPath :serialization-length))
   ;; project_s_msgs/ehSegment[50] _ehSegment
   (dotimes (i 50)
     (send (elt _ehSegment i) :deserialize buf ptr-) (incf ptr- (send (elt _ehSegment i) :serialization-length))
     )
   ;; std_msgs/UInt8 _NbrSegment
     (send _NbrSegment :deserialize buf ptr-) (incf ptr- (send _NbrSegment :serialization-length))
   ;; project_s_msgs/ehStub[10] _ehStub
   (dotimes (i 10)
     (send (elt _ehStub i) :deserialize buf ptr-) (incf ptr- (send (elt _ehStub i) :serialization-length))
     )
   ;; std_msgs/UInt8 _NbrStub
     (send _NbrStub :deserialize buf ptr-) (incf ptr- (send _NbrStub :serialization-length))
   ;; project_s_msgs/ehSpotCurvature[300] _ehSpotCurvature
   (dotimes (i 300)
     (send (elt _ehSpotCurvature i) :deserialize buf ptr-) (incf ptr- (send (elt _ehSpotCurvature i) :serialization-length))
     )
   ;; std_msgs/UInt16 _NbrSpotCurvature
     (send _NbrSpotCurvature :deserialize buf ptr-) (incf ptr- (send _NbrSpotCurvature :serialization-length))
   ;; project_s_msgs/ehSpotCoordGeo[2000] _ehSpotCoordGeoRight
   (dotimes (i 2000)
     (send (elt _ehSpotCoordGeoRight i) :deserialize buf ptr-) (incf ptr- (send (elt _ehSpotCoordGeoRight i) :serialization-length))
     )
   ;; std_msgs/UInt16 _NbrSpotCoordGeoRight
     (send _NbrSpotCoordGeoRight :deserialize buf ptr-) (incf ptr- (send _NbrSpotCoordGeoRight :serialization-length))
   ;; project_s_msgs/ehSpotCoordGeo[2000] _ehSpotCoordGeoLeft
   (dotimes (i 2000)
     (send (elt _ehSpotCoordGeoLeft i) :deserialize buf ptr-) (incf ptr- (send (elt _ehSpotCoordGeoLeft i) :serialization-length))
     )
   ;; std_msgs/UInt16 _NbrSpotCoordGeoLeft
     (send _NbrSpotCoordGeoLeft :deserialize buf ptr-) (incf ptr- (send _NbrSpotCoordGeoLeft :serialization-length))
   ;; project_s_msgs/ehLineCoordGeo[10] _ehLineCoordGeo
   (dotimes (i 10)
     (send (elt _ehLineCoordGeo i) :deserialize buf ptr-) (incf ptr- (send (elt _ehLineCoordGeo i) :serialization-length))
     )
   ;; std_msgs/UInt8 _QtyLineCoordGeo
     (send _QtyLineCoordGeo :deserialize buf ptr-) (incf ptr- (send _QtyLineCoordGeo :serialization-length))
   ;; project_s_msgs/ehME[2] _ehME
   (dotimes (i 2)
     (send (elt _ehME i) :deserialize buf ptr-) (incf ptr- (send (elt _ehME i) :serialization-length))
     )
   ;; project_s_msgs/ehNbrLineCoordGeo[100] _ehNbrLineCoordGeo
   (dotimes (i 100)
     (send (elt _ehNbrLineCoordGeo i) :deserialize buf ptr-) (incf ptr- (send (elt _ehNbrLineCoordGeo i) :serialization-length))
     )
   ;; std_msgs/UInt8 _QtyNbrLineCoordGeo
     (send _QtyNbrLineCoordGeo :deserialize buf ptr-) (incf ptr- (send _QtyNbrLineCoordGeo :serialization-length))
   ;; project_s_msgs/ehSpotTrafficSign[50] _ehSpotTrafficSign
   (dotimes (i 50)
     (send (elt _ehSpotTrafficSign i) :deserialize buf ptr-) (incf ptr- (send (elt _ehSpotTrafficSign i) :serialization-length))
     )
   ;; std_msgs/UInt8 _NbrSpotTrafficSign
     (send _NbrSpotTrafficSign :deserialize buf ptr-) (incf ptr- (send _NbrSpotTrafficSign :serialization-length))
   ;; project_s_msgs/ehPosition _ehPosition
     (send _ehPosition :deserialize buf ptr-) (incf ptr- (send _ehPosition :serialization-length))
   ;; uint8 _speedLimit_interpolMethod
     (setq _speedLimit_interpolMethod (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _curvature_interpolMethod
     (setq _curvature_interpolMethod (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; project_s_msgs/ehSegmentME[100] _ehSegmentAO
   (dotimes (i 100)
     (send (elt _ehSegmentAO i) :deserialize buf ptr-) (incf ptr- (send (elt _ehSegmentAO i) :serialization-length))
     )
   ;; std_msgs/UInt8 _QtySegmentAO
     (send _QtySegmentAO :deserialize buf ptr-) (incf ptr- (send _QtySegmentAO :serialization-length))
   ;; project_s_msgs/ehSegmentME[100] _ehSegmentEO
   (dotimes (i 100)
     (send (elt _ehSegmentEO i) :deserialize buf ptr-) (incf ptr- (send (elt _ehSegmentEO i) :serialization-length))
     )
   ;; std_msgs/UInt8 _QtySegmentEO
     (send _QtySegmentEO :deserialize buf ptr-) (incf ptr- (send _QtySegmentEO :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::ElectronicHorizon :md5sum-) "3734a37717a8e474a926575905e89801")
(setf (get project_s_msgs::ElectronicHorizon :datatype-) "project_s_msgs/ElectronicHorizon")
(setf (get project_s_msgs::ElectronicHorizon :definition-)
      "Header header
std_msgs/UInt8 id

std_msgs/UInt8 indexPath

uint8 SEGMENT_REPORT_SIZE = 50
project_s_msgs/ehSegment[50] ehSegment
std_msgs/UInt8 NbrSegment

uint8 STUB_REPORT_SIZE = 10
project_s_msgs/ehStub[10] ehStub
std_msgs/UInt8 NbrStub

uint16 SPOT_CURVATURE_REPORT_SIZE = 300
project_s_msgs/ehSpotCurvature[300] ehSpotCurvature
std_msgs/UInt16 NbrSpotCurvature

uint16 SPOT_COORD_GEO_REPORT_SIZE = 2000
project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoRight
std_msgs/UInt16 NbrSpotCoordGeoRight
project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeoLeft
std_msgs/UInt16 NbrSpotCoordGeoLeft

uint8 LINE_REPORT_SIZE = 10
project_s_msgs/ehLineCoordGeo[10] ehLineCoordGeo
std_msgs/UInt8 QtyLineCoordGeo

uint8 ME_RIGHT_LINE = 0
uint8 ME_LEFT_LINE = 1
project_s_msgs/ehME[2] ehME

uint8 NBR_LINE_REPORT_SIZE = 100
project_s_msgs/ehNbrLineCoordGeo[100] ehNbrLineCoordGeo
std_msgs/UInt8 QtyNbrLineCoordGeo

uint8 SPOT_TRAFFIC_SIGN_REPORT_SIZE = 50
project_s_msgs/ehSpotTrafficSign[50] ehSpotTrafficSign
std_msgs/UInt8 NbrSpotTrafficSign

project_s_msgs/ehPosition ehPosition

uint8 speedLimit_interpolMethod
uint8 curvature_interpolMethod
uint8 STEP = 0
uint8 LINEAR = 1

uint8 SEGMENT_ARRET_OBSTACLE_REPORT_SIZE = 100
project_s_msgs/ehSegmentME[100] ehSegmentAO
std_msgs/UInt8 QtySegmentAO

uint8 SEGMENT_EVITEMENT_OBSTACLE_REPORT_SIZE = 100
project_s_msgs/ehSegmentME[100] ehSegmentEO
std_msgs/UInt8 QtySegmentEO


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

================================================================================
MSG: project_s_msgs/ehSegment
Header header
std_msgs/UInt8 id

#std_msgs/UInt8 indexPath
std_msgs/Float32 offset
std_msgs/UInt8 functionRoadClass
std_msgs/UInt8 wayForm
std_msgs/UInt8 effectiveSpeedLimit
std_msgs/UInt8 nbLanesDrivingDirection
std_msgs/UInt8 nbLanesOppositeDirection



================================================================================
MSG: std_msgs/Float32
float32 data
================================================================================
MSG: project_s_msgs/ehStub
Header header
std_msgs/UInt8 id

#std_msgs/UInt8 indexPath
std_msgs/Float32 offset
std_msgs/UInt8 indexSubPath
std_msgs/Float32 turnAngle
std_msgs/UInt8 functionRoadClass
std_msgs/UInt8 wayForm
std_msgs/UInt8 nbLanesDrivingDirection
std_msgs/UInt8 nbLanesOppositeDirection



================================================================================
MSG: project_s_msgs/ehSpotCurvature
Header header
std_msgs/UInt8 id

#std_msgs/UInt8 indexPath
std_msgs/Float32 offset
std_msgs/Float32 Value_0
std_msgs/Float32 Distance_1
std_msgs/Float32 Value_1



================================================================================
MSG: std_msgs/UInt16
uint16 data

================================================================================
MSG: project_s_msgs/ehSpotCoordGeo
Header header
std_msgs/UInt8 id

std_msgs/Float32 offset
float64 latitude
float64 longitude



================================================================================
MSG: project_s_msgs/ehLineCoordGeo
Header header
std_msgs/UInt8 id

uint32 SPOT_REPORT_SIZE = 3000
project_s_msgs/ehSpotCoordGeo[3000] ehSpotCoordGeo
std_msgs/UInt32 NbrSpotCoordGeo


================================================================================
MSG: std_msgs/UInt32
uint32 data
================================================================================
MSG: project_s_msgs/ehME
Header header
std_msgs/UInt8 id

uint32 SPOT_REPORT_SIZE = 2000
project_s_msgs/ehSpotCoordGeo[2000] ehSpotCoordGeo
std_msgs/UInt32 NbrSpotCoordGeo

uint32 SEGMENT_ME_REPORT_SIZE = 100
project_s_msgs/ehSegmentME[100] ehSegmentME
std_msgs/UInt32 QtySegment

================================================================================
MSG: project_s_msgs/ehSegmentME
Header header
std_msgs/UInt8 id

std_msgs/UInt32 NbrSpot
std_msgs/Float32 offset_debut
std_msgs/Float32 offset_fin

================================================================================
MSG: project_s_msgs/ehNbrLineCoordGeo
std_msgs/UInt8 Nbr
std_msgs/Float32 offset




================================================================================
MSG: project_s_msgs/ehSpotTrafficSign
Header header
std_msgs/UInt8 id

std_msgs/Float32 offset
uint8 Sign_Type
uint8 Value
uint8 Lane
uint8 Sign_Location
float64 latitude
float64 longitude




================================================================================
MSG: project_s_msgs/ehPosition
Header header
std_msgs/UInt8 id

#std_msgs/UInt8 indexPath
std_msgs/Float32 offset
float64 latitude
float64 longitude
std_msgs/Float32 cap
std_msgs/UInt16 agePosition
std_msgs/Float32 speed
std_msgs/Float32 relativeHeading
std_msgs/UInt8 currentLane



")



(provide :project_s_msgs/ElectronicHorizon "3734a37717a8e474a926575905e89801")


