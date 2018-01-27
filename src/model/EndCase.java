package src.model;

import java.lang.StringBuffer;

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
		StringBuffer bf = new StringBuffer();

		bf.append("EndCase\n");
		bf.append(super.toString());
		return (bf.toString());
	}
}
