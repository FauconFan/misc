package src.model.gen;

import src.model.board.Case;
import src.model.board.LineWall;
import src.model.ContentMaze;
import src.model.gen.ContentMazeFactory.GenFactoryException;
import src.model.gen.RectMazeShift;
import src.model.MainMaze;
import src.model.MazeDimension;

public class CreatorHelper
{
	private ContentMazeFactory cmf;

	public CreatorHelper(int minX, int maxX, int minY, int maxY, LineWall[] lw, Case[] cases)
	{
		cmf = new ContentMazeFactory();
		cmf.addContentMazeShift(new RectMazeShift(new RectMaze(new ContentMaze(cases, lw), Math.abs(maxX - minX), Math.abs(maxY - minY)), 0, 0));
	}

	public MainMaze buildMainMaze(String name) throws GenFactoryException
	{
		this.cmf.normalize();
		return (new MainMaze(new ContentMaze(this.cmf.getFinalSpecialCases(), this.cmf.getFinalLineWall()), this.cmf.getMazeDimension(), name));
	}
}
