package src.model;

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
}
