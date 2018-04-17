package src.view.scene.creator;

import java.util.ArrayList;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.ButtonType;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.Scene;
import javafx.scene.transform.Scale;
import javafx.scene.transform.Translate;
import javafx.stage.Screen;

import java.util.Optional;

import java.util.function.Consumer;

import src.model.*;
import src.model.board.*;
import src.view.scene.game.Game;
import src.view.scene.Menus;
import src.view.scene.ScenePlus;
import src.view.View;

public class Creator extends ScenePlus
{
	private static int screenWidth  = (int)Screen.getPrimary().getBounds().getWidth();
	private static int screenHeight = (int)Screen.getPrimary().getBounds().getHeight();

	private Circle startedDraw = null;

	private final Scale sc     = new Scale(100, 100);
	private final Translate tr = new Translate(10, 10);

	protected final ArrayList <Level> levels = new ArrayList <Level>(); //To store the levels
	protected int currentLevel = 0;

	private LeftPanel leftPanel;
	private final StackPane root = new StackPane();

	private final int rightWidth, rightHeight;

	public Creator(View v, int width, int height, int nbLevel, boolean flyMode)
	{
		this(v, width, height, nbLevel, flyMode, new Menus(v));
	}

	public Creator(View v, Game g)
	{
		this(v, g.getMaze(), g.getMaze().getContentMazeCurrentLevel().getMazeDimension().list_rectmaze.get(0), g);
	}

	private Creator(View v, MainMaze maze, MazeDimension.RectInMaze md, Scene old)
	{
		this(v, md.x2 - md.x1, md.y2 - md.y1, maze.getContentMaze().length, maze.getFlyMode(), old);
		for (int i = 0; i < levels.size(); i++)
		{
			for (LineWall l: maze.getContentMaze(i).getLineWalls())
			{
				levels.get(i).walls.getChildren().add(new LinePlus(l));
			}
			for (Case c:maze.getContentMaze(i).getSpecialCases())
			{
				levels.get(i).cases.add(new RectanglePlus(c));
			}
			levels.get(i).setWallTexture(maze.getContentMaze(i).getWallTexturePath());
			levels.get(i).setFloorTexture(maze.getContentMaze(i).getFloorTexturePath());
		}

		leftPanel.setCurrentWallTexture(maze.getContentMazeCurrentLevel().getWallTexturePath());
		leftPanel.setCurrentFloorTexture(maze.getContentMazeCurrentLevel().getFloorTexturePath());
		updateRightPanel();
	}

