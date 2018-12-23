cmake_minimum_required(VERSION 3.10)

project(CMakeSample_Solution)

include_directories(include)
include_directories(src)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
# For creating an executable
add_executable(CMakeSample_EXE ${SOURCES})


