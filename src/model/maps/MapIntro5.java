package src.model.maps;

import java.util.ArrayList;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.LineWall;
import src.model.board.StartCase;
import src.model.board.TeleportCase;
import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.gen.ContentMazeEgg;
import src.model.gen.ContentMazeFactory;
import src.model.gen.ContentMazeFactory.GenFactoryException;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

public class MapIntro5 extends Algo
{
	public MapIntro5() throws GenFactoryException
	{
		super();
		this.cmfactory    = new ContentMazeFactory [1];
		this.cmfactory[0] = new ContentMazeFactory();

		RectMaze rm1 = buildOneSquareLabyrinthe();

		RectMazeShift rms1 = new RectMazeShift(rm1, 0, 0);

		this.cmfactory[0].addContentMazeShift(rms1);

		this.cmfactory[0].addSpecialCase(new StartCase(0, 0));
		this.cmfactory[0].addSpecialCase(new EndCase(9, 0));
		this.cmfactory[0].addSpecialCase(new TeleportCase(2, 4, 7, 4));
		this.cmfactory[0].addSpecialCase(new TeleportCase(7, 3, 2, 3));
		this.cmfactory[0].normalize();
	}

	private RectMaze buildOneSquareLabyrinthe()
	{
		RectMaze rl;

		ArrayList <LineWall> listWalls;

		listWalls = new ArrayList <>();
		listWalls.add(new LineWall(0, 0, 0, 6));
		listWalls.add(new LineWall(10, 6, 10, 0));
		listWalls.add(new LineWall(0, 0, 10, 0));
		listWalls.add(new LineWall(0, 6, 10, 6));
		listWalls.add(new LineWall(5, 0, 5, 6));
		rl = new RectMaze(new ContentMazeEgg(new Case[0], listWalls.toArray(new LineWall[0])), 10, 6);
		return (rl);
	}
}
