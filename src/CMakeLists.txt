cmake_minimum_required(VERSION 3.15)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    any.hpp
)

add_library(cpplib SHARED STATIC ${SOURCES})

target_include_directories(cpplib PRIVATE ../include)
target_include_directories(cpplib PRIVATE ../src)