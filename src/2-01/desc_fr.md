# Écrire un algorithme permettant de calculer la valeur moyenne d'une séquence de valeurs réelles

## Étape 1: définitions

- `u_n`, la séquence de valeurs réelles d'entrée, finie
- `N`, le nombre d'éléments dans `u_n`
- `S`, la somme des `N` premiers éléments de `u_n`
- `M = S / N`, la valeur moyenne de `u_n`

## Étape 2: définition récursive

Soit `S_n` la somme des `n` premiers termes de `u_n`:

- `S_0 = 0`
- `S_n = S_(n-1) + u_n`

Ainsi, `M = S_N / N`.

## Étape 3: algorithme

```
Soit N <- 0
Soit S <- 0

Tant que le stream d'entrée n'est pas fini:
    Entrer u
    S <- S + u
    N <- N + 1

Retourner S / N
```
