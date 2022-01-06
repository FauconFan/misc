package src.model.board;

/**
 * Case du labyrinthe sur laquelle le joueur va débuter.
 */
public class StartCase extends Case
{
	public StartCase(int x, int y)
	{
		super(x, y, TypeCase.START);
	}

	public StartCase clone()
	{
		return (new StartCase(this.x, this.y));
	}

	public String toString()
	{
		return ("StartCase\n" + super.toString());
	}
}
