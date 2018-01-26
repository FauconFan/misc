## Interfaces

### Controller
* getter/setter params

### Labyrinthe

#### Attributs
* private Player player
* private int portee_vue

#### Fonctions
* RectLabyrinthe getAdaptedLabyrinthe()
* private boolean canMove(int dx, int dyi)
* Labyrinthe(Path p)
* Labyrinthe(Algo algo)
* boolean movePlayer(int dx, int dy)

### RectLabyrinthe
#### Fonctions
* CasesSpec[]
* LineWall[]

### Player
#### Attributs
* float Hitbox
* float posX
* float posY

### LineWall
#### Attributs
* int epaisseur
