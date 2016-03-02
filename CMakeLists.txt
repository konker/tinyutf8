cmake_minimum_required(VERSION 2.8)
project(tinyutf8)
set(CMAKE_BUILD_TYPE Debug)

option(SHARED_LIBRARY "Build a shared library" OFF)

include_directories(include)

file(GLOB LIBSOURCES "src/*.c")
file(GLOB EXAMPLESOURCES "examples/*.c")

if(SHARED_LIBRARY)
    add_library(tinyutf8 SHARED ${LIBSOURCES})
else()
    add_library(tinyutf8 STATIC ${LIBSOURCES})
endif()

add_executable(example examples/example.c)
target_link_libraries(example tinyutf8)
