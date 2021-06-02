cmake_minimum_required(VERSION 3.15)

project(mtl_cpplib LANGUAGES CXX)

#add_subdirectory(src)

add_executable(call  main.cpp "src/any.hpp")
target_link_libraries(call mltcpp)