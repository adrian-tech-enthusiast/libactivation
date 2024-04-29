#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "unit_test_callbacks.h"

/**
 * {@inheritdoc}
 */
int unit_test_callback(double input, double expected_output, const char *callback_name, double (*callback)(double)) {
  double result = callback(input);
  printf("%s(%.1f):\n", callback_name, input);
  printf("  Expected: %.11f \n", expected_output);
  printf("  Got:      %.11f \n", result);
  // Use a small tolerance for floating-point comparison.
  printf("  Result:   ");
  if (fabs(result - expected_output) < 0.0000000000001) {
    printf("Test Passed\n\n");
    return EXIT_SUCCESS;
  } else {
    printf("Test Failed\n\n");
    return EXIT_FAILURE;
  }
}
