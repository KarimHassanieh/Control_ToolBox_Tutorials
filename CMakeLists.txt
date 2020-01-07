cmake_minimum_required (VERSION 3.3)

project(CONTROL_TOOLBOX VERSION 3.0.2 LANGUAGES CXX)


## find and include required dependencies
find_package (Eigen3 3.3 REQUIRED )
find_package(Boost COMPONENTS REQUIRED)
find_package(PythonLibs 2.7 QUIET)
find_package(ct_core)
add_executable(hello hello.cpp)
add_executable(pendulum simple_pendulum.cpp)
set(LIBS Eigen3::Eigen ct_plot ${EIGEN_INCLUDE_DIR} ${ct_core_LIBS})
target_link_libraries (pendulum ${LIBS} )
target_link_libraries (hello ${LIBS} )
