#include <stdio.h>
#include "functions.h"
#include "equation_solver.h"
#include "test_equation_solver.h"
#include "common_interface.h"

int main ()
{

  // test_newton ();
  printf ("%f", root (f1,  0, f2, 0, 0.001, 10, EPS1));
  return 0;
}