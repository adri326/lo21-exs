#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "../macros.h"

// Structure to hold an array of integers
struct int_l {
    size_t length;
    int* values;
};
typedef struct int_l int_l;

/** Splits the `input` array into two arrays, `lhs` and `rhs`, containing respectively all the values lower or equal and strictly greater than `input[p]`, each excluding `input[p]`.
    @param input The input array to split
    @param p The "pivot" index
    @param lhs The values lower or equal to `input[p]`
    @param rhs The values strictly greater than `input[p]`
**/
void qs_split(const int_l input, int_l* lhs, int_l* rhs, const size_t p);

/** Sorts the input array using the quicksort method (chooses a random pivot point and recursively calls quicksort on values higher and lower than that pivot value)
    @param input The input array to sort
    @returns The sorted array
**/
int_l quicksort(const int_l input);

int main(int argc, char* argv[]) {
    int_l array;
    array.length = 0;
    INPUT(
        printf("N = "),
        printf("Invalid number, try again:\n"),
        1,
        "%zu", &array.length
    );

    array.values = (int*)malloc(sizeof(int) * array.length);

    for (size_t n = 0; n < array.length; n++) {
        INPUT(
            printf("L_%zu = ", n),
            printf("Invalid number, try again:\n"),
            1,
            "%d", &array.values[n]
        );
    }

    int_l res = quicksort(array);

    for (size_t n = 0; n < res.length; n++) {
        printf("R_%zu = %d\n", n, res.values[n]);
    }

    free(array.values);
    free(res.values);
}

void qs_split(const int_l input, int_l* lhs, int_l* rhs, const size_t p) {
    lhs->values = (int*)malloc(sizeof(int) * input.length);
    lhs->length = 0;
    rhs->values = (int*)malloc(sizeof(int) * input.length);
    rhs->length = 0;

    for (size_t n = 0; n < input.length; n++) {
        if (n == p) continue;
        if (input.values[n] > input.values[p]) {
            rhs->values[rhs->length] = input.values[n];
            rhs->length++;
        } else {
            lhs->values[lhs->length] = input.values[n];
            lhs->length++;
        }
    }
}

int_l quicksort(const int_l input) {
    int_l res;
    res.values = (int*)malloc(sizeof(int) * input.length);
    res.length = 0;
    if (input.length == 0) {
        res.values = NULL;
    } else {
        int_l lhs;
        int_l rhs;
        size_t p = rand() % input.length;
        qs_split(input, &lhs, &rhs, p);

        int_l s_lhs = quicksort(lhs);
        int_l s_rhs = quicksort(rhs);
        for (size_t n = 0; n < s_lhs.length; n++) {
            res.values[res.length++] = s_lhs.values[n];
        }

        res.values[res.length++] = input.values[p];

        for (size_t n = 0; n < s_rhs.length; n++) {
            res.values[res.length++] = s_rhs.values[n];
        }

        // Free the various intermediate values
        free(lhs.values);
        free(rhs.values);
        free(s_lhs.values);
        free(s_rhs.values);
    }

    return res;
}
