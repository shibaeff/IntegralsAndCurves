//
// Created by paavo on 4/16/20.
//

#ifndef _TEST_EQUATION_SOLVER_H_H_
#define _TEST_EQUATION_SOLVER_H_H_
#include <stdio.h>
#include "equation_solver.h"
#include "settings.h"
#include "functions.h"

/**
 * @brief tests Newton's equation solution method on 3 functions
 */
void test_newton();

static const char *TEST_OUTPUT = "Running test #%d. Took %d iterations. Expected %f, got %f\n";
#endif //_TEST_EQUATION_SOLVER_H_H_
