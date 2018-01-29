package src.model.board;

import java.io.Serializable;

/**
 * Case du labyrinthe quelconque.
 */
public abstract class Case implements Serializable
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
		String repX = "x : " + this.x + "\n";
		String repY = "y : " + this.y + "\n";

		return (repX + repY);
	}
}
