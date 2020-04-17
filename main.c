#include <stdio.h>
#include "asm_functions.h"
#include <unistd.h>
#include <getopt.h>
#include <math.h>
#include "functions.h"
#include "equation_solver.h"
#include "test_equation_solver.h"
#include "common_interface.h"
#include "integration.h"
#include "colors.h"


int
main (int argc, char** argv)
{

  const char* short_options = "ht::p::i::";

  const struct option long_options[] = {
      {"help",no_argument,NULL,'h'},
      {"test",optional_argument,NULL,'t'},
      {"points", optional_argument, NULL, 'p'},
      {"iterations", optional_argument, NULL, 'i'},
      {NULL,0,NULL,0}
  };

  int rez;
  int option_index;
  // SOLVING EQUATIONS
#ifdef NEWTON
  printf("Using Newton's method\n");
#endif

#ifdef BISSEC
  printf("Using bisection method\n");
#endif
  double left = 0.001, right = 10;
  double x1, x2; // intersection points of functions f1 and f3, f2 and f3
  unsigned iterations1, iterations2; // iterations for two cases
  ITERATIONS = 0; // ITERATION is a global variable
  x1 = root (f1, df1, f3, df3, left, right, EPS1);
  iterations1 = ITERATIONS;
  ITERATIONS = 0;
  x2 = root (f2, df2, f3, df3, left, right, EPS1);
  iterations2 = ITERATIONS;

  // CALCULATING AREAS
  double area1 = integration (f1, df1, left, x1, EPS2);
  double area2 = integration (f3, df3, x1, x2, EPS2);
  double area3 = integration (f2, df2, 0, 3, EPS2);
  double area4 = integration (f2, df2, 3, x2, EPS2);
  double ans = area1 + area2 - area3 - area4;

  // FINAL ANSWER
  printf(ANSI_COLOR_BLUE "Areas %f, %f, %f, %f\n", area1, area2, area3, area4);
  printf("The answer is %f\n", ans);

  // PRINT ADDITIONAL INFORMATION IF NEEDED
  while ((rez=getopt_long(argc,argv,short_options,
                          long_options,&option_index))!=-1){

      switch(rez){
          case 'h': {
              printf(ANSI_COLOR_GREEN "This program calculates areas between three curves:\n");
              printf("1) 0.6x + 3\n");
              printf("2) (x-2)^3-1\n");
              printf("3) 3/x\n");
              printf("Options: \n");
              printf("-h, -help for this help\n");
              printf("-t, -test for testing \n");
              printf("-p, -points to print points of intersection");
              printf("-i, -iterations to print number of iterations to find points of intersection\n" ANSI_COLOR_RESET);

              break;
            };
          case 's': {
              if (optarg!=NULL)
                printf("found size with value %s\n",optarg);
              else
                printf("found size without value\n");
              break;
            };

          case 'p': {
              printf(ANSI_COLOR_CYAN "Printing intersection points\n");
              printf("%f %f\n", x1, x2);
              printf(ANSI_COLOR_RESET);

              break;
            };
          case 'i': {
              printf(ANSI_COLOR_YELLOW "Printing number of iterations it took find respective intersections\n");
              printf("For f1 and f2 it took %d iterations\n", iterations1);
              printf("For f2 and f3 it took %d iterations\n", iterations2);
              printf(ANSI_COLOR_RESET);

              break;
            };
          case 't': {
              printf(ANSI_COLOR_RED "Testing equation solver\n");
#ifdef NEWTON
              test_newton ();
#endif
#ifdef BISSEC
              test_bisection ();
#endif
              printf(ANSI_COLOR_RESET);
              break;
            };
          case '?': default: {
              printf("found unknown option. type -h or --help for help\n");
              break;
            };
        };
    };
  printf("%f", df3(1));
  return 0;
}