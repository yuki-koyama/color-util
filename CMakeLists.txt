cmake_minimum_required(VERSION 3.1)

project(color-util CXX)
set(CMAKE_CXX_STANDARD 11)

file(GLOB headers color-util/*.hpp)
install(FILES ${headers} DESTINATION include/color-util)
