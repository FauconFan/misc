package src.model.gen;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import src.model.board.Case;
import src.model.board.LineWall;
import src.model.ContentMaze;
import src.model.gen.RectMazeShift;

public class ContentMazeFactory
{
	private HashMap <Integer, ArrayList <LineWall> > contentX;
	private HashMap <Integer, ArrayList <LineWall> > contentY;
	private ArrayList <Case> contentSpecialCases;

	public ContentMazeFactory()
	{
		this.contentX            = new HashMap <>();
		this.contentY            = new HashMap <>();
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

	public void normalize()
	{
		normalizeEachDimension(this.contentX);
		normalizeEachDimension(this.contentY);
	}

	private void normalizeEachDimension(HashMap <Integer, ArrayList <LineWall> > content)
	{
		for (Map.Entry <Integer, ArrayList <LineWall> > entry : content.entrySet())
		{
			ArrayList <LineWall> normalized = this.normalizeList(entry.getValue());
			content.put(entry.getKey(), normalized);
		}
	}

	public ArrayList <LineWall> normalizeList(ArrayList <LineWall> list)
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

	public void addContentMazeShift(RectMazeShift cms)
	{
		ContentMaze cm = cms.getTranslatedContentMaze();

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

	public LineWall[] getFinalLineWall()
	{
		ArrayList <LineWall> all = new ArrayList <>();

		Collection <ArrayList <LineWall> > x = this.contentX.values();
		Object[] listX = x.toArray();
		for (Object al : listX)
		{
			all.addAll((ArrayList <LineWall> )al);
		}

		return (all.toArray(new LineWall[0]));
	}

	public Case[] getFinalSpecialCases()
	{
		return (this.contentSpecialCases.toArray(new Case[0]));
	}
}
