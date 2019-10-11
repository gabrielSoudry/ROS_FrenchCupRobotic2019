#ifndef DEF_DIFF_ROBOT_ODOMETRY_H
#define DEF_DIFF_ROBOT_ODOMETRY_H

#include "ros/ros.h"
#include "tf/transform_broadcaster.h"
#include "nav_msgs/Odometry.h"

class Test 
{
    public:
        nav_msgs::Odometry odom_;
        void test();
};

#endif