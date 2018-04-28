cmake_minimum_required(VERSION 3.1)

project(color-util CXX)
set(CMAKE_CXX_STANDARD 11)

file(GLOB headers color-util/*.hpp)
install(FILES ${headers} DESTINATION include/color-util)

option(COLORUTIL_BUILD_TESTS "Build tests" OFF)

if(COLORUTIL_BUILD_TESTS)
	include_directories(${CMAKE_SOURCE_DIR})
	add_subdirectory(tests/CIEDE2000)

	enable_testing()
	add_test(NAME test-CIEDE2000 COMMAND $<TARGET_FILE:test-CIEDE2000> ${CMAKE_BINARY_DIR})
endif()