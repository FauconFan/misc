package src.model.gen;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.LineWall;
import src.model.board.StartCase;
import src.model.gen.Algo;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

import java.util.ArrayList;

public class AlgoSample extends Algo
{
	public static int SIZE_SQUARE = 10;

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

	private LineWall[] buildWalls(boolean door)
	{
		ArrayList <LineWall> res = new ArrayList <>();

		res.add(new LineWall(0, 0, 0, SIZE_SQUARE));
		res.add(new LineWall(SIZE_SQUARE, SIZE_SQUARE, SIZE_SQUARE, 0));
		if (door)
		{
			res.add(new LineWall(0, SIZE_SQUARE, SIZE_SQUARE / 2 + 2, SIZE_SQUARE));
			res.add(new LineWall(SIZE_SQUARE / 2 + 3, SIZE_SQUARE, SIZE_SQUARE, SIZE_SQUARE));
			res.add(new LineWall(0, 0, SIZE_SQUARE, 0));
		}
		else
		{
			res.add(new LineWall(0, SIZE_SQUARE, SIZE_SQUARE, SIZE_SQUARE));
		}
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

	private RectMaze buildOneSquareLabyrinthe(boolean hasStartCase, boolean hasEndCase, boolean door)
	{
		RectMaze rl;

		Case[]     listSpecialeCases;
		LineWall[] listWalls;

		listSpecialeCases = this.buildCases(hasStartCase, hasEndCase);
		listWalls         = this.buildWalls(door);
		rl = new RectMaze(listSpecialeCases, listWalls, SIZE_SQUARE, SIZE_SQUARE);
		return (rl);
	}

	public RectMazeShift[] buildSubMaze()
	{
		RectMazeShift[] res = new RectMazeShift[2];

		res[0] = new RectMazeShift(buildOneSquareLabyrinthe(false, false, true), 0, 0);
		res[1] = new RectMazeShift(buildOneSquareLabyrinthe(true, true, false), SIZE_SQUARE, SIZE_SQUARE / 2);;
		return (res);
	}
}
