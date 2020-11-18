#include <stdio.h>
#include "btree.h"

bool bt_is_leaf(int_bt_t* tree) {
  return tree != NULL && tree->left == NULL && tree->right == NULL;
}

bool bt_append(int_bt_t* parent, int_bt_t* left, int_bt_t* right) {
  if (parent == NULL || parent->left != NULL || parent->right != NULL) return false;

  parent->left = left;
  parent->right = right;

  return true;
}

int_bt_t* bt_new_leaf(int element) {
  int_bt_t* res = (int_bt_t*)malloc(sizeof(struct int_bt));

  res->value = element;
  res->left = NULL;
  res->right = NULL;

  return res;
}

int bt_free_leaf(int_bt_t* leaf) {
  if (leaf == NULL) return 0;
  int res = leaf->value;
  free(leaf);
  return res;
}

int_bt_t* bt_left_child(int_bt_t* node) {
  if (node == NULL) return NULL;
  return node->left;
}

int_bt_t* bt_right_child(int_bt_t* node) {
  if (node == NULL) return NULL;
  return node->right;
}

size_t bt_count(int_bt_t* tree) {
  if (tree == NULL) return 0;
  else return 1 + bt_count(tree->left) + bt_count(tree->right);
}

size_t bt_count_leaves(int_bt_t* tree) {
  if (tree == NULL) return 0;
  if (bt_is_leaf(tree)) return 1;
  else return bt_count(tree->left) + bt_count(tree->right);
}

bool bt_contains(int_bt_t* hay, int needle) {
  if (hay == NULL) return false;
  else if (hay->value == needle) return true;
  else return bt_contains(hay->left, needle) || bt_contains(hay->right, needle);
}

size_t bt_remove_leaves_eq(int_bt_t* tree, int taboo) {
  if (tree == NULL) return 0;
  else if (bt_is_leaf(tree) && tree->value == taboo) {
    bt_free_leaf(tree);
    return 1;
  } else {
    bool left_leaf = bt_is_leaf(tree->left);
    bool right_leaf = bt_is_leaf(tree->right);
    size_t left_res = bt_remove_leaves_eq(tree->left, taboo);
    if (left_leaf && left_res > 0) tree->left = NULL;
    size_t right_res = bt_remove_leaves_eq(tree->right, taboo);
    if (right_leaf && right_res > 0) tree->right = NULL;
    return left_res + right_res;
  }
}

void bt_free(int_bt_t* tree) {
  if (tree == NULL) return;

  bt_free(tree->left);
  bt_free(tree->right);

  bt_free_leaf(tree);
}

void bt_print(int_bt_t* tree) {
  if (tree == NULL) printf("()");
  else if (bt_is_leaf(tree)) printf("(%d)", tree->value);
  else {
    printf("(");
    bt_print(tree->left);
    printf(" %d ", tree->value);
    bt_print(tree->right);
    printf(")");
  }
}

void bt_println(int_bt_t* tree) {
  if (tree == NULL) printf("()\n");
  else if (bt_is_leaf(tree)) printf("(%d)\n", tree->value);
  else {
    printf("(");
    bt_print(tree->left);
    printf(" %d ", tree->value);
    bt_print(tree->right);
    printf(")\n");
  }
}
