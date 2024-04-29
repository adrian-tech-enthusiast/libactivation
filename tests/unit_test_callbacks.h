#ifndef UNIT_TEST_CALLBACKS_H
#define UNIT_TEST_CALLBACKS_H

/**
 * Execute unit tests for the specified callback function.
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

#endif
