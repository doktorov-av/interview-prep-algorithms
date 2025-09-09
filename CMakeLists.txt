cmake_minimum_required(VERSION 3.16)

project(interview-prep-algorithms VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(tsp ${CMAKE_SOURCE_DIR}/backtracking/tsp_problem/main.cpp)
add_executable(ip_resolve ${CMAKE_SOURCE_DIR}/backtracking/restore_ip/main.cpp)
