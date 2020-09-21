# [EN] Integral approximation using the trapezium method (`ʃa->b (dx/x)`)

## Step 1:

- a: lower integral bound
- b: higher integral bound
- n: number of steps
- h: integration step; h = (b - a) / n
- x<sub>i</sub>: value of x at the i-th step; x<sub>i</sub> = a + h * i
- I: integral value

A trapezium's surface is given by the following equation: S = h * (a + b) / 2

In our case, each trapezium has as surface: S<sub>i</sub> = h * (f(x<sub>i</sub>) + f(x<sub>(i+1)</sub>)) / 2

## Step 2:

I = Σ(i = 0..(n-1); S<sub>i</sub>)

Let I<sub>i</sub> be the sum of the i-th first elements of (S<sub>n</sub>):

I<sub>0</sub> = 0
I<sub>(i+1)</sub> = I<sub>i</sub> + S<sub>i</sub> = I<sub>i</sub> + h * (f(x<sub>i</sub>) + f(x<sub>(i+1)</sub>)) / 2

## Step 3:

```
Result: I
Data: f, a, b, n

Assert(a <= b)
Assert(n > 0)
Assert(a * b > 0)

I <- 0
h <- (b - a) / n

for i in 0..(n-1):
    I <- I + h * (f(a + i * h) + f(a + (i + 1) * h)) / 2

print I
```
