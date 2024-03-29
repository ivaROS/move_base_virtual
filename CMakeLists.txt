cmake_minimum_required(VERSION 2.8.3)
project(move_base_virtual)

find_package(catkin REQUIRED
    COMPONENTS
        actionlib
        base_local_planner
        clear_costmap_recovery
        cmake_modules
        costmap_2d
        dynamic_reconfigure
        geometry_msgs
        message_generation
        move_base_msgs
        nav_core
        nav_msgs
        navfn
        pluginlib
        roscpp
        rospy
        rotate_recovery
        std_srvs
        tf
)
find_package(Eigen3 REQUIRED)
add_definitions(${EIGEN3_DEFINITIONS})

# dynamic reconfigure
generate_dynamic_reconfigure_options(
    cfg/MoveBase.cfg
)

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES move_base_virtual
    CATKIN_DEPENDS
        dynamic_reconfigure
        geometry_msgs
        move_base_msgs
        nav_msgs
        roscpp
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIRS}
)

# move_base
add_library(move_base_virtual
  src/move_base_virtual.cpp
)
target_link_libraries(move_base_virtual
    ${Boost_LIBRARIES}
    ${catkin_LIBRARIES}
    )
add_dependencies(move_base_virtual ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(move_base_virtual_node
  src/move_base_virtual_node.cpp
)
add_dependencies(move_base_virtual_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(move_base_virtual_node move_base_virtual)
set_target_properties(move_base_virtual_node PROPERTIES OUTPUT_NAME move_base_virtual)

#install(
#    TARGETS
#        move_base
#        move_base_node
#    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)
#
### Mark cpp header files for installation
#install(DIRECTORY include/${PROJECT_NAME}/
#  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#  FILES_MATCHING PATTERN "*.h"
#)
