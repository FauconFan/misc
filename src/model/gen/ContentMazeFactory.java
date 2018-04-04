package src.model.gen;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Set;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.LineWall;
import src.model.board.LineWallUtils;
import src.model.board.SpeedCase;
import src.model.board.StartCase;
import src.model.board.TeleportCase;
import src.model.board.TimeCase;
import src.model.ContentMaze;
import src.model.gen.RectMazeShift;
import src.model.MazeDimension;
import src.model.MazeDimension.RectInMaze;
import src.utils.DiscreteStatMazeGenerator;

public class ContentMazeFactory
{
	private MazeDimension mazeDim;
	private HashMap <Integer, ArrayList <LineWall> > contentX;
	private HashMap <Integer, ArrayList <LineWall> > contentY;
	private HashMap <Integer, ArrayList <LineWall> > listDoorsX;
	private HashMap <Integer, ArrayList <LineWall> > listDoorsY;
	private ArrayList <Case> contentSpecialCases;

	public ContentMazeFactory()
	{
		this.mazeDim             = new MazeDimension();
		this.contentX            = new HashMap <>();
		this.contentY            = new HashMap <>();
		this.listDoorsX          = new HashMap <>();
		this.listDoorsY          = new HashMap <>();
		this.contentSpecialCases = new ArrayList <>();
	}

	public void addWall(LineWall lw)
	{
		if (lw.getX1() == lw.getX2())
		{
			if (contentX.containsKey(lw.getX1()) == false)
			{
				this.contentX.put(lw.getX1(), new ArrayList <LineWall>());
			}
			this.contentX.get(lw.getX1()).add(lw);
		}
		else if (lw.getY1() == lw.getY2())
		{
			if (contentY.containsKey(lw.getY1()) == false)
			{
				this.contentY.put(lw.getY1(), new ArrayList <LineWall>());
			}
			this.contentY.get(lw.getY1()).add(lw);
		}
		else
		{
			throw new RuntimeException("We suppose that we have only horizontal or vertical walls");
		}
	}

	public void addSpecialCase(Case c)
	{
		this.contentSpecialCases.add(c);
	}

	public void addContentMazeShift(RectMazeShift cms)
	{
		int x1;
		int x2;
		int y1;
		int y2;

		x1 = cms.getDX();
		x2 = cms.getRectMazeSizeX() + x1;
		y1 = cms.getDY();
		y2 = cms.getRectMazeSizeY() + y1;

		this.mazeDim.append(x1, y1, x2, y2);
		verifyIfMazeGenerationIsValid(cms, x1, x2, y1, y2);
		addingDoors(cms, x1, x2, y1, y2);
		reallyAddRectMazeShift(cms);
	}

	private void verifyIfMazeGenerationIsValid(RectMazeShift cms, int x1, int x2, int y1, int y2)
	{
		for (int i = x1 + 1; i < x2; i++)
		{
			ArrayList <LineWall> li = this.contentX.get(i);
			if (li != null)
			{
				for (LineWall lw : li)
				{
					if (((y1 >= lw.getY1() && y1 >= lw.getY2()) ||
						 (y2 <= lw.getY1() && y2 <= lw.getY2())) == false)
					{
						throw new RuntimeException("Maze Generation Not Valid");
					}
				}
			}
		}
		for (int j = y1 + 1; j < y2; j++)
		{
			ArrayList <LineWall> li = this.contentY.get(j);
			if (li != null)
			{
				for (LineWall lw : li)
				{
					if (((x1 >= lw.getX1() && x1 >= lw.getX2()) ||
						 (x2 <= lw.getX1() && x2 <= lw.getX2())) == false)
					{
						throw new RuntimeException("Maze Generation Not Valid");
					}
				}
			}
		}
	}

	private void addingDoors(RectMazeShift cms, int x1, int x2, int y1, int y2)
	{
		// Handle row x1
		ArrayList <LineWall> li;

		li = new ArrayList <>();

		li.addAll(calculateIntersection(this.contentX.get(x1), new LineWall(x1, y1, x1, y2)));
		li.addAll(calculateIntersection(this.contentX.get(x2), new LineWall(x2, y1, x2, y2)));
		li.addAll(calculateIntersection(this.contentY.get(y1), new LineWall(x1, y1, x2, y1)));
		li.addAll(calculateIntersection(this.contentY.get(y2), new LineWall(x1, y2, x2, y2)));
		for (LineWall lw : li)
		{
			LineWall lres;
			int      nb_door;
			int[]    index_doors;
			boolean  mode;

			nb_door     = (lw.getSize() - 1) / 5 + 1;
			index_doors = DiscreteStatMazeGenerator.getKParmiN(nb_door, lw.getSize());
			mode        = lw.isHorizontal();
			for (int i : index_doors)
			{
				if (mode)
				{
					lres = new LineWall(lw.getX1() + i - 1, lw.getY1(), lw.getX1() + i, lw.getY1());
					if (this.listDoorsY.containsKey(lw.getY1()) == false)
					{
						this.listDoorsY.put(lw.getY1(), new ArrayList <LineWall>());
					}
					this.listDoorsY.get(lw.getY1()).add(lres);
				}
				else
				{
					lres = new LineWall(lw.getX1(), lw.getY1() + i - 1, lw.getX1(), lw.getY1() + i);
					if (this.listDoorsX.containsKey(lw.getX1()) == false)
					{
						this.listDoorsX.put(lw.getX1(), new ArrayList <LineWall>());
					}
					this.listDoorsX.get(lw.getX1()).add(lres);
				}
			}
		}
	}

