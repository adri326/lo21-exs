#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "btree.h"
#include "../macros.h"

int main(int argc, char* argv[]) {
  int_bt_t* empty = NULL;
  int_bt_t* lonely = bt_new_leaf(12);
  int_bt_t* happy_family = bt_new_leaf(1);
  bt_append(happy_family, bt_new_leaf(2), bt_new_leaf(3));
  printf("Empty tree: ");
  bt_println(empty);
  printf("Lonely node: ");
  bt_println(lonely);
  printf("Family: ");
  bt_println(happy_family);

  printf("Number of nodes within family: %zu (should be equal to 3)\n", bt_count(happy_family));
  ASSERT(bt_count(happy_family) == 3);

  printf("Number of leaves within family: %zu (should be equal to 2)\n", bt_count_leaves(happy_family));
  ASSERT(bt_count_leaves(happy_family) == 2);

  bt_free(lonely);
  bt_free(happy_family);
}
