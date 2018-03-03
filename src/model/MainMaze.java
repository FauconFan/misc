package src.model;

import java.util.ArrayList;
import java.util.Vector;

import java.lang.Math;
import src.model.board.Case;
import src.model.board.LineWall;
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
	 * Décompose le vecteur AD en deux vecteurs AB et BC avec B le point d'intersection entre AD et le mur le plus proche
	 * @param v Vecteur déplacement qu'il faut décomposer
	 * @return Tableau de deux vecteurs
	 */
	private FloatVector [] calculateSplitMoves(FloatVector v)
	{
		float coefPropMin = 1;
		float coefProp;

		FloatVector [] splitMove = new FloatVector[2];
		splitMove[0] = v;
		splitMove[1] = new FloatVector(0, 0);
		FloatVector [] closestWall = new FloatVector [2];
		for (LineWall lw : m.getLineWalls())
		{
			FloatVector [][] effectWalls = lw.effWalls(p.getPosX(), p.getPosY());
			for (int i = 0; i < effectWalls.length; i++)
			{
				boolean horizontalWall = (Math.abs(effectWalls[i][1].getY() - effectWalls[i][0].getY()) < 10e-4f);
				if (!v.isCollinearTo((effectWalls[i][1].getX() - effectWalls[i][0].getX()), (effectWalls[i][1].getY() - effectWalls[i][0].getY())))
				{
					coefProp = (horizontalWall) ? ((effectWalls[i][0].getY() - p.getPosY()) / v.getY()) : ((effectWalls[i][0].getX() - p.getPosX()) / v.getX());
					if (0 < coefProp && coefProp < 1 && FloatVector.pointInWall(new FloatVector(p.getPosX(), p.getPosY()).sum(v.multiplicate(coefProp)), effectWalls[i]) && coefProp < coefPropMin)
					{
						coefPropMin = coefProp;
						closestWall = effectWalls[i];
					}
				}
			}
		}
		if (coefPropMin > 0 && coefPropMin < 1)
		{
			float t = 1 - p.getHitBoxCircle() / (coefPropMin * (float)Math.sqrt(Math.pow(v.getX(), 2) + Math.pow(v.getY(), 2)));
			splitMove[0] = v.multiplicate(t * coefPropMin);
			if (Math.abs(closestWall[0].getY() - closestWall[1].getY()) < 10e-4f)
			{
				splitMove[1] = new FloatVector(v.getX() * (1 - t * coefPropMin), 0);
			}
			else
			{
				splitMove[1] = new FloatVector(0, v.getY() * (1 - t * coefPropMin));
			}
		}
		return (splitMove);
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
			FloatVector v = new FloatVector(dx, dy);
			while (!v.isNul())
			{
				FloatVector [] moves = this.calculateSplitMoves(v);
				this.applyMove(moves[0]);
				v = moves[1];
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
