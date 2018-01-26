package src.model;

/**
 * Structure de données du labyrinthe.
 */
public class MainLabyrinthe
{
	private RectLabyrintheShift [] subLabyrinthes;
	private String name;
	private Player p;
	private int porteeVue;

	public MainLabyrinthe(String path)
	{
		subLabyrinthe = null;
		name          = "";
		p             = null;
		porteeVue     = 0;
	}

	public MainLabyrinthe(/*Algo algo*/)
	{
		subLabyrinthe = null;
		name          = "";
		p             = null;
		porteeVue     = 0;
	}

	/**
	 * Retourne un RectLabyrinthe centré sur la position du joueur de dimension porteeVue x porteeVue.
	 * @return RectLabyrinthe centré sur le joueur.
	 */
	public RectLabyrinthe getAdaptedLabyrinthe()
	{
		return (null);
	}

	/**
	 * Retourne true si le joueur peut se déplacer depuis sa position (x,y) vers (x+dx, y+dy).
	 * @param dx Le deplacement horizontal du joueur.
	 * @param dy Le deplacement vertical du joueur.
	 * @return true si le joueur peut se déplacer.
	 */
	private boolean canMove(int dx, int dy)
	{
		return (false);
	}

	/**
	 * Déplace le joueur dans le labyrinthe depuis sa position (x,y) vers (x+dx,y+dy) si c'est possible.
	 * @param dx Le deplacement horizontal du joueur.
	 * @param dy Le deplacement vertical du joueur.
	 * @return true si le joueur a pu se déplacer
	 */
	public boolean movePlayer(int dx, int dy)
	{
		return (false);
	}
}
