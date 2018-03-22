package src.view.scene.creator;

import java.util.ArrayList;

import javafx.collections.ObservableList;
import javafx.collections.transformation.FilteredList;
import javafx.geometry.Insets;
import javafx.geometry.Point2D;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.Group;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.Scene;
import javafx.scene.transform.Scale;
import javafx.stage.Screen;

import src.model.*;
import src.model.board.*;
import src.view.scene.game.CaseColor;
import src.view.scene.ScenePlus;
import src.view.View;

public class Creator extends ScenePlus
{
	private static int screenWidth  = (int)Screen.getPrimary().getBounds().getWidth();
	private static int screenHeight = (int)Screen.getPrimary().getBounds().getHeight();

	private Circle startedDraw = null;
	private final VBox leftPaneGr;

	private final Scale sc = new Scale(100, 100);

	public Creator(View v)
	{
		super(new HBox(), screenWidth, screenWidth, false, v);

		setFill(Color.GRAY);

		HBox pane = (HBox)getRoot();
		pane.setAlignment(Pos.BASELINE_LEFT);
		StackPane root = new StackPane();

		Group dots  = new Group();
		Group walls = new Group();
		Group cases = new Group();

		dots.getTransforms().add(sc);
		walls.getTransforms().add(sc);
		cases.getTransforms().add(sc);

		root.getChildren().addAll(cases, dots, walls);

		final double dotWidth = 0.1;
		final int    width    = 20;
		final int    height   = 10;

		// Draw circles
		// They are with almost integer values (modified by dotWidth)
		for (double i = dotWidth; i < width; i++)
		{
			for (double j = dotWidth; j < height; j++)
			{
				final Circle c = new Circle(i, j, dotWidth, Color.BLACK);
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
							final LinePlus l = new LinePlus(startedDraw.getCenterX() - dotWidth / 2, startedDraw.getCenterY() - dotWidth / 2, c.getCenterX() - dotWidth / 2, c.getCenterY() - dotWidth / 2);
							if (!removeLine(walls.getChildren(), l)) // Si on ne l'avait pas déjà
							{
								l.setStrokeWidth(0.05);
								walls.getChildren().add(l);
							}
						}
						startedDraw.setFill(Color.BLACK);
						startedDraw = null;
					}
				});
				if (!(j + 1 >= height || i + 1 >= width))// Si on n'est pas sur une ligne du "bord"
				{
					final RectanglePlus rect = new RectanglePlus(i, j, 1, 1, (int)(i - dotWidth), (int)(j - dotWidth));
					rect.setOnMouseClicked((ev)->{
						rect.changeCase();
						updateLeftPane(rect);
					});
					cases.getChildren().add(rect);
				}
				dots.getChildren().add(c);
			}
		}

		VBox panel = new VBox();
		panel.setMinSize(150, 0);
		panel.setAlignment(Pos.TOP_CENTER);
		panel.setPadding(new Insets(20, 0, 20, 0));

		Button button = new Button("Finish");

		leftPaneGr = new VBox();
		leftPaneGr.setAlignment(Pos.TOP_CENTER);
		leftPaneGr.setPadding(new Insets(20, 0, 20, 0));

		panel.getChildren().addAll(button, leftPaneGr);

		button.setOnAction((ev)->{
			ArrayList <LineWall> lineWalls = new ArrayList <LineWall>();
			for (Node l: walls.getChildren())
			{
				Line li = (Line)l;
				lineWalls.add(new LineWall((int)(li.getStartX() - dotWidth), (int)(li.getStartY() - dotWidth), (int)(li.getEndX() - dotWidth), (int)(li.getEndY() - dotWidth)));
			}

			ArrayList <Case> specialCases = new ArrayList <Case>();
			for (Node l: cases.getChildren())
			{
				RectanglePlus rect = (RectanglePlus)l;
				Case c             = rect.getCase();
				if (c != null)
				{
					specialCases.add(c);
				}
			}

			MazeDimension md = new MazeDimension();
			md.append(0, 0, 20, 20);

			MainMaze mm = new MainMaze(new ContentMaze(specialCases.toArray(new Case[specialCases.size()]), lineWalls.toArray(new LineWall[lineWalls.size()])), md, "", new Player(0.05f, 0.5f, 0.5f, 0f, 0f, 0f));

			v.con.setMaze(mm);
			v.showGame();
		});

		pane.getChildren().addAll(panel, root);
	}

	/**
	 * Update the left pane according to the new case
	 */
	private void updateLeftPane(RectanglePlus startedRect)
	{
		leftPaneGr.getChildren().clear();
		Case c = startedRect.getCase();

		if (c != null)
		{
			leftPaneGr.getChildren().add(new Label(c.type + " case"));
			switch (c.type)
			{
			case TELEPORT:
				//TODO
				break;

			case TIME:
				Slider slider = new Slider();
				slider.setMin(-5);
				slider.setValue(((TimeCase)c).getTimeMillis());
				slider.setMax(5);
				slider.setShowTickLabels(true);
				slider.setMajorTickUnit(0.25f);
				slider.setBlockIncrement(0.25f);
				slider.valueProperty().addListener((ov, x, z)->{
					((TimeCase)c).setTimeMilis(z.longValue());
				});
				leftPaneGr.getChildren().add(slider);
				break;

			case SPEED:
				Slider sliderS = new Slider();
				sliderS.setMin(0);
				sliderS.setValue(((SpeedCase)c).getSpeedModif());
				sliderS.setMax(5);
				sliderS.setShowTickLabels(true);
				sliderS.setMajorTickUnit(0.25f);
				sliderS.setBlockIncrement(0.25f);
				sliderS.valueProperty().addListener((ov, x, z)->{
					((SpeedCase)c).setSpeedModif(z.floatValue());
				});
				leftPaneGr.getChildren().add(sliderS);
				break;
			}
		}
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
