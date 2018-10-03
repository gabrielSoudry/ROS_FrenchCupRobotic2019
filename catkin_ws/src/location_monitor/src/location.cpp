#include <vector>
#include <string>

#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "location_monitor/LandMarkDistance.h"

using std::string;
using std::vector;

class Landmark
{
  public:
    Landmark(string name, double x, double y)
        : name(name), x(x), y(y) {}
    string name;
    double x;
    double y;
};

class LandmarkMonitor
{
  public:
    LandmarkMonitor() : landmarks_()
    {
        InitLandmarks();
    }

 void OdomCallBack(const nav_msgs::Odometry::ConstPtr &msg)
{
    double x = msg -> pose.pose.position.x;
    double y = msg -> pose.pose.position.y;
    ROS_INFO("x: %f, y: %f", x,y);
}

private:
vector<Landmark> landmarks_;

void InitLandmarks() {
    landmarks_.push_back(Landmark("Cube",0.31,-0.99));
}
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "location");
    ros::NodeHandle nh;
    LandmarkMonitor monitor;
    ros::Subscriber sub = nh.subscribe("odom", 10,&LandmarkMonitor::OdomCallBack, &monitor);
    ros::spin();
    return 0;
}