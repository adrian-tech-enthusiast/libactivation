#include <stdio.h>
#include <stdlib.h>
#include "../include/activation.h"
#include "unit_test_callbacks.h"

/**
 * Unit testing for the isoftmax(x, len) function.
 *
 * @param double *x
 *   The pointer to a vector with double values.
 * @param double *result
 *   The pointer to the vector where the output result will be stored.
 * @param double *expected
 *   The pointor to a vector with the expected double values.
 * @param int len
 *   The vector length.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_isoftmax(double *x, double *result, double *expected, int len) {
  char *callback_name = "isoftmax";
  isoftmax(x, result, len);
  double tolerance = 0.000001;
  double input, expected_output, actual_output;
  printf("%s:\n", callback_name);
  for (int i = 0; i < len; i++) {
    input = x[i];
    expected_output = expected[i];
    actual_output = result[i];
    printf("  Input:    %.11f \n", input);
    printf("  Expected: %.11f \n", expected_output);
    printf("  Got:      %.11f \n", actual_output);
    printf("  Result:   ");
    if (fabs(actual_output - expected_output) < tolerance) {
      printf("Test Passed\n\n");
    } else {
      printf("Test Failed\n\n");
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}

/**
 * Unit testing for the isoftmaxf(x, len) function.
 *
 * @param float *x
 *   The pointor to a vector with float values.
 * @param float *result
 *   The pointer to the vector where the output result will be stored.
 * @param float *expected
 *   The pointor to a vector with the expected float values.
 * @param int len
 *   The vector length.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_isoftmaxf(float *x, float *result, float *expected, int len) {
  char *callback_name = "isoftmaxf";
  isoftmaxf(x, result, len);
  float tolerance = 0.000001;
  float input, expected_output, actual_output;
  printf("%s:\n", callback_name);
  for (int i = 0; i < len; i++) {
    input = x[i];
    expected_output = expected[i];
    actual_output = result[i];
    printf("  Input:    %.11f \n", input);
    printf("  Expected: %.11f \n", expected_output);
    printf("  Got:      %.11f \n", actual_output);
    printf("  Result:   ");
    if (fabs(actual_output - expected_output) < tolerance) {
      printf("Test Passed\n\n");
    } else {
      printf("Test Failed\n\n");
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}

/**
 * Unit testing for the isoftmaxl(x, len) function.
 *
 * @param long double *x
 *   The pointor to a vector with long double values.
 * @param long double *result
 *   The pointer to the vector where the output result will be stored.
 * @param long double *expected
 *   The pointor to a vector with the expected long double values.
 * @param int len
 *   The vector length.
 *
 * @return int
 *   The constant that represent the test exit status.
 */
static int unit_test_isoftmaxl(long double *x, long double *result, long double *expected, int len) {
  char *callback_name = "isoftmaxl";
  isoftmaxl(x, result, len);
  long double tolerance = 0.000001;
  long double input, expected_output, actual_output;
  printf("%s:\n", callback_name);
  for (int i = 0; i < len; i++) {
    input = x[i];
    expected_output = expected[i];
    actual_output = result[i];
    printf("  Input:    %.11Lf \n", input);
    printf("  Expected: %.11Lf \n", expected_output);
    printf("  Got:      %.11Lf \n", actual_output);
    printf("  Result:   ");
    if (fabs(actual_output - expected_output) < tolerance) {
      printf("Test Passed\n\n");
    } else {
      printf("Test Failed\n\n");
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}

/**
 * {@inheritdoc}
 */
int run_softmax_unit_tests() {
  printf("Testing the Softmax functions:\n");
  printf("------------------------------\n");
  long double inputl[] = {1.0, 2.0, 3.0, 6.0};
  long double outputl[] = {0, 0, 0, 0};
  long double expectedl[] = {0.00626879, 0.01704033, 0.04632042, 0.93037047};
  int lenl = sizeof(inputl) / sizeof(long double);
  if (unit_test_isoftmaxl(inputl, outputl, expectedl, lenl) == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }
  float inputf[] = {1.0, 2.0, 3.0, 6.0};
  float outputf[] = {0, 0, 0, 0};
  float expectedf[] = {0.00626879, 0.01704033, 0.04632042, 0.93037047};
  int lenf = sizeof(inputf) / sizeof(float);
  if (unit_test_isoftmaxf(inputf, outputf, expectedf, lenf) == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }
  double input[] = {1.0, 2.0, 3.0, 6.0};
  double output[] = {0, 0, 0, 0};
  double expected[] = {0.00626879, 0.01704033, 0.04632042, 0.93037047};
  int len = sizeof(input) / sizeof(double);
  if (unit_test_isoftmax(input, output, expected, len) == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }
  // Tests Passed!.
  return EXIT_SUCCESS;
}
