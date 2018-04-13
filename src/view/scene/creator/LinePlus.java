package src.view.scene.creator;

import javafx.scene.shape.Line;

import src.model.*;
import src.model.board.*;

/**
 * A linePlus is a JavaFX line paired with the correspondant LineWal
 */
class LinePlus extends Line
{
	public final LineWall lw;

	public LinePlus(int a, int b, int c, int d)
	{
		super(a, b, c, d);
		lw = new LineWall(a, b, c, d);
		create();
	}

	public LinePlus(LineWall lw)
	{
		super(lw.getX1(), lw.getY1(), lw.getX2(), lw.getY2());
		this.lw = lw;
		create();
	}

	public void create()
	{
		setStrokeWidth(0.05);
	}

	public boolean equals(Line l1)
	{
		return ((l1.getStartX() == getStartX() && l1.getStartY() == getStartY() && l1.getEndX() == getEndX() && l1.getEndY() == getEndY()) || (l1.getStartX() == getEndX() && l1.getStartY() == getEndY() && l1.getEndX() == getStartX() && l1.getEndY() == getStartY()));
	}
}
