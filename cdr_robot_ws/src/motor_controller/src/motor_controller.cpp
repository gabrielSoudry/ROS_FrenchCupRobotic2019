#include "dvb_hardware/motor.h"


int main(int argc, char** argv)
{
    //Start ROS node
    ros::init(argc, argv, "motor_controller_node");
    ros::NodeHandle n;
      
    Motor motor(ros::this_node::getName(), false);
   
    std::cout << "Lancement de la node :  " << ros::this_node::getName();

   ROS_INFO("yes");
    motor.setEnable(true);
    motor.spin();
}
