package src.view.scene.game;

import javafx.animation.AnimationTimer;
import javafx.geometry.Pos;
import javafx.scene.AmbientLight;
import javafx.scene.Cursor;
import javafx.scene.Group;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;
import javafx.scene.PerspectiveCamera;
import javafx.scene.SubScene;
import javafx.scene.transform.Scale;

//Pour remettre le curseur au centre de l'ecran
import java.awt.AWTException;
import java.awt.Robot;
import javafx.stage.Screen;

import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;

import javafx.scene.text.Font;
import javafx.scene.text.TextAlignment;

import java.util.function.BiConsumer;
import java.util.function.Consumer;

import src.model.Directions;
import src.model.MainMaze;
import src.model.Player;
import src.view.scene.EndMenu;
import src.view.scene.Pause;
import src.view.scene.ScenePlus;
import src.view.View;

public class Game extends ScenePlus
{
	private final MainMaze maze;

	//Dimensions de l'ecran
	private static int screenWidth  = (int)Screen.getPrimary().getBounds().getWidth();
	private static int screenHeight = (int)Screen.getPrimary().getBounds().getHeight();
	private static int screenOffset = 0;

	// Anciennes positions de la souris
	private double mousePosX = (double)(screenWidth / 2);
	private double mousePosY = (double)(screenHeight / 2);

	// Scale pour les murs
	private final Scale sc = new Scale(30, 25, 30);

	private final StackPane layout;
	private final GroupCameraPlus groupCameraPlus3D;
	private final MiniMap sceneMiniMap;

	public final Timer timer;

	private final Label clock = new Label("");
	private final Label level = new Label("");

	private final Font defaultFont = Font.font("Verdana", 30);

	private int currentLevel;

