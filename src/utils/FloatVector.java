package src.utils;

import java.lang.Math;
import java.util.Vector;
import src.model.board.LineWall;

public class FloatVector extends Vector <Float>
{
	private float erreur;

	public FloatVector(float x, float y, float err)
	{
		this.add(x);
		this.add(y);
		this.erreur = err;
	}

	public FloatVector(float x, float y)
	{
		this(x, y, 10e-10F);
	}

	/**
	 * Teste si le vecteur est le vecteur nul à une erreur près
	 * @return true si le vecteur est (0, 0)
	 */
	public boolean isNul()
	{
		return (Math.abs(this.get(0)) < erreur && Math.abs(this.get(1)) < erreur);
	}

	/**
	 * Calcule la norme du vecteur
	 * @return la norme du vecteur
	 */
	public float norm()
	{
		return ((float)Math.sqrt(Math.pow(this.get(0), 2) + Math.pow(this.get(1), 2)));
	}

	/**
	 * Calcule la somme avec le vecteur fv
	 * @param fv Vecteur à sommer
	 * @return vecteur somme avec fv
	 */
	public FloatVector sum(FloatVector fv)
	{
		return (new FloatVector(fv.get(0) + this.get(0), fv.get(1) + this.get(1)));
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
		return (new FloatVector(fv.get(0) - this.get(0), fv.get(1) - this.get(1)));
	}

	public FloatVector leftSubstractRight(float vx, float vy)
	{
		return (this.leftSubstractRight(new  FloatVector(vx, vy)));
	}

	public FloatVector rightSubstractLeft(FloatVector fv)
	{
		return (new FloatVector(this.get(0) - fv.get(0), this.get(1) - fv.get(1)));
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
		return (Math.abs(this.get(0) * fv.get(1) - this.get(1) * fv.get(0)) < erreur);
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
		return ("(" + this.get(0) + " ; " + this.get(1) + ")");
	}
}
