package src.model;

/**
 * Sous-labyrinthe rectangulaire qui compose le MainLabyrinthe (en tenant compte du décalage).
 */
public class RectLabyrintheShift
{
	private final RectLabyrinthe rl;
	private final int x;
	private final int y;

	public RectLabyrintheShift(RectLabyrinthe rl, int dx, int dy)
	{
		this.rl = rl;
		this.x = dx;
		this.y = dy;
	}

	public RectLabyrinthe getRectLabyrinthe()
	{
		return (this.rl);
	}

	public int getDX()
	{
		return (this.x);
	}

	public int getDY()
	{
		return (this.y);
	}
}
