package src.model.gen;

import src.model.board.Case;
import src.model.board.LineWall;
import src.model.ContentMaze;
import src.model.gen.ContentMazeEgg;
import src.model.gen.ContentMazeFactory.GenFactoryException;
import src.model.gen.RectMazeShift;
import src.model.MainMaze;
import src.model.MazeDimension;

public class CreatorHelper
{
	private ContentMazeFactory[] cmf;

	public CreatorHelper(int ma)
	{
		this.cmf = new ContentMazeFactory[ma];
	}

	public void append(int level_actu, int minX, int maxX, int minY, int maxY, LineWall[] lw, Case[] cases)
	{
		cmf[level_actu] = new ContentMazeFactory();
		cmf[level_actu].addContentMazeShift(new RectMazeShift(new RectMaze(new ContentMazeEgg(cases, lw), Math.abs(maxX - minX), Math.abs(maxY - minY)), 0, 0));
	}

	public MainMaze buildMainMaze(String name) throws GenFactoryException
	{
		ContentMaze[] cm;

		for (int i = 0; i < cmf.length; i++)
		{
			this.cmf[i].normalize();
		}
		cm = new ContentMaze[this.cmf.length];
		for (int i = 0; i < this.cmf.length; i++)
		{
			cm[i] = this.cmf[i].getContentMaze();
		}
		return (new MainMaze(cm));
	}
}
