cmake_minimum_required(VERSION 3.10)

project(mtl_cpplib LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

include_directories(src)
include_directories(include)
add_executable(call  main.cpp)
target_link_libraries(call cpplib)