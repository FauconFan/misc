package src.model;

import java.lang.StringBuffer;

import src.model.gen.Algo;
import src.utils.StringManipulation;

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
		subLabyrinthes = null;
		name           = "";
		p         = null;
		porteeVue = 0;
	}

	public MainLabyrinthe(Algo algo, int porteeVueP)
	{
		subLabyrinthes = algo.buildSubLabyrinthe();
		name           = "";
		p         = null;
		porteeVue = porteeVueP;
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

	/**
	 * The obvious overwrited toString function
	 * @return representation String
	 */
	@Override
	public String toString()
	{
		StringBuffer bf = new StringBuffer();

		bf.append("Describing Labyrinthe\n");
		bf.append("name = " + this.name + "\n");
		bf.append("player = " + this.p + "\n");
		bf.append("porteeVue = " + this.porteeVue + "\n");
		bf.append("\n");
		bf.append("nb subLabyrinthes : " + this.subLabyrinthes.length + "\n");
		for (int i = 0; i < this.subLabyrinthes.length; i++)
		{
			if (this.subLabyrinthes[i] == null)
			{
				bf.append(StringManipulation.makeTabsProperly("subLabyrinthes index[" + i + "] is null\n"));
			}
			else
			{
				bf.append(StringManipulation.makeTabsProperly("Describing subLabyrinthesShift[" + i + "] :\n"));
				bf.append(StringManipulation.makeTabsProperly(this.subLabyrinthes[i].toString()));
			}
			if (i != this.subLabyrinthes.length - 1)
			{
				bf.append("\n");
			}
		}
		return (bf.toString());
	}
}
