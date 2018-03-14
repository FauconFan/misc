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
import javafx.scene.ParallelCamera;
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

import java.util.function.Consumer;

import src.model.board.Case;
import src.model.board.LineWall;
import src.model.ContentMaze;
import src.model.MainMaze;
import src.model.MazeDimension;
import src.model.Player;
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

	// Constantes de déplacements
	private final float change = 0.1f;
	private final float goUp   = 1f;
	private final int rot      = 5; // En degré

	private final Group walls;

	private final StackPane layout;
	private final GroupCameraPlus groupCameraPlus3D;
	private final MiniMap sceneMiniMap;

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
		SubScene cross = sceneMiniMap.new Cross();

		groupCameraPlus3D = new GroupCameraPlus(new PerspectiveCamera(true));

		// Ajoute le sol
		root3D.getChildren().add(Init.makeSpecialCases(hauteur, this.maze));
		root3D.getChildren().add(Init.makeFloors(hauteur, sc, this.maze));

		/* Le plafond est juste un sol décalé vers le haut
		 * final Group roof = makeFloors();
		 * roof.setTranslateY(-1 * hauteur);
		 * root.getChildren().add(roof);*/

		// Ajoute les murs
		walls = Init.makeWalls(hauteur, sc, this.maze);
		root3D.getChildren().add(walls);
		// Ajoute la caméra
		root3D.getChildren().add(groupCameraPlus3D);

		// Défini la camera pour la scène
		scene3D.setCamera(groupCameraPlus3D.camera);

		// Met le joueur sur la startCase
		updatePlayer(false);


		//Greetings label
		System.out.println(screenOffset);
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

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			boolean reallyMove = false;
			switch (key.getCode())
			{
			case Q: setTr(-90, change * this.maze.getPlayer().getSpeed()); reallyMove = true; break;

			case D: setTr(90, change * this.maze.getPlayer().getSpeed()); reallyMove = true; break;

			case Z: setTr(0, change * this.maze.getPlayer().getSpeed()); reallyMove = true; break;

			case S: setTr(180, change * this.maze.getPlayer().getSpeed()); reallyMove = true; break;

			// Le déplacement vertical ne demande pour l'instant aucun calcul particulié
			case F: maze.movePlayer(0, 0, goUp);  break;

			case R: maze.movePlayer(0, 0, -1 * goUp); break;

			case LEFT: maze.getPlayer().addHorizontalAngle(-1 * rot); break;

			case RIGHT: maze.getPlayer().addHorizontalAngle(1 * rot); break;

			case UP: maze.getPlayer().addVerticalAngle(1 * rot); break;

			case DOWN: maze.getPlayer().addVerticalAngle(-1 * rot); break;

			case ESCAPE: v.changeScene(new Pause(v, this)); break;

			case ENTER: msg.setText(""); break;

			case G: this.maze.getPlayer().setGhostMode(!this.maze.getPlayer().getGhostMode()); break;

			case T: makeTransparentWallsOrNot(); break;

			case H: msg.setText("Here is a HELP page. You have to find green cell to escape the maze.\nSpecial cells :\nBlue - teleportates you in a random position.\nPress ENTER to close"); break;
			}

			updatePlayer(reallyMove);
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
			updatePlayer(false);
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
	 * Set the translate
	 * @param diff la différence à ajouter à l'angle
	 * @param change Le déplacement
	 */
	private void setTr(int diff, float change)
	{
		final double r1 = Math.toRadians(groupCameraPlus3D.rx.getAngle() + diff);

		maze.movePlayer((float)(Math.sin(r1) * change), (float)(Math.cos(r1) * change), 0);
	}

	/**
	 * Update the camera position according to the player
	 * @param b Si le joueur a vraiment bougé
	 */
	private void updatePlayer(boolean b)
	{
		final Player p = maze.getPlayer();

		groupCameraPlus3D.tr.setZ(p.getPosY() * sc.getZ());
		groupCameraPlus3D.tr.setX(p.getPosX() * sc.getX());
		groupCameraPlus3D.tr.setY(p.getPosZ() * sc.getY());
		groupCameraPlus3D.rx.setAngle(p.getHorizontalAngle());
		groupCameraPlus3D.ry.setAngle(p.getVerticalAngle());

		sceneMiniMap.updateCamera(p);
		if (b)
		{
			maze.actionCase();
			checkWin();
		}
	}

	/**
	 *  Teste si on a gagné et agit en conséquence
	 */
	private void checkWin()
	{
		if (maze.getPlayer().getHasWin())
		{
			v.changeScene(new Winner(v));
		}
	}

	public MainMaze getMaze()
	{
		return (this.maze);
	}

	private void makeTransparentWallsOrNot()
	{
		for (Node n : walls.getChildren())
		{
			PhongMaterial ph = (PhongMaterial)((Box)n).getMaterial();
			if (ph.getDiffuseColor() == Color.WHITE)
			{
				ph.setDiffuseColor(new Color(1, 1, 1, 0.25));
			}
			else
			{
				ph.setDiffuseColor(Color.WHITE);
			}
			((Box)n).setMaterial(ph);
		}
	}

	private class Timer extends AnimationTimer
	{
		public void handle(long l)
		{
		}
	}
}
