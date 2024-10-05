#!/bin/bash

# Create the build directory if it doesn't exist
if [ ! -d "build" ]; then
    mkdir build
fi

# Change to the build directory
cd build

# Run CMake to configure the project
cmake .. -G "MinGW Makefiles"

# Build the project
mingw32-make

# Return to the original directory
cd ..

echo "Build process completed!"
