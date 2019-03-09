
#!/usr/bin/env python

import rospy
from std_msgs.msg import Float64

rospy.init_node("test")

pub = rospy.Publisher('/robot/base/wheel/right/setpoint', Float64, queue_size=10)
pub2 = rospy.Publisher('/robot/base/wheel/left/setpoint', Float64, queue_size=10)
rospy.sleep(2.0)
#r = rospy.Rate(10) # 10hz

pub.publish(5800)
#rospy.sleep(0.001)
pub2.publish(5800)

rospy.spin()


