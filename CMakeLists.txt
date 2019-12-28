cmake_minimum_required (VERSION 3.3)

project(CONTROL_TOOLBOX VERSION 3.0.2 LANGUAGES CXX)


## find and include required dependencies
find_package (Eigen3 3.3 REQUIRED )
find_package(Boost COMPONENTS REQUIRED)
find_package(PythonLibs 2.7 QUIET)
find_package(ct_core)
include_directories(${EIGEN_INCLUDE_DIR}${PYTHON_INCLUDE_DIRS})
add_executable(hello hello.cpp)
target_link_libraries (hello Eigen3::Eigen ${ct_core_LIBS} ct_plot)




