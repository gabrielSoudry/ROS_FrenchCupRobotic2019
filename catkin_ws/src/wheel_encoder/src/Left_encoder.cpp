// %Tag(FULLTEXT)%
#include "ros/ros.h"
#include "std_msgs/Int32.h"

void chatterCallback(const std_msgs::Int32::ConstPtr &msg)
{
    ROS_INFO("Value of Tic Left Encoder : %d ", msg->data);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("Encodeur_Gauche", 1000, chatterCallback);
    ros::spin();

    return 0;
}
// %EndTag(FULLTEXT)%
