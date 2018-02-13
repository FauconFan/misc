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

	public ViewIngame(ContentMaze m)
	{
		super(new Group());
		root = (Group)this.getRoot();
		maze = m;

		setFill(Color.GREY);

		// Seul moyen d'obtenir quelque chose d'euclidien...
		Scale s = new Scale(1, 1, 0.05f);
		root.getTransforms().add(s);

		//Creation de la camera
		final PerspectiveCamera camera = new PerspectiveCamera(true);
		root.getChildren().add(camera);
		camera.setNearClip(0.1);
		camera.setFarClip(100000.0);

		// Rotate
		final Rotate rx = new Rotate();
		rx.setAxis(Rotate.Y_AXIS);

		final Rotate ry = new Rotate();
		ry.setAxis(Rotate.X_AXIS);
		camera.getTransforms().addAll(rx, ry);

		final Translate tr = new Translate();
		camera.getTransforms().add(tr);

		//Creation de la source de lumiere ompnipresente

		root.getChildren().add(new AmbientLight(Color.WHITE));



		//Source de lumiere sur le joueur
		//TODO

		/*
		 * PointLight lightPlayer = new PointLight();
		 * lightPlayer.setColor(Color.WHITE);
		 *
		 * lightPlayer.setTranslateX(tr.getX());
		 * lightPlayer.setTranslateY(tr.getY());
		 * lightPlayer.setTranslateZ(tr.getZ());
		 * this.root.getChildren().add(lightPlayer);
		 */

		// Défini la camera pour la scène
		setCamera(camera);

		// On tourne par rapport à Y
		//camera.setRotationAxis(Rotate.Y_AXIS);

		// constantes de déplacements
		final int change = 1;
		final int rot    = 1; // En degré

		renderMaze();

		//Key controller
		addEventHandler(KeyEvent.KEY_PRESSED, (key)->{
			if (key.getCode() == KeyCode.Q)
			{
				tr.setX(tr.getX() - change);
			}
			if (key.getCode() == KeyCode.D)
			{
				tr.setX(tr.getX() + change);
			}
			if (key.getCode() == KeyCode.Z)
			{
				tr.setZ(tr.getZ() + change);
			}
			if (key.getCode() == KeyCode.S)
			{
				tr.setZ(tr.getZ() - change);
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
		final int hauteur = 60;
		Group     walls   = new Group();

		final int facteur = 30;

		root.getChildren().add(walls);
		//LineWall[] lineWalls = { new LineWall(0, 0, 0, 5, (float)(0.5)), new LineWall(0, 5, 5, 5, (float)(0.5)), new LineWall(5, 5, 5, 0, (float)(0.5)), new LineWall(5, 0, 0, 0, (float)(0.5)) };
		LineWall[] lineWalls = maze.getLineWalls();

		for (LineWall l: lineWalls)
		{
			System.out.println(l);
			Box w = new Box();
			w.setHeight(hauteur);
			if (l.getX1() == l.getX2())                                            // Mur "vertical" dans le plan
			{
				w.setDepth((l.getY2() - l.getY1()) * facteur);
				w.setWidth(l.getEpaisseur() * facteur);
			}
			else // Mur horizontal
			{
				w.setWidth((l.getX2() - l.getX1()) * facteur);
				w.setDepth(l.getEpaisseur() * facteur);
			}
			w.setTranslateX(l.getX1() * facteur);
			w.setTranslateZ(l.getY1() * facteur);
			w.setMaterial(new PhongMaterial(Color.GREEN));
			walls.getChildren().add(w);
		}
	}
}
