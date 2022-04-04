cmake_minimum_required(VERSION 3.21)
project(Queue_Stack_38)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Queue_Stack_38
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Queue.cpp
        Queue.h
        ShortTest.cpp
        ShortTest.h Stack.cpp Stack.h)
