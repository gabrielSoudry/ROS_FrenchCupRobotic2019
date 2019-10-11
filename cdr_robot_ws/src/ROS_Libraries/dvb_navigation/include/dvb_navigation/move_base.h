#ifndef DEF_MOVE_BASE_H
#define DEF_MOVE_BASE_H

//Ros lib
#include "ros/ros.h"

//Ros messages
#include "geometry_msgs/Twist.h"

class Move_Base
{
    public:
        Move_Base();
        ~Move_Base();

        void spin();
        virtual void spinOnce();

        void setEnable(bool state);
        void setStartable(bool state);

        bool getEnable();
        bool getStartable();

    private:
        
};

#endif