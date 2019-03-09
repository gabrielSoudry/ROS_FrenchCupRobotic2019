#include "NewPing.h" //ultrasonic sensor specific library
#include <ros.h>
#include <sensor_msgs/Range.h>

//define the pins
#define trigPin 5
#define echoPin 4

//define the constants
#define maxDistance 400
#define intervalR 200

NewPing sonar(trigPin, echoPin, maxDistance);

//variables
float range;
unsigned long range_timer;
float duration, distance;

ros::NodeHandle nh;

sensor_msgs::Range range_msg;

ros::Publisher pub_range_ultrasound("/ultrasound", &range_msg);


float returnDistance()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  return duration/58; //    duration/29/2, return centimeters
}
 
void setup() {
     //pin mode for the ultrasonic sensor
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

   nh.initNode();
   nh.advertise(pub_range_ultrasound);
}

void loop() {
  unsigned long currentMillis = millis();
 
  if (currentMillis-range_timer >= intervalR)
  {
    range_timer = currentMillis+intervalR;
   
    range_msg.range = returnDistance();
    pub_range_ultrasound.publish(&range_msg);
    }
   
   nh.spinOnce();
}
