package src.model.gen;

import src.model.board.Case;
import src.model.board.LineWall;
import src.model.ContentMaze;
import src.model.gen.ContentMazeEgg;
import src.model.gen.MainMazeFactory.GenFactoryException;
import src.model.gen.RectMazeShift;
import src.model.MainMaze;

import java.util.ArrayList;

/**
 * Class API to communicate with Graphic part to create Maze (Creator Mode)
 */
public class CreatorHelper
{
	private MainMazeFactory mmf;

	private final ArrayList <String> wallTextures  = new ArrayList <String>();
	private final ArrayList <String> floorTextures = new ArrayList <String>();

	public CreatorHelper(int ma)
	{
		this.mmf = new MainMazeFactory(ma);
	}

	public void append(int level_actu, int minX, int maxX, int minY, int maxY, LineWall[] lw, Case[] cases, String wallFilename, String floorFilename)
	{
		ContentMazeFactory cmf = new ContentMazeFactory(true);

		wallTextures.add(wallFilename);
		floorTextures.add(floorFilename);

		cmf.addContentMazeShift(new RectMazeShift(new RectMaze(new ContentMazeEgg(cases, lw), Math.abs(maxX - minX), Math.abs(maxY - minY)), 0, 0));

		this.mmf.setContentMazeFactory(cmf, level_actu);
	}

	public MainMaze buildMainMaze(String name, boolean flyMode) throws GenFactoryException
	{
		ContentMaze[] content;

		content = this.mmf.buildContentMaze();
		for (int i = 0; i < content.length; i++)
		{
			content[i].setWallTexturePath(wallTextures.get(i));
			content[i].setFloorTexturePath(wallTextures.get(i));
		}
		return (new MainMaze(content, flyMode));
	}
}
