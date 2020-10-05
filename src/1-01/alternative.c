#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "../macros.h"

/** Integrates f(x) over [a; b] with `n` trapezoids
    @param a Lower integral bound
    @param b Higher integral bound
    @param n Number of trapezoids
    @param f Callback function to integrate over
**/
double trapezoid_integration(double a, double b, uint64_t n, double (*f)(double));

double inverse(double x) {
  return 1 / x;
}

int main(int argc, char* argv[]) {
    double a = 1.0;
    double b = 2.0;
    uint64_t n = 10;

    INPUT(
        printf("a = "),
        printf("Invalid number, try again:\n"),
        1,
        "%lf", &a
    );

    INPUT(
        printf("b = "),
        printf("Invalid number, try again:\n"),
        1,
        "%lf", &b
    );

    INPUT(
        printf("n = "),
        printf("Invalid number, try again:\n"),
        1,
        "%" SCNu64, &n
    );

    printf("I = %lf\n", trapezoid_integration(a, b, n, &inverse));
}

double trapezoid_integration(double a, double b, uint64_t n, double (*f)(double)) {
    ASSERT(a <= b);
    ASSERT(n > 0);
    ASSERT(a * b > 0);

    double res = 0.0;
    double h = (b - a) / (double)n;

    for (uint64_t i = 0; i < n; i++) {
        res += h * (
            f(a + h*(double)i)
            + f(a + h*((double)i+1))
        ) / 2;
    }

    return res;
}
