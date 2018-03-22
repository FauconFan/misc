package src.view.scene.creator;

import java.util.Iterator;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.Scene;
import javafx.stage.Screen;

import src.model.*;
import src.model.board.*;
import src.view.scene.game.CaseColor;
import src.view.scene.ScenePlus;
import src.view.View;


// Hold the x/y center of the rectangle + The possible Case
class RectanglePlus extends Rectangle
{
	public final int x, y;

	private Case cas;
	private final CircularArray circ = new CircularArray();

	public RectanglePlus(double a, double b, double c, double d, int x, int y)
	{
		super(a, b, c, d);
		this.x = x;
		this.y = y;

		setStrokeWidth(0.001);
		setStroke(Color.BLACK);
		setFill(Color.WHITE);
	}

	public Case getCase()
	{
		return (this.cas);
	}

	public void changeCase()
	{
		Case.TypeCase t = circ.next();
		if (t == null)
		{
			cas = null;
			setFill(Color.WHITE);
		}
		else
		{
			switch (t)
			{
			case START: cas = new StartCase(x, y); break;

			case END: cas = new EndCase(x, y); break;

			case TIME: cas = new TimeCase(x, y, 0); break;

			case SPEED: cas = new SpeedCase(x, y, 1); break;

			case TELEPORT: cas = new TeleportCase(x, y, 0, 0); break;
			}
			setFill(CaseColor.getColor(t));
		}
	}

	public void changeCase(Case c)
	{
		this.cas = c;
	}

	private class CircularArray implements Iterator <Case.TypeCase>
	{
		private int ind = -1;
		private final Case.TypeCase[] liste = Case.TypeCase.values();

		public boolean hasNext()
		{
			return (true);
		}

		public Case.TypeCase next()
		{
			ind = (ind + 1) % (liste.length + 1);
			return ((ind == liste.length) ? null : liste[ind]);
		}
	}
}
