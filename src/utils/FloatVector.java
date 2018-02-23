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
	 * Calcule la somme avec le vecteur (vx, vy)
	 * @param vx Composante en x du vecteur à sommer
	 * @param vy Composante en y du vecteur à sommer
	 * @return vecteur somme avec (x, y)
	 */
	public FloatVector sum(float vx, float vy)
	{
		return (this.sum(new FloatVector(vx, vy)));
	}

	public FloatVector leftSubstractRight(FloatVector fv)
	{
		return (new FloatVector(fv.getX() - this.x, fv.getY() - this.y));
	}

	public FloatVector leftSubstractRight(float vx, float vy)
	{
		return (this.leftSubstractRight(new  FloatVector(vx, vy)));
	}

	public FloatVector rightSubstractLeft(FloatVector fv)
	{
		return (new FloatVector(this.x - fv.getX(), this.y - fv.getY()));
	}

	public FloatVector rightSubstractLeft(float vx, float vy)
	{
		return (this.rightSubstractLeft(new  FloatVector(vx, vy)));
	}

	/**
	 * Teste la collinéarité avec le vecteur fv
	 * @param fv Vecteur
	 * @return true si le vecteur est collinéaire au vecteur fv
	 */

	public boolean isCollinearTo(FloatVector fv)
	{
		return (Math.abs(this.x * fv.getY() - this.y * fv.getX()) < erreur);
	}

	/**
	 * Teste la collinéarité avec le vecteur (vx, vy)
	 * @param vx Composante en x du vecteur
	 * @param vy Composante en y du vecteur
	 * @return true si le vecteur est collinéaire au vecteur (vx, vy)
	 */
	public boolean isCollinearTo(float vx, float vy)
	{
		return (this.isCollinearTo(new FloatVector(vx, vy)));
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
