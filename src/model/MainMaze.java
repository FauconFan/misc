package src.model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Vector;
import src.model.board.LineWall;
import src.model.gen.Algo;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;
import src.model.parser.Parser;
import src.utils.DisplayMazeConsole;
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
		this(algo.getContentMaze(), "", null, porteeVueP);
	}

	/**
	 * Retourne un RectMaze centré sur la position du joueur de dimension porteeVue x porteeVue.
	 * @return RectMaze centré sur le joueur.
	 */
	public ContentMaze getAdaptedMaze()
	{
		return (this.m);
	}

	public Vector <Float> calculateDep(Vector <Float> v)
	{
		/*for (LineWall lw : m.getLineWalls())
		 * {
		 *  if (lw.isHorizontal()){
		 *      if (lw.pointInWall(p.getPosX() + (lw.getY1() - p.getPosX())/v.get(1) * v.get(0), lw.getY1())){
		 *          Vector <Float> newDep = new Vector<Float>();
		 *          newDep.add(p.getPosX() + v.get(0));
		 *          newDep.add(lw.getY1());
		 *              return calculateDep (newDep);
		 *          }
		 *  }
		 *  else
		 *  {
		 *      if (lw.pointInWall(lw.getY0(), p.getPosY() + (lw.getX1() - p.getPosX())/v.get(0) * v.get(1))){
		 *          Vector <Float> newDep = new Vector<Float>();
		 *          newDep.add(lw.getX1());
		 *          newDep.add(p.getPosY() + v.get(1));
		 *          return calculateDep (newDep);
		 *      }
		 *  }
		 * }*/
		return (null);
	}

	/**
	 * Déplace le joueur dans le labyrinthe depuis sa position (x,y) vers (x+dx,y+dy) si c'est possible.
	 * @param dx Le deplacement horizontal du joueur.
	 * @param dy Le deplacement vertical du joueur.
	 * @return true si le joueur a pu se déplacer
	 */
	public void movePlayer(float dx, float dy)
	{
		/*
		 * Vector<Float> d = new Vector<Float>();
		 * d.add(dx);
		 * d.add(dy);
		 * d = calculateDep(d);
		 * p.setPosX(p.getPosX() + d.get(0));
		 * p.setPosY(p.getPosY() + d.get(1));
		 */
	}

	/**
	 * Affiche le labyrinthe dans la console
	 */
	public void displayMaze(boolean reverse)
	{
		DisplayMazeConsole.displayMaze(m, reverse);
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
