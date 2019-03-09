#include <ros/ros.h>
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    //Topic you want to publish
    pub_ = n_.advertise<std_msgs::Int32>("/motor/left", 1);
    pub2_ = n_.advertise<std_msgs::Int32>("/motor/right", 1);

    //Topic you want to subscribe
    sub_ = n_.subscribe("robot_deplacement", 1, &SubscribeAndPublish::callback, this);
  }

  void callback(const std_msgs::String& input)
  { 
   std::cout << input << std::endl;
  if(input.data == "forward"){
   ROS_INFO("forward");

    std_msgs::Int32 output;
   output.data = 300;
    pub_.publish(output);
    pub2_.publish(output);
   }
if(input.data == "stop"){
ROS_INFO("Stop");
    std_msgs::Int32 output;
   output.data = 0;
    pub_.publish(output);
    pub2_.publish(output);
   }
if(input.data == "right"){
    std_msgs::Int32 output;
   output.data = 600;
    pub_.publish(output);
   output.data = 200;
    pub2_.publish(output);
   }
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;
  ros::Publisher pub2_;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "subscribe_and_publish");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}

