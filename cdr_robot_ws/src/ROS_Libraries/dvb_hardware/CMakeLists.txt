cmake_minimum_required(VERSION 2.8.3)
project(dvb_hardware)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  rospy
  std_msgs
  sensor_msgs
)

find_package(dvb_spinner REQUIRED)

find_package(Boost REQUIRED COMPONENTS system)

set(wiringPi_include "/usr/local/include")


###################################
## catkin specific configuration ##
###################################

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES dvb_hardware
  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy std_msgs
  #DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
  ${wiringPi_include}
  ${dvb_spinner_INCLUDE_DIRS}
)
LINK_DIRECTORIES("/usr/local/lib")


add_library(dvb_hardware
  src/hardware.cpp
  src/ultrasonic_sensor.cpp
)

target_link_libraries(dvb_hardware
  ${catkin_LIBRARIES} 
  wiringPi
  dvb_spinner
)

##target_link_libraries(sonar_controller
  ## ${catkin_LIBRARIES} wiringPi
 ##)

#############
## Install ##
#############

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE
)