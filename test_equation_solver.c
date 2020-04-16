//
// Created by paavo on 4/16/20.
//

#include "test_equation_solver.h"
#include "settings.h"

void test_newton()
{
  // f1 against f2, f2 against f3
  double expected[] = {3.94584, 3.2439};
  double A = 0;
  double B = 10;
  double (*funcs[][4])(double x) = {{f1, df1, f2, df2}, {f2, df2, f3, df3}};
  for (int i = 0; i < 2; ++i) {
    ITERATIONS = 0;
    double got = newton (funcs[i][0], funcs[i][1], funcs[i][2], funcs[i][3], A, B, EPS1);
    if (fabs (got - expected[i]) >= EPS1) {
      printf("TEST FAILED!\n");
    } else {
      printf(TEST_OUTPUT, i, ITERATIONS, expected[i], got);
    }
    ITERATIONS = 0;

  }
}
