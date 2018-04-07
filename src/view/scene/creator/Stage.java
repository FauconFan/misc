package src.view.scene.creator;

import javafx.scene.layout.Pane;

class Stage
{
	//walls MUST contain LinePlus
	//cases MUST contain RectanglePlus
	public final Pane walls, cases, dots;

	public Stage(Pane w, Pane c, Pane d)
	{
		walls = w;
		cases = c;
		dots  = d;

		dots.setPickOnBounds(false);
		walls.setPickOnBounds(false);
	}

	public Stage()
	{
		this(new Pane(), new Pane(), new Pane());
	}
}
