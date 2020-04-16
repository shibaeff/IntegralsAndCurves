//
// Created by paavo on 4/16/20.
//

#include "equation_solver.h"


double newton (double(*f) (double x), double (*fd) (double x),
             double (*g) (double x), double (*gd) (double x),
             double a, double b, double eps1
)
{
  double h = (f(a) - g(a)) / (fd(a) - gd(a));
  double x = a;
  while (fabs(h) >= eps1)
    {
      h = (f(x) - g(x)) / (fd(x) - gd(x));
      x = x - h;
      ITERATIONS++;
    }
  return x;
}