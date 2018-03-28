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

	public int size()
	{
		int res = 0;

		for (RectInMaze rim : this.list_rectmaze)
		{
			res += rim.size();
		}
		return (res);
	}

	public boolean isFloor(int x, int y)
	{
		for (RectInMaze r : list_rectmaze)
		{
			if (r.contains(x, y))
			{
				return (true);
			}
		}
		return (false);
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
			if (x1 < x2)
			{
				this.x1 = x1;
				this.x2 = x2;
			}
			else
			{
				this.x2 = x1;
				this.x1 = x2;
			}
			if (y1 < y2)
			{
				this.y1 = y1;
				this.y2 = y2;
			}
			else
			{
				this.y2 = y1;
				this.y1 = y2;
			}
		}

		public int size()
		{
			return ((x2 - x1) * (y2 - y1));
		}

		public boolean contains(int x, int y)
		{
			return (x1 <= x && x <= x2 && y1 <= y && y <= y2);
		}

		public String toString()
		{
			return ("(" + x1 + ", " + y1 + ") => (" + x2 + ", " + y2 + ")");
		}
	}
}
