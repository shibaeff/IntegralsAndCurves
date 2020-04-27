//
// Created by paavo on 4/17/20.
//

#include "integration.h"
int granularity (double (*f) (double x), double (*fd) (double), double a, double b, double eps)
{
  int n = 100;
  double length = b - a;
  double delta;
  while (1)
    {
    new:
    delta = (b - a) / n;
      for (double x = a; x <= b; x += delta)
        {
          if (fabs (f (x) * delta + fd (x) * delta * delta / 2) > eps)
            {
              n *= 2;
              goto new; // TODO continue
            }
        }
      return n;
    }
}

double rectangle (double(*f) (double x), double (*fd) (double x),
                  double a, double b, double eps1
)
{
  int n = 0;
  if (f && fd) {
    n = granularity (f, fd, a, b, eps1);
  }
  double delta = (b - a) / n;
  double sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += delta * f(a + (i - 1) * delta);
    I_ITERATIONS++;
  }
  return sum;
}