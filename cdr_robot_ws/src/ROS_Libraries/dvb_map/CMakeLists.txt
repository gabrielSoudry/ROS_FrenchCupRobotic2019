cmake_minimum_required(VERSION 2.8.3)
project(dvb_map)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  rospy
  std_msgs
)

find_package(dvb_robot REQUIRED)
find_package(dvb_hardware REQUIRED)

###################################
## catkin specific configuration ##
###################################

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES dvb_map
  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy std_msgs
  #DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
  ${dvb_robot_INCLUDE_DIRS}
  ${dvb_hardware_INCLUDE_DIRS}
)

add_library(dvb_map
    src/map.cpp
    src/table.cpp
    src/obstacle.cpp
)

target_link_libraries(dvb_map
   ${catkin_LIBRARIES}
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