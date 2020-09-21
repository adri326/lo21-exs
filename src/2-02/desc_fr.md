# Écrire un algorithme permettant de calculer l'écart-type d'une séquence de valeurs réelles

## Étape 1: définitions

- `u_n`, la séquence de valeurs réelles d'entrée
- `N`, la longueur de cette séquence
- `M`, la moyenne des `N` premiers termes de `u_n` (cf. ex 2-01)
- `e_n = u_n - M`, l'écart de `u_n`
- `R`, l'écart-type de `u_n`

## Étape 2: définition récursive

Soit `E_n` la somme des `n` premiers termes mis au carré de `e_n`:

- `E_0 = 0`
- `E_n = E_(n-1) + (e_n)² = E_(n-1) + (u_n - M)²`
- `R = √((E_N) / N)`

## Étape 3: algorithme

```
Soit N <- 0
Soit S <- 0
Soit u <- []

Tant que le stream d'entrée n'est pas fini:
    Entrer u[N]
    S <- S + u
    N <- N + 1

Soit M <- S / N
Soit E <- 0

Pour n dans 0..N:
    E <- E + (u[N] - M)²

Retourner sqrt(E / N)
```
