package src.model;

import java.util.ArrayList;

import src.model.board.Case;
import src.model.board.JumpCase;
import src.model.board.LineWall;
import src.model.board.SpeedCase;
import src.model.board.TeleportCase;
import src.model.board.TimeCase;
import src.model.gen.Algo;
import src.model.gen.MainMazeFactory.GenFactoryException;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;
import src.model.parser.Parser;
import src.utils.DisplayMazeConsole;
import src.utils.FloatVector;
import src.utils.StringManipulation;

/**
 * Structure de données du labyrinthe.
 */
public class MainMaze
{
	private ContentMaze[] cm;
	private Player p;
	private int current_level;

	public MainMaze(ContentMaze[] cm)
	{
		Case start = null;

		this.cm = cm;
		this.p  = new Player(0.05f, 0.25f, 0.5f, 0.5f, 0.25f, 0f, 0f);
		for (int i = 0; i < cm.length; i++)
		{
			start = cm[i].getCase(Case.TypeCase.START);
			this.current_level = i;
			break;
		}
		if (start == null)
		{
			throw new RuntimeException("SNH should be checked in generation");
		}
		this.p.goTo(start);
	}

	public MainMaze(Algo algo) throws GenFactoryException
	{
		this(algo.getContentMaze());
	}

	public ContentMaze[] getContentMaze()
	{
		return (this.cm);
	}

	public ContentMaze getContentMazeCurrentLevel()
	{
		return (this.cm[this.current_level]);
	}

	public ContentMaze getContentMaze(int n)
	{
		if (n >= cm.length)
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

	/**
	 * Déplace le joueur dans le labyrinthe, si le joueur rencontre un mur, il longera ce mur.
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
						p.updateTime(((TimeCase)c).getTimeMillis());
					}
					break;

				case JUMP:
					this.p.setVelocityZ(0.05f);
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
