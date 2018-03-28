package src.model.gen;

import src.model.board.LineWall;
import src.model.board.LineWallUtils;
import src.model.ContentMaze;
import src.model.gen.ContentMazeFactory;
import src.model.gen.ContentMazeFactory.GenFactoryException;
import src.model.gen.RectMazeShift;
import src.model.MainMaze;
import src.model.MazeDimension;
import src.utils.DiscreteStatMazeGenerator;
import src.utils.DisplayMazeConsole;

import src.model.gen.CreatorHelper;

public abstract class Algo
{
	protected ContentMazeFactory[] cmfactory;

	public Algo()
	{
		this.cmfactory = null;
	}

	public ContentMaze[] getContentMaze() throws GenFactoryException
	{
		ContentMaze[] content;

		if (this.cmfactory == null)
		{
			throw new RuntimeException("Should never happen. The maze should be generated");
		}
		content = new ContentMaze[this.cmfactory.length];
		for (int i = 0; i < this.cmfactory.length; i++)
		{
			content[i] = this.cmfactory[i].getContentMaze();
		}
		return (content);
	}

	public static void main(String[] args)
	{
		System.out.println("Nothing implemented in Algo....");
	}
}
