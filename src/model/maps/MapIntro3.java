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
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

public class MapIntro3 extends Algo
{
	private static int size_x = 7;
	private static int size_y = 15;

	public MapIntro3()
	{
		super();
		this.cmfactory = new ContentMazeFactory();

		RectMaze rm1 = buildOneSquareLabyrinthe();

		RectMazeShift rms1 = new RectMazeShift(rm1, 0, 0);

		this.cmfactory.addContentMazeShift(rms1);

		this.cmfactory.addSpecialCase(new StartCase(3, 2));
		this.cmfactory.addSpecialCase(new EndCase(3, 13));
		this.cmfactory.addSpecialCase(new TimeCase(1, 6, 10000));
		this.cmfactory.addSpecialCase(new TimeCase(5, 6, -10000));
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
		rl = new RectMaze(new ContentMaze(new Case[0], listWalls.toArray(new LineWall[0])), size_x, size_y);
		return (rl);
	}
}
