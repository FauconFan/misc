package src.model.gen;

import src.model.board.Case;
import src.model.board.LineWall;
import src.utils.StringManipulation;

/**
 * Sous-labyrinthe rectangulaire qui compose le MainLabyrinthe (sans tenir compte du décalage).
 */
public class RectMaze
{
	private final Case [] specialCases;
	private final LineWall [] linewalls;
	private final int size_x;
	private final int size_y;

	public RectMaze(Case[] specialCases, LineWall[] linewalls, int x, int y)
	{
		this.specialCases = specialCases;
		this.linewalls    = linewalls;
		this.size_x       = x;
		this.size_y       = y;
	}

	public Case[] getSpecialCases()
	{
		return (this.specialCases);
	}

	public LineWall[] getLineWalls()
	{
		return (this.linewalls);
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
		if (specialCases.length == 0)
		{
			str += "No specialCases\n";
		}
		else
		{
			for (int i = 0; i < specialCases.length; i++)
			{
				str += StringManipulation.makeTabsProperly(specialCases[i].toString());
			}
		}
		if (linewalls.length == 0)
		{
			str += "No Walls\n";
		}
		else
		{
			for (int i = 0; i < linewalls.length; i++)
			{
				str += StringManipulation.makeTabsProperly(linewalls[i].toString());
			}
		}
		return (str);
	}
}
