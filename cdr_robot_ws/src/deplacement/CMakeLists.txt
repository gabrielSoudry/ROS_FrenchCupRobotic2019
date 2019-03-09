cmake_minimum_required(VERSION 2.8.3)
project(deplacement)

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

set(wiringPi_include "/usr/local/include")

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES motor_controller
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
  ${dvb_hardware_INCLUDE_DIRS}
  ${wiringPi_include}
)

LINK_DIRECTORIES("/usr/local/lib")

add_executable(deplacement_robot src/deplacement.cpp)

target_link_libraries(deplacement_robot
   dvb_hardware
wiringPi
   ${catkin_LIBRARIES}
)
