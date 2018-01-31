package src.model;

import java.io.Serializable;
import src.model.gen.Algo;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;
import src.model.parser.Parser;
import src.utils.StringManipulation;

/**
 * Structure de données du labyrinthe.
 */
public class MainMaze implements Serializable
{
	private ContentMaze m;
	private String name;
	private Player p;
	private int porteeVue;


	public MainMaze(ContentMaze m, String name, Player p, int porteeVue)
	{
		this.m         = m;
		this.name      = name;
		this.p         = p;
		this.porteeVue = porteeVue;
	}

	public MainMaze(Algo algo, int porteeVueP)
	{
		this.m         = algo.getContentMaze();
		this.name      = "";
		this.p         = null;
		this.porteeVue = porteeVueP;
	}

	/**
	 * Retourne un RectMaze centré sur la position du joueur de dimension porteeVue x porteeVue.
	 * @return RectMaze centré sur le joueur.
	 */
	public RectMaze getAdaptedMaze()
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
		String str = "Describing Maze\n";

		str += "name = " + this.name + "\n";
		str += "player = " + this.p + "\n";
		str += "porteeVue = " + this.porteeVue + "\n";
		str += "\n";
		str += "labyrinthe :\n";
		if (m != null)
		{
			str += m.toString();
		}
		return (str);
	}
}
