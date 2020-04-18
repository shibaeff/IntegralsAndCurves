//
// Created by paavo on 4/18/20.
//

#ifndef _TEST_INTEGRATION_H_
#define _TEST_INTEGRATION_H_
#include "functions.h"
#include <stdio.h>
#include <math.h>
#include "settings.h"
#include "integration.h"
extern double zero(double);
extern unsigned  I_ITERATIONS;
static const char *I_TEST_OUTPUT = "Running test #%d. Took %d iterations. Expected %f, got %f\n";
/**
 * @brief tests approximate integration method
 */
void
test_integration();
#endif //_TEST_INTEGRATION_H_
