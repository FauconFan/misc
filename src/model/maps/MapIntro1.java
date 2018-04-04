package src.model.maps;

import java.util.ArrayList;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.JumpCase;
import src.model.board.LineWall;
import src.model.board.MessageCase;
import src.model.board.StartCase;
import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.gen.ContentMazeEgg;
import src.model.gen.ContentMazeFactory;
import src.model.gen.ContentMazeFactory.GenFactoryException;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

public class MapIntro1 extends Algo
{
	private static int size_x = 7;
	private static int size_y = 15;

	public MapIntro1() throws GenFactoryException
	{
		super();
		this.cmfactory    = new ContentMazeFactory[1];
		this.cmfactory[0] = new ContentMazeFactory();

		RectMaze rm1 = buildOneSquareLabyrinthe();

		RectMazeShift rms1 = new RectMazeShift(rm1, 0, 0);

		this.cmfactory[0].addContentMazeShift(rms1);

		this.cmfactory[0].addSpecialCase(new StartCase(3, 2));
		this.cmfactory[0].addSpecialCase(new EndCase(3, 13));
		this.cmfactory[0].addSpecialCase(new MessageCase(3, 5, "Hello"));
		this.cmfactory[0].addSpecialCase(new JumpCase(2, 3, 5));

		this.cmfactory[0].normalize();
	}

	private RectMaze buildOneSquareLabyrinthe()
	{
		RectMaze rl;

		ArrayList <LineWall> listWalls;

		listWalls = new ArrayList <>();
		listWalls.add(new LineWall(0, 0, 0, size_y));
		listWalls.add(new LineWall(size_x, size_y, size_x, 0));
		listWalls.add(new LineWall(0, 0, size_x, 0));
		listWalls.add(new LineWall(0, size_y, size_x, size_y));
		rl = new RectMaze(new ContentMazeEgg(new Case[0], listWalls.toArray(new LineWall[0])), size_x, size_y);
		return (rl);
	}
}
