## Interfaces

### Labyrinthe

#### Attributs
* private Player player
* private int portee_vue
* CaseSpec[]
* TraitWall[]

#### Main Labyrinthe
* RectLabyrinthe getAdaptedLabyrinthe()
* private boolean canMove(int dx, int dyi)
* Labyrinthe(Path p)
* Labyrinthe(Algo algo)
* boolean movePlayer(int dx, int dy)

### RectLabyrinthe


### Player
#### Attributs
* float Hitbox
* float posX
* float posY

### TraitWall
#### Attributs
* int epaisseur
