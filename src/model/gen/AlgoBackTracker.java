package src.model.gen;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Random;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.LineWall;
import src.model.board.LineWallUtils;
import src.model.board.StartCase;
import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.gen.ContentMazeFactory;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

public class AlgoBackTracker extends Algo
{
	public AlgoBackTracker()
	{
		super();
		this.cmfactory = new ContentMazeFactory();

		RectMaze rm = buildRect(true, true);

		RectMazeShift rms = new RectMazeShift(rm, 0, 0);

		this.cmfactory.addContentMazeShift(rms);

		this.cmfactory.normalize();
		this.cm = new ContentMaze(this.cmfactory.getFinalSpecialCases(), this.cmfactory.getFinalLineWall());
	}

	public RectMaze buildRect(boolean hasStartCase, boolean hasEndCase)
	{
		RectMaze rm;

		Case[]     listSpecialeCases;
		LineWall[] listWalls;
		int        size_x = 100;
		int        size_y = 20;

		listSpecialeCases = this.buildCases(hasStartCase, hasEndCase);
		listWalls         = this.buildWalls(size_x, size_y);
		rm = new RectMaze(new ContentMaze(listSpecialeCases, listWalls), size_x, size_y);
		return (rm);
	}

	private Case[] buildCases(boolean hasStartCase, boolean hasEndCase)
	{
		Case[] listSpecialeCases;

		if (hasStartCase && hasEndCase)
		{
			listSpecialeCases    = new Case[2];
			listSpecialeCases[0] = new StartCase(2, 2);
			listSpecialeCases[1] = new EndCase(8, 8);
		}
		else if (hasStartCase || hasEndCase)
		{
			listSpecialeCases = new Case[1];
			if (hasStartCase)
			{
				listSpecialeCases[0] = new StartCase(2, 2);
			}
			else
			{
				listSpecialeCases[0] = new EndCase(8, 8);
			}
		}
		else
		{
			listSpecialeCases = new Case[0];
		}
		return (listSpecialeCases);
	}

	private LineWall[] buildWalls(int size_x, int size_y)
	{
		HashMap <Integer, ArrayList <LineWall> > list_X = new HashMap <>();
		HashMap <Integer, ArrayList <LineWall> > list_Y = new HashMap <>();
		ArrayList <LineWall> final_res       = new ArrayList <>();
		ArrayList <Point>    unvisited_cases = new ArrayList <>();
		Point  current_position_agent        = null;
		Random ran = new Random();

		// Initialize Walls : Fill it
		for (int i = 0; i <= size_y; i++)
		{
			ArrayList <LineWall> tmp = new ArrayList <>();
			tmp.add(LineWall.buildDirectedLineWall(true, 0, size_x, i));
			list_X.put(i, tmp);
		}

		for (int j = 0; j <= size_x; j++)
		{
			ArrayList <LineWall> tmp = new ArrayList <>();
			tmp.add(LineWall.buildDirectedLineWall(false, 0, size_y, j));
			list_Y.put(j, tmp);
		}

		for (int i = 0; i < size_y; i++)
		{
			for (int j = 0; j < size_x; j++)
			{
				unvisited_cases.add(new Point(i, j));
			}
		}

		current_position_agent = Point.getArrayList(unvisited_cases, ran.nextInt(size_y), ran.nextInt(size_x));
		unvisited_cases.remove(current_position_agent);

		// Recursive Backtracking Algorithm

		while (unvisited_cases.isEmpty() == false)
		{
			ArrayList <Point> neighborhoods = new ArrayList <>();
			Point             ptLeft;
			Point             ptRight;
			Point             ptUp;
			Point             ptDown;

			ptLeft  = Point.getArrayListLeft(unvisited_cases, current_position_agent);
			ptRight = Point.getArrayListRight(unvisited_cases, current_position_agent);
			ptUp    = Point.getArrayListUp(unvisited_cases, current_position_agent);
			ptDown  = Point.getArrayListDown(unvisited_cases, current_position_agent);

			if (ptLeft != null)
			{
				neighborhoods.add(ptLeft);
			}
			if (ptRight != null)
			{
				neighborhoods.add(ptRight);
			}
			if (ptUp != null)
			{
				neighborhoods.add(ptUp);
			}
			if (ptDown != null)
			{
				neighborhoods.add(ptDown);
			}

			if (neighborhoods.isEmpty())
			{
				current_position_agent = Point.getRandomWhenNoNeighboors(unvisited_cases, size_y, size_x);
				continue;
			}

			Point next = neighborhoods.get(ran.nextInt(neighborhoods.size()));
			unvisited_cases.remove(next);
			Point.removeWalls(list_Y, list_X, current_position_agent, next);
			current_position_agent = next;
		}

		// Build the answer
		Collection <ArrayList <LineWall> > content_y = list_Y.values();
		Object[] content_y2 = content_y.toArray();
		for (Object obj : content_y2)
		{
			final_res.addAll((ArrayList <LineWall> )obj);
		}

		Collection <ArrayList <LineWall> > content_x = list_X.values();
		Object[] content_x2 = content_x.toArray();
		for (Object obj : content_x2)
		{
			final_res.addAll((ArrayList <LineWall> )obj);
		}

		return (final_res.toArray(new LineWall[0]));
	}

