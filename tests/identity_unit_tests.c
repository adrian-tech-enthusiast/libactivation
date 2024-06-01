#include <stdio.h>
#include <stdlib.h>
#include "../include/activation.h"
#include "unit_test_callbacks.h"

/**
 * Unit testing for the identity(x) function.
 *
 * @param double x
 *   The double value.
 * @param double expected
 *   The expected double value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_identity(double x, double expected) {
  return unit_test_callback(x, expected, "identity", identity);
}

/**
 * Unit testing for the identityf(x) function.
 *
 * @param float x
 *   The float value.
 * @param float expected
 *   The expected float value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_identityf(float x, float expected) {
  return unit_test_callbackf(x, expected, "identityf", identityf);
}

/**
 * Unit testing for the identityl(x) function.
 *
 * @param long double x
 *   The long double value.
 * @param long double expected
 *   The expected long double value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_identityl(long double x, long double expected) {
  return unit_test_callbackl(x, expected, "identityl", identityl);
}

/**
 * {@inheritdoc}
 */
int run_identity_unit_tests() {
  printf("Testing the Identity functions:\n");
  printf("------------------------------\n");
  long double inputs_a[][2] = {
      // Identity(-1) expected to be -1.
      {-1.0, -1.0},
      // Identity(0) expected to be 0.
      {0.0, 0.0},
      // Identity(0.5) expected to be 0.5.
      {0.5, 0.5},
      // Identity(10.0) expected to be 10.
      {10.0, 10.0},
      // Identity(-10.0) expected to be -10.0.
      {-10.0, -10.0},
      // Identity(-0.0001) expected to be -0.0001.
      {-0.0001, -0.0001},
      // Identity(1000) expected to be 1000.
      {1000.0, 1000.0},
      // Identity(-1000) expected to be -1000.
      {-1000.0, -1000.0},
  };
  for (int i = 0; i < 7; i++) {
    if (unit_test_identityl(inputs_a[i][0], inputs_a[i][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
    if (unit_test_identityf((float)inputs_a[i][0], (float)inputs_a[i][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
    if (unit_test_identity((double)inputs_a[i][0], (double)inputs_a[i][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
  }
  // Tests Passed!.
  return EXIT_SUCCESS;
}
