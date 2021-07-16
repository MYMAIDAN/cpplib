cmake_minimum_required(VERSION 3.10)

project(mtl_cpplib LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

include(conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

add_subdirectory(src)
add_subdirectory(test)

include_directories(src)
include_directories(include)
add_executable(call  main.cpp)
target_link_libraries(call cpplib)