# Labyrinthe 3d

Projet de programmation en 2ème année universitaire.  
Le projet consiste à coder un jeu de Labyrinthe en 3 dimensions. On doit pouvoir générer des labyrinthes de toute taille sur demande, ainsi que de pouvoir sauvegarder un labyrinthe dans un fichier et charger un labyrinthe depuis un fichier.

## Compilation
Pour tous les systèmes unix,
```Shell
make dep && make && make run
```

## Menus

Vous pouvez générer, créer, charger un labyrinthe ou en lancer un fait par nos soins.

### Menu de création

Vous pouvez définir la taille de votre labyrinthe, rectangulaire, ainsi que le nombre d'étage qu'il contiendra. Le joueur commence dans l'étage le plus bas, et la case d'arrivée se trouve dans l'étage le plus haut. On passe d'étage en étage grâce aux cases de saut (en bleu).
Le flyMode propose une autre expérience de jeu: il n'y a pas de sol ni de gravité et le joueur doit trouver la sortie dans ce véritable labyrinthe en 3 dimensions.

## Jeu

En jeu, vous pouvez appuyer sur les touches suivantes:

### Dans tous les modes

* Échap pour mettre le jeu en pause
* H pour avoir de l'aide
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

Vous pouvez ajouter des murs en cliquant sur les cercles noirs. Un premier clic "active" un croisement. Faites un autre clic sur un embranchement sur la même ligne ou la même colonne, un mur apparait.
Vous pouvez ajouter des cases spéciales en cliquant sur les rectangles. Re-cliquer pour en changer. *Notez que chaque labyrinthe doit avoir au moins une case de départ et une case d'arrivée*.

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

* Add pour ajouter un niveau.

* Remove pour supprimer le niveau courrant.

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
