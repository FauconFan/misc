package src.model;

/**
 * Player est la classe qui représente le joueur dans le labyrinthe.
 */
public class Player
{
	private float hitBox;
	private float posX;
	private float posY;
	private float horizontalAngle;
	private float verticalAngle;

	public Player(float hitBox, float posX, float posY, float horizontalAngle, float verticalAngle)
	{
		this.hitBox          = hitBox;
		this.posX            = posX;
		this.posY            = posY;
		this.horizontalAngle = horizontalAngle;
		this.verticalAngle   = verticalAngle;
	}
}
