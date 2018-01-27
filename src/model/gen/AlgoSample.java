package src.model.gen;

import src.model.Case;
import src.model.EndCase;
import src.model.gen.Algo;
import src.model.LineWall;
import src.model.RectLabyrinthe;
import src.model.RectLabyrintheShift;
import src.model.StartCase;

public class AlgoSample extends Algo
{
	public static int SIZE_SQUARE = 10;

	private RectLabyrinthe buildOneSquareLabyrinthe(boolean hasStartCase, boolean hasEndCase)
	{
		RectLabyrinthe rl;

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
		rl = new RectLabyrinthe(listSpecialeCases, new LineWall[0], SIZE_SQUARE, SIZE_SQUARE);
		return (rl);
	}

	public RectLabyrintheShift[] buildSubLabyrinthe()
	{
		RectLabyrintheShift[] res = new RectLabyrintheShift[2];

		res[0] = new RectLabyrintheShift(buildOneSquareLabyrinthe(false, false), 0, 0);
		res[1] = new RectLabyrintheShift(buildOneSquareLabyrinthe(true, true), SIZE_SQUARE, SIZE_SQUARE / 2);;
		return (res);
	}
}
