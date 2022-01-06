package src.utils;

import src.model.board.LineWall;
import src.model.ContentMaze;

/**
 * Utilitaire pour afficher un labyrinthe correctement dans un terminal
 *
 * On utilise quelques charatères de la table unicode pour la lisibilité
 */
public class DisplayMazeConsole
{
	public enum charWall
	{
		HORIZONTAL('\u2500'),
		HORIZONTALLEFT('\u2574'),
		HORIZONTALRIGHT('\u2576'),
		VERTICAL('\u2502'),
		VERTICALUP('\u2575'),
		VERTICALDOWN('\u2577'),
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
	 * @param cm Labyrinthe a affiché
	 * @param reverse Sens d'affichage par rapport aux ordonnées
	 */
	public static void displayMaze(ContentMaze[] cm, boolean reverse)
	{
		for (int i = 0; i < cm.length; i++)
		{
			System.out.println("LEVEL " + (i + 1));
			displayMazeSingle(cm[i], reverse);
		}
	}

	/**
	 * Affiche le labyrinthe dans la console
	 * @param cm Labyrinthe a affiché
	 * @param reverse Sens d'affichage par rapport aux ordonnées
	 */
	private static void displayMazeSingle(ContentMaze cm, boolean reverse)
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
			for (int d = 0; d < distanceWall; d++)
			{
				if (maze[yRef][xRef] != null&& ((maze[yRef][xRef].equals(charWall.HORIZONTAL) && !isHorizontal) || (maze[yRef][xRef].equals(charWall.VERTICAL) && isHorizontal)))
				{
					maze[yRef][xRef] = charWall.INTERSECTION;
				}
				else if (maze[yRef][xRef] == null)
				{
					maze[yRef][xRef] = (isHorizontal) ? charWall.HORIZONTAL : charWall.VERTICAL;
				}
				if (isHorizontal)
				{
					xRef++;
				}
				else
				{
					yRef++;
				}
			}
		}
		int i = (reverse) ? maze.length - 1 : 0;
		for (int index = 0; index < maze.length; index++)
		{
			for (int j = 0; j < maze[index].length; j++)
			{
				boolean haut, bas;
				if (reverse)
				{
					bas = (i > 0 && maze[i - 1][j] != null&&
						   (maze[i - 1][j].equals(charWall.VERTICAL) || maze[i - 1][j].equals(charWall.INTERSECTION)));
					haut = (maze[i][j] != null&& (maze[i][j].equals(charWall.VERTICAL) || maze[i][j].equals(charWall.INTERSECTION)));
				}
				else
				{
					haut = (i > 0 && maze[i - 1][j] != null&&
							(maze[i - 1][j].equals(charWall.VERTICAL) || maze[i - 1][j].equals(charWall.INTERSECTION)));
					bas = (maze[i][j] != null&& (maze[i][j].equals(charWall.VERTICAL) || maze[i][j].equals(charWall.INTERSECTION)));
				}
				boolean gauche = (j > 0 && maze[i][j - 1] != null&&
								  (maze[i][j - 1].equals(charWall.HORIZONTAL) || maze[i][j - 1].equals(charWall.INTERSECTION)));
				boolean droit = (maze[i][j] != null&& (maze[i][j].equals(charWall.HORIZONTAL) || maze[i][j].equals(charWall.INTERSECTION)));

				if ((droit && gauche && !haut && !bas))
				{
					System.out.print(charWall.HORIZONTAL);
				}
				else if ((droit && !gauche && !bas && !haut))
				{
					System.out.print(charWall.HORIZONTALRIGHT);
				}
				else if ((!droit && gauche && !bas && !haut))
				{
					System.out.print(charWall.HORIZONTALLEFT);
				}
				else if ((bas && haut && !droit && !gauche))
				{
					System.out.print(charWall.VERTICAL);
				}
				else if ((bas && !haut && !gauche && !droit))
				{
					System.out.print(charWall.VERTICALDOWN);
				}
				else if ((haut && !bas && !gauche && !droit))
				{
					System.out.print(charWall.VERTICALUP);
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
				else if (!haut && !gauche && bas && droit)
				{
					System.out.print(charWall.CORNERBOTTOMRIGHT);
				}
				else
				{
					System.out.print(" ");
				}
			}
			i += (reverse) ? -1 : 1;
			System.out.println();
		}
	}
}
