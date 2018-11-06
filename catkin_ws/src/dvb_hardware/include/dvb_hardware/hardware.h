#ifndef DEF_HARDWARE_H
#define DEF_HARDWARE_H

#include <stdio.h>
#include <vector>

//GPIO raspberry lib
//#include <wiringPi.h>

//Ros lib
#include "ros/ros.h"
#include "ros/console.h"

//Ros messages
#include "std_msgs/Int32.h"
#include "sensor_msgs/Range.h"

class Hardware
{
    public:
        Hardware(bool debug_mode);

        virtual ~Hardware();

        void spin();
        virtual void spinOnce();

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