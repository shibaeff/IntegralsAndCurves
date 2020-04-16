cmake_minimum_required(VERSION 3.14)
project(curves C)

set(CMAKE_C_STANDARD 99)

add_executable(curves main.c  functions.c equation_solver.c settings.h test_equation_solver.c)
