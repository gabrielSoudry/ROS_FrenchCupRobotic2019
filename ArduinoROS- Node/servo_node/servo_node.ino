#include <Servo.h>



/************* SETUP ******************/


#define TOPIC_ENCODER_NAME "/robot/servo"


/**************************************/

#include <ros.h>
#include <std_msgs/Int16.h>

ros::NodeHandle nh;
Servo myservo;  // create servo object to control a servo



void encoder_reset(const std_msgs::Int16& toggle_msg) {
  myservo.write(toggle_msg.data);
}

ros::Subscriber <std_msgs::Int16>  sub_encoder(TOPIC_ENCODER_NAME, &encoder_reset);


void setup()
{
  myservo.attach(9);// attaches the servo on pin 9 to the servo object
  myservo.write(0);
   nh.initNode();
   nh.subscribe(sub_encoder);
}
 
void loop(){
  nh.spinOnce();  
  delay(100);
}
