package src.utils;

import src.model.board.LineWall;
import src.model.ContentMaze;

public class DisplayMazeConsole
{
	public enum charWall
	{
		HORIZONTAL('\u2500'),
		VERTICAL('\u2502'),
		INTERSECTION('\u253C'),
		HORIZONTALTOP('\u2534'),
		HORIZONTALBOTTOM('\u252C'),
		VERTICALLEFT('\u2524'),
		VERTICALRIGHT('\u251C'),
		CORNERBOTTOMLEFT('\u2510'),
		CORNERBOTTOMRIGHT('\u250C'),
		CORNERTOPLEFT('\u2518'),
		CORNERTOPRIGHT('\u2514');

		private char caractere;

		charWall(char c)
		{
			caractere = c;
		}

		public String toString()
		{
			return (caractere + "");
		}
	}

	/**
	 * Affiche le labyrinthe dans la console
	 */
	public static void displayMaze(ContentMaze cm)
	{
		int xStart = 0;
		int yStart = 0;
		int xEnd   = 0;
		int yEnd   = 0;

		LineWall[] walls = cm.getLineWalls();
		for (LineWall lw : walls)
		{
			xStart = Math.min(Math.min(lw.getX1(), lw.getX2()), xStart);
			xEnd   = Math.max(Math.max(lw.getX1(), lw.getX2()), xEnd);
			yStart = Math.min(Math.min(lw.getY1(), lw.getY2()), yStart);
			yEnd   = Math.max(Math.max(lw.getY1(), lw.getY2()), yEnd);
		}
		charWall[][] maze = new charWall [yEnd - yStart + 1][xEnd - xStart + 1];
		for (LineWall lw : walls)
		{
			int     xRef         = Math.min(lw.getX1(), lw.getX2()) - xStart;
			int     yRef         = Math.min(lw.getY1(), lw.getY2()) - yStart;
			int     distanceWall = Math.max(Math.abs(lw.getX1() - lw.getX2()), Math.abs(lw.getY1() - lw.getY2()));
			boolean isHorizontal = lw.isHorizontal();
			for (int d = 0; d <= distanceWall; d++)
			{
				if (maze[yRef][xRef] != null && ((maze[yRef][xRef].equals(charWall.HORIZONTAL) && !isHorizontal) || (maze[yRef][xRef].equals(charWall.VERTICAL) && isHorizontal)))
				{
					maze[yRef][xRef] = charWall.INTERSECTION;
				}
				else if (maze[yRef][xRef] == null)
				{
					maze[yRef][xRef] = (isHorizontal) ? charWall.HORIZONTAL : charWall.VERTICAL;
				}
				xRef = xRef + ((isHorizontal) ? 1 : 0);
				yRef = yRef + ((!isHorizontal) ? 1 : 0);
			}
		}
		for (int i = 0; i < maze.length; i++)
		{
			for (int j = 0; j < maze[i].length; j++)
			{
				if (maze[i][j] == null)
				{
					System.out.print(" ");
				}
				else
				{
					boolean haut   = (i > 0 && maze[i - 1][j] != null && (maze[i][j].equals(charWall.VERTICAL) || maze[i][j].equals(charWall.INTERSECTION)) && (maze[i - 1][j].equals(charWall.VERTICAL) || maze[i - 1][j].equals(charWall.INTERSECTION)));
					boolean droit  = (j < maze[i].length - 1 && maze[i][j + 1] != null && (maze[i][j].equals(charWall.HORIZONTAL) || maze[i][j].equals(charWall.INTERSECTION)) && (maze[i][j + 1].equals(charWall.HORIZONTAL) || maze[i][j + 1].equals(charWall.INTERSECTION)));
					boolean bas    = (i < maze.length - 1 && maze[i + 1][j] != null && (maze[i][j].equals(charWall.VERTICAL) || maze[i][j].equals(charWall.INTERSECTION)) && (maze[i + 1][j].equals(charWall.VERTICAL) || maze[i + 1][j].equals(charWall.INTERSECTION)));
					boolean gauche = (j > 0 && maze[i][j - 1] != null && (maze[i][j].equals(charWall.HORIZONTAL) || maze[i][j].equals(charWall.INTERSECTION)) && (maze[i][j - 1].equals(charWall.HORIZONTAL) || maze[i][j - 1].equals(charWall.INTERSECTION)));
					if ((droit && gauche && !haut && !bas) || (droit && !gauche && !bas && !haut) || (gauche && !droit && !bas && !haut))
					{
						System.out.print(charWall.HORIZONTAL);
					}
					else if ((bas && haut && !droit && !gauche) || (bas && !haut && !gauche && !droit) || (haut && !bas && !gauche && !droit))
					{
						System.out.print(charWall.VERTICAL);
					}
					else if (haut && droit && bas && gauche)
					{
						System.out.print(charWall.INTERSECTION);
					}
					else if (droit && gauche && haut && !bas)
					{
						System.out.print(charWall.HORIZONTALTOP);
					}
					else if (droit && gauche && !haut && bas)
					{
						System.out.print(charWall.HORIZONTALBOTTOM);
					}
					else if (haut && gauche && bas && !droit)
					{
						System.out.print(charWall.VERTICALLEFT);
					}
					else if (haut && droit && bas && !gauche)
					{
						System.out.print(charWall.VERTICALRIGHT);
					}
					else if (haut && gauche && !bas && !droit)
					{
						System.out.print(charWall.CORNERTOPLEFT);
					}
					else if (haut && !gauche && !bas && droit)
					{
						System.out.print(charWall.CORNERTOPRIGHT);
					}
					else if (!haut && gauche && bas && !droit)
					{
						System.out.print(charWall.CORNERBOTTOMLEFT);
					}
					else
					{
						System.out.print(charWall.CORNERBOTTOMRIGHT);
					}
				}
			}
			System.out.println();
		}
	}
}
