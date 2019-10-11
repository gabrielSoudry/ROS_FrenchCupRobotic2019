#ifndef DEF_ROBOT_H
#define DEF_ROBOT_H

#include <vector>

//Ros lib
#include "ros/ros.h"
#include "ros/console.h"

//Ros messages
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Pose2D.h"

//DVB Lib
#include "dvb_hardware/hardware.h"

class Robot
{
    public:
        Robot(bool debug_mode);
        virtual ~Robot();

        void setEnable(bool state);
        void setStartable(bool state);

        bool getEnable();
        bool getStartable();

    protected:
        ros::NodeHandle nh_;

        //State
        bool debug_mode_;
        bool hardware_startable_;
        bool hardware_enable_;

        //Frequency rate in second
        ros::Duration rate_;
        double_t freq_;
        
};

#endif