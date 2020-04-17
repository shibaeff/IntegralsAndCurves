#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "equation_solver.h"
#include "test_equation_solver.h"
#include "common_interface.h"
#include "integration.h"

int main ()
{

  // test_newton ();
  printf ("%f\n", root (f1,  0, f2, 0, 0.001, 10, EPS1));
  printf("%f", integration (f3, df3, 5, 10, pow (EPS2, 0.25) / 120));
  return 0;
}