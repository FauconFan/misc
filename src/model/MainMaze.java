package src.model;

import java.util.ArrayList;

import src.model.board.Case;
import src.model.board.LineWall;
import src.model.CollisionsManager;
import src.model.gen.Algo;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;
import src.model.parser.Parser;
import src.utils.DisplayMazeConsole;
import src.utils.FloatVector;
import src.utils.StringManipulation;

/**
 * Structure de données du labyrinthe.
 */
public class MainMaze
{
	private ContentMaze m;
	private MazeDimension mazeDim;
	private String name;
	private Player p;

	public MainMaze(ContentMaze m, MazeDimension mz, String name, Player p)
	{
		this.m       = m;
		this.mazeDim = mz;
		this.name    = name;
		this.p       = p;

		p.goTo(Case.TypeCase.START, m);
	}

	public MainMaze(Algo algo)
	{
		this(algo.getContentMaze(), algo.getMazeDimension(), "", new Player(0.05f, 0.5f, 0.5f, 0f, 0f, 0f));
	}

	public ContentMaze getContentMaze()
	{
		return (this.m);
	}

	public MazeDimension getMazeDimension()
	{
		return (this.mazeDim);
	}

	public Player getPlayer()
	{
		return (this.p);
	}

	public Case getEndCase()
	{
		return (m.getCase(Case.TypeCase.END));
	}

	/**
	 * Déplace le joueur à la position (x + v.getX(), y + v.getY())
	 * @param v Vecteur de déplacement
	 */
	private void applyMove(FloatVector v)
	{
		p.setPosX(p.getPosX() + v.getX());
		p.setPosY(p.getPosY() + v.getY());
	}

	/**
	 * Déplace le joueur dans le labyrinthe, si le joueur rencontre un mur, il longera ce mur.
	 * @param dx Deplacement horizontal du joueur.
	 * @param dy Deplacement vertical du joueur.
	 * @param dz Deplacement selon la troisième coordonnées (ne sera pas pris en compte dans le calcul des collisions)
	 */
	public void movePlayer(float dx, float dy, float dz)
	{
		if (p.getGhostMode())
		{
			p.setPosZ(p.getPosZ() + dz);
			p.setPosX(p.getPosX() + dx);
			p.setPosY(p.getPosY() + dy);
		}

		else
		{
			CollisionsManager colManage = new CollisionsManager(m.getLineWalls(), p, new FloatVector(dx, dy));
			while (!colManage.getNextMove().isNul())
			{
				colManage.updateMove();
				this.applyMove(colManage.getNextMove());
				colManage.next();
			}
		}
	}

	/**
	 * Affiche le labyrinthe dans la console
	 * @param reverse reverse axis y
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
		str += "\n";
		str += "labyrinthe :\n";
		if (m != null)
		{
			str += m.toString();
		}
		return (str);
	}
}
