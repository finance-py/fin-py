@echo off
REM Create the build directory if it doesn't exist
if not exist "build" (
    mkdir build
)

REM Change to the build directory
cd build

REM Run CMake to configure the project
cmake .. -G "MinGW Makefiles"

REM Build the project
mingw32-make

REM Return to the original directory
cd ..

@echo off
echo Build process completed!
