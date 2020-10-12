#include "int_ll.h"
#include <stdio.h>
#include "../macros.h"

bool is_empty(const int_ll_t* list) {
    return list == NULL;
}

int_ll_t* get_tail(int_ll_t* list) {
    ASSERT(list != NULL);
    while (list->next != NULL) list = list->next;
    return list;
}

int_ll_t* insert_head(int_ll_t* list, int element) {
    int_ll_t* new_list = (int_ll_t*)malloc(sizeof(struct int_ll));
    new_list->value = element;
    new_list->next = list;
    return new_list;
}

int_ll_t* insert_tail(int_ll_t* list, int element) {
    int_ll_t* new_element = (int_ll_t*)malloc(sizeof(struct int_ll));
    new_element->value = element;
    new_element->next = NULL; // technically not necessary
    if (list == NULL) {
        return new_element;
    } else {
        int_ll_t* tail = get_tail(list);
        tail->next = new_element;
        return list;
    }
}

int_ll_t* remove_head(int_ll_t* list) {
    if (list == NULL) return NULL;
    int_ll_t* next = list->next;
    free(list);
    return next;
}

int_ll_t* remove_tail(int_ll_t* list) {
    if (list == NULL) return NULL;
    else if (list->next == NULL) {
        free(list);
        return NULL;
    } else {
        int_ll_t* tail = list;
        while (tail->next->next != NULL) tail = tail->next;
        free(tail->next);
        tail->next = NULL;
        return list;
    }
}

void print_list(const int_ll_t* list) {
    printf("[");
    while (list != NULL) {
        printf("%d", list->value);
        if (list->next != NULL) printf(", ");
        list = list->next;
    }
    printf("]\n");
}
