package src.model.gen;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import src.model.board.Case;
import src.model.board.LineWall;
import src.model.ContentMaze;
import src.model.gen.RectMazeShift;

public class ContentMazeFactory
{
	private HashMap <Integer, ArrayList <LineWall> > contentX;
	private HashMap <Integer, ArrayList <LineWall> > contentY;
	private ArrayList <Case> contentSpecialCases;

	public ContentMazeFactory()
	{
		this.contentX            = new HashMap <>();
		this.contentY            = new HashMap <>();
		this.contentSpecialCases = new ArrayList <>();
	}

	public void addWall(LineWall lw)
	{
		if (lw.getX1() == lw.getX2())
		{
			if (contentX.containsKey(lw.getX1()) == false)
			{
				this.contentX.put(lw.getX1(), new ArrayList <LineWall>());
			}
			this.contentX.get(lw.getX1()).add(lw);
		}
		else if (lw.getY1() == lw.getY2())
		{
			if (contentX.containsKey(lw.getY1()) == false)
			{
				this.contentX.put(lw.getY1(), new ArrayList <LineWall>());
			}
			this.contentX.get(lw.getY1()).add(lw);
		}
		else
		{
			throw new RuntimeException("We suppose that we have only horizontal or vertical walls");
		}
	}

	public void addSpecialCase(Case c)
	{
		this.contentSpecialCases.add(c);
	}

	public void addContentMazeShift(RectMazeShift cms)
	{
		ContentMaze cm = cms.getTranslatedContentMaze();

		LineWall[] lw = cm.getLineWalls();
		for (LineWall l : lw)
		{
			this.addWall(l);
		}
		Case[] cs = cm.getSpecialCases();
		for (Case c : cs)
		{
			this.addSpecialCase(c);
		}
	}

	public LineWall[] getFinalLineWall()
	{
		ArrayList <LineWall> all = new ArrayList <>();

		Collection <ArrayList <LineWall> > x = this.contentX.values();
		Object[] listX = x.toArray();
		for (Object al : listX)
		{
			all.addAll((ArrayList <LineWall> )al);
		}

		return (all.toArray(new LineWall[0]));
	}

	public Case[] getFinalSpecialCases()
	{
		return (this.contentSpecialCases.toArray(new Case[0]));
	}
}
