//
// Created by paavo on 4/16/20.
//

#include "equation_solver.h"


double newton (double(*f) (double x), double (*fd) (double x),
             double (*g) (double x), double (*gd) (double x),
             double a, double b, double eps1
)
{
  double mid = (a + b) / 2;
  if ((f(mid) - g(mid)) > (f(a) - g(a) + f(b) - g(b)) / 2 && (f(a) - g(a) < 0) ||
      (f(mid) - g(mid)) < (f(a) - g(a) + f(b) - g(b)) / 2 && (f(a) - g(a)  > 0)
      ) {
      double h = (f(a) - g(a)) / (fd(a) - gd(a));
      double x = a;
      while (fabs(h) >= eps1)
        {
          x = x - h;
          h = (f(x) - g(x)) / (fd(x) - gd(x));

          ITERATIONS++;
        }
      return x;

  }
  double h = (f(b) - g(b)) / (fd(b) - gd(b));
  double x = b;
  while (fabs(h) >= eps1)
    {
      x = x - h;
      h = (f(x) - g(x)) / (fd(x) - gd(x));

      ITERATIONS++;
    }
  return x;
}

double EPS = 0.00001;
double bisection (double (*f) (double x), double (*g) (double x),
                  double a, double b, double eps1
)
{
  double x = a;
//  double val1 = f(a) - g(a);
//  double val2 = f(b) - g(b);
//  if (val1 * val2 > 0) {
//    return NAN;
//  }
  while (fabs(b - a) >= eps1) {
    x = (a + b) / 2;
    if (f(x) - g(x) == 0) {
      break;
    }
    if ((f(x) - g(x)) * (f(a) - g(a)) < 0) {
      b = x;
    } else {
      a = x;
    }
    ITERATIONS++;
    if (ITERATIONS >= 100000) {
      return NAN;
    }
  }
  return x;
}