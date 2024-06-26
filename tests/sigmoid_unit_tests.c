#include <stdio.h>
#include <stdlib.h>
#include "../include/activation.h"
#include "unit_test_callbacks.h"

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
static int unit_test_isigmoid(double x, double expected) {
  return unit_test_callback(x, expected, "isigmoid", isigmoid);
}

/**
 * Unit testing for the isigmoidf(x) function.
 *
 * @param float x
 *   The float value.
 * @param float expected
 *   The expected float value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_isigmoidf(float x, float expected) {
  return unit_test_callbackf(x, expected, "isigmoidf", isigmoidf);
}

/**
 * Unit testing for the isigmoidl(x) function.
 *
 * @param long double x
 *   The long double value.
 * @param long double expected
 *   The expected long double value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_isigmoidl(long double x, long double expected) {
  return unit_test_callbackl(x, expected, "isigmoidl", isigmoidl);
}

/**
 * Unit testing for the isigmoid_derivative(x) function.
 *
 * @param double x
 *   The double value.
 * @param double expected
 *   The expected double value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_isigmoid_derivative(double x, double expected) {
  return unit_test_callback(x, expected, "isigmoid_derivative", isigmoid_derivative);
}

/**
 * Unit testing for the isigmoidf_derivative(x) function.
 *
 * @param float x
 *   The float value.
 * @param float expected
 *   The expected float value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_isigmoidf_derivative(float x, float expected) {
  return unit_test_callbackf(x, expected, "isigmoidf_derivative", isigmoidf_derivative);
}

/**
 * Unit testing for the isigmoidl_derivative(x) function.
 *
 * @param long double x
 *   The long double value.
 * @param long double expected
 *   The expected long double value.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_isigmoidl_derivative(long double x, long double expected) {
  return unit_test_callbackl(x, expected, "isigmoidl_derivative", isigmoidl_derivative);
}

/**
 * {@inheritdoc}
 */
int run_sigmoid_unit_tests() {
  printf("Testing the Sigmoid functions:\n");
  printf("------------------------------\n");
  long double inputs_a[][2] = {
      // Sigmoid(0) should be 0.5.
      {0.0, 0.5},
      // Sigmoid(1) approx 0.7311.
      {1.0, 0.731058578630074},
      // Sigmoid(-1) approx 0.2689.
      {-1.0, 0.2689414213699260},
      // Sigmoid(10) should be close to 1.
      {10.0, 0.9999546021312978},
      // Sigmoid(-10) should be close to 0.
      {-10.0, 0.0000453978687022},
  };
  for (int i = 0; i < 5; i++) {
    if (unit_test_isigmoidl(inputs_a[i][0], inputs_a[i][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
    if (unit_test_isigmoidf((float)inputs_a[i][0], (float)inputs_a[i][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
    if (unit_test_isigmoid((double)inputs_a[i][0], (double)inputs_a[i][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
  }
  printf("------------------------------\n");
  double inputs_b[][2] = {
      // Sigmoid'(0) should be 0.25.
      {0.0, 0.25},
      // Sigmoid'(1) approx 0.19661193324148185.
      {1.0, 0.19661193324148185},
      // Sigmoid'(2) approx 0.1049935854035065.
      {2.0, 0.1049935854035065},
      // Sigmoid'(-1.0) approx 0.19661193324148185.
      {-1.0, 0.19661193324148185},
      // Sigmoid'(2) should 0.1049935854035065.
      {2.0, 0.1049935854035065},
  };
  for (int j = 0; j < 5; j++) {
    if (unit_test_isigmoidl_derivative(inputs_b[j][0], inputs_b[j][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
    if (unit_test_isigmoidf_derivative((float)inputs_b[j][0], (float)inputs_b[j][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
    if (unit_test_isigmoid_derivative(inputs_b[j][0], inputs_b[j][1]) == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
  }
  // Tests Passed!.
  return EXIT_SUCCESS;
}
