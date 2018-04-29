package src.model.gen;

import src.model.board.Case;
import src.model.ContentMaze;

/**
 * Class for simplify, manage and handle queries for building a Level of a Maze (Working with ContentMazeFactory)
 */
public class MainMazeFactory
{
	public ContentMazeFactory[] list_contenmaze_factory;

	public MainMazeFactory(int nb_level)
	{
		this.list_contenmaze_factory = new ContentMazeFactory[nb_level];
	}

	public void setContentMazeFactory(ContentMazeFactory cmf, int i)
	{
		this.list_contenmaze_factory[i] = cmf;
	}

	public ContentMaze[] buildContentMaze() throws GenFactoryException
	{
		ContentMaze[] cm;
		boolean       hasEndCase;
		int           nbStartCase;

		nbStartCase = 0;
		hasEndCase  = false;
		cm          = new ContentMaze[list_contenmaze_factory.length];
		for (int i = 0; i < list_contenmaze_factory.length; i++)
		{
			this.list_contenmaze_factory[i].normalize();
			cm[i] = this.list_contenmaze_factory[i].getContentMaze();

			for (Case cs : cm[i].getSpecialCases())
			{
				switch (cs.getType())
				{
				case START: nbStartCase++; break;

				case END: hasEndCase = true; break;

				default: break;
				}
			}
		}
		if (nbStartCase != 1 || hasEndCase == false)
		{
			throw new GenFactoryException("This implementation doesn't have a single StartCase or at least one EndCase");
		}
		return (cm);
	}

	public static class GenFactoryException extends Exception
	{
		private static final long serialVersionUID = 0x4615992428470203L;

		public GenFactoryException(String message)
		{
			super(message);
		}
	}
}
