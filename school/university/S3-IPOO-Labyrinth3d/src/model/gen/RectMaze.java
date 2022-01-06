package src.model.gen;

import src.utils.StringManipulation;

import src.model.gen.ContentMazeEgg;

/**
 * Sous-labyrinthe rectangulaire qui compose le MainLabyrinthe (sans tenir compte du décalage).
 */
public class RectMaze
{
	private final ContentMazeEgg cm;
	private final int size_x;
	private final int size_y;

	public RectMaze(ContentMazeEgg cm, int x, int y)
	{
		this.cm     = cm;
		this.size_x = x;
		this.size_y = y;
	}

	public ContentMazeEgg getContentMazeEgg()
	{
		return (this.cm);
	}

	public int getSizeX()
	{
		return (this.size_x);
	}

	public int getSizeY()
	{
		return (this.size_y);
	}

	/**
	 * RectMaze rep
	 * @return String rep
	 */
	public String toString()
	{
		String str;

		str  = "size_x : " + this.getSizeX() + "\n";
		str += "size_y : " + this.getSizeY() + "\n";
		str += StringManipulation.makeTabsProperly(this.cm.toString());
		return (str);
	}
}
