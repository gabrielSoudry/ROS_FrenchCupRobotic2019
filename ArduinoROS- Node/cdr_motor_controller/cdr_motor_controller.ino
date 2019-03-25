#include "DualVNH5019MotorShield.h"


#define TOPIC_MOTOR_LEFT_NAME "/robot/base/wheel/left/control_effort"
#define TOPIC_MOTOR_RIGHT_NAME "/robot/base/wheel/right/control_effort"

/**************************************/

#include <ros.h>
#include "std_msgs/Float64.h"

DualVNH5019MotorShield md;

ros::NodeHandle  nh;

void onMotorLeftEvent(const std_msgs::Float64& cmd_msg) {
  double control =  map(cmd_msg.data, -1000, 1000, -400, 400);
  md.setM2Speed(control);
}

void onMotorRightEvent(const std_msgs::Float64& cmd_msg) {
  double control = map(cmd_msg.data, -1000, 1000, -400, 400);
  md.setM1Speed(control);
}

ros::Subscriber<std_msgs::Float64> sub_motor_left(TOPIC_MOTOR_LEFT_NAME, onMotorLeftEvent );
ros::Subscriber<std_msgs::Float64> sub_motor_right(TOPIC_MOTOR_RIGHT_NAME, onMotorRightEvent );

void setup()
{
  md.init();
  nh.initNode();
  nh.subscribe(sub_motor_left);
  nh.subscribe(sub_motor_right);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}
