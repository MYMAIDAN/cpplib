cmake_minimum_required(VERSION 3.15)

ADD_EXECUTABLE(any_test any_test.cpp)
TARGET_LINK_LIBRARIES(any_test cpplib ${CONAN_LIBS})