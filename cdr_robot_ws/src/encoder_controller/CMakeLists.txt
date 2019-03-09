cmake_minimum_required(VERSION 2.8.3)
project(encoder_controller)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  rospy
  std_msgs
  sensor_msgs
)

find_package(dvb_hardware REQUIRED)

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES encoder_controller
#  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy std_msgs sensor_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
  ${dvb_hardware_INCLUDE_DIRS}
)

add_executable(encoder_controller src/encoder_controller.cpp)

target_link_libraries(encoder_controller
   dvb_hardware
   ${catkin_LIBRARIES}
)
