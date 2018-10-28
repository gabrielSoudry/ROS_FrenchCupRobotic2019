cmake_minimum_required(VERSION 2.8.3)
project(wheel_encoder)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services
##add_message_files(FILES Num.msg)
##add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(Left_encoder src/Left_encoder.cpp)
 target_link_libraries(Left_encoder ${catkin_LIBRARIES})
 add_dependencies(Left_encoder wheel_encoder_generate_messages_cpp)

##add_executable(listener src/listener.cpp)
##target_link_libraries(listener ${catkin_LIBRARIES})
##add_dependencies(listener beginner_tutorials_generate_messages_cpp)

# %EndTag(FULLTEXT)%
