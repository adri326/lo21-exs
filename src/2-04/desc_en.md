# Write an algorithm that sorts any unsorted integer list

## Step 1: definitions

- `L = (L₀, L₁, ..., L_n)`, the input integer list
- `R = (R₀, R₁, ..., R_n)`, the output, sorted list; `∀i∈[0; n], R[i] ∈ L && L[i] ∈ R` et `∀i∈[0; n-1], R[i] < R[i+1]`
- `++`, the list "join" operator (infix, transitive)
- `[]`, empty list

## Step 2: recursive definitions

### `qs_split`

Let `qs_split(L, p)` be the function that takes as input a list `L` with `n` elements and a "pivot point" `p ∈ [0; n - 1]` and that returns the list of the values of `L` that are lower or equal to `L[p]` and the list of the values of `L` that are strictly greater than `L[p]` (both excluding `L[p]` itself).

- `qs_split([], p) = ([], [])`
- `qs_split(L, p) = ([L_i | i ∈ [0, n], i ≠ p et L_i ≤ L_p], [L_i | i ∈ [0, n], i ≠ p et L_i ≥ L_p])`

```
qs_split(L, p):
    If length(L) = 0:
        Return ([], [])
    Else:
        Let lhs <- [] // left-hand side
        Let rhs <- [] // right-hand side
        For i in 0..length(L):
            If i ≠ p:
                If L[i] > L[p]:
                    rhs <- rhs ++ [L[i]]
                Else:
                    lhs <- lhs ++ [L[i]]
        Return (lhs, rhs)
```

### `quicksort`

Let `quicksort(L)` be the function that returns the sorted list corresponding to `L` using the quicksort method:

```
quicksort(L):
    If length(L) = 0:
        Return []
    Else:
        Let n <- random number from 0 to length(L) - 1
        Let (lhs, rhs) <- quicksort
        Return quicksort(lhs) ++ [L[n]] ++ quicksort(rhs)
```

## Step 3: final algorithm

```
Input N
Let L <- []

For n in 0..N:
    Input L[n]

Return quicksort(L)
```
