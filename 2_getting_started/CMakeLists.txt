cmake_minimum_required(VERSION 3.19)
project(2_getting_started C)

set(CMAKE_C_STANDARD 99)

add_executable(2_getting_started sorts.c main.c sorts.h ../utils.c ../utils.h)
target_link_libraries(2_getting_started m)