	public Game(View v, MainMaze m)
	{
		super(new StackPane(), screenWidth, screenHeight, true, v);
		Group root3D = new Group();
		Group root2D = new Group();
		layout       = (StackPane)this.getRoot();
		maze         = m;
		currentLevel = m.getCurrentLevel();

		setFill(Color.GREY);
		setCursor(Cursor.NONE);

		// AmbientLight
		AmbientLight al = new AmbientLight(Color.WHITE);
		root3D.getChildren().add(al);

		level.setText("Current level : " + currentLevel);


		SubScene scene3D = new SubScene(root3D, screenWidth, screenHeight, true, null);
		SubScene scene2D = new SubScene(root2D, screenWidth, screenHeight, true, null);
		sceneMiniMap = new MiniMap(400, 400, new Scale(sc.getX(), sc.getZ()), m.getContentMazeCurrentLevel().getLineWalls());
		sceneMiniMap.setVisible(false); // On cache la minimap
		SubScene cross = sceneMiniMap.new Cross();
		cross.setVisible(false);
		groupCameraPlus3D = new GroupCameraPlus(new PerspectiveCamera(true));

		// Ajoute le sol
		root3D.getChildren().add(Init.makeSpecialCases(sc, this.maze, m.getFlyMode()));
		root3D.getChildren().add(Init.makeFloors(sc, this.maze, m.getFlyMode()));

		// Ajoute les murs
		Group walls = Init.makeWalls(sc, this.maze);
		root3D.getChildren().add(walls);
		// Ajoute la caméra
		root3D.getChildren().add(groupCameraPlus3D);

		// Défini la camera pour la scène
		scene3D.setCamera(groupCameraPlus3D.camera);

		// Met le joueur sur la startCase
		updatePlayer();

		//Greetings label
		Label msg = new Label("Welcome to the maze\n Press ENTER to close the message\nor H to see HELP");
		msg.setFont(defaultFont);
		msg.setTextFill(Color.WHITE);
		msg.setTextAlignment(TextAlignment.CENTER);
		msg.setLayoutY(screenOffset);
		root2D.getChildren().add(msg);

		StackPane.setAlignment(msg, Pos.BOTTOM_CENTER);

		// Minimap en haut à doite
		StackPane.setAlignment(sceneMiniMap, Pos.TOP_RIGHT);
		StackPane.setAlignment(cross, Pos.TOP_RIGHT);

		//Ajout des subscenes
		layout.getChildren().addAll(scene3D, scene2D, sceneMiniMap, cross);

		// Initialise le timer
		timer = new Timer();
		timer.start();

		// Add the Clock
		StackPane.setAlignment(clock, Pos.BOTTOM_LEFT);
		clock.setFont(defaultFont);
		clock.setTextFill(Color.WHITE);
		layout.getChildren().add(clock);

		//Add the CurrentLevel
		StackPane.setAlignment(level, Pos.BOTTOM_CENTER);
		level.setFont(defaultFont);
		level.setTextFill(Color.WHITE);
		layout.getChildren().add(level);

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			switch (key.getCode())
			{
			case ESCAPE: v.changeScene(new Pause(v, this)); timer.stop(); break;

			case ENTER: msg.setText(""); break;

			case G:
				this.maze.getPlayer().setGhostMode(!this.maze.getPlayer().getGhostMode());
				sceneMiniMap.setVisible(!sceneMiniMap.isVisible()); cross.setVisible(!cross.isVisible()); break;

			case T: walls.setVisible(!walls.isVisible()); break;

			case H: msg.setText("Here is a HELP page. You have to find green cell to escape the maze.\nSpecial cells :\n" + CaseColor.prettify() + "Press ENTER to close"); break;

			case SHIFT: maze.getPlayer().invertRun();
			}

			updatePlayer();
		});

		//Mouse controller
		//screenOffset : decalage en Y par rapport au centre de l'ecran

		setOnMouseMoved((mm)->{
			final double rotateConst = 0.1;
			int screenOffset         = (int)Screen.getPrimary().getVisualBounds().getMaxY() - (int)getHeight();
			double newX = mm.getSceneX();
			double newY = mm.getSceneY();
			double dX   = newX - mousePosX;
			double dY   = newY - mousePosY + screenOffset;
			if (dX != 0 || dY != 0)
			{
				centerMouse();
			}
			maze.getPlayer().addHorizontalAngle((float)(dX * rotateConst));
			maze.getPlayer().addVerticalAngle((float)(-1 * dY * rotateConst));
			updatePlayer();
		});

		BiConsumer <? super KeyEvent, Boolean> onkey = (key, bool)->{
			final Player p = maze.getPlayer();
			final Consumer <Directions> cons = (bool) ? (p.dirs::add) : (p.dirs::remove);
			switch (key.getCode())
			{
			case Q: if (bool && p.dirs.contains(Directions.east))
				{
					p.dirs.remove(Directions.east);
				}
				else
				{
					cons.accept(Directions.west);
				}
				break;

			case D: if (bool && p.dirs.contains(Directions.west))
				{
					p.dirs.remove(Directions.west);
				}

				else
				{
					cons.accept(Directions.east);
				}
				break;

			case Z: if (bool && p.dirs.contains(Directions.south))
				{
					p.dirs.remove(Directions.south);
				}
				else
				{
					cons.accept(Directions.north);
				}
				break;

			case S: if (bool && p.dirs.contains(Directions.north))
				{
					p.dirs.remove(Directions.north);
				}

				else
				{
					cons.accept(Directions.south);
				}
				break;

			case F: if (bool && p.dirs.contains(Directions.goUp))
				{
					p.dirs.remove(Directions.goUp);
				}

				else
				{
					cons.accept(Directions.goDown);
				}
				break;

			case R: if (bool && p.dirs.contains(Directions.goDown))
				{
					p.dirs.remove(Directions.goDown);
				}

				else
				{
					cons.accept(Directions.goUp);
				}
				break;

			case LEFT: cons.accept(Directions.left); break;

			case RIGHT: cons.accept(Directions.right); break;

			case UP: cons.accept(Directions.up); break;

			case DOWN: cons.accept(Directions.down); break;

			case SPACE: cons.accept(Directions.jump); break;
			}
		};

		setOnKeyPressed((key)->{
			onkey.accept(key, true);
		});

		setOnKeyReleased((key)->{
			onkey.accept(key, false);
		});
	}

	//Place le curseur au centre de l'ecran
	private void centerMouse()
	{
		try{
			Robot robo = new Robot();
			robo.mouseMove(screenWidth / 2, screenHeight / 2);
		}catch (AWTException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Update the camera position according to the player
	 */
	private void updatePlayer()
	{
		final Player p = maze.getPlayer();

		groupCameraPlus3D.tr.setZ(p.getPosY() * sc.getZ());
		groupCameraPlus3D.tr.setX(p.getPosX() * sc.getX());
		groupCameraPlus3D.tr.setY(-p.getPosZ() * sc.getY());
		groupCameraPlus3D.rx.setAngle(p.getHorizontalAngle());
		groupCameraPlus3D.ry.setAngle(p.getVerticalAngle());

		sceneMiniMap.updateCamera(p);
		maze.actionCase();
		checkWin();
		checkLoss();
	}

	/**
	 * Do the player won the game ?
	 */
	private void checkWin()
	{
		if (maze.getPlayer().getHasWin())
		{
			timer.stop();
			v.changeScene(new EndMenu(v, maze.getPlayer().getTime() / 1000000000));
		}
	}

	/**
	 * Is he dead ?
	 */
	public void checkLoss()
	{
		if (maze.getPlayer().getIsDead())
		{
			timer.stop();
			v.changeScene(new EndMenu(v));
		}
	}

	public MainMaze getMaze()
	{
		return (this.maze);
	}

	public void startTimer()
	{
		timer.start();
	}

	private class Timer extends AnimationTimer
	{
		private long oldTime = 0;

		public void handle(long l)
		{
			maze.updatePlayer(l - oldTime);
			updatePlayer();
			clock.setText(Long.toString(maze.getPlayer().getTime() / 1000000000) + " s.");
			if (currentLevel != maze.getCurrentLevel())
			{
				currentLevel = maze.getCurrentLevel();
				level.setText("Current level : " + currentLevel);
				sceneMiniMap.makeLineWalls(maze.getContentMazeCurrentLevel().getLineWalls());
			}
			oldTime = l;
		}
	}
}
