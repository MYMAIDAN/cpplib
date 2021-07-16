cmake_minimum_required(VERSION 3.10)

project(cpplib)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(../include)

set(SOURCES_FILES any.cpp ../include/bad_cast.h optional.h)

add_library(cpplib STATIC ${SOURCES_FILES})
