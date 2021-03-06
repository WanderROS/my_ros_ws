cmake_minimum_required(VERSION 2.8.3)
project(mra_control)

#support C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++0x")

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
    moveit_ros_planning_interface 
    std_msgs
    roscpp
    mra_core_msgs
    controller_manager
    transmission_interface
    hardware_interface
    sensor_msgs
    joint_limits_interface
    trajectory_msgs
    moveit_msgs
    mra_basic#config.h
)

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS system)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
   INCLUDE_DIRS include
   LIBRARIES 
    mra_utilities
    arm_interface
   CATKIN_DEPENDS 
    moveit_ros_planning_interface 
    std_msgs
    roscpp
    mra_core_msgs
    controller_manager
    transmission_interface
    hardware_interface
    sensor_msgs
    joint_limits_interface
    trajectory_msgs
    moveit_msgs
    mra_basic#config.h
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(include ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

add_library(mra_utilities src/mra_utilities.cpp)
target_link_libraries(mra_utilities ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(mra_utilities ${catkin_EXPORTED_TARGETS}) # don't build until necessary msgs are finished

add_library(arm_interface src/arm_hardware_interface.cpp)
target_link_libraries(arm_interface ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(arm_interface ${catkin_EXPORTED_TARGETS}) # don't build until necessary msgs are finished

add_executable(mra_hardware_interface src/mra_hardware_interface.cpp)
target_link_libraries(mra_hardware_interface 
  mra_utilities 
  arm_interface 
  ${catkin_LIBRARIES} 
  ${Boost_LIBRARIES}
)
add_dependencies(mra_hardware_interface ${catkin_EXPORTED_TARGETS}) # don't build until necessary msgs are finish

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/groovy/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS mra_control mra_control_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_mra_control.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
