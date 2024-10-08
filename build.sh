#!/bin/bash

# Create the build directory if it doesn't exist
if [ ! -d "build" ]; then
    mkdir build
fi

build() {
    cmake -S . -B build
    cmake --build build
}

clean() {
    rm -rf build
}

all() {
    clean
    build
}

case "$1" in
    build)
        build
        ;;
    clean)
        clean
        ;;
    all)
        all
        ;;
    *)
        echo "Usage: $0 {build|clean|all}"
        exit 1
        ;;
esac
