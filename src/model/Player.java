package src.model;

import java.util.HashSet;

import src.model.board.Case;
import src.model.board.LineWall;
import src.model.board.StartCase;
import src.model.MazeDimension;
import src.utils.FloatVector;

/**
 * Player est la classe qui représente le joueur dans le labyrinthe.
 */
public class Player
{
	//Est-on en mode ghost ?
	private boolean ghostMode = false;

	public final float hitBoxCircle;
	public final float hitBoxTop;
	public final float hitBoxBottom;

	private float posX;
	private float posY;
	private float posZ;
	private float horizontalAngle;
	private float verticalAngle;
	private boolean hasWin    = false;
	private boolean isDead    = false;
	private float speed       = 1;
	private boolean isRunning = false;
	private long time;

	//Constante de déplacement (Angle)
	public final float rot = 2f;       // En degré

	//Constantes d'accélération et de vitesse max
	private static final float ACCELERATIONXY = 2f;
	private static final float ACCELERATIONZ  = 2f;
	private static final float VMAXXY         = 5f;
	private static final float VMAXZ          = 5f;
	private static final float PESANTEUR      = 5f;
	private static final float VELOCITYGHOST  = 0.02f;

	//Vitesse selon les axes/plan
	private float velocityXY;
	private float velocityZ;

	//Angle du dernier déplacement
	private int lastDepAngle;

	//Gestionnaires de Collisions
	private transient CollisionsXYManager xyCol;
	private transient CollisionsZManager zCol;

	//Ensemble de déplacements à faire
	public final HashSet <Directions> dirs = new HashSet <Directions>();

	public Player(float hitBoxCircle, float hitBoxTop, float hitBoxBottom, float posX, float posY, float posZ, float horizontalAngle, float verticalAngle)
	{
		this.hitBoxCircle    = hitBoxCircle;
		this.hitBoxTop       = hitBoxTop;
		this.hitBoxBottom    = hitBoxBottom;
		this.posX            = posX;
		this.posY            = posY;
		this.posZ            = posZ;
		this.horizontalAngle = horizontalAngle;
		this.verticalAngle   = verticalAngle;
	}

	public Player(boolean flyMode)
	{
		this(0.05f,
			 0.1f,
			 flyMode ? 0.1f : 0.4f,
			 0.5f,
			 0.5f,
			 flyMode ? 0.5f : 0.4f,
			 0f,
			 0f);
	}

	public boolean getGhostMode()
	{
		return (ghostMode);
	}

