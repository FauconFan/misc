package src.view.scene.creator;

import java.util.ArrayList;

import javafx.collections.ObservableList;
import javafx.collections.transformation.FilteredList;
import javafx.event.EventHandler;
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
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.Scene;
import javafx.scene.transform.Scale;
import javafx.scene.transform.Translate;
import javafx.stage.Screen;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import src.model.*;
import src.model.board.*;
import src.model.gen.CreatorHelper;
import src.view.scene.game.CaseColor;
import src.view.scene.game.Game;
import src.view.scene.Menus;
import src.view.scene.ScenePlus;
import src.view.View;

//TODO STAGIFICATION
public class Creator extends ScenePlus
{
	private static int screenWidth  = (int)Screen.getPrimary().getBounds().getWidth();
	private static int screenHeight = (int)Screen.getPrimary().getBounds().getHeight();

	private Circle startedDraw = null;
	private Tile currentTile   = null;
	private final VBox leftPaneGr;

	private final int leftPaneGrSize = 180;

	private final Scale sc     = new Scale(100, 100);
	private final Translate tr = new Translate(10, 10); // Décalage par défaut du dessin

	private final Pane walls = new Pane();              //MUST contain LinePlus
	private final Pane cases = new Pane();              //MUST contain RectanglePlus
	private final Pane dots  = new Pane();

	private final GridPane gridPane = new GridPane();     // MUST contain Tile


