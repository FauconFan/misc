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
	private RectMazeShift [] subMazes;
	private String name;
	private Player p;
	private int porteeVue;


	public MainMaze(RectMazeShift[] subMazes, String name, Player p, int porteeVue)
	{
		this.subMazes  = subMazes;
		this.name      = name;
		this.p         = p;
		this.porteeVue = porteeVue;
	}

	public MainMaze(Algo algo, int porteeVueP)
	{
		subMazes  = algo.buildSubMaze();
		name      = "";
		p         = null;
		porteeVue = porteeVueP;
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
		str += "nb subMazes : " + this.subMazes.length + "\n";
		for (int i = 0; i < this.subMazes.length; i++)
		{
			if (this.subMazes[i] == null)
			{
				str += StringManipulation.makeTabsProperly("subMazes index[" + i + "] is null\n");
			}
			else
			{
				str += StringManipulation.makeTabsProperly("Describing subMazesShift[" + i + "] :\n");
				str += StringManipulation.makeTabsProperly(this.subMazes[i].toString());
			}
			if (i != this.subMazes.length - 1)
			{
				str += "\n";
			}
		}
		return (str);
	}
}
