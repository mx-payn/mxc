cmake_minimum_required(VERSION 3.26)

project(
  mxc
  VERSION 0.0.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
                               ${CMAKE_CURRENT_SOURCE_DIR}/src/common.cpp)

target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/include/config.h)
