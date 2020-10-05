# Write the algorithm to test if a number is prime

## Step 1: Definitions

- `input`, the input integer

A number is prime if it cannot be divided by any other number but itself and 1.
We thus need to find a number `a` such that `∃ b, a*b = input`. In this case, we will have `a ≤ sqrt(input)` and `b ≥ sqrt(input)`.
We have the following relationship: `∃ b, a*b = input <=> input mod a = 0`

## Step 2: Algorithm

We only need to iterate from 2 to `sqrt(a)`, as any potential divider after `sqrt(a)` would have been found already.
Moreover, we do not need to look for even numbers (except for two), as is `input = (2k)*b`, then `input = 2*(k*b)`, which will be covered by the first test.

```
is_prime(input):
    if input = 2:
        return true
    if input <= 1:
        return false
    if input % 2 = 0:
        return false
    result <- true
    for n ranging from 3 to sqrt(input), step 2:
        if input % n = 0:
            result <- false
    return result
```
