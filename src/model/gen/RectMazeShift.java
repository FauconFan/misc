package src.model.gen;

import java.io.Serializable;

import src.utils.StringManipulation;

import src.model.ContentMaze;

/**
 * Sous-labyrinthe rectangulaire qui compose le MainLabyrinthe (en tenant compte du décalage).
 */
public class RectMazeShift implements Serializable
{
	private final RectMaze rl;
	private final int x;
	private final int y;

	public RectMazeShift(RectMaze rl, int dx, int dy)
	{
		if (rl == null)
		{
			throw new RuntimeException("RectMazeShift can't be implemented with a null RectMaze");
		}
		this.rl = rl;
		this.x  = dx;
		this.y  = dy;
	}

	public ContentMaze getTranslatedContentMaze()
	{
		ContentMaze cmcpy = this.rl.getContentMaze().clone();

		cmcpy.translate(this.x, this.y);
		return (cmcpy);
	}

	public int getDX()
	{
		return (this.x);
	}

	public int getDY()
	{
		return (this.y);
	}

	/**
	 * RectLabShift Rep
	 * @return String rep
	 */
	@Override
	public String toString()
	{
		String str;

		str  = "dx : " + this.getDX() + "\n";
		str += "dy : " + this.getDY() + "\n";
		str += StringManipulation.makeTabsProperly(rl.toString());
		return (str);
	}
}
