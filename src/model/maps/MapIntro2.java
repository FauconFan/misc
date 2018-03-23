package src.model.maps;

import java.util.ArrayList;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.LineWall;
import src.model.board.StartCase;
import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.gen.ContentMazeFactory;
import src.model.gen.ContentMazeFactory.GenFactoryException;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

public class MapIntro2 extends Algo
{
	private static int size_x = 3;
	private static int size_y = 5;

	public MapIntro2() throws GenFactoryException
	{
		super();
		this.cmfactory = new ContentMazeFactory();

		RectMaze rm1 = buildOneSquareLabyrinthe();

		RectMazeShift rms1 = new RectMazeShift(rm1, 0, 0);

		this.cmfactory.addContentMazeShift(rms1);

		this.cmfactory.addSpecialCase(new StartCase(2, 0));
		this.cmfactory.addSpecialCase(new EndCase(1, 3));
		this.cmfactory.normalize();
		this.cm = new ContentMaze(this.cmfactory.getFinalSpecialCases(), this.cmfactory.getFinalLineWall());
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
		listWalls.add(new LineWall(1, 1, size_x, 1));
		listWalls.add(new LineWall(1, 1, 1, size_y - 1));
		listWalls.add(new LineWall(1, size_y - 1, size_x - 1, size_y - 1));
		listWalls.add(new LineWall(size_x - 1, size_y - 1, size_x - 1, 2));
		rl = new RectMaze(new ContentMaze(new Case[0], listWalls.toArray(new LineWall[0])), size_x, size_y);
		return (rl);
	}
}
