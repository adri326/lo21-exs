# Écrire un algorithme permettant de trier une liste d'entiers quelconques

## Étape 1: définitions

- `L = (L₀, L₁, ..., L_n)`, la liste d'entrée d'entiers quelconques
- `R = (R₀, R₁, ..., R_n)`, la liste de sortie d'entiers triés; `∀i∈[0; n], R[i] ∈ L && L[i] ∈ R` et `∀i∈[0; n-1], R[i] < R[i+1]`
- `++`, l'opérateur "join" sur les listes (infix, transitif)
- `[]`, la liste vide

## Étape 2: définitions récursives

### `qs_split`

Soit `qs_split(L, p)` la fonction qui prend comme entrée une liste `L` ayant `n` éléments et un pivot `p ∈ [0; n - 1]`, qui retourne la liste des éléments inférieurs ou égaux à `L[p]` (en excluant `L[p]`) et la liste des éléments strictement supérieurs à `L[p]` (en excluant `L[p]`):

- `qs_split([], p) = ([], [])`
- `qs_split(L, p) = ([L_i | i ∈ [0, n], i ≠ p et L_i ≤ L_p], [L_i | i ∈ [0, n], i ≠ p et L_i ≥ L_p])`

```
qs_split(L, p):
    Si taille(L) = 0:
        Retourner ([], [])
    Sinon:
        Soit lhs <- [] // left-hand side
        Soit rhs <- [] // right-hand side
        Pour i de 0 à taille(L) - 1:
            Si i ≠ p:
                Si L[i] > L[p]:
                    rhs <- rhs ++ [L[i]]
                Sinon:
                    lhs <- lhs ++ [L[i]]
        Retourner (lhs, rhs)
```

### `quicksort`

Soit `quicksort(L)` la fonction qui retourne la liste triée correspondant à `L` en utilisant la méthode quicksort:

```
quicksort(L):
    Si taille(L) = 0:
        Retourner []
    Sinon:
        Soit n <- nombre aléatoire de 0 à taille(L) - 1
        Soit (lhs, rhs) <- quicksort
        Retourner quicksort(lhs) ++ [L[n]] ++ quicksort(rhs)
```

## Étape 3: algorithme final

```
Entrer N
Soit L <- []

Pour n de 0 à N-1:
    Entrer L[n]

Retourner quicksort(L)
```