	private ArrayList <LineWall> calculateIntersection(ArrayList <LineWall> content, LineWall actu)
	{
		ArrayList <LineWall> result;

		result = new ArrayList <>();
		if (content != null)
		{
			for (LineWall lw : content)
			{
				LineWall linter;

				linter = LineWallUtils.intersection(lw, actu);
				if (linter != null)
				{
					result.add(linter);
				}
			}
		}
		return (result);
	}

	private void reallyAddRectMazeShift(RectMazeShift cms)
	{
		ContentMazeEgg cm;

		cm = cms.getTranslatedContentMaze();
		LineWall[] lw = cm.getLineWalls();
		for (LineWall l : lw)
		{
			this.addWall(l);
		}
		Case[] cs = cm.getSpecialCases();
		for (Case c : cs)
		{
			this.addSpecialCase(c);
		}
	}

	/**
	 * Normalizing ContentMaze
	 */

	public void normalize()
	{
		normalizeEachDimension(this.contentX, this.listDoorsX);
		normalizeEachDimension(this.contentY, this.listDoorsY);
		normalizeSpecialCases();
	}

	private void normalizeEachDimension(HashMap <Integer, ArrayList <LineWall> > content, HashMap <Integer, ArrayList <LineWall> > list_doors)
	{
		ArrayList <LineWall> normalized;
		ArrayList <LineWall> doors;
		ArrayList <LineWall> tmp;
		ArrayList <LineWall> res_tmp;
		int old_size;

		for (Map.Entry <Integer, ArrayList <LineWall> > entry : content.entrySet())
		{
			normalized = this.normalizeList(entry.getValue());
			doors      = list_doors.get(entry.getKey());
			if (doors != null)
			{
				res_tmp = new ArrayList <>();
				for (LineWall wall : normalized)
				{
					tmp = new ArrayList <>();
					tmp.add(wall);
					while (true)
					{
						old_size = tmp.size();
						for (int i = 0; i < tmp.size(); i++)
						{
							for (LineWall door : doors)
							{
								ArrayList <LineWall> ahah = LineWallUtils.except(tmp.get(i), door);
								tmp.addAll(ahah);
								tmp.remove(i);
							}
						}
						if (old_size == tmp.size())
						{
							break;
						}
					}
					res_tmp.addAll(tmp);
				}
				normalized = res_tmp;
			}
			content.put(entry.getKey(), normalized);
		}
	}

	private ArrayList <LineWall> normalizeList(ArrayList <LineWall> list)
	{
		ArrayList <LineWall> res = new ArrayList <>();
		boolean modeX;

		if (list.size() == 0)
		{
			return (res);
		}
		modeX = (list.get(0).getX1() == list.get(0).getX2());
		while (list.size() != 0)
		{
			LineWall actu;
			int      maxActu;
			int      minActu;
			boolean  isFinished;

			actu = list.get(0);
			list.remove(0);
			maxActu    = ((modeX) ? Math.max(actu.getY1(), actu.getY2()) : Math.max(actu.getX1(), actu.getX2()));
			minActu    = ((modeX) ? Math.min(actu.getY1(), actu.getY2()) : Math.min(actu.getX1(), actu.getX2()));
			isFinished = false;
			while (isFinished == false)
			{
				isFinished = true;
				for (int i = 0; i < list.size(); i++)
				{
					LineWall tested;
					int      maxTested;
					int      minTested;

					tested    = list.get(i);
					maxTested = ((modeX) ? Math.max(tested.getY1(), tested.getY2()) : Math.max(tested.getX1(), tested.getX2()));
					minTested = ((modeX) ? Math.min(tested.getY1(), tested.getY2()) : Math.min(tested.getX1(), tested.getX2()));
					if ((maxTested >= minActu && maxTested <= maxActu) || (minTested >= minActu && minTested <= maxActu))
					{
						isFinished = false;
						LineWall fusion;
						if (modeX)
						{
							fusion = new LineWall(
								actu.getX1(),
								Math.min(minTested, minActu),
								actu.getX2(),
								Math.max(maxTested, maxActu),
								Math.max(actu.getEpaisseur(), tested.getEpaisseur()));
						}
						else
						{
							fusion = new LineWall(
								Math.min(minTested, minActu),
								actu.getY1(),
								Math.max(maxTested, maxActu),
								actu.getY2(),
								Math.max(actu.getEpaisseur(), tested.getEpaisseur()));
						}
						actu = fusion;
						list.remove(i);
						i--;
					}
				}
			}
			res.add(actu);
		}
		return (res);
	}

