package src.model.maps;

import java.util.ArrayList;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.LineWall;
import src.model.board.StartCase;
import src.model.board.TimeCase;
import src.model.ContentMaze;
import src.model.gen.Algo;
import src.model.gen.ContentMazeEgg;
import src.model.gen.ContentMazeFactory;
import src.model.gen.MainMazeFactory;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

public class MapIntro3 extends Algo
{
	private static int size_x = 7;
	private static int size_y = 15;

	public MapIntro3()
	{
		super();
		ContentMazeFactory cmf = new ContentMazeFactory(true);

		this.mmfactory = new MainMazeFactory(1);
		this.mmfactory.setContentMazeFactory(cmf, 0);

		RectMaze rm1 = buildOneSquareLabyrinthe();

		RectMazeShift rms1 = new RectMazeShift(rm1, 0, 0);

		cmf.addContentMazeShift(rms1);

		cmf.addSpecialCase(new StartCase(3, 2));
		cmf.addSpecialCase(new EndCase(3, 13));
		cmf.addSpecialCase(new TimeCase(1, 6, 10000));
		cmf.addSpecialCase(new TimeCase(5, 6, -10000));
		cmf.normalize();
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
