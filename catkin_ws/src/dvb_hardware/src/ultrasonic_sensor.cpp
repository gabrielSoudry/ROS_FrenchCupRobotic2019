#include "dvb_hardware/ultrasonic_sensor.h"

/*// Maximum distance reported. Values over this distance
const float Sonar::MAX_DISTANCE = 30;
const float Sonar::DIST_SCALE = 58.0;
const float Sonar::TRAVEL_TIME_MAX = MAX_DISTANCE * DIST_SCALE;
using namespace std;*/

Ultrasonic_Sensor::Ultrasonic_Sensor(std::string topic_ultrasonic_sensor_name, bool debug_mode) :
    Hardware(debug_mode),
    dist_(0)
{
    topic_ultrasonic_sensor_name_ = topic_ultrasonic_sensor_name;

    //Get ultrasonic sensor params
    char paramPinTrigg[50];
    char paramPinEcho[50];

    sprintf(paramPinTrigg, "%s/pin_trigg", topic_ultrasonic_sensor_name_.c_str());
    sprintf(paramPinEcho, "%s/pin_echo", topic_ultrasonic_sensor_name_.c_str());

    std::string pin_trigg = paramPinTrigg;
    std::string pin_echo = paramPinEcho;

    if (
			      nh_.hasParam(pin_trigg) ||
            nh_.hasParam(pin_echo) ||
            nh_.hasParam("/ultrasonic/distance_max") ||
            nh_.hasParam("/ultrasonic/distance_scale") ||
            nh_.hasParam("/ultrasonic/travel_time_max") //||
            //wiringPiSetup() < 0
    )
    {
        nh_.param<int32_t>(pin_trigg, pin_trigger_);
        nh_.param<int32_t>(pin_echo, pin_echo_);
        nh_.param<float_t>("/ultrasonic/distance_max", distance_max_);
        nh_.param<float_t>("/ultrasonic/distance_scale", distance_scale_);
        nh_.param<float_t>("/ultrasonic/travel_time_max", travel_time_max_);

        hardware_startable_ = true;
    }
    else
    {
		    ROS_INFO("Please check if motor PIN parameters are set in the ROS Parameter Server !\n");
	  }

    /*
        Publishers
	  */
    pub_ultrasonic_ = nh_.advertise<std_msgs::Int32>(topic_ultrasonic_sensor_name_, 10);
}

float_t Ultrasonic_Sensor::getDistance()
{
    /*
    digitalWrite(pin_trigger_, HIGH);
    delayMicroseconds(20);
    digitalWrite(pin_trigger_, LOW);

    int32_t bail = 1000;
    while (digitalRead(pin_echo_) == LOW)
    {
      if (--bail == 0)
      {
        error = true;
        return 0;
      }
    }

    int32_t startTime = micros();
    int32_t travelTime = 0;
  
    while (digitalRead(pin_echo_) == HIGH)
    {
      travelTime = micros() - startTime;
      if (travelTime > TRAVEL_TIME_MAX)
      {
        travelTime = TRAVEL_TIME_MAX;
        break;
      }

      delayMicroseconds(100);
    }

    // Return distance in cm
    error = false;
    return travelTime / 58.0;
    */

    std_msgs::Int32 ultrasonic_dist;
    ultrasonic_dist.data = dist_;

    pub_ultrasonic_.publish(ultrasonic_dist);

    return dist_;
}

void Ultrasonic_Sensor::spinOnce()
{
	  if(hardware_enable_ && hardware_startable_){
        getDistance();
        ROS_INFO_COND(debug_mode_, "%s : %d", topic_ultrasonic_sensor_name_.c_str(), dist_);
	  }
	  else{
		    ROS_INFO_COND(debug_mode_,"Ultrasonic sensor disabled");
	  }
}