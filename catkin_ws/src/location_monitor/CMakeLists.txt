cmake_minimum_required(VERSION 2.8.3)
project(location_monitor)


## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  nav_msgs
  genmsg
)


## Declare ROS messages and services
add_message_files(FILES LandMarkDistance.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build ##
include_directories(include ${catkin_INCLUDE_DIRS})


add_executable(location_node src/location.cpp)
add_dependencies (location_node location_monitor_generate_messages_cpp)
target_link_libraries(location_node ${catkin_LIBRARIES})


## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )

