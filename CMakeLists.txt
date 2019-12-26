cmake_minimum_required (VERSION 3.3)

project(CONTROL_TOOLBOX VERSION 3.0.2 LANGUAGES CXX)


## find and include required dependencies
find_package(Eigen3 3.0.0 REQUIRED)
find_package(Boost COMPONENTS REQUIRED)
include_directories(-I/usr/include/eigen3)
include_directories(${EIGEN_INCLUDE_DIRS})
add_executable(hello hello.cpp)
target_link_libraries (hello ct_core)
list(APPEND core_ex_TARGETS hello)



