cmake_minimum_required(VERSION 3.13)
project(curves C)
enable_language(ASM_NASM)

# SET(EQSOLVER "")
# add_compile_definitions(NEWTON) # uncomment to use Newton's method
# add_compile_definitions(BISSEC)   # uncomment to use bisect   method
# add_definitions(${EQSOLVER})


#add_custom_target(asm DEPENDS asm_functions.o)
#add_custom_command(OUTPUT asm_functions.o
#        COMMAND nasm -f elf32 -o asm_functions.o asm_functions.asm
#        DEPENDS asm_functions.h)
add_custom_target(
        myCustomTarget
        COMMAND echo Compiling NASM && nasm -f elf32 -o asm_functions.o asm_functions.asm
)
add_custom_target(run ALL
        DEPENDS myCustomTarget)

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

add_executable(curves main.c test_equation_solver.c  settings.h equation_solver.c test_integration.c test_integration.h
        common_interface.c common_interface.h integration.c integration.h colors.h asm_functions.o functions.c)
add_dependencies(curves myCustomTarget)
set_target_properties(curves PROPERTIES C_COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
target_link_libraries(curves m)
