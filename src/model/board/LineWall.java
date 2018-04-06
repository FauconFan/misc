package src.model.board;

import com.google.gson.*;

import java.lang.Cloneable;
import java.lang.reflect.Type;

import java.util.ArrayList;

import java.lang.Math;
import java.util.ArrayList;
import src.utils.FloatVector;

/**
 * LineWall est la classe représentant un mur entre deux points.
 * <br>
 * Le premier étant (x1, y1) et le deuxième (x2,y2)
 */
public class LineWall implements Cloneable
{
	private static final float EPAISSEUR_DEFAULT = 0.1f;

	private int x1;
	private int y1;
	private int x2;
	private int y2;
	private float epaisseur;
	private boolean isLadder;

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

	public static float getEpaisseurDefault()
	{
		return (EPAISSEUR_DEFAULT);
	}

	public int getSize()
	{
		if (this.isHorizontal())
		{
			return (Math.abs(this.x1 - this.x2));
		}
		return (Math.abs(this.y1 - this.y2));
	}

	public boolean isWallLadder()
	{
		return (this.isLadder);
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

	public boolean onSameLine(LineWall lw)
	{
		boolean min;
		boolean oth;

		min = this.isHorizontal();
		oth = lw.isHorizontal();
		return ((min != oth ||
				 (min && oth && this.getY1() != lw.getY1()) ||
				 (min == false && oth == false && this.getX1() != lw.getX1())) == false);
	}

	public float effectiveEpaisseur(float x, float y)
	{
		if (this.isHorizontal())
		{
			return (((this.y1 < y) ? 1 : -1) * epaisseur);
		}
		else
		{
			return (((this.x1 < x) ? 1 : -1) * epaisseur);
		}
	}

	public FloatVector [][] effWalls(float x, float y)
	{
		FloatVector [][] wall = new FloatVector [0][2];
		float            epaisseurEffective = effectiveEpaisseur(x, y);
		if (this.isHorizontal())
		{
			if (this.x1 - this.epaisseur > x)
			{
				wall = FloatVector.append(wall,
										  new FloatVector(this.x1 - this.epaisseur, this.y1 - this.epaisseur),
										  new FloatVector(this.x1 - this.epaisseur, this.y1 + this.epaisseur));
			}
			if (this.y1 + this.epaisseur < y || y < this.y1 - this.epaisseur)
			{
				wall = FloatVector.append(wall,
										  new FloatVector(this.x1 - this.epaisseur, this.y1 + epaisseurEffective),
										  new FloatVector(this.x2 + this.epaisseur, this.y1 + epaisseurEffective));
			}
			if (this.x2 + this.epaisseur < x)
			{
				wall = FloatVector.append(wall,
										  new FloatVector(this.x2 + this.epaisseur, this.y1 - this.epaisseur),
										  new FloatVector(this.x2 + this.epaisseur, this.y1 + this.epaisseur));
			}
		}
		else
		{
			if (this.y1 - this.epaisseur > y)
			{
				wall = FloatVector.append(wall,
										  new FloatVector(this.x1 - this.epaisseur, this.y1 - this.epaisseur),
										  new FloatVector(this.x1 + this.epaisseur, this.y1 - this.epaisseur));
			}
			if (this.x1 + this.epaisseur < x || x < this.x1 - this.epaisseur)
			{
				wall = FloatVector.append(wall,
										  new FloatVector(this.x1 + epaisseurEffective, this.y1 - this.epaisseur),
										  new FloatVector(this.x1 + epaisseurEffective, this.y2 + this.epaisseur));
			}
			if (this.y2 + this.epaisseur < y)
			{
				wall = FloatVector.append(wall,
										  new FloatVector(this.x1 - this.epaisseur, this.y2 + this.epaisseur),
										  new FloatVector(this.x1 + this.epaisseur, this.y2 + this.epaisseur));
			}
		}
		return (wall);
	}

	public static LineWall[] breakWallsIntoSimpleOnes(LineWall lw)
	{
		ArrayList <LineWall> res;

		res = new ArrayList <>();
		if (lw.isHorizontal())
		{
			for (int j = lw.getX1(); j < lw.getX2(); j++)
			{
				res.add(new LineWall(j, lw.getY1(), j + 1, lw.getY2(), lw.getEpaisseur()));
			}
		}
		else
		{
			for (int i = lw.getY1(); i < lw.getY2(); i++)
			{
				res.add(new LineWall(lw.getX1(), i, lw.getX2(), i + 1, lw.getEpaisseur()));
			}
		}
		return (res.toArray(new LineWall[0]));
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
		return ("(" + x1 + ", " + y1 + ") => (" + x2 + ", " + y2 + ")" + ", " + epaisseur);
	}

	public static class LineWallAdapter implements JsonSerializer <LineWall>, JsonDeserializer <LineWall>
	{
		private static final String X1 = "x1";
		private static final String Y1 = "y1";
		private static final String X2 = "x2";
		private static final String Y2 = "y2";
		private static final String E  = "e";

		@Override
		public JsonElement serialize(LineWall ln, Type tp, JsonSerializationContext context)
		{
			JsonObject result = new JsonObject();

			result.add(X1, new JsonPrimitive(ln.getX1()));
			result.add(Y1, new JsonPrimitive(ln.getY1()));
			result.add(X2, new JsonPrimitive(ln.getX2()));
			result.add(Y2, new JsonPrimitive(ln.getY2()));
			result.add(E, new JsonPrimitive(ln.getEpaisseur()));

			return (result);
		}

		@Override
		public LineWall deserialize(JsonElement json, Type tp, JsonDeserializationContext context)
		{
			JsonObject object = json.getAsJsonObject();

			return (new LineWall(object.get(X1).getAsInt(),
								 object.get(Y1).getAsInt(),
								 object.get(X2).getAsInt(),
								 object.get(Y2).getAsInt(),
								 object.get(E).getAsFloat()));
		}
	}
}
