#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <linkedlist.h>
#include <inttypes.h>
#include "../macros.h"

DECL_LL(int);
DECL_LL_SOURCES(int, "%d");

size_t list_length_rec(LL(int)* list) {
  if (list == NULL) return 0;
  return 1 + list_length_rec(list->next);
}

int main() {
  LL(int)* list = int_ll_new(0);
  list = int_ll_push_head(list, 1);
  list = int_ll_push_head(list, 2);
  list = int_ll_push_head(list, 3);

  printf("list = ");
  int_ll_printf(list);
  printf("length(list) = %zu\n", list_length_rec(list));

  int_ll_free(list);
}
