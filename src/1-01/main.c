#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "../macros.h"
// #include <stdbool.h>

// Step 1: define the different variables, datas, results, the different equations (mathematical formalization)
// Step 2: define a recursive sequence / function
// Step 3: define an algorithm that will give the result

/**

**/

float trapezoid_integration(float a, float b, uint32_t n);

int main(int argc, char* argv[]) {
    float a = 1.0;
    float b = 2.0;
    uint32_t n = 10;

    INPUT(
        printf("a = "),
        printf("Invalid number, try again:\n"),
        1,
        "%f", &a
    );

    INPUT(
        printf("b = "),
        printf("Invalid number, try again:\n"),
        1,
        "%f", &b
    );

    INPUT(
        printf("n = "),
        printf("Invalid number, try again:\n"),
        1,
        "%" SCNu32, &n
    );

    printf("I = %f\n", trapezoid_integration(a, b, n));
}

/** Integrates 1/x over [a; b] with `n` trapezoids

    @param a Lower integral bound
    @param b Higher integral bound
    @param n Number of trapezoids
**/
float trapezoid_integration(float a, float b, uint32_t n) {
    ASSERT(a <= b);
    ASSERT(n > 0);
    ASSERT(a * b > 0);

    float res = 0.0;
    float h = (b - a) / (float)n;

    for (uint32_t i = 0; i < n; i++) {
        res += h * (
            1 / (a + h*(float)i)
            + 1 / (a + h*((float)i+1))
        ) / 2;
    }

    return res;
}
