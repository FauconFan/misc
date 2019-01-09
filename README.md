# PF5_Mondrian

![Puzzle du Mondrian](https://github.com/FauconFan/PF5_Mondrian/blob/master/.github/logo.png)

Le projet consiste à coder un jeu dont le but est de résoudre un puzzle de Mondrian.

Un puzzle de mondrian consiste à colorier, avec les couleurs rouge et bleu, un plan partitionné en rectangles. Au début du jeu, tous les rectangles sont blancs, et les lignes partitionnant le plan peuvent être de couleur noire, rouge, bleu ou violet. Le joueur doit choisir une couleur de remplissage pour chaque rectangle, en respectant les contraintes suivantes. Pour chaque ligne de séparation, on considère l’ensemble des rectangles dont le bord se superpose à celle-ci :
  - Si la ligne est rouge ou bleue, cet ensemble doit contenir strictement plus de rectangles de même
couleur que la ligne, que de rectangles de l’autre couleur.
  - Si la ligne est violette, l’ensemble doit contenir autant de rectangles d’une couleur que de l’autre.
  - Si la ligne est noire, il n’y a aucune contrainte sur ces rectangles.

Nous allons vous présenter tout ce dont vous allez avoir besoin pour pouvoir utiliser ce programme.

## Compilation, exécution, installation

Pour pouvoir compiler le projet, il suffit de faire :
```
make mondrian
```
Et à ce moment là, vous allez voir apparaître dans vos fichiers le fichier `mondrian` qui est un exécutable.
Il vous suffira ensuite de lancer la commande :
```
./mondrian
```
Pour pouvoir exécuté le programme.

Vous pouvez également installer le programme à l'aide de:
```
make install
```
Ce qui fera compilera le binaire si ce n'est déjà fait et fera une copie de ce binaire dans le dossier /usr/local/bin, afin qu'il soit visible sur tout le système.

## Fonctionnalités

Nous allons ici faire la liste des fonctionnalités du jeu.

### Model

Dans le model, nous avons généré un bsp correspondant au puzzle du mondrian, suivant une loi de probabilité modulable par l'utilisateur (dans les paramètres de l'interface graphique) pour la génération des rectangles.
De plus, on a aussi défini une taille minimale des rectangles générés, qui est aussi modulable par l'utilisateur.
Ensuite, on a implémenté une fonctionnalité permettant de résoudre le puzzle à l'aide d'un sat solver. La partie compliquée a été de transformer un bsp avec des restrictions dues aux couleurs des lignes en une forme normale conjonctive, et tout cela de façon optimale. Dans le cas présent, il se peut que le programme puisse résoudre le puzzle lorsque la profondeur du bsp est de 10, mais on a un gros risque de dépassement de la mémoire.

Les fichiers FNC.ml, Bsp.ml et Check.ml, situés dans le dossier src/model, contiennent toute l'impléméntation "intéressante" de ce projet. Tous nos types et fonctions basiques pour la manipulation du bsp se situent dans Base.ml et Bsp.ml.

### Graphique

Comme vous pouvez le voir lors du lancement de notre programme, nous avons créé une sorte de template ocaml en objet permettant de faire les différents composants graphiques suivants :
- des boutons engendrant des actions sur la vue et sur le model
- un background
- des curseurs
- des zones d'affichage de text qui peuvent être centré ou non
- une zone d'affichage du bsp

Ensuite, tous ces composants sont ensuite reliés à l'aide d'une couche. Et on assemble ensute plusieurs couches pour former une page graphique.

Notre programme possède une "game loop", c'est à dire qu'elle se met à jour et réaffiche régulièrement pour maintenir un niveau de 60 FPS (frame per second). L'intérêt d'une game loop est de pouvoir contrôler l'affichage de notre programme sans attendre une interaction directe avec l'utilisateur. La librairie graphique standard de OCaml ne permettant pas de mettre en place des hooks sur événement, nous avons alors adopté cette pratique. Avoir une "game loop" nous permet aussi de rafraîchir la vue dès que la fenêtre est redimensionnée. Nous avons donc une vue dynamique en fonction de la taille actuelle de la fenêtre.

La gestion de tous nos composants sont gérés dans SLAC.ml (Scene Layer and Abstract Component), et la gestion de la "game loop" et de l'interaction avec l'utilisateur se trouve dans le fichier GraphicsManager.ml

# Auteurs

Xavier Durand et Joseph Priou.  
Ce programme a été fait au sein d'un projet pédagogique pour l'Université Paris Diderot (Paris 7).