	public void setGhostMode(boolean b)
	{
		this.ghostMode = b;
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

	public boolean getIsDead()
	{
		return (this.isDead);
	}

	public float getSpeed()
	{
		return (this.speed);
	}

	public long getTime()
	{
		return (this.time);
	}

	public void updateTime(long l)
	{
		time = Math.max(0, time + l);
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

	public void setPosZ(float z)
	{
		posZ = z;
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
		float diff = 0.5f;

		return (Math.abs(posX - (c.getX() + diff)) < diff && Math.abs(posY - (c.getY() + diff)) < diff);
	}

	public void invertRun()
	{
		isRunning = !isRunning;
	}

	/**
	 * Transport the player to the start case
	 * @param c The case
	 */
	public boolean goToStartCase(StartCase c, int levelTo)
	{
		if (c != null)
		{
			posX = c.getX() + 0.5f;
			posY = c.getY() + 0.5f;
			posZ = (float)levelTo + hitBoxBottom;
			return (true);
		}
		else
		{
			return (false);
		}
	}

	/**
	 * Update the player position with the collisions with walls
	 * @param m MainMaze
	 * @param dt Time
	 */
	public void update(MainMaze m, long dt)
	{
		int     angle         = 0;
		int     nbDirPushedXY = 0;
		int     nbDirPushedZ  = 0;
		boolean flyMode       = m.getFlyMode();

		if (this.xyCol == null)
		{
			this.xyCol = new CollisionsXYManager(this);
		}
		if (this.zCol == null)
		{
			this.zCol = new CollisionsZManager(this, flyMode);
		}
		if (dt <= 100000000)     //if not init
		{
			this.time += dt;
		}

		for (Directions d: dirs)
		{
			switch (d)
			{
			case north: angle += 0; nbDirPushedXY++; break;

			case east: angle += 90; nbDirPushedXY++; break;

			case south: angle += 180; nbDirPushedXY++; break;

			case west: angle += -90; nbDirPushedXY++; break;

			case left: horizontalAngle -= rot; lastDepAngle += rot; break;

			case right: horizontalAngle += rot; lastDepAngle -= rot; break;

			case up: verticalAngle += rot; break;

			case down: verticalAngle -= rot; break;

			case goUp: if (ghostMode)
				{
					posZ += 0.05f;
				}
				if (flyMode)
				{
					if (this.velocityZ < 0)
					{
						this.velocityZ = -this.velocityZ;
					}
				}
				nbDirPushedZ++;
				break;

			case goDown: if (ghostMode)
				{
					posZ -= 0.05f;
				}
				if (flyMode)
				{
					if (this.velocityZ > 0)
					{
						this.velocityZ = -this.velocityZ;
					}
				}
				nbDirPushedZ++;
				break;

			case jump:  if (this.zCol.isOnFloor() && !flyMode)
				{
					this.velocityZ = (float)Math.sqrt((0.6f - this.hitBoxBottom) * 2 * PESANTEUR) * (float)Math.sin(90 - this.velocityXY / VMAXXY * 30);
				}
				break;
			}
		}

		int currentLevel = m.getCurrentLevel();

		ContentMaze [] cms = { m.getContentMaze(currentLevel - 1), m.getContentMazeCurrentLevel(), m.getContentMaze(currentLevel + 1) };

		this.zCol.updateFloor(cms, currentLevel);
		this.xyCol.updateWalls(cms, currentLevel);

		if (nbDirPushedXY != 0)
		{
			this.velocityXY   = Math.min(VMAXXY, this.velocityXY + ACCELERATIONXY * dt / 1e9f / ((!this.isOnFloor()) ? 2.0f : 1.0f));
			this.lastDepAngle = (this.dirs.contains(Directions.south) && this.dirs.contains(Directions.west)) ? -135 : (angle / nbDirPushedXY);
		}
		else
		{
			this.velocityXY = Math.max(0, this.velocityXY - ACCELERATIONXY * 2 * dt / 1e9f);
		}

		if (flyMode)
		{
			if (nbDirPushedZ != 0)
			{
				this.velocityZ = Math.min(VMAXZ, Math.abs(this.velocityZ) + ACCELERATIONZ / 2.0f * dt / 1e9f) * this.sign(this.velocityZ);
			}
			else
			{
				this.velocityZ = Math.max(0, Math.abs(this.velocityZ) - ACCELERATIONZ * 2 * dt / 1e9f) * this.sign(this.velocityZ);
			}
		}
		else
		{
			if (!this.isOnFloor() && !this.ghostMode)
			{
				this.velocityZ -= (PESANTEUR * dt / 1e9f);
			}
		}

		if (this.velocityZ < -10)
		{
			this.isDead = true;
		}

		this.reallyMove(dt /*, flyMode*/);
	}

	/**
	 * Really move the player
	 */
	private void reallyMove(long dt /*, boolean flyMode*/)
	{
		final double r1 = Math.toRadians(this.horizontalAngle + this.lastDepAngle);

		float speed = (this.isRunning) ? this.speed * 2 : this.speed;

		float dx, dy, dz;

		/*if (flyMode && (this.lastDepAngle == 0 || this.lastDepAngle == 180)) //Si on appuye sur avancer et reculer)
		 * {
		 *  final double r2 = Math.toRadians(this.verticalAngle);
		 *  dx = (float)(Math.sin(r1) * (float)Math.cos(r2) * this.velocityXY * dt / 1e9f * this.speed);
		 *  dy = (float)(Math.cos(r1) * (float)Math.cos(r2) * this.velocityXY * dt / 1e9f * this.speed);
		 *  dz = ((this.velocityZ + this.velocityXY * (float)Math.sin(r2) / 2.0f) * dt / 1e9f); // Dépend de avancer ou reculer
		 * }
		 * else
		 * {*/
		dx = (float)(Math.sin(r1) * this.velocityXY * dt / 1e9f * this.speed);
		dy = (float)(Math.cos(r1) * this.velocityXY * dt / 1e9f * this.speed);
		dz = (this.velocityZ * dt / 1e9f);
		//}

		FloatVector d = new FloatVector(dx, dy);

		if (this.ghostMode)
		{
			this.applyMove(d, 0);
		}
		else
		{
			this.xyCol.updateMove(d);
			this.velocityXY = this.xyCol.getNorm() * 1e9f / dt;

			this.zCol.updateMove(dz);
			this.velocityZ = this.zCol.getMove() * 1e9f / dt;

			this.applyMove(this.xyCol.getMove(), this.zCol.getMove());
		}
	}

	public void actionJumpCase(int nbLevel)
	{
		if (!this.ghostMode)
		{
			this.velocityZ = (float)Math.sqrt((2 * nbLevel + 1 - this.hitBoxBottom - this.hitBoxTop) * 2 * PESANTEUR);
		}
	}

	public boolean isOnFloor()
	{
		return (this.zCol.isOnFloor());
	}

	/**
	 * Déplace le joueur à la position (x + v.getX(), y + v.getY())
	 * @param v Vecteur de déplacement
	 */
	public void applyMove(FloatVector v, float dz)
	{
		this.posX += v.getX();
		this.posY += v.getY();
		this.posZ += dz;
	}

	public int sign(float f)
	{
		if (f == 0)
		{
			return (1);
		}
		return ((int)Math.signum(f));
	}

	public String toString()
	{
		return ("posX = " + posX + " posY = " + posY + " other things");
	}
}
