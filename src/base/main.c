#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "../macros.h"
#include "../6-01/int_ll.h"

int_ll_t* construct_from_base(int base, uint64_t input) {
    ASSERT(base > 1);
    int_ll_t* res = NULL;
    uint64_t tmp = input;
    while (tmp > 0) {
        res = insert_head(res, (int)(tmp % (uint64_t)base));
        tmp /= base;
    }
    return res;
}

uint64_t deconstruct_from_base(int base, int_ll_t* input) {
    ASSERT(base > 1);
    uint64_t res = 0;
    int_ll_t* tmp = input;
    while (!is_empty(tmp)) {
        res = res * (uint64_t)base + (uint64_t)tmp->value;
        tmp = remove_head(tmp); // is bad, use a temporary variable
    }
    return res;
}

int main(int argc, char* argv[]) {
    int_ll_t* res = construct_from_base(16, 256);
    print_list(res);
    res = insert_tail(res, 12);
    printf("%" PRIu64 "\n", deconstruct_from_base(16, res));
}
