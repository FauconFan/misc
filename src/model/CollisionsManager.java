package src.model;

import src.model.board.LineWall;
import src.model.Player;
import src.utils.FloatVector;

import java.lang.Math;

public class CollisionsManager
{
	private LineWall [] walls;
	private Player p;
	private float coefPropMin;
	private FloatVector [] closestWall;
	private FloatVector [] splitMove;

	public CollisionsManager(LineWall [] lws, Player p, FloatVector dep)
	{
		this.walls        = lws;
		this.p            = p;
		this.splitMove    = new FloatVector[2];
		this.splitMove[0] = dep;
		this.splitMove[1] = new FloatVector(0, 0);
	}

	private void init()
	{
		coefPropMin = 1;
		closestWall = null;
	}

	public FloatVector getNextMove()
	{
		return (splitMove[0]);
	}

	public void next()
	{
		splitMove[0] = splitMove[1];
		splitMove[1] = new FloatVector(0, 0);
	}

	/**
	 * Cherche le mur le plus proche qui gène le déplacement.
	 */
	private void putClosestWall()
	{
		float coefProp;
		float positionEff;

		for (LineWall lw : this.walls)
		{
			FloatVector [][] effectWalls = lw.effWalls(p.getPosX(), p.getPosY());
			for (int i = 0; i < effectWalls.length; i++)
			{
				boolean horizontalWall = CollisionsManager.effectWallIsHorizontal(effectWalls[i]);
				if (!splitMove[0].isCollinearTo((effectWalls[i][1].getX() - effectWalls[i][0].getX()), (effectWalls[i][1].getY() - effectWalls[i][0].getY())))
				{
					if (horizontalWall)
					{
						positionEff = (p.getPosY() < effectWalls[i][0].getY()) ? -1 : 1;
						coefProp    = (effectWalls[i][0].getY() + p.getHitBoxCircle() * positionEff - p.getPosY()) / splitMove[0].getY();
					}
					else
					{
						positionEff = (p.getPosX() < effectWalls[i][0].getX()) ? -1 : 1;
						coefProp    = (effectWalls[i][0].getX() + p.getHitBoxCircle() * positionEff - p.getPosX()) / splitMove[0].getX();
					}
					if ((coefProp < this.coefPropMin && coefProp < 1 && isConsideredWall(coefProp, effectWalls[i], horizontalWall)) &&
						(0 < coefProp || (Math.abs(coefProp) < 10e-4f && ((horizontalWall && splitMove[0].getY() * positionEff < 0) || (!horizontalWall && splitMove[0].getX() * positionEff < 0)))))
					{
						this.coefPropMin = coefProp;
						this.closestWall = effectWalls[i];
					}
				}
			}
		}
	}

	/**
	 * Décompose le vecteur AD en deux vecteurs AB et BC avec B le point d'intersection entre AD et le mur le plus proche
	 */
	public void updateMove()
	{
		init();
		putClosestWall();

		if (this.coefPropMin >= 0 && this.coefPropMin < 1)
		{
			if (CollisionsManager.effectWallIsHorizontal(this.closestWall))
			{
				splitMove[1] = new FloatVector(splitMove[0].getX() * (1 - this.coefPropMin), 0);
			}
			else
			{
				splitMove[1] = new FloatVector(0, splitMove[0].getY() * (1 - this.coefPropMin));
			}
			splitMove[0] = splitMove[0].multiplicate(coefPropMin);
		}
	}

	/**
	 * Teste si le mur gène le déplacement
	 * @param k Coefficient de proportionnalité
	 * @param wall Vecteurs représentant un mur
	 * @param isHorizontal Test de l'horizontalité du mur
	 * @return true si le mur peut gener le déplacement
	 */
	private boolean isConsideredWall(float k, FloatVector [] wall, boolean isHorizontal)
	{
		if (isHorizontal)
		{
			return ((wall[0].getX() - p.getHitBoxCircle() < p.getPosX() + k * splitMove[0].getX() && p.getPosX() + k * splitMove[0].getX() < wall[1].getX() + p.getHitBoxCircle()) ||
					(wall[1].getX() - p.getHitBoxCircle() < p.getPosX() + k * splitMove[0].getX() && p.getPosX() + k * splitMove[0].getX() < wall[0].getX() + p.getHitBoxCircle()));
		}
		else
		{
			return ((wall[0].getY() - p.getHitBoxCircle() < p.getPosY() + k * splitMove[0].getY() && p.getPosY() + k * splitMove[0].getY() < wall[1].getY() + p.getHitBoxCircle()) ||
					(wall[1].getY() - p.getHitBoxCircle() < p.getPosY() + k * splitMove[0].getY() && p.getPosY() + k * splitMove[0].getY() < wall[0].getY() + p.getHitBoxCircle()));
		}
	}

	/**
	 * Teste l'horizontalité du mur à 10e-4 près
	 * @param w Mur
	 * @return true si le mur est horzontal
	 */
	private static boolean effectWallIsHorizontal(FloatVector [] w)
	{
		return (Math.abs(w[0].getY() - w[1].getY()) < 10e-4f);
	}
}