	private static class Point
	{
		public int y;
		public int x;

		public Point(int y, int x)
		{
			this.y = y;
			this.x = x;
		}

		public String toString()
		{
			return ("(" + x + ", " + y + ")");
		}

		public boolean onSameRow(Point pt)
		{
			return (this.y == pt.y);
		}

		public static Point getArrayList(ArrayList <Point> arr, int y, int x)
		{
			for (Point pt : arr)
			{
				if (pt.y == y && pt.x == x)
				{
					return (pt);
				}
			}
			return (null);
		}

		public static Point getArrayListLeft(ArrayList <Point> arr, Point pt)
		{
			return (Point.getArrayList(arr, pt.y, pt.x - 1));
		}

		public static Point getArrayListRight(ArrayList <Point> arr, Point pt)
		{
			return (Point.getArrayList(arr, pt.y, pt.x + 1));
		}

		public static Point getArrayListUp(ArrayList <Point> arr, Point pt)
		{
			return (Point.getArrayList(arr, pt.y - 1, pt.x));
		}

		public static Point getArrayListDown(ArrayList <Point> arr, Point pt)
		{
			return (Point.getArrayList(arr, pt.y + 1, pt.x));
		}

		public static LineWall getBetweenPoints(Point pt1, Point pt2)
		{
			boolean horizontal;

			horizontal = pt1.onSameRow(pt2);
			if (horizontal)
			{
				if (pt1.x > pt2.x)
				{
					return (getBetweenPoints(pt2, pt1));
				}
				return (new LineWall(pt2.x, pt2.y, pt2.x, pt2.y + 1));
			}
			if (pt1.y > pt2.y)
			{
				return (getBetweenPoints(pt2, pt1));
			}
			return (new LineWall(pt2.x, pt2.y, pt2.x + 1, pt2.y));
		}

		public static void removeWalls(HashMap <Integer, ArrayList <LineWall> > list_walls_Y, HashMap <Integer, ArrayList <LineWall> > list_walls_X, Point pt1, Point pt2)
		{
			HashMap <Integer, ArrayList <LineWall> > list_walls;
			ArrayList <LineWall> list;
			LineWall             toRemove;
			boolean isHorizontal;

			isHorizontal = pt1.onSameRow(pt2);
			if (isHorizontal == false)
			{
				list_walls = list_walls_X;
			}
			else
			{
				list_walls = list_walls_Y;
			}
			toRemove = Point.getBetweenPoints(pt1, pt2);
			list     = list_walls.get(toRemove.isHorizontal() ? toRemove.getY1() : toRemove.getX1());
			if (list == null)
			{
				return;
			}
			for (int i = 0; i < list.size(); i++)
			{
				LineWall             lw       = list.get(i);
				ArrayList <LineWall> excepted = LineWallUtils.except(lw, toRemove);
				if ((excepted.size() == 1 && excepted.get(0).equals(lw)) == false)
				{
					list.remove(lw);
					list.addAll(excepted);
					return;
				}
			}
		}

		public static Point getRandomWhenNoNeighboors(ArrayList <Point> unvisited_cases, int size_y, int size_x)
		{
			Point  res;
			Point  tmp;
			Random ran = new Random();

			tmp = unvisited_cases.get(ran.nextInt(unvisited_cases.size()));
			if (tmp.y > 0 && getArrayListUp(unvisited_cases, tmp) == null)
			{
				return (new Point(tmp.y - 1, tmp.x));
			}
			else if (tmp.x > 0 && getArrayListLeft(unvisited_cases, tmp) == null)
			{
				return (new Point(tmp.y, tmp.x - 1));
			}
			else if (tmp.y < size_y - 1 && getArrayListDown(unvisited_cases, tmp) == null)
			{
				return (new Point(tmp.y + 1, tmp.x));
			}
			else if (tmp.x < size_x - 1 && getArrayListRight(unvisited_cases, tmp) == null)
			{
				return (new Point(tmp.y, tmp.x + 1));
			}
			return (getRandomWhenNoNeighboors(unvisited_cases, size_y, size_x));
		}
	}
}
