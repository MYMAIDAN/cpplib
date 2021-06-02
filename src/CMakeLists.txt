cmake_minimum_required(VERSION 3.15)
project(cpplib C CXX)

set(SOURCE_FILES
    any.hpp
)

add_library(cpplib SHARED STATIC ${SOURCE_FILES})