package src.view.scene;

import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Screen;

import src.view.View;

/**
 * Classe mère pour les scènes du jeu, contient surtout la vue
 */
public class ScenePlus extends Scene
{
	protected static int screenWidth  = (int)Screen.getPrimary().getVisualBounds().getMaxX();
	protected static int screenHeight = (int)Screen.getPrimary().getVisualBounds().getMaxY();

	protected final View v;

	public ScenePlus(Parent p, View v)
	{
		super(p);
		this.v = v;
	}

	public ScenePlus(Parent p, boolean bool, View v)
	{
		super(p, screenWidth, screenHeight, bool);
		this.v = v;
	}

	/**
	 * Classe ajoutant un style de menu à la scène
	 */
	public static class ScenePlusMenu extends ScenePlus
	{
		public ScenePlusMenu(Parent p, View v)
		{
			super(p, v);
			getStylesheets().add("menuStyle.css");
		}
	}
}
