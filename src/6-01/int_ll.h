#ifndef INT_LL_H
#define INT_LL_H

#include <stdlib.h>
#include <stdbool.h>

struct int_ll {
    int value;
    struct int_ll* next;
};
typedef struct int_ll int_ll_t;

/** Returns whether or not the list is empty (is equal to NULL)
    @param list - The list whose emptiness is to check
    @returns `list == NULL`
**/
bool is_empty(const int_ll_t* list);

/** Returns the last element of the linked list; no loop detection is done
    @param list - The list to retrieve the last element from
    @throw Asserts that list is not empty
    @returns The last element of list (not null)
**/
int_ll_t* get_tail(int_ll_t* list);

/** Prepends `element` to `list`
    @param list - The list to prepend to
    @param element - The element to prepend
    @returns The prepended list (a new list if `list` was empty)
**/
int_ll_t* insert_head(int_ll_t* list, int element);

/** Appends `element` to `list`; no loop detection is done
    @param list - The list to append to
    @param element - The element to append
    @returns The appended list (a new list if `list` was empty)
**/
int_ll_t* insert_tail(int_ll_t* list, int element);

/** Removes the head of `list`
    @param list - The list to remove the head from
    @returns The new, popped list (null if empty)
**/
int_ll_t* remove_head(int_ll_t* list);

/** Removes the tail of `list`; no loop detection is done
    @param list - The list to remove the tail from
    @returns The new, popped list (null if empty)
**/
int_ll_t* remove_tail(int_ll_t* list);

/** Prints out a list's contents; no loop detection is done
    @param list - The list to print
**/
void print_list(const int_ll_t* list);

#endif // INT_LL_H
