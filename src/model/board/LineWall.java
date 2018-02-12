package src.model.board;

import java.io.Serializable;
import java.lang.Cloneable;

import java.util.ArrayList;

/**
 * LineWall est la classe représentant un mur entre deux points.
 * <br>
 * Le premier étant (x1, y1) et le deuxième (x2,y2)
 */
public class LineWall implements Serializable, Cloneable
{
	public static final float EPAISSEUR_DEFAULT = 0.1f;

	private int x1;
	private int y1;
	private int x2;
	private int y2;
	private float epaisseur;

	public LineWall(int x1, int y1, int x2, int y2, float epaisseur)
	{
		if (x1 <= x2)
		{
			this.x1 = x1;
			this.x2 = x2;
		}
		else
		{
			this.x1 = x2;
			this.x2 = x1;
		}
		if (y1 <= y2)
		{
			this.y1 = y1;
			this.y2 = y2;
		}
		else
		{
			this.y1 = y2;
			this.y2 = y1;
		}
		this.epaisseur = epaisseur;
		if (x1 == x2 && y1 == y2)
		{
			throw new RuntimeException("Cannot initiate an empty LineWall");
		}
		if (x1 != x2 && y1 != y2)
		{
			throw new RuntimeException("Cannot initiate a diagonale LineWall");
		}
	}

	public LineWall(int x1, int y1, int x2, int y2)
	{
		this(x1, y1, x2, y2, EPAISSEUR_DEFAULT);
	}

	public int getX1()
	{
		return (this.x1);
	}

	public int getY1()
	{
		return (this.y1);
	}

	public int getX2()
	{
		return (this.x2);
	}

	public int getY2()
	{
		return (this.y2);
	}

	public float getEpaisseur()
	{
		return (this.epaisseur);
	}

	public int getSize()
	{
		if (this.isHorizontal())
		{
			return (Math.abs(this.x1 - this.x2));
		}
		return (Math.abs(this.y1 - this.y2));
	}

	public void translate(int dx, int dy)
	{
		this.x1 = this.x1 + dx;
		this.x2 = this.x2 + dx;
		this.y1 = this.y1 + dy;
		this.y2 = this.y2 + dy;
	}

	public boolean isHorizontal()
	{
		return (y1 == y2);
	}

	public static LineWall getIntersection(LineWall lw1, LineWall lw2)
	{
		LineWall lw;
		boolean  mode;
		int      m1;
		int      m2;
		int      n1;
		int      n2;

		if (lw1 == null || lw2 == null)
		{
			return (null);
		}
		if (lw1.isHorizontal() != lw2.isHorizontal())
		{
			return (null);
		}
		mode = lw1.isHorizontal();
		if (mode)
		{
			m1 = lw1.getX1();
			m2 = lw1.getX2();
			n1 = lw2.getX1();
			n2 = lw2.getX2();
		}
		else
		{
			m1 = lw1.getY1();
			m2 = lw1.getY2();
			n1 = lw2.getY1();
			n2 = lw2.getY2();
		}
		if ((m1 >= n1 && m1 < n2) ||
			(m2 > n1 && m2 <= n2) ||
			(n1 >= m1 && n1 < m2) ||
			(n2 > m1 && n2 <= m2))
		{
			if (mode)
			{
				lw = new LineWall(Math.max(m1, n1), lw1.getY1(), Math.min(m2, n2), lw1.getY1());
			}
			else
			{
				lw = new LineWall(lw1.getX1(), Math.max(m1, n1), lw1.getX1(), Math.min(m2, n2));
			}
			return (lw);
		}
		return (null);
	}

