cmake_minimum_required(VERSION 2.8.3)
project(sonar_controller)

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
find_package(Boost REQUIRED COMPONENTS system)

##set(wiringPi_include "/usr/local/include")


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES sonar_controller
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
##  ${wiringPi_include}
)

##LINK_DIRECTORIES("/usr/local/lib")


##add_executable(sonar_controller src/sonar_controller.cpp)

##target_link_libraries(sonar_controller
   ##dvb_hardware
   ## wiringPi
  ## ${catkin_LIBRARIES}
##)