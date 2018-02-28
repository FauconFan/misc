package src.view.scene;

import java.io.FileInputStream;
import javafx.application.Application;
import javafx.scene.AmbientLight;
import javafx.scene.Cursor;
import javafx.scene.Group;
import javafx.scene.image.Image;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;
import javafx.scene.paint.Material;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.Parent;
import javafx.scene.PerspectiveCamera;
import javafx.scene.PointLight;
import javafx.scene.shape.Box;
import javafx.scene.shape.Box;
import javafx.scene.shape.DrawMode;
import javafx.scene.Scene;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Scale;
import javafx.scene.transform.Translate;
import javafx.stage.Stage;

//Pour remettre le curseur au centre de l'ecran
import java.awt.AWTException;
import java.awt.Robot;
import javafx.stage.Screen;

import src.model.board.LineWall;
import src.model.ContentMaze;
import src.model.MainMaze;
import src.model.MazeDimension;
import src.model.Player;

import src.view.View;

public class Game extends ScenePlus
{
	private final Group root;
	private final MainMaze maze;

	//Dimensions de l'ecran
	private static int screenWidth  = (int)Screen.getPrimary().getBounds().getWidth();
	private static int screenHeight = (int)Screen.getPrimary().getBounds().getHeight();

	// Anciennes positions de la souris
	private double mousePosX = (double)(screenWidth / 2);
	private double mousePosY = (double)(screenHeight / 2);

	//Hauteur des murs
	private final int hauteur = 20;

	//Transforms pour la camera
	private final Translate tr = new Translate();
	private final Rotate rx    = new Rotate(0, Rotate.Y_AXIS);
	private final Rotate ry    = new Rotate(0, Rotate.X_AXIS);

	// Scale pour les murs
	private final Scale sc = new Scale(30, 1, 30);

	// Constantes de déplacements
	private final float change = 0.1f;
	private final float goUp   = 1f;
	private final int rot      = 5; // En degré


