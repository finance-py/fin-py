cmake_minimum_required(VERSION 3.10)

# Set the project name
project(fin-py)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES src/main.cpp src/generation.cpp src/parser.cpp src/tokenizer.cpp
            src/tokens.cpp)

include_directories(include)
# Create the executable from the source files
add_executable(fin-py ${SOURCES})
