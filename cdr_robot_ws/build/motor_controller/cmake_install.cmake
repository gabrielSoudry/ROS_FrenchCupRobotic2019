# Install script for directory: /home/gab/Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/cdr_robot_ws/src/motor_controller

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/gab/Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/cdr_robot_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/motor_controller/cmake" TYPE FILE FILES "/home/gab/Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/cdr_robot_ws/build/motor_controller/catkin_generated/installspace/motor_controller-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/gab/Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/cdr_robot_ws/devel/share/roseus/ros/motor_controller")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/gab/Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/cdr_robot_ws/devel/lib/python2.7/dist-packages/motor_controller")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/gab/Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/cdr_robot_ws/devel/lib/python2.7/dist-packages/motor_controller")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/gab/Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/cdr_robot_ws/build/motor_controller/catkin_generated/installspace/motor_controller.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/motor_controller/cmake" TYPE FILE FILES "/home/gab/Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/cdr_robot_ws/build/motor_controller/catkin_generated/installspace/motor_controller-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/motor_controller/cmake" TYPE FILE FILES
    "/home/gab/Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/cdr_robot_ws/build/motor_controller/catkin_generated/installspace/motor_controllerConfig.cmake"
    "/home/gab/Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/cdr_robot_ws/build/motor_controller/catkin_generated/installspace/motor_controllerConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/motor_controller" TYPE FILE FILES "/home/gab/Documents/DaVinciBot-CDR_ATOM_FACTORY_2019/cdr_robot_ws/src/motor_controller/package.xml")
endif()

