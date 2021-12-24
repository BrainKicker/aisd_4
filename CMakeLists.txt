cmake_minimum_required(VERSION 3.20)
project(aisd_4)

set(CMAKE_CXX_STANDARD 20)

add_executable(aisd_4 source/main.cpp source/find_match.h)

add_executable(runTests source/find_match.h tests/tests_main.cpp tests/tests_find_match.cpp)