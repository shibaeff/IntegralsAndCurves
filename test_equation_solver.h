//
// Created by paavo on 4/16/20.
//

#ifndef _TEST_EQUATION_SOLVER_H_H_
#define _TEST_EQUATION_SOLVER_H_H_
#include <stdio.h>
#include "equation_solver.h"
#include "settings.h"
#include "functions.h"
#include "asm_functions.h"

static const char *TEST_OUTPUT = "Running test #%d. Took %d iterations. Expected %f, got %f\n";

#ifdef NEWTON
/**
 * @brief tests Newton's equation solution method on 3 functions
 */
void test_newton();
#endif

#ifdef BISSEC
/**
 * @brief test bisection method
 */
void test_bisection();
#endif

#endif //_TEST_EQUATION_SOLVER_H_H_
