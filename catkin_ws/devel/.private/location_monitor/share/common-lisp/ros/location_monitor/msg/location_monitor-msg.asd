
(cl:in-package :asdf)

(defsystem "location_monitor-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "LandMarkDistance" :depends-on ("_package_LandMarkDistance"))
    (:file "_package_LandMarkDistance" :depends-on ("_package"))
  ))