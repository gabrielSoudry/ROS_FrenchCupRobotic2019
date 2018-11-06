#include "dvb_hardware/encoder.h"

Encoder::Encoder(std::string topic_encoder_name, bool debug_mode) :
    Hardware(debug_mode),
    pos_(0)
{
    //Topic name for motor and encoder
	topic_encoder_name_ = topic_encoder_name;

    //Get Encoder PIN params
    char paramPinA[50];
    char paramPinB[50];

    sprintf(paramPinA, "%s/pinA", topic_encoder_name.c_str());
    sprintf(paramPinB, "%s/pinB", topic_encoder_name.c_str());

    std::string pin_a = paramPinA;
    std::string pin_b = paramPinB;

    if (
			nh_.hasParam(paramPinA) ||
            nh_.hasParam(paramPinB) //||
            //wiringPiSetup() < 0
    )
    {
        nh_.param<int32_t>(pin_a, pinA_);
        nh_.param<int32_t>(pin_b, pinB_);

        hardware_startable_ = true;
    }
    else{
		ROS_WARN("Please check if encoder PIN parameters are set in the ROS Parameter Server !\n");
	}

    /*
		Publishers
	*/
	pub_encoder_ = nh_.advertise<std_msgs::Int32>(topic_encoder_name_.c_str(), 10);

    //WIRING PI Setup
    /*
    wiringPiISR(encoder->pinA, INT_EDGE_RISING, &increment)
    pinMode(encoder->pinB, _IOS_IMPUT);
    */
}

Encoder::~Encoder(){
    
}

int32_t Encoder::getPos()
{
    return pos_;
}

void Encoder::increment()
{
    /*
    int32_t signalA = digitalRead(pinA_);
    int32_t signalB = digitalRead(pinB_);

    if (signalB == HIGH)
    {
        --pos_;
    }

    else
    {
        ++pos_;
    }
    */

   std_msgs::Int32 encoder_pos;
   encoder_pos.data = pos_;

   pub_encoder_.publish(encoder_pos);

   ROS_INFO_COND(debug_mode_, "%s : %d", topic_encoder_name_.c_str(), pos_);
}

void Encoder::spinOnce(){
    if(hardware_enable_ && hardware_startable_){
        increment();
	}
	else{
        ROS_INFO_COND(debug_mode_,"Encoder disabled");
	}
}