//
// Created by paavo on 4/18/20.
//

/**
 * @file
 * @brief Tests for integration methods
 */


#include "test_integration.h"

void
test_integration()
{
  double expected[] = {2, M_E - 1, 0.5};
  double bounds[][2] = {{0, M_PI}, {0, 1}, {0, 1}};
  double (*funcs[][2]) (double x) = {{sin, cos}, {exp, exp}, {ident, one}};
  for (int i = 0; i < 3; ++i)
    {
      I_ITERATIONS = 0;
      double got = rectangle (funcs[i][0], funcs[i][1], bounds[i][0], bounds[i][1], EPS1);
      if (fabs (got - expected[i]) >= EPS1)
        {
          printf ("TEST FAILED! ");
          printf (I_TEST_OUTPUT, i, I_ITERATIONS, expected[i], got);
        }
      else
        {
          printf (I_TEST_OUTPUT, i, I_ITERATIONS, expected[i], got);
        }
    }

}
