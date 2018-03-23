package src.model.maps;

import java.util.ArrayList;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.LineWall;
import src.model.board.StartCase;
import src.model.board.TeleportCase;
import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.gen.ContentMazeFactory;
import src.model.gen.ContentMazeFactory.GenFactoryException;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

public class MapIntro5 extends Algo
{
	public MapIntro5() throws GenFactoryException
	{
		super();
		this.cmfactory = new ContentMazeFactory();

		RectMaze rm1 = buildOneSquareLabyrinthe();

		RectMazeShift rms1 = new RectMazeShift(rm1, 0, 0);

		this.cmfactory.addContentMazeShift(rms1);

		this.cmfactory.addSpecialCase(new StartCase(0, 0));
		this.cmfactory.addSpecialCase(new EndCase(9, 0));
		this.cmfactory.addSpecialCase(new TeleportCase(2, 4, 7, 4));
		this.cmfactory.addSpecialCase(new TeleportCase(7, 3, 2, 3));
		this.cmfactory.normalize();
		this.cm = new ContentMaze(this.cmfactory.getFinalSpecialCases(), this.cmfactory.getFinalLineWall());
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
		rl = new RectMaze(new ContentMaze(new Case[0], listWalls.toArray(new LineWall[0])), 10, 6);
		return (rl);
	}
}
