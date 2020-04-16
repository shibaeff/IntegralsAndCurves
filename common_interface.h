//
// Created by paavo on 4/16/20.
//

#ifndef _COMMON_INTERFACE_H_
#define _COMMON_INTERFACE_H_
#include "equation_solver.h"

/**
 * Solves equation with one of methods
 * @param f function
 * @param fd f's derivative. Set to null if it's not used
 * @param g function
 * @param gd g's derivative. Set to null if it's not used
 * @param a left bound
 * @param b right bound
 * @param eps1 error bound
 * @return
 */
double root (double(*f) (double x), double (*fd) (double x),
               double (*g) (double x), double (*gd) (double x),
               double a, double b, double eps1
);
#endif //_COMMON_INTERFACE_H_