	public Game(View v, MainMaze m)
	{
		super(new Group(), screenWidth, screenHeight, true, v);
		root = (Group)this.getRoot();
		maze = m;

		setFill(Color.GREY);
		setCursor(Cursor.NONE);

		// Ajoute le sol
		root.getChildren().add(makeFloors());

		/* Le plafond est juste un sol décalé vers le haut
		 * final Group roof = makeFloors();
		 * roof.setTranslateY(-1 * hauteur);
		 * root.getChildren().add(roof);*/

		//Ajoute les murs
		root.getChildren().add(makeWalls());

		//Creation de la camera
		final Group             cameraGroup = new Group();
		final PerspectiveCamera camera      = new PerspectiveCamera(true);
		cameraGroup.getChildren().add(camera);
		camera.setNearClip(0.1);
		camera.setFarClip(1000.0);

		// On met les tranforms sur la camera
		cameraGroup.getTransforms().addAll(tr, rx, ry);

		//Source de lumiere sur le joueur
		Group      light         = new Group();
		PointLight lightOnPlayer = new PointLight();
		lightOnPlayer.setColor(Color.WHITE);
		light.getChildren().add(lightOnPlayer);
		cameraGroup.getChildren().add(light);

		root.getChildren().add(cameraGroup);

		// Met le joueur sur la startCase
		updatePlayer();

		// Défini la camera pour la scène
		setCamera(camera);

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			switch (key.getCode())
			{
			case Q: setTr(-90, change); break;

			case D: setTr(90, change); break;

			case Z: setTr(0, change); break;

			case S: setTr(180, change); break;

			// Le déplacement vertical ne demande pour l'instant aucun calcul particulier
			case F: maze.movePlayer(0, 0, goUp);  break;

			case R: maze.movePlayer(0, 0, -1 * goUp); break;

			case LEFT: maze.getPlayer().addHorizontalAngle(-1 * rot); break;

			case RIGHT: maze.getPlayer().addHorizontalAngle(1 * rot); break;

			case UP: maze.getPlayer().addVerticalAngle(1 * rot); break;

			case DOWN: maze.getPlayer().addVerticalAngle(-1 * rot); break;

			case ESCAPE: v.changeScene(new Pause(v, this)); break;

			case T: centerMouse(); break;
			}

			updatePlayer();
		});

		//Mouse controller

		setOnMouseMoved((mm)->{
			final double rotateConst = 0.01;
			double newX = mm.getSceneX();
			double newY = mm.getSceneY();
			double dX   = newX - mousePosX;
			double dY   = newY - mousePosY;
			if (dX != 0 && dY != 0)
			{
				centerMouse();
			}
			maze.getPlayer().addHorizontalAngle((float)(-1 * dX * rotateConst));
			maze.getPlayer().addVerticalAngle((float)(dY * rotateConst));

			//mousePosX = mm.getSceneX();
			//mousePosY = mm.getSceneY();

			updatePlayer();
		});
	}

	//Place le curseur au centre de l'ecran
	private void centerMouse()
	{
		//mousePosX = (double)(screenWidth / 2);
		//mousePosY = (double)(screenHeight / 2);
		try{
			Robot robo = new Robot();
			robo.mouseMove(screenWidth / 2, screenHeight / 2);
		}catch (AWTException e) {
			e.printStackTrace();
		}
	}

	// Teste si le curseur est au centre de l'ecran
	private boolean isInCenter()
	{
		if (mousePosX == screenWidth / 2 && mousePosY == screenHeight / 2)
		{
			return (true);
		}
		return (false);
	}

	/**
	 * Set the translate
	 * @param diff la différence à ajouter à l'angle
	 * @param change Le déplacement
	 */
	private void setTr(int diff, float change)
	{
		final double r1 = Math.toRadians(rx.getAngle() + diff);

		maze.movePlayer((float)(Math.sin(r1) * change), (float)(Math.cos(r1) * change), 0);
	}

	/**
	 * Update the camera position according to the player
	 */
	private void updatePlayer()
	{
		final Player p = maze.getPlayer();

		tr.setZ(p.getPosY() * sc.getZ());
		tr.setX(p.getPosX() * sc.getX());
		tr.setY(p.getPosZ() * sc.getY());
		rx.setAngle(p.getHorizontalAngle());
		ry.setAngle(p.getVerticalAngle());

		checkWin();
	}

	/**
	 *  Teste si on a gagné et agit en conséquence
	 */
	private void checkWin()
	{
		if (maze.getPlayer().hasWin(maze.getContentMaze().getSpecialCases()))
		{
			v.changeScene(new Winner(v));
		}
	}

	/**
	 * Dessine le Maze
	 * @return Le groupe contenant les murs
	 */
	private Group makeWalls()
	{
		Image    img;
		Material mat;

		try{
			img = new Image(new FileInputStream("assets/bricks2.jpg"));
			mat = new PhongMaterial(Color.WHITE, img, null, null, null);
		}
		catch (Exception e) {
			mat = new PhongMaterial(Color.GREEN);
		}
		Group walls = new Group();

		// On scale les murs
		walls.getTransforms().add(sc);
		final LineWall[] lineWalls = maze.getContentMaze().getLineWalls();
		for (LineWall l: lineWalls)
		{
			Box w = new Box();
			w.setHeight(hauteur);
			if (!l.isHorizontal())                                            // Mur "vertical" dans le plan
			{
				final float depth = l.getY2() - l.getY1() + l.getEpaisseur();
				w.setDepth(depth);
				w.setWidth(l.getEpaisseur());
				w.setTranslateX(l.getX1() + l.getEpaisseur() / 2.0);
				w.setTranslateZ(l.getY1() + depth / 2.0);
			}
			else // Mur horizontal
			{
				final float width = l.getX2() - l.getX1() + l.getEpaisseur();
				w.setWidth(width);
				w.setDepth(l.getEpaisseur());
				w.setTranslateX(l.getX1() + width / 2.0);
				w.setTranslateZ(l.getY1() + l.getEpaisseur() / 2.0);
			}
			w.setMaterial(mat);
			walls.getChildren().add(w);
		}
		return (walls);
	}

	/**
	 * Dessine le sol
	 * @return Un groupe contenant le sol
	 */
	public Group makeFloors()
	{
		final Group floors = new Group();

		floors.getTransforms().add(sc);

		for (MazeDimension.RectInMaze md: maze.getMazeDimension().list_rectmaze)
		{
			final int w = md.x2 - md.x1;
			final int h = md.y2 - md.y1;
			Box       f = new Box(w, 0.5, h);
			f.setTranslateX(md.x1 + w / 2.0);
			f.setTranslateZ(md.y1 + h / 2.0);
			f.setMaterial(new PhongMaterial(Color.RED));
			f.setTranslateY(hauteur / 2.0);
			floors.getChildren().add(f);
		}
		return (floors);
	}

	public MainMaze getMaze()
	{
		return (this.maze);
	}
}
