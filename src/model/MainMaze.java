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
import src.utils.FloatVector;
import src.utils.StringManipulation;

/**
 * Structure de données du labyrinthe.
 */
public class MainMaze implements Serializable
{
	private ContentMaze m;
	private MazeDimension mazeDim;
	private String name;
	private Player p;
	private int porteeVue;

	public MainMaze(ContentMaze m, MazeDimension mz, String name, Player p, int porteeVue)
	{
		this.m         = m;
		this.mazeDim   = mz;
		this.name      = name;
		this.p         = p;
		this.porteeVue = porteeVue;
	}

	public MainMaze(Algo algo, int porteeVueP)
	{
		this(algo.getContentMaze(), algo.getMazeDimension(), "", null, porteeVueP);
	}

	public ContentMaze getAdaptedMaze()
	{
		return (this.m);
	}

	public MazeDimension getMazeDimension()
	{
		return (this.mazeDim);
	}

	/**
	 * Déplace le joueur à la position (x + v.get(0), y + v.get(1))
	 * @param v Vecteur de déplacement
	 */
	private void applyMove(FloatVector v)
	{
		p.setPosX(p.getPosX() + v.get(0));
		p.setPosY(p.getPosY() + v.get(1));
	}

	/**
	 * Décompose le vecteur AD en deux vecteurs AB et BC avec B le point d'intersection entre AD et le mur le plus proche/
	 * @param v Vecteur déplacement qu'il faut décomposer
	 * @return Tableau de deux vecteurs
	 */
	private FloatVector [] calculateSplitMoves(FloatVector v)
	{
		FloatVector [] splitMove = new FloatVector[2];
		splitMove[0] = v;
		splitMove[1] = new FloatVector(0, 0);
		float          minNormMove = splitMove[0].norm();
		float          coefPropMin = 1;
		float          coefProp;
		LineWall       closestWall  = null;
		FloatVector    closestPoint = null;
		FloatVector [] hitboxPoints = new FloatVector [4];
		hitboxPoints[0] = (new FloatVector(p.getHitBoxLength() / 2, p.getHitBoxWidth() / 2)).rotate(p.getHorizontalAngle()).sum(p.getPosX(), p.getPosY());
		hitboxPoints[1] = (new FloatVector(-p.getHitBoxLength() / 2, p.getHitBoxWidth() / 2)).rotate(p.getHorizontalAngle()).sum(p.getPosX(), p.getPosY());
		hitboxPoints[2] = (new FloatVector(p.getHitBoxLength() / 2, -p.getHitBoxWidth() / 2)).rotate(p.getHorizontalAngle()).sum(p.getPosX(), p.getPosY());
		hitboxPoints[3] = (new FloatVector(-p.getHitBoxLength() / 2, -p.getHitBoxWidth() / 2)).rotate(p.getHorizontalAngle()).sum(p.getPosX(), p.getPosY());
		for (LineWall lw : m.getLineWalls())
		{
			boolean horizontalWall = lw.isHorizontal();
			for (int i = 0; i < 4; i++)
			{
				if (lw.pointInWall(hitboxPoints[i]))
				{
					if (horizontalWall)
					{
						if ((p.getPosY() < lw.getY1() && p.getPosY() + v.get(1) > p.getPosY()) ||
							(p.getPosY() > lw.getY1() && p.getPosY() + v.get(1) < p.getPosY()))
						{
							splitMove[0] = new FloatVector(0, 0);
							splitMove[1] = new FloatVector(v.get(0), 0);
							return (splitMove);
						}
					}
					else
					{
						if ((p.getPosX() > lw.getX1() && p.getPosX() + v.get(0) < p.getPosX()) ||
							(p.getPosX() < lw.getX1() && p.getPosX() + v.get(0) > p.getPosX()))
						{
							splitMove[0] = new FloatVector(0, 0);
							splitMove[1] = new FloatVector(0, v.get(1));
							return (splitMove);
						}
					}
				}
				if (!v.isCollinearTo((lw.getX2() - lw.getX1()), (lw.getY2() - lw.getY1())))
				{
					coefProp = (horizontalWall) ? ((lw.getY1() - hitboxPoints[i].get(1)) / v.get(1)) : ((lw.getX1() - hitboxPoints[i].get(0)) / v.get(0));
					if (0 < coefProp && coefProp < 1 && lw.pointInWall(hitboxPoints[i].sum(v.multiplicate(coefProp))) && coefProp < coefPropMin)
					{
						coefPropMin  = coefProp;
						closestWall  = lw;
						closestPoint = hitboxPoints[i];
					}
				}
			}
		}
		if (coefPropMin > 0 && coefPropMin < 1)
		{
			FloatVector intersecPoint = (closestWall.isHorizontal()) ? new FloatVector(closestPoint.get(0) + coefPropMin * v.get(0), (float)closestWall.getY1()) : new FloatVector((float)closestWall.getX1(), closestPoint.get(1) + coefPropMin * v.get(1));
			splitMove[0] = intersecPoint.rightSubstractLeft(closestPoint);
			splitMove[1] = (closestWall.isHorizontal()) ? intersecPoint.leftSubstractRight(closestPoint.get(0) + v.get(0), closestWall.getY1()) : intersecPoint.leftSubstractRight(closestWall.getX1(), closestPoint.get(1) + v.get(1));
		}
		return (splitMove);
	}

	/**
	 * Déplace le joueur dans le labyrinthe, si le joueur rencontre un mur, il longera ce mur.
	 * @param dx Deplacement horizontal du joueur.
	 * @param dy Deplacement vertical du joueur.
	 * @return Player
	 */
	public Player movePlayer(float dx, float dy)
	{
		FloatVector v = new FloatVector(dx, dy);

		while (!v.isNul())
		{
			FloatVector [] moves = this.calculateSplitMoves(v);
			System.out.println("moves 1 : " + moves[0] + " moves 2 : " + moves[1]);
			this.applyMove(moves[0]);
			v = moves[1];
		}
		return (p);
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
