#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "../macros.h"

/**
    Computes the result of P(x) (P ∈ ℝ[X])
    @param l - The length of `a`
    @param a - The terms of `P`
    @param x - The value at which `P(x)` is computed
    @returns P(x)
**/
float polynome(const size_t l, const float a[], const float x);

int main(int argc, char* argv[]) {
    size_t l = 0;
    INPUT(
        printf("l = "),
        printf("Invalid number, try again:\n"),
        1,
        "%zu", &l
    );

    float* a = (float*)malloc(sizeof(float) * l);

    for (size_t n = 0; n < l; n++) {
        INPUT(
            printf("a_%zu = ", n),
            printf("Invalid number, try again:\n"),
            1,
            "%f", &a[n]
        );
    }

    float x = 0;
    INPUT(
        printf("x = "),
        printf("Invalid number, try again:\n"),
        1,
        "%f", &x
    );

    printf("P(x) = %f\n", polynome(l, a, x));

    free(a);
}

float polynome(const size_t l, const float a[], const float x) {
    float y = 1;
    float res = 0;
    for (size_t n = 0; n < l; n++) {
        res += a[n] * y;
        y *= x;
    }
    return res;
}
