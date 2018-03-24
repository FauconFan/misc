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

		ContentMaze   cm;
		RectMaze      rm;
		RectMazeShift rms;

		cm  = new ContentMaze(cases, lw);
		rm  = new RectMaze(cm, Math.abs(maxX - minX), Math.abs(maxY - minY));
		rms = new RectMazeShift(rm, 0, 0);

		cmf.addContentMazeShift(rms);
	}

	public MainMaze buildMainMaze(String name) throws GenFactoryException
	{
		ContentMaze   cm;
		MazeDimension md;

		LineWall[] lw;
		Case[]     cs;

		this.cmf.normalize();
		lw = this.cmf.getFinalLineWall();
		cs = this.cmf.getFinalSpecialCases();
		md = this.cmf.getMazeDimension();
		cm = new ContentMaze(cs, lw);

		return (new MainMaze(cm, md, name));
	}
}
