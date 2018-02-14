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

import src.model.gen.AlgoSample2;

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

	public ContentMaze getAdaptedMaze()
	{
		return (this.m);
	}

	/**
	 * Déplace le joueur à la position (x + v.get(0), y + v.get(1))
	 * @param v Le vecteur de déplacement
	 */
	private void applyMove(FloatVector v)
	{
		p.setPosX(p.getPosX() + v.get(0));
		p.setPosY(p.getPosY() + v.get(1));
	}

	/**
	 * Décompose le vecteur AD en deux vecteurs AB et BC avec B le point d'intersection entre AD et le mur le plus proche/
	 * @param v Le vecteur déplacement qu'il faut décomposer
	 * @return Tableau de deux vecteurs
	 */
	private FloatVector [] calculateSplitMoves(FloatVector v)
	{
		float erreur = 10e-5F;

		FloatVector [] splitMove = new FloatVector[2];
		splitMove[0] = v;
		splitMove[1] = new FloatVector(0, 0);
		float minNormNextMove = splitMove[0].norm();
		for (LineWall lw : m.getLineWalls())
		{
			if (!v.isCollinearTo((lw.getX2() - lw.getX1()), (lw.getY2() - lw.getY1())))
			{
				boolean horizontalWall = lw.isHorizontal();
				float   coefProp       = (horizontalWall) ? ((lw.getY1() - p.getPosY()) / v.get(1)) : ((lw.getX1() - p.getPosX()) / v.get(0));
				if (coefProp >= 0 && coefProp <= 1)
				{
					FloatVector intersecPoint = (horizontalWall) ? new FloatVector(p.getPosX() + coefProp * v.get(0), (float)lw.getY1()) : new FloatVector((float)lw.getX1(), p.getPosY() + coefProp * v.get(1));
					splitMove[0] = intersecPoint.rightSubstractLeft(p.getPosX(), p.getPosY());
					if (minNormNextMove == -1 || minNormNextMove >= splitMove[0].norm())
					{
						minNormNextMove = splitMove[0].norm();
						splitMove[1]    = (horizontalWall) ? intersecPoint.leftSubstractRight(p.getPosX() + v.get(0), lw.getY1()) : intersecPoint.leftSubstractRight(lw.getX1(), p.getPosY() + v.get(1));
						System.out.println("nMove : " + splitMove[1] + " actMove" + splitMove[0]);
					}
				}
			}
		}
		return (splitMove);
	}

	/**
	 * Déplace le joueur dans le labyrinthe, si le joueur rencontre un mur, il longera ce mur.
	 * @param dx Le deplacement horizontal du joueur.
	 * @param dy Le deplacement vertical du joueur.
	 * @return Player
	 */
	public Player movePlayer(float dx, float dy)
	{
		FloatVector v = new FloatVector(dx, dy);

		while (!v.isNul())
		{
			FloatVector [] moves = this.calculateSplitMoves(v);
			this.applyMove(moves[0]);
			v = moves[1];
		}
		return (p);
	}

	/**
	 * Affiche le labyrinthe dans la console
	 * @param reverse Affichage du labyrinthe reverser si reverse = true
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
