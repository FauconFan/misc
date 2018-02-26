package src.view.scene;

import javafx.scene.Parent;
import javafx.scene.Scene;

import src.view.View;

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
}
