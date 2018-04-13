# Labyrinthe 3d

Voici le Readme

## Commentaires pour le développement
### Mettre en place le hook

Le hook lance pour l'instant `make clean`, `make norm` et `make doc`. Il est exécuté à chaque `git commit`. Pour le désactiver, utiliser l'option `-n` avec `git commit`

```bash
chmod +x scripts/pre-commit-hook
cd .git/hooks
ln -sf ../../scripts/pre-commit-hook pre-commit
cd ../..

```

### GSON
Penser à lancer au moins une fois `make dep` afin de télécharger la dépendance
