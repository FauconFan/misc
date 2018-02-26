package src.utils;

import java.lang.Math;
import java.util.Vector;
import src.model.board.LineWall;

public class FloatVector
{
	private float x;
	private float y;
	private float erreur;

	public FloatVector(float x, float y, float err)
	{
		this.x      = x;
		this.y      = y;
		this.erreur = err;
	}

	public FloatVector(float x, float y)
	{
		this(x, y, 10e-4F);
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
	 * Teste si le vecteur est le vecteur nul à une erreur près
	 * @return true si le vecteur est (0, 0)
	 */
	public boolean isNul()
	{
		return (Math.abs(this.x) < erreur && Math.abs(this.y) < erreur);
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
		return (Math.abs(this.x * vy - this.y * vx) < erreur);
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
