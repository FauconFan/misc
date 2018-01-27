package src.model;

import java.lang.StringBuffer;

import src.utils.StringManipulation;

/**
 * Sous-labyrinthe rectangulaire qui compose le MainLabyrinthe (sans tenir compte du décalage).
 */
public class RectLabyrinthe
{
	private final Case [] specialCases;
	private final LineWall [] linewalls;
	private final int size_x;
	private final int size_y;

	public RectLabyrinthe(Case[] specialCases, LineWall[] linewalls, int x, int y)
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
	 * RectLabyrinthe rep
	 * @return String rep
	 */
	public String toString()
	{
		StringBuffer bf = new StringBuffer();

		bf.append("size_x : " + this.getSizeX() + "\n");
		bf.append("size_y : " + this.getSizeY() + "\n");
		if (specialCases.length == 0)
		{
			bf.append(StringManipulation.makeTabsProperly("No specialCases\n"));
		}
		else
		{
			for (int i = 0; i < specialCases.length; i++)
			{
				bf.append(StringManipulation.makeTabsProperly(specialCases[i].toString()));
			}
		}
		return (bf.toString());
	}
}
