# Écrire un algorithme permettant d'insérer un entier dans une liste triée d'entiers, de sorte que la liste soit toujours triée

## Étape 1: définitions

- `L = (L₀, L₁, ..., L_n)`, la liste triée d'entiers d'entrée (`∀x∈[0; n-1], L_x < L_(x+1)`)
- `N`, la longueur de `L`
- `y`, la valeur à insérer
- `++`, l'opérateur "join" sur les listes (infix, transitif)
- `R`, la liste à retourner, ayant la valeur `N` insérée

## Étape 2: définition récursive

Soit `insert(N, l)` la fonction qui tente d'insérer `N` au début de `l` si celui-ci est plus petit que le premier terme de `l`, et qui sinon retourne `[l[0]] ++ insert(N, l[1..])`:

- `insert(N, []) = [N]`
- `insert(N, l) = ([N] ++ l) si l[0] ≥ N; ([l[0]] ++ insert(N, l[1..])) sinon`
- `R = insert(y, L)`

## Étape 3: algorithme

```
Soit insert <- λy -> (λl -> (
    Si l[0] >= y:
        Retourner [y] ++ l
    Sinon:
        Retourner [l[0]] ++ insert(y, l[1..])
))

Soit N <- 0
Soit L <- []

Tant que le stream d'entrée n'est pas fini:
    Entrer L[N]
    Si N > 0:
        Assertion(L[N] > L[N - 1])
    N <- N + 1

Entrer y
Retourner insert(y, L)
```
