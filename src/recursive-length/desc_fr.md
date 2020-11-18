# Écrire une fonction récursive retournant la longueur d'une liste

## Étape 1: Définitions

Nous utiliserons une liste chaînée d'entiers lors de l'implémentation C.

- `T`, le type des éléments dans la liste
- `vide(liste)`, retourne `true` si `liste` est vide, retourne `false` autrement
- `reste(liste)`, retourne `liste` privée de son premier élément

### 1a. Paramétrage du (sous-)problème

```rs
list_length_rec(liste: Liste(T)) -> Entier
```

### 1b. Identifier le cas trivial

```rs
list_length_rec([]) = 0
```

### 1c. Trouver la relation de récurrence

Si la liste n'est pas vide, nous pouvons la réduire en utilisant `reste`

```rs
list_length_rec([a, b, ..., ω]) = 1 + list_length_rec([b, c, ..., ω])
```

## Étape 2: Algorithme

```rs
Def list_length_rec(liste: Liste(T)) -> Entier:
    Si vide(liste) alors
        Retourner 0
    Sinon
        Retourner 1 + list_length_rec(reste(liste))
    Fin Si
```
