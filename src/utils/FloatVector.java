package src.utils;

import java.lang.Math;

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

	public float norm()
	{
		return ((float)Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2)));
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
	 */
	public void sum(FloatVector fv)
	{
		this.x += fv.getX();
		this.y += fv.getY();
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
