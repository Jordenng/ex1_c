cmake_minimum_required(VERSION 3.8)
project(ex1_c)

set(CMAKE_C_FLAGS "-Wvla -Wextra -Wall -lm -std=c99")


set(SOURCE_FILES FindString.c)
add_executable(ex1_c ${SOURCE_FILES})