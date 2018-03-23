package src.model;

import src.model.Player;

import java.lang.Math;

public class CollisionsZManager
{
	private Player p;
	private float zMove;

	public CollisionsZManager(Player p, float dz)
	{
		this.p     = p;
		this.zMove = dz;
	}

	public float getMove()
	{
		return (this.zMove);
	}

	public void updateMove()
	{
		if (this.p.getPosZ() < 0)
		{
			this.zMove = 0;
		}
		else
		{
			this.zMove = (this.p.getPosZ() + this.zMove < 0) ? this.p.getPosZ() : this.zMove;
		}
	}
}
