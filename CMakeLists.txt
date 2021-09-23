cmake_minimum_required(VERSION 3.5)
project(message_logger)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

set(INCLUDE_DIRS include ${ament_cmake_INCLUDE_DIRS})
include_directories(${INCLUDE_DIRS})

message(STATUS "INCLUDE_DIRS - ${INCLUDE_DIRS}")

set(LIBRARY_DIRS ${ament_cmake_LIBRARY_DIRS})
link_directories(${LIBRARY_DIRS})

message(STATUS "LIBRARY_DIRS - ${LIBRARY_DIRS}")

set(LIBS ${ament_cmake_LIBRARIES})

message(STATUS "LIBS - ${LIBS}")

# Find Catkin

include(CMakeDependentOption)
cmake_dependent_option(MELO_USE_COUT "Use std::cout" OFF
                                     "DEFINED ENV{ROS_DISTRO}" ON)

# Configure header file before catkin_package
configure_file(include/message_logger/log/log_messages_backend_config.hpp.in
  include/${PROJECT_NAME}/log/log_messages_backend_config.hpp
  @ONLY)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

if(NOT MELO_USE_COUT)
  message(STATUS "Building message_logger using ros.")
else()
  message(STATUS "Building message_logger using std::cout.")
endif()

if(DEFINED MELO_FUNCTION_PRINTS)
  add_definitions(-DMELO_FUNCTION_PRINTS)
endif()

add_definitions(-std=c++14 -fPIC -Wall)

add_library(${PROJECT_NAME} SHARED src/time/Time.cpp src/time/TimeStd.cpp)
ament_target_dependencies(${PROJECT_NAME} rclcpp)
target_link_libraries(${PROJECT_NAME} ${LIBS})

install(DIRECTORY include/${PROJECT_NAME}/
  ${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME}/
  DESTINATION include/${PROJECT_NAME}
  PATTERN "*.in"
  EXCLUDE)
install(TARGETS ${PROJECT_NAME}
  ARCHIVE
  DESTINATION lib
  LIBRARY
  DESTINATION lib
  RUNTIME
  DESTINATION lib/${PROJECT_NAME})

ament_export_dependencies(ament_cmake)
ament_export_include_directories(${INCLUDE_DIRS})
ament_export_libraries(${PROJECT_NAME} ${LIBS})

ament_package()
