#ifndef DEF_PID
#define DEF_PID

#include "ros/ros.h"
#include "ros/time.h"
#include "ros/console.h"

#include "dvb_spinner/dvb_spinner.h"

class Pid : public Dvb_Spinner
{
    public:
        Pid();

        ~Pid();

        void calcul_pid(float_t prev_val);

     private:
	 	ros::NodeHandle nh_;
		
        int target_;
        int output_;

         //PID
        float_t kp_;
        float_t ki_;
        float_t kd_;

        float_t integral_;
        float_t error_;
        float_t derivative_;
        float_t previous_error_;

         //Time
        ros::Time prev_time_;
        ros::Duration dt_;
};
 #endif 