# [FR] Approximation de l'intégrale `ʃa->b (dx/x)` par méthode des trapèzes

## Étape 1:

- a: borne inférieure de l'intégrale
- b: borne supérieure de l'intégrale
- n: nombre d'étapes d'intégrations
- h: pas d'intégration; h = (b - a) / n
- x<sub>i</sub>: valeur de x à l'étape i d'intégration; x<sub>i</sub> = a + h * i
- I: valeur de l'intégrale

La surface d'un trapèze est donnée par l'équation suivante: S = h * (a + b) / 2

Dans notre cas, chaque trapèze a pour surface: S<sub>i</sub> = h * (f(x<sub>i</sub>) + f(x<sub>(i+1)</sub>)) / 2

## Étape 2:

I = Σ(i = 0..(n-1); S<sub>i</sub>)

Soit I<sub>i</sub> la somme des i premiers éléments de (S<sub>n</sub>):

I<sub>0</sub> = 0
I<sub>(i+1)</sub> = I<sub>i</sub> + S<sub>i</sub> = I<sub>i</sub> + h * (f(x<sub>i</sub>) + f(x<sub>(i+1)</sub>)) / 2

## Étape 3:

```
Résultat: I
Données: f, a, b, n

Assertion(a <= b)
Assertion(n > 0)
Assertion(a * b > 0)

I <- 0
h <- (b - a) / n

Pour i allant de 0 à (n-1):
    I <- I + h * (f(a + i * h) + f(a + (i + 1) * h)) / 2

Afficher I
```
