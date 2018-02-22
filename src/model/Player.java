package src.model;

/**
 * Player est la classe qui représente le joueur dans le labyrinthe.
 */
public class Player
{
	//Est on en mode ghost ?
	private boolean ghostMode = true;

	private float hitBoxWidth;
	private float hitBoxLength;
	private float posX;
	private float posY;
	private float posZ;
	private float horizontalAngle;
	private float verticalAngle;

	public Player(float hitBoxWidth, float hitBoxLength, float posX, float posY, float posZ, float horizontalAngle, float verticalAngle)
	{
		this.hitBoxWidth     = hitBoxWidth;
		this.hitBoxLength    = hitBoxLength;
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

	public float getHitBoxWidth()
	{
		return (this.hitBoxWidth);
	}

	public float getHitBoxLength()
	{
		return (this.hitBoxLength);
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
		horizontalAngle += x;
	}

	public void addVerticalAngle(float y)
	{
		verticalAngle += y;
	}
}
