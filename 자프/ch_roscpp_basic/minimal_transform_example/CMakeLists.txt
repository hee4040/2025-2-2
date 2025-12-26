cmake_minimum_required(VERSION 3.8)
project(minimal_transform_example)

# Default to C++17
if (NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
# find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

add_executable(minimal_moving_pose src/minimal_moving_pose.cpp)
ament_target_dependencies(minimal_moving_pose rclcpp geometry_msgs)
install(TARGETS minimal_moving_pose
        DESTINATION lib/${PROJECT_NAME})

add_executable(minimal_fixed_pose src/minimal_fixed_pose.cpp)
ament_target_dependencies(minimal_fixed_pose rclcpp geometry_msgs tf2 tf2_ros tf2_geometry_msgs)
install(TARGETS minimal_fixed_pose
        DESTINATION lib/${PROJECT_NAME})

add_executable(minimal_transform_broadcaster src/minimal_transform_broadcaster.cpp)
ament_target_dependencies(minimal_transform_broadcaster rclcpp geometry_msgs tf2 tf2_ros)
install(TARGETS minimal_transform_broadcaster
        DESTINATION lib/${PROJECT_NAME})

add_executable(minimal_transform_listener src/minimal_transform_listener.cpp)
ament_target_dependencies(minimal_transform_listener rclcpp geometry_msgs tf2 tf2_ros tf2_geometry_msgs)
install(TARGETS minimal_transform_listener
        DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
