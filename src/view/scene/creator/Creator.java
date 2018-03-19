package src.view.scene.creator;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.ArcType;
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

		Canvas canvas = new Canvas(screenWidth, screenHeight);

		GraphicsContext gc = canvas.getGraphicsContext2D();


		// Draw the circle
		for (int i = 50; i < screenWidth; i += 100)
		{
			for (int j = 50; j < screenHeight; j += 100)
			{
				gc.strokeArc(i, j, 10, 10, 0, 360, ArcType.OPEN);
			}
		}


		root.getChildren().add(canvas);
	}
}
