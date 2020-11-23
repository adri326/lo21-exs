# Algorithme testant l'égalité de deux arbres binaires

Nous vérifions que `arbre_a === arbre_b` (ceci ignore ainsi les arbres différents de structure mais correspondant à une même liste triée).

## Étape 1: Définitions

- `arbre_a` et `arbre_b`, les deux arbres à comparer
- `noeud_a` et `noeud_b`, un noeud de respectivement `arbre_a` ou `arbre_b`

Pour chaque noeud, nous vérifions que:

- `valeur(noeud_a) == valeur(noeud_b)`
- `est_vide(noeud_a) == est_vide(noeud_b)`
- `gauche(noeud_a) === gauche(noeud_b)`
- `droite(noeud_a) === droite(noeud_b)`

## Étape 2: Algorithme

```
Déf abr_eq(noeud_a, noeud_b): bool
    Si est_vide(noeud_a) || est_vide(noeud_b):
        Retourner est_vide(noeud_a) == est_vide(noeud_b)
    Sinon:
        Retourner
            valeur(noeud_a) == valeur(noeud_b)
            ET abr_eq(gauche(noeud_a), gauche(noeud_b))
            ET abr_eq(droite(noeud_a), droite(noeud_b))
    Fin Si
```
