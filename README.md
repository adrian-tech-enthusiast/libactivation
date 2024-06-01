## Lib Activation: A specialized C library designed to provide developers and researchers with a comprehensive set of activation functions essential for building and experimenting with neural networks.

This lightweight, efficient library supports a wide range of activation functions, enabling optimal performance and
flexibility in neural network development.

Whether you're building deep learning models, experimenting with machine learning algorithms, or conducting research in
artificial intelligence, `Lib Activation` offers a collection of widely-used activation functions optimized for
performance and ease of use.

## Key Features

- **Comprehensive Activation Functions**: Includes a variety of activation functions such as Sigmoid, ReLU, Tanh, Leaky
  ReLU, and more, each optimized for high performance.
- **Optimized for Speed**: Carefully optimized C code to ensure maximum performance, crucial for training and deploying
  neural networks.
- **Extensive Unit Testing:** Unit tests are provided for each activation function to ensure correctness and reliability. These tests cover a variety of input scenarios to validate the behavior of the functions.
- **Easy Integration**: Designed with simplicity in mind, `Lib Activation` can be easily integrated into existing neural
  network projects or used in new developments.
- **Cross-Platform Compatibility**: Compatible with various operating systems, ensuring flexibility across different
  development environments.
- **Open Source**: The library is open source and actively maintained, allowing for community contributions and
  enhancements.

## Target Audience

`Lib Activation` is ideal for computer science students, AI researchers, and professional developers working on machine
learning projects that require efficient and effective activation functions in C.

### Prerequisites

Ensure you have a C compiler installed on your system, such as `gcc` or `clang`.

## Getting Started

To start using `Lib Activation`, clone the repository, include it in your project and refer to the documentation for
guidance on how to implement each function within your neural networks.

## Installation

To make sure you obtain the most updated stable version
of [shared library](https://en.wikipedia.org/wiki/Library_(computing)#Shared_libraries)(a DLL in Windows or .so in
Unix/Linux), you’ll download this software from
its [official Github repository](https://github.com/adrian-tech-enthusiast/libactivation).

First, confirm the latest version available in
their [releases page](https://github.com/adrian-tech-enthusiast/libactivation/releases). At the time of this writing,
the most current stable version is `1.0.1`.

1. The following command will download the `1.0.1` release and save the shared library file at
   /usr/local/lib/libactivation.so, which will make this library globally accessible to clients:

    ```bash
    sudo curl -L "https://github.com/adrian-tech-enthusiast/libactivation/releases/download/v1.0.1/libactivation.so" -o /usr/local/lib/libactivation.so
    ```

2. Next, We need to tell the loader it is available for use, so let us update the cache, invoke the `ldconfig` utility,
   which configures the system's dynamic loader. This configuration ensures that the loader will find the newly
   published library:

    ```bash
    sudo ldconfig;
    ```

   That should create a link to our shared library and update the cache so it is available for immediate use. To verify
   you can run:

    ```bash
    ldconfig -p | grep activation
    ```

3. Copy the library header file(`activation.h`) to where it can be included in one of the C compiler's search path.
   Typical locations are `/usr/include` and `/usr/local/include`;

    ```bash
    sudo curl -L "https://raw.githubusercontent.com/adrian-tech-enthusiast/libactivation/v1.0.1/include/activation.h" -o /usr/local/include/activation.h;
    ```

   This allows the library header file to be included in your C project as follows:

    ```c
    #include <stdio.h>  /* standard input/output functions */
    #include <activation.h> /* C Activation Library functions */
    ```
   Without this `#include`, the compiler would complain about missing declarations for functions provided by the C
   Activation Library.

4. Finally, in order to compile your code with the library, add the link flag to the library during the compilation of
   your C project:

    ```bash
    gcc -o tester tester.c -lactivation
    ```

## Example Usage

This section provides basic examples of how to integrate `Lib Activation` functions into your neural network projects.
Here we demonstrate the usage of two popular activation functions: Sigmoid and ReLU.

#### Including the Library

First, ensure that the `Lib Activation` library is correctly included in your C source files:

```c
#include <activation.h> /* C Activation Library functions */
```

#### Example 1: Using the Sigmoid Activation Function

The Sigmoid function is commonly used in neural networks for binary classification. Here's how you can use it:

```c
#include <stdio.h>
#include <activation.h> /* C Activation Library functions */

int main() {
    double input = 0.5; // Example input
    double output;

    output = isigmoid(input);
    printf("Sigmoid Activation Output: %f\n", output);

    return 0;
}
```

#### Example 2: Using the ReLU Activation Function

The Rectified Linear Unit (ReLU) function is widely used in deep learning models. Here's an example of applying ReLU:

```c
#include <stdio.h>
#include <activation.h> /* C Activation Library functions */

int main() {
    double input = -0.5; // Example input
    double output;

    output = irelu(input);
    printf("ReLU Activation Output: %f\n", output);

    return 0;
}
```

#### Compiling the Code

To compile your program, you might use a command like this, depending on your setup:

```bash
gcc -o my_neural_network my_neural_network.c -lactivation
```

Replace `my_neural_network.c` with the name of your source file. Make sure that the activation library is correctly linked.

#### Additional Tips

- Always test activation functions with different inputs to understand their behavior.
- Refer to the `Lib Activation` documentation for more advanced usage, including other available activation functions
  and performance considerations.

## Contributions

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any
contributions you make are greatly appreciated.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This library is licensed under the `GNU General Public License v3.0` License. See the LICENSE file for details.

## Contact

Mr. Adrián Morelos - adrian.tech.enthusiast@gmail.com