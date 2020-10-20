# Distance de Hamming entre deux mots

## Étape 1: Définitions

- `length`, entier, la longueur des deux chaînes de caractères
- `left` et `right`, les deux chaînes de caractères, toutes deux de longueur `length`

La distance de Hamming correspond au nombre d'éléments qui diffèrent entre les deux listes d'entrées.

## Étape 2: Algorithme

```
hamming_distance(length: entier, left: char[entier], right: char[entier]): entier
```

```py
Fonction hamming_distance(length, left, right):
    assert(length(left) == length)
    assert(length(right) == length)
    result <- 0

    Pour i allant de 0 à length-1 faire
        Si left[i] != right[i] alors
            result <- result + 1
        Fin Si
    Fin Pour

    Retourner result
```
