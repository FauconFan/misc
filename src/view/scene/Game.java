package src.view.scene;

import java.io.FileInputStream;
import javafx.application.Application;
import javafx.scene.AmbientLight;
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

	//Translate
	private final Translate tr;
	private final Rotate rx, ry;

	// Scale
	private final Scale sc = new Scale(30, 1, 30);

	public Game(View v, MainMaze m)
	{
		super(new Group(), screenWidth, screenHeight, true, v);
		root = (Group)this.getRoot();
		maze = m;

		setFill(Color.GREY);

		// Ajoute le sol
		root.getChildren().add(makeFloors());

		// Le plafond est juste un sol décalé vers le haut
		final Group roof = makeFloors();
		roof.setTranslateY(-1 * hauteur);
		//root.getChildren().add(roof);

		//Creation de la camera
		final Group             cameraGroup = new Group();
		final PerspectiveCamera camera      = new PerspectiveCamera(true);
		cameraGroup.getChildren().add(camera);
		camera.setNearClip(0.1);
		camera.setFarClip(1000.0);

		//Translate
		tr = new Translate();
		cameraGroup.getTransforms().add(tr);

		// Rotate
		rx = new Rotate();
		rx.setAxis(Rotate.Y_AXIS);

		ry = new Rotate();
		ry.setAxis(Rotate.X_AXIS);
		cameraGroup.getTransforms().addAll(rx, ry);

		//Source de lumiere sur le joueur

		Group      light         = new Group();
		PointLight lightOnPlayer = new PointLight();
		lightOnPlayer.setColor(Color.WHITE);
		light.getChildren().add(lightOnPlayer);
		cameraGroup.getChildren().add(light);

		root.getChildren().add(cameraGroup);

		updatePlayer();

		// Défini la camera pour la scène
		setCamera(camera);

		// constantes de déplacements
		final float change = 0.1f;
		final float goUp   = 1f;
		final int   rot    = 5; // En degré

		renderMaze();

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

		/*setOnMouseMoved((mm)->{
		 *  final double rotateConst = 0.1;
		 *  maze.getPlayer().addHorizontalAngle((float)(-1 * (mousePosX - mm.getSceneX()) * rotateConst));
		 *  maze.getPlayer().addVerticalAngle((float)((mousePosY - mm.getSceneY()) * rotateConst));
		 *  mousePosX = mm.getSceneX();
		 *  mousePosY = mm.getSceneY();
		 *  //centerMouse();
		 *  updatePlayer();
		 * });*/
	}

	//Place le curseur au centre de l'ecran
	private void centerMouse()
	{
		mousePosX = (double)(screenWidth / 2);
		mousePosY = (double)(screenHeight / 2);
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

	private void checkWin()
	{
		if (maze.getPlayer().hasWin(maze.getContentMaze().getSpecialCases()))
		{
			v.changeScene(new Winner(v));
		}
	}

	/**
	 * Dessine le Maze
	 */
	private void renderMaze()
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

		walls.getTransforms().add(sc);
		root.getChildren().add(walls);
		final LineWall[] lineWalls = maze.getContentMaze().getLineWalls();
		for (LineWall l: lineWalls)
		{
			Box w = new Box();
			w.setHeight(hauteur);
			if (!l.isHorizontal())                                            // Mur "vertical" dans le plan
			{
				final int depth = l.getY2() - l.getY1();
				w.setDepth(depth);
				w.setWidth(l.getEpaisseur());
				w.setTranslateX(l.getX1() + l.getEpaisseur() / 2.0);
				w.setTranslateZ(l.getY1() + depth / 2.0);
			}
			else // Mur horizontal
			{
				final int width = l.getX2() - l.getX1();
				w.setWidth(width);
				w.setDepth(l.getEpaisseur());
				w.setTranslateX(l.getX1() + width / 2.0);
				w.setTranslateZ(l.getY1() + l.getEpaisseur() / 2.0);
			}
			w.setMaterial(mat);
			walls.getChildren().add(w);
		}
	}

	/**
	 * Dessine le sol
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
			f.setTranslateX(md.x1 + w / 2);
			f.setTranslateZ(md.y1 + h / 2);
			f.setMaterial(new PhongMaterial(Color.RED));
			f.setTranslateY(hauteur / 2);
			floors.getChildren().add(f);
		}
		return (floors);
	}

	public MainMaze getMaze()
	{
		return (this.maze);
	}
}
