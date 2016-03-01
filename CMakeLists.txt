cmake_minimum_required(VERSION 2.8)
project(tinyutf8)
set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

file(GLOB LIBSOURCES "src/*.c")
file(GLOB EXAMPLESOURCES "examples/*.c")

add_library(tinyutf8_static STATIC ${LIBSOURCES})
add_library(tinyutf8_shared SHARED ${LIBSOURCES})

add_executable(example examples/example.c)
target_link_libraries(example tinyutf8_static)
