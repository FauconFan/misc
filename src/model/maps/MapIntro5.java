package src.model.maps;

import java.util.ArrayList;

import src.model.board.Case;
import src.model.board.EndCase;
import src.model.board.LineWall;
import src.model.board.StartCase;
import src.model.board.TeleportCase;
import src.model.gen.Algo;
import src.model.gen.ContentMazeEgg;
import src.model.gen.ContentMazeFactory;
import src.model.gen.MainMazeFactory;
import src.model.gen.RectMaze;
import src.model.gen.RectMazeShift;

public class MapIntro5 extends Algo
{
	public MapIntro5()
	{
		super();
		ContentMazeFactory cmf = new ContentMazeFactory(true);

		this.mmfactory = new MainMazeFactory(1);
		this.mmfactory.setContentMazeFactory(cmf, 0);

		RectMaze rm1 = buildOneSquareLabyrinthe();

		RectMazeShift rms1 = new RectMazeShift(rm1, 0, 0);

		cmf.addContentMazeShift(rms1);

		cmf.addSpecialCase(new StartCase(0, 0));
		cmf.addSpecialCase(new EndCase(9, 0));
		cmf.addSpecialCase(new TeleportCase(2, 4, 7, 4, 0));
		cmf.addSpecialCase(new TeleportCase(7, 3, 2, 3, 0));
		cmf.normalize();
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
