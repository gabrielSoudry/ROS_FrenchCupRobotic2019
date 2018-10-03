;; Auto-generated. Do not edit!


(when (boundp 'location_monitor::LandMarkDistance)
  (if (not (find-package "LOCATION_MONITOR"))
    (make-package "LOCATION_MONITOR"))
  (shadow 'LandMarkDistance (find-package "LOCATION_MONITOR")))
(unless (find-package "LOCATION_MONITOR::LANDMARKDISTANCE")
  (make-package "LOCATION_MONITOR::LANDMARKDISTANCE"))

(in-package "ROS")
;;//! \htmlinclude LandMarkDistance.msg.html


(defclass location_monitor::LandMarkDistance
  :super ros::object
  :slots (_name _distance ))

(defmethod location_monitor::LandMarkDistance
  (:init
   (&key
    ((:name __name) "")
    ((:distance __distance) 0.0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _distance (float __distance))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; float64 _distance
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; float64 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float64 _distance
     (setq _distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get location_monitor::LandMarkDistance :md5sum-) "e2f8ddf8c9e39a28149179429f5ae342")
(setf (get location_monitor::LandMarkDistance :datatype-) "location_monitor/LandMarkDistance")
(setf (get location_monitor::LandMarkDistance :definition-)
      "string name 
float64 distance 
")



(provide :location_monitor/LandMarkDistance "e2f8ddf8c9e39a28149179429f5ae342")


