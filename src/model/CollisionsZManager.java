package src.model;

import src.model.Player;

import java.lang.Math;

public class CollisionsZManager
{
	private Player p;
	private float zMove;

	public CollisionsZManager(Player p)
	{
		this.p = p;
	}

	public float getMove()
	{
		return (this.zMove);
	}

	public void updateMove(float dz)
	{
		//If la position en z est plus haute que la position du sol le plus proche tel que p.getPosZ() > sol
		if (this.p.getPosZ() >= 0)
		{
			this.zMove = (this.p.getPosZ() + dz < 0) ? -(this.p.getPosZ() - 0) : dz;
		}
	}
}
