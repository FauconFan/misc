package src.view.scene.creator;

import java.util.ArrayList;
import javafx.scene.layout.Pane;

class Level
{
	//walls MUST contain LinePlus
	public final Pane walls;
	public final ArrayList <RectanglePlus> cases;
	private String wallTexture, floorTexture;

	public Level(Pane w, ArrayList <RectanglePlus> c)
	{
		walls = w;
		cases = c;
		walls.setPickOnBounds(false);
	}

	public Level()
	{
		this(new Pane(), new ArrayList <RectanglePlus>());
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
