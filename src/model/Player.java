package src.model;

import java.util.HashSet;

import src.model.board.Case;
import src.model.board.StartCase;
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
	private static final float ACCELERATIONZ  = 1f;
	private static final float VMAXXY         = 2f;
	private static final float VMAXZ          = 1f;
	private static final float PESANTEUR      = 5f;

	//Vitesse selon les axes et plans
	private float velocity;
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

	/**
	 * Teste si le joueur est dans la case donnée en paramètre.
	 * @param c Case
	 * @return True si le joueur est dans la case
	 */
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
	 * @param levelTo Numero d'étage où se trouve la case
	 * @return True si le joueur a été déplacé sur la
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
	 * Update the player position with the collisions with walls, roof and floor
	 * @param m MainMaze
	 * @param dt Intervalle de temps entre deux frames
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

			case goUp:
				if (flyMode || ghostMode)
				{
					if (this.velocityZ < 0)
					{
						this.velocityZ = -this.velocityZ;
					}
					nbDirPushedZ++;
				}
				break;

			case goDown:
				if (flyMode || ghostMode)
				{
					if (this.velocityZ > 0)
					{
						this.velocityZ = -this.velocityZ;
					}
					nbDirPushedZ++;
				}
				break;

			case jump:
				if (this.zCol.isOnFloor() && !flyMode && !ghostMode)
				{
					this.velocityZ = (float)Math.sqrt((0.6f - this.hitBoxBottom) * 2 * PESANTEUR) * (float)Math.sin(90 - this.velocity / VMAXXY * 30);
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
			this.velocity     = Math.min(VMAXXY, this.velocity + ACCELERATIONXY * dt / 1e9f / ((!this.isOnFloor()) ? 2.0f : 1.0f));
			this.lastDepAngle = (this.dirs.contains(Directions.south) && this.dirs.contains(Directions.west)) ? -135 : (angle / nbDirPushedXY);
		}
		else
		{
			this.velocity = Math.max(0, this.velocity - ACCELERATIONXY * 2 * dt / 1e9f);
		}

		if (flyMode || ghostMode)
		{
			if (nbDirPushedZ != 0)
			{
				this.velocityZ = Math.min(VMAXZ, Math.abs(this.velocityZ) + ACCELERATIONZ * dt / 1e9f) * this.sign(this.velocityZ, this.dirs.contains(Directions.goUp));
			}
			else
			{
				this.velocityZ = Math.max(0, Math.abs(this.velocityZ) - ACCELERATIONZ * 2 * dt / 1e9f) * this.sign(this.velocityZ, true);
			}
		}
		else
		{
			if (!this.isOnFloor() && !this.ghostMode)
			{
				this.velocityZ -= (PESANTEUR * dt / 1e9f);
			}
		}

		if (this.velocityZ < -20)
		{
			this.isDead = true;
		}

		this.reallyMove(dt, flyMode);
	}

	/**
	 * Really move the player
	 * @param dt Intervalle de temps entre deux frames
	 * @param flyMode flyMode
	 */
	private void reallyMove(long dt, boolean flyMode)
	{
		final double r1 = Math.toRadians(this.horizontalAngle + this.lastDepAngle);

		float speed = (this.isRunning) ? this.speed * 2 : this.speed;

		float dx, dy, dz;

		if (flyMode && this.lastDepAngle != 90 && this.lastDepAngle != -90)
		{
			final double r2 = Math.toRadians(this.verticalAngle);

			dx = (float)(Math.sin(r1) * (float)Math.cos(r2) * this.velocity * dt / 1e9f * this.speed);
			dy = (float)(Math.cos(r1) * (float)Math.cos(r2) * this.velocity * dt / 1e9f * this.speed);

			if (-90 < this.lastDepAngle && this.lastDepAngle < 90)
			{
				dz = (this.velocity * (float)Math.sin(r2) * dt / 1e9f);
			}
			else
			{
				dz = (this.velocity * (float)Math.sin(-r2) * dt / 1e9f);
			}


			this.xyCol.updateMove(new FloatVector(dx, dy));
			this.zCol.updateMove(dz);

			this.velocity = (float)Math.sqrt(Math.pow(this.xyCol.getMove().getX(), 2) + Math.pow(this.xyCol.getMove().getY(), 2) + Math.pow(this.zCol.getMove(), 2)) * 1e9f / dt;
			this.applyMove(this.xyCol.getMove(), this.zCol.getMove());
		}
		else
		{
			dx = (float)(Math.sin(r1) * this.velocity * dt / 1e9f * this.speed);
			dy = (float)(Math.cos(r1) * this.velocity * dt / 1e9f * this.speed);

			FloatVector d = new FloatVector(dx, dy);

			if (!ghostMode)
			{
				this.xyCol.updateMove(d);
				this.velocity = this.xyCol.getNorm() * 1e9f / dt;

				this.applyMove(this.xyCol.getMove(), 0);
			}
			else
			{
				this.applyMove(d, 0);
			}
		}

		dz = (this.velocityZ * dt / 1e9f);

		FloatVector zero = new FloatVector(0, 0);

		if (ghostMode)
		{
			this.applyMove(zero, dz);
		}
		else
		{
			this.zCol.updateMove(dz);

			this.velocityZ = this.zCol.getMove() * 1e9f / dt;
			this.applyMove(zero, this.zCol.getMove());
		}
	}

	/**
	 * Modifie la vitesse pour faire sauter le joueur
	 * @param nbLevel Nombre d'étage a sauter.
	 */
	public void actionJumpCase(int nbLevel)
	{
		if (!this.ghostMode)
		{
			this.velocityZ = (float)Math.sqrt((2 * nbLevel + 1 - this.hitBoxBottom - this.hitBoxTop) * 2 * PESANTEUR);
		}
	}

	/**
	 * Teste si le joueur est sur un sol
	 * @return True si le joueur est sur un sol
	 */
	public boolean isOnFloor()
	{
		return (this.zCol.isOnFloor());
	}

	/**
	 * Déplace le joueur à la position (x + v.getX(), y + v.getY(), z + dz)
	 * @param v Vecteur de déplacement dans le plan XY
	 * @param dz Vecteur de déplacement dans l'axe z
	 */
	public void applyMove(FloatVector v, float dz)
	{
		this.posX += v.getX();
		this.posY += v.getY();
		this.posZ += dz;
	}

	/**
	 * Renvoit le signe de f
	 * @param f Nombre
	 * @param positiveZero Signe à renvoyer si f = 0
	 * @return 1 si f supérieur à 0, positiveZero si f = 0 et -1 sinon
	 */
	public int sign(float f, boolean positiveZero)
	{
		if (f == 0)
		{
			return ((positiveZero) ? 1 : -1);
		}
		return ((int)Math.signum(f));
	}

	/**
	 * The obvious overwrited toString function
	 * @return representation String
	 */
	@Override
	public String toString()
	{
		return ("posX = " + posX + " posY = " + posY + " other things");
	}
}
