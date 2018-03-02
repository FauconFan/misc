package src.model;

import java.util.ArrayList;
import java.util.Vector;

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
		float       coefPropMin = 1;
		float       coefProp;
		float       epaisEff     = 0;
		LineWall    closestWall  = null;
		FloatVector closestPoint = new FloatVector(0, 0);

		FloatVector [] splitMove = new FloatVector[2];
		FloatVector    hitboxPoint;
		splitMove[0] = v;
		splitMove[1] = new FloatVector(0, 0);
		for (LineWall lw : m.getLineWalls())
		{
			boolean horizontalWall = lw.isHorizontal();
			if (horizontalWall)
			{
				epaisEff    = ((lw.getY1() < p.getPosY()) ? 1 : -1) * lw.getEpaisseur();
				hitboxPoint = new FloatVector(p.getPosX(), p.getPosY() + ((epaisEff > 0) ? -1 : 1) * p.getHitBoxCircle());
			}
			else
			{
				epaisEff    = ((lw.getX1() < p.getPosX()) ? 1 : -1) * lw.getEpaisseur();
				hitboxPoint = new FloatVector(p.getPosX() + ((epaisEff > 0) ? -1 : 1) * p.getHitBoxCircle(), p.getPosY());
			}
			if (lw.pointInWall(hitboxPoint))
			{
				if (horizontalWall)
				{
					if ((epaisEff > 0 && v.getY() < 0) ||
						(epaisEff < 0 && v.getY() > 0))
					{
						splitMove[0] = new FloatVector(0, 0);
						splitMove[1] = new FloatVector(v.getX(), 0);
						return (splitMove);
					}
				}
				else
				{
					if ((epaisEff > 0 && v.getX() < 0) ||
						(epaisEff < 0 && v.getX() > 0))
					{
						splitMove[0] = new FloatVector(0, 0);
						splitMove[1] = new FloatVector(0, v.getY());
						return (splitMove);
					}
				}
			}
			else if (!v.isCollinearTo((lw.getX2() - lw.getX1()), (lw.getY2() - lw.getY1())))
			{
				coefProp = (horizontalWall) ? ((lw.getY1() + epaisEff - hitboxPoint.getY()) / v.getY()) : ((lw.getX1() + epaisEff - hitboxPoint.getX()) / v.getX());
				if (0 < coefProp && coefProp < 1 && lw.pointInWall(hitboxPoint.sum(v.multiplicate(coefProp))) && coefProp < coefPropMin)
				{
					coefPropMin  = coefProp;
					closestPoint = hitboxPoint;
					closestWall  = lw;
				}
			}
		}
		if (coefPropMin > 0 && coefPropMin < 1)
		{
			if (closestWall.isHorizontal())
			{
				epaisEff     = ((closestWall.getY1() < p.getPosY()) ? 1 : -1) * closestWall.getEpaisseur();
				splitMove[0] = new FloatVector(coefPropMin * v.getX(), coefPropMin * v.getY());
				splitMove[1] = new FloatVector(v.getX() * (1 - coefPropMin), 0);
			}
			else
			{
				epaisEff     = ((closestWall.getX1() < p.getPosX()) ? 1 : -1) * closestWall.getEpaisseur();
				splitMove[0] = new FloatVector(coefPropMin * v.getX(), coefPropMin * v.getY());
				splitMove[1] = new FloatVector(0, v.getY() * (1 - coefPropMin));
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
