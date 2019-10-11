cmake_minimum_required(VERSION 2.8.3)
project(dvb_control)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  geometry_msgs
  genmsg
  roscpp
  rospy
  sensor_msgs
  nav_msgs
  std_msgs
)

find_package(dvb_spinner REQUIRED)

###################################
## catkin specific configuration ##
###################################

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES dvb_hardware
  CATKIN_DEPENDS actionlib
  actionlib_msgs
  geometry_msgs
  genmsg
  roscpp
  rospy
  sensor_msgs
  nav_msgs
  std_msgs
  #DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
  ${dvb_spinner_INCLUDE_DIRS}
)


add_library(dvb_control
  src/pid.cpp
  src/move_base.cpp
)

target_link_libraries(dvb_control
  ${catkin_LIBRARIES} 
  dvb_spinner
)

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