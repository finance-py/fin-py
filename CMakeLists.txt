cmake_minimum_required(VERSION 3.10)

# Set the project name
project(fin-py)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost
find_package(Boost REQUIRED)

if(NOT Boost_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    boost
    URL https://boostorg.jfrog.io/artifactory/main/release/1.76.0/source/boost_1_76_0.tar.gz)
  FetchContent_MakeAvailable(boost)
endif()

set(SOURCES src/main.cpp src/generation.cpp src/parser.cpp src/tokenizer.cpp
            src/tokens.cpp)

include_directories(include)
# Create the executable from the source files
add_executable(fin-py ${SOURCES})

# Link the Boost libraries
target_link_libraries(fin-py Boost::boost)

set_target_properties(
  fin-py
  PROPERTIES CXX_STANDARD 20
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS OFF)
