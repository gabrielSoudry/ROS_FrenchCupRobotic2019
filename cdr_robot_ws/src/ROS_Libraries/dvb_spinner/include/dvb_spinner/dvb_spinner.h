#ifndef DEF_DVB_SPINNER_H
#define DEF_DVB_SPINNER_H

#include "ros/ros.h"

class Dvb_Spinner
{
    public:
        Dvb_Spinner();

        virtual ~Dvb_Spinner();

        void spin(int times_freq); // spin frequency = times_freq * freq
        virtual void spinOnce();

        void setEnable(bool state);
        void setStartable(bool state);

        bool getEnable();
        bool getStartable();

        ros::NodeHandle getNodeHandler();

        float_t getSpinOnceTimer();

    protected:
        ros::NodeHandle nh_;

        //State
        bool debug_mode_;
        bool spinner_startable_;
        bool spinner_enable_;

        //Frequency
        float_t freq_;

        float_t spinOnce_timer_;
};

#endif