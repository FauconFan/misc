package src.model;

import java.lang.StringBuffer;

/**
 * Case du labyrinthe quelconque.
 */
public abstract class Case
{
	private int x;
	private int y;

	public Case(int x, int y)
	{
		this.x = x;
		this.y = y;
	}

	public String toString()
	{
		StringBuffer bf = new StringBuffer();

		bf.append("x : " + this.x + "\n");
		bf.append("y : " + this.y + "\n");
		return (bf.toString());
	}
}
