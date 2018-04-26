# Labyrinthe 3d

Voici le Readme

## Compilation
Pour tous les systèmes unix,
```Shell
make dep && make && make run
```

## Menus

## Jeu

En jeu, vous pouvez appuyer sur les touches suivantes:

### Dans tous les modes

* Échap pour mettre le jeu en pause
* Z pour avancer
* Q pour aller à gauche
* S pour reculer
* D pour aller à droite
* ← ↑ → ↓ pour orienter la caméra
* CTRL +
  * G pour passer en "GhostMode", qui affiche une carte de l'étage courant et désactive les collisions
  * T pour faire disparaitre les murs

### En mode normal

* Space pour sauter

### En FlyMode

* R pour monter
* F pour descendre

## Creator

### Panneau droit

Vous pouvez ajouter des murs en cliquant sur les cercles noirs. Un premier clic "active" un croisement. Faites un autre clic sur un embranchement sur la même ligne et la même colonne, un mur apparait.
Vous pouvez ajouter des cases spéciales en cliquant sur les rectangles. Re-cliquer pour en changer. *Notez que chaque labyrinthe doit avoir au moins une case de départ et une case d'arrivée*

#### Contrôles au clavier

* Échap pour revenir au menu principal
* Z pour avancer
* Q pour aller à gauche
* S pour reculer
* D pour aller à droite
* F pour dézoomer
* R pour zoomer

### Panneau gauche

* Appuyez sur "finish" pour lancer le jeu avec le labyrinthe que vous venez de créer.

* Add/Remove pour supprimer le niveau courrant.

* Par étage, cliquez sur une texture pour la définir pour l'étage. Si une texture n'est pas définie, celle par défaut sera utilisée.

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
