# Algorithme permettant d'insérer un entier dans un arbre de recherche

*Note: un arbre binaire de recherche (ABR) est un arbre binaire tel quel `∀node, (!est_vide(gauche(node)) => valeur(left_child(node)) ≤ node) and (!est_vide(droite(node)) => valeur(right_child(node)) ≥ node)` (la valeur d'un noeud enfant à gauche doit être inférieure à celle du noeud et inversement pour le noeud enfant à droite).*

## Étape 1: Définitions

Soit `B` un arbre binaire de recherche et soit `x` la valeur que nous souhaitons insérer dans cet arbre.

Pour chaque noeud `node`, nous avons 4 cas:

- `x < valeur(node)` et `est_vide(gauche(node))`: `x` est inséré à gauche
- `x < valeur(node)` et `!est_vide(gauche(node))`: on réitère l'opération sur `gauche(node)`
- `x ≥ valeur(node)` et `est_vide(droite(node))`: `x` est inséré à droite
- `x ≥ valeur(node)` et `!est_vide(droite(node))`: on réitère l'opération sur `droite(node)`

## Étape 2: Algorithme

```
Déf abr_insérer(B: ABR, x: nombre):
    Si est_vide(ABR) alors:
        Retourner nouveau_noeud(x)
    Sinon:
        Si x < valeur(B) alors:
            Si est_vide(gauche(B)) alors:
                gauche(B) <- nouveau_noeud(x)
            Sinon:
                abr_insérer(gauche(B), x)
            Fin Si
        Sinon:
            Si est_vide(droite(B)) alors:
                droite(B) <- nouveau_noeud(x)
            Sinon:
                abr_insérer(droite(B), x)
            Fin Si
        Fin Si
        Retourner B
    Fin Si
```

Plus simplement, nous pouvons écrire:

```
Déf abr_insérer(B: ABR, x: nombre):
    Si est_vide(ABR) alors:
        Retourner nouveau_noeud(x)
    Sinon:
        Si x < valeur(B) alors:
            gauche(B) <- abr_insérer(gauche(B), x)
        Sinon:
            droite(B) <- abr_insérer(droite(B), x)
        Fin Si
        Retourner B
    Fin Si
```
