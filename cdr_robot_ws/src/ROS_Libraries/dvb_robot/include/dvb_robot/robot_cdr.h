#ifndef DEF_ROBOT_CDR_H
#define DEF_ROBOT_CDR_H

#include "dvb_robot/robot.h"

class Robot_Cdr : public Robot
{
    public:
        Robot();
        ~Robot();

    private:
        //Robot position in the map
        geometry_msgs::Pose2D robot_pos_;

};

#endif