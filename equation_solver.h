//
// Created by paavo on 4/16/20.
//
#include <math.h>
#ifndef _EQUATION_SOLVER_H_
#define _EQUATION_SOLVER_H_


static unsigned ITERATIONS = 0; /** @brief zero it before the euquation solver call. The number of iterations consumed to solve the equations will be there*/

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

/**
 * @brief Solves equation using Newton's method
 * @param f function
 * @param g function
 * @param a left bound
 * @param b right bound
 * @param eps1 error bound
 */
double bijection (double (*f) (double x), double (*g) (double x),
                  double a, double b, double eps1
);

#endif //_EQUATION_SOLVER_H_
