#!/usr/bin/env python

import rospy
from std_msgs.msg import Float64

rospy.init_node("Redressement")

pub = rospy.Publisher('/robot/base/wheel/right/setpoint', Float64, queue_size=10)
pub2 = rospy.Publisher('/robot/base/wheel/left/setpoint', Float64, queue_size=10)
rospy.sleep(2.0)
#r = rospy.Rate(10) # 10hz

pub.publish(6700)
rospy.sleep(2.0)
#rospy.sleep(0.001)
pub2.publish(6700)

rospy.spin()
