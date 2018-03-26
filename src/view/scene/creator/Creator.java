package src.view.scene.creator;

import java.util.ArrayList;

import javafx.collections.ObservableList;
import javafx.collections.transformation.FilteredList;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.geometry.Point2D;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollBar;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import javafx.scene.control.Slider;
import javafx.scene.Group;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.Scene;
import javafx.scene.transform.Scale;
import javafx.scene.transform.Translate;
import javafx.stage.Screen;

import src.model.*;
import src.model.board.*;
import src.model.gen.CreatorHelper;
import src.view.scene.game.CaseColor;
import src.view.scene.ScenePlus;
import src.view.View;

public class Creator extends ScenePlus
{
	private static int screenWidth  = (int)Screen.getPrimary().getBounds().getWidth();
	private static int screenHeight = (int)Screen.getPrimary().getBounds().getHeight();

	private Circle startedDraw = null;
	private final VBox leftPaneGr;

	private final int leftPaneGrSize = 150;

	private final Scale sc     = new Scale(100, 100);
	private final Translate tr = new Translate(10, 10); // Décalage par défaut du dessin

	private final Pane walls;                           //MUST contain LinePlus
	private final Group cases;                          //MUST contain RectanglePlus

	public Creator(View v, int width, int height)
	{
		super(new HBox(), screenWidth, screenWidth, false, v);

		setFill(Color.GRAY);

		HBox pane = (HBox)getRoot();
		pane.setAlignment(Pos.CENTER_LEFT);
		StackPane root = new StackPane();

		root.setAlignment(Pos.TOP_LEFT);

		final double dotWidth = 0.1;

		Group dots = new Group();
		walls = new Pane();
		walls.setPickOnBounds(false);
		cases = new Group();

		dots.getTransforms().addAll(tr, sc);
		walls.getTransforms().addAll(tr, sc);
		cases.getTransforms().addAll(tr, sc);

		root.getChildren().addAll(cases, walls, dots);

		// Draw circles
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
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
							final LinePlus newLineWall = new LinePlus((int)startedDraw.getCenterX(), (int)startedDraw.getCenterY(), (int)c.getCenterX(), (int)c.getCenterY());

							boolean isGood = false;
							for (Node n: walls.getChildren())
							{
								LinePlus li             = (LinePlus)n;
								ArrayList <LineWall> lw = LineWallUtils.exceptIfIntersectOrUnion(li.lw, newLineWall.lw);
								if (lw.size() == 0 || lw.size() == 1 || (lw.size() == 2 && !(lw.get(0) == li.lw && lw.get(1) == newLineWall.lw)))
								{
									walls.getChildren().remove(li);
									for (LineWall l: lw)
									{
										walls.getChildren().add(new LinePlus(l));
									}
									isGood = true;
									break;
								}
							}
							if (!isGood)// Les murs ne se superposaient pas
							{
								walls.getChildren().add(newLineWall);
							}
						}
						startedDraw.setFill(Color.BLACK);
						startedDraw = null;
					}
				});
				if (!(j + 1 >= height || i + 1 >= width))// Si on n'est pas sur une ligne du "bord"
				{
					final RectanglePlus rect = new RectanglePlus(i, j, 1, 1);
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
		panel.setMinSize(leftPaneGrSize, 0);
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
				LinePlus li = (LinePlus)l;
				lineWalls.add(li.lw);
			}

			ArrayList <Case> specialCases = new ArrayList <Case>();
			for (Node l: cases.getChildren())
			{
				Case c = ((RectanglePlus)l).getCase();
				if (c != null)
				{
					specialCases.add(c);
				}
			}

			CreatorHelper ch = new CreatorHelper(0, width, 0, height, lineWalls.toArray(new LineWall[0]), specialCases.toArray(new Case[0]));
			try{
				v.con.setMaze(ch.buildMainMaze(""));
				v.showGame();
			}
			catch (Exception e) {
				System.out.println(e);
			}
		});

		ScrollPane sp = new ScrollPane(root);
		sp.setPrefSize(screenWidth - leftPaneGrSize, screenHeight - 100);
		sp.setVbarPolicy(ScrollPane.ScrollBarPolicy.ALWAYS);
		sp.setHbarPolicy(ScrollPane.ScrollBarPolicy.ALWAYS);
		sp.setPadding(new Insets(10, 10, 10, 10));

		sp.setVmax(height - screenHeight / sc.getY());
		sp.setHmax(width - (screenWidth - leftPaneGrSize) / sc.getX() + 7.5);

		sp.vvalueProperty().addListener((ov, old_val, new_val)->{
			tr.setY(tr.getY() + sc.getY() * (old_val.doubleValue() - new_val.doubleValue()));
		});

		sp.hvalueProperty().addListener((ov, old_val, new_val)->{
			tr.setX(tr.getX() + sc.getX() * (old_val.doubleValue() - new_val.doubleValue()));
		});

		pane.getChildren().addAll(panel, sp);
	}

	public Creator(View v, MainMaze maze)
	{
		this(v, maze, maze.getMazeDimension().list_rectmaze.get(0));
	}

	private Creator(View v, MainMaze maze, MazeDimension.RectInMaze md)
	{
		this(v, md.x2 - md.x1, md.y2 - md.y1);
		for (LineWall l: maze.getContentMaze().getLineWalls())
		{
			drawWall(l);
		}
		for (Case c:maze.getContentMaze().getSpecialCases())
		{
			drawCell(c);
		}
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

	private void drawWall(LineWall l)
	{
	}

	private void drawCell(Case c)
	{
	}
}
