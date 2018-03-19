package src.view.scene.creator;

import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.Scene;
import javafx.stage.Screen;

import src.view.scene.ScenePlus;
import src.view.View;

public class Creator extends ScenePlus
{
	private static int screenWidth  = (int)Screen.getPrimary().getBounds().getWidth();
	private static int screenHeight = (int)Screen.getPrimary().getBounds().getHeight();

	public Creator(View v)
	{
		super(new Group(), screenWidth, screenWidth, false, v);

		Group root = (Group)getRoot();

		final int separator = 100;
		final int start     = 50;

		Group dots = new Group();

		// Draw the circle
		for (int i = start; i < screenWidth; i += separator)
		{
			for (int j = start; j < screenHeight; j += separator)
			{
				Circle c = new Circle(i, j, 5, Color.BLACK);
				dots.getChildren().add(c);
			}
		}

		root.getChildren().addAll(dots);
	}
}
