#!/usr/bin/expect -f
spawn ssh gab@192.168.1.101
##spawn ssh cdr-robot1@192.168.1.101
expect "assword:" 
send "gab\r"
expect "$ " {send "rosnode cleanup  \r"}
expect "$ " {send "rosnode kill -a \r"}
expect "$ " {send "killall -9 rosmaster \r"}
expect "$ " {send "killall -9 roscore \r"}
