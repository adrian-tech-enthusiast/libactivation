#include <stdio.h>
#include <stdlib.h>
#include "../include/activation.h"

// Function to test isigmoid function.
static int unit_test_sigmoid(double x, double expected)
{
   double result = isigmoid(x);
   printf("Sigmoid(%.2f): Expected %.4f, Got %.4f - ", x, expected, result);
   // Use a small tolerance for floating-point comparison
   if (fabs(result - expected) < 0.0001)
   {
      printf("Test Passed.\n");
      return EXIT_SUCCESS;
   }
   else
   {
      printf("Test Failed.\n");
      return EXIT_FAILURE;
   }
}

/**
 * {@inheritdoc}
 */
int run_sigmoid_unit_tests()
{
   printf("Testing the Sigmoid function:\n");
   // Sigmoid(0) should be 0.5
   if (unit_test_sigmoid(0.0, 0.5) == EXIT_FAILURE)
   {
      return EXIT_FAILURE;
   }
   // Sigmoid(1) approx 0.7311
   if (unit_test_sigmoid(1.0, 0.7311) == EXIT_FAILURE)
   {
      return EXIT_FAILURE;
   }
   // Sigmoid(-1) approx 0.2689
   if (unit_test_sigmoid(-1.0, 0.2689) == EXIT_FAILURE)
   {
      return EXIT_FAILURE;
   }
   // Sigmoid(10) should be close to 1
   if (unit_test_sigmoid(10.0, 0.99995) == EXIT_FAILURE)
   {
      return EXIT_FAILURE;
   }
   // Sigmoid(-10) should be close to 0
   if (unit_test_sigmoid(-10.0, 0.00005) == EXIT_FAILURE)
   {
      return EXIT_FAILURE;
   }
   // Tests Passed!.
   return EXIT_SUCCESS;
}
