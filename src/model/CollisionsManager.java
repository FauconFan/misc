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

	private void putClosestWall(FloatVector v)
	{
		float coefProp;

		for (LineWall lw : this.walls)
		{
			FloatVector [][] effectWalls = lw.effWalls(p.getPosX(), p.getPosY());
			for (int i = 0; i < effectWalls.length; i++)
			{
				boolean horizontalWall = CollisionsManager.effectWallIsHorizontal(effectWalls[i]);
				if (!v.isCollinearTo((effectWalls[i][1].getX() - effectWalls[i][0].getX()), (effectWalls[i][1].getY() - effectWalls[i][0].getY())))
				{
					coefProp = (horizontalWall) ? ((effectWalls[i][0].getY() - p.getPosY()) / v.getY()) : ((effectWalls[i][0].getX() - p.getPosX()) / v.getX());
					if (0 < coefProp && coefProp < 1 &&
						CollisionsManager.pointInWall(new FloatVector(p.getPosX(), p.getPosY()).sum(v.multiplicate(coefProp)), effectWalls[i]) &&
						coefProp < this.coefPropMin)
					{
						this.coefPropMin = coefProp;
						this.closestWall = effectWalls[i];
					}
				}
			}
		}
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
	 * Décompose le vecteur AD en deux vecteurs AB et BC avec B le point d'intersection entre AD et le mur le plus proche
	 */
	public void updateMove()
	{
		init();
		FloatVector v = splitMove[0];
		putClosestWall(v);

		if (this.coefPropMin > 0 && this.coefPropMin < 1)
		{
			float t = 1 - p.getHitBoxCircle() / (coefPropMin * (float)Math.sqrt(Math.pow(v.getX(), 2) + Math.pow(v.getY(), 2)));
			splitMove[0] = v.multiplicate(t * this.coefPropMin);
			if (CollisionsManager.effectWallIsHorizontal(this.closestWall))
			{
				splitMove[1] = new FloatVector(v.getX() * (1 - t * this.coefPropMin), 0);
			}
			else
			{
				splitMove[1] = new FloatVector(0, v.getY() * (1 - t * this.coefPropMin));
			}
		}
	}

	private static boolean effectWallIsHorizontal(FloatVector [] w)
	{
		return (Math.abs(w[0].getY() - w[1].getY()) < 10e-4f);
	}

	public static boolean pointInWall(FloatVector point, FloatVector [] wall)
	{
		float erreur = 10e-5F;

		if (wall[0].getY() == wall[1].getY())
		{
			if (Math.abs(point.getY() - wall[0].getY()) > erreur)
			{
				return (false);
			}
			if ((wall[0].getX() <= point.getX() && point.getX() <= wall[1].getX()) || (wall[0].getX() >= point.getX() && point.getX() >= wall[1].getX()))
			{
				return (true);
			}
		}
		else
		{
			if (Math.abs(point.getX() - wall[0].getX()) > erreur)
			{
				return (false);
			}
			if ((wall[0].getY() <= point.getY() && point.getY() <= wall[1].getY()) || (wall[0].getY() >= point.getY() && point.getY() >= wall[1].getY()))
			{
				return (true);
			}
		}
		return (false);
	}
}
