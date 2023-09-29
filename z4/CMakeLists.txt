cmake_minimum_required(VERSION 3.24)
project(z4)

set(CMAKE_CXX_STANDARD 17)

add_executable(z4 main.cpp
        html_table_generator.cpp
        html_table_generator.h
        gradient_generator.cpp
        gradient_generator.h
        rgb.h
        rgb.cpp
        icolor_generator.h
        tests.cpp
        tests.h)
