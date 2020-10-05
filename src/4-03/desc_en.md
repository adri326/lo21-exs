# Write an algorithm that merges two sorted arrays into a third, sorted array

## Step 1: Definition

- `left`, the first input array (sorted, integers)
- `right`, the second input array (sorted, integers)
- `length(arr)`, the length of an array `arr`
- `merged`, the merged, output array (sorted, integers)
- `i`, `j` the iterators over both `left` and `right`

## Step 2: Algorithm

```
read(left)
read(right)
merged <- []
i <- 0
j <- 0

while i < length(left) || j < length(right):
    if i < length(left) and (j = length(right) or left[i] <= right[j]):
        merged[length(merged)] <- left[i]
        i <- i + 1
    else:
        merged[length(merged)] <- right[j]
        j <- j + 1

print(merged)
```