	private void normalizeSpecialCases()
	{
		Case c;
		Case tmp;

		for (int i = 0; i < this.contentSpecialCases.size(); i++)
		{
			c = this.contentSpecialCases.get(i);
			for (int j = i + 1; j < this.contentSpecialCases.size(); j++)
			{
				tmp = this.contentSpecialCases.get(j);
				if (c.equals(tmp))
				{
					this.contentSpecialCases.remove(j);
					j--;
					continue;
				}
			}
		}
	}

	private Point genRandomPoint(Random ran, ArrayList <RectInMaze> li, ArrayList <Point> oldPoints)
	{
		Point      res;
		RectInMaze rim;
		int        x;
		int        y;

		rim = li.get(ran.nextInt(li.size()));
		x   = ran.nextInt(rim.x2 - rim.x1) + rim.x1;
		y   = ran.nextInt(rim.y2 - rim.y1) + rim.y1;
		res = new Point(x, y);
		if (oldPoints.contains(res))
		{
			return (genRandomPoint(ran, li, oldPoints));
		}
		oldPoints.add(res);
		return (res);
	}

	public void initiateSpecialCases()
	{
		ArrayList <Point>      oldPoints;
		ArrayList <RectInMaze> li;
		RectInMaze             rim;
		Random ran;
		int    x;
		int    y;
		int    max;
		Point  tmp;
		Point  tmp2;

		ran       = new Random();
		li        = this.mazeDim.getListRectMaze();
		oldPoints = new ArrayList <>();

		tmp = this.genRandomPoint(ran, li, oldPoints);
		this.contentSpecialCases.add(new StartCase(tmp.x, tmp.y));
		tmp = this.genRandomPoint(ran, li, oldPoints);
		this.contentSpecialCases.add(new EndCase(tmp.x, tmp.y));

		max = 0;
		if (this.mazeDim.size() >= 200)
		{
			max = 3;
		}
		else if (this.mazeDim.size() >= 100)
		{
			max = 2;
		}
		for (int i = 0; i < max; i++)
		{
			tmp = this.genRandomPoint(ran, li, oldPoints);
			this.contentSpecialCases.add(new SpeedCase(tmp.x, tmp.y, 0.5f));
			tmp = this.genRandomPoint(ran, li, oldPoints);
			this.contentSpecialCases.add(new TimeCase(tmp.x, tmp.y, 1000));
			tmp  = this.genRandomPoint(ran, li, oldPoints);
			tmp2 = this.genRandomPoint(ran, li, oldPoints);
			this.contentSpecialCases.add(new TeleportCase(tmp.x, tmp.y, tmp2.x, tmp2.y));
		}
	}

	/**
	 * Final Getters for deploying ContentMaze
	 * @return LineWall[] and Case[]
	 */

	private LineWall[] getFinalLineWall()
	{
		ArrayList <LineWall> all = new ArrayList <>();

		Collection <ArrayList <LineWall> > x = this.contentX.values();
		for (ArrayList <LineWall> al : x)
		{
			all.addAll(al);
		}
		Collection <ArrayList <LineWall> > y = this.contentY.values();
		for (ArrayList <LineWall> al : y)
		{
			all.addAll(al);
		}
		return (all.toArray(new LineWall[0]));
	}

	private Case[] getFinalSpecialCases()
	{
		return (this.contentSpecialCases.toArray(new Case[0]));
	}

	private MazeDimension getMazeDimension()
	{
		return (this.mazeDim);
	}

	public ContentMaze getContentMaze()
	{
		return (new ContentMaze(this.getFinalSpecialCases(), this.getFinalLineWall(), getMazeDimension()));
	}

	private static class Point
	{
		public int x;
		public int y;

		public Point(int x, int y)
		{
			this.x = x;
			this.y = y;
		}

		public boolean isEquals(Point pt)
		{
			return (this.x == pt.x && this.y == pt.y);
		}
	}
}
