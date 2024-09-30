;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::Line)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'Line (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::LINE")
  (make-package "PROJECT_S_MSGS::LINE"))

(in-package "ROS")
;;//! \htmlinclude Line.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*SEGMENT_REPORT_SIZE*" (find-package "PROJECT_S_MSGS::LINE"))
(shadow '*SEGMENT_REPORT_SIZE* (find-package "PROJECT_S_MSGS::LINE"))
(defconstant project_s_msgs::Line::*SEGMENT_REPORT_SIZE* 3000)
(defclass project_s_msgs::Line
  :super ros::object
  :slots (_header _id _segment _QtySegment _lineClass _idPiste _existenceState _scoreDetection _nbrDetection _nbrVisibility _scorePersistence _nbrUpdate _nbrAge ))

(defmethod project_s_msgs::Line
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:segment __segment) (let (r) (dotimes (i 3000) (push (instance project_s_msgs::Segment :init) r)) r))
    ((:QtySegment __QtySegment) (instance std_msgs::UInt16 :init))
    ((:lineClass __lineClass) (instance std_msgs::Float32 :init))
    ((:idPiste __idPiste) (let (r) (dotimes (i 2) (push (instance std_msgs::UInt16 :init) r)) r))
    ((:existenceState __existenceState) (instance std_msgs::UInt8 :init))
    ((:scoreDetection __scoreDetection) (instance std_msgs::Float32 :init))
    ((:nbrDetection __nbrDetection) (instance std_msgs::Float32 :init))
    ((:nbrVisibility __nbrVisibility) (instance std_msgs::Float32 :init))
    ((:scorePersistence __scorePersistence) (instance std_msgs::Float32 :init))
    ((:nbrUpdate __nbrUpdate) (instance std_msgs::Float32 :init))
    ((:nbrAge __nbrAge) (instance std_msgs::Float32 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _segment __segment)
   (setq _QtySegment __QtySegment)
   (setq _lineClass __lineClass)
   (setq _idPiste __idPiste)
   (setq _existenceState __existenceState)
   (setq _scoreDetection __scoreDetection)
   (setq _nbrDetection __nbrDetection)
   (setq _nbrVisibility __nbrVisibility)
   (setq _scorePersistence __scorePersistence)
   (setq _nbrUpdate __nbrUpdate)
   (setq _nbrAge __nbrAge)
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
  (:segment
   (&rest __segment)
   (if (keywordp (car __segment))
       (send* _segment __segment)
     (progn
       (if __segment (setq _segment (car __segment)))
       _segment)))
  (:QtySegment
   (&rest __QtySegment)
   (if (keywordp (car __QtySegment))
       (send* _QtySegment __QtySegment)
     (progn
       (if __QtySegment (setq _QtySegment (car __QtySegment)))
       _QtySegment)))
  (:lineClass
   (&rest __lineClass)
   (if (keywordp (car __lineClass))
       (send* _lineClass __lineClass)
     (progn
       (if __lineClass (setq _lineClass (car __lineClass)))
       _lineClass)))
  (:idPiste
   (&rest __idPiste)
   (if (keywordp (car __idPiste))
       (send* _idPiste __idPiste)
     (progn
       (if __idPiste (setq _idPiste (car __idPiste)))
       _idPiste)))
  (:existenceState
   (&rest __existenceState)
   (if (keywordp (car __existenceState))
       (send* _existenceState __existenceState)
     (progn
       (if __existenceState (setq _existenceState (car __existenceState)))
       _existenceState)))
  (:scoreDetection
   (&rest __scoreDetection)
   (if (keywordp (car __scoreDetection))
       (send* _scoreDetection __scoreDetection)
     (progn
       (if __scoreDetection (setq _scoreDetection (car __scoreDetection)))
       _scoreDetection)))
  (:nbrDetection
   (&rest __nbrDetection)
   (if (keywordp (car __nbrDetection))
       (send* _nbrDetection __nbrDetection)
     (progn
       (if __nbrDetection (setq _nbrDetection (car __nbrDetection)))
       _nbrDetection)))
  (:nbrVisibility
   (&rest __nbrVisibility)
   (if (keywordp (car __nbrVisibility))
       (send* _nbrVisibility __nbrVisibility)
     (progn
       (if __nbrVisibility (setq _nbrVisibility (car __nbrVisibility)))
       _nbrVisibility)))
  (:scorePersistence
   (&rest __scorePersistence)
   (if (keywordp (car __scorePersistence))
       (send* _scorePersistence __scorePersistence)
     (progn
       (if __scorePersistence (setq _scorePersistence (car __scorePersistence)))
       _scorePersistence)))
  (:nbrUpdate
   (&rest __nbrUpdate)
   (if (keywordp (car __nbrUpdate))
       (send* _nbrUpdate __nbrUpdate)
     (progn
       (if __nbrUpdate (setq _nbrUpdate (car __nbrUpdate)))
       _nbrUpdate)))
  (:nbrAge
   (&rest __nbrAge)
   (if (keywordp (car __nbrAge))
       (send* _nbrAge __nbrAge)
     (progn
       (if __nbrAge (setq _nbrAge (car __nbrAge)))
       _nbrAge)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; project_s_msgs/Segment[3000] _segment
    (apply #'+ (send-all _segment :serialization-length))
    ;; std_msgs/UInt16 _QtySegment
    (send _QtySegment :serialization-length)
    ;; std_msgs/Float32 _lineClass
    (send _lineClass :serialization-length)
    ;; std_msgs/UInt16[2] _idPiste
    (apply #'+ (send-all _idPiste :serialization-length))
    ;; std_msgs/UInt8 _existenceState
    (send _existenceState :serialization-length)
    ;; std_msgs/Float32 _scoreDetection
    (send _scoreDetection :serialization-length)
    ;; std_msgs/Float32 _nbrDetection
    (send _nbrDetection :serialization-length)
    ;; std_msgs/Float32 _nbrVisibility
    (send _nbrVisibility :serialization-length)
    ;; std_msgs/Float32 _scorePersistence
    (send _scorePersistence :serialization-length)
    ;; std_msgs/Float32 _nbrUpdate
    (send _nbrUpdate :serialization-length)
    ;; std_msgs/Float32 _nbrAge
    (send _nbrAge :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; project_s_msgs/Segment[3000] _segment
     (dolist (elem _segment)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt16 _QtySegment
       (send _QtySegment :serialize s)
     ;; std_msgs/Float32 _lineClass
       (send _lineClass :serialize s)
     ;; std_msgs/UInt16[2] _idPiste
     (dolist (elem _idPiste)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _existenceState
       (send _existenceState :serialize s)
     ;; std_msgs/Float32 _scoreDetection
       (send _scoreDetection :serialize s)
     ;; std_msgs/Float32 _nbrDetection
       (send _nbrDetection :serialize s)
     ;; std_msgs/Float32 _nbrVisibility
       (send _nbrVisibility :serialize s)
     ;; std_msgs/Float32 _scorePersistence
       (send _scorePersistence :serialize s)
     ;; std_msgs/Float32 _nbrUpdate
       (send _nbrUpdate :serialize s)
     ;; std_msgs/Float32 _nbrAge
       (send _nbrAge :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; project_s_msgs/Segment[3000] _segment
   (dotimes (i 3000)
     (send (elt _segment i) :deserialize buf ptr-) (incf ptr- (send (elt _segment i) :serialization-length))
     )
   ;; std_msgs/UInt16 _QtySegment
     (send _QtySegment :deserialize buf ptr-) (incf ptr- (send _QtySegment :serialization-length))
   ;; std_msgs/Float32 _lineClass
     (send _lineClass :deserialize buf ptr-) (incf ptr- (send _lineClass :serialization-length))
   ;; std_msgs/UInt16[2] _idPiste
   (dotimes (i 2)
     (send (elt _idPiste i) :deserialize buf ptr-) (incf ptr- (send (elt _idPiste i) :serialization-length))
     )
   ;; std_msgs/UInt8 _existenceState
     (send _existenceState :deserialize buf ptr-) (incf ptr- (send _existenceState :serialization-length))
   ;; std_msgs/Float32 _scoreDetection
     (send _scoreDetection :deserialize buf ptr-) (incf ptr- (send _scoreDetection :serialization-length))
   ;; std_msgs/Float32 _nbrDetection
     (send _nbrDetection :deserialize buf ptr-) (incf ptr- (send _nbrDetection :serialization-length))
   ;; std_msgs/Float32 _nbrVisibility
     (send _nbrVisibility :deserialize buf ptr-) (incf ptr- (send _nbrVisibility :serialization-length))
   ;; std_msgs/Float32 _scorePersistence
     (send _scorePersistence :deserialize buf ptr-) (incf ptr- (send _scorePersistence :serialization-length))
   ;; std_msgs/Float32 _nbrUpdate
     (send _nbrUpdate :deserialize buf ptr-) (incf ptr- (send _nbrUpdate :serialization-length))
   ;; std_msgs/Float32 _nbrAge
     (send _nbrAge :deserialize buf ptr-) (incf ptr- (send _nbrAge :serialization-length))
   ;;
   self)
  )

(setf (get project_s_msgs::Line :md5sum-) "76c1d98fd2e545accf02a06698e73bb3")
(setf (get project_s_msgs::Line :datatype-) "project_s_msgs/Line")
(setf (get project_s_msgs::Line :definition-)
      "Header header
std_msgs/UInt8 id

uint16 SEGMENT_REPORT_SIZE = 3000
project_s_msgs/Segment[3000] segment
std_msgs/UInt16 QtySegment
std_msgs/Float32 lineClass	# class of the line
std_msgs/UInt16[2] idPiste	#define NBR_SOURCE_LINE		2	(voir lines_association.cpp)

std_msgs/UInt8 existenceState
std_msgs/Float32 scoreDetection
std_msgs/Float32 nbrDetection
std_msgs/Float32 nbrVisibility
std_msgs/Float32 scorePersistence
std_msgs/Float32 nbrUpdate
std_msgs/Float32 nbrAge



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
MSG: project_s_msgs/Segment
std_msgs/Float32 length		# length of the segment
std_msgs/Float32 angle		# angle of the segment
geometry_msgs/Point position
geometry_msgs/Twist Velocity

float32 offset
float64 latitude
float64 longitude


================================================================================
MSG: std_msgs/Float32
float32 data
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
================================================================================
MSG: std_msgs/UInt16
uint16 data

")



(provide :project_s_msgs/Line "76c1d98fd2e545accf02a06698e73bb3")


