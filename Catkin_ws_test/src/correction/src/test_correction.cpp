#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int16.h>
#include <std_msgs/Float64.h>

#include <sstream>

// Parameters
const int drive_distance = 10000;   // cm
const int motor_power = 60;      // 0-400 (negative value -400-0 for other direction)
const int motor_offset = 5;       // Diff. when driving straight
const int wheel_d = 60;           // Wheel diameter (mm)
const float wheel_c = 3.14 * wheel_d; // Wheel circumference (mm) 
const int counts_per_rev = 1024;  


// Globals
unsigned long enc_l = 0; // value of encoder left
unsigned long enc_r = 0; //value of encoder right


// Update value of encoder
void messageRight( const std_msgs::Int16& toggle_msg){
    enc_r = toggle_msg.data;
}

void messageLeft( const std_msgs::Int16& toggle_msg){
enc_l = toggle_msg.data;
}




int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/robot/base/wheel/right/state",1000, messageLeft);
  ros::Subscriber sub2 = n.subscribe("/robot/base/wheel/right/state",1000, messageRight);
  ros::Rate loop_rate(10);
  ros::Publisher pub = n.advertise<std_msgs::Float64>("/robot/base/wheel/right/control_effort", 1000);
  ros::Publisher pub2 = n.advertise<std_msgs::Float64>("/robot/base/wheel/left/control_effort", 1000);

  
  unsigned long num_ticks_l;
  unsigned long num_ticks_r;
  // Set initial motor power
  int power_l = motor_power;
  int power_r = motor_power;
  // Used to determine which way to turn to adjust
  unsigned long diff_l;
  unsigned long diff_r;
  // Reset encoder counts
  enc_l = 0;
  enc_r = 0;
  // Remember previous encoder counts
  unsigned long enc_l_prev = enc_l;
  unsigned long enc_r_prev = enc_r;
  // Calculate target number of ticks
 //float num_rev = (dist * 10) / wheel_c;  // Convert to mm
 // unsigned long target_count = num_rev * counts_per_rev;

  while (ros::ok() && ((enc_l < 7000) && (enc_r < 7000)))
  {
    num_ticks_l = enc_l;
   num_ticks_r = enc_r;
 
    // Sample number of encoder ticks
      if (power_r <0) {
      power_r = 0;
      }
      if (power_r > 400) {
        power_r = 150;
      }

      if (power_l <0) {
      power_l = 0;
      }
      if (power_l > 400) {
        power_l = 150;
      }
      
      std_msgs::Float64 msg;
      std_msgs::Float64 msg2;
      msg.data = float(power_r);
      msg2.data = float(power_l);
      pub.publish(msg);
      pub2.publish(msg2);

  // Number of ticks counted since last time
    diff_l = num_ticks_l - enc_l_prev;
    diff_r = num_ticks_r - enc_r_prev;

    // Store current tick counter for next time
    enc_l_prev = num_ticks_l;
    enc_r_prev = num_ticks_r;
    
    // If left is faster, slow it down and speed up right
    if ( diff_l > diff_r ) {
      power_l -= (diff_l-diff_r)*0.0914;
 
    }

    // If right is faster, slow it down and speed up left
    if ( diff_l < diff_r ) {
      power_l += (diff_r-diff_l)*0.08;
     
    }
    
    ROS_INFO("Gauche %d Droite %d, Encoder Gauche %d, Encoder Droite : %d", power_l,power_r,enc_l,enc_r);

    ros::spinOnce();
    loop_rate.sleep();

  }


  return 0;
}
