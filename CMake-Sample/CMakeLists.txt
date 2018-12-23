cmake_minimum_required(VERSION 3.10)

project(CMakeSample_Solution)

include_directories(include)
include_directories(src)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
# For creating an executable
# add_executable(CMakeSample_EXE ${SOURCES})

# -----------------------------------------------------------
# Shared Lib:
#Can manually add the sources using the set command as follows:
# set is used to assign variable with a value
set(LIB_SOURCES src/Student.cpp)

# Generate a shared library from the sources
# add_library(Student_SharedDLL SHARED ${LIB_SOURCES})

# -----------------------------------------------------------
# Static  Lib:
add_library(Student_StaticLib STATIC ${LIB_SOURCES})

# -----------------------------------------------------------
# Common for Shared DLL / Static Lib:

#Set the location for library installation
#install(TARGETS Student_SharedDLL RUNTIME DESTINATION lib)

link_directories(BUILD_)
#include_directories(BUILD_)
add_executable(CMakeSample_TestLibrary ./src/main.cpp)

# set(PROJECT_LINK_LIBS Student_SharedDLL.lib)
set(PROJECT_LINK_LIBS Student_StaticLib.lib)
target_link_libraries(CMakeSample_TestLibrary ${PROJECT_LINK_LIBS} )

# How to add inter-module dependency
add_dependencies(CMakeSample_TestLibrary Student_StaticLib)

# How to change the startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT CMakeSample_TestLibrary)
