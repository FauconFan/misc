package src.model;

import java.io.Serializable;

/**
 * Player est la classe qui représente le joueur dans le labyrinthe.
 */
public class Player implements Serializable
{
	private float hitBoxCircle;
	private float posX;
	private float posY;
	private float horizontalAngle;
	private float verticalAngle;

	public Player(float hitBoxCircle, float posX, float posY, float horizontalAngle, float verticalAngle)
	{
		this.hitBoxCircle    = hitBoxCircle;
		this.posX            = posX;
		this.posY            = posY;
		this.horizontalAngle = horizontalAngle;
		this.verticalAngle   = verticalAngle;
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

	public void addHorizontalAngle(float x)
	{
		horizontalAngle += x;
	}

	public void addVerticalAngle(float y)
	{
		verticalAngle += y;
	}
}
