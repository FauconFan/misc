package src.view.scene.creator;

import javafx.scene.layout.Pane;

class Level
{
	//walls MUST contain LinePlus
	//cases MUST contain RectanglePlus
	public final Pane walls, cases, dots;
	private String texture;

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

	public void setTexture(String s)
	{
		texture = s;
	}

	public String getTexture()
	{
		return (texture);
	}

	public String toString()
	{
		return ("Level with : " + texture);
	}
}
