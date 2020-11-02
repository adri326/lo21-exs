# Merge two sorted lists

## Step 1: Definitions

- `A`, `B`, the two sorted input lists of ordered elements in ascending order (`A₀ ≤ A₁ ≤ ... ≤ An`, same with `B`)
- `res`, the result list
- `is_empty(list)`, returns whether or not `list` is empty
- `get_head(list)`, returns the first element of `list`
- `pop_head(list)`, returns `list`, minus its first element
- `push_tail(list, element)`, returns `list`, with `element` added at its end

## Step 2: Algorithm

```py
Input A
Input B
res <- []

While !is_empty(A) or !is_empty(B):
    if !is_empty(A) && !is_empty(B):
        if get_head(A) > get_head(B):
            res <- push_tail(res, get_head(B))
            B <- pop_head(B)
        else:
            res <- push_tail(res, get_head(A))
            A <- pop_head(A)
    else if is_empty(A):
        res <- push_tail(res, get_head(B))
        B <- pop_head(B)
    else:
        res <- push_tail(res, get_head(A))
        A <- pop_head(A)

Return res
```
