package src.model;

import java.util.ArrayList;
import java.util.Date;

import src.model.board.Case;
import src.model.board.LineWall;
import src.model.board.SpeedCase;
import src.model.board.TeleportCase;
import src.model.board.TimeCase;
import src.model.gen.Algo;
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
	private ContentMaze m;
	private MazeDimension mazeDim;
	private String name;
	private Player p;

	public MainMaze(ContentMaze m, MazeDimension mz, String name, Player p)
	{
		this.m       = m;
		this.mazeDim = mz;
		this.name    = name;
		this.p       = p;
		this.p.goTo(m.getCase(Case.TypeCase.START));
	}

	public MainMaze(Algo algo)
	{
		this(algo.getContentMaze(), algo.getMazeDimension(), "", new Player(0.05f, 0.5f, 0.5f, 0f, 0f, 0f));
	}

	public ContentMaze getContentMaze()
	{
		return (this.m);
	}

	public MazeDimension getMazeDimension()
	{
		return (this.mazeDim);
	}

	public Player getPlayer()
	{
		return (this.p);
	}

	public Case getEndCase()
	{
		return (m.getCase(Case.TypeCase.END));
	}

	/**
	 * Déplace le joueur dans le labyrinthe, si le joueur rencontre un mur, il longera ce mur.
	 */
	public void updatePlayer()
	{
		this.p.update(this.m.getLineWalls());
	}

	public void actionCase()
	{
		for (Case c : m.getSpecialCases())
		{
			if (this.p.playerInCase(c))
			{
				switch (c.type)
				{
				case END:
					this.p.setWin(true);
					break;

				case TELEPORT:
					this.p.setPosX(((TeleportCase)c).getXDest() + Case.getTailleCase() / 2);
					this.p.setPosY(((TeleportCase)c).getYDest() + Case.getTailleCase() / 2);
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
						Date d = this.p.getDate();
						d.setTime(d.getTime() + ((TimeCase)c).getTimeMillis());
					}
					break;
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
		DisplayMazeConsole.displayMaze(m, reverse);
	}

	/**
	 * The obvious overwrited toString function
	 * @return representation String
	 */
	@Override
	public String toString()
	{
		String str = "Describing Maze\n";

		str += "name = " + this.name + "\n";
		str += "player = " + this.p + "\n";
		str += "\n";
		str += "labyrinthe :\n";
		if (m != null)
		{
			str += m.toString();
		}
		return (str);
	}
}
