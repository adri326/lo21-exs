# Write a recursive function that returns the length of a list

## Step 1: Definitions

We shall use a linked list of integers for the C implementation.

- `T`, the type of the elements within the list
- `is_empty(list)`, returns `true` if `list` is empty, returns `false` otherwise
- `pop_head(list)`, returns the `list` without its first element

## Step 2: Algorithm

```rs
Def list_length_rec(list: List(T)) -> Int:
    If is_empty(list) then
        Return 0
    Else
        Return 1 + list_length_rec(pop_head(list))
    End If
```
