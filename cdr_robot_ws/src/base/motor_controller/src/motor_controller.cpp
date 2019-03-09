#include "dvb_hardware/motor.h"

int main(int argc, char** argv)
{
    //Start ROS node
    ros::init(argc, argv, "motor_controller_node");

    Motor* motor = new Motor();

    motor->spin(1);

    return 0;
}