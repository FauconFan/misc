package src.model;

import src.model.board.LineWall;
import src.model.Player;
import src.utils.FloatVector;

import java.lang.Math;

public class CollisionsXYManager
{
	private Player p;
	private int currentLevel;
	private float coefPropMin;
	private ContentMaze [] cms;
	private FloatVector [] closestWall;
	private FloatVector [] splitMove;
	private FloatVector finalMove;

	public CollisionsXYManager(Player p)
	{
		this.p         = p;
		this.splitMove = new FloatVector[2];
	}

	private void init()
	{
		this.coefPropMin = 1;
		this.closestWall = null;
	}

	public void updateMove(FloatVector d)
	{
		this.finalMove    = new FloatVector(0, 0);
		this.splitMove[0] = d;
		this.splitMove[1] = new FloatVector(0, 0);
		do
		{
			this.update();
			this.finalMove.sum(this.splitMove[0]);
			this.next();
		} while (!this.splitMove[0].isNul());
	}

	public void updateWalls(ContentMaze [] cms, int currentLevel)
	{
		this.cms          = cms;
		this.currentLevel = currentLevel;
	}

	public FloatVector getMove()
	{
		return (this.finalMove);
	}

	public float getNorm()
	{
		return (this.finalMove.norm());
	}

	public void next()
	{
		this.splitMove[0] = this.splitMove[1];
		this.splitMove[1] = new FloatVector(0, 0);
	}

	/**
	 * Cherche le mur le plus proche qui gène le déplacement.
	 */
	private void putClosestWall()
	{
		float coefProp;
		float positionEff;

		for (int k = 0; k < cms.length; k++)
		{
			if (cms[k] != null&& ((k == 0 && this.p.getPosZ() - this.p.hitBoxBottom < currentLevel) ||
								  k == 1 ||
								  (k == 2 && this.p.getPosZ() + this.p.hitBoxTop > currentLevel + 1)))
			{
				for (LineWall lw : cms[k].getLineWalls())
				{
					FloatVector [][] effectWalls = lw.effWalls(this.p.getPosX(), this.p.getPosY());
					for (int i = 0; i < effectWalls.length; i++)
					{
						boolean horizontalWall = CollisionsXYManager.effectWallIsHorizontal(effectWalls[i]);
						if (!this.splitMove[0].isCollinearTo((effectWalls[i][1].getX() - effectWalls[i][0].getX()), (effectWalls[i][1].getY() - effectWalls[i][0].getY())))
						{
							if (horizontalWall)
							{
								positionEff = (this.p.getPosY() < effectWalls[i][0].getY()) ? -1 : 1;
								coefProp    = (effectWalls[i][0].getY() + this.p.hitBoxCircle * positionEff - this.p.getPosY()) / this.splitMove[0].getY();
							}
							else
							{
								positionEff = (this.p.getPosX() < effectWalls[i][0].getX()) ? -1 : 1;
								coefProp    = (effectWalls[i][0].getX() + this.p.hitBoxCircle * positionEff - this.p.getPosX()) / this.splitMove[0].getX();
							}
							if ((coefProp < this.coefPropMin && coefProp < 1 && this.isConsideredWall(coefProp, effectWalls[i], horizontalWall)) &&
								(0 < coefProp || (Math.abs(coefProp) < 10e-4f && ((horizontalWall && this.splitMove[0].getY() * positionEff < 0) ||
																				  (!horizontalWall && this.splitMove[0].getX() * positionEff < 0)))))
							{
								this.coefPropMin = coefProp;
								this.closestWall = effectWalls[i];
							}
						}
					}
				}
			}
		}
	}

	/**
	 * Décompose le vecteur AD en deux vecteurs AB et BC avec B le point d'intersection entre AD et le mur le plus proche
	 */
	private void update()
	{
		this.init();
		this.putClosestWall();

		if (this.coefPropMin >= 0 && this.coefPropMin < 1)
		{
			if (CollisionsXYManager.effectWallIsHorizontal(this.closestWall))
			{
				this.splitMove[1] = new FloatVector(this.splitMove[0].getX() * (1 - this.coefPropMin), 0);
			}
			else
			{
				this.splitMove[1] = new FloatVector(0, this.splitMove[0].getY() * (1 - this.coefPropMin));
			}
			this.splitMove[0] = this.splitMove[0].multiplicate(this.coefPropMin);
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
			return ((wall[0].getX() - this.p.hitBoxCircle < this.p.getPosX() + k * this.splitMove[0].getX() &&
					 this.p.getPosX() + k * this.splitMove[0].getX() < wall[1].getX() + this.p.hitBoxCircle) ||
					(wall[1].getX() - this.p.hitBoxCircle < this.p.getPosX() + k * this.splitMove[0].getX() &&
					 this.p.getPosX() + k * this.splitMove[0].getX() < wall[0].getX() + this.p.hitBoxCircle));
		}
		else
		{
			return ((wall[0].getY() - this.p.hitBoxCircle < this.p.getPosY() + k * this.splitMove[0].getY() &&
					 this.p.getPosY() + k * this.splitMove[0].getY() < wall[1].getY() + this.p.hitBoxCircle) ||
					(wall[1].getY() - this.p.hitBoxCircle < this.p.getPosY() + k * this.splitMove[0].getY() &&
					 this.p.getPosY() + k * this.splitMove[0].getY() < wall[0].getY() + this.p.hitBoxCircle));
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
