# Write the algorithm to replace in a sentence a sequence of more than one spaces by a single space

## Step 1: definitions

- `input`, the input string
- `L`, the length of the input string
- `output`, the output string, which will have at most the length of `input`
- `O`, the length of the output string
- `n_spaces`, a counter for how many adjacent spaces were found

We will iterate through input and add each character to output, skipping redundant spaces.

## Step 2: algorithm

```
read(input)
output <- ""
O <- 0
n_spaces <- 0

for i in 0..L:
    if input[i] = " ":
        n_spaces <- n_spaces + 1
    else:
        n_spaces <- 0
    if n_spaces <= 1:
        output[O] = input[i]
        O <- O + 1

print(output)
```
