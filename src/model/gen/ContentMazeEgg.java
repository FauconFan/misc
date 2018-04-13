package src.model.gen;

import src.model.board.*;
import src.utils.StringManipulation;

public class ContentMazeEgg
{
	private Case[] specialCases;
	private LineWall[] linewalls;

	public ContentMazeEgg(Case[] sc, LineWall[] w)
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

	public void translate(int dx, int dy)
	{
		for (Case c : this.specialCases)
		{
			c.translate(dx, dy);
		}
		for (LineWall lw : this.linewalls)
		{
			lw.translate(dx, dy);
		}
	}

	public ContentMazeEgg clone()
	{
		Case[]     sccp;
		LineWall[] wcp;

		sccp = new Case[this.specialCases.length];
		wcp  = new LineWall[this.linewalls.length];

		for (int i = 0; i < this.specialCases.length; i++)
		{
			sccp[i] = this.specialCases[i].clone();
		}
		for (int i = 0; i < this.linewalls.length; i++)
		{
			wcp[i] = this.linewalls[i].clone();
		}
		return (new ContentMazeEgg(sccp, wcp));
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

	public Case getCase(Case.TypeCase t)
	{
		for (Case c:this.specialCases)
		{
			if (c.type == t)
			{
				return (c);
			}
		}
		return (null);
	}
}
