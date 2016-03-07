cmake_minimum_required(VERSION 2.8)
project(tinyutf8)
set(CMAKE_BUILD_TYPE Debug)

option(SHARED_LIBRARY "Build a shared library" OFF)

include_directories(include)

file(GLOB LIBSOURCES "src/*.c")
file(GLOB EXAMPLESOURCES "examples/*.c")

add_library(tinyutf8 ${LIBSOURCES})

add_executable(tinyutf8_example examples/tinyutf8_example.c)
target_link_libraries(tinyutf8_example tinyutf8)
