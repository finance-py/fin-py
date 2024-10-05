cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all source files in the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the executable from the source files
add_executable(MyProject ${SOURCES})

# Include the src directory for header files
target_include_directories(MyProject PRIVATE src)
