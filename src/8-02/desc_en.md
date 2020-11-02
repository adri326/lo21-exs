# Polynomial sum

## Step 1: Definitions

| Polynome |
| :------- |
| unsigned int order |
| float coefficient |
| Polynome next |

- `P` and `Q`, polynomes within `ℝ[x]`, represented as instances of `Polynome` and whose monomes are assumed sorted in ascending order

`∀P, Q ∈ ℝ[X], P = (pn) and Q = (qn), P + Q = (Σpn+qn)`

## Step 2: Algorithm

```py
Input P
Input Q

sum <- 0

While !is_empty(P) and !is_empty(Q):
    If head(P).order < head(Q).order:
        sum <- sum + head(P)
        P <- pop_head(P)
    Else if head(P).order > head(Q).order:
        sum <- sum + head(Q)
        Q <- pop_head(Q)
    Else:
        If head(P) + head(Q) != 0:
            sum <- sum + head(P) + head(Q)
            P <- pop_head(P)
            Q <- pop_head(Q)

While !is_empty(P):
    sum <- sum + head(P)
    P <- pop_head(P)

While !is_empty(Q):
    sum <- sum + head(Q)
    Q <- pop_head(Q)
```
