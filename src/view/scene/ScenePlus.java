package src.view.scene;

import javafx.scene.Parent;
import javafx.scene.Scene;

import src.view.View;

/**
 * Class for storing a View
 */
public class ScenePlus extends Scene
{
	protected final View v;

	public ScenePlus(Parent p, View v)
	{
		super(p);
		this.v = v;
	}

	public ScenePlus(Parent p, int a, int b, boolean bool, View v)
	{
		super(p, a, b, bool);
		this.v = v;
	}

	public static class ScenePlusMenu extends ScenePlus
	{
		public ScenePlusMenu(Parent p, View v)
		{
			super(p, v);
			getStylesheets().add("menuStyle.css");
		}
	}
}
