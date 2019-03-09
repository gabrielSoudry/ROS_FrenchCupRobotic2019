#include <dvb_hardware/ultrasonic_sensor.h>

int main(int argc, char **argv)
{
    //Start ROS node
    ros::init(argc, argv, "sonar_controller_node");
    ros::NodeHandle n;
   
    n.setParam("/frequency", 1);
    n.setParam("/ultrasonic_sensor/pin_trigg", 2);
    n.setParam("/ultrasonic_sensor/pin_echo", 3);
    n.setParam("/ultrasonic/distance_max",30);
    n.setParam("/ultrasonic/distance_scale",58);
    n.setParam("/ultrasonic/travel_time_max",30*58);

    Ultrasonic_Sensor *ultrasonic_Sensor = new Ultrasonic_Sensor(std::string("/ultrasonic_sensor/"), false);
    ultrasonic_Sensor->setEnable(true);
    ultrasonic_Sensor->spin();

    return 0;
}