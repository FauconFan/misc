package src.model;

import java.lang.StringBuffer;

/**
 * Case du labyrinthe sur laquelle le joueur va débuter.
 */
public class StartCase extends Case
{
	public StartCase(int x, int y)
	{
		super(x, y);
	}

	public String toString()
	{
		StringBuffer bf = new StringBuffer();

		bf.append("StartCase\n");
		bf.append(super.toString());
		return (bf.toString());
	}
}
