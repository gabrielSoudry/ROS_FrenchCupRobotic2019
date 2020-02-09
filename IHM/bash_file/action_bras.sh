#!/usr/bin/expect -f
spawn ssh gab@192.168.1.101
expect "assword:" 
send "gab\r"
set host [lindex $argv 0]
expect "$ " {send "rostopic pub /robot/servo std_msgs/Int16 $host \r"}
expect "$ " {send "sleep 1\r"}
interact