#!/usr/bin/expect -f
spawn ssh gab@192.168.1.101
#spawn ssh cdr-robot1@192.168.1.101
expect "assword:" 
send "gab\r"
expect "$ " {send "rostopic echo /robot/base/wheel/right/state \r"}
interact

