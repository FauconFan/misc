package src.view;

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
import javafx.scene.SubScene;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Scale;
import javafx.scene.transform.Translate;
import javafx.stage.Stage;


import src.model.board.LineWall;
import src.model.ContentMaze;

public class ViewIngame extends Scene
{
	private final Group root;
	private final ContentMaze maze;

	//To remind pos of the mouse
	private double mousePosX = 0;
	private double mousePosY = 0;

	final int hauteur = 60;

	public ViewIngame(ContentMaze m)
	{
		super(new Group(), 500, 750, true);
		root = (Group)this.getRoot();
		maze = m;

		setFill(Color.GREY);

		// Seul moyen d'obtenir quelque chose d'euclidien...

		Box floor = new Box(1000, 0.5, 1000);
		floor.setMaterial(new PhongMaterial(Color.RED));
		floor.setTranslateY(hauteur / 2 - 1);
		root.getChildren().add(floor);

		//Creation de la camera
		final Group             cameraGroup = new Group();
		final PerspectiveCamera camera      = new PerspectiveCamera(true);
		cameraGroup.getChildren().add(camera);
		camera.setNearClip(0.1);
		camera.setFarClip(100000.0);

		final Translate tr = new Translate();
		cameraGroup.getTransforms().add(tr);

		// Rotate
		final Rotate rx = new Rotate();
		rx.setAxis(Rotate.Y_AXIS);

		final Rotate ry = new Rotate();
		ry.setAxis(Rotate.X_AXIS);
		cameraGroup.getTransforms().addAll(rx, ry);

		root.getChildren().add(cameraGroup);
		//Source de lumiere sur le joueur

		PointLight lightOnPlayer = new PointLight();
		lightOnPlayer.setColor(Color.WHITE);
		cameraGroup.getChildren().add(lightOnPlayer);

		// Défini la camera pour la scène
		setCamera(camera);

		// On tourne par rapport à Y

		// constantes de déplacements
		final int change = 5;
		final int rot    = 5; // En degré

		renderMaze();

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			switch (key.getCode())
			{
			case Q: tr.setX(tr.getX() - change); break;

			case D: tr.setX(tr.getX() + change); break;

			case Z: tr.setZ(tr.getZ() + change); break;

			case S: tr.setZ(tr.getZ() - change); break;

			case F: tr.setY(tr.getY() + change); break;

			case R: tr.setY(tr.getY() - change); break;

			case LEFT: rx.setAngle(rx.getAngle() - rot); break;

			case RIGHT: rx.setAngle(rx.getAngle() + rot); break;

			case UP: ry.setAngle(ry.getAngle() + rot); break;

			case DOWN: ry.setAngle(ry.getAngle() - rot); break;
			}
		});

		//Mouse controller
		//Remind the old pos
		setOnMousePressed((me)->{
			mousePosX = me.getSceneX();
			mousePosY = me.getSceneY();
		});
		//End
		setOnMouseDragged((mEv)->{
			final double rotateConst = 0.005;
			rx.setAngle(rx.getAngle() + (mousePosX - mEv.getSceneX()) * rotateConst);
			ry.setAngle(ry.getAngle() + (mousePosY - mEv.getSceneY()) * rotateConst);
		});
	}

	private void renderMaze()
	{
		Group walls = new Group();

		final int facteur = 30;

		root.getChildren().add(walls);
		final LineWall[] lineWalls = maze.getLineWalls();
		//LineWall[] lineWalls={new LineWall(0,0,10,0)};
		for (LineWall l: lineWalls)
		{
			Box w = new Box();
			w.setHeight(hauteur);
			//System.out.println(l);
			if (!l.isHorizontal())                                            // Mur "vertical" dans le plan
			{
				int depth = l.getY2() - l.getY1();
				w.setDepth(depth * facteur);
				w.setWidth(l.getEpaisseur() * facteur);
				w.setTranslateX(l.getX1() * facteur);
				w.setTranslateZ((l.getY1() + depth / 2) * facteur);
			}
			else // Mur horizontal
			{
				final int width = l.getX2() - l.getX1();
				w.setWidth(width * facteur);
				w.setDepth(l.getEpaisseur() * facteur);
				w.setTranslateX((l.getX1() + width / 2) * facteur);
				w.setTranslateZ(l.getY1() * facteur);
			}
			w.setMaterial(new PhongMaterial(Color.GREEN));
			walls.getChildren().add(w);
		}
	}
}
