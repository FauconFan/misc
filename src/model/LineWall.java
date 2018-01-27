package src.model;

/**
 * LineWall est la classe représentant un mur entre deux points.
 * <br/>
 * Le premier étant (x1, y1) et le deuxième (x2,y2)
 */
public class LineWall
{
	private int x1;
	private int x2;
	private int y1;
	private int y2;
	private float epaisseur;

	public LineWall(int x1, int x2, int y1, int y2, float epaisseur)
	{
		this.x1 = x1;
		this.x2 = x2;
		this.y1 = y1;
		this.y2 = y2;
		this.epaisseur = epaisseur;
	}
}