	public static ArrayList <LineWall> getUnion(LineWall lw1, LineWall lw2)
	{
		ArrayList <LineWall> res;
		boolean mode;
		int     m1;
		int     m2;
		int     n1;
		int     n2;

		if (lw1 == null&& lw2 == null)
		{
			return (null);
		}
		res = new ArrayList <>();
		if (lw1 == null || lw2 == null)
		{
			if (lw1 == null)
			{
				res.add(lw2);
			}
			else
			{
				res.add(lw1);
			}
			return (res);
		}
		if (lw1.isHorizontal() != lw2.isHorizontal())
		{
			res.add(lw1);
			res.add(lw2);
			return (res);
		}
		mode = lw1.isHorizontal();
		if (mode)
		{
			m1 = lw1.getX1();
			m2 = lw1.getX2();
			n1 = lw2.getX1();
			n2 = lw2.getX2();
		}
		else
		{
			m1 = lw1.getY1();
			m2 = lw1.getY2();
			n1 = lw2.getY1();
			n2 = lw2.getY2();
		}
		if ((m1 >= n1 && m1 < n2) ||
			(m2 > n1 && m2 <= n2) ||
			(n1 >= m1 && n1 < m2) ||
			(n2 > m1 && n2 <= m2))
		{
			if (mode)
			{
				res.add(new LineWall(Math.min(m1, n1), lw1.getY1(), Math.max(m2, n2), lw1.getY1()));
			}
			else
			{
				res.add(new LineWall(lw1.getX1(), Math.min(m1, n1), lw1.getX1(), Math.max(m2, n2)));
			}
			return (res);
		}
		res.add(lw1);
		res.add(lw2);
		return (res);
	}

	public ArrayList <LineWall> except(LineWall lw)
	{
		ArrayList <LineWall> res;
		LineWall             left;
		LineWall             right;
		boolean mode;
		int     m1;
		int     m2;
		int     n1;
		int     n2;

		res = new ArrayList <>();
		if (lw == null)
		{
			res.add(this);
			return (res);
		}
		if (this.isHorizontal() != lw.isHorizontal())
		{
			res.add(this);
			return (res);
		}
		mode = this.isHorizontal();
		if (mode)
		{
			m1 = this.getX1();
			m2 = this.getX2();
			n1 = lw.getX1();
			n2 = lw.getX2();
		}
		else
		{
			m1 = this.getY1();
			m2 = this.getY2();
			n1 = lw.getY1();
			n2 = lw.getY2();
		}
		if ((m1 >= n1 && m1 < n2) ||
			(m2 > n1 && m2 <= n2) ||
			(n1 >= m1 && n1 < m2) ||
			(n2 > m1 && n2 <= m2))
		{
			left  = null;
			right = null;
			if (m1 < n1)
			{
				if (mode)
				{
					left = new LineWall(m1, lw.getY1(), n1, lw.getY1());
				}
				else
				{
					left = new LineWall(lw.getX1(), m1, lw.getX1(), n1);
				}
			}
			if (m2 > n2)
			{
				if (mode)
				{
					right = new LineWall(n2, lw.getY1(), m2, lw.getY1());
				}
				else
				{
					right = new LineWall(lw.getX1(), n2, lw.getX1(), m2);
				}
			}
			if (left != null)
			{
				res.add(left);
			}
			if (right != null)
			{
				res.add(right);
			}
			return (res);
		}
		res.add(this);
		return (res);
	}

	public boolean pointInWall(int x, int y)
	{
		if (isHorizontal())
		{
			if (y != y1)
			{
				return (false);
			}
			else if ((x1 > x && x2 > x) || (x1 < x && x2 < x))
			{
				return (false);
			}
		}
		else
		{
			if (x != x1)
			{
				return (false);
			}
			else if ((y1 > y && y2 > y) || (y1 < y && y2 < y))
			{
				return (false);
			}
		}
		return (true);
	}

	public LineWall clone()
	{
		return (new LineWall(this.getX1(), this.getY1(), this.getX2(), this.getY2(), this.getEpaisseur()));
	}

	public String toString()
	{
		return ("(" + x1 + ", " + y1 + ") => (" + x2 + ", " + y2 + ")");
	}
}
