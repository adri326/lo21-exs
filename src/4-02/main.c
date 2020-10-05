#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "../macros.h"

#define LEN 1024

int main(int argc, char* argv[]) {
    char input[LEN];
    char output[LEN];
    if (fgets(input, LEN, stdin) == NULL || feof(stdin)) return 2;
    size_t o = 0;
    size_t n_spaces = 0;
    for (size_t n = 0; input[n]; n++) {
        if (input[n] == ' ') {
            n_spaces++;
        } else {
            n_spaces = 0;
        }
        if (n_spaces <= 1) {
            output[o++] = input[n];
        }
    }
    printf("%s\n", output);
}
