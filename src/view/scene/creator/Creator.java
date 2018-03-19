package src.view.scene.creator;

import javafx.collections.ObservableList;
import javafx.collections.transformation.FilteredList;
import javafx.geometry.Point2D;
import javafx.scene.control.Button;
import javafx.scene.Group;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.Scene;
import javafx.stage.Screen;

import src.view.scene.ScenePlus;
import src.view.View;

public class Creator extends ScenePlus
{
	private static int screenWidth  = (int)Screen.getPrimary().getBounds().getWidth();
	private static int screenHeight = (int)Screen.getPrimary().getBounds().getHeight();

	private Circle startedDraw = null;

	public Creator(View v)
	{
		super(new Group(), screenWidth, screenWidth, false, v);

		setFill(Color.GRAY);

		Group root = (Group)getRoot();

		final int separator = 100;
		final int start     = 50;

		Group dots  = new Group();
		Group walls = new Group();

		// Draw the circle
		for (int i = start; i < screenWidth; i += separator)
		{
			for (int j = start; j < screenHeight; j += separator)
			{
				final Circle c = new Circle(i, j, 8, Color.BLACK);
				c.setOnMouseClicked((ev)->{
					if (startedDraw == null)
					{
						startedDraw = c;
						c.setFill(Color.RED);
					}
					else if (c == startedDraw)
					{
						startedDraw = null;
						c.setFill(Color.BLACK);
					}
					else
					{
						if (startedDraw.getCenterX() == c.getCenterX() || startedDraw.getCenterY() == c.getCenterY())
						{
							final LinePlus l = new LinePlus(startedDraw.getCenterX(), startedDraw.getCenterY(), c.getCenterX(), c.getCenterY());
							if (!removeLine(walls.getChildren(), l)) // Si on ne l'avait pas déjà
							{
								walls.getChildren().add(l);
							}
						}
						startedDraw.setFill(Color.BLACK);
						startedDraw = null;
					}
				});
				dots.getChildren().add(c);
			}
		}

		Button button = new Button("Finish");

		button.setOnAction((ev)->{
			//TODO -> Transformer les Line en LineWall et créer le MainMaze qui va bien.
		});

		root.getChildren().addAll(dots, walls, button);
	}

	private < E > boolean removeLine(ObservableList <E> g, LinePlus l)
	{
		FilteredList <E> fil = g.filtered((li)->((LinePlus)li).equals(l));
		if (fil.size() == 0)
		{
			return (false);
		}
		try{
			for (E e: fil)
			{
				g.remove(e);
			}
		}catch (Exception E) {}

		return (true);
	}

	class LinePlus extends Line
	{
		public LinePlus(double a, double b, double c, double d)
		{
			super(a, b, c, d);
		}

		public boolean equals(Line l1)
		{
			return ((l1.getStartX() == getStartX() && l1.getStartY() == getStartY() && l1.getEndX() == getEndX() && l1.getEndY() == getEndY()) || (l1.getStartX() == getEndX() && l1.getStartY() == getEndY() && l1.getEndX() == getStartX() && l1.getEndY() == getStartY()));
		}
	}
}
