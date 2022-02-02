cmake_minimum_required(VERSION 3.21)
project(Main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Main
        fileHandling.cpp
        fileHandling.h
        Main.cpp
        Queue.cpp
        Queue.h
        user.cpp
        user.h
        userLog.cpp
        userLog.h)
