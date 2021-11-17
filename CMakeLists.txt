cmake_minimum_required(VERSION 3.20)
project(catalogue)

set(CMAKE_CXX_STANDARD 20)

include(setup_conan.cmake)
enable_testing()

add_subdirectory(src)
add_subdirectory(test)