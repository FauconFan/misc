package src.model.board;

/**
 * Case du labyrinthe sur laquelle le joueur doit arriver.
 */
public class EndCase extends Case
{
	public EndCase(int x, int y)
	{
		super(x, y, TypeCase.END);
	}

	public EndCase clone()
	{
		return (new EndCase(this.x, this.y));
	}

	public String toString()
	{
		return ("EndCase\n" + super.toString());
	}
}
