#include <dvb_hardware/encoder.h>

int main(int argc, char **argv)
{
  //Start ROS node
  ros::init(argc, argv, "encoder_controller_node");
  ros::NodeHandle n;
  n.setParam("/frequency", 1);
  n.setParam("/encoder/left/pinA", 2);
  n.setParam("/encoder/left/pinB", 3);

  Encoder *encoder_left = new Encoder(std::string("/encoder/left"), false);
  encoder_left->setEnable(true);
  encoder_left->spin();

  return 0;
}

/*// Start ROS node.
  ROS_INFO("Starting node");
  ros::init(argc, argv, "hc_sr04s");
  ros::NodeHandle node;
  ros::Rate rate(10); // 10 hz

  // Build N sonars.
  wiringPiSetupSys();

  // uses gpio pin numbering
  vector<Sonar::Sonar> sonars;
  sonars.push_back(Sonar::Sonar(24, 25));
  sonars.push_back(Sonar::Sonar(22, 23));
  sonars.push_back(Sonar::Sonar(18, 27));

  // Build a publisher for each sonar.
  vector<ros::Publisher> sonar_pubs;
  for (int i = 0; i < sonars.size(); ++i)
  {
    stringstream ss;
    ss << "sonar_" << i;
    sonar_pubs.push_back(node.advertise<sensor_msgs::Range>(ss.str(), 10));
  }

  // Build base range message that will be used for
  // each time a msg is published.
  sensor_msgs::Range range;
  range.radiation_type = sensor_msgs::Range::ULTRASOUND;
  range.min_range = 0.0;
  range.max_range = Sonar::MAX_DISTANCE;

  float distance;
  bool error;
  while (ros::ok())
  {
    for (int i = 0; i < sonars.size(); ++i)
    {
      range.header.stamp = ros::Time::now();
      range.range = sonars[i].distance(&error);
      if (error)
        ROS_WARN("Error on sonar %d", i);
      else
        sonar_pubs[i].publish(range);
    }
    ros::spinOnce();
    rate.sleep();
  }
  return 0;*/