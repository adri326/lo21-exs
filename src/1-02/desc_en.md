# Given `P ∈ ℝ[X]`, `x ∈ ℝ`, calculate `P(x)`

## 1. Definitions

- `P(X)`, a polynome in the form of `P(X) = a₀ + a₁*X + a₂*X² + ...`
- `a`, the sequence of the polynomial terms of `P(X)`
- `l`, the smallest integer for which ∀n>l, `a_n = 0`
- `x ∈ ℝ`, the input value for the polynome
- `R = P(x)`, the output value for the polynome - its value at `x`

## 2. Recursive definition

Let `q_n = a_n*x^n`; `p_k = Σ(n = 0 -> k; q_n)`:

- `P(x) = p_l`
- `p_0 = 0`
- `p_n = p_(n-1) + q_n = p_n + a_n*x^n`

To avoid exponentiation for every step, we multiply a variable `y` at each iteration by `x`:

- `y_0 = 1`
- `y_n = y_(n-1) * x`
- `p_n = p_(n-1) + a_n*y_n`

## 3. Algorithm

```
Input l
For n in 0..l:
    Input a_n
Input x

Let R <- 0
Let y <- 1
For n in 0..=l:
    R <- R + a_n*y
    y <- y * x

Return R
```
