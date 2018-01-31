package src.model.gen;

import src.model.board.Case;
import src.model.board.LineWall;
import src.utils.StringManipulation;

import java.io.Serializable;
import src.model.ContentMaze;

/**
 * Sous-labyrinthe rectangulaire qui compose le MainLabyrinthe (sans tenir compte du décalage).
 */
public class RectMaze implements Serializable
{
	private final ContentMaze cm;
	private final int size_x;
	private final int size_y;

	public RectMaze(ContentMaze cm, int x, int y)
	{
		this.cm     = cm;
		this.size_x = x;
		this.size_y = y;
	}

	public ContentMaze getContentMaze()
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
