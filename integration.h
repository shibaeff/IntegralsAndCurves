//
// Created by paavo on 4/17/20.
//

#ifndef _INTEGRATION_H_
#define _INTEGRATION_H_
#include "equation_solver.h"
/**
 * @brief Calculates area under curve for function f on a segment [a, b]
 * @param f function
 * @param fd function's derivative, used to calculate the second order error
 * @param a left bound
 * @param b right bound
 * @param eps2 error bound
 * @return
 */
double rectangle (double(*f) (double x), double (*fd) (double x),
               double a, double b, double eps1
);

/**
 * Calculate chunk size to satisfy the error
 * @param f
 * @param fd
 * @param eps
 * @return
 */
int granularity(double (*f)(double x), double (*fd)(double), double a, double b, double eps);

#endif //_INTEGRATION_H_
