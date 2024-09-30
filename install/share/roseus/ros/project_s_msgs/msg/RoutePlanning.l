;; Auto-generated. Do not edit!


(when (boundp 'project_s_msgs::RoutePlanning)
  (if (not (find-package "PROJECT_S_MSGS"))
    (make-package "PROJECT_S_MSGS"))
  (shadow 'RoutePlanning (find-package "PROJECT_S_MSGS")))
(unless (find-package "PROJECT_S_MSGS::ROUTEPLANNING")
  (make-package "PROJECT_S_MSGS::ROUTEPLANNING"))

(in-package "ROS")
;;//! \htmlinclude RoutePlanning.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass project_s_msgs::RoutePlanning
  :super ros::object
  :slots (_header _id _roadSegment _nbrLane _intersection _list_Links_ID _list_Links_HEREtile_ID _list_Nodes_ID _list_Nodes_HEREtile_ID _list_Links_vs_Route_direction _LIST_LINKS_SIZE _NBRE_POINT_CIRCUIT_GPS _NBRE_POINT_TABLEAU_GPS _Tableau_circuit_GPS _Tableau_circuit_GPS_gauche _Tableau_circuit_GPS_droite _Tableau_circuit_GPS_MEgauche _Tableau_circuit_GPS_MEdroite _Tableau_circuit_speedlimit _Tableau_circuit_curvature _Tableau_circuit_trafficsign _Tableau_circuit_ehSegmentAO _Tableau_circuit_ehSegmentEO ))

(defmethod project_s_msgs::RoutePlanning
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) (instance std_msgs::UInt8 :init))
    ((:roadSegment __roadSegment) (let (r) (dotimes (i 0) (push (instance project_s_msgs::Segment :init) r)) r))
    ((:nbrLane __nbrLane) (instance std_msgs::UInt8 :init))
    ((:intersection __intersection) (instance std_msgs::UInt8 :init))
    ((:list_Links_ID __list_Links_ID) (make-array 0 :initial-element 0 :element-type :integer))
    ((:list_Links_HEREtile_ID __list_Links_HEREtile_ID) (make-array 0 :initial-element 0 :element-type :integer))
    ((:list_Nodes_ID __list_Nodes_ID) (make-array 0 :initial-element 0 :element-type :integer))
    ((:list_Nodes_HEREtile_ID __list_Nodes_HEREtile_ID) (make-array 0 :initial-element 0 :element-type :integer))
    ((:list_Links_vs_Route_direction __list_Links_vs_Route_direction) (let (r) (dotimes (i 0) (push nil r)) r))
    ((:LIST_LINKS_SIZE __LIST_LINKS_SIZE) 0)
    ((:NBRE_POINT_CIRCUIT_GPS __NBRE_POINT_CIRCUIT_GPS) 0)
    ((:NBRE_POINT_TABLEAU_GPS __NBRE_POINT_TABLEAU_GPS) 0)
    ((:Tableau_circuit_GPS __Tableau_circuit_GPS) (let (r) (dotimes (i 0) (push (instance project_s_msgs::point_GPS :init) r)) r))
    ((:Tableau_circuit_GPS_gauche __Tableau_circuit_GPS_gauche) (let (r) (dotimes (i 0) (push (instance project_s_msgs::point_GPS :init) r)) r))
    ((:Tableau_circuit_GPS_droite __Tableau_circuit_GPS_droite) (let (r) (dotimes (i 0) (push (instance project_s_msgs::point_GPS :init) r)) r))
    ((:Tableau_circuit_GPS_MEgauche __Tableau_circuit_GPS_MEgauche) (let (r) (dotimes (i 0) (push (instance project_s_msgs::point_GPS :init) r)) r))
    ((:Tableau_circuit_GPS_MEdroite __Tableau_circuit_GPS_MEdroite) (let (r) (dotimes (i 0) (push (instance project_s_msgs::point_GPS :init) r)) r))
    ((:Tableau_circuit_speedlimit __Tableau_circuit_speedlimit) (let (r) (dotimes (i 0) (push (instance project_s_msgs::speed_limit :init) r)) r))
    ((:Tableau_circuit_curvature __Tableau_circuit_curvature) (let (r) (dotimes (i 0) (push (instance project_s_msgs::curvature :init) r)) r))
    ((:Tableau_circuit_trafficsign __Tableau_circuit_trafficsign) (let (r) (dotimes (i 0) (push (instance project_s_msgs::traffic_sign :init) r)) r))
    ((:Tableau_circuit_ehSegmentAO __Tableau_circuit_ehSegmentAO) (let (r) (dotimes (i 0) (push (instance project_s_msgs::segmentME :init) r)) r))
    ((:Tableau_circuit_ehSegmentEO __Tableau_circuit_ehSegmentEO) (let (r) (dotimes (i 0) (push (instance project_s_msgs::segmentME :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _id __id)
   (setq _roadSegment __roadSegment)
   (setq _nbrLane __nbrLane)
   (setq _intersection __intersection)
   (setq _list_Links_ID __list_Links_ID)
   (setq _list_Links_HEREtile_ID __list_Links_HEREtile_ID)
   (setq _list_Nodes_ID __list_Nodes_ID)
   (setq _list_Nodes_HEREtile_ID __list_Nodes_HEREtile_ID)
   (setq _list_Links_vs_Route_direction __list_Links_vs_Route_direction)
   (setq _LIST_LINKS_SIZE (round __LIST_LINKS_SIZE))
   (setq _NBRE_POINT_CIRCUIT_GPS (round __NBRE_POINT_CIRCUIT_GPS))
   (setq _NBRE_POINT_TABLEAU_GPS (round __NBRE_POINT_TABLEAU_GPS))
   (setq _Tableau_circuit_GPS __Tableau_circuit_GPS)
   (setq _Tableau_circuit_GPS_gauche __Tableau_circuit_GPS_gauche)
   (setq _Tableau_circuit_GPS_droite __Tableau_circuit_GPS_droite)
   (setq _Tableau_circuit_GPS_MEgauche __Tableau_circuit_GPS_MEgauche)
   (setq _Tableau_circuit_GPS_MEdroite __Tableau_circuit_GPS_MEdroite)
   (setq _Tableau_circuit_speedlimit __Tableau_circuit_speedlimit)
   (setq _Tableau_circuit_curvature __Tableau_circuit_curvature)
   (setq _Tableau_circuit_trafficsign __Tableau_circuit_trafficsign)
   (setq _Tableau_circuit_ehSegmentAO __Tableau_circuit_ehSegmentAO)
   (setq _Tableau_circuit_ehSegmentEO __Tableau_circuit_ehSegmentEO)
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
  (:roadSegment
   (&rest __roadSegment)
   (if (keywordp (car __roadSegment))
       (send* _roadSegment __roadSegment)
     (progn
       (if __roadSegment (setq _roadSegment (car __roadSegment)))
       _roadSegment)))
  (:nbrLane
   (&rest __nbrLane)
   (if (keywordp (car __nbrLane))
       (send* _nbrLane __nbrLane)
     (progn
       (if __nbrLane (setq _nbrLane (car __nbrLane)))
       _nbrLane)))
  (:intersection
   (&rest __intersection)
   (if (keywordp (car __intersection))
       (send* _intersection __intersection)
     (progn
       (if __intersection (setq _intersection (car __intersection)))
       _intersection)))
  (:list_Links_ID
   (&optional __list_Links_ID)
   (if __list_Links_ID (setq _list_Links_ID __list_Links_ID)) _list_Links_ID)
  (:list_Links_HEREtile_ID
   (&optional __list_Links_HEREtile_ID)
   (if __list_Links_HEREtile_ID (setq _list_Links_HEREtile_ID __list_Links_HEREtile_ID)) _list_Links_HEREtile_ID)
  (:list_Nodes_ID
   (&optional __list_Nodes_ID)
   (if __list_Nodes_ID (setq _list_Nodes_ID __list_Nodes_ID)) _list_Nodes_ID)
  (:list_Nodes_HEREtile_ID
   (&optional __list_Nodes_HEREtile_ID)
   (if __list_Nodes_HEREtile_ID (setq _list_Nodes_HEREtile_ID __list_Nodes_HEREtile_ID)) _list_Nodes_HEREtile_ID)
  (:list_Links_vs_Route_direction
   (&optional __list_Links_vs_Route_direction)
   (if __list_Links_vs_Route_direction (setq _list_Links_vs_Route_direction __list_Links_vs_Route_direction)) _list_Links_vs_Route_direction)
  (:LIST_LINKS_SIZE
   (&optional __LIST_LINKS_SIZE)
   (if __LIST_LINKS_SIZE (setq _LIST_LINKS_SIZE __LIST_LINKS_SIZE)) _LIST_LINKS_SIZE)
  (:NBRE_POINT_CIRCUIT_GPS
   (&optional __NBRE_POINT_CIRCUIT_GPS)
   (if __NBRE_POINT_CIRCUIT_GPS (setq _NBRE_POINT_CIRCUIT_GPS __NBRE_POINT_CIRCUIT_GPS)) _NBRE_POINT_CIRCUIT_GPS)
  (:NBRE_POINT_TABLEAU_GPS
   (&optional __NBRE_POINT_TABLEAU_GPS)
   (if __NBRE_POINT_TABLEAU_GPS (setq _NBRE_POINT_TABLEAU_GPS __NBRE_POINT_TABLEAU_GPS)) _NBRE_POINT_TABLEAU_GPS)
  (:Tableau_circuit_GPS
   (&rest __Tableau_circuit_GPS)
   (if (keywordp (car __Tableau_circuit_GPS))
       (send* _Tableau_circuit_GPS __Tableau_circuit_GPS)
     (progn
       (if __Tableau_circuit_GPS (setq _Tableau_circuit_GPS (car __Tableau_circuit_GPS)))
       _Tableau_circuit_GPS)))
  (:Tableau_circuit_GPS_gauche
   (&rest __Tableau_circuit_GPS_gauche)
   (if (keywordp (car __Tableau_circuit_GPS_gauche))
       (send* _Tableau_circuit_GPS_gauche __Tableau_circuit_GPS_gauche)
     (progn
       (if __Tableau_circuit_GPS_gauche (setq _Tableau_circuit_GPS_gauche (car __Tableau_circuit_GPS_gauche)))
       _Tableau_circuit_GPS_gauche)))
  (:Tableau_circuit_GPS_droite
   (&rest __Tableau_circuit_GPS_droite)
   (if (keywordp (car __Tableau_circuit_GPS_droite))
       (send* _Tableau_circuit_GPS_droite __Tableau_circuit_GPS_droite)
     (progn
       (if __Tableau_circuit_GPS_droite (setq _Tableau_circuit_GPS_droite (car __Tableau_circuit_GPS_droite)))
       _Tableau_circuit_GPS_droite)))
  (:Tableau_circuit_GPS_MEgauche
   (&rest __Tableau_circuit_GPS_MEgauche)
   (if (keywordp (car __Tableau_circuit_GPS_MEgauche))
       (send* _Tableau_circuit_GPS_MEgauche __Tableau_circuit_GPS_MEgauche)
     (progn
       (if __Tableau_circuit_GPS_MEgauche (setq _Tableau_circuit_GPS_MEgauche (car __Tableau_circuit_GPS_MEgauche)))
       _Tableau_circuit_GPS_MEgauche)))
  (:Tableau_circuit_GPS_MEdroite
   (&rest __Tableau_circuit_GPS_MEdroite)
   (if (keywordp (car __Tableau_circuit_GPS_MEdroite))
       (send* _Tableau_circuit_GPS_MEdroite __Tableau_circuit_GPS_MEdroite)
     (progn
       (if __Tableau_circuit_GPS_MEdroite (setq _Tableau_circuit_GPS_MEdroite (car __Tableau_circuit_GPS_MEdroite)))
       _Tableau_circuit_GPS_MEdroite)))
  (:Tableau_circuit_speedlimit
   (&rest __Tableau_circuit_speedlimit)
   (if (keywordp (car __Tableau_circuit_speedlimit))
       (send* _Tableau_circuit_speedlimit __Tableau_circuit_speedlimit)
     (progn
       (if __Tableau_circuit_speedlimit (setq _Tableau_circuit_speedlimit (car __Tableau_circuit_speedlimit)))
       _Tableau_circuit_speedlimit)))
  (:Tableau_circuit_curvature
   (&rest __Tableau_circuit_curvature)
   (if (keywordp (car __Tableau_circuit_curvature))
       (send* _Tableau_circuit_curvature __Tableau_circuit_curvature)
     (progn
       (if __Tableau_circuit_curvature (setq _Tableau_circuit_curvature (car __Tableau_circuit_curvature)))
       _Tableau_circuit_curvature)))
  (:Tableau_circuit_trafficsign
   (&rest __Tableau_circuit_trafficsign)
   (if (keywordp (car __Tableau_circuit_trafficsign))
       (send* _Tableau_circuit_trafficsign __Tableau_circuit_trafficsign)
     (progn
       (if __Tableau_circuit_trafficsign (setq _Tableau_circuit_trafficsign (car __Tableau_circuit_trafficsign)))
       _Tableau_circuit_trafficsign)))
  (:Tableau_circuit_ehSegmentAO
   (&rest __Tableau_circuit_ehSegmentAO)
   (if (keywordp (car __Tableau_circuit_ehSegmentAO))
       (send* _Tableau_circuit_ehSegmentAO __Tableau_circuit_ehSegmentAO)
     (progn
       (if __Tableau_circuit_ehSegmentAO (setq _Tableau_circuit_ehSegmentAO (car __Tableau_circuit_ehSegmentAO)))
       _Tableau_circuit_ehSegmentAO)))
  (:Tableau_circuit_ehSegmentEO
   (&rest __Tableau_circuit_ehSegmentEO)
   (if (keywordp (car __Tableau_circuit_ehSegmentEO))
       (send* _Tableau_circuit_ehSegmentEO __Tableau_circuit_ehSegmentEO)
     (progn
       (if __Tableau_circuit_ehSegmentEO (setq _Tableau_circuit_ehSegmentEO (car __Tableau_circuit_ehSegmentEO)))
       _Tableau_circuit_ehSegmentEO)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/UInt8 _id
    (send _id :serialization-length)
    ;; project_s_msgs/Segment[] _roadSegment
    (apply #'+ (send-all _roadSegment :serialization-length)) 4
    ;; std_msgs/UInt8 _nbrLane
    (send _nbrLane :serialization-length)
    ;; std_msgs/UInt8 _intersection
    (send _intersection :serialization-length)
    ;; uint32[] _list_Links_ID
    (* 4    (length _list_Links_ID)) 4
    ;; uint32[] _list_Links_HEREtile_ID
    (* 4    (length _list_Links_HEREtile_ID)) 4
    ;; uint32[] _list_Nodes_ID
    (* 4    (length _list_Nodes_ID)) 4
    ;; uint32[] _list_Nodes_HEREtile_ID
    (* 4    (length _list_Nodes_HEREtile_ID)) 4
    ;; bool[] _list_Links_vs_Route_direction
    (* 1    (length _list_Links_vs_Route_direction)) 4
    ;; uint32 _LIST_LINKS_SIZE
    4
    ;; uint32 _NBRE_POINT_CIRCUIT_GPS
    4
    ;; uint32 _NBRE_POINT_TABLEAU_GPS
    4
    ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS
    (apply #'+ (send-all _Tableau_circuit_GPS :serialization-length)) 4
    ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_gauche
    (apply #'+ (send-all _Tableau_circuit_GPS_gauche :serialization-length)) 4
    ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_droite
    (apply #'+ (send-all _Tableau_circuit_GPS_droite :serialization-length)) 4
    ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_MEgauche
    (apply #'+ (send-all _Tableau_circuit_GPS_MEgauche :serialization-length)) 4
    ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_MEdroite
    (apply #'+ (send-all _Tableau_circuit_GPS_MEdroite :serialization-length)) 4
    ;; project_s_msgs/speed_limit[] _Tableau_circuit_speedlimit
    (apply #'+ (send-all _Tableau_circuit_speedlimit :serialization-length)) 4
    ;; project_s_msgs/curvature[] _Tableau_circuit_curvature
    (apply #'+ (send-all _Tableau_circuit_curvature :serialization-length)) 4
    ;; project_s_msgs/traffic_sign[] _Tableau_circuit_trafficsign
    (apply #'+ (send-all _Tableau_circuit_trafficsign :serialization-length)) 4
    ;; project_s_msgs/segmentME[] _Tableau_circuit_ehSegmentAO
    (apply #'+ (send-all _Tableau_circuit_ehSegmentAO :serialization-length)) 4
    ;; project_s_msgs/segmentME[] _Tableau_circuit_ehSegmentEO
    (apply #'+ (send-all _Tableau_circuit_ehSegmentEO :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/UInt8 _id
       (send _id :serialize s)
     ;; project_s_msgs/Segment[] _roadSegment
     (write-long (length _roadSegment) s)
     (dolist (elem _roadSegment)
       (send elem :serialize s)
       )
     ;; std_msgs/UInt8 _nbrLane
       (send _nbrLane :serialize s)
     ;; std_msgs/UInt8 _intersection
       (send _intersection :serialize s)
     ;; uint32[] _list_Links_ID
     (write-long (length _list_Links_ID) s)
     (dotimes (i (length _list_Links_ID))
       (write-long (elt _list_Links_ID i) s)
       )
     ;; uint32[] _list_Links_HEREtile_ID
     (write-long (length _list_Links_HEREtile_ID) s)
     (dotimes (i (length _list_Links_HEREtile_ID))
       (write-long (elt _list_Links_HEREtile_ID i) s)
       )
     ;; uint32[] _list_Nodes_ID
     (write-long (length _list_Nodes_ID) s)
     (dotimes (i (length _list_Nodes_ID))
       (write-long (elt _list_Nodes_ID i) s)
       )
     ;; uint32[] _list_Nodes_HEREtile_ID
     (write-long (length _list_Nodes_HEREtile_ID) s)
     (dotimes (i (length _list_Nodes_HEREtile_ID))
       (write-long (elt _list_Nodes_HEREtile_ID i) s)
       )
     ;; bool[] _list_Links_vs_Route_direction
     (write-long (length _list_Links_vs_Route_direction) s)
     (dotimes (i (length _list_Links_vs_Route_direction))
       (if (elt _list_Links_vs_Route_direction i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; uint32 _LIST_LINKS_SIZE
       (write-long _LIST_LINKS_SIZE s)
     ;; uint32 _NBRE_POINT_CIRCUIT_GPS
       (write-long _NBRE_POINT_CIRCUIT_GPS s)
     ;; uint32 _NBRE_POINT_TABLEAU_GPS
       (write-long _NBRE_POINT_TABLEAU_GPS s)
     ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS
     (write-long (length _Tableau_circuit_GPS) s)
     (dolist (elem _Tableau_circuit_GPS)
       (send elem :serialize s)
       )
     ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_gauche
     (write-long (length _Tableau_circuit_GPS_gauche) s)
     (dolist (elem _Tableau_circuit_GPS_gauche)
       (send elem :serialize s)
       )
     ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_droite
     (write-long (length _Tableau_circuit_GPS_droite) s)
     (dolist (elem _Tableau_circuit_GPS_droite)
       (send elem :serialize s)
       )
     ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_MEgauche
     (write-long (length _Tableau_circuit_GPS_MEgauche) s)
     (dolist (elem _Tableau_circuit_GPS_MEgauche)
       (send elem :serialize s)
       )
     ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_MEdroite
     (write-long (length _Tableau_circuit_GPS_MEdroite) s)
     (dolist (elem _Tableau_circuit_GPS_MEdroite)
       (send elem :serialize s)
       )
     ;; project_s_msgs/speed_limit[] _Tableau_circuit_speedlimit
     (write-long (length _Tableau_circuit_speedlimit) s)
     (dolist (elem _Tableau_circuit_speedlimit)
       (send elem :serialize s)
       )
     ;; project_s_msgs/curvature[] _Tableau_circuit_curvature
     (write-long (length _Tableau_circuit_curvature) s)
     (dolist (elem _Tableau_circuit_curvature)
       (send elem :serialize s)
       )
     ;; project_s_msgs/traffic_sign[] _Tableau_circuit_trafficsign
     (write-long (length _Tableau_circuit_trafficsign) s)
     (dolist (elem _Tableau_circuit_trafficsign)
       (send elem :serialize s)
       )
     ;; project_s_msgs/segmentME[] _Tableau_circuit_ehSegmentAO
     (write-long (length _Tableau_circuit_ehSegmentAO) s)
     (dolist (elem _Tableau_circuit_ehSegmentAO)
       (send elem :serialize s)
       )
     ;; project_s_msgs/segmentME[] _Tableau_circuit_ehSegmentEO
     (write-long (length _Tableau_circuit_ehSegmentEO) s)
     (dolist (elem _Tableau_circuit_ehSegmentEO)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/UInt8 _id
     (send _id :deserialize buf ptr-) (incf ptr- (send _id :serialization-length))
   ;; project_s_msgs/Segment[] _roadSegment
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _roadSegment (let (r) (dotimes (i n) (push (instance project_s_msgs::Segment :init) r)) r))
     (dolist (elem- _roadSegment)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; std_msgs/UInt8 _nbrLane
     (send _nbrLane :deserialize buf ptr-) (incf ptr- (send _nbrLane :serialization-length))
   ;; std_msgs/UInt8 _intersection
     (send _intersection :deserialize buf ptr-) (incf ptr- (send _intersection :serialization-length))
   ;; uint32[] _list_Links_ID
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _list_Links_ID (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _list_Links_ID i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; uint32[] _list_Links_HEREtile_ID
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _list_Links_HEREtile_ID (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _list_Links_HEREtile_ID i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; uint32[] _list_Nodes_ID
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _list_Nodes_ID (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _list_Nodes_ID i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; uint32[] _list_Nodes_HEREtile_ID
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _list_Nodes_HEREtile_ID (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _list_Nodes_HEREtile_ID i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; bool[] _list_Links_vs_Route_direction
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _list_Links_vs_Route_direction (make-list n))
     (dotimes (i n)
     (setf (elt _list_Links_vs_Route_direction i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     ))
   ;; uint32 _LIST_LINKS_SIZE
     (setq _LIST_LINKS_SIZE (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _NBRE_POINT_CIRCUIT_GPS
     (setq _NBRE_POINT_CIRCUIT_GPS (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _NBRE_POINT_TABLEAU_GPS
     (setq _NBRE_POINT_TABLEAU_GPS (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _Tableau_circuit_GPS (let (r) (dotimes (i n) (push (instance project_s_msgs::point_GPS :init) r)) r))
     (dolist (elem- _Tableau_circuit_GPS)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_gauche
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _Tableau_circuit_GPS_gauche (let (r) (dotimes (i n) (push (instance project_s_msgs::point_GPS :init) r)) r))
     (dolist (elem- _Tableau_circuit_GPS_gauche)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_droite
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _Tableau_circuit_GPS_droite (let (r) (dotimes (i n) (push (instance project_s_msgs::point_GPS :init) r)) r))
     (dolist (elem- _Tableau_circuit_GPS_droite)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_MEgauche
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _Tableau_circuit_GPS_MEgauche (let (r) (dotimes (i n) (push (instance project_s_msgs::point_GPS :init) r)) r))
     (dolist (elem- _Tableau_circuit_GPS_MEgauche)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; project_s_msgs/point_GPS[] _Tableau_circuit_GPS_MEdroite
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _Tableau_circuit_GPS_MEdroite (let (r) (dotimes (i n) (push (instance project_s_msgs::point_GPS :init) r)) r))
     (dolist (elem- _Tableau_circuit_GPS_MEdroite)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; project_s_msgs/speed_limit[] _Tableau_circuit_speedlimit
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _Tableau_circuit_speedlimit (let (r) (dotimes (i n) (push (instance project_s_msgs::speed_limit :init) r)) r))
     (dolist (elem- _Tableau_circuit_speedlimit)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; project_s_msgs/curvature[] _Tableau_circuit_curvature
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _Tableau_circuit_curvature (let (r) (dotimes (i n) (push (instance project_s_msgs::curvature :init) r)) r))
     (dolist (elem- _Tableau_circuit_curvature)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; project_s_msgs/traffic_sign[] _Tableau_circuit_trafficsign
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _Tableau_circuit_trafficsign (let (r) (dotimes (i n) (push (instance project_s_msgs::traffic_sign :init) r)) r))
     (dolist (elem- _Tableau_circuit_trafficsign)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; project_s_msgs/segmentME[] _Tableau_circuit_ehSegmentAO
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _Tableau_circuit_ehSegmentAO (let (r) (dotimes (i n) (push (instance project_s_msgs::segmentME :init) r)) r))
     (dolist (elem- _Tableau_circuit_ehSegmentAO)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; project_s_msgs/segmentME[] _Tableau_circuit_ehSegmentEO
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _Tableau_circuit_ehSegmentEO (let (r) (dotimes (i n) (push (instance project_s_msgs::segmentME :init) r)) r))
     (dolist (elem- _Tableau_circuit_ehSegmentEO)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get project_s_msgs::RoutePlanning :md5sum-) "686ce86a53e3fc605337589df78e8395")
(setf (get project_s_msgs::RoutePlanning :datatype-) "project_s_msgs/RoutePlanning")
(setf (get project_s_msgs::RoutePlanning :definition-)
      "Header header
std_msgs/UInt8 id

project_s_msgs/Segment[] roadSegment		#segments array   
std_msgs/UInt8 nbrLane
std_msgs/UInt8 intersection

uint32[] list_Links_ID
uint32[] list_Links_HEREtile_ID
uint32[] list_Nodes_ID
uint32[] list_Nodes_HEREtile_ID
bool[] list_Links_vs_Route_direction
uint32 LIST_LINKS_SIZE

uint32 NBRE_POINT_CIRCUIT_GPS
uint32 NBRE_POINT_TABLEAU_GPS

project_s_msgs/point_GPS[]   Tableau_circuit_GPS
project_s_msgs/point_GPS[]   Tableau_circuit_GPS_gauche
project_s_msgs/point_GPS[]   Tableau_circuit_GPS_droite

project_s_msgs/point_GPS[]   Tableau_circuit_GPS_MEgauche
project_s_msgs/point_GPS[]   Tableau_circuit_GPS_MEdroite

project_s_msgs/speed_limit[] Tableau_circuit_speedlimit
project_s_msgs/curvature[]   Tableau_circuit_curvature
project_s_msgs/traffic_sign[]   Tableau_circuit_trafficsign


project_s_msgs/segmentME[] Tableau_circuit_ehSegmentAO
project_s_msgs/segmentME[] Tableau_circuit_ehSegmentEO


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
MSG: project_s_msgs/point_GPS
float64 latitude
float64 longitude
float32 offset


================================================================================
MSG: project_s_msgs/speed_limit
float32 offset
uint8 effectiveSpeedLimit


================================================================================
MSG: project_s_msgs/curvature
float32 offset
float32 value

================================================================================
MSG: project_s_msgs/traffic_sign
float32 offset
uint8 Sign_Type
uint8 Value
uint8 Lane
uint8 Sign_Location
float64 latitude
float64 longitude




================================================================================
MSG: project_s_msgs/segmentME
uint32 NbrSpot
float32 offset_debut
float32 offset_fin



")



(provide :project_s_msgs/RoutePlanning "686ce86a53e3fc605337589df78e8395")


