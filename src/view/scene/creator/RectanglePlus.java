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

/**
 * A RectanglePlus is a JavaFx rectangle with maybe a correspondant Case
 */
class RectanglePlus extends Rectangle
{
	private Case cas;
	private final CircularArray circ = new CircularArray();

	public RectanglePlus(double a, double b, double c, double d)
	{
		super(a, b, c, d);
		setFill(Color.WHITE);
		init();
	}

	public RectanglePlus(Case c)
	{
		super(c.getX(), c.getY(), 1, 1);//NOT GOOD
		this.cas = c;
		circ.setIndex(c.type);
		setFill(CaseColor.getColor(c.type));
		init();
	}

	private void init()
	{
		setStrokeWidth(0.001);
		setStroke(Color.BLACK);
	}

	public Case getCase()
	{
		return (this.cas);
	}

	public int getIntX()
	{
		return ((int)getX());
	}

	public int getIntY()
	{
		return ((int)getY());
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
			case START: cas = new StartCase(getIntX(), getIntY()); break;

			case END: cas = new EndCase(getIntX(), getIntY()); break;

			case TIME: cas = new TimeCase(getIntX(), getIntY(), 0); break;

			case SPEED: cas = new SpeedCase(getIntX(), getIntY(), 1); break;

			case TELEPORT: cas = new TeleportCase(getIntX(), getIntY(), 0, 0, 0); break;

			case JUMP: cas = new JumpCase(getIntX(), getIntY(), 1); break;

			default: changeCase(); break;
			}
			setFill(CaseColor.getColor(cas.type));
		}
	}

	public void changeCase(Case c)
	{
		this.cas = c;
	}

	/**
	 * Array for sotring the Cases
	 */
	private class CircularArray implements Iterator <Case.TypeCase>
	{
		private int ind = -1;
		private final Case.TypeCase[] liste = Case.TypeCase.values();

		public boolean hasNext()
		{
			return (true);
		}

		public void setIndex(Case.TypeCase c)
		{
			for (int i = 0; i < liste.length; i++)
			{
				if (c == liste[i])
				{
					ind = i;
				}
			}
		}

		public Case.TypeCase next()
		{
			ind = (ind + 1) % (liste.length + 1);
			return ((ind == liste.length) ? null : liste[ind]);
		}
	}
}
