cmake_minimum_required(VERSION 3.13)
project(curves C)

# SET(EQSOLVER "")
# add_compile_definitions(NEWTON) # uncomment to use Newton's method
# add_compile_definitions(BISSEC)   # uncomment to use bisect   method
# add_definitions(${EQSOLVER})
OPTION(USEBISEC
        "Set bisection as default equation solution method"
        OFF)
IF(USEBISEC)
    MESSAGE("Using bisection method")
    ADD_DEFINITIONS(-DBISSEC)
ELSE(USEBISEC)
    MESSAGE("Using Newton's method")
    ADD_DEFINITIONS(-DNEWTON)
ENDIF(USEBISEC)
set(CMAKE_C_STANDARD 99)

add_executable(curves main.c  functions.c  test_equation_solver.c  settings.h equation_solver.c common_interface.c common_interface.h integration.c integration.h colors.h)
target_link_libraries(curves m)