#include "dvb_control/pid.h"

Pid::Pid() :
	Dvb_Spinner(),
	target_(0),
    output_(0),
	kp_(0.0),
	ki_(0.0),
	kd_(0.0),
	integral_(0.0),
    error_(0.0),
    derivative_(0.0),
    previous_error_(0.0)
{
    nh_ = ros::NodeHandle("~");
    
	prev_time_ = ros::Time::now();

	/*
		Get all params for ros server
	*/
	//PID params
	if (
			nh_.hasParam("/control/pid/Kp") ||
			nh_.hasParam("/control/pid//Ki") ||
			nh_.hasParam("/control/pid//Kd")
	   )
	{
		nh_.getParam("/control/pid/Kp", kp_);
		nh_.getParam("/control/pid/Kp", ki_);
		nh_.getParam("/control/pid//Kd", kd_);

		spinner_startable_ = true;
	}
	else{
		ROS_INFO("Please check if PID parameters are set in the ROS Parameter Server !\n");
	}	
}



void Pid::calcul_pid(float_t prev_val)
{
	//Initialize PID stuffs
	float_t P_val = 0;
	float_t I_val = 0;
	float_t D_val = 0;
	
	previous_error_ = 0;
	integral_ = 0;
	error_ = 0;
	derivative_ = 0;

	//Starting PID calculation
	error_ = target_ - prev_val;

	P_val = kp_ * error_;

	//Update dt
	dt_ = ros::Time::now() - prev_time_;
	prev_time_ = ros::Time::now();

	integral_ += error_ * (float_t)dt_.toSec();
	I_val = ki_ * integral_;

	derivative_ = (error_ - previous_error_) / dt_.toSec();
	previous_error_ = error_;

	output_ = P_val + I_val + D_val;
}