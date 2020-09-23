// Set of macros to make it easier to write the different algorithms

#ifndef MACROS_H
#define MACROS_H

#include <stdio.h>

// The maximum line length that `INPUT(...)` accepts
#define INPUT_MAX_LEN 1024

/** Error-checking user input
    Executes `prompt` every time the user is asked to enter the different values.
    `err_prompt` will also be executed after the first, failed attempt.

    @param prompt - the expression to run before accepting user input
    @param err_prompt - the expression to run after an invalid input
    @param n_args - the number of
    @throw 2 if the input stream ends

    ## Example

    ```
    int favorite_number = 0;
    INPUT(
        printf("Please enter your favorite number: "),
        printf("This isn't a number!\n"),
        1,
        "%d",
        &favorite_number
    );
    ```
**/
#define INPUT(prompt, err_prompt, n_args, ...) { \
    prompt; \
    while (1) { \
        int m_res; \
        char* f_res; \
        char raw_str[INPUT_MAX_LEN + 1]; \
        f_res = fgets(raw_str, INPUT_MAX_LEN, stdin); \
        if (f_res == NULL || feof(stdin)) exit(2); \
        m_res = sscanf(raw_str, __VA_ARGS__); \
        if (m_res == n_args) { \
            break; \
        } else { \
            err_prompt; \
            prompt; \
        } \
    } \
};

// Assertions

/** Basic assertion, exits with code 1 is the condition was not met and prints an error generated using the contents of `cond`.

    @param cond - The condition of the assertion; throws iff this condition yields false
    @param printf_args... - The arguments passed to printf
**/
#define ASSERT(cond) {if (!(cond)) {fprintf(stderr, "Assertion error: the requirement '" #cond "' was not met\n"); exit(1);}}

/** Assertion with a custom message; exits with code `code` and passes the remaining arguments to printf

    @param cond - The condition of the assertion; throws iff this condition yields false
    @param code - The exit code passed to `exit(...)`
    @param printf_args... - The arguments passed to printf
**/
#define ASSERT_MSG(cond, code, ...) {if (!(cond)) {fprintf(stderr, "Assertion error: "); fprintf(stderr, __VA_ARGS__); exit(code);}}

#endif
