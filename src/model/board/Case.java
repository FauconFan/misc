package src.model.board;

import java.io.Serializable;
import java.lang.Cloneable;

/**
 * Case du labyrinthe quelconque.
 */
public abstract class Case implements Serializable, Cloneable
{
	protected int x;
	protected int y;

	public Case(int x, int y)
	{
		this.x = x;
		this.y = y;
	}

	public int getX()
	{
		return (this.x);
	}

	public int getY()
	{
		return (this.y);
	}

	public void translate(int dx, int dy)
	{
		this.x = this.x + dx;
		this.y = this.y + dy;
	}

	public abstract Case clone();
	public abstract TypeCase getTypeCase();

	public boolean coordsEquals(Case c)
	{
		return (this.x == c.getX() && this.y == c.getY());
	}

	public boolean equals(Case c)
	{
		return (this.getTypeCase() == c.getTypeCase() && this.coordsEquals(c));
	}

	@Override
	public String toString()
	{
		String repX = "x : " + this.x + "\n";
		String repY = "y : " + this.y + "\n";

		return (repX + repY);
	}

	public enum TypeCase
	{
		START,
		END;
	}
}
