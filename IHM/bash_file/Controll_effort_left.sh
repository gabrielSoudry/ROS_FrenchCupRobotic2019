#!/usr/bin/expect -f
spawn ssh gab@192.168.1.101
#spawn ssh cdr-robot1@192.168.1.101
expect "assword:" 
send "gab\r"
expect "$ " {send "rostopic pub /robot/base/wheel/left/control_effort std_msgs/Float64 500 \r"}
expect "$ " {send "sleep 1\r"}
