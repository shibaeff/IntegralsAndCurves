//
// Created by paavo on 4/16/20.
//
/**
 * @file
 * @brief contains implementations of Newton's method and bisection method
 */

#include <math.h>
#ifndef _EQUATION_SOLVER_H_
#define _EQUATION_SOLVER_H_


unsigned ITERATIONS; /** @brief zero it before the euquation solver call. The number of iterations consumed to solve the equations will be there*/

# ifdef NEWTON

/**
 * @brief Solves equation using Newton's method
 * @param f function
 * @param fd f's derivative
 * @param g function
 * @param gd g's derivative
 * @param a left bound
 * @param b right bound
 * @param eps1 error bound
 */
double newton (double(*f) (double x), double (*fd) (double x),
               double (*g) (double x), double (*gd) (double x),
               double a, double b, double eps1
);
# endif

#ifdef BISSEC
/**
 * @brief Solves equation using bijection method. Return NAN if something goes wrong
 * @param f function
 * @param g function
 * @param a left bound
 * @param b right bound
 * @param eps1 error bound
 */
double bisection (double (*f) (double x), double (*g) (double x),
                  double a, double b, double eps
);
#endif

#endif //_EQUATION_SOLVER_H_
