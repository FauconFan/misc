package src.model.gen;

import src.model.board.LineWall;
import src.model.board.LineWallUtils;
import src.model.ContentMaze;
import src.model.gen.ContentMazeFactory;
import src.model.gen.MainMazeFactory.GenFactoryException;
import src.model.gen.RectMazeShift;
import src.model.MainMaze;
import src.model.MazeDimension;
import src.utils.DiscreteStatMazeGenerator;
import src.utils.DisplayMazeConsole;

import src.model.gen.CreatorHelper;

public abstract class Algo
{
	protected MainMazeFactory mmfactory;

	public Algo()
	{
		this.mmfactory = null;
	}

	public ContentMaze[] getContentMaze() throws GenFactoryException
	{
		ContentMaze[] content;

		if (this.mmfactory == null)
		{
			throw new RuntimeException("Should never happen. The maze should be generated");
		}
		content = this.mmfactory.buildContentMaze();
		return (content);
	}

	public static void main(String[] args)
	{
		System.out.println("Nothing implemented in Algo....");
	}
}
