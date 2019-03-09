cmake_minimum_required(VERSION 2.8.3)
project(robot_path_planning)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  rospy
  std_msgs
  sensor_msgs
)

find_package(dvb_map REQUIRED)
find_package(dvb_robot REQUIRED)
find_package(dvb_hardware REQUIRED)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES robot_path_planning
  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
  ${dvb_map_INCLUDE_DIRS}
  ${dvb_robot_INCLUDE_DIRS}
  ${dvb_hardware_INCLUDE_DIRS}
)

add_executable(a_star src/a_star.cpp)

target_link_libraries(a_star
   dvb_map
   dvb_robot
   dvb_hardware
   ${catkin_LIBRARIES}
)

add_executable(test2 src/test.cpp)

target_link_libraries(test2
   dvb_map
   dvb_robot
   dvb_hardware
   ${catkin_LIBRARIES}
)