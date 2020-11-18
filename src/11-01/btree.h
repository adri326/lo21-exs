#include <stdlib.h>
#include <stdbool.h>

/// Binary tree containing integers
struct int_bt {
  int value;
  struct int_bt* left;
  struct int_bt* right;
};
typedef struct int_bt int_bt_t;

/// Returns whether or not the given binary tree is empty (null)
#define bt_is_empty(tree) ((int_bt_t*)(tree) == NULL)

/// Returns whether or not the given binary tree is a terminal node / leaf; returns false if tree is NULL
bool bt_is_leaf(int_bt_t* tree);

/// Append (`left`, `right`) to `parent`
/// @returns false if parent is empty or if parent already has a child element
/// This is as to prevent memory leaks; the elements will only be appended if this function returns true
bool bt_append(int_bt_t* parent, int_bt_t* left, int_bt_t* right);

/// Allocate a new leaf
int_bt_t* bt_new_leaf(int element);

/// Deallocates a leaf and returns its previous value
int bt_free_leaf(int_bt_t* leaf);

/// Returns the left child of a node, NULL if the node is NULL
int_bt_t* bt_left_child(int_bt_t* node);

/// Returns the right child of a node, NULL if the node is NULL
int_bt_t* bt_right_child(int_bt_t* node);

/// Returns the number of nodes contained in `tree`
size_t bt_count(int_bt_t* tree);

/// Returns the number of leaves (terminal nodes) contained in `tree`
size_t bt_count_leaves(int_bt_t* tree);

/// Returns whether or not the tree (`hay`) contains `needle`; performs a DFS
bool bt_contains(int_bt_t* hay, int needle);

/// Removes every element of tree whose value is equal to `taboo`; note that if the root is a leaf and its value is equal to `taboo`, then it will be freed nonetheless, leaving you with an invalid pointer
size_t bt_remove_leaves_eq(int_bt_t* tree, int taboo);

/// Frees the memory owned by `tree` and its descendants
void bt_free(int_bt_t* tree);

/// Prints out the binary tree
void bt_print(int_bt_t* tree);

/// Prints out the binary tree; adds a newline at the end
void bt_println(int_bt_t* tree);
