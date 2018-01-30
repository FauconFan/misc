## Interfaces

### Controller
* getter/setter params

### Labyrinthe

#### Attributs
* private Player player
* private int porteeVue

#### Fonctions
* RectLabyrinthe getAdaptedLabyrinthe()
* private boolean canMove(int dx, int dyi)
* Labyrinthe(Path p)
* Labyrinthe(Algo algo)
* boolean movePlayer(int dx, int dy)

### Gen Maze
* void algo.build();
* LineWall[] algo.getWalls();
* Case[] algo.getSpecialCase();

### RectLabyrinthe
#### Fonctions
* CasesSpec[]
* LineWall[]

### Player
#### Attributs
* float hitBoxWidth
* float hitBoxLength
* float posX
* float posY

### LineWall
#### Attributs
* float epaisseur
