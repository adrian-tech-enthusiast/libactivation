#ifndef UNIT_TEST_CALLBACKS_H
#define UNIT_TEST_CALLBACKS_H

/**
 * Execute unit tests for the specified callback function with double values.
 *
 * @param double input
 *   The input value.
 * @param double expected_output
 *   The expected output value.
 * @param const char *callback_name
 *   The callback name.
 * @param double (*callback)(double)
 *   The pointer to the callback function.
 *
 * @return int
 *   The constant that represent the exit status.
 */
int unit_test_callback(double input, double expected_output, const char *callback_name, double (*callback)(double));

/**
 * Execute unit tests for the specified callback function with float values.
 *
 * @param float input
 *   The input value.
 * @param float expected_output
 *   The expected output value.
 * @param const char *callback_name
 *   The callback name.
 * @param float (*callback)(float)
 *   The pointer to the callback function.
 *
 * @return int
 *   The constant that represent the exit status.
 */
int unit_test_callbackf(float input, float expected_output, const char *callback_name, float (*callback)(float));

/**
 * Execute unit tests for the specified callback function with long double values.
 *
 * @param long double input
 *   The input value.
 * @param long double expected_output
 *   The expected output value.
 * @param const char *callback_name
 *   The callback name.
 * @param long double (*callback)(long double)
 *   The pointer to the callback function.
 *
 * @return int
 *   The constant that represent the exit status.
 */
int unit_test_callbackl(long double input, long double expected_output, const char *callback_name, long double (*callback)(long double));

#endif
