cmake_minimum_required(VERSION 3.16)

project(interview-prep-algorithms VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(tsp ${CMAKE_SOURCE_DIR}/backtracking/tsp_problem/main.cpp)
add_executable(ip_resolve ${CMAKE_SOURCE_DIR}/backtracking/restore_ip/main.cpp)
add_executable(letter_combinations backtracking/letter_combintaions/main.cpp)
add_executable(desert_cost backtracking/closest_dessert_cost/main.cpp
        backtracking/combination_sum/main.cpp)
add_executable(combination_sum_39 backtracking/combination_sum/main.cpp)
