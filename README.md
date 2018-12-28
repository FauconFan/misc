# PF5_Mondrian

Ce projet vous est proposé par Joseph Priou et Xavier Durand.

Le projet consiste à coder un jeu dont le but est de résoudre un puzzle de Mondrian.

Nous allons vous présenter tout ce dont vous allez avoir besoin pour pouvoir utiliser ce programme.

## Compilation et exécution

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

## Fonctionnalités

Nous allons ici faire la liste des fonctionnalités du jeu.

### Graphique

Comme vous pouvez le voir lors du lancement de notre programme, nous avons créé une sorte de template ocaml en objet permettant de faire les différents composants graphiques suivants :
- des boutons engendrant des actions sur la vue et sur le model
- un background
- des curseurs
- des zones d'affichage de text qui peuvent être centré ou non
- des popups
- une zone d'affichage du bsp

Ensuite, tous ces composants sont ensuite reliés à l'aide d'une couche. Et on assemble ensute plusieurs couches pour former une page graphique.

### Model
Dans le model, nous avons généré un bsp correspondant au puzzle du mondrian, suivant une loi de probabilité modulable par l'utilisateur (dans les paramètres de l'interface graphique) pour la génération des rectangles.
De plus, on a aussi défini une taille minimale des rectangles générés, qui est aussi modulable par l'utilisateur.
Ensuite, on a implémenté une fonctionnalité permettant de résoudre le puzzle à l'aide d'un sat solver fourni par l'université. La partie compliquée a été de transformer un bsp avec des restrictions dues aux couleurs des lignes en une forme normale conjonctive, et tout cela de façon optimale. Dans le cas présent, il se peut que le programme puisse résoudre le puzzle lorsque la profondeur du bsp est de 10, mais on a un gros risque de dépassement de la mémoire.
Enfin, je vous laisse découvrir tout le jeu à l'aide de notre interface graphique.
