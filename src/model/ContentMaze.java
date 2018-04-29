package src.model;

import src.model.board.*;
import src.utils.StringManipulation;

/**
 * Structure de données pour un nouveau du labyrinthe
 */
public class ContentMaze
{
	private Case[] specialCases;
	private LineWall[] linewalls;
	private MazeDimension mazeDim;
	private String wallTexturePath, floorTexturePath;

	public ContentMaze(Case[] sc, LineWall[] w, MazeDimension mz)
	{
		this.specialCases = sc;
		this.linewalls    = w;
		this.mazeDim      = mz;
	}

	public Case[] getSpecialCases()
	{
		return (this.specialCases);
	}

	public LineWall[] getLineWalls()
	{
		return (this.linewalls);
	}

	public MazeDimension getMazeDimension()
	{
		return (this.mazeDim);
	}

	public boolean isFloor(float x, float y)
	{
		return (mazeDim.isFloor(x, y));
	}

	public ContentMaze clone()
	{
		Case[]        sccp;
		LineWall[]    wcp;
		MazeDimension mzcp;

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
		mzcp = this.mazeDim.clone();
		return (new ContentMaze(sccp, wcp, mzcp));
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

	public boolean isWall(float x, float y, float hitBox)
	{
		for (LineWall lw : linewalls)
		{
			if (lw.playerInWall(x, y, hitBox))
			{
				return (true);
			}
		}
		return (false);
	}

	public String getWallTexturePath()
	{
		return (this.wallTexturePath);
	}

	public void setWallTexturePath(String s)
	{
		this.wallTexturePath = s;
	}

	public String getFloorTexturePath()
	{
		return (this.floorTexturePath);
	}

	public void setFloorTexturePath(String s)
	{
		this.floorTexturePath = s;
	}
}
