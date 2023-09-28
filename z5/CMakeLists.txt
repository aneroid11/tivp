cmake_minimum_required(VERSION 3.24)
project(z5)

set(CMAKE_CXX_STANDARD 17)

add_executable(z5 main.cpp
        find_files.cpp
        find_files.h
        test_find_files.cpp
        test_find_files.h)
