#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "../macros.h"

/** Returns whether or not `input` is prime
    @param input - The number to test
    @returns Whether or not `input` is prime
**/
bool is_prime(uint64_t input);

int main(int argc, char* argv[]) {
    uint64_t input = 0;
    INPUT(
        printf("input = "),
        printf("Invalid number, try again:\n"),
        1,
        "%"SCNu64,
        &input
    );

    printf("is_prime(%"PRIu64 ") = %s\n", input, is_prime(input) ? "true" : "false");
}

bool is_prime(uint64_t input) {
    if (input == 2) return true;
    if (input <= 1 || input % 2 == 0) {
        return false;
    }
    for (uint64_t n = 3; n * n <= input; n += 2) {
        if (input % n == 0) return false;
    }
    return true;
}
