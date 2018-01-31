package src.model.gen;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.LineWall;
import src.model.board.StartCase;
import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.gen.ContentMazeFactory;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

import java.util.ArrayList;

public class AlgoSample extends Algo
{
	public static int SIZE_SQUARE = 10;

	public AlgoSample()
	{
		super();
		this.cmfactory = new ContentMazeFactory();

		RectMaze rm1 = buildOneSquareLabyrinthe(false, false);
		RectMaze rm2 = buildOneSquareLabyrinthe(true, true);
		RectMaze rm3 = buildOneSquareLabyrinthe(false, false);
		RectMaze rm4 = buildOneSquareLabyrinthe(false, false);
		RectMaze rm5 = buildOneSquareLabyrinthe(false, false);
		RectMaze rm6 = buildOneSquareLabyrinthe(false, false);

		RectMazeShift rms1 = new RectMazeShift(rm1, 0, 0);
		RectMazeShift rms2 = new RectMazeShift(rm2, SIZE_SQUARE, SIZE_SQUARE / 2);
		RectMazeShift rms3 = new RectMazeShift(rm3, 0, SIZE_SQUARE);
		RectMazeShift rms4 = new RectMazeShift(rm4, -SIZE_SQUARE, 0);
		RectMazeShift rms5 = new RectMazeShift(rm5, -SIZE_SQUARE, SIZE_SQUARE);
		RectMazeShift rms6 = new RectMazeShift(rm6, SIZE_SQUARE * 3 / 2, -SIZE_SQUARE / 2);

		this.cmfactory.addContentMazeShift(rms1);
		this.cmfactory.addContentMazeShift(rms2);
		this.cmfactory.addContentMazeShift(rms3);
		this.cmfactory.addContentMazeShift(rms4);
		this.cmfactory.addContentMazeShift(rms5);
		this.cmfactory.addContentMazeShift(rms6);

		this.cmfactory.normalize();
		this.cm = new ContentMaze(this.cmfactory.getFinalSpecialCases(), this.cmfactory.getFinalLineWall());
	}

	private RectMaze buildOneSquareLabyrinthe(boolean hasStartCase, boolean hasEndCase)
	{
		RectMaze rl;

		Case[]     listSpecialeCases;
		LineWall[] listWalls;

		listSpecialeCases = this.buildCases(hasStartCase, hasEndCase);
		listWalls         = this.buildWalls();
		rl = new RectMaze(new ContentMaze(listSpecialeCases, listWalls), SIZE_SQUARE, SIZE_SQUARE);
		return (rl);
	}

	private Case[] buildCases(boolean hasStartCase, boolean hasEndCase)
	{
		Case[] listSpecialeCases;

		if (hasStartCase && hasEndCase)
		{
			listSpecialeCases    = new Case[2];
			listSpecialeCases[0] = new StartCase(2, 2);
			listSpecialeCases[1] = new EndCase(8, 8);
		}
		else if (hasStartCase || hasEndCase)
		{
			listSpecialeCases = new Case[1];
			if (hasStartCase)
			{
				listSpecialeCases[0] = new StartCase(2, 2);
			}
			else
			{
				listSpecialeCases[0] = new EndCase(8, 8);
			}
		}
		else
		{
			listSpecialeCases = new Case[0];
		}
		return (listSpecialeCases);
	}

	private LineWall[] buildWalls()
	{
		ArrayList <LineWall> res = new ArrayList <>();

		res.add(new LineWall(0, 0, 0, SIZE_SQUARE));
		res.add(new LineWall(SIZE_SQUARE, SIZE_SQUARE, SIZE_SQUARE, 0));
		res.add(new LineWall(0, 0, SIZE_SQUARE, 0));
		res.add(new LineWall(0, SIZE_SQUARE, SIZE_SQUARE, SIZE_SQUARE));
		if (SIZE_SQUARE > 1)
		{
			for (int i = 1; i < SIZE_SQUARE; i++)
			{
				if (i % 2 == 1)
				{
					res.add(new LineWall(i, 0, i, SIZE_SQUARE - 1));
				}
				else
				{
					res.add(new LineWall(i, 1, i, SIZE_SQUARE));
				}
			}
		}
		return (res.toArray(new LineWall[0]));
	}
}
