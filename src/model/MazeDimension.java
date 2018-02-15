package src.model;

import java.util.ArrayList;

public class MazeDimension
{
	public final ArrayList <RectInMaze> list_rectmaze;

	public MazeDimension()
	{
		this.list_rectmaze = new ArrayList <>();
	}

	public ArrayList <RectInMaze> getListRectMaze()
	{
		return (this.list_rectmaze);
	}

	public void append(int x1, int y1, int x2, int y2)
	{
		list_rectmaze.add(new RectInMaze(x1, y1, x2, y2));
	}

	public String toString()
	{
		String str = "";

		for (RectInMaze si : list_rectmaze)
		{
			str += si + "\n";
		}
		return (str);
	}

	public static class RectInMaze
	{
		public final int x1;
		public final int y1;
		public final int x2;
		public final int y2;

		public RectInMaze(int x1, int y1, int x2, int y2)
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
