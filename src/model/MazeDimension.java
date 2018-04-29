package src.model;

import java.lang.Cloneable;
import java.util.ArrayList;

/**
 * Structure de données pour stocker les informations relatifs au sol de l'étage courant
 */
public class MazeDimension implements Cloneable
{
	public final ArrayList <RectInMaze> list_rectmaze;
	public final boolean hasPhysicalDimension;

	public MazeDimension(boolean hasPhysicalDimension)
	{
		this.list_rectmaze        = new ArrayList <>();
		this.hasPhysicalDimension = hasPhysicalDimension;
	}

	public ArrayList <RectInMaze> getListRectMaze()
	{
		return (this.list_rectmaze);
	}

	public boolean hasPhysicalDimension()
	{
		return (this.hasPhysicalDimension);
	}

	public void append(RectInMaze rim)
	{
		list_rectmaze.add(rim);
	}

	public void append(int x1, int y1, int x2, int y2)
	{
		this.append(new RectInMaze(x1, y1, x2, y2));
	}

	public MazeDimension clone()
	{
		MazeDimension mz;

		mz = new MazeDimension(this.hasPhysicalDimension);
		for (RectInMaze rim : this.list_rectmaze)
		{
			mz.append(rim.clone());
		}
		return (mz);
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

	public boolean isFloor(float x, float y)
	{
		if (hasPhysicalDimension == false)
		{
			return (false);
		}
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

	public static class RectInMaze implements Cloneable
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

		public RectInMaze clone()
		{
			return (new RectInMaze(this.x1, this.y1, this.x2, this.y2));
		}

		public int size()
		{
			return ((x2 - x1) * (y2 - y1));
		}

		public boolean contains(float x, float y)
		{
			return (x1 <= x && x < x2 && y1 <= y && y < y2);
		}

		public String toString()
		{
			return ("(" + x1 + ", " + y1 + ") => (" + x2 + ", " + y2 + ")");
		}
	}
}
