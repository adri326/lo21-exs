#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <linkedlist.h>
#include <inttypes.h>
#include "../macros.h"

DECL_LL(uint64_t);
DECL_LL_SOURCES(uint64_t, "%"PRIu64);

LL(uint64_t)* merge_ll(LL(uint64_t)* a, LL(uint64_t)* b);

int main(int argc, char* argv[]) {
    LL(uint64_t)* a = NULL;
    LL(uint64_t)* b = NULL;
    size_t n = 0;

    printf("Let us enter the different values of A (must be sorted); type -1 to stop.\n");
    while (true) {
        int64_t tmp = -1;
        n++;
        INPUT(
            printf("a_%zu = ", n),
            printf("Invalid number, try again (-1 to stop):\n"),
            1,
            "%"SCNi64, &tmp
        );
        if (tmp < 0) break;
        else a = uint64_t_ll_push_tail(a, (uint64_t)tmp);
    }

    n = 0;
    printf("Let us enter the different values of B (must be sorted); type -1 to stop.\n");
    while (true) {
        int64_t tmp = -1;
        n++;
        INPUT(
            printf("b_%zu = ", n),
            printf("Invalid number, try again (-1 to stop):\n"),
            1,
            "%"SCNi64, &tmp
        );
        if (tmp < 0) break;
        else b = uint64_t_ll_push_tail(b, (uint64_t)tmp);
    }

    LL(uint64_t)* merged = merge_ll(a, b);
    uint64_t_ll_printf(merged);

    uint64_t_ll_free(a);
    uint64_t_ll_free(b);
    uint64_t_ll_free(merged);
}

LL(uint64_t)* merge_ll(LL(uint64_t)* a, LL(uint64_t)* b) {
    LL(uint64_t)* res = NULL;
    while (a != NULL || b != NULL) {
        if (a != NULL && b != NULL) {
            if (*uint64_t_ll_head(a) > *uint64_t_ll_head(b)) {
                res = uint64_t_ll_push_tail(res, *uint64_t_ll_head(b));
                b = uint64_t_ll_pop_head(b);
            } else {
                res = uint64_t_ll_push_tail(res, *uint64_t_ll_head(a));
                a = uint64_t_ll_pop_head(a);
            }
        } else if (a == NULL) {
            res = uint64_t_ll_push_tail(res, *uint64_t_ll_head(b));
            b = uint64_t_ll_pop_head(b);
        } else {
            res = uint64_t_ll_push_tail(res, *uint64_t_ll_head(a));
            a = uint64_t_ll_pop_head(a);
        }
    }
    return res;
}
