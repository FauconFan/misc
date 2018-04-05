package src.model;

import src.model.MazeDimension;
import src.model.Player;

import java.lang.Math;

public class CollisionsZManager
{
	private Player p;
	private float zMove;
	private ContentMaze [] cms;
	private int highLevel;


	public CollisionsZManager(Player p)
	{
		this.p = p;
	}

	public void updateFloor(ContentMaze [] cms, int lvl)
	{
		this.cms       = cms;
		this.highLevel = lvl;
	}

	public float getMove()
	{
		return (this.zMove);
	}

	public float getNorm()
	{
		return (this.zMove);
	}

	public void updateMove(float dz)
	{
		if (dz > 0 && cms[1] != null && this.p.getPosZ() + this.p.getHitBoxZ() + dz > highLevel + 1 && this.isFloor(cms[1]))
		{
			this.zMove = (highLevel + 1) - this.p.getHitBoxZ() - this.p.getPosZ();
		}
		else if (dz < 0 && this.p.getPosZ() - this.p.getHitBoxZ() >= highLevel && this.isFloor(cms[0]))
		{
			this.zMove = (this.p.getPosZ() - this.p.getHitBoxZ() + dz < highLevel) ? highLevel - (this.p.getPosZ() - this.p.getHitBoxZ()) : dz;
		}
		else
		{
			this.zMove = dz;
		}
	}

	public boolean isFloor(ContentMaze cm)
	{
		return (cm.isFloor(this.p.getPosX(), this.p.getPosY()));
	}

	public boolean isOnFloor()
	{
		return (this.isFloor(cms[0]) && Math.abs(this.p.getPosZ() - this.p.getHitBoxZ() - highLevel) < 10e-4);
	}
}
