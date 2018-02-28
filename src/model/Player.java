package src.model;

import src.model.board.Case;

/**
 * Player est la classe qui représente le joueur dans le labyrinthe.
 */
public class Player
{
	//Est on en mode ghost ?
	private boolean ghostMode = false;

	private float hitBoxCircle;
	private float posX;
	private float posY;
	private float posZ;
	private float horizontalAngle;
	private float verticalAngle;

	public Player(float hitBoxCircle, float posX, float posY, float posZ, float horizontalAngle, float verticalAngle)
	{
		this.hitBoxCircle    = hitBoxCircle;
		this.posX            = posX;
		this.posY            = posY;
		this.posZ            = posZ;
		this.horizontalAngle = horizontalAngle;
		this.verticalAngle   = verticalAngle;
	}

	public boolean getGhostMode()
	{
		return (ghostMode);
	}

	public void setGhostMode(boolean b)
	{
		this.ghostMode = b;
	}

	public float getHitBoxCircle()
	{
		return (this.hitBoxCircle);
	}

	public float getPosX()
	{
		return (this.posX);
	}

	public float getPosY()
	{
		return (this.posY);
	}

	public float getPosZ()
	{
		return (this.posZ);
	}

	public float getHorizontalAngle()
	{
		return (this.horizontalAngle);
	}

	public float getVerticalAngle()
	{
		return (this.verticalAngle);
	}

	public void setPosX(float x)
	{
		posX = x;
	}

	public void setPosY(float y)
	{
		posY = y;
	}

	public void setPosZ(float z)
	{
		posZ = z;
	}

	public void addHorizontalAngle(float x)
	{
		this.horizontalAngle += x;
	}

	public void addVerticalAngle(float y)
	{
		this.verticalAngle += y;
	}

	public boolean goTo(Case.TypeCase t, Case[] sc)
	{
		for (Case c:sc)
		{
			if (c.getTypeCase() == t)
			{
				posX = c.getX() + Case.getTailleCase() / 2;
				posY = c.getY() + Case.getTailleCase() / 2;
				return (true);
			}
		}
		return (false);
	}

	public boolean hasWin(Case[] sc)
	{
		for (Case c:sc)
		{
			if (c.getTypeCase() == Case.TypeCase.END && Math.abs(posX - c.getX()) < Case.getTailleCase() / 2 && Math.abs(posY - c.getY()) < Case.getTailleCase() / 2)
			{
				return (true);
			}
		}
		return (false);
	}
}
