package src.model;

import src.utils.StringManipulation;

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
		if (rl == null)
		{
			throw new RuntimeException("RectLabyrintheShift can't be implemented with a null RectLabyrinthe");
		}
		this.rl = rl;
		this.x  = dx;
		this.y  = dy;
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

	/**
	 * RectLabShift Rep
	 * @return String rep
	 */
	@Override
	public String toString()
	{
		String str;

		str  = "dx : " + this.getDX() + "\n";
		str += "dy : " + this.getDY() + "\n";
		str += StringManipulation.makeTabsProperly(rl.toString());
		return (str);
	}
}
