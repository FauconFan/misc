package src.model;

/**
 * Case du labyrinthe sur laquelle le joueur doit arriver.
 */
public class EndCase extends Case
{
	public EndCase(int x, int y)
	{
		super(x, y);
	}

	public String toString()
	{
		return ("EndCase\n" + super.toString());
	}
}
