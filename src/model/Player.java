package src.model;

import java.util.Date;
import java.util.HashSet;

import src.model.board.Case;
import src.model.board.LineWall;
import src.utils.FloatVector;

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
	private boolean hasWin    = false;
	private float speed       = 1;
	private boolean isRunning = false;
	private Date time;

	//Constante de déplacement (Angle)
	public final float rot = 2f;       // En degré

	//Constantes d'accélération et de vitesse max
	private static final float ACCELERATIONXY = 0.001f;
	private static final float VMAX           = 0.04f;
	private static final float PESANTEUR      = -0.015f;

	//Vitesse selon les axes/plan
	private float velocityXY;
	private float velocityZ;

	//Angle du dernier déplacement
	private int lastDepAngle;

	//Gestionnaires de Collisions
	private CollisionsXYManager xyCol = new CollisionsXYManager(this);
	private CollisionsZManager zCol   = new CollisionsZManager(this);

	//Ensemble de déplacements à faire
	public final HashSet <Directions> dirs = new HashSet <Directions>();

	public Player(float hitBoxCircle, float posX, float posY, float posZ, float horizontalAngle, float verticalAngle)
	{
		this.hitBoxCircle    = hitBoxCircle;
		this.posX            = posX;
		this.posY            = posY;
		this.posZ            = posZ;
		this.horizontalAngle = horizontalAngle;
		this.verticalAngle   = verticalAngle;
		this.time            = new Date(System.currentTimeMillis());
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

	public boolean getHasWin()
	{
		return (this.hasWin);
	}

	public float getSpeed()
	{
		return (this.speed);
	}

	public Date getDate()
	{
		return (this.time);
	}

	public void setSpeed(float f)
	{
		speed = f;
	}

	public void setPosX(float x)
	{
		posX = x;
	}

	public void setPosY(float y)
	{
		posY = y;
	}

	public void addPosZ(float z)
	{
		posZ += z;
	}

	public void setWin(boolean b)
	{
		hasWin = b;
	}

	public void addHorizontalAngle(float x)
	{
		this.horizontalAngle += x;
	}

	public void addVerticalAngle(float y)
	{
		this.verticalAngle += y;
	}

	public boolean playerInCase(Case c)
	{
		float diff = Case.getTailleCase() / 2;

		return (Math.abs(posX - (c.getX() + diff)) < diff && Math.abs(posY - (c.getY() + diff)) < diff);
	}

	public void invertRun()
	{
		isRunning = !isRunning;
	}

	/**
	 * Transport the player to the specified case
	 * @param c The case
	 */
	public boolean goTo(Case c)
	{
		if (c != null)
		{
			posX = c.getX() + Case.getTailleCase() / 2;
			posY = c.getY() + Case.getTailleCase() / 2;
			return (true);
		}
		else
		{
			return (false);
		}
	}

	/**
	 * Update the player position with the collisions with walls
	 * @param lw the walls
	 */
	public void update(LineWall [] lw)
	{
		int angle       = 0;
		int nbDirPushed = 0;

		for (Directions d: dirs)
		{
			switch (d)
			{
			case north: angle += 0; nbDirPushed++; break;

			case east: angle += 90; nbDirPushed++; break;

			case south: angle += 180; nbDirPushed++; break;

			case west: angle += -90; nbDirPushed++; break;

			case left: horizontalAngle -= rot;
				lastDepAngle           += rot;
				break;

			case right: horizontalAngle += rot;
				lastDepAngle            -= rot;
				break;

			case up: verticalAngle += rot; break;

			case down: verticalAngle -= rot; break;

			case goUp: if (ghostMode)
				{
					posZ += 1f;
				}
				break;

			case goDown: if (ghostMode)
				{
					posZ -= 1f;
				}
				break;

			case jump:  if (Math.abs(this.posZ) < 10e-4)
				{
					this.velocityZ = Math.max(0.25f, this.velocityXY * 5) * (float)Math.sin(90 - this.velocityXY / VMAX * 45);
				}
				break;
			}
		}
		if (nbDirPushed != 0 && Math.abs(this.posZ) < 10e-4)
		{
			this.velocityXY   = Math.min(VMAX, this.velocityXY + ACCELERATIONXY);
			this.lastDepAngle = (this.dirs.contains(Directions.south) && this.dirs.contains(Directions.west)) ? -135 : (angle / nbDirPushed);
		}
		else if (Math.abs(this.posZ) < 10e-4)
		{
			this.velocityXY = Math.max(0, this.velocityXY - ACCELERATIONXY * 2);
		}
		this.reallyMove(lw, this.lastDepAngle);
	}

	/**
	 * Really move the player
	 * @param lw the walls
	 * @param diff The difference of orientation
	 */
	private void reallyMove(LineWall[] lw, int diff)
	{
		final double r1 = Math.toRadians(horizontalAngle + diff);

		float speed = (this.isRunning) ? this.speed * 2 : this.speed;

		final float dx = (float)(Math.sin(r1) * velocityXY * speed);
		final float dy = (float)(Math.cos(r1) * velocityXY * speed);

		FloatVector d = new FloatVector(dx, dy);

		if (ghostMode)
		{
			this.applyMove(d);
		}
		else
		{
			this.xyCol.updateWalls(lw);
			this.xyCol.updateMove(d);
			this.applyMove(this.xyCol.getMove());
			this.velocityXY = this.xyCol.getNorm();

			this.velocityZ = this.velocityZ + PESANTEUR;
			this.zCol.updateMove(velocityZ);
			this.posZ      = this.zCol.getMove() + this.posZ;
			this.velocityZ = this.zCol.getMove();
		}
	}

	/**
	 * Déplace le joueur à la position (x + v.getX(), y + v.getY())
	 * @param v Vecteur de déplacement
	 */
	public void applyMove(FloatVector v)
	{
		posX += v.getX();
		posY += v.getY();
	}

	public String toString()
	{
		return ("posX = " + posX + " posY = " + posY + " other things");
	}
}
