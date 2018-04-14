package src.model;


import src.model.board.Case;
import src.model.board.JumpCase;
import src.model.board.SpeedCase;
import src.model.board.StartCase;
import src.model.board.TeleportCase;
import src.model.board.TimeCase;
import src.model.gen.Algo;
import src.model.gen.MainMazeFactory.GenFactoryException;
import src.utils.DisplayMazeConsole;

/**
 * Structure de données du labyrinthe.
 */
public class MainMaze
{
	private ContentMaze[] cm;
	private Player p;
	private int current_level;

	//Peut-on voler ?
	private boolean flyMode;

	public MainMaze(ContentMaze[] cm, boolean flyMode)
	{
		StartCase start = null;

		this.cm = cm;
		this.p  = new Player(flyMode);
		for (int i = 0; i < cm.length; i++)
		{
			start = (StartCase)cm[i].getCase(Case.TypeCase.START);
			if (start != null)
			{
				this.current_level = i;
				break;
			}
		}
		if (start == null)
		{
			throw new RuntimeException("SNH should be checked in generation");
		}
		this.p.goToStartCase(start, this.current_level);
		this.flyMode = flyMode;
	}

	public MainMaze(Algo algo, boolean flyMode) throws GenFactoryException
	{
		this(algo.getContentMaze(), flyMode);
	}

	public ContentMaze[] getContentMaze()
	{
		return (this.cm);
	}

	/**
	 * Renvoit l'étage courant
	 * @return ContentMaze courant
	 */
	public ContentMaze getContentMazeCurrentLevel()
	{
		return (this.cm[this.current_level]);
	}

	/**
	 * Renvoit l'étage demandé
	 * @param n Numero de l'étage
	 * @return ContentMaze numéro n s'il existe, null sinon
	 */
	public ContentMaze getContentMaze(int n)
	{
		if (n >= cm.length || n < 0)
		{
			return (null);
		}
		return (cm[n]);
	}

	public Player getPlayer()
	{
		return (this.p);
	}

	public int getCurrentLevel()
	{
		return (this.current_level);
	}

	public Case getEndCase()
	{
		Case c;

		for (ContentMaze cms : cm)
		{
			c = cms.getCase(Case.TypeCase.END);
		}
		throw new RuntimeException("SNH should be checked in generation");
	}

	public boolean getFlyMode()
	{
		return (flyMode);
	}

	public void setFlyMode(boolean b)
	{
		this.flyMode = b;
	}

	/**
	 * Met à jour les coordonnées du joueur dans le labyrinthe
	 * @param l Intervalle de temps entre deux frames
	 */
	public void updatePlayer(long l)
	{
		this.p.update(this, l);

		float posZ = this.p.getPosZ();
		if (posZ >= 0 && posZ <= this.cm.length - 1)
		{
			this.current_level = (int)posZ;
		}
		else if (posZ < 0)
		{
			this.current_level = 0;
		}
		else
		{
			this.current_level = cm.length - 1;
		}
	}

	/**
	 * Vérifie si le joueur est sur une case spéciale et active son effet
	 */
	public void actionCase()
	{
		// TODO to change actually
		for (Case c : cm[current_level].getSpecialCases())
		{
			if (this.p.playerInCase(c))
			{
				switch (c.type)
				{
				case END:
					this.p.setWin(true);
					break;

				case TELEPORT:
					this.p.setPosX(((TeleportCase)c).getXDest() + 0.5f);
					this.p.setPosY(((TeleportCase)c).getYDest() + 0.5f);
					this.p.setPosZ(((TeleportCase)c).getStage() + this.p.hitBoxBottom);
					break;

				case SPEED:
					if (!((SpeedCase)c).isActivated())
					{
						((SpeedCase)c).activate();
						this.p.setSpeed(((SpeedCase)c).getSpeedModif() * this.p.getSpeed());
					}
					break;

				case TIME:
					if (!((TimeCase)c).isActivated())
					{
						((TimeCase)c).activate();
						p.updateTime(-((TimeCase)c).getTimeNano() * (long)10e9);
					}
					break;

				case JUMP:
					if (this.p.isOnFloor())
					{
						this.p.actionJumpCase(((JumpCase)c).getNbLevelJump());
					}
				}
			}
		}
	}

	/**
	 * Affiche le labyrinthe dans la console
	 * @param reverse reverse axis y
	 */
	public void displayMaze(boolean reverse)
	{
		DisplayMazeConsole.displayMaze(cm, reverse);
	}

	/**
	 * The obvious overwrited toString function
	 * @return representation String
	 */
	@Override
	public String toString()
	{
		String str = "Describing Maze\n";

		str += "player = " + this.p + "\n";
		str += "\n";
		str += "labyrinthe :\n";
		if (cm != null)
		{
			for (int i = 0; i < cm.length; i++)
			{
				str += "LEVEL " + (i + 1) + "\n";
				str += cm[i].toString();
			}
		}
		return (str);
	}
}
