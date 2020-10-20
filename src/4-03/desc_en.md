# Write an algorithm that merges two sorted arrays into a third, sorted array

## Step 1: Definition

- `left`, the first input array (sorted, integers)
- `right`, the second input array (sorted, integers)
- `length(arr)`, the length of an array `arr`
- `merged`, the merged, output array (sorted, integers)
- `i`, `j` the iterators over both `left` and `right`

## Step 2: Algorithm (using arrays)

```
read(left)
read(right)
merged <- []
i <- 0
j <- 0

while i < length(left) or j < length(right):
    if i < length(left) and (j = length(right) or left[i] <= right[j]):
        merged[length(merged)] <- left[i]
        i <- i + 1
    else:
        merged[length(merged)] <- right[j]
        j <- j + 1

print(merged)
```

## Step 3: Algorithm (using lists)

```
read(left)
read(right)
merged <- []

while !is_empty(left) or !is_empty(right):
    if !is_empty(left) and (is_empty(right) or head(left) <= head(right)):
        push(merged, head(left))
        left <- rest(left)
    else:
        push(merged, head(right))
        right <- rest(right)
```
