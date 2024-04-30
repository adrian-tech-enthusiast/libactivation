#include <stdio.h>
#include <stdlib.h>
#include "../include/activation.h"
#include "unit_test_callbacks.h"

/**
 * Unit testing for the itanh(x) function.
 *
 * @param double x
 *   The double value.
 * @param double expected
 *   The expected double value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_itanh(double x, double expected) {
  return unit_test_callback(x, expected, "itanh", itanh);
}

/**
 * Unit testing for the itanhf(x) function.
 *
 * @param float x
 *   The float value.
 * @param float expected
 *   The expected float value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_itanhf(float x, float expected) {
  return unit_test_callbackf(x, expected, "itanhf", itanhf);
}

/**
 * Unit testing for the itanhl(x) function.
 *
 * @param long double x
 *   The long double value.
 * @param long double expected
 *   The expected long double value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_itanhl(long double x, long double expected) {
  return unit_test_callbackl(x, expected, "itanhl", itanhl);
}

/**
 * Unit testing for the itanh_derivative(x) function.
 *
 * @param double x
 *   The double value.
 * @param double expected
 *   The expected double value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_itanh_derivative(double x, double expected) {
  return unit_test_callback(x, expected, "itanh_derivative", itanh_derivative);
}

/**
 * Unit testing for the itanhf_derivative(x) function.
 *
 * @param float x
 *   The float value.
 * @param float expected
 *   The expected float value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_itanhf_derivative(float x, float expected) {
  return unit_test_callbackf(x, expected, "itanhf_derivative", itanhf_derivative);
}

/**
 * Unit testing for the itanhl_derivative(x) function.
 *
 * @param long double x
 *   The long double value.
 * @param long double expected
 *   The expected long double value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_itanhl_derivative(long double x, long double expected) {
  return unit_test_callbackl(x, expected, "itanhl_derivative", itanhl_derivative);
}

/**
 * {@inheritdoc}
 */
int run_tanh_unit_tests() {
  printf("Testing the tanh functions:\n");
  printf("------------------------------\n");
  long double inputs_a[][2] = {
      // tanh(0) expected to be 0.
      {0.0, 0.0},
      // tanh(1) approx 0.7615941559558.
      {1.0, 0.7615941559558},
      // tanh(-1) approx -0.7615941559558.
      {-1.0, -0.7615941559558},
      // tanh(5) should be close to 1.
      {5.0, 0.9999092042626},
      // tanh(-5.0) should be close to -1.
      {-5.0, -0.9999092042626},
      // tanh(20.0) expected to be 1.
      {20.0, 1.0000000000000},
      // tanh(-20.0) expected to be -1.
      {-20.0, -1.0000000000000},
  };
  for (int i = 0; i < 7; i++) {
    if (unit_test_itanhl(inputs_a[i][0], inputs_a[i][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
    if (unit_test_itanhf((float)inputs_a[i][0], (float)inputs_a[i][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
    if (unit_test_itanh((double)inputs_a[i][0], (double)inputs_a[i][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
  }
  printf("------------------------------\n");
  double inputs_b[][2] = {
      // tanh'(0) should be close to 1.0.
      {0.0, 1.0000000000000},
      // tanh'(1) approx 0.4199743416140.
      {1.0, 0.4199743416140},
      // tanh'(-1.0) approx 0.4199743416140.
      {-1.0, 0.4199743416140},
      // tanh'(2.0) approx 0.0706508248532.
      {2.0, 0.0706508248532},
      // tanh'(-2.0) should 0.0706508248532.
      {-2.0, 0.0706508248532},
      // tanh'(5.0) should 0.0001815832309.
      {5.0, 0.0001815832309},
      // tanh'(-5.0) should 0.0001815832309.
      {-5.0, 0.0001815832309},
  };
  for (int j = 0; j < 7; j++) {
    if (unit_test_itanhl_derivative(inputs_b[j][0], inputs_b[j][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
    if (unit_test_itanhf_derivative((float)inputs_b[j][0], (float)inputs_b[j][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
    if (unit_test_itanh_derivative(inputs_b[j][0], inputs_b[j][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
  }
  // Tests Passed!.
  return EXIT_SUCCESS;
}
