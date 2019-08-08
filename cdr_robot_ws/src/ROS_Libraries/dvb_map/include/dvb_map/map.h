#ifndef DEF_MAP_H
#define DEF_MAP_H

#include <vector>

//Ros lib
#include "ros/ros.h"
#include "ros/console.h"

//Ros messages
#include "geometry_msgs/Point.h"

//DVB Lib
#include "dvb_robot/robot.h"

class Map
{
    public:
        Map(bool debug_mode);
        virtual ~Map();
        
    private:
        bool debug_mode_;

        std::vector<int> robots_;
        std::vector<int> obstaces_;
};

#endif