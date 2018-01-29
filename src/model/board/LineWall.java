package src.model.board;

/**
 * LineWall est la classe représentant un mur entre deux points.
 * <br>
 * Le premier étant (x1, y1) et le deuxième (x2,y2)
 */
public class LineWall
{
	public static final float EPAISSEUR_DEFAULT = 0.1f;

	private int x1;
	private int y1;
	private int x2;
	private int y2;
	private float epaisseur;

	public LineWall(int x1, int y1, int x2, int y2, float epaisseur)
	{
		this.x1        = x1;
		this.y1        = y1;
		this.x2        = x2;
		this.y2        = y2;
		this.epaisseur = epaisseur;
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

	public String toString()
	{
		return ("(" + x1 + ", " + y1 + ") => (" + x2 + ", " + y2 + ")\n");
	}
}
