// Set of macros to make it easier to write the different algorithms

#ifndef MACROS_H
#define MACROS_H

#include <stdio.h>
#include <stdlib.h>

// Error-checking input
#define INPUT(prompt, err_prompt, n_args, ...) { \
    int m_res; \
    prompt; \
    while ((m_res = scanf(__VA_ARGS__)) != n_args) { \
        if (m_res == EOF) { \
            exit(2); \
        } \
        scanf("%*[^\n]"); \
        err_prompt; \
        prompt; \
    } \
};

// Assertions
#define ASSERT(cond) {if (!(cond)) {printf("Assertion error: the requirement '" #cond "' was not met\n"); exit(1);}}
#define ASSERT_MSG(cond, ...) {if (!(cond)) {printf("Assertion error: "); printf(__VA_ARGS__); exit(1);}}

#endif
