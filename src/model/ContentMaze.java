package src.model;

import java.io.Serializable;
import src.model.board.*;
import src.utils.StringManipulation;

public class ContentMaze implements Serializable
{
	private Case[] specialCases;
	private LineWall[] linewalls;

	public ContentMaze(Case[] sc, LineWall[] w)
	{
		this.specialCases = sc;
		this.linewalls    = w;
	}

	public Case[] getSpecialCases()
	{
		return (this.specialCases);
	}

	public LineWall[] getLineWalls()
	{
		return (this.linewalls);
	}

	/**
	 * RectMaze rep
	 * @return String rep
	 */
	public String toString()
	{
		String str = "";

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
