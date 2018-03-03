package src.utils;

import java.lang.Math;
import java.util.Vector;
import src.model.board.LineWall;

public class FloatVector
{
	private float x;
	private float y;
	private final static float ERREUR = 10e-5f;

	public FloatVector(float x, float y)
	{
		this.x = x;
		this.y = y;
	}

	public float getX()
	{
		return (this.x);
	}

	public float getY()
	{
		return (this.y);
	}

	/**
	 * Teste si le vecteur est le vecteur nul à une ERREUR près
	 * @return true si le vecteur est (0, 0)
	 */
	public boolean isNul()
	{
		return (Math.abs(this.x) < ERREUR && Math.abs(this.y) < ERREUR);
	}

	/**
	 * Multiple un vecteur par un scalaire
	 * @param k Coefficient de multiplication
	 * @return vecteur multiplié par le scalaire
	 */
	public FloatVector multiplicate(float k)
	{
		return (new FloatVector(this.x * k, this.y * k));
	}

	/**
	 * Calcule la somme avec le vecteur fv
	 * @param fv Vecteur à sommer
	 * @return vecteur somme avec fv
	 */
	public FloatVector sum(FloatVector fv)
	{
		return (new FloatVector(fv.getX() + this.x, fv.getY() + this.y));
	}

	/**
	 * Teste la collinéarité avec le vecteur v = (vx, vy)
	 * @param vx Composante en x du vecteur v
	 * @param vy Composante en y du vecteur v
	 * @return true si le vecteur est collinéaire au vecteur v = (vx, vy)
	 */
	public boolean isCollinearTo(float vx, float vy)
	{
		return (Math.abs(this.x * vy - this.y * vx) < ERREUR);
	}

	public static FloatVector [][] append(FloatVector [][] tab, FloatVector a, FloatVector b)
	{
		FloatVector [][] newTab = new FloatVector [tab.length + 1][2];
		for (int i = 0; i < tab.length; i++)
		{
			newTab[i] = tab[i];
		}
		newTab[newTab.length - 1][0] = a;
		newTab[newTab.length - 1][1] = b;
		return (newTab);
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

	/**
	 * Réécriture de la méthode toString()
	 * @return représentation du vecteur dans une chaîne de caractères
	 */
	@Override
	public String toString()
	{
		return ("(" + this.x + " ; " + this.y + ")");
	}
}
