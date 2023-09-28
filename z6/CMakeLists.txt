cmake_minimum_required(VERSION 3.24)
project(z6)

set(CMAKE_CXX_STANDARD 17)

add_executable(z6 main.cpp
        load.cpp
        load.h
        load_tests.cpp
        load_tests.h)

target_link_libraries(z6 curl)
