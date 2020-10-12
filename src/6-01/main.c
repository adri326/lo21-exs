#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "int_ll.h"
#include "../macros.h"

int main(int argc, char* argv[]) {
    int_ll_t* list = NULL;
    list = insert_tail(list, 2);
    list = insert_head(list, 3);
    list = insert_tail(list, 1);
    print_list(list);
    list = remove_tail(list);
    print_list(list);
}
