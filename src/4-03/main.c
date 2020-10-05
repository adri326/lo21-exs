#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "../macros.h"

/** Merges `left` (of length `l_left`) and `right` (of length `l_right`) into `merged`
    Requires that `merged` has as length at least `l_left + l_right`
    @param left - The first input array
    @param l_left - The length of `left`
    @param right - The second input array
    @param l_right - The length of `right`
    @param merged - The output array
**/
void merge(
    const int* left,
    const size_t l_left,
    const int* right,
    const size_t l_right,
    int* merged
);

int main(int argc, char* argv[]) {
    size_t l_left, l_right;
    INPUT(
        printf("length(left) = "),
        printf("Invalid number, try again:\n"),
        1,
        "%zu", &l_left
    );
    INPUT(
        printf("length(right) = "),
        printf("Invalid number, try again:\n"),
        1,
        "%zu", &l_right
    );

    int* left = (int*)malloc(sizeof(int) * l_left);
    int* right = (int*)malloc(sizeof(int) * l_right);
    int* merged = (int*)malloc(sizeof(int) * (l_left + l_right));

    for (size_t n = 0; n < l_left; n++) {
        INPUT(
            printf("left[%zu] = ", n),
            printf("Invalid number, try again:\n"),
            1,
            "%d", &left[n]
        );
    }

    for (size_t n = 0; n < l_right; n++) {
        INPUT(
            printf("right[%zu] = ", n),
            printf("Invalid number, try again:\n"),
            1,
            "%d", &right[n]
        );
    }

    merge(left, l_left, right, l_right, merged);

    for (size_t n = 0; n < l_left + l_right; n++) {
        printf("merged[%zu] = %d\n", n, merged[n]);
    }

    free(left);
    free(right);
    free(merged);
}

void merge(
    const int* left,
    const size_t l_left,
    const int* right,
    const size_t l_right,
    int* merged
) {
    size_t i = 0, j = 0, l = 0;
    while (i < l_left || j < l_right) {
        if (i < l_left && (j == l_right || left[i] <= right[j])) {
            merged[l++] = left[i++];
        } else {
            merged[l++] = right[j++];
        }
    }
}
