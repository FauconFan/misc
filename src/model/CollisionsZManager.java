package src.model;

import src.model.MazeDimension;
import src.model.Player;

import java.lang.Math;

public class CollisionsZManager
{
	private Player p;
	private float zMove;
	private MazeDimension mazeDim;

	public CollisionsZManager(Player p)
	{
		this.p = p;
	}

	public void updateFloor(MazeDimension md)
	{
		mazeDim = md;
	}

	public float getMove()
	{
		return (this.zMove);
	}

	public void updateMove(float dz)
	{
		//If la position en z est plus haute que la position du sol le plus proche tel que p.getPosZ() > sol
		if (this.p.getPosZ() >= 0 && this.isFloor())
		{
			this.zMove = (this.p.getPosZ() + dz < 0) ? -(this.p.getPosZ() - 0) : dz;
		}
		else
		{
			this.zMove = dz;
		}
	}

	public float getNorm()
	{
		return (this.zMove);
	}

	public boolean isFloor()
	{
		return (mazeDim.isFloor((int)this.p.getPosX(), (int)this.p.getPosY()));
	}

	public boolean isOnFloor()
	{
		return (this.isFloor() && Math.abs(this.p.getPosZ()) < 10e-4);
	}
}
