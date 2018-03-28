package src.view.scene.game;

import java.io.FileInputStream;
import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.AmbientLight;
import javafx.scene.Camera;
import javafx.scene.Cursor;
import javafx.scene.Group;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.Node;
import javafx.scene.paint.Color;
import javafx.scene.paint.Material;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.Parent;
import javafx.scene.PerspectiveCamera;
import javafx.scene.PointLight;
import javafx.scene.shape.Box;
import javafx.scene.shape.DrawMode;
import javafx.scene.shape.Line;
import javafx.scene.Scene;
import javafx.scene.SubScene;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Scale;
import javafx.scene.transform.Translate;
import javafx.stage.Stage;

//Pour remettre le curseur au centre de l'ecran
import java.awt.AWTException;
import java.awt.Robot;
import javafx.stage.Screen;

import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.shape.Rectangle;

import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;

import java.util.function.BiConsumer;
import java.util.function.Consumer;

import src.model.board.Case;
import src.model.ContentMaze;
import src.model.Directions;
import src.model.MainMaze;
import src.model.MazeDimension;
import src.model.Player;
import src.view.scene.Menus;
import src.view.scene.Pause;
import src.view.scene.ScenePlus;
import src.view.scene.Winner;
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

	//Hauteur des murs
	private final int hauteur = 20;

	// Scale pour les murs
	private final Scale sc = new Scale(30, 1, 30);

	private final StackPane layout;
	private final GroupCameraPlus groupCameraPlus3D;
	private final MiniMap sceneMiniMap;

	public final Timer timer;

	public Game(View v, MainMaze m)
	{
		super(new StackPane(), screenWidth, screenHeight, true, v);
		Group root3D = new Group();
		Group root2D = new Group();
		layout = (StackPane)this.getRoot();
		maze   = m;

		setFill(Color.GREY);
		setCursor(Cursor.NONE);

		// AmbientLight
		AmbientLight al = new AmbientLight(Color.WHITE);
		root3D.getChildren().add(al);

		SubScene scene3D = new SubScene(root3D, screenWidth, screenHeight, true, null);
		SubScene scene2D = new SubScene(root2D, screenWidth, screenHeight, true, null);
		sceneMiniMap = new MiniMap(400, 400, new Scale(sc.getX(), sc.getZ()), m.getContentMaze().getLineWalls());
		sceneMiniMap.setVisible(false); // On cache la minimap
		SubScene cross = sceneMiniMap.new Cross();
		cross.setVisible(false);
		groupCameraPlus3D = new GroupCameraPlus(new PerspectiveCamera(true));

		// Ajoute le sol
		root3D.getChildren().add(Init.makeSpecialCases(hauteur, sc, this.maze));
		root3D.getChildren().add(Init.makeFloors(hauteur, sc, this.maze));

		// Ajoute les murs
		Group walls = Init.makeWalls(hauteur, sc, this.maze);
		root3D.getChildren().add(walls);
		// Ajoute la caméra
		root3D.getChildren().add(groupCameraPlus3D);

		// Défini la camera pour la scène
		scene3D.setCamera(groupCameraPlus3D.camera);

		// Met le joueur sur la startCase
		updatePlayer();

		//Greetings label
		Label msg = new Label("Welcome to the maze\n Press ENTER to close the message\nor H to see HELP");
		msg.setFont(Font.font("Verdana", 30));
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

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			switch (key.getCode())
			{
			case ESCAPE: v.changeScene(new Pause(v, this)); timer.stop(); break;

			case ENTER: msg.setText(""); break;

			case G: this.maze.getPlayer().setGhostMode(!this.maze.getPlayer().getGhostMode()); break;

			case T: walls.setVisible(!walls.isVisible()); break;

			case H: msg.setText("Here is a HELP page. You have to find green cell to escape the maze.\nSpecial cells :\n" + CaseColor.prettify() + "Press ENTER to close"); break;

			case M: sceneMiniMap.setVisible(!sceneMiniMap.isVisible()); cross.setVisible(!cross.isVisible()); break;

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

			case F: cons.accept(Directions.goDown); break;

			case R: cons.accept(Directions.goUp); break;

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
	}

	/**
	 *  Teste si on a gagné et agit en conséquence
	 */
	private void checkWin()
	{
		if (maze.getPlayer().getHasWin())
		{
			timer.stop();
			v.changeScene(new Winner(v));
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
		public void handle(long l)
		{
			maze.updatePlayer();
			updatePlayer();
		}
	}
}
