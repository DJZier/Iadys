cmake_minimum_required(VERSION 3.5)
project(iadys)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)

endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rclcpp REQUIRED)
find_package(iadys REQUIRED)
find_package(OpenCV REQUIRED )
find_package(aruco REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories(${aruco_LIB_DIR})

set(msg_files
  "msg/Position.msg"
)


rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)

ament_export_dependencies(rosidl_default_runtime)

add_executable(position src/position.cpp)
target_link_libraries( position ${OpenCV_LIBS} ${aruco_LIBS})

ament_target_dependencies(position "rclcpp" )

install(TARGETS position DESTINATION lib/${PROJECT_NAME})


rosidl_target_interfaces(position
${PROJECT_NAME} "rosidl_typesupport_cpp")


 if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
