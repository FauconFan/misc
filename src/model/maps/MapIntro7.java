package src.model.maps;

import java.util.ArrayList;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.LineWall;
import src.model.board.SpeedCase;
import src.model.board.StartCase;
import src.model.board.TeleportCase;
import src.model.board.TimeCase;
import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.gen.ContentMazeFactory;
import src.model.gen.ContentMazeFactory.GenFactoryException;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

public class MapIntro7 extends Algo
{
	public int size_y = 9;

	public MapIntro7() throws GenFactoryException
	{
		super();
		this.cmfactory = new ContentMazeFactory();

		RectMaze rm1 = buildOneSquareLabyrinthe();

		RectMazeShift rms1 = new RectMazeShift(rm1, 0, 0);

		this.cmfactory.addContentMazeShift(rms1);

		this.cmfactory.addSpecialCase(new StartCase(1, 5));
		this.cmfactory.addSpecialCase(new EndCase(size_y - 1, 0));
		this.cmfactory.addSpecialCase(new TeleportCase(0, 0, 1, 4));
		this.cmfactory.addSpecialCase(new SpeedCase(2, 4, 0.5f));
		this.cmfactory.addSpecialCase(new TimeCase(3, 2, 1000));
		this.cmfactory.addSpecialCase(new SpeedCase(8, 2, 1.5f));
		this.cmfactory.normalize();
		this.cm = new ContentMaze(this.cmfactory.getFinalSpecialCases(), this.cmfactory.getFinalLineWall());
	}

	private RectMaze buildOneSquareLabyrinthe()
	{
		RectMaze rl;

		ArrayList <LineWall> listWalls;

		listWalls = new ArrayList <>();
		listWalls.add(new LineWall(0, 0, 0, 7));
		listWalls.add(new LineWall(size_y, 7, size_y, 0));
		listWalls.add(new LineWall(0, 0, size_y, 0));
		listWalls.add(new LineWall(0, 7, size_y, 7));
		listWalls.add(new LineWall(1, 0, 1, 2));
		listWalls.add(new LineWall(1, 3, 1, 6));
		listWalls.add(new LineWall(2, 1, 2, 3));
		listWalls.add(new LineWall(2, 4, 2, 6));
		listWalls.add(new LineWall(2, 4, 3, 4));
		listWalls.add(new LineWall(3, 4, 3, 5));
		listWalls.add(new LineWall(3, 2, 3, 3));
		listWalls.add(new LineWall(3, 3, size_y - 3, 3));
		listWalls.add(new LineWall(4, 4, size_y - 3, 4));
		listWalls.add(new LineWall(size_y - 2, 5, size_y - 2, 2));
		listWalls.add(new LineWall(size_y - 2, 2, 3, 2));
		listWalls.add(new LineWall(1, 6, size_y - 1, 6));
		listWalls.add(new LineWall(1, 3, 2, 3));
		listWalls.add(new LineWall(size_y - 1, 2, size_y - 1, 6));
		listWalls.add(new LineWall(size_y, 1, 2, 1));
		listWalls.add(new LineWall(size_y - 2, 5, 3, 5));
		rl = new RectMaze(new ContentMaze(new Case[0], listWalls.toArray(new LineWall[0])), size_y, 7);
		return (rl);
	}
}
