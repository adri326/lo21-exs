# lo21-exs

Exercises for "LO21" (algorithmics and programmation)

## Installation

Clone this repository:

```sh
git clone https://github.com/adri326/lo21-exs
cd lo21-exs
```

Then build the project:

```sh
mkdir build && cd build
cmake ..
make -j
```

## Notes and initial definitions

Following are initial definitions of algorithmical syntaxes used throughout this repository:

### Operators

- `!=`, "not equal to", infix, commutative
- `a..b`, iterates over `[a; b)`
- `::`, references structure fields (eg. `int_ll::next`); note that this is different from field accessing (`.`)
- `.`, field accessing, infix (eg. `my_linkedlist.next`); works with both plain structures and structure pointers
- `++`, list concatenation, infix, transitive
- `%`, modulo (eg. `5 % 2 = 1`)

### Expression groups

For ease of writing, a more complex expression may be split into a set of instructions, followed by a return statement, which will yield the result of that return statement.
Such a splitting is enclosed within curly brackets `{}`:

```py
x <- (a % 3) * 4 - 2 * max(b, 3)
```

is equivalent to:

```py
x <- {
    res_a <- a % 3
    res_a <- res * 4
    res_b <- max(b, 3)
    return res_a - 2 * res_b
}
```

### Structure allocation

The following syntax will be used to describe structure allocation and field attribution:

```
type {
    key_1: value_1,
    key_2: value_2,
    // ...
    key_n: value_n
}
```

Such a construct is equivalent to the following set of instructions:

```
{
    res <- allocate(type)
    res.key_1 = value_1
    res.key_2 = value_2
    // ...
    res.key_n = value_n
    return res
}
```
