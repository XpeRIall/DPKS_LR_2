cmake_minimum_required(VERSION 3.15)
project(LR2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)

add_executable(LR2
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/LR2
        cmake-build-debug/LR2.cbp
        cmake-build-debug/Makefile
        CMakeLists.txt
        main.cpp)
