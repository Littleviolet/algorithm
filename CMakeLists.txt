cmake_minimum_required(VERSION 3.1)
project(Algorithm VERSION 0.0)

file(GLOB_RECURSE SRC_FILE src/*.cpp)
include_directories(inc)

add_subdirectory(test)