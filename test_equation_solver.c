//
// Created by paavo on 4/16/20.
//

#include "test_equation_solver.h"
#include "settings.h"
#include "functions.h"

extern double newton (double(*f) (double x), double (*fd) (double x),
                      double (*g) (double x), double (*gd) (double x),
                      double a, double b, double eps1
);

void test_newton()
{
  // f1 against f2, f2 against f3
  double expected[] = {3.84776, 3.2439, 0, 1, 0};
  double A = 0.01;
  double B = 10;
  double (*funcs[][4])(double x) = {{f1, df1, f2, df2}, {f2, df2, f3, df3}, {sin, cos, zero, zero},
                                    {log, reverse, zero, zero}, {exp_minus_1, exp, zero, zero}};
  for (int i = 0; i < 5; ++i) {
    ITERATIONS = 0;
    double got = newton (funcs[i][0], funcs[i][1], funcs[i][2], funcs[i][3], A, B, EPS1);
    if (fabs (got - expected[i]) >= EPS1) {
      printf("TEST FAILED!\n");
      printf(TEST_OUTPUT, i, ITERATIONS, expected[i], got);
    } else {
      printf(TEST_OUTPUT, i, ITERATIONS, expected[i], got);
    }

  }
}

/**
 * @brief Solves equation using bijection method. Return NAN if something goes wrong
 * @param f function
 * @param g function
 * @param a left bound
 * @param b right bound
 * @param eps1 error bound
 */
extern double bisection (double (*f) (double x), double (*g) (double x),
                  double a, double b, double eps
);
void test_bisection()
{
  double expected[] = {3.84776, 3.2439};
  double A = 0.001;
  double B = 10;
  double (*funcs[][2])(double x) = {{f1, f2}, {f2, f3}};
  for (int i = 0; i < 2; ++i) {
      ITERATIONS = 0;
      double got = bisection (funcs[i][0], funcs[i][1], A, B, EPS1);
      if (fabs (got - expected[i]) >= EPS1) {
          printf("TEST FAILED! ");
          printf(TEST_OUTPUT, i, ITERATIONS, expected[i], got);
        } else {
          printf(TEST_OUTPUT, i, ITERATIONS, expected[i], got);
        }
    }
}
