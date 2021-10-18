cmake_minimum_required(VERSION 3.19)
project(4_divide_and_conquer C)

set(CMAKE_C_STANDARD 99)

add_executable(4_divide_and_conquer main.c maximum_subarray.c maximum_subarray.h ../utils.c ../utils.h matrix_multiplication.c matrix_multiplication.h)
target_link_libraries(4_divide_and_conquer m)