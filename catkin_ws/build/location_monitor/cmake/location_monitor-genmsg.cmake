# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "location_monitor: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ilocation_monitor:/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(location_monitor_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg" NAME_WE)
add_custom_target(_location_monitor_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "location_monitor" "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(location_monitor
  "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/location_monitor
)

### Generating Services

### Generating Module File
_generate_module_cpp(location_monitor
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/location_monitor
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(location_monitor_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(location_monitor_generate_messages location_monitor_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg" NAME_WE)
add_dependencies(location_monitor_generate_messages_cpp _location_monitor_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(location_monitor_gencpp)
add_dependencies(location_monitor_gencpp location_monitor_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS location_monitor_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(location_monitor
  "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/location_monitor
)

### Generating Services

### Generating Module File
_generate_module_eus(location_monitor
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/location_monitor
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(location_monitor_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(location_monitor_generate_messages location_monitor_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg" NAME_WE)
add_dependencies(location_monitor_generate_messages_eus _location_monitor_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(location_monitor_geneus)
add_dependencies(location_monitor_geneus location_monitor_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS location_monitor_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(location_monitor
  "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/location_monitor
)

### Generating Services

### Generating Module File
_generate_module_lisp(location_monitor
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/location_monitor
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(location_monitor_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(location_monitor_generate_messages location_monitor_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg" NAME_WE)
add_dependencies(location_monitor_generate_messages_lisp _location_monitor_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(location_monitor_genlisp)
add_dependencies(location_monitor_genlisp location_monitor_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS location_monitor_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(location_monitor
  "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/location_monitor
)

### Generating Services

### Generating Module File
_generate_module_nodejs(location_monitor
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/location_monitor
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(location_monitor_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(location_monitor_generate_messages location_monitor_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg" NAME_WE)
add_dependencies(location_monitor_generate_messages_nodejs _location_monitor_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(location_monitor_gennodejs)
add_dependencies(location_monitor_gennodejs location_monitor_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS location_monitor_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(location_monitor
  "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/location_monitor
)

### Generating Services

### Generating Module File
_generate_module_py(location_monitor
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/location_monitor
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(location_monitor_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(location_monitor_generate_messages location_monitor_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/gab/catkin_tutorials/create_package_pubsub/catkin_ws/src/location_monitor/msg/LandMarkDistance.msg" NAME_WE)
add_dependencies(location_monitor_generate_messages_py _location_monitor_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(location_monitor_genpy)
add_dependencies(location_monitor_genpy location_monitor_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS location_monitor_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/location_monitor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/location_monitor
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(location_monitor_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/location_monitor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/location_monitor
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(location_monitor_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/location_monitor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/location_monitor
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(location_monitor_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/location_monitor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/location_monitor
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(location_monitor_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/location_monitor)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/location_monitor\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/location_monitor
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(location_monitor_generate_messages_py std_msgs_generate_messages_py)
endif()
