cmake_minimum_required(VERSION 2.8.3)
project(dvb_navigation)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  rospy
  std_msgs
  tf
)

find_package(Boost REQUIRED COMPONENTS system)


