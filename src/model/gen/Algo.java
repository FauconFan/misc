package src.model.gen;

import src.model.board.LineWall;
import src.model.ContentMaze;
import src.model.gen.ContentMazeFactory;
import src.model.gen.RectMazeShift;
import src.model.MainMaze;
import src.utils.DiscreteStatMazeGenerator;
import src.utils.DisplayMazeConsole;

public abstract class Algo
{
	protected ContentMaze cm;
	protected ContentMazeFactory cmfactory;

	public Algo()
	{
		this.cm        = null;
		this.cmfactory = null;
	}

	public ContentMaze getContentMaze()
	{
		if (this.cm == null)
		{
			throw new RuntimeException("Should never happen. The maze should be generated");
		}
		return (this.cm);
	}

	public static void main(String[] args)
	{
		MainMaze ml;
		Algo     al;

		al = new AlgoSample2();
		ml = new MainMaze(al, 0);
		ml.displayMaze();
	}
}
