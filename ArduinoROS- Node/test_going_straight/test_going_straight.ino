#include <DualVNH5019MotorShield.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>


DualVNH5019MotorShield md; // Motor

// Parameters
const int drive_distance = 10000;   // cm
const int motor_power = 60;      // 0-400 (negative value -400-0 for other direction)
const int motor_offset = 5;       // Diff. when driving straight
const int wheel_d = 60;           // Wheel diameter (mm)
const float wheel_c = PI * wheel_d; // Wheel circumference (mm) 
const int counts_per_rev = 1024;  


// Globals
unsigned long enc_l = 0; // value of encoder left
unsigned long enc_r = 0; //value of encoder right



// Update value of encoder
void messageRight( const std_msgs::Int16& toggle_msg){
   nh.loginfo("msg received");
  enc_l = -toggle_msg.data;
}

void messageLeft( const std_msgs::Int16& toggle_msg){
enc_r = toggle_msg.data;
}



ros::NodeHandle  nh;
ros::Subscriber<std_msgs::Int16> sub("/robot/base/encoder/left/state", messageLeft);
ros::Subscriber<std_msgs::Int16> sub2("/robot/base/encoder/right/state", messageRight);


void setup() {
  md.init();
  nh.initNode();
  nh.subscribe(sub);
  nh.subscribe(sub2);
  driveStraight(drive_distance, motor_power); // Straight line (Maybe ... )


}



void loop() {

  
}



void driveStraight(float dist, int power) {
  
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
  float num_rev = (dist * 10) / wheel_c;  // Convert to mm
  unsigned long target_count = num_rev * counts_per_rev;


  // Drive until one of the encoders reaches desired count
  while ( (enc_l < 2000) && (enc_r < 2000) ) {
     nh.spinOnce();
    
    // Sample number of encoder ticks
    num_ticks_l = enc_l;
    num_ticks_r = enc_r;

    // Drive    
    drive(power_l, power_r);

    // Number of ticks counted since last time
    diff_l = num_ticks_l - enc_l_prev;
    diff_r = num_ticks_r - enc_r_prev;

    // Store current tick counter for next time
    enc_l_prev = num_ticks_l;
    enc_r_prev = num_ticks_r;

    // Debug
    char log_msg2 [50];
    sprintf(log_msg2, "diff_l %d \n", (int)diff_l);
    //
    
    // If left is faster, slow it down and speed up right
    if ( diff_l > diff_r ) {
      power_l -= motor_offset;
      power_r += motor_offset;
    }

    // If right is faster, slow it down and speed up left
    if ( diff_l < diff_r ) {
      power_l += motor_offset;
      power_r -= motor_offset;
    }


  // Debug :  (Verifier les valeurs des Encodeur)
  char log_msg [150];
  float temp = (float) power_l;
  float temp2 = (float) power_r;
  float temp3 = (float) enc_l;
  float temp4 = (float) enc_r;
  
  sprintf(log_msg, "Cmd is = %d, CmG is = %d, num_ticks_l :%d, num_ticks_d : %d ", (int)temp,(int)temp2,(int)temp3,(int)temp4 );
  nh.loginfo(log_msg);  

  delay(10);
  }
   
  // Brake
  brake();
  nh.spinOnce();

}

void drive(int power_a, int power_b) {

  // Constrain power to between -400 and 400
  power_a = constrain(power_a, -400, 400);
  power_b = constrain(power_b, -400, 400);


  // Set speed
  md.setM1Speed(power_a);
  md.setM2Speed(power_b);
 
}

void brake() {
  md.setM1Speed(0);
  md.setM2Speed(0);
}
