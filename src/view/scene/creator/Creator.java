package src.view.scene.creator;

import java.util.ArrayList;

import javafx.collections.ObservableList;
import javafx.collections.transformation.FilteredList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.geometry.Point2D;
import javafx.geometry.Pos;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollBar;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.ScrollPane.ScrollBarPolicy;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.scene.effect.ColorAdjust;
import javafx.scene.Group;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.paint.ImagePattern;
import javafx.scene.Parent;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.Scene;
import javafx.scene.transform.Scale;
import javafx.scene.transform.Translate;
import javafx.stage.Screen;

import javafx.beans.value.ChangeListener;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Optional;

import src.model.*;
import src.model.board.*;
import src.model.gen.CreatorHelper;
import src.view.scene.game.CaseColor;
import src.view.scene.game.Game;
import src.view.scene.Menus;
import src.view.scene.ScenePlus;
import src.view.View;

public class Creator extends ScenePlus
{
	private static int screenWidth  = (int)Screen.getPrimary().getBounds().getWidth();
	private static int screenHeight = (int)Screen.getPrimary().getBounds().getHeight();

	private Circle startedDraw = null;

	private final int leftPaneGrSize = 180;

	private final Scale sc     = new Scale(100, 100);
	private final Translate tr = new Translate(10, 10); // Décalage par défaut du dessin

	protected final ArrayList <Stage> stages = new ArrayList <Stage>();
	protected int currentStage = 0;

	private final LeftPanel leftPanel;

	public Creator(View v, int width, int height, int nbStage, boolean flyMode)
	{
		super(new HBox(), screenWidth, screenWidth, false, v);

		for (int i = 0; i < nbStage; i++)
		{
			stages.add(new Stage());
		}

		final double change = 5;
		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			switch (key.getCode())
			{
			case ESCAPE:
				Alert alert = new Alert(AlertType.CONFIRMATION, "Do you really want to quit the creator ?", ButtonType.YES, ButtonType.NO);
				Optional <ButtonType> result = alert.showAndWait();
				if (result.isPresent() && result.get() == ButtonType.YES)
				{
					v.changeScene(new Menus(v));
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

		HBox pane = (HBox)getRoot();
		pane.setAlignment(Pos.CENTER_LEFT);
		StackPane root = new StackPane();

		root.setAlignment(Pos.TOP_LEFT);

		updateRightPanel(root);
		root.getTransforms().addAll(tr, sc);

		drawCircles(width, height);

		//Left Panel

		//For the choiceBox
		ChangeListener <Integer> choiceBoxListener = (ov, old_val, new_val)->{
			root.getChildren().removeAll(stages.get(currentStage).walls, stages.get(currentStage).dots, stages.get(currentStage).cases);
			currentStage = new_val;
			if (stages.get(currentStage).dots.getChildren().size() == 0)      // Init
			{
				drawCircles(width, height);
			}

			updateRightPanel(root);
		};

		leftPanel = new LeftPanel(leftPaneGrSize, this, choiceBoxListener, width, height, v, flyMode);

		ScrollPane sp = new ScrollPane(root);
		sp.setPrefSize(screenWidth - leftPaneGrSize, screenHeight - 100);
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

		pane.getChildren().addAll(leftPanel, sp);
	}

	public Creator(View v, Game g)
	{
		this(v, g.getMaze(), g.getMaze().getContentMazeCurrentLevel().getMazeDimension().list_rectmaze.get(0));
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{ if (key.getCode() == KeyCode.ESCAPE)
													   {
														   v.changeScene(g);
													   }
						});
	}

	private Creator(View v, MainMaze maze, MazeDimension.RectInMaze md)
	{
		this(v, md.x2 - md.x1, md.y2 - md.y1, maze.getContentMaze().length, maze.getFlyMode());
		for (int i = 0; i < stages.size(); i++)
		{
			for (LineWall l: maze.getContentMaze(i).getLineWalls())
			{
				stages.get(i).walls.getChildren().add(new LinePlus(l));
			}
			for (Case c:maze.getContentMaze(i).getSpecialCases())
			{
				final RectanglePlus rect = new RectanglePlus(c);
				rect.setOnMouseClicked((ev)->{
					rect.changeCase();
					leftPanel.updateLeftPane(rect);
				});
				stages.get(i).cases.getChildren().add(rect);
			}
			stages.get(i).setTexture(maze.getContentMaze(i).getTexturePath());
		}

		leftPanel.setCurrentTexture(maze.getContentMazeCurrentLevel().getTexturePath());
	}

	private void updateRightPanel(Pane root)
	{
		root.getChildren().addAll(stages.get(currentStage).cases, stages.get(currentStage).walls, stages.get(currentStage).dots);
	}

	private void drawCircles(int width, int height)
	{
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
							for (Node n: stages.get(currentStage).walls.getChildren())
							{
								LinePlus li             = (LinePlus)n;
								ArrayList <LineWall> lw = LineWallUtils.exceptIfIntersectOrUnion(li.lw, newLineWall.lw);
								if (lw.size() == 0 || lw.size() == 1 || (lw.size() == 2 && !(lw.get(0) == li.lw && lw.get(1) == newLineWall.lw)))
								{
									stages.get(currentStage).walls.getChildren().remove(li);
									for (LineWall l: lw)
									{
										stages.get(currentStage).walls.getChildren().add(new LinePlus(l));
									}
									isGood = true;
									break;
								}
							}
							if (!isGood)// Les murs ne se superposaient pas
							{
								stages.get(currentStage).walls.getChildren().add(newLineWall);
							}
						}
						startedDraw.setFill(Color.BLACK);
						startedDraw = null;
					}
				});
				if (!(j == height || i == width))// Si on n'est pas sur une ligne du "bord"
				{
					final RectanglePlus rect = new RectanglePlus(i, j, 1, 1);
					rect.setOnMouseClicked((ev)->{
						rect.changeCase();
						leftPanel.updateLeftPane(rect);
					});
					stages.get(currentStage).cases.getChildren().add(rect);
				}
				stages.get(currentStage).dots.getChildren().add(c);
			}
		}
	}

	private boolean isIn(double totest, double min, double max)
	{
		return (totest >= min && totest <= max);
	}
}
