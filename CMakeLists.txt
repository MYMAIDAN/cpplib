cmake_minimum_required(VERSION 3.15)

project(mtl_cpplib CXX)

add_subdirectory(src)

add_executable(main  main.cpp)
target_link_libraries( main cpplib)