	private Creator(View v, int width, int height, int nbLevel, boolean flyMode, Scene old)
	{
		super(new HBox(), screenWidth, screenWidth, false, v);

		for (int i = 0; i < nbLevel; i++)
		{
			levels.add(new Level());
		}

		final double change = 5;

		this.rightWidth  = width;
		this.rightHeight = height;

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			switch (key.getCode())
			{
			case ESCAPE:
				Alert alert = new Alert(AlertType.CONFIRMATION, "Do you really want to quit the creator ?", ButtonType.YES, ButtonType.NO);
				Optional <ButtonType> result = alert.showAndWait();
				if (result.isPresent() && result.get() == ButtonType.YES)
				{
					v.changeScene(old);
				}
				break;

			case Z: tr.setY((isIn(tr.getY() + change, -screenHeight, 11)) ? tr.getY() + change : tr.getY()); break;

			case Q: tr.setX((isIn(tr.getX() + change, -screenWidth, 11)) ? tr.getX() + change : tr.getX()); break;

			case S: tr.setY((isIn(tr.getY() - change, -screenHeight, 11)) ? tr.getY() - change : tr.getY()); break;

			case D: tr.setX((isIn(tr.getX() - change, -screenWidth, 11)) ? tr.getX() - change : tr.getX()); break;

			case R: if (sc.getX() <= 150)
				{
					sc.setX(sc.getX() + change); sc.setY(sc.getY() + change);
				}
				break;

			case F: if (sc.getY() >= 50)
				{
					sc.setX(sc.getX() - change); sc.setY(sc.getY() - change);
				}
				break;
			}
		});

		setFill(Color.GRAY);

		root.setAlignment(Pos.TOP_LEFT);
		root.getTransforms().addAll(tr, sc);

		updateRightPanel();

		//Left Panel

		leftPanel = new LeftPanel(this, width, height, v, flyMode);
		ScrollPane leftPanelScr = new ScrollPane(leftPanel);
		leftPanelScr.setCenterShape(true);
		leftPanelScr.setMinSize(leftPanel.leftPaneGrSize + 10, 0);

		ScrollPane sp = new ScrollPane(root);
		sp.setPrefSize(screenWidth - leftPanel.leftPaneGrSize, screenHeight - 100);
		sp.setVbarPolicy(ScrollPane.ScrollBarPolicy.ALWAYS);
		sp.setHbarPolicy(ScrollPane.ScrollBarPolicy.ALWAYS);
		sp.setPadding(new Insets(10, 10, 10, 10));

		sp.setVmax(height);
		sp.setHmax(width);

		sp.vvalueProperty().addListener((ov, old_val, new_val)->{
			tr.setY(tr.getY() + sc.getY() * (old_val.doubleValue() - new_val.doubleValue()));
		});

		sp.hvalueProperty().addListener((ov, old_val, new_val)->{
			tr.setX(tr.getX() + sc.getX() * (old_val.doubleValue() - new_val.doubleValue()));
		});

		HBox pane = (HBox)getRoot();
		pane.setAlignment(Pos.CENTER_LEFT);
		pane.getChildren().addAll(leftPanelScr, sp);
	}

	protected void updateRightPanel(int newCurr)
	{
		currentLevel = newCurr;
		updateRightPanel();
	}

	private void updateRightPanel()
	{
		root.getChildren().clear();
		Pane dots = drawCircles(rightWidth, rightHeight);

		dots.setPickOnBounds(false);
		root.getChildren().addAll(drawRectangle(rightWidth, rightHeight), levels.get(currentLevel).walls, dots);
	}

	private Pane drawCircles(int width, int height)
	{
		final Pane   res      = new Pane();
		final double dotWidth = 0.1;

		// Draw circles
		for (int i = 0; i < width + 1; i++)
		{
			for (int j = 0; j < height + 1; j++)
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
							for (Node n: levels.get(currentLevel).walls.getChildren())
							{
								LinePlus li             = (LinePlus)n;
								ArrayList <LineWall> lw = LineWallUtils.exceptIfIntersectOrUnion(li.lw, newLineWall.lw);
								if (lw.size() == 0 || lw.size() == 1 || (lw.size() == 2 && !(lw.get(0) == li.lw && lw.get(1) == newLineWall.lw)))
								{
									levels.get(currentLevel).walls.getChildren().remove(li);
									for (LineWall l: lw)
									{
										levels.get(currentLevel).walls.getChildren().add(new LinePlus(l));
									}
									isGood = true;
									break;
								}
							}
							if (!isGood)// Les murs ne se superposaient pas
							{
								levels.get(currentLevel).walls.getChildren().add(newLineWall);
							}
						}
						startedDraw.setFill(Color.BLACK);
						startedDraw = null;
					}
				});
				res.getChildren().add(c);
			}
		}
		return (res);
	}

	private Pane drawRectangle(int width, int height)
	{
		final Pane res = new Pane();

		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				RectanglePlus rect = null;
				for (RectanglePlus n: levels.get(currentLevel).cases)           // If it is already a cases known
				{
					if (n.getX() == i && n.getY() == j)
					{
						rect = n;
					}
				}
				if (rect == null)
				{
					rect = new RectanglePlus(i, j, 1, 1);
				}
				final RectanglePlus rectemp = rect;
				rect.setOnMouseClicked((ev)->{ actionRect.accept(rectemp); });
				res.getChildren().add(rect);
			}
		}

		return (res);
	}

	private Consumer <RectanglePlus> actionRect = (rect)->{
		rect.changeCase();
		if (rect.getCase() == null)
		{
			levels.get(currentLevel).cases.remove(rect);
		}
		else
		{
			if (!levels.get(currentLevel).cases.contains(rect))
			{
				levels.get(currentLevel).cases.add(rect);
			}
		}
		leftPanel.updateLeftPane(rect);
	};

	private boolean isIn(double totest, double min, double max)
	{
		return (totest >= min && totest <= max);
	}
}
