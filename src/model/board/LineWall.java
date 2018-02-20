package src.model.board;

import java.io.Serializable;
import java.lang.Cloneable;

import java.util.ArrayList;

import java.lang.Math;
import src.utils.FloatVector;

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

	public static LineWall buildDirectedLineWall(boolean isHorizontal, int d1, int d2, int deep)
	{
		if (isHorizontal)
		{
			return (new LineWall(d1, deep, d2, deep));
		}
		return (new LineWall(deep, d1, deep, d2));
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

	public boolean pointInWall(FloatVector point)
	{
		float erreur = 10e-5F;

		if (this.isHorizontal())
		{
			if (Math.abs(point.get(1) - this.y1) > erreur)
			{
				return (false);
			}
			if ((this.x1 <= point.get(0) && point.get(0) <= this.x2) || (this.x1 >= point.get(0) && point.get(0) >= this.x2))
			{
				return (true);
			}
		}
		else
		{
			if (Math.abs(point.get(0) - this.x1) > erreur)
			{
				return (false);
			}
			if ((this.y1 <= point.get(1) && point.get(1) <= this.y2) || (this.y1 >= point.get(1) && point.get(1) >= this.y2))
			{
				return (true);
			}
		}
		return (false);
	}

	public LineWall clone()
	{
		return (new LineWall(this.getX1(), this.getY1(), this.getX2(), this.getY2(), this.getEpaisseur()));
	}

	public boolean equals(LineWall lw)
	{
		return (this.x1 == lw.getX1() &&
				this.x2 == lw.getX2() &&
				this.y1 == lw.getY1() &&
				this.y2 == lw.getY2());
	}

	public String toString()
	{
		return ("(" + x1 + ", " + y1 + ") => (" + x2 + ", " + y2 + ")");
	}
}
