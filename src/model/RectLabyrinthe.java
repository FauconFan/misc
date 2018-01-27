package src.model;

public class RectLabyrinthe
{
	private final Case [] specialCases;
	private final LineWall [] linewalls;
	private final int size_x;
	private final int size_y;

	public RectLabyrinthe(Case[] specialCases, LineWall[] linewalls, int x, int y)
	{
		this.specialCases = specialCases;
		this.linewalls = linewalls;
		this.size_x = x;
		this.size_y = y;
	}

	public Case[] getSpecialCases()
	{
		retun (this.specialCases);
	}

	public LineWall[] getSpecialCases()
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
}
