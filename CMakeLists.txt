cmake_minimum_required(VERSION 3.0)
project(segfault)

set(SRC segfault.cpp)

add_library(segfault_dll SHARED ${SRC})
target_compile_options(segfault_dll PRIVATE "-fvisibility=hidden")

add_executable(segfault_exe ${SRC})
target_compile_definitions(segfault_exe PRIVATE "-DBUILD_EXE=1")
