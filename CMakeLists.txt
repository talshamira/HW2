cmake_minimum_required(VERSION 3.22)
project(ex2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex2
        utilities.cpp
        utilities.h
        Card.h
        Card.cpp
        Mtmchkin.h
        Mtmchkin.cpp
        Player.cpp
        Player.h
        test.cpp
        )
