package src.model;

import java.io.Serializable;

/**
 * Player est la classe qui représente le joueur dans le labyrinthe.
 */
public class Player implements Serializable
{
	private float hitBoxWidth;
	private float hitBoxLength;
	private float posX;
	private float posY;
	private float horizontalAngle;
	private float verticalAngle;

	public Player(float hitBoxWidth, float hitBoxLength, float posX, float posY, float horizontalAngle, float verticalAngle)
	{
		this.hitBoxWidth     = hitBoxWidth;
		this.hitBoxLength    = hitBoxLength;
		this.posX            = posX;
		this.posY            = posY;
		this.horizontalAngle = horizontalAngle;
		this.verticalAngle   = verticalAngle;
	}
}
