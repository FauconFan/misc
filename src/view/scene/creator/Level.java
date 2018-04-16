package src.view.scene.creator;

import javafx.scene.layout.Pane;

class Level
{
	//walls MUST contain LinePlus
	//cases MUST contain RectanglePlus
	public final Pane walls, cases, dots;
	private String wallTexture, floorTexture;

	public Level(Pane w, Pane c, Pane d)
	{
		walls = w;
		cases = c;
		dots  = d;

		dots.setPickOnBounds(false);
		walls.setPickOnBounds(false);
	}

	public Level()
	{
		this(new Pane(), new Pane(), new Pane());
	}

	public void setWallTexture(String s)
	{
		wallTexture = s;
	}

	public void setFloorTexture(String s)
	{
		floorTexture = s;
	}

	public String getWallTexture()
	{
		return (wallTexture);
	}

	public String getFloorTexture()
	{
		return (floorTexture);
	}
}
