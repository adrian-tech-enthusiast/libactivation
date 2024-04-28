#include <stdio.h>
#include <stdlib.h>
#include "../include/activation.h"

/**
 * Unit testing for the isigmoid(x) function.
 *
 * @param double x
 *   The double value.
 * @param double expected
 *   The expected double value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_sigmoid(double x, double expected)
{
   double result = isigmoid(x);
   printf("isigmoid(%.1f):\n", x);
   printf("  Expected: %.8f \n", expected);
   printf("  Got:      %.8f \n", result);
   // Use a small tolerance for floating-point comparison.
   printf("  Result:   ");
   if (fabs(result - expected) < 0.000000000000000001)
   {
      printf("Test Passed\n\n");
      return EXIT_SUCCESS;
   }
   else
   {
      printf("Test Failed\n\n");
      return EXIT_FAILURE;
   }
}

/**
 * {@inheritdoc}
 */
int run_sigmoid_unit_tests()
{
   printf("Testing the Sigmoid functions:\n");
   printf("------------------------------\n");
   // Sigmoid(0) should be 0.5.
   if (unit_test_sigmoid(0.0, 0.5) == EXIT_FAILURE)
   {
      return EXIT_FAILURE;
   }
   // Sigmoid(1) approx 0.7311.
   if (unit_test_sigmoid(1.0, 0.731058578630074) == EXIT_FAILURE)
   {
      return EXIT_FAILURE;
   }
   // Sigmoid(-1) approx 0.2689.
   if (unit_test_sigmoid(-1.0, 0.2689414213699260) == EXIT_FAILURE)
   {
      return EXIT_FAILURE;
   }
   // Sigmoid(10) should be close to 1.
   if (unit_test_sigmoid(10.0, 0.9999546021312978) == EXIT_FAILURE)
   {
      return EXIT_FAILURE;
   }
   // Sigmoid(-10) should be close to 0.
   if (unit_test_sigmoid(-10.0, 0.0000453978687022) == EXIT_FAILURE)
   {
      return EXIT_FAILURE;
   }
   // Tests Passed!.
   return EXIT_SUCCESS;
}
