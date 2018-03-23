package src.model.maps;

import java.util.ArrayList;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.LineWall;
import src.model.board.StartCase;
import src.model.board.TimeCase;
import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.gen.ContentMazeFactory;
import src.model.gen.ContentMazeFactory.GenFactoryException;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

public class MapIntro4 extends Algo
{
	public MapIntro4() throws GenFactoryException
	{
		super();
		this.cmfactory = new ContentMazeFactory();

		RectMaze rm1 = buildOneSquareLabyrinthe();

		RectMazeShift rms1 = new RectMazeShift(rm1, 0, 0);

		this.cmfactory.addContentMazeShift(rms1);

		this.cmfactory.addSpecialCase(new StartCase(0, 0));
		this.cmfactory.addSpecialCase(new EndCase(4, 1));
		this.cmfactory.addSpecialCase(new TimeCase(2, 3, 10000));
		this.cmfactory.addSpecialCase(new TimeCase(6, 3, 10000));
		this.cmfactory.addSpecialCase(new TimeCase(6, 1, 10000));
		this.cmfactory.normalize();
		this.cm = new ContentMaze(this.cmfactory.getFinalSpecialCases(), this.cmfactory.getFinalLineWall());
	}

	private RectMaze buildOneSquareLabyrinthe()
	{
		RectMaze rl;

		ArrayList <LineWall> listWalls;

		listWalls = new ArrayList <>();
		listWalls.add(new LineWall(0, 0, 0, 4));
		listWalls.add(new LineWall(7, 4, 7, 0));
		listWalls.add(new LineWall(0, 0, 7, 0));
		listWalls.add(new LineWall(0, 4, 7, 4));
		listWalls.add(new LineWall(1, 0, 1, 3));
		listWalls.add(new LineWall(2, 3, 6, 3));
		listWalls.add(new LineWall(1, 2, 5, 2));
		listWalls.add(new LineWall(5, 2, 5, 1));
		listWalls.add(new LineWall(5, 1, 2, 1));
		listWalls.add(new LineWall(6, 3, 6, 1));
		rl = new RectMaze(new ContentMaze(new Case[0], listWalls.toArray(new LineWall[0])), 7, 4);
		return (rl);
	}
}
