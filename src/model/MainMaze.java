package src.model;

import java.io.Serializable;
import java.util.ArrayList;
import src.model.board.LineWall;
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

	/**
	 * Constantes pour l'affichage du labyrinthe dans la console
	 */
	private static final char HORIZONTAL        = '\u2500';
	private static final char VERTICAL          = '\u2502';
	private static final char INTERSECTION      = '\u253C';
	private static final char HORIZONTALTOP     = '\u2534';
	private static final char HORIZONTALBOTTOM  = '\u252C';
	private static final char VERTICALLEFT      = '\u2524';
	private static final char VERTICALRIGHT     = '\u251C';
	private static final char CORNERTOPLEFT     = '\u2510';
	private static final char CORNERTOPRIGHT    = '\u250C';
	private static final char CORNERBOTTOMLEFT  = '\u2518';
	private static final char CORNERBOTTOMRIGHT = '\u2514';


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
	private boolean canMove(float dx, float dy)
	{
		return (false);
	}

	/**
	 * Déplace le joueur dans le labyrinthe depuis sa position (x,y) vers (x+dx,y+dy) si c'est possible.
	 * @param dx Le deplacement horizontal du joueur.
	 * @param dy Le deplacement vertical du joueur.
	 * @return true si le joueur a pu se déplacer
	 */
	public boolean movePlayer(float dx, float dy)
	{
		if (canMove(dx, dy))
		{
			p.setPosX(p.getPosX() + dx);
			p.setPosY(p.getPosY() + dy);
			return (true);
		}
		return (false);
	}

	/**
	 * Affiche le labyrinthe dans la console
	 */
	public void displayMaze()
	{
		System.out.println();
		int        xStart = 0;
		int        yStart = 0;
		int        xEnd   = 0;
		int        yEnd   = 0;
		LineWall[] walls  = m.getLineWalls();
		for (LineWall lw : walls)
		{
			xStart = Math.min(Math.min(lw.getX1(), lw.getX2()), xStart);
			xEnd   = Math.max(Math.max(lw.getX1(), lw.getX2()), xEnd);
			yStart = Math.min(Math.min(lw.getY1(), lw.getY2()), yStart);
			yEnd   = Math.max(Math.max(lw.getY1(), lw.getY2()), yEnd);
		}
		char[][] maze = new char [yEnd - yStart + 1][xEnd - xStart + 1];
		for (int i = 0; i < maze.length; i++)
		{
			for (int j = 0; j < maze[i].length; j++)
			{
				maze[i][j] = ' ';
			}
		}
		for (LineWall lw : walls)
		{
			int xRef = Math.min(lw.getX1(), lw.getX2()) - xStart;
			int yRef = Math.min(lw.getY1(), lw.getY2()) - yStart;
			//System.out.println(lw.getX1() + " " + lw.getX2() + " " + lw.getY1() + " " + lw.getY2());
			int distanceWall = Math.max(Math.abs(lw.getX1() - lw.getX2()), Math.abs(lw.getY1() - lw.getY2()));
			//System.out.println(xRef + " " + yRef + " " + distanceWall);
			boolean isHorizontal = lw.isHorizontal();
			//System.out.println(xRef + " " + yRef + " " + distanceWall);
			for (int d = 0; d < distanceWall; d++)
			{
				maze[yRef][xRef] = (isHorizontal) ? HORIZONTAL : VERTICAL;
				xRef             = xRef + ((isHorizontal) ? 1 : 0);
				yRef             = yRef + ((!isHorizontal) ? 1 : 0);
				//System.out.println(xRef + " " + yRef);
			}
		}
		for (int i = 0; i < maze.length; i++)
		{
			for (int j = 0; j < maze[i].length; j++)
			{
				System.out.print(maze[i][j]);
			}
			System.out.println();
		}
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
