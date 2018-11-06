#ifndef DEF_ULTRASONIC_SENSOR_H
#define DEF_ULTRASONIC_SENSOR_H

#include "dvb_hardware/hardware.h"

class Ultrasonic_Sensor : public Hardware
{
    public:
        Ultrasonic_Sensor(std::string topic_ultrasonic_sensor_name, bool debug_mode);
        
        void spinOnce() override;

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