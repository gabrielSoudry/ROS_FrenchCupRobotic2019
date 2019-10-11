 #include "dvb_control/move_base.h"

/**

Move_Base::Move_Base() :
    node_name_(""),
    debug_mode_(false),
    move_startable_(false),
    moe_enable_(false),
    topic_pid_left_name_(""),
    topic_pid_right_name_(""),
    freq_(0.0),
    wheel_radius_(0.0),
    centreline_dist_(0.0)
{
    //Node name
	node_name_ = ros::this_node::getName();
	ROS_INFO("Starting ROS Node %s", node_name_.c_str());

    /*
		Get all params for ros server
	
	//PID params
	if (
			nh_.hasParam("/robot/base/wheel/radius") ||
			nh_.hasParam("/robot/base/centreline") ||
			nh_.hasParam("/frequency")
	   )
	{
		nh_.param<float_t>("/robot/base/wheel/radius", wheel_radius_);
		nh_.param<float_t>("/robot/base/centreline", centreline_dist_);
		nh_.param<double_t>("/frequency", freq_);

		move_startable_ = true;
	}
	else
    {
		ROS_INFO("Please check if PID parameters are set in the ROS Parameter Server !\n");
	}
}

void Move_Base::onTwistMsgEvent(const geometry_msgs::Twist::ConstPtr& twist_msg)
{
	
}*/