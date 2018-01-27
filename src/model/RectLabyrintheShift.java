package src.model;

import java.lang.StringBuffer;

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
		StringBuffer bf = new StringBuffer();

		bf.append("dx : " + this.getDX() + "\n");
		bf.append("dy : " + this.getDY() + "\n");
		bf.append(StringManipulation.makeTabsProperly(rl.toString()));
		return (bf.toString());
	}
}
