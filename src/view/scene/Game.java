package src.view.scene;

import javafx.application.Application;
import javafx.scene.AmbientLight;
import javafx.scene.Group;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;
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

/*
 * Pour remettre le curseur au centre de l'ecran
 * import java.awt.AWTException;
 * import java.awt.Robot;
 */
import src.model.board.LineWall;
import src.model.MainMaze;
import src.model.MazeDimension;

import src.view.View;

public class Game extends Scene
{
	private final Group root;
	private final MainMaze maze;
	private final View v;

	// Anciennes positions de la souris
	private double mousePosX = 0;
	private double mousePosY = 0;

	//Hauteur des murs
	final int hauteur = 60;

	// Facteur de multiplication général
	final int facteur = 30;

	//Est on en mode ghost ?
	private boolean ghostMode = true;

	//Translate
	final Translate tr;

	public boolean getGhostMode()
	{
		return (ghostMode);
	}

	public void setGhostMode(boolean b)
	{
		tr.setY(0); // Retour au sol
		this.ghostMode = b;
	}

	public Game(View v, MainMaze m)
	{
		super(new Group(), 500, 750, true);
		this.v = v;
		root   = (Group)this.getRoot();
		maze   = m;

		setFill(Color.GREY);

		// Ajoute le sol
		root.getChildren().add(makeFloors());

		//Creation de la camera
		final Group             cameraGroup = new Group();
		final PerspectiveCamera camera      = new PerspectiveCamera(true);
		cameraGroup.getChildren().add(camera);
		camera.setNearClip(0.1);
		camera.setFarClip(1000.0);

		tr = new Translate();
		cameraGroup.getTransforms().add(tr);

		// Rotate
		final Rotate rx = new Rotate();
		rx.setAxis(Rotate.Y_AXIS);

		final Rotate ry = new Rotate();
		ry.setAxis(Rotate.X_AXIS);
		cameraGroup.getTransforms().addAll(rx, ry);

		//Source de lumiere sur le joueur
		PointLight lightOnPlayer = new PointLight();
		lightOnPlayer.setColor(Color.WHITE);
		cameraGroup.getChildren().add(lightOnPlayer);

		root.getChildren().add(cameraGroup);
		cameraGroup.setTranslateZ(maze.getPlayer().getPosY() * facteur);

		cameraGroup.setTranslateX(maze.getPlayer().getPosX() * facteur);

		// Défini la camera pour la scène
		setCamera(camera);

		// constantes de déplacements
		final float change = 0.2f;
		final int   rot    = 5; // En degré

		renderMaze();

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			switch (key.getCode())
			{
			case Q: setTrX(ry, -1 * change); break;

			case D: setTrX(ry, change); break;

			case Z: setTrZ(rx, change); break;

			case S: setTrZ(rx, -1 * change); break;

			case F: if (ghostMode)
				{
					tr.setY(tr.getY() + change);
				}
				break;

			case R: if (ghostMode)
				{
					tr.setY(tr.getY() - change);
				}
				break;

			case LEFT: maze.getPlayer().addHorizontalAngle(-1 * rot); break;

			case RIGHT: maze.getPlayer().addHorizontalAngle(1 * rot); break;

			case UP: maze.getPlayer().addVerticalAngle(1 * rot); break;

			case DOWN: maze.getPlayer().addVerticalAngle(-1 * rot); break;

			case ESCAPE: v.changeScene(new Pause(v, this)); break;
			}

			updatePlayer(rx, ry);
		});

		//Mouse controller
		setOnMouseMoved((mm)->{
			final double rotateConst = 0.1;
			maze.getPlayer().addHorizontalAngle((float)(-1 * (mousePosX - mm.getSceneX()) * rotateConst));
			maze.getPlayer().addVerticalAngle((float)((mousePosY - mm.getSceneY()) * rotateConst));
			mousePosX = mm.getSceneX();
			mousePosY = mm.getSceneY();

			updatePlayer(rx, ry);
		});
	}

	private void setTrZ(Rotate rx, float change)
	{
		final double r = Math.toRadians(rx.getAngle());

		maze.movePlayer((float)(tr.getX() + Math.sin(r) * change), (float)(tr.getZ() + Math.cos(r) * change));
	}

	private void setTrX(Rotate rx, float change)
	{
		final double r = Math.toRadians(rx.getAngle());

		maze.movePlayer((float)(tr.getX() + Math.cos(r) * change), (float)(tr.getZ() + Math.sin(r) * change));
	}

	private void updatePlayer(Rotate rx, Rotate ry)
	{
		tr.setZ(maze.getPlayer().getPosY());
		tr.setX(maze.getPlayer().getPosX());
		rx.setAngle(maze.getPlayer().getHorizontalAngle());
		ry.setAngle(maze.getPlayer().getVerticalAngle());
	}

	/**
	 * Dessine le Maze
	 */
	private void renderMaze()
	{
		Group walls = new Group();

		root.getChildren().add(walls);
		final LineWall[] lineWalls = maze.getAdaptedMaze().getLineWalls();
		for (LineWall l: lineWalls)
		{
			Box w = new Box();
			w.setHeight(hauteur);
			if (!l.isHorizontal())                                            // Mur "vertical" dans le plan
			{
				final int depth = l.getY2() - l.getY1();
				w.setDepth(depth * facteur);
				w.setWidth(l.getEpaisseur() * facteur);
				w.setTranslateX((l.getX1() + l.getEpaisseur() / 2.0) * facteur);
				w.setTranslateZ((l.getY1() + depth / 2.0) * facteur);
			}
			else // Mur horizontal
			{
				final int width = l.getX2() - l.getX1();
				w.setWidth(width * facteur);
				w.setDepth(l.getEpaisseur() * facteur);
				w.setTranslateX((l.getX1() + width / 2.0) * facteur);
				w.setTranslateZ((l.getY1() + l.getEpaisseur() / 2.0) * facteur);
			}
			w.setMaterial(new PhongMaterial(Color.GREEN));
			walls.getChildren().add(w);
		}
	}

	/**
	 * Dessine le sol
	 */
	public Group makeFloors()
	{
		final Group floors = new Group();

		for (MazeDimension.RectInMaze md: maze.getMazeDimension().list_rectmaze)
		{
			final int w = md.x2 - md.x1;
			final int h = md.y2 - md.y1;
			Box       f = new Box(w * facteur, 0.5, h * facteur);
			f.setTranslateX((md.x1 + w / 2) * facteur);
			f.setTranslateZ((md.y1 + h / 2) * facteur);
			f.setMaterial(new PhongMaterial(Color.RED));
			f.setTranslateY(hauteur / 2 - 1);
			floors.getChildren().add(f);
		}
		return (floors);
	}
}
