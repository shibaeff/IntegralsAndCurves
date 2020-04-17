cmake_minimum_required(VERSION 3.14)
project(curves C)

# add_compile_definitions(NEWTON) # uncomment to use Newton's method
add_compile_definitions(BISSEC)   # uncomment to use bisect   method
set(CMAKE_C_STANDARD 99)

add_executable(curves main.c  functions.c  test_equation_solver.c  settings.h equation_solver.c common_interface.c common_interface.h integration.c integration.h)
target_link_libraries(curves m)