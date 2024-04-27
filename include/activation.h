#ifndef SIGMOID_H
#define SIGMOID_H

#include <math.h>

/**
 * Sigmoid Function.
 *
 * The Sigmoid function maps any value from its domain to a number within the
 * range of 0 to 1.
 *
 * 1. Definition:
 *    sigmoid(x) = 1 / (1 + exp(-x))
 *
 * 2. Derivative Definition:
 *    sigmoid'(x) = sigmoid(x) * (1 - sigmoid(x))
 *
 * Note: We define the function as 'static inline' to enhance performance
 * and reduce execution time. This choice is made because the function is
 * lightweight and frequently utilized, allowing it to be seamlessly integrated
 * into the code where it is invoked. Consequently, this approach minimizes the
 * overhead typically incurred by function calls.
 *
 * @see https://en.wikipedia.org/wiki/Sigmoid_function
 */

/**
 * Calculate the sigmoid(x) value for a double.
 *
 * @param double x
 *   The double value.
 *
 * @return double
 *   The sigmoid value.
 */
static inline double isigmoid(double x) {
  return 1 / (1 + exp(-x));
}

/**
 * Calculates the derivative of the sigmoid(x) function for the given double.
 *
 * @param double x
 *   The double value.
 *
 * @return double
 *   The derivative value of the sigmoid function for the given double.
 */
static inline double isigmoid_derivative(double x) {
  double sigmoid = isigmoid(x);
  return sigmoid * (1 - sigmoid);
}

/**
 * Calculate the sigmoid(x) value for a float.
 *
 * @param float x
 *   The float value.
 *
 * @return float
 *   The sigmoid value.
 */
static inline float isigmoidf(float x) {
  return 1 / (1 + expf(-x));
}

/**
 * Calculates the derivative of the sigmoid(x) function for the given float.
 *
 * @param float x
 *   The float value.
 *
 * @return float
 *   The derivative value of the sigmoid function for the given float.
 */
static inline float isigmoidf_derivative(float x) {
  float sigmoidf = isigmoidf(x);
  return sigmoidf * (1 - sigmoidf);
}

/**
 * Calculate the sigmoid(x) value for a long double.
 *
 * @param long double x
 *   The long double value.
 *
 * @return long double
 *   The sigmoid value.
 */
static inline long double isigmoidl(long double x) {
  return 1 / (1 + expl(-x));
}

/**
 * Calculates the derivative of the sigmoid(x) func for the given long double.
 *
 * @param long double x
 *   The long double value.
 *
 * @return long double
 *   The derivative value of the sigmoid function for the given long double.
 */
static inline long double isigmoidl_derivative(long double x) {
  long double sigmoidl = isigmoidl(x);
  return sigmoidl * (1 - sigmoidl);
}

#endif

#ifndef TANH_H
#define TANH_H

#include "math.h"

/**
 * Hyperbolic Tangent Function.
 *
 * tanh(x) is a nonlinear activation function, with its center at 0 and
 * its value ranging between –1 to 1.
 *
 * tanh(x) can be expressed in numerous ways depending on the need, it can be
 * defined using the exponential function in several slightly different but
 * equivalent forms. Here are three common representations:
 *
 * 1. Basic Exponential Definition:
 *    tanh(x) = (exp(x) - exp(-x)) / (exp(x) + exp(-x))
 *
 * 2. Symmetric Form Definition:
 *    tanh(x) = (1- exp(-2*x)) / (1 - exp(-2*x))
 *
 * 3. Alternate Symmetric Form:
 *    tanh(x) = (exp(2*x) - 1) / (exp(2*x) + 1)
 *
 * The form #2 is particularly useful for computing tanh(x) for large negative
 * x values because it avoids large exponential values that could lead to
 * numerical overflow.
 *
 * The form #3 is beneficial for computing tanh(x) for
 * large positive x values, mitigating issues with numerical underflow that
 * might occur when x is negative and large in magnitude.
 *
 * These three forms showcase the flexibility in representing the hyperbolic
 * tangent function using exponential functions, each of these expressions
 * provides the same hyperbolic tangent function, each being particularly
 * useful under different computational circumstances.
 *
 * The derivative of the hyperbolic tangent (tanh) function can be expressed in
 * multiple equivalent forms, each tailored to different contexts or
 * computational requirements. Below is the standard and most commonly used
 * expression for the derivative of tanh(x):
 *
 * 1. Standard Derivative Definition:
 *    tanh'(x) = 1 - tanh²(x)
 *
 * Note: We define the function as 'static inline' to enhance performance
 * and reduce execution time. This choice is made because the function is
 * lightweight and frequently utilized, allowing it to be seamlessly integrated
 * into the code where it is invoked. Consequently, this approach minimizes the
 * overhead typically incurred by function calls.
 *
 * @see https://en.wikipedia.org/wiki/Hyperbolic_functions
 * @see https://www.mathworks.com/help/matlab/ref/tanh.html#bt7lj8r-3
 */

/**
 * Calculate the tanh(x) value for a double.
 *
 * @param double x
 *   The double value.
 *
 * @return double
 *   The tanh value.
 */
static inline double itanh(double x) {
  return (exp(2 * x) - 1) / (exp(2 * x) + 1);
}

/**
 * Calculates the derivative of the tanh(x) function for the given double.
 *
 * @param double x
 *   The double value.
 *
 * @return double
 *   The derivative value of the tanh function for the given double.
 */
static inline double itanh_derivative(double x) {
  double tanh = itanh(x);
  return 1 - tanh * tanh;
}

/**
 * Calculate the tanh(x) value for a float.
 *
 * @param float x
 *   The float value.
 *
 * @return float
 *   The tanh value.
 */
static inline float itanhf(float x) {
  return (expf(2 * x) - 1) / (expf(2 * x) + 1);
}

/**
 * Calculates the derivative of the tanh(x) function for the given float.
 *
 * @param float x
 *   The float value.
 *
 * @return float
 *   The derivative value of the tanh function for the given float.
 */
static inline float itanhf_derivative(float x) {
  float tanhf = itanhf(x);
  return 1 - tanhf * tanhf;
}

/**
 * Calculate the tanh(x) value for a long double.
 *
 * @param long double x
 *   The long double value.
 *
 * @return long double
 *   The tanh value.
 */
static inline long double itanhl(long double x) {
  return (expl(2 * x) - 1) / (expl(2 * x) + 1);
}

/**
 * Calculates the derivative of the tanh(x) func for the given long double.
 *
 * @param long double x
 *   The long double value.
 *
 * @return long double
 *   The derivative value of the tanh function for the given long double.
 */
static inline long double itanhl_derivative(long double x) {
  long double tanhl = itanhl(x);
  return 1 - tanhl * tanhl;
}

#endif
