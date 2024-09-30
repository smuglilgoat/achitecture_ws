;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::Side)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'Side (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::SIDE")
  (make-package "PROJECT_S_MSGS::SIDE"))

(in-package "ROS")
;;//! \htmlinclude Side.msg.html


(defclass project_s_msgs::Side
  :super ros::object
  :slots (_segment ))

(defmethod project_s_msgs::Side
  (:init
   (&key
    ((:segment __segment) (let (r) (dotimes (i 100) (push (instance project_s_msgs::Segment :init) r)) r))
    )
   (send-super :init)
   (setq _segment __segment)
   self)
  (:segment
   (&rest __segment)
   (if (keywordp (car __segment))
       (send* _segment __segment)
     (progn
       (if __segment (setq _segment (car __segment)))
       _segment)))
  (:serialization-length
   ()
   (+
    ;; project_s_msgs/Segment[100] _segment
    (apply #'+ (send-all _segment :serialization-length))
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; project_s_msgs/Segment[100] _segment
     (dolist (elem _segment)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; project_s_msgs/Segment[100] _segment
   (dotimes (i 100)
     (send (elt _segment i) :deserialize buf ptr-) (incf ptr- (send (elt _segment i) :serialization-length))
     )
   ;;
   self)
  )

(setf (get project_s_msgs::Side :md5sum-) "3cee93af1c46f02386b8de1d0844998c")
(setf (get project_s_msgs::Side :datatype-) "project_s_msgs/Side")
(setf (get project_s_msgs::Side :definition-)
      "project_s_msgs/Segment[100] segment

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
")



(provide :project_s_msgs/Side "3cee93af1c46f02386b8de1d0844998c")


