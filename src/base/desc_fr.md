# Représenter des entiers dans une base

Les nombres seront transformés en listes de chiffres. Ces listes sont en big endian.

## Séparation des entiers

Étant donné un nombre entier n, écrire un algorithme le séparant en liste de chiffres.

### Étape 1: Définition

- `base`, entier positif supérieur à 1, la base dans laquelle nous souhaitons écrire le nombre
- `input`, le nombre entier positif en entrée
- `output`, une liste de chiffres correspondant à ceux d'input

On définit 0 comme étant représenté par une liste vide.

### Étape 2: Algorithme

```
Fonction construire(base, input):
    output <- []
    tmp <- input // as to not mutate input
    TantQue tmp > 0 faire
        ajouterTête(output, tmp % base)
        tmp = floor(tmp / base)
    Fin TantQue
    Retourner output
```

## Recombination des chiffres

Retrouver le nombre entier `n` correspondant à une liste de chiffres donnée.

### Étape 1: Définition

- `base`, entier positif supérieur à 1, la base dans laquelle nous souhaitons écrire le nombre
- `input`, une liste de chiffres
- `output`, le nombre construit à partir d'`input`

### Étape 2: Algorithme

```
Fonction déconstuire(base, input):
    output <- 0
    tmp <- input
    TantQue non(is_empty(tmp)) faire
        output = output * base + head(tmp).value
        tmp = rest(tmp)
    Fin TantQue
    Retourner output
```

## Comparaison de listes de chiffres

Écrire une fonction qui compare deux listes de chiffres.

### Étape 1: Définition

- `left` et `right`, deux liste de chiffres
- `output`, -1 si `left` est plus petit que `right`, +1 si `left` est plus grand que `right` et 0 sinon

### Étape 2: Algorithme

```
Fonction comparer(left, right):
    tmp_left <- left
    tmp_right <- right
    TantQue non(is_empty(tmp_left)) et non(is_empty(tmp_right)) faire
        Si head(tmp_left) > head(tmp_right) alors
            Retourner +1
        Sinon Si head(tmp_left) < head(tmp_right) alors
            Retourner -1
        Fin Si
    Fin TantQue

    Si is_empty(tmp_left) et non(is_empty(tmp_right)) alors
        Retourner +1
    Sinon Si non(is_empty(tmp_left)) et is_empty(tmp_right) alors
        Retourner -1
    Sinon
        Retourner 0
    Fin Si
```
