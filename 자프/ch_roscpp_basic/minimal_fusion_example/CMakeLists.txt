cmake_minimum_required(VERSION 3.8)
project(minimal_fusion_example)

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
find_package(rclcpp_components REQUIRED)

# add_executable(minimal_publisher_node src/minimal_publisher_node.cpp)
# add_executable(minimal_fusion_node src/minimal_fusion_node.cpp)
# ament_target_dependencies(minimal_publisher_node rclcpp std_msgs)
# ament_target_dependencies(minimal_fusion_node rclcpp std_msgs)
# ament_target_dependencies(minimal_publisher_node rclcpp geometry_msgs)
# ament_target_dependencies(minimal_fusion_node rclcpp geometry_msgs)

# install(TARGETS minimal_publisher_node minimal_fusion_node
#   DESTINATION lib/${PROJECT_NAME})

add_library(minimal_publisher_node_component SHARED src/minimal_publisher_node.cpp)
add_library(minimal_fusion_node_component SHARED src/minimal_fusion_node.cpp)
ament_target_dependencies(minimal_publisher_node_component rclcpp_components geometry_msgs)
ament_target_dependencies(minimal_fusion_node_component rclcpp_components geometry_msgs)

rclcpp_components_register_node(
  minimal_publisher_node_component
  PLUGIN "MinimalPublisher"
  EXECUTABLE minimal_publisher_node
)

rclcpp_components_register_node(
  minimal_fusion_node_component
  PLUGIN "MinimalFusion"
  EXECUTABLE minimal_fusion_node
)

ament_export_targets(export_minimal_publisher_node_component 
  export_minimal_fusion_node_component)

install(TARGETS minimal_publisher_node_component
        EXPORT export_minimal_publisher_node_component
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

install(TARGETS minimal_fusion_node_component
        EXPORT export_minimal_fusion_node_component
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