	public Creator(View v, int width, int height, int nbStage)
	{
		super(new HBox(), screenWidth, screenWidth, false, v);

		final double change = 5;
		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			switch (key.getCode())
			{
			case ESCAPE: v.changeScene(new Menus(v)); break;

			case Z: tr.setY((isIn(tr.getY() + change, -screenHeight, 11)) ? tr.getY() + change : tr.getY()); break;

			case Q: tr.setX((isIn(tr.getX() + change, -screenWidth, 11)) ? tr.getX() + change : tr.getX()); break;

			case S: tr.setY((isIn(tr.getY() - change, -screenHeight, 11)) ? tr.getY() - change : tr.getY()); break;

			case D: tr.setX((isIn(tr.getX() - change, -screenWidth, 11)) ? tr.getX() - change : tr.getX()); break;

			case R: sc.setX(sc.getX() + change); sc.setY(sc.getY() + change); break;

			case F: sc.setX(sc.getX() - change); sc.setY(sc.getY() - change); break;
			}
		});

		setFill(Color.GRAY);

		HBox pane = (HBox)getRoot();
		pane.setAlignment(Pos.CENTER_LEFT);
		StackPane root = new StackPane();

		root.setAlignment(Pos.TOP_LEFT);

		final double dotWidth = 0.1;

		dots.setPickOnBounds(false);
		walls.setPickOnBounds(false);

		root.getChildren().addAll(cases, walls, dots);
		root.getTransforms().addAll(tr, sc);

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
				if (!(j == height || i == width))// Si on n'est pas sur une ligne du "bord"
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

		//Left Panel
		VBox panel = new VBox();
		panel.setMinSize(leftPaneGrSize, 0);
		panel.setAlignment(Pos.TOP_CENTER);
		panel.setPadding(new Insets(20, 0, 20, 0));

		//Textures
		gridPane.setAlignment(Pos.TOP_CENTER);
		gridPane.setPadding(new Insets(20, 0, 20, 0));
		final int gap = 5;
		final int numOfTilesPerLine = 2;
		final int tileLength        = leftPaneGrSize / numOfTilesPerLine - gap * numOfTilesPerLine;
		gridPane.setVgap(gap);
		gridPane.setHgap(gap);
		File[] textures = getTextures();
		for (int i = 0; i < textures.length; i++)
		{
			try{
				Tile tile = new Tile(textures[i], tileLength);
				((ColorAdjust)tile.getEffect()).setBrightness(-0.6);
				GridPane.setConstraints(tile, i % numOfTilesPerLine, i / numOfTilesPerLine);
				gridPane.getChildren().add(tile);
				tile.setOnMouseClicked((ev)->{ setCurrentTile(tile); });
			}
			catch (Exception e) {}
		}
		if (textures.length != 0)
		{
			currentTile = (Tile)gridPane.getChildren().get(0);
			((ColorAdjust)currentTile.getEffect()).setBrightness(0);
		}

		//Placeholder for case
		leftPaneGr = new VBox();
		leftPaneGr.setAlignment(Pos.TOP_CENTER);
		leftPaneGr.setPadding(new Insets(20, 0, 20, 0));

		//Finish
		Button button = new Button("Finish");
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

			CreatorHelper ch = new CreatorHelper(1);
			ch.append(0, 0, width, 0, height, lineWalls.toArray(new LineWall[0]), specialCases.toArray(new Case[0]));
			try{
				v.con.setMaze(ch.buildMainMaze("", currentTile.filename));
				v.showGame();
			}
			catch (Exception e) {
				System.out.println(e);
			}
		});

		panel.getChildren().addAll(button, gridPane, leftPaneGr);

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

		pane.getChildren().addAll(panel, sp);
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
		this(v, md.x2 - md.x1, md.y2 - md.y1, maze.getContentMaze().length);
		for (LineWall l: maze.getContentMazeCurrentLevel().getLineWalls())
		{
			walls.getChildren().add(new LinePlus(l));
		}
		for (Case c:maze.getContentMazeCurrentLevel().getSpecialCases())
		{
			final RectanglePlus rect = new RectanglePlus(c);
			rect.setOnMouseClicked((ev)->{
				rect.changeCase();
				updateLeftPane(rect);
			});
			cases.getChildren().add(rect);
		}
		for (Node n: gridPane.getChildren())
		{
			Tile t = (Tile)n;
			if (t.filename.equals(maze.getContentMazeCurrentLevel().getTexturePath()))
			{
				setCurrentTile(t);
			}
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
				HBox      hx = new HBox(new Label("x: "));
				HBox      hy = new HBox(new Label("y: "));
				TextField tx = new TextField(Integer.toString(((TeleportCase)c).getXDest()));
				tx.setPrefColumnCount(4);
				tx.textProperty().addListener((ov, o, n)->{ ((TeleportCase)c).setXDest(Integer.parseInt(n)); });            //TODO Faire attention...
				TextField ty = new TextField(Integer.toString(((TeleportCase)c).getYDest()));
				ty.setPrefColumnCount(4);
				ty.textProperty().addListener((ov, o, n)->{ ((TeleportCase)c).setYDest(Integer.parseInt(n)); });
				hx.getChildren().add(ty);
				hy.getChildren().add(tx);
				leftPaneGr.getChildren().addAll(hx, hy);
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

	private boolean isIn(double totest, double min, double max)
	{
		return (totest >= min && totest <= max);
	}

	private File[] getTextures()
	{
		File assets = new File("assets");

		return (assets.listFiles((file, name)->{
			int i = name.lastIndexOf('.');
			if (i > 0)
			{
				return name.substring(i + 1).equals("jpg");
			}
			return false;
		}));
	}

	//For textures
	private class Tile extends Rectangle
	{
		private final String filename;
		public Tile(File texture, int tileLength) throws FileNotFoundException
		{
			super(tileLength, tileLength);
			filename = texture.getPath();
			setEffect(new ColorAdjust());
			setFill(new ImagePattern(new Image(new FileInputStream(texture), tileLength, tileLength, true, false)));
		}
	}

	private void setCurrentTile(Tile tile)
	{
		if (currentTile != null)
		{
			((ColorAdjust)currentTile.getEffect()).setBrightness(-0.6);
		}
		currentTile = tile;
		((ColorAdjust)currentTile.getEffect()).setBrightness(0);
	}

	//For stage

	private static class Stage
	{
		public final Pane walls, cases, dots;

		public Stage(Pane w, Pane c, Pane d)
		{
			walls = w;
			cases = c;
			dots  = d;
		}

		public Stage()
		{
			this(new Pane(), new Pane(), new Pane());
		}
	}
}
