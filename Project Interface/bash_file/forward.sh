#!/usr/bin/expect
spawn ssh gab@192.168.1.101
##spawn ssh cdr-robot1@192.168.1.101
set host [lindex $argv 0]

expect "assword:" 
send "gab\r"
expect "$ " {send "cd Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/optimiste_ws \r" }
expect "$ " {send "source devel/setup.bash\r" }
expect "$ " {send "rosrun deplacement test.py $host $host \r" }
expect "$ "
interact




