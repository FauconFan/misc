# Labyrinthe 3d

Voici le Readme

## Mettre en place le hook

Le hook lance pour l'instant `make clean`, `make norm` et `make doc`. Il est exécuté à chaque `git commit`. Pour le désactiver, utiliser l'option `-n` avec `git commit`

```bash
cp scripts/pre-commit-hook .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit

```

## GSON
Penser à lancer au moins une fois `make dep` afin de télécharger la dépendance
