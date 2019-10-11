#include "dvb_hardware/hardware.h"

Hardware::Hardware() :
    debug_mode_(false),
    hardware_startable_(false),
    hardware_enable_(false),
    freq_(0.001) //1 ms
{  
    nh_ = ros::NodeHandle("~");

    /*
		Get all params for ros server
	*/
    if( nh_.hasParam("/frequency") ||
        nh_.hasParam("/debug_mode")
    )
    {
        nh_.getParam("/frequency", freq_);
        nh_.getParam("/debug_mode", debug_mode_);
    }
    else
    {
		ROS_WARN("Please check if FREQUENCY | DEBUG_MODE parameters is set in the ROS Parameter Server !\n");
	}

    rate_ = ros::Duration(freq_);
}

Hardware::~Hardware(){

}

void Hardware::spin()
{
    
}

void Hardware::spinOnce(){
    
}

void Hardware::setEnable(bool state)
{
    hardware_enable_ = state;
}

void Hardware::setStartable(bool state)
{
    hardware_startable_ = state;
}

bool Hardware::getEnable()
{
    return hardware_enable_;
}

bool Hardware::getStartable()
{
    return hardware_startable_;
}