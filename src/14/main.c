// This is a little joke :)

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <btree.h>
#include <bstree.h>
#include <inttypes.h>
#include "../macros.h"

DECL_BT(int);
DECL_BT_SOURCES(int, "%d");

DECL_BST(int);
DECL_BST_SOURCES(int, "%d");

int main(int argc, char* argv[]) {
    BT(int)* bt = int_bt_connect(int_bt_new(1), int_bt_connect(int_bt_new(2), NULL, 4), 0);

    // 1 - Calculate the depth of the tree
    printf("Depth = %zu\n", int_bt_depth(bt));
    // 2 - Calculate the number of nodes in a tree
    printf("Number of nodes = %zu\n", int_bt_size(bt));
    // 3 - Calculate the number of non-terminal nodes in a tree
    printf("Number of intermediary nodes = %zu\n", int_bt_size(bt) - int_bt_leaves(bt));

    printf("Tree before insertion: ");
    int_bt_printf(bt);

    // 5 - Insert a number in a binary tree
    int_bst_insert(bt, 3);

    printf("Tree after insertion: ");
    int_bt_printf(bt);

    // 4 - Completely free a binary tree
    int_bt_free(bt);
}
