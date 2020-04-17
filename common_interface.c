//
// Created by paavo on 4/16/20.
//

#include "common_interface.h"
#include "equation_solver.h"


double root (double(*f) (double x), double (*fd) (double x),
             double (*g) (double x), double (*gd) (double x),
             double a, double b, double eps1
)
{
#ifdef NEWTON
  return newton(f, fd, g, gd, a, b, eps1);
#endif

#ifdef BISSEC
  return  bisection (f, g, a, b, eps1);
#endif
}


double integration (double(*f) (double x), double (*fd) (double x),
                    double a, double b, double eps1
)
{
  return rectangle (f, fd, a, b, eps1);
}