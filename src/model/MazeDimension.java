package src.model;

import java.util.ArrayList;

public class MazeDimension
{
	public ArrayList <SquareInMaze> list_rectmaze;

	public MazeDimension()
	{
		this.list_rectmaze = new ArrayList <>();
	}

	public void append(int x1, int y1, int x2, int y2)
	{
		list_rectmaze.add(new SquareInMaze(x1, y1, x2, y2));
	}

	public String toString()
	{
		String str = "";

		for (SquareInMaze si : list_rectmaze)
		{
			str += si + "\n";
		}
		return (str);
	}

	public static class SquareInMaze
	{
		public int x1;
		public int y1;
		public int x2;
		public int y2;

		public SquareInMaze(int x1, int y1, int x2, int y2)
		{
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}

		public String toString()
		{
			return ("(" + x1 + ", " + y1 + ") => (" + x2 + ", " + y2 + ")");
		}
	}
}
