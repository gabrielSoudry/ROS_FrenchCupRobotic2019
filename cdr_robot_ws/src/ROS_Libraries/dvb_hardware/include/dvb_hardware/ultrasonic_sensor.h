#ifndef DEF_ULTRASONIC_SENSOR_H
#define DEF_ULTRASONIC_SENSOR_H

#include "dvb_spinner/dvb_spinner.h"

#include "std_msgs/Int32.h"

class Ultrasonic_Sensor : public Dvb_Spinner
{
    public:
        Ultrasonic_Sensor(std::string topic_ultrasonic_sensor_name, bool debug_mode);
        
        virtual void spinOnce();

        float_t getDistance();

    private:
        //Topics name
        std::string topic_ultrasonic_sensor_name_;

        //PIN Number
        int32_t pin_trigger_;
        int32_t pin_echo_;

        //Ultrasonic sensor parameters
        float_t distance_max_;
        float_t distance_scale_;
        float_t travel_time_max_;

        //Ultrasonic distance
        int32_t dist_;

        //Error statement
        bool error_;

        /*
            Publishers
        */
        ros::Publisher pub_ultrasonic_;
};

#endif