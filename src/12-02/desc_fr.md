# Trier une list chaînée en utilisant un arbre binaire de recherche

## Étape 1: Définitions

- `tree`: l'arbre binaire de recherche intermédiaire
- `input`: une liste chaînée de nombres
- `output`: la liste chaînée correspondant à `input`; triée

## Étape 2: Algorithme

```
Entrer(input)
tree <- []
output <- []

Tant que !is_empty(input):
    insérer(tree, valeur(input))

Déf récursif(noeud):
    Si !est_vide(noeud):
        récursif(gauche(noeud))
        pousser(output, valeur(noeud))
        récursif(droite(noeud))

récursif(tree)
```

Altérnativement, nous pouvons écrire `récursif` de manière fonctionnelle:

```
Entrer(input)
tree <- []
output <- []

Tant que !is_empty(input):
    insérer(tree, valeur(input))

Déf récursif(noeud):
    Si est_vide(noeud):
        Retourner []
    Sinon:
        résultat <- récursif(gauche(noeud))
        pousser(résultat, valeur(noeud))
        concat(résultat, récursif(droite(noeud)))
        Retourner résultat

output <- récursif(tree)
